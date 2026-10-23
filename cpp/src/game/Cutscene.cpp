#include "game.h"

Ref<Cutscene> Cutscene::init(Ref<Game> gameRef) {
	this->steps = nullptr;
	this->nextStepIndex = 0;
	this->currentStep = nullptr;
	this->isPortraitVisible = 0;
	this->portraitX = 0;
	this->portraitY = 0;
	this->portraitFrame = 0;
	this->portraitPackIndex = 0;
	this->portraitIconFrame = -1;
	this->isSkipped = 0;
	this->game = nullptr;
	this->lineEnds = newArray<int16_t>(16);
	this->game = gameRef;
	return this;
}

void Cutscene::drawCommand(Ref<Graphics> g, Arr<int8_t> step, int32_t offset) {
	int32_t duration = 0, packIndex = 0, frameId = 0, opcode = 0, tick = 0, playerX = 0, playerY = 0, lerpX = 0, lerpY = 0, maxCamX = 0, maxCamY = 0, firstLine = 0, visibleLines = 0, boxHeight = 0, toX = 0, toY = 0, fromX = 0, fromY = 0, posX = 0, posY = 0, s1 = 0;
	Ref<String> text;
	Ref<Object> s0;
	Ref<Game> t2;
	if (step == nullptr) {
		return;
	}
	opcode = step[offset + 0];
	switch (opcode) {
		case 27:
			Game::spritePacks[41]->lineSpacing = 2;
			firstLine = step[offset + 6] & 255;
			Game::drawFramedBoxWithTab(g, 6, 229, 226, 35, 73, 1, Game::measureFirstLineWidth(Game::spritePacks[41], Game::langStrings[70], 0) + 10, 15);
			text = nullptr;
			try {
				text = String::fromBytes(step, offset + 8, (int16_t)Game::readU16LE(step, offset + 2), u"ISO-8859-1"_j);
			} catch (JavaException& ex) {
				if (ex.isa(u"java/lang/Exception")) {
					s0 = ex.ex;
				}
				else throw;
			}
			this->wrapText(text, 196);
			this->drawWrappedLines(g, text, 22, 231, firstLine, firstLine + 2);
			Game::spritePacks[41]->drawString(g, Game::langStrings[70], 19, 211, 20);
			if (Game::drawCount / 2 % 4 >= 2) {
				return;
			}
			g->drawImage(Game::uiFrameImages[0][9], 223, 220, 17);
			return;
		case 18:
			if (step[offset + 7] == 0) {
				return;
			}
			tick = (step[offset + 3] & 255) + ((step[offset + 3 + 1] & 255) << 8) + ((step[offset + 3 + 2] & 255) << 16);
			g->setColor(tick);
			g->fillRect(0, 0, 240, 320);
			return;
		case 13:
			tick = this->stepTick;
			toX = (int16_t)Game::readU16LE(step, offset + 2);
			toY = (int16_t)Game::readU16LE(step, offset + 4);
			duration = (int16_t)Game::readU16LE(step, offset + 6);
			fromX = (int16_t)Game::readU16LE(step, offset + 8);
			fromY = (int16_t)Game::readU16LE(step, offset + 10);
			if (tick > duration) {
				tick = duration;
			}
			lerpX = (int16_t)idiv(toX * tick + fromX * (duration - tick), duration);
			lerpY = (int16_t)idiv(toY * tick + fromY * (duration - tick), duration);
			if (opcode != 13) {
				return;
			}
			this->portraitX = lerpX;
			this->portraitY = lerpY;
			return;
		case 12:
			tick = this->stepTick;
			g->setColor(16777215);
			if (tick > 5) {
				tick = 5;
			}
			playerX = this->game->playerCol * 24;
			playerY = this->game->playerRow * 24;
			lerpX = this->portraitX;
			lerpY = this->portraitY;
			g->fillRect(((playerX - this->game->camX) * (5 - tick) + lerpX * tick) / 5, ((playerY - this->game->camY) * (5 - tick) + lerpY * tick) / 5, 102 * tick / 5, 38 * tick / 5);
			return;
		case 4:
			tick = this->stepTick;
			fromX = (int16_t)Game::readU16LE(step, offset + 2);
			fromY = (int16_t)Game::readU16LE(step, offset + 4);
			toX = (int16_t)Game::readU16LE(step, offset + 6);
			toY = (int16_t)Game::readU16LE(step, offset + 6);
			duration = (int16_t)Game::readU16LE(step, offset + 14);
			if (tick > duration) {
				tick = duration;
			}
			posX = (int16_t)idiv(toX * tick + fromX * (duration - tick), duration);
			posY = (int16_t)idiv(toY * tick + fromY * (duration - tick), duration);
			packIndex = (int16_t)Game::readU16LE(step, offset + 10);
			frameId = (int16_t)Game::readU16LE(step, offset + 12);
			Cutscene::sprites[packIndex]->drawFrame(g, frameId, posX, posY, 0, 0, 0);
			return;
		case 2:
			Game::spritePacks[41]->lineSpacing = 2;
			posY = (int16_t)Game::readU16LE(step, offset + 6);
			posX = (int16_t)Game::readU16LE(step, offset + 4);
			if (posX == 10000) {
				posX = -240;
			}
			visibleLines = step[offset + 8] & 255;
			firstLine = step[offset + 9] & 255;
			boxHeight = visibleLines * Game::getFontLineHeight(Game::spritePacks[41]) + 4 - 2;
			Game::drawFramedBox(g, posX, posY, 226, boxHeight, 73, 0);
			text = nullptr;
			try {
				text = String::fromBytes(step, offset + 11, (int16_t)Game::readU16LE(step, offset + 2), u"ISO-8859-1"_j);
			} catch (JavaException& ex) {
				if (ex.isa(u"java/lang/Exception")) {
					s0 = ex.ex;
				}
				else throw;
			}
			this->wrapText(text, 222);
			this->drawWrappedLines(g, text, posX + 2, posY + 2, firstLine, firstLine + visibleLines);
			if (Game::drawCount / 2 % 4 < 2) {
				g->drawImage(Game::uiFrameImages[0][9], posX + 226 - 10, posY + boxHeight - 5, 17);
			}
			g->setClip(0, 0, 240, 320);
			return;
		case 1:
			tick = this->stepTick;
			toX = (int16_t)Game::readU16LE(step, offset + 2);
			toY = (int16_t)Game::readU16LE(step, offset + 4);
			duration = (int16_t)Game::readU16LE(step, offset + 6);
			fromX = (int16_t)Game::readU16LE(step, offset + 8);
			fromY = (int16_t)Game::readU16LE(step, offset + 10);
			if (fromX == 10000) {
				fromX = (int16_t)this->game->camTargetX;
			}
			if (fromY == 10000) {
				fromY = (int16_t)this->game->camTargetY;
			}
			if (tick > duration) {
				tick = duration;
			}
			toX = (int16_t)(toX - 108);
			toY = (int16_t)(toY - 108);
			this->game->camTargetX = (int16_t)idiv(toX * tick + fromX * (duration - tick), duration);
			this->game->camTargetY = (int16_t)idiv(toY * tick + fromY * (duration - tick), duration);
			maxCamX = this->game->levelW * 24 - 240;
			maxCamY = this->game->levelH * 24 - 320 + 80;
			if (this->game->camTargetX <= maxCamX) {
				if (this->game->camTargetX < 0) {
					s0 = this->game;
					s1 = 0;
					cast<Game>(s0)->camTargetX = s1;
				}
			} else {
				s0 = this->game;
				s1 = maxCamX;
				cast<Game>(s0)->camTargetX = s1;
			}
			if (this->game->camTargetY <= maxCamY) {
				if (this->game->camTargetY < 0) {
					s0 = this->game;
					s1 = 0;
					cast<Game>(s0)->camTargetY = s1;
				}
			} else {
				s0 = this->game;
				s1 = maxCamY;
				cast<Game>(s0)->camTargetY = s1;
			}
			this->game->camX = this->game->camTargetX;
			this->game->camY = this->game->camTargetY;
			if (this->game->camX > maxCamX) {
				t2 = this->game;
				t2->camX = t2->camX - maxCamX;
			}
			if (this->game->camY <= maxCamY) {
				if (this->game->camY >= 0) {
					return;
				}
				return;
			}
			this->game->camY = maxCamY;
			return;
		default:
			return;
	}
}

void Cutscene::onConfirmCommand(Arr<int8_t> step, int32_t offset) {
	int32_t opcode = 0, firstLine = 0, linesPerPage = 0, s1 = 0, s2 = 0;
	Ref<String> text;
	Ref<Object> s0;
	opcode = (int16_t)step[offset + 0];
	switch (opcode) {
		case 27:
			if (!Game::itemRaiseFreeze) {
				text = nullptr;
				try {
					text = String::fromBytes(step, offset + 8, (int16_t)Game::readU16LE(step, offset + 2), u"ISO-8859-1"_j);
				} catch (JavaException& ex) {
					if (ex.isa(u"java/lang/Exception")) {
						s0 = ex.ex;
						this->wrapText(text, 196);
						firstLine = (int16_t)(step[offset + 6] & 255);
						linesPerPage = 0;
						if (firstLine + 2 < this->lineCount) {
							step[offset + 6] = (int8_t)(firstLine + 2);
							return;
						}
						step[offset + 7] = 1;
						return;
					}
					else throw;
				}
				this->wrapText(text, 196);
				firstLine = (int16_t)(step[offset + 6] & 255);
				linesPerPage = 0;
				if (firstLine + 2 < this->lineCount) {
					step[offset + 6] = (int8_t)(firstLine + 2);
					return;
				}
				step[offset + 7] = 1;
				return;
			}
			return;
		case 7:
			step[offset + 1] = 1;
			return;
		case 2:
			text = nullptr;
			try {
				text = String::fromBytes(step, offset + 11, (int16_t)Game::readU16LE(step, offset + 2), u"ISO-8859-1"_j);
			} catch (JavaException& ex) {
				if (ex.isa(u"java/lang/Exception")) {
					s0 = ex.ex;
				}
				else throw;
			}
			this->wrapText(text, 222);
			firstLine = (int16_t)(step[offset + 9] & 255);
			linesPerPage = (int16_t)(step[offset + 8] & 255);
			if (firstLine + linesPerPage < this->lineCount) {
				s0 = step;
				s1 = offset + 9;
				s2 = (int8_t)(firstLine + linesPerPage);
			} else {
				s0 = step;
				s1 = offset + 10;
				s2 = 1;
			}
			cast<Array<int8_t>>(s0)[s1] = s2;
			return;
		default:
			return;
	}
}

void Cutscene::onConfirmPressed() {
	int32_t commandCount = 0, commandOffset = 0, commandIndex = 0, commandSize = 0;
	if (this->currentStep != nullptr) {
		if (JMath::abs(this->stepStartTime - JSystem::currentTimeMillis()) >= Cutscene::startDelayMs) {
			if (this->currentStep[0] != 0) {
				this->onConfirmCommand(this->currentStep, 0);
			} else {
				commandCount = this->currentStep[1];
				commandOffset = 2 + commandCount * 4;
				for (commandIndex = 0; commandIndex < commandCount; commandIndex++) {
					commandSize = Game::readS32LE(this->currentStep, 2 + commandIndex * 4);
					this->onConfirmCommand(this->currentStep, commandOffset);
					commandOffset = commandOffset + commandSize;
				}
			}
			return;
		}
		return;
	}
}

void Cutscene::draw(Ref<Graphics> g) {
	int32_t commandCount = 0, commandOffset = 0, commandIndex = 0, commandSize = 0;
	if (!this->isSkipped) {
		switch (this->getStepOpcode()) {
			default:
				g->setColor(0);
				g->fillRect(0, 0, 240, 42);
				g->fillRect(0, 278, 240, 42);
				Game::spritePacks[41]->drawString(g, Game::langStrings[53], 5, 315, 36);
				break;
			case 25:
			case 26:
				if (this->steps == nullptr || this->nextStepIndex >= this->steps->length) {
					return;
				}
				break;
		}
		if (this->currentStep[0] != 0) {
			this->drawCommand(g, this->currentStep, 0);
		} else {
			commandCount = this->currentStep[1];
			commandOffset = 2 + commandCount * 4;
			for (commandIndex = 0; commandIndex < commandCount; commandIndex++) {
				commandSize = Game::readS32LE(this->currentStep, 2 + commandIndex * 4);
				this->drawCommand(g, this->currentStep, commandOffset);
				commandOffset = commandOffset + commandSize;
			}
		}
		if (this->isPortraitVisible) {
			g->setColor(0);
			g->fillRect(this->portraitX - 3, this->portraitY - 3, 109, 45);
			Cutscene::sprites[this->portraitPackIndex]->drawAnimFrame(g, 0, irem(this->stepTick, Cutscene::sprites[this->portraitPackIndex]->getAnimFrameCount(0)), this->portraitX, this->portraitY, 0, 0, 0);
			Cutscene::sprites[0]->drawFrame(g, this->portraitFrame, this->portraitX + 0, this->portraitY, 0, 0, 0);
			if (this->portraitIconFrame >= 0) {
				Cutscene::sprites[1]->drawFrame(g, this->portraitIconFrame, this->portraitX + 90, this->portraitY - 6, 0, 0, 0);
			}
		}
		return;
	}
}

Arr<int8_t> Cutscene::start() {
	this->resetSteps(this->steps);
	this->isPortraitVisible = 0;
	this->portraitX = 0;
	this->portraitY = 0;
	this->portraitFrame = 0;
	this->portraitPackIndex = 0;
	this->portraitIconFrame = -1;
	this->isSkipped = 0;
	this->nextStepIndex = 0;
	this->stepStartTime = JSystem::currentTimeMillis();
	return this->nextStep();
}

void Cutscene::resetCommand(Arr<int8_t> step, int32_t offset) {
	int32_t commandCount = 0, subOffset = 0, commandIndex = 0, commandSize = 0, s1 = 0, s2 = 0;
	Ref<Object> s0;
	if (step[offset + 0] == 0) {
		commandCount = step[offset + 1];
		subOffset = offset + 2 + commandCount * 4;
		for (commandIndex = 0; commandIndex < commandCount; commandIndex++) {
			commandSize = Game::readS32LE(step, offset + 2 + commandIndex * 4);
			this->resetCommand(step, subOffset);
			subOffset = subOffset + commandSize;
		}
		return;
	}
	step[offset + 1] = 0;
	switch (step[offset + 0]) {
		case 27:
			step[offset + 6] = 0;
			Cutscene::writeShort(step, offset + 4, -240);
			s0 = step;
			s1 = offset;
			s2 = 7;
			cast<Array<int8_t>>(s0)[s1 + s2] = 0;
			break;
		case 2:
			step[offset + 9] = 0;
			Cutscene::writeShort(step, offset + 4, -240);
			s0 = step;
			s1 = offset;
			s2 = 10;
			cast<Array<int8_t>>(s0)[s1 + s2] = 0;
			break;
		default:
			break;
	}
}

void Cutscene::resetSteps(Arr<Arr<int8_t>> stepList) {
	int32_t stepIndex = 0;
	for (stepIndex = 0; stepIndex < stepList->length; stepIndex++) {
		this->resetCommand(stepList[stepIndex], 0);
	}
}

Arr<int8_t> Cutscene::nextStep() {
	Ref<Object> s1;
	Arr<Arr<int8_t>> t1;
	int32_t t2 = 0;
	this->stepTick = 0;
	if (this->steps == nullptr || this->nextStepIndex >= this->steps->length) {
		s1 = nullptr;
	} else {
		t1 = this->steps;
		t2 = this->nextStepIndex;
		this->nextStepIndex = t2 + 1;
		s1 = t1[t2];
	}
	cast<Cutscene>(this)->currentStep = cast<Array<int8_t>>(s1);
	return this->currentStep;
}

void Cutscene::updateStep() {
	int32_t commandCount = 0, commandOffset = 0, commandIndex = 0, commandSize = 0;
	if (this->currentStep[0] != 0) {
		this->updateCommand(this->currentStep, 0);
	} else {
		commandCount = this->currentStep[1];
		commandOffset = 2 + commandCount * 4;
		for (commandIndex = 0; commandIndex < commandCount; commandIndex++) {
			commandSize = Game::readS32LE(this->currentStep, 2 + commandIndex * 4);
			this->updateCommand(this->currentStep, commandOffset);
			commandOffset = commandOffset + commandSize;
		}
	}
	this->stepTick = this->stepTick + 1;
}

void Cutscene::updateCommand(Arr<int8_t> step, int32_t offset) {
	int32_t iconFrame = 0, toggleOffset = 0, isBlinkOn = 0, value = 0, valueHigh = 0, x = 0, y = 0, duration = 0, moveDir = 0, opcode = 0, counterOffset = 0, blinksLeft = 0;
	opcode = (int16_t)step[offset + 0];
	{
		if (this->isSkipped) {
			switch (opcode) {
				default:
					step[offset + 1] = 1;
					return;
				case 5:
				case 9:
				case 10:
				case 25:
				case 26:
					goto B1_end;
			}
		}
	}
	B1_end:;
	switch (opcode) {
		case 27:
			if (step[offset + 7] == 0) {
				return;
			}
			step[offset + 1] = 1;
			return;
		case 26:
			x = (int16_t)Game::readU16LE(step, offset + 2);
			y = (int16_t)Game::readU16LE(step, offset + 4);
			value = Game::readS32LE(step, offset + 6);
			Game::cellStates[x][y] = value;
			step[offset + 1] = 1;
			return;
		case 25:
			x = (int16_t)Game::readU16LE(step, offset + 2);
			y = (int16_t)Game::readU16LE(step, offset + 4);
			value = step[offset + 6];
			valueHigh = step[offset + 7];
			Game::cellObjects[x][y] = valueHigh << 8 | value;
			step[offset + 1] = 1;
			return;
		case 16:
		case 17:
		case 18:
			if (this->stepTick % 2 != 0) {
				counterOffset = offset + (opcode != 18 ? 4 : 2);
				blinksLeft = step[counterOffset];
				iconFrame = -1;
				toggleOffset = offset + (opcode != 18 ? 5 : 7);
				isBlinkOn = step[toggleOffset] != 0 ? 1 : 0;
				if (opcode != 18) {
					iconFrame = (int16_t)Game::readU16LE(step, offset + 2);
				}
				if (isBlinkOn == 0) {
					if (blinksLeft <= 0) {
						step[offset + 1] = 1;
					} else {
						isBlinkOn = 1;
						if (opcode != 18) {
							this->portraitIconFrame = iconFrame;
						}
					}
				} else {
					isBlinkOn = 0;
					this->portraitIconFrame = -1;
					blinksLeft = (int8_t)(blinksLeft - 1);
					if (blinksLeft == 0) {
						step[offset + 1] = 1;
						if (opcode != 18) {
							this->portraitIconFrame = opcode != 16 ? -1 : iconFrame;
						}
					}
				}
				step[toggleOffset] = (int8_t)(isBlinkOn != 0 ? 1 : 0);
				step[counterOffset] = blinksLeft;
				return;
			}
			return;
		case 14:
		case 15:
			this->isPortraitVisible = opcode == 14 ? 1 : 0;
			step[offset + 1] = 1;
			return;
		case 13:
			if ((int16_t)Game::readU16LE(step, offset + 8) == 10000) {
				Cutscene::writeShort(step, offset + 8, (int16_t)this->portraitX);
			}
			if ((int16_t)Game::readU16LE(step, offset + 10) == 10000) {
				Cutscene::writeShort(step, offset + 10, (int16_t)this->portraitY);
			}
			duration = (int16_t)Game::readU16LE(step, offset + 6);
			if (this->stepTick <= duration) {
				return;
			}
			step[offset + 1] = 1;
			return;
		case 12:
			x = (int16_t)Game::readU16LE(step, offset + 2);
			y = (int16_t)Game::readU16LE(step, offset + 4);
			this->portraitX = x;
			this->portraitY = y;
			if (this->stepTick <= 5) {
				return;
			}
			step[offset + 1] = 1;
			this->isPortraitVisible = 1;
			return;
		case 11:
			this->portraitPackIndex = (int16_t)Game::readU16LE(step, offset + 4);
			this->portraitFrame = (int16_t)Game::readU16LE(step, offset + 2);
			step[offset + 1] = 1;
			return;
		case 10:
			moveDir = step[offset + 2];
			if (this->stepTick != 0) {
				if (this->game->playerStep <= 0) {
					this->game->requestedMoveDir = 0;
					step[offset + 1] = 1;
				}
			} else {
				this->game->explorerStateFlags = this->game->explorerStateFlags & -8 | moveDir;
				this->game->requestedMoveDir = moveDir;
			}
			this->game->updateCameraFollow();
			return;
		case 9:
			Game::setCellTypeAndState((int16_t)Game::readU16LE(step, offset + 2), (int16_t)Game::readU16LE(step, offset + 4), 0, (int16_t)Game::readU16LE(step, offset + 6));
			step[offset + 1] = 1;
			return;
		case 8:
			return;
		case 6:
			if (this->stepTick <= Game::readS32LE(step, offset + 2)) {
				return;
			}
			step[offset + 1] = 1;
			return;
		case 5:
			Game::setCellTypeAndState((int16_t)Game::readU16LE(step, offset + 2), (int16_t)Game::readU16LE(step, offset + 4), step[offset + 6], 0);
			step[offset + 1] = 1;
			return;
		case 4:
			duration = (int16_t)Game::readU16LE(step, offset + 14);
			if (this->stepTick <= duration) {
				return;
			}
			step[offset + 1] = 1;
			return;
		case 2:
			x = (int16_t)Game::readU16LE(step, offset + 4);
			if (x == 10000) {
				x = -226;
			}
			x = (int16_t)(x + 30);
			if (step[offset + 10] != 0) {
				if (x > 240) {
					step[offset + 1] = 1;
				}
			} else {
				if (x > 7) {
					x = 7;
				}
			}
			Cutscene::writeShort(step, offset + 4, x);
			return;
		case 1:
			if ((int16_t)Game::readU16LE(step, offset + 8) == 10000) {
				Cutscene::writeShort(step, offset + 8, (int16_t)this->game->camTargetX);
			}
			if ((int16_t)Game::readU16LE(step, offset + 10) == 10000) {
				Cutscene::writeShort(step, offset + 10, (int16_t)this->game->camTargetY);
			}
			duration = (int16_t)Game::readU16LE(step, offset + 6);
			if (this->stepTick <= duration) {
				return;
			}
			step[offset + 1] = 1;
			return;
		default:
			return;
	}
}

bool Cutscene::isStepFinished() {
	int32_t isDone = 0, commandCount = 0, commandOffset = 0, commandIndex = 0, commandSize = 0;
	isDone = 1;
	{
		if (this->currentStep[0] != 0) {
			isDone = this->currentStep[1] == 1 ? 1 : 0;
		} else {
			commandCount = this->currentStep[1];
			commandOffset = 2 + commandCount * 4;
			commandIndex = 0;
			while (true) {
				if (commandIndex >= commandCount) {
					goto B1_end;
				}
				commandSize = Game::readS32LE(this->currentStep, 2 + commandIndex * 4);
				isDone = isDone != 0 && this->currentStep[commandOffset + 1] == 1 ? 1 : 0;
				if (isDone) {
					commandOffset = commandOffset + commandSize;
					commandIndex++;
					continue;
				}
				break;
			}
		}
	}
	B1_end:;
	return isDone;
}

int8_t Cutscene::getStepOpcode() {
	if (this->currentStep != nullptr) {
		return this->currentStep[0];
	}
	return -1;
}

void Cutscene::loadScript(int32_t cutsceneId) {
	Ref<Object> table, dest, s0_o;
	int32_t writeIndex = 0, group_n = 0, groupFill_n = 0, remaining = 0, index = 0, opcode = 0, command_n = 0, word = 0, size = 0, frameArg = 0, packArg = 0, argX = 0, argY = 0, duration = 0, fromX = 0, fromY = 0, toX = 0, toY = 0, packIndex = 0, delay = 0, cellValue = 0, lowByte = 0, highByte = 0, textLength = 0, visibleLines = 0, extraArg = 0, direction = 0, found = 0, entryId = 0, stepCount = 0, dataSize = 0, pos = 0, spriteCount = 0, s0 = 0;
	Arr<Arr<int8_t>> group;
	Ref<InputStream> groupFill;
	Arr<int8_t> command, buffer;
	Ref<ByteArrayInputStream> input;
	Ref<String> t1;
	try {
		t1 = Cutscene::scriptPath;
		this->game->getClass();
		input = jnew<ByteArrayInputStream>(Game::readResource(t1, 0));
		buffer = newArray<int8_t>(4);
		input->read(buffer, 0, 2);
		found = 0;
		while (true) {
			input->read(buffer, 0, 2);
			entryId = (int16_t)Game::readU16LE(buffer, 0);
			if (entryId != cutsceneId) {
				input->skip(2LL);
				input->read(buffer, 0, 4);
				stepCount = Game::readS32LE(buffer, 0);
				input->skip((int64_t)stepCount);
			} else {
				input->read(buffer, 0, 2);
				stepCount = (int16_t)Game::readU16LE(buffer, 0);
				input->read(buffer, 0, 4);
				dataSize = Game::readS32LE(buffer, 0);
				buffer = newArray<int8_t>(dataSize);
				input->read(buffer);
				input->close();
				input = nullptr;
				found = 1;
				pos = 0;
				spriteCount = (int16_t)Game::readU16LE(buffer, 0);
				pos += 2;
				if (spriteCount != 0) {
					table = newArray<int16_t>(spriteCount);
					for (writeIndex = 0; writeIndex < spriteCount; writeIndex++) {
						cast<Array<int16_t>>(table)[writeIndex] = (int16_t)Game::readU16LE(buffer, pos);
						pos += 2;
					}
					for (groupFill_n = 1; groupFill_n < spriteCount; groupFill_n++) {
						writeIndex = cast<Array<int16_t>>(table)[groupFill_n];
						s0 = groupFill_n;
						while (true) {
							group_n = s0;
							if (group_n <= 0 || cast<Array<int16_t>>(table)[group_n - 1] <= writeIndex) {
								break;
							}
							cast<Array<int16_t>>(table)[group_n] = cast<Array<int16_t>>(table)[group_n - 1];
							s0 = group_n - 1;
						}
						cast<Array<int16_t>>(table)[group_n] = writeIndex;
					}
					groupFill = this->getClass()->getResourceAsStream(Cutscene::spritesPath);
					dest = newArray<int8_t>(4);
					groupFill->read(cast<Array<int8_t>>(dest), 0, 2);
					remaining = (int16_t)Game::readU16LE(cast<Array<int8_t>>(dest), 0);
					if (Cutscene::sprites == nullptr) {
						Cutscene::sprites = newArray<Ref<SpritePack>>(remaining);
					}
					index = 0;
					while (index < spriteCount) {
						opcode = cast<Array<int16_t>>(table)[index];
						command_n = 0;
						while (command_n == 0) {
							groupFill->read(cast<Array<int8_t>>(dest), 0, 2);
							word = (int16_t)Game::readU16LE(cast<Array<int8_t>>(dest), 0);
							if (opcode == word) {
								command_n = 1;
							}
							groupFill->read(cast<Array<int8_t>>(dest), 0, 4);
							size = Game::readS32LE(cast<Array<int8_t>>(dest), 0);
							if (command_n != 0 || Cutscene::sprites[opcode] == nullptr) {
								dest = newArray<int8_t>(size);
								groupFill->read(cast<Array<int8_t>>(dest));
								Cutscene::sprites[opcode] = jnew<SpritePack>()->init();
								Cutscene::sprites[opcode]->loadFromBytes(cast<Array<int8_t>>(dest), 0);
								Cutscene::sprites[opcode]->buildModuleImages(0, 0, -1, -1);
								Cutscene::sprites[opcode]->moduleData = nullptr;
								continue;
							}
							groupFill->skip((int64_t)size);
						}
						index++;
					}
					groupFill->close();
				}
				table = newArray<Arr<int8_t>>(stepCount);
				writeIndex = 0;
				group = nullptr;
				groupFill_n = 0;
				dest = nullptr;
				remaining = 0;
				for (index = 0; index < stepCount || remaining != 0; index++) {
					if (remaining != 0) {
						dest = group;
						remaining--;
						index--;
					} else {
						dest = cast<Array<Arr<int8_t>>>(table);
					}
					opcode = buffer[pos++] & 255;
					command = nullptr;
					switch (opcode) {
						case 27:
							textLength = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							command = newArray<int8_t>(8 + textLength);
							Cutscene::writeShort(command, 2, textLength);
							Cutscene::writeShort(command, 4, 10000);
							command[6] = 0;
							command[7] = 0;
							JSystem::arraycopy(buffer, pos, command, 8, textLength);
							pos = pos + textLength;
							break;
						case 26:
							argX = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							argY = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							cellValue = Game::readS32LE(buffer, pos);
							pos += 4;
							command = newArray<int8_t>(10);
							Cutscene::writeShort(command, 2, argX);
							Cutscene::writeShort(command, 4, argY);
							Cutscene::writeInt(command, 6, cellValue);
							break;
						case 25:
							argX = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							argY = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							lowByte = (int16_t)(buffer[pos++] & 255);
							highByte = (int16_t)(buffer[pos++] & 255);
							command = newArray<int8_t>(8);
							Cutscene::writeShort(command, 2, argX);
							Cutscene::writeShort(command, 4, argY);
							command[6] = (int8_t)lowByte;
							command[7] = (int8_t)highByte;
							break;
						case 18:
							word = (int16_t)(buffer[pos++] & 255);
							size = (buffer[pos++] & 255) + ((buffer[pos++] & 255) << 8) + ((buffer[pos++] & 255) << 16);
							command = newArray<int8_t>(8);
							Cutscene::writeShort(command, 2, word);
							Cutscene::writeInt(command, 3, size);
							command[7] = 0;
							break;
						case 16:
						case 17:
							frameArg = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							word = (int16_t)(buffer[pos++] & 255);
							command = newArray<int8_t>(6);
							Cutscene::writeShort(command, 2, frameArg);
							Cutscene::writeShort(command, 4, word);
							command[5] = 0;
							break;
						case 14:
						case 15:
							s0_o = newArray<int8_t>(2);
							command = cast<Array<int8_t>>(s0_o);
							break;
						case 13:
							argX = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							argY = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							duration = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							command = newArray<int8_t>(12);
							Cutscene::writeShort(command, 2, argX);
							Cutscene::writeShort(command, 4, argY);
							Cutscene::writeShort(command, 6, duration);
							Cutscene::writeShort(command, 8, 10000);
							Cutscene::writeShort(command, 10, 10000);
							break;
						case 12:
							argX = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							argY = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							command = newArray<int8_t>(6);
							Cutscene::writeShort(command, 2, argX);
							Cutscene::writeShort(command, 4, argY);
							break;
						case 11:
							frameArg = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							packArg = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							command = newArray<int8_t>(6);
							Cutscene::writeShort(command, 2, frameArg);
							Cutscene::writeShort(command, 4, packArg);
							break;
						case 10:
							direction = (int16_t)(buffer[pos++] & 255);
							command = newArray<int8_t>(3);
							command[2] = (int8_t)direction;
							break;
						case 9:
							argX = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							argY = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							extraArg = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							command = newArray<int8_t>(8);
							Cutscene::writeShort(command, 2, argX);
							Cutscene::writeShort(command, 4, argY);
							Cutscene::writeShort(command, 6, extraArg);
							break;
						case 7:
							s0_o = newArray<int8_t>(2);
							command = cast<Array<int8_t>>(s0_o);
							break;
						case 6:
							delay = Game::readS32LE(buffer, pos);
							pos += 4;
							command = newArray<int8_t>(6);
							Cutscene::writeInt(command, 2, delay);
							break;
						case 5:
							argX = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							argY = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							lowByte = (int16_t)(buffer[pos++] & 255);
							command = newArray<int8_t>(7);
							Cutscene::writeShort(command, 2, argX);
							Cutscene::writeShort(command, 4, argY);
							command[6] = (int8_t)lowByte;
							break;
						case 4:
							fromX = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							fromY = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							toX = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							toY = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							packIndex = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							frameArg = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							duration = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							command = newArray<int8_t>(16);
							Cutscene::writeShort(command, 2, fromX);
							Cutscene::writeShort(command, 4, fromY);
							Cutscene::writeShort(command, 6, toX);
							Cutscene::writeShort(command, 8, toY);
							Cutscene::writeShort(command, 10, packIndex);
							Cutscene::writeShort(command, 12, frameArg);
							Cutscene::writeShort(command, 14, duration);
							break;
						case 2:
							visibleLines = (int16_t)(buffer[pos++] & 255);
							argY = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							textLength = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							command = newArray<int8_t>(11 + textLength);
							Cutscene::writeShort(command, 2, textLength);
							Cutscene::writeShort(command, 4, 10000);
							Cutscene::writeShort(command, 6, argY);
							command[8] = (int8_t)visibleLines;
							command[9] = 0;
							command[10] = 0;
							JSystem::arraycopy(buffer, pos, command, 11, textLength);
							pos = pos + textLength;
							break;
						case 1:
							argX = (int16_t)(Game::readU16LE(buffer, pos) * 24);
							pos += 2;
							argY = (int16_t)(Game::readU16LE(buffer, pos) * 24);
							pos += 2;
							duration = (int16_t)Game::readU16LE(buffer, pos);
							pos += 2;
							command = newArray<int8_t>(12);
							Cutscene::writeShort(command, 2, argX);
							Cutscene::writeShort(command, 4, argY);
							Cutscene::writeShort(command, 6, duration);
							Cutscene::writeShort(command, 8, 10000);
							Cutscene::writeShort(command, 10, 10000);
							break;
						case 0:
							remaining = (int16_t)(buffer[pos++] & 255);
							group = newArray<Arr<int8_t>>(remaining);
							s0_o = nullptr;
							command = cast<Array<int8_t>>(s0_o);
							break;
						default:
							break;
					}
					if (command != nullptr) {
						command[0] = (int8_t)(opcode & 255);
						command[1] = 0;
						if (cast<Array<Arr<int8_t>>>(dest) != group) {
							cast<Array<Arr<int8_t>>>(dest)[writeIndex] = command;
							writeIndex++;
						} else {
							cast<Array<Arr<int8_t>>>(dest)[groupFill_n] = command;
							groupFill_n++;
						}
					}
					if (cast<Array<Arr<int8_t>>>(dest) == group && remaining == 0) {
						word = 0;
						for (size = 0; size < group->length; size++) {
							word = word + group[size]->length;
						}
						command = newArray<int8_t>(2 + group->length * 4 + word);
						command[0] = 0;
						command[1] = (int8_t)group->length;
						size = 2 + group->length * 4;
						for (frameArg = 0; frameArg < group->length; frameArg++) {
							Cutscene::writeInt(command, 2 + frameArg * 4, group[frameArg]->length);
							JSystem::arraycopy(group[frameArg], 0, command, size, group[frameArg]->length);
							size = size + group[frameArg]->length;
						}
						cast<Array<Arr<int8_t>>>(table)[writeIndex] = command;
						groupFill_n = 0;
						group = nullptr;
						writeIndex++;
					}
				}
				this->steps = cast<Array<Arr<int8_t>>>(table);
			}
			if (found == 0) {
				continue;
			}
			break;
		}
	} catch (JavaException& ex) {
		if (ex.isa(u"java/lang/Exception")) {
			s0_o = ex.ex;
			return;
		}
		else throw;
	}
}

void Cutscene::drawWrappedLines(Ref<Graphics> g, Ref<String> text, int32_t x, int32_t y, int32_t firstLine, int32_t endLine) {
	int32_t lineHeight = 0, line = 0;
	lineHeight = Game::spritePacks[41]->lineSpacing + (Game::spritePacks[41]->moduleSizes[1] & 255);
	if (endLine > this->lineCount) {
		endLine = this->lineCount;
	}
	for (line = firstLine; line < endLine; line++) {
		SpritePack::textStart = line <= 0 ? 0 : this->lineEnds[line - 1] + 1;
		SpritePack::textEnd = this->lineEnds[line];
		Game::spritePacks[41]->drawString(g, text, x, y + (line - firstLine) * lineHeight, 4);
	}
	SpritePack::textStart = -1;
	SpritePack::textEnd = -1;
}

void Cutscene::wrapText(Ref<String> text, int32_t maxWidth) {
	int32_t sizeIndex = 0, length = 0, lineWidth = 0, breakStart = 0, charIndex = 0, ch = 0, glyph = 0, nextGlyph = 0, t3 = 0, t5 = 0, t7 = 0;
	Arr<int16_t> t2, t4, t6;
	this->lineCount = 0;
	length = text->length();
	lineWidth = 0;
	breakStart = 0;
	for (charIndex = 0; charIndex < length; charIndex++) {
		ch = text->charAt(charIndex);
		if (ch <= 32) {
			if (ch != 32 || charIndex + 1 >= length || text->charAt(charIndex + 1) != 63 && text->charAt(charIndex + 1) != 33 && text->charAt(charIndex + 1) != 58) {
				if (ch == 32) {
					lineWidth = lineWidth + ((Game::spritePacks[41]->moduleSizes[0] & 255) + Game::spritePacks[41]->frameModules[1]);
					breakStart = charIndex + 1;
				}
				if (ch == 10) {
					lineWidth = 0;
					t2 = this->lineEnds;
					t3 = this->lineCount;
					this->lineCount = t3 + 1;
					t2[t3] = (int16_t)charIndex;
				}
			} else {
				lineWidth = lineWidth + ((Game::spritePacks[41]->moduleSizes[0] & 255) + Game::spritePacks[41]->frameModules[1]);
				nextGlyph = SpritePack::charMap[text->charAt(charIndex + 1)] & 255;
				sizeIndex = (Game::spritePacks[41]->frameModules[nextGlyph << 2] & 255) << 1;
				lineWidth = lineWidth + ((Game::spritePacks[41]->moduleSizes[sizeIndex] & 255) - Game::spritePacks[41]->frameModules[(nextGlyph << 2) + 1] + Game::spritePacks[41]->frameModules[1]);
				if (lineWidth > maxWidth) {
					charIndex = breakStart - 1;
					t4 = this->lineEnds;
					t5 = this->lineCount;
					this->lineCount = t5 + 1;
					t4[t5] = (int16_t)charIndex;
					lineWidth = 0;
				}
				if (text->charAt(charIndex) == 32) {
					breakStart = charIndex + 1;
				}
			}
		} else {
			glyph = SpritePack::charMap[ch] & 255;
			nextGlyph = (Game::spritePacks[41]->frameModules[glyph << 2] & 255) << 1;
			lineWidth = lineWidth + ((Game::spritePacks[41]->moduleSizes[nextGlyph] & 255) - Game::spritePacks[41]->frameModules[(glyph << 2) + 1] + Game::spritePacks[41]->frameModules[1]);
			if (lineWidth > maxWidth) {
				charIndex = breakStart - 1;
				t4 = this->lineEnds;
				t5 = this->lineCount;
				this->lineCount = t5 + 1;
				t4[t5] = (int16_t)charIndex;
				lineWidth = 0;
			}
			if (text->charAt(charIndex) == 32) {
				breakStart = charIndex + 1;
			}
		}
	}
	t6 = this->lineEnds;
	t7 = this->lineCount;
	this->lineCount = t7 + 1;
	t6[t7] = (int16_t)length;
}

void Cutscene::writeShort(Arr<int8_t> buffer, int32_t offset, int16_t value) {
	buffer[offset] = (int8_t)(value & 255);
	buffer[offset + 1] = (int8_t)(value >> 8 & 255);
}

void Cutscene::writeInt(Arr<int8_t> buffer, int32_t offset, int32_t value) {
	buffer[offset] = (int8_t)(value & 255);
	buffer[offset + 1] = (int8_t)(value >> 8 & 255);
	buffer[offset + 2] = (int8_t)(value >> 16 & 255);
	buffer[offset + 3] = (int8_t)(value >> 24 & 255);
}

void Cutscene::clinit() {
	Cutscene::startDelayMs = 1000LL;
	Cutscene::spritesPath = u"/demoSpr.bin"_j;
	Cutscene::scriptPath = u"/demo.f"_j;
	Cutscene::sprites = nullptr;
}

