#pragma once
#include "runtime.h"
#include <string>
#include <type_traits>

struct StateWriter {
	std::string out;
	bool first = true;

	void sep() { if (!first) out += ','; first = false; }
	void raw(const std::string& s) { sep(); out += s; }
	void str(const std::string& s) {
		std::string o = "\"";
		for (unsigned char c : s) {
			if (c == '"' || c == '\\') { o += '\\'; o += (char)c; }
			else if (c < 0x20) { char b[8]; snprintf(b, sizeof b, "\\u%04x", c); o += b; }
			else o += (char)c;
		}
		raw(o + "\"");
	}

	template<class T> static int32_t elem(const T& v, int d) {
		if constexpr (std::is_same<T, int64_t>::value) return (int32_t)v;
		else if constexpr (std::is_arithmetic<T>::value) return (int32_t)v;
		else return elem_ref(v, d);
	}
	template<class T> static int32_t elem_ref(const Ref<T>& r, int d) {
		if (!r.get()) return 7;
		if (r.p->javaClass()[0] == '[') return d < 2 ? 5 : 3;
		return 3;
	}
	template<class T> struct is_arr : std::false_type {};
	template<class T> struct is_arr<Array<T>> : std::true_type {};

	static inline bool verbose = false;
	template<class T> static std::string arr(const Arr<T>& a, int d) {
		if (verbose) {
			std::string o = "A" + std::to_string(a->length) + ":";
			for (int32_t i = 0; i < a->length; i++) o += (i ? "," : "") + std::to_string(elem(a->data[i], d));
			return o;
		}
		uint32_t h = 0x811C9DC5u;
		for (int32_t i = 0; i < a->length; i++) {
			h ^= (uint32_t)elem(a->data[i], d);
			h *= 0x01000193u;
		}
		return "A" + std::to_string(a->length) + ":" + std::to_string(h);
	}

	template<class T> void put(const char*, const T& v) {
		if constexpr (std::is_same<T, int64_t>::value) str("L" + std::to_string(v));
		else if constexpr (std::is_same<T, bool>::value) raw(v ? "1" : "0");
		else if constexpr (std::is_arithmetic<T>::value) raw(std::to_string((int64_t)v));
		else put_ref(v);
	}
	template<class T> void put_ref(const Ref<T>& r) {
		if (!r.get()) { raw("null"); return; }
		if constexpr (std::is_same<T, String>::value) str("S" + r->utf8());
		else if constexpr (is_arr<T>::value) str(arr(r, 0));
		else str("O");
	}
};
