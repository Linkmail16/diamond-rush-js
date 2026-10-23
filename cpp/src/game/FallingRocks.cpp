#include "game.h"

Ref<FallingRocks> FallingRocks::init() {
	return this;
}

void FallingRocks::scroll(int32_t rocksPerRow) {
	int32_t row = 0, col = 0;
	FallingRocks::rockOffsetY = (int8_t)(FallingRocks::rockOffsetY + FallingRocks::rockSpeed);
	if (FallingRocks::rockOffsetY > 24) {
		FallingRocks::rockOffsetY = 0;
		for (row = 12; row >= 1; row--) {
			for (col = 0; col < 12; col++) {
				FallingRocks::rockGrid[col][row] = FallingRocks::rockGrid[col][row - 1];
			}
		}
		FallingRocks::spawnTopRow(rocksPerRow);
	}
	if (FallingRocks::hasSecondLayer) {
		FallingRocks::rockOffsetY2 = (int8_t)(FallingRocks::rockOffsetY2 + FallingRocks::rockSpeed2);
		if (FallingRocks::rockOffsetY2 > 24) {
			FallingRocks::rockOffsetY2 = 0;
			for (row = 12; row >= 1; row--) {
				for (col = 0; col < 12; col++) {
					FallingRocks::rockGrid2[col][row] = FallingRocks::rockGrid2[col][row - 1];
				}
			}
			FallingRocks::spawnTopRow(rocksPerRow);
		}
	}
}

void FallingRocks::spawnTopRow(int32_t rocksPerRow) {
	int32_t col = 0, rockType = 0, rockIndex = 0;
	for (col = 0; col < 12; col++) {
		FallingRocks::rockGrid[col][0] = 0;
	}
	if (FallingRocks::hasSecondLayer) {
		for (col = 0; col < 12; col++) {
			FallingRocks::rockGrid2[col][0] = 0;
		}
	}
	rockType = 0;
	for (rockIndex = 0; rockIndex < rocksPerRow; rockIndex++) {
		do {
			col = Rnd::nextInRange(0, 12);
		} while (FallingRocks::rockGrid[col][0] != 0);
		rockType = Rnd::nextInRange(1, 3);
		FallingRocks::rockGrid[col][0] = (int8_t)rockType;
	}
	if (FallingRocks::hasSecondLayer) {
		for (rockIndex = 0; rockIndex < rocksPerRow; rockIndex++) {
			do {
				col = Rnd::nextInRange(0, 12);
			} while (FallingRocks::rockGrid2[col][0] != 0);
			rockType = Rnd::nextInRange(1, 3);
			FallingRocks::rockGrid2[col][0] = (int8_t)rockType;
		}
	}
}

void FallingRocks::draw(Ref<Graphics> g) {
	int32_t col = 0, row = 0, s2 = 0;
	Ref<Object> s0;
	Ref<Graphics> s1;
	for (col = 0; col < 12; col++) {
		for (row = 0; row < 13; row++) {
			if (FallingRocks::rockGrid[col][row] != 1) {
				if (FallingRocks::rockGrid[col][row] == 2) {
					s0 = Game::spritePacks[Game::getSpritePackForImageSet(2)];
					s1 = g;
					s2 = 0;
					cast<SpritePack>(s0)->drawFrame(s1, s2, col * 24, (row - 1) * 24 + FallingRocks::rockOffsetY, 0, 0, 0);
				}
			} else {
				s0 = Game::spritePacks[Game::getSpritePackForImageSet(2)];
				s1 = g;
				s2 = FallingRocks::rockAnimFrame;
				cast<SpritePack>(s0)->drawFrame(s1, s2, col * 24, (row - 1) * 24 + FallingRocks::rockOffsetY, 0, 0, 0);
			}
		}
	}
	if (FallingRocks::hasSecondLayer) {
		for (col = 0; col < 12; col++) {
			for (row = 0; row < 13; row++) {
				if (FallingRocks::rockGrid2[col][row] != 1) {
					if (FallingRocks::rockGrid2[col][row] == 2) {
						Game::spritePacks[Game::getSpritePackForImageSet(2)]->drawFrame(g, 0, col * 24, (row - 1) * 24 + FallingRocks::rockOffsetY2, 0, 0, 0);
					}
				} else {
					Game::spritePacks[Game::getSpritePackForImageSet(2)]->drawFrame(g, 0, col * 24, (row - 1) * 24 + FallingRocks::rockOffsetY2, 0, 0, 0);
				}
			}
		}
	}
	FallingRocks::rockAnimFrame = irem(FallingRocks::rockAnimFrame + 1, FallingRocks::rockAnimFrameCount);
}

void FallingRocks::clinit() {
	FallingRocks::rockOffsetY = 0;
	FallingRocks::rockSpeed = 4;
	FallingRocks::rockAnimFrame = 0;
	FallingRocks::rockOffsetY2 = 0;
	FallingRocks::rockSpeed2 = 2;
	FallingRocks::hasSecondLayer = 0;
	FallingRocks::rockAnimFrameCount = 0;
}

