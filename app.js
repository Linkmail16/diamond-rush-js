'use strict';

const view = document.getElementById('screen');
const vctx = view.getContext('2d');
vctx.imageSmoothingEnabled = false;

let flushes = 0;
function present() {
	if (SM.on) return;
	if (SCREEN) vctx.drawImage(SCREEN, 0, 0);
	flushes++;
}

let VS = 1;
function fit() {
	const dpr = window.devicePixelRatio || 1;
	const H = SM.on ? Math.max(320, Math.round(view.clientHeight * dpr)) : 320;
	const Wd = SM.on ? Math.round(H * 3 / 4) : 240;
	if (view.width !== Wd || view.height !== H) {
		view.width = Wd;
		view.height = H;
		vctx.imageSmoothingEnabled = false;
		if (!SM.on && SCREEN) vctx.drawImage(SCREEN, 0, 0);
	}
	VS = H / 320;
}
addEventListener('resize', fit);
function frame() {
	if (SM.on && SCREEN) { sm_render(vctx, VS); flushes++; }
	requestAnimationFrame(frame);
}
requestAnimationFrame(frame);

const RATES = [20, 30, 60, 0];
const rateBtn = document.getElementById('rate'), fpsNow = document.getElementById('fpsnow');
let rateIdx = 0;
try { rateIdx = Math.max(0, RATES.indexOf(parseInt(localStorage.getItem('diamondrush.fps'), 10))); } catch (e) {}
function apply_rate() {
	const f = SM.on ? 20 : RATES[rateIdx];
	set_rate(f);
	rateBtn.disabled = SM.on;
	if (SM.on) { rateBtn.textContent = 'Game: 20 FPS'; rateBtn.classList.remove('fast'); return; }
	rateBtn.textContent = f ? 'Limit: ' + f + ' FPS' + (f === 20 ? ' (original)' : '') : 'No limit';
	rateBtn.classList.toggle('fast', f !== 20);
	try { localStorage.setItem('diamondrush.fps', String(f)); } catch (e) {}
}
function next_rate() { if (SM.on) return; rateIdx = (rateIdx + 1) % RATES.length; apply_rate(); }
const smoothBtn = document.getElementById('smooth');
function apply_smooth(on) {
	sm_set(on);
	smoothBtn.textContent = on ? 'Smooth: on' : 'Smooth: off';
	smoothBtn.classList.toggle('fast', on);
	try { localStorage.setItem('diamondrush.fluido', on ? '1' : '0'); } catch (e) {}
	fit();
	apply_rate();
}
smoothBtn.addEventListener('click', () => { apply_smooth(!SM.on); smoothBtn.blur(); });
rateBtn.addEventListener('click', (e) => { next_rate(); rateBtn.blur(); });
let smoothPref = true;
try { smoothPref = localStorage.getItem('diamondrush.fluido') !== '0'; } catch (e) {}
apply_smooth(smoothPref);
let fpsT = performance.now();
setInterval(() => {
	const t = performance.now();
	fpsNow.textContent = Math.round(flushes * 1000 / (t - fpsT)) + ' FPS';
	flushes = 0; fpsT = t;
}, 500);

const KEYMAP = {
	ArrowUp: -1, KeyW: -1, ArrowDown: -2, KeyS: -2, ArrowLeft: -3, KeyA: -3, ArrowRight: -4, KeyD: -4,
	Space: -5, Enter: -5, NumpadEnter: -5, KeyE: 53, KeyR: 42, KeyQ: -6, Escape: -7, KeyP: -7, Backspace: -7,
	Numpad5: 53, NumpadMultiply: 42,
};
for (let d = 0; d <= 9; d++) { KEYMAP['Digit' + d] = 48 + d; KEYMAP['Numpad' + d] = KEYMAP['Numpad' + d] || 48 + d; }
const held = new Set();
function key(code, down) {
	if (down) { if (held.has(code)) return; held.add(code); }
	else { if (!held.has(code)) return; held.delete(code); }
	game_key(code, down);
}
addEventListener('keydown', (e) => {
	if (e.code === 'KeyM') { toggle_mute(); return; }
	if (e.code === 'KeyF' && !e.repeat) { toggle_full(); return; }
	if (e.code === 'KeyL' && !e.repeat) { next_rate(); return; }
	if (e.code === 'KeyG' && !e.repeat) { apply_smooth(!SM.on); return; }
	const k = KEYMAP[e.code];
	if (k === undefined) return;
	e.preventDefault();
	if (!e.repeat) key(k, true);
});
addEventListener('keyup', (e) => {
	const k = KEYMAP[e.code];
	if (k === undefined) return;
	e.preventDefault();
	key(k, false);
});
addEventListener('blur', () => { for (const k of [...held]) key(k, false); });

for (const b of document.querySelectorAll('[data-key]')) {
	const k = parseInt(b.dataset.key, 10);
	const on = (e) => { e.preventDefault(); b.classList.add('on'); key(k, true); };
	const off = (e) => { e.preventDefault(); b.classList.remove('on'); key(k, false); };
	b.addEventListener('pointerdown', on);
	b.addEventListener('pointerup', off);
	b.addEventListener('pointercancel', off);
	b.addEventListener('pointerleave', off);
}
if (matchMedia('(pointer: coarse)').matches || 'ontouchstart' in window) document.body.classList.add('touch');

let softHeld = 0;
view.addEventListener('pointerdown', (e) => {
	const r = view.getBoundingClientRect();
	const x = (e.clientX - r.left) * 240 / r.width, y = (e.clientY - r.top) * 320 / r.height;
	if (y < 276) return;
	softHeld = x < 80 ? -6 : x > 160 ? -7 : 0;
	if (!softHeld) return;
	e.preventDefault();
	key(softHeld, true);
});
const softUp = () => { if (softHeld) { key(softHeld, false); softHeld = 0; } };
view.addEventListener('pointerup', softUp);
view.addEventListener('pointercancel', softUp);
view.addEventListener('pointerleave', softUp);

function toggle_mute() {
	if (!SND.ctx) return;
	if (!SND.gain) return;
	SND.gain.gain.value = SND.gain.gain.value > 0 ? 0 : 1;
}
function toggle_full() {
	if (document.fullscreenElement) document.exitFullscreen();
	else document.documentElement.requestFullscreen().catch(() => {});
}
document.addEventListener('visibilitychange', () => {
	const hidden = document.hidden;
	game_pause(hidden);
	if (SND.ctx) { if (hidden) SND.ctx.suspend(); else SND.ctx.resume(); }
});

const start = document.getElementById('start');
const play = document.getElementById('play');
const msg = document.getElementById('msg');
G.onstop = (why) => {
	start.classList.remove('hidden');
	play.textContent = 'Play again';
	play.disabled = false;
	msg.textContent = why === 'fin' ? '' : String(why);
};
let ready = png_preload();
ready.then(() => { play.disabled = false; play.textContent = 'Play'; })
	.catch((e) => { msg.textContent = 'Could not load: ' + e; });
play.addEventListener('click', async () => {
	if (G.game) { location.reload(); return; }
	play.disabled = true;
	play.textContent = 'Loading sound…';
	if (!SND.ctx) {
		await snd_init();
		if (SND.ctx) {
			SND.gain = SND.ctx.createGain();
			SND.gain.connect(SND.ctx.destination);
			SND.ctx.resume();
		}
	}
	start.classList.add('hidden');
	try {
		boot();
	} catch (e) {
		console.error(e);
		G.onstop('Startup error: ' + e);
	}
});
