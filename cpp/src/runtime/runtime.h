#pragma once
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <initializer_list>
#include <type_traits>
#include <typeinfo>

struct JClass;
struct String;
template<class T> struct Ref;
template<class T> struct Array;
template<class T> struct is_obj_array_t : std::false_type {};
template<class T> struct is_obj_array_t<Array<Ref<T>>> : std::true_type {};
template<class T> constexpr bool is_obj_array_v = is_obj_array_t<T>::value;

struct Object {
	int32_t refs = 0;
	bool queued = false;
	virtual ~Object() {}
	virtual int32_t hashCode() { return (int32_t)(intptr_t)this; }
	virtual bool equalsObj(Object* o) { return o == this; }
	virtual const char* javaClass() const { return "java/lang/Object"; }
	Ref<JClass> getClass();
	void retain() { refs++; }
	void release();
};

void gc_collect();
[[noreturn]] void throwNPE();

template<class T>
struct Ref {
	Object* p = nullptr;
	Ref() {}
	Ref(std::nullptr_t) {}
	Ref(T* q) : p(q) { if (p) p->retain(); }
	Ref(const Ref& o) : p(o.p) { if (p) p->retain(); }
	Ref(Ref&& o) noexcept : p(o.p) { o.p = nullptr; }
	template<class U, class = std::enable_if_t<std::is_base_of<T, U>::value || (is_obj_array_v<T> && is_obj_array_v<U>)>>
	Ref(const Ref<U>& o) : p(o.p) { if (p) p->retain(); }
	Ref(Object* q, int) : p(q) { if (p) p->retain(); }
	~Ref() { if (p) p->release(); }
	Ref& operator=(const Ref& o) { Object* q = o.p; if (q) q->retain(); if (p) p->release(); p = q; return *this; }
	Ref& operator=(Ref&& o) noexcept { if (this != &o) { if (p) p->release(); p = o.p; o.p = nullptr; } return *this; }
	Ref& operator=(std::nullptr_t) { if (p) p->release(); p = nullptr; return *this; }
	T* get() const { return static_cast<T*>(p); }
	T* operator->() const { if (!p) throwNPE(); return static_cast<T*>(p); }
	T& operator*() const { if (!p) throwNPE(); return *static_cast<T*>(p); }
	template<class I> auto& operator[](I i) const { return (**this)[(int32_t)i]; }
	explicit operator bool() const { return p != nullptr; }
};
template<class A, class B> bool operator==(const Ref<A>& a, const Ref<B>& b) { return a.p == b.p; }
template<class A, class B> bool operator!=(const Ref<A>& a, const Ref<B>& b) { return a.p != b.p; }
template<class A> bool operator==(const Ref<A>& a, std::nullptr_t) { return a.p == nullptr; }
template<class A> bool operator!=(const Ref<A>& a, std::nullptr_t) { return a.p != nullptr; }
template<class A, class B> bool operator==(const Ref<A>& a, B* b) { return a.p == static_cast<Object*>(b); }
template<class A, class B> bool operator!=(const Ref<A>& a, B* b) { return a.p != static_cast<Object*>(b); }

template<class T, class... A> Ref<T> jnew(A&&... a) { return Ref<T>(new T(std::forward<A>(a)...)); }

struct Throwable : Object {
	std::u16string cls;
	std::u16string msg;
	Throwable(const char16_t* c = u"java/lang/Throwable", std::u16string m = u"") : cls(c), msg(std::move(m)) {}
	bool isa(const char16_t* c) const;
	void printStackTrace();
	const char* javaClass() const override { return "java/lang/Throwable"; }
};
struct JavaException {
	Ref<Throwable> ex;
	JavaException(Ref<Throwable> e) : ex(std::move(e)) {}
	template<class T> JavaException(const Ref<T>& e) : ex(Ref<Throwable>(static_cast<Throwable*>(e.get()))) {}
	bool isa(const char16_t* c) const { return ex.get() && ex->isa(c); }
};
[[noreturn]] void jthrow(const char16_t* cls, std::u16string msg = u"");
[[noreturn]] void cast_failed(const char* to, const char* from);

inline int32_t idiv(int32_t a, int32_t b) {
	if (b == 0) jthrow(u"java/lang/ArithmeticException", u"/ by zero");
	if (b == -1) return (int32_t)(0u - (uint32_t)a);
	return a / b;
}
inline int32_t irem(int32_t a, int32_t b) {
	if (b == 0) jthrow(u"java/lang/ArithmeticException", u"/ by zero");
	if (b == -1) return 0;
	return a % b;
}
inline int64_t ldiv64(int64_t a, int64_t b) {
	if (b == 0) jthrow(u"java/lang/ArithmeticException", u"/ by zero");
	if (b == -1) return (int64_t)(0ull - (uint64_t)a);
	return a / b;
}
inline int64_t lrem64(int64_t a, int64_t b) {
	if (b == 0) jthrow(u"java/lang/ArithmeticException", u"/ by zero");
	if (b == -1) return 0;
	return a % b;
}
inline int32_t lcmp(int64_t a, int64_t b) { return a < b ? -1 : (a > b ? 1 : 0); }
inline int32_t shl(int32_t a, int32_t n) { return (int32_t)((uint32_t)a << (n & 31)); }
inline int32_t shr(int32_t a, int32_t n) { return a >> (n & 31); }
inline int32_t ushr(int32_t a, int32_t n) { return (int32_t)((uint32_t)a >> (n & 31)); }
inline int64_t lshl(int64_t a, int32_t n) { return (int64_t)((uint64_t)a << (n & 63)); }
inline int64_t lshr(int64_t a, int32_t n) { return a >> (n & 63); }
inline int64_t lushr(int64_t a, int32_t n) { return (int64_t)((uint64_t)a >> (n & 63)); }

template<class T>
struct Array : Object {
	int32_t length;
	T* data;
	explicit Array(int32_t n) : length(n), data(new T[n > 0 ? n : 1]()) {
		if (n < 0) jthrow(u"java/lang/NegativeArraySizeException");
	}
	~Array() override { delete[] data; }
	T& operator[](int32_t i) {
		if ((uint32_t)i >= (uint32_t)length) jthrow(u"java/lang/ArrayIndexOutOfBoundsException", std::u16string());
		return data[i];
	}
	const char* javaClass() const override { return "[array"; }
};
struct ObjArray : Object {
	int32_t length;
	Ref<Object>* data;
	explicit ObjArray(int32_t n) : length(n), data(new Ref<Object>[n > 0 ? n : 1]()) {
		if (n < 0) jthrow(u"java/lang/NegativeArraySizeException");
	}
	~ObjArray() override { delete[] data; }
	Ref<Object>& at(int32_t i) {
		if ((uint32_t)i >= (uint32_t)length) jthrow(u"java/lang/ArrayIndexOutOfBoundsException", std::u16string());
		return data[i];
	}
	const char* javaClass() const override { return "[array"; }
};
template<class T>
struct Array<Ref<T>> : ObjArray {
	explicit Array(int32_t n) : ObjArray(n) {}
	Ref<T>& operator[](int32_t i) { return reinterpret_cast<Ref<T>&>(at(i)); }
};
template<class T> using Arr = Ref<Array<T>>;
template<class T> Arr<T> newArray(int32_t n) { return Arr<T>(new Array<T>(n)); }

template<class T> struct is_obj_array : std::false_type {};
template<class T> struct is_obj_array<Array<Ref<T>>> : std::true_type {};

template<class T> Ref<T> cast(const Ref<Object>& o) {
	if (!o.p) return nullptr;
	if constexpr (is_obj_array<T>::value) {
		ObjArray* a = dynamic_cast<ObjArray*>(o.p);
		if (!a) cast_failed(typeid(T).name(), typeid(*o.p).name());
		return Ref<T>(static_cast<T*>(a));
	} else {
		T* t = dynamic_cast<T*>(o.p);
		if (!t) cast_failed(typeid(T).name(), typeid(*o.p).name());
		return Ref<T>(t);
	}
}
template<class T, class U> Ref<T> cast(const Ref<U>& o) { return cast<T>(Ref<Object>(o.p ? o.p : nullptr, 0)); }
template<class T, class U> bool instanceOf(const Ref<U>& o) {
	if (!o.p) return false;
	if constexpr (is_obj_array<T>::value) return dynamic_cast<ObjArray*>(o.p) != nullptr;
	else return dynamic_cast<T*>(o.p) != nullptr;
}

template<class T, int D> struct Nest { using type = Arr<typename Nest<T, D - 1>::type>; };
template<class T> struct Nest<T, 0> { using type = T; };
template<class T, int D> typename Nest<T, D>::type multiArrayAt(const int32_t* dims, int n) {
	using Elem = typename Nest<T, D - 1>::type;
	auto a = newArray<Elem>(dims[0]);
	if constexpr (D > 1) {
		if (n > 1) for (int32_t i = 0; i < a->length; i++) a->data[i] = multiArrayAt<T, D - 1>(dims + 1, n - 1);
	}
	return a;
}
template<class T, int D, class... I> typename Nest<T, D>::type multiArray(I... d) {
	const int32_t dims[] = { (int32_t)d... };
	return multiArrayAt<T, D>(dims, (int)sizeof...(I));
}

struct String : Object {
	std::u16string s;
	String() {}
	explicit String(std::u16string v) : s(std::move(v)) {}
	int32_t length() const { return (int32_t)s.size(); }
	uint16_t charAt(int32_t i) const;
	Ref<String> substring(int32_t a) const;
	Ref<String> substring(int32_t a, int32_t b) const;
	int32_t indexOf(int32_t c) const { return indexOf(c, 0); }
	int32_t indexOf(int32_t c, int32_t from) const;
	bool endsWith(const Ref<String>& x) const;
	Ref<String> toLowerCase() const;
	Arr<int8_t> getBytes() const;
	int32_t compareTo(const Ref<String>& o) const;
	bool equals(const Ref<Object>& o) const;
	int32_t hashCode() override;
	bool equalsObj(Object* o) override;
	const char* javaClass() const override { return "java/lang/String"; }
	static Ref<String> valueOf(int32_t v);
	static Ref<String> fromBytes(const Arr<int8_t>& b, int32_t off, int32_t len, const Ref<String>& enc);
	std::string utf8() const;
};
Ref<String> operator""_j(const char16_t* s, size_t n);
Ref<String> jstring(const std::u16string& s);

struct StringBuffer : Object {
	std::u16string s;
	StringBuffer() {}
	explicit StringBuffer(const Ref<String>& v) : s(v.get() ? v->s : u"null") {}
	Ref<StringBuffer> append(const Ref<String>& v);
	Ref<StringBuffer> append(const Ref<StringBuffer>& v);
	Ref<StringBuffer> append(int32_t v);
	Ref<StringBuffer> appendChar(int32_t c);
	Ref<String> toString() const { return jstring(s); }
	int32_t length() const { return (int32_t)s.size(); }
	uint16_t charAt(int32_t i) const;
	Ref<StringBuffer> deleteChars(int32_t a, int32_t e);
	void setCharAt(int32_t i, int32_t c);
	const char* javaClass() const override { return "java/lang/StringBuffer"; }
};

struct Integer : Object {
	int32_t value;
	explicit Integer(int32_t v) : value(v) {}
	int32_t intValue() const { return value; }
	int8_t byteValue() const { return (int8_t)value; }
	int32_t hashCode() override { return value; }
	bool equalsObj(Object* o) override;
	const char* javaClass() const override { return "java/lang/Integer"; }
};

struct Hashtable : Object {
	struct H { size_t operator()(Object* o) const { return (size_t)(uint32_t)o->hashCode(); } };
	struct Eq { bool operator()(Object* a, Object* b) const { return a->equalsObj(b); } };
	std::unordered_map<Object*, std::pair<Ref<Object>, Ref<Object>>, H, Eq> m;
	Ref<Object> put(const Ref<Object>& k, const Ref<Object>& v);
	Ref<Object> get(const Ref<Object>& k);
	const char* javaClass() const override { return "java/util/Hashtable"; }
};

struct Random : Object {
	int64_t seed;
	explicit Random(int64_t s) : seed((s ^ 0x5DEECE66DLL) & ((1LL << 48) - 1)) {}
	int32_t nextInt() {
		seed = (int64_t)(((uint64_t)seed * 0x5DEECE66DULL + 0xBULL) & ((1ULL << 48) - 1));
		return (int32_t)(seed >> 16);
	}
};

struct PrintStream : Object {
	void println(const Ref<String>& s);
	void println(int32_t v);
};

struct JSystem {
	static inline Ref<PrintStream> out = Ref<PrintStream>(new PrintStream());
	static int64_t currentTimeMillis();
	static void gc() {}
	template<class A, class B>
	static void arraycopy(const Ref<A>& src, int32_t sp, const Ref<B>& dst, int32_t dp, int32_t n) {
		auto s = src.operator->();
		auto d = dst.operator->();
		if (n < 0 || sp < 0 || dp < 0 || sp + n > s->length || dp + n > d->length) jthrow(u"java/lang/ArrayIndexOutOfBoundsException");
		if (n == 0) return;
		if ((void*)s == (void*)d) {
			std::vector<std::remove_reference_t<decltype(s->data[0])>> t(s->data + sp, s->data + sp + n);
			for (int32_t i = 0; i < n; i++) d->data[dp + i] = t[i];
		} else {
			for (int32_t i = 0; i < n; i++) d->data[dp + i] = s->data[sp + i];
		}
	}
};

struct JMath {
	static int32_t abs(int32_t v) { return v < 0 ? (int32_t)(0u - (uint32_t)v) : v; }
	static int64_t abs(int64_t v) { return v < 0 ? (int64_t)(0ull - (uint64_t)v) : v; }
};

struct Thread : Object {
	Ref<Object> target;
	explicit Thread(const Ref<Object>& r) : target(r) {}
	void start();
	void setPriority(int32_t) {}
	static void sleep(int64_t) {}
	static void yield() {}
};

struct InputStream : Object {
	Arr<int8_t> keep;
	const uint8_t* buf = nullptr;
	int32_t size = 0, pos = 0;
	InputStream() {}
	InputStream(const uint8_t* b, int32_t n) : buf(b), size(n) {}
	int32_t read();
	int32_t read(const Arr<int8_t>& b) { return read(b, 0, b->length); }
	int32_t read(const Arr<int8_t>& b, int32_t off, int32_t len);
	int64_t skip(int64_t n);
	void close() {}
};
struct ByteArrayInputStream : InputStream {
	explicit ByteArrayInputStream(const Arr<int8_t>& b) {
		keep = b;
		buf = (const uint8_t*)b->data;
		size = b->length;
	}
};
struct JClass : Object {
	std::u16string name;
	static Ref<JClass> forName(const Ref<String>& n);
	Ref<InputStream> getResourceAsStream(const Ref<String>& name);
};

const std::vector<uint8_t>* resource(const std::string& name);

struct Image : Object {
	int32_t w = 0, h = 0;
	std::vector<uint32_t> px;
	bool mutableImg = false;
	int32_t id = 0;
	int32_t version = 0;
	void* tex = nullptr;
	int32_t texVersion = -1;
	~Image() override;
	static Ref<Image> createImage(const Ref<String>& name);
	static Ref<Image> createImage(int32_t w, int32_t h);
	static Ref<Image> createImage(const Arr<int8_t>& data, int32_t off, int32_t len);
	static Ref<Image> createRGBImage(const Arr<int32_t>& rgb, int32_t w, int32_t h, bool alpha);
	int32_t getWidth() const { return w; }
	int32_t getHeight() const { return h; }
	struct Ref<struct Graphics> getGraphics();
	const char* javaClass() const override { return "javax/microedition/lcdui/Image"; }
};

struct Graphics : Object {
	Image* target;
	Ref<Image> keep;
	int32_t tx = 0, ty = 0, cx = 0, cy = 0, cw, ch;
	uint32_t color = 0xFF000000;
	explicit Graphics(Image* t) : target(t), keep(t), cw(t->w), ch(t->h) {}
	void translate(int32_t x, int32_t y) { tx += x; ty += y; }
	void setColor(int32_t rgb) { color = 0xFF000000u | ((uint32_t)rgb & 0xFFFFFF); }
	void setColor(int32_t r, int32_t g, int32_t b) { setColor(((r & 255) << 16) | ((g & 255) << 8) | (b & 255)); }
	void setClip(int32_t x, int32_t y, int32_t w, int32_t h);
	void clipRect(int32_t x, int32_t y, int32_t w, int32_t h);
	int32_t getClipX() const { return cx - tx; }
	int32_t getClipY() const { return cy - ty; }
	int32_t getClipWidth() const { return cw; }
	int32_t getClipHeight() const { return ch; }
	void fillRect(int32_t x, int32_t y, int32_t w, int32_t h);
	void drawRect(int32_t x, int32_t y, int32_t w, int32_t h);
	void drawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
	void fillRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t aw, int32_t ah);
	void drawRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t aw, int32_t ah);
	void drawImage(const Ref<Image>& im, int32_t x, int32_t y, int32_t anchor);
	void drawRegion(const Ref<Image>& im, int32_t sx, int32_t sy, int32_t w, int32_t h, int32_t tr, int32_t x, int32_t y, int32_t anchor);
	void rect(int32_t x, int32_t y, int32_t w, int32_t h);
};

struct MIDlet : Object {
	Ref<String> getAppProperty(const Ref<String>& key);
	void notifyDestroyed();
	void notifyPaused() {}
	bool platformRequest(const Ref<String>&) { return false; }
};
struct Display : Object {
	Ref<Object> current;
	static Ref<Display> getDisplay(const Ref<MIDlet>& m);
	void setCurrent(const Ref<Object>& c) { current = c; }
	bool vibrate(int32_t) { return true; }
};
struct GameCanvas : Object {
	Ref<Image> canvasImage;
	Ref<GameCanvas> init(bool suppressKeys);
	void setFullScreenMode(bool) {}
	Ref<Graphics> getGraphics() { return jnew<Graphics>(canvasImage.get()); }
	void flushGraphics();
};

struct RecordStore : Object {
	std::string name;
	std::vector<std::vector<int8_t>> recs;
	static Ref<RecordStore> openRecordStore(const Ref<String>& name, bool create);
	void closeRecordStore() {}
	int32_t getNumRecords() const { return (int32_t)recs.size(); }
	int32_t addRecord(const Arr<int8_t>& b, int32_t off, int32_t n);
	void setRecord(int32_t id, const Arr<int8_t>& b, int32_t off, int32_t n);
	Arr<int8_t> getRecord(int32_t id);
	void save();
};

struct Sound : Object {
	static inline bool enabled = true;
	Sound() {}
	void load(int32_t) {}
	void start() {}
	void open() {}
	void close() {}
	void release() { stop(); }
	void stop();
	static bool isPlaying();
	void play(int32_t i);
};
