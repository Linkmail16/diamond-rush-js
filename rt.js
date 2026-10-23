'use strict';

const SCR_W = 240, SCR_H = 320;
const DEBUG = /[?&]debug/.test(location.search);

class Throwable {
	constructor(cls, msg) { this.cls = cls || 'java/lang/Throwable'; this.msg = msg || ''; }
	printStackTrace() { if (DEBUG) console.warn('[java] exception', this); }
}
const EXC_PARENT = {
	'java/lang/Throwable': null, 'java/lang/Exception': 'java/lang/Throwable', 'java/lang/Error': 'java/lang/Throwable',
	'java/lang/RuntimeException': 'java/lang/Exception', 'java/io/IOException': 'java/lang/Exception',
	'java/lang/InterruptedException': 'java/lang/Exception',
	'java/lang/ArrayIndexOutOfBoundsException': 'java/lang/RuntimeException',
	'java/lang/StringIndexOutOfBoundsException': 'java/lang/RuntimeException',
	'java/lang/NullPointerException': 'java/lang/RuntimeException',
	'java/lang/ArithmeticException': 'java/lang/RuntimeException',
	'java/lang/NegativeArraySizeException': 'java/lang/RuntimeException',
	'java/lang/ClassCastException': 'java/lang/RuntimeException',
	'java/lang/IllegalArgumentException': 'java/lang/RuntimeException',
	'java/lang/IllegalStateException': 'java/lang/RuntimeException',
	'java/lang/OutOfMemoryError': 'java/lang/Error',
	'javax/microedition/media/MediaException': 'java/lang/Exception',
	'javax/microedition/rms/RecordStoreException': 'java/lang/Exception',
	'javax/microedition/rms/InvalidRecordIDException': 'javax/microedition/rms/RecordStoreException',
	'javax/microedition/midlet/MIDletStateChangeException': 'java/lang/Exception',
};
function jthrow(cls, msg) { throw new Throwable('java/lang/' + cls, msg); }

const J = {
	exc(ex) {
		if (ex instanceof Throwable) return ex;
		if (DEBUG) console.warn('[java] JS error as exception:', ex);
		if (ex instanceof TypeError) return new Throwable('java/lang/NullPointerException', String(ex));
		if (ex instanceof RangeError) return new Throwable('java/lang/NegativeArraySizeException', String(ex));
		return new Throwable('java/lang/Error', String(ex));
	},
	isa(ex, cls) {
		for (let c = ex.cls; c; c = EXC_PARENT[c]) if (c === cls) return true;
		return false;
	},
	idiv(a, b) { if (b === 0) jthrow('ArithmeticException', '/ by zero'); return (a / b) | 0; },
	irem(a, b) { if (b === 0) jthrow('ArithmeticException', '/ by zero'); return (a % b) | 0; },
	ldiv(a, b) { if (b === 0n) jthrow('ArithmeticException', '/ by zero'); return BigInt.asIntN(64, a / b); },
	lrem(a, b) { if (b === 0n) jthrow('ArithmeticException', '/ by zero'); return a % b; },
	lcmp(a, b) { return a < b ? -1 : (a > b ? 1 : 0); },
	labs(v) { return v < 0n ? BigInt.asIntN(64, -v) : v; },
	newArray(n) {
		if (n < 0) jthrow('NegativeArraySizeException', String(n));
		return new Array(n).fill(null);
	},
	multiArray(T, levels, dims) {
		const mk = (k) => {
			if (k === levels - 1) {
				if (dims[k] < 0) jthrow('NegativeArraySizeException');
				return T === Array ? new Array(dims[k]).fill(null) : new T(dims[k]);
			}
			const a = J.newArray(dims[k]);
			if (k + 1 < dims.length) for (let i = 0; i < a.length; i++) a[i] = mk(k + 1);
			return a;
		};
		return mk(0);
	},
	getClass(o) { return JClass.forName(typeof o === 'string' ? 'java/lang/String' : (o.constructor && o.constructor.name) || 'Object'); },
	newString(b, off, len, enc) {
		const u = new Uint8Array(b.buffer, b.byteOffset + off, len);
		const e = enc ? enc.toLowerCase() : 'iso-8859-1';
		try { return new TextDecoder(e === 'utf-8' || e === 'utf8' ? 'utf-8' : 'iso-8859-1').decode(u); }
		catch (x) { return String.fromCharCode.apply(null, u); }
	},
	indexOf(s, c, from) { return s.indexOf(String.fromCharCode(c), from === undefined ? 0 : Math.max(0, from)); },
	getBytes(s) {
		const a = new Int8Array(s.length);
		for (let i = 0; i < s.length; i++) a[i] = s.charCodeAt(i);
		return a;
	},
	compareTo(a, b) {
		const n = Math.min(a.length, b.length);
		for (let i = 0; i < n; i++) if (a.charCodeAt(i) !== b.charCodeAt(i)) return a.charCodeAt(i) - b.charCodeAt(i);
		return a.length - b.length;
	},
};

const TIME0 = Date.now() - performance.now();
class PrintStream {
	println(x) { if (DEBUG) console.log('[java]', x); }
}
class JSystem {
	static currentTimeMillis() { return BigInt(Math.floor(performance.now() + TIME0)); }
	static gc() {}
	static arraycopy(src, sp, dst, dp, n) {
		if (src === null || dst === null) jthrow('NullPointerException');
		if (n < 0 || sp < 0 || dp < 0 || sp + n > src.length || dp + n > dst.length) jthrow('ArrayIndexOutOfBoundsException');
		if (src === dst) {
			if (src.copyWithin) src.copyWithin(dp, sp, sp + n);
			else { const t = src.slice(sp, sp + n); for (let i = 0; i < n; i++) dst[dp + i] = t[i]; }
		} else if (dst.set && src.subarray) dst.set(src.subarray(sp, sp + n), dp);
		else for (let i = 0; i < n; i++) dst[dp + i] = src[sp + i];
	}
}
JSystem.out = new PrintStream();
class Thread {
	constructor(r) { this.r = r || null; }
	start() { if (this.r instanceof Game) game_start(this.r); }
	setPriority(p) {}
	static sleep(ms) {}
	static yield() {}
}
class Integer {
	constructor(v) { this.value = v; }
	intValue() { return this.value; }
	byteValue() { return (this.value << 24) >> 24; }
}
class StringBuffer {
	constructor(s) { this.s = s === undefined ? '' : String(s); }
	append(x) { this.s += x === null ? 'null' : (x instanceof StringBuffer ? x.s : String(x)); return this; }
	toString() { return this.s; }
	length() { return this.s.length; }
	charAt(i) {
		if (i < 0 || i >= this.s.length) jthrow('StringIndexOutOfBoundsException', String(i));
		return this.s.charCodeAt(i);
	}
	delete(a, e) {
		if (a < 0 || a > this.s.length || a > e) jthrow('StringIndexOutOfBoundsException');
		this.s = this.s.slice(0, a) + this.s.slice(Math.min(e, this.s.length));
		return this;
	}
	setCharAt(i, c) {
		if (i < 0 || i >= this.s.length) jthrow('StringIndexOutOfBoundsException', String(i));
		this.s = this.s.slice(0, i) + String.fromCharCode(c) + this.s.slice(i + 1);
	}
}
class Hashtable {
	constructor() { this.m = new Map(); }
	static key(k) {
		if (typeof k === 'string') return 'S' + k;
		if (k instanceof Integer) return 'I' + k.value;
		return k;
	}
	put(k, v) {
		if (k === null || v === null) jthrow('NullPointerException');
		const kk = Hashtable.key(k), old = this.m.has(kk) ? this.m.get(kk) : null;
		this.m.set(kk, v);
		return old;
	}
	get(k) { const kk = Hashtable.key(k); return this.m.has(kk) ? this.m.get(kk) : null; }
}
class Random {
	constructor(seed) { this.seed = (seed ^ 0x5DEECE66Dn) & ((1n << 48n) - 1n); }
	nextInt() {
		this.seed = (this.seed * 0x5DEECE66Dn + 0xBn) & ((1n << 48n) - 1n);
		return Number(BigInt.asIntN(32, this.seed >> 16n));
	}
}

const RES = {};
for (const k in RES_B64) {
	const bin = atob(RES_B64[k]);
	const u = new Uint8Array(bin.length);
	for (let i = 0; i < bin.length; i++) u[i] = bin.charCodeAt(i);
	RES[k] = u;
}
class InputStream {
	constructor(buf) { this.buf = buf; this.pos = 0; }
	read(b, off, len) {
		if (b === undefined) return this.pos < this.buf.length ? this.buf[this.pos++] : -1;
		if (off === undefined) { off = 0; len = b.length; }
		if (len === 0) return 0;
		if (this.pos >= this.buf.length) return -1;
		const n = Math.min(len, this.buf.length - this.pos);
		for (let i = 0; i < n; i++) b[off + i] = this.buf[this.pos + i];
		this.pos += n;
		return n;
	}
	skip(n) {
		const k = Math.max(0, Math.min(Number(n), this.buf.length - this.pos));
		this.pos += k;
		return BigInt(k);
	}
	close() {}
}
class ByteArrayInputStream extends InputStream {
	constructor(b) { super(new Uint8Array(b.buffer, b.byteOffset, b.length)); }
}
class JClass {
	constructor(name) { this.name = name; }
	static forName(n) { return JClass.all[n] || (JClass.all[n] = new JClass(n)); }
	getResourceAsStream(name) {
		const n = name.startsWith('/') ? name.slice(1) : name;
		return RES[n] ? new InputStream(RES[n]) : null;
	}
}
JClass.all = {};
class JObject {}

function fnv(u, off, len) {
	let h = 0x811C9DC5;
	for (let i = 0; i < len; i++) { h ^= u[off + i] & 0xFF; h = Math.imul(h, 0x01000193); }
	return h >>> 0;
}
const PNG = new Map();
function png_preload() {
	const jobs = [];
	for (const k in RES) {
		const u = RES[k];
		for (let p = 0; p + 8 < u.length; p++) {
			if (u[p] !== 0x89 || u[p + 1] !== 0x50 || u[p + 2] !== 0x4E || u[p + 3] !== 0x47) continue;
			let q = p + 8;
			while (q + 8 <= u.length) {
				const len = (u[q] << 24 | u[q + 1] << 16 | u[q + 2] << 8 | u[q + 3]) >>> 0;
				const t = String.fromCharCode(u[q + 4], u[q + 5], u[q + 6], u[q + 7]);
				q += 12 + len;
				if (t === 'IEND') break;
			}
			const bytes = u.slice(p, q), h = fnv(bytes, 0, bytes.length);
			jobs.push(createImageBitmap(new Blob([bytes], { type: 'image/png' })).then(bmp => {
				const c = mkcanvas(bmp.width, bmp.height);
				c.getContext('2d').drawImage(bmp, 0, 0);
				PNG.set(h, c);
			}).catch(() => {}));
			p = q - 1;
		}
	}
	return Promise.all(jobs);
}

function mkcanvas(w, h) {
	const c = document.createElement('canvas');
	c.width = Math.max(1, w); c.height = Math.max(1, h);
	c.getContext('2d').imageSmoothingEnabled = false;
	return c;
}
let IMG_ID = 0;
class Image {
	constructor(c, mutable) { this.c = c; this.w = c.width; this.h = c.height; this.mutable = mutable; this.id = ++IMG_ID; }
	static createImage(a, b, c) {
		if (typeof a === 'string') {
			const n = a.startsWith('/') ? a.slice(1) : a;
			const d = RES[n], cv = d && PNG.get(fnv(d, 0, d.length));
			if (!cv) throw new Throwable('java/io/IOException', 'no hay ' + n);
			return new Image(cv, false);
		}
		if (typeof a === 'number') {
			if (a <= 0 || b <= 0) jthrow('IllegalArgumentException');
			const cv = mkcanvas(a, b), x = cv.getContext('2d');
			x.fillStyle = '#fff';
			x.fillRect(0, 0, a, b);
			return new Image(cv, true);
		}
		const u = new Uint8Array(a.buffer, a.byteOffset, a.length);
		const cv = PNG.get(fnv(u, b, c));
		if (!cv) jthrow('IllegalArgumentException', 'PNG');
		return new Image(cv, false);
	}
	static createRGBImage(rgb, w, h, alpha) {
		const c = mkcanvas(w, h), x = c.getContext('2d');
		const id = x.createImageData(w, h), d = id.data;
		for (let i = 0, n = w * h; i < n; i++) {
			const v = rgb[i];
			d[4 * i] = (v >> 16) & 255; d[4 * i + 1] = (v >> 8) & 255; d[4 * i + 2] = v & 255;
			d[4 * i + 3] = alpha ? (v >>> 24) : 255;
		}
		x.putImageData(id, 0, 0);
		return new Image(c, false);
	}
	getWidth() { return this.w; }
	getHeight() { return this.h; }
	getGraphics() {
		if (!this.mutable) jthrow('IllegalStateException');
		return new Graphics(this.c);
	}
}
function anc_x(x, w, a) { return (a & 1) ? x - (w >> 1) : ((a & 8) ? x - w : x); }
function anc_y(y, h, a) { return (a & 2) ? y - (h >> 1) : ((a & 32) ? y - h : y); }
function round_inset(row, h, aw, ah) {
	const rx = Math.min(aw, Math.max(0, h > 0 ? aw : 0)) / 2, ry = ah / 2;
	if (rx <= 0 || ry <= 0) return 0;
	let dy = 0;
	if (row < ry) dy = ry - row - 0.5;
	else if (row >= h - ry) dy = row - (h - ry) + 0.5;
	else return 0;
	const t = Math.max(0, 1 - (dy * dy) / (ry * ry));
	return Math.round(rx - rx * Math.sqrt(t));
}
class Graphics {
	constructor(c) {
		this.x = c.getContext('2d'); this.w = c.width; this.h = c.height;
		this.tx = 0; this.ty = 0; this.cx = 0; this.cy = 0; this.cw = c.width; this.ch = c.height;
		this.col = 0; this.css = '#000';
	}
	translate(x, y) { this.tx += x; this.ty += y; }
	setColor(r, g, b) {
		const c = g === undefined ? r : ((r & 255) << 16) | ((g & 255) << 8) | (b & 255);
		this.col = c & 0xFFFFFF;
		this.css = '#' + this.col.toString(16).padStart(6, '0');
	}
	setClip(x, y, w, h) {
		x += this.tx; y += this.ty;
		const x0 = Math.max(0, x), y0 = Math.max(0, y), x1 = Math.min(this.w, x + w), y1 = Math.min(this.h, y + h);
		this.cx = x0; this.cy = y0; this.cw = Math.max(0, x1 - x0); this.ch = Math.max(0, y1 - y0);
	}
	clipRect(x, y, w, h) {
		const ax = x + this.tx, ay = y + this.ty;
		const x0 = Math.max(this.cx, ax), y0 = Math.max(this.cy, ay);
		const x1 = Math.min(this.cx + this.cw, ax + w), y1 = Math.min(this.cy + this.ch, ay + h);
		this.cx = x0; this.cy = y0; this.cw = Math.max(0, x1 - x0); this.ch = Math.max(0, y1 - y0);
	}
	getClipX() { return this.cx - this.tx; }
	getClipY() { return this.cy - this.ty; }
	getClipWidth() { return this.cw; }
	getClipHeight() { return this.ch; }
	clipBegin() {
		if (this.cw <= 0 || this.ch <= 0) return false;
		const x = this.x;
		x.save();
		if (this.cx > 0 || this.cy > 0 || this.cw < this.w || this.ch < this.h) {
			x.beginPath();
			x.rect(this.cx, this.cy, this.cw, this.ch);
			x.clip();
		}
		return true;
	}
	pr(x, y, w, h) {
		this.x.fillRect(x, y, w, h);
		if (SM.rec && this.x === SCREEN_CTX) SM.cur.push({ t: 1, css: this.css, dx: x, dy: y, w, h, cl: [this.cx, this.cy, this.cw, this.ch] });
	}
	fillRect(x, y, w, h) {
		if (w <= 0 || h <= 0 || !this.clipBegin()) return;
		this.x.fillStyle = this.css;
		this.pr(x + this.tx, y + this.ty, w, h);
		this.x.restore();
	}
	drawRect(x, y, w, h) {
		if (w < 0 || h < 0 || !this.clipBegin()) return;
		const ax = x + this.tx, ay = y + this.ty;
		this.x.fillStyle = this.css;
		this.pr(ax, ay, w + 1, 1); this.pr(ax, ay + h, w + 1, 1);
		this.pr(ax, ay, 1, h + 1); this.pr(ax + w, ay, 1, h + 1);
		this.x.restore();
	}
	drawLine(x1, y1, x2, y2) {
		if (!this.clipBegin()) return;
		this.x.fillStyle = this.css;
		x1 += this.tx; x2 += this.tx; y1 += this.ty; y2 += this.ty;
		if (x1 === x2 || y1 === y2) this.pr(Math.min(x1, x2), Math.min(y1, y2), Math.abs(x2 - x1) + 1, Math.abs(y2 - y1) + 1);
		else {
			let dx = Math.abs(x2 - x1), dy = -Math.abs(y2 - y1), sx = x1 < x2 ? 1 : -1, sy = y1 < y2 ? 1 : -1, er = dx + dy;
			for (;;) {
				this.pr(x1, y1, 1, 1);
				if (x1 === x2 && y1 === y2) break;
				const e2 = 2 * er;
				if (e2 >= dy) { er += dy; x1 += sx; }
				if (e2 <= dx) { er += dx; y1 += sy; }
			}
		}
		this.x.restore();
	}
	fillRoundRect(x, y, w, h, aw, ah) {
		if (w <= 0 || h <= 0 || !this.clipBegin()) return;
		const ax = x + this.tx, ay = y + this.ty;
		aw = Math.min(Math.abs(aw), w); ah = Math.min(Math.abs(ah), h);
		this.x.fillStyle = this.css;
		for (let r = 0; r < h; r++) {
			const k = round_inset(r, h, aw, ah);
			this.pr(ax + k, ay + r, w - 2 * k, 1);
		}
		this.x.restore();
	}
	drawRoundRect(x, y, w, h, aw, ah) {
		if (w < 0 || h < 0 || !this.clipBegin()) return;
		const ax = x + this.tx, ay = y + this.ty, H = h + 1, W = w + 1;
		aw = Math.min(Math.abs(aw), W); ah = Math.min(Math.abs(ah), H);
		this.x.fillStyle = this.css;
		let prev = round_inset(0, H, aw, ah);
		this.pr(ax + prev, ay, W - 2 * prev, 1);
		this.pr(ax + prev, ay + H - 1, W - 2 * prev, 1);
		for (let r = 1; r < H - 1; r++) {
			const k = round_inset(r, H, aw, ah);
			const len = Math.max(1, Math.abs(prev - k));
			this.pr(ax + Math.min(prev, k), ay + r, len, 1);
			this.pr(ax + W - Math.min(prev, k) - len, ay + r, len, 1);
			prev = k;
		}
		this.x.restore();
	}
	drawImage(im, x, y, a) {
		if (im === null) jthrow('NullPointerException');
		this.drawRegion(im, 0, 0, im.w, im.h, 0, x, y, a === 0 ? 20 : a);
	}
	drawRegion(im, sx, sy, w, h, tr, x, y, a) {
		if (im === null) jthrow('NullPointerException');
		if (w <= 0 || h <= 0) return;
		const sw = tr >= 4 ? h : w, sh = tr >= 4 ? w : h;
		const dx = anc_x(x, sw, a) + this.tx, dy = anc_y(y, sh, a) + this.ty;
		if (dx >= this.cx + this.cw || dy >= this.cy + this.ch || dx + sw <= this.cx || dy + sh <= this.cy) return;
		if (!this.clipBegin()) return;
		const c = this.x;
		set_transform(c, tr, 1, dx, dy, w, h);
		c.drawImage(im.c, sx, sy, w, h, 0, 0, w, h);
		c.restore();
		if (SM.rec && c === SCREEN_CTX) SM.cur.push({ t: 0, im, sx, sy, w, h, tr, dx, dy, cl: [this.cx, this.cy, this.cw, this.ch] });
	}
}
function set_transform(c, tr, S, e, f, w, h) {
	switch (tr) {
		case 0: c.setTransform(S, 0, 0, S, e, f); break;
		case 1: c.setTransform(S, 0, 0, -S, e, f + h * S); break;
		case 2: c.setTransform(-S, 0, 0, S, e + w * S, f); break;
		case 3: c.setTransform(-S, 0, 0, -S, e + w * S, f + h * S); break;
		case 4: c.setTransform(0, S, S, 0, e, f); break;
		case 5: c.setTransform(0, S, -S, 0, e + h * S, f); break;
		case 6: c.setTransform(0, -S, S, 0, e, f + w * S); break;
		case 7: c.setTransform(0, -S, -S, 0, e + h * S, f + w * S); break;
	}
}

const MANIFEST = { 'MIDlet-Version': '1.0.3', 'MIDlet-Name': 'Diamond Rush', 'MIDlet-Vendor': 'Gameloft' };
class MIDlet {
	getAppProperty(k) { const v = MANIFEST[k]; return v === undefined ? null : v; }
	notifyDestroyed() { game_stop('fin'); }
	notifyPaused() {}
	platformRequest(url) { return 0; }
}
class Display {
	static getDisplay(m) { return Display.the || (Display.the = new Display()); }
	setCurrent(c) { this.cur = c; }
	vibrate(ms) { try { if (navigator.vibrate && ms > 0) navigator.vibrate(ms); } catch (e) {} return 1; }
}
let SCREEN = null, SCREEN_CTX = null;
class GameCanvas {
	init(suppressKeys) {
		SCREEN = mkcanvas(SCR_W, SCR_H);
		SCREEN_CTX = SCREEN.getContext('2d');
		SCREEN_CTX.fillStyle = '#000';
		SCREEN_CTX.fillRect(0, 0, SCR_W, SCR_H);
		return this;
	}
	setFullScreenMode(b) {}
	getGraphics() { return new Graphics(SCREEN); }
	flushGraphics() { present(); }
}

class RecordStore {
	constructor(name, recs) { this.name = name; this.recs = recs; }
	static load(name) {
		try { const v = localStorage.getItem('diamondrush.rs.' + name); return v ? JSON.parse(v) : null; } catch (e) { return null; }
	}
	save() { try { localStorage.setItem('diamondrush.rs.' + this.name, JSON.stringify(this.recs)); } catch (e) {} }
	static openRecordStore(name, create) {
		const recs = RecordStore.load(name);
		if (recs === null && !create) throw new Throwable('javax/microedition/rms/RecordStoreException', 'no existe ' + name);
		const rs = new RecordStore(name, recs || []);
		if (recs === null) rs.save();
		return rs;
	}
	closeRecordStore() {}
	getNumRecords() { return this.recs.length; }
	static pack(b, off, n) { let s = ''; for (let i = 0; i < n; i++) s += String.fromCharCode(b[off + i] & 255); return btoa(s); }
	addRecord(b, off, n) { this.recs.push(RecordStore.pack(b, off, n)); this.save(); return this.recs.length; }
	setRecord(id, b, off, n) {
		if (id < 1 || id > this.recs.length) throw new Throwable('javax/microedition/rms/InvalidRecordIDException');
		this.recs[id - 1] = RecordStore.pack(b, off, n);
		this.save();
	}
	getRecord(id) {
		if (id < 1 || id > this.recs.length) throw new Throwable('javax/microedition/rms/InvalidRecordIDException');
		const s = atob(this.recs[id - 1]), a = new Int8Array(s.length);
		for (let i = 0; i < s.length; i++) a[i] = s.charCodeAt(i);
		return a;
	}
}

const SND_PRIO = [10, 30, 30, 20, 30, 10, 10, 20, 20, 20, 10, 20, 20, 20, 10, 30, 30, 30, 30, 30, 30];
const SND = { ctx: null, buf: [], cur: -1, prio: 0, t0: 0, node: null, gain: null };
class Sound {
	static enabled = 1;
	load(i) {}
	start() {}
	open() {}
	close() {}
	release() { this.stop(); }
	stop() { snd_stop(); }
	static isPlaying() { return SND.cur !== -1; }
	play(i) {
		if (!Sound.enabled || i < 0 || i >= SND_PRIO.length) return;
		const p = SND_PRIO[i], now = performance.now();
		let cur = SND.prio;
		if (SND.cur === -1) cur = 0;
		else if (cur >= p && (cur !== p || Math.abs(now - SND.t0) <= 50)) return;
		if (p >= cur) {
			SND.cur = i; SND.prio = p; SND.t0 = now;
			snd_play(i);
		}
	}
}
function snd_init() {
	try { SND.ctx = new (window.AudioContext || window.webkitAudioContext)(); } catch (e) { return Promise.resolve(); }
	const jobs = [];
	for (let i = 0; i < SND_PRIO.length; i++) {
		const bin = atob(SND_B64[i]), u = new Uint8Array(bin.length);
		for (let k = 0; k < bin.length; k++) u[k] = bin.charCodeAt(k);
		jobs.push(SND.ctx.decodeAudioData(u.buffer).then(b => { SND.buf[i] = b; }).catch(() => {}));
	}
	return Promise.all(jobs);
}
function snd_stop() {
	if (SND.node) { try { SND.node.onended = null; SND.node.stop(); } catch (e) {} SND.node = null; }
	SND.cur = -1; SND.prio = 0;
}
function snd_play(i) {
	if (SND.node) { try { SND.node.onended = null; SND.node.stop(); } catch (e) {} SND.node = null; }
	if (!SND.ctx || !SND.buf[i]) return;
	const n = SND.ctx.createBufferSource();
	n.buffer = SND.buf[i];
	n.connect(SND.gain || SND.ctx.destination);
	n.onended = () => { if (SND.node === n) { SND.node = null; SND.cur = -1; SND.prio = 0; } };
	n.start();
	SND.node = n;
}

const SM = { on: false, rec: false, ready: false, base: null, pbase: null, cur: [], prev: [], tN: 0, cam: [0, 0] };
function sm_cam(game) { return [game.camX | 0, game.camY | 0]; }
function sm_begin(game) {
	if (!SM.on || !SCREEN) { SM.rec = false; return; }
	if (!SM.base) { SM.base = mkcanvas(SCR_W, SCR_H); SM.pbase = mkcanvas(SCR_W, SCR_H); }
	SM.pbase.getContext('2d').drawImage(SCREEN, 0, 0);
	SM.prev = SM.cur;
	SM.cur = [];
	SM.cam = sm_cam(game);
	SM.rec = true;
}
function sm_key(o) { return o.t === 0 ? o.im.id + '|' + o.sx + '|' + o.sy + '|' + o.w + '|' + o.h + '|' + o.tr : 'R' + o.css + '|' + o.w + '|' + o.h; }
function sm_end(game) {
	if (!SM.rec) return;
	SM.rec = false;
	const t = SM.base; SM.base = SM.pbase; SM.pbase = t;
	const l = Game.screen, c1 = sm_cam(game);
	const play = l === 1 || l === 2;
	const sx = play ? SM.cam[0] - c1[0] : 0, sy = play ? SM.cam[1] - c1[1] : 0;
	const scroll = (sx !== 0 || sy !== 0) && Math.abs(sx) < 64 && Math.abs(sy) < 64;
	const exact = new Map(), loose = new Map();
	for (const p of SM.prev) {
		p.used = false;
		const k = sm_key(p);
		if (!exact.has(k)) exact.set(k, []);
		exact.get(k).push(p);
		if (p.t === 0) {
			const k2 = p.w + 'x' + p.h + '|' + p.tr;
			if (!loose.has(k2)) loose.set(k2, []);
			loose.get(k2).push(p);
		}
	}
	const pick = (list, o, lim) => {
		let best = null, bd = lim;
		if (!list) return null;
		for (const p of list) {
			if (p.used) continue;
			const d0 = Math.abs(p.dx - o.dx) + Math.abs(p.dy - o.dy);
			const d1 = scroll ? Math.abs(p.dx + sx - o.dx) + Math.abs(p.dy + sy - o.dy) : d0;
			const d = Math.min(d0, d1);
			if (d < bd) { bd = d; best = p; }
		}
		return best;
	};
	const inPlay = (o) => o.cl[1] >= 16 && o.cl[1] <= 48 && o.cl[3] <= 248;
	const rest = [];
	for (const o of SM.cur) {
		const p = pick(exact.get(sm_key(o)), o, 40);
		if (p) { p.used = true; o.mx = p.dx; o.my = p.dy; } else rest.push(o);
	}
	for (const o of rest) {
		const p = o.t === 0 ? pick(loose.get(o.w + 'x' + o.h + '|' + o.tr), o, 24) : null;
		if (p) { p.used = true; o.mx = p.dx; o.my = p.dy; }
		else if (scroll && inPlay(o)) { o.mx = o.dx - sx; o.my = o.dy - sy; }
		else { o.mx = o.dx; o.my = o.dy; }
	}
	SM.tN = performance.now();
	SM.ready = true;
}
function sm_render(ctx, S) {
	ctx.setTransform(1, 0, 0, 1, 0, 0);
	ctx.imageSmoothingEnabled = false;
	if (!SM.ready || !SM.base) { if (SCREEN) ctx.drawImage(SCREEN, 0, 0, SCR_W * S, SCR_H * S); return; }
	const a = Math.min(1, Math.max(0, (performance.now() - SM.tN) / (G.dt || 50))), b = 1 - a;
	ctx.drawImage(SM.base, 0, 0, SCR_W * S, SCR_H * S);
	const q = (v) => Math.round(v * S) / S;
	for (const o of SM.cur) {
		const X = o.dx + q((o.mx - o.dx) * b), Y = o.dy + q((o.my - o.dy) * b);
		let cx = o.cl[0], cy = o.cl[1];
		const cw = o.cl[2], ch = o.cl[3];
		if (cw * ch < 240 * 200) { cx += X - o.dx; cy += Y - o.dy; }
		ctx.save();
		if (cx > 0 || cy > 0 || cw < SCR_W || ch < SCR_H) {
			ctx.beginPath();
			ctx.rect(cx * S, cy * S, cw * S, ch * S);
			ctx.clip();
		}
		if (o.t === 1) {
			ctx.fillStyle = o.css;
			ctx.fillRect(X * S, Y * S, o.w * S, o.h * S);
		} else {
			set_transform(ctx, o.tr, S, X * S, Y * S, o.w, o.h);
			ctx.drawImage(o.im.c, o.sx, o.sy, o.w, o.h, 0, 0, o.w, o.h);
		}
		ctx.restore();
	}
}
function sm_set(on) {
	SM.on = on;
	SM.ready = false;
	SM.rec = false;
	SM.cur = []; SM.prev = [];
}

const G = { game: null, timer: 0, next: 0, running: false, onstop: null, soundAsk: 0, tickNo: 0, downAt: new Map(), ups: [], dt: 50 };
const TICK_CH = new MessageChannel();
TICK_CH.port1.onmessage = () => tick();
function set_rate(fps) {
	G.dt = fps > 0 ? 1000 / fps : 0;
	G.next = performance.now();
	if (G.running) { clearTimeout(G.timer); G.timer = setTimeout(tick, 0); }
}
function game_start(game) {
	G.game = game;
	game.startTime = JSystem.currentTimeMillis();
	game.resetCounters();
	game.loadPreferences();
	G.running = true;
	G.next = performance.now();
	tick();
}
function tick() {
	if (!G.running) return;
	const game = G.game;
	try {
		if (game.quit) { game_end(); return; }
		if (!game.paused) {
			sm_begin(game);
			game.frameStart = JSystem.currentTimeMillis();
			try { game.update(); } catch (ex) { if (DEBUG) console.warn('[game] exception in update()', ex); }
			if (game.quit) { game_end(); return; }
			if (Game.screen !== 2) Game.frameCount = (Game.frameCount + 1) | 0;
			if (Game.screen === 7 && G.soundAsk < 2) {
				game_key(-5, G.soundAsk === 0);
				G.soundAsk++;
			}
			game.frameUpdated = JSystem.currentTimeMillis();
			if (game.frameTime > 65n) {
				game.frameSkipped = 1;
				game.frameTime = 0n;
			} else {
				try { game.paint(game.getGraphics()); } catch (ex) { if (DEBUG) console.warn('[game] exception while painting', ex); }
				game.flushGraphics();
				game.frameSkipped = 0;
				if (Game.screen !== 2) Game.drawCount = (Game.drawCount + 1) | 0;
				game.frameTime = J.labs(JSystem.currentTimeMillis() - game.frameStart);
			}
		}
		sm_end(game);
		G.tickNo++;
		if (G.ups.length) { const u = G.ups; G.ups = []; for (const k of u) key_up(k); }
	} catch (ex) {
		console.error('[game]', ex);
	}
	if (G.dt === 0) { TICK_CH.port2.postMessage(0); return; }
	G.next += G.dt;
	const t = performance.now();
	if (G.next < t - 250) G.next = t;
	G.timer = setTimeout(tick, Math.max(0, G.next - t));
}
function game_end() {
	G.running = false;
	try { G.game.cleanup(); } catch (e) {}
	snd_stop();
	game_stop('fin');
}
function game_stop(why) {
	G.running = false;
	clearTimeout(G.timer);
	if (G.onstop) G.onstop(why);
}
function game_key(code, down) {
	if (!G.game || !G.running) return;
	if (down) {
		G.downAt.set(code, G.tickNo);
		try { G.game.keyPressed(code); } catch (ex) { if (DEBUG) console.warn('[game] exception in key handler', ex); }
	} else if (G.downAt.get(code) === G.tickNo) {
		if (!G.ups.includes(code)) G.ups.push(code);
	} else key_up(code);
}
function key_up(code) {
	G.downAt.delete(code);
	try { G.game.keyReleased(code); } catch (ex) { if (DEBUG) console.warn('[game] exception in key handler', ex); }
}
function game_pause(p) {
	if (!G.game) return;
	try { if (p) G.game.hideNotify(); else G.game.showNotify(); } catch (ex) {}
}
function boot() {
	for (const f of GAME_CLINIT) f();
	const m = new Midlet().init();
	m.startApp();
}
