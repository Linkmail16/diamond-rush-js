'use strict';

class Cutscene {
	static startDelayMs = 0n;
	static spritesPath = null;
	static scriptPath = null;
	static sprites = null;
	steps = null;
	nextStepIndex = 0;
	stepStartTime = 0n;
	currentStep = null;
	stepTick = 0;
	isPortraitVisible = 0;
	portraitX = 0;
	portraitY = 0;
	portraitFrame = 0;
	portraitPackIndex = 0;
	portraitIconFrame = 0;
	isSkipped = 0;
	game = null;
	lineEnds = null;
	lineCount = 0;

	init(gameRef) {
		this.steps = null;
		this.nextStepIndex = 0;
		this.currentStep = null;
		this.isPortraitVisible = 0;
		this.portraitX = 0;
		this.portraitY = 0;
		this.portraitFrame = 0;
		this.portraitPackIndex = 0;
		this.portraitIconFrame = -1;
		this.isSkipped = 0;
		this.game = null;
		this.lineEnds = new Int16Array(16);
		this.game = gameRef;
		return this;
	}

	drawCommand(g, step, offset) {
		let text = null, maxCamY = 0, frameId = 0, visibleLines = 0, playerY = 0, firstLine = 0, toY = 0, lerpX = 0, fromX = 0, toX = 0, posX = 0, packIndex = 0, lerpY = 0, fromY = 0, boxHeight = 0, playerX = 0, opcode = 0, duration = 0, posY = 0, maxCamX = 0, tick = 0, s0, s1, t2;
		if (step === null) {
			return;
		}
		opcode = step[offset + 0];
		switch (opcode) {
			case 27:
				Game.spritePacks[41].lineSpacing = 2;
				firstLine = step[offset + 6] & 255;
				Game.drawFramedBoxWithTab(g, 6, 229, 226, 35, 73, 1, Game.measureFirstLineWidth(Game.spritePacks[41], Game.langStrings[70], 0) + 10 | 0, 15);
				text = null;
				try {
					text = J.newString(step, offset + 8 | 0, Game.readU16LE(step, offset + 2 | 0) << 16 >> 16, "ISO-8859-1");
				} catch (ex) {
					ex = J.exc(ex);
					if (J.isa(ex, "java/lang/Exception")) {
						s0 = ex;
					}
					else throw ex;
				}
				this.wrapText(text, 196);
				this.drawWrappedLines(g, text, 22, 231, firstLine, firstLine + 2 | 0);
				Game.spritePacks[41].drawString(g, Game.langStrings[70], 19, 211, 20);
				if ((Game.drawCount / 2 | 0) % 4 >= 2) {
					return;
				}
				g.drawImage(Game.uiFrameImages[0][9], 223, 220, 17);
				return;
			case 18:
				if (step[offset + 7] === 0) {
					return;
				}
				tick = (step[offset + 3] & 255) + ((step[offset + 3 + 1] & 255) << 8) + ((step[offset + 3 + 2] & 255) << 16) | 0;
				g.setColor(tick);
				g.fillRect(0, 0, 240, 320);
				return;
			case 13:
				tick = this.stepTick;
				toX = Game.readU16LE(step, offset + 2 | 0) << 16 >> 16;
				toY = Game.readU16LE(step, offset + 4 | 0) << 16 >> 16;
				duration = Game.readU16LE(step, offset + 6 | 0) << 16 >> 16;
				fromX = Game.readU16LE(step, offset + 8 | 0) << 16 >> 16;
				fromY = Game.readU16LE(step, offset + 10 | 0) << 16 >> 16;
				if (tick > duration) {
					tick = duration;
				}
				lerpX = J.idiv(Math.imul(toX, tick) + Math.imul(fromX, duration - tick | 0) | 0, duration) << 16 >> 16;
				lerpY = J.idiv(Math.imul(toY, tick) + Math.imul(fromY, duration - tick | 0) | 0, duration) << 16 >> 16;
				if (opcode !== 13) {
					return;
				}
				this.portraitX = lerpX;
				this.portraitY = lerpY;
				return;
			case 12:
				tick = this.stepTick;
				g.setColor(16777215);
				if (tick > 5) {
					tick = 5;
				}
				playerX = this.game.playerCol * 24 | 0;
				playerY = this.game.playerRow * 24 | 0;
				lerpX = this.portraitX;
				lerpY = this.portraitY;
				g.fillRect((Math.imul(playerX - this.game.camX | 0, 5 - tick | 0) + Math.imul(lerpX, tick) | 0) / 5 | 0, (Math.imul(playerY - this.game.camY | 0, 5 - tick | 0) + Math.imul(lerpY, tick) | 0) / 5 | 0, (102 * tick | 0) / 5 | 0, (38 * tick | 0) / 5 | 0);
				return;
			case 4:
				tick = this.stepTick;
				fromX = Game.readU16LE(step, offset + 2 | 0) << 16 >> 16;
				fromY = Game.readU16LE(step, offset + 4 | 0) << 16 >> 16;
				toX = Game.readU16LE(step, offset + 6 | 0) << 16 >> 16;
				toY = Game.readU16LE(step, offset + 6 | 0) << 16 >> 16;
				duration = Game.readU16LE(step, offset + 14 | 0) << 16 >> 16;
				if (tick > duration) {
					tick = duration;
				}
				posX = J.idiv(Math.imul(toX, tick) + Math.imul(fromX, duration - tick | 0) | 0, duration) << 16 >> 16;
				posY = J.idiv(Math.imul(toY, tick) + Math.imul(fromY, duration - tick | 0) | 0, duration) << 16 >> 16;
				packIndex = Game.readU16LE(step, offset + 10 | 0) << 16 >> 16;
				frameId = Game.readU16LE(step, offset + 12 | 0) << 16 >> 16;
				Cutscene.sprites[packIndex].drawFrame(g, frameId, posX, posY, 0, 0, 0);
				return;
			case 2:
				Game.spritePacks[41].lineSpacing = 2;
				posY = Game.readU16LE(step, offset + 6 | 0) << 16 >> 16;
				posX = Game.readU16LE(step, offset + 4 | 0) << 16 >> 16;
				if (posX === 10000) {
					posX = -240;
				}
				visibleLines = step[offset + 8] & 255;
				firstLine = step[offset + 9] & 255;
				boxHeight = Math.imul(visibleLines, Game.getFontLineHeight(Game.spritePacks[41])) + 4 - 2 | 0;
				Game.drawFramedBox(g, posX, posY, 226, boxHeight, 73, 0);
				text = null;
				try {
					text = J.newString(step, offset + 11 | 0, Game.readU16LE(step, offset + 2 | 0) << 16 >> 16, "ISO-8859-1");
				} catch (ex) {
					ex = J.exc(ex);
					if (J.isa(ex, "java/lang/Exception")) {
						s0 = ex;
					}
					else throw ex;
				}
				this.wrapText(text, 222);
				this.drawWrappedLines(g, text, posX + 2 | 0, posY + 2 | 0, firstLine, firstLine + visibleLines | 0);
				if ((Game.drawCount / 2 | 0) % 4 < 2) {
					g.drawImage(Game.uiFrameImages[0][9], posX + 226 - 10 | 0, posY + boxHeight - 5 | 0, 17);
				}
				g.setClip(0, 0, 240, 320);
				return;
			case 1:
				tick = this.stepTick;
				toX = Game.readU16LE(step, offset + 2 | 0) << 16 >> 16;
				toY = Game.readU16LE(step, offset + 4 | 0) << 16 >> 16;
				duration = Game.readU16LE(step, offset + 6 | 0) << 16 >> 16;
				fromX = Game.readU16LE(step, offset + 8 | 0) << 16 >> 16;
				fromY = Game.readU16LE(step, offset + 10 | 0) << 16 >> 16;
				if (fromX === 10000) {
					fromX = this.game.camTargetX << 16 >> 16;
				}
				if (fromY === 10000) {
					fromY = this.game.camTargetY << 16 >> 16;
				}
				if (tick > duration) {
					tick = duration;
				}
				toX = toX - 108 << 16 >> 16;
				toY = toY - 108 << 16 >> 16;
				this.game.camTargetX = J.idiv(Math.imul(toX, tick) + Math.imul(fromX, duration - tick | 0) | 0, duration) << 16 >> 16;
				this.game.camTargetY = J.idiv(Math.imul(toY, tick) + Math.imul(fromY, duration - tick | 0) | 0, duration) << 16 >> 16;
				maxCamX = this.game.levelW * 24 - 240 | 0;
				maxCamY = this.game.levelH * 24 - 320 + 80 | 0;
				if (this.game.camTargetX <= maxCamX) {
					if (this.game.camTargetX < 0) {
						s0 = this.game;
						s1 = 0;
						s0.camTargetX = s1;
					}
				} else {
					s0 = this.game;
					s1 = maxCamX;
					s0.camTargetX = s1;
				}
				if (this.game.camTargetY <= maxCamY) {
					if (this.game.camTargetY < 0) {
						s0 = this.game;
						s1 = 0;
						s0.camTargetY = s1;
					}
				} else {
					s0 = this.game;
					s1 = maxCamY;
					s0.camTargetY = s1;
				}
				this.game.camX = this.game.camTargetX;
				this.game.camY = this.game.camTargetY;
				if (this.game.camX > maxCamX) {
					t2 = this.game;
					t2.camX = t2.camX - maxCamX | 0;
				}
				if (this.game.camY <= maxCamY) {
					if (this.game.camY >= 0) {
						return;
					}
					return;
				}
				this.game.camY = maxCamY;
				return;
			default:
				return;
		}
	}

	onConfirmCommand(step, offset) {
		let text = null, opcode = 0, firstLine = 0, linesPerPage = 0, s0, s1, s2;
		opcode = step[offset + 0] << 16 >> 16;
		switch (opcode) {
			case 27:
				if (!Game.itemRaiseFreeze) {
					text = null;
					try {
						text = J.newString(step, offset + 8 | 0, Game.readU16LE(step, offset + 2 | 0) << 16 >> 16, "ISO-8859-1");
					} catch (ex) {
						ex = J.exc(ex);
						if (J.isa(ex, "java/lang/Exception")) {
							s0 = ex;
							this.wrapText(text, 196);
							firstLine = (step[offset + 6] & 255) << 16 >> 16;
							linesPerPage = 0;
							if ((firstLine + 2 | 0) < this.lineCount) {
								step[offset + 6] = firstLine + 2 << 24 >> 24;
								return;
							}
							step[offset + 7] = 1;
							return;
						}
						else throw ex;
					}
					this.wrapText(text, 196);
					firstLine = (step[offset + 6] & 255) << 16 >> 16;
					linesPerPage = 0;
					if ((firstLine + 2 | 0) < this.lineCount) {
						step[offset + 6] = firstLine + 2 << 24 >> 24;
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
				text = null;
				try {
					text = J.newString(step, offset + 11 | 0, Game.readU16LE(step, offset + 2 | 0) << 16 >> 16, "ISO-8859-1");
				} catch (ex) {
					ex = J.exc(ex);
					if (J.isa(ex, "java/lang/Exception")) {
						s0 = ex;
					}
					else throw ex;
				}
				this.wrapText(text, 222);
				firstLine = (step[offset + 9] & 255) << 16 >> 16;
				linesPerPage = (step[offset + 8] & 255) << 16 >> 16;
				if ((firstLine + linesPerPage | 0) < this.lineCount) {
					s0 = step;
					s1 = offset + 9 | 0;
					s2 = firstLine + linesPerPage << 24 >> 24;
				} else {
					s0 = step;
					s1 = offset + 10 | 0;
					s2 = 1;
				}
				s0[s1] = s2;
				return;
			default:
				return;
		}
	}

	onConfirmPressed() {
		let commandCount = 0, commandOffset = 0, commandSize = 0, commandIndex = 0;
		if (this.currentStep !== null) {
			if (J.labs(BigInt.asIntN(64, this.stepStartTime - JSystem.currentTimeMillis())) >= Cutscene.startDelayMs) {
				if (this.currentStep[0] !== 0) {
					this.onConfirmCommand(this.currentStep, 0);
				} else {
					commandCount = this.currentStep[1];
					commandOffset = 2 + commandCount * 4 | 0;
					for (commandIndex = 0; commandIndex < commandCount; commandIndex++) {
						commandSize = Game.readS32LE(this.currentStep, 2 + commandIndex * 4 | 0);
						this.onConfirmCommand(this.currentStep, commandOffset);
						commandOffset = commandOffset + commandSize | 0;
					}
				}
				return;
			}
			return;
		}
	}

	draw(g) {
		let commandCount = 0, commandOffset = 0, commandSize = 0, commandIndex = 0;
		if (!this.isSkipped) {
			switch (this.getStepOpcode()) {
				default:
					g.setColor(0);
					g.fillRect(0, 0, 240, 42);
					g.fillRect(0, 278, 240, 42);
					Game.spritePacks[41].drawString(g, Game.langStrings[53], 5, 315, 36);
					break;
				case 25:
				case 26:
					if (this.steps === null || this.nextStepIndex >= this.steps.length) {
						return;
					}
					break;
			}
			if (this.currentStep[0] !== 0) {
				this.drawCommand(g, this.currentStep, 0);
			} else {
				commandCount = this.currentStep[1];
				commandOffset = 2 + commandCount * 4 | 0;
				for (commandIndex = 0; commandIndex < commandCount; commandIndex++) {
					commandSize = Game.readS32LE(this.currentStep, 2 + commandIndex * 4 | 0);
					this.drawCommand(g, this.currentStep, commandOffset);
					commandOffset = commandOffset + commandSize | 0;
				}
			}
			if (this.isPortraitVisible) {
				g.setColor(0);
				g.fillRect(this.portraitX - 3 | 0, this.portraitY - 3 | 0, 109, 45);
				Cutscene.sprites[this.portraitPackIndex].drawAnimFrame(g, 0, J.irem(this.stepTick, Cutscene.sprites[this.portraitPackIndex].getAnimFrameCount(0)), this.portraitX, this.portraitY, 0, 0, 0);
				Cutscene.sprites[0].drawFrame(g, this.portraitFrame, this.portraitX + 0 | 0, this.portraitY, 0, 0, 0);
				if (this.portraitIconFrame >= 0) {
					Cutscene.sprites[1].drawFrame(g, this.portraitIconFrame, this.portraitX + 90 | 0, this.portraitY - 6 | 0, 0, 0, 0);
				}
			}
			return;
		}
	}

	start() {
		this.resetSteps(this.steps);
		this.isPortraitVisible = 0;
		this.portraitX = 0;
		this.portraitY = 0;
		this.portraitFrame = 0;
		this.portraitPackIndex = 0;
		this.portraitIconFrame = -1;
		this.isSkipped = 0;
		this.nextStepIndex = 0;
		this.stepStartTime = JSystem.currentTimeMillis();
		return this.nextStep();
	}

	resetCommand(step, offset) {
		let commandCount = 0, subOffset = 0, commandIndex = 0, commandSize = 0, s0, s1, s2;
		if (step[offset + 0] === 0) {
			commandCount = step[offset + 1];
			subOffset = offset + 2 + commandCount * 4 | 0;
			for (commandIndex = 0; commandIndex < commandCount; commandIndex++) {
				commandSize = Game.readS32LE(step, offset + 2 + commandIndex * 4 | 0);
				this.resetCommand(step, subOffset);
				subOffset = subOffset + commandSize | 0;
			}
			return;
		}
		step[offset + 1] = 0;
		switch (step[offset + 0]) {
			case 27:
				step[offset + 6] = 0;
				Cutscene.writeShort(step, offset + 4 | 0, -240);
				s0 = step;
				s1 = offset;
				s2 = 7;
				s0[s1 + s2] = 0;
				break;
			case 2:
				step[offset + 9] = 0;
				Cutscene.writeShort(step, offset + 4 | 0, -240);
				s0 = step;
				s1 = offset;
				s2 = 10;
				s0[s1 + s2] = 0;
				break;
			default:
				break;
		}
	}

	resetSteps(stepList) {
		let stepIndex = 0;
		for (stepIndex = 0; stepIndex < stepList.length; stepIndex++) {
			this.resetCommand(stepList[stepIndex], 0);
		}
	}

	nextStep() {
		let s1, t1, t2;
		this.stepTick = 0;
		if (this.steps === null || this.nextStepIndex >= this.steps.length) {
			s1 = null;
		} else {
			t1 = this.steps;
			t2 = this.nextStepIndex;
			this.nextStepIndex = t2 + 1 | 0;
			s1 = t1[t2];
		}
		this.currentStep = s1;
		return this.currentStep;
	}

	updateStep() {
		let commandCount = 0, commandOffset = 0, commandSize = 0, commandIndex = 0;
		if (this.currentStep[0] !== 0) {
			this.updateCommand(this.currentStep, 0);
		} else {
			commandCount = this.currentStep[1];
			commandOffset = 2 + commandCount * 4 | 0;
			for (commandIndex = 0; commandIndex < commandCount; commandIndex++) {
				commandSize = Game.readS32LE(this.currentStep, 2 + commandIndex * 4 | 0);
				this.updateCommand(this.currentStep, commandOffset);
				commandOffset = commandOffset + commandSize | 0;
			}
		}
		this.stepTick = this.stepTick + 1 | 0;
	}

	updateCommand(step, offset) {
		let blinksLeft = 0, iconFrame = 0, opcode = 0, duration = 0, moveDir = 0, x = 0, value = 0, toggleOffset = 0, counterOffset = 0, isBlinkOn = 0, valueHigh = 0, y = 0;
		opcode = step[offset + 0] << 16 >> 16;
		B1: {
			if (this.isSkipped) {
				switch (opcode) {
					default:
						step[offset + 1] = 1;
						return;
					case 5:
					case 9:
					case 10:
					case 25:
					case 26:
						break B1;
				}
			}
		}
		switch (opcode) {
			case 27:
				if (step[offset + 7] === 0) {
					return;
				}
				step[offset + 1] = 1;
				return;
			case 26:
				x = Game.readU16LE(step, offset + 2 | 0) << 16 >> 16;
				y = Game.readU16LE(step, offset + 4 | 0) << 16 >> 16;
				value = Game.readS32LE(step, offset + 6 | 0);
				Game.cellStates[x][y] = value;
				step[offset + 1] = 1;
				return;
			case 25:
				x = Game.readU16LE(step, offset + 2 | 0) << 16 >> 16;
				y = Game.readU16LE(step, offset + 4 | 0) << 16 >> 16;
				value = step[offset + 6];
				valueHigh = step[offset + 7];
				Game.cellObjects[x][y] = valueHigh << 8 | value;
				step[offset + 1] = 1;
				return;
			case 16:
			case 17:
			case 18:
				if (this.stepTick % 2 !== 0) {
					counterOffset = offset + (opcode !== 18 ? 4 : 2) | 0;
					blinksLeft = step[counterOffset];
					iconFrame = -1;
					toggleOffset = offset + (opcode !== 18 ? 5 : 7) | 0;
					isBlinkOn = step[toggleOffset] !== 0 ? 1 : 0;
					if (opcode !== 18) {
						iconFrame = Game.readU16LE(step, offset + 2 | 0) << 16 >> 16;
					}
					if (isBlinkOn === 0) {
						if (blinksLeft <= 0) {
							step[offset + 1] = 1;
						} else {
							isBlinkOn = 1;
							if (opcode !== 18) {
								this.portraitIconFrame = iconFrame;
							}
						}
					} else {
						isBlinkOn = 0;
						this.portraitIconFrame = -1;
						blinksLeft = blinksLeft - 1 << 24 >> 24;
						if (blinksLeft === 0) {
							step[offset + 1] = 1;
							if (opcode !== 18) {
								this.portraitIconFrame = opcode !== 16 ? -1 : iconFrame;
							}
						}
					}
					step[toggleOffset] = (isBlinkOn !== 0 ? 1 : 0) << 24 >> 24;
					step[counterOffset] = blinksLeft;
					return;
				}
				return;
			case 14:
			case 15:
				this.isPortraitVisible = opcode === 14 ? 1 : 0;
				step[offset + 1] = 1;
				return;
			case 13:
				if (Game.readU16LE(step, offset + 8 | 0) << 16 >> 16 === 10000) {
					Cutscene.writeShort(step, offset + 8 | 0, this.portraitX << 16 >> 16);
				}
				if (Game.readU16LE(step, offset + 10 | 0) << 16 >> 16 === 10000) {
					Cutscene.writeShort(step, offset + 10 | 0, this.portraitY << 16 >> 16);
				}
				duration = Game.readU16LE(step, offset + 6 | 0) << 16 >> 16;
				if (this.stepTick <= duration) {
					return;
				}
				step[offset + 1] = 1;
				return;
			case 12:
				x = Game.readU16LE(step, offset + 2 | 0) << 16 >> 16;
				y = Game.readU16LE(step, offset + 4 | 0) << 16 >> 16;
				this.portraitX = x;
				this.portraitY = y;
				if (this.stepTick <= 5) {
					return;
				}
				step[offset + 1] = 1;
				this.isPortraitVisible = 1;
				return;
			case 11:
				this.portraitPackIndex = Game.readU16LE(step, offset + 4 | 0) << 16 >> 16;
				this.portraitFrame = Game.readU16LE(step, offset + 2 | 0) << 16 >> 16;
				step[offset + 1] = 1;
				return;
			case 10:
				moveDir = step[offset + 2];
				if (this.stepTick !== 0) {
					if (this.game.playerStep <= 0) {
						this.game.requestedMoveDir = 0;
						step[offset + 1] = 1;
					}
				} else {
					this.game.explorerStateFlags = this.game.explorerStateFlags & -8 | moveDir;
					this.game.requestedMoveDir = moveDir;
				}
				this.game.updateCameraFollow();
				return;
			case 9:
				Game.setCellTypeAndState(Game.readU16LE(step, offset + 2 | 0) << 16 >> 16, Game.readU16LE(step, offset + 4 | 0) << 16 >> 16, 0, Game.readU16LE(step, offset + 6 | 0) << 16 >> 16);
				step[offset + 1] = 1;
				return;
			case 8:
				return;
			case 6:
				if (this.stepTick <= Game.readS32LE(step, offset + 2 | 0)) {
					return;
				}
				step[offset + 1] = 1;
				return;
			case 5:
				Game.setCellTypeAndState(Game.readU16LE(step, offset + 2 | 0) << 16 >> 16, Game.readU16LE(step, offset + 4 | 0) << 16 >> 16, step[offset + 6], 0);
				step[offset + 1] = 1;
				return;
			case 4:
				duration = Game.readU16LE(step, offset + 14 | 0) << 16 >> 16;
				if (this.stepTick <= duration) {
					return;
				}
				step[offset + 1] = 1;
				return;
			case 2:
				x = Game.readU16LE(step, offset + 4 | 0) << 16 >> 16;
				if (x === 10000) {
					x = -226;
				}
				x = x + 30 << 16 >> 16;
				if (step[offset + 10] !== 0) {
					if (x > 240) {
						step[offset + 1] = 1;
					}
				} else {
					if (x > 7) {
						x = 7;
					}
				}
				Cutscene.writeShort(step, offset + 4 | 0, x);
				return;
			case 1:
				if (Game.readU16LE(step, offset + 8 | 0) << 16 >> 16 === 10000) {
					Cutscene.writeShort(step, offset + 8 | 0, this.game.camTargetX << 16 >> 16);
				}
				if (Game.readU16LE(step, offset + 10 | 0) << 16 >> 16 === 10000) {
					Cutscene.writeShort(step, offset + 10 | 0, this.game.camTargetY << 16 >> 16);
				}
				duration = Game.readU16LE(step, offset + 6 | 0) << 16 >> 16;
				if (this.stepTick <= duration) {
					return;
				}
				step[offset + 1] = 1;
				return;
			default:
				return;
		}
	}

	isStepFinished() {
		let isDone = 0, commandIndex = 0, commandCount = 0, commandOffset = 0, commandSize = 0;
		isDone = 1;
		B1: {
			if (this.currentStep[0] !== 0) {
				isDone = this.currentStep[1] === 1 ? 1 : 0;
			} else {
				commandCount = this.currentStep[1];
				commandOffset = 2 + commandCount * 4 | 0;
				commandIndex = 0;
				while (true) {
					if (commandIndex >= commandCount) {
						break B1;
					}
					commandSize = Game.readS32LE(this.currentStep, 2 + commandIndex * 4 | 0);
					isDone = isDone !== 0 && this.currentStep[commandOffset + 1] === 1 ? 1 : 0;
					if (isDone) {
						commandOffset = commandOffset + commandSize | 0;
						commandIndex++;
						continue;
					}
					break;
				}
			}
		}
		return isDone;
	}

	getStepOpcode() {
		if (this.currentStep !== null) {
			return this.currentStep[0];
		}
		return -1;
	}

	loadScript(cutsceneId) {
		let stepCount = 0, size = 0, argX = 0, found = 0, visibleLines = 0, delay = 0, remaining = 0, frameArg = 0, highByte = 0, argY = 0, extraArg = 0, table = null, direction = 0, input = null, toY = 0, fromX = 0, toX = 0, group = 0, packIndex = 0, packArg = 0, cellValue = 0, lowByte = 0, fromY = 0, pos = 0, writeIndex = 0, word = 0, groupFill = 0, entryId = 0, index = 0, opcode = 0, dest = null, duration = 0, textLength = 0, command = 0, buffer = null, spriteCount = 0, dataSize = 0, s0, t1;
		try {
			t1 = Cutscene.scriptPath;
			J.getClass(this.game);
			input = new ByteArrayInputStream(Game.readResource(t1, 0));
			buffer = new Int8Array(4);
			input.read(buffer, 0, 2);
			found = 0;
			while (true) {
				input.read(buffer, 0, 2);
				entryId = Game.readU16LE(buffer, 0) << 16 >> 16;
				if (entryId !== cutsceneId) {
					input.skip(2n);
					input.read(buffer, 0, 4);
					stepCount = Game.readS32LE(buffer, 0);
					input.skip(BigInt(stepCount));
				} else {
					input.read(buffer, 0, 2);
					stepCount = Game.readU16LE(buffer, 0) << 16 >> 16;
					input.read(buffer, 0, 4);
					dataSize = Game.readS32LE(buffer, 0);
					buffer = new Int8Array(dataSize);
					input.read(buffer);
					input.close();
					input = null;
					found = 1;
					pos = 0;
					spriteCount = Game.readU16LE(buffer, 0) << 16 >> 16;
					pos += 2;
					if (spriteCount !== 0) {
						table = new Int16Array(spriteCount);
						for (writeIndex = 0; writeIndex < spriteCount; writeIndex++) {
							table[writeIndex] = Game.readU16LE(buffer, pos) << 16 >> 16;
							pos += 2;
						}
						for (groupFill = 1; groupFill < spriteCount; groupFill++) {
							writeIndex = table[groupFill];
							s0 = groupFill;
							while (true) {
								group = s0;
								if (group <= 0 || table[group - 1] <= writeIndex) {
									break;
								}
								table[group] = table[group - 1];
								s0 = group - 1 | 0;
							}
							table[group] = writeIndex;
						}
						groupFill = J.getClass(this).getResourceAsStream(Cutscene.spritesPath);
						dest = new Int8Array(4);
						groupFill.read(dest, 0, 2);
						remaining = Game.readU16LE(dest, 0) << 16 >> 16;
						if (Cutscene.sprites === null) {
							Cutscene.sprites = J.newArray(remaining);
						}
						index = 0;
						while (index < spriteCount) {
							opcode = table[index];
							command = 0;
							while (command === 0) {
								groupFill.read(dest, 0, 2);
								word = Game.readU16LE(dest, 0) << 16 >> 16;
								if (opcode === word) {
									command = 1;
								}
								groupFill.read(dest, 0, 4);
								size = Game.readS32LE(dest, 0);
								if (command !== 0 || Cutscene.sprites[opcode] === null) {
									dest = new Int8Array(size);
									groupFill.read(dest);
									Cutscene.sprites[opcode] = new SpritePack().init();
									Cutscene.sprites[opcode].loadFromBytes(dest, 0);
									Cutscene.sprites[opcode].buildModuleImages(0, 0, -1, -1);
									Cutscene.sprites[opcode].moduleData = null;
									continue;
								}
								groupFill.skip(BigInt(size));
							}
							index++;
						}
						groupFill.close();
					}
					table = J.newArray(stepCount);
					writeIndex = 0;
					group = null;
					groupFill = 0;
					dest = null;
					remaining = 0;
					for (index = 0; index < stepCount || remaining !== 0; index++) {
						if (remaining !== 0) {
							dest = group;
							remaining--;
							index--;
						} else {
							dest = table;
						}
						opcode = buffer[pos++] & 255;
						command = null;
						switch (opcode) {
							case 27:
								textLength = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								command = new Int8Array(8 + textLength | 0);
								Cutscene.writeShort(command, 2, textLength);
								Cutscene.writeShort(command, 4, 10000);
								command[6] = 0;
								command[7] = 0;
								JSystem.arraycopy(buffer, pos, command, 8, textLength);
								pos = pos + textLength | 0;
								break;
							case 26:
								argX = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								argY = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								cellValue = Game.readS32LE(buffer, pos);
								pos += 4;
								command = new Int8Array(10);
								Cutscene.writeShort(command, 2, argX);
								Cutscene.writeShort(command, 4, argY);
								Cutscene.writeInt(command, 6, cellValue);
								break;
							case 25:
								argX = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								argY = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								lowByte = (buffer[pos++] & 255) << 16 >> 16;
								highByte = (buffer[pos++] & 255) << 16 >> 16;
								command = new Int8Array(8);
								Cutscene.writeShort(command, 2, argX);
								Cutscene.writeShort(command, 4, argY);
								command[6] = lowByte << 24 >> 24;
								command[7] = highByte << 24 >> 24;
								break;
							case 18:
								word = (buffer[pos++] & 255) << 16 >> 16;
								size = (buffer[pos++] & 255) + ((buffer[pos++] & 255) << 8) + ((buffer[pos++] & 255) << 16) | 0;
								command = new Int8Array(8);
								Cutscene.writeShort(command, 2, word);
								Cutscene.writeInt(command, 3, size);
								command[7] = 0;
								break;
							case 16:
							case 17:
								frameArg = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								word = (buffer[pos++] & 255) << 16 >> 16;
								command = new Int8Array(6);
								Cutscene.writeShort(command, 2, frameArg);
								Cutscene.writeShort(command, 4, word);
								command[5] = 0;
								break;
							case 14:
							case 15:
								s0 = new Int8Array(2);
								command = s0;
								break;
							case 13:
								argX = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								argY = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								duration = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								command = new Int8Array(12);
								Cutscene.writeShort(command, 2, argX);
								Cutscene.writeShort(command, 4, argY);
								Cutscene.writeShort(command, 6, duration);
								Cutscene.writeShort(command, 8, 10000);
								Cutscene.writeShort(command, 10, 10000);
								break;
							case 12:
								argX = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								argY = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								command = new Int8Array(6);
								Cutscene.writeShort(command, 2, argX);
								Cutscene.writeShort(command, 4, argY);
								break;
							case 11:
								frameArg = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								packArg = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								command = new Int8Array(6);
								Cutscene.writeShort(command, 2, frameArg);
								Cutscene.writeShort(command, 4, packArg);
								break;
							case 10:
								direction = (buffer[pos++] & 255) << 16 >> 16;
								command = new Int8Array(3);
								command[2] = direction << 24 >> 24;
								break;
							case 9:
								argX = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								argY = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								extraArg = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								command = new Int8Array(8);
								Cutscene.writeShort(command, 2, argX);
								Cutscene.writeShort(command, 4, argY);
								Cutscene.writeShort(command, 6, extraArg);
								break;
							case 7:
								s0 = new Int8Array(2);
								command = s0;
								break;
							case 6:
								delay = Game.readS32LE(buffer, pos);
								pos += 4;
								command = new Int8Array(6);
								Cutscene.writeInt(command, 2, delay);
								break;
							case 5:
								argX = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								argY = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								lowByte = (buffer[pos++] & 255) << 16 >> 16;
								command = new Int8Array(7);
								Cutscene.writeShort(command, 2, argX);
								Cutscene.writeShort(command, 4, argY);
								command[6] = lowByte << 24 >> 24;
								break;
							case 4:
								fromX = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								fromY = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								toX = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								toY = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								packIndex = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								frameArg = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								duration = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								command = new Int8Array(16);
								Cutscene.writeShort(command, 2, fromX);
								Cutscene.writeShort(command, 4, fromY);
								Cutscene.writeShort(command, 6, toX);
								Cutscene.writeShort(command, 8, toY);
								Cutscene.writeShort(command, 10, packIndex);
								Cutscene.writeShort(command, 12, frameArg);
								Cutscene.writeShort(command, 14, duration);
								break;
							case 2:
								visibleLines = (buffer[pos++] & 255) << 16 >> 16;
								argY = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								textLength = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								command = new Int8Array(11 + textLength | 0);
								Cutscene.writeShort(command, 2, textLength);
								Cutscene.writeShort(command, 4, 10000);
								Cutscene.writeShort(command, 6, argY);
								command[8] = visibleLines << 24 >> 24;
								command[9] = 0;
								command[10] = 0;
								JSystem.arraycopy(buffer, pos, command, 11, textLength);
								pos = pos + textLength | 0;
								break;
							case 1:
								argX = Game.readU16LE(buffer, pos) * 24 << 16 >> 16;
								pos += 2;
								argY = Game.readU16LE(buffer, pos) * 24 << 16 >> 16;
								pos += 2;
								duration = Game.readU16LE(buffer, pos) << 16 >> 16;
								pos += 2;
								command = new Int8Array(12);
								Cutscene.writeShort(command, 2, argX);
								Cutscene.writeShort(command, 4, argY);
								Cutscene.writeShort(command, 6, duration);
								Cutscene.writeShort(command, 8, 10000);
								Cutscene.writeShort(command, 10, 10000);
								break;
							case 0:
								remaining = (buffer[pos++] & 255) << 16 >> 16;
								group = J.newArray(remaining);
								s0 = null;
								command = s0;
								break;
							default:
								break;
						}
						if (command !== null) {
							command[0] = (opcode & 255) << 24 >> 24;
							command[1] = 0;
							if (dest !== group) {
								dest[writeIndex] = command;
								writeIndex++;
							} else {
								dest[groupFill] = command;
								groupFill++;
							}
						}
						if (dest === group && remaining === 0) {
							word = 0;
							for (size = 0; size < group.length; size++) {
								word = word + group[size].length | 0;
							}
							command = new Int8Array(2 + group.length * 4 + word | 0);
							command[0] = 0;
							command[1] = group.length << 24 >> 24;
							size = 2 + group.length * 4 | 0;
							for (frameArg = 0; frameArg < group.length; frameArg++) {
								Cutscene.writeInt(command, 2 + frameArg * 4 | 0, group[frameArg].length);
								JSystem.arraycopy(group[frameArg], 0, command, size, group[frameArg].length);
								size = size + group[frameArg].length | 0;
							}
							table[writeIndex] = command;
							groupFill = 0;
							group = null;
							writeIndex++;
						}
					}
					this.steps = table;
				}
				if (found === 0) {
					continue;
				}
				break;
			}
		} catch (ex) {
			ex = J.exc(ex);
			if (J.isa(ex, "java/lang/Exception")) {
				s0 = ex;
				return;
			}
			else throw ex;
		}
	}

	drawWrappedLines(g, text, x, y, firstLine, endLine) {
		let line = 0, lineHeight = 0;
		lineHeight = Game.spritePacks[41].lineSpacing + (Game.spritePacks[41].moduleSizes[1] & 255) | 0;
		if (endLine > this.lineCount) {
			endLine = this.lineCount;
		}
		for (line = firstLine; line < endLine; line++) {
			SpritePack.textStart = line <= 0 ? 0 : this.lineEnds[line - 1] + 1 | 0;
			SpritePack.textEnd = this.lineEnds[line];
			Game.spritePacks[41].drawString(g, text, x, y + Math.imul(line - firstLine | 0, lineHeight) | 0, 4);
		}
		SpritePack.textStart = -1;
		SpritePack.textEnd = -1;
	}

	wrapText(text, maxWidth) {
		let glyph = 0, nextGlyph = 0, charIndex = 0, ch = 0, breakStart = 0, lineWidth = 0, length = 0, sizeIndex = 0, t2, t3, t4, t5, t6, t7;
		this.lineCount = 0;
		length = text.length;
		lineWidth = 0;
		breakStart = 0;
		for (charIndex = 0; charIndex < length; charIndex++) {
			ch = text.charCodeAt(charIndex);
			if (ch <= 32) {
				if (ch !== 32 || (charIndex + 1 | 0) >= length || text.charCodeAt(charIndex + 1 | 0) !== 63 && text.charCodeAt(charIndex + 1 | 0) !== 33 && text.charCodeAt(charIndex + 1 | 0) !== 58) {
					if (ch === 32) {
						lineWidth = lineWidth + ((Game.spritePacks[41].moduleSizes[0] & 255) + Game.spritePacks[41].frameModules[1]) | 0;
						breakStart = charIndex + 1 | 0;
					}
					if (ch === 10) {
						lineWidth = 0;
						t2 = this.lineEnds;
						t3 = this.lineCount;
						this.lineCount = t3 + 1 | 0;
						t2[t3] = charIndex << 16 >> 16;
					}
				} else {
					lineWidth = lineWidth + ((Game.spritePacks[41].moduleSizes[0] & 255) + Game.spritePacks[41].frameModules[1]) | 0;
					nextGlyph = SpritePack.charMap[text.charCodeAt(charIndex + 1 | 0)] & 255;
					sizeIndex = (Game.spritePacks[41].frameModules[nextGlyph << 2] & 255) << 1;
					lineWidth = lineWidth + ((Game.spritePacks[41].moduleSizes[sizeIndex] & 255) - Game.spritePacks[41].frameModules[(nextGlyph << 2) + 1] + Game.spritePacks[41].frameModules[1]) | 0;
					if (lineWidth > maxWidth) {
						charIndex = breakStart - 1 | 0;
						t4 = this.lineEnds;
						t5 = this.lineCount;
						this.lineCount = t5 + 1 | 0;
						t4[t5] = charIndex << 16 >> 16;
						lineWidth = 0;
					}
					if (text.charCodeAt(charIndex) === 32) {
						breakStart = charIndex + 1 | 0;
					}
				}
			} else {
				glyph = SpritePack.charMap[ch] & 255;
				nextGlyph = (Game.spritePacks[41].frameModules[glyph << 2] & 255) << 1;
				lineWidth = lineWidth + ((Game.spritePacks[41].moduleSizes[nextGlyph] & 255) - Game.spritePacks[41].frameModules[(glyph << 2) + 1] + Game.spritePacks[41].frameModules[1]) | 0;
				if (lineWidth > maxWidth) {
					charIndex = breakStart - 1 | 0;
					t4 = this.lineEnds;
					t5 = this.lineCount;
					this.lineCount = t5 + 1 | 0;
					t4[t5] = charIndex << 16 >> 16;
					lineWidth = 0;
				}
				if (text.charCodeAt(charIndex) === 32) {
					breakStart = charIndex + 1 | 0;
				}
			}
		}
		t6 = this.lineEnds;
		t7 = this.lineCount;
		this.lineCount = t7 + 1 | 0;
		t6[t7] = length << 16 >> 16;
	}

	static writeShort(buffer, offset, value) {
		buffer[offset] = (value & 255) << 24 >> 24;
		buffer[offset + 1] = (value >> 8 & 255) << 24 >> 24;
	}

	static writeInt(buffer, offset, value) {
		buffer[offset] = (value & 255) << 24 >> 24;
		buffer[offset + 1] = (value >> 8 & 255) << 24 >> 24;
		buffer[offset + 2] = (value >> 16 & 255) << 24 >> 24;
		buffer[offset + 3] = (value >> 24 & 255) << 24 >> 24;
	}

	static clinit() {
		Cutscene.startDelayMs = 1000n;
		Cutscene.spritesPath = "/demoSpr.bin";
		Cutscene.scriptPath = "/demo.f";
		Cutscene.sprites = null;
	}

}
