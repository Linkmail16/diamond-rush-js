#include "runtime.h"
#include "hooks.h"
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#define STBI_NO_STDIO
#include "../../third_party/stb_image.h"

RtHooks rt;

static std::vector<Object*>* zombies = new std::vector<Object*>();

void Object::release() {
	if (--refs <= 0 && !queued) {
		queued = true;
		zombies->push_back(this);
	}
}

void gc_collect() {
	while (!zombies->empty()) {
		std::vector<Object*> now;
		now.swap(*zombies);
		for (Object* o : now) {
			o->queued = false;
			if (o->refs <= 0) delete o;
		}
	}
}

void throwNPE() { jthrow(u"java/lang/NullPointerException"); }

static const std::map<std::u16string, std::u16string>& exc_parent() {
	static const std::map<std::u16string, std::u16string> m = {
		{u"java/lang/Exception", u"java/lang/Throwable"}, {u"java/lang/Error", u"java/lang/Throwable"},
		{u"java/lang/RuntimeException", u"java/lang/Exception"}, {u"java/io/IOException", u"java/lang/Exception"},
		{u"java/lang/InterruptedException", u"java/lang/Exception"},
		{u"java/lang/ArrayIndexOutOfBoundsException", u"java/lang/RuntimeException"},
		{u"java/lang/StringIndexOutOfBoundsException", u"java/lang/RuntimeException"},
		{u"java/lang/NullPointerException", u"java/lang/RuntimeException"},
		{u"java/lang/ArithmeticException", u"java/lang/RuntimeException"},
		{u"java/lang/NegativeArraySizeException", u"java/lang/RuntimeException"},
		{u"java/lang/ClassCastException", u"java/lang/RuntimeException"},
		{u"java/lang/IllegalArgumentException", u"java/lang/RuntimeException"},
		{u"java/lang/IllegalStateException", u"java/lang/RuntimeException"},
		{u"java/lang/OutOfMemoryError", u"java/lang/Error"},
		{u"javax/microedition/media/MediaException", u"java/lang/Exception"},
		{u"javax/microedition/rms/RecordStoreException", u"java/lang/Exception"},
		{u"javax/microedition/rms/InvalidRecordIDException", u"javax/microedition/rms/RecordStoreException"},
		{u"javax/microedition/midlet/MIDletStateChangeException", u"java/lang/Exception"},
	};
	return m;
}

bool Throwable::isa(const char16_t* c) const {
	std::u16string want(c), cur = cls;
	for (;;) {
		if (cur == want) return true;
		auto it = exc_parent().find(cur);
		if (it == exc_parent().end()) return false;
		cur = it->second;
	}
}

static std::string u8(const std::u16string& s) {
	std::string o;
	for (char16_t c : s) {
		if (c < 0x80) o += (char)c;
		else if (c < 0x800) { o += (char)(0xC0 | (c >> 6)); o += (char)(0x80 | (c & 63)); }
		else { o += (char)(0xE0 | (c >> 12)); o += (char)(0x80 | ((c >> 6) & 63)); o += (char)(0x80 | (c & 63)); }
	}
	return o;
}

void Throwable::printStackTrace() {
	if (rt.debug) fprintf(stderr, "[java] excepcion %s %s\n", u8(cls).c_str(), u8(msg).c_str());
}

void jthrow(const char16_t* cls, std::u16string msg) {
	if (rt.debug) fprintf(stderr, "[java] lanza %s %s\n", u8(cls).c_str(), u8(msg).c_str());
	throw JavaException(Ref<Throwable>(new Throwable(cls, std::move(msg))));
}

void cast_failed(const char* to, const char* from) {
	if (rt.debug) fprintf(stderr, "[java] cast de %s a %s\n", from, to);
	jthrow(u"java/lang/ClassCastException");
}

Ref<String> jstring(const std::u16string& s) { return Ref<String>(new String(s)); }

Ref<String> operator""_j(const char16_t* s, size_t n) {
	static auto* lits = new std::unordered_map<std::u16string, Ref<String>>();
	std::u16string k(s, n);
	auto it = lits->find(k);
	if (it != lits->end()) return it->second;
	Ref<String> r = jstring(k);
	(*lits)[k] = r;
	return r;
}

std::string String::utf8() const { return u8(s); }

uint16_t String::charAt(int32_t i) const {
	if (i < 0 || i >= length()) jthrow(u"java/lang/StringIndexOutOfBoundsException");
	return s[i];
}
Ref<String> String::substring(int32_t a) const { return substring(a, length()); }
Ref<String> String::substring(int32_t a, int32_t b) const {
	if (a < 0 || b > length() || a > b) jthrow(u"java/lang/StringIndexOutOfBoundsException");
	return jstring(s.substr(a, b - a));
}
int32_t String::indexOf(int32_t c, int32_t from) const {
	if (from < 0) from = 0;
	for (int32_t i = from; i < length(); i++) if (s[i] == (char16_t)c) return i;
	return -1;
}
bool String::endsWith(const Ref<String>& x) const {
	const std::u16string& t = x->s;
	return t.size() <= s.size() && s.compare(s.size() - t.size(), t.size(), t) == 0;
}
Ref<String> String::toLowerCase() const {
	std::u16string o = s;
	for (auto& c : o) {
		if ((c >= u'A' && c <= u'Z') || (c >= 0xC0 && c <= 0xDE && c != 0xD7)) c = (char16_t)(c + 32);
	}
	return jstring(o);
}
Arr<int8_t> String::getBytes() const {
	auto a = newArray<int8_t>(length());
	for (int32_t i = 0; i < length(); i++) a->data[i] = (int8_t)s[i];
	return a;
}
int32_t String::compareTo(const Ref<String>& o) const {
	const std::u16string& b = o->s;
	size_t n = std::min(s.size(), b.size());
	for (size_t i = 0; i < n; i++) if (s[i] != b[i]) return (int32_t)s[i] - (int32_t)b[i];
	return (int32_t)s.size() - (int32_t)b.size();
}
bool String::equals(const Ref<Object>& o) const {
	String* t = dynamic_cast<String*>(o.get());
	return t && t->s == s;
}
int32_t String::hashCode() {
	uint32_t h = 0;
	for (char16_t c : s) h = h * 31 + c;
	return (int32_t)h;
}
bool String::equalsObj(Object* o) {
	String* t = dynamic_cast<String*>(o);
	return t && t->s == s;
}
Ref<String> String::valueOf(int32_t v) {
	std::string a = std::to_string(v);
	return jstring(std::u16string(a.begin(), a.end()));
}
Ref<String> String::fromBytes(const Arr<int8_t>& b, int32_t off, int32_t len, const Ref<String>& enc) {
	if (off < 0 || len < 0 || off + len > b->length) jthrow(u"java/lang/StringIndexOutOfBoundsException");
	const uint8_t* p = (const uint8_t*)b->data + off;
	std::u16string e = enc.get() ? enc->s : u"";
	for (auto& c : e) if (c >= u'A' && c <= u'Z') c = (char16_t)(c + 32);
	std::u16string o;
	if (e == u"utf-8" || e == u"utf8") {
		for (int32_t i = 0; i < len;) {
			uint8_t c = p[i];
			if (c < 0x80) { o += c; i++; }
			else if ((c & 0xE0) == 0xC0 && i + 1 < len) { o += (char16_t)(((c & 31) << 6) | (p[i + 1] & 63)); i += 2; }
			else if ((c & 0xF0) == 0xE0 && i + 2 < len) { o += (char16_t)(((c & 15) << 12) | ((p[i + 1] & 63) << 6) | (p[i + 2] & 63)); i += 3; }
			else { o += 0xFFFD; i++; }
		}
	} else {
		for (int32_t i = 0; i < len; i++) o += (char16_t)p[i];
	}
	return jstring(o);
}

Ref<StringBuffer> StringBuffer::append(const Ref<String>& v) { s += v.get() ? v->s : u"null"; return this; }
Ref<StringBuffer> StringBuffer::append(const Ref<StringBuffer>& v) { s += v.get() ? v->s : u"null"; return this; }
Ref<StringBuffer> StringBuffer::append(int32_t v) { std::string a = std::to_string(v); s += std::u16string(a.begin(), a.end()); return this; }
Ref<StringBuffer> StringBuffer::appendChar(int32_t c) { s += (char16_t)c; return this; }
uint16_t StringBuffer::charAt(int32_t i) const {
	if (i < 0 || i >= length()) jthrow(u"java/lang/StringIndexOutOfBoundsException");
	return s[i];
}
Ref<StringBuffer> StringBuffer::deleteChars(int32_t a, int32_t e) {
	if (a < 0 || a > length() || a > e) jthrow(u"java/lang/StringIndexOutOfBoundsException");
	s.erase(a, std::min(e, length()) - a);
	return this;
}
void StringBuffer::setCharAt(int32_t i, int32_t c) {
	if (i < 0 || i >= length()) jthrow(u"java/lang/StringIndexOutOfBoundsException");
	s[i] = (char16_t)c;
}

bool Integer::equalsObj(Object* o) {
	Integer* t = dynamic_cast<Integer*>(o);
	return t && t->value == value;
}

Ref<Object> Hashtable::put(const Ref<Object>& k, const Ref<Object>& v) {
	if (!k.get() || !v.get()) throwNPE();
	auto it = m.find(k.get());
	if (it != m.end()) {
		Ref<Object> old = it->second.second;
		it->second.second = v;
		return old;
	}
	m.emplace(k.get(), std::make_pair(k, v));
	return nullptr;
}
Ref<Object> Hashtable::get(const Ref<Object>& k) {
	if (!k.get()) throwNPE();
	auto it = m.find(k.get());
	return it == m.end() ? Ref<Object>() : it->second.second;
}

void PrintStream::println(const Ref<String>& s) { if (rt.debug) fprintf(stderr, "[java] %s\n", s.get() ? s->utf8().c_str() : "null"); }
void PrintStream::println(int32_t v) { if (rt.debug) fprintf(stderr, "[java] %d\n", v); }

int64_t JSystem::currentTimeMillis() { return rt.now_ms(); }

void Thread::start() { if (target.get() && rt.start_game) rt.start_game(target.get()); }

int32_t InputStream::read() { return pos < size ? buf[pos++] : -1; }
int32_t InputStream::read(const Arr<int8_t>& b, int32_t off, int32_t len) {
	if (len == 0) return 0;
	if (pos >= size) return -1;
	int32_t n = std::min(len, size - pos);
	if (off < 0 || off + n > b->length) jthrow(u"java/lang/ArrayIndexOutOfBoundsException");
	memcpy(b->data + off, buf + pos, n);
	pos += n;
	return n;
}
int64_t InputStream::skip(int64_t n) {
	int64_t k = std::max<int64_t>(0, std::min<int64_t>(n, size - pos));
	pos += (int32_t)k;
	return k;
}

Ref<JClass> JClass::forName(const Ref<String>& n) {
	static auto* all = new std::unordered_map<std::u16string, Ref<JClass>>();
	auto it = all->find(n->s);
	if (it != all->end()) return it->second;
	Ref<JClass> c(new JClass());
	c->name = n->s;
	(*all)[n->s] = c;
	return c;
}
static std::string res_name(const Ref<String>& name) {
	std::string s = name->utf8();
	return s.size() && s[0] == '/' ? s.substr(1) : s;
}
Ref<InputStream> JClass::getResourceAsStream(const Ref<String>& name) {
	const std::vector<uint8_t>* r = resource(res_name(name));
	if (!r) return nullptr;
	return Ref<InputStream>(new InputStream(r->data(), (int32_t)r->size()));
}
Ref<JClass> Object::getClass() {
	const char* c = javaClass();
	return JClass::forName(jstring(std::u16string(c, c + strlen(c))));
}

static int32_t IMG_ID = 0;
static Ref<Image> png_image(const uint8_t* d, int32_t n) {
	int w, h, comp;
	unsigned char* px = stbi_load_from_memory(d, n, &w, &h, &comp, 4);
	if (!px) return nullptr;
	Ref<Image> im(new Image());
	im->w = w;
	im->h = h;
	im->id = ++IMG_ID;
	im->px.resize((size_t)w * h);
	for (int i = 0; i < w * h; i++) {
		const unsigned char* q = px + 4 * i;
		im->px[i] = ((uint32_t)q[3] << 24) | ((uint32_t)q[0] << 16) | ((uint32_t)q[1] << 8) | q[2];
	}
	stbi_image_free(px);
	return im;
}
Ref<Image> Image::createImage(const Ref<String>& name) {
	const std::vector<uint8_t>* r = resource(res_name(name));
	Ref<Image> im = r ? png_image(r->data(), (int32_t)r->size()) : nullptr;
	if (!im.get()) jthrow(u"java/io/IOException", u"no hay " + name->s);
	return im;
}
Ref<Image> Image::createImage(int32_t w, int32_t h) {
	if (w <= 0 || h <= 0) jthrow(u"java/lang/IllegalArgumentException");
	Ref<Image> im(new Image());
	im->w = w;
	im->h = h;
	im->id = ++IMG_ID;
	im->mutableImg = true;
	im->px.assign((size_t)w * h, 0xFFFFFFFFu);
	return im;
}
Ref<Image> Image::createImage(const Arr<int8_t>& data, int32_t off, int32_t len) {
	if (off < 0 || len < 0 || off + len > data->length) jthrow(u"java/lang/ArrayIndexOutOfBoundsException");
	Ref<Image> im = png_image((const uint8_t*)data->data + off, len);
	if (!im.get()) jthrow(u"java/lang/IllegalArgumentException", u"PNG");
	return im;
}
Ref<Image> Image::createRGBImage(const Arr<int32_t>& rgb, int32_t w, int32_t h, bool alpha) {
	if (w <= 0 || h <= 0) jthrow(u"java/lang/IllegalArgumentException");
	Ref<Image> im(new Image());
	im->w = w;
	im->h = h;
	im->id = ++IMG_ID;
	im->px.resize((size_t)w * h);
	for (int32_t i = 0; i < w * h; i++) {
		uint32_t v = (uint32_t)rgb[i];
		im->px[i] = alpha ? v : (v | 0xFF000000u);
	}
	return im;
}
Image::~Image() { if (tex && rt.free_tex) rt.free_tex(tex); }

Ref<Graphics> Image::getGraphics() {
	if (!mutableImg) jthrow(u"java/lang/IllegalStateException");
	return Ref<Graphics>(new Graphics(this));
}

void Graphics::setClip(int32_t x, int32_t y, int32_t w, int32_t h) {
	x += tx;
	y += ty;
	int32_t x0 = std::max(0, x), y0 = std::max(0, y);
	int32_t x1 = std::min(target->w, x + w), y1 = std::min(target->h, y + h);
	cx = x0; cy = y0; cw = std::max(0, x1 - x0); ch = std::max(0, y1 - y0);
}
void Graphics::clipRect(int32_t x, int32_t y, int32_t w, int32_t h) {
	int32_t ax = x + tx, ay = y + ty;
	int32_t x0 = std::max(cx, ax), y0 = std::max(cy, ay);
	int32_t x1 = std::min(cx + cw, ax + w), y1 = std::min(cy + ch, ay + h);
	cx = x0; cy = y0; cw = std::max(0, x1 - x0); ch = std::max(0, y1 - y0);
}
void Graphics::rect(int32_t x, int32_t y, int32_t w, int32_t h) {
	int32_t x0 = std::max(x, cx), y0 = std::max(y, cy);
	int32_t x1 = std::min(x + w, cx + cw), y1 = std::min(y + h, cy + ch);
	if (x0 >= x1 || y0 >= y1) return;
	uint32_t* p = target->px.data();
	int32_t W = target->w;
	for (int32_t yy = y0; yy < y1; yy++) std::fill(p + (size_t)yy * W + x0, p + (size_t)yy * W + x1, color);
	target->version++;
	if (rt.sm_rec && target == rt.sm_screen)
		rt.sm_cur->push_back(SmOp{1, nullptr, 0, 0, w, h, 0, x, y, color, {cx, cy, cw, ch}, x, y, false});
}
void Graphics::fillRect(int32_t x, int32_t y, int32_t w, int32_t h) {
	if (w <= 0 || h <= 0 || cw <= 0 || ch <= 0) return;
	rect(x + tx, y + ty, w, h);
}
void Graphics::drawRect(int32_t x, int32_t y, int32_t w, int32_t h) {
	if (w < 0 || h < 0 || cw <= 0 || ch <= 0) return;
	int32_t ax = x + tx, ay = y + ty;
	rect(ax, ay, w + 1, 1);
	rect(ax, ay + h, w + 1, 1);
	rect(ax, ay, 1, h + 1);
	rect(ax + w, ay, 1, h + 1);
}
void Graphics::drawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
	if (cw <= 0 || ch <= 0) return;
	x1 += tx; x2 += tx; y1 += ty; y2 += ty;
	if (x1 == x2 || y1 == y2) {
		rect(std::min(x1, x2), std::min(y1, y2), std::abs(x2 - x1) + 1, std::abs(y2 - y1) + 1);
		return;
	}
	int32_t dx = std::abs(x2 - x1), dy = -std::abs(y2 - y1), sx = x1 < x2 ? 1 : -1, sy = y1 < y2 ? 1 : -1, er = dx + dy;
	for (;;) {
		rect(x1, y1, 1, 1);
		if (x1 == x2 && y1 == y2) break;
		int32_t e2 = 2 * er;
		if (e2 >= dy) { er += dy; x1 += sx; }
		if (e2 <= dx) { er += dx; y1 += sy; }
	}
}
static int32_t round_inset(int32_t row, int32_t h, int32_t aw, int32_t ah) {
	double rx = std::min((double)aw, std::max(0.0, h > 0 ? (double)aw : 0.0)) / 2, ry = ah / 2.0;
	if (rx <= 0 || ry <= 0) return 0;
	double dy;
	if (row < ry) dy = ry - row - 0.5;
	else if (row >= h - ry) dy = row - (h - ry) + 0.5;
	else return 0;
	double t = std::max(0.0, 1 - (dy * dy) / (ry * ry));
	return (int32_t)std::floor(rx - rx * std::sqrt(t) + 0.5);
}
void Graphics::fillRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t aw, int32_t ah) {
	if (w <= 0 || h <= 0 || cw <= 0 || ch <= 0) return;
	int32_t ax = x + tx, ay = y + ty;
	aw = std::min(std::abs(aw), w);
	ah = std::min(std::abs(ah), h);
	for (int32_t r = 0; r < h; r++) {
		int32_t k = round_inset(r, h, aw, ah);
		rect(ax + k, ay + r, w - 2 * k, 1);
	}
}
void Graphics::drawRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t aw, int32_t ah) {
	if (w < 0 || h < 0 || cw <= 0 || ch <= 0) return;
	int32_t ax = x + tx, ay = y + ty, H = h + 1, W = w + 1;
	aw = std::min(std::abs(aw), W);
	ah = std::min(std::abs(ah), H);
	int32_t prev = round_inset(0, H, aw, ah);
	rect(ax + prev, ay, W - 2 * prev, 1);
	rect(ax + prev, ay + H - 1, W - 2 * prev, 1);
	for (int32_t r = 1; r < H - 1; r++) {
		int32_t k = round_inset(r, H, aw, ah);
		int32_t len = std::max(1, std::abs(prev - k));
		rect(ax + std::min(prev, k), ay + r, len, 1);
		rect(ax + W - std::min(prev, k) - len, ay + r, len, 1);
		prev = k;
	}
}
void Graphics::drawImage(const Ref<Image>& im, int32_t x, int32_t y, int32_t a) {
	if (!im.get()) throwNPE();
	drawRegion(im, 0, 0, im->w, im->h, 0, x, y, a == 0 ? 20 : a);
}
static int32_t anc_x(int32_t x, int32_t w, int32_t a) { return (a & 1) ? x - (w >> 1) : ((a & 8) ? x - w : x); }
static int32_t anc_y(int32_t y, int32_t h, int32_t a) { return (a & 2) ? y - (h >> 1) : ((a & 32) ? y - h : y); }
void Graphics::drawRegion(const Ref<Image>& im, int32_t sx, int32_t sy, int32_t w, int32_t h, int32_t tr, int32_t x, int32_t y, int32_t a) {
	if (!im.get()) throwNPE();
	if (w <= 0 || h <= 0) return;
	int32_t sw = tr >= 4 ? h : w, sh = tr >= 4 ? w : h;
	int32_t dx = anc_x(x, sw, a) + tx, dy = anc_y(y, sh, a) + ty;
	if (dx >= cx + cw || dy >= cy + ch || dx + sw <= cx || dy + sh <= cy) return;
	if (cw <= 0 || ch <= 0) return;
	int32_t x0 = std::max(dx, cx), y0 = std::max(dy, cy);
	int32_t x1 = std::min(dx + sw, cx + cw), y1 = std::min(dy + sh, cy + ch);
	Image* src = im.get();
	uint32_t* dp = target->px.data();
	int32_t DW = target->w;
	for (int32_t yy = y0; yy < y1; yy++) {
		int32_t ry = yy - dy;
		for (int32_t xx = x0; xx < x1; xx++) {
			int32_t rx = xx - dx, u, v;
			switch (tr) {
				default: u = rx; v = ry; break;
				case 1: u = rx; v = h - 1 - ry; break;
				case 2: u = w - 1 - rx; v = ry; break;
				case 3: u = w - 1 - rx; v = h - 1 - ry; break;
				case 4: u = ry; v = rx; break;
				case 5: u = ry; v = h - 1 - rx; break;
				case 6: u = w - 1 - ry; v = rx; break;
				case 7: u = w - 1 - ry; v = h - 1 - rx; break;
			}
			int32_t px = sx + u, py = sy + v;
			if (px < 0 || py < 0 || px >= src->w || py >= src->h) continue;
			uint32_t s = src->px[(size_t)py * src->w + px];
			uint32_t al = s >> 24;
			if (al == 0) continue;
			uint32_t& d = dp[(size_t)yy * DW + xx];
			if (al == 255) { d = s; continue; }
			uint32_t ia = 255 - al;
			uint32_t r = (((s >> 16) & 255) * al + ((d >> 16) & 255) * ia + 127) / 255;
			uint32_t g = (((s >> 8) & 255) * al + ((d >> 8) & 255) * ia + 127) / 255;
			uint32_t b = ((s & 255) * al + (d & 255) * ia + 127) / 255;
			d = 0xFF000000u | (r << 16) | (g << 8) | b;
		}
	}
	target->version++;
	if (rt.sm_rec && target == rt.sm_screen)
		rt.sm_cur->push_back(SmOp{0, im, sx, sy, w, h, tr, dx, dy, 0, {cx, cy, cw, ch}, dx, dy, false});
}

Ref<String> MIDlet::getAppProperty(const Ref<String>& key) {
	static const std::map<std::u16string, std::u16string> m = {
		{u"MIDlet-Version", u"1.0.3"}, {u"MIDlet-Name", u"Diamond Rush"}, {u"MIDlet-Vendor", u"Gameloft"}};
	auto it = m.find(key->s);
	return it == m.end() ? Ref<String>() : jstring(it->second);
}
void MIDlet::notifyDestroyed() { if (rt.stop) rt.stop("fin"); }

Ref<Display> Display::getDisplay(const Ref<MIDlet>&) {
	static Ref<Display>* d = new Ref<Display>(new Display());
	return *d;
}

Ref<GameCanvas> GameCanvas::init(bool) {
	canvasImage = Image::createImage(240, 320);
	std::fill(canvasImage->px.begin(), canvasImage->px.end(), 0xFF000000u);
	return this;
}
void GameCanvas::flushGraphics() { if (rt.flush) rt.flush(canvasImage.get()); }

static std::map<std::string, std::vector<std::vector<int8_t>>>& mem_stores() {
	static auto* m = new std::map<std::string, std::vector<std::vector<int8_t>>>();
	return *m;
}
static std::string store_path(const std::string& name) { return rt.save_dir + "rs_" + name + ".bin"; }
static bool store_load(const std::string& name, std::vector<std::vector<int8_t>>& out) {
	if (!rt.save_to_disk) {
		auto it = mem_stores().find(name);
		if (it == mem_stores().end()) return false;
		out = it->second;
		return true;
	}
	FILE* f = fopen(store_path(name).c_str(), "rb");
	if (!f) return false;
	uint32_t n = 0;
	bool ok = fread(&n, 4, 1, f) == 1;
	for (uint32_t i = 0; ok && i < n; i++) {
		uint32_t len = 0;
		ok = fread(&len, 4, 1, f) == 1 && len < (1u << 24);
		if (!ok) break;
		std::vector<int8_t> r(len);
		ok = len == 0 || fread(r.data(), 1, len, f) == len;
		out.push_back(std::move(r));
	}
	fclose(f);
	return ok;
}
void RecordStore::save() {
	if (!rt.save_to_disk) { mem_stores()[name] = recs; return; }
	std::string tmp = store_path(name) + ".tmp";
	FILE* f = fopen(tmp.c_str(), "wb");
	if (!f) return;
	uint32_t n = (uint32_t)recs.size();
	fwrite(&n, 4, 1, f);
	for (auto& r : recs) {
		uint32_t len = (uint32_t)r.size();
		fwrite(&len, 4, 1, f);
		if (len) fwrite(r.data(), 1, len, f);
	}
	fclose(f);
	std::remove(store_path(name).c_str());
	std::rename(tmp.c_str(), store_path(name).c_str());
}
Ref<RecordStore> RecordStore::openRecordStore(const Ref<String>& name, bool create) {
	Ref<RecordStore> rs(new RecordStore());
	rs->name = name->utf8();
	bool found = store_load(rs->name, rs->recs);
	if (!found && !create) jthrow(u"javax/microedition/rms/RecordStoreException", u"no existe " + name->s);
	if (!found) rs->save();
	return rs;
}
int32_t RecordStore::addRecord(const Arr<int8_t>& b, int32_t off, int32_t n) {
	if (off < 0 || n < 0 || off + n > b->length) jthrow(u"java/lang/ArrayIndexOutOfBoundsException");
	recs.emplace_back(b->data + off, b->data + off + n);
	save();
	return (int32_t)recs.size();
}
void RecordStore::setRecord(int32_t id, const Arr<int8_t>& b, int32_t off, int32_t n) {
	if (id < 1 || id > (int32_t)recs.size()) jthrow(u"javax/microedition/rms/InvalidRecordIDException");
	if (off < 0 || n < 0 || off + n > b->length) jthrow(u"java/lang/ArrayIndexOutOfBoundsException");
	recs[id - 1].assign(b->data + off, b->data + off + n);
	save();
}
Arr<int8_t> RecordStore::getRecord(int32_t id) {
	if (id < 1 || id > (int32_t)recs.size()) jthrow(u"javax/microedition/rms/InvalidRecordIDException");
	auto& r = recs[id - 1];
	auto a = newArray<int8_t>((int32_t)r.size());
	if (!r.empty()) memcpy(a->data, r.data(), r.size());
	return a;
}

static const int SND_PRIO[] = {10, 30, 30, 20, 30, 10, 10, 20, 20, 20, 10, 20, 20, 20, 10, 30, 30, 30, 30, 30, 30};
static int snd_cur = -1, snd_prio = 0;
static double snd_t0 = 0;

void sound_ended() { snd_cur = -1; snd_prio = 0; }
static void snd_stop_all() {
	if (rt.snd_stop) rt.snd_stop();
	snd_cur = -1;
	snd_prio = 0;
}
void Sound::stop() { snd_stop_all(); }
bool Sound::isPlaying() { return snd_cur != -1; }
void Sound::play(int32_t i) {
	if (!enabled || i < 0 || i >= (int32_t)(sizeof(SND_PRIO) / sizeof(SND_PRIO[0]))) return;
	int p = SND_PRIO[i];
	double now = rt.perf_ms ? rt.perf_ms() : 0;
	int cur = snd_prio;
	if (snd_cur == -1) cur = 0;
	else if (cur >= p && (cur != p || std::abs(now - snd_t0) <= 50)) return;
	if (p >= cur) {
		snd_cur = i;
		snd_prio = p;
		snd_t0 = now;
		if (rt.snd_play) rt.snd_play(i);
	}
}
