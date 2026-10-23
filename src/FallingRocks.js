'use strict';

class FallingRocks {
	static rockGrid = null;
	static rockOffsetY = 0;
	static rockSpeed = 0;
	static rockAnimFrame = 0;
	static rockGrid2 = null;
	static rockOffsetY2 = 0;
	static rockSpeed2 = 0;
	static hasSecondLayer = 0;
	static rockAnimFrameCount = 0;

	init() {
		return this;
	}

	static scroll(rocksPerRow) {
		let row = 0, col = 0;
		FallingRocks.rockOffsetY = FallingRocks.rockOffsetY + FallingRocks.rockSpeed << 24 >> 24;
		if (FallingRocks.rockOffsetY > 24) {
			FallingRocks.rockOffsetY = 0;
			for (row = 12; row >= 1; row--) {
				for (col = 0; col < 12; col++) {
					FallingRocks.rockGrid[col][row] = FallingRocks.rockGrid[col][row - 1];
				}
			}
			FallingRocks.spawnTopRow(rocksPerRow);
		}
		if (FallingRocks.hasSecondLayer) {
			FallingRocks.rockOffsetY2 = FallingRocks.rockOffsetY2 + FallingRocks.rockSpeed2 << 24 >> 24;
			if (FallingRocks.rockOffsetY2 > 24) {
				FallingRocks.rockOffsetY2 = 0;
				for (row = 12; row >= 1; row--) {
					for (col = 0; col < 12; col++) {
						FallingRocks.rockGrid2[col][row] = FallingRocks.rockGrid2[col][row - 1];
					}
				}
				FallingRocks.spawnTopRow(rocksPerRow);
			}
		}
	}

	static spawnTopRow(rocksPerRow) {
		let rockType = 0, col = 0, rockIndex = 0;
		for (col = 0; col < 12; col++) {
			FallingRocks.rockGrid[col][0] = 0;
		}
		if (FallingRocks.hasSecondLayer) {
			for (col = 0; col < 12; col++) {
				FallingRocks.rockGrid2[col][0] = 0;
			}
		}
		rockType = 0;
		for (rockIndex = 0; rockIndex < rocksPerRow; rockIndex++) {
			do {
				col = Rnd.nextInRange(0, 12);
			} while (FallingRocks.rockGrid[col][0] !== 0);
			rockType = Rnd.nextInRange(1, 3);
			FallingRocks.rockGrid[col][0] = rockType << 24 >> 24;
		}
		if (FallingRocks.hasSecondLayer) {
			for (rockIndex = 0; rockIndex < rocksPerRow; rockIndex++) {
				do {
					col = Rnd.nextInRange(0, 12);
				} while (FallingRocks.rockGrid2[col][0] !== 0);
				rockType = Rnd.nextInRange(1, 3);
				FallingRocks.rockGrid2[col][0] = rockType << 24 >> 24;
			}
		}
	}

	static draw(g) {
		let row = 0, col = 0, s0, s1, s2;
		for (col = 0; col < 12; col++) {
			for (row = 0; row < 13; row++) {
				if (FallingRocks.rockGrid[col][row] !== 1) {
					if (FallingRocks.rockGrid[col][row] === 2) {
						s0 = Game.spritePacks[Game.getSpritePackForImageSet(2)];
						s1 = g;
						s2 = 0;
						s0.drawFrame(s1, s2, col * 24 | 0, (row - 1 | 0) * 24 + FallingRocks.rockOffsetY | 0, 0, 0, 0);
					}
				} else {
					s0 = Game.spritePacks[Game.getSpritePackForImageSet(2)];
					s1 = g;
					s2 = FallingRocks.rockAnimFrame;
					s0.drawFrame(s1, s2, col * 24 | 0, (row - 1 | 0) * 24 + FallingRocks.rockOffsetY | 0, 0, 0, 0);
				}
			}
		}
		if (FallingRocks.hasSecondLayer) {
			for (col = 0; col < 12; col++) {
				for (row = 0; row < 13; row++) {
					if (FallingRocks.rockGrid2[col][row] !== 1) {
						if (FallingRocks.rockGrid2[col][row] === 2) {
							Game.spritePacks[Game.getSpritePackForImageSet(2)].drawFrame(g, 0, col * 24 | 0, (row - 1 | 0) * 24 + FallingRocks.rockOffsetY2 | 0, 0, 0, 0);
						}
					} else {
						Game.spritePacks[Game.getSpritePackForImageSet(2)].drawFrame(g, 0, col * 24 | 0, (row - 1 | 0) * 24 + FallingRocks.rockOffsetY2 | 0, 0, 0, 0);
					}
				}
			}
		}
		FallingRocks.rockAnimFrame = J.irem(FallingRocks.rockAnimFrame + 1 | 0, FallingRocks.rockAnimFrameCount);
	}

	static clinit() {
		FallingRocks.rockOffsetY = 0;
		FallingRocks.rockSpeed = 4;
		FallingRocks.rockAnimFrame = 0;
		FallingRocks.rockOffsetY2 = 0;
		FallingRocks.rockSpeed2 = 2;
		FallingRocks.hasSecondLayer = 0;
		FallingRocks.rockAnimFrameCount = 0;
	}

}
