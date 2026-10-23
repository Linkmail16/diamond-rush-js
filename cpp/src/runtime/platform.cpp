#include "../game/game.h"
#include "hooks.h"
#include "state.h"
#include <SDL.h>
#include <atomic>
#include <cmath>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

#define DR_MP3_IMPLEMENTATION
#include "../../third_party/dr_mp3.h"
#include "../../third_party/stb_image.h"

void game_state(StateWriter& w, Game* g);
const std::vector<uint8_t>* sound_mp3(int i);

static const int SCR_W = 240, SCR_H = 320;

struct Loop {
	Ref<Game> game;
	bool running = false;
	bool stopped = false;
	int soundAsk = 0;
	int64_t tickNo = 0;
	std::map<int, int64_t> downAt;
	std::vector<int> ups;
} G;

static void game_end();
static void (*sm_begin_fn)(Game*) = nullptr;
static void (*sm_end_fn)(Game*) = nullptr;

static void key_up(int code) {
	G.downAt.erase(code);
	try { G.game->keyReleased(code); } catch (JavaException&) {}
}

static void game_key(int code, bool down) {
	if (!G.game.get() || !G.running) return;
	if (down) {
		G.downAt[code] = G.tickNo;
		try { G.game->keyPressed(code); } catch (JavaException&) {}
	} else {
		auto it = G.downAt.find(code);
		if (it != G.downAt.end() && it->second == G.tickNo) {
			if (std::find(G.ups.begin(), G.ups.end(), code) == G.ups.end()) G.ups.push_back(code);
		} else key_up(code);
	}
}

static void tick() {
	if (!G.running) return;
	Game* game = G.game.get();
	try {
		if (game->quit) { game_end(); return; }
		if (!game->paused) {
			if (sm_begin_fn) sm_begin_fn(game);
			game->frameStart = JSystem::currentTimeMillis();
			try { game->update(); } catch (JavaException& ex) { ex.ex->printStackTrace(); }
			if (game->quit) { game_end(); return; }
			if (Game::screen != 2) Game::frameCount = Game::frameCount + 1;
			if (Game::screen == 7 && G.soundAsk < 2) {
				game_key(-5, G.soundAsk == 0);
				G.soundAsk++;
			}
			game->frameUpdated = JSystem::currentTimeMillis();
			if (game->frameTime > 65) {
				game->frameSkipped = true;
				game->frameTime = 0;
			} else {
				try { game->paint(game->getGraphics()); } catch (JavaException& ex) { ex.ex->printStackTrace(); }
				game->flushGraphics();
				game->frameSkipped = false;
				if (Game::screen != 2) Game::drawCount = Game::drawCount + 1;
				game->frameTime = JMath::abs(JSystem::currentTimeMillis() - game->frameStart);
			}
		}
		if (sm_end_fn) sm_end_fn(game);
		G.tickNo++;
		if (!G.ups.empty()) {
			std::vector<int> u;
			u.swap(G.ups);
			for (int k : u) key_up(k);
		}
	} catch (JavaException& ex) {
		ex.ex->printStackTrace();
	}
	gc_collect();
}

static void game_start(Object* o) {
	Game* game = dynamic_cast<Game*>(o);
	if (!game) return;
	G.game = game;
	game->startTime = JSystem::currentTimeMillis();
	game->resetCounters();
	game->loadPreferences();
	G.running = true;
	tick();
}

static void game_stop(const char*) {
	G.running = false;
	G.stopped = true;
}

static void game_end() {
	G.running = false;
	try { G.game->cleanup(); } catch (JavaException&) {}
	Sound().stop();
	game_stop("fin");
}

static Ref<Midlet> boot() {
	game_clinit();
	Ref<Midlet> m = jnew<Midlet>()->init();
	m->startApp();
	return m;
}

static int64_t VT = 1000000;
static int run_headless(int argc, char** argv) {
	int frames = 3000;
	std::string events, out;
	int lw = -1, ls = -1;
	for (int i = 1; i < argc; i++) {
		std::string a = argv[i];
		if (a == "--frames" && i + 1 < argc) frames = atoi(argv[++i]);
		else if (a == "--events" && i + 1 < argc) events = argv[++i];
		else if (a == "--out" && i + 1 < argc) out = argv[++i];
		else if (a == "--nivel" && i + 1 < argc) sscanf(argv[++i], "%d,%d", &lw, &ls);
		else if (a == "--debug") rt.debug = true;
		else if (a == "--verbose") StateWriter::verbose = true;
	}
	struct Ev { int t, k, d; };
	std::vector<Ev> ev;
	if (!events.empty()) {
		std::ifstream f(events);
		Ev e;
		while (f >> e.t >> e.k >> e.d) ev.push_back(e);
	}
	rt.now_ms = [] { return VT; };
	rt.perf_ms = [] { return (double)VT; };
	rt.flush = [](Image*) {};
	rt.start_game = game_start;
	rt.stop = game_stop;
	rt.save_to_disk = false;
	Ref<Midlet> m = boot();
	FILE* fo = out.empty() ? stdout : fopen(out.c_str(), "w");
	size_t ei = 0;
	bool levelDone = lw < 0;
	for (int t = 0; t < frames; t++) {
		while (ei < ev.size() && ev[ei].t <= t) { game_key(ev[ei].k, ev[ei].d == 1); ei++; }
		VT += 50;
		if (!levelDone && G.game.get() && Game::screen == 5 && G.game->loadingStep >= 5) {
			G.game->world = lw;
			G.game->stage = ls;
			levelDone = true;
		}
		if (G.running) tick();
		if (t % 25 == 24) {
			StateWriter w;
			w.out = "[";
			game_state(w, G.game.get());
			w.out += "]";
			fprintf(fo, "%s\n", w.out.c_str());
		}
	}
	if (fo != stdout) fclose(fo);
	fflush(stdout);
	_Exit(0);
}

struct Snd {
	std::vector<std::vector<int16_t>> pcm;
	std::atomic<int> cur{-1};
	std::atomic<int> gen{0};
	std::atomic<bool> ended{false};
	std::atomic<bool> mute{false};
	size_t pos = 0;
	int playing_gen = -1;
	SDL_AudioDeviceID dev = 0;
} S;

static void SDLCALL audio_cb(void*, Uint8* stream, int len) {
	int16_t* out = (int16_t*)stream;
	int n = len / 2;
	memset(stream, 0, len);
	int c = S.cur.load();
	int g = S.gen.load();
	if (g != S.playing_gen) { S.playing_gen = g; S.pos = 0; }
	if (c < 0 || c >= (int)S.pcm.size()) return;
	const auto& b = S.pcm[c];
	bool mute = S.mute.load();
	int i = 0;
	for (; i < n && S.pos < b.size(); i++, S.pos++) out[i] = mute ? 0 : b[S.pos];
	if (S.pos >= b.size()) {
		S.cur.store(-1);
		S.ended.store(true);
	}
}

static void snd_play(int i) {
	if (!S.dev) return;
	SDL_LockAudioDevice(S.dev);
	S.gen++;
	S.cur.store(i);
	S.ended.store(false);
	SDL_UnlockAudioDevice(S.dev);
}
static void snd_stop() {
	if (!S.dev) return;
	SDL_LockAudioDevice(S.dev);
	S.cur.store(-1);
	S.ended.store(false);
	SDL_UnlockAudioDevice(S.dev);
}

static void load_sounds() {
	for (int i = 0;; i++) {
		const std::vector<uint8_t>* m = sound_mp3(i);
		if (!m) break;
		drmp3_config cfg;
		drmp3_uint64 frames = 0;
		int16_t* p = drmp3_open_memory_and_read_pcm_frames_s16(m->data(), m->size(), &cfg, &frames, nullptr);
		std::vector<int16_t> v;
		if (p) {
			if (cfg.channels == 2) v.assign(p, p + frames * 2);
			else { v.resize(frames * 2); for (drmp3_uint64 k = 0; k < frames; k++) v[2 * k] = v[2 * k + 1] = p[k]; }
			drmp3_free(p, nullptr);
		}
		S.pcm.push_back(std::move(v));
	}
}

static SDL_Window* win;
static SDL_Renderer* ren;
static SDL_Texture* tex;
static float VS = 1, VX = 0, VY = 0;

static void viewport() {
	int ww, wh;
	SDL_GetRendererOutputSize(ren, &ww, &wh);
	VS = std::min(ww / (float)SCR_W, wh / (float)SCR_H);
	VX = (ww - SCR_W * VS) / 2;
	VY = (wh - SCR_H * VS) / 2;
}

static void draw_screen_tex() {
	SDL_FRect d{VX, VY, SCR_W * VS, SCR_H * VS};
	SDL_RenderCopyF(ren, tex, nullptr, &d);
}

struct Smooth {
	bool on = true, ready = false;
	std::vector<uint32_t> base, pbase;
	std::vector<SmOp> cur, prev;
	double tN = 0;
	int cam[2] = {0, 0};
	SDL_Texture* baseTex = nullptr;
} SM;

static void sm_begin(Game* game) {
	if (!SM.on || !game->canvasImage.get()) { rt.sm_rec = false; return; }
	Image* scr = game->canvasImage.get();
	SM.pbase = scr->px;
	SM.prev.swap(SM.cur);
	SM.cur.clear();
	SM.cam[0] = game->camX;
	SM.cam[1] = game->camY;
	rt.sm_screen = scr;
	rt.sm_cur = &SM.cur;
	rt.sm_rec = true;
}

static std::string sm_key(const SmOp& o) {
	char b[96];
	if (o.t == 0) snprintf(b, sizeof b, "%d|%d|%d|%d|%d|%d", o.im->id, o.sx, o.sy, o.w, o.h, o.tr);
	else snprintf(b, sizeof b, "R%u|%d|%d", o.color, o.w, o.h);
	return b;
}

static void sm_end(Game* game) {
	if (!rt.sm_rec) return;
	rt.sm_rec = false;
	SM.base.swap(SM.pbase);
	int l = Game::screen, c1x = game->camX, c1y = game->camY;
	bool play = l == 1 || l == 2;
	int sx = play ? SM.cam[0] - c1x : 0, sy = play ? SM.cam[1] - c1y : 0;
	bool scroll = (sx != 0 || sy != 0) && std::abs(sx) < 64 && std::abs(sy) < 64;
	std::unordered_map<std::string, std::vector<SmOp*>> exact, loose;
	for (SmOp& p : SM.prev) {
		p.used = false;
		exact[sm_key(p)].push_back(&p);
		if (p.t == 0) loose[std::to_string(p.w) + "x" + std::to_string(p.h) + "|" + std::to_string(p.tr)].push_back(&p);
	}
	auto pick = [&](std::vector<SmOp*>* list, const SmOp& o, int lim) -> SmOp* {
		SmOp* best = nullptr;
		int bd = lim;
		if (!list) return nullptr;
		for (SmOp* p : *list) {
			if (p->used) continue;
			int d0 = std::abs(p->dx - o.dx) + std::abs(p->dy - o.dy);
			int d1 = scroll ? std::abs(p->dx + sx - o.dx) + std::abs(p->dy + sy - o.dy) : d0;
			int d = std::min(d0, d1);
			if (d < bd) { bd = d; best = p; }
		}
		return best;
	};
	auto inPlay = [](const SmOp& o) { return o.cl[1] >= 16 && o.cl[1] <= 48 && o.cl[3] <= 248; };
	std::vector<SmOp*> rest;
	for (SmOp& o : SM.cur) {
		auto it = exact.find(sm_key(o));
		SmOp* p = pick(it == exact.end() ? nullptr : &it->second, o, 40);
		if (p) { p->used = true; o.mx = p->dx; o.my = p->dy; } else rest.push_back(&o);
	}
	for (SmOp* o : rest) {
		SmOp* p = nullptr;
		if (o->t == 0) {
			auto it = loose.find(std::to_string(o->w) + "x" + std::to_string(o->h) + "|" + std::to_string(o->tr));
			p = pick(it == loose.end() ? nullptr : &it->second, *o, 24);
		}
		if (p) { p->used = true; o->mx = p->dx; o->my = p->dy; }
		else if (scroll && inPlay(*o)) { o->mx = o->dx - sx; o->my = o->dy - sy; }
		else { o->mx = o->dx; o->my = o->dy; }
	}
	SM.tN = rt.perf_ms();
	SM.ready = true;
	if (SM.base.size() == (size_t)SCR_W * SCR_H) SDL_UpdateTexture(SM.baseTex, nullptr, SM.base.data(), SCR_W * 4);
}

static SDL_Texture* image_tex(Image* im) {
	if (im->tex && im->texVersion == im->version) return (SDL_Texture*)im->tex;
	if (!im->tex) {
		SDL_Texture* t = SDL_CreateTexture(ren, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, im->w, im->h);
		if (!t) return nullptr;
		SDL_SetTextureBlendMode(t, SDL_BLENDMODE_BLEND);
		im->tex = t;
	}
	SDL_UpdateTexture((SDL_Texture*)im->tex, nullptr, im->px.data(), im->w * 4);
	im->texVersion = im->version;
	return (SDL_Texture*)im->tex;
}

static void sm_render() {
	viewport();
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_RenderClear(ren);
	if (!SM.ready) { draw_screen_tex(); SDL_RenderPresent(ren); return; }
	double a = std::min(1.0, std::max(0.0, (rt.perf_ms() - SM.tN) / 50.0)), b = 1 - a;
	float S = VS;
	SDL_FRect full{VX, VY, SCR_W * S, SCR_H * S};
	SDL_RenderCopyF(ren, SM.baseTex, nullptr, &full);
	auto q = [S](double v) { return std::round(v * S) / S; };
	for (const SmOp& o : SM.cur) {
		double X = o.dx + q((o.mx - o.dx) * b), Y = o.dy + q((o.my - o.dy) * b);
		double cx = o.cl[0], cy = o.cl[1];
		int cw = o.cl[2], ch = o.cl[3];
		if (cw * ch < 240 * 200) { cx += X - o.dx; cy += Y - o.dy; }
		if (cx > 0 || cy > 0 || cw < SCR_W || ch < SCR_H) {
			int x0 = (int)std::lround(VX + cx * S), y0 = (int)std::lround(VY + cy * S);
			int x1 = (int)std::lround(VX + (cx + cw) * S), y1 = (int)std::lround(VY + (cy + ch) * S);
			if (x1 <= x0 || y1 <= y0) continue;
			SDL_Rect c{x0, y0, x1 - x0, y1 - y0};
			SDL_RenderSetClipRect(ren, &c);
		} else SDL_RenderSetClipRect(ren, nullptr);
		if (o.t == 1) {
			SDL_SetRenderDrawColor(ren, (o.color >> 16) & 255, (o.color >> 8) & 255, o.color & 255, 255);
			SDL_FRect r{(float)(VX + X * S), (float)(VY + Y * S), o.w * S, o.h * S};
			SDL_RenderFillRectF(ren, &r);
		} else {
			SDL_Texture* t = image_tex(o.im.get());
			if (!t) continue;
			static const double ANG[8] = {0, 0, 0, 180, 270, 90, 270, 90};
			static const SDL_RendererFlip FL[8] = {SDL_FLIP_NONE, SDL_FLIP_VERTICAL, SDL_FLIP_HORIZONTAL, SDL_FLIP_NONE,
			                                       SDL_FLIP_HORIZONTAL, SDL_FLIP_NONE, SDL_FLIP_NONE, SDL_FLIP_HORIZONTAL};
			int tr = o.tr & 7;
			double px = X, py = Y;
			if (tr >= 4) { px += o.h / 2.0 - o.w / 2.0; py += o.w / 2.0 - o.h / 2.0; }
			SDL_Rect src{o.sx, o.sy, o.w, o.h};
			SDL_FRect dst{(float)(VX + px * S), (float)(VY + py * S), o.w * S, o.h * S};
			SDL_RenderCopyExF(ren, t, &src, &dst, ANG[tr], nullptr, FL[tr]);
		}
	}
	SDL_RenderSetClipRect(ren, nullptr);
	SDL_RenderPresent(ren);
}

static void present(Image* screen) {
	SDL_UpdateTexture(tex, nullptr, screen->px.data(), SCR_W * 4);
	if (SM.on) return;
	viewport();
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_RenderClear(ren);
	draw_screen_tex();
	SDL_RenderPresent(ren);
}

static int map_key(const SDL_Keysym& k) {
	switch (k.scancode) {
		case SDL_SCANCODE_UP: case SDL_SCANCODE_W: return -1;
		case SDL_SCANCODE_DOWN: case SDL_SCANCODE_S: return -2;
		case SDL_SCANCODE_LEFT: case SDL_SCANCODE_A: return -3;
		case SDL_SCANCODE_RIGHT: case SDL_SCANCODE_D: return -4;
		case SDL_SCANCODE_SPACE: case SDL_SCANCODE_RETURN: case SDL_SCANCODE_KP_ENTER: return -5;
		case SDL_SCANCODE_E: case SDL_SCANCODE_KP_5: return 53;
		case SDL_SCANCODE_R: case SDL_SCANCODE_KP_MULTIPLY: return 42;
		case SDL_SCANCODE_Q: return -6;
		case SDL_SCANCODE_ESCAPE: case SDL_SCANCODE_P: case SDL_SCANCODE_BACKSPACE: return -7;
		case SDL_SCANCODE_0: case SDL_SCANCODE_KP_0: return 48;
		case SDL_SCANCODE_KP_1: return 49;
		case SDL_SCANCODE_KP_2: return 50;
		case SDL_SCANCODE_KP_3: return 51;
		case SDL_SCANCODE_KP_4: return 52;
		case SDL_SCANCODE_KP_6: return 54;
		case SDL_SCANCODE_KP_7: return 55;
		case SDL_SCANCODE_KP_8: return 56;
		case SDL_SCANCODE_KP_9: return 57;
		default: break;
	}
	if (k.scancode >= SDL_SCANCODE_1 && k.scancode <= SDL_SCANCODE_9) return 49 + (k.scancode - SDL_SCANCODE_1);
	return 0;
}

static void set_icon() {
	const std::vector<uint8_t>* r = resource("icon.png");
	if (!r) return;
	int w, h, c;
	unsigned char* px = stbi_load_from_memory(r->data(), (int)r->size(), &w, &h, &c, 4);
	if (!px) return;
	SDL_Surface* s = SDL_CreateRGBSurfaceWithFormatFrom(px, w, h, 32, w * 4, SDL_PIXELFORMAT_RGBA32);
	if (s) { SDL_SetWindowIcon(win, s); SDL_FreeSurface(s); }
	stbi_image_free(px);
}

static const int RATES[] = {20, 30, 60, 0};
static int rate = 0;

static void update_title() {
	std::string t = "Diamond Rush   (";
	if (SM.on) t += "smooth, 20 FPS";
	else if (RATES[rate]) t += std::to_string(RATES[rate]) + " FPS" + (RATES[rate] == 20 ? ", original" : "");
	else t += "no FPS limit";
	t += ")";
	SDL_SetWindowTitle(win, t.c_str());
}

static void load_settings() {
	if (rt.save_dir.empty()) return;
	FILE* f = fopen((rt.save_dir + "settings.txt").c_str(), "r");
	if (!f) return;
	int sm = 1, r = 0;
	if (fscanf(f, "smooth=%d fps=%d", &sm, &r) >= 1) {
		SM.on = sm != 0;
		for (int i = 0; i < 4; i++) if (RATES[i] == r) rate = i;
	}
	fclose(f);
}
static void save_settings() {
	if (rt.save_dir.empty()) return;
	FILE* f = fopen((rt.save_dir + "settings.txt").c_str(), "w");
	if (!f) return;
	fprintf(f, "smooth=%d fps=%d\n", SM.on ? 1 : 0, RATES[rate]);
	fclose(f);
}

static void set_smooth(bool on) {
	SM.on = on;
	SM.ready = false;
	SM.cur.clear();
	SM.prev.clear();
	rt.sm_rec = false;
	SDL_RenderSetVSync(ren, on ? 1 : 0);
	update_title();
	save_settings();
	if (!on && G.game.get() && G.game->canvasImage.get()) present(G.game->canvasImage.get());
}

static int run_window(int, char**) {
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
		fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
		return 1;
	}
	win = SDL_CreateWindow("Diamond Rush", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCR_W * 2, SCR_H * 2,
	                       SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (!ren) ren = SDL_CreateRenderer(win, -1, 0);
	tex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCR_W, SCR_H);
	SM.baseTex = SDL_CreateTexture(ren, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCR_W, SCR_H);
	set_icon();

	load_sounds();
	SDL_AudioSpec want{}, have{};
	want.freq = 44100;
	want.format = AUDIO_S16SYS;
	want.channels = 2;
	want.samples = 1024;
	want.callback = audio_cb;
	S.dev = SDL_OpenAudioDevice(nullptr, 0, &want, &have, 0);
	if (S.dev) SDL_PauseAudioDevice(S.dev, 0);

	char* pref = SDL_GetPrefPath("DiamondRushPort", "DiamondRush");
	if (pref) { rt.save_dir = pref; SDL_free(pref); }
	rt.save_to_disk = !rt.save_dir.empty();
	rt.now_ms = [] {
		return (int64_t)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	};
	rt.perf_ms = [] { return (double)SDL_GetPerformanceCounter() * 1000.0 / (double)SDL_GetPerformanceFrequency(); };
	rt.flush = present;
	rt.start_game = game_start;
	rt.stop = game_stop;
	rt.snd_play = snd_play;
	rt.snd_stop = snd_stop;
	rt.free_tex = [](void* t) { SDL_DestroyTexture((SDL_Texture*)t); };
	rt.debug = getenv("DR_DEBUG") != nullptr;
	sm_begin_fn = sm_begin;
	sm_end_fn = sm_end;
	load_settings();
	SDL_RenderSetVSync(ren, SM.on ? 1 : 0);
	update_title();

	Ref<Midlet> midlet = boot();
	double next = rt.perf_ms();
	int softHeld = 0;
	while (!G.stopped) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) G.stopped = true;
			else if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
				bool down = e.type == SDL_KEYDOWN;
				if (down && !e.key.repeat) {
					SDL_Keycode kc = e.key.keysym.sym;
					if (kc == SDLK_F11 || kc == SDLK_f || (kc == SDLK_RETURN && (e.key.keysym.mod & KMOD_ALT))) {
						bool fs = SDL_GetWindowFlags(win) & SDL_WINDOW_FULLSCREEN_DESKTOP;
						SDL_SetWindowFullscreen(win, fs ? 0 : SDL_WINDOW_FULLSCREEN_DESKTOP);
						continue;
					}
					if (kc == SDLK_m) { S.mute.store(!S.mute.load()); continue; }
					if (kc == SDLK_g) { set_smooth(!SM.on); next = rt.perf_ms(); continue; }
					if (kc == SDLK_l) {
						if (!SM.on) { rate = (rate + 1) % 4; update_title(); save_settings(); next = rt.perf_ms(); }
						continue;
					}
				}
				if (e.key.repeat) continue;
				int k = map_key(e.key.keysym);
				if (k) game_key(k, down);
			} else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
				int ww, wh, ow, oh;
				SDL_GetWindowSize(win, &ww, &wh);
				SDL_GetRendererOutputSize(ren, &ow, &oh);
				viewport();
				float lx = (e.button.x * (ow / (float)ww) - VX) / VS, ly = (e.button.y * (oh / (float)wh) - VY) / VS;
				if (ly >= 276 && ly < SCR_H) {
					softHeld = lx >= 0 && lx < 80 ? -6 : (lx > 160 && lx < SCR_W ? -7 : 0);
					if (softHeld) game_key(softHeld, true);
				}
			} else if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT) {
				if (softHeld) { game_key(softHeld, false); softHeld = 0; }
			} else if (e.type == SDL_WINDOWEVENT) {
				if (e.window.event == SDL_WINDOWEVENT_FOCUS_LOST) {
					for (auto it = G.downAt.begin(); it != G.downAt.end();) { int k = it->first; ++it; game_key(k, false); }
				}
				if (e.window.event == SDL_WINDOWEVENT_MINIMIZED && G.game.get()) {
					try { G.game->hideNotify(); } catch (JavaException&) {}
					if (S.dev) SDL_PauseAudioDevice(S.dev, 1);
				}
				if (e.window.event == SDL_WINDOWEVENT_RESTORED && G.game.get()) {
					try { G.game->showNotify(); } catch (JavaException&) {}
					if (S.dev) SDL_PauseAudioDevice(S.dev, 0);
				}
				if ((e.window.event == SDL_WINDOWEVENT_EXPOSED || e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) && !SM.on &&
				    G.game.get() && G.game->canvasImage.get()) present(G.game->canvasImage.get());
			}
		}
		if (S.ended.exchange(false)) sound_ended();
		int fps = SM.on ? 20 : RATES[rate];
		double now = rt.perf_ms();
		if (fps == 0) { tick(); continue; }
		double dt = 1000.0 / fps;
		if (now >= next) {
			tick();
			next += dt;
			if (next < now - 250) next = now;
		}
		if (SM.on) sm_render();
		else if (now < next) {
			double wait = next - rt.perf_ms();
			if (wait > 2) SDL_Delay((Uint32)(wait - 1));
		}
	}
	if (S.dev) SDL_CloseAudioDevice(S.dev);
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	_Exit(0);
}

int main(int argc, char** argv) {
	for (int i = 1; i < argc; i++)
		if (std::string(argv[i]) == "--headless") return run_headless(argc, argv);
	return run_window(argc, argv);
}
