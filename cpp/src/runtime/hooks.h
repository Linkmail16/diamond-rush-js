#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include "runtime.h"

struct SmOp {
	int t;
	Ref<Image> im;
	int32_t sx, sy, w, h, tr;
	int32_t dx, dy;
	uint32_t color;
	int32_t cl[4];
	int32_t mx, my;
	bool used;
};

struct RtHooks {
	int64_t (*now_ms)() = nullptr;
	double (*perf_ms)() = nullptr;
	void (*flush)(Image* screen) = nullptr;
	void (*start_game)(Object* game) = nullptr;
	void (*stop)(const char* why) = nullptr;
	void (*snd_play)(int i) = nullptr;
	void (*snd_stop)() = nullptr;
	bool save_to_disk = false;
	std::string save_dir;
	bool debug = false;
	bool sm_rec = false;
	Image* sm_screen = nullptr;
	std::vector<SmOp>* sm_cur = nullptr;
	void (*free_tex)(void* tex) = nullptr;
};
extern RtHooks rt;

void sound_ended();
