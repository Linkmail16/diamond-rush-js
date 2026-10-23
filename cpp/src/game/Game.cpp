#include "game.h"

Ref<Game> Game::init(Ref<Midlet> midletRef) {
	Arr<int32_t> t1;
	GameCanvas::init(0);
	this->boulderHoldTimer = 40;
	this->isHoldingBoulder = 0;
	this->shopCursor = 0;
	this->shopItemCost = Tables::upgradeCosts[this->shopCursor];
	this->shopMessage = u""_j;
	this->isExplorerVisible = 1;
	this->worldMapNode = 0;
	this->worldMapCursorX = 0;
	this->worldMapCursorY = 0;
	this->worldMapCursorPrevX = this->worldMapCursorX;
	this->worldMapCursorPrevY = this->worldMapCursorY;
	this->worldMapHintText = u""_j;
	this->worldMapNodeName = u""_j;
	this->worldMapCommand = -1;
	this->isWorldMapCursorMoving = 0;
	this->worldMapInfoDirty = 1;
	this->worldMapCursorStep = 0;
	this->worldMapCursorTargetX = 0;
	this->worldMapCursorTargetY = 0;
	this->worldMapCursorFrameCount = 0;
	this->worldMapCursorFrame = 0;
	this->medallionX = 0;
	this->medallionY = 0;
	this->worldUnlockAnimIndex = 0;
	this->worldUnlockBlinkCount = 0;
	this->gotElementalDiamond = 0;
	this->placingElementalIndex = -1;
	this->flyingGemX = 10;
	this->flyingGemY = 10;
	this->gemHalfWidth = 0;
	this->gemHalfHeight = 0;
	this->gemFlashCounter = 0;
	this->sparkleFrameCount = 0;
	this->sparkleFrame = 0;
	this->creditsAfterEnding = 0;
	this->anacondaAttackTimer = 0;
	this->anacondaBlockCol = -1;
	this->anacondaBlockRow = -1;
	this->bossRockSpawnRow = 0;
	this->bossRockCol1 = 0;
	this->bossRockCol2 = 0;
	this->bossRockCheckRow = 0;
	this->anacondaStateWhenHit = 0;
	this->anacondaHitPlayer = 0;
	this->anacondaSlamVisible = 0;
	this->anacondaRiseOffset = 0;
	this->worldUnlockToAnnounce = 0;
	this->armorUnlockToAnnounce = 0;
	this->endingPhase = 0;
	this->endingFlashColor = 0;
	this->medallionShakeX = 0;
	this->medallionShakeY = 0;
	this->medallionShakeDirY = 1;
	this->medallionShakeDirX = 1;
	this->medallionShakeRangeY = 3;
	this->medallionShakeRangeX = 3;
	this->medallionShakeSpeedY = 2;
	this->medallionShakeSpeedX = 0;
	this->hasWaterLayer = 0;
	this->loadingTipIndex = 0;
	this->isExplorerOnGround = 1;
	this->specialStageType = 0;
	this->checkpointTextEndFrame = 0;
	this->introTrigger13Reached = 0;
	this->introTrigger16Reached = 0;
	this->introHintSpotReached = 0;
	this->introHintIconVisible = 0;
	this->requestedMoveDir = 0;
	this->currentMoveDir = 0;
	this->resultsSkipPressed = 0;
	this->diamondsInStage = 0;
	this->redDiamondsInStage = 0;
	this->pendingCutsceneId = -1;
	this->landingDustFrame = 0;
	this->checkpointEntryWalk = 0;
	this->checkpointDiamonds = 0;
	this->checkpointRedDiamonds = 0;
	this->checkpointNextIndex = 0;
	this->checkpointRisingHazardPhase = 0;
	this->checkpointRisingHazardHeight = 0;
	this->fromStageClear = 0;
	this->isNewGame = 0;
	this->activeCutscene = nullptr;
	this->killerCol = -1;
	this->killerRow = -1;
	this->checkpointMsgCount = 0;
	this->titleShown = 0;
	this->needFreeMenuRes = 0;
	this->needFreeMapRes = 0;
	this->needSaveStageResult = 0;
	this->needLevelCleanup = 0;
	this->needFreeCutscenes = 0;
	this->needGarbageCollect = 0;
	this->needReadSaveStats = 0;
	this->needWriteSave = 0;
	this->playerPaletteIndex = -1;
	this->stageWasCompleted = 0;
	this->newGamePromptDirty = 0;
	this->loadingFullRedraw = 0;
	this->hudShownEnergy = -1;
	this->hudShownDiamonds = -1;
	this->hudShownRedDiamonds = -1;
	this->hudShownLives = -1;
	this->hudShownDiamondsLeft = -1;
	this->hudShownKeysA = -1;
	this->hudShownKeysB = -1;
	this->hudFrame19Visible = 1;
	this->menuTextScrollStep = 2;
	this->menuTextScrollX = 0;
	this->menuRevealDelay = 3;
	this->menuConfirmStep = -1;
	this->menuConfirmStepTime = 0LL;
	this->menuLastDrawnItem = -1;
	this->menuMoveLockTime = 0LL;
	this->cheatPassLevels = 0;
	this->debugTextPage = 0;
	t1 = newArray<int32_t>(5);
	t1[0] = 0;
	t1[1] = 0;
	t1[2] = 0;
	t1[3] = 0;
	t1[4] = 0;
	this->debugTextIndices = t1;
	this->newStageUnlocked = 0;
	this->lastLeverAnimTime = 0LL;
	this->bossAttackOffset = 0;
	this->bossQuakeFrame = 0LL;
	this->ceilingCollapseFrame = 0LL;
	this->paused = 0;
	this->resumeMenuMusic = 0;
	this->bossTreasureTaken = 0;
	this->hintTimer = 0;
	this->showMoreGamesBadge = 0;
	this->liquidStartNextEmitter = 1;
	this->liquidDrainTick = -1;
	this->liquidFlowTick = -1;
	this->liquidState = 3;
	this->firstSecretStage = 100;
	this->markerWalkRestart = 1;
	this->unlockPathShown = 1;
	this->recordUnlockPath = 1;
	this->unlockRevealDone = 1;
	this->unlockPathDotDelay = 2;
	this->unlockNodeBlinkTimer = 2;
	this->usedMainExit = 1;
	this->stageMapImageNeeded = 1;
	this->stageSelectLockTime = 0LL;
	this->shopLastDrawnCursor = -1;
	this->shopPriceText = jnew<StringBuffer>();
	this->needsFullRedraw = 1;
	this->stageMapAnimating = 1;
	this->popupLastTick = JSystem::currentTimeMillis();
	Game::instance = this;
	this->hintBubbleImageSet = -1;
	this->heldItemImageSet = -1;
	this->heldItemAmount = -1;
	Game::actors = newArray<Ref<Actor>>(6);
	Game::spritePacks = newArray<Ref<SpritePack>>(61);
	this->loadCharMap();
	Game::objectFrameImages = newArray<Arr<Ref<Image>>>(33);
	Game::uiFrameImages = newArray<Arr<Ref<Image>>>(2);
	Game::midlet = midletRef;
	this->sound = jnew<Sound>();
	Game::vibrationEnabled = 1;
	this->setFullScreenMode(1);
	this->requestHudRedraw();
	this->gameThread = jnew<Thread>(this);
	this->gameThread->start();
	return this;
}

void Game::damageExplorer(int32_t damage, int32_t hitKind, int32_t knockbackDir) {
	Ref<Actor> explorerActor;
	int32_t animIndex = 0, dir = 0, col = 0, row = 0;
	this->heldItemImageSet = -1;
	this->pickedItemType = -1;
	this->heldItemAmount = -1;
	explorerActor = Game::actors[(this->explorerStateFlags & 16384) != 0 ? 3 : 0];
	animIndex = explorerActor->animIndex;
	if (animIndex != 40) {
		if (animIndex != 48) {
			if (animIndex != 47) {
				if (this->invulnTimer <= 0LL && this->deathTimer == 0 && this->slideCellsLeft == 0 && this->currentMoveDir != 6 && (this->explorerStateFlags & 112) == 0 || this->encasedStruggleCount > 0) {
					this->hitsTaken = this->hitsTaken + 1;
					this->setExplorerEnergy((int8_t)(this->explorerEnergy - damage));
					if (this->deathLetterboxHeight == 0 && this->explorerEnergy == 0) {
						this->bossQuakeFrame = 0LL;
						this->killerCol = this->updateCellCol;
						this->killerRow = this->updateCellRow;
						Game::killerSprites = nullptr;
					}
					this->explorerStateFlags = this->explorerStateFlags & -113 | hitKind;
					this->playSound(5);
					switch (hitKind) {
						default:
							this->setExplorerAnim(10);
							{
								if (knockbackDir != 0) {
									dir = (int8_t)knockbackDir;
									while (true) {
										col = this->playerCol - Game::dirDeltas[dir];
										row = this->playerRow - Game::dirDeltas[dir + 8];
										if (Game::cellTypes[col][row] >= 0 || (int8_t)(Game::cellObjects[col][row] & 255) >= 0) {
											dir = dir < 4 ? (int8_t)(dir + 1) : 1;
											if (dir != knockbackDir) {
												continue;
											}
											goto B7_end;
										}
										break;
									}
									this->playerCol = col;
									this->playerRow = row;
									this->playerStep = 18;
									this->requestedMoveDir = 0;
									this->explorerStateFlags = this->explorerStateFlags & -8 | dir | 2048;
									return;
								}
							}
							B7_end:;
							return;
						case 64:
							this->setExplorerAnim(1000);
							return;
						case 16:
							this->frozenShakeY = 0;
							this->frozenShakeX = 0;
							this->encasedStruggleCount = 5;
							Game::cellTypes[this->playerCol][this->playerRow] = 9;
							this->explorerStateFlags = this->explorerStateFlags & -113 | 0;
							Game::cellStates[this->playerCol][this->playerRow] = 138412032;
							Game::cellUpdateTimers[this->playerCol][this->playerRow] = 24;
							return;
					}
				}
				return;
			}
			return;
		}
		return;
	}
}

void Game::setExplorerEnergy(int8_t energy) {
	int32_t s1 = 0;
	this->explorerEnergy = energy;
	{
		if (this->explorerEnergy <= 0) {
			s1 = 0;
			this->explorerEnergy = s1;
			goto B1_end;
		}
		if (this->explorerEnergy > Game::saveData[8]) {
			s1 = Game::saveData[8];
			this->explorerEnergy = s1;
		}
	}
	B1_end:;
	this->requestHudRedraw();
}

void Game::openMenu(int32_t menuIdToOpen) {
	this->prevMenuId = this->menuId;
	this->menuItemChosen = 0;
	this->menuCursor = 0;
	this->menuId = menuIdToOpen;
	this->menuTick = 0;
	if (menuIdToOpen >= 0) {
		this->layoutMenuItems();
	}
}

bool Game::isKeyDown(int32_t mask) {
	if ((Game::keys & mask) == 0) {
		return 0;
	}
	return 1;
}

void Game::keyPressed(int32_t keyCode) {
	int32_t mask = 0;
	mask = Game::keyMask(keyCode);
	Game::keys = Game::keys | mask;
	this->isKeyReleased = 0;
}

void Game::keyReleased(int32_t keyCode) {
	Game::keys = Game::keys & (Game::keyMask(keyCode) ^ -1);
	this->isKeyReleased = 1;
}

void Game::resetCounters() {
	this->startTime = JSystem::currentTimeMillis();
	Game::frameCount = 0;
	Game::drawCount = 0;
	this->checkpointTextEndFrame = 0;
}

void Game::sleep(int64_t millis) {
	Ref<Throwable> s0;
	if (millis > 0LL) {
		JSystem::currentTimeMillis();
		try {
			Thread::sleep(millis);
		} catch (JavaException& ex) {
			if (ex.isa(u"java/lang/Exception")) {
				s0 = ex.ex;
				return;
			}
			else throw;
		}
		return;
	}
}

void Game::run() {
	Ref<Throwable> error;
	Ref<Object> s0;
	this->startTime = JSystem::currentTimeMillis();
	this->resetCounters();
	this->loadPreferences();
	while (true) {
		if (this->quit) {
			this->cleanup();
			this->sound->release();
			Game::midlet->exitGame();
			return;
		}
		Thread::yield();
		if (!this->paused) {
			this->frameStart = JSystem::currentTimeMillis();
			try {
				this->update();
			} catch (JavaException& ex) {
				if (ex.isa(u"java/lang/Exception")) {
					s0 = ex.ex;
					error = cast<Throwable>(s0);
					error->printStackTrace();
					Game::sleep(5000LL);
				}
				else throw;
			}
			if (!this->quit) {
				if (Game::screen != 2) {
					Game::frameCount = Game::frameCount + 1;
				}
				this->frameUpdated = JSystem::currentTimeMillis();
				if (this->frameTime <= 65LL) {
					this->paint(this->getGraphics());
					this->flushGraphics();
					this->frameSkipped = 0;
					if (Game::screen != 2) {
						Game::drawCount = Game::drawCount + 1;
					}
					this->frameTime = JMath::abs(JSystem::currentTimeMillis() - this->frameStart);
					Game::sleep(50LL - (JSystem::currentTimeMillis() - this->frameStart));
				} else {
					Game::sleep(100LL - this->frameTime - this->frameUpdated);
					this->frameSkipped = 1;
					this->frameTime = 0LL;
				}
				continue;
			}
			break;
		}
	}
	this->cleanup();
	this->sound->release();
	Game::midlet->exitGame();
}

void Game::update() {
	int32_t step = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	Ref<Object> s0_o;
	this->updatePopupTimer();
	this->dispatchKeyInput();
	switch (Game::screen) {
		case 35:
			t2 = this->loadingStep;
			this->loadingStep = t2 + 1;
			this->runStageCompleteStep(t2);
			this->resetCounters();
			if (this->loadingStep != 12) {
				return;
			}
			Game::screen = 17;
			this->screenSubState = 0;
			this->playSound(15);
			return;
		case 31:
			return;
		case 29:
			this->updateEndingSequence();
			return;
		case 28:
			{
				try {
					this->loadWorldMapStep(this->loadingStep);
					this->loadingStep = this->loadingStep + 1;
					if (this->loadingStep != 11) {
						goto T3_end;
					}
					Game::screen = 27;
					goto T3_end;
					this->resetCounters();
					return;
				} catch (JavaException& ex) {
					if (ex.isa(u"java/lang/Exception")) {
						s0_o = ex.ex;
						this->resetCounters();
						return;
					}
					else throw;
				}
			}
			T3_end:;
			this->resetCounters();
			return;
		case 27:
			this->updateWorldMap();
			return;
		case 22:
			this->updateCredits();
			return;
		case 21:
			t1 = this->loadingStep;
			this->loadingStep = t1 + 1;
			this->loadStageMapStep(t1);
			this->resetCounters();
			return;
		case 20:
			if (Game::frameCount <= 30) {
				return;
			}
			this->fromStageClear = 1;
			this->needLevelCleanup = 1;
			this->needFreeMapRes = 1;
			this->openStageMap();
			return;
		case 17:
			this->advanceStageResults();
			return;
		case 16:
			this->isNewGame = 1;
			this->startLevelLoading();
			Game::keys = 0;
			return;
		case 15:
			this->showPendingUnlockPopup();
			return;
		case 11:
			this->needLevelCleanup = 1;
			this->needFreeMapRes = 1;
			Game::screen = 5;
			this->loadingFullRedraw = 1;
			this->resetCounters();
			return;
		case 9:
			{
				try {
					if ((Game::prefsData[0] & 1) != 0) {
						this->readSaveRecord();
						step = this->loadingStepCount != 8 ? this->loadingStep - 24 : this->loadingStep;
						this->loadMenuResourcesStep(step);
						step++;
						this->loadingStep = this->loadingStep + 1;
						this->menuSaveRecheck = 1;
						if (step != 8) {
							goto T6_end;
						}
						if (!this->titleShown) {
							Game::screen = 30;
							this->titleShown = 1;
							this->sound->play(19);
							goto T6_end;
						}
						Game::screen = 4;
						if (this->menuId != -1) {
							this->screenSubState = 2;
							this->sound->play(19);
							goto T6_end;
						}
						this->screenSubState = 0;
						this->openMenu(0);
						this->sound->play(19);
						goto T6_end;
					}
					this->showMoreGamesBadge = 1;
					this->readSaveRecord();
					step = this->loadingStepCount != 8 ? this->loadingStep - 24 : this->loadingStep;
					this->loadMenuResourcesStep(step);
					step++;
					this->loadingStep = this->loadingStep + 1;
					this->menuSaveRecheck = 1;
					if (step != 8) {
						goto T6_end;
					}
					if (!this->titleShown) {
						Game::screen = 30;
						this->titleShown = 1;
						this->sound->play(19);
						goto T6_end;
					}
					Game::screen = 4;
					if (this->menuId != -1) {
						this->screenSubState = 2;
						this->sound->play(19);
						goto T6_end;
					}
					this->screenSubState = 0;
					this->openMenu(0);
					this->sound->play(19);
					goto T6_end;
					this->resetCounters();
					return;
					this->resetCounters();
					return;
					this->resetCounters();
					return;
					this->resetCounters();
					return;
				} catch (JavaException& ex) {
					if (ex.isa(u"java/lang/Exception")) {
						s0_o = ex.ex;
						this->resetCounters();
						return;
					}
					else throw;
				}
			}
			T6_end:;
			this->resetCounters();
			return;
		case 8:
			t4 = this->loadingStep;
			this->loadingStep = t4 + 1;
			this->loadStartupStep(t4);
			this->resetCounters();
			return;
		case 7:
			if (!this->menuItemChosen) {
				return;
			}
			Game::screen = 8;
			this->loadingStep = 0;
			this->loadingStepCount = 32;
			return;
		default:
			return;
		case 6:
			if (Game::frameCount >= 60) {
				Game::langStrings = Game::loadStringTable(u"/lang.f"_j, 115);
				Game::loadUiFont();
				Game::spritePacks[18] = Game::loadSpritePack(u"/ui.f"_j, 3);
				this->cleanup();
				this->openMenu(3);
				Game::screen = 7;
				return;
			}
			Game::actors[0]->advanceFrame();
			return;
		case 5:
			if (!this->isNewGame || this->loadingStep > 5) {
				this->loadLevelStep();
			} else {
				t3 = this->loadingStep;
				this->loadingStep = t3 + 1;
				this->buildNewSaveStep(t3);
				for (step = 0; step < 3; step++) {
					Game::elementalDiamondPlaced[step] = 0;
				}
				for (step = 1; step < 3; step++) {
					Game::worldUnlockedOnMap[step] = 0;
				}
				this->resetCounters();
				if (this->loadingStep == 5) {
					this->needWriteSave = 1;
					this->needReadSaveStats = 1;
					this->needGarbageCollect = 1;
					this->world = 0;
					this->stage = 13;
					Game::keys = 0;
				}
			}
			this->resetCounters();
			return;
		case 3:
			this->quit = 1;
			return;
		case 2:
		case 12:
			return;
		case 1:
			this->updatePlaying();
			return;
		case 0:
			Game::actors[0] = jnew<Actor>()->init_1(Game::loadSpritePack(u"/ui.f"_j, 0), 0, 0, nullptr);
			Game::actors[0]->setAnimation(0);
			Game::screen = 6;
			this->resetCounters();
			return;
	}
}

void Game::updateMedallionShake() {
	int32_t s1 = 0;
	{
		if (this->medallionShakeY >= this->medallionShakeRangeY) {
			s1 = -1;
			this->medallionShakeDirY = s1;
			goto B1_end;
		}
		if (this->medallionShakeY <= -this->medallionShakeRangeY) {
			s1 = 1;
			this->medallionShakeDirY = s1;
		}
	}
	B1_end:;
	this->medallionShakeY = this->medallionShakeY + this->medallionShakeDirY * this->medallionShakeSpeedY;
	{
		if (this->medallionShakeX >= this->medallionShakeRangeX) {
			s1 = -1;
			this->medallionShakeDirX = s1;
			goto B3_end;
		}
		if (this->medallionShakeY <= -this->medallionShakeRangeX) {
			s1 = 1;
			this->medallionShakeDirX = s1;
		}
	}
	B3_end:;
	this->medallionShakeX = this->medallionShakeX + this->medallionShakeDirX * this->medallionShakeSpeedX;
}

void Game::updateEndingSequence() {
	int32_t s1 = 0;
	switch (this->endingPhase) {
		case 10:
			this->cleanup();
			this->openMenu(0);
			Game::screen = 22;
			this->screenSubState = 0;
			this->sound->stop();
			break;
		case 9:
			this->needsFullRedraw = 1;
			FallingRocks::scroll(3);
			if (JSystem::currentTimeMillis() - this->startTime >= 12000LL) {
				this->endingPhase = this->endingPhase + 1;
				this->resetCounters();
				return;
			}
			break;
		case 8:
			FallingRocks::scroll(3);
			this->needsFullRedraw = 1;
			if (JSystem::currentTimeMillis() - this->startTime >= 15000LL) {
				this->endingPhase = this->endingPhase + 1;
				this->resetCounters();
				return;
			}
			break;
		case 7:
			if (JSystem::currentTimeMillis() - this->startTime >= 1000LL) {
				FallingRocks::rockGrid = multiArray<int8_t, 2>(12, 13);
				this->endingPhase = this->endingPhase + 1;
				FallingRocks::spawnTopRow(3);
				this->sound->play(19);
				this->resetCounters();
				return;
			}
			break;
		case 6:
			if (JSystem::currentTimeMillis() - this->startTime >= 1000LL) {
				this->endingPhase = this->endingPhase + 1;
				this->resetCounters();
				return;
			}
			break;
		case 5:
			if (JSystem::currentTimeMillis() - this->startTime >= 1000LL) {
				this->endingPhase = this->endingPhase + 1;
				return;
			}
			break;
		case 4:
			if (JSystem::currentTimeMillis() - this->startTime >= 1000LL) {
				this->endingPhase = this->endingPhase + 1;
				return;
			}
			break;
		case 3:
			if (JSystem::currentTimeMillis() - this->startTime >= 1000LL) {
				this->endingPhase = this->endingPhase + 1;
				return;
			}
			break;
		case 2:
			this->updateMedallionShake();
			if (JSystem::currentTimeMillis() - this->startTime >= 10000LL) {
				this->medallionShakeX = 0;
				this->medallionShakeY = 0;
				this->resetCounters();
				this->endingPhase = this->endingPhase + 1;
				return;
			}
			break;
		case 1:
			if (Game::frameCount % 6 < 3) {
				s1 = 1;
			} else {
				this->endingFlashColor = this->endingFlashColor + 1677721;
				s1 = 0;
			}
			cast<Game>(this)->needsFullRedraw = s1;
			if (JSystem::currentTimeMillis() - this->startTime >= 5000LL) {
				this->endingPhase = this->endingPhase + 1;
				this->needsFullRedraw = 1;
				this->resetCounters();
				return;
			}
			break;
		case 0:
			if (JSystem::currentTimeMillis() - this->startTime >= 3000LL) {
				this->endingPhase = this->endingPhase + 1;
				this->resetCounters();
				return;
			}
			break;
		default:
			break;
	}
}

void Game::freeWorldMapResources() {
	int32_t count = 0, index = 0;
	this->needFreeMenuRes = 0;
	Game::freeSpritePack(Game::spritePacks[17], 1);
	Game::spritePacks[17] = nullptr;
	count = MoreGames::adImages->length;
	for (index = 0; index < count; index++) {
		MoreGames::adImages[index] = nullptr;
	}
	MoreGames::adImages = nullptr;
	Game::freeSpritePack(Game::spritePacks[10], 1);
	Game::spritePacks[10] = nullptr;
	Game::freeSpritePack(Game::spritePacks[46], 1);
	Game::spritePacks[46] = nullptr;
	Game::freeSpritePack(Game::spritePacks[55], 1);
	Game::spritePacks[55] = nullptr;
	Game::objectFrameImages[8] = nullptr;
	Game::freeSpritePack(Game::spritePacks[59], 1);
	Game::objectFrameImages[3] = nullptr;
	Game::freeSpritePack(Game::spritePacks[17], 1);
	Game::spritePacks[17] = nullptr;
	JSystem::gc();
}

void Game::loadWorldMapStep(int32_t step) {
	Ref<SpritePack> value;
	int32_t value_n = 0, index = 0, s1 = 0, s2 = 0;
	Ref<Object> s0;
	Arr<int8_t> t4, t6;
	switch (step) {
		case 10:
			if (Game::spritePacks[9] == nullptr) {
				Game::spritePacks[9] = Game::loadSpritePack(u"/cm.f"_j, 7);
			}
			this->sparkleFrameCount = Game::getAnimDuration(Game::spritePacks[9], 5);
			value_n = Game::saveData[2];
			for (index = 0; index < 3; index++) {
				if ((value_n & shl(1, index)) != 0) {
					Game::elementalDiamondPlaced[index] = 1;
				}
			}
			this->flyingGemX = 10;
			this->flyingGemY = 10;
			value_n = Game::saveData[1];
			if ((value_n & 1) == 0) {
				index = Game::readU16LE(Game::saveData, 6);
				if (index < Tables::worldUnlockRequirements[1]) {
					s0 = Game::worldUnlockedOnMap;
					s1 = 1;
					s2 = 0;
					cast<Array<bool>>(s0)[s1] = s2;
				} else {
					t4 = Game::saveData;
					t4[1] = (int8_t)(t4[1] | 1);
					this->writeSaveRecord();
					this->worldUnlockAnimIndex = 1;
					this->worldMapNode = 1;
				}
			} else {
				s0 = Game::worldUnlockedOnMap;
				s1 = 1;
				s2 = 1;
				cast<Array<bool>>(s0)[s1] = s2;
			}
			{
				if ((value_n & 2) != 0) {
					s0 = Game::worldUnlockedOnMap;
					s1 = 2;
					s2 = 1;
					cast<Array<bool>>(s0)[s1] = s2;
					goto B7_end;
				}
				index = Game::readU16LE(Game::saveData, 6);
				if (index < Tables::worldUnlockRequirements[2]) {
					s0 = Game::worldUnlockedOnMap;
					s1 = 2;
					s2 = 0;
					cast<Array<bool>>(s0)[s1] = s2;
				} else {
					t6 = Game::saveData;
					t6[1] = (int8_t)(t6[1] | 2);
					this->writeSaveRecord();
					this->worldUnlockAnimIndex = 2;
					this->worldMapNode = 2;
				}
			}
			B7_end:;
			this->worldMapCursorX = Tables::worldMapCursorPositions[this->worldMapNode << 1];
			this->worldMapCursorY = Tables::worldMapCursorPositions[(this->worldMapNode << 1) + 1];
			this->worldMapCursorPrevX = this->worldMapCursorX;
			this->worldMapCursorPrevY = this->worldMapCursorY;
			this->updateWorldMapNodeTexts();
			this->worldMapInfoDirty = 1;
			this->needsFullRedraw = 1;
			return;
		case 9:
			try {
				value = Game::loadSpritePackPalette(jnew<StringBuffer>(u"/"_j)->append(0)->append(u".f"_j)->toString(), 3, 0);
				Game::objectFrameImages[8] = value->moduleImages[0];
				value = Game::loadSpritePackPalette(u"/cm.f"_j, 2, 0);
				value->buildModuleImages(0, 0, -1, -1);
				value->buildModuleImages(1, 0, 0, -1);
				Game::spritePacks[59] = value;
				FallingRocks::rockAnimFrameCount = value->moduleImages[0]->length;
				value->moduleData = nullptr;
				if (Game::spritePacks[17] == nullptr) {
					Game::spritePacks[17] = Game::loadSpritePack(u"/ms.f"_j, 0);
				}
			} catch (JavaException& ex) {
				if (ex.isa(u"java/lang/Exception")) {
					s0 = ex.ex;
					return;
				}
				else throw;
			}
			return;
		case 8:
			if (Game::spritePacks[52] != nullptr) {
				return;
			}
			Game::spritePacks[52] = Game::loadSpritePack(u"/mmv.f"_j, 3);
			return;
		case 7:
			if (Game::spritePacks[53] != nullptr) {
				return;
			}
			Game::spritePacks[53] = Game::loadSpritePack(u"/mmv.f"_j, 2);
			return;
		case 6:
			if (Game::spritePacks[54] == nullptr) {
				Game::spritePacks[54] = Game::loadSpritePack(u"/mmv.f"_j, 1);
			}
			this->gemHalfWidth = Game::getFrameWidth(Game::spritePacks[54], 0) >> 1;
			this->gemHalfHeight = Game::getFrameHeight(Game::spritePacks[54], 0) >> 1;
			return;
		case 5:
			if (Game::spritePacks[55] == nullptr) {
				Game::spritePacks[55] = Game::loadSpritePack(u"/mmv.f"_j, 4);
				this->worldMapCursorFrameCount = Game::getAnimDuration(Game::spritePacks[55], 0);
				Game::curObjectSprites = Game::spritePacks[55];
			}
			if (Game::spritePacks[18] != nullptr) {
				return;
			}
			Game::spritePacks[18] = Game::loadSpritePack(u"/ui.f"_j, 3);
			return;
		case 4:
			this->cleanup();
			MoreGames::adImages = Game::loadSpriteImages(u"/demoui.f"_j, 0);
			if (Game::spritePacks[10] == nullptr) {
				Game::spritePacks[10] = Game::loadSpritePack(u"/mmv.f"_j, 0);
			}
			if (Game::spritePacks[46] == nullptr) {
				Game::spritePacks[46] = Game::loadSpritePack(u"/mmv.f"_j, 5);
			}
			this->medallionX = 240 - Game::getFrameWidth(Game::spritePacks[10], 0) >> 1;
			this->medallionY = 320 - Game::getFrameHeight(Game::spritePacks[10], 0) - 48 >> 1;
			return;
		case 3:
			if (!this->needGarbageCollect) {
				return;
			}
			JSystem::gc();
			this->needGarbageCollect = 0;
			return;
		case 2:
			if (!this->needReadSaveStats) {
				return;
			}
			this->readSaveStats();
			return;
		case 1:
			if (!this->needFreeMapRes) {
				return;
			}
			this->freeStageMapResources();
			return;
		case 0:
			if (!this->needFreeCutscenes) {
				return;
			}
			this->freeLevelCutscenes();
			return;
		default:
			return;
	}
}

void Game::updateWorldMapNodeTexts() {
	int32_t isUnlocked = 0, s2_n = 0;
	Ref<Object> s1, s2;
	if (this->worldMapNode != 3) {
		isUnlocked = Game::isWorldUnlocked(this->worldMapNode);
		if (!isUnlocked) {
			s1 = jnew<StringBuffer>()->append(Tables::worldUnlockRequirements[this->worldMapNode])->append(u" "_j);
			s2 = Game::langStrings[114]->toLowerCase();
		} else {
			s1 = jnew<StringBuffer>();
			s2 = Game::langStrings[82];
		}
	} else {
		s1 = jnew<StringBuffer>();
		s2 = Game::langStrings[82];
	}
	this->worldMapHintText = cast<StringBuffer>(s1)->append(cast<String>(s2))->append(u" "_j)->append(Game::langStrings[79])->toString();
	switch (this->worldMapNode) {
		case 3:
			s1 = Game::langStrings;
			s2_n = 31;
			this->worldMapNodeName = cast<Array<Ref<String>>>(s1)[s2_n];
			break;
		case 2:
			s1 = Game::langStrings;
			s2_n = 30;
			this->worldMapNodeName = cast<Array<Ref<String>>>(s1)[s2_n];
			break;
		case 1:
			s1 = Game::langStrings;
			s2_n = 29;
			this->worldMapNodeName = cast<Array<Ref<String>>>(s1)[s2_n];
			break;
		case 0:
			s1 = Game::langStrings;
			s2_n = 28;
			this->worldMapNodeName = cast<Array<Ref<String>>>(s1)[s2_n];
			break;
		default:
			break;
	}
}

bool Game::isWorldUnlocked(int32_t worldIndex) {
	int32_t totalDiamonds = 0;
	if (worldIndex == 0 || worldIndex == 3) {
		return 1;
	}
	totalDiamonds = Game::readU16LE(Game::saveData, 6);
	if (totalDiamonds < Tables::worldUnlockRequirements[worldIndex]) {
		return 0;
	}
	return 1;
}

void Game::showPendingUnlockPopup() {
	Ref<StringBuffer> message;
	Ref<Object> s0;
	int32_t s1 = 0, s2 = 0, s3 = 0;
	Arr<int8_t> t1, t2, t3;
	if (this->worldUnlockToAnnounce > 0 || this->armorUnlockToAnnounce > 0) {
		message = jnew<StringBuffer>();
		if (this->worldUnlockToAnnounce > 0) {
			message->append(Game::langStrings[92])->append(u"\n"_j);
			switch (this->worldUnlockToAnnounce) {
				case 2:
					message->append(Game::langStrings[30]);
					t2 = Game::saveData;
					t2[2] = (int8_t)(t2[2] | 8);
					t3 = Game::saveData;
					s0 = t3;
					s1 = 2;
					s2 = t3[2];
					s3 = 16;
					cast<Array<int8_t>>(s0)[s1] = (int8_t)(s2 | s3);
					break;
				case 1:
					message->append(Game::langStrings[29]);
					t1 = Game::saveData;
					s0 = t1;
					s1 = 2;
					s2 = t1[2];
					s3 = 8;
					cast<Array<int8_t>>(s0)[s1] = (int8_t)(s2 | s3);
					break;
				default:
					break;
			}
			this->writeSaveRecord();
			this->worldUnlockToAnnounce = 0;
		}
		if (this->armorUnlockToAnnounce > 0) {
			if (message->length() > 0) {
				message->append(u"\n\n"_j);
			}
			message->append(Game::langStrings[99])->append(u"\n"_j)->append(Game::langStrings[85 + this->armorUnlockToAnnounce - 1]);
			this->armorUnlockToAnnounce = 0;
		}
		if (message->length() > 0) {
			this->showPopup(message->toString(), -1, -1, 5000, 4273165, 0);
		}
	}
}

void Game::updateWorldMap() {
	int32_t deltaX = 0, deltaY = 0;
	if (!this->frameSkipped) {
		this->worldMapCursorPrevX = this->worldMapCursorX;
		this->worldMapCursorPrevY = this->worldMapCursorY;
	}
	if (!this->isWorldMapCursorMoving) {
		switch (this->worldMapCommand) {
			default:
				deltaX = Tables::worldMapNeighbors[this->worldMapCommand][this->worldMapNode];
				if (deltaX != -1) {
					this->worldMapNode = deltaX;
					this->isWorldMapCursorMoving = 1;
					this->worldMapCursorTargetX = Tables::worldMapCursorPositions[this->worldMapNode * 2];
					this->worldMapCursorTargetY = Tables::worldMapCursorPositions[this->worldMapNode * 2 + 1];
				}
				break;
			case 4:
				switch (this->worldMapNode) {
					case 3:
						Game::screen = 18;
						break;
					case 2:
						{
							if (!Game::isWorldUnlocked(this->worldMapNode)) {
								goto B6_end;
							}
							this->needFreeMenuRes = 1;
							this->needFreeMapRes = 1;
							this->sound->stop();
							this->world = 2;
							this->stage = 0;
							this->hasWaterLayer = 0;
							Game::screen = 15;
							Game::latestUnlockedStage = this->getSavedLatestStage(this->world);
							this->openStageMap();
							this->hasCompass = 1;
							{
								if (Game::saveData[9] >= 2) {
									goto B7_end;
								}
								Game::saveData[9] = 2;
							}
							B7_end:;
						}
						B6_end:;
						break;
					case 1:
						{
							if (!Game::isWorldUnlocked(this->worldMapNode)) {
								goto B8_end;
							}
							this->needFreeMenuRes = 1;
							this->needFreeMapRes = 1;
							this->sound->stop();
							this->world = 1;
							this->stage = 0;
							Game::screen = 15;
							Game::latestUnlockedStage = this->getSavedLatestStage(this->world);
							this->openStageMap();
							this->hasCompass = 1;
							this->hasWaterLayer = 0;
							{
								if (Game::saveData[9] >= 1) {
									goto B9_end;
								}
								Game::saveData[9] = 1;
							}
							B9_end:;
						}
						B8_end:;
						break;
					default:
						break;
					case 0:
						this->needFreeMenuRes = 1;
						this->needFreeMapRes = 1;
						this->sound->stop();
						this->world = 0;
						this->hasWaterLayer = 0;
						Game::screen = 15;
						Game::latestUnlockedStage = this->getSavedLatestStage(this->world);
						this->openStageMap();
						break;
				}
				break;
			case -1:
				break;
		}
		this->worldMapCommand = -1;
	} else {
		Game::keys = 0;
		deltaX = this->worldMapCursorTargetX - this->worldMapCursorX;
		deltaY = this->worldMapCursorTargetY - this->worldMapCursorY;
		this->worldMapCursorX = this->worldMapCursorX + idiv(deltaX, 8 - this->worldMapCursorStep);
		this->worldMapCursorY = this->worldMapCursorY + idiv(deltaY, 8 - this->worldMapCursorStep);
		this->worldMapCursorStep = (int8_t)(this->worldMapCursorStep + 1);
		if (this->worldMapCursorStep == 8) {
			this->worldMapCursorX = this->worldMapCursorTargetX;
			this->worldMapCursorY = this->worldMapCursorTargetY;
			this->isWorldMapCursorMoving = 0;
			this->worldMapCursorStep = 0;
			this->worldMapInfoDirty = 1;
			this->updateWorldMapNodeTexts();
			return;
		}
	}
}

void Game::loadStartupStep(int32_t step) {
	if (step < 21) {
		if (step == 0) {
			this->sound->open();
		}
		this->sound->load(step);
		if (step == 20) {
			this->sound->close();
		}
		JSystem::gc();
		return;
	}
	switch (step) {
		case 24:
			this->sound->start();
			Game::screen = 9;
			this->openMenu(-1);
			Game::stageLabelPrefix = jnew<StringBuffer>(Game::langStrings[8]);
			Game::stageLabelPrefix->deleteChars(Game::stageLabelPrefix->length() - 1, Game::stageLabelPrefix->length());
			Game::secretStageLabelPrefix = jnew<StringBuffer>(Game::langStrings[20]);
			Game::secretStageLabelPrefix->deleteChars(Game::secretStageLabelPrefix->length() - 1, Game::secretStageLabelPrefix->length());
			Game::scratchText = jnew<StringBuffer>(u"1"_j);
			return;
		default:
			return;
		case 23:
			Game::uiFrameImages[0] = Game::loadSpriteImagesPalette(u"/demoui.f"_j, 0, 0);
			Game::uiFrameImages[1] = Game::loadSpriteImagesPalette(u"/demoui.f"_j, 0, 1);
			return;
		case 22:
			Game::spritePacks[0] = Game::loadSpritePack(u"/ui.f"_j, 2);
			return;
		case 21:
			Game::spritePacks[9] = Game::loadSpritePack(u"/cm.f"_j, 7);
			return;
	}
}

Arr<Ref<String>> Game::loadStringTable(Ref<String> path, int32_t count) {
	Arr<int8_t> bytes;
	int32_t start = 0, length = 0, index = 0;
	Arr<Ref<String>> strings;
	Ref<Throwable> error;
	Ref<Object> s0;
	bytes = Game::readResource(path, 0);
	start = 0;
	length = 0;
	index = 0;
	strings = newArray<Ref<String>>(count);
	while (index < count) {
		if (bytes[start + length] != 0) {
			length++;
		} else {
			try {
				strings[index] = String::fromBytes(bytes, start, length, u"ISO-8859-1"_j);
			} catch (JavaException& ex) {
				if (ex.isa(u"java/lang/Exception")) {
					s0 = ex.ex;
					error = cast<Throwable>(s0);
					error->printStackTrace();
				}
				else throw;
			}
			start = start + (length + 1);
			length = 0;
			index++;
		}
	}
	return strings;
}

void Game::loadLevelStep() {
	int32_t step = 0, subStep_n = 0, item_n = 0, s0_n = 0, s1 = 0, t1 = 0, t2 = 0;
	Ref<String> subStep;
	Ref<SpritePack> item;
	Ref<Object> s0;
	Ref<Game> t3, t4, t5, t6, t7, t8, t9;
	int32_t pc = 0;
	int32_t B = 0;
	for (;;) { try {
		switch (pc) {
		case 0:
			B = 0;
			step = this->loadingStep;
			if (!this->isNewGame) { pc = 15; continue; }
			pc = 12; continue;
		case 12:
			B = 12;
			step -= 5;
			pc = 15; continue;
		case 15:
			B = 15;
			this->loadingStep = this->loadingStep + 1;
			switch (step) {
				case 0: pc = 84; continue;
				case 1: pc = 96; continue;
				case 2: pc = 108; continue;
				case 3: pc = 124; continue;
				case 4: pc = 145; continue;
				case 5: pc = 157; continue;
				case 6: pc = 169; continue;
				case 7: pc = 213; continue;
				case 8: pc = 218; continue;
				case 9: pc = 226; continue;
				case 10: pc = 231; continue;
				default: pc = 304; continue;
			}
		case 84:
			B = 84;
			if (!this->needWriteSave) { pc = 95; continue; }
			pc = 91; continue;
		case 91:
			B = 91;
			this->writeSaveRecord();
			pc = 95; continue;
		case 95:
			B = 95;
			return;
		case 96:
			B = 96;
			if (!this->needReadSaveStats) { pc = 107; continue; }
			pc = 103; continue;
		case 103:
			B = 103;
			this->readSaveStats();
			pc = 107; continue;
		case 107:
			B = 107;
			return;
		case 108:
			B = 108;
			if (!this->needGarbageCollect) { pc = 123; continue; }
			pc = 115; continue;
		case 115:
			B = 115;
			JSystem::gc();
			this->needGarbageCollect = 0;
			pc = 123; continue;
		case 123:
			B = 123;
			return;
		case 124:
			B = 124;
			Game::spritePacks[41]->freeModuleImages(1);
			Game::spritePacks[41]->freeModuleImages(2);
			pc = 144; continue;
		case 144:
			B = 144;
			return;
		case 145:
			B = 145;
			if (!this->needLevelCleanup) { pc = 156; continue; }
			pc = 152; continue;
		case 152:
			B = 152;
			this->cleanup();
			pc = 156; continue;
		case 156:
			B = 156;
			return;
		case 157:
			B = 157;
			if (!this->needFreeMapRes) { pc = 168; continue; }
			pc = 164; continue;
		case 164:
			B = 164;
			this->freeStageMapResources();
			pc = 168; continue;
		case 168:
			B = 168;
			return;
		case 169:
			B = 169;
			t1 = Game::getSavedTipIndex();
			subStep_n = t1;
			if (subStep_n >= 1) { pc = 183; continue; }
			pc = 178; continue;
		case 178:
			B = 178;
			s0 = this;
			s1 = subStep_n;
			pc = 199; continue;
		case 183:
			B = 183;
			if ((this->loadingTipIndex + 9) % 9 >= 1) { pc = 202; continue; }
			pc = 197; continue;
		case 197:
			B = 197;
			s0 = this;
			s1 = 1;
			pc = 199; continue;
		case 199:
			B = 199;
			cast<Game>(s0)->loadingTipIndex = s1;
			pc = 202; continue;
		case 202:
			B = 202;
			Game::loadTipPage(this->loadingTipIndex % 9);
			pc = 212; continue;
		case 212:
			B = 212;
			return;
		case 213:
			B = 213;
			this->loadRedDiamondsInStage();
			pc = 217; continue;
		case 217:
			B = 217;
			return;
		case 218:
			B = 218;
			Game::createLevelBuffer();
			this->loadLevelData();
			pc = 225; continue;
		case 225:
			B = 225;
			return;
		case 226:
			B = 226;
			this->setupLevelCells();
			pc = 230; continue;
		case 230:
			B = 230;
			return;
		case 231:
			B = 231;
			subStep = jnew<StringBuffer>(u"/"_j)->append(this->world)->append(u".f"_j)->toString();
			this->resourceStream = this->getClass()->getResourceAsStream(subStep);
			this->packEntryCount = this->resourceStream->read();
			Game::genFileTable = newArray<int8_t>(this->packEntryCount << 3);
			this->resourceStream->read(Game::genFileTable);
			pc = 303; continue;
		case 303:
			B = 303;
			return;
		case 304:
			B = 304;
			t2 = step - 10 - 1;
			subStep_n = t2;
			if (subStep_n >= 4) { pc = 327; continue; }
			pc = 316; continue;
		case 316:
			B = 316;
			this->loadWorldPackEntry(subStep_n);
			this->nextGenPackIndex = 0;
			pc = 326; continue;
		case 326:
			B = 326;
			return;
		case 327:
			B = 327;
			subStep_n -= 4;
			if (subStep_n < 0) { pc = 346; continue; }
			pc = 334; continue;
		case 334:
			B = 334;
			if (subStep_n >= 43) { pc = 346; continue; }
			pc = 340; continue;
		case 340:
			B = 340;
			this->loadGenPackEntry(subStep_n);
			pc = 345; continue;
		case 345:
			B = 345;
			return;
		case 346:
			B = 346;
			subStep_n -= 43;
			if (subStep_n < 0) { pc = 386; continue; }
			pc = 353; continue;
		case 353:
			B = 353;
			if (subStep_n >= 8) { pc = 386; continue; }
			pc = 359; continue;
		case 359:
			B = 359;
			this->loadCommonPackEntry(subStep_n);
			if (subStep_n != 7) { pc = 385; continue; }
			pc = 370; continue;
		case 370:
			B = 370;
			this->resourceStream->close();
			this->resourceStream = nullptr;
			JSystem::gc();
			pc = 385; continue;
		case 385:
			B = 385;
			return;
		case 386:
			B = 386;
			subStep_n -= 8;
			if (subStep_n < 0) { pc = 492; continue; }
			pc = 393; continue;
		case 393:
			B = 393;
			if (subStep_n >= 16) { pc = 492; continue; }
			pc = 399; continue;
		case 399:
			B = 399;
			if (subStep_n >= Game::levelCutscenes->length) { pc = 433; continue; }
			pc = 407; continue;
		case 407:
			B = 407;
			Game::levelCutscenes[subStep_n] = jnew<Cutscene>()->init(this);
			Game::levelCutscenes[subStep_n]->loadScript(Game::cutsceneTriggerIds[subStep_n]);
			pc = 433; continue;
		case 433:
			B = 433;
			if (subStep_n != 15) { pc = 491; continue; }
			pc = 439; continue;
		case 439:
			B = 439;
			if (Game::levelCutscenes->length < 16) { pc = 491; continue; }
			pc = 448; continue;
		case 448:
			B = 448;
			item_n = 16;
			pc = 451; continue;
		case 451:
			B = 451;
			if (item_n >= Game::levelCutscenes->length) { pc = 491; continue; }
			pc = 459; continue;
		case 459:
			B = 459;
			Game::levelCutscenes[item_n] = jnew<Cutscene>()->init(this);
			Game::levelCutscenes[item_n]->loadScript(Game::cutsceneTriggerIds[item_n]);
			item_n++;
			pc = 451; continue;
		case 491:
			B = 491;
			return;
		case 492:
			B = 492;
			subStep_n -= 16;
			if (subStep_n < 0) { pc = 760; continue; }
			pc = 499; continue;
		case 499:
			B = 499;
			if (subStep_n >= 3) { pc = 760; continue; }
			pc = 504; continue;
		case 504:
			B = 504;
			switch (this->specialStageType) {
				case 1: pc = 544; continue;
				case 3: pc = 567; continue;
				case 4: pc = 625; continue;
				case 5: pc = 690; continue;
				default: pc = 759; continue;
			}
		case 544:
			B = 544;
			this->loadFloodStagePackEntry(subStep_n);
			if (subStep_n != 2) { pc = 566; continue; }
			pc = 554; continue;
		case 554:
			B = 554;
			this->resourceStream->close();
			this->resourceStream = nullptr;
			pc = 566; continue;
		case 566:
			B = 566;
			return;
		case 567:
			B = 567;
			if (subStep_n <= 0) { pc = 572; continue; }
			pc = 571; continue;
		case 571:
			B = 571;
			return;
		case 572:
			B = 572;
			item = Game::loadSpritePackPalette(u"/mmv.f"_j, 1, 0);
			Game::objectFrameImages[31] = item->moduleImages[0];
			Game::actors[5] = jnew<Actor>()->init_1(Game::loadSpritePack(u"/mm1.f"_j, 0), 0, 0, nullptr);
			Game::actors[5]->setAnimation(0);
			pc = 624; continue;
		case 624:
			B = 624;
			return;
		case 625:
			B = 625;
			if (subStep_n < 2) { pc = 631; continue; }
			pc = 630; continue;
		case 630:
			B = 630;
			return;
		case 631:
			B = 631;
			this->loadAnacondaPackEntry(subStep_n);
			item = Game::loadSpritePackPalette(u"/mmv.f"_j, 3, 0);
			Game::objectFrameImages[32] = item->moduleImages[0];
			Game::spritePacks[20] = Game::loadSpritePackPalette(u"/gen0.f"_j, 7, 0);
			if (subStep_n != 1) { pc = 689; continue; }
			pc = 677; continue;
		case 677:
			B = 677;
			this->resourceStream->close();
			this->resourceStream = nullptr;
			pc = 689; continue;
		case 689:
			B = 689;
			return;
		case 690:
			B = 690;
			item = Game::loadSpritePackPalette(u"/mmv.f"_j, 2, 0);
			Game::objectFrameImages[30] = item->moduleImages[0];
			Game::spritePacks[20] = Game::loadSpritePackPalette(u"/gen0.f"_j, 7, 0);
			Game::actors[5] = jnew<Actor>()->init_1(Game::loadSpritePack(u"/b1.f"_j, 0), 0, 0, nullptr);
			Game::actors[5]->setAnimation(10);
			pc = 758; continue;
		case 758:
			B = 758;
			return;
		case 759:
			B = 759;
			return;
		case 760:
			B = 760;
			subStep_n -= 3;
			switch (subStep_n) {
				case 0: pc = 812; continue;
				case 1: pc = 879; continue;
				case 2: pc = 930; continue;
				case 3: pc = 1008; continue;
				case 4: pc = 1015; continue;
				case 5: pc = 1037; continue;
				case 6: pc = 1102; continue;
				case 7: pc = 1119; continue;
				default: pc = 1149; continue;
			}
		case 812:
			B = 812;
			Game::genFileTable = nullptr;
			s0 = this;
			if (Game::spritePacks[12] != nullptr) { pc = 868; continue; }
			pc = 826; continue;
		case 826:
			B = 826;
			t3 = cast<Game>(s0);
			s0 = t3;
			if (Game::objectFrameImages[6] != nullptr) { pc = 868; continue; }
			pc = 835; continue;
		case 835:
			B = 835;
			t4 = cast<Game>(s0);
			s0 = t4;
			if (Game::spritePacks[58] != nullptr) { pc = 868; continue; }
			pc = 844; continue;
		case 844:
			B = 844;
			t5 = cast<Game>(s0);
			s0 = t5;
			if (this->specialStageType == 1) { pc = 868; continue; }
			pc = 852; continue;
		case 852:
			B = 852;
			t6 = cast<Game>(s0);
			s0 = t6;
			if (this->specialStageType == 4) { pc = 868; continue; }
			pc = 860; continue;
		case 860:
			B = 860;
			t7 = cast<Game>(s0);
			s0 = t7;
			if (this->specialStageType != 5) { pc = 872; continue; }
			pc = 868; continue;
		case 868:
			B = 868;
			t8 = cast<Game>(s0);
			s0 = t8;
			s1 = 1;
			pc = 873; continue;
		case 872:
			B = 872;
			t9 = cast<Game>(s0);
			s0 = t9;
			s1 = 0;
			pc = 873; continue;
		case 873:
			B = 873;
			cast<Game>(s0)->loadExplorerSprites(s1);
			pc = 1151; continue;
		case 879:
			B = 879;
			this->levelResourceMask = 0LL;
			this->levelExtraResourceMask = 0LL;
			this->enemyPackFlags = 0;
			this->loadingTipIndex = this->loadingTipIndex + 1;
			if (this->loadingTipIndex >= 3) { pc = 919; continue; }
			pc = 912; continue;
		case 912:
			B = 912;
			s0_n = this->loadingTipIndex;
			pc = 920; continue;
		case 919:
			B = 919;
			s0_n = 3;
			pc = 920; continue;
		case 920:
			B = 920;
			Game::setSavedTipIndex(s0_n);
			this->writeSaveRecord();
			pc = 1151; continue;
		case 930:
			B = 930;
			Game::checkpointCellStates = multiArray<int32_t, 2>(this->levelW, this->levelH);
			Game::checkpointCellMoveOffsets = multiArray<int8_t, 2>(this->levelW, this->levelH);
			Game::checkpointCellTypes = multiArray<int8_t, 2>(this->levelW, this->levelH);
			Game::checkpointCellObjects = multiArray<int32_t, 2>(this->levelW, this->levelH);
			if (Game::gateRemainingCounts == nullptr) { pc = 1149; continue; }
			pc = 996; continue;
		case 996:
			B = 996;
			Game::checkpointGateCounts = newArray<int8_t>(Game::gateRemainingCounts->length);
			pc = 1151; continue;
		case 1008:
			B = 1008;
			this->createLiquidLayer();
			pc = 1151; continue;
		case 1015:
			B = 1015;
			this->deathLetterboxHeight = 0;
			this->effectQueueTail = 0;
			this->effectQueueHead = 0;
			this->saveCheckpoint();
			pc = 1151; continue;
		case 1037:
			B = 1037;
			this->stageIntroEndFrame = Game::frameCount + 60;
			this->diamondsNeededText = jnew<StringBuffer>(Game::langStrings[38])->append(u"\n"_j)->append(this->diamondsToOpenExit)->append(u" "_j)->append(Game::langStrings[39])->toString();
			this->requestHudRedraw();
			pc = 1151; continue;
		case 1102:
			B = 1102;
			Game::freeSpritePack(Game::tipSprites, 1);
			Game::tipSprites = nullptr;
			JSystem::gc();
			pc = 1151; continue;
		case 1119:
			B = 1119;
			this->isNewGame = 0;
			Game::tipPageData = nullptr;
			JSystem::gc();
			this->sound->play(16 + this->world);
			Game::screen = 1;
			pc = 1149; continue;
		case 1149:
			B = 1149;
			return;
		case 1150:
			B = 1150;
			pc = 1151; continue;
		case 1151:
			B = 1151;
			return;
		}
	} catch (JavaException& ex) {
		if (B >= 0 && B < 95 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 96 && B < 107 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 108 && B < 123 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 124 && B < 144 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 145 && B < 156 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 157 && B < 168 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 169 && B < 212 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 213 && B < 217 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 218 && B < 225 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 226 && B < 230 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 231 && B < 303 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 304 && B < 326 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 327 && B < 345 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 346 && B < 385 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 386 && B < 491 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 492 && B < 566 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 567 && B < 571 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 572 && B < 624 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 625 && B < 630 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 631 && B < 689 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 690 && B < 758 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		if (B >= 760 && B < 1149 && ex.isa(u"java/lang/Exception")) { s0 = ex.ex; pc = 1150; continue; }
		throw;
	} }
}

int32_t Game::getArmorPaletteIndex() {
	return Game::saveData[8] - 4;
}

void Game::loadExplorerSprites(bool withAltSprite) {
	Ref<InputStream> stream;
	int32_t entryCount = 0, entrySize = 0;
	Arr<int8_t> fileTable, data;
	Ref<SpritePack> pack;
	Ref<Object> s0;
	try {
		stream = this->getClass()->getResourceAsStream(u"/o.f"_j);
		entryCount = stream->read();
		fileTable = newArray<int8_t>(entryCount << 3);
		stream->read(fileTable);
		entrySize = Game::readS32LE(fileTable, 4);
		data = newArray<int8_t>(entrySize);
		stream->read(data);
		if (withAltSprite == 0) {
			stream->close();
			stream = nullptr;
			JSystem::gc();
		}
		pack = jnew<SpritePack>()->init();
		pack->loadFromBytes(data, 0);
		this->playerPaletteIndex = Game::getArmorPaletteIndex();
		pack->buildModuleImages(this->playerPaletteIndex, 0, -1, -1);
		pack->paletteIndex = this->playerPaletteIndex;
		pack->moduleData = nullptr;
		Game::actors[0] = jnew<Actor>()->init_1(pack, 0, 0, nullptr);
		JSystem::gc();
		if (withAltSprite != 0) {
			entrySize = Game::readS32LE(fileTable, 12);
			data = newArray<int8_t>(entrySize);
			stream->read(data);
			stream->close();
			JSystem::gc();
			pack = jnew<SpritePack>()->init();
			pack->loadFromBytes(data, 0);
			pack->buildModuleImages(0, 0, -1, -1);
			pack->moduleData = nullptr;
			Game::actors[3] = jnew<Actor>()->init_1(pack, 0, 0, nullptr);
			JSystem::gc();
		}
	} catch (JavaException& ex) {
		if (ex.isa(u"java/lang/Exception")) {
			s0 = ex.ex;
			return;
		}
		else throw;
	}
}

int32_t Game::getSelectedMenuAction() {
	return Game::menuDefs[this->menuId][this->menuCursor << 1];
}

void Game::selectMenuItem() {
	Game::spritePacks[41]->paletteIndex = 0;
	this->menuItemChosen = 1;
	switch (this->menuId) {
		case 7:
			this->handleConfirmMenuItem();
			return;
		case 5:
			this->handleOptionsMenuItem();
			return;
		default:
			return;
		case 3:
			this->handleSoundPromptMenuItem();
			return;
		case 2:
			this->handleWorldSelectMenuItem();
			return;
		case 1:
			this->handlePauseMenuItem();
			return;
		case 0:
			this->handleMainMenuItem();
			return;
	}
}

void Game::handleConfirmMenuItem() {
	switch (this->getSelectedMenuAction()) {
		case 1:
			switch (this->screenSubState) {
				case 5:
					Game::screen = 3;
					this->sound->release();
					Game::midlet->notifyDestroyed();
					break;
				case 4:
					this->cleanup();
					Game::screen = 9;
					this->loadingStepCount = 8;
					this->openMenu(-1);
					this->loadingStep = 0;
					break;
				case 3:
					Game::screen = 15;
					this->needLevelCleanup = 1;
					this->needFreeMapRes = 1;
					this->openStageMap();
					break;
				case 1:
					this->startLevelLoading();
					break;
				default:
					break;
			}
			break;
		case 0:
			if (this->prevMenuId == 0) {
				Game::screen = 4;
			}
			this->openMenu(this->prevMenuId);
			break;
		default:
			break;
	}
	this->screenSubState = -1;
}

void Game::handleOptionsMenuItem() {
	int32_t soundLabelId = 0, vibrationLabelId = 0, s0 = 0, s1 = 0, s2 = 0;
	switch (this->getSelectedMenuAction()) {
		case 1:
			Game::vibrationEnabled = !Game::vibrationEnabled ? 1 : 0;
			vibrationLabelId = 51;
			if (Game::vibrationEnabled) {
				vibrationLabelId = 50;
				Game::vibrateDevice(200);
			}
			s0 = 5;
			s1 = 1;
			s2 = vibrationLabelId;
			Game::setMenuItemValue(s0, s1, s2);
			break;
		case 0:
			Sound::enabled = !Sound::enabled ? 1 : 0;
			if (!Sound::enabled) {
				this->sound->stop();
				this->sound->stop();
				soundLabelId = 33;
			} else {
				soundLabelId = 32;
				this->playSound(0);
			}
			s0 = 5;
			s1 = 0;
			s2 = soundLabelId;
			Game::setMenuItemValue(s0, s1, s2);
			break;
		default:
			break;
	}
}

void Game::handlePauseMenuItem() {
	switch (this->getSelectedMenuAction()) {
		default:
			this->menuItemChosen = 0;
			return;
		case 6:
			Game::screen = 33;
			this->needsFullRedraw = 1;
			return;
		case 5:
			this->openMenu(7);
			this->screenSubState = 5;
			return;
		case 4:
			this->openMenu(7);
			this->screenSubState = 4;
			return;
		case 3:
			if (this->stage != 13 || this->world != 0) {
				this->openMenu(7);
				this->screenSubState = 3;
				return;
			}
			return;
		case 2:
			this->openMenu(5);
			return;
		case 1:
			this->openMenu(7);
			this->screenSubState = 1;
			return;
		case 0:
			Game::screen = 1;
			Game::stageMapImage = nullptr;
			Game::moreGamesBadgeBg = nullptr;
			return;
	}
}

void Game::startLevelLoading() {
	int32_t s1 = 0;
	if (!this->isNewGame) {
		s1 = 92;
	} else {
		s1 = 97;
	}
	this->loadingStepCount = s1;
	this->loadingStep = 0;
	this->needLevelCleanup = 1;
	this->isExitingLevel = 0;
	Game::screen = 11;
	this->requestedMoveDir = 0;
	this->currentMoveDir = 0;
	this->explorerStateFlags = 0;
	this->heldItemFrame = -1;
	this->heldItemImageSet = -1;
	this->invulnTimer = 0LL;
}

void Game::handleWorldSelectMenuItem() {
	switch (this->getSelectedMenuAction()) {
		default:
			Game::screen = 3;
			this->sound->release();
			Game::midlet->exitGame();
			return;
		case 3:
			this->openMenu(4);
			return;
		case 2:
			this->sound->stop();
			this->world = 2;
			this->stage = 0;
			this->hasWaterLayer = 0;
			Game::screen = 15;
			Game::latestUnlockedStage = this->getSavedLatestStage(this->world);
			this->needFreeMapRes = 1;
			this->openStageMap();
			this->hasCompass = 1;
			if (Game::saveData[9] < 2) {
				Game::saveData[9] = 2;
			}
			if (Game::saveData[8] >= 8) {
				return;
			}
			Game::saveData[8] = 8;
			return;
		case 1:
			this->sound->stop();
			this->world = 1;
			this->stage = 0;
			Game::screen = 15;
			Game::latestUnlockedStage = this->getSavedLatestStage(this->world);
			this->needFreeMapRes = 1;
			this->openStageMap();
			this->hasCompass = 1;
			this->hasWaterLayer = 0;
			if (Game::saveData[9] >= 1) {
				return;
			}
			Game::saveData[9] = 1;
			return;
		case 0:
			this->sound->stop();
			this->world = 0;
			this->hasWaterLayer = 0;
			Game::screen = 15;
			Game::latestUnlockedStage = this->getSavedLatestStage(this->world);
			this->needFreeMapRes = 1;
			this->openStageMap();
			return;
	}
}

void Game::handleSoundPromptMenuItem() {
	int32_t soundLabelId = 0, s0 = 0;
	soundLabelId = 0;
	switch (this->getSelectedMenuAction()) {
		case 1:
			Sound::enabled = 0;
			s0 = 33;
			soundLabelId = s0;
			break;
		case 0:
			Sound::enabled = 1;
			s0 = 32;
			soundLabelId = s0;
			break;
		default:
			break;
	}
	this->screenSubState = 0;
	Game::setMenuItemValue(5, 0, soundLabelId);
}

void Game::handleMainMenuItem() {
	switch (this->getSelectedMenuAction()) {
		default:
			this->menuItemChosen = 0;
			return;
		case 6:
			this->menuItemChosen = 0;
			return;
		case 5:
			this->openMenu(7);
			this->screenSubState = 5;
			return;
		case 4:
			Game::screen = 22;
			this->screenSubState = 0;
			this->sound->stop();
			return;
		case 3:
			Game::screen = 33;
			this->sound->stop();
			this->needsFullRedraw = 1;
			return;
		case 2:
			this->openMenu(5);
			this->sound->stop();
			return;
		case 1:
			this->sound->stop();
			this->readSaveRecord();
			if (Game::saveData == nullptr || !Game::readHasSavedGame()) {
				this->sound->stop();
				if (Game::readHasSavedGame()) {
					this->newGamePromptDirty = 1;
					this->isNewGame = 0;
					Game::screen = 31;
					return;
				}
				this->startNewGame();
				return;
			}
			this->loadingTipIndex = 0;
			this->needReadSaveStats = 1;
			this->hasCompass = 1;
			this->loadingStep = 0;
			Game::screen = 28;
			return;
		case 0:
			this->sound->stop();
			if (Game::readHasSavedGame()) {
				this->newGamePromptDirty = 1;
				this->isNewGame = 0;
				Game::screen = 31;
				return;
			}
			this->startNewGame();
			return;
	}
}

void Game::moveMenuCursorUp() {
	this->menuCursor = this->menuCursor - 1;
	if (this->menuCursor < 0) {
		this->menuCursor = (Game::menuDefs[this->menuId]->length >> 1) - 1;
	}
}

void Game::moveMenuCursorDown() {
	this->menuCursor = irem(this->menuCursor + 1, Game::menuDefs[this->menuId]->length >> 1);
}

void Game::freeLevelCutscenes() {
	int32_t count = 0, index = 0;
	this->needFreeCutscenes = 0;
	if (Game::levelCutscenes != nullptr) {
		count = Game::levelCutscenes->length;
		for (index = 0; index < count; index++) {
			Game::freeCutscene(Game::levelCutscenes[index]);
			Game::levelCutscenes[index] = nullptr;
		}
	}
	Game::levelCutscenes = nullptr;
	Game::freeSpritePack(Game::spritePacks[42], 1);
	Game::freeSpritePack(Game::spritePacks[43], 1);
	JSystem::gc();
}

void Game::freeCutscene(Ref<Cutscene> cutscene) {
	int32_t index = 0;
	if (cutscene != nullptr) {
		if (Cutscene::sprites != nullptr) {
			for (index = 0; index < Cutscene::sprites->length; index++) {
				Game::freeSpritePack(Cutscene::sprites[index], 1);
				Cutscene::sprites[index] = nullptr;
			}
		}
		if (cutscene->steps != nullptr) {
			for (index = 0; index < cutscene->steps->length; index++) {
				cutscene->steps[index] = nullptr;
			}
			cutscene->steps = nullptr;
		}
		cutscene->currentStep = nullptr;
		return;
	}
}

void Game::freeSpritePack(Ref<SpritePack> pack, bool freeImages) {
	if (pack != nullptr) {
		pack->unload(freeImages);
		return;
	}
}

void Game::cleanup() {
	int32_t index = 0, count = 0, frame = 0;
	this->needLevelCleanup = 0;
	this->hudNeedsRedraw = 1;
	this->respawnPanActive = 0;
	this->hintTimer = 0;
	this->hintText = nullptr;
	Game::gateRemainingCounts = nullptr;
	Game::gateObjectiveMsgs = nullptr;
	this->redDiamondPickCount = 0;
	this->checkpointRedDiamondPickCount = 0;
	Game::redDiamondPickCells = nullptr;
	Game::freezeRays = nullptr;
	this->resourceStream = nullptr;
	Game::genFileTable = nullptr;
	Game::stageMapImage = nullptr;
	Game::stageMapGraphics = nullptr;
	Game::levelBufferGraphics = nullptr;
	Game::levelBufferImage = nullptr;
	Game::cutsceneTriggerIds = nullptr;
	Game::compassTargets = nullptr;
	if (Game::levelCutscenes != nullptr) {
		index = Game::levelCutscenes->length;
		for (count = 0; count < index; count++) {
			Game::freeCutscene(Game::levelCutscenes[count]);
			Game::levelCutscenes[count] = nullptr;
		}
	}
	Game::levelCutscenes = nullptr;
	if (this->activeCutscene != nullptr) {
		Game::freeCutscene(this->activeCutscene);
		this->activeCutscene = nullptr;
	}
	if (Game::objectFrameImages != nullptr) {
		for (index = 0; index < 33; index++) {
			if (Game::objectFrameImages[index] != nullptr) {
				count = Game::objectFrameImages[index]->length;
				for (frame = 0; frame < count; frame++) {
					Game::objectFrameImages[index][frame] = nullptr;
				}
				Game::objectFrameImages[index] = nullptr;
			}
		}
	}
	Game::freeSpritePack(Game::liquidSprites, 1);
	JSystem::gc();
	if (Game::spritePacks != nullptr) {
		for (index = 0; index < 61; index++) {
			if (index != 41 && index != 0 && index != 9 && index != 18) {
				Game::freeSpritePack(Game::spritePacks[index], 1);
				Game::spritePacks[index] = nullptr;
			}
		}
	}
	if (Game::actors != nullptr) {
		for (index = 0; index < 6; index++) {
			if (Game::actors[index] != nullptr) {
				Game::freeSpritePack(Game::actors[index]->sprite, 1);
				Game::actors[index]->sprite = nullptr;
				Game::actors[index] = nullptr;
			}
		}
	}
	Game::cellStates = nullptr;
	Game::cellObjects = nullptr;
	Game::cellMoveOffsets = nullptr;
	Game::cellTypes = nullptr;
	Game::cellUpdateTimers = nullptr;
	Game::checkpointCellStates = nullptr;
	Game::checkpointCellObjects = nullptr;
	Game::checkpointCellMoveOffsets = nullptr;
	Game::checkpointCellTypes = nullptr;
	Game::checkpointGateCounts = nullptr;
	this->levelResourceMask = 0LL;
	this->enemyPackFlags = 0;
	this->hintBubbleImageSet = -1;
	this->heldItemImageSet = -1;
	this->heldItemAmount = -1;
	this->pickedItemType = -1;
	Game::curObjectSprites = nullptr;
	this->cellAnimIndex = -1;
	this->diamondsNeededText = nullptr;
	this->liquidState = 3;
	Game::liquidCells = nullptr;
	Game::savedLiquidCells = nullptr;
	Game::liquidFlows = nullptr;
	Game::savedLiquidFlows = nullptr;
	Game::liquidEmitters = nullptr;
	Game::savedLiquidEmitters = nullptr;
	this->liquidStartNextEmitter = 0;
	this->liquidDrainTick = -1;
	this->liquidPoolRiseCount = 0;
	this->liquidSpareCounter = 0;
	this->liquidFillTargetSlot = 0;
	this->liquidBreachCol = 0;
	this->liquidBreachRow = 0;
	this->liquidBreachDir = 0;
	this->liquidDrainFlow = 0;
	this->liquidDrainStopRow = 0;
	this->liquidFlowTick = -1;
	this->hasWaterLayer = 0;
	Game::freezeRays = nullptr;
	Game::freeTitleImages();
	JSystem::gc();
}

void Game::requestHudRedraw() {
	this->hudNeedsRedraw = 1;
}

void Game::loadWorldPackEntry(int32_t entryIndex) {
	int32_t entrySize = 0, s1 = 0;
	Arr<int8_t> data;
	Ref<SpritePack> pack;
	Ref<Object> s0, s2;
	entrySize = Game::readS32LE(Game::genFileTable, entryIndex * 8 + 4);
	data = newArray<int8_t>(entrySize);
	this->resourceStream->read(data);
	pack = jnew<SpritePack>()->init();
	pack->loadFromBytes(data, 0);
	pack->buildModuleImages(0, 0, -1, -1);
	switch (entryIndex) {
		case 3:
			s0 = Game::objectFrameImages;
			s1 = 8;
			s2 = pack->moduleImages[0];
			cast<Array<Ref<Object>>>(s0)[s1] = s2;
			break;
		case 2:
			Game::objectFrameImages[0] = nullptr;
			s0 = Game::spritePacks;
			s1 = 42;
			s2 = pack;
			cast<Array<Ref<Object>>>(s0)[s1] = s2;
			break;
		case 1:
			{
				if ((this->levelExtraResourceMask & 2LL) != 0LL) {
					s0 = Game::spritePacks;
					s1 = 16;
					s2 = pack;
					cast<Array<Ref<Object>>>(s0)[s1] = s2;
					goto B2_end;
				}
			}
			B2_end:;
			break;
		case 0:
			{
				if ((this->levelExtraResourceMask & 1LL) != 0LL) {
					s0 = Game::spritePacks;
					s1 = 60;
					s2 = pack;
					cast<Array<Ref<Object>>>(s0)[s1] = s2;
					goto B3_end;
				}
			}
			B3_end:;
			break;
		default:
			break;
	}
	pack->moduleData = nullptr;
}

void Game::loadCommonPackEntry(int32_t entryIndex) {
	int32_t entrySize = 0, s1 = 0;
	Arr<int8_t> data;
	Ref<SpritePack> pack;
	Ref<Object> s0, s2;
	Arr<Arr<Ref<Image>>> t3;
	try {
		if (entryIndex == 0) {
			this->resourceStream->close();
			this->resourceStream = nullptr;
			JSystem::gc();
			this->resourceStream = this->getClass()->getResourceAsStream(u"/cm.f"_j);
			this->packEntryCount = this->resourceStream->read();
			Game::genFileTable = newArray<int8_t>(this->packEntryCount << 3);
			this->resourceStream->read(Game::genFileTable);
		}
		entrySize = Game::readS32LE(Game::genFileTable, entryIndex * 8 + 4);
		data = newArray<int8_t>(entrySize);
		this->resourceStream->read(data);
		pack = jnew<SpritePack>()->init();
		pack->loadFromBytes(data, 0);
		pack->buildModuleImages(0, 0, -1, -1);
		switch (entryIndex) {
			case 6:
				Game::spritePacks[43] = pack;
				s0 = Game::objectFrameImages;
				s1 = 20;
				s2 = nullptr;
				cast<Array<Ref<Object>>>(s0)[s1] = s2;
				break;
			case 5:
				s0 = Game::objectFrameImages;
				s1 = 18;
				t3 = cast<Array<Arr<Ref<Image>>>>(s0);
				s0 = t3;
				s2 = pack->moduleImages[0];
				cast<Array<Ref<Object>>>(s0)[s1] = s2;
				break;
			case 4:
				s0 = Game::objectFrameImages;
				s1 = 5;
				t3 = cast<Array<Arr<Ref<Image>>>>(s0);
				s0 = t3;
				s2 = pack->moduleImages[0];
				cast<Array<Ref<Object>>>(s0)[s1] = s2;
				break;
			case 3:
				Game::spritePacks[13] = pack;
				this->freeUnusedCommonPack13Frames();
				break;
			case 2:
				pack->buildModuleImages(1, 0, 0, -1);
				s0 = Game::spritePacks;
				s1 = 59;
				s2 = pack;
				cast<Array<Ref<Object>>>(s0)[s1] = s2;
				break;
			case 1:
				switch (this->world) {
					case 1:
					case 2:
						if (this->world != 0) {
							pack->buildModuleImages(this->world, 0, -1, -1);
							pack->freeModuleImages(0);
							pack->paletteIndex = this->world;
						}
						break;
					default:
						break;
				}
				s0 = Game::spritePacks;
				s1 = 56;
				s2 = pack;
				cast<Array<Ref<Object>>>(s0)[s1] = s2;
				break;
			case 0:
				s0 = Game::objectFrameImages;
				s1 = 11;
				t3 = cast<Array<Arr<Ref<Image>>>>(s0);
				s0 = t3;
				s2 = pack->moduleImages[0];
				cast<Array<Ref<Object>>>(s0)[s1] = s2;
				break;
			default:
				break;
		}
		pack->moduleData = nullptr;
	} catch (JavaException& ex) {
		if (ex.isa(u"java/lang/Exception")) {
			s0 = ex.ex;
			return;
		}
		else throw;
	}
}

void Game::freeUnusedCommonPack13Frames() {
	int32_t frame = 0;
	if ((this->levelExtraResourceMask & 1LL) == 0LL) {
		for (frame = 0; frame < 5; frame++) {
			Game::spritePacks[13]->moduleImages[0][frame] = nullptr;
		}
	}
}

void Game::loadGenPackEntry(int32_t entryIndex) {
	Ref<StringBuffer> localIndex;
	int32_t localIndex_n = 0, entrySize = 0, spritePackSlot = 0, frameImageSlot = 0, s0 = 0;
	Arr<int8_t> data;
	Ref<SpritePack> pack, t1;
	Ref<Object> s0_o;
	int32_t pc = 0;
	int32_t B = 0;
	for (;;) { try {
		switch (pc) {
		case 0:
			B = 0;
			if (entryIndex % 10 != 0) { pc = 106; continue; }
			pc = 7; continue;
		case 7:
			B = 7;
			this->resourceStream->close();
			this->resourceStream = nullptr;
			localIndex = jnew<StringBuffer>(u"/gen"_j)->append(this->nextGenPackIndex)->append(u".f"_j);
			this->resourceStream = this->getClass()->getResourceAsStream(localIndex->toString());
			this->packEntryCount = this->resourceStream->read();
			Game::genFileTable = newArray<int8_t>(this->packEntryCount << 3);
			this->resourceStream->read(Game::genFileTable);
			this->packSkipBytes = 0;
			this->nextGenPackIndex = this->nextGenPackIndex + 1;
			pc = 106; continue;
		case 106:
			B = 106;
			localIndex_n = entryIndex - (this->nextGenPackIndex - 1) * 10;
			entrySize = Game::readS32LE(Game::genFileTable, localIndex_n * 8 + 4);
			if ((this->levelResourceMask & lshl(1LL, entryIndex)) == 0LL) { pc = 984; continue; }
			pc = 144; continue;
		case 144:
			B = 144;
			if (this->packSkipBytes == 0) { pc = 169; continue; }
			pc = 151; continue;
		case 151:
			B = 151;
			this->resourceStream->skip((int64_t)this->packSkipBytes);
			this->packSkipBytes = 0;
			pc = 169; continue;
		case 169:
			B = 169;
			data = newArray<int8_t>(entrySize);
			this->resourceStream->read(data);
			t1 = jnew<SpritePack>()->init();
			pack = t1;
			pack->loadFromBytes(data, 0);
			if (entryIndex != 28) { pc = 213; continue; }
			pc = 206; continue;
		case 206:
			B = 206;
			if (!this->levelHasLockType9) { pc = 235; continue; }
			pc = 213; continue;
		case 213:
			B = 213;
			if (entryIndex != 24) { pc = 226; continue; }
			pc = 219; continue;
		case 219:
			B = 219;
			if (!this->levelHasBlock35) { pc = 235; continue; }
			pc = 226; continue;
		case 226:
			B = 226;
			pack->buildModuleImages(0, 0, -1, -1);
			pc = 235; continue;
		case 235:
			B = 235;
			spritePackSlot = -1;
			frameImageSlot = -1;
			switch (entryIndex) {
				case 0: pc = 442; continue;
				case 1: pc = 456; continue;
				case 2: pc = 565; continue;
				case 3: pc = 647; continue;
				case 4: case 21: pc = 709; continue;
				case 5: pc = 640; continue;
				case 6: pc = 617; continue;
				case 7: pc = 726; continue;
				case 8: pc = 661; continue;
				case 9: pc = 799; continue;
				case 10: pc = 770; continue;
				case 11: pc = 926; continue;
				case 12: pc = 938; continue;
				case 13: pc = 920; continue;
				case 14: pc = 765; continue;
				case 15: case 17: pc = 806; continue;
				case 16: case 18: pc = 470; continue;
				case 19: pc = 933; continue;
				case 20: pc = 704; continue;
				case 22: pc = 697; continue;
				case 23: pc = 490; continue;
				case 24: pc = 667; continue;
				case 25: pc = 635; continue;
				case 26: pc = 627; continue;
				case 27: pc = 622; continue;
				case 28: pc = 537; continue;
				case 29: pc = 560; continue;
				case 30: pc = 530; continue;
				case 31: pc = 525; continue;
				case 32: pc = 483; continue;
				case 33: pc = 518; continue;
				case 34: pc = 511; continue;
				case 35: pc = 504; continue;
				case 36: pc = 449; continue;
				case 37: pc = 497; continue;
				case 38: pc = 463; continue;
				case 39: pc = 654; continue;
				case 40: pc = 477; continue;
				case 41: pc = 428; continue;
				case 42: pc = 435; continue;
				default: pc = 942; continue;
			}
		case 428:
			B = 428;
			spritePackSlot = 38;
			pc = 942; continue;
		case 435:
			B = 435;
			spritePackSlot = 39;
			pc = 942; continue;
		case 442:
			B = 442;
			spritePackSlot = 33;
			pc = 942; continue;
		case 449:
			B = 449;
			spritePackSlot = 35;
			pc = 942; continue;
		case 456:
			B = 456;
			spritePackSlot = 34;
			pc = 942; continue;
		case 463:
			B = 463;
			spritePackSlot = 36;
			pc = 942; continue;
		case 470:
			B = 470;
			spritePackSlot = 37;
			pc = 942; continue;
		case 477:
			B = 477;
			spritePackSlot = 2;
			pc = 942; continue;
		case 483:
			B = 483;
			spritePackSlot = 32;
			pc = 942; continue;
		case 490:
			B = 490;
			spritePackSlot = 30;
			pc = 942; continue;
		case 497:
			B = 497;
			spritePackSlot = 29;
			pc = 942; continue;
		case 504:
			B = 504;
			spritePackSlot = 28;
			pc = 942; continue;
		case 511:
			B = 511;
			spritePackSlot = 27;
			pc = 942; continue;
		case 518:
			B = 518;
			spritePackSlot = 22;
			pc = 942; continue;
		case 525:
			B = 525;
			s0 = 29;
			pc = 940; continue;
		case 530:
			B = 530;
			spritePackSlot = 15;
			pc = 942; continue;
		case 537:
			B = 537;
			if (!this->levelHasLockType8) { pc = 553; continue; }
			pc = 544; continue;
		case 544:
			B = 544;
			pack->buildModuleImages(1, 0, -1, -1);
			pc = 553; continue;
		case 553:
			B = 553;
			spritePackSlot = 45;
			pc = 942; continue;
		case 560:
			B = 560;
			s0 = 26;
			pc = 940; continue;
		case 565:
			B = 565;
			if (!this->levelHasLockType9) { pc = 585; continue; }
			pc = 572; continue;
		case 572:
			B = 572;
			Game::objectFrameImages[24] = pack->moduleImages[0];
			pc = 585; continue;
		case 585:
			B = 585;
			if (!this->levelHasLockType8) { pc = 942; continue; }
			pc = 592; continue;
		case 592:
			B = 592;
			pack->buildModuleImages(1, 0, -1, -1);
			Game::objectFrameImages[25] = pack->moduleImages[1];
			pc = 942; continue;
		case 617:
			B = 617;
			s0 = 21;
			pc = 940; continue;
		case 622:
			B = 622;
			s0 = 19;
			pc = 940; continue;
		case 627:
			B = 627;
			Game::liquidSprites = pack;
			pc = 942; continue;
		case 635:
			B = 635;
			s0 = 17;
			pc = 940; continue;
		case 640:
			B = 640;
			spritePackSlot = 58;
			pc = 942; continue;
		case 647:
			B = 647;
			spritePackSlot = 7;
			pc = 942; continue;
		case 654:
			B = 654;
			spritePackSlot = 6;
			pc = 942; continue;
		case 661:
			B = 661;
			spritePackSlot = 5;
			pc = 942; continue;
		case 667:
			B = 667;
			Game::objectFrameImages[15] = nullptr;
			pack->buildModuleImages(1, 0, -1, -1);
			spritePackSlot = 57;
			Game::objectFrameImages[14] = nullptr;
			pc = 942; continue;
		case 697:
			B = 697;
			spritePackSlot = 8;
			pc = 942; continue;
		case 704:
			B = 704;
			s0 = 13;
			pc = 940; continue;
		case 709:
			B = 709;
			if (this->world != 2) { pc = 720; continue; }
			pc = 717; continue;
		case 717:
			B = 717;
			pc = 942; continue;
		case 720:
			B = 720;
			spritePackSlot = 3;
			pc = 942; continue;
		case 726:
			B = 726;
			if (this->world != 2) { pc = 758; continue; }
			pc = 734; continue;
		case 734:
			B = 734;
			pack->moduleImages = nullptr;
			pack->buildModuleImages(1, 0, -1, -1);
			pack->paletteIndex = 1;
			pc = 758; continue;
		case 758:
			B = 758;
			spritePackSlot = 20;
			pc = 942; continue;
		case 765:
			B = 765;
			s0 = 6;
			pc = 940; continue;
		case 770:
			B = 770;
			Game::actors[4] = jnew<Actor>()->init_1(pack, 0, 0, nullptr);
			Game::actors[4]->setAnimation(0);
			pc = 942; continue;
		case 799:
			B = 799;
			spritePackSlot = 12;
			pc = 942; continue;
		case 806:
			B = 806;
			if ((this->enemyPackFlags & 2) == 0) { pc = 850; continue; }
			pc = 815; continue;
		case 815:
			B = 815;
			if (this->world != 2) { pc = 847; continue; }
			pc = 823; continue;
		case 823:
			B = 823;
			pack->moduleImages = nullptr;
			pack->buildModuleImages(2, 0, -1, -1);
			pack->paletteIndex = 2;
			pc = 847; continue;
		case 847:
			B = 847;
			spritePackSlot = 4;
			pc = 850; continue;
		case 850:
			B = 850;
			if ((this->enemyPackFlags & 1) == 0) { pc = 942; continue; }
			pc = 859; continue;
		case 859:
			B = 859;
			Game::spritePacks[21] = jnew<SpritePack>()->init();
			Game::spritePacks[21]->loadFromBytes(data, 0);
			Game::spritePacks[21]->buildModuleImages(1, 0, -1, -1);
			Game::spritePacks[21]->paletteIndex = 1;
			Game::spritePacks[21]->moduleData = nullptr;
			pc = 942; continue;
		case 920:
			B = 920;
			spritePackSlot = 1;
			pc = 942; continue;
		case 926:
			B = 926;
			spritePackSlot = 11;
			pc = 942; continue;
		case 933:
			B = 933;
			s0 = 7;
			pc = 940; continue;
		case 938:
			B = 938;
			s0 = 10;
			pc = 940; continue;
		case 940:
			B = 940;
			frameImageSlot = s0;
			pc = 942; continue;
		case 942:
			B = 942;
			if (spritePackSlot == -1) { pc = 956; continue; }
			pc = 948; continue;
		case 948:
			B = 948;
			Game::spritePacks[spritePackSlot] = pack;
			pc = 956; continue;
		case 956:
			B = 956;
			if (frameImageSlot == -1) { pc = 975; continue; }
			pc = 962; continue;
		case 962:
			B = 962;
			Game::objectFrameImages[frameImageSlot] = pack->moduleImages[0];
			pc = 975; continue;
		case 975:
			B = 975;
			pack->moduleData = nullptr;
			pc = 996; continue;
		case 984:
			B = 984;
			this->packSkipBytes = this->packSkipBytes + entrySize;
			pc = 994; continue;
		case 994:
			B = 994;
			return;
		case 995:
			B = 995;
			pc = 996; continue;
		case 996:
			B = 996;
			return;
		}
	} catch (JavaException& ex) {
		if (B >= 0 && B < 994 && ex.isa(u"java/io/IOException")) { s0_o = ex.ex; pc = 995; continue; }
		throw;
	} }
}

void Game::loadAnacondaPackEntry(int32_t entryIndex) {
	int32_t entrySize = 0;
	Arr<int8_t> entryBytes;
	Ref<SpritePack> pack;
	Ref<Object> s0;
	{
		try {
			if (entryIndex == 0) {
				this->resourceStream = this->getClass()->getResourceAsStream(u"/b0.f"_j);
				this->packEntryCount = this->resourceStream->read();
				Game::genFileTable = newArray<int8_t>(this->packEntryCount * 8);
				this->resourceStream->read(Game::genFileTable);
			}
			entrySize = Game::readS32LE(Game::genFileTable, entryIndex * 8 + 4);
			entryBytes = newArray<int8_t>(entrySize);
			this->resourceStream->read(entryBytes);
			pack = jnew<SpritePack>()->init();
			pack->loadFromBytes(entryBytes, 0);
			pack->buildModuleImages(0, 0, -1, -1);
			pack->moduleData = nullptr;
			switch (entryIndex) {
				case 1:
					Game::spritePacks[40] = pack;
					goto T1_end;
				default:
					return;
				case 0:
					Game::actors[5] = jnew<Actor>()->init_1(pack, 0, 0, nullptr);
					return;
			}
		} catch (JavaException& ex) {
			if (ex.isa(u"java/lang/Exception")) {
				s0 = ex.ex;
				return;
			}
			else throw;
		}
	}
	T1_end:;
}

void Game::loadFloodStagePackEntry(int32_t entryIndex) {
	int32_t entrySize = 0;
	Arr<int8_t> entryBytes;
	Ref<SpritePack> pack;
	Ref<Object> s0;
	{
		try {
			if (entryIndex == 0) {
				this->resourceStream = this->getClass()->getResourceAsStream(u"/mm0.f"_j);
				this->packEntryCount = this->resourceStream->read();
				Game::genFileTable = newArray<int8_t>(this->packEntryCount * 8);
				this->resourceStream->read(Game::genFileTable);
			}
			entrySize = Game::readS32LE(Game::genFileTable, entryIndex * 8 + 4);
			entryBytes = newArray<int8_t>(entrySize);
			this->resourceStream->read(entryBytes);
			pack = jnew<SpritePack>()->init();
			pack->loadFromBytes(entryBytes, 0);
			pack->buildModuleImages(0, 0, -1, -1);
			pack->moduleData = nullptr;
			switch (entryIndex) {
				case 2:
					Game::objectFrameImages[27] = pack->moduleImages[0];
					goto T1_end;
				case 1:
					Game::actors[2] = jnew<Actor>()->init_1(pack, 0, 0, nullptr);
					Game::actors[2]->setAnimation(0);
					goto T1_end;
				case 0:
					Game::actors[1] = jnew<Actor>()->init_1(pack, 0, 0, nullptr);
					Game::actors[1]->setAnimation(2);
					return;
				default:
					return;
			}
		} catch (JavaException& ex) {
			if (ex.isa(u"java/lang/Exception")) {
				s0 = ex.ex;
			}
			else throw;
		}
	}
	T1_end:;
}

int32_t Game::getSavedTipIndex() {
	int32_t tipIndex = 0;
	tipIndex = Game::saveData[12];
	return tipIndex;
}

void Game::setSavedTipIndex(int32_t tipIndex) {
	Game::saveData[12] = (int8_t)tipIndex;
}

bool Game::readHasSavedGame() {
	if (Game::saveData != nullptr) {
		if (Game::saveData[13] != 0) {
			return 1;
		}
		return 0;
	}
	return 0;
}

void Game::setHasSavedGameAndSave(bool hasSave) {
	Game::saveData[13] = hasSave != 0 ? 1 : 0;
	this->writeSaveRecord();
}

void Game::loadRedDiamondsInStage() {
	this->redDiamondsInStage = this->getStageRedDiamondTotal(this->world, this->stage);
}

void Game::saveStageResult() {
	this->needSaveStageResult = 0;
	this->writeLivesToSave();
	this->raiseSavedLatestStage(this->world, Game::latestUnlockedStage);
	this->setStageBankedRedDiamonds(this->world, this->stage, this->redDiamondCount + this->getStageBankedRedDiamonds(this->world, this->stage));
	this->writeSaveRecord();
}

void Game::readSaveRecord() {
	Ref<RecordStore> store;
	Ref<Object> s0;
	try {
		store = RecordStore::openRecordStore(u"DiamondRush"_j, 1);
		Game::saveData = store->getRecord(1);
		this->saveDataSize = Game::saveData->length;
		store->closeRecordStore();
	} catch (JavaException& ex) {
		if (ex.isa(u"java/lang/Exception")) {
			s0 = ex.ex;
			return;
		}
		else throw;
	}
}

void Game::writeSaveRecord() {
	Ref<RecordStore> store;
	Ref<Object> s0;
	this->needWriteSave = 0;
	try {
		store = RecordStore::openRecordStore(u"DiamondRush"_j, 1);
		if (store->getNumRecords() != 0) {
			store->setRecord(1, Game::saveData, 0, this->saveDataSize);
		} else {
			store->addRecord(Game::saveData, 0, this->saveDataSize);
		}
		store->closeRecordStore();
	} catch (JavaException& ex) {
		if (ex.isa(u"java/lang/Exception")) {
			s0 = ex.ex;
			return;
		}
		else throw;
	}
}

void Game::loadPreferences() {
	Ref<RecordStore> store;
	Ref<Object> s0;
	store = nullptr;
	try {
		store = RecordStore::openRecordStore(u"Preferences"_j, 0);
	} catch (JavaException& ex) {
		if (ex.isa(u"java/lang/Exception")) {
			s0 = ex.ex;
			Game::prefsData = newArray<int8_t>(1);
			if (store != nullptr) {
				try {
					Game::prefsData = store->getRecord(1);
					this->prefsDataSize = Game::prefsData->length;
					store->closeRecordStore();
				} catch (JavaException& ex) {
					if (ex.isa(u"java/lang/Exception")) {
						s0 = ex.ex;
						return;
					}
					else throw;
				}
				return;
			}
			try {
				store = RecordStore::openRecordStore(u"Preferences"_j, 1);
				Game::prefsData[0] = 0;
				this->prefsDataSize = Game::prefsData->length;
				store->closeRecordStore();
				this->savePreferences();
			} catch (JavaException& ex) {
				if (ex.isa(u"java/lang/Exception")) {
					s0 = ex.ex;
					return;
				}
				else throw;
			}
			return;
		}
		else throw;
	}
	Game::prefsData = newArray<int8_t>(1);
	if (store != nullptr) {
		Game::prefsData = store->getRecord(1);
		this->prefsDataSize = Game::prefsData->length;
		store->closeRecordStore();
		return;
	}
	store = RecordStore::openRecordStore(u"Preferences"_j, 1);
	Game::prefsData[0] = 0;
	this->prefsDataSize = Game::prefsData->length;
	store->closeRecordStore();
	this->savePreferences();
}

void Game::savePreferences() {
	Ref<RecordStore> store;
	Ref<Object> s0;
	try {
		store = RecordStore::openRecordStore(u"Preferences"_j, 1);
		if (store->getNumRecords() != 0) {
			store->setRecord(1, Game::prefsData, 0, this->prefsDataSize);
		} else {
			store->addRecord(Game::prefsData, 0, this->prefsDataSize);
		}
		store->closeRecordStore();
	} catch (JavaException& ex) {
		if (ex.isa(u"java/lang/Exception")) {
			s0 = ex.ex;
			return;
		}
		else throw;
	}
}

void Game::buildNewSaveStep(int32_t step) {
	int32_t redDiamondTotal = 0, width = 0, height = 0, rowOrListHeaderPos = 0, colOrRow = 0, col = 0, worldIndex = 0, worldBlockPos = 0, stageCount = 0, stageIndex = 0, stageRecordPos = 0, collectibleCount = 0, t2 = 0, t4 = 0, t6 = 0, t9 = 0, t11 = 0, t13 = 0, t15 = 0, t17 = 0;
	Arr<int8_t> layerBytes, t1, t3, t5, t7, t8, t10, t12, t14, t16;
	Ref<String> stageMapFile;
	Ref<RecordStore> store;
	Ref<Object> s0;
	{
		try {
			stageMapFile = nullptr;
			switch (step) {
				case 2:
					stageMapFile = u"/map_angkor.out"_j;
					if (stageMapFile == nullptr) {
						stageMapFile = u"/map_scotland.out"_j;
					}
					if (stageMapFile == nullptr) {
						stageMapFile = u"/map_tibet.out"_j;
					}
					this->resourceStream = this->getClass()->getResourceAsStream(Game::worldDataFiles[step - 2]);
					this->resourceStream->read();
					worldIndex = step - 2;
					worldBlockPos = this->saveDataSize;
					Game::saveData[14 + worldIndex * 2] = (int8_t)(this->saveDataSize & 255);
					Game::saveData[14 + worldIndex * 2 + 1] = (int8_t)(this->saveDataSize >> 8);
					stageCount = this->resourceStream->read();
					t1 = Game::saveData;
					t2 = this->saveDataSize;
					this->saveDataSize = t2 + 1;
					t1[t2] = (int8_t)stageCount;
					t3 = Game::saveData;
					t4 = this->saveDataSize;
					this->saveDataSize = t4 + 1;
					t3[t4] = 0;
					this->allocStageMapNodes();
					this->loadStageMapFile(stageMapFile);
					t5 = Game::saveData;
					t6 = this->saveDataSize;
					this->saveDataSize = t6 + 1;
					t5[t6] = (int8_t)this->firstSecretStage;
					this->freeStageMapResources();
					this->saveDataSize = this->saveDataSize + (stageCount << 1);
					for (stageIndex = 0; stageIndex < stageCount; stageIndex++) {
						stageRecordPos = this->saveDataSize;
						Game::saveData[worldBlockPos + 3 + stageIndex * 2] = (int8_t)(stageRecordPos & 255);
						Game::saveData[worldBlockPos + 3 + stageIndex * 2 + 1] = (int8_t)(stageRecordPos >> 8);
						collectibleCount = 0;
						redDiamondTotal = 0;
						width = Game::readUShortLE(this->resourceStream);
						height = Game::readUShortLE(this->resourceStream);
						layerBytes = newArray<int8_t>(width * height);
						this->resourceStream->read(layerBytes);
						for (rowOrListHeaderPos = 0; rowOrListHeaderPos < height; rowOrListHeaderPos++) {
							for (colOrRow = 0; colOrRow < width; colOrRow++) {
								if (layerBytes[colOrRow + rowOrListHeaderPos * width] == 2) {
									redDiamondTotal = (int8_t)(redDiamondTotal + 1);
								}
							}
						}
						t7 = Game::saveData;
						t7[0] = (int8_t)(t7[0] + redDiamondTotal);
						t8 = Game::saveData;
						t9 = this->saveDataSize;
						this->saveDataSize = t9 + 1;
						t8[t9] = 0;
						t10 = Game::saveData;
						t11 = this->saveDataSize;
						this->saveDataSize = t11 + 1;
						t10[t11] = redDiamondTotal;
						t12 = Game::saveData;
						t13 = this->saveDataSize;
						this->saveDataSize = t13 + 1;
						t12[t13] = 0;
						this->resourceStream->skip((int64_t)(width * height));
						rowOrListHeaderPos = this->saveDataSize;
						this->saveDataSize = this->saveDataSize + 2;
						this->resourceStream->read(layerBytes);
						for (colOrRow = 0; colOrRow < height; colOrRow++) {
							for (col = 0; col < width; col++) {
								if (layerBytes[col + colOrRow * width] == 14 || layerBytes[col + colOrRow * width] == 33) {
									t14 = Game::saveData;
									t15 = this->saveDataSize;
									this->saveDataSize = t15 + 1;
									t14[t15] = (int8_t)col;
									t16 = Game::saveData;
									t17 = this->saveDataSize;
									this->saveDataSize = t17 + 1;
									t16[t17] = (int8_t)colOrRow;
									collectibleCount = (int8_t)(collectibleCount + 1);
								}
							}
						}
						Game::saveData[rowOrListHeaderPos] = 0;
						Game::saveData[rowOrListHeaderPos + 1] = collectibleCount;
					}
					this->resourceStream->close();
					this->resourceStream = nullptr;
					JSystem::gc();
					goto T1_end;
				case 3:
					if (stageMapFile == nullptr) {
						stageMapFile = u"/map_scotland.out"_j;
					}
					if (stageMapFile == nullptr) {
						stageMapFile = u"/map_tibet.out"_j;
					}
					this->resourceStream = this->getClass()->getResourceAsStream(Game::worldDataFiles[step - 2]);
					this->resourceStream->read();
					worldIndex = step - 2;
					worldBlockPos = this->saveDataSize;
					Game::saveData[14 + worldIndex * 2] = (int8_t)(this->saveDataSize & 255);
					Game::saveData[14 + worldIndex * 2 + 1] = (int8_t)(this->saveDataSize >> 8);
					stageCount = this->resourceStream->read();
					t1 = Game::saveData;
					t2 = this->saveDataSize;
					this->saveDataSize = t2 + 1;
					t1[t2] = (int8_t)stageCount;
					t3 = Game::saveData;
					t4 = this->saveDataSize;
					this->saveDataSize = t4 + 1;
					t3[t4] = 0;
					this->allocStageMapNodes();
					this->loadStageMapFile(stageMapFile);
					t5 = Game::saveData;
					t6 = this->saveDataSize;
					this->saveDataSize = t6 + 1;
					t5[t6] = (int8_t)this->firstSecretStage;
					this->freeStageMapResources();
					this->saveDataSize = this->saveDataSize + (stageCount << 1);
					stageIndex = 0;
					while (true) {
						if (stageIndex >= stageCount) {
							break;
						}
						stageRecordPos = this->saveDataSize;
						Game::saveData[worldBlockPos + 3 + stageIndex * 2] = (int8_t)(stageRecordPos & 255);
						Game::saveData[worldBlockPos + 3 + stageIndex * 2 + 1] = (int8_t)(stageRecordPos >> 8);
						collectibleCount = 0;
						redDiamondTotal = 0;
						width = Game::readUShortLE(this->resourceStream);
						height = Game::readUShortLE(this->resourceStream);
						layerBytes = newArray<int8_t>(width * height);
						this->resourceStream->read(layerBytes);
						rowOrListHeaderPos = 0;
						while (true) {
							if (rowOrListHeaderPos >= height) {
								break;
							}
							colOrRow = 0;
							while (true) {
								if (colOrRow >= width) {
									break;
								}
								if (layerBytes[colOrRow + rowOrListHeaderPos * width] == 2) {
									redDiamondTotal = (int8_t)(redDiamondTotal + 1);
								}
								colOrRow++;
							}
							rowOrListHeaderPos++;
						}
						t7 = Game::saveData;
						t7[0] = (int8_t)(t7[0] + redDiamondTotal);
						t8 = Game::saveData;
						t9 = this->saveDataSize;
						this->saveDataSize = t9 + 1;
						t8[t9] = 0;
						t10 = Game::saveData;
						t11 = this->saveDataSize;
						this->saveDataSize = t11 + 1;
						t10[t11] = redDiamondTotal;
						t12 = Game::saveData;
						t13 = this->saveDataSize;
						this->saveDataSize = t13 + 1;
						t12[t13] = 0;
						this->resourceStream->skip((int64_t)(width * height));
						rowOrListHeaderPos = this->saveDataSize;
						this->saveDataSize = this->saveDataSize + 2;
						this->resourceStream->read(layerBytes);
						colOrRow = 0;
						while (true) {
							if (colOrRow >= height) {
								break;
							}
							col = 0;
							while (true) {
								if (col >= width) {
									break;
								}
								if (layerBytes[col + colOrRow * width] == 14 || layerBytes[col + colOrRow * width] == 33) {
									t14 = Game::saveData;
									t15 = this->saveDataSize;
									this->saveDataSize = t15 + 1;
									t14[t15] = (int8_t)col;
									t16 = Game::saveData;
									t17 = this->saveDataSize;
									this->saveDataSize = t17 + 1;
									t16[t17] = (int8_t)colOrRow;
									collectibleCount = (int8_t)(collectibleCount + 1);
								}
								col++;
							}
							colOrRow++;
						}
						Game::saveData[rowOrListHeaderPos] = 0;
						Game::saveData[rowOrListHeaderPos + 1] = collectibleCount;
						stageIndex++;
					}
					this->resourceStream->close();
					this->resourceStream = nullptr;
					JSystem::gc();
					goto T1_end;
				case 4:
					if (stageMapFile == nullptr) {
						stageMapFile = u"/map_tibet.out"_j;
					}
					this->resourceStream = this->getClass()->getResourceAsStream(Game::worldDataFiles[step - 2]);
					this->resourceStream->read();
					worldIndex = step - 2;
					worldBlockPos = this->saveDataSize;
					Game::saveData[14 + worldIndex * 2] = (int8_t)(this->saveDataSize & 255);
					Game::saveData[14 + worldIndex * 2 + 1] = (int8_t)(this->saveDataSize >> 8);
					stageCount = this->resourceStream->read();
					t1 = Game::saveData;
					t2 = this->saveDataSize;
					this->saveDataSize = t2 + 1;
					t1[t2] = (int8_t)stageCount;
					t3 = Game::saveData;
					t4 = this->saveDataSize;
					this->saveDataSize = t4 + 1;
					t3[t4] = 0;
					this->allocStageMapNodes();
					this->loadStageMapFile(stageMapFile);
					t5 = Game::saveData;
					t6 = this->saveDataSize;
					this->saveDataSize = t6 + 1;
					t5[t6] = (int8_t)this->firstSecretStage;
					this->freeStageMapResources();
					this->saveDataSize = this->saveDataSize + (stageCount << 1);
					stageIndex = 0;
					while (true) {
						if (stageIndex >= stageCount) {
							break;
						}
						stageRecordPos = this->saveDataSize;
						Game::saveData[worldBlockPos + 3 + stageIndex * 2] = (int8_t)(stageRecordPos & 255);
						Game::saveData[worldBlockPos + 3 + stageIndex * 2 + 1] = (int8_t)(stageRecordPos >> 8);
						collectibleCount = 0;
						redDiamondTotal = 0;
						width = Game::readUShortLE(this->resourceStream);
						height = Game::readUShortLE(this->resourceStream);
						layerBytes = newArray<int8_t>(width * height);
						this->resourceStream->read(layerBytes);
						rowOrListHeaderPos = 0;
						while (true) {
							if (rowOrListHeaderPos >= height) {
								break;
							}
							colOrRow = 0;
							while (true) {
								if (colOrRow >= width) {
									break;
								}
								if (layerBytes[colOrRow + rowOrListHeaderPos * width] == 2) {
									redDiamondTotal = (int8_t)(redDiamondTotal + 1);
								}
								colOrRow++;
							}
							rowOrListHeaderPos++;
						}
						t7 = Game::saveData;
						t7[0] = (int8_t)(t7[0] + redDiamondTotal);
						t8 = Game::saveData;
						t9 = this->saveDataSize;
						this->saveDataSize = t9 + 1;
						t8[t9] = 0;
						t10 = Game::saveData;
						t11 = this->saveDataSize;
						this->saveDataSize = t11 + 1;
						t10[t11] = redDiamondTotal;
						t12 = Game::saveData;
						t13 = this->saveDataSize;
						this->saveDataSize = t13 + 1;
						t12[t13] = 0;
						this->resourceStream->skip((int64_t)(width * height));
						rowOrListHeaderPos = this->saveDataSize;
						this->saveDataSize = this->saveDataSize + 2;
						this->resourceStream->read(layerBytes);
						colOrRow = 0;
						while (true) {
							if (colOrRow >= height) {
								break;
							}
							col = 0;
							while (true) {
								if (col >= width) {
									break;
								}
								if (layerBytes[col + colOrRow * width] == 14 || layerBytes[col + colOrRow * width] == 33) {
									t14 = Game::saveData;
									t15 = this->saveDataSize;
									this->saveDataSize = t15 + 1;
									t14[t15] = (int8_t)col;
									t16 = Game::saveData;
									t17 = this->saveDataSize;
									this->saveDataSize = t17 + 1;
									t16[t17] = (int8_t)colOrRow;
									collectibleCount = (int8_t)(collectibleCount + 1);
								}
								col++;
							}
							colOrRow++;
						}
						Game::saveData[rowOrListHeaderPos] = 0;
						Game::saveData[rowOrListHeaderPos + 1] = collectibleCount;
						stageIndex++;
					}
					this->resourceStream->close();
					this->resourceStream = nullptr;
					JSystem::gc();
					goto T1_end;
				default:
					return;
				case 0:
				case 1:
					store = nullptr;
					try {
						store = RecordStore::openRecordStore(u"DiamondRush"_j, 0);
					} catch (JavaException& ex) {
						if (ex.isa(u"java/lang/Exception")) {
							s0 = ex.ex;
						}
						else throw;
					}
					if (store != nullptr) {
						this->noSavedProgress = 0;
						store->closeRecordStore();
						if (step != 0) {
							Game::saveData = newArray<int8_t>(1000);
							Game::saveData[3] = 5;
							Game::saveData[8] = 4;
							Game::saveData[9] = 0;
							Game::saveData[10] = 0;
							this->saveDataSize = 14;
							this->saveDataSize = this->saveDataSize + 6;
						}
					} else {
						this->noSavedProgress = 1;
						{
							if (step != 0) {
								Game::saveData = newArray<int8_t>(1000);
								Game::saveData[3] = 5;
								Game::saveData[8] = 4;
								Game::saveData[9] = 0;
								Game::saveData[10] = 0;
								this->saveDataSize = 14;
								this->saveDataSize = this->saveDataSize + 6;
								goto B42_end;
							}
							goto B42_end;
						}
						B42_end:;
						return;
					}
					return;
			}
		} catch (JavaException& ex) {
			if (ex.isa(u"java/lang/Exception")) {
				s0 = ex.ex;
				return;
			}
			else throw;
		}
	}
	T1_end:;
}

void Game::writeLivesToSave() {
	Game::saveData[3] = (int8_t)this->lives;
	Game::saveData[11] = this->checkpointMsgCount;
}

void Game::readSaveStats() {
	this->needReadSaveStats = 0;
	this->lives = Game::saveData[3];
	this->checkpointMsgCount = Game::saveData[11];
	this->diamondCount = Game::readU16LE(Game::saveData, 4);
}

int8_t Game::getStageFlags(int32_t world, int32_t stage) {
	int32_t recordPos = 0;
	recordPos = this->getStageSaveOffset(world, stage);
	return Game::saveData[recordPos + 2];
}

void Game::addStageFlags(int32_t world, int32_t stage, int8_t flags) {
	int32_t recordPos = 0, t2 = 0;
	Arr<int8_t> t1;
	recordPos = this->getStageSaveOffset(world, stage);
	t1 = Game::saveData;
	t2 = recordPos + 2;
	t1[t2] = (int8_t)(t1[t2] | flags);
}

void Game::raiseSavedLatestStage(int32_t world, int32_t stage) {
	int32_t latestStagePos = 0;
	latestStagePos = Game::getWorldSaveOffset(world) + 1;
	if (Game::saveData[latestStagePos] < stage) {
		Game::saveData[latestStagePos] = (int8_t)stage;
	}
}

int32_t Game::getSavedLatestStage(int32_t world) {
	int32_t latestStagePos = 0;
	latestStagePos = Game::getWorldSaveOffset(world) + 1;
	if (latestStagePos < 0 || latestStagePos > Game::saveData->length) {
		return 0;
	}
	return Game::saveData[Game::getWorldSaveOffset(world) + 1];
}

int32_t Game::getWorldSaveOffset(int32_t world) {
	int32_t s0 = 0;
	{
		if (world < 0) {
			s0 = 0;
			world = s0;
			goto B1_end;
		}
		if (world >= 3) {
			s0 = 2;
			world = s0;
		}
	}
	B1_end:;
	return Game::readU16LE(Game::saveData, 14 + world * 2);
}

int32_t Game::getWorldStageCount(int32_t world) {
	int32_t s0 = 0;
	Ref<Object> s0_o;
	try {
		s0 = Game::saveData[Game::getWorldSaveOffset(world) + 0];
	} catch (JavaException& ex) {
		if (ex.isa(u"java/lang/Exception")) {
			s0_o = ex.ex;
			return 0;
		}
		else throw;
	}
	return s0;
}

int32_t Game::getWorldFirstSecretStage(int32_t world) {
	return Game::saveData[Game::getWorldSaveOffset(world) + 2];
}

int32_t Game::getStageSaveOffset(int32_t world, int32_t stage) {
	return Game::readU16LE(Game::saveData, Game::getWorldSaveOffset(world) + 3 + stage * 2);
}

int32_t Game::getStageBankedRedDiamonds(int32_t world, int32_t stage) {
	return Game::saveData[this->getStageSaveOffset(world, stage) + 0];
}

void Game::setStageBankedRedDiamonds(int32_t world, int32_t stage, int32_t count) {
	Game::saveData[this->getStageSaveOffset(world, stage) + 0] = (int8_t)count;
}

int32_t Game::getStageRedDiamondTotal(int32_t world, int32_t stage) {
	return Game::saveData[this->getStageSaveOffset(world, stage) + 1];
}

void Game::markCollectibleTaken(int32_t world, int32_t stage, int32_t col, int32_t row) {
	int32_t recordPos = 0, collectibleCount = 0, index = 0, t2 = 0;
	Arr<int8_t> t1;
	recordPos = this->getStageSaveOffset(world, stage);
	collectibleCount = Game::saveData[recordPos + 4];
	index = 0;
	while (true) {
		if (index >= collectibleCount) {
			return;
		}
		if (Game::saveData[recordPos + 5 + 2 * index + 0] != col || Game::saveData[recordPos + 5 + 2 * index + 1] != row) {
			index++;
			continue;
		}
		break;
	}
	Game::saveData[recordPos + 5 + 2 * index + 0] = 0;
	Game::saveData[recordPos + 5 + 2 * index + 1] = 0;
	t1 = Game::saveData;
	t2 = recordPos + 3;
	t1[t2] = (int8_t)(t1[t2] + 1);
}

bool Game::isCollectibleTaken(int32_t world, int32_t stage, int32_t col, int32_t row) {
	int32_t recordPos = 0, collectibleCount = 0, index = 0;
	recordPos = this->getStageSaveOffset(world, stage);
	collectibleCount = Game::saveData[recordPos + 4];
	index = 0;
	while (true) {
		if (index >= collectibleCount) {
			return 1;
		}
		if (Game::saveData[recordPos + 5 + 2 * index + 0] != col || Game::saveData[recordPos + 5 + 2 * index + 1] != row) {
			index++;
			continue;
		}
		break;
	}
	return 0;
}

void Game::initKnightBossStage() {
	this->bossState = 13;
	this->bossHealth = 4;
	this->knightX = 408;
	this->specialStageType = 5;
	this->levelResourceMask = this->levelResourceMask | 128LL;
	this->levelResourceMask = this->levelResourceMask | 8LL;
	this->bossWokenUp = 0;
	this->bossRockSpawnRow = 16;
	this->bossRockCol1 = 16;
	this->bossRockCol2 = 19;
	this->bossRockCheckRow = 18;
}

void Game::loadLevelData() {
	Arr<int8_t> buffer;
	int32_t found = 0, stageCount = 0, stageIndex = 0, width = 0, height = 0, col = 0, row = 0;
	Game::bufLeftX = -1;
	Game::itemRaiseFreeze = 0;
	this->isExplorerVisible = 1;
	this->nextCheckpointIndex = 0;
	this->shakeTime = 0;
	this->levelResourceMask = 0LL;
	this->levelExtraResourceMask = 0LL;
	this->exitDoorCol = 0;
	this->exitDoorRow = 0;
	this->specialStageType = 0;
	this->stageWasCompleted = (this->getStageFlags(this->world, this->stage) & 2) != 0 ? 1 : 0;
	this->gateRevealState = 0;
	switch (this->world) {
		case 2:
			if (this->stage == 10) {
				this->resetBoss();
				this->yetiX = 360;
				this->specialStageType = 3;
				this->levelResourceMask = this->levelResourceMask | 128LL;
				this->levelResourceMask = this->levelResourceMask | 8LL;
			}
			break;
		case 1:
			if (this->stage == 9) {
				this->initKnightBossStage();
			}
			break;
		case 0:
			if (this->stage != 5) {
				if (this->stage != 13) {
					if (this->stage == 8) {
						this->specialStageType = 4;
						this->bossState = 0;
						this->bossHealth = 3;
						this->anacondaHoleIndex = 0;
						this->bossTimer = 0;
						this->anacondaSlamVisible = 0;
						this->levelResourceMask = this->levelResourceMask | 8LL;
						this->levelResourceMask = this->levelResourceMask | 1024LL;
						this->bossRockSpawnRow = 2;
						this->bossRockCol1 = 12;
						this->bossRockCol2 = 15;
						this->bossRockCheckRow = 5;
					}
				} else {
					this->specialStageType = 2;
					this->introHintIconVisible = 0;
				}
			} else {
				this->specialStageType = 1;
				this->floodHeight = 816;
				this->floodTriggerStage = 0;
			}
			break;
		default:
			break;
	}
	this->introTrigger13Reached = 0;
	this->introTrigger16Reached = 0;
	this->introHintSpotReached = 0;
	this->diamondsToOpenExit = 0;
	this->slidingObjParams = -1;
	this->slidingObjSavedParams = -1;
	this->slidingObjSubStep = 0;
	this->slidingObjCol = 0;
	this->slidingObjRow = 0;
	this->slideCellsLeft = 0;
	this->playerIdleCountdown = 70;
	this->explorerEnergy = Game::saveData[8];
	this->currentMoveDir = 0;
	this->diamondCount = 0;
	this->hitsTaken = 0;
	this->livesLostInStage = 0;
	this->redDiamondCount = 0;
	this->deathTimer = 0;
	this->explorerStateFlags = 0;
	this->encasedStruggleCount = 0;
	this->goldKeys = 0;
	this->silverKeys = 0;
	Game::activeGateId = -1;
	Game::gateRemainingCounts = nullptr;
	Game::gateObjectiveMsgs = nullptr;
	this->resourceStream = this->getClass()->getResourceAsStream(Game::worldDataFiles[this->world]);
	this->resourceStream->read();
	found = 0;
	while (found == 0) {
		stageCount = this->resourceStream->read();
		stageIndex = 0;
		buffer = newArray<int8_t>(4);
		while (stageIndex < stageCount && found == 0) {
			this->resourceStream->read(buffer);
			width = Game::readU16LE(buffer, 0);
			height = Game::readU16LE(buffer, 2);
			if (stageIndex != this->stage) {
				this->resourceStream->skip((int64_t)(width * height * 3));
			} else {
				this->levelW = width;
				this->levelH = height;
				Game::cellTypes = nullptr;
				Game::cellUpdateTimers = nullptr;
				Game::cellObjects = nullptr;
				JSystem::gc();
				Game::cellTypes = multiArray<int8_t, 2>(this->levelW, this->levelH);
				Game::cellUpdateTimers = multiArray<int8_t, 2>(this->levelW, this->levelH);
				Game::cellObjects = multiArray<int32_t, 2>(this->levelW, this->levelH);
				buffer = newArray<int8_t>(this->levelW * this->levelH);
				this->resourceStream->read(buffer);
				for (col = 0; col < this->levelW; col++) {
					for (row = 0; row < this->levelH; row++) {
						Game::cellTypes[col][row] = buffer[col + row * this->levelW];
					}
				}
				Game::cellMoveOffsets = multiArray<int8_t, 2>(this->levelW, this->levelH);
				Game::cellStates = multiArray<int32_t, 2>(this->levelW, this->levelH);
				this->resourceStream->read(buffer);
				for (col = 0; col < this->levelW; col++) {
					for (row = 0; row < this->levelH; row++) {
						Game::cellStates[col][row] = buffer[col + row * this->levelW];
					}
				}
				this->resourceStream->read(buffer);
				for (col = 0; col < this->levelW; col++) {
					for (row = 0; row < this->levelH; row++) {
						Game::cellObjects[col][row] = buffer[col + row * this->levelW];
					}
				}
				buffer = nullptr;
				found = 1;
			}
			stageIndex++;
		}
	}
	this->resourceStream->close();
	this->resourceStream = nullptr;
	this->camTargetX = 0;
	this->camX = 0;
	this->camTargetY = 0;
	this->camY = 0;
	this->updateCameraFollow();
	JSystem::gc();
}

void Game::unlockStagesAfterClear() {
	int32_t nodeCol = 0, linkRow = 0, linkKind = 0, linkStage = 0, nodeRow = 0, nodeStage = 0, linkCount = 0, bitPos = 0, linkIndex = 0, linkCol = 0;
	int64_t linkNode = 0, node = 0;
	nodeCol = this->mapMarkerCol;
	nodeRow = this->mapMarkerRow;
	node = Game::stageMapNodes[nodeCol][nodeRow];
	nodeStage = Game::extractLongBits(node, 6, 5);
	linkCount = Game::extractLongBits(node, 11, 3);
	bitPos = 14;
	if (this->stage >= this->firstSecretStage) {
		this->addStageFlags(this->world, this->stage, 2);
	}
	if (linkCount <= 1) {
		Game::latestUnlockedStage = this->stage;
	} else {
		linkIndex = 0;
		while (linkIndex < linkCount) {
			linkCol = Game::extractLongBits(node, (int8_t)bitPos, 4);
			bitPos += 4;
			linkRow = Game::extractLongBits(node, (int8_t)bitPos, 4);
			linkNode = Game::stageMapNodes[linkCol][linkRow];
			linkKind = Game::extractLongBits(linkNode, 3, 3);
			if (linkKind == 1) {
				linkStage = Game::extractLongBits(linkNode, 6, 5);
				if (linkStage > nodeStage) {
					Game::latestUnlockedStage = linkStage;
					this->unlockFromNodeX = nodeCol;
					this->unlockFromNodeY = nodeRow;
					this->addStageFlags(this->world, Game::latestUnlockedStage, 64);
					this->newStageUnlocked = 1;
				}
			}
			linkIndex++;
			bitPos += 4;
		}
	}
}

void Game::paint(Ref<Graphics> g) {
	Ref<Object> s0;
	try {
		this->screenGraphics = g;
		this->screenGraphics->setClip(0, 0, 240, 320);
		switch (Game::screen) {
			case 34:
				this->drawTextViewerScreen();
				break;
			case 33:
				this->drawHelpScreen();
				break;
			case 31:
				if (this->newGamePromptDirty) {
					this->newGamePromptDirty = 0;
					this->screenGraphics->setColor(0);
					this->screenGraphics->fillRect(0, 0, 240, 320);
					Game::spritePacks[41]->lineSpacing = 5;
					Game::spritePacks[41]->drawMultilineString(this->screenGraphics, Game::wrapText(Game::langStrings[!this->noSavedProgress ? 68 : 69], 220), 120, 160, 3);
					this->drawSelectSoftkeyIcon();
					this->drawBackSoftkeyIcon();
				}
				break;
			case 30:
				this->drawTitleBackground(this->screenGraphics, 1);
				if (Game::frameCount % 20 >= 10) {
					Game::spritePacks[41]->drawString(this->screenGraphics, Game::langStrings[82], 120, 250, 17);
				}
				break;
			case 29:
				this->drawEndingScreen();
				break;
			case 28:
				this->loadingStepCount = 11;
				this->drawLoadingScreen();
				break;
			case 27:
				this->drawWorldMapScreen();
				break;
			case 26:
				break;
			case 24:
				this->drawCheatScreen();
				break;
			case 22:
				this->drawCredits();
				break;
			case 20:
				Game::drawTextInBox(this->screenGraphics, Game::spritePacks[41], Game::langStrings[48], 120, 180, 3, 20, 1);
				break;
			case 18:
				this->loadShopSpritesAndHandleInput();
				this->needsFullRedraw = 1;
				Game::screen = 25;
				this->shopLastDrawnCursor = this->shopCursor;
				this->shopDiamondsText = jnew<StringBuffer>(Game::langStrings[110])->append(u" "_j)->append(Game::readU16LE(Game::saveData, 4))->append(u" "_j)->append(Game::langStrings[109])->toString();
				this->drawShopScreen();
				break;
			case 25:
				this->drawShopScreen();
				break;
			case 17:
				this->drawStageResults();
				break;
			case 16:
				this->drawLoadingScreen();
				break;
			case 15:
				this->drawStageMapScreen();
				break;
			case 12:
				this->drawGameOverScreen();
				break;
			case 10:
				this->updateMoreGamesScreen(this->screenGraphics);
				break;
			case 8:
			case 9:
			case 21:
			case 35:
				this->drawLoadingScreen();
				break;
			case 7:
				this->drawMenu();
				break;
			case 6:
				this->paintGameloftLogo();
				break;
			case 5:
				if (this->loadingFullRedraw) {
					this->drawLoadingScreen();
				} else {
					this->screenGraphics->setClip(0, 293, 240, 27);
					this->drawLoadingScreen();
					this->screenGraphics->setClip(0, 0, 240, 320);
				}
				if (Game::tipPageData != nullptr && this->loadingFullRedraw) {
					this->drawTipPage();
				}
				break;
			case 4:
				this->drawMainMenuScreen();
				break;
			case 2:
				this->drawMenu();
				break;
			case 1:
				this->paintPlayfield();
				break;
			case 0:
			case 3:
				break;
			default:
				break;
		}
		this->drawPopup();
	} catch (JavaException& ex) {
		{
			s0 = ex.ex;
			return;
		}
	}
}

void Game::drawHelpScreen() {
	Ref<String> text;
	if (this->needsFullRedraw) {
		this->screenGraphics->setColor(0);
		this->screenGraphics->setClip(0, 0, 240, 320);
		this->screenGraphics->fillRect(0, 0, 240, 320);
		Game::spritePacks[41]->lineSpacing = 3;
		text = jnew<StringBuffer>(Game::langStrings[4])->append(u"\n\n"_j)->append(Game::langStrings[103])->append(u"\n"_j)->append(Game::langStrings[104])->append(u"\n"_j)->append(Game::langStrings[105])->append(u"\n\n"_j)->append(Game::langStrings[106])->append(u"\n\n"_j)->append(Game::langStrings[107])->append(u"\n\n"_j)->append(Game::langStrings[108])->toString();
		text = Game::wrapText(text, 235);
		Game::spritePacks[41]->drawMultilineString(this->screenGraphics, text, 120, 10, 17);
		this->drawBackSoftkeyIcon();
		this->needsFullRedraw = 0;
	}
}

void Game::drawWorldMapBackgroundAt(Ref<Graphics> g, bool dimmed, int32_t offsetX, int32_t offsetY) {
	int32_t overlayX = 0, x = 0, startX = 0, startY = 0, y = 0;
	g->setClip(0, 0, 240, 320);
	startX = 0;
	startY = 0;
	if (offsetX != 0 || offsetY != 0) {
		startX -= 24;
		startY -= 24;
	}
	y = startY;
	overlayX = 0;
	while (y < 320) {
		for (x = startX; x < 240; x += 24) {
			g->drawImage(Game::objectFrameImages[8][0], x + offsetX, y + offsetY, 0);
		}
		y += 24;
	}
	Game::spritePacks[10]->drawFrame(g, 0, this->medallionX + offsetX, this->medallionY + offsetY, 0, 0, 0);
	if (dimmed != 0) {
		for (y = 0; y < 320; y += 24) {
			for (overlayX = 0; overlayX < 240; overlayX += 24) {
				Game::spritePacks[17]->drawFrame(g, 16, overlayX, y, 0, 0, 0);
			}
		}
	}
}

void Game::drawWorldMapBackground(Ref<Graphics> g, bool dimmed) {
	this->drawWorldMapBackgroundAt(g, dimmed, 0, 0);
}

void Game::drawEndingScreen() {
	int32_t packOrSpacing = 0, gemOrText_n = 0;
	Ref<String> gemOrText;
	if (this->needsFullRedraw) {
		this->drawWorldMapBackgroundAt(this->screenGraphics, 0, this->medallionShakeX, this->medallionShakeY);
		Game::spritePacks[17]->drawFrame(this->screenGraphics, 11, 120 + Tables::medallionPieceOffsets[6] + this->medallionShakeX, 136 + Tables::medallionPieceOffsets[7] + this->medallionShakeY, 0, 0, 0);
		packOrSpacing = 0;
		for (gemOrText_n = 0; gemOrText_n < 3; gemOrText_n++) {
			packOrSpacing = 52 + gemOrText_n;
			Game::spritePacks[packOrSpacing]->drawFrame(this->screenGraphics, 0, Tables::medallionPieceOffsets[gemOrText_n << 1] + 120 - this->gemHalfWidth + this->medallionShakeX, Tables::medallionPieceOffsets[(gemOrText_n << 1) + 1] + 136 - this->gemHalfHeight + this->medallionShakeY, 0, 0, 0);
		}
	}
	switch (this->endingPhase) {
		case 9:
		case 10:
			FallingRocks::draw(this->screenGraphics);
			packOrSpacing = Game::spritePacks[41]->lineSpacing;
			Game::spritePacks[41]->lineSpacing = 3;
			gemOrText = jnew<StringBuffer>()->append(Game::langStrings[40])->append(u"\n"_j)->append(Game::langStrings[97])->toString();
			gemOrText = Game::wrapText(gemOrText, 220);
			Game::spritePacks[41]->measureString(gemOrText);
			Game::drawFramedBox(this->screenGraphics, (240 - SpritePack::textWidth >> 1) - 3, (320 - SpritePack::textHeight >> 1) - 3, SpritePack::textWidth + 6, SpritePack::textHeight + 6, 7096587, 0);
			Game::spritePacks[41]->drawMultilineString(this->screenGraphics, gemOrText, 120, 160, 3);
			Game::spritePacks[41]->lineSpacing = packOrSpacing;
			return;
		case 8:
			FallingRocks::draw(this->screenGraphics);
			return;
		case 7:
			return;
		case 6:
			return;
		case 5:
			return;
		case 4:
			return;
		case 3:
			return;
		case 2:
			return;
		case 1:
			if (!this->needsFullRedraw) {
				this->screenGraphics->setColor(this->endingFlashColor);
				this->screenGraphics->fillRect(0, 0, 240, 320);
				for (gemOrText_n = 0; gemOrText_n < 3; gemOrText_n++) {
					packOrSpacing = 52 + gemOrText_n;
					Game::spritePacks[packOrSpacing]->drawFrame(this->screenGraphics, 0, Tables::medallionPieceOffsets[gemOrText_n << 1] + 120 - this->gemHalfWidth, Tables::medallionPieceOffsets[(gemOrText_n << 1) + 1] + 136 - this->gemHalfHeight, 0, 0, 0);
				}
			}
			return;
		default:
			return;
	}
}

void Game::drawWorldMapScreen() {
	int32_t index = 0, gemIndexOrSpacing = 0, boxX = 0, boxY = 0, boxW = 0, boxH = 0;
	Ref<String> infoText;
	if (this->needsFullRedraw || this->worldMapInfoDirty) {
		this->screenGraphics->setClip(0, 0, 240, 320);
		this->drawWorldMapBackground(this->screenGraphics, 0);
		Game::spritePacks[17]->drawFrame(this->screenGraphics, 11, 120 + Tables::medallionPieceOffsets[6], 136 + Tables::medallionPieceOffsets[7], 0, 0, 0);
		this->drawBackSoftkeyIcon();
		this->drawSelectSoftkeyIcon();
		Game::spritePacks[41]->drawString(this->screenGraphics, Game::langStrings[27]->toLowerCase(), 222, 311, 10);
		this->needsFullRedraw = 0;
	} else {
		this->screenGraphics->setClip(this->worldMapCursorPrevX + 120, this->worldMapCursorPrevY + 136, 14, 22);
		Game::spritePacks[10]->drawFrame(this->screenGraphics, 0, this->medallionX, this->medallionY, 0, 0, 0);
	}
	if (this->worldUnlockAnimIndex == 0) {
		for (index = 0; index < 3; index++) {
			if (Game::worldUnlockedOnMap[index] != 0) {
				Game::spritePacks[10]->drawFrame(this->screenGraphics, index + 1, this->medallionX, this->medallionY, 0, 0, 0);
			}
		}
	} else {
		this->worldMapInfoDirty = 0;
		this->needsFullRedraw = 1;
		for (index = 0; index < this->worldUnlockAnimIndex; index++) {
			if (Game::isWorldUnlocked(index)) {
				Game::spritePacks[10]->drawFrame(this->screenGraphics, index + 1, this->medallionX, this->medallionY, 0, 0, 0);
			}
		}
		this->screenGraphics->setClip(0, 0, 240, 320);
		if (this->sparkleFrame >= this->sparkleFrameCount) {
			if (irem(this->worldMapCursorFrame, this->worldMapCursorFrameCount) >= this->worldMapCursorFrameCount >> 1) {
				Game::spritePacks[10]->drawFrame(this->screenGraphics, this->worldUnlockAnimIndex + 1, this->medallionX, this->medallionY, 0, 0, 0);
				this->worldUnlockBlinkCount = this->worldUnlockBlinkCount + 1;
			}
			if (this->worldUnlockBlinkCount >= 15) {
				Game::worldUnlockedOnMap[this->worldUnlockAnimIndex] = 1;
				this->worldUnlockBlinkCount = 0;
				this->worldUnlockAnimIndex = 0;
				this->sparkleFrame = 0;
				this->updateWorldMapNodeTexts();
				this->worldMapInfoDirty = 1;
				this->needsFullRedraw = 0;
			}
		} else {
			Game::spritePacks[9]->drawAnimFrame(this->screenGraphics, 5, this->sparkleFrame, Tables::medallionPieceOffsets[this->worldUnlockAnimIndex << 1] + 120 - 12, Tables::medallionPieceOffsets[(this->worldUnlockAnimIndex << 1) + 1] + 124, 0, 0, 0);
			this->sparkleFrame = this->sparkleFrame + 1;
		}
	}
	for (gemIndexOrSpacing = 0; gemIndexOrSpacing < 3; gemIndexOrSpacing++) {
		if (Game::elementalDiamondPlaced[gemIndexOrSpacing] != 0) {
			index = 52 + gemIndexOrSpacing;
			if (this->placingElementalIndex != gemIndexOrSpacing) {
				Game::spritePacks[index]->drawFrame(this->screenGraphics, 0, Tables::medallionPieceOffsets[gemIndexOrSpacing << 1] + 120 - this->gemHalfWidth, Tables::medallionPieceOffsets[(gemIndexOrSpacing << 1) + 1] + 136 - this->gemHalfHeight, 0, 0, 0);
			}
		}
	}
	if (this->placingElementalIndex == -1) {
		this->worldMapCursorFrame = irem(this->worldMapCursorFrame, this->worldMapCursorFrameCount);
		this->screenGraphics->setClip(this->worldMapCursorX + 120, 136 + this->worldMapCursorY, 14, 22);
		Game::spritePacks[55]->drawAnimFrame(this->screenGraphics, 0, this->worldMapCursorFrame, 120 + this->worldMapCursorX, 136 + this->worldMapCursorY, 0, 0, 0);
		this->worldMapCursorFrame = this->worldMapCursorFrame + 1;
		if (this->worldMapInfoDirty) {
			gemIndexOrSpacing = Game::spritePacks[41]->lineSpacing;
			Game::spritePacks[41]->lineSpacing = 1;
			infoText = jnew<StringBuffer>()->append(this->worldMapHintText)->append(u"\n"_j)->append(this->worldMapNodeName)->toString();
			infoText = Game::wrapText(infoText, 220);
			Game::spritePacks[41]->measureString(infoText);
			boxX = (240 - SpritePack::textWidth >> 1) - 3;
			boxY = 250 - (SpritePack::textHeight >> 1) - 3;
			boxW = SpritePack::textWidth + 6;
			boxH = SpritePack::textHeight + 6;
			this->screenGraphics->setClip(boxX, boxY, boxW, boxH);
			Game::drawFramedBox(this->screenGraphics, boxX, boxY, boxW, boxH, 7096587, 0);
			Game::spritePacks[41]->drawMultilineString(this->screenGraphics, infoText, 120, 250, 3);
			Game::spritePacks[41]->lineSpacing = gemIndexOrSpacing;
			this->worldMapInfoDirty = 0;
		}
		return;
	}
	this->needsFullRedraw = 1;
	if (this->animateGemToMedallion(this->placingElementalIndex)) {
		this->placingElementalIndex = -1;
		if (Game::elementalDiamondPlaced[0] != 0 && Game::elementalDiamondPlaced[1] != 0 && Game::elementalDiamondPlaced[2] != 0) {
			this->resetCounters();
			this->needsFullRedraw = 1;
			this->creditsAfterEnding = 1;
			Game::screen = 29;
		}
	}
}

bool Game::animateGemToMedallion(int32_t world) {
	int32_t packIndex = 0, targetX = 0, targetY = 0, deltaY = 0, deltaX = 0, flashColorStep = 0;
	packIndex = 52 + world;
	targetX = Tables::medallionPieceOffsets[world << 1] + 120;
	targetY = Tables::medallionPieceOffsets[(world << 1) + 1] + 136;
	deltaY = targetY - this->flyingGemY;
	deltaX = targetX - this->flyingGemX;
	if (deltaY >= 0) {
		if (deltaY > 0) {
			this->flyingGemY = this->flyingGemY + 2;
			if (this->flyingGemY >= targetY) {
				this->flyingGemY = targetY;
			}
		}
	} else {
		this->flyingGemY = this->flyingGemY - 2;
		if (this->flyingGemY <= targetY) {
			this->flyingGemY = targetY;
		}
	}
	if (deltaX >= 0) {
		if (deltaX > 0) {
			this->flyingGemX = this->flyingGemX + 3;
			if (this->flyingGemX >= targetX) {
				this->flyingGemX = targetX;
			}
		}
	} else {
		this->flyingGemX = this->flyingGemX - 3;
		if (this->flyingGemX <= targetX) {
			this->flyingGemX = targetX;
		}
	}
	Game::spritePacks[packIndex]->drawFrame(this->screenGraphics, 0, this->flyingGemX - this->gemHalfWidth, this->flyingGemY - this->gemHalfHeight, 0, 0, 0);
	if (this->flyingGemX != targetX || this->flyingGemY != targetY) {
		return 0;
	}
	this->flyingGemX = targetX;
	this->flyingGemY = targetY;
	if (this->gemFlashCounter >= 20) {
		if (this->sparkleFrame >= this->sparkleFrameCount) {
			this->sparkleFrame = 0;
			this->gemFlashCounter = 0;
			return 1;
		}
		Game::spritePacks[9]->drawAnimFrame(this->screenGraphics, 5, this->sparkleFrame, Tables::medallionPieceOffsets[world << 1] + 120 - 12, Tables::medallionPieceOffsets[(world << 1) + 1] + 124, 0, 0, 0);
		this->sparkleFrame = this->sparkleFrame + 1;
		return 0;
	}
	if (this->gemFlashCounter % 2 == 1) {
		flashColorStep = 838860;
		this->screenGraphics->setColor(0 + flashColorStep * this->gemFlashCounter);
		this->screenGraphics->fillRect(0, 0, 240, 320);
	}
	this->gemFlashCounter = this->gemFlashCounter + 1;
	return 0;
}

void Game::drawCheatScreen() {
	Ref<String> valueText;
	Ref<SpritePack> font;
	int32_t row = 0, labelStringId = 0, y = 0;
	Ref<Object> s0, s1;
	valueText = nullptr;
	font = Game::spritePacks[41];
	font->lineSpacing = 15;
	this->screenGraphics->setColor(0);
	this->screenGraphics->fillRect(0, 0, 240, 320);
	for (row = 0; row < 6; row++) {
		labelStringId = -1;
		switch (row) {
			case 5:
				labelStringId = -1;
				s0 = u"5 to activate lang cheat"_j;
				valueText = cast<String>(s0);
				break;
			case 4:
				labelStringId = 64;
				s0 = jnew<StringBuffer>()->append(u" 0 - "_j)->append(Game::langStrings[!this->cheatUnlockSecretStages ? 67 : 66])->toString();
				valueText = cast<String>(s0);
				break;
			case 3:
				labelStringId = 63;
				s0 = jnew<StringBuffer>()->append(u" 9 - "_j)->append(Game::langStrings[!this->cheatUnlockAllStages ? 67 : 66])->toString();
				valueText = cast<String>(s0);
				break;
			case 2:
				labelStringId = 62;
				s0 = jnew<StringBuffer>()->append(u" 8 - x "_j)->append(String::valueOf(this->cheatWeaponFlags))->append(this->cheatWeaponFlags < 4 ? u""_j : u" blue potion"_j)->toString();
				valueText = cast<String>(s0);
				break;
			case 1:
				labelStringId = 61;
				s0 = jnew<StringBuffer>()->append(u" 7 - Add "_j)->append(String::valueOf(this->redDiamondCount))->toString();
				valueText = cast<String>(s0);
				break;
			case 0:
				labelStringId = 60;
				s0 = jnew<StringBuffer>()->append(u" 6 - Add "_j)->append(String::valueOf(this->diamondCount))->toString();
				valueText = cast<String>(s0);
				break;
			default:
				break;
		}
		y = row * 35;
		if (labelStringId >= 0) {
			font->drawString(this->screenGraphics, Game::langStrings[labelStringId], 110, y, 17);
		}
		y = y + font->lineSpacing;
		font->drawString(this->screenGraphics, Game::langStrings[65], 110, y, 24);
		font->drawString(this->screenGraphics, valueText, 110, y, 20);
	}
	valueText = u"Pound - Pass levels "_j;
	if (!this->cheatPassLevels) {
		s0 = jnew<StringBuffer>()->append(valueText);
		s1 = u"off"_j;
	} else {
		s0 = jnew<StringBuffer>()->append(valueText);
		s1 = u"on"_j;
	}
	valueText = cast<StringBuffer>(s0)->append(cast<String>(s1))->toString();
	font->drawString(this->screenGraphics, valueText, 110, 290, 17);
	this->drawBackSoftkeyIcon();
	this->drawSelectSoftkeyIcon();
}

void Game::drawTextViewerScreen() {
	Ref<String> pageTitle;
	Ref<SpritePack> font;
	font = Game::spritePacks[41];
	font->lineSpacing = 2;
	this->screenGraphics->setColor(0);
	this->screenGraphics->fillRect(0, 0, 240, 320);
	switch (this->debugTextPage) {
		default:
			pageTitle = u""_j;
			break;
		case 1:
			pageTitle = u"Tips"_j;
			Game::loadTipPage(this->debugTextIndices[1]);
			this->drawTipPage();
			break;
		case 0:
			pageTitle = u"Mix"_j;
			font->drawMultilineString(this->screenGraphics, Game::langStrings[this->debugTextIndices[0]], 10, 5, 20);
			break;
	}
	font->lineSpacing = 2;
	font->drawString(this->screenGraphics, pageTitle, 40, 308, 20);
	font->drawString(this->screenGraphics, jnew<StringBuffer>()->append(u""_j)->append(this->debugTextIndices[this->debugTextPage])->toString(), 120, 308, 20);
	font->drawMultilineString(this->screenGraphics, u"Use up, down, left and right to navigate"_j, 10, 280, 20);
	this->drawBackSoftkeyIcon();
	this->drawSelectSoftkeyIcon();
}

void Game::drawMainMenuScreen() {
	this->drawMenu();
}

void Game::drawTitleBackground(Ref<Graphics> g, bool showBottomImage) {
	g->drawImage(Game::titleBackgroundImage, 0, 0, 20);
	g->drawImage(Game::titleLogoImage, 0, 0, 20);
	if (showBottomImage != 0) {
		g->drawImage(Game::titleBottomImage, 120, 319, 33);
	}
}

void Game::drawGameOverScreen() {
	Ref<SpritePack> font;
	Ref<String> lostText;
	Ref<Object> s0, s1, s2;
	int32_t s3 = 0, s4 = 0, s5 = 0;
	this->screenGraphics->setColor(0);
	this->screenGraphics->fillRect(0, 0, 240, 320);
	font = Game::spritePacks[41];
	font->drawString(this->screenGraphics, Game::langStrings[35], 120, 50, 17);
	if (this->specialStageType != 2) {
		font->drawString(this->screenGraphics, Game::langStrings[1], 0, 320, 36);
		lostText = jnew<StringBuffer>(Game::langStrings[111])->append(u" "_j)->append(Game::readU16LE(Game::saveData, 4) >= 500 ? 500 : Game::readU16LE(Game::saveData, 4))->append(u" "_j)->append(Game::langStrings[109])->toString();
		s0 = font;
		s1 = this->screenGraphics;
		s2 = lostText;
		s3 = 120;
		s4 = 160;
		s5 = 17;
	} else {
		s0 = font;
		s1 = this->screenGraphics;
		s2 = Game::langStrings[26];
		s3 = 0;
		s4 = 320;
		s5 = 36;
	}
	cast<SpritePack>(s0)->drawString(cast<Graphics>(s1), cast<String>(s2), s3, s4, s5);
	this->paintExplorer();
}

void Game::paintLevelBuffer(Ref<Graphics> g) {
	int32_t srcLeft = 0, srcTop = 0, srcRight = 0, srcBottom = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0;
	Ref<Object> s0;
	Ref<Graphics> t1;
	srcLeft = irem(this->camX, Game::bufW);
	srcTop = irem(this->camY, Game::bufH);
	srcRight = irem(this->camX + 240, Game::bufW);
	srcBottom = irem(this->camY + 240, Game::bufH);
	if (srcRight <= srcLeft) {
		if (srcBottom <= srcTop) {
			Game::blitLevelBuffer(g, srcLeft, srcTop, 0, 0);
			Game::blitLevelBuffer(g, srcLeft, 0, 0, 240 - srcBottom);
			Game::blitLevelBuffer(g, 0, srcTop, 240 - srcRight, 0);
			s0 = g;
			s1 = 0;
			s2 = 0;
			s3 = 240 - srcRight;
			t1 = cast<Graphics>(s0);
			s0 = t1;
			s4 = 240 - srcBottom;
		} else {
			Game::blitLevelBuffer(g, srcLeft, srcTop, 0, 0);
			s0 = g;
			s1 = 0;
			s2 = srcTop;
			s3 = 240 - srcRight;
			s4 = 0;
		}
	} else {
		{
			if (srcBottom <= srcTop) {
				Game::blitLevelBuffer(g, srcLeft, srcTop, 0, 0);
				s0 = g;
				s1 = srcLeft;
				s2 = 0;
				s3 = 0;
				t1 = cast<Graphics>(s0);
				s0 = t1;
				s4 = 240 - srcBottom;
				goto B3_end;
			}
			s0 = g;
			s1 = srcLeft;
			s2 = srcTop;
			s3 = 0;
			s4 = 0;
		}
		B3_end:;
	}
	Game::blitLevelBuffer(cast<Graphics>(s0), s1, s2, s3, s4);
}

void Game::blitLevelBuffer(Ref<Graphics> g, int32_t srcX, int32_t srcY, int32_t destX, int32_t destY) {
	g->drawImage(Game::levelBufferImage, destX - srcX, destY - srcY, 0);
}

void Game::createLevelBuffer() {
	Game::bufW = 264;
	Game::bufH = 264;
	Game::levelBufferImage = Image::createImage(Game::bufW, Game::bufH);
	Game::levelBufferGraphics = Game::levelBufferImage->getGraphics();
}

void Game::eraseCellInBuffer(int32_t col, int32_t row) {
	int32_t terrain = 0, bufLeft = 0, bufTop = 0, bufRight = 0, bufBottom = 0, cellX = 0, cellY = 0, objectType = 0;
	bufLeft = this->camX - this->camX % 24;
	bufTop = this->camY - this->camY % 24;
	bufRight = this->camX + Game::bufW - 24 - (this->camX + Game::bufW - 24) % 24;
	bufBottom = this->camY + Game::bufH - 24 - (this->camY + Game::bufH - 24) % 24;
	cellX = col * 24;
	cellY = row * 24;
	if (cellX >= bufLeft && cellX <= bufRight && cellY >= bufTop && cellY <= bufBottom) {
		objectType = Game::cellObjects[col][row] & 255;
		terrain = Game::cellTypes[col][row];
		if (terrain < 80) {
			if (objectType == 4 || objectType == 16 || objectType == 15) {
				this->redrawCellInBuffer(col, row);
				return;
			}
			Game::levelBufferGraphics->drawImage(Game::objectFrameImages[8][0], irem(cellX, Game::bufW), irem(cellY, Game::bufH), 0);
		}
	}
}

void Game::redrawCellInBuffer(int32_t col, int32_t row) {
	int32_t bufLeft = 0, bufTop = 0, bufRight = 0, bufBottom = 0, cellX = 0, cellY = 0;
	bufLeft = this->camX - this->camX % 24;
	bufTop = this->camY - this->camY % 24;
	bufRight = this->camX + Game::bufW - 24 - (this->camX + Game::bufW - 24) % 24;
	bufBottom = this->camY + Game::bufH - 24 - (this->camY + Game::bufH - 24) % 24;
	cellX = col * 24;
	cellY = row * 24;
	if (cellX >= bufLeft && cellX <= bufRight && cellY >= bufTop && cellY <= bufBottom) {
		this->renderCellsToBuffer(cellX, cellY, cellX, cellY, 0);
	}
}

int32_t Game::getSpritePackForImageSet(int32_t imageSet) {
	switch (imageSet) {
		default:
			return -1;
		case 23:
			Game::spritePacks[45]->paletteIndex = 1;
			return 45;
		case 22:
			Game::spritePacks[45]->paletteIndex = 0;
			return 45;
		case 20:
			return 43;
		case 16:
			return 58;
		case 15:
			Game::spritePacks[57]->paletteIndex = 0;
			return 57;
		case 14:
			Game::spritePacks[57]->paletteIndex = 1;
			return 57;
		case 4:
			return 56;
		case 3:
			Game::spritePacks[59]->paletteIndex = 1;
			return 59;
		case 2:
			Game::spritePacks[59]->paletteIndex = 0;
			return 59;
		case 1:
			return 60;
		case 0:
			return 42;
	}
}

void Game::renderCellsToBuffer(int32_t left, int32_t top, int32_t right, int32_t bottom, bool objectsOnly) {
	int32_t bufStartY = 0, y = 0, x = 0, wallFrame = 0, bufWidth = 0, bufHeight = 0, bufStartX = 0, s1 = 0;
	Ref<Graphics> g;
	g = nullptr;
	bufStartX = 0;
	bufStartY = 0;
	g = Game::levelBufferGraphics;
	bufWidth = Game::bufW;
	bufHeight = Game::bufH;
	bufStartX = irem(left, bufWidth);
	bufStartY = irem(top, bufHeight);
	this->cellDrawY = bufStartY - 24;
	this->paintCellRow = top / 24 - 1;
	for (y = top; y <= bottom; y += 24) {
		this->cellDrawX = bufStartX - 24;
		this->paintCellCol = left / 24 - 1;
		this->cellDrawY = this->cellDrawY + 24;
		this->paintCellRow = this->paintCellRow + 1;
		if (this->cellDrawY >= bufHeight) {
			this->cellDrawY = 0;
		}
		for (x = left; x <= right; x += 24) {
			this->cellDrawX = this->cellDrawX + 24;
			this->paintCellCol = this->paintCellCol + 1;
			if (this->cellDrawX >= bufWidth) {
				this->cellDrawX = 0;
			}
			if (this->paintCellCol >= 0 && this->paintCellCol < this->levelW && this->paintCellRow >= 0) {
				if (this->paintCellRow < this->levelH) {
					this->paintCellTerrain = Game::cellTypes[this->paintCellCol][this->paintCellRow];
					this->paintCellObject = Game::cellObjects[this->paintCellCol][this->paintCellRow] & 255;
					if (this->paintCellTerrain < 80 && objectsOnly == 0) {
						g->drawImage(Game::objectFrameImages[8][0], this->cellDrawX, this->cellDrawY, 0);
					}
					if (this->paintCellObject > -1 && this->paintCellObject < 38) {
						switch (this->paintCellObject) {
							case 27:
								this->objectSpriteSet = 21;
								this->objectSpriteFrame = 0;
								this->cellDrawOffsetY = 0;
								this->cellDrawOffsetX = 0;
								break;
							case 16:
								if (this->switchWallsPhase == 9) {
									this->objectSpriteSet = 15;
									this->objectSpriteFrame = 4 - this->switchWallsPhase * 5 / 10;
									if (this->objectSpriteFrame < 0) {
										s1 = 0;
										cast<Game>(this)->objectSpriteFrame = s1;
									}
								}
								break;
							case 15:
								if (this->switchWallsPhase == 0) {
									this->objectSpriteSet = 14;
									s1 = 0 + this->switchWallsPhase * 5 / 10;
									cast<Game>(this)->objectSpriteFrame = s1;
								}
								break;
							case 4:
								this->objectSpriteSet = 20;
								this->objectSpriteFrame = 7;
								this->cellDrawOffsetY = 0;
								this->cellDrawOffsetX = 0;
								break;
							default:
								break;
						}
					}
					if (this->objectSpriteSet != -1) {
						if (Game::objectFrameImages[this->objectSpriteSet] != nullptr) {
							g->drawImage(Game::objectFrameImages[this->objectSpriteSet][this->objectSpriteFrame], this->cellDrawX + this->cellDrawOffsetX, this->cellDrawY + this->cellDrawOffsetY, this->cellDrawAnchor);
						} else {
							Game::spritePacks[Game::getSpritePackForImageSet(this->objectSpriteSet)]->drawFrame(g, this->objectSpriteFrame, this->cellDrawX + this->cellDrawOffsetX, this->cellDrawY + this->cellDrawOffsetY, this->cellDrawAnchor, 0, 0);
						}
						this->cellDrawAnchor = 0;
						this->objectSpriteSet = -1;
						this->cellDrawOffsetY = 0;
						this->cellDrawOffsetX = 0;
					}
					if (this->paintCellTerrain != -1 && objectsOnly == 0) {
						wallFrame = (int8_t)(this->paintCellTerrain - 80);
						if (wallFrame < 0) {
							switch (this->paintCellTerrain) {
								case 35:
									if (this->switchWallsPhase == 0) {
										this->terrainSpriteSet = 15;
										this->terrainSpriteFrame = 4 - this->switchWallsPhase * 5 / 10;
										if (this->terrainSpriteFrame < 0) {
											s1 = 0;
											cast<Game>(this)->terrainSpriteFrame = s1;
										}
									}
									break;
								case 34:
									if (this->switchWallsPhase == 9) {
										this->terrainSpriteSet = 14;
										s1 = 0 + this->switchWallsPhase * 5 / 10;
										cast<Game>(this)->terrainSpriteFrame = s1;
									}
									break;
								case 10:
									Game::spritePacks[16]->drawFrame(g, 0, this->cellDrawX, this->cellDrawY, 0, 0, 0);
									break;
								case 1:
									if (Game::cellMoveOffsets[this->paintCellCol][this->paintCellRow] == 0 && (Game::liquidCells == nullptr || Game::liquidCells[this->paintCellCol][this->paintCellRow] == 0)) {
										this->prepareLooseObjectSprite();
										this->terrainSpriteFrame = this->terrainSpriteFrame - this->sparklePhase;
										this->cellDrawOffsetY = 0;
									}
									break;
								case 0:
									if (Game::cellMoveOffsets[this->paintCellCol][this->paintCellRow] == 0 && (Game::liquidCells == nullptr || Game::liquidCells[this->paintCellCol][this->paintCellRow] == 0)) {
										this->prepareLooseObjectSprite();
									}
									break;
								default:
									break;
							}
						} else {
							this->terrainSpriteSet = 0;
							s1 = wallFrame;
							cast<Game>(this)->terrainSpriteFrame = s1;
						}
						if (this->terrainSpriteSet != -1) {
							if (Game::objectFrameImages[this->terrainSpriteSet] != nullptr) {
								g->drawImage(Game::objectFrameImages[this->terrainSpriteSet][this->terrainSpriteFrame], this->cellDrawX + this->cellDrawOffsetX, this->cellDrawY + this->cellDrawOffsetY, this->cellDrawAnchor);
							} else {
								Game::spritePacks[Game::getSpritePackForImageSet(this->terrainSpriteSet)]->drawFrame(g, this->terrainSpriteFrame, this->cellDrawX + this->cellDrawOffsetX, this->cellDrawY + this->cellDrawOffsetY, this->cellDrawAnchor, 0, 0);
							}
							this->terrainSpriteSet = -1;
							this->cellDrawAnchor = 0;
							this->cellDrawOffsetY = 0;
							this->cellDrawOffsetX = 0;
						}
					}
					if (this->specialStageType == 2) {
						this->paintIntroStageCellOverlay(g);
					}
				}
			}
		}
	}
}

void Game::paintObjects(Ref<Graphics> g) {
	int32_t rowOffset = 0, colOffset = 0, frame = 0, cellState = 0;
	for (rowOffset = -1; rowOffset < 12; rowOffset++) {
		for (colOffset = -1; colOffset < 12; colOffset++) {
			this->paintCellCol = colOffset + this->camCellX;
			this->paintCellRow = rowOffset + this->camCellY;
			if (this->paintCellCol >= 0 && this->paintCellCol < this->levelW && this->paintCellRow >= 0) {
				if (this->paintCellRow < this->levelH) {
					this->paintCellTerrain = Game::cellTypes[this->paintCellCol][this->paintCellRow];
					this->paintCellObject = Game::cellObjects[this->paintCellCol][this->paintCellRow] & 255;
					this->cellDrawX = colOffset * 24 - this->camOffX;
					this->cellDrawY = rowOffset * 24 - this->camOffY;
					this->clipToPlayfield();
					if (this->paintCellObject > -1 && this->paintCellObject < 38) {
						switch (this->paintCellObject) {
							case 37:
								Game::spritePacks[27]->drawAnimFrame(g, 2, 0, this->cellDrawX, this->cellDrawY, 0, 0, 0);
								cast<Game>(this)->prepareWindSprite();
								break;
							case 35:
								cast<Game>(this)->prepareWindSprite();
								break;
							case 34:
								Game::spritePacks[27]->drawAnimFrame(g, 2, 0, this->cellDrawX, this->cellDrawY, 0, 0, 0);
								break;
							case 16:
								if (this->switchWallsPhase != 9 && this->switchWallsPhase >= 5) {
									this->objectSpriteSet = 15;
									this->objectSpriteFrame = 4 - this->switchWallsPhase * 5 / 10;
									if (this->objectSpriteFrame < 0) {
										this->objectSpriteFrame = 0;
									}
								}
								break;
							case 15:
								if (this->switchWallsPhase != 0 && this->switchWallsPhase <= 5) {
									this->objectSpriteSet = 14;
									this->objectSpriteFrame = 0 + this->switchWallsPhase * 5 / 10;
								}
								break;
							case 14:
							case 33:
								this->drawChest(this->paintCellObject);
								break;
							case 8:
							case 9:
								this->prepareKeyDoorSprite();
								break;
							case 7:
								this->prepareDoorBaseSprite();
								break;
							case 6:
								this->preparePressurePlateSprite();
								if (this->cellDrawY + 24 < 240) {
									g->clipRect(this->cellDrawX, this->cellDrawY, 24, 24);
								}
								break;
							case 5:
							case 28:
								this->objectSpriteSet = 11;
								this->objectSpriteFrame = 0;
								break;
							case 4:
								if (Game::cellObjects[this->paintCellCol][this->paintCellRow] >> 8 >= this->nextCheckpointIndex) {
									this->prepareCheckpointStarSprite();
								}
								break;
							case 3:
								frame = (Game::cellObjects[this->paintCellCol][this->paintCellRow] >> 8) - 1;
								if (frame >= 0) {
									this->objectSpriteSet = 12;
									this->objectSpriteFrame = (int8_t)frame;
								}
								break;
							default:
								break;
						}
						if (this->objectSpriteSet == -1) {
							if (Game::curObjectSprites != nullptr) {
								if (this->cellAnimIndex != -1) {
									Game::curObjectSprites->drawAnimFrame(g, this->cellAnimIndex, this->cellAnimFrame, this->cellDrawX + this->cellDrawOffsetX, this->cellDrawY + this->cellDrawOffsetY, 0, 0, 0);
									this->cellAnimIndex = -1;
								}
								Game::curObjectSprites = nullptr;
								this->cellDrawOffsetY = 0;
								this->cellDrawOffsetX = 0;
							}
						} else {
							if (Game::objectFrameImages[this->objectSpriteSet] != nullptr) {
								g->drawImage(Game::objectFrameImages[this->objectSpriteSet][this->objectSpriteFrame], this->cellDrawX + this->cellDrawOffsetX, this->cellDrawY + this->cellDrawOffsetY, this->cellDrawAnchor);
							} else {
								Game::spritePacks[Game::getSpritePackForImageSet(this->objectSpriteSet)]->drawFrame(g, this->objectSpriteFrame, this->cellDrawX + this->cellDrawOffsetX, this->cellDrawY + this->cellDrawOffsetY, this->cellDrawAnchor, 0, 0);
							}
							this->cellDrawAnchor = 0;
							this->objectSpriteSet = -1;
							g->setClip(0, -this->shake, 240, 240);
							this->cellDrawOffsetY = 0;
							this->cellDrawOffsetX = 0;
						}
					}
					if (this->paintCellTerrain != -1) {
						frame = (int8_t)(this->paintCellTerrain - 80);
						if (frame < 0) {
							cellState = Game::cellStates[this->paintCellCol][this->paintCellRow];
							switch (this->paintCellTerrain) {
								case 49:
									this->prepareEnemy49Sprite();
									break;
								case 48:
									this->prepareFreezeEmitterSprite();
									break;
								case 47:
									cast<Game>(this)->prepareLooseObjectSprite();
									break;
								case 46:
									this->prepareStaffMonkeySprite();
									break;
								case 45:
									this->prepareHopperSprite();
									break;
								case 44:
									this->prepareIcicleSprite();
									this->cellAnimFrame = 0;
									break;
								case 43:
									this->prepareSnakeSprite((int8_t)this->paintCellTerrain);
									break;
								case 37:
									this->terrainSpriteSet = 17;
									this->terrainSpriteFrame = 0 + (cellState - 1) * 3 / 8;
									break;
								case 36:
									this->prepareFloorTrapSprite();
									break;
								case 35:
									if (this->switchWallsPhase != 0 && this->switchWallsPhase <= 5) {
										this->terrainSpriteSet = 15;
										this->terrainSpriteFrame = 4 - this->switchWallsPhase * 5 / 10;
										if (this->terrainSpriteFrame < 0) {
											this->terrainSpriteFrame = 0;
										}
									}
									break;
								case 34:
									if (this->switchWallsPhase != 9 && this->switchWallsPhase >= 5) {
										this->terrainSpriteSet = 14;
										this->terrainSpriteFrame = 0 + this->switchWallsPhase * 5 / 10;
									}
									break;
								case 32:
									this->drawExtendingRod();
									break;
								case 30:
									Game::curObjectSprites = Game::spritePacks[20];
									this->cellAnimIndex = 0;
									this->cellAnimFrame = 0 + (cellState - 1) * 7 / 16;
									break;
								case 28:
									this->drawPistonTrap();
									break;
								case 23:
									Game::curObjectSprites = Game::spritePacks[12];
									this->cellAnimFrame = 0;
									this->drawStatueFlame(23);
									break;
								case 22:
									Game::curObjectSprites = Game::spritePacks[12];
									this->cellAnimFrame = 1;
									this->drawStatueFlame(22);
									break;
								case 21:
									this->prepareProjectileSprite();
									break;
								case 19:
									this->prepareSnakeSprite((int8_t)this->paintCellTerrain);
									break;
								case 18:
									this->prepareLeverSprite();
									break;
								case 16:
									this->prepareTallTrapSprite();
									break;
								case 14:
									this->prepareRollerSprite();
									break;
								case 12:
									this->drawExitPadlockAtCell();
									break;
								case 11:
									this->prepareWallCrawlerSprite();
									break;
								case 10:
									break;
								case 9:
									this->prepareLooseObjectSprite();
									if ((Game::cellStates[this->paintCellCol][this->paintCellRow] & 264241152) == 138412032) {
										this->cellDrawOffsetX = this->cellDrawOffsetX + this->frozenShakeX;
										this->cellDrawOffsetY = this->cellDrawOffsetY + this->frozenShakeY;
									}
									break;
								case 7:
									break;
								case 6:
									break;
								case 5:
									break;
								case 4:
									break;
								case 2:
									break;
								case 1:
									if ((Game::cellStates[this->paintCellCol][this->paintCellRow] & INT32_MIN) != 0 || this->sparklePhase != 0) {
										cast<Game>(this)->prepareLooseObjectSprite();
									}
									break;
								case 0:
									if ((Game::cellStates[this->paintCellCol][this->paintCellRow] & INT32_MIN) != 0) {
										cast<Game>(this)->prepareLooseObjectSprite();
									}
									break;
								case 8:
									cast<Game>(this)->prepareLooseObjectSprite();
									break;
								default:
									break;
							}
						}
						if (this->terrainSpriteSet == -1) {
							if (Game::curObjectSprites != nullptr) {
								if (this->paintCellCol == this->killerCol && this->paintCellRow == this->killerRow) {
									Game::killerSprites = Game::curObjectSprites;
									this->killerAnim = this->cellAnimIndex;
									this->killerFrame = this->cellAnimFrame;
									this->killerDrawX = this->cellDrawX + this->cellDrawOffsetX;
									this->killerDrawY = this->cellDrawY + this->cellDrawOffsetY;
								}
								if (this->cellAnimIndex == -1) {
									Game::curObjectSprites->drawFrame(g, this->cellAnimFrame, this->cellDrawX + this->cellDrawOffsetX, this->cellDrawY + this->cellDrawOffsetY, this->cellDrawFlip, 0, 0);
								} else {
									Game::curObjectSprites->drawAnimFrame(g, this->cellAnimIndex, this->cellAnimFrame, this->cellDrawX + this->cellDrawOffsetX, this->cellDrawY + this->cellDrawOffsetY, this->cellDrawFlip, 0, 0);
									this->cellAnimIndex = -1;
								}
								Game::curObjectSprites = nullptr;
								this->cellDrawFlip = 0;
								this->cellDrawOffsetY = 0;
								this->cellDrawOffsetX = 0;
							}
						} else {
							if (Game::objectFrameImages[this->terrainSpriteSet] != nullptr) {
								g->drawImage(Game::objectFrameImages[this->terrainSpriteSet][this->terrainSpriteFrame], this->cellDrawX + this->cellDrawOffsetX, this->cellDrawY + this->cellDrawOffsetY, this->cellDrawAnchor);
							} else {
								Game::spritePacks[Game::getSpritePackForImageSet(this->terrainSpriteSet)]->drawFrame(g, this->terrainSpriteFrame, this->cellDrawX + this->cellDrawOffsetX, this->cellDrawY + this->cellDrawOffsetY, this->cellDrawAnchor, 0, 0);
							}
							this->terrainSpriteSet = -1;
							this->cellDrawAnchor = 0;
							this->cellDrawOffsetY = 0;
							this->cellDrawOffsetX = 0;
						}
					}
				}
			}
		}
	}
}

void Game::clipToPlayfield() {
	this->screenGraphics->setClip(0, 0, 240, 240);
}

void Game::paintPlayfield() {
	Ref<Graphics> g;
	int32_t screenX = 0, screenY = 0, frameIndex = 0, animIndex = 0, animFrame = 0, wallFrame = 0, frame = 0, leftOrRow = 0, topOrCol = 0, rightOrObject = 0, bottomOrTerrain_n = 0, fromOrCol = 0, toOrRow = 0, s0_n = 0, s2 = 0, s3 = 0;
	Ref<SpritePack> pack, bottomOrTerrain;
	Ref<Object> s0, s1_o;
	g = this->screenGraphics;
	frame = Game::frameCount;
	this->explorerDrawMoveDir = (this->explorerStateFlags & 4096) != 0 ? 0 : this->currentMoveDir;
	g->translate(0, 40);
	this->shake = 0;
	this->clipToPlayfield();
	if (this->shakeTime > 0) {
		this->shake = irem(this->shakeTime * frame, (this->shakeTime >> 1) + 1) % 12;
	}
	if (this->shake > this->camY) {
		this->shake = this->camY;
	}
	this->camY = this->camY - this->shake;
	this->camCellX = this->camX / 24;
	this->camCellY = this->camY / 24;
	this->camOffX = this->camX % 24;
	this->camOffY = this->camY % 24;
	this->sparklePhase = (frame & 63) >> 1;
	if (this->sparklePhase >= 4) {
		this->sparklePhase = 0;
	}
	leftOrRow = this->camX - this->camOffX;
	topOrCol = this->camY - this->camOffY;
	rightOrObject = this->camX + Game::bufW - 24 - (this->camX + Game::bufW - 24) % 24;
	bottomOrTerrain_n = this->camY + Game::bufH - 24 - (this->camY + Game::bufH - 24) % 24;
	if (Game::bufLeftX == -1) {
		this->renderCellsToBuffer(leftOrRow, topOrCol, rightOrObject, bottomOrTerrain_n, 0);
		Game::bufLeftX = leftOrRow;
		Game::bufRightX = rightOrObject;
		Game::bufTopY = topOrCol;
		Game::bufBottomY = bottomOrTerrain_n;
	}
	if (Game::bufLeftX != leftOrRow) {
		if (Game::bufLeftX >= leftOrRow) {
			fromOrCol = leftOrRow;
			s0_n = Game::bufLeftX - 24;
		} else {
			fromOrCol = Game::bufRightX + 24;
			s0_n = rightOrObject;
		}
		toOrRow = s0_n;
		this->renderCellsToBuffer(fromOrCol, topOrCol, toOrRow, bottomOrTerrain_n, 0);
		Game::bufLeftX = leftOrRow;
		Game::bufRightX = rightOrObject;
	}
	if (Game::bufTopY != topOrCol) {
		if (Game::bufTopY >= topOrCol) {
			fromOrCol = topOrCol;
			s0_n = Game::bufTopY - 24;
		} else {
			fromOrCol = Game::bufBottomY + 24;
			s0_n = bottomOrTerrain_n;
		}
		toOrRow = s0_n;
		this->renderCellsToBuffer(leftOrRow, fromOrCol, rightOrObject, toOrRow, 0);
		Game::bufTopY = topOrCol;
		Game::bufBottomY = bottomOrTerrain_n;
	}
	this->paintLevelBuffer(g);
	this->clipToPlayfield();
	this->paintObjects(g);
	if (!Game::itemRaiseFreeze) {
		this->paintExplorer();
		if (this->hasWaterLayer) {
			this->drawLiquidLayer(this->camOffX, this->camOffY);
		}
		if (Game::playfieldOverlayImage != nullptr) {
			g->drawImage(Game::playfieldOverlayImage, Game::overlayImageX, Game::overlayImageY, Game::overlayImageAnchor);
		}
		if (this->freezeRayCount > 0) {
			this->drawFreezeRays();
		}
		if (this->specialStageType != 0) {
			this->paintSpecialStageExtras();
		}
		for (leftOrRow = -1; leftOrRow < 12; leftOrRow++) {
			for (topOrCol = -1; topOrCol < 12; topOrCol++) {
				fromOrCol = topOrCol + this->camCellX;
				toOrRow = leftOrRow + this->camCellY;
				if (fromOrCol >= 0 && fromOrCol < this->levelW && toOrRow >= 0) {
					if (toOrRow < this->levelH) {
						rightOrObject = Game::cellObjects[fromOrCol][toOrRow] & 255;
						bottomOrTerrain_n = Game::cellTypes[fromOrCol][toOrRow];
						if (rightOrObject < 38 || rightOrObject >= 80) {
							screenX = topOrCol * 24 - this->camOffX;
							screenY = leftOrRow * 24 - this->camOffY;
							if (rightOrObject < 20 || rightOrObject >= 26) {
								switch (rightOrObject) {
									default:
										wallFrame = (int8_t)(rightOrObject - 80);
										if (wallFrame >= 0) {
											Game::spritePacks[42]->drawFrame(g, wallFrame, screenX, screenY, 0, 0, 0);
										}
										break;
									case 36:
										frameIndex = (Game::cellObjects[fromOrCol][toOrRow] >> 8) - 1;
										frameIndex = (0 + frameIndex * 7) / 16;
										Game::spritePacks[20]->drawAnimFrame(g, 0, frameIndex, screenX, screenY, 0, 0, 0);
										break;
									case 32:
										Game::spritePacks[16]->drawAnimFrame(this->screenGraphics, 0, Game::cellObjects[fromOrCol][toOrRow] >> 8 & 255, screenX, screenY, 0, 0, 0);
										break;
									case 31:
										animIndex = Game::cellObjects[fromOrCol][toOrRow] >> 8;
										pack = Game::spritePacks[15];
										animFrame = irem(Game::frameCount >> 1, pack->animFrameCounts[animIndex] & 255);
										pack->drawAnimFrame(this->screenGraphics, animIndex, animFrame, screenX, screenY, 0, 0, 0);
										break;
								}
								frameIndex = (Game::cellObjects[fromOrCol][toOrRow] & -268435456) >> 28;
								if (frameIndex > 0) {
									s0 = Game::spritePacks[13];
									s1_o = g;
									s2 = 0;
									s3 = frameIndex;
									cast<SpritePack>(s0)->drawAnimFrame(cast<Graphics>(s1_o), s2, s3, screenX, screenY, 0, 0, 0);
								}
							} else {
								frameIndex = rightOrObject - 20;
								s0 = Game::spritePacks[3];
								s1_o = g;
								s2 = frameIndex;
								s3 = irem(frame >> 2, Game::spritePacks[3]->animFrameCounts[frameIndex] & 255);
								cast<SpritePack>(s0)->drawAnimFrame(cast<Graphics>(s1_o), s2, s3, screenX, screenY, 0, 0, 0);
							}
							if (bottomOrTerrain_n == 54) {
								Game::spritePacks[7]->drawAnimFrame(g, 0, Game::frameAtTime(Game::spritePacks[7], 0, Game::cellStates[fromOrCol][toOrRow]), screenX, screenY, 0, 0, 0);
							}
						}
					}
				}
			}
		}
		if (this->hasLandingDust) {
			leftOrRow = (this->landingDustCol - this->camCellX) * 24 - this->camOffX + this->landingDustOffX;
			topOrCol = (this->landingDustRow - this->camCellY + 1) * 24 - this->camOffY + this->landingDustOffY;
			g->drawImage(Game::spritePacks[13]->moduleImages[0][0 + this->landingDustFrame], leftOrRow, topOrCol, 0);
			this->hasLandingDust = 0;
		}
		if (this->hintBubbleImageSet != -1) {
			g->drawImage(Game::objectFrameImages[13][0], this->explorerScreenX - 12, this->explorerScreenY - 24 + 2, 3);
			g->drawImage(Game::objectFrameImages[this->hintBubbleImageSet][this->hintBubbleFrame], this->explorerScreenX - 12, this->explorerScreenY - 24, 3);
		}
		if (this->effectQueueHead != this->effectQueueTail) {
			s0_n = this->effectQueueHead;
			while (true) {
				leftOrRow = s0_n;
				if (leftOrRow == this->effectQueueTail) {
					break;
				}
				topOrCol = Game::effectCells[leftOrRow << 1] * 24 - this->camX;
				rightOrObject = Game::effectCells[(leftOrRow << 1) + 1] * 24 - this->camY;
				if (Game::effectAnims[leftOrRow] >= 0) {
					s0 = Game::spritePacks[9];
					s1_o = g;
					s2 = Game::effectAnims[leftOrRow];
					s3 = Game::effectFrames[leftOrRow];
				} else {
					bottomOrTerrain = Game::spritePacks[2];
					s0 = bottomOrTerrain;
					s1_o = g;
					s2 = 0;
					s3 = Game::frameAtTime(bottomOrTerrain, 0, Game::effectFrames[leftOrRow]);
				}
				cast<SpritePack>(s0)->drawAnimFrame(cast<Graphics>(s1_o), s2, s3, topOrCol, rightOrObject, 0, 0, 0);
				leftOrRow++;
				s0_n = leftOrRow & 7;
			}
		}
		this->camY = this->camY + this->shake;
		if (this->isExitingLevel) {
			Game::drawTextInBox(g, Game::spritePacks[41], Game::langStrings[40], 120, 160, 17, 19, 0);
		}
		if (this->stageIntroEndFrame <= Game::frameCount || this->specialStageType == 2) {
			if (this->checkpointTextEndFrame <= Game::frameCount) {
				if (this->checkpointTextEndFrame == Game::frameCount) {
					if (this->checkpointMsgCount <= 2) {
						this->checkpointMsgCount = (int8_t)(this->checkpointMsgCount + 1);
						this->writeLivesToSave();
					}
				}
			} else {
				if (this->checkpointMsgCount <= 2) {
					Game::drawTextInBox(g, Game::spritePacks[41], Game::langStrings[36], 120, 230, 33, 20, 0);
				} else {
					if (this->checkpointTextEndFrame == Game::frameCount) {
						if (this->checkpointMsgCount <= 2) {
							this->checkpointMsgCount = (int8_t)(this->checkpointMsgCount + 1);
							this->writeLivesToSave();
						}
					}
				}
			}
		} else {
			if (!this->bossTreasureTaken && !this->gotElementalDiamond) {
				leftOrRow = this->stageIntroEndFrame - Game::frameCount;
				if (leftOrRow >= 20) {
					if (leftOrRow < 50) {
						s0_n = 120;
					} else {
						s0_n = (60 - leftOrRow) * 240 / 15;
					}
				} else {
					s0_n = (leftOrRow - 10) * 240 / 20;
				}
				topOrCol = s0_n;
				rightOrObject = 240 - topOrCol;
				Game::drawTextInBox(g, Game::spritePacks[41], Game::langStrings[Game::worldNameIds[this->world]], topOrCol, 15, 17, 20, 0);
				Game::drawTextInBox(g, Game::spritePacks[41], Game::langStrings[Game::stageNameIds[this->world][this->stage]], rightOrObject, 50, 17, 20, 0);
				if (this->diamondsToOpenExit > 0) {
					Game::drawTextInBox(g, Game::spritePacks[41], this->diamondsNeededText, 120, 190, 17, 5, 1);
				}
			}
		}
		switch (this->specialStageType) {
			case 5:
				if (this->bossState != -1 && this->bossState != 15 && this->bossState != 13 && this->bossState != 12) {
					s0 = this;
					s1_o = g;
					s2 = 4;
					cast<Game>(s0)->drawBossHealthBar(cast<Graphics>(s1_o), s2);
				}
				break;
			case 4:
				this->paintAnacondaHealthOrExplosion();
				break;
			case 3:
				if (this->bossState != -1 && this->bossState != 15) {
					s0 = this;
					s1_o = g;
					s2 = 5;
					cast<Game>(s0)->drawBossHealthBar(cast<Graphics>(s1_o), s2);
				}
				break;
			default:
				break;
		}
		g->translate(0, -40);
		g->setClip(0, 0, 240, 320);
		if (this->activeCutscene == nullptr) {
			this->drawHud();
		}
		if (this->hintText != nullptr) {
			this->hudNeedsRedraw = 1;
			Game::drawTextInBox(g, Game::spritePacks[41], this->hintText, 120, 263, 33, 4, 1);
		}
		if (this->activeCutscene != nullptr && !Game::itemRaiseFreeze) {
			this->hudNeedsRedraw = 1;
			this->activeCutscene->draw(g);
		}
		if (this->deathLetterboxHeight > 0) {
			this->hudNeedsRedraw = 1;
			g->setColor(0);
			g->fillRect(0, 0, 240, this->deathLetterboxHeight);
			g->fillRect(0, 320 - this->deathLetterboxHeight, 240, this->deathLetterboxHeight);
			g->translate(0, 40);
			this->paintExplorer();
			if (Game::playfieldOverlayImage != nullptr) {
				g->drawImage(Game::playfieldOverlayImage, Game::overlayImageX, Game::overlayImageY, Game::overlayImageAnchor);
			}
			if (Game::killerSprites != nullptr) {
				if (this->killerAnim == -1) {
					Game::killerSprites->drawFrame(g, this->killerFrame, this->killerDrawX, this->killerDrawY, this->cellDrawFlip, 0, 0);
				} else {
					Game::killerSprites->drawAnimFrame(g, this->killerAnim, this->killerFrame, (this->killerCol - this->camCellX) * 24 - this->camOffX, (this->killerRow - this->camCellY) * 24 - this->camOffY, this->cellDrawFlip, 0, 0);
				}
			}
			g->translate(0, -40);
		}
		return;
	}
	g->setColor(0);
	g->fillRect(0, 0, 240, 320);
	this->paintExplorer();
	if (Game::playfieldOverlayImage != nullptr) {
		g->drawImage(Game::playfieldOverlayImage, Game::overlayImageX, Game::overlayImageY, Game::overlayImageAnchor);
	}
	if (this->effectQueueHead != this->effectQueueTail) {
		s0_n = this->effectQueueHead;
		while (true) {
			leftOrRow = s0_n;
			if (leftOrRow == this->effectQueueTail) {
				break;
			}
			topOrCol = Game::effectCells[leftOrRow << 1] * 24 - this->camX;
			rightOrObject = Game::effectCells[(leftOrRow << 1) + 1] * 24 - this->camY;
			if (Game::effectAnims[leftOrRow] >= 0) {
				s0 = Game::spritePacks[9];
				s1_o = g;
				s2 = Game::effectAnims[leftOrRow];
				s3 = Game::effectFrames[leftOrRow];
			} else {
				bottomOrTerrain = Game::spritePacks[2];
				s0 = bottomOrTerrain;
				s1_o = g;
				s2 = 0;
				s3 = Game::frameAtTime(bottomOrTerrain, 0, Game::effectFrames[leftOrRow]);
			}
			cast<SpritePack>(s0)->drawAnimFrame(cast<Graphics>(s1_o), s2, s3, topOrCol, rightOrObject, 0, 0, 0);
			leftOrRow++;
			s0_n = leftOrRow & 7;
		}
	}
	this->screenGraphics->setClip(0, 0, 240, 320);
	g->translate(0, -40);
	this->drawHud();
}

void Game::drawFreezeRays() {
	int32_t viewTop = 0, leftCol = 0, rightCol = 0, leftX = 0, rightX = 0, startX = 0, neighbourCol = 0, leftEndFree = 0, endX = 0, rightEndFree = 0, lineY = 0, viewBottom = 0, viewLeft = 0, viewRight = 0, sparkFrame = 0, rayIndex = 0, rayYOffset = 0, rayRow = 0, rayY = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0;
	Ref<Object> s0_o, s1_o;
	viewTop = this->camY - 24;
	viewBottom = this->camY + 320;
	viewLeft = this->camX;
	viewRight = this->camX + 240;
	sparkFrame = irem(Game::frameCount >> 1, Game::spritePacks[2]->getAnimFrameCount(1));
	for (rayIndex = 0; rayIndex < Game::freezeRays->length; rayIndex += 3) {
		rayYOffset = 0;
		rayRow = Game::freezeRays[rayIndex + 2];
		rayY = rayRow * 24;
		if (rayY > viewTop && rayY < viewBottom) {
			leftCol = Game::freezeRays[rayIndex + 0];
			rightCol = Game::freezeRays[rayIndex + 1];
			leftX = leftCol * 24;
			rightX = rightCol * 24 + 24;
			if (leftX >= viewLeft && leftX <= viewRight || rightX >= viewLeft && rightX <= viewRight || leftX <= viewLeft && rightX >= viewRight) {
				startX = leftX - viewLeft;
				s0 = leftCol;
				s1 = leftCol == 0 ? 0 : -1;
				neighbourCol = s0 + s1;
				leftEndFree = 1;
				if (Game::cellTypes[neighbourCol][rayRow] == 48 && (Game::cellStates[neighbourCol][rayRow] & 8) != 0) {
					startX -= 12;
					leftEndFree = 0;
					if ((Game::cellStates[neighbourCol][rayRow + 1] & 7) != 3) {
						startX = startX - -Game::cellMoveOffsets[neighbourCol][rayRow + 1];
					} else {
						rayYOffset = -Game::cellMoveOffsets[neighbourCol][rayRow + 1];
					}
				}
				endX = rightX - viewLeft;
				s0 = rightCol;
				s1 = rightCol >= this->levelW - 1 ? 0 : 1;
				neighbourCol = s0 + s1;
				rightEndFree = 1;
				if (Game::cellTypes[neighbourCol][rayRow] == 48 && (Game::cellStates[neighbourCol][rayRow] & 8) != 0) {
					endX += 12;
					rightEndFree = 0;
					if ((Game::cellStates[neighbourCol][rayRow + 1] & 7) != 3) {
						endX = endX + -Game::cellMoveOffsets[neighbourCol][rayRow + 1];
					} else {
						rayYOffset = -Game::cellMoveOffsets[neighbourCol][rayRow + 1];
					}
				}
				lineY = rayY - this->camY + 10 + rayYOffset;
				this->screenGraphics->setColor(1820159);
				this->screenGraphics->drawLine(startX, lineY, endX, lineY);
				lineY += 2;
				this->screenGraphics->drawLine(startX, lineY, endX, lineY);
				lineY--;
				this->screenGraphics->setColor(14153215);
				this->screenGraphics->drawLine(startX, lineY, endX, lineY);
				if (leftEndFree == 0) {
					if (rightEndFree != 0) {
						s0_o = Game::spritePacks[2];
						s1_o = this->screenGraphics;
						s2 = 1;
						s3 = sparkFrame;
						s4 = endX;
						s5 = lineY;
						s6 = 0;
						cast<SpritePack>(s0_o)->drawAnimFrame(cast<Graphics>(s1_o), s2, s3, s4, s5, s6, 0, 0);
					}
				} else {
					s0_o = Game::spritePacks[2];
					s1_o = this->screenGraphics;
					s2 = 1;
					s3 = sparkFrame;
					s4 = startX;
					s5 = lineY;
					s6 = 1;
					cast<SpritePack>(s0_o)->drawAnimFrame(cast<Graphics>(s1_o), s2, s3, s4, s5, s6, 0, 0);
				}
			}
		}
	}
}

void Game::prepareFreezeEmitterSprite() {
	int32_t state = 0, dir = 0, facingRight = 0, moveOffset = 0, s1 = 0;
	Ref<Object> s0_o;
	state = Game::cellStates[this->paintCellCol][this->paintCellRow];
	if ((state & 8) == 0) {
		Game::curObjectSprites = Game::spritePacks[32];
		dir = state & 7;
		facingRight = (state & 16) != 0 ? 0 : 1;
		if ((facingRight == 0 || dir != 2) && (facingRight != 0 || dir != 4)) {
			s0_o = this;
			if (facingRight == 0) {
				s0_o = cast<Game>(s0_o);
				s1 = 0;
			} else {
				s0_o = cast<Game>(s0_o);
				s1 = 1;
			}
		} else {
			s0_o = this;
			s1 = 2;
		}
		cast<Game>(s0_o)->cellAnimFrame = s1;
		moveOffset = Game::cellMoveOffsets[this->paintCellCol][this->paintCellRow];
		this->cellDrawOffsetX = moveOffset * Game::dirDeltas[dir];
		this->cellDrawOffsetY = moveOffset * Game::dirDeltas[dir + 8];
	}
}

void Game::applyWindLiftOffset() {
	if ((Game::cellStates[this->paintCellCol][this->paintCellRow] & 7) == 1 && (Game::cellObjects[this->paintCellCol][this->paintCellRow] & 255) == 35) {
		this->cellDrawOffsetX = 0;
		this->cellDrawOffsetY = Game::cellMoveOffsets[this->paintCellCol][this->paintCellRow];
	}
}

void Game::prepareWindSprite() {
	Game::curObjectSprites = Game::spritePacks[30];
	this->cellAnimIndex = 1;
	this->cellAnimFrame = Game::frameAtTime(Game::curObjectSprites, 1, irem(Game::frameCount, Game::getAnimDuration(Game::curObjectSprites, 1)));
}

void Game::prepareProjectileSprite() {
	int32_t dir = 0, frameRecord = 0, s1 = 0;
	dir = Game::cellStates[this->paintCellCol][this->paintCellRow] & 7;
	Game::curObjectSprites = Game::spritePacks[29];
	if ((Game::cellStates[this->paintCellCol][this->paintCellRow] & 8) != 0) {
		switch (dir) {
			case 4:
				s1 = 12;
				cast<Game>(this)->cellAnimIndex = s1;
				break;
			case 2:
				s1 = 13;
				cast<Game>(this)->cellAnimIndex = s1;
				break;
			case 1:
				s1 = 14;
				cast<Game>(this)->cellAnimIndex = s1;
				break;
			default:
				break;
		}
		this->cellAnimFrame = Game::frameAtTime(Game::curObjectSprites, this->cellAnimIndex, Game::cellMoveOffsets[this->paintCellCol][this->paintCellRow]);
		frameRecord = (Game::curObjectSprites->animFirstFrame[this->cellAnimIndex] + this->cellAnimFrame) * 5;
		this->cellDrawOffsetX = Game::curObjectSprites->animFrames[frameRecord + 2];
		s1 = Game::curObjectSprites->animFrames[frameRecord + 3];
	} else {
		switch (dir) {
			case 4:
				s1 = 0;
				cast<Game>(this)->cellAnimFrame = s1;
				break;
			case 2:
				s1 = 1;
				cast<Game>(this)->cellAnimFrame = s1;
				break;
			case 1:
				s1 = 2;
				cast<Game>(this)->cellAnimFrame = s1;
				break;
			default:
				break;
		}
		this->cellDrawOffsetX = Game::cellMoveOffsets[this->paintCellCol][this->paintCellRow] * Game::dirDeltas[dir];
		s1 = Game::cellMoveOffsets[this->paintCellCol][this->paintCellRow] * Game::dirDeltas[8 + dir];
	}
	cast<Game>(this)->cellDrawOffsetY = s1;
}

void Game::prepareStaffMonkeySprite() {
	int32_t frameRecOrTime = 0, frame = 0, frameRecord = 0, s1 = 0;
	Game::curObjectSprites = Game::spritePacks[29];
	this->cellAnimIndex = Game::cellStates[this->paintCellCol][this->paintCellRow] & 31;
	if (this->cellAnimIndex == 8 || this->cellAnimIndex == 9) {
		this->cellAnimFrame = 0;
		frameRecOrTime = (Game::curObjectSprites->animFirstFrame[this->cellAnimIndex] + 0) * 5;
		this->cellDrawOffsetX = Game::curObjectSprites->animFrames[frameRecOrTime + 2];
		s1 = -Game::cellMoveOffsets[this->paintCellCol][this->paintCellRow];
	} else {
		frameRecOrTime = (Game::cellStates[this->paintCellCol][this->paintCellRow] & 8160) >> 5;
		frame = Game::frameAtTime(Game::curObjectSprites, this->cellAnimIndex, frameRecOrTime);
		this->cellAnimFrame = frame;
		frameRecord = (Game::curObjectSprites->animFirstFrame[this->cellAnimIndex] + frame) * 5;
		this->cellDrawOffsetX = Game::curObjectSprites->animFrames[frameRecord + 2];
		s1 = Game::curObjectSprites->animFrames[frameRecord + 3];
	}
	cast<Game>(this)->cellDrawOffsetY = s1;
}

void Game::prepareIcicleSprite() {
	int32_t s1 = 0;
	this->cellAnimIndex = (Game::cellStates[this->paintCellCol][this->paintCellRow] & 56) >> 3;
	Game::curObjectSprites = Game::spritePacks[27];
	switch (this->cellAnimIndex) {
		default:
			s1 = Game::cellMoveOffsets[this->paintCellCol][this->paintCellRow];
			cast<Game>(this)->cellAnimFrame = s1;
			return;
		case 3:
			this->cellAnimFrame = 0;
			this->cellDrawOffsetY = -Game::cellMoveOffsets[this->paintCellCol][this->paintCellRow];
			return;
		case 1:
			s1 = irem(Game::cellMoveOffsets[this->paintCellCol][this->paintCellRow] >> 1, Game::spritePacks[27]->getAnimFrameCount(1));
			cast<Game>(this)->cellAnimFrame = s1;
			return;
	}
}

void Game::drawExitPadlockAtCell() {
	this->drawExitPadlock(this->cellDrawX, this->cellDrawY, 0);
}

void Game::drawExitPadlock(int32_t x, int32_t y, bool opened) {
	Arr<Ref<Image>> images;
	int32_t shackleOffsetY = 0, digitShift = 0;
	images = Game::objectFrameImages[18];
	shackleOffsetY = 0;
	if (opened != 0) {
		shackleOffsetY = -5;
	}
	this->screenGraphics->drawImage(images[1], x + 6, y + shackleOffsetY, 0);
	this->screenGraphics->drawImage(images[0], x + 3, y + 7, 0);
	if (opened == 0) {
		digitShift = 0;
		if (this->diamondsToOpenExit < 10) {
			digitShift = Game::spritePacks[0]->moduleImages[0][0]->getWidth() >> 1;
			digitShift++;
		}
		Game::drawNumberRightAligned(this->screenGraphics, x + 19 - digitShift, y + 13, this->diamondsToOpenExit, Game::spritePacks[0]->moduleImages[0], 0);
	}
}

void Game::drawLiquidLayer(int32_t offsetX, int32_t offsetY) {
	int32_t screenX = 0, screenY = 0, slideX = 0, slot = 0, frame = 0, tileKind = 0, animPhase = 0, row = 0, col = 0, liquid = 0, cellCol = 0, cellRow = 0, s0 = 0, s2 = 0, s3 = 0, s4 = 0;
	Ref<Graphics> g;
	Ref<Object> s0_o, s1;
	g = this->screenGraphics;
	for (row = 0; row < 12; row++) {
		for (col = 0; col < 12; col++) {
			cellCol = col + this->camX / 24;
			cellRow = row + this->camY / 24;
			if (cellCol >= 0 && cellCol < this->levelW && cellRow >= 0) {
				if (cellRow < this->levelH) {
					liquid = Game::liquidCells[cellCol][cellRow];
					screenX = col * 24 - offsetX;
					screenY = row * 24 - offsetY;
					slideX = 0;
					if (liquid > 0) {
						s0 = 0;
						while (true) {
							slot = s0;
							if (slot > 2) {
								break;
							}
							if (Game::getLiquidBits(liquid, slot, 0, 3) != 0) {
								slideX = (int8_t)(Game::getLiquidBits(liquid, slot, 7, 2) << 3);
								if (slideX > 0) {
									frame = Game::getLiquidBits(liquid, slot, 0, 3);
									tileKind = Game::getFlowBits(frame, 45, 2);
									if (tileKind > 1) {
										s0 = (int8_t)(24 - slideX);
									} else {
										slideX = (int8_t)(slideX - 24);
										s0 = slideX;
									}
									slideX = s0;
									this->clipToPlayfield();
									g->clipRect(screenX, screenY + (slot << 3), 24, 8);
								}
								frame = this->getLiquidSlotGraphic(cellCol, cellRow, liquid, slot);
								tileKind = frame >> 1;
								animPhase = (tileKind != 7 ? Game::frameCount : Game::frameCount >> 3) & 1;
								if (tileKind != 15) {
									if (tileKind == 14 || tileKind == 11) {
										s0_o = Game::liquidSprites;
										s1 = g;
										s2 = frame + animPhase;
										s3 = screenX + slideX;
										s4 = screenY;
										cast<SpritePack>(s0_o)->drawFrame(cast<Graphics>(s1), s2, s3, s4, 20, 0, 0);
										this->clipToPlayfield();
									} else {
										if (tileKind != 8 || slot != 0 || Game::liquidCells[cellCol][cellRow - 1] <= 0) {
											s0_o = Game::liquidSprites;
											s1 = g;
											s2 = frame + animPhase;
											s3 = screenX + slideX;
											s4 = screenY + (slot << 3);
											cast<SpritePack>(s0_o)->drawFrame(cast<Graphics>(s1), s2, s3, s4, 20, 0, 0);
											this->clipToPlayfield();
										} else {
											Game::liquidSprites->drawFrame(g, 33, screenX + slideX, screenY, 20, 0, 0);
											slot = 3;
										}
									}
								} else {
									Game::liquidSprites->drawFrame(g, frame + this->blockStripAnimFrame, screenX + slideX - 8, screenY + (slot << 3) + 8, 36, 0, 0);
									this->blockStripAnimFrame = this->blockStripAnimFrame + 1;
									if (this->blockStripAnimFrame > 2) {
										this->blockStripAnimFrame = 0;
									}
								}
							}
							s0 = (int8_t)(slot + 1);
						}
					}
				}
			}
		}
	}
}

void Game::prepareCheckpointStarSprite() {
	int32_t s1 = 0;
	this->objectSpriteSet = 20;
	if (Game::cellObjects[this->paintCellCol][this->paintCellRow] >> 8 < this->nextCheckpointIndex) {
		s1 = 7;
	} else {
		s1 = 0 + (Game::frameCount >> 1) % 7;
	}
	cast<Game>(this)->objectSpriteFrame = s1;
}

void Game::drawChest(int32_t objectType) {
	int32_t openFrame = 0, packIndex = 0;
	openFrame = Game::cellObjects[this->paintCellCol][this->paintCellRow] >> 8;
	if (openFrame == 255) {
		openFrame = 0;
	}
	packIndex = 14 != objectType ? 22 : 8;
	if (Game::spritePacks[packIndex] != nullptr) {
		Game::spritePacks[packIndex]->drawAnimFrame(this->screenGraphics, 0, openFrame, this->cellDrawX, this->cellDrawY, 0, 0, 0);
	}
}

void Game::drawHud() {
	int32_t partialRedraw = 0, barOffsetX = 0, isLowEnergy = 0, barX = 0, segmentWidth = 0, segmentIndex = 0, s2 = 0;
	Ref<Graphics> g;
	Ref<SpritePack> hudPack;
	Arr<Ref<Image>> hudImages;
	Ref<Object> s0, s1;
	partialRedraw = 0;
	g = this->screenGraphics;
	hudPack = Game::spritePacks[0];
	if (hudPack != nullptr) {
		g->translate(120, 320);
		if (this->hudNeedsRedraw || Game::screen == 2) {
			hudPack->drawFrame(g, 0, 0, 0, 0, 0, 0);
			if (this->hudFrame19Visible) {
				hudPack->drawFrame(g, 19, 0, 0, 0, 0, 0);
			}
			s0 = hudPack;
		} else {
			partialRedraw = 1;
			g->setClip(-120, -320, 240, 320);
			s0 = hudPack;
		}
		cast<SpritePack>(s0)->drawFrame(g, 1, 0, 0, 0, 0, 0);
		if (this->hasCompass) {
			hudPack->drawFrame(g, 2, 0, 0, 0, 0, 0);
			hudPack->drawFrame(g, 3 + this->compassDirection, 0, 0, 0, 0, 0);
		}
		if (partialRedraw != 0) {
			g->setClip(-120, -320, 240, 320);
		}
		if (this->diamondsToOpenExit <= 0) {
			if (JSystem::currentTimeMillis() - this->exitOpenMsgTime < 1500LL) {
				Game::drawTextInBox(g, Game::spritePacks[41], Game::langStrings[34], 0, -55, 33, 5, 1);
			}
		} else {
			this->exitOpenMsgTime = JSystem::currentTimeMillis();
		}
		if (this->explorerEnergy != this->hudShownEnergy || this->hudNeedsRedraw || this->explorerEnergy <= 1) {
			hudImages = Game::spritePacks[0]->moduleImages[0];
			barOffsetX = 0;
			isLowEnergy = this->explorerEnergy <= 1 ? 1 : 0;
			barX = -11 - (Game::saveData[8] - 4) * hudImages[11 + isLowEnergy]->getWidth() / 2;
			g->drawImage(hudImages[11 + isLowEnergy], barX, -29, 0);
			barOffsetX = 0 + hudImages[11 + isLowEnergy]->getWidth();
			segmentWidth = hudImages[15]->getWidth();
			for (segmentIndex = 0; segmentIndex < Game::saveData[8]; segmentIndex++) {
				if ((this->explorerEnergy > 1 || segmentIndex != 0 || (Game::frameCount >> 2 & 1) != 0) && (segmentIndex >= this->explorerEnergy || this->explorerEnergy <= 1)) {
					s0 = g;
					s1 = hudImages;
					s2 = 13;
				} else {
					s0 = g;
					s1 = hudImages;
					s2 = 15;
				}
				cast<Graphics>(s0)->drawImage(cast<Array<Ref<Image>>>(s1)[s2 + isLowEnergy], barX + barOffsetX, -29, 0);
				barOffsetX = barOffsetX + segmentWidth;
			}
			g->drawImage(hudImages[17 + isLowEnergy], barX + barOffsetX, -29, 0);
			this->hudShownEnergy = this->explorerEnergy;
		}
		if (this->hudShownDiamonds != this->diamondCount || this->hudShownDiamondsLeft != this->diamondsToOpenExit || this->hudNeedsRedraw) {
			if (this->diamondsToOpenExit <= 0) {
				Game::drawNumberRightAligned(g, 70, -12, this->diamondCount, Game::spritePacks[0]->moduleImages[0], 0);
			} else {
				Game::drawDigitStringRightAligned(g, 70, -12, jnew<StringBuffer>()->append(u""_j)->append(this->diamondCount)->append(u"/"_j)->append(this->diamondsToOpenExit + this->diamondCount)->toString(), Game::spritePacks[0]->moduleImages[0], 0);
			}
		}
		if (this->hudShownRedDiamonds != this->redDiamondCount || this->hudNeedsRedraw) {
			this->hudShownRedDiamonds = this->redDiamondCount;
			Game::drawNumberRightAligned(g, 107, -12, this->redDiamondCount, Game::spritePacks[0]->moduleImages[0], 0);
		}
		if (this->hudShownLives != this->lives || this->hudNeedsRedraw) {
			this->hudShownLives = this->lives;
			Game::drawNumberRightAligned(g, -25, -12, this->lives, Game::spritePacks[0]->moduleImages[0], 0);
		}
		g->translate(-120, -320);
		g->translate(120, 0);
		if (this->hudNeedsRedraw || Game::screen == 2) {
			hudPack->drawFrame(g, 20, 0, 0, 0, 0, 0);
		}
		if (this->hudShownDiamonds != this->diamondCount || this->hudShownDiamondsLeft != this->diamondsToOpenExit || this->hudNeedsRedraw) {
			this->drawExitPadlock(-53, 8, this->diamondsToOpenExit <= 0 ? 1 : 0);
		}
		if (this->hudShownKeysA != this->goldKeys || this->hudShownKeysB != this->silverKeys || this->hudNeedsRedraw || Game::screen == 2) {
			hudPack->drawFrame(g, 21, 0, 0, 0, 0, 0);
			Game::drawNumberRightAligned(g, 55, 15, this->goldKeys, Game::spritePacks[0]->moduleImages[0], 0);
			Game::drawNumberRightAligned(g, 87, 15, this->silverKeys, Game::spritePacks[0]->moduleImages[0], 0);
			this->hudShownKeysA = this->goldKeys;
			this->hudShownKeysB = this->silverKeys;
		}
		g->translate(-120, 0);
		this->hudShownDiamonds = this->diamondCount;
		this->hudShownDiamondsLeft = this->diamondsToOpenExit;
		this->hudNeedsRedraw = 0;
		return;
	}
}

void Game::prepareLeverSprite() {
	Ref<Object> s0;
	int32_t s1 = 0;
	Game::curObjectSprites = Game::spritePacks[6];
	this->cellAnimIndex = 0;
	if (this->switchWallsPhase != 0) {
		if (this->switchWallsPhase != 9) {
			s0 = this;
			if (this->leverMoveDir >= 0) {
				s0 = cast<Game>(s0);
				s1 = 3;
			} else {
				s0 = cast<Game>(s0);
				s1 = 1;
			}
		} else {
			s0 = this;
			s1 = 2;
		}
	} else {
		s0 = this;
		s1 = 0;
	}
	cast<Game>(s0)->cellAnimFrame = s1;
}

void Game::prepareFloorTrapSprite() {
	int32_t isActive = 0;
	Ref<SpritePack> pack;
	isActive = Game::cellStates[this->paintCellCol][this->paintCellRow] == 1 ? 1 : 0;
	pack = Game::spritePacks[5];
	pack->drawAnimFrame(this->screenGraphics, isActive, irem(Game::frameCount >> 1, pack->getAnimFrameCount(isActive)), this->cellDrawX, this->cellDrawY, 0, 0, 0);
}

void Game::drawStatueFlame(int8_t statueType) {
	Ref<Actor> flameActor;
	flameActor = Game::actors[4];
	if (statueType != 23) {
		flameActor->flipFlags = flameActor->flipFlags & -2;
		flameActor->x = this->cellDrawX + 24;
	} else {
		flameActor->x = this->cellDrawX;
		flameActor->flipFlags = flameActor->flipFlags | 1;
	}
	flameActor->y = this->cellDrawY;
	flameActor->applyFrameOffset();
	flameActor->draw(this->screenGraphics);
}

void Game::loadMenuResourcesStep(int32_t step) {
	switch (step) {
		case 7:
			if (Game::spritePacks[18] == nullptr) {
				Game::spritePacks[18] = Game::loadSpritePack(u"/ui.f"_j, 3);
			}
			return;
		case 6:
			if (Game::titleLogoImage == nullptr) {
				Game::titleLogoImage = Game::loadPng(u"/spl.f"_j, 0);
			}
			if (Game::titleBackgroundImage == nullptr) {
				Game::titleBackgroundImage = Game::loadPng(u"/spl.f"_j, 1);
			}
			if (Game::titleBottomImage != nullptr) {
				return;
			}
			Game::titleBottomImage = Game::loadPng(u"/spl.f"_j, 2);
			return;
		default:
			return;
		case 5:
			return;
		case 4:
			return;
		case 3:
			return;
		case 2:
			Game::spritePacks[41]->lineSpacing = 15;
			return;
		case 1:
			return;
		case 0:
			Game::loadUiFont();
			JSystem::gc();
			return;
	}
}

void Game::freeTitleImages() {
	Game::titleLogoImage = nullptr;
	Game::titleBackgroundImage = nullptr;
	Game::titleBottomImage = nullptr;
	Game::stageMapImage = nullptr;
	Game::moreGamesBadgeBg = nullptr;
	Game::stageMapGraphics = nullptr;
	JSystem::gc();
}

void Game::layoutMenuItems() {
	int32_t itemIndex = 0, textWidth = 0;
	this->menuItemCount = Game::menuDefs[this->menuId]->length >> 1;
	this->menuMaxItemWidth = 0;
	for (itemIndex = 0; itemIndex < this->menuItemCount; itemIndex++) {
		textWidth = Game::measureFirstLineWidth(Game::spritePacks[41], Game::langStrings[Game::menuDefs[this->menuId][itemIndex * 2 + 1]], 0);
		if (this->menuId != 0 || itemIndex != 3) {
			if (textWidth > this->menuMaxItemWidth) {
				this->menuMaxItemWidth = textWidth;
			}
		}
	}
	this->menuItemsRevealed = 0;
	this->menuTick = 0;
}

void Game::drawMenuBackground(int32_t topY, int32_t bottomY) {
	int32_t row = 0;
	if (Game::screen == 4) {
		this->drawTitleBackground(this->screenGraphics, 0);
		for (row = topY - 1; row < bottomY - 2; row++) {
			Game::spritePacks[18]->drawFrame(this->screenGraphics, 4, row % 2, row, 0, 0, 0);
		}
	}
	if (Game::screen == 2) {
		this->screenGraphics->setColor(0);
		this->screenGraphics->fillRect(0, topY - 1, 240, bottomY - 2 - (topY - 1));
	}
	this->screenGraphics->setColor(16777215);
	this->screenGraphics->drawLine(0, topY - 1 - 1, 240, topY - 1 - 1);
	this->screenGraphics->drawLine(0, bottomY - 1, 240, bottomY - 1);
	this->screenGraphics->setColor(0);
	this->screenGraphics->drawLine(0, topY - 1 - 2, 240, topY - 1 - 2);
	this->screenGraphics->drawLine(0, bottomY - 2, 240, bottomY - 2);
}

void Game::refreshHasSavedGame() {
	this->menuSaveRecheck = 0;
	this->hasSavedGame = Game::readHasSavedGame();
}

void Game::drawMenu() {
	int32_t menuTopY = 0, fullTextWidth = 0, scrollX = 0, maxTextWidth = 0, textLeftX = 0, needsScroll = 0, menuBottomY = 0, offsetOrTime = 0, itemIndex = 0, itemTopY = 0, itemMidY_n = 0, paletteIndex = 0, textWidth = 0, s0 = 0, s1 = 0, s2_n = 0, s3 = 0, s4 = 0;
	int64_t offsetOrTime_l = 0;
	Ref<Graphics> itemMidY;
	Ref<Object> s0_o;
	if (this->menuSaveRecheck) {
		this->refreshHasSavedGame();
	}
	menuTopY = 320 - (this->menuItemCount * 15 + 1 + 2);
	s0 = menuTopY;
	s1 = this->hasSavedGame || this->menuId != 0 ? 0 : 15;
	menuTopY = s0 + s1;
	menuBottomY = 320;
	this->screenGraphics->setClip(0, 0, 240, 320);
	if (Game::screen == 2 && Game::menuFullRedraw && Game::menuRepaintPlayfield) {
		this->hudFrame19Visible = 0;
		this->paintPlayfield();
		this->hudFrame19Visible = 1;
		Game::menuRepaintPlayfield = 0;
	}
	if (Game::screen == 7 || Game::screen == 2) {
		offsetOrTime = menuTopY - (160 - (320 - menuTopY) / 2);
		menuTopY = menuTopY - offsetOrTime;
		menuBottomY = 320 - offsetOrTime;
	}
	if (this->menuId == 7) {
		Game::spritePacks[41]->drawString(this->screenGraphics, Game::langStrings[this->screenSubState != 5 ? 113 : 102], 120, menuTopY - 20, 17);
	}
	if (Game::screen == 7) {
		if (this->menuLastDrawnItem == -1 || Game::menuFullRedraw) {
			this->screenGraphics->setColor(0);
			s0_o = this->screenGraphics;
			s1 = 0;
			s2_n = 0;
			s3 = 240;
			s4 = 320;
		} else {
			offsetOrTime = menuTopY + this->menuLastDrawnItem * 15;
			this->screenGraphics->setColor(0);
			s0_o = this->screenGraphics;
			s1 = 0;
			s2_n = offsetOrTime;
			s3 = 240;
			s4 = 16;
		}
		cast<Graphics>(s0_o)->fillRect(s1, s2_n, s3, s4);
	}
	offsetOrTime_l = JSystem::currentTimeMillis();
	if (this->menuConfirmStep >= 0 && offsetOrTime_l - this->menuConfirmStepTime > 100LL) {
		this->menuConfirmStep = this->menuConfirmStep + 1;
		this->menuConfirmStepTime = offsetOrTime_l;
	}
	if (this->menuLastDrawnItem != -1 && !Game::menuFullRedraw) {
		itemIndex = this->menuId != 0 || this->menuLastDrawnItem <= 1 || this->hasSavedGame ? 0 : 15;
		itemTopY = menuTopY + this->menuLastDrawnItem * 15 - itemIndex;
		this->screenGraphics->setClip(0, itemTopY, 240, 16);
	}
	if (this->menuLastDrawnItem != this->menuCursor || Game::menuFullRedraw) {
		this->drawMenuBackground(menuTopY, menuBottomY);
	}
	for (itemIndex = 0; itemIndex < this->menuItemCount; itemIndex++) {
		if (this->menuLastDrawnItem == -1 || itemIndex == this->menuLastDrawnItem || itemIndex == this->menuCursor || Game::menuFullRedraw) {
			if (this->menuId != 0 || itemIndex != 1 || this->hasSavedGame) {
				itemTopY = menuTopY + itemIndex * 15;
				itemMidY_n = itemTopY + 7;
				if (this->menuId == 0 && itemIndex > 1 && !this->hasSavedGame) {
					itemTopY -= 15;
					itemMidY_n -= 15;
				}
				paletteIndex = 0;
				if (itemIndex == 2 && this->menuId == 0) {
					paletteIndex = 1;
				}
				if (this->specialStageType != 2 || itemIndex != 4 || this->menuId != 1) {
					if (itemIndex == this->menuCursor) {
						s0_o = this->screenGraphics;
						s1 = 13540096;
						cast<Graphics>(s0_o)->setColor(s1);
						s0_o = this->screenGraphics;
						s1 = 0;
						s2_n = itemMidY_n - 7;
						s3 = 240;
						s4 = 16;
						cast<Graphics>(s0_o)->fillRect(s1, s2_n, s3, s4);
					}
				} else {
					paletteIndex = 0;
					if (itemIndex != this->menuCursor) {
						this->screenGraphics->setColor(13421772);
						s0_o = this->screenGraphics;
						s1 = 0;
						s2_n = itemMidY_n - 7 + 1;
						s3 = 240;
						s4 = 14;
					} else {
						s0_o = this->screenGraphics;
						s1 = 6710886;
						cast<Graphics>(s0_o)->setColor(s1);
						s0_o = this->screenGraphics;
						s1 = 0;
						s2_n = itemMidY_n - 7;
						s3 = 240;
						s4 = 16;
					}
					cast<Graphics>(s0_o)->fillRect(s1, s2_n, s3, s4);
				}
				scrollX = 0;
				needsScroll = 0;
				Game::spritePacks[41]->measureString(Game::langStrings[Game::menuDefs[this->menuId][itemIndex * 2 + 1]]);
				textWidth = SpritePack::textWidth;
				fullTextWidth = textWidth;
				maxTextWidth = itemIndex != 2 || this->menuId != 0 ? 210 : 152;
				if (textWidth > maxTextWidth) {
					needsScroll = 1;
					textWidth = maxTextWidth;
				}
				textLeftX = 120 - textWidth / 2;
				if (needsScroll != 0) {
					scrollX = itemIndex != this->menuCursor ? 0 : this->menuTextScrollX;
					this->screenGraphics->setClip(textLeftX, itemTopY, textWidth, 15);
				}
				Game::spritePacks[41]->paletteIndex = paletteIndex;
				Game::spritePacks[41]->drawString(this->screenGraphics, Game::langStrings[Game::menuDefs[this->menuId][itemIndex * 2 + 1]], 120 - textWidth / 2 - scrollX, itemMidY_n + 1, 6);
				if (needsScroll != 0) {
					this->screenGraphics->setClip(0, 0, 240, 320);
				}
				if (itemIndex == this->menuCursor) {
					this->screenGraphics->setColor(16777215);
					Game::spritePacks[18]->drawFrame(this->screenGraphics, 2, 120 - textWidth / 2 - 8, itemMidY_n, 0, 0, 10);
					Game::spritePacks[18]->drawFrame(this->screenGraphics, 2, 120 + textWidth / 2 + 8, itemMidY_n, 0, 0, 6);
				}
				if (itemIndex == this->menuCursor && needsScroll != 0 && this->menuTick % 2 == 0) {
					this->menuTextScrollX = this->menuTextScrollX + this->menuTextScrollStep;
					if (this->menuTextScrollX < -5 || this->menuTextScrollX + maxTextWidth - 5 > fullTextWidth) {
						this->menuTextScrollStep = -this->menuTextScrollStep;
						this->menuTextScrollX = this->menuTextScrollX + this->menuTextScrollStep;
					}
				}
			}
		}
	}
	this->menuLastDrawnItem = this->menuCursor;
	this->menuTick = this->menuTick + 1;
	if (this->menuRevealDelay >= 0) {
		s0_o = this;
		s1 = this->menuRevealDelay - 1;
	} else {
		s0_o = this;
		s1 = 3;
	}
	cast<Game>(s0_o)->menuRevealDelay = s1;
	if (this->menuRevealDelay == 0 && this->menuItemsRevealed + 1 < this->menuItemCount) {
		this->menuItemsRevealed = this->menuItemsRevealed + 1;
	}
	this->screenGraphics->setClip(0, 0, 240, 320);
	if (this->menuId == 0 && this->showMoreGamesBadge) {
		itemIndex = this->menuTick % 20;
		if (itemIndex < 10) {
			if (this->menuCursor != 2) {
				if (Game::moreGamesBadgeBg == nullptr) {
					itemTopY = menuTopY + 30 + 1 - (!this->hasSavedGame ? 15 : 0);
					Game::moreGamesBadgeBg = Image::createImage(28, 14);
					itemMidY = Game::moreGamesBadgeBg->getGraphics();
					itemMidY->translate(-1, -itemTopY);
					this->drawTitleBackground(itemMidY, 0);
					itemMidY->translate(1, itemTopY);
					for (paletteIndex = 0; paletteIndex < 14; paletteIndex++) {
						Game::spritePacks[18]->drawFrame(itemMidY, 4, (itemTopY + paletteIndex + 1) % 2, paletteIndex, 0, 0, 0);
					}
				}
				this->screenGraphics->drawImage(Game::moreGamesBadgeBg, 1, menuTopY + 30 + 1 - (!this->hasSavedGame ? 15 : 0), 0);
			}
		} else {
			Game::spritePacks[18]->drawFrame(this->screenGraphics, 1, 1, menuTopY + 30 + 7 - (!this->hasSavedGame ? 15 : 0), 0, 0, 6);
		}
	}
	if (this->menuId != 0 && this->menuId != 3 && this->menuId != 1 && this->menuId != 7) {
		this->drawBackSoftkeyIcon();
	}
	this->drawSelectSoftkeyIcon();
	Game::menuFullRedraw = 0;
	if (this->menuConfirmStep == 2) {
		if (Game::screen == 2) {
			Game::menuFullRedraw = 1;
			Game::menuRepaintPlayfield = 1;
		}
		this->menuConfirmStep = -1;
		this->hudNeedsRedraw = 1;
		this->menuLastDrawnItem = -1;
		this->selectMenuItem();
	}
}

void Game::drawBackSoftkeyIcon() {
	Game::spritePacks[18]->drawFrame(this->screenGraphics, 0, 223, 308, 0, 0, 0);
}

void Game::drawSelectSoftkeyIcon() {
	Game::spritePacks[18]->drawFrame(this->screenGraphics, 3, 2, 308, 0, 0, 0);
}

void Game::drawLoadingScreen() {
	Ref<Graphics> g;
	int32_t barWidth = 0;
	g = this->screenGraphics;
	g->setColor(0);
	g->fillRect(0, 0, 240, 320);
	barWidth = idiv((this->loadingStep + 1) * 230, this->loadingStepCount);
	if (barWidth > 230) {
		barWidth = 230;
	}
	g->setColor(13540096);
	this->screenGraphics->fillRect(5, 310, barWidth, 6);
	g->setColor(16554500);
	this->screenGraphics->drawRoundRect(4, 309, 231, 6, 2, 2);
	Game::spritePacks[41]->paletteIndex = 0;
	Game::spritePacks[41]->drawString(this->screenGraphics, Game::langStrings[37], 120, 293, 1);
}

void Game::paintSpecialStageExtras() {
	switch (this->specialStageType) {
		case 5:
			this->paintKnightBoss();
			return;
		default:
			return;
		case 4:
			this->paintAnacondaBoss();
			return;
		case 3:
			this->paintYetiBoss();
			return;
		case 2:
			this->paintIntroHintIcon();
			this->paintIntroStageForeground();
			return;
		case 1:
			this->paintFloodStage();
			return;
	}
}

void Game::paintIntroStageForeground() {
	Ref<SpritePack> pack;
	if (this->camX + 240 > 1440 && this->camY + 320 > 48) {
		if (Game::spritePacks[10] == nullptr) {
			Game::spritePacks[10] = Game::loadSpritePack(u"/mmv.f"_j, 0);
		}
		pack = Game::spritePacks[10];
		if (this->isPlayerAt(60, 3) || this->isPlayerAt(61, 3)) {
			pack->drawFrame(this->screenGraphics, 1, 1440 - this->camX, 48 - this->camY, 0, 0, 0);
		}
	}
	if (this->playerCol > 55 && this->isExplorerVisible) {
		Game::actors[0]->draw(this->screenGraphics);
	}
}

void Game::paintIntroStageCellOverlay(Ref<Graphics> g) {
	if (Game::spritePacks[10] == nullptr) {
		Game::spritePacks[10] = Game::loadSpritePack(u"/mmv.f"_j, 0);
	}
	if (this->paintCellCol >= 60 && this->paintCellCol < 65 && this->paintCellRow >= 2 && this->paintCellRow < 7) {
		Game::spritePacks[10]->drawFrame(g, 4 + (this->paintCellRow - 2) * 5 + this->paintCellCol - 60, this->cellDrawX, this->cellDrawY, 0, 0, 0);
	}
}

void Game::paintKnightBoss() {
	Ref<Actor> knight;
	int32_t explosionX = 0, explosionY = 0;
	if (this->bossState != -1) {
		knight = Game::actors[5];
		knight->x = this->knightX - this->camX;
		knight->y = 504 - this->camY;
		knight->applyFrameOffset();
		knight->draw(this->screenGraphics);
		if (this->bossState == 12) {
			explosionX = this->knightX - this->camX + Game::frameCount * this->bossTimer % 48;
			explosionY = Game::actors[5]->y + 24;
			Game::spritePacks[7]->drawAnimFrame(this->screenGraphics, 0, irem(Game::frameCount, Game::spritePacks[7]->getAnimFrameCount(1)), explosionX, explosionY, 0, 0, 0);
			this->hurtPlayerNearExplosion(explosionX, explosionY);
		}
	}
}

void Game::paintYetiBoss() {
	Ref<Actor> colOrActorOrX;
	int32_t colOrActorOrX_n = 0, explosionY = 0;
	if (this->specialStageType == 3 && (int64_t)Game::frameCount >= this->ceilingCollapseFrame + 80LL) {
		for (colOrActorOrX_n = 14; colOrActorOrX_n <= 21; colOrActorOrX_n++) {
			Game::cellStates[colOrActorOrX_n][15] = 0;
			Game::cellObjects[colOrActorOrX_n][15] = -1;
			Game::cellTypes[colOrActorOrX_n][15] = 44;
			Game::cellMoveOffsets[colOrActorOrX_n][15] = 0;
			Game::cellUpdateTimers[colOrActorOrX_n][15] = 24;
		}
		this->ceilingCollapseFrame = 0LL;
	}
	if (this->bossState != 15) {
		if (this->camX + 240 + 48 >= this->yetiX && this->camY + 320 + 48 >= 504) {
			colOrActorOrX = Game::actors[5];
			colOrActorOrX->x = this->yetiX - this->camX;
			colOrActorOrX->y = 504 - this->camY;
			colOrActorOrX->applyFrameOffset();
			colOrActorOrX->draw(this->screenGraphics);
		}
		if (this->bossState == 12) {
			colOrActorOrX_n = this->yetiX - this->camX + Game::frameCount * this->bossTimer % 48;
			explosionY = Game::actors[5]->y + 24;
			Game::spritePacks[7]->drawAnimFrame(this->screenGraphics, 0, irem(Game::frameCount, Game::spritePacks[7]->getAnimFrameCount(0)), colOrActorOrX_n, explosionY, 0, 0, 0);
			this->hurtPlayerNearExplosion(colOrActorOrX_n, explosionY);
		}
	}
}

void Game::paintAnacondaHealthOrExplosion() {
	Ref<Graphics> g;
	Ref<Actor> anaconda;
	int32_t explosionX = 0, explosionY = 0;
	g = this->screenGraphics;
	anaconda = Game::actors[5];
	if (this->bossState != 7) {
		if (this->bossState != 8 && this->bossState != 0) {
			this->drawBossHealthBar(g, 3);
		}
		return;
	}
	explosionX = anaconda->x + Game::frameCount * this->bossTimer % 48;
	explosionY = anaconda->y;
	if (this->anacondaStateWhenHit == 10) {
		explosionY = explosionY - 144;
	}
	Game::spritePacks[7]->drawAnimFrame(g, 1, irem(Game::frameCount, Game::spritePacks[7]->getAnimFrameCount(1)), explosionX, explosionY, 0, 0, 0);
	this->hurtPlayerNearExplosion(explosionX, explosionY);
}

void Game::drawBossHealthBar(Ref<Graphics> g, int32_t maxSegments) {
	int32_t barWidth = 0, barX = 0, segment = 0;
	barWidth = maxSegments * 14 + 2;
	barX = 240 - barWidth >> 1;
	if (this->bossHealth > 0) {
		g->setColor(0);
		g->fillRect(barX, 5, barWidth, 12);
		g->setColor(3913615);
		for (segment = 0; segment < this->bossHealth; segment++) {
			g->fillRect(barX + 2 + segment * 14, 7, 12, 8);
		}
	}
}

void Game::paintAnacondaBoss() {
	Ref<Graphics> g;
	Ref<Actor> anaconda, slamActor;
	int32_t riseHeight = 0, holeOrSavedY = 0, holeX = 0, s0 = 0, s1 = 0, s2 = 0;
	Ref<Object> s0_o;
	g = this->screenGraphics;
	anaconda = Game::actors[5];
	slamActor = Game::actors[4];
	switch (this->bossState) {
		default:
			s0 = -1000;
			riseHeight = s0;
			break;
		case 11:
			s0 = 15 + this->bossTimer * 18;
			riseHeight = s0;
			break;
		case 10:
			s0 = 15 + this->bossTimer * 18;
			riseHeight = s0;
			break;
		case 9:
			s0 = 15 + this->bossTimer * 18;
			riseHeight = s0;
			break;
		case 5:
			riseHeight = 15 + this->bossTimer * 18;
			this->bossStepDoneThisFrame = 0;
			break;
		case 4:
			s0 = 40 - (this->bossTimer * 2 << 1);
			riseHeight = s0;
			break;
		case 3:
			s0 = 40;
			riseHeight = s0;
			break;
		case 2:
		case 7:
			s0 = 40;
			riseHeight = s0;
			break;
		case 1:
			s0 = this->bossTimer * 1;
			riseHeight = s0;
			break;
	}
	anaconda->x = (10 + this->anacondaHoleIndex * (2 + (this->anacondaHoleIndex > 0 ? 1 : 0))) * 24 - this->camX;
	if (this->bossState != 5) {
		s0_o = anaconda;
		s1 = 256 - riseHeight - this->camY;
		cast<Actor>(s0_o)->y = s1;
	} else {
		holeOrSavedY = anaconda->y;
		anaconda->y = 256 - this->camY - this->anacondaRiseOffset - 15;
		if (this->getAnacondaHeadRow() == 3) {
			s0_o = anaconda;
			s1 = holeOrSavedY;
			cast<Actor>(s0_o)->y = s1;
		}
	}
	anaconda->draw(g);
	if (this->anacondaSlamVisible) {
		slamActor->y = 96 - this->camY;
		slamActor->x = (this->getAnacondaHoleCol() + 1) * 24 - this->camX;
		slamActor->draw(g);
	}
	for (holeOrSavedY = 0; holeOrSavedY < 3; holeOrSavedY++) {
		s0 = holeOrSavedY;
		s1 = 2;
		s2 = holeOrSavedY <= 0 ? 0 : 1;
		holeX = (s0 * (s1 + s2) + 10) * 24 - this->camX;
		if (holeX < 240 && holeX > -48 && this->camY > -80) {
			Game::spritePacks[40]->drawFrame(g, 1, holeX, 216 - this->camY, 0, 0, 0);
		}
	}
}

void Game::paintFloodStage() {
	int32_t frame = 0, tileY = 0, tileX = 0, floodTopY = 0, firstTileX = 0, floodLeftX = 0, floodRightX = 0;
	Ref<Actor> gateActor, floodActor;
	frame = Game::frameCount;
	gateActor = Game::actors[2];
	if (this->camY + this->shake < 1008 && this->camY + this->shake > 592) {
		gateActor->x = 240 - this->camX;
		gateActor->y = 1008 - this->camY;
		gateActor->applyFrameOffset();
		gateActor->draw(this->screenGraphics);
		gateActor->x = 336 - this->camX;
		gateActor->y = 1008 - this->camY;
		gateActor->applyFrameOffset();
		gateActor->flipFlags = 1;
		gateActor->draw(this->screenGraphics);
	}
	if (this->shakeTime > 10) {
		this->paintFallingDebris();
	}
	floodTopY = this->levelH * 24 - this->floodHeight - this->camY;
	firstTileX = 168 - this->camX;
	floodLeftX = firstTileX;
	floodRightX = firstTileX + 240;
	while (firstTileX <= -24) {
		firstTileX += 24;
	}
	floodActor = Game::actors[1];
	if ((this->floodHeight >= 816 || floodActor->animIndex == 2) && this->floodHeight > 816) {
		for (tileY = floodTopY + 20; tileY < 320; tileY += 24) {
			for (tileX = firstTileX; tileX < floodRightX; tileX += 24) {
				floodActor->sprite->drawAnimFrame(this->screenGraphics, 1, ((frame >> 1) + tileX + tileY) % 2, tileX, tileY, 0, 0, 0);
			}
		}
	}
	if (gateActor->animIndex == 2) {
		floodActor->flipFlags = 0;
		floodActor->x = floodLeftX + 120;
		floodActor->y = floodTopY;
		floodActor->applyFrameOffset();
		floodActor->draw(this->screenGraphics);
		floodActor->flipFlags = 1;
		floodActor->draw(this->screenGraphics);
		this->paintAlarmBorder();
	}
}

void Game::paintFallingDebris() {
	int32_t index = 0, speed = 0, x = 0, y = 0;
	for (index = 3; index < 13; index += 2) {
		speed = 10 * (2 * index / 5 + 1);
		x = (speed + idiv(Game::frameCount, speed)) * index % 240;
		y = idiv(320, speed) * Game::frameCount % 320;
		this->screenGraphics->drawImage(Game::objectFrameImages[27][index & 1], x, y, 0);
	}
}

void Game::paintIntroHintIcon() {
	if (this->introHintIconVisible && this->activeCutscene == nullptr && this->pendingCutsceneId == -1) {
		Game::spritePacks[15]->drawAnimFrame(this->screenGraphics, 0, Game::frameCount >> 1 & 3, this->explorerScreenX, this->explorerScreenY - 24, 0, 0, 0);
	}
}

void Game::paintAlarmBorder() {
	Ref<Graphics> g;
	int32_t green = 0, phase = 0;
	g = this->screenGraphics;
	phase = (Game::frameCount << 3) % 160;
	green = (Game::frameCount / 160 & 1) != 0 ? 0 + phase : 160 - phase;
	g->setColor(255, green, 0);
	g->drawRect(0, 0, 239, 319);
}

void Game::paintExplorer() {
	int32_t col = 0, bobOrOffset = 0, row = 0, frame = 0, facing = 0, actorIndex = 0, insideBorder = 0, drawDir = 0, bobPhaseOrAnim = 0, s0 = 0, s1 = 0;
	Ref<Actor> actor;
	Ref<Object> s0_o;
	if (!this->respawnPanActive) {
		col = this->playerCol;
		row = this->playerRow;
		frame = Game::frameCount;
		facing = this->explorerStateFlags & 7;
		actorIndex = (this->explorerStateFlags & 16384) != 0 ? 3 : 0;
		actor = Game::actors[actorIndex];
		insideBorder = this->isPlayerInsideBorder();
		drawDir = (this->explorerStateFlags & 2048) != 0 ? this->explorerStateFlags & 7 : this->explorerDrawMoveDir;
		if (this->isExplorerVisible) {
			this->explorerScreenX = col * 24 + Game::dirDeltas[drawDir] * this->playerStep - this->camX;
			this->explorerScreenY = row * 24 + Game::dirDeltas[drawDir + 8] * this->playerStep - this->camY;
			if ((this->invulnTimer <= 0LL || (frame >> 1 & 1) == 0) && this->encasedStruggleCount <= 0) {
				actor->x = this->explorerScreenX;
				actor->y = this->explorerScreenY;
				if (Game::liquidCells != nullptr && insideBorder != 0 && facing != 1 && facing != 3 && Game::liquidCells[col][row + 1] != 0 && Game::isHeavyObject(col, row + 1)) {
					bobPhaseOrAnim = (frame >> 1) + col;
					bobOrOffset = bobPhaseOrAnim % 4;
					if ((bobPhaseOrAnim / 4 & 1) == 1) {
						bobOrOffset = 4 - bobOrOffset;
					}
					actor->y = actor->y + bobOrOffset;
				}
				actor->applyFrameOffset();
				actor->draw(this->screenGraphics);
				bobPhaseOrAnim = actor->animIndex;
				Game::itemRaiseFreeze = bobPhaseOrAnim == 47 && actor->frameIndex == 0 ? 1 : 0;
				switch (bobPhaseOrAnim) {
					case 40:
					case 47:
					case 48:
						s0 = actor->frameIndex;
						s1 = bobPhaseOrAnim != 40 ? 6 : 13;
						if (s0 > s1 || bobPhaseOrAnim == 47) {
							try {
								bobOrOffset = 0;
								if (this->heldItemImageSet == 30 || this->heldItemImageSet == 31 || this->heldItemImageSet == 32) {
									bobOrOffset = -2;
									if (Game::objectFrameImages[this->heldItemImageSet] != nullptr) {
										this->screenGraphics->drawImage(Game::objectFrameImages[this->heldItemImageSet][this->heldItemFrame], actor->x + bobOrOffset, actor->y - 24, 0);
									} else {
										Game::spritePacks[Game::getSpritePackForImageSet(this->heldItemImageSet)]->drawFrame(this->screenGraphics, this->heldItemFrame, actor->x + bobOrOffset, actor->y - 24, 0, 0, 0);
									}
								} else {
									if (Game::objectFrameImages[this->heldItemImageSet] != nullptr) {
										this->screenGraphics->drawImage(Game::objectFrameImages[this->heldItemImageSet][this->heldItemFrame], actor->x + bobOrOffset, actor->y - 24, 0);
									} else {
										Game::spritePacks[Game::getSpritePackForImageSet(this->heldItemImageSet)]->drawFrame(this->screenGraphics, this->heldItemFrame, actor->x + bobOrOffset, actor->y - 24, 0, 0, 0);
									}
								}
							} catch (JavaException& ex) {
								if (ex.isa(u"java/lang/Exception")) {
									s0_o = ex.ex;
								}
								else throw;
							}
							if (this->heldItemAmount > 0) {
								Game::drawNumberRightAligned(this->screenGraphics, actor->x + 24, actor->y - 10, this->heldItemAmount, Game::spritePacks[0]->moduleImages[0], 0);
							}
						}
						break;
					case 17:
					case 18:
						if (actor->frameIndex == 0) {
							this->screenGraphics->drawImage(Game::objectFrameImages[this->heldItemImageSet][this->heldItemFrame], actor->x, actor->y - 12, 0);
						}
						break;
					default:
						break;
				}
			}
			if (insideBorder == 0 || Game::cellTypes[col][row] != 0) {
				return;
			}
			bobPhaseOrAnim = Game::cellStates[col][row] & 7;
			bobOrOffset = Game::cellMoveOffsets[col][row];
			try {
				Game::spritePacks[Game::getSpritePackForImageSet(1)]->drawFrame(this->screenGraphics, 0 + (Game::cellStates[col][row] & 56), col * 24 - this->camX + Game::dirDeltas[bobPhaseOrAnim] * bobOrOffset, row * 24 - this->camY + Game::dirDeltas[bobPhaseOrAnim + 8] * bobOrOffset, 0, 0, 0);
			} catch (JavaException& ex) {
				if (ex.isa(u"java/lang/Exception")) {
					s0_o = ex.ex;
					return;
				}
				else throw;
			}
			return;
		}
		return;
	}
}

void Game::prepareLooseObjectSprite() {
	int32_t col = 0, rollRight = 0, row = 0, rowBelow = 0, state = 0, moveOffset = 0, moveDir = 0, inLiquid = 0, rollFrameOrPhase = 0, rollStepOrBob = 0, s1 = 0;
	Ref<Object> s0_o;
	col = this->paintCellCol;
	row = this->paintCellRow;
	rowBelow = row + 1;
	this->landingDustOffX = 0;
	this->landingDustOffY = 0;
	this->hasLandingDust = 0;
	state = Game::cellStates[col][row];
	moveDir = state & 7;
	moveOffset = Game::cellMoveOffsets[col][row];
	if (state == -1) {
		state = -1;
	}
	this->cellDrawOffsetX = this->cellDrawOffsetX + moveOffset * Game::dirDeltas[moveDir];
	this->cellDrawOffsetY = this->cellDrawOffsetY + moveOffset * Game::dirDeltas[moveDir + 8];
	inLiquid = Game::liquidCells != nullptr && Game::liquidCells[col][row] != 0 ? 1 : 0;
	switch (this->paintCellTerrain) {
		case 47:
			Game::curObjectSprites = Game::spritePacks[30];
			this->cellAnimIndex = 0;
			this->cellAnimFrame = Game::frameAtTime(Game::curObjectSprites, 0, irem(Game::frameCount, Game::getAnimDuration(Game::curObjectSprites, 0)));
			break;
		case 9:
			Game::curObjectSprites = Game::spritePacks[(state & 264241152) >> 22];
			this->cellAnimFrame = 0;
			break;
		case 8:
			this->terrainSpriteSet = 16;
			this->terrainSpriteFrame = 0 + (Game::frameCount >> 1 & 1);
			break;
		case 7:
			this->terrainSpriteSet = 5;
			this->terrainSpriteFrame = 1;
			break;
		case 6:
			this->terrainSpriteSet = 5;
			this->terrainSpriteFrame = 0;
			break;
		case 5:
			this->terrainSpriteSet = 25;
			this->terrainSpriteFrame = 0 + this->sparklePhase;
			break;
		case 4:
			this->terrainSpriteSet = 24;
			this->terrainSpriteFrame = 0 + this->sparklePhase;
			break;
		case 2:
			this->prepareRedDiamondSprite();
			break;
		case 1:
			this->terrainSpriteSet = 2;
			this->terrainSpriteFrame = 0 + this->sparklePhase;
			break;
		case 0:
			rollFrameOrPhase = (state & 56) >> 3;
			rollStepOrBob = (state & 28672) >> 12;
			rollRight = (state & 65536) != 0 ? 0 : 1;
			if (inLiquid != 0 || moveDir != 0 || !Game::isHeavyObject(col, rowBelow)) {
				state = state & -28673;
			} else {
				state = state & -28673 | rollStepOrBob << 12;
				if (rollRight == 0) {
					state = state | 65536;
					rollStepOrBob = -rollStepOrBob;
				} else {
					state = state & -65537;
				}
				this->cellDrawOffsetX = rollStepOrBob;
			}
			Game::cellStates[col][row] = state;
			this->terrainSpriteSet = 1;
			this->terrainSpriteFrame = 0 + rollFrameOrPhase;
			break;
		default:
			break;
	}
	if (inLiquid != 0 || Game::liquidCells != nullptr && Game::liquidCells[col][rowBelow] != 0 && Game::isHeavyObject(col, rowBelow)) {
		rollFrameOrPhase = (Game::frameCount >> 1) + col;
		rollStepOrBob = rollFrameOrPhase % 4;
		if ((rollFrameOrPhase / 4 & 1) == 1) {
			rollStepOrBob = 4 - rollStepOrBob;
		}
		this->cellDrawOffsetY = this->cellDrawOffsetY + rollStepOrBob;
	}
	if (((state & 512) != 0 || Game::cellTypes[col - Game::dirDeltas[moveDir]][rowBelow] < 0 && Game::isHeavyObject(col, rowBelow) && (Game::cellStates[col][rowBelow] & 7) == 0 && col != this->slidingObjCol && row != this->slidingObjRow) && (this->explorerStateFlags & 8) == 0) {
		this->cellDrawOffsetY = this->cellDrawOffsetY + moveOffset * moveOffset / 24;
		if (this->paintCellTerrain != 9) {
			this->cellDrawOffsetX = this->cellDrawOffsetX + (-1 + Game::frameCount % 3);
		}
	}
	if ((state & 512) != 0) {
		this->cellDrawOffsetX = -this->cellDrawOffsetX;
	}
	if (this->paintCellTerrain == 0) {
		this->landingDustFrame = ((state & 448) >> 6) - 1;
		if (this->landingDustFrame >= 0 && this->landingDustFrame < 5) {
			this->hasLandingDust = 1;
			switch (state & 7) {
				default:
					s0_o = this;
					s1 = 0;
					break;
				case 4:
					s0_o = this;
					s1 = 24;
					break;
				case 2:
					s0_o = this;
					s1 = -24;
					break;
			}
			cast<Game>(s0_o)->landingDustOffX = s1;
			this->landingDustOffY = 13;
			this->landingDustCol = this->paintCellCol;
			this->landingDustRow = this->paintCellRow - 1;
		}
	}
	this->applyWindLiftOffset();
}

void Game::prepareEnemy49Sprite() {
	int32_t col = 0, row = 0, state = 0, moveOffset = 0, moveDir = 0, facing = 0, s1 = 0;
	col = this->paintCellCol;
	row = this->paintCellRow;
	state = Game::cellStates[col][row];
	moveOffset = Game::cellMoveOffsets[col][row];
	moveDir = state & 7;
	this->cellDrawOffsetX = moveOffset * Game::dirDeltas[moveDir];
	this->cellDrawOffsetY = moveOffset * Game::dirDeltas[moveDir + 8];
	Game::curObjectSprites = Game::spritePacks[38];
	facing = (state & 28672) >> 12;
	if ((facing == 2 || facing == 4 || moveDir == 2 || moveDir == 4) && Game::cellTypes[col - 1][row] >= 0 && Game::cellTypes[col + 1][row] >= 0 || (facing == 1 || facing == 3 || moveDir == 1 || moveDir == 3) && Game::cellTypes[col][row - 1] >= 0 && Game::cellTypes[col][row + 1] >= 0) {
		this->cellAnimIndex = 1;
		s1 = 0;
	} else {
		if (moveDir == 1 || moveDir == 3) {
			s1 = moveDir - 1;
		} else {
			s1 = 0;
		}
		cast<Game>(this)->cellAnimIndex = s1;
		s1 = irem(Game::frameCount >> 1, Game::curObjectSprites->getAnimFrameCount(this->cellAnimIndex));
	}
	cast<Game>(this)->cellAnimFrame = s1;
	this->applyWindLiftOffset();
}

void Game::prepareSnakeSprite(int8_t snakeType) {
	int32_t state = 0, moveOffset = 0, moveDir = 0, packIndex = 0, hitCounter = 0, s1 = 0, s3 = 0;
	Ref<Object> s0_o, s2;
	Ref<Game> t3, t5;
	Ref<SpritePack> t4, t6;
	state = Game::cellStates[this->paintCellCol][this->paintCellRow];
	moveOffset = Game::cellMoveOffsets[this->paintCellCol][this->paintCellRow];
	moveDir = state & 7;
	this->cellDrawOffsetX = moveOffset * Game::dirDeltas[moveDir];
	this->cellDrawOffsetY = moveOffset * Game::dirDeltas[moveDir + 8];
	packIndex = snakeType != 19 ? 21 : 4;
	Game::curObjectSprites = Game::spritePacks[packIndex];
	{
		if (this->world == 1) {
			hitCounter = (state & 248) >> 3;
			if (hitCounter <= 0) {
				s0_o = this;
				s1 = 0;
			} else {
				s0_o = this;
				s1 = 2;
			}
			cast<Game>(s0_o)->cellAnimIndex = s1;
			s0_o = this;
			s1 = Game::frameCount;
			s2 = Game::curObjectSprites;
			t5 = cast<Game>(s0_o);
			t6 = cast<SpritePack>(s2);
			s0_o = t5;
			s2 = t6;
			s3 = this->cellAnimIndex;
			goto B1_end;
		}
		hitCounter = (state & 248) >> 3;
		{
			if (hitCounter > 0) {
				s0_o = this;
				s1 = 4;
				cast<Game>(s0_o)->cellAnimIndex = s1;
				goto B2_end;
			}
			this->cellAnimIndex = moveDir - 1;
			if (this->cellAnimIndex < 0) {
				s0_o = this;
				s1 = ((state & 28672) >> 12) - 1;
				cast<Game>(s0_o)->cellAnimIndex = s1;
			}
		}
		B2_end:;
		s0_o = this;
		s1 = Game::frameCount >> 1;
		s2 = Game::curObjectSprites;
		if (this->cellAnimIndex >= 0) {
			t5 = cast<Game>(s0_o);
			t6 = cast<SpritePack>(s2);
			s0_o = t5;
			s2 = t6;
			s3 = this->cellAnimIndex;
		} else {
			t3 = cast<Game>(s0_o);
			t4 = cast<SpritePack>(s2);
			s0_o = t3;
			s2 = t4;
			s3 = 0;
		}
	}
	B1_end:;
	cast<Game>(s0_o)->cellAnimFrame = irem(s1, cast<SpritePack>(s2)->getAnimFrameCount(s3));
	this->applyWindLiftOffset();
}

void Game::preparePressurePlateSprite() {
	int32_t col = 0, row = 0, s1 = 0;
	col = this->paintCellCol;
	row = this->paintCellRow;
	this->objectSpriteSet = 26;
	this->objectSpriteFrame = 0;
	{
		if (Game::isHeavyObject(col, row) && Game::cellMoveOffsets[col][row] <= 12) {
			s1 = -(Game::cellMoveOffsets[col][row] - 12);
			cast<Game>(this)->cellDrawOffsetY = s1;
			goto B1_end;
		}
		if (!this->isPlayerAt(col, row)) {
			if (!this->isPlayerAt(col - 1, row)) {
				if (this->isPlayerAt(col + 1, row) && this->explorerDrawMoveDir == 2 && this->playerStep > 12) {
					s1 = this->playerStep - 12;
					cast<Game>(this)->cellDrawOffsetY = s1;
				}
			} else {
				{
					if (this->explorerDrawMoveDir == 4 && this->playerStep > 12) {
						s1 = this->playerStep - 12;
						cast<Game>(this)->cellDrawOffsetY = s1;
						goto B5_end;
					}
				}
				B5_end:;
			}
		} else {
			{
				if ((this->explorerStateFlags & 4096) != 0) {
					s1 = 12;
					cast<Game>(this)->cellDrawOffsetY = s1;
					goto B6_end;
				}
				{
					if (this->playerStep <= 12) {
						s1 = -(this->playerStep - 12);
						cast<Game>(this)->cellDrawOffsetY = s1;
						goto B7_end;
					}
				}
				B7_end:;
			}
			B6_end:;
		}
	}
	B1_end:;
	this->cellDrawOffsetY = this->cellDrawOffsetY + 24;
	this->cellDrawAnchor = 36;
}

void Game::prepareRedDiamondSprite() {
	int32_t chestType = 0, chestFrame = 0, s2 = 0;
	Ref<Object> s1;
	chestType = Game::cellObjects[this->paintCellCol][this->paintCellRow] & 255;
	chestFrame = Game::cellObjects[this->paintCellCol][this->paintCellRow] >> 8;
	if (chestType != 14 && chestType != 33 || chestFrame > 11) {
		this->terrainSpriteSet = 3;
		this->terrainSpriteFrame = 0 + this->sparklePhase;
		{
			if (chestType == 14) {
				s1 = Game::spritePacks;
				s2 = 8;
				cast<Game>(this)->cellDrawOffsetY = -(cast<Array<Ref<SpritePack>>>(s1)[s2]->getAnimFrameCount(0) - chestFrame);
				goto B2_end;
			}
			if (chestType == 33) {
				s1 = Game::spritePacks;
				s2 = 22;
				cast<Game>(this)->cellDrawOffsetY = -(cast<Array<Ref<SpritePack>>>(s1)[s2]->getAnimFrameCount(0) - chestFrame);
			}
		}
		B2_end:;
	}
}

void Game::prepareWallCrawlerSprite() {
	int32_t col = 0, row = 0, deathStage = 0, moveDir = 0, s1 = 0;
	col = this->paintCellCol;
	row = this->paintCellRow;
	this->terrainSpriteSet = 6;
	deathStage = (Game::cellStates[col][row] & 3840) >> 8;
	if (deathStage < 4) {
		if (deathStage != 0) {
			s1 = 3 + deathStage - 1;
		} else {
			s1 = 0 + (Game::frameCount >> 1) % 3;
		}
		cast<Game>(this)->terrainSpriteFrame = s1;
		moveDir = Game::cellStates[col][row] & 7;
		this->cellDrawOffsetX = Game::cellMoveOffsets[col][row] * Game::dirDeltas[moveDir] + 2;
		this->cellDrawOffsetY = Game::cellMoveOffsets[col][row] * Game::dirDeltas[moveDir + 8] + 2;
		{
			if ((Game::cellStates[col][row] & 16) != 0) {
				switch (moveDir) {
					case 4:
						s1 = this->cellDrawOffsetY + 4;
						cast<Game>(this)->cellDrawOffsetY = s1;
						goto B3_end;
					case 3:
						this->cellDrawOffsetX = this->cellDrawOffsetX + 4;
						return;
					case 2:
						s1 = this->cellDrawOffsetY - 4;
						cast<Game>(this)->cellDrawOffsetY = s1;
						goto B3_end;
					default:
						return;
					case 1:
						this->cellDrawOffsetX = this->cellDrawOffsetX - 4;
						return;
				}
			} else {
				switch (moveDir) {
					case 4:
						s1 = this->cellDrawOffsetY - 4;
						cast<Game>(this)->cellDrawOffsetY = s1;
						return;
					case 3:
						this->cellDrawOffsetX = this->cellDrawOffsetX - 4;
						goto B3_end;
					case 2:
						s1 = this->cellDrawOffsetY + 4;
						cast<Game>(this)->cellDrawOffsetY = s1;
						return;
					default:
						return;
					case 1:
						this->cellDrawOffsetX = this->cellDrawOffsetX + 4;
						goto B3_end;
				}
			}
		}
		B3_end:;
		return;
	}
	this->terrainSpriteSet = -1;
}

void Game::drawExtendingRod() {
	int32_t baseX = 0, tipX = 0, extension = 0, s1 = 0;
	this->screenGraphics->setColor(13883367);
	extension = Game::cellMoveOffsets[this->paintCellCol][this->paintCellRow];
	if ((Game::cellStates[this->paintCellCol][this->paintCellRow] & 1) == 0) {
		baseX = this->cellDrawX + 24;
		tipX = this->cellDrawX + extension;
		s1 = 1;
	} else {
		baseX = this->cellDrawX;
		tipX = this->cellDrawX + 24 - extension;
		s1 = 0;
	}
	cast<Game>(this)->cellAnimFrame = s1;
	this->screenGraphics->drawLine(baseX, this->cellDrawY + 12, tipX, this->cellDrawY + 12);
	if (extension > 0) {
		Game::actors[0]->sprite->drawModule(this->screenGraphics, this->cellAnimFrame, tipX, this->cellDrawY + 12 - 2, 0);
	}
}

void Game::prepareKeyDoorSprite() {
	int32_t doorParam = 0, s1 = 0;
	Ref<Object> s0;
	doorParam = Game::cellObjects[this->paintCellCol][this->paintCellRow] >> 8;
	this->objectSpriteSet = this->paintCellObject != 9 ? 23 : 22;
	if ((doorParam & 512) == 0) {
		if ((doorParam & 256) == 0) {
			s0 = this;
			s1 = 0;
		} else {
			s0 = this;
			s1 = 1;
		}
	} else {
		s0 = this;
		s0 = cast<Game>(s0);
		s1 = (int8_t)(1 + (Game::frameCount >> 2) % 6);
	}
	cast<Game>(s0)->objectSpriteFrame = s1;
}

void Game::prepareDoorBaseSprite() {
	int32_t col = 0, row = 0, param = 0, openStage = 0;
	col = this->paintCellCol;
	row = this->paintCellRow;
	param = Game::cellObjects[col][row] >> 8;
	openStage = ((param & 240) >> 4) - 1;
	if (openStage < 0) {
		openStage = 0;
	}
	if ((Game::cellObjects[col][row - 1] & 255) != 9 && (Game::cellObjects[col][row - 1] & 255) != 8) {
		Game::spritePacks[56]->drawFrame(this->screenGraphics, openStage, this->cellDrawX, this->cellDrawY, 0, 0, 0);
	}
	this->objectSpriteSet = 4;
	this->objectSpriteFrame = (int8_t)(openStage + 3);
}

void Game::prepareRollerSprite() {
	int32_t frame = 0, state = 0, moveOffset = 0, moveDir = 0, trailFrame = 0;
	frame = Game::frameCount;
	state = Game::cellStates[this->paintCellCol][this->paintCellRow];
	moveOffset = Game::cellMoveOffsets[this->paintCellCol][this->paintCellRow];
	if (moveOffset > 24) {
		moveOffset = 24;
	}
	moveDir = state & 7;
	this->cellDrawOffsetX = moveOffset * Game::dirDeltas[moveDir];
	this->cellDrawOffsetY = moveOffset * Game::dirDeltas[moveDir + 8];
	if ((state & 8) != 0) {
		this->terrainSpriteSet = 10;
		this->terrainSpriteFrame = 2 - (frame >> 1) % 3;
		if (moveDir != 3) {
			trailFrame = (frame >> 1) % 5;
			this->screenGraphics->drawImage(Game::objectFrameImages[10][8 + trailFrame], this->cellDrawX + 24 - 12 + this->cellDrawOffsetX + trailFrame * 3, this->cellDrawY + (this->cellDrawOffsetY + 24), 36);
			if ((frame >> 1 & 1) == 0 && Game::cellTypes[this->paintCellCol - 1][this->paintCellRow] >= 0) {
				this->cellDrawOffsetX = this->cellDrawOffsetX - 1;
				this->cellDrawOffsetY = this->cellDrawOffsetY + 1;
			}
		}
	} else {
		this->terrainSpriteSet = 10;
		this->terrainSpriteFrame = (frame >> 1) % 3;
		if (moveDir != 3) {
			trailFrame = (frame >> 1) % 5;
			this->screenGraphics->drawImage(Game::objectFrameImages[10][3 + trailFrame], this->cellDrawX + this->cellDrawOffsetX - trailFrame * 4, this->cellDrawY + (this->cellDrawOffsetY + 24), 36);
			return;
		}
	}
}

void Game::prepareTallTrapSprite() {
	int32_t state = 0, moveOffset = 0, timeLeft = 0, frameIdx = 0, frameDataIndex = 0;
	Ref<SpritePack> pack;
	if (Game::cellTypes[this->paintCellCol][this->paintCellRow + 1] != 16) {
		state = Game::cellStates[this->paintCellCol][this->paintCellRow];
		pack = Game::spritePacks[1];
		Game::curObjectSprites = pack;
		moveOffset = Game::cellMoveOffsets[this->paintCellCol][this->paintCellRow];
		timeLeft = 36 - moveOffset;
		frameIdx = 0;
		this->cellAnimIndex = (state & 7) == 4 ? 1 : 0;
		if (moveOffset != 0) {
			frameDataIndex = 0;
			while (timeLeft > 0) {
				timeLeft = timeLeft - pack->getFrameDuration(this->cellAnimIndex, frameDataIndex);
				frameIdx = frameDataIndex;
				frameDataIndex++;
			}
		}
		this->cellAnimFrame = frameIdx;
		frameDataIndex = (pack->animFirstFrame[this->cellAnimIndex] + frameIdx) * 5;
		this->cellDrawOffsetX = pack->animFrames[frameDataIndex + 2];
		return;
	}
}

void Game::prepareHopperSprite() {
	int32_t state = 0, animTime = 0, frameOrTime = 0, frameDataOrLast = 0, frameCursor = 0, animFrameCount = 0, s0 = 0;
	state = Game::cellStates[this->paintCellCol][this->paintCellRow];
	Game::curObjectSprites = Game::spritePacks[28];
	this->cellAnimIndex = state & 15;
	animTime = (Game::cellStates[this->paintCellCol][this->paintCellRow] & 2088960) >> 13;
	if (this->cellAnimIndex != 10) {
		frameOrTime = Game::frameAtTime(Game::curObjectSprites, this->cellAnimIndex, animTime);
		this->cellAnimFrame = frameOrTime;
		frameDataOrLast = (Game::curObjectSprites->animFirstFrame[this->cellAnimIndex] + frameOrTime) * 5;
		this->cellDrawOffsetX = Game::curObjectSprites->animFrames[frameDataOrLast + 2];
		this->cellDrawOffsetY = Game::curObjectSprites->animFrames[frameDataOrLast + 3];
	} else {
		frameOrTime = animTime;
		frameDataOrLast = 0;
		animFrameCount = Game::curObjectSprites->getAnimFrameCount(this->cellAnimIndex);
		s0 = 0;
		while (true) {
			frameCursor = s0;
			if (frameOrTime <= 0) {
				break;
			}
			frameOrTime = frameOrTime - Game::curObjectSprites->getFrameDuration(this->cellAnimIndex, frameCursor);
			frameDataOrLast = frameCursor;
			s0 = irem(frameCursor + 1, animFrameCount);
		}
		this->cellAnimFrame = frameDataOrLast;
	}
	this->applyWindLiftOffset();
}

int32_t Game::frameAtTime(Ref<SpritePack> pack, int32_t animIndex, int32_t time) {
	int32_t frame = 0, frameCursor = 0;
	frame = 0;
	frameCursor = 0;
	while (time > 0) {
		time = time - pack->getFrameDuration(animIndex, frameCursor);
		frame = frameCursor;
		frameCursor++;
	}
	return frame;
}

int32_t Game::animTimeBeforeFrame(Ref<SpritePack> pack, int32_t animIndex, int32_t frameCount) {
	int32_t total = 0, frame = 0;
	total = 0;
	for (frame = 0; frame < frameCount; frame++) {
		total = total + pack->getFrameDuration(animIndex, frame);
	}
	return total;
}

void Game::updateHopperEnemy() {
	int32_t col = 0, dirToPlayerOrRow = 0, animIsVertical = 0, playerIsLeft = 0, destCol = 0, destRow = 0, destFree = 0, row = 0, variantBits = 0, animIndex = 0, animDuration = 0, onSteam = 0, animTime = 0, frameOrHitDir = 0, nextAnimOrCol = 0, s0 = 0, s1 = 0, s2 = 0;
	Ref<Object> s0_o;
	col = this->updateCellCol;
	row = this->updateCellRow;
	Game::cellUpdateTimers[col][row] = 24;
	variantBits = (Game::cellStates[col][row] & 7168) >> 10;
	animIndex = Game::cellStates[col][row] & 15;
	animDuration = 0;
	onSteam = (Game::cellObjects[col][row] & 255) == 35 ? 1 : 0;
	if (animIndex != 10) {
		animTime = Game::spritePacks[28]->getAnimFrameCount(animIndex);
		for (frameOrHitDir = 0; frameOrHitDir < animTime; frameOrHitDir++) {
			animDuration = animDuration + Game::spritePacks[28]->getFrameDuration(animIndex, frameOrHitDir);
		}
	} else {
		animDuration = 100;
	}
	animTime = (Game::cellStates[col][row] & 2088960) >> 13;
	animTime++;
	Game::cellStates[col][row] = Game::cellStates[col][row] & -2088961 | animTime << 13;
	if (animIndex < 4 || animIndex > 9) {
		s0_o = Game::cellMoveOffsets[col];
		s1 = row;
		s2 = 0;
	} else {
		s0_o = Game::cellMoveOffsets[col];
		s1 = row;
		s2 = 12;
	}
	cast<Array<int8_t>>(s0_o)[s1] = s2;
	if (animTime > animDuration >> 1) {
		if (onSteam == 0) {
			if (this->isPlayerAt(col, row) && animIndex != 10) {
				switch (animIndex) {
					default:
						s0 = Game::oppositeDir[this->explorerStateFlags & 7];
						break;
					case 9:
						s0 = 4;
						break;
					case 7:
					case 8:
						s0 = 3;
						break;
					case 6:
						s0 = 2;
						break;
					case 4:
					case 5:
						s0 = 1;
						break;
				}
				frameOrHitDir = s0;
				this->damageExplorer(1, 48, frameOrHitDir);
			}
			if (this->isCellCrushed(col, row)) {
				Game::cellTypes[col][row] = -1;
				this->killEnemyAt(col, row);
				return;
			}
		}
		if (animTime >= animDuration) {
			Game::wakeCellsAround(col, row);
			dirToPlayerOrRow = this->chooseDirectionToward(col, row, this->playerCol, this->playerRow, 1);
			animIsVertical = 0;
			switch (animIndex) {
				case 0:
				case 3:
				case 4:
				case 7:
				case 9:
					animIsVertical = 1;
					break;
				default:
					break;
			}
			playerIsLeft = dirToPlayerOrRow == 4 ? 1 : 0;
			if (animIsVertical == playerIsLeft) {
				destCol = col - Game::dirDeltas[dirToPlayerOrRow];
				destRow = row - Game::dirDeltas[8 + dirToPlayerOrRow];
				if (playerIsLeft == 0) {
					if (!this->isPlayerAt(destCol, destRow) || animIndex == 1) {
						switch (dirToPlayerOrRow) {
							default:
								s0 = 1;
								break;
							case 3:
								s0 = 8;
								break;
							case 2:
								s0 = 6;
								break;
							case 1:
								s0 = 5;
								break;
						}
						nextAnimOrCol = s0;
					} else {
						nextAnimOrCol = 1;
						destCol = col;
						destRow = row;
					}
				} else {
					if (!this->isPlayerAt(destCol, destRow) || animIndex == 0) {
						switch (dirToPlayerOrRow) {
							default:
								s0 = 0;
								break;
							case 4:
								s0 = 9;
								break;
							case 3:
								s0 = 7;
								break;
							case 1:
								s0 = 4;
								break;
						}
						nextAnimOrCol = s0;
					} else {
						nextAnimOrCol = 0;
						destCol = col;
						destRow = row;
					}
				}
			} else {
				nextAnimOrCol = playerIsLeft == 0 ? 2 : 3;
				destCol = col;
				destRow = row;
			}
			s0 = Game::cellTypes[destCol][destRow] >= 0 ? 0 : 1;
			destFree = s0;
			if (destFree == 0 || onSteam != 0) {
				if (destCol != col || destRow != row) {
					nextAnimOrCol = 0;
				}
				destCol = col;
				destRow = row;
			}
			Game::cellTypes[col][row] = -1;
			Game::cellMoveOffsets[destCol][destRow] = 0;
			Game::cellStates[destCol][destRow] = variantBits << 10 | nextAnimOrCol;
			Game::cellStates[destCol][destRow] = Game::cellStates[destCol][destRow] & -2088961;
			Game::cellTypes[destCol][destRow] = 45;
		}
	}
	if (onSteam == 0) {
		nextAnimOrCol = col;
		dirToPlayerOrRow = row;
		switch (animIndex) {
			case 10:
				nextAnimOrCol = -1;
				dirToPlayerOrRow = -1;
				break;
			case 9:
				nextAnimOrCol++;
				break;
			case 7:
			case 8:
				dirToPlayerOrRow--;
				break;
			case 6:
				nextAnimOrCol--;
				break;
			case 4:
			case 5:
				dirToPlayerOrRow++;
				break;
			case 0:
			case 1:
			case 2:
			case 3:
				break;
			default:
				break;
		}
		if (this->isPlayerAt(nextAnimOrCol, dirToPlayerOrRow)) {
			this->damageExplorer(1, 48, Game::oppositeDir[this->explorerStateFlags & 7]);
		}
	} else {
		{
			if (this->isPlayerAt(col, row) && animIndex != 10) {
				this->damageExplorer(1, 48, Game::oppositeDir[this->explorerStateFlags & 7]);
				goto B23_end;
			}
		}
		B23_end:;
	}
}

void Game::drawPistonTrap() {
	int32_t dirSign = 0, firstFrame = 0, state = 0, segmentCount = 0, extent = 0, segment = 0, s0 = 0, s2 = 0, s3 = 0, s4 = 0;
	Ref<Object> s0_o, s1;
	dirSign = -1;
	firstFrame = 3;
	state = Game::cellStates[this->paintCellCol][this->paintCellRow];
	if ((state & 7) == 3) {
		dirSign = 1;
		firstFrame = 0;
	}
	if ((state & 8) != 0) {
		segmentCount = this->pistonFastSegments;
		s0 = this->pistonFastExtent;
	} else {
		segmentCount = this->pistonSlowSegments;
		s0 = this->pistonSlowExtent;
	}
	extent = s0;
	for (segment = 0; segment < segmentCount; segment++) {
		Game::spritePacks[11]->drawFrame(this->screenGraphics, firstFrame + segment * dirSign, this->cellDrawX + 3, this->cellDrawY + dirSign * (extent - segment * 24), 0, 0, 0);
	}
	if (dirSign != 1) {
		s0_o = Game::spritePacks[42];
		s1 = this->screenGraphics;
		s2 = Game::cellTypes[this->paintCellCol][this->paintCellRow + 1] - 80;
		s3 = this->cellDrawX;
		s4 = this->cellDrawY + 24;
	} else {
		s0_o = Game::spritePacks[42];
		s1 = this->screenGraphics;
		s2 = Game::cellTypes[this->paintCellCol][this->paintCellRow - 1] - 80;
		s3 = this->cellDrawX;
		s4 = this->cellDrawY - 24;
	}
	cast<SpritePack>(s0_o)->drawFrame(cast<Graphics>(s1), s2, s3, s4, 0, 0, 0);
}

void Game::paintGameloftLogo() {
	Ref<Actor> actor;
	int32_t bounceY = 0, dropY = 0, framesLeft = 0, s2 = 0, s3 = 0, s4 = 0;
	Ref<Object> s0, s1;
	actor = Game::actors[0];
	this->screenGraphics->setColor(0);
	this->screenGraphics->fillRect(0, 0, 240, 320);
	actor->y = 136;
	bounceY = 0;
	if (Game::frameCount <= 30) {
		actor->x = Game::frameCount * 4 - 1 + 18;
	} else {
		actor->x = 139;
		actor->setAnimation(1);
		dropY = (Game::frameCount - 30) * 4;
		if (dropY <= 29) {
			actor->sprite->drawFrame(this->screenGraphics, 10, 138, 136, 0, 0, 0);
		} else {
			dropY = 29;
			if (Game::frameCount >= 42) {
				s0 = actor->sprite;
				s1 = this->screenGraphics;
				s2 = 4;
				s3 = 138;
				s4 = 136;
			} else {
				framesLeft = 42 - Game::frameCount;
				bounceY = 0 + irem(framesLeft * framesLeft, (framesLeft >> 1) + 1);
				s0 = actor->sprite;
				s1 = this->screenGraphics;
				s2 = 10;
				s3 = 138;
				s4 = 136 + bounceY;
			}
			cast<SpritePack>(s0)->drawFrame(cast<Graphics>(s1), s2, s3, s4, 0, 0, 0);
			actor->frameIndex = 0;
		}
		actor->y = 136 + dropY;
	}
	actor->y = actor->y + bounceY;
	actor->draw(this->screenGraphics);
	actor->sprite->drawFrame(this->screenGraphics, 5, 138, 160 + bounceY, 0, 0, 0);
}

void Game::drawNumberRightAligned(Ref<Graphics> g, int32_t rightX, int32_t y, int32_t value, Arr<Ref<Image>> digitImages, int32_t imageBase) {
	int32_t digit = 0;
	Ref<Image> digitImage;
	if (value != 0) {
		while (value > 0) {
			digit = value % 10;
			value = value / 10;
			digitImage = digitImages[digit + imageBase];
			rightX = rightX - digitImage->getWidth();
			g->drawImage(digitImage, rightX, y, 0);
		}
		return;
	}
	digitImage = Game::spritePacks[0]->moduleImages[0][0];
	g->drawImage(digitImage, rightX, y, 24);
}

void Game::drawDigitStringRightAligned(Ref<Graphics> g, int32_t rightX, int32_t y, Ref<String> text, Arr<Ref<Image>> digitImages, int32_t imageBase) {
	Ref<Image> digitImage;
	int32_t charCode = 0, charIndex = 0;
	for (charIndex = text->length() - 1; charIndex >= 0; charIndex--) {
		charCode = text->charAt(charIndex);
		if (charCode == 47) {
			charCode = 58;
		}
		charCode = (uint16_t)(charCode - 48);
		digitImage = digitImages[charCode + imageBase];
		g->drawImage(digitImage, rightX, y, 24);
		rightX = rightX - digitImage->getWidth();
	}
}

bool Game::isPlayerInsideBorder() {
	if (this->playerCol <= 0 || this->playerCol >= this->levelW - 1 || this->playerRow <= 0 || this->playerRow >= this->levelH - 1) {
		return 0;
	}
	return 1;
}

void Game::setExplorerAnim(int32_t anim) {
	int32_t prevAnim = 0, liquidLevel = 0, s0 = 0;
	prevAnim = Game::actors[0]->animIndex;
	if (prevAnim != 19 && (this->explorerStateFlags & 16384) == 0 && (this->explorerStateFlags & 2048) == 0) {
		if (this->isPlayerInsideBorder()) {
			s0 = Game::liquidCells != nullptr ? (Game::getLiquidBits(Game::liquidCells[this->playerCol][this->playerRow], 0, 3, 4)) : 0;
			liquidLevel = s0;
			if (liquidLevel == 8 || liquidLevel == 7) {
				switch (anim) {
					case 0:
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:
					case 6:
					case 7:
					case 8:
					case 9:
					case 11:
					case 24:
					case 25:
					case 26:
					case 27:
						anim = 36 + (this->explorerStateFlags & 7) - 1;
						break;
					default:
						break;
				}
			} else {
				if (Game::cellTypes[this->playerCol][this->playerRow + 1] < 0 || Game::cellTypes[this->playerCol][this->playerRow + 1] == 14) {
					switch (anim) {
						case 44:
							s0 = 45;
							anim = s0;
							break;
						case 42:
							s0 = 46;
							anim = s0;
							break;
						case 23:
							s0 = 33;
							anim = s0;
							break;
						case 22:
							s0 = 31;
							anim = s0;
							break;
						case 21:
							s0 = 32;
							anim = s0;
							break;
						case 20:
							s0 = 30;
							anim = s0;
							break;
						case 16:
							s0 = 29;
							anim = s0;
							break;
						case 14:
							s0 = 28;
							anim = s0;
							break;
						case 3:
							s0 = 34;
							anim = s0;
							break;
						case 2:
							s0 = 2;
							anim = s0;
							break;
						case 1:
							s0 = 35;
							anim = s0;
							break;
						case 0:
							s0 = 0;
							anim = s0;
							break;
						default:
							break;
					}
				}
			}
		}
		if (anim != 1000) {
			Game::actors[0]->setAnimation(anim);
		} else {
			Game::actors[3]->setAnimation(0);
			this->explorerStateFlags = this->explorerStateFlags | 16384;
		}
		if (prevAnim != anim) {
			this->playerIdleCountdown = 70;
		}
	}
}

void Game::handleShopInput() {
	int32_t itemStatus = 0, s1 = 0, s2 = 0;
	Ref<Object> s1_o;
	if (!Game::isKeyDown(32944)) {
		if (!Game::isKeyDown(64)) {
			if (!Game::isKeyDown(4097)) {
				if (Game::isKeyDown(262146)) {
					s1 = 1;
					cast<Game>(this)->moveShopCursor(s1);
				}
			} else {
				s1 = -1;
				cast<Game>(this)->moveShopCursor(s1);
			}
			Game::keys = 0;
			itemStatus = Game::getShopItemStatus(this->shopCursor);
			if (itemStatus != 0) {
				this->shopItemCost = Tables::upgradeCosts[this->shopCursor];
				this->shopPriceText->deleteChars(0, this->shopPriceText->length());
				this->shopPriceText->append(this->shopItemCost);
				s1_o = Game::langStrings;
				s2 = 90;
			} else {
				this->shopItemCost = -1;
				s1_o = Game::langStrings;
				s2 = 81;
			}
			cast<Game>(this)->shopMessage = cast<Array<Ref<String>>>(s1_o)[s2];
			this->needsFullRedraw = 1;
			return;
		}
		Game::keys = 0;
		Game::screen = 27;
		this->needsFullRedraw = 1;
		this->worldMapInfoDirty = 1;
		Game::keys = 0;
		return;
	}
	Game::keys = 0;
	this->needsFullRedraw = 1;
	this->buyShopItem(this->shopCursor);
}

int32_t Game::getShopItemStatus(int32_t itemIndex) {
	int32_t maxEnergy = 0, savedDiamonds = 0;
	maxEnergy = Game::saveData[8];
	if (maxEnergy < 4 + itemIndex + 1) {
		savedDiamonds = Game::readU16LE(Game::saveData, 4);
		if (savedDiamonds >= Tables::upgradeCosts[itemIndex]) {
			return 1;
		}
		return -1;
	}
	return 0;
}

void Game::buyShopItem(int32_t itemIndex) {
	this->shopLastDrawnCursor = -1;
	switch (Game::getShopItemStatus(itemIndex)) {
		case 1:
			this->diamondCount = Game::readU16LE(Game::saveData, 4) - Tables::upgradeCosts[this->shopCursor];
			this->shopDiamondsText = nullptr;
			JSystem::gc();
			this->shopDiamondsText = jnew<StringBuffer>(Game::langStrings[110])->append(u" "_j)->append(this->diamondCount)->append(u" "_j)->append(Game::langStrings[109])->toString();
			Game::saveData[4] = (int8_t)(this->diamondCount & 255);
			Game::saveData[5] = (int8_t)(this->diamondCount >> 8 & 255);
			Game::saveData[8] = (int8_t)(4 + itemIndex + 1);
			this->writeSaveRecord();
			this->shopItemCost = -1;
			this->shopMessage = Game::langStrings[81];
			this->shopPurchaseMsgPending = 1;
			this->showPopup(Game::langStrings[91], -1, -1, 5000, 4273165, 0);
			return;
		default:
			return;
		case 0:
			this->shopMessage = Game::langStrings[81];
			return;
		case -1:
			this->shopMessage = Game::langStrings[89];
			return;
	}
}

void Game::moveShopCursor(int32_t delta) {
	this->shopCursor = this->shopCursor + delta;
	if (this->shopCursor < 0) {
		this->shopCursor = 3;
	}
	if (this->shopCursor == 4) {
		this->shopCursor = 0;
	}
}

void Game::handleReturnToMenuInput() {
	if (Game::isKeyDown(64)) {
		Game::screen = 4;
		this->openMenu(4);
	}
	Game::keys = 0;
}

void Game::dispatchKeyInput() {
	int32_t s0 = 0;
	if (Game::keys != 0) {
		if (!Game::isPopupVisible()) {
			switch (Game::screen) {
				case 34:
					this->handleDebugTextInput();
					break;
				case 33:
					this->handleHelpScreenInput();
					break;
				case 31:
					if (!Game::isKeyDown(64)) {
						if (Game::isKeyDown(32944)) {
							this->startNewGame();
						}
					} else {
						this->loadingStep = 0;
						this->loadingStepCount = 8;
						Game::screen = 9;
						this->openMenu(-1);
					}
					s0 = 0;
					Game::keys = s0;
					break;
				case 30:
					{
						if (Game::isKeyDown(32784)) {
							Game::screen = 4;
							if (this->menuId != -1) {
								this->screenSubState = 2;
							} else {
								this->screenSubState = 0;
								this->openMenu(0);
							}
							s0 = 0;
							Game::keys = s0;
							goto B6_end;
						}
					}
					B6_end:;
					break;
				case 27:
					Game::returnScreen = Game::screen;
					this->checkCheatCode();
					this->handleWorldMapInput();
					break;
				case 26:
					this->handleReturnToMenuInput();
					break;
				case 25:
					this->handleShopInput();
					break;
				case 24:
					this->handleCheatMenuInput();
					break;
				case 18:
					break;
				case 17:
				case 20:
					{
						if (Game::isKeyDown(32944)) {
							if (this->screenSubState == 5) {
								this->returnToStageMap();
								this->cleanup();
							}
							this->resultsSkipPressed = 1;
							s0 = 0;
							Game::keys = s0;
							goto B8_end;
						}
					}
					B8_end:;
					break;
				case 15:
					this->handleStageMapInput();
					break;
				case 12:
					this->handleGameOverInput();
					break;
				case 10:
					break;
				case 4:
					this->handleMenuInput();
					break;
				case 2:
				case 7:
				case 32:
					this->handleMenuInput();
					break;
				case 1:
					if (this->gotElementalDiamond || this->bossTreasureTaken) {
						Game::keys = 0;
					}
					Game::returnScreen = Game::screen;
					this->checkCheatCode();
					this->handlePlayInput();
					break;
				default:
					break;
			}
			if (!this->isKeyReleased) {
				if ((this->explorerStateFlags & 7) != 0) {
					this->keyHoldTimer = 10;
				}
				return;
			}
			return;
		}
		this->hidePopup(1);
		Game::keys = 0;
		return;
	}
	this->requestedMoveDir = 0;
}

void Game::startNewGame() {
	this->isNewGame = 1;
	Game::screen = 16;
	this->loadingStep = 0;
	this->loadingStepCount = 6;
	this->lives = 0;
	this->redDiamondCount = 0;
	this->diamondCount = 0;
	this->hasCompass = 0;
	this->loadingTipIndex = 0;
	Game::latestUnlockedStage = 0;
}

void Game::handleHelpScreenInput() {
	if (Game::isKeyDown(64)) {
		if (this->menuId == 0) {
			Game::screen = 4;
			this->openMenu(0);
			this->sound->play(19);
		}
		if (this->menuId == 1) {
			Game::screen = 2;
			Game::menuFullRedraw = 1;
			this->hudNeedsRedraw = 1;
			this->openMenu(1);
		}
	}
}

void Game::checkCheatCode() {
	int32_t s0 = 0;
	if (Game::cheatCodeProgress >= Game::cheatCodeKeys->length || !Game::isKeyDown(Game::cheatCodeKeys[Game::cheatCodeProgress])) {
		if (!Game::isKeyDown(Game::cheatCodeKeys[0])) {
			s0 = 0;
		} else {
			Game::keys = 0;
			s0 = 1;
		}
		Game::cheatCodeProgress = s0;
	} else {
		Game::keys = 0;
		Game::cheatCodeProgress = (int8_t)(Game::cheatCodeProgress + 1);
		if (Game::cheatCodeProgress == Game::cheatCodeKeys->length) {
			Game::keys = 0;
			Game::screen = 24;
			this->cheatMaxEnergy = Game::saveData[8];
			this->cheatWeaponFlags = Game::saveData[9];
			this->cheatUnlockAllStages = 0;
			this->cheatUnlockSecretStages = 0;
			return;
		}
	}
}

void Game::handleWorldMapInput() {
	int32_t s1 = 0;
	if (this->placingElementalIndex != -1 || this->worldUnlockAnimIndex != 0) {
		Game::keys = 0;
		return;
	}
	{
		if (Game::isKeyDown(32944)) {
			s1 = 4;
			this->worldMapCommand = s1;
			goto B2_end;
		}
		if (!Game::isKeyDown(64)) {
			{
				if (Game::isKeyDown(4097)) {
					s1 = 0;
					this->worldMapCommand = s1;
					goto B4_end;
				}
				{
					if (Game::isKeyDown(262146)) {
						s1 = 2;
						this->worldMapCommand = s1;
						goto B5_end;
					}
					{
						if (Game::isKeyDown(16388)) {
							s1 = 3;
							this->worldMapCommand = s1;
							goto B6_end;
						}
						if (Game::isKeyDown(65544)) {
							s1 = 1;
							this->worldMapCommand = s1;
						}
					}
					B6_end:;
				}
				B5_end:;
			}
			B4_end:;
		} else {
			this->cleanup();
			Game::screen = 9;
			this->loadingStepCount = 8;
			this->openMenu(-1);
			this->loadingStep = 0;
		}
	}
	B2_end:;
	Game::keys = 0;
}

void Game::cheatSkipStage() {
	if (this->world != 0 || this->stage != 13) {
		this->usedMainExit = Game::isKeyDown(524288);
		this->fromStageClear = !this->usedMainExit ? 1 : 0;
		this->livesLostInStage = 0;
		this->hitsTaken = 0;
		this->isExitingLevel = 1;
		this->playerCol = this->levelW + 5 + 1;
		return;
	}
	this->activeCutscene = nullptr;
	this->playerCol = 60;
	this->playerRow = 3;
}

void Game::handleCheatMenuInput() {
	int32_t closeMenu = 0, worldIndex = 0, lastStage = 0, stageIndex = 0, s1 = 0;
	closeMenu = 0;
	if (!Game::isKeyDown(512)) {
		if (!Game::isKeyDown(65536)) {
			if (!Game::isKeyDown(131072)) {
				if (!Game::isKeyDown(262144)) {
					if (!Game::isKeyDown(524288)) {
						if (!Game::isKeyDown(32768)) {
							if (!Game::isKeyDown(1024)) {
								{
									if (Game::isKeyDown(64)) {
										closeMenu = 1;
										goto B8_end;
									}
									if (Game::isKeyDown(32944)) {
										Game::saveData[8] = (int8_t)this->cheatMaxEnergy;
										Game::saveData[9] = (int8_t)this->cheatWeaponFlags;
										if (this->cheatUnlockAllStages || this->cheatUnlockSecretStages) {
											for (worldIndex = 0; worldIndex <= 2; worldIndex++) {
												lastStage = this->getWorldFirstSecretStage(worldIndex);
												if (worldIndex == 2) {
													lastStage++;
												}
												for (stageIndex = 0; stageIndex <= lastStage; stageIndex++) {
													this->addStageFlags(worldIndex, stageIndex, 2);
													this->addStageFlags(worldIndex, stageIndex, 64);
												}
												this->raiseSavedLatestStage(worldIndex, lastStage);
											}
											if (this->cheatUnlockSecretStages) {
												for (worldIndex = 0; worldIndex <= 2; worldIndex++) {
													lastStage = this->getWorldStageCount(worldIndex);
													if (worldIndex == 0) {
														lastStage--;
													}
													for (stageIndex = this->getWorldFirstSecretStage(worldIndex); stageIndex < lastStage; stageIndex++) {
														this->addStageFlags(worldIndex, stageIndex, 2);
														this->addStageFlags(worldIndex, stageIndex, 64);
													}
													this->raiseSavedLatestStage(worldIndex, lastStage - 1);
												}
											}
										}
										this->bankStageDiamonds();
										this->bankStageRedDiamonds();
										this->writeSaveRecord();
										closeMenu = 1;
									}
								}
								B8_end:;
							} else {
								this->cheatUnlockSecretStages = !this->cheatUnlockSecretStages ? 1 : 0;
							}
						} else {
							Game::screen = 34;
						}
					} else {
						this->cheatUnlockAllStages = !this->cheatUnlockAllStages ? 1 : 0;
					}
				} else {
					if (Game::returnScreen != 1) {
						this->cheatWeaponFlags = this->cheatWeaponFlags << 1;
						{
							if (this->cheatWeaponFlags == 0) {
								s1 = 1;
								cast<Game>(this)->cheatWeaponFlags = s1;
								goto B19_end;
							}
							if (this->cheatWeaponFlags > 8) {
								s1 = 0;
								cast<Game>(this)->cheatWeaponFlags = s1;
							}
						}
						B19_end:;
						if (this->cheatWeaponFlags <= 2) {
							Game::saveData[10] = 0;
						} else {
							Game::saveData[10] = 1;
						}
					}
				}
			} else {
				this->redDiamondCount = this->redDiamondCount + 5;
			}
		} else {
			this->diamondCount = this->diamondCount + 50;
		}
	} else {
		this->cheatPassLevels = !this->cheatPassLevels ? 1 : 0;
	}
	if (closeMenu != 0) {
		this->closeCheatMenu();
	}
	Game::keys = 0;
}

void Game::closeCheatMenu() {
	Game::screen = Game::returnScreen;
	if (Game::returnScreen != 27) {
		if (Game::returnScreen == 1) {
			this->requestHudRedraw();
		}
	} else {
		this->needsFullRedraw = 1;
		this->worldMapInfoDirty = 1;
	}
	Game::keys = 0;
}

void Game::handleDebugTextInput() {
	int32_t maxIndex = 0, textIndex = 0, s0 = 0;
	maxIndex = 0;
	textIndex = 0;
	if (Game::isKeyDown(33008)) {
		this->closeCheatMenu();
		Game::freeSpritePack(Game::tipSprites, 1);
		Game::tipSprites = nullptr;
	}
	if (Game::isKeyDown(4097)) {
		this->debugTextPage = this->debugTextPage - 1;
		if (this->debugTextPage < 0) {
			this->debugTextPage = 0;
		}
	}
	if (Game::isKeyDown(262146)) {
		this->debugTextPage = this->debugTextPage + 1;
		if (this->debugTextPage >= 2) {
			this->debugTextPage = 1;
		}
	}
	textIndex = this->debugTextIndices[this->debugTextPage];
	if (Game::isKeyDown(16388)) {
		textIndex--;
	}
	if (Game::isKeyDown(65544)) {
		textIndex++;
	}
	if (textIndex < 0) {
		textIndex = 0;
	}
	switch (this->debugTextPage) {
		case 1:
			s0 = 9;
			maxIndex = s0;
			break;
		case 0:
			s0 = 115;
			maxIndex = s0;
			break;
		default:
			break;
	}
	if (textIndex >= maxIndex) {
		textIndex = maxIndex - 1;
	}
	this->debugTextIndices[this->debugTextPage] = textIndex;
	Game::keys = 0;
}

void Game::handleGameOverInput() {
	if (Game::isKeyDown(32944)) {
		this->lives = 5;
		Game::saveData[3] = (int8_t)this->lives;
		if (this->specialStageType != 2) {
			Game::addToSaveCounter(4, -500);
			Game::screen = 15;
			this->needLevelCleanup = 1;
			this->needFreeMapRes = 1;
			this->openStageMap();
			return;
		}
		this->startLevelLoading();
		return;
	}
}

void Game::handlePlayInput() {
	int32_t scratch = 0, checkCol = 0, checkType = 0, checkObject = 0, neighborIndex = 0, neighborCol = 0, neighborRow = 0, neighborDir = 0, isEnemy = 0, hitDir = 0, facing = 0, isTarget = 0, aimDir = 0, rangedDir = 0, targetsBothSides = 0, targetMask = 0, sideOrDxTable_n = 0, signOrDyTable_n = 0, distance = 0, s0 = 0, s1 = 0, s2 = 0;
	Arr<int32_t> aimMasks, sideOrDxTable, signOrDyTable, t2, t3, t4;
	Ref<Object> s0_o;
	if (this->cheatPassLevels && (Game::isKeyDown(524288) || Game::isKeyDown(131072))) {
		this->cheatSkipStage();
	}
	if ((this->gateRevealState == 0 || Game::isKeyDown(32944)) && this->entryWalkRemaining == 0 && !this->isExitingLevel && this->explorerEnergy > 0 && Game::actors[0]->animIndex != 19 && !this->respawnPanActive) {
		if (this->activeCutscene == nullptr) {
			if (this->encasedStruggleCount <= 0) {
				if (!Game::isKeyDown(4097)) {
					if (!Game::isKeyDown(262146)) {
						if (!Game::isKeyDown(16388)) {
							if (!Game::isKeyDown(65544)) {
								if (!Game::isKeyDown(32784)) {
									if (!Game::isKeyDown(256)) {
										if (Game::isKeyDown(32944)) {
											this->openPauseMenu();
											Game::keys = 0;
										}
									} else {
										this->hintBubbleImageSet = -1;
										scratch = Game::actors[0]->animIndex;
										if (scratch == 36 + (this->explorerStateFlags & 7) - 1) {
											if ((Game::cellObjects[this->playerCol][this->playerRow] & 255) != 4) {
												this->playSound(2);
												this->setExplorerAnim(19);
											} else {
												this->restoreCheckpoint();
											}
										}
										switch (scratch) {
											case 0:
											case 1:
											case 2:
											case 3:
											case 34:
											case 35:
												if ((Game::cellObjects[this->playerCol][this->playerRow] & 255) != 4) {
													this->playSound(2);
													this->setExplorerAnim(19);
												} else {
													this->restoreCheckpoint();
												}
												break;
											default:
												break;
										}
									}
								} else {
									Game::keys = 0;
									if (this->checkpointCol != this->playerCol || this->checkpointRow != this->playerRow || (Game::cellObjects[this->playerCol][this->playerRow] & 255) != 4) {
										s0 = Game::liquidCells != nullptr ? (Game::getLiquidBits(Game::liquidCells[this->playerCol][this->playerRow], 0, 3, 4)) : 0;
										scratch = s0;
										if (scratch != 8 && scratch != 7) {
											facing = this->explorerStateFlags & 7;
											aimDir = -1;
											rangedDir = -1;
											targetsBothSides = 0;
											if (Game::saveData[9] >= 2) {
												targetMask = 0;
												for (sideOrDxTable_n = 0; sideOrDxTable_n < 2; sideOrDxTable_n++) {
													s0 = sideOrDxTable_n != 0 ? -1 : 1;
													signOrDyTable_n = s0;
													if (signOrDyTable_n > 0 && this->playerCol < this->levelW - 3 || signOrDyTable_n < 0 && this->playerCol > 3) {
														for (distance = 1; distance <= 3; distance++) {
															checkCol = this->playerCol + signOrDyTable_n * distance;
															checkType = Game::cellTypes[checkCol][this->playerRow];
															checkObject = Game::cellObjects[checkCol][this->playerRow] & 255;
															if (checkObject != 7 || (Game::cellObjects[checkCol][this->playerRow] >> 8 & 240) != 0) {
																if (checkType != 48 || (Game::cellStates[checkCol][this->playerRow] & 8) == 0) {
																	switch (checkType) {
																		case 11:
																		case 19:
																		case 43:
																			if (signOrDyTable_n <= 0) {
																				if (signOrDyTable_n < 0) {
																					s0 = targetMask;
																					s1 = 4;
																					targetMask = s0 | s1;
																				}
																			} else {
																				s0 = targetMask;
																				s1 = 2;
																				targetMask = s0 | s1;
																			}
																			if (distance == 1) {
																				s0 = 4;
																			} else {
																				if (rangedDir >= 0) {
																					targetsBothSides = 1;
																					if (targetMask != 2) {
																						s0 = targetMask != 4 ? -1 : 4;
																					} else {
																						s0 = 2;
																					}
																					rangedDir = s0;
																					s0 = 4;
																				} else {
																					rangedDir = signOrDyTable_n <= 0 ? 4 : 2;
																					s0 = 4;
																				}
																			}
																			distance = s0;
																			break;
																		case 0:
																		case 1:
																		case 8:
																		case 9:
																		case 14:
																		case 47:
																		case 48:
																			if (distance == 1) {
																				s0 = 4;
																			} else {
																				if (rangedDir >= 0) {
																					targetsBothSides = 1;
																					if (targetMask != 2) {
																						s0 = targetMask != 4 ? -1 : 4;
																					} else {
																						s0 = 2;
																					}
																					rangedDir = s0;
																					s0 = 4;
																				} else {
																					rangedDir = signOrDyTable_n <= 0 ? 4 : 2;
																					s0 = 4;
																				}
																			}
																			distance = s0;
																			break;
																		default:
																			s0 = 4;
																			distance = s0;
																			break;
																		case -1:
																			break;
																	}
																}
															} else {
																s0 = 4;
																distance = s0;
															}
														}
													}
												}
											}
											if (Game::saveData[9] >= 1) {
												this->requestedMoveDir = 5;
												targetMask = 0;
												t2 = newArray<int32_t>(12);
												t2[0] = 0;
												t2[1] = 1;
												t2[2] = 0;
												t2[3] = -1;
												t2[4] = 1;
												t2[5] = 1;
												t2[6] = -1;
												t2[7] = -1;
												t2[8] = 0;
												t2[9] = 2;
												t2[10] = 0;
												t2[11] = -2;
												sideOrDxTable = t2;
												t3 = newArray<int32_t>(12);
												t3[0] = -1;
												t3[1] = 0;
												t3[2] = 1;
												t3[3] = 0;
												t3[4] = -1;
												t3[5] = 1;
												t3[6] = 1;
												t3[7] = -1;
												t3[8] = -2;
												t3[9] = 0;
												t3[10] = 2;
												t3[11] = 0;
												signOrDyTable = t3;
												t4 = newArray<int32_t>(12);
												t4[0] = 0;
												t4[1] = 0;
												t4[2] = 0;
												t4[3] = 0;
												t4[4] = 3;
												t4[5] = 6;
												t4[6] = 12;
												t4[7] = 9;
												t4[8] = 1;
												t4[9] = 2;
												t4[10] = 4;
												t4[11] = 8;
												aimMasks = t4;
												for (neighborIndex = 0; neighborIndex < sideOrDxTable->length; neighborIndex++) {
													neighborCol = this->playerCol + sideOrDxTable[neighborIndex];
													neighborRow = this->playerRow + signOrDyTable[neighborIndex];
													if (neighborCol >= 0 && neighborCol < this->levelW && neighborRow >= 0) {
														if (neighborRow < this->levelH) {
															neighborDir = Game::cellStates[neighborCol][neighborRow] & 7;
															isEnemy = 0;
															hitDir = -1;
															isTarget = 0;
															switch (Game::cellTypes[neighborCol][neighborRow]) {
																case 46:
																case 49:
																case 50:
																	if (aimMasks[neighborIndex] == 0) {
																		targetMask++;
																		isTarget = 1;
																	}
																	break;
																case 45:
																	if ((Game::cellStates[neighborCol][neighborRow] & 15) != 10) {
																		isEnemy = 1;
																	}
																	break;
																case 19:
																case 43:
																	if ((Game::cellStates[neighborCol][neighborRow] & 248) == 0) {
																		isEnemy = 1;
																	}
																	break;
																case 9:
																case 18:
																case 30:
																	if (aimMasks[neighborIndex] == 0) {
																		isTarget = 1;
																	}
																	break;
																default:
																	break;
															}
															if (isEnemy != 0) {
																if (aimMasks[neighborIndex] != 0) {
																	if (Game::cellMoveOffsets[neighborCol][neighborRow] >= 12) {
																		if ((aimMasks[neighborIndex] & 1) == 0 || neighborDir != 3) {
																			if ((aimMasks[neighborIndex] & 8) != 0 && neighborDir == 2) {
																				if (signOrDyTable[neighborIndex] != 0) {
																					if (signOrDyTable[neighborIndex] >= 0) {
																						if (signOrDyTable[neighborIndex] > 0) {
																							s0 = 3;
																							hitDir = s0;
																						}
																					} else {
																						s0 = 1;
																						hitDir = s0;
																					}
																				} else {
																					s0 = 4;
																					hitDir = s0;
																				}
																			}
																		} else {
																			if (sideOrDxTable[neighborIndex] != 0) {
																				if (sideOrDxTable[neighborIndex] >= 0) {
																					if (sideOrDxTable[neighborIndex] > 0) {
																						s0 = 2;
																						hitDir = s0;
																					}
																				} else {
																					s0 = 4;
																					hitDir = s0;
																				}
																			} else {
																				s0 = 1;
																				hitDir = s0;
																			}
																		}
																	}
																} else {
																	s0 = neighborIndex + 1;
																	hitDir = s0;
																}
																if (hitDir != -1) {
																	isTarget = 1;
																	targetMask++;
																}
															}
															if (isTarget != 0) {
																if (targetMask != 0) {
																	if (targetMask != 1) {
																		aimDir = facing;
																		break;
																	}
																	aimDir = hitDir;
																} else {
																	if (facing != neighborIndex + 1) {
																		if (aimDir < 0) {
																			aimDir = neighborIndex + 1;
																		}
																	} else {
																		aimDir = facing;
																	}
																}
															}
														}
													}
												}
											}
											{
												if (aimDir > 0 && rangedDir == facing) {
													this->requestedMoveDir = 6;
													s0_o = this;
													s1 = this->explorerStateFlags & -8;
													s2 = facing;
													cast<Game>(s0_o)->explorerStateFlags = s1 | s2;
													goto B63_end;
												}
												{
													if (aimDir > 0 && rangedDir < 0 && targetsBothSides == 0) {
														s0_o = this;
														s1 = this->explorerStateFlags & -8;
														s2 = aimDir;
														cast<Game>(s0_o)->explorerStateFlags = s1 | s2;
														goto B64_end;
													}
													{
														if (aimDir < 0 && rangedDir > 0 && targetsBothSides == 0) {
															this->requestedMoveDir = 6;
															s0_o = this;
															s1 = this->explorerStateFlags & -8;
															s2 = rangedDir;
															cast<Game>(s0_o)->explorerStateFlags = s1 | s2;
															goto B65_end;
														}
														{
															if (targetsBothSides != 0 && (facing == 2 || facing == 4)) {
																this->requestedMoveDir = 6;
																s0_o = this;
																s1 = this->explorerStateFlags & -8;
																s2 = facing;
																cast<Game>(s0_o)->explorerStateFlags = s1 | s2;
																goto B66_end;
															}
															if (targetsBothSides != 0 && rangedDir > 0) {
																this->requestedMoveDir = 6;
																s0_o = this;
																s1 = this->explorerStateFlags & -8;
																s2 = rangedDir;
																cast<Game>(s0_o)->explorerStateFlags = s1 | s2;
															}
														}
														B66_end:;
													}
													B65_end:;
												}
												B64_end:;
											}
											B63_end:;
											if (this->requestedMoveDir == 6 && (Game::cellObjects[this->playerCol][this->playerRow] & 255) == 2 && Game::cellObjects[this->playerCol][this->playerRow] >> 8 == 1) {
												this->hintBubbleImageSet = -1;
												this->clearConnectedObjects(this->playerCol, this->playerRow, 2);
											}
										}
									} else {
										this->playSound(9);
										this->restoreCheckpoint();
									}
								}
							} else {
								this->requestedMoveDir = 2;
							}
						} else {
							this->requestedMoveDir = 4;
						}
					} else {
						this->requestedMoveDir = 3;
					}
				} else {
					this->requestedMoveDir = 1;
				}
				if (this->requestedMoveDir != 5 && this->currentMoveDir == 0 && this->keyHoldTimer == 0 && this->requestedMoveDir != (this->explorerStateFlags & 7)) {
					this->explorerStateFlags = this->explorerStateFlags | 4096;
				}
			} else {
				scratch = 1;
				if (!Game::isKeyDown(4097)) {
					if (!Game::isKeyDown(262146)) {
						if (!Game::isKeyDown(16388)) {
							if (!Game::isKeyDown(65544)) {
								if (!Game::isKeyDown(32784)) {
									if (!Game::isKeyDown(32944)) {
										scratch = 0;
									} else {
										this->openPauseMenu();
										Game::keys = 0;
									}
								}
							} else {
								this->frozenShakeX = 5;
							}
						} else {
							this->frozenShakeX = -5;
						}
					} else {
						this->frozenShakeY = 5;
					}
				} else {
					this->frozenShakeY = -5;
				}
				if (scratch != 0) {
					this->encasedStruggleCount = this->encasedStruggleCount - 1;
					if (this->encasedStruggleCount == 0) {
						if ((int8_t)(Game::cellObjects[this->playerCol][this->playerRow] & 255) < 0) {
							Game::cellObjects[this->playerCol][this->playerRow] = 32;
						}
						if (Game::cellTypes[this->playerCol][this->playerRow] == 9) {
							Game::cellTypes[this->playerCol][this->playerRow] = -1;
						}
						this->invulnTimer = 40LL;
						this->playerStep = 0;
						this->explorerStateFlags = this->explorerStateFlags & -113 | 0;
						this->setExplorerAnim(this->endHurtState());
					}
					Game::keys = 0;
					return;
				}
			}
			return;
		}
		if (!Game::isKeyDown(32784)) {
			if (Game::isKeyDown(32944)) {
				this->activeCutscene->isSkipped = 1;
			}
		} else {
			this->activeCutscene->onConfirmPressed();
		}
		Game::keys = 0;
		return;
	}
	Game::keys = 0;
}

void Game::handleMenuInput() {
	if (this->menuConfirmStep < 0 || this->menuConfirmStep > 2) {
		if (!Game::isKeyDown(4097)) {
			if (!Game::isKeyDown(262146)) {
				if (!Game::isKeyDown(32944)) {
					if (Game::isKeyDown(64)) {
						this->handleMenuBack();
					}
				} else {
					if (this->menuConfirmStep < 0 || this->menuConfirmStep > 2) {
						this->menuConfirmStep = 0;
						this->menuConfirmStepTime = JSystem::currentTimeMillis();
					}
				}
			} else {
				if (JSystem::currentTimeMillis() - this->menuMoveLockTime < 300LL) {
					return;
				}
				this->moveMenuCursorDown();
				if (this->menuId == 0 && this->menuCursor == 1 && !this->hasSavedGame) {
					this->moveMenuCursorDown();
				}
			}
		} else {
			if (JSystem::currentTimeMillis() - this->menuMoveLockTime < 300LL) {
				return;
			}
			this->moveMenuCursorUp();
			if (this->menuId == 0 && this->menuCursor == 1 && !this->hasSavedGame) {
				this->moveMenuCursorUp();
			}
		}
		Game::keys = 0;
		return;
	}
	Game::keys = 0;
}

void Game::handleMenuBack() {
	switch (this->menuId) {
		case 5:
			Game::menuFullRedraw = 1;
			Game::menuRepaintPlayfield = 0;
			if (Game::screen == 2) {
				this->openMenu(1);
				this->requestHudRedraw();
				Game::menuRepaintPlayfield = 1;
			}
			if (Game::screen != 4) {
				return;
			}
			this->openMenu(0);
			this->playSound(19);
			return;
		case 4:
			this->openMenu(2);
			return;
		default:
			return;
		case 2:
			Game::screen = 9;
			this->openMenu(0);
			this->loadingStepCount = 8;
			this->loadingStep = 0;
			return;
		case -1:
			return;
	}
}

void Game::strikeCell(int32_t col, int32_t row) {
	int32_t targetCol = 0, targetRow = 0, canDamage = 0, isHit = 0, value = 0, moveOffset = 0, isDamageable = 0, handled = 0, hasFreezePower = 0, hitSolid = 0, targetType = 0, i = 0, s0 = 0;
	Arr<int32_t> dCols, dRows, t1, t2;
	t1 = newArray<int32_t>(5);
	t1[0] = 0;
	t1[1] = 1;
	t1[2] = -1;
	t1[3] = 0;
	t1[4] = 0;
	dCols = t1;
	t2 = newArray<int32_t>(5);
	t2[0] = 0;
	t2[1] = 0;
	t2[2] = 0;
	t2[3] = 1;
	t2[4] = -1;
	dRows = t2;
	handled = 0;
	hasFreezePower = Game::saveData[9] >= 8 ? 1 : 0;
	hitSolid = 0;
	switch (Game::cellTypes[col][row]) {
		default:
			if (Game::cellTypes[col][row] - 80 >= 0 || (Game::cellObjects[col][row] & 255) == 7 && (Game::cellObjects[col][row] >> 8 & 240) == 0) {
				hitSolid = 1;
				s0 = 1;
				handled = s0;
			}
			break;
		case 30:
			handled = 1;
			if (Game::cellStates[col][row] == 0) {
				this->playSound(11);
				Game::cellStates[col][row] = 1;
			}
			break;
		case 18:
			s0 = this->tryPullLever();
			handled = s0;
			break;
		case 16:
			handled = 1;
			hitSolid = 1;
			break;
		case 10:
			if (this->liquidState == 3 && Game::cellStates[col][row] <= 0) {
				handled = 1;
				Game::cellStates[col][row] = 1;
				this->eraseCellInBuffer(col, row);
			}
			break;
		case 9:
			if ((this->explorerStateFlags & 8192) == 0) {
				this->explorerStateFlags = this->explorerStateFlags | 8192;
				handled = 1;
				this->thawFrozenCell(col, row);
			}
			break;
		case 0:
			hitSolid = 1;
			break;
	}
	if (hitSolid != 0) {
		Game::vibrateDevice(200);
		this->playSound(6);
		this->setExplorerAnim(41 + (this->explorerStateFlags & 7) - 1);
	}
	if (handled == 0) {
		for (i = 0; i < 5; i++) {
			targetCol = col + dCols[i];
			targetRow = row + dRows[i];
			if (targetCol >= 0 && targetCol < this->levelW && targetRow >= 0) {
				if (targetRow < this->levelH) {
					targetType = Game::cellTypes[targetCol][targetRow];
					canDamage = 0;
					isHit = 0;
					switch (targetType) {
						case 19:
						case 43:
						case 45:
						case 46:
						case 49:
							value = Game::cellStates[targetCol][targetRow] & 7;
							s0 = value != 0 ? (Game::cellMoveOffsets[targetCol][targetRow]) : 0;
							moveOffset = s0;
							isDamageable = targetType != 49 && targetType != 46 ? 1 : 0;
							if (Game::doMovingCellsTouch(col, row, 0, 0, targetCol, targetRow, value, moveOffset)) {
								isHit = 1;
								canDamage = isDamageable;
							}
							if (isHit != 0) {
								this->playSound(10);
							}
							break;
						case 1:
							if (targetCol == this->playerCol - Game::dirDeltas[this->explorerStateFlags & 7] && targetRow == this->playerRow - Game::dirDeltas[(this->explorerStateFlags & 7) + 8]) {
								isHit = 1;
							}
							break;
						default:
							break;
					}
					if (hasFreezePower == 0 || isHit == 0 || targetCol == this->playerCol && targetRow == this->playerRow) {
						if (canDamage != 0) {
							this->explorerStateFlags = this->explorerStateFlags | 8192;
							if (targetType != 45) {
								this->hitCreature(targetType, targetCol, targetRow);
							} else {
								value = (Game::cellStates[targetCol][targetRow] & 7168) >> 10;
								if (value != 3) {
									value++;
									Game::cellStates[targetCol][targetRow] = 10 | value << 10;
									Game::cellStates[targetCol][targetRow] = Game::cellStates[targetCol][targetRow] & -249 | 120;
									Game::cellMoveOffsets[targetCol][targetRow] = 0;
								} else {
									Game::cellTypes[targetCol][targetRow] = -1;
									this->killEnemyAt(targetCol, targetRow);
								}
							}
						}
					} else {
						value = this->freezeCell(targetCol, targetRow);
						if (value) {
							this->explorerStateFlags = this->explorerStateFlags | 8192;
						}
					}
				}
			}
		}
	}
}

void Game::thawFrozenCell(int32_t col, int32_t row) {
	int32_t facing = 0, s1 = 0, s2 = 0;
	Ref<Object> s0_o;
	if (Game::isFreezeRayBlocker(col, row)) {
		return;
	}
	Game::wakeCellsAround(col, row);
	facing = !this->isPlayerAt(col, row - 1) ? 1 : 2;
	switch ((Game::cellStates[col][row] & 264241152) >> 22) {
		case 39:
			Game::cellTypes[col][row] = 49;
			Game::cellStates[col][row] = facing;
			return;
		case 37:
			if ((Game::cellStates[col][row] & 268435456) == 0) {
				s0_o = Game::cellTypes[col];
				s1 = row;
				s2 = 19;
			} else {
				s0_o = Game::cellTypes[col];
				s1 = row;
				s2 = 43;
			}
			cast<Array<int8_t>>(s0_o)[s1] = s2;
			Game::cellStates[col][row] = facing;
			this->hitCreature(19, col, row);
			return;
		case 36:
			Game::cellTypes[col][row] = 46;
			Game::cellStates[col][row] = 0;
			Game::cellMoveOffsets[col][row] = 0;
			return;
		default:
			return;
		case 35:
			Game::cellTypes[col][row] = 45;
			Game::cellStates[col][row] = Game::cellStates[col][row] & -16 | 10;
			return;
		case 34:
			Game::cellTypes[col][row] = 1;
			this->redrawCellInBuffer(col, row);
			return;
	}
}

bool Game::tryPullLever() {
	int32_t layerObj = 0, s1 = 0;
	if (this->liquidState != 3) {
		return 0;
	}
	layerObj = Game::cellObjects[this->playerCol][this->playerRow] & 255;
	if (this->leverMoveDir == 0 && layerObj != 15 && layerObj != 16) {
		this->playSound(0);
		if (this->switchWallsPhase > 0) {
			s1 = -1;
		} else {
			s1 = 1;
		}
		cast<Game>(this)->leverMoveDir = s1;
	}
	return 1;
}

void Game::hitCreature(int32_t type, int32_t col, int32_t row) {
	int32_t state = 0;
	state = Game::cellStates[col][row];
	if (type == 43 && (state & 248) == 0) {
		if ((state & 98304) == 0) {
			Game::cellTypes[col][row] = -1;
			this->killEnemyAt(col, row);
			return;
		}
		state = state - 32768;
		state = state & -16646145 | col << 17;
		state = state & -2130706433 | row << 24;
		state = (state & 7) == 1 || (state & 7) == 3 ? state | INT32_MIN : state & 2147483647;
	}
	state = state & -249 | 120;
	Game::cellStates[col][row] = state;
}

void Game::tickExpiringLayerObject() {
	int32_t age = 0, s1 = 0, s2 = 0;
	Ref<Object> s0;
	age = Game::cellObjects[this->updateCellCol][this->updateCellRow] >> 8;
	age++;
	if (age < 16) {
		Game::cellUpdateTimers[this->updateCellCol][this->updateCellRow] = 24;
		s0 = Game::cellObjects[this->updateCellCol];
		s1 = this->updateCellRow;
		s2 = age << 8 | 36;
	} else {
		s0 = Game::cellObjects[this->updateCellCol];
		s1 = this->updateCellRow;
		s2 = -1;
	}
	cast<Array<int32_t>>(s0)[s1] = s2;
}

void Game::crushCellContents(int32_t col, int32_t row) {
	int32_t otherRow = 0, rayIndex = 0;
	switch (Game::cellTypes[col][row]) {
		default:
			Game::cellObjects[col][row] = -1;
			return;
		case 48:
			Game::cellObjects[col][row] = -1;
			this->killEnemyAt(col, row);
			otherRow = row + 1;
			if (Game::cellTypes[col][otherRow] != 48) {
				otherRow = -1;
			}
			Game::cellTypes[col][otherRow] = -1;
			this->killEnemyAt(col, otherRow);
			rayIndex = (Game::cellStates[col][row] >> 24) * 3;
			Game::freezeRays[rayIndex + 2] = -1;
			return;
		case 0:
			this->playSound(11);
			Game::cellObjects[col][row] = -1;
			this->killEnemyAt(col, row);
			return;
		case 19:
		case 43:
		case 45:
		case 46:
			Game::cellObjects[col][row] = -1;
			this->killEnemyAt(col, row);
			return;
	}
}

void Game::updatePlaying() {
	int32_t inBounds = 0, moved = 0, value = 0, row = 0, col = 0, layerObj = 0, cellType = 0, switched = 0, s0 = 0, s1 = 0, s2 = 0, t2 = 0, t3 = 0, t4 = 0;
	Ref<Object> s0_o;
	Arr<int8_t> t1;
	if (this->isHoldingBoulder) {
		this->boulderHoldTimer = this->boulderHoldTimer - 1;
	}
	if ((this->gotElementalDiamond || this->bossTreasureTaken) && Game::frameCount > 140) {
		if (this->bossTreasureTaken) {
			this->bankStageDiamonds();
		}
		this->gotElementalDiamond = 0;
		this->bossTreasureTaken = 0;
		this->needFreeCutscenes = 1;
		this->loadingStep = 0;
		this->resetCounters();
		this->needSaveStageResult = 1;
		Game::screen = 28;
	}
	inBounds = this->isPlayerInsideBorder();
	if (this->liquidStartNextEmitter) {
		this->liquidStartNextEmitter = 0;
		if (this->liquidNextEmitter >= this->liquidEmitterCount) {
			this->liquidNextEmitter = 0;
			this->liquidEmitterCount = 0;
		} else {
			moved = Game::getEmitterBits((int8_t)this->liquidNextEmitter, 13, 7);
			value = Game::getEmitterBits((int8_t)this->liquidNextEmitter, 20, 7);
			this->openLiquidEmitter(moved, value);
			this->liquidNextEmitter = this->liquidNextEmitter + 1;
		}
	}
	if (Game::actors[4] != nullptr) {
		Game::actors[4]->advanceFrame();
	}
	if (this->shakeTime > 0) {
		this->shakeTime = this->shakeTime - 1;
	}
	if (this->hintTimer > 0) {
		this->hintTimer = this->hintTimer - 1;
		if (this->hintTimer == 0) {
			this->hintText = nullptr;
		}
	}
	if (this->effectQueueHead != this->effectQueueTail) {
		s0 = this->effectQueueHead;
		while (true) {
			moved = s0;
			if (moved == this->effectQueueTail) {
				break;
			}
			t1 = Game::effectFrames;
			t1[moved] = (int8_t)(t1[moved] + 1);
			value = Game::effectAnims[moved] >= 0 ? Game::spritePacks[9]->getAnimFrameCount(Game::effectAnims[moved]) : Game::getAnimDuration(Game::spritePacks[2], 0);
			if (Game::effectFrames[moved] >= value) {
				this->effectQueueHead = this->effectQueueHead + 1;
				this->effectQueueHead = this->effectQueueHead & 7;
			}
			s0 = moved + 1 & 7;
		}
	}
	if (this->specialStageType != 0) {
		this->updateSpecialStage();
		if (Game::screen != 1) {
			return;
		}
	}
	if ((Game::frameCount & 15) == 0) {
		this->updateCompassDirection();
	}
	if (this->leverMoveDir != 0 && (Game::frameCount >> 1 & 1) == 0) {
		this->switchWallsPhase = this->switchWallsPhase + this->leverMoveDir;
		if (this->switchWallsPhase == 0 || this->switchWallsPhase == 9) {
			this->leverMoveDir = 0;
			for (moved = 1; moved < this->levelH - 1; moved++) {
				for (value = 1; value < this->levelW - 1; value++) {
					row = Game::cellObjects[value][moved] & 255;
					col = Game::cellTypes[value][moved];
					if (row == 15 || row == 16 || col == 34 || col == 35) {
						this->redrawCellInBuffer(value, moved);
					}
				}
			}
		} else {
			if (this->switchWallsPhase == 5) {
				moved = this->levelH - 1;
				value = this->levelW - 1;
				for (row = 1; row < moved; row++) {
					for (col = 1; col < value; col++) {
						layerObj = Game::cellObjects[col][row] & 255;
						cellType = Game::cellTypes[col][row];
						switched = 0;
						if (layerObj != 15) {
							if (layerObj != 16) {
								if (cellType != 34) {
									if (cellType == 35) {
										s0_o = Game::cellObjects[col];
										s1 = row;
										s2 = 16;
										cast<Array<int32_t>>(s0_o)[s1] = s2;
										Game::cellTypes[col][row] = -1;
										this->checkLiquidBreachAt(col, row);
										switched = 1;
									}
								} else {
									s0_o = Game::cellObjects[col];
									s1 = row;
									s2 = 15;
									cast<Array<int32_t>>(s0_o)[s1] = s2;
									Game::cellTypes[col][row] = -1;
									this->checkLiquidBreachAt(col, row);
									switched = 1;
								}
							} else {
								this->crushCellContents(col, row);
								Game::cellTypes[col][row] = 35;
								switched = 1;
							}
						} else {
							this->crushCellContents(col, row);
							Game::cellTypes[col][row] = 34;
							switched = 1;
						}
						if (switched != 0) {
							Game::wakeCellsAround(col, row);
						}
					}
				}
			}
		}
	}
	this->invulnTimer = this->invulnTimer - 1LL;
	if (this->deathTimer > 0) {
		t2 = this->deathTimer - 1;
		this->deathTimer = t2;
		if (t2 == 0) {
			this->loseLife();
		}
	}
	if (this->playerStep <= 0 && this->checkpointSavePending) {
		this->checkpointSavePending = 0;
		this->playSound(9);
		try {
			Thread::sleep(100LL);
		} catch (JavaException& ex) {
			if (ex.isa(u"java/lang/InterruptedException")) {
				s0_o = ex.ex;
			}
			else throw;
		}
		this->saveCheckpoint();
	}
	if (Game::spritePacks[11] != nullptr) {
		this->updatePistonTraps();
	}
	if (this->slideCellsLeft != 0 && this->slidingObjCol != 0) {
		this->updateSlidingObject();
	}
	this->updateCellsNearPlayer();
	if (this->freezeRayCount > 0) {
		this->updateFreezeRays();
	}
	this->updateLiquidSimulation();
	if (this->gateRevealState != 0) {
		this->updateGateRevealPan();
	}
	if (this->activeCutscene == nullptr) {
		if (this->pendingCutsceneId != -1) {
			this->startCutscene(this->pendingCutsceneId);
			this->pendingCutsceneId = -1;
			this->requestedMoveDir = 0;
		}
	} else {
		this->playerIdleCountdown = 70;
		if (this->activeCutscene->isStepFinished() && this->activeCutscene->nextStep() == nullptr) {
			this->activeCutscene = nullptr;
		}
		if (this->activeCutscene != nullptr) {
			this->activeCutscene->updateStep();
		}
	}
	{
		if (this->encasedStruggleCount <= 0) {
			if ((this->currentMoveDir == 0 || this->playerStep <= 0 && this->currentMoveDir != 5) && !this->isExitingLevel && (this->explorerStateFlags & 112) == 0 && this->heldItemImageSet == -1) {
				this->currentMoveDir = this->requestedMoveDir;
				moved = 0;
				if (this->entryWalkRemaining <= 0) {
					if (inBounds != 0) {
						Game::wakeCellsAround(this->playerCol, this->playerRow);
					}
				} else {
					this->currentMoveDir = 2;
					this->entryWalkRemaining = this->entryWalkRemaining - 1;
					if (this->entryWalkRemaining == 0) {
						this->closeDoorAt(this->playerCol - 1, this->playerRow);
						this->requestedMoveDir = 0;
						Game::keys = 0;
					}
				}
				switch (this->currentMoveDir) {
					case 6:
						s0 = (this->explorerStateFlags & 7) != 2 ? -1 : 1;
						value = s0;
						if (inBounds != 0 && Game::cellTypes[this->playerCol + value][this->playerRow] < 0) {
							this->setExplorerAnim(value != -1 ? 20 : 22);
							Game::cellTypes[this->playerCol + value][this->playerRow] = 32;
							Game::cellMoveOffsets[this->playerCol + value][this->playerRow] = 18;
							Game::cellStates[this->playerCol + value][this->playerRow] = 4 | (value > 0 ? 1 : 0);
							Game::cellUpdateTimers[this->playerCol + value][this->playerRow] = 30;
							this->playerStep = 72;
							this->requestedMoveDir = 0;
						}
						break;
					case 5:
						this->playerStep = 0;
						row = this->explorerStateFlags & 7;
						if (this->isPlayerInsideBorder()) {
							this->setExplorerAnim(13 + row - 1);
						}
						break;
					case 3:
						this->explorerStateFlags = this->explorerStateFlags & -9;
						if (Game::actors[0]->animIndex != 40 && Game::actors[0]->animIndex != 48) {
							if ((this->explorerStateFlags & 4096) != 0) {
								this->explorerStateFlags = this->explorerStateFlags & -8 | this->currentMoveDir;
								this->playerStep = 18;
								t4 = this->currentMoveDir - 1;
								value = t4;
								if (value < 0) {
									value = 0;
								}
								this->setExplorerAnim(0 + value);
							} else {
								moved = this->tryMoveExplorer(-Game::dirDeltas[this->currentMoveDir], -Game::dirDeltas[this->currentMoveDir + 8], 0);
								inBounds = this->isPlayerInsideBorder();
								if (moved != 0) {
									this->boulderHoldTimer = 40;
									this->isHoldingBoulder = 0;
									t3 = this->currentMoveDir - 1;
									value = t3;
									if (value < 0) {
										value = 0;
									}
									if ((this->explorerStateFlags & 8) == 0) {
										this->setExplorerAnim(4 + value);
									} else {
										if (this->currentMoveDir != 2) {
											this->setExplorerAnim(9);
										} else {
											this->setExplorerAnim(8);
										}
									}
								}
							}
						}
						break;
					case 1:
					case 2:
					case 4:
						if (Game::actors[0]->animIndex != 40 && Game::actors[0]->animIndex != 48) {
							if ((this->explorerStateFlags & 4096) != 0) {
								this->explorerStateFlags = this->explorerStateFlags & -8 | this->currentMoveDir;
								this->playerStep = 18;
								t4 = this->currentMoveDir - 1;
								value = t4;
								if (value < 0) {
									value = 0;
								}
								this->setExplorerAnim(0 + value);
							} else {
								moved = this->tryMoveExplorer(-Game::dirDeltas[this->currentMoveDir], -Game::dirDeltas[this->currentMoveDir + 8], 0);
								inBounds = this->isPlayerInsideBorder();
								if (moved != 0) {
									this->boulderHoldTimer = 40;
									this->isHoldingBoulder = 0;
									t3 = this->currentMoveDir - 1;
									value = t3;
									if (value < 0) {
										value = 0;
									}
									if ((this->explorerStateFlags & 8) == 0) {
										this->setExplorerAnim(4 + value);
									} else {
										if (this->currentMoveDir != 2) {
											this->setExplorerAnim(9);
										} else {
											this->setExplorerAnim(8);
										}
									}
								}
							}
						}
						break;
					case 0:
						this->explorerStateFlags = this->explorerStateFlags & -9;
						col = 0;
						switch (Game::actors[0]->animIndex) {
							default:
								if ((this->explorerStateFlags & 16384) == 0) {
									col = 1;
								}
								break;
							case 0:
							case 2:
							case 10:
							case 11:
							case 12:
							case 34:
							case 35:
							case 40:
							case 48:
								break;
						}
						if (col != 0) {
							layerObj = 0 + (this->explorerStateFlags & 7) - 1;
							if (layerObj < 0) {
								layerObj = 0;
							}
							this->setExplorerAnim(layerObj);
						}
						if (this->activeCutscene != nullptr) {
							s0_o = this;
							s1 = 0;
						} else {
							s0_o = this;
							s1 = 6;
						}
						cast<Game>(s0_o)->pushDelay = s1;
						if (this->playerStep > 0) {
							this->playerStep = this->playerStep - 6;
						}
						break;
					default:
						break;
				}
				if (inBounds != 0) {
					value = Game::cellTypes[this->playerCol][this->playerRow - 1];
					if (moved == 0 && this->currentMoveDir != 5 && this->playerStep <= 0 && (value == 0 || value == 9 || value == 8 || value == 48) && (Game::cellObjects[this->playerCol][this->playerRow] & 255) != 35) {
						row = 0;
						if (Game::liquidCells != nullptr) {
							row = Game::getLiquidBits(Game::liquidCells[this->playerCol][this->playerRow], 0, 3, 4);
						}
						if (!this->hasWaterLayer || row == 0 && row != 3) {
							if ((this->explorerStateFlags & 8) == 0 && Game::actors[0]->animIndex != 11 && Game::actors[0]->animIndex != 10 && Game::actors[0]->animIndex != 12) {
								this->setExplorerAnim(11);
							}
							this->isHoldingBoulder = 1;
							if (this->boulderHoldTimer <= 0) {
								this->boulderHoldTimer = 40;
								this->invulnTimer = 0LL;
								this->damageExplorer(Game::saveData[8], 32, 0);
								return;
							}
						}
					}
				}
				if (moved == 0) {
					if (inBounds != 0 && (Game::frameCount & 31) == 0) {
						value = Game::cellTypes[this->playerCol][this->playerRow - 1] == 0 ? 1 : 0;
						for (row = 1; value == 0 && row <= 4; row++) {
							value = value | this->tryMoveExplorer(Game::dirDeltas[row], Game::dirDeltas[row + 8], 1);
						}
						if (value == 0) {
							if (!this->stuckWarned) {
								this->stuckWarned = 1;
							} else {
								this->setExplorerAnim(19);
							}
						}
					}
				} else {
					this->stuckWarned = 0;
				}
			} else {
				if (this->isExitingLevel && this->playerStep <= 0) {
					if (!this->usedMainExit) {
						s0_o = this;
						s1 = this->altExitWalkDir;
					} else {
						s0_o = this;
						s1 = this->exitWalkDir;
					}
					cast<Game>(s0_o)->currentMoveDir = s1;
					this->explorerStateFlags = this->explorerStateFlags & -8 | this->currentMoveDir;
					this->playerCol = this->playerCol + -Game::dirDeltas[this->currentMoveDir];
					this->playerRow = this->playerRow + -Game::dirDeltas[this->currentMoveDir + 8];
					inBounds = this->isPlayerInsideBorder();
					this->playerStep = 18;
					if (Game::actors[0]->animIndex != 4) {
						this->setExplorerAnim(4 + this->currentMoveDir - 1);
					}
				}
				if ((this->explorerStateFlags & 112) <= 32 || (this->explorerStateFlags & 2048) != 0) {
					this->playerStep = this->playerStep - 6;
					if (this->playerStep <= 0) {
						this->explorerStateFlags = this->explorerStateFlags & -4209;
						s0_o = this;
						s1 = 0;
						goto B42_end;
					}
				}
			}
			if (this->gateRevealState == 0) {
				if (!this->respawnPanActive) {
					if (this->activeCutscene != nullptr) {
						this->camX = this->camTargetX;
						this->camY = this->camTargetY;
					} else {
						if (Game::cameraHoldAfterPan && this->currentMoveDir != 0) {
							Game::cameraHoldAfterPan = 0;
							this->playerIdleCountdown = 0;
						}
						if (!Game::cameraHoldAfterPan) {
							this->updateCameraFollow();
						}
					}
				} else {
					this->camPanSpeed = 8;
					if (this->stepCameraPan()) {
						this->spawnCellEffect(this->checkpointCol, this->checkpointRow, 5);
						this->respawnPanActive = 0;
					}
				}
			}
			if (this->currentMoveDir != 0 && inBounds != 0) {
				this->isExplorerOnGround = Game::cellTypes[this->playerCol][this->playerRow + 1] >= 0 ? 1 : 0;
			}
			this->updateExplorerAnim();
			if (this->isExitingLevel && (this->playerCol < -5 || this->playerCol > this->levelW + 5 || this->playerRow < -5 || this->playerRow > this->levelH + 5)) {
				this->freeLevelCutscenes();
				if (this->usedMainExit || this->stage >= this->firstSecretStage) {
					this->loadingStep = 0;
					this->loadingStepCount = 12;
					Game::screen = 35;
				} else {
					Game::screen = 20;
					this->loadingStep = 0;
					this->saveRedDiamondPicks();
					this->unlockStagesAfterClear();
					Game::addToSaveCounter(6, this->redDiamondCount);
					this->saveStageResult();
				}
				this->resetCounters();
				this->screenSubState = -1;
			}
			return;
		}
		if (Game::cellTypes[this->playerCol][this->playerRow] < 0) {
			if (Game::cellTypes[this->playerCol][this->playerRow + 1] != 9 || (Game::cellStates[this->playerCol][this->playerRow + 1] & 7) != 3) {
				if (Game::cellTypes[this->playerCol - 1][this->playerRow + 1] != 9 || (Game::cellStates[this->playerCol - 1][this->playerRow + 1] & 7) != 3) {
					if (Game::cellTypes[this->playerCol + 1][this->playerRow + 1] != 9 || (Game::cellStates[this->playerCol + 1][this->playerRow + 1] & 7) != 3) {
						s0_o = this;
						s1 = this->explorerStateFlags & -8;
						s2 = 0;
					} else {
						this->playerRow = this->playerRow + 1;
						this->playerCol = this->playerCol + 1;
						s0_o = this;
						s1 = this->explorerStateFlags & -8;
						s2 = 3;
					}
				} else {
					this->playerRow = this->playerRow + 1;
					this->playerCol = this->playerCol - 1;
					s0_o = this;
					s1 = this->explorerStateFlags & -8;
					s2 = 3;
				}
			} else {
				this->playerRow = this->playerRow + 1;
				s0_o = this;
				s1 = this->explorerStateFlags & -8;
				s2 = 3;
			}
			cast<Game>(s0_o)->explorerStateFlags = s1 | s2;
		}
		s0_o = this;
		s1 = Game::cellMoveOffsets[this->playerCol][this->playerRow];
	}
	B42_end:;
	cast<Game>(s0_o)->playerStep = s1;
	if (this->gateRevealState == 0) {
		if (!this->respawnPanActive) {
			if (this->activeCutscene != nullptr) {
				this->camX = this->camTargetX;
				this->camY = this->camTargetY;
			} else {
				if (Game::cameraHoldAfterPan && this->currentMoveDir != 0) {
					Game::cameraHoldAfterPan = 0;
					this->playerIdleCountdown = 0;
				}
				if (!Game::cameraHoldAfterPan) {
					this->updateCameraFollow();
				}
			}
		} else {
			this->camPanSpeed = 8;
			if (this->stepCameraPan()) {
				this->spawnCellEffect(this->checkpointCol, this->checkpointRow, 5);
				this->respawnPanActive = 0;
			}
		}
	}
	if (this->currentMoveDir != 0 && inBounds != 0) {
		this->isExplorerOnGround = Game::cellTypes[this->playerCol][this->playerRow + 1] >= 0 ? 1 : 0;
	}
	this->updateExplorerAnim();
	{
		if (this->isExitingLevel && (this->playerCol < -5 || this->playerCol > this->levelW + 5 || this->playerRow < -5 || this->playerRow > this->levelH + 5)) {
			this->freeLevelCutscenes();
			{
				if (this->usedMainExit || this->stage >= this->firstSecretStage) {
					this->loadingStep = 0;
					this->loadingStepCount = 12;
					Game::screen = 35;
					goto B108_end;
				}
				Game::screen = 20;
				this->loadingStep = 0;
				this->saveRedDiamondPicks();
				this->unlockStagesAfterClear();
				Game::addToSaveCounter(6, this->redDiamondCount);
				this->saveStageResult();
				goto B108_end;
			}
			B108_end:;
			this->resetCounters();
			this->screenSubState = -1;
			goto B107_end;
		}
	}
	B107_end:;
}

int8_t Game::extendFreezeRayEnd(int32_t col, int32_t step, int32_t limitCol, int32_t row) {
	int32_t nextCol = 0;
	nextCol = col + step;
	if ((col > 0 && limitCol == 0 || col < limitCol && limitCol > 0) && (Game::cellTypes[nextCol][row] < 0 || Game::cellTypes[nextCol][row] == 31 || Game::getFrozenKind(nextCol, row) >= 0)) {
		do {
			col = nextCol;
			nextCol = nextCol + step;
		} while (!((col <= 0 || limitCol != 0) && (col >= limitCol || limitCol <= 0) || Game::cellTypes[nextCol][row] >= 0 && Game::getFrozenKind(nextCol, row) < 0 && Game::cellTypes[nextCol][row] != 31));
	}
	return (int8_t)col;
}

bool Game::isFreezeRayBlocker(int32_t col, int32_t row) {
	int32_t i = 0;
	if (Game::freezeRays != nullptr) {
		i = 0;
		while (true) {
			if (i >= Game::freezeRays->length) {
				return 0;
			}
			if (Game::freezeRays[i + 2] == row) {
				if (Game::freezeRays[i + 0] - 1 == col || Game::freezeRays[i + 1] + 1 == col) {
					break;
				}
			}
			i += 3;
		}
		return 1;
	}
	return 0;
}

void Game::updateFreezeRays() {
	int32_t maxCol = 0, i = 0, row = 0, rightCol = 0, leftCol = 0, col = 0, t3 = 0, t4 = 0, t6 = 0, t7 = 0;
	Arr<int8_t> t2, t5;
	maxCol = this->levelW - 1;
	for (i = 0; i < Game::freezeRays->length; i += 3) {
		row = Game::freezeRays[i + 2];
		if (row > 0) {
			rightCol = Game::freezeRays[i + 1];
			leftCol = Game::freezeRays[i + 0];
			t2 = Game::freezeRays;
			t3 = i + 0;
			t4 = this->extendFreezeRayEnd(leftCol, -1, 0, row);
			t2[t3] = t4;
			leftCol = t4;
			t5 = Game::freezeRays;
			t6 = i + 1;
			t7 = this->extendFreezeRayEnd(rightCol, 1, maxCol, row);
			t5[t6] = t7;
			rightCol = t7;
			for (col = leftCol; col <= rightCol; col++) {
				this->freezeCell(col, row);
			}
		}
	}
}

bool Game::freezeCell(int32_t col, int32_t row) {
	int32_t frozenKind = 0, variantFlag = 0, actorIndex = 0;
	Ref<Actor> actor;
	frozenKind = Game::getFrozenKind(col, row);
	variantFlag = 0;
	if (frozenKind >= 0) {
		if (frozenKind == 37 && Game::cellTypes[col][row] == 43) {
			variantFlag = 268435456;
		}
		Game::wakeCellsAround(col, row);
		Game::cellTypes[col][row] = 9;
		Game::cellStates[col][row] = Game::cellStates[col][row] & -264241153 | frozenKind << 22 | variantFlag;
		this->spawnCellEffect(col, row, 1);
	}
	actorIndex = (this->explorerStateFlags & 16384) != 0 ? 3 : 0;
	actor = Game::actors[actorIndex];
	if (this->isPlayerAt(col, row) && this->encasedStruggleCount <= 0 && actor->animIndex != 40 && actor->animIndex != 48) {
		if (actor->animIndex != 47) {
			this->damageExplorer(0, 16, 0);
		}
	}
	if (frozenKind < 0) {
		return 0;
	}
	return 1;
}

int32_t Game::getFrozenKind(int32_t col, int32_t row) {
	if (Game::cellTypes[col][row] < 0) {
		return -1;
	}
	switch (Game::cellTypes[col][row]) {
		default:
			return -1;
		case 49:
			return 39;
		case 46:
			return 36;
		case 45:
			return 35;
		case 19:
		case 43:
			return 37;
		case 1:
			return 34;
	}
}

void Game::drawStageResults() {
	int32_t step = 0, slideX = 0, slideX2 = 0, value_n = 0, animLength = 0, s3 = 0, t3 = 0, t5 = 0, t7 = 0, t9 = 0, t10 = 0, t11 = 0;
	Ref<SpritePack> font, value, t2, t4, t6, t8, t12, t15;
	Ref<Graphics> g, t1, t13, t16;
	Ref<Object> text, s0, s1, s2;
	Arr<Ref<String>> t14, t17;
	int32_t pc = 0;
	for (;;) {
		switch (pc) {
		case 0:
			step = this->screenSubState;
			font = Game::spritePacks[41];
			t1 = this->screenGraphics;
			g = t1;
			g->setColor(2496263);
			g->fillRect(0, 0, 240, 320);
			switch (step) {
				case 0: pc = 919; continue;
				case 1: pc = 787; continue;
				case 2: pc = 573; continue;
				case 3: pc = 376; continue;
				case 4: pc = 181; continue;
				case 5: pc = 76; continue;
				default: pc = 1014; continue;
			}
		case 76:
			if (this->livesLostInStage != 0) { pc = 181; continue; }
			pc = 83; continue;
		case 83:
			if ((this->stageMedalsNew & 32) == 0) { pc = 162; continue; }
			pc = 93; continue;
		case 93:
			g->drawImage(Game::objectFrameImages[5][0], 200, 237, 0);
			if (step != 5) { pc = 162; continue; }
			pc = 116; continue;
		case 116:
			t2 = Game::spritePacks[9];
			text = t2;
			value_n = t2->getAnimFrameCount(0);
			if (Game::frameCount >= value_n * 2) { pc = 162; continue; }
			pc = 141; continue;
		case 141:
			cast<SpritePack>(text)->drawAnimFrame(g, 0, Game::frameCount * 2, 200, 237, 0, 0, 0);
			pc = 162; continue;
		case 162:
			g->drawImage(Game::objectFrameImages[28][0], 180, 254, 0);
			pc = 181; continue;
		case 181:
			if (step != 4) { pc = 201; continue; }
			pc = 186; continue;
		case 186:
			t3 = -100 + Game::frameCount * 10;
			slideX = t3;
			if (slideX <= 0) { pc = 204; continue; }
			pc = 201; continue;
		case 201:
			slideX = 0;
			pc = 204; continue;
		case 204:
			Game::actors[0]->sprite->drawAnimFrame(g, 12, 0, 7 + slideX, 243, 0, 0, 0);
			font->drawMultilineString(g, Game::langStrings[44], 120, 243, 17);
			text = String::valueOf(this->livesLostInStage);
			font->drawMultilineString(g, cast<String>(text), 120, 255, 17);
			if (this->hitsTaken != 0) { pc = 376; continue; }
			pc = 278; continue;
		case 278:
			if ((this->stageMedalsNew & 16) == 0) { pc = 357; continue; }
			pc = 288; continue;
		case 288:
			g->drawImage(Game::objectFrameImages[5][0], 200, 179, 0);
			if (step != 4) { pc = 357; continue; }
			pc = 311; continue;
		case 311:
			t4 = Game::spritePacks[9];
			value = t4;
			animLength = value->getAnimFrameCount(0);
			if (Game::frameCount >= animLength * 2) { pc = 357; continue; }
			pc = 336; continue;
		case 336:
			value->drawAnimFrame(g, 0, Game::frameCount >> 1, 200, 179, 0, 0, 0);
			pc = 357; continue;
		case 357:
			g->drawImage(Game::objectFrameImages[28][0], 180, 196, 0);
			pc = 376; continue;
		case 376:
			if (step != 3) { pc = 396; continue; }
			pc = 381; continue;
		case 381:
			t5 = -100 + Game::frameCount * 10;
			slideX = t5;
			if (slideX <= 0) { pc = 399; continue; }
			pc = 396; continue;
		case 396:
			slideX = 0;
			pc = 399; continue;
		case 399:
			Game::actors[0]->sprite->drawAnimFrame(g, 10, 0, 7 + slideX, 189, 0, 0, 0);
			font->drawMultilineString(g, Game::langStrings[43], 120, 185, 17);
			text = String::valueOf(this->hitsTaken);
			font->drawMultilineString(g, cast<String>(text), 120, 197, 17);
			if (this->redDiamondCount != this->redDiamondsInStage) { pc = 573; continue; }
			pc = 477; continue;
		case 477:
			if ((this->stageMedalsNew & 8) == 0) { pc = 554; continue; }
			pc = 487; continue;
		case 487:
			g->drawImage(Game::objectFrameImages[5][0], 200, 121, 0);
			if (step != 3) { pc = 554; continue; }
			pc = 509; continue;
		case 509:
			t6 = Game::spritePacks[9];
			value = t6;
			animLength = value->getAnimFrameCount(0);
			if (Game::frameCount >= animLength * 2) { pc = 554; continue; }
			pc = 534; continue;
		case 534:
			value->drawAnimFrame(g, 0, Game::frameCount >> 1, 200, 121, 0, 0, 0);
			pc = 554; continue;
		case 554:
			g->drawImage(Game::objectFrameImages[28][0], 180, 138, 0);
			pc = 573; continue;
		case 573:
			if (step != 2) { pc = 593; continue; }
			pc = 578; continue;
		case 578:
			t7 = -100 + Game::frameCount * 10;
			slideX = t7;
			if (slideX <= 0) { pc = 596; continue; }
			pc = 593; continue;
		case 593:
			slideX = 0;
			pc = 596; continue;
		case 596:
			Game::spritePacks[Game::getSpritePackForImageSet(3)]->drawFrame(g, 0, 7 + slideX, 127, 0, 0, 0);
			font->drawMultilineString(g, Game::langStrings[114], 120, 127, 17);
			text = jnew<StringBuffer>()->append(this->redDiamondCount)->append(u"/"_j)->append(this->redDiamondsInStage)->toString();
			font->drawMultilineString(g, cast<String>(text), 120, 139, 17);
			if (this->diamondCount != this->diamondsInStage) { pc = 787; continue; }
			pc = 693; continue;
		case 693:
			if ((this->stageMedalsNew & 4) == 0) { pc = 769; continue; }
			pc = 702; continue;
		case 702:
			g->drawImage(Game::objectFrameImages[5][0], 200, 63, 0);
			if (step != 2) { pc = 769; continue; }
			pc = 724; continue;
		case 724:
			t8 = Game::spritePacks[9];
			value = t8;
			animLength = value->getAnimFrameCount(0);
			if (Game::frameCount >= animLength >> 1) { pc = 769; continue; }
			pc = 749; continue;
		case 749:
			value->drawAnimFrame(g, 0, Game::frameCount * 2, 200, 63, 0, 0, 0);
			pc = 769; continue;
		case 769:
			g->drawImage(Game::objectFrameImages[28][0], 180, 80, 0);
			pc = 787; continue;
		case 787:
			if (step != 1) { pc = 807; continue; }
			pc = 792; continue;
		case 792:
			t9 = -100 + Game::frameCount * 10;
			slideX = t9;
			if (slideX <= 0) { pc = 810; continue; }
			pc = 807; continue;
		case 807:
			slideX = 0;
			pc = 810; continue;
		case 810:
			Game::spritePacks[Game::getSpritePackForImageSet(2)]->drawFrame(g, 0, 7 + slideX, 69, 0, 0, 0);
			font->drawMultilineString(g, Game::langStrings[109], 120, 69, 17);
			if (step != 1) { pc = 870; continue; }
			pc = 855; continue;
		case 855:
			t10 = Game::frameCount >> 1;
			value_n = t10;
			if (value_n <= this->diamondCount) { pc = 876; continue; }
			pc = 870; continue;
		case 870:
			value_n = this->diamondCount;
			pc = 876; continue;
		case 876:
			text = jnew<StringBuffer>()->append(value_n)->append(u"/"_j)->append(this->diamondsInStage)->toString();
			font->drawMultilineString(g, cast<String>(text), 120, 81, 17);
			pc = 919; continue;
		case 919:
			if (step != 0) { pc = 957; continue; }
			pc = 923; continue;
		case 923:
			t11 = -100 + Game::frameCount * 10;
			slideX = t11;
			slideX2 = slideX - 240;
			if (slideX <= 0) { pc = 949; continue; }
			pc = 946; continue;
		case 946:
			slideX = 0;
			pc = 949; continue;
		case 949:
			if (slideX2 <= 0) { pc = 963; continue; }
			pc = 954; continue;
		case 954:
			pc = 960; continue;
		case 957:
			slideX = 0;
			pc = 960; continue;
		case 960:
			slideX2 = 0;
			pc = 963; continue;
		case 963:
			font->drawString(g, Game::langStrings[Game::stageNameIds[this->world][this->stage]], 120 + slideX, 10, 17);
			font->drawString(g, Game::langStrings[41], 120 + slideX2, 25, 17);
			pc = 1014; continue;
		case 1014:
			s0 = Game::spritePacks[41];
			s1 = this->screenGraphics;
			s2 = Game::langStrings;
			if (this->screenSubState != 5) { pc = 1040; continue; }
			pc = 1035; continue;
		case 1035:
			t12 = cast<SpritePack>(s0);
			t13 = cast<Graphics>(s1);
			t14 = cast<Array<Ref<String>>>(s2);
			s0 = t12;
			s1 = t13;
			s2 = t14;
			s3 = 98;
			pc = 1042; continue;
		case 1040:
			t15 = cast<SpritePack>(s0);
			t16 = cast<Graphics>(s1);
			t17 = cast<Array<Ref<String>>>(s2);
			s0 = t15;
			s1 = t16;
			s2 = t17;
			s3 = 53;
			pc = 1042; continue;
		case 1042:
			cast<SpritePack>(s0)->drawString(cast<Graphics>(s1), cast<Array<Ref<String>>>(s2)[s3], 5, 318, 36);
			return;
		}
	}
}

int32_t Game::readU16LE(Arr<int8_t> data, int32_t offset) {
	return data[offset] & 255 | (data[offset + 1] & 255) << 8;
}

int32_t Game::readS32LE(Arr<int8_t> data, int32_t offset) {
	return data[offset] & 255 | (data[offset + 1] & 255) << 8 | (data[offset + 2] & 255) << 16 | (data[offset + 3] & 255) << 24;
}

int32_t Game::addToSaveCounter(int32_t offset, int32_t delta) {
	int32_t value = 0;
	value = Game::readU16LE(Game::saveData, offset);
	value = value + delta;
	if (value < 0) {
		value = 0;
	}
	Game::saveData[offset] = (int8_t)(value & 255);
	Game::saveData[offset + 1] = (int8_t)(value >> 8 & 255);
	return value;
}

void Game::saveRedDiamondPicks() {
	int32_t i = 0;
	for (i = 0; i < this->redDiamondPickCount; i++) {
		this->markCollectibleTaken(this->world, this->stage, Game::redDiamondPickCells[i << 1] & 255, Game::redDiamondPickCells[(i << 1) + 1] & 255);
	}
}

int32_t Game::bankStageDiamonds() {
	return Game::addToSaveCounter(4, this->diamondCount);
}

int32_t Game::bankStageRedDiamonds() {
	return Game::addToSaveCounter(6, this->redDiamondCount);
}

void Game::runStageCompleteStep(int32_t step) {
	int32_t oldLevel = 0, newLevel = 0;
	Ref<Object> s0;
	Arr<int8_t> t2, t3;
	switch (step) {
		case 11:
			if (this->lives < 99 && this->diamondCount == this->diamondsInStage && (this->stageMedalsBefore & 4) == 0) {
				this->addStageFlags(this->world, this->stage, 4);
				this->stageMedalsNew = (int8_t)(this->stageMedalsNew | 4);
				this->lives = this->lives + 1;
			}
			if (this->lives < 99 && this->redDiamondCount == this->redDiamondsInStage && (this->stageMedalsBefore & 8) == 0) {
				this->addStageFlags(this->world, this->stage, 8);
				this->stageMedalsNew = (int8_t)(this->stageMedalsNew | 8);
				this->lives = this->lives + 1;
			}
			if (this->lives < 99 && this->hitsTaken == 0 && (this->stageMedalsBefore & 16) == 0) {
				this->addStageFlags(this->world, this->stage, 16);
				this->stageMedalsNew = (int8_t)(this->stageMedalsNew | 16);
				this->lives = this->lives + 1;
			}
			if (this->lives < 99 && this->livesLostInStage == 0 && (this->stageMedalsBefore & 32) == 0) {
				this->addStageFlags(this->world, this->stage, 32);
				this->stageMedalsNew = (int8_t)(this->stageMedalsNew | 32);
				this->lives = this->lives + 1;
			}
			this->unlockNextStage();
			this->saveStageResult();
			this->needSaveStageResult = 0;
			this->needFreeMapRes = 1;
			return;
		case 10:
			this->resetCounters();
			JSystem::gc();
			return;
		case 8:
			oldLevel = (Game::progressFlagsCopy & 224) >> 5;
			for (newLevel = oldLevel; newLevel < 4 && Game::bankedDiamonds >= Tables::upgradeCosts[newLevel]; newLevel++) {
			}
			if (oldLevel < newLevel) {
				t2 = Game::saveData;
				t2[2] = (int8_t)(t2[2] & -225);
				t3 = Game::saveData;
				t3[2] = (int8_t)(t3[2] | newLevel << 5 & 224);
				this->writeSaveRecord();
				this->armorUnlockToAnnounce = newLevel;
			}
			this->saveRedDiamondPicks();
			return;
		case 9:
			this->saveRedDiamondPicks();
			return;
		case 7:
			this->addStageFlags(this->world, this->stage, 2);
			this->armorUnlockToAnnounce = 0;
			return;
		case 6:
			try {
				Game::objectFrameImages[28] = Game::loadSpriteImages(u"/ui.f"_j, 4);
			} catch (JavaException& ex) {
				if (ex.isa(u"java/lang/Exception")) {
					s0 = ex.ex;
					return;
				}
				else throw;
			}
			return;
		case 5:
			Game::progressFlagsCopy = Game::saveData[2];
			this->worldUnlockToAnnounce = 0;
			if ((Game::progressFlagsCopy & 8) != 0 || Game::bankedRedDiamonds < Tables::worldUnlockRequirements[1]) {
				if ((Game::progressFlagsCopy & 16) != 0 || Game::bankedRedDiamonds < Tables::worldUnlockRequirements[2]) {
					return;
				}
				this->worldUnlockToAnnounce = 2;
				return;
			}
			this->worldUnlockToAnnounce = 1;
			return;
		default:
			return;
		case 4:
			Game::saveData[6] = (int8_t)(Game::bankedRedDiamonds & 255);
			Game::saveData[7] = (int8_t)(Game::bankedRedDiamonds >> 8 & 255);
			return;
		case 3:
			Game::bankedRedDiamonds = Game::readU16LE(Game::saveData, 6);
			Game::bankedRedDiamonds = Game::bankedRedDiamonds + this->redDiamondCount;
			return;
		case 2:
			Game::saveData[4] = (int8_t)(Game::bankedDiamonds & 255);
			Game::saveData[5] = (int8_t)(Game::bankedDiamonds >> 8 & 255);
			return;
		case 1:
			Game::bankedDiamonds = Game::readU16LE(Game::saveData, 4);
			Game::bankedDiamonds = Game::bankedDiamonds + this->diamondCount;
			this->resultsSkipPressed = 0;
			return;
		case 0:
			Game::bankedDiamonds = 0;
			Game::bankedRedDiamonds = 0;
			Game::progressFlagsCopy = 0;
			this->stageMedalsBefore = this->getStageFlags(this->world, this->stage);
			this->stageMedalsNew = 0;
			return;
	}
}

void Game::advanceStageResults() {
	switch (this->screenSubState) {
		case 4:
			if (Game::frameCount > 10 || this->resultsSkipPressed) {
				this->screenSubState = this->screenSubState + 1;
				this->resetCounters();
				this->resultsSkipPressed = 0;
			}
			break;
		case 3:
			if (Game::frameCount > 10 || this->resultsSkipPressed) {
				this->screenSubState = this->screenSubState + 1;
				this->resetCounters();
				return;
			}
			break;
		case 2:
			if (Game::frameCount > 40 || this->resultsSkipPressed) {
				this->screenSubState = this->screenSubState + 1;
				this->resetCounters();
				return;
			}
			break;
		case 1:
			if (Game::frameCount > this->diamondCount << 1 && Game::frameCount > 40 || this->resultsSkipPressed) {
				this->screenSubState = this->screenSubState + 1;
				this->resetCounters();
				return;
			}
			break;
		case 0:
			if (Game::frameCount > 40 || this->resultsSkipPressed) {
				this->screenSubState = this->screenSubState + 1;
				this->resetCounters();
				return;
			}
			break;
		default:
			break;
	}
}

int64_t Game::findStageMapNode(int32_t stageIndex) {
	int32_t col = 0, row = 0;
	int64_t node = 0;
	col = 0;
	while (true) {
		if (col >= 12) {
			return (-1LL);
		}
		row = 0;
		while (row < 12) {
			node = Game::stageMapNodes[col][row];
			if (node == 0LL || Game::extractLongBits(node, 6, 5) != stageIndex) {
				row++;
				continue;
			}
			goto L1_end;
		}
		col++;
	}
	L1_end:;
	return node;
}

void Game::unlockNextStage() {
	int64_t node = 0;
	node = this->findStageMapNode(this->stage);
	if ((this->stage == 0 || Game::extractLongBits(node, 11, 3) > 1) && node >= 0LL && (this->getStageFlags(this->world, this->stage + 1) & 64) == 0) {
		Game::latestUnlockedStage = this->stage + 1;
		this->addStageFlags(this->world, Game::latestUnlockedStage, 64);
		this->newStageUnlocked = 1;
		return;
	}
	Game::latestUnlockedStage = this->stage;
}

void Game::returnToStageMap() {
	this->openStageMap();
}

void Game::spawnCellEffect(int32_t col, int32_t row, int32_t anim) {
	int32_t cellIndex = 0;
	cellIndex = this->effectQueueTail << 1;
	Game::effectCells[cellIndex] = (int8_t)col;
	Game::effectCells[cellIndex + 1] = (int8_t)row;
	Game::effectAnims[this->effectQueueTail] = (int8_t)anim;
	Game::effectFrames[this->effectQueueTail] = 0;
	this->effectQueueTail = this->effectQueueTail + 1 & 7;
}

void Game::loseLife() {
	this->lives = this->lives - 1;
	this->livesLostInStage = this->livesLostInStage + 1;
	if (this->lives < 0) {
		Game::screen = 12;
		return;
	}
	this->restoreCheckpoint();
	this->explorerEnergy = Game::saveData[8];
	this->requestHudRedraw();
	this->explorerStateFlags = 0;
	this->encasedStruggleCount = 0;
	this->currentMoveDir = 0;
	this->requestedMoveDir = 0;
}

void Game::unlockDoorLock(int32_t doorId) {
	int32_t col = 0, row = 0, objType = 0, param = 0, locksLeft = 0, aboveParam = 0;
	if (doorId >= 0) {
		col = Game::doorCols[doorId];
		row = Game::doorRows[doorId];
		objType = Game::cellObjects[col][row] & 255;
		param = Game::cellObjects[col][row] >> 8;
		if ((param & 240) == 0) {
			if (objType != 7 || (param & 65280) >> 8 != doorId) {
				JSystem::out->println(u"!!!!!!!!!!!!!! door missing"_j);
			}
			locksLeft = param & 15;
			locksLeft--;
			if (locksLeft != 0) {
				param = param & -16 | locksLeft;
			} else {
				param = param & -241 | 16;
				this->propagateLockFlag(col, row - 1, 1, 0, 1);
				this->propagateLockFlag(col, row - 1, -1, 0, 1);
				aboveParam = Game::cellObjects[col][row - 1] >> 8;
				aboveParam = aboveParam | 512;
				Game::cellObjects[col][row - 1] = aboveParam << 8 | Game::cellObjects[col][row - 1] & 255;
				Game::cellUpdateTimers[col][row] = 24;
			}
			Game::cellObjects[col][row] = param << 8 | objType;
			this->playSound(8);
			return;
		}
		return;
	}
}

void Game::openDoorAt(int32_t col, int32_t row) {
	int32_t param = 0;
	param = Game::cellObjects[col][row] >> 8;
	if ((param & 240) == 0) {
		param = param | 16;
		Game::cellObjects[col][row] = param << 8 | 7;
		Game::cellUpdateTimers[col][row] = 24;
	}
}

void Game::closeDoorAt(int32_t col, int32_t row) {
	int32_t param = 0;
	param = Game::cellObjects[col][row] >> 8;
	if ((Game::cellObjects[col][row] & 255) == 7) {
		if ((param & 240) != 0) {
			if (Game::cellTypes[col][row] != 32) {
				this->playSound(14);
				param = param & -241;
				Game::cellObjects[col][row] = param << 8 | 7;
				this->propagateLockFlag(col, row - 1, 1, 0, 0);
				this->propagateLockFlag(col, row - 1, -1, 0, 0);
				if (!this->isPlayerAt(col, row)) {
					switch (Game::cellTypes[col][row]) {
						case 0:
						case 1:
						case 19:
						case 43:
						case 45:
							Game::cellTypes[col][row] = -1;
							this->eraseCellInBuffer(col, row);
							this->killEnemyAt(col, row);
							break;
						default:
							break;
					}
				} else {
					this->invulnTimer = 0LL;
					this->slideCellsLeft = 0;
					this->damageExplorer(Game::saveData[8], 48, 0);
					this->playSound(2);
				}
				Game::cellUpdateTimers[col][row] = 24;
				return;
			}
			return;
		}
		return;
	}
}

void Game::closeDoorById(int32_t doorId) {
	if (doorId >= 0) {
		this->closeDoorAt(Game::doorCols[doorId], Game::doorRows[doorId]);
		return;
	}
}

void Game::updateExplorerAnim() {
	int32_t actorIndex = 0, nextAnim = 0, advanceAnim = 0, isIdle = 0, animEnded = 0, col = 0, row = 0, objType = 0, s0 = 0, s1 = 0, t2 = 0, t3 = 0;
	Ref<Actor> actor;
	Ref<Object> s0_o;
	actorIndex = (this->explorerStateFlags & 16384) != 0 ? 3 : 0;
	actor = Game::actors[actorIndex];
	nextAnim = -1;
	advanceAnim = 1;
	isIdle = 0;
	animEnded = actor->isAnimFinished();
	if (animEnded) {
		this->explorerStateFlags = this->explorerStateFlags & -8193;
	}
	if (actorIndex != 3) {
		switch (actor->animIndex) {
			default:
				s0 = 36;
				t2 = s0 + (this->explorerStateFlags & 7) - 1;
				s0 = t2;
				nextAnim = s0;
				break;
			case 47:
				this->playerStep = 0;
				this->currentMoveDir = 0;
				this->requestedMoveDir = 0;
				if ((Game::frameCount & 1) == 0) {
					col = this->playerCol - 2 + Game::frameCount % 5;
					row = this->playerRow - 2 + Game::frameCount % 3;
					if (col == this->playerCol && (row == this->playerRow || row == this->playerRow - 1)) {
						col = col + ((Game::frameCount >> 1 & 1) != 0 ? -1 : 1);
					}
					this->spawnCellEffect(col, row, Game::frameCount * 3 % 5);
				}
				if (animEnded != 0) {
					nextAnim = 0 + (this->explorerStateFlags & 7) - 1;
					this->heldItemAmount = -1;
					this->heldItemFrame = -1;
					this->heldItemImageSet = -1;
				}
				break;
			case 41:
			case 42:
			case 43:
			case 44:
			case 45:
			case 46:
				if (animEnded != 0) {
					nextAnim = 0 + (this->explorerStateFlags & 7) - 1;
					this->requestedMoveDir = 0;
					this->currentMoveDir = 0;
					this->playerStep = 0;
					Game::keys = 0;
				}
				break;
			case 40:
			case 48:
				this->playerStep = 0;
				this->currentMoveDir = 0;
				this->requestedMoveDir = 0;
				if (actor->frameTimer == 0) {
					if (actor->frameIndex == (actor->animIndex != 40 ? 6 : 12)) {
						this->playSound(4);
					}
					if (actor->frameIndex == (actor->animIndex != 40 ? 6 : 13)) {
						this->finishItemPickup();
					}
				}
				if (actor->isAnimFinished()) {
					this->lastLeverAnimTime = JSystem::currentTimeMillis();
					nextAnim = 0 + (this->explorerStateFlags & 7) - 1;
					this->heldItemAmount = -1;
					this->heldItemFrame = -1;
					this->heldItemImageSet = -1;
				}
				break;
			case 36:
			case 37:
			case 38:
			case 39:
				{
					if (animEnded != 0) {
						s0 = 4;
						t2 = s0 + (this->explorerStateFlags & 7) - 1;
						s0 = t2;
						nextAnim = s0;
						goto B12_end;
					}
				}
				B12_end:;
				break;
			case 35:
				isIdle = 1;
				s0 = 35;
				nextAnim = s0;
				break;
			case 34:
				isIdle = 1;
				s0 = 34;
				nextAnim = s0;
				break;
			case 27:
				{
					if (!this->isExplorerOnGround) {
						s0 = 9;
						nextAnim = s0;
						goto B13_end;
					}
				}
				B13_end:;
				break;
			case 26:
				{
					if (!this->isExplorerOnGround) {
						s0 = 8;
						nextAnim = s0;
						goto B14_end;
					}
				}
				B14_end:;
				break;
			case 25:
				{
					if (this->isExplorerOnGround) {
						s0 = 7;
						nextAnim = s0;
						goto B15_end;
					}
				}
				B15_end:;
				break;
			case 24:
				{
					if (this->isExplorerOnGround) {
						s0 = 5;
						nextAnim = s0;
						goto B16_end;
					}
				}
				B16_end:;
				break;
			case 20:
			case 21:
			case 22:
			case 23:
			case 30:
			case 31:
			case 32:
			case 33:
				if (animEnded != 0) {
					advanceAnim = 0;
					Game::keys = 0;
				}
				break;
			case 19:
				if (animEnded != 0) {
					advanceAnim = 0;
					this->loseLife();
				}
				break;
			case 17:
			case 18:
				if (animEnded == 0) {
					if (actor->frameIndex > 0 && this->heldItemImageSet != -1) {
						col = (this->explorerStateFlags & 7) != 2 ? this->playerCol - 1 : this->playerCol + 1;
						row = Game::cellObjects[col][this->playerRow] >> 8;
						objType = Game::cellObjects[col][this->playerRow] & 255;
						row = row | 256;
						if (objType != 9) {
							this->silverKeys = this->silverKeys - 1;
						} else {
							this->goldKeys = this->goldKeys - 1;
						}
						Game::cellObjects[col][this->playerRow] = row << 8 | objType;
						this->unlockDoorLock(row & 255);
						this->heldItemAmount = -1;
						this->heldItemImageSet = -1;
					}
				} else {
					nextAnim = 0 + (this->explorerStateFlags & 7) - 1;
					this->playerStep = 0;
				}
				break;
			case 13:
			case 14:
			case 15:
			case 16:
			case 28:
			case 29:
				{
					if (animEnded != 0) {
						Game::keys = 0;
						this->currentMoveDir = 0;
						this->playerStep = 0;
						s0 = 0;
						t2 = s0 + (this->explorerStateFlags & 7) - 1;
						s0 = t2;
						nextAnim = s0;
						goto B22_end;
					}
					if ((this->explorerStateFlags & 8192) == 0 && actor->frameIndex == 2 && actor->frameTimer == 0) {
						col = this->playerCol - Game::dirDeltas[this->explorerStateFlags & 7];
						row = this->playerRow - Game::dirDeltas[(this->explorerStateFlags & 7) + 8];
						if (Game::saveData[9] >= 8 && actor->frameIndex == 2 && actor->frameTimer == 0) {
							this->spawnCellEffect(col, row, -1);
						}
						this->strikeCell(col, row);
						this->requestedMoveDir = 0;
						Game::keys = 0;
					}
				}
				B22_end:;
				break;
			case 12:
				if (this->deathLetterboxHeight < 160) {
					this->deathLetterboxHeight = this->deathLetterboxHeight + 12;
				}
				break;
			case 11:
				{
					if (Game::cellTypes[this->playerCol][this->playerRow - 1] != -1) {
						if (animEnded != 0 && Game::cellTypes[this->playerCol][this->playerRow - 1] != -1) {
							this->invulnTimer = 0LL;
							this->damageExplorer(Game::saveData[8], 32, 0);
						}
					} else {
						s0 = 0;
						t2 = s0 + (this->explorerStateFlags & 7) - 1;
						s0 = t2;
						nextAnim = s0;
						goto B26_end;
					}
				}
				B26_end:;
				break;
			case 10:
				{
					if (animEnded == 0) {
						this->invulnTimer = 40LL;
					} else {
						this->explorerStateFlags = this->explorerStateFlags & -2049;
						s0 = this->endHurtState();
						nextAnim = s0;
						goto B28_end;
					}
				}
				B28_end:;
				break;
			case 9:
				{
					if (!this->isExplorerOnGround) {
						s0 = 27;
						nextAnim = s0;
						goto B29_end;
					}
				}
				B29_end:;
				break;
			case 8:
				{
					if (!this->isExplorerOnGround) {
						s0 = 26;
						nextAnim = s0;
						goto B30_end;
					}
				}
				B30_end:;
				break;
			case 7:
				{
					if (!this->isExplorerOnGround) {
						s0 = 25;
						nextAnim = s0;
						goto B31_end;
					}
				}
				B31_end:;
				break;
			case 5:
				{
					if (!this->isExplorerOnGround) {
						s0 = 24;
						nextAnim = s0;
						goto B32_end;
					}
				}
				B32_end:;
				break;
			case 4:
			case 6:
				{
					if (this->isExplorerOnGround) {
						s0 = actor->animIndex;
						nextAnim = s0;
						goto B33_end;
					}
				}
				B33_end:;
				break;
			case 2:
				isIdle = 1;
				s0 = 2;
				nextAnim = s0;
				break;
			case 1:
			case 3:
				if (animEnded != 0) {
					nextAnim = 0 + (this->explorerStateFlags & 7) - 1;
				}
				isIdle = 1;
				break;
			case 0:
				isIdle = 1;
				s0 = 0;
				nextAnim = s0;
				break;
		}
	} else {
		{
			if (animEnded != 0) {
				this->explorerStateFlags = this->explorerStateFlags & -18433;
				s0 = this->endHurtState();
				nextAnim = s0;
				goto B35_end;
			}
		}
		B35_end:;
	}
	if (isIdle == 0) {
		s0_o = this;
		s1 = 70;
	} else {
		s0_o = this;
		s1 = this->playerIdleCountdown - 1;
	}
	cast<Game>(s0_o)->playerIdleCountdown = s1;
	if (nextAnim != -1) {
		this->setExplorerAnim(nextAnim);
	}
	if (advanceAnim != 0) {
		actor->advanceFrame();
	}
	s0_o = this;
	if (this->keyHoldTimer <= 0) {
		s0_o = cast<Game>(s0_o);
		s1 = 0;
	} else {
		t3 = this->keyHoldTimer - 1;
		this->keyHoldTimer = t3;
		s0_o = cast<Game>(s0_o);
		s1 = t3;
	}
	cast<Game>(s0_o)->keyHoldTimer = s1;
}

int32_t Game::endHurtState() {
	int32_t anim = 0;
	anim = 0;
	if (this->explorerEnergy > 0) {
		anim = 0 + (this->explorerStateFlags & 7) - 1;
		this->explorerStateFlags = this->explorerStateFlags & -113 | 0;
		this->invulnTimer = 40LL;
	} else {
		this->playSound(2);
		anim = 12;
		this->deathTimer = 80;
	}
	this->currentMoveDir = 0;
	return anim;
}

void Game::vibrateDevice(int32_t durationMs) {
	if (Game::vibrationEnabled) {
		Game::midlet->display->vibrate(durationMs);
	}
}

void Game::updateSlidingObject() {
	int32_t dir = 0, state = 0, otherRow = 0, col = 0, s0 = 0;
	if (this->slidingObjSubStep > 0) {
		this->slidingObjSubStep = (int8_t)(this->slidingObjSubStep - 6);
		Game::cellMoveOffsets[this->slidingObjCol][this->slidingObjRow] = this->slidingObjSubStep;
		if ((this->slideCellsLeft == 1 || this->slideCellsLeft == -1) && this->slidingObjSubStep <= 6 && (this->explorerStateFlags & 112) == 0) {
			this->setExplorerAnim((this->explorerStateFlags & 7) != 4 ? 21 : 23);
		}
		return;
	}
	dir = this->slideCellsLeft <= 0 ? -1 : 1;
	this->slideCellsLeft = this->slideCellsLeft - dir;
	if (this->slideCellsLeft == 0) {
		if (Game::cellTypes[this->slidingObjCol][this->slidingObjRow] != 48) {
			Game::cellStates[this->slidingObjCol][this->slidingObjRow] = this->slidingObjSavedParams;
		} else {
			state = Game::cellStates[this->slidingObjCol][this->slidingObjRow];
			otherRow = this->slidingObjRow + ((state & 8) != 0 ? 1 : -1);
			Game::cellMoveOffsets[this->slidingObjCol][otherRow] = 0;
		}
		Game::cellMoveOffsets[this->slidingObjCol][this->slidingObjRow] = 0;
		this->slidingObjSavedParams = -1;
		this->redrawCellInBuffer(this->slidingObjCol, this->slidingObjRow);
	} else {
		if (Game::cellTypes[this->slidingObjCol][this->slidingObjRow] == 48) {
			state = Game::cellStates[this->slidingObjCol][this->slidingObjRow];
			otherRow = this->slidingObjRow + ((state & 8) != 0 ? 1 : -1);
			if (Game::cellTypes[this->slidingObjCol + dir][otherRow] >= 0) {
				s0 = this->playerCol;
				while (true) {
					col = s0 - dir;
					if (Game::cellTypes[col][this->playerRow] != 32) {
						break;
					}
					Game::cellTypes[col][this->playerRow] = -1;
					s0 = col;
				}
				this->slideCellsLeft = 0;
				return;
			}
			Game::cellTypes[this->slidingObjCol + dir][otherRow] = Game::cellTypes[this->slidingObjCol][otherRow];
			Game::cellTypes[this->slidingObjCol][otherRow] = -1;
			Game::cellStates[this->slidingObjCol + dir][otherRow] = Game::cellStates[this->slidingObjCol][otherRow];
			Game::cellMoveOffsets[this->slidingObjCol][otherRow] = this->slidingObjSubStep;
		}
		Game::cellTypes[this->slidingObjCol + dir][this->slidingObjRow] = Game::cellTypes[this->slidingObjCol][this->slidingObjRow];
		Game::cellTypes[this->slidingObjCol][this->slidingObjRow] = -1;
		this->eraseCellInBuffer(this->slidingObjCol, this->slidingObjRow);
		this->slidingObjCol = this->slidingObjCol + dir;
		Game::cellStates[this->slidingObjCol][this->slidingObjRow] = this->slidingObjParams | INT32_MIN;
		this->slidingObjSubStep = 18;
		Game::cellMoveOffsets[this->slidingObjCol][this->slidingObjRow] = this->slidingObjSubStep;
	}
	Game::wakeCellsAround(this->slidingObjCol - dir, this->slidingObjRow);
}

void Game::updatePistonTraps() {
	int32_t phase = 0, s1 = 0;
	phase = Game::frameCount % 89;
	if (phase >= 15) {
		if (phase >= 45) {
			if (phase >= 60) {
				s1 = 48 - 48 * (phase - 60) / 30;
			} else {
				s1 = 48;
			}
		} else {
			s1 = 48 * (phase - 15) / 30;
		}
	} else {
		s1 = 0;
	}
	this->pistonSlowExtent = s1;
	this->pistonSlowSegments = this->pistonSlowExtent <= 0 ? 1 : (this->pistonSlowExtent - 1) / 24 + 2;
	phase = Game::frameCount % 44;
	if (phase >= 7) {
		if (phase >= 22) {
			if (phase >= 30) {
				s1 = 48 - 48 * (phase - 30) / 15;
			} else {
				s1 = 48;
			}
		} else {
			s1 = 48 * (phase - 7) / 15;
		}
	} else {
		s1 = 0;
	}
	this->pistonFastExtent = s1;
	this->pistonFastSegments = this->pistonFastExtent <= 0 ? 1 : (this->pistonFastExtent - 1) / 24 + 2;
}

void Game::updateCompassDirection() {
	int32_t dx = 0, dy = 0, slope = 0, s1 = 0;
	dx = Game::compassTargets[this->nextCheckpointIndex << 1] - this->playerCol;
	dy = Game::compassTargets[(this->nextCheckpointIndex << 1) + 1] - this->playerRow;
	if (this->specialStageType == 2 && this->nextCheckpointIndex == 2) {
		dx = 10;
		dy = -8;
	}
	if (dy != 0) {
		if (dx != 0) {
			slope = idiv(dx * 128, dy);
			if (slope <= 0) {
				if (slope <= -128) {
					if (slope >= -128) {
						if (dx >= 0) {
							s1 = 2;
						} else {
							s1 = 10;
						}
					} else {
						if (dx >= 0) {
							s1 = 3;
						} else {
							s1 = 11;
						}
					}
				} else {
					if (dx >= 0) {
						s1 = 1;
					} else {
						s1 = 9;
					}
				}
			} else {
				if (slope >= 128) {
					if (slope <= 128) {
						if (dx <= 0) {
							s1 = 14;
						} else {
							s1 = 6;
						}
					} else {
						if (dx <= 0) {
							s1 = 13;
						} else {
							s1 = 5;
						}
					}
				} else {
					if (dx <= 0) {
						s1 = 15;
					} else {
						s1 = 7;
					}
				}
			}
		} else {
			if (dy >= 0) {
				s1 = 8;
			} else {
				s1 = 0;
			}
		}
	} else {
		if (dx >= 0) {
			s1 = 4;
		} else {
			s1 = 12;
		}
	}
	cast<Game>(this)->compassDirection = s1;
}

void Game::updateSpecialStage() {
	switch (this->specialStageType) {
		case 5:
			this->updateKnightBoss();
			return;
		default:
			return;
		case 4:
			this->updateAnacondaBoss();
			return;
		case 3:
			this->updateYetiBoss();
			return;
		case 2:
			this->updateIntroStageTriggers();
			this->updateIntroStage();
			return;
		case 1:
			this->updateFloodStage();
			return;
	}
}

void Game::updateIntroStage() {
	if (this->isPlayerAt(61, 3) && this->playerStep == 6) {
		this->spawnCellEffect(this->playerCol, this->playerRow, 5);
		this->isExplorerVisible = 0;
	}
	if (this->activeCutscene == nullptr && (this->isPlayerAt(60, 3) || this->isPlayerAt(61, 3))) {
		this->setHasSavedGameAndSave(1);
		this->needWriteSave = 1;
		this->freeStageMapResources();
		this->cleanup();
		this->world = 0;
		this->stage = 0;
		this->startLevelLoading();
	}
	if (this->pickedItemType == 2) {
		Game::cellObjects[11][50] = -1;
	}
}

void Game::hurtPlayerNearExplosion(int32_t screenX, int32_t screenY) {
	int32_t dy = 0, dx = 0, col = 0, row = 0;
	for (dy = -1; dy < 2; dy++) {
		for (dx = -1; dx < 2; dx++) {
			col = (this->camX + screenX) / 24 + dx;
			row = (this->camY + screenY) / 24 + dy;
			if (this->isPlayerAt(col, row)) {
				this->damageExplorer(1, 48, 0);
			}
		}
	}
}

void Game::updateKnightBoss() {
	Ref<Actor> knight;
	int32_t nextAnim = 0, playerX = 0, playerY = 0, knightPosX = 0, stepsLeft = 0, row = 0, col = 0, s0_n = 0, s1 = 0, t1 = 0, t2 = 0;
	Ref<Object> s0;
	knight = Game::actors[5];
	{
		if (this->bossState != 12) {
			if (this->bossState != -1) {
				if (this->bossState != 15 && this->bossState != -1) {
					nextAnim = -1;
					playerX = this->playerCol * 24 + 12;
					playerY = this->playerRow * 24;
					knightPosX = this->knightX + 24;
					if (this->bossState == 13) {
						nextAnim = 13;
						if (playerX > knightPosX) {
							this->bossWokenUp = 1;
						}
					}
					if (this->bossHealth > 0) {
						if (irem(Game::frameCount, this->bossHealth) != 0) {
							s0_n = 1;
						} else {
							s0_n = 2;
						}
					} else {
						s0_n = 1;
					}
					stepsLeft = s0_n;
					if (this->bossState == 6 || this->bossState == 7) {
						stepsLeft = (Game::frameCount & 11) != 0 ? stepsLeft : 2;
					}
					if (!this->bossAttackPending && (this->bossState == 0 || this->bossState == 1)) {
						if (this->bossState != 0) {
							s0 = this;
							s1 = 36;
						} else {
							this->bossAttackOffset = 36;
							this->bossAttackOffset = this->bossAttackOffset ^ -1;
							s0 = this;
							s1 = this->bossAttackOffset + 1;
						}
						cast<Game>(s0)->bossAttackOffset = s1;
						if (playerY < 504 && (playerX == knightPosX + this->bossAttackOffset || Game::frameCount % 76 == 0)) {
							this->bossAttackPending = 1;
						}
					}
					while (true) {
						t2 = stepsLeft;
						stepsLeft = stepsLeft - 1;
						if (t2 <= 0) {
							break;
						}
						switch (this->bossState) {
							case 13:
								if (!knight->isAnimFinished()) {
									if (this->bossWokenUp) {
										knight->advanceFrame();
									}
								} else {
									nextAnim = 0;
									this->bossState = nextAnim;
									this->bossWokenUp = 0;
								}
								break;
							case 10:
							case 11:
								if (playerX <= knightPosX || knightPosX >= 504) {
									if (playerX < knightPosX && knightPosX > 360) {
										s0 = this;
										s1 = 0;
										nextAnim = s1;
										cast<Game>(s0)->bossState = nextAnim;
									}
								} else {
									s0 = this;
									s1 = 1;
									nextAnim = s1;
									cast<Game>(s0)->bossState = nextAnim;
								}
								this->bossAttackPending = 0;
								this->bossAttackOffset = 0;
								break;
							case 9:
								if (knight->isAnimFinished()) {
									nextAnim = 11;
									this->bossState = nextAnim;
								}
								if (knight->frameIndex >= 4 && playerY >= 504 && playerX >= knightPosX && playerX <= knightPosX + 48) {
									this->damageExplorer(1, 48, 0);
								}
								break;
							case 8:
								if (knight->isAnimFinished()) {
									nextAnim = 10;
									this->bossState = nextAnim;
								}
								if (knight->frameIndex >= 4 && playerY >= 504 && playerX >= knightPosX - 48 && playerX <= knightPosX) {
									this->damageExplorer(1, 48, 0);
								}
								break;
							case 7:
								if (playerY < 504) {
									if (knightPosX <= 504) {
										nextAnim = 1;
										this->bossState = nextAnim;
									}
								} else {
									if (playerX > knightPosX + 48) {
										this->knightX = this->knightX + 2;
									} else {
										nextAnim = 9;
										this->bossState = nextAnim;
									}
								}
								break;
							case 6:
								if (playerY < 504) {
									if (knightPosX >= 360) {
										nextAnim = 0;
										this->bossState = nextAnim;
									}
								} else {
									if (playerX < knightPosX - 48) {
										this->knightX = this->knightX - 2;
									} else {
										nextAnim = 8;
										this->bossState = nextAnim;
									}
								}
								break;
							case 4:
							case 5:
								if (knight->isAnimFinished()) {
									nextAnim = this->bossState != 4 ? 1 : 0;
									this->bossState = nextAnim;
								}
								this->bossAttackPending = 0;
								this->bossAttackOffset = 0;
								break;
							case 3:
								if (knight->frameIndex == 5 && knight->frameTimer == 0) {
									this->shakeTime = 30;
								}
								if (knight->isAnimFinished()) {
									nextAnim = 11;
									this->bossState = nextAnim;
									this->bossAttackPending = 0;
									this->bossAttackOffset = 0;
								}
								if (knight->frameIndex >= 7 && playerY < 504 && playerX == knightPosX + this->bossAttackOffset) {
									this->damageExplorer(1, 48, 0);
								}
								break;
							case 2:
								if (knight->frameIndex == 5 && knight->frameTimer == 0) {
									this->shakeTime = 30;
								}
								if (knight->isAnimFinished()) {
									nextAnim = 10;
									this->bossState = nextAnim;
									this->bossAttackPending = 0;
									this->bossAttackOffset = 0;
								}
								if (knight->frameIndex >= 7 && playerY < 504 && playerX == knightPosX + this->bossAttackOffset) {
									this->damageExplorer(1, 48, 0);
								}
								break;
							case 1:
								if (playerY < 504 || knightPosX >= 504) {
									if (!this->bossAttackPending) {
										if (knightPosX < 504) {
											this->knightX = this->knightX + 1;
										} else {
											nextAnim = 0;
											this->bossState = nextAnim;
										}
									} else {
										nextAnim = 3;
										this->bossState = nextAnim;
									}
								} else {
									if (playerX >= knightPosX) {
										nextAnim = 7;
										this->bossState = nextAnim;
									} else {
										this->knightX = this->knightX + 1;
									}
								}
								break;
							case 0:
								if (playerY < 504 || knightPosX <= 360) {
									if (!this->bossAttackPending) {
										if (knightPosX > 360) {
											this->knightX = this->knightX - 1;
										} else {
											nextAnim = 1;
											this->bossState = nextAnim;
										}
									} else {
										nextAnim = 2;
										this->bossState = nextAnim;
									}
								} else {
									if (playerX >= knightPosX) {
										this->knightX = this->knightX - 1;
									} else {
										nextAnim = 6;
										this->bossState = nextAnim;
									}
								}
								break;
							default:
								break;
						}
						if (playerY >= 504 && playerX >= knightPosX - 24 && playerX <= knightPosX - 24) {
							this->damageExplorer(1, 48, Game::oppositeDir[this->explorerStateFlags & 7]);
						}
					}
					if ((this->bossState == 8 || this->bossState == 9) && knight->frameIndex == 5) {
						this->dropBossShakeRocks();
					}
					if (this->bossState != 6 && this->bossState != 7) {
						for (row = 21; row < 23; row++) {
							for (col = knightPosX / 24 - 1; col < knightPosX / 24 - 2 + 4; col++) {
								if (Game::cellTypes[col][row] == 0) {
									if ((Game::cellStates[col][row] & 7) == 3 && this->bossState != 13) {
										this->bossHealth = this->bossHealth - 1;
										switch (this->bossState) {
											case 1:
											case 3:
											case 5:
											case 9:
											case 11:
												s0 = this;
												s1 = 5;
												nextAnim = s1;
												cast<Game>(s0)->bossState = nextAnim;
												break;
											case 0:
											case 2:
											case 4:
											case 8:
											case 10:
												s0 = this;
												s1 = 4;
												nextAnim = s1;
												cast<Game>(s0)->bossState = nextAnim;
												break;
											default:
												break;
										}
									}
									Game::cellTypes[col][row] = -1;
									this->eraseCellInBuffer(col, row);
									Game::cellTypes[col][row] = 30;
									Game::cellUpdateTimers[col][row] = 24;
									Game::cellStates[col][row] = 4;
									this->playSound(14);
								}
							}
						}
					}
					if (this->bossHealth <= 0) {
						this->bossState = 12;
						this->bossTimer = 0;
						nextAnim = 12;
					}
					if (nextAnim == -1) {
						s0 = knight;
						goto B1_end;
					}
					knight->setAnimation(nextAnim);
					return;
				}
			} else {
				if (this->playerCol * 24 >= 360) {
					this->bossState = 10;
					knight->setAnimation(10);
					return;
				}
			}
			return;
		}
		t1 = this->bossTimer;
		this->bossTimer = t1 + 1;
		if (t1 <= 100) {
			this->sound->play(7);
		} else {
			this->bossState = 15;
			this->killEnemyAt(11, 11);
		}
		s0 = knight;
	}
	B1_end:;
	cast<Actor>(s0)->advanceFrame();
}

void Game::checkAnacondaBodyHit() {
	int32_t holeCol = 0, topY = 0, bottomY = 0, frameDy = 0, playerY = 0;
	Ref<Actor> anaconda;
	holeCol = this->getAnacondaHoleCol();
	if (this->playerCol == holeCol || this->playerCol == holeCol + 1) {
		anaconda = Game::actors[5];
		topY = anaconda->y - 40;
		bottomY = anaconda->y + 256;
		frameDy = (anaconda->sprite->animFirstFrame[anaconda->animIndex] + anaconda->frameIndex) * 5;
		frameDy = (anaconda->sprite->animFrames[frameDy + 3] << 0) * 1 / 1;
		topY = topY - frameDy;
		bottomY = bottomY - frameDy;
		playerY = Game::actors[0]->y;
		if (playerY > topY && playerY < bottomY && !this->anacondaHitPlayer) {
			this->damageExplorer(1, 48, this->playerCol != holeCol ? 2 : 4);
		}
	}
}

void Game::clearAnacondaBlock(int32_t col, int32_t row) {
	if (col < 0 || row < 0) {
		return;
	}
	Game::cellTypes[col][row] = -1;
	Game::cellTypes[col + 1][row] = -1;
}

void Game::placeAnacondaBlock(int32_t col, int32_t row) {
	if (col < 0 || row < 0) {
		return;
	}
	Game::cellTypes[col][row] = 50;
	Game::cellTypes[col + 1][row] = 50;
}

bool Game::smashBouldersAt(int32_t col, int32_t row) {
	int32_t smashed = 0, x = 0, y = 0;
	smashed = 0;
	for (x = col; x <= col + 1; x++) {
		for (y = row; y >= row - 1; y--) {
			if (Game::cellTypes[x][y] == 0) {
				this->crushCellContents(x, y);
				Game::wakeCellsAround(x, y);
				Game::cellTypes[x][y] = -1;
				this->eraseCellInBuffer(x, y);
				smashed = 1;
			}
		}
	}
	return smashed;
}

int32_t Game::getAnacondaHoleCol() {
	int32_t notFirstHole = 0;
	notFirstHole = this->anacondaHoleIndex > 0 ? 1 : 0;
	return 10 + this->anacondaHoleIndex * (2 + notFirstHole);
}

int32_t Game::getAnacondaHeadRow() {
	Ref<Actor> anaconda;
	int32_t headY = 0, frameDy = 0;
	anaconda = Game::actors[5];
	headY = anaconda->y - 40;
	frameDy = (anaconda->sprite->animFirstFrame[anaconda->animIndex] + anaconda->frameIndex) * 5;
	frameDy = (anaconda->sprite->animFrames[frameDy + 3] << 0) * 1 / 1;
	headY = headY - frameDy;
	headY = headY + this->camY;
	return idiv(this->levelH * headY, this->levelH * 24);
}

bool Game::smashBouldersUnderAnaconda() {
	int32_t holeCol = 0, headRow = 0, smashed = 0, col = 0, row = 0;
	holeCol = this->getAnacondaHoleCol();
	headRow = this->getAnacondaHeadRow();
	smashed = 0;
	for (col = holeCol; col <= holeCol + 1; col++) {
		for (row = headRow; row <= 10; row++) {
			if (Game::cellTypes[col][row] == 0) {
				this->crushCellContents(col, row);
				Game::wakeCellsAround(col, row);
				Game::cellTypes[col][row] = -1;
				this->eraseCellInBuffer(col, row);
				smashed = 1;
			}
		}
	}
	return smashed;
}

int32_t Game::pickAnacondaHoleNearPlayer() {
	int32_t relCol = 0, hole = 0;
	relCol = this->playerCol - 10;
	hole = relCol / 3;
	if (relCol == hole * 3 + 2) {
		hole = hole + Game::frameCount % 50 / 25;
	}
	return hole;
}

void Game::updateAnacondaBoss() {
	Ref<Actor> anaconda, slamActor;
	int32_t headY2 = 0, frameDy2 = 0, nextAnim = 0, slamAnim = 0, holeCol = 0, waitFrames = 0, headY = 0, frameDy = 0, s0 = 0;
	if (this->bossState == 5) {
		if (!this->bossStepDoneThisFrame) {
			this->bossStepDoneThisFrame = 1;
		} else {
			return;
		}
	}
	anaconda = Game::actors[5];
	this->bossTimer = this->bossTimer + 1;
	nextAnim = -1;
	slamActor = Game::actors[4];
	slamAnim = -1;
	holeCol = this->getAnacondaHoleCol();
	if (Game::cellTypes[this->bossRockCol1][2] == -1) {
		Game::cellTypes[this->bossRockCol1][2] = 31;
	}
	if (Game::cellTypes[this->bossRockCol2][2] == -1) {
		Game::cellTypes[this->bossRockCol2][2] = 31;
	}
	switch (this->bossState) {
		case 11:
			this->bossTimer = this->bossTimer - 1;
			this->anacondaAttackTimer = this->anacondaAttackTimer + 1;
			if (this->anacondaAttackTimer < 12) {
				if (!this->anacondaHitPlayer) {
					this->checkAnacondaSlamHit();
				}
			} else {
				this->anacondaAttackTimer = 0;
				this->bossState = 9;
				nextAnim = 4;
				this->anacondaHitPlayer = 0;
				this->anacondaSlamVisible = 0;
			}
			break;
		case 10:
			this->bossTimer = this->bossTimer - 1;
			this->checkAnacondaBodyHit();
			this->anacondaAttackTimer = this->anacondaAttackTimer + 1;
			if (this->anacondaAttackTimer == 28) {
				nextAnim = 7;
			}
			if (this->anacondaAttackTimer >= 50) {
				this->anacondaAttackTimer = 0;
				this->bossState = 11;
				Game::clearAnacondaBlock(this->anacondaBlockCol, this->anacondaBlockRow);
				this->anacondaBlockCol = -1;
				this->anacondaBlockRow = -1;
				nextAnim = 8;
				slamAnim = 2;
				this->anacondaSlamVisible = 1;
			}
			break;
		case 9:
			this->bossTimer = this->bossTimer - 2;
			this->checkAnacondaBodyHit();
			headY2 = anaconda->y - 40;
			frameDy2 = (anaconda->sprite->animFirstFrame[anaconda->animIndex] + anaconda->frameIndex) * 5;
			frameDy2 = (anaconda->sprite->animFrames[frameDy2 + 3] << 0) * 1 / 1;
			headY2 = headY2 - frameDy2;
			if (headY2 >= 240 - this->camY + 40) {
				this->bossState = 6;
				this->bossTimer = 0;
				this->anacondaHoleIndex = this->pickAnacondaHoleNearPlayer();
			}
			break;
		case 7:
			Game::clearAnacondaBlock(this->anacondaBlockCol, this->anacondaBlockRow);
			this->anacondaBlockCol = -1;
			this->anacondaBlockRow = -1;
			if (this->bossTimer > 80) {
				this->bossState = 8;
				this->progressGateObjective();
			}
			if ((this->bossTimer & 111) == 1) {
				this->playSound(7);
			}
			break;
		case 6:
			if (this->bossTimer > 10) {
				this->bossState = 1;
				nextAnim = 2;
				this->bossTimer = 0;
			}
			break;
		case 5:
			headY = anaconda->y - 40;
			frameDy = (anaconda->sprite->animFirstFrame[anaconda->animIndex] + anaconda->frameIndex) * 5;
			frameDy = (anaconda->sprite->animFrames[frameDy + 3] << 0) * 1 / 1;
			headY = headY - frameDy;
			if (headY <= 72 - this->camY + 40) {
				this->anacondaRiseOffset = 0;
				this->dropBossShakeRocks();
				this->bossState = 10;
				this->anacondaBlockCol = holeCol;
				this->anacondaBlockRow = 4;
				Game::placeAnacondaBlock(this->anacondaBlockCol, this->anacondaBlockRow);
			}
			this->smashBouldersUnderAnaconda();
			this->checkAnacondaBodyHit();
			break;
		case 4:
			waitFrames = this->bossHealth > 1 ? 10 : 5;
			{
				if (this->bossTimer < waitFrames) {
					if (this->bossTimer > waitFrames >> 1 && anaconda->animIndex != 1) {
						s0 = 1;
						nextAnim = s0;
					}
				} else {
					this->bossState = 5;
					this->bossTimer = 0;
					s0 = 4;
					nextAnim = s0;
					goto B15_end;
				}
			}
			B15_end:;
			this->smashBouldersUnderAnaconda();
			this->checkAnacondaBodyHit();
			break;
		case 3:
			waitFrames = 0;
			if (this->bossTimer > 40) {
				if (this->bossHealth <= 0) {
					this->bossState = 7;
					this->bossTimer = 0;
				} else {
					if (this->anacondaStateWhenHit != 10) {
						if (this->anacondaStateWhenHit == 2 || this->anacondaStateWhenHit == 1) {
							this->bossState = 4;
							this->bossTimer = 0;
							nextAnim = 2;
						}
					} else {
						this->bossState = 9;
						this->bossTimer = 0;
					}
				}
			}
			break;
		case 2:
			waitFrames = 0;
			if (this->smashBouldersAt(holeCol, 8)) {
				this->bossHealth = this->bossHealth - 1;
				this->anacondaStateWhenHit = this->bossState;
				Game::clearAnacondaBlock(this->anacondaBlockCol, this->anacondaBlockRow);
				this->anacondaBlockCol = -1;
				this->anacondaBlockRow = -1;
				this->anacondaStateWhenHit = this->bossState;
				this->bossState = 3;
				nextAnim = 3;
				this->playSound(10);
			}
			if (this->bossTimer > 15 && anaconda->animIndex != 6) {
				nextAnim = 6;
			}
			if (this->bossTimer > 30) {
				this->bossState = 4;
				this->bossTimer = 0;
				nextAnim = 0;
				Game::clearAnacondaBlock(this->anacondaBlockCol, this->anacondaBlockRow);
				this->anacondaBlockCol = -1;
				this->anacondaBlockRow = -1;
			}
			break;
		case 1:
			waitFrames = 0;
			if (this->bossTimer <= 40) {
				if (this->bossTimer > 20) {
					this->smashBouldersAt(holeCol, 8);
					Game::placeAnacondaBlock(holeCol, 8);
					this->anacondaBlockCol = holeCol;
					this->anacondaBlockRow = 8;
				}
			} else {
				this->bossState = 2;
				this->bossTimer = 0;
			}
			break;
		case 0:
			if (this->playerCol >= 10) {
				this->bossState = 6;
				this->bossTimer = 0;
			}
			break;
		default:
			break;
	}
	if (nextAnim != -1) {
		anaconda->setAnimation(nextAnim);
	} else {
		anaconda->advanceFrame();
	}
	if (this->anacondaSlamVisible) {
		if (slamAnim != -1) {
			slamActor->setAnimation(slamAnim);
		} else {
			slamActor->advanceFrame();
			return;
		}
	}
}

void Game::checkAnacondaSlamHit() {
	int32_t holeCol = 0;
	holeCol = this->getAnacondaHoleCol();
	if (this->playerRow == 4 && this->playerCol >= holeCol - 3 && this->playerCol <= holeCol + 4) {
		this->damageExplorer(1, 64, this->playerCol != holeCol ? 2 : 4);
		this->anacondaHitPlayer = 1;
	}
}

void Game::dropBossShakeRocks() {
	this->shakeTime = 30;
	if (Game::cellTypes[this->bossRockCol1][this->bossRockCheckRow] == -1) {
		Game::cellTypes[this->bossRockCol1][this->bossRockSpawnRow] = 0;
		Game::wakeCellsAround(this->bossRockCol1, this->bossRockSpawnRow);
	}
	if (Game::cellTypes[this->bossRockCol2][this->bossRockCheckRow] == -1) {
		Game::cellTypes[this->bossRockCol2][this->bossRockSpawnRow] = 0;
		Game::wakeCellsAround(this->bossRockCol2, this->bossRockSpawnRow);
	}
}

void Game::resetBoss() {
	this->bossState = -1;
	this->bossHealth = 5;
}

void Game::updateYetiBoss() {
	Ref<Actor> yetiActor;
	int32_t playerY = 0, yetiCenterX = 0, stepsThisFrame = 0, row = 0, col = 0, stompReachLeft = 0, stompReachRight = 0, savedUpdateCol = 0, savedUpdateRow = 0, viewMinCol = 0, viewMaxCol = 0, viewMaxRow = 0, viewMinRow = 0, nextState = 0, playerCenterX = 0, s0_n = 0, s1 = 0, t1 = 0, t2 = 0;
	Ref<Object> s0;
	yetiActor = Game::actors[5];
	savedUpdateCol = this->updateCellCol;
	savedUpdateRow = this->updateCellRow;
	viewMinCol = this->playerCol - 8;
	viewMaxCol = this->playerCol + 8;
	viewMaxRow = this->playerRow + 8;
	viewMinRow = this->playerRow - 8;
	for (nextState = 15; nextState <= 22; nextState++) {
		for (playerCenterX = 14; playerCenterX <= 21; playerCenterX++) {
			if (playerCenterX <= viewMinCol || playerCenterX >= viewMaxCol || nextState <= viewMaxRow || nextState >= viewMinRow) {
				if (Game::cellTypes[playerCenterX][nextState] == 44) {
					this->updateCellCol = playerCenterX;
					this->updateCellRow = nextState;
					this->updateStalactite();
				}
			}
		}
	}
	this->updateCellCol = savedUpdateCol;
	this->updateCellRow = savedUpdateRow;
	if (this->explorerEnergy == 0) {
		this->resetBoss();
	}
	{
		if (this->bossState != 12) {
			if (this->bossState != -1) {
				if (this->bossState != 15 && this->bossState != -1) {
					nextState = -1;
					playerCenterX = this->playerCol * 24 + 12;
					playerY = this->playerRow * 24;
					yetiCenterX = this->yetiX + 24;
					if (this->bossQuakeFrame == 0LL && this->explorerEnergy != 0) {
						this->bossQuakeFrame = (int64_t)(Game::frameCount + Rnd::nextInRange(340, 441));
					}
					if (this->bossHealth > 0) {
						if (irem(Game::frameCount, this->bossHealth) != 0) {
							s0_n = 1;
						} else {
							s0_n = 2;
						}
					} else {
						s0_n = 1;
					}
					stepsThisFrame = s0_n;
					if (this->bossState == 10 || this->bossState == 11) {
						stepsThisFrame = (Game::frameCount & 11) != 0 ? stepsThisFrame : 2;
					}
					while (true) {
						t2 = stepsThisFrame;
						stepsThisFrame = stepsThisFrame - 1;
						if (t2 <= 0) {
							break;
						}
						switch (this->bossState) {
							case 11:
								if (!yetiActor->isAnimFinished()) {
									this->yetiX = this->yetiX + 2;
								} else {
									this->shakeTime = 10;
									yetiCenterX = this->yetiX + 24;
									if ((int64_t)Game::frameCount <= this->bossQuakeFrame) {
										if (playerY < 504) {
											nextState = 5;
											this->bossState = nextState;
										} else {
											if (playerCenterX <= yetiCenterX + 48) {
												nextState = 7;
												this->bossState = nextState;
											}
										}
									} else {
										nextState = 14;
										this->bossState = nextState;
									}
								}
								break;
							case 10:
								if (!yetiActor->isAnimFinished()) {
									this->yetiX = this->yetiX - 2;
								} else {
									this->shakeTime = 10;
									yetiCenterX = this->yetiX + 24;
									if ((int64_t)Game::frameCount <= this->bossQuakeFrame) {
										if (playerY < 504) {
											nextState = 4;
											this->bossState = nextState;
										} else {
											if (playerCenterX >= yetiCenterX - 48) {
												nextState = 6;
												this->bossState = nextState;
											}
										}
									} else {
										nextState = 13;
										this->bossState = nextState;
									}
								}
								break;
							case 6:
							case 7:
							case 13:
							case 14:
								col = 0;
								stompReachLeft = 0;
								stompReachRight = 0;
								switch (this->bossState) {
									case 7:
									case 14:
										col = 5;
										stompReachLeft = 1;
										s0_n = 2;
										stompReachRight = s0_n;
										break;
									case 6:
									case 13:
										col = 4;
										stompReachLeft = 2;
										s0_n = 1;
										stompReachRight = s0_n;
										break;
									default:
										break;
								}
								if (yetiActor->frameIndex == 5 && yetiActor->frameTimer == 0) {
									if (this->bossState == 13 || this->bossState == 14) {
										s0 = this;
										s1 = 80;
									} else {
										s0 = this;
										s1 = 10;
									}
									cast<Game>(s0)->shakeTime = s1;
								}
								if (yetiActor->isAnimFinished()) {
									if (this->bossState == 13 || this->bossState == 14) {
										this->ceilingCollapseFrame = (int64_t)(Game::frameCount + 40);
										this->bossQuakeFrame = (int64_t)(Game::frameCount + Rnd::nextInRange(340, 441));
									}
									nextState = col;
									this->bossState = nextState;
								}
								if (yetiActor->frameIndex >= 5 && playerY >= 504 && playerCenterX >= yetiCenterX - stompReachLeft * 24 && playerCenterX <= yetiCenterX + stompReachRight * 24) {
									this->damageExplorer(1, 48, 4);
								}
								break;
							case 5:
								if ((int64_t)Game::frameCount <= this->bossQuakeFrame) {
									if (playerY >= 504 && playerCenterX > yetiCenterX && this->yetiX + 48 <= 504) {
										nextState = 11;
										this->bossState = nextState;
									}
									if (yetiCenterX >= 504) {
										nextState = 4;
										this->bossState = nextState;
									}
									if (this->bossState == 5) {
										this->yetiX = this->yetiX + 1;
									}
								} else {
									nextState = 14;
									this->bossState = nextState;
								}
								break;
							case 4:
								if ((int64_t)Game::frameCount <= this->bossQuakeFrame) {
									if (playerY >= 504 && playerCenterX < yetiCenterX && this->yetiX - 48 >= 360) {
										nextState = 10;
										this->bossState = nextState;
									}
									if (yetiCenterX <= 360) {
										nextState = 5;
										this->bossState = nextState;
									}
									if (this->bossState == 4) {
										this->yetiX = this->yetiX - 1;
									}
								} else {
									nextState = 13;
									this->bossState = nextState;
								}
								break;
							case 3:
								if (yetiActor->isAnimFinished()) {
									if ((int64_t)Game::frameCount <= this->bossQuakeFrame) {
										nextState = 5;
										this->bossState = nextState;
									} else {
										nextState = 14;
										this->bossState = nextState;
									}
								}
								break;
							case 2:
								if (yetiActor->isAnimFinished()) {
									if ((int64_t)Game::frameCount <= this->bossQuakeFrame) {
										nextState = 4;
										this->bossState = nextState;
									} else {
										nextState = 13;
										this->bossState = nextState;
									}
								}
								break;
							case 1:
								if (yetiCenterX >= 504) {
									nextState = 4;
									this->bossState = nextState;
								} else {
									nextState = 5;
									this->bossState = nextState;
								}
								break;
							case 0:
								if (yetiCenterX <= 360) {
									nextState = 5;
									this->bossState = nextState;
								} else {
									nextState = 4;
									this->bossState = nextState;
								}
								break;
							default:
								break;
						}
						if (playerY >= 504 && playerCenterX >= yetiCenterX - 24 && playerCenterX <= yetiCenterX + 24) {
							this->damageExplorer(1, 48, Game::oppositeDir[this->explorerStateFlags & 7]);
						}
						if (this->bossHealth > 0) {
							continue;
						}
						this->bossState = 12;
						this->bossTimer = 0;
						return;
					}
					if (this->switchWallsPhase == 5) {
						if (this->leverMoveDir > 0) {
							Game::cellTypes[10][19] = 45;
							Game::cellUpdateTimers[10][19] = 24;
							Game::cellMoveOffsets[10][19] = 0;
							Game::cellStates[10][19] = 0;
							if (this->bossHealth <= 2) {
								Game::cellTypes[26][16] = 45;
								Game::cellUpdateTimers[26][16] = 24;
								Game::cellMoveOffsets[26][16] = 0;
								s0 = Game::cellStates[26];
								s1 = 16;
								cast<Array<int32_t>>(s0)[s1] = 0;
							}
						} else {
							if (this->bossHealth <= 2) {
								Game::cellTypes[10][16] = 45;
								Game::cellUpdateTimers[10][16] = 24;
								Game::cellMoveOffsets[10][16] = 0;
								Game::cellStates[10][16] = 0;
							}
							Game::cellTypes[26][19] = 45;
							Game::cellUpdateTimers[26][19] = 24;
							Game::cellMoveOffsets[26][19] = 0;
							s0 = Game::cellStates[26];
							s1 = 19;
							cast<Array<int32_t>>(s0)[s1] = 0;
						}
					}
					if (this->bossState != 10 && this->bossState != 11) {
						for (row = 21; row < 23; row++) {
							for (col = yetiCenterX / 24 - 1; col < yetiCenterX / 24 - 2 + 4; col++) {
								if (Game::cellTypes[col][row] == 9) {
									if ((Game::cellStates[col][row] & 7) == 3) {
										this->bossHealth = this->bossHealth - 1;
										switch (this->bossState) {
											case 1:
											case 3:
											case 5:
											case 7:
												s0 = this;
												s1 = 3;
												nextState = s1;
												cast<Game>(s0)->bossState = nextState;
												break;
											case 0:
											case 2:
											case 4:
											case 6:
												s0 = this;
												s1 = 2;
												nextState = s1;
												cast<Game>(s0)->bossState = nextState;
												break;
											default:
												break;
										}
									}
									Game::cellTypes[col][row] = -1;
									this->eraseCellInBuffer(col, row);
									Game::cellTypes[col][row] = 30;
									Game::cellUpdateTimers[col][row] = 24;
									Game::cellStates[col][row] = 4;
									this->playSound(14);
								}
							}
						}
					}
					if (nextState == -1) {
						s0 = yetiActor;
						goto B6_end;
					}
					yetiActor->setAnimation(nextState);
					return;
				}
			} else {
				if (this->playerCol * 24 >= 336) {
					this->bossState = 0;
					yetiActor->setAnimation(0);
					return;
				}
			}
			return;
		}
		t1 = this->bossTimer;
		this->bossTimer = t1 + 1;
		if (t1 <= 100) {
			this->sound->play(7);
		} else {
			this->bossState = 15;
			this->killEnemyAt(11, 11);
		}
		s0 = yetiActor;
	}
	B6_end:;
	cast<Actor>(s0)->advanceFrame();
}

void Game::updateFloodStage() {
	int32_t minFloodHeight = 0, s1 = 0;
	Ref<Object> s0;
	if (Game::cellTypes[18][63] == 0 && Game::cellMoveOffsets[18][63] <= 0 && this->floodTriggerStage == 0) {
		this->shakeTime = 120;
		this->floodTriggerStage = this->floodTriggerStage + 1;
	}
	if (this->floodTriggerStage != 3) {
		if (Game::actors[2]->animIndex != 0) {
			s0 = Game::actors[2];
			s1 = 0;
			cast<Actor>(s0)->setAnimation(s1);
		}
	} else {
		if (Game::actors[2]->animIndex != 0) {
			if (Game::actors[2]->animIndex == 1 && Game::actors[2]->isAnimFinished()) {
				Game::actors[2]->setAnimation(2);
				if (this->playerRow == this->levelH - 4) {
					this->floodHeight = 817;
				}
			}
		} else {
			s0 = Game::actors[2];
			s1 = 1;
			cast<Actor>(s0)->setAnimation(s1);
		}
	}
	Game::actors[2]->advanceFrame();
	if (Game::actors[2]->animIndex == 2) {
		Game::actors[1]->advanceFrame();
		if (this->shakeTime == 10) {
			this->shakeTime = 60;
		}
		if (Game::actors[1]->animIndex != 0) {
			if (Game::actors[1]->isAnimFinished()) {
				Game::actors[1]->setAnimation(0);
			}
		} else {
			if ((this->activeCutscene == nullptr || this->floodHeight < 46) && this->floodHeight < 1704) {
				this->floodHeight = this->floodHeight + 1;
				minFloodHeight = this->levelH * 24 - (this->camY + 320 - 80);
				if (this->floodHeight < minFloodHeight) {
					this->floodHeight = minFloodHeight;
				}
			}
			if (this->levelH * 24 - this->floodHeight <= this->playerRow * 24 + 18 && this->playerCol < 17) {
				this->damageExplorer(Game::saveData[8], 64, 1);
				return;
			}
		}
	}
}

void Game::updateIntroStageTriggers() {
	int32_t triggerId = 0;
	if (Game::cellObjects != nullptr && this->isPlayerInsideBorder() && (Game::cellObjects[this->playerCol][this->playerRow] & 255) == 0) {
		triggerId = Game::cellObjects[this->playerCol][this->playerRow] >> 8;
		if (triggerId != 13) {
			if (triggerId == 16) {
				this->introTrigger16Reached = 1;
			}
		} else {
			this->introTrigger13Reached = 1;
		}
	}
	if (!this->introHintSpotReached && this->playerStep <= 0 && this->isPlayerAt(46, 7)) {
		this->introHintIconVisible = 1;
		this->introHintSpotReached = 1;
	}
}

void Game::updateCameraFollow() {
	int32_t moveDir = 0, playerPos = 0, maxCamX = 0, maxCamY = 0, s1 = 0, s2 = 0;
	Ref<Game> s0_o, s1_o;
	moveDir = (this->explorerStateFlags & 4096) != 0 ? 0 : this->currentMoveDir;
	playerPos = this->playerCol * 24 + this->playerStep * Game::dirDeltas[moveDir];
	maxCamX = 24 * this->levelW - 240;
	maxCamY = 24 * this->levelH - 240;
	if (playerPos >= this->camTargetX + 96) {
		if (playerPos > this->camTargetX + 120) {
			this->camTargetX = this->camTargetX - 120 + playerPos >> 1;
			if (this->camTargetX > maxCamX) {
				s0_o = this;
				s1 = maxCamX;
				s0_o->camTargetX = s1;
			}
		}
	} else {
		this->camTargetX = this->camTargetX - 96 + playerPos >> 1;
		if (this->camTargetX < 0) {
			s0_o = this;
			s1 = 0;
			s0_o->camTargetX = s1;
		}
	}
	playerPos = this->playerRow * 24 + this->playerStep * Game::dirDeltas[moveDir + 8] + 40;
	if (playerPos < this->camTargetY + 96) {
		this->camTargetY = this->camTargetY - 96 + playerPos >> 1;
		if (this->camTargetY < 0) {
			this->camTargetY = 0;
		}
	}
	if (playerPos > this->camTargetY + 160) {
		this->camTargetY = this->camTargetY - 160 + playerPos >> 1;
		if (this->camTargetY > maxCamY) {
			this->camTargetY = maxCamY;
		}
	}
	this->camX = this->camTargetX;
	this->camY = this->camTargetY;
	{
		if (this->camX < 0) {
			s0_o = this;
			s1 = 0;
			s0_o->camX = s1;
			goto B9_end;
		}
		if (this->camX > maxCamX) {
			s0_o = this;
			s1 = maxCamX;
			s0_o->camX = s1;
		}
	}
	B9_end:;
	{
		if (this->camY < 0) {
			s0_o = this;
			s1_o = this;
			s2 = 0;
			s1_o->camTargetY = s2;
			s0_o->camY = s2;
			goto B11_end;
		}
		if (this->camY > maxCamY) {
			s0_o = this;
			s1_o = this;
			s2 = maxCamY;
			s1_o->camTargetY = s2;
			s0_o->camY = s2;
		}
	}
	B11_end:;
}

void Game::pushObjectSideways(int32_t col, int32_t row, bool toRight, int8_t cellType) {
	int32_t destCol = 0, state = 0, s0 = 0, s1 = 0;
	destCol = toRight == 0 ? col - 1 : col + 1;
	state = Game::cellStates[col][row];
	Game::cellTypes[destCol][row] = cellType;
	Game::cellTypes[col][row] = -1;
	Game::cellMoveOffsets[destCol][row] = 18;
	if (toRight == 0) {
		state = state & -8 | 4;
		s0 = state & -3073;
		s1 = 2048;
	} else {
		state = state & -8 | 2;
		s0 = state & -3073;
		s1 = 1024;
	}
	state = s0 | s1;
	Game::cellStates[destCol][row] = state & -513 | INT32_MIN;
	Game::wakeCellsAround(destCol, row);
	this->eraseCellInBuffer(col, row);
}

void Game::clearConnectedObjects(int32_t col, int32_t row, int8_t objType) {
	if ((Game::cellObjects[col][row] & 255) == objType) {
		Game::cellObjects[col][row] = -1;
		this->clearConnectedObjects(col - 1, row, objType);
		this->clearConnectedObjects(col + 1, row, objType);
		this->clearConnectedObjects(col, row - 1, objType);
		this->clearConnectedObjects(col, row + 1, objType);
	}
}

bool Game::tryMoveExplorer(int32_t dx, int32_t dy, bool testOnly) {
	int32_t newPushDelay = 0, newStep = 0, curDeathTimer = 0, targetCol = 0, targetRow = 0, canMove = 0, onHintTile = 0, objType = 0, objParam = 0, targetCellType = 0, pushDestCol = 0, pushDestRow = 0, destObjType = 0, destObjParam = 0, cellBelowTarget = 0, topCellOffset = 0, bottomCellOffset = 0, blockedByObject = 0, newStateFlags = 0, newCol = 0, newRow = 0, newMoveDir = 0, newExiting = 0, s0 = 0, s1 = 0;
	Ref<Object> s0_o;
	Ref<Game> t5;
	blockedByObject = 0;
	newStateFlags = this->explorerStateFlags;
	newCol = this->playerCol;
	newRow = this->playerRow;
	newMoveDir = this->currentMoveDir;
	newExiting = this->isExitingLevel;
	newPushDelay = this->pushDelay;
	newStep = this->playerStep;
	curDeathTimer = this->deathTimer;
	if (dx <= 0) {
		if (dx >= 0) {
			if (dy >= 0) {
				s0 = newStateFlags & -8;
				s1 = 3;
			} else {
				s0 = newStateFlags & -8;
				s1 = 1;
			}
		} else {
			s0 = newStateFlags & -8;
			s1 = 4;
		}
	} else {
		s0 = newStateFlags & -8;
		s1 = 2;
	}
	newStateFlags = s0 | s1;
	targetCol = newCol + dx;
	targetRow = newRow + dy;
	canMove = 0;
	onHintTile = 0;
	if (targetCol < 0 || targetCol >= this->levelW || targetRow < 0 || targetRow >= this->levelH) {
		canMove = 1;
	} else {
		if (Game::liquidCells != nullptr && Game::liquidCells[targetCol][targetRow] != 0 && Game::saveData[10] == 0) {
			canMove = 0;
			blockedByObject = 1;
		}
		objType = (int8_t)(Game::cellObjects[targetCol][targetRow] & 255);
		switch (objType) {
			case 28:
				if (testOnly == 0) {
					newExiting = 1;
					this->usedMainExit = 0;
				}
				break;
			case 19:
				if (testOnly == 0) {
					targetCellType = targetCol + 3;
					for (pushDestCol = targetRow; Game::cellTypes[targetCellType][pushDestCol] != 39; pushDestCol--) {
					}
					if (!this->hasWaterLayer) {
						this->resetLiquidSimulation();
					}
					this->hasWaterLayer = 1;
					this->liquidStartNextEmitter = 0;
					if (Game::liquidCells == nullptr) {
						Game::liquidCells = multiArray<int32_t, 2>(this->levelW, this->levelH);
					}
					this->addLiquidEmitter((int8_t)Game::cellStates[targetCellType][pushDestCol], (int8_t)targetCellType, (int8_t)pushDestCol, 0);
					this->openLiquidEmitter(targetCellType, pushDestCol);
					targetCellType = targetCol;
					while (true) {
						pushDestCol++;
						if ((Game::cellObjects[targetCellType][pushDestCol] & 255) != 19) {
							break;
						}
						Game::cellObjects[targetCellType][pushDestCol] = -1;
					}
				}
				break;
			case 7:
				objParam = Game::cellObjects[targetCol][targetRow] >> 8;
				if ((objParam & 240) >> 4 < 2) {
					s0 = 1;
					blockedByObject = s0;
				}
				break;
			case 6:
				break;
			case 5:
				canMove = 1;
				if (testOnly == 0) {
					newExiting = 1;
					this->usedMainExit = 1;
				}
				break;
			case 4:
				if (testOnly == 0) {
					objParam = (Game::cellObjects[targetCol][targetRow] & -256) >> 8;
					if (objParam >= this->nextCheckpointIndex) {
						this->checkpointSavePending = 1;
						this->nextCheckpointIndex = objParam + 1;
						this->checkpointTextEndFrame = Game::frameCount + 13;
					}
				}
				break;
			case 3:
				if (Game::cellObjects[targetCol][targetRow] >> 8 >= 3) {
					canMove = 0;
					s0 = 1;
					blockedByObject = s0;
				} else {
					canMove = 1;
				}
				break;
			case 2:
				if (testOnly == 0) {
					onHintTile = 1;
					objParam = Game::cellObjects[targetCol][targetRow] >> 8;
					switch (objParam) {
						case 1:
							if (Game::saveData[9] < 2) {
								s0_o = this;
								t5 = cast<Game>(s0_o);
								s0_o = t5;
								s1 = 13;
							} else {
								s0_o = this;
								s1 = 7;
							}
							cast<Game>(s0_o)->hintBubbleImageSet = s1;
							s0_o = this;
							s1 = 1;
							cast<Game>(s0_o)->hintBubbleFrame = s1;
							break;
						case 0:
							if (Game::saveData[9] < 1) {
								s0_o = this;
								t5 = cast<Game>(s0_o);
								s0_o = t5;
								s1 = 13;
								cast<Game>(s0_o)->hintBubbleImageSet = s1;
								s0_o = this;
								s1 = 1;
							} else {
								this->hintBubbleImageSet = 7;
								s0_o = this;
								s1 = 0;
							}
							cast<Game>(s0_o)->hintBubbleFrame = s1;
							break;
						default:
							break;
					}
				}
				break;
			case 1:
				if (testOnly == 0) {
					this->shakeTime = 120;
					this->floodTriggerStage = this->floodTriggerStage + 1;
					this->clearConnectedObjects(targetCol, targetRow, 1);
				}
				break;
			default:
				break;
		}
		if (blockedByObject == 0) {
			targetCellType = Game::cellTypes[targetCol][targetRow];
			switch (targetCellType) {
				default:
					dx = 0;
					canMove = 0;
					if (this->currentMoveDir == 4 || this->currentMoveDir == 2) {
						this->setExplorerAnim(0 + this->currentMoveDir - 1);
					}
					break;
				case 48:
					pushDestCol = newCol + (dx << 1);
					pushDestRow = newRow + (dy << 1);
					newPushDelay--;
					if ((Game::cellStates[targetCol][targetRow] & 8) == 0) {
						topCellOffset = -1;
						s0 = 0;
					} else {
						topCellOffset = 0;
						s0 = 1;
					}
					bottomCellOffset = s0;
					if ((newPushDelay < 0 || testOnly != 0) && dx != 0 && Game::cellTypes[pushDestCol][pushDestRow + topCellOffset] < 0 && Game::cellTypes[pushDestCol][pushDestRow + bottomCellOffset] < 0 && Game::cellTypes[targetCol][targetRow + bottomCellOffset + 1] >= 0) {
						if (testOnly == 0) {
							Game::cellTypes[pushDestCol][pushDestRow + topCellOffset] = targetCellType;
							Game::cellTypes[pushDestCol][pushDestRow + bottomCellOffset] = targetCellType;
							Game::cellTypes[targetCol][targetRow + topCellOffset] = -1;
							Game::cellTypes[targetCol][targetRow + bottomCellOffset] = -1;
							Game::cellStates[pushDestCol][pushDestRow + topCellOffset] = Game::cellStates[targetCol][targetRow + topCellOffset];
							Game::cellStates[pushDestCol][pushDestRow + bottomCellOffset] = Game::cellStates[targetCol][targetRow + bottomCellOffset] & -16 | (dx <= 0 ? 4 : 2);
							Game::cellMoveOffsets[pushDestCol][pushDestRow + bottomCellOffset] = 18;
							Game::cellUpdateTimers[pushDestCol][pushDestRow + topCellOffset - 1] = 48;
							Game::cellUpdateTimers[pushDestCol][pushDestRow + topCellOffset - 1] = 48;
							Game::cellUpdateTimers[pushDestCol][pushDestRow + topCellOffset - 1] = 48;
							Game::wakeCellsAround(pushDestCol, pushDestRow + bottomCellOffset);
						}
						canMove = 1;
						newStateFlags = newStateFlags | 8;
					} else {
						if (dx != 0) {
							newStateFlags = newStateFlags | 8;
						}
						newMoveDir = 0;
					}
					break;
				case 34:
				case 35:
					canMove = testOnly;
					break;
				case 31:
				case 49:
					canMove = 0;
					break;
				case 28:
					newMoveDir = 0;
					newStateFlags = newStateFlags & -9;
					break;
				case 10:
					if (this->liquidState == 3) {
						if (testOnly == 0 && Game::cellStates[targetCol][targetRow] <= 0) {
							Game::cellStates[targetCol][targetRow] = 1;
						}
						canMove = 1;
					}
					break;
				case 1:
				case 2:
				case 4:
				case 5:
				case 6:
				case 7:
				case 11:
				case 14:
				case 19:
				case 24:
				case 26:
				case 27:
				case 33:
				case 40:
				case 41:
				case 42:
				case 43:
				case 45:
				case 50:
				case 51:
				case 52:
				case 53:
					canMove = 1;
					break;
				case 0:
				case 8:
				case 9:
				case 47:
					pushDestCol = newCol + (dx << 1);
					pushDestRow = newRow + (dy << 1);
					if (this->specialStageType == 4) {
						destObjType = this->getAnacondaHoleCol();
						if (pushDestCol == destObjType || pushDestCol == destObjType + 1) {
							destObjParam = this->getAnacondaHeadRow();
							if (pushDestRow >= destObjParam) {
								newStateFlags = newStateFlags | 8;
								this->setExplorerAnim((newStateFlags & 7) != 2 ? 9 : 8);
								return 0;
							}
						}
					}
					newPushDelay--;
					destObjType = Game::cellObjects[pushDestCol][pushDestRow] & 255;
					destObjParam = Game::cellObjects[pushDestCol][pushDestRow] >> 8;
					cellBelowTarget = Game::cellTypes[targetCol][newRow + 1];
					if ((newPushDelay < 0 || testOnly != 0) && dx != 0 && Game::isCellFreeForObject(pushDestCol, pushDestRow) && (destObjType != 7 || (destObjParam & 240) != 0) && (cellBelowTarget != 19 && cellBelowTarget != 45 && cellBelowTarget != 49 && cellBelowTarget != 43 || (Game::cellObjects[targetCol][newRow + 1] & 255) == 35)) {
						if (testOnly == 0) {
							this->pushObjectSideways(targetCol, targetRow, dx > 0 ? 1 : 0, targetCellType);
						}
						canMove = 1;
						newStateFlags = newStateFlags | 8;
					} else {
						if (dx != 0) {
							newStateFlags = newStateFlags | 8;
						}
						newMoveDir = 0;
						Game::cellStates[targetCol][targetRow] = Game::cellStates[targetCol][targetRow] & -8 | 0;
					}
					break;
				case -1:
					if (targetCol == 0 || targetRow == 0 || targetCol == this->levelW - 1 || targetRow == this->levelH - 1) {
						s0 = 1;
						canMove = s0;
					} else {
						if ((dx == 0 || Game::cellTypes[targetCol][newRow + 1] != 0 || (Game::cellStates[targetCol][newRow + 1] & 7) != 3) && (this->pistonSlowExtent < 24 || (Game::cellTypes[targetCol][targetRow - 1] != 28 || (Game::cellStates[targetCol][targetRow - 1] & 8) != 0) && (Game::cellTypes[targetCol][targetRow + 1] != 28 || (Game::cellStates[targetCol][targetRow + 1] & 8) != 0)) && (this->pistonFastExtent < 24 || Game::cellTypes[targetCol][targetRow - 1] != 28 && Game::cellTypes[targetCol][targetRow + 1] != 28)) {
							s0 = 1;
							canMove = s0;
						} else {
							if (testOnly == 0) {
								newMoveDir = 0;
							} else {
								s0 = 1;
								canMove = s0;
							}
						}
					}
					newStateFlags = newStateFlags & -9;
					break;
			}
		}
	}
	if (testOnly == 0 && canMove != 0 && onHintTile == 0) {
		this->hintBubbleImageSet = -1;
	}
	if (canMove == 0 || curDeathTimer != 0) {
		if (dx != 0 && testOnly == 0) {
			newStateFlags = newStateFlags | 8;
		}
	} else {
		newStep = 18;
		newCol = newCol + dx;
		newRow = newRow + dy;
		if ((newStateFlags & 8) == 0 && testOnly == 0) {
			this->setExplorerAnim(4 + newMoveDir - 1);
		}
	}
	if ((newStateFlags & 8) != 0 && testOnly == 0) {
		this->setExplorerAnim((newStateFlags & 7) != 2 ? 9 : 8);
	}
	if (testOnly == 0) {
		this->explorerStateFlags = newStateFlags;
		this->playerCol = newCol;
		this->playerRow = newRow;
		this->currentMoveDir = newMoveDir;
		this->isExitingLevel = newExiting;
		this->pushDelay = newPushDelay;
		this->playerStep = newStep;
		this->deathTimer = curDeathTimer;
	}
	return canMove;
}

void Game::requestQuit() {
	Game::screen = 3;
}

void Game::openPauseMenu() {
	Game::screen = 2;
	Game::menuFullRedraw = 1;
	this->openMenu(1);
	this->requestHudRedraw();
	if (Game::spritePacks[18] == nullptr) {
		Game::spritePacks[18] = Game::loadSpritePack(u"/ui.f"_j, 3);
	}
}

void Game::pauseGame() {
	this->pausedElapsedTime = JSystem::currentTimeMillis() - this->startTime;
	this->paused = 1;
	JSystem::out->println(Sound::isPlaying());
	if ((Game::screen == 30 || Game::screen == 4) && Sound::isPlaying()) {
		this->resumeMenuMusic = 1;
	}
	this->sound->stop();
}

void Game::showNotify() {
	if (this->paused) {
		this->resumeGame();
	}
}

void Game::hideNotify() {
	if (!this->paused) {
		this->pauseGame();
	}
}

void Game::resumeGame() {
	this->paused = 0;
	Game::menuFullRedraw = 1;
	Game::menuRepaintPlayfield = 1;
	this->isKeyReleased = 1;
	Game::keys = 0;
	this->menuConfirmStep = -1;
	if (this->menuId == 7) {
		this->menuCursor = 0;
	}
	this->startTime = JSystem::currentTimeMillis() - this->pausedElapsedTime;
	switch (Game::screen) {
		case 33:
			cast<Game>(this)->needsFullRedraw = 1;
			return;
		case 31:
			this->newGamePromptDirty = 1;
			return;
		case 27:
			this->needsFullRedraw = 1;
			this->worldMapInfoDirty = 1;
			return;
		case 23:
			return;
		case 21:
			this->openStageMap();
			return;
		case 20:
			return;
		case 19:
			return;
		case 18:
		case 25:
		case 26:
			cast<Game>(this)->needsFullRedraw = 1;
			return;
		case 17:
			return;
		case 16:
			this->lives = 0;
			this->redDiamondCount = 0;
			this->hasCompass = 0;
			this->loadingTipIndex = 0;
			this->isNewGame = 1;
			return;
		case 15:
			cast<Game>(this)->needsFullRedraw = 1;
			return;
		case 11:
			this->loadingStep = 6;
			return;
		case 10:
			Game::menuRepaintPlayfield = 0;
			return;
		case 9:
		case 28:
			return;
		case 8:
			return;
		case 7:
			this->menuCursor = 1;
			return;
		case 5:
			this->loadingFullRedraw = 1;
			return;
		case 4:
		case 30:
			if (!this->resumeMenuMusic) {
				return;
			}
			this->sound->play(19);
			return;
		case 2:
			Game::stageMapImage = nullptr;
			this->hudNeedsRedraw = 1;
			if (this->menuId != 1) {
				return;
			}
			this->menuCursor = 0;
			return;
		default:
			return;
		case 1:
			this->requestHudRedraw();
			if (!Game::itemRaiseFreeze) {
				if (this->activeCutscene == nullptr) {
					if (this->entryWalkRemaining == 0) {
						if (!this->isExitingLevel) {
							if (this->explorerEnergy > 0) {
								if (Game::actors[0]->animIndex != 19) {
									if (!this->respawnPanActive) {
										this->openPauseMenu();
										return;
									}
									return;
								}
								return;
							}
							return;
						}
						return;
					}
					return;
				}
				return;
			}
			return;
		case 0:
		case 6:
		case 12:
		case 22:
			return;
	}
}

void Game::registerLiquidEmitters() {
	int32_t col = 0, row = 0;
	if (this->hasWaterLayer) {
		for (col = 0; col < this->levelW; col++) {
			for (row = 0; row < this->levelH; row++) {
				if (Game::cellTypes[col][row] == 38) {
					this->addLiquidEmitter((int8_t)Game::cellStates[col][row], (int8_t)col, (int8_t)row, 0);
					this->liquidEmitterCount = this->liquidEmitterCount + 1;
				}
			}
		}
		return;
	}
}

void Game::placeChestOnCell(int32_t col, int32_t row) {
	Arr<int32_t> t1, t2;
	this->levelResourceMask = this->levelResourceMask | 4194304LL;
	t1 = Game::cellObjects[col];
	t1[row] = t1[row] & -256;
	t2 = Game::cellObjects[col];
	t2[row] = t2[row] | 14;
}

bool Game::isBossStage() {
	if (this->specialStageType == 4 || this->specialStageType == 5 || this->specialStageType == 3) {
		return 1;
	}
	return 0;
}

void Game::setupLevelCells() {
	Ref<Hashtable> locksPerDoor, gateTaskCounts, gateObjectiveMsgIds;
	int32_t objValue = 0, cellParam = 0, cellType = 0, objType = 0, typeOrParam = 0, key_n = 0, count_n = 0, prevMsgId_n = 0, goalIndex = 0, pickupSlotCount = 0, goalTargetCount = 0, gateIdMask = 0, cutsceneCount = 0, col = 0, row = 0, s0_n = 0, s1_n = 0, s2_n = 0, t13 = 0;
	Ref<Integer> key, count, prevMsgId, gateKey, taskCount, msgId, t7;
	Ref<Object> s0;
	int64_t s1 = 0, s2 = 0;
	Arr<int32_t> t6, t11, t12;
	locksPerDoor = jnew<Hashtable>();
	gateTaskCounts = jnew<Hashtable>();
	gateObjectiveMsgIds = jnew<Hashtable>();
	this->redDiamondPickCount = 0;
	this->checkpointRedDiamondPickCount = 0;
	pickupSlotCount = 0;
	this->diamondsInStage = 0;
	this->enemyPackFlags = 0;
	goalTargetCount = 0;
	gateIdMask = 0;
	this->levelHasLockType9 = 0;
	this->levelHasLockType8 = 0;
	this->levelHasBlock35 = 0;
	this->freezeRayCount = 0;
	cutsceneCount = 0;
	for (col = 0; col < this->levelW; col++) {
		for (row = 0; row < this->levelH; row++) {
			Game::cellMoveOffsets[col][row] = 0;
			Game::cellUpdateTimers[col][row] = 0;
			objValue = Game::cellObjects[col][row];
			cellParam = Game::cellStates[col][row];
			cellType = Game::cellTypes[col][row];
			if (objValue != -1) {
				switch (objValue & 255) {
					default:
						if (objValue < 20 || objValue >= 26) {
							if (objValue < 80 && objValue > -1) {
								Game::cellObjects[col][row] = -1;
							}
						} else {
							Game::cellObjects[col][row] = objValue;
							switch (this->world) {
								case 1:
									s0 = this;
									s1 = this->levelResourceMask;
									s2 = 2097152LL;
									cast<Game>(s0)->levelResourceMask = s1 | s2;
									break;
								case 0:
									s0 = this;
									s1 = this->levelResourceMask;
									s2 = 16LL;
									cast<Game>(s0)->levelResourceMask = s1 | s2;
									break;
								default:
									break;
							}
						}
						break;
					case 34:
						this->levelResourceMask = this->levelResourceMask | 17179869184LL;
						break;
					case 31:
						this->levelResourceMask = this->levelResourceMask | 1073741824LL;
						Game::cellObjects[col][row] = cellParam << 8 | 31;
						Game::cellObjects[col][row] = cellParam << 8 | 19;
						break;
					case 30:
						this->levelResourceMask = this->levelResourceMask | 1073741824LL;
						cutsceneCount++;
						Game::cellObjects[col][row] = cellParam << 8 | objValue & 255;
						break;
					case 28:
						this->altExitWalkDir = (int8_t)cellParam;
						break;
					case 19:
						Game::cellObjects[col][row] = cellParam << 8 | 19;
						break;
					case 17:
						objType = Game::cellObjects[col][row - 1] & 255;
						if (objType == 14 || objType == 33) {
							Game::cellObjects[col][row - 1] = 65280 | objType;
						}
						typeOrParam = Game::cellTypes[col][row - 1];
						switch (typeOrParam) {
							default:
								Game::cellObjects[col][row] = cellParam << 8 | 17;
								break;
							case 19:
							case 36:
							case 43:
							case 45:
							case 46:
							case 49:
								key = jnew<Integer>(cellParam);
								count = cast<Integer>(gateTaskCounts->get(key));
								count = count != nullptr ? jnew<Integer>(count->intValue() + 1) : jnew<Integer>(1);
								gateTaskCounts->put(key, count);
								Game::cellObjects[col][row] = -1;
								prevMsgId = cast<Integer>(gateObjectiveMsgIds->get(key));
								if (typeOrParam != 36) {
									gateObjectiveMsgIds->put(key, jnew<Integer>(57));
									if (this->specialStageType != 4) {
										if (this->specialStageType != 5) {
											if (this->specialStageType == 3) {
												gateObjectiveMsgIds->put(key, jnew<Integer>(95));
											}
										} else {
											gateObjectiveMsgIds->put(key, jnew<Integer>(94));
										}
									} else {
										gateObjectiveMsgIds->put(key, jnew<Integer>(93));
									}
								} else {
									if (prevMsgId == nullptr) {
										gateObjectiveMsgIds->put(key, jnew<Integer>(58));
									}
								}
								break;
						}
						if (cellParam >= 0) {
							gateIdMask = gateIdMask | shl(1, cellParam);
						}
						break;
					case 14:
					case 33:
						if (!this->isBossStage()) {
							Game::cellObjects[col][row] = 33;
						}
						this->levelResourceMask = this->levelResourceMask | lshl(1LL, (Game::cellObjects[col][row] & 255) != 14 ? 33 : 22);
						if (this->isCollectibleTaken(this->world, this->stage, col, row)) {
							if (!this->isBossStage()) {
								Game::cellTypes[col][row] = -1;
								t6 = Game::cellObjects[col];
								t6[row] = t6[row] | 256;
							} else {
								Game::cellTypes[col][row] = 41;
								Game::cellStates[col][row] = 10;
								this->diamondsInStage = this->diamondsInStage + 10;
							}
						}
						break;
					case 8:
						this->levelHasLockType8 = 1;
						if ((objValue & 255) != 8) {
							this->levelHasLockType9 = 1;
						}
						this->levelResourceMask = this->levelResourceMask | 268435456LL;
						key = jnew<Integer>(cellParam);
						t7 = cast<Integer>(locksPerDoor->get(key));
						count = t7;
						count = count != nullptr ? jnew<Integer>(count->intValue() + 1) : jnew<Integer>(1);
						locksPerDoor->put(key, count);
						Game::cellObjects[col][row] = cellParam << 8 | objValue;
						break;
					case 9:
						if ((objValue & 255) != 8) {
							this->levelHasLockType9 = 1;
						}
						this->levelResourceMask = this->levelResourceMask | 268435456LL;
						key = jnew<Integer>(cellParam);
						t7 = cast<Integer>(locksPerDoor->get(key));
						count = t7;
						count = count != nullptr ? jnew<Integer>(count->intValue() + 1) : jnew<Integer>(1);
						locksPerDoor->put(key, count);
						Game::cellObjects[col][row] = cellParam << 8 | objValue;
						break;
					case 7:
						if (cellParam != -1) {
							Game::doorCols[cellParam] = (int8_t)col;
							Game::doorRows[cellParam] = (int8_t)row;
						}
						Game::cellObjects[col][row] = cellParam << 8 | objValue;
						break;
					case 6:
						key = jnew<Integer>(cellParam);
						count = cast<Integer>(locksPerDoor->get(key));
						count = count != nullptr ? jnew<Integer>(count->intValue() + 1) : jnew<Integer>(1);
						locksPerDoor->put(key, count);
						this->levelResourceMask = this->levelResourceMask | 536870912LL;
						Game::cellObjects[col][row] = cellParam << 8 | 6;
						break;
					case 5:
						this->exitWalkDir = (int8_t)cellParam;
						break;
					case 4:
						goalTargetCount++;
						this->levelResourceMask = this->levelResourceMask | 16LL;
						Game::cellObjects[col][row] = cellParam << 8 | objValue & 255;
						break;
					case 3:
						Game::cellUpdateTimers[col][row] = 127;
						if (cellParam > 0) {
							Game::cellObjects[col][row] = cellParam + 1 << 8 | 3;
						}
						break;
					case 2:
						this->levelResourceMask = this->levelResourceMask | 1048576LL;
						switch (cellParam) {
							case 0:
							case 1:
								this->levelResourceMask = this->levelResourceMask | 524288LL;
								break;
							default:
								break;
						}
						Game::cellObjects[col][row] = cellParam << 8 | 2;
						break;
					case 1:
					case 26:
						Game::cellObjects[col][row] = cellParam << 8 | objValue & 255;
						break;
					case 0:
						cutsceneCount++;
						Game::cellObjects[col][row] = cellParam << 8 | objValue & 255;
						break;
				}
			}
			switch (cellType) {
				default:
					if (cellType < 80 && cellType > -1) {
						s0 = Game::cellTypes[col];
						s1_n = row;
						s2_n = -1;
						cast<Array<int8_t>>(s0)[s1_n] = s2_n;
					}
					break;
				case 79:
					this->playerCol = 0;
					this->playerRow = row;
					this->entryWalkRemaining = col;
					Game::cellTypes[col][row] = -1;
					this->camTargetX = 0;
					this->camX = 0;
					t13 = this->playerRow * 24 - 160;
					this->camTargetY = t13;
					this->camY = t13;
					break;
				case 53:
					break;
				case 52:
					break;
				case 51:
					break;
				case 49:
					this->levelResourceMask = this->levelResourceMask | 2199023255552LL;
					s0 = Game::cellUpdateTimers[col];
					s1_n = row;
					s2_n = 48;
					cast<Array<int8_t>>(s0)[s1_n] = s2_n;
					break;
				case 48:
					if ((cellParam & 7) != 4) {
						s0 = Game::cellStates[col];
						s1_n = row;
						s2_n = 0;
					} else {
						s0 = Game::cellStates[col];
						s1_n = row;
						s2_n = 16;
					}
					cast<Array<int32_t>>(s0)[s1_n] = s2_n;
					this->freezeRayCount = this->freezeRayCount + 1;
					this->levelResourceMask = this->levelResourceMask | 1099511627776LL;
					this->levelResourceMask = this->levelResourceMask | 4294967296LL;
					objType = row - 1;
					Game::cellTypes[col][objType] = 48;
					Game::cellStates[col][objType] = 8;
					Game::wakeCellsAround(col, objType);
					break;
				case 47:
					Game::cellUpdateTimers[col][row] = 48;
					Game::cellStates[col][row] = 0;
					this->levelResourceMask = this->levelResourceMask | 8388608LL;
					break;
				case 46:
					Game::cellStates[col][row] = 0;
					Game::cellUpdateTimers[col][row] = 24;
					Game::cellMoveOffsets[col][row] = 0;
					this->levelResourceMask = this->levelResourceMask | 137438953472LL;
					break;
				case 45:
					Game::cellStates[col][row] = 0;
					Game::cellUpdateTimers[col][row] = 24;
					this->levelResourceMask = this->levelResourceMask | 34359738368LL;
					break;
				case 44:
					Game::cellUpdateTimers[col][row] = 24;
					Game::cellStates[col][row] = 0;
					this->levelResourceMask = this->levelResourceMask | 17179869184LL;
					break;
				case 43:
					this->levelResourceMask = this->levelResourceMask | lshl(1LL, this->world != 1 ? 15 : 17);
					this->enemyPackFlags = this->enemyPackFlags | 1;
					Game::cellStates[col][row] = cellParam & -98305 | 65536;
					s0 = Game::cellUpdateTimers[col];
					s1_n = row;
					s2_n = 48;
					cast<Array<int8_t>>(s0)[s1_n] = s2_n;
					break;
				case 42:
					cutsceneCount++;
					pickupSlotCount++;
					this->levelResourceMask = this->levelResourceMask | 2147483648LL;
					this->levelResourceMask = this->levelResourceMask | 1073741824LL;
					this->placeChestOnCell(col, row);
					break;
				case 41:
					if (Game::cellStates[col][row] <= 0) {
						Game::cellStates[col][row] = 1;
					}
					this->diamondsInStage = this->diamondsInStage + Game::cellStates[col][row];
					break;
				case 40:
					this->levelResourceMask = this->levelResourceMask | 1073741824LL;
					cutsceneCount++;
					this->hasWaterLayer = 1;
					this->levelResourceMask = this->levelResourceMask | 134217728LL;
					this->placeChestOnCell(col, row);
					pickupSlotCount++;
					break;
				case 39:
					this->hasWaterLayer = 1;
					this->levelResourceMask = this->levelResourceMask | 67108864LL;
					break;
				case 38:
					this->hasWaterLayer = 1;
					this->levelResourceMask = this->levelResourceMask | 67108864LL;
					Game::cellObjects[col][row] = 27;
					this->levelResourceMask = this->levelResourceMask | 64LL;
					break;
				case 37:
					this->levelResourceMask = this->levelResourceMask | 33554432LL;
					Game::cellStates[col][row] = 0;
					break;
				case 36:
					if (Game::cellStates[col][row] != 1) {
						Game::cellStates[col][row] = 0;
					}
					this->levelResourceMask = this->levelResourceMask | 256LL;
					break;
				case 35:
					Game::cellTypes[col][row] = 35;
					Game::cellObjects[col][row] = -1;
					this->levelResourceMask = this->levelResourceMask | 16777216LL;
					this->levelHasBlock35 = 1;
					break;
				case 34:
					Game::cellTypes[col][row] = -1;
					Game::cellObjects[col][row] = 15;
					this->levelResourceMask = this->levelResourceMask | 16777216LL;
					break;
				case 31:
				case 33:
					break;
				case 30:
					this->levelResourceMask = this->levelResourceMask | 128LL;
					Game::cellStates[col][row] = 0;
					break;
				case 28:
					this->levelResourceMask = this->levelResourceMask | 2048LL;
					if (cellParam > 10) {
						t11 = Game::cellStates[col];
						t11[row] = t11[row] / 11;
						t12 = Game::cellStates[col];
						t12[row] = t12[row] | 8;
					}
					s0 = Game::cellUpdateTimers[col];
					s1_n = row;
					s2_n = 24;
					cast<Array<int8_t>>(s0)[s1_n] = s2_n;
					break;
				case 26:
					this->levelResourceMask = this->levelResourceMask | 1099511627776LL;
					cutsceneCount++;
					pickupSlotCount++;
					this->levelResourceMask = this->levelResourceMask | 1073741824LL;
					this->levelResourceMask = this->levelResourceMask | 524288LL;
					this->placeChestOnCell(col, row);
					break;
				case 24:
				case 27:
					cutsceneCount++;
					pickupSlotCount++;
					this->levelResourceMask = this->levelResourceMask | 1073741824LL;
					this->levelResourceMask = this->levelResourceMask | 524288LL;
					this->placeChestOnCell(col, row);
					break;
				case 22:
				case 23:
					this->levelResourceMask = this->levelResourceMask | 512LL;
					this->levelResourceMask = this->levelResourceMask | 1024LL;
					s0 = Game::cellUpdateTimers[col];
					s1_n = row;
					s2_n = 48;
					cast<Array<int8_t>>(s0)[s1_n] = s2_n;
					break;
				case 19:
					this->levelResourceMask = this->levelResourceMask | lshl(1LL, this->world != 1 ? 15 : 17);
					this->enemyPackFlags = this->enemyPackFlags | 2;
					s0 = Game::cellUpdateTimers[col];
					s1_n = row;
					s2_n = 48;
					cast<Array<int8_t>>(s0)[s1_n] = s2_n;
					break;
				case 18:
					this->switchWallsPhase = 0;
					this->leverMoveDir = 0;
					this->levelResourceMask = this->levelResourceMask | 549755813888LL;
					this->levelResourceMask = this->levelResourceMask | 128LL;
					break;
				case 16:
					if (Game::cellTypes[col][row + 1] != 16) {
						Game::cellTypes[col][row - 1] = 16;
						Game::cellStates[col][row - 1] = cellParam;
					}
					this->levelResourceMask = this->levelResourceMask | 8192LL;
					break;
				case 14:
					this->levelResourceMask = this->levelResourceMask | 4096LL;
					Game::cellStates[col][row] = Game::cellStates[col][row] != 4 ? 0 : 8;
					s0 = Game::cellUpdateTimers[col];
					s1_n = row;
					s2_n = 24;
					cast<Array<int8_t>>(s0)[s1_n] = s2_n;
					break;
				case 12:
					this->exitDoorCol = col;
					this->exitDoorRow = row;
					this->diamondsToOpenExit = cellParam;
					break;
				case 11:
					Game::cellStates[col][row] = cellParam != 1 ? 0 : 16;
					Game::cellUpdateTimers[col][row] = 48;
					this->levelResourceMask = this->levelResourceMask | 16384LL;
					break;
				case 10:
					Game::cellStates[col][row] = 0;
					this->levelExtraResourceMask = this->levelExtraResourceMask | 2LL;
					break;
				case 8:
					this->levelResourceMask = this->levelResourceMask | 32LL;
					this->levelResourceMask = this->levelResourceMask | 8LL;
					if (cellType != 8) {
						this->placeChestOnCell(col, row);
					}
					this->levelResourceMask = this->levelResourceMask | 4LL;
					pickupSlotCount++;
					Game::cellUpdateTimers[col][row] = 48;
					Game::cellStates[col][row] = 0;
					this->levelExtraResourceMask = this->levelExtraResourceMask | 1LL;
					break;
				case 6:
					pickupSlotCount++;
					this->placeChestOnCell(col, row);
					this->levelResourceMask = this->levelResourceMask | 16LL;
					Game::cellStates[col][row] = 0;
					break;
				case 7:
					this->levelResourceMask = this->levelResourceMask | 16LL;
					Game::cellStates[col][row] = 0;
					break;
				case 4:
					if (cellType != 8) {
						this->placeChestOnCell(col, row);
					}
					this->levelResourceMask = this->levelResourceMask | 4LL;
					pickupSlotCount++;
					Game::cellUpdateTimers[col][row] = 48;
					Game::cellStates[col][row] = 0;
					this->levelExtraResourceMask = this->levelExtraResourceMask | 1LL;
					break;
				case 5:
					this->levelResourceMask = this->levelResourceMask | 4LL;
					pickupSlotCount++;
					Game::cellUpdateTimers[col][row] = 48;
					Game::cellStates[col][row] = 0;
					this->levelExtraResourceMask = this->levelExtraResourceMask | 1LL;
					break;
				case 2:
					pickupSlotCount++;
					Game::cellUpdateTimers[col][row] = 48;
					Game::cellStates[col][row] = 0;
					this->levelExtraResourceMask = this->levelExtraResourceMask | 1LL;
					break;
				case 1:
					this->diamondsInStage = this->diamondsInStage + 1;
					Game::cellUpdateTimers[col][row] = 48;
					Game::cellStates[col][row] = 0;
					break;
				case 0:
					Game::cellUpdateTimers[col][row] = 48;
					Game::cellStates[col][row] = 0;
					this->levelExtraResourceMask = this->levelExtraResourceMask | 1LL;
					break;
			}
		}
	}
	Game::redDiamondPickCells = newArray<int8_t>(pickupSlotCount << 1);
	for (col = 0; col < Game::redDiamondPickCells->length; col++) {
		Game::redDiamondPickCells[col] = 0;
	}
	Game::levelCutscenes = newArray<Ref<Cutscene>>(cutsceneCount);
	Game::cutsceneTriggerIds = newArray<int8_t>(cutsceneCount);
	col = 0;
	Game::compassTargets = newArray<int8_t>((goalTargetCount + 1) * 2);
	for (row = 31; row >= 0 && (gateIdMask & shl(1, row)) == 0; row--) {
	}
	row++;
	if (row > 0) {
		Game::gateRemainingCounts = newArray<int8_t>(row);
		Game::gateObjectiveMsgs = newArray<int8_t>(row);
	}
	if (this->freezeRayCount > 0) {
		Game::freezeRays = newArray<int8_t>(this->freezeRayCount * 3);
	}
	objValue = 0;
	for (cellParam = 0; cellParam < this->levelH; cellParam++) {
		for (cellType = 0; cellType < this->levelW; cellType++) {
			objType = Game::cellObjects[cellType][cellParam] & 255;
			typeOrParam = Game::cellObjects[cellType][cellParam] >> 8;
			switch (objType) {
				case 17:
					if (typeOrParam != -1) {
						gateKey = jnew<Integer>(typeOrParam);
						taskCount = cast<Integer>(gateTaskCounts->get(gateKey));
						if (taskCount == nullptr) {
							taskCount = jnew<Integer>(0);
						}
						Game::gateRemainingCounts[typeOrParam] = taskCount->byteValue();
						msgId = cast<Integer>(gateObjectiveMsgIds->get(gateKey));
						if (msgId == nullptr) {
							msgId = jnew<Integer>(59);
						}
						s0 = Game::gateObjectiveMsgs;
						s1_n = typeOrParam;
						s2_n = msgId->byteValue();
						cast<Array<int8_t>>(s0)[s1_n] = s2_n;
					}
					break;
				case 7:
					key = cast<Integer>(locksPerDoor->get(jnew<Integer>(typeOrParam)));
					typeOrParam = typeOrParam << 8;
					if (key != nullptr) {
						typeOrParam = typeOrParam & -16 | key->intValue();
					}
					if ((Game::cellObjects[cellType][cellParam - 1] & 255) != 17) {
						s0_n = 0;
					} else {
						s0_n = 1;
					}
					count_n = s0_n;
					if ((Game::cellObjects[cellType][cellParam + 1] & 255) != 17 || (Game::cellObjects[cellType + 1][cellParam] & 255) == 26 || (Game::cellObjects[cellType - 1][cellParam] & 255) == 26) {
						s0_n = 0;
					} else {
						s0_n = 1;
					}
					prevMsgId_n = s0_n;
					if (count_n != 0 || prevMsgId_n != 0) {
						typeOrParam = typeOrParam & -241 | 48;
						Game::cellUpdateTimers[cellType][cellParam] = 24;
						if (count_n != 0) {
							Game::cellObjects[cellType][cellParam - 1] = -1;
						}
					}
					Game::cellObjects[cellType][cellParam] = typeOrParam << 8 | objType;
					break;
				case 5:
					Game::compassTargets[goalTargetCount * 2] = (int8_t)cellType;
					s0 = Game::compassTargets;
					s1_n = goalTargetCount * 2 + 1;
					s2_n = (int8_t)cellParam;
					cast<Array<int8_t>>(s0)[s1_n] = s2_n;
					break;
				case 4:
					goalIndex = typeOrParam;
					Game::compassTargets[goalIndex * 2] = (int8_t)cellType;
					s0 = Game::compassTargets;
					s1_n = goalIndex * 2 + 1;
					s2_n = (int8_t)cellParam;
					cast<Array<int8_t>>(s0)[s1_n] = s2_n;
					break;
				case 0:
				case 30:
					s0 = Game::cutsceneTriggerIds;
					s1_n = col++;
					s2_n = (int8_t)typeOrParam;
					cast<Array<int8_t>>(s0)[s1_n] = s2_n;
					break;
				default:
					break;
			}
			switch (Game::cellTypes[cellType][cellParam]) {
				case 48:
					if ((Game::cellStates[cellType][cellParam] & 8) != 0) {
						key_n = cellType + ((Game::cellStates[cellType][cellParam + 1] & 16) != 0 ? -1 : 1);
						count_n = objValue * 3;
						if (Game::getFrozenKind(key_n, cellParam) < 0) {
							s0 = Game::freezeRays;
							s1_n = count_n + 2;
							s2_n = -1;
						} else {
							Game::freezeRays[count_n + 0] = (int8_t)key_n;
							Game::freezeRays[count_n + 1] = (int8_t)key_n;
							s0 = Game::freezeRays;
							s1_n = count_n + 2;
							s2_n = (int8_t)cellParam;
						}
						cast<Array<int8_t>>(s0)[s1_n] = s2_n;
						Game::cellStates[cellType][cellParam] = Game::cellStates[cellType][cellParam] & 16777215 | objValue << 24;
						objValue++;
					}
					break;
				case 42:
					s0 = Game::cutsceneTriggerIds;
					s1_n = col++;
					s2_n = 11;
					cast<Array<int8_t>>(s0)[s1_n] = s2_n;
					break;
				case 40:
					s0 = Game::cutsceneTriggerIds;
					s1_n = col++;
					s2_n = 24;
					cast<Array<int8_t>>(s0)[s1_n] = s2_n;
					break;
				case 27:
					s0 = Game::cutsceneTriggerIds;
					s1_n = col++;
					s2_n = 23;
					cast<Array<int8_t>>(s0)[s1_n] = s2_n;
					break;
				case 26:
					s0 = Game::cutsceneTriggerIds;
					s1_n = col++;
					s2_n = 25;
					cast<Array<int8_t>>(s0)[s1_n] = s2_n;
					break;
				case 24:
					s0 = Game::cutsceneTriggerIds;
					s1_n = col++;
					s2_n = 22;
					cast<Array<int8_t>>(s0)[s1_n] = s2_n;
					break;
				default:
					break;
			}
		}
	}
	Game::cellObjects[this->entryWalkRemaining - 2][this->playerRow] = -193 << 8 | 7;
	if ((this->levelResourceMask & 4294967296LL) != 0LL || Game::saveData[9] >= 8) {
		this->levelResourceMask = this->levelResourceMask | 1099511627776LL;
		this->levelResourceMask = this->levelResourceMask | 2LL;
		this->levelResourceMask = this->levelResourceMask | 1LL;
		if ((this->levelResourceMask & 131072LL) != 0LL) {
			this->levelResourceMask = this->levelResourceMask | 262144LL;
		}
		if ((this->levelResourceMask & 32768LL) != 0LL) {
			this->levelResourceMask = this->levelResourceMask | 65536LL;
		}
		if ((this->levelResourceMask & 34359738368LL) != 0LL) {
			this->levelResourceMask = this->levelResourceMask | 68719476736LL;
		}
		if ((this->levelResourceMask & 137438953472LL) != 0LL) {
			this->levelResourceMask = this->levelResourceMask | 274877906944LL;
		}
		if ((this->levelResourceMask & 2199023255552LL) != 0LL) {
			this->levelResourceMask = this->levelResourceMask | 4398046511104LL;
		}
	}
}

void Game::propagateLockFlag(int32_t col, int32_t row, int32_t dx, int32_t dy, int32_t setFlag) {
	int32_t stepDx = 0, stepDy = 0, objParam = 0, objType = 0;
	if (col + dx <= 0 || col + dx >= this->levelW || row + dy <= 0 || row + dy >= this->levelH) {
		return;
	}
	stepDx = dx;
	stepDy = dy;
	objType = Game::cellObjects[col + dx][row + dy] & 255;
	switch (objType) {
		case 8:
		case 9:
			objParam = Game::cellObjects[col + dx][row + dy] >> 8;
			objParam = setFlag != 1 ? objParam & -513 : objParam | 512;
			Game::cellObjects[col + dx][row + dy] = objParam << 8 | objType;
			this->propagateLockFlag(col + dx, row + dy, stepDx, stepDy, setFlag);
			this->propagateLockFlag(col + dx, row + dy, 0, 1, setFlag);
			break;
		default:
			break;
	}
}

bool Game::isPlayerAt(int32_t col, int32_t row) {
	if (col != this->playerCol || row != this->playerRow) {
		return 0;
	}
	return 1;
}

void Game::startCutscene(int32_t triggerId) {
	int32_t index = 0;
	this->currentMoveDir = 0;
	this->requestedMoveDir = 0;
	for (index = 0; index < Game::cutsceneTriggerIds->length; index++) {
		if (Game::cutsceneTriggerIds[index] == triggerId) {
			this->activeCutscene = Game::levelCutscenes[index];
		}
	}
	this->activeCutscene->start();
}

bool Game::stepCameraPan() {
	int32_t xReached = 0, yReached = 0;
	if (this->camX >= this->camPanTargetX) {
		if (this->camX > this->camPanTargetX) {
			this->camX = this->camX - this->camPanSpeed;
			if (this->camX < this->camPanTargetX) {
				this->camX = this->camPanTargetX;
			}
		}
	} else {
		this->camX = this->camX + this->camPanSpeed;
		if (this->camX > this->camPanTargetX) {
			this->camX = this->camPanTargetX;
		}
	}
	if (this->camY >= this->camPanTargetY) {
		if (this->camY > this->camPanTargetY) {
			this->camY = this->camY - this->camPanSpeed;
			if (this->camY < this->camPanTargetY) {
				this->camY = this->camPanTargetY;
			}
		}
	} else {
		this->camY = this->camY + this->camPanSpeed;
		if (this->camY > this->camPanTargetY) {
			this->camY = this->camPanTargetY;
		}
	}
	xReached = 0;
	yReached = 0;
	if (this->camX >= 0) {
		if (this->camX <= this->levelW * 24 - 240) {
			if (this->camX == this->camPanTargetX) {
				xReached = 1;
			}
		} else {
			this->camX = this->levelW * 24 - 240;
			xReached = 1;
		}
	} else {
		this->camX = 0;
		xReached = 1;
	}
	{
		if (this->camY < 0) {
			this->camY = 0;
			yReached = 1;
			goto B12_end;
		}
		{
			if (this->camY <= this->levelH * 24 - 320 + 80) {
				if (this->camY == this->camPanTargetY) {
					yReached = 1;
				}
			} else {
				this->camY = this->levelH * 24 - 320 + 80;
				yReached = 1;
				goto B13_end;
			}
		}
		B13_end:;
	}
	B12_end:;
	if (xReached == 0 || yReached == 0) {
		return 0;
	}
	this->camTargetX = this->camX;
	this->camTargetY = this->camY;
	this->playerIdleCountdown = 70;
	return 1;
}

void Game::updateGateRevealPan() {
	int32_t doorParam = 0;
	switch (this->gateRevealState) {
		case 4:
			this->doorPanTimer = this->doorPanTimer - 1;
			if (this->doorPanTimer == 0) {
				this->playerIdleCountdown = 0;
				this->gateRevealState = 0;
				Game::cameraHoldAfterPan = 1;
			}
			break;
		case 3:
			if (this->stepCameraPan()) {
				this->doorPanTimer = 20;
				this->gateRevealState = 4;
				this->playerIdleCountdown = 0;
				return;
			}
			break;
		case 2:
			this->doorPanTimer = this->doorPanTimer - 1;
			if (this->doorPanTimer != 30) {
				if (this->doorPanTimer == 0) {
					this->gateRevealState = 3;
					this->camPanTargetX = this->playerCol * 24 - 108;
					this->camPanTargetY = this->playerRow * 24 - 108;
					this->camPanSpeed = 5;
					this->hintText = Game::langStrings[Game::gateObjectiveMsgs[Game::activeGateId]];
					Game::spritePacks[41]->measureTextHeight(this->hintText);
					this->hintTimer = 80;
					return;
				}
			} else {
				doorParam = Game::cellObjects[this->panDoorCol][this->panDoorRow] >> 8;
				if ((doorParam & 240) != 0) {
					this->closeDoorAt(this->panDoorCol, this->panDoorRow);
					return;
				}
			}
			break;
		case 1:
			this->camPanSpeed = 8;
			if (this->stepCameraPan()) {
				this->gateRevealState = 2;
				this->doorPanTimer = 40;
				return;
			}
			break;
		default:
			break;
	}
}

void Game::setGatePanTarget(int32_t gateId) {
	int32_t maxCol = 0, maxRow = 0, row = 0, col = 0, targetCol = 0, targetRow = 0, objAbove = 0, doorParam = 0, s0 = 0;
	this->playSound(1);
	maxCol = this->levelW - 1;
	maxRow = this->levelH - 1;
	for (row = 1; row < maxRow; row++) {
		for (col = 1; col < maxCol; col++) {
			if ((Game::cellObjects[col][row] & 255) == 17 && Game::cellObjects[col][row] >> 8 == gateId) {
				targetCol = -1;
				targetRow = -1;
				if (Game::cellTypes[col][row] != 18) {
					objAbove = Game::cellObjects[col][row - 1] & 255;
					switch (objAbove) {
						case 7:
							doorParam = Game::cellObjects[col][row - 1] >> 8;
							if ((doorParam & 240) != 0) {
								targetCol = col;
								s0 = row - 1;
								targetRow = s0;
							}
							break;
						case 14:
						case 33:
							targetCol = col;
							s0 = row - 1;
							targetRow = s0;
							break;
						default:
							break;
					}
				} else {
					targetCol = col;
					s0 = row;
					targetRow = s0;
				}
				if (targetCol != -1) {
					this->panDoorCol = targetCol;
					this->panDoorRow = targetRow;
					this->camPanTargetX = 24 * targetCol - 108;
					this->camPanTargetY = 24 * targetRow - 108;
				}
			}
		}
	}
}

void Game::openGateById(int32_t gateId) {
	int32_t maxCol = 0, maxRow = 0, row = 0, col = 0, objAbove = 0;
	this->playSound(8);
	maxCol = this->levelW - 1;
	maxRow = this->levelH - 1;
	for (row = 1; row < maxRow; row++) {
		for (col = 1; col < maxCol; col++) {
			if ((Game::cellObjects[col][row] & 255) == 17 && Game::cellObjects[col][row] >> 8 == gateId) {
				objAbove = Game::cellObjects[col][row - 1] & 255;
				switch (objAbove) {
					case 14:
					case 33:
						Game::cellObjects[col][row - 1] = 0 | objAbove;
						break;
					case 7:
						Game::openDoorAt(col, row - 1);
						break;
					default:
						break;
				}
			}
		}
	}
}

void Game::updateCellsNearPlayer() {
	int32_t cellType = 0, minCol = 0, maxCol = 0, maxRow = 0, minRow = 0, trapLength = 0, isSlidingObj = 0, effectFrame = 0, s0 = 0, s1 = 0, t3 = 0;
	Ref<Object> s0_o;
	Arr<int8_t> t2;
	minCol = this->playerCol - 8;
	maxCol = this->playerCol + 8;
	maxRow = this->playerRow + 8;
	minRow = this->playerRow - 8;
	trapLength = 0;
	if (Game::actors[4] != nullptr) {
		isSlidingObj = Game::actors[4]->frameIndex;
		if (isSlidingObj != 0) {
			if (isSlidingObj > 10) {
				s0 = isSlidingObj > 20 ? 3 : 2;
			} else {
				s0 = 1;
			}
		} else {
			s0 = 0;
		}
		trapLength = s0;
	}
	if (minCol < 1) {
		minCol = 1;
	}
	if (maxCol > this->levelW - 2) {
		maxCol = this->levelW - 2;
	}
	if (minRow < 1) {
		minRow = 1;
	}
	if (maxRow > this->levelH - 2) {
		maxRow = this->levelH - 2;
	}
	s0_o = this;
	s1 = maxRow;
	while (true) {
		cast<Game>(s0_o)->updateCellRow = s1;
		if (this->updateCellRow < minRow) {
			break;
		}
		s0_o = this;
		s1 = minCol;
		while (true) {
			cast<Game>(s0_o)->updateCellCol = s1;
			if (this->updateCellCol > maxCol) {
				break;
			}
			s0 = this->slideCellsLeft == 0 || this->updateCellCol != this->slidingObjCol || this->updateCellRow != this->slidingObjRow ? 0 : 1;
			isSlidingObj = s0;
			if (Game::cellUpdateTimers[this->updateCellCol][this->updateCellRow] > 0 && isSlidingObj == 0) {
				t2 = Game::cellUpdateTimers[this->updateCellCol];
				t3 = this->updateCellRow;
				t2[t3] = (int8_t)(t2[t3] - 6);
				cellType = (int8_t)(Game::cellObjects[this->updateCellCol][this->updateCellRow] & 255);
				switch (cellType) {
					case 36:
						this->tickExpiringLayerObject();
						break;
					case 35:
					case 37:
						if (this->updateCellCol != this->slidingObjCol || this->updateCellRow != this->slidingObjRow || this->slideCellsLeft == 0) {
							this->updateLiftColumnCell();
						}
						break;
					case 33:
						this->updateChest(33);
						break;
					case 32:
						this->animateWallDebris();
						break;
					case 30:
						if (this->activeCutscene == nullptr && this->pendingCutsceneId == -1 && this->isPlayerAt(this->updateCellCol, this->updateCellRow) && this->playerStep <= 0) {
							this->pendingCutsceneId = Game::cellObjects[this->updateCellCol][this->updateCellRow] >> 8;
							Game::cellObjects[this->updateCellCol][this->updateCellRow] = -1;
						}
						break;
					case 26:
						this->triggerGateChallenge();
						break;
					case 14:
						this->updateChest(14);
						break;
					case 9:
						s0_o = this;
						cast<Game>(s0_o)->tryStartDoorUnlock();
						break;
					case 8:
						s0_o = this;
						cast<Game>(s0_o)->tryStartDoorUnlock();
						break;
					case 7:
						this->updateDoorOpening();
						break;
					case 6:
						this->updatePressurePlate();
						break;
					case 3:
						this->updateProximityAnimTile();
						break;
					case 2:
						switch (Game::cellObjects[this->updateCellCol][this->updateCellRow] >> 8) {
							case 0:
								if (Game::cellTypes[this->updateCellCol - 1][this->updateCellRow] != 30 && Game::cellTypes[this->updateCellCol + 1][this->updateCellRow] != 30 && Game::cellTypes[this->updateCellCol][this->updateCellRow - 1] != 30 && Game::cellTypes[this->updateCellCol][this->updateCellRow + 1] != 30) {
									this->hintBubbleImageSet = -1;
									this->clearConnectedObjects(this->updateCellCol, this->updateCellRow, 2);
								}
								break;
							default:
								break;
						}
						break;
					case 0:
						if (this->activeCutscene == nullptr && this->pendingCutsceneId == -1 && this->isPlayerAt(this->updateCellCol, this->updateCellRow) && this->playerStep <= 6) {
							this->pendingCutsceneId = Game::cellObjects[this->updateCellCol][this->updateCellRow] >> 8;
							Game::cellObjects[this->updateCellCol][this->updateCellRow] = -1;
						}
						break;
					default:
						break;
				}
				effectFrame = (Game::cellObjects[this->updateCellCol][this->updateCellRow] & -268435456) >> 28;
				if (effectFrame > 0) {
					this->animateEnemyDeathPuff();
				}
				cellType = Game::cellTypes[this->updateCellCol][this->updateCellRow];
				switch (cellType) {
					case 54:
						this->updateExplosion();
						break;
					case 53:
						this->startItemPickup(53);
						break;
					case 52:
						this->startItemPickup(52);
						break;
					case 51:
						this->startItemPickup(51);
						break;
					case 50:
						if (this->playerStep < 12 && this->isPlayerAt(this->updateCellCol, this->updateCellRow) && !this->anacondaHitPlayer) {
							this->damageExplorer(1, 48, Game::oppositeDir[this->explorerStateFlags & 7]);
						}
						break;
					case 49:
						this->updateWalkingEnemy(49);
						break;
					case 48:
						if ((Game::cellStates[this->updateCellCol][this->updateCellRow] & 8) != 0) {
							this->updateFreezeRay();
						} else {
							this->updateTallObjectFall(48);
						}
						break;
					case 47:
						this->updateFallingObject();
						this->emitLiftColumn();
						break;
					case 46:
						this->updateShooterEnemy();
						break;
					case 45:
						this->updateHopperEnemy();
						break;
					case 44:
						this->updateStalactite();
						break;
					case 43:
						this->updateWalkingEnemy(43);
						break;
					case 42:
						this->startItemPickup(42);
						break;
					case 41:
						this->startItemPickup(41);
						break;
					case 40:
						this->startItemPickup(40);
						break;
					case 37:
						this->updateCrackingWall();
						break;
					case 36:
						this->updateTorch();
						break;
					case 32:
						this->updateExtendingRod();
						break;
					case 30:
						this->updateCrumblingWall();
						break;
					case 28:
						this->updateExtendingTrap();
						break;
					case 27:
						this->takeRelicFromChest(27);
						break;
					case 26:
						this->takeRelicFromChest(26);
						break;
					case 24:
						this->takeRelicFromChest(24);
						break;
					case 23:
						s0_o = this;
						s1 = 23;
						cast<Game>(s0_o)->updateFlameJetTrap(s1, trapLength);
						break;
					case 22:
						s0_o = this;
						s1 = 22;
						cast<Game>(s0_o)->updateFlameJetTrap(s1, trapLength);
						break;
					case 21:
						this->updateProjectile();
						break;
					case 19:
						this->updateWalkingEnemy(19);
						break;
					case 16:
						this->updateTallStrikerEnemy();
						break;
					case 14:
						this->updateSideRoller();
						break;
					case 11:
						this->updateCrawlingFlame();
						break;
					case 10:
						this->updateFragileWall();
						break;
					case 9:
						if ((Game::cellStates[this->updateCellCol][this->updateCellRow] & 264241152) == 138412032) {
							Game::cellUpdateTimers[this->updateCellCol][this->updateCellRow] = 24;
							if (this->frozenShakeX <= 0) {
								if (this->frozenShakeX < 0) {
									s0_o = this;
									s1 = this->frozenShakeX + 1;
									cast<Game>(s0_o)->frozenShakeX = s1;
								}
							} else {
								s0_o = this;
								s1 = this->frozenShakeX - 1;
								cast<Game>(s0_o)->frozenShakeX = s1;
							}
							if (this->frozenShakeY <= 0) {
								if (this->frozenShakeY < 0) {
									s0_o = this;
									s1 = this->frozenShakeY + 1;
									cast<Game>(s0_o)->frozenShakeY = s1;
								}
							} else {
								s0_o = this;
								s1 = this->frozenShakeY - 1;
								cast<Game>(s0_o)->frozenShakeY = s1;
							}
						}
						this->updateFallingObject();
						break;
					case 8:
						this->updateFallingObject();
						break;
					case 7:
						this->startItemPickup(7);
						break;
					case 6:
						this->startItemPickup(6);
						break;
					case 5:
						this->startItemPickup(5);
						break;
					case 4:
						this->startItemPickup(4);
						break;
					case 2:
						this->startItemPickup(2);
						break;
					case 1:
						this->updateFallingObject();
						break;
					case 0:
						this->updateFallingObject();
						break;
					default:
						break;
				}
			}
			s0_o = this;
			s1 = this->updateCellCol + 1;
		}
		s0_o = this;
		s1 = this->updateCellRow - 1;
	}
}

void Game::updateFreezeRay() {
	int32_t col = 0, row = 0, baseRow = 0, baseState = 0, rayCol = 0, rayIndex = 0, s0 = 0, s1 = 0, s2 = 0, t3 = 0;
	Ref<Object> s0_o;
	col = this->updateCellCol;
	row = this->updateCellRow;
	baseRow = row + 1;
	baseState = Game::cellStates[col][baseRow];
	switch (baseState & 7) {
		default:
			if ((baseState & 16) != 0) {
				s0 = col;
				t3 = s0 - 1;
				s0 = t3;
			} else {
				s0 = col + 1;
			}
			break;
		case 4:
			s0 = col + 1;
			break;
		case 2:
			s0 = col;
			t3 = s0 - 1;
			s0 = t3;
			break;
	}
	rayCol = s0;
	rayIndex = (Game::cellStates[col][row] >> 24) * 3;
	if (Game::cellTypes[rayCol][row] >= 0) {
		s0_o = Game::freezeRays;
		s1 = rayIndex + 2;
		s2 = -1;
	} else {
		Game::freezeRays[rayIndex + 2] = (int8_t)row;
		Game::freezeRays[rayIndex + 1] = (int8_t)rayCol;
		s0_o = Game::freezeRays;
		s1 = rayIndex + 0;
		s2 = (int8_t)rayCol;
	}
	cast<Array<int8_t>>(s0_o)[s1] = s2;
}

void Game::updateTallObjectFall(int8_t cellType) {
	int32_t col = 0, row = 0, state = 0, dir = 0, belowRow = 0, wakeRow = 0, s0 = 0;
	Arr<int8_t> t3;
	col = this->updateCellCol;
	row = this->updateCellRow;
	if (Game::cellMoveOffsets[col][row] == 6 && (Game::cellObjects[col][row] & 255) == 6) {
		this->unlockDoorLock(Game::cellObjects[col][row] >> 8);
	}
	if (Game::cellMoveOffsets[col][row] > 0) {
		t3 = Game::cellMoveOffsets[col];
		t3[row] = (int8_t)(t3[row] - 6);
	} else {
		state = Game::cellStates[col][row];
		dir = state & 7;
		if (dir != 2) {
			if (dir == 4) {
				s0 = state & -17;
				state = s0;
			}
		} else {
			s0 = state | 16;
			state = s0;
		}
		belowRow = row + 1;
		if (Game::cellTypes[col][belowRow] >= 0 || this->isPlayerAt(col, belowRow) && this->deathTimer == 0) {
			if ((state & 7) == 3 && this->isPlayerAt(col, row + 1)) {
				this->damageExplorer(2, 48, 0);
			}
			Game::cellStates[col][row] = state & -8 | 0;
		} else {
			Game::cellTypes[col][row - 1] = -1;
			Game::cellTypes[col][belowRow] = cellType;
			Game::cellStates[col][belowRow] = state & -8 | 3;
			Game::cellStates[col][row] = Game::cellStates[col][row - 1] | 8;
			Game::cellMoveOffsets[col][belowRow] = 18;
			wakeRow = row - 2;
			Game::cellUpdateTimers[col - 1][wakeRow] = 48;
			Game::cellUpdateTimers[col][wakeRow] = 48;
			Game::cellUpdateTimers[col + 1][wakeRow] = 48;
			Game::wakeCellsAround(col, row);
			if (cellType == 48) {
				this->updateFreezeRay();
			}
		}
	}
	Game::cellUpdateTimers[col][row] = 24;
	Game::cellUpdateTimers[col][row - 1] = 24;
}

void Game::updateLiftColumnCell() {
	int32_t col = 0, row = 0, aboveRow = 0, belowRow = 0, aboveObj = 0, cellType = 0, s1 = 0, s2 = 0;
	Ref<Object> s0;
	Arr<int8_t> t2;
	col = this->updateCellCol;
	row = this->updateCellRow;
	Game::cellUpdateTimers[col][row] = 24;
	if (Game::cellMoveOffsets[col][row] > 0) {
		t2 = Game::cellMoveOffsets[col];
		s0 = t2;
		s1 = row;
		s2 = (int8_t)(t2[row] - 6);
		cast<Array<int8_t>>(s0)[s1] = s2;
	} else {
		aboveRow = row - 1;
		belowRow = row + 1;
		aboveObj = (int8_t)(Game::cellObjects[col][aboveRow] & 255);
		if (aboveObj == 34 || aboveObj == 37) {
			s0 = Game::cellObjects[col];
			s1 = aboveRow;
			s2 = 37;
			cast<Array<int32_t>>(s0)[s1] = s2;
		} else {
			if (aboveObj != 35 && Game::canLiftColumnEnter(col, aboveRow)) {
				Game::cellMoveOffsets[col][aboveRow] = 18;
				s0 = Game::cellObjects[col];
				s1 = aboveRow;
				s2 = 35;
				cast<Array<int32_t>>(s0)[s1] = s2;
			}
		}
		cellType = Game::cellTypes[col][row];
		if (Game::cellTypes[col][aboveRow] >= 0 || this->isPlayerAt(col, aboveRow) || aboveObj != 35 || cellType == 32 || cellType == 21 || Game::cellTypes[col][row] == -1) {
			this->redrawCellInBuffer(col, row);
		} else {
			Game::cellMoveOffsets[col][aboveRow] = 18;
			Game::cellTypes[col][aboveRow] = Game::cellTypes[col][row];
			Game::cellStates[col][aboveRow] = Game::cellStates[col][row] & -8 | 1;
			Game::cellTypes[col][row] = -1;
			this->eraseCellInBuffer(col, row);
		}
		if ((Game::cellObjects[col][belowRow] & 255) != 35 && Game::cellTypes[col][belowRow] != 47) {
			if (Game::cellObjects[col][row] != 37) {
				s0 = Game::cellObjects[col];
				s1 = row;
				s2 = -1;
			} else {
				s0 = Game::cellObjects[col];
				s1 = row;
				s2 = 34;
			}
			cast<Array<int32_t>>(s0)[s1] = s2;
		}
		Game::cellUpdateTimers[col][aboveRow] = 24;
		{
			if (Game::cellTypes[col][row] < 0) {
				s0 = Game::cellMoveOffsets[col];
				s1 = row;
				s2 = 18;
				cast<Array<int8_t>>(s0)[s1] = s2;
				goto B7_end;
			}
		}
		B7_end:;
	}
}

bool Game::canLiftColumnEnter(int32_t col, int32_t row) {
	int32_t cellType = 0, objType = 0;
	cellType = Game::cellTypes[col][row];
	objType = Game::cellObjects[col][row] & 255;
	if (cellType >= 80 || cellType == 30 || cellType == 10 || cellType == 37 || cellType == 34 || cellType == 35 || objType == 14 || objType == 33 || objType == 15 || objType == 4 || objType == 16) {
		return 0;
	}
	return 1;
}

bool Game::isCellFreeForObject(int32_t col, int32_t row) {
	int32_t cellType = 0, objType = 0;
	cellType = Game::cellTypes[col][row];
	objType = Game::cellObjects[col][row] & 255;
	if (cellType != -1 || objType == 14 || objType == 33 || objType == 5 || objType == 28) {
		return 0;
	}
	return 1;
}

bool Game::isCellFreeForEnemy(int32_t col, int32_t row) {
	int32_t cellType = 0, objType = 0;
	cellType = Game::cellTypes[col][row];
	objType = Game::cellObjects[col][row] & 255;
	if (cellType != -1 || objType == 14 || objType == 33 || objType == 4 || objType == 32 || objType == 7 && (Game::cellObjects[col][row] >> 8 & 240) == 0) {
		return 0;
	}
	return 1;
}

void Game::emitLiftColumn() {
	int32_t aboveRow = 0, atLiquidSurface = 0;
	aboveRow = this->updateCellRow - 1;
	atLiquidSurface = Game::liquidCells == nullptr || Game::liquidCells[this->updateCellCol][this->updateCellRow] == 0 || Game::liquidCells[this->updateCellCol][this->updateCellRow - 1] != 0 ? 0 : 1;
	if ((Game::cellStates[this->updateCellCol][this->updateCellRow] & 7) == 0 && (Game::cellObjects[this->updateCellCol][aboveRow] & 255) != 35 && Game::canLiftColumnEnter(this->updateCellCol, aboveRow) && (!this->isPlayerAt(this->updateCellCol - 1, this->updateCellRow) && !this->isPlayerAt(this->updateCellCol + 1, this->updateCellRow) || (this->explorerStateFlags & 8) == 0) && (Game::cellTypes[this->updateCellCol][this->updateCellRow + 1] >= 0 || atLiquidSurface != 0)) {
		Game::cellObjects[this->updateCellCol][aboveRow] = 35;
		Game::cellMoveOffsets[this->updateCellCol][aboveRow] = 18;
		Game::cellUpdateTimers[this->updateCellCol][aboveRow] = 24;
	}
}

void Game::updateShooterEnemy() {
	int32_t col = 0, aboveRow = 0, row = 0, animState = 0, animTick = 0, animLength = 0, isOnLiftColumn = 0, playerFacing = 0, dirToPlayer = 0, rightCol = 0, s0 = 0, s1 = 0;
	Ref<Object> s0_o;
	Arr<int8_t> t1;
	col = this->updateCellCol;
	row = this->updateCellRow;
	animState = Game::cellStates[col][row] & 31;
	animTick = (Game::cellStates[col][row] & 8160) >> 5;
	animLength = Game::getAnimDuration(Game::spritePacks[29], animState);
	isOnLiftColumn = (Game::cellObjects[col][row] & 255) == 35 ? 1 : 0;
	if (!isOnLiftColumn) {
		if (Game::cellTypes[col][row + 1] >= 0 || animState == 8 || animState == 9) {
			if (animState == 8 || animState == 9) {
				t1 = Game::cellMoveOffsets[col];
				t1[row] = (int8_t)(t1[row] - 6);
				if (Game::cellMoveOffsets[col][row] >= 0) {
					if (Game::doMovingCellsTouch(col, row, 3, Game::cellMoveOffsets[col][row], this->playerCol, this->playerRow, this->explorerStateFlags & 7, this->playerStep)) {
						this->damageExplorer(1, 48, Game::cellStates[col][row] & 7);
						return;
					}
				} else {
					if (Game::cellTypes[col][row + 1] >= 0) {
						animState = animState != 8 ? 11 : 10;
						Game::cellStates[col][row] = animState;
						Game::cellMoveOffsets[col][row] = 0;
						return;
					}
					Game::cellMoveOffsets[col][row + 1] = 18;
					Game::cellTypes[col][row + 1] = 46;
					Game::cellTypes[col][row] = -1;
					Game::cellStates[col][row + 1] = animState;
					Game::wakeCellsAround(col, row);
					return;
				}
			} else {
				if (this->isCellCrushed(col, row)) {
					Game::cellTypes[col][row] = -1;
					this->killEnemyAt(col, row);
					Game::wakeCellsAround(col, row);
					return;
				}
				if (this->isPlayerAt(col - 1, row) || this->isPlayerAt(col + 1, row) || this->isPlayerAt(col, row - 1)) {
					{
						if (this->playerRow == row - 1) {
							s0 = 17;
							animState = s0;
							goto B9_end;
						}
						{
							if (this->playerCol == col - 1) {
								s0 = 16;
								animState = s0;
								goto B10_end;
							}
							if (this->playerCol == col + 1) {
								s0 = 15;
								animState = s0;
							}
						}
						B10_end:;
					}
					B9_end:;
					animTick = 0;
				} else {
					playerFacing = this->explorerStateFlags & 7;
					if (this->playerCol != col || this->playerStep != 6 || playerFacing != 4 && playerFacing != 2 || this->playerRow >= row || Game::cellTypes[col][row - 1] >= 0 || row * 24 > this->camY + 320 - 80) {
						if (this->playerRow != row || this->playerStep != 6 || playerFacing != 1 && playerFacing != 3 || animState < 0 || animState > 3 || (this->playerCol >= col || Game::cellTypes[col - 1][row] >= 0 || col * 24 >= this->camX + 240) && (this->playerCol <= col || Game::cellTypes[col + 1][row] >= 0 || (col + 1) * 24 <= this->camX)) {
							animTick++;
							switch (animState) {
								case 6:
								case 7:
									aboveRow = row - 1;
									if (Game::cellTypes[col][aboveRow] < 0 && animTick == Game::animTimeBeforeFrame(Game::spritePacks[29], animState, 1)) {
										Game::cellTypes[col][aboveRow] = 21;
										Game::cellStates[col][aboveRow] = 1;
										Game::cellMoveOffsets[col][aboveRow] = 18;
										s0_o = Game::cellUpdateTimers[col];
										s1 = aboveRow;
										cast<Array<int8_t>>(s0_o)[s1] = 24;
									}
									break;
								case 5:
									rightCol = col + 1;
									if (Game::cellTypes[rightCol][row] < 0 && animTick == Game::animTimeBeforeFrame(Game::spritePacks[29], 5, 1)) {
										Game::cellTypes[rightCol][row] = 21;
										Game::cellStates[rightCol][row] = 2;
										Game::cellMoveOffsets[rightCol][row] = 18;
										s0_o = Game::cellUpdateTimers[rightCol];
										s1 = row;
										cast<Array<int8_t>>(s0_o)[s1] = 24;
									}
									break;
								case 4:
									dirToPlayer = col - 1;
									if (Game::cellTypes[dirToPlayer][row] < 0 && animTick == Game::animTimeBeforeFrame(Game::spritePacks[29], 4, 1)) {
										Game::cellTypes[dirToPlayer][row] = 21;
										Game::cellStates[dirToPlayer][row] = 4;
										Game::cellMoveOffsets[dirToPlayer][row] = 18;
										s0_o = Game::cellUpdateTimers[dirToPlayer];
										s1 = row;
										cast<Array<int8_t>>(s0_o)[s1] = 24;
									}
									break;
								default:
									break;
							}
							if (animTick > animLength) {
								animTick = 0;
								dirToPlayer = this->chooseDirectionToward(col, row, this->playerCol, this->playerRow, 0);
								switch (dirToPlayer) {
									default:
										s0 = this->playerCol >= col ? 1 : 0;
										animState = s0;
										break;
									case 4:
										s0 = this->playerRow != row || animState == 4 || col * 24 >= this->camX + 240 ? 0 : 4;
										animState = s0;
										break;
									case 2:
										s0 = this->playerRow != row || animState == 5 || (col + 1) * 24 <= this->camX ? 1 : 5;
										animState = s0;
										break;
									case 1:
										if (this->playerCol != col || animState == 6 || animState == 7 || row * 24 > this->camY + 320 - 80) {
											animState = this->playerCol >= col ? 3 : 2;
										} else {
											animState = animState != 2 ? 7 : 6;
										}
										break;
								}
							}
						} else {
							animState = this->playerCol >= col ? 5 : 4;
							animTick = 0;
						}
					} else {
						switch (animState) {
							case 1:
							case 3:
								s0 = 7;
								animState = s0;
								animTick = 0;
								break;
							case 0:
							case 2:
								s0 = 6;
								animState = s0;
								animTick = 0;
								break;
							default:
								break;
						}
					}
				}
				Game::cellUpdateTimers[col][row] = 24;
				Game::cellStates[col][row] = animState & 31 | animTick << 5;
			}
			return;
		}
		switch (animState) {
			default:
				s0 = 9;
				break;
			case 0:
			case 2:
			case 4:
			case 6:
				s0 = 8;
				break;
		}
		animState = s0;
		Game::cellMoveOffsets[col][row + 1] = 18;
		Game::cellTypes[col][row + 1] = 46;
		Game::cellTypes[col][row] = -1;
		Game::cellStates[col][row + 1] = animState;
		Game::wakeCellsAround(col, row);
		return;
	}
	animTick++;
	if (animTick > animLength) {
		animTick = 0;
	}
	Game::cellStates[col][row] = 0 | animTick << 5;
}

int32_t Game::getAnimDuration(Ref<SpritePack> pack, int32_t animIndex) {
	int32_t totalTicks = 0, frameCount = 0, i = 0;
	totalTicks = 0;
	frameCount = pack->animFrameCounts[animIndex] & 255;
	for (i = 0; i < frameCount; i++) {
		totalTicks = totalTicks + (pack->animFrames[(pack->animFirstFrame[animIndex] + i) * 5 + 1] & 255);
	}
	return totalTicks;
}

void Game::updateStalactite() {
	int32_t col = 0, row = 0, phase = 0, scanRow = 0, blocked = 0, s1 = 0, s2 = 0;
	Ref<Object> s0;
	Arr<int8_t> t2, t3, t4;
	col = this->updateCellCol;
	row = this->updateCellRow;
	Game::cellUpdateTimers[col][row] = 24;
	phase = (Game::cellStates[col][row] & 56) >> 3;
	switch (phase) {
		case 4:
			if ((Game::frameCount & 1) == 0) {
				t4 = Game::cellMoveOffsets[col];
				t4[row] = (int8_t)(t4[row] + 1);
				if (Game::cellMoveOffsets[col][row] == Game::spritePacks[27]->getAnimFrameCount(4)) {
					s0 = Game::cellTypes[col];
					s1 = row;
					s2 = -1;
					cast<Array<int8_t>>(s0)[s1] = s2;
					Game::wakeCellsAround(col, row);
				}
			}
			break;
		case 3:
			if (Game::cellMoveOffsets[col][row] > 0) {
				t3 = Game::cellMoveOffsets[col];
				t3[row] = (int8_t)(t3[row] - 5);
				return;
			}
			scanRow = this->isPlayerAt(col, row + 1);
			blocked = 0;
			if (scanRow != 0 || Game::cellTypes[col][row + 1] >= 0 || this->hasWaterLayer && Game::liquidCells[col][row + 1] != 0) {
				if (scanRow == 0) {
					blocked = 1;
					switch (Game::cellTypes[col][row + 1]) {
						default:
							this->playSound(14);
							break;
						case 30:
							this->playSound(11);
							Game::cellStates[col][row + 1] = 1;
							break;
						case 21:
							blocked = 0;
							break;
						case 19:
						case 43:
						case 45:
						case 46:
						case 49:
							this->killEnemyAt(col, row + 1);
							Game::cellTypes[col][row + 1] = -1;
							break;
						case 18:
							this->tryPullLever();
							break;
						case 10:
							Game::cellObjects[col][row + 1] = 32;
							this->eraseCellInBuffer(col, row + 1);
							blocked = 0;
							break;
					}
				} else {
					this->damageExplorer(1, 48, 0);
					blocked = 1;
				}
			}
			if (blocked == 0) {
				Game::cellTypes[col][row] = -1;
				Game::cellTypes[col][row + 1] = 44;
				Game::cellStates[col][row + 1] = Game::cellStates[col][row];
				s0 = Game::cellMoveOffsets[col];
				s1 = row + 1;
				s2 = 19;
				cast<Array<int8_t>>(s0)[s1] = s2;
				Game::wakeCellsAround(col, row);
				break;
			}
			Game::cellStates[col][row] = Game::cellStates[col][row] & -64 | 32;
			Game::cellMoveOffsets[col][row] = 0;
			return;
		case 1:
			t2 = Game::cellMoveOffsets[col];
			t2[row] = (int8_t)(t2[row] - 1);
			if (Game::cellMoveOffsets[col][row] <= 0) {
				Game::cellObjects[col][row] = 34;
				Game::cellStates[col][row] = Game::cellStates[col][row] & -64 | 24 | 3;
				Game::cellMoveOffsets[col][row] = 0;
				return;
			}
			break;
		case 0:
			if (this->playerCol == col && (row + 1) * 24 > this->camY && this->specialStageType != 3 || this->specialStageType == 3 && this->ceilingCollapseFrame != 0LL && (int64_t)Game::frameCount >= this->ceilingCollapseFrame + (int64_t)(21 - col)) {
				scanRow = row + 1;
				while (true) {
					blocked = Game::cellTypes[col][scanRow];
					if (this->playerRow == scanRow || blocked >= 80 || blocked == 30 || blocked == 34 || blocked == 35 || blocked == 0) {
						break;
					}
					scanRow++;
				}
				if (this->playerRow == scanRow || this->specialStageType == 3) {
					Game::cellStates[col][row] = Game::cellStates[col][row] & -57 | 8;
					Game::cellMoveOffsets[col][row] = 10;
					return;
				}
			}
			break;
		default:
			break;
	}
}

void Game::animateWallDebris() {
	int32_t frame = 0, s1 = 0, s2 = 0;
	Ref<Object> s0;
	frame = Game::cellObjects[this->updateCellCol][this->updateCellRow] >> 8 & 255;
	if ((Game::frameCount & 1) != 0) {
		if (frame == 1) {
			this->eraseCellInBuffer(this->updateCellCol, this->updateCellRow);
		}
	} else {
		frame++;
	}
	if (frame != Game::spritePacks[16]->getAnimFrameCount(0)) {
		s0 = Game::cellObjects[this->updateCellCol];
		s1 = this->updateCellRow;
		s2 = frame << 8 | 32;
	} else {
		s0 = Game::cellObjects[this->updateCellCol];
		s1 = this->updateCellRow;
		s2 = -1;
	}
	cast<Array<int32_t>>(s0)[s1] = s2;
	Game::cellUpdateTimers[this->updateCellCol][this->updateCellRow] = 24;
}

void Game::updatePressurePlate() {
	int32_t col = 0, row = 0, doorId = 0, isPressed = 0, pressDepth = 0;
	col = this->updateCellCol;
	row = this->updateCellRow;
	doorId = Game::cellObjects[col][row] >> 8;
	isPressed = Game::isHeavyObject(col, row) || Game::cellTypes[col][row] == 47 || Game::cellTypes[col][row] == 48 ? 1 : 0;
	pressDepth = Game::cellMoveOffsets[col][row];
	if (isPressed == 0 && this->isPlayerAt(col, row)) {
		isPressed = 1;
		pressDepth = (this->explorerStateFlags & 4096) == 0 ? this->playerStep : 0;
	}
	if (isPressed == 0 || pressDepth >= 12) {
		this->closeDoorById(doorId);
		return;
	}
	this->unlockDoorLock(doorId);
}

void Game::updateExplosion() {
	int32_t col = 0, row = 0, frame = 0, animLength = 0, dy = 0, dx = 0, x = 0, y = 0, s1 = 0, s2 = 0;
	Ref<SpritePack> explosionSprites;
	Ref<Object> s0;
	col = this->updateCellCol;
	row = this->updateCellRow;
	frame = Game::cellStates[col][row];
	explosionSprites = Game::spritePacks[7];
	frame++;
	animLength = Game::getAnimDuration(explosionSprites, 0);
	if (frame < animLength) {
		if (frame != 1) {
			if (frame == animLength >> 1) {
				for (dy = -1; dy < 2; dy++) {
					for (dx = -1; dx < 2; dx++) {
						x = col + dx;
						y = row + dy;
						switch (Game::cellTypes[x][y]) {
							case 16:
							case 19:
							case 43:
							case 49:
								Game::cellTypes[x][y] = -1;
								this->killEnemyAt(x, y);
								Game::cellUpdateTimers[x][y] = 24;
								break;
							case 10:
								if (this->liquidState == 3) {
									s0 = Game::cellStates[x];
									s1 = y;
									s2 = 1;
									cast<Array<int32_t>>(s0)[s1] = s2;
									Game::wakeCellsAround(x, y);
								}
								break;
							case 30:
							case 37:
								s0 = Game::cellStates[x];
								s1 = y;
								s2 = 1;
								cast<Array<int32_t>>(s0)[s1] = s2;
								Game::wakeCellsAround(x, y);
								break;
							case 8:
								Game::cellTypes[x][y] = 54;
								s0 = Game::cellStates[x];
								s1 = y;
								s2 = 0;
								cast<Array<int32_t>>(s0)[s1] = s2;
								Game::wakeCellsAround(x, y);
								break;
							default:
								break;
						}
						if (this->isPlayerAt(x, y)) {
							this->damageExplorer(1, 64, 0);
						}
					}
				}
			}
		} else {
			this->playSound(7);
			Game::wakeCellsAround(col, row);
		}
		Game::cellStates[col][row] = frame;
		Game::cellUpdateTimers[col][row] = 24;
		return;
	}
	Game::cellTypes[col][row] = -1;
	Game::wakeCellsAround(col, row);
}

void Game::updateTorch() {
	int32_t col = 0, row = 0;
	col = this->updateCellCol;
	row = this->updateCellRow;
	if (Game::cellStates[col][row] != 0) {
		if (this->isPlayerAt(col, row - 1)) {
			this->damageExplorer(1, 64, 0);
		}
	} else {
		if (Game::cellTypes[col][row - 1] == 11) {
			Game::cellStates[col][row] = 1;
			this->progressGateObjective();
			return;
		}
	}
}

void Game::triggerGateChallenge() {
	if (this->playerStep <= 6 && this->isPlayerAt(this->updateCellCol, this->updateCellRow)) {
		Game::keys = 0;
		this->requestedMoveDir = 0;
		Game::activeGateId = Game::cellObjects[this->updateCellCol][this->updateCellRow] >> 8;
		this->closeDoorAt(this->playerCol + Game::dirDeltas[this->explorerStateFlags & 7], this->playerRow);
		if (Game::activeGateId < 0 || Game::activeGateId >= Game::gateRemainingCounts->length) {
			Game::activeGateId = -1;
		} else {
			this->playSound(1);
			this->gateRevealState = 1;
			this->setGatePanTarget(Game::activeGateId);
		}
		Game::cellObjects[this->updateCellCol][this->updateCellRow] = -1;
	}
}

void Game::updateFlameJetTrap(int32_t trapType, int32_t flameLength) {
	int32_t col = 0, row = 0, dirSign = 0, i = 0, flameCol = 0;
	col = this->updateCellCol;
	row = this->updateCellRow;
	dirSign = trapType != 23 ? 1 : -1;
	Game::cellUpdateTimers[col][row] = 24;
	if (this->playerRow == row) {
		for (i = 0; i <= flameLength; i++) {
			flameCol = col + i * dirSign;
			if (this->playerCol == flameCol) {
				this->damageExplorer(1, 64, 0);
			}
		}
	}
}

void Game::finishItemPickup() {
	int32_t playRaiseAnim = 0, effectType = 0, rememberPickupCell = 0, s1 = 0, t2 = 0;
	Arr<int32_t> t1;
	Arr<int8_t> t3;
	playRaiseAnim = 0;
	effectType = -1;
	rememberPickupCell = 0;
	switch (this->pickedItemType) {
		case 51:
		case 52:
		case 53:
			this->markCollectibleTaken(this->world, this->stage, this->playerCol, this->playerRow);
			effectType = 0;
			playRaiseAnim = 1;
			this->resetCounters();
			this->gotElementalDiamond = 1;
			if (this->pickedItemType != 53) {
				if (this->pickedItemType != 51) {
					s1 = 2;
				} else {
					s1 = 1;
				}
			} else {
				s1 = 0;
			}
			cast<Game>(this)->placingElementalIndex = s1;
			t3 = Game::saveData;
			t3[2] = (int8_t)(t3[2] | shl(1, this->placingElementalIndex));
			this->writeSaveRecord();
			break;
		case 42:
			rememberPickupCell = 1;
			playRaiseAnim = 1;
			this->hasCompass = 1;
			this->pendingCutsceneId = 11;
			break;
		case 41:
			if (this->isBossStage()) {
				this->bossTreasureTaken = 1;
				this->resetCounters();
			}
			this->diamondCount = this->diamondCount + this->heldItemAmount;
			this->diamondsToOpenExit = this->diamondsToOpenExit - this->heldItemAmount;
			if (this->diamondsToOpenExit <= 0 && !this->isBossStage()) {
				Game::cellTypes[this->exitDoorCol][this->exitDoorRow] = -1;
				this->diamondsToOpenExit = 0;
			}
			effectType = 3;
			break;
		case 40:
			rememberPickupCell = 1;
			playRaiseAnim = 1;
			this->pendingCutsceneId = 24;
			break;
		case 27:
			rememberPickupCell = 1;
			playRaiseAnim = 1;
			this->pendingCutsceneId = 23;
			break;
		case 26:
			playRaiseAnim = 1;
			this->pendingCutsceneId = 25;
			rememberPickupCell = 1;
			break;
		case 24:
			rememberPickupCell = 1;
			playRaiseAnim = 1;
			this->pendingCutsceneId = 22;
			break;
		case 7:
			this->setExplorerEnergy(127);
			effectType = 4;
			break;
		case 6:
			this->lives = this->lives + 1;
			Game::checkpointCellTypes[this->playerCol][this->playerRow] = -1;
			t1 = Game::checkpointCellObjects[this->playerCol];
			t2 = this->playerRow;
			t1[t2] = t1[t2] | 256;
			effectType = 0;
			this->markCollectibleTaken(this->world, this->stage, this->playerCol, this->playerRow);
			break;
		case 5:
			this->silverKeys = this->silverKeys + 1;
			effectType = 1;
			break;
		case 4:
			effectType = 2;
			this->goldKeys = this->goldKeys + 1;
			break;
		case 2:
			this->redDiamondCount = this->redDiamondCount + 1;
			rememberPickupCell = 1;
			effectType = 0;
			break;
		default:
			break;
	}
	if (playRaiseAnim != 0) {
		this->setExplorerAnim(47);
	}
	if (effectType != -1) {
		this->spawnCellEffect(this->playerCol, this->playerRow - 1, effectType);
	}
	if (rememberPickupCell != 0) {
		Game::redDiamondPickCells[this->redDiamondPickCount << 1] = (int8_t)this->playerCol;
		Game::redDiamondPickCells[(this->redDiamondPickCount << 1) + 1] = (int8_t)this->playerRow;
		this->redDiamondPickCount = this->redDiamondPickCount + 1;
	}
	this->requestHudRedraw();
	this->pickedItemType = -1;
}

void Game::startItemPickup(int32_t itemType) {
	int32_t col = 0, row = 0, cellObject = 0, s1 = 0;
	col = this->updateCellCol;
	row = this->updateCellRow;
	if (this->playerStep > 0 || !this->isPlayerAt(col, row)) {
		return;
	}
	cellObject = Game::cellObjects[col][row] & 255;
	if ((cellObject == 14 || cellObject == 33) && Game::cellObjects[col][row] >> 8 == 255) {
		return;
	}
	this->pickedItemType = itemType;
	switch (itemType) {
		case 53:
			this->heldItemImageSet = 32;
			s1 = 0;
			cast<Game>(this)->heldItemFrame = s1;
			break;
		case 52:
			this->heldItemImageSet = 31;
			s1 = 0;
			cast<Game>(this)->heldItemFrame = s1;
			break;
		case 51:
			this->heldItemImageSet = 30;
			s1 = 0;
			cast<Game>(this)->heldItemFrame = s1;
			break;
		case 42:
			this->heldItemImageSet = 29;
			s1 = 0;
			cast<Game>(this)->heldItemFrame = s1;
			break;
		case 41:
			this->heldItemImageSet = 2;
			this->heldItemFrame = 0;
			this->heldItemAmount = Game::cellStates[this->updateCellCol][this->updateCellRow];
			break;
		case 40:
			this->heldItemImageSet = 19;
			this->heldItemFrame = 0;
			Game::cellTypes[this->updateCellCol][this->updateCellRow] = -1;
			this->pickedItemType = 40;
			Game::saveData[10] = 1;
			break;
		case 7:
			{
				if (this->explorerEnergy != Game::saveData[8]) {
					this->heldItemImageSet = 5;
					s1 = 1;
					cast<Game>(this)->heldItemFrame = s1;
					goto B4_end;
				}
				Game::cellTypes[col][row] = 41;
				Game::cellStates[col][row] = 10;
				this->diamondsInStage = this->diamondsInStage + 10;
				this->startItemPickup(41);
			}
			B4_end:;
			break;
		case 6:
			{
				if (this->lives >= 99) {
					Game::cellTypes[col][row] = 7;
					Game::cellStates[col][row] = 0;
					this->startItemPickup(7);
				} else {
					this->heldItemImageSet = 5;
					s1 = 0;
					cast<Game>(this)->heldItemFrame = s1;
					goto B5_end;
				}
			}
			B5_end:;
			break;
		case 5:
			this->heldItemImageSet = 25;
			s1 = 0;
			cast<Game>(this)->heldItemFrame = s1;
			break;
		case 4:
			this->heldItemImageSet = 24;
			s1 = 0;
			cast<Game>(this)->heldItemFrame = s1;
			break;
		case 2:
			this->heldItemImageSet = 3;
			s1 = 0;
			cast<Game>(this)->heldItemFrame = s1;
			break;
		default:
			break;
	}
	Game::cellTypes[col][row] = -1;
	this->requestHudRedraw();
}

bool Game::isBlockedByExtendingTrap(int32_t col, int32_t row) {
	if (Game::cellTypes[col][row] == 28 || this->pistonSlowExtent >= 24 && (Game::cellTypes[col][row - 1] == 28 && (Game::cellStates[col][row - 1] & 8) == 0 || Game::cellTypes[col][row + 1] == 28 && (Game::cellStates[col][row + 1] & 8) == 0) || this->pistonFastExtent >= 24 && (Game::cellTypes[col][row - 1] == 28 || Game::cellTypes[col][row + 1] == 28)) {
		return 1;
	}
	return 0;
}

int32_t Game::chooseDirectionToward(int32_t fromCol, int32_t fromRow, int32_t toCol, int32_t toRow, bool avoidBlockedVertical) {
	int32_t dir = 0, nextRow = 0, dx = 0, dy = 0, absDx = 0, absDy = 0, s0 = 0;
	dx = fromCol - toCol;
	dy = fromRow - toRow;
	absDx = dx <= 0 ? -dx : dx;
	absDy = dy <= 0 ? -dy : dy;
	dir = 0;
	if (absDx > absDy) {
		if (dx <= 0) {
			if (dx < 0) {
				s0 = 2;
				dir = s0;
			}
		} else {
			s0 = 4;
			dir = s0;
		}
		if (dir != 0 && (!Game::isCellFreeForEnemy(fromCol - Game::dirDeltas[dir], fromRow) || this->isBlockedByExtendingTrap(fromCol - Game::dirDeltas[dir], fromRow))) {
			dir = 0;
		}
	}
	if (dir == 0) {
		{
			if (dy > 0) {
				s0 = 1;
				dir = s0;
				goto B6_end;
			}
			if (dy < 0) {
				s0 = 3;
				dir = s0;
			}
		}
		B6_end:;
		nextRow = fromRow - Game::dirDeltas[8 + dir];
		if (avoidBlockedVertical != 0 && dir != 0 && (!Game::isCellFreeForEnemy(fromCol, nextRow) || this->hasWaterLayer && Game::liquidCells[fromCol][nextRow] != 0 || this->isBlockedByExtendingTrap(fromCol, nextRow))) {
			dir = 0;
			{
				if (dx > 0) {
					s0 = 4;
					dir = s0;
					goto B9_end;
				}
				if (dx < 0) {
					s0 = 2;
					dir = s0;
				}
			}
			B9_end:;
			if (dir != 0 && Game::cellTypes[fromCol - Game::dirDeltas[dir]][fromRow] >= 0) {
				dir = 0;
			}
		}
	}
	return dir;
}

void Game::updateWalkingEnemy(int8_t enemyType) {
	int32_t dir = 0, dirOrTargetCol = 0, targetRow = 0, pathDir = 0, col = 0, row = 0, state = 0, moveOffset = 0, stepX = 0, stepY = 0, isInBubble = 0, isChasing = 0, s0 = 0, s1 = 0, s2 = 0;
	Ref<Object> s0_o;
	col = this->updateCellCol;
	row = this->updateCellRow;
	state = Game::cellStates[col][row];
	moveOffset = Game::cellMoveOffsets[col][row];
	stepX = 0;
	stepY = 0;
	s0 = (Game::cellObjects[col][row] & 255) != 35 ? 0 : 1;
	isInBubble = s0;
	s0 = enemyType != 43 || (state & 3840) == 0 ? 0 : 1;
	isChasing = s0;
	if (isInBubble != 0 || !this->isCellCrushed(col, row)) {
		dir = state & 7;
		if (moveOffset > 0) {
			if (moveOffset < 0) {
				Game::cellMoveOffsets[col][row] = 0;
			}
			moveOffset = (int8_t)(moveOffset - 3);
			s0_o = Game::cellMoveOffsets[col];
			s1 = row;
			s2 = moveOffset;
			cast<Array<int8_t>>(s0_o)[s1] = s2;
		} else {
			if (isInBubble == 0 || moveOffset > 6) {
				Game::wakeCellsAround(col, row);
				if (isChasing == 0) {
					if ((state & 16646144) == 0 || (state & 248) != 0) {
						if (dir != 0) {
							moveOffset = 21;
							stepX = -Game::dirDeltas[dir];
							stepY = -Game::dirDeltas[dir + 8];
							if (!Game::isCellFreeForEnemy(col + stepX, row + stepY)) {
								switch (dir) {
									case 4:
										s0 = state & -28673;
										s1 = 8192;
										state = s0 | s1;
										break;
									case 3:
										s0 = state & -28673;
										s1 = 4096;
										state = s0 | s1;
										break;
									case 2:
										s0 = state & -28673;
										s1 = 16384;
										state = s0 | s1;
										break;
									case 1:
										s0 = state & -28673;
										s1 = 12288;
										state = s0 | s1;
										break;
									default:
										break;
								}
								state = state & -8 | 0;
								dir = 0;
								stepY = 0;
								stepX = stepY;
							}
						} else {
							moveOffset = 21;
							dirOrTargetCol = (state & 28672) >> 12;
							state = state & -8 | dirOrTargetCol;
							dir = dirOrTargetCol;
							stepX = -Game::dirDeltas[dirOrTargetCol];
							stepY = -Game::dirDeltas[dirOrTargetCol + 8];
							if (!Game::isCellFreeForEnemy(col + stepX, row + stepY)) {
								stepY = 0;
								stepX = stepY;
								moveOffset = 0;
							}
						}
					} else {
						dirOrTargetCol = (state & 16646144) >> 17;
						targetRow = (state & 2130706432) >> 24;
						if (col != dirOrTargetCol || row != targetRow) {
							moveOffset = 21;
							pathDir = this->chooseDirectionToward(col, row, dirOrTargetCol, targetRow, 1);
							state = state & -8 | pathDir;
							stepX = -Game::dirDeltas[pathDir];
							stepY = -Game::dirDeltas[pathDir + 8];
							dir = pathDir;
							if (pathDir == 0) {
								moveOffset = 0;
								stepY = 0;
								stepX = stepY;
							}
						} else {
							state = state & -16646145;
							dir = (state & INT32_MIN) != 0 ? 1 : 2;
							state = state & -8 | dir;
						}
					}
				} else {
					moveOffset = 18;
					dirOrTargetCol = this->chooseDirectionToward(col, row, this->playerCol, this->playerRow, 1);
					state = state & -8 | dirOrTargetCol;
					dir = dirOrTargetCol;
					stepX = -Game::dirDeltas[dirOrTargetCol];
					stepY = -Game::dirDeltas[dirOrTargetCol + 8];
					if (dirOrTargetCol == 0) {
						moveOffset = 0;
						stepY = 0;
						stepX = stepY;
					}
					state = state - 256;
				}
			} else {
				if (moveOffset < 0) {
					Game::cellMoveOffsets[col][row] = 0;
				}
			}
			{
				if ((state & 248) != 0) {
					if ((Game::frameCount & 3) == 0) {
						state = state & -249 | (state & 248) - 8;
						if (enemyType == 43 && (state & 248) == 0) {
							state = state & -3841 | 3072;
						}
					}
					s0_o = Game::cellMoveOffsets[col];
					s1 = row;
					s2 = 0;
					cast<Array<int8_t>>(s0_o)[s1] = s2;
					goto B17_end;
				}
				Game::cellTypes[col][row] = -1;
				Game::cellTypes[col + stepX][row + stepY] = enemyType;
				Game::cellUpdateTimers[col + stepX][row + stepY] = 48;
				Game::cellMoveOffsets[col + stepX][row + stepY] = moveOffset;
				Game::cellStates[col + stepX][row + stepY] = state;
			}
			B17_end:;
		}
		if ((state & 248) == 0 && (Game::actors[0]->animIndex < 13 || Game::actors[0]->animIndex > 16) && Game::doMovingCellsTouch(col, row, dir, Game::cellMoveOffsets[col][row], this->playerCol, this->playerRow, (this->explorerStateFlags & 4096) != 0 ? 0 : this->currentMoveDir, this->playerStep)) {
			this->damageExplorer(1, 48, dir);
			if (isChasing != 0) {
				state = state & -3841;
			}
		}
		Game::cellStates[col][row] = state;
		return;
	}
	Game::cellTypes[col][row] = -1;
	this->killEnemyAt(col, row);
}

void Game::animateEnemyDeathPuff() {
	int32_t frame = 0, s1 = 0, s2 = 0;
	Ref<Object> s0;
	frame = (Game::cellObjects[this->updateCellCol][this->updateCellRow] & -268435456) >> 28;
	if (frame == 0) {
		this->playSound(10);
	}
	if ((Game::frameCount & 1) == 0) {
		frame++;
	}
	if (frame < Game::spritePacks[13]->getAnimFrameCount(0)) {
		s0 = Game::cellObjects[this->updateCellCol];
		s1 = this->updateCellRow;
		s2 = Game::cellObjects[this->updateCellCol][this->updateCellRow] & 268435455 | frame << 28;
	} else {
		s0 = Game::cellObjects[this->updateCellCol];
		s1 = this->updateCellRow;
		s2 = Game::cellObjects[this->updateCellCol][this->updateCellRow] & 268435455;
	}
	cast<Array<int32_t>>(s0)[s1] = s2;
	Game::wakeCellsAround(this->updateCellCol, this->updateCellRow);
}

void Game::progressGateObjective() {
	Arr<int8_t> t1;
	int32_t t2 = 0;
	if ((this->specialStageType == 3 || this->specialStageType == 4 || this->specialStageType == 5) && this->bossHealth > 0) {
		return;
	}
	if (Game::activeGateId >= 0) {
		t1 = Game::gateRemainingCounts;
		t2 = Game::activeGateId;
		t1[t2] = (int8_t)(t1[t2] - 1);
		if (Game::gateRemainingCounts[Game::activeGateId] == 0) {
			this->openGateById(Game::activeGateId);
		}
	}
}

void Game::takeRelicFromChest(int32_t relicType) {
	int32_t s1 = 0;
	if ((Game::cellObjects[this->updateCellCol][this->updateCellRow] & 255) != 14 || Game::cellObjects[this->updateCellCol][this->updateCellRow] >> 8 != 255) {
		if (this->isPlayerAt(this->updateCellCol, this->updateCellRow) && (Game::actors[0]->animIndex == 40 || Game::actors[0]->animIndex == 48)) {
			Game::cellTypes[this->updateCellCol][this->updateCellRow] = -1;
			switch (relicType) {
				case 27:
					Game::saveData[9] = 2;
					this->heldItemImageSet = 7;
					this->heldItemFrame = 1;
					s1 = 27;
					cast<Game>(this)->pickedItemType = s1;
					break;
				case 26:
					Game::saveData[9] = 8;
					this->heldItemImageSet = 7;
					this->heldItemFrame = 2;
					s1 = 26;
					cast<Game>(this)->pickedItemType = s1;
					break;
				case 24:
					Game::saveData[9] = 1;
					this->heldItemImageSet = 7;
					this->heldItemFrame = 0;
					s1 = 24;
					cast<Game>(this)->pickedItemType = s1;
					break;
				default:
					break;
			}
			this->markCollectibleTaken(this->world, this->stage, this->updateCellCol, this->updateCellRow);
		}
		return;
	}
}

void Game::updateCrumblingWall() {
	int32_t crumbleStep = 0, col = 0, row = 0, dir = 0, dx = 0, dy = 0, t3 = 0;
	Arr<int32_t> t2;
	crumbleStep = Game::cellStates[this->updateCellCol][this->updateCellRow];
	if (crumbleStep > 0) {
		col = this->updateCellCol;
		row = this->updateCellRow;
		if (crumbleStep != 4) {
			if (crumbleStep >= 16) {
				Game::cellTypes[col][row] = -1;
				Game::wakeCellsAround(col, row);
			}
		} else {
			for (dir = 1; dir < 5; dir++) {
				dx = Game::dirDeltas[dir];
				dy = Game::dirDeltas[dir + 8];
				if (Game::cellTypes[col + dx][row + dy] == 30) {
					t2 = Game::cellStates[col + dx];
					t3 = row + dy;
					t2[t3] = t2[t3] + 1;
					Game::cellUpdateTimers[col + dx][row + dy] = 24;
				}
			}
		}
		Game::cellStates[col][row] = crumbleStep + 1;
		Game::cellUpdateTimers[col][row] = 24;
	}
}

void Game::updateCrackingWall() {
	int32_t col = 0, row = 0, crackStep = 0;
	col = this->updateCellCol;
	row = this->updateCellRow;
	crackStep = Game::cellStates[col][row];
	if (crackStep > 0) {
		if (crackStep >= 8) {
			this->checkLiquidBreachAt(col, row);
			Game::cellTypes[col][row] = -1;
			Game::wakeCellsAround(col, row);
		}
		Game::cellStates[col][row] = crackStep + 1;
		Game::cellUpdateTimers[col][row] = 24;
	}
}

void Game::updateCrawlingFlame() {
	int32_t col = 0, forwardDy = 0, sideTurnDir = 0, blockedTurnDir = 0, row = 0, dyingStep = 0, state = 0, isCounterClockwise = 0, dir = 0, sideDx = 0, sideDy = 0, forwardDx = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0;
	Ref<Object> s0_o;
	Arr<int8_t> t15;
	col = this->updateCellCol;
	row = this->updateCellRow;
	dyingStep = (Game::cellStates[col][row] & 3840) >> 8;
	if (dyingStep == 0) {
		if (Game::liquidCells == nullptr || Game::liquidCells[col][row] == 0) {
			if (Game::cellMoveOffsets[col][row] <= 4) {
				state = Game::cellStates[col][row];
				Game::cellUpdateTimers[col][row] = 24;
				isCounterClockwise = (state & 16) != 0 ? 1 : 0;
				dir = state & 7;
				if (dir == 0) {
					if (Game::cellTypes[col - 1][row] < 0) {
						if (Game::cellTypes[col][row + 1] >= 0) {
							s0_o = Game::cellStates[col];
							s1 = row;
							s2 = state & -8 | (isCounterClockwise == 0 ? 4 : 2);
							cast<Array<int32_t>>(s0_o)[s1] = s2;
						}
					} else {
						s0_o = Game::cellStates[col];
						s1 = row;
						s2 = state & -8 | (isCounterClockwise == 0 ? 3 : 1);
						cast<Array<int32_t>>(s0_o)[s1] = s2;
					}
					if (Game::cellTypes[col + 1][row] >= 0) {
						Game::cellStates[col][row] = state & -8 | (isCounterClockwise == 0 ? 1 : 3);
					}
					if (Game::cellTypes[col][row + 1] >= 0) {
						s0_o = Game::cellStates[col];
						s1 = row;
						s2 = state & -8;
						if (isCounterClockwise == 0) {
							s0_o = cast<Array<int32_t>>(s0_o);
							s3 = 2;
						} else {
							s0_o = cast<Array<int32_t>>(s0_o);
							s3 = 4;
						}
						cast<Array<int32_t>>(s0_o)[s1] = s2 | s3;
					}
				} else {
					sideDx = 0;
					sideDy = 0;
					forwardDx = 0;
					forwardDy = 0;
					sideTurnDir = 0;
					blockedTurnDir = 0;
					switch (dir) {
						case 4:
							sideDy = isCounterClockwise == 0 ? -1 : 1;
							sideTurnDir = isCounterClockwise == 0 ? 1 : 3;
							blockedTurnDir = isCounterClockwise == 0 ? 3 : 1;
							s0 = -1;
							forwardDx = s0;
							break;
						case 3:
							sideDx = isCounterClockwise == 0 ? -1 : 1;
							sideTurnDir = isCounterClockwise == 0 ? 4 : 2;
							blockedTurnDir = isCounterClockwise == 0 ? 2 : 4;
							forwardDy = 1;
							break;
						case 2:
							sideDy = isCounterClockwise == 0 ? 1 : -1;
							sideTurnDir = isCounterClockwise == 0 ? 3 : 1;
							blockedTurnDir = isCounterClockwise == 0 ? 1 : 3;
							s0 = 1;
							forwardDx = s0;
							break;
						case 1:
							sideDx = isCounterClockwise == 0 ? 1 : -1;
							sideTurnDir = isCounterClockwise == 0 ? 2 : 4;
							blockedTurnDir = isCounterClockwise == 0 ? 4 : 2;
							forwardDy = -1;
							break;
						default:
							break;
					}
					if (!Game::isCellFreeForEnemy(col + forwardDx, row + forwardDy) || !Game::isCellFreeForEnemy(col + sideDx, row + sideDy) || !Game::isCellFreeForEnemy(col + sideDx - forwardDx, row + sideDy - forwardDy)) {
						if (!Game::isCellFreeForEnemy(col + sideDx, row + sideDy)) {
							{
								if (!Game::isCellFreeForEnemy(col + forwardDx, row + forwardDy)) {
									s0_o = Game::cellStates[col];
									s1 = row;
									s2 = state & -8;
									s3 = blockedTurnDir;
									cast<Array<int32_t>>(s0_o)[s1] = s2 | s3;
									goto B13_end;
								}
								if (Game::cellMoveOffsets[col][row] <= 0) {
									Game::cellStates[col + forwardDx][row + forwardDy] = state;
									Game::cellTypes[col + forwardDx][row + forwardDy] = 11;
									Game::cellTypes[col][row] = -1;
									Game::cellMoveOffsets[col + forwardDx][row + forwardDy] = 18;
								}
							}
							B13_end:;
						} else {
							Game::cellStates[col + sideDx][row + sideDy] = state & -8 | sideTurnDir;
							Game::cellTypes[col + sideDx][row + sideDy] = 11;
							Game::cellTypes[col][row] = -1;
							Game::cellMoveOffsets[col + sideDx][row + sideDy] = 18;
						}
					} else {
						if (Game::cellMoveOffsets[col][row] <= 0) {
							Game::cellStates[col + forwardDx][row + forwardDy] = state;
							Game::cellTypes[col + forwardDx][row + forwardDy] = 11;
							Game::cellTypes[col][row] = -1;
							Game::cellMoveOffsets[col + forwardDx][row + forwardDy] = 18;
						}
					}
				}
				Game::wakeCellsAround(col, row);
			}
		} else {
			Game::cellStates[col][row] = Game::cellStates[col][row] & -3841 | 256;
		}
	} else {
		if (dyingStep < 4) {
			if ((Game::frameCount >> 1 & 1) == 0) {
				Game::cellStates[col][row] = Game::cellStates[col][row] + 256;
			}
		} else {
			Game::cellTypes[col][row] = -1;
		}
	}
	if (this->isPlayerAt(col, row)) {
		this->damageExplorer(1, 64, 0);
	}
	if (Game::cellMoveOffsets[col][row] > 0) {
		t15 = Game::cellMoveOffsets[col];
		t15[row] = (int8_t)(t15[row] - 5);
	}
}

void Game::updateFragileWall() {
	int32_t col = 0, row = 0, hitState = 0;
	col = this->updateCellCol;
	row = this->updateCellRow;
	hitState = Game::cellStates[col][row];
	if (hitState > 0) {
		Game::cellTypes[col][row] = -1;
		Game::cellObjects[col][row] = 32;
		Game::wakeCellsAround(col, row);
		this->checkLiquidBreachAt(col, row);
		Game::cellUpdateTimers[col][row] = 24;
	}
}

void Game::updateExtendingRod() {
	int32_t col = 0, pushBack = 0, row = 0, state = 0, dirX = 0, aheadType = 0, aheadObject = 0, retract = 0, lengthLeft = 0, aheadState = 0, s1 = 0, s2 = 0, t3 = 0;
	Ref<Object> s0_o;
	Arr<int8_t> t4;
	col = this->updateCellCol;
	row = this->updateCellRow;
	Game::cellUpdateTimers[col][row] = 24;
	if (Game::cellMoveOffsets[col][row] != 0) {
		t4 = Game::cellMoveOffsets[col];
		s0_o = t4;
		s1 = row;
		s2 = (int8_t)(t4[row] - 6);
	} else {
		state = Game::cellStates[col][row];
		dirX = (state & 1) != 0 ? 1 : -1;
		aheadType = Game::cellTypes[col + dirX][row];
		aheadObject = Game::cellObjects[col + dirX][row] & 255;
		retract = 0;
		lengthLeft = state >> 1;
		if (lengthLeft <= 0) {
			retract = 1;
		} else {
			if (aheadType >= 0 || aheadObject == 14 || aheadObject == 33) {
				if (aheadType != 32) {
					aheadState = Game::cellStates[col + dirX][row];
					pushBack = 0;
					if (aheadType != 48 || (aheadState & 8) == 0) {
						switch (aheadType) {
							default:
								if (aheadType != -1) {
									retract = 1;
								}
								break;
							case 1:
							case 2:
							case 4:
							case 5:
							case 6:
							case 7:
								pushBack = -dirX;
								this->playSound(12);
								this->slidingObjSubStep = 0;
								this->slideCellsLeft = this->playerCol - (col + dirX) + pushBack;
								this->slidingObjCol = col + dirX;
								this->slidingObjRow = row;
								if (this->slidingObjSavedParams == -1) {
									switch (aheadType) {
										case 0:
										case 8:
										case 9:
										case 47:
											t3 = aheadState & -28673;
											aheadState = t3;
											aheadState = aheadState & -513;
											break;
										default:
											break;
									}
									this->slidingObjSavedParams = aheadState;
								}
								if (this->slideCellsLeft >= 0) {
									this->slidingObjParams = aheadState & -8 | 2;
								} else {
									this->slidingObjParams = aheadState & -8 | 4;
								}
								break;
							case 0:
							case 8:
							case 9:
							case 11:
							case 14:
							case 19:
							case 43:
							case 47:
							case 48:
							case 49:
								this->playSound(12);
								this->slidingObjSubStep = 0;
								this->slideCellsLeft = this->playerCol - (col + dirX) + pushBack;
								this->slidingObjCol = col + dirX;
								this->slidingObjRow = row;
								if (this->slidingObjSavedParams == -1) {
									switch (aheadType) {
										case 0:
										case 8:
										case 9:
										case 47:
											t3 = aheadState & -28673;
											aheadState = t3;
											aheadState = aheadState & -513;
											break;
										default:
											break;
									}
									this->slidingObjSavedParams = aheadState;
								}
								if (this->slideCellsLeft >= 0) {
									this->slidingObjParams = aheadState & -8 | 2;
								} else {
									this->slidingObjParams = aheadState & -8 | 4;
								}
								break;
						}
					}
				}
			} else {
				Game::cellStates[col + dirX][row] = lengthLeft - 1 << 1 | state & 1;
				Game::cellUpdateTimers[col + dirX][row] = 30;
				Game::cellMoveOffsets[col + dirX][row] = 18;
				aheadType = 32;
			}
		}
		if (retract != 0) {
			for (aheadState = 1; aheadState <= 3; aheadState++) {
				if (Game::cellTypes[this->playerCol + dirX * aheadState][this->playerRow] == 32) {
					Game::cellTypes[this->playerCol + dirX * aheadState][this->playerRow] = -1;
				}
			}
		}
		s0_o = Game::cellTypes[col + dirX];
		s1 = row;
		s2 = aheadType;
	}
	cast<Array<int8_t>>(s0_o)[s1] = s2;
	Game::wakeCellsAround(col, row);
}

void Game::updateProjectile() {
	int32_t col = 0, ownState = 0, row = 0, dir = 0, nextCol = 0, nextRow = 0, startOffset = 0, otherDir = 0, pushCol = 0, pushRow = 0, s0 = 0, s1 = 0, s2 = 0;
	Ref<Object> s0_o;
	Arr<int8_t> t1, t3;
	Arr<int32_t> t2;
	col = this->updateCellCol;
	row = this->updateCellRow;
	dir = Game::cellStates[col][row] & 7;
	if ((Game::cellStates[col][row] & 8) == 0) {
		if (this->isPlayerAt(col, row) || this->isPlayerAt(col + Game::dirDeltas[dir], row + Game::dirDeltas[8 + dir]) && Game::cellMoveOffsets[col][row] <= this->playerStep) {
			this->damageExplorer(1, 48, 0);
		}
		if (Game::cellMoveOffsets[col][row] > 0) {
			t3 = Game::cellMoveOffsets[col];
			s0_o = t3;
			s1 = row;
			s2 = (int8_t)(t3[row] - 12);
		} else {
			nextCol = col - Game::dirDeltas[dir];
			nextRow = row - Game::dirDeltas[dir + 8];
			startOffset = 24;
			if (dir == 4) {
				startOffset = 12;
			}
			if (Game::cellTypes[nextCol][nextRow] >= 0) {
				if (Game::cellTypes[nextCol][nextRow] != 21) {
					switch (Game::cellTypes[nextCol][nextRow]) {
						case 19:
						case 43:
						case 45:
						case 46:
							Game::cellTypes[nextCol][nextRow] = -1;
							this->killEnemyAt(nextCol, nextRow);
							break;
						case 10:
						case 30:
							if (Game::cellStates[nextCol][nextRow] < 1) {
								Game::cellStates[nextCol][nextRow] = 1;
							}
							break;
						default:
							break;
					}
					t2 = Game::cellStates[col];
					t2[row] = t2[row] | 8;
					s0_o = Game::cellMoveOffsets[col];
					s1 = row;
					s2 = 0;
				} else {
					otherDir = Game::cellStates[nextCol][nextRow] & 7;
					pushCol = nextCol - Game::dirDeltas[otherDir];
					pushRow = nextRow - Game::dirDeltas[otherDir + 8];
					Game::cellTypes[col][row] = -1;
					Game::wakeCellsAround(col, row);
					ownState = Game::cellStates[col][row];
					if (Game::cellTypes[pushCol][pushRow] < 0) {
						Game::cellTypes[pushCol][pushRow] = 21;
						Game::cellStates[pushCol][pushRow] = Game::cellStates[nextCol][nextRow];
						Game::cellMoveOffsets[pushCol][pushRow] = 18;
					}
					Game::cellTypes[nextCol][nextRow] = 21;
					Game::cellStates[nextCol][nextRow] = ownState;
					s0_o = Game::cellMoveOffsets[nextCol];
					s1 = nextRow;
					s2 = 18;
				}
			} else {
				Game::cellTypes[nextCol][nextRow] = 21;
				Game::cellStates[nextCol][nextRow] = Game::cellStates[col][row];
				Game::cellMoveOffsets[nextCol][nextRow] = startOffset;
				s0_o = Game::cellTypes[col];
				s1 = row;
				s2 = -1;
			}
			cast<Array<int8_t>>(s0_o)[s1] = s2;
			s0_o = Game::cellUpdateTimers[nextCol];
			s1 = nextRow;
			s2 = 48;
		}
		cast<Array<int8_t>>(s0_o)[s1] = s2;
		return;
	}
	switch (dir) {
		default:
			s0 = 14;
			break;
		case 4:
			s0 = 12;
			break;
		case 2:
			s0 = 13;
			break;
	}
	nextCol = s0;
	if (Game::cellMoveOffsets[col][row] >= Game::getAnimDuration(Game::spritePacks[29], nextCol) || (Game::cellObjects[this->updateCellCol][this->updateCellRow] & 255) == 35) {
		Game::cellTypes[col][row] = -1;
		Game::wakeCellsAround(col, row);
	} else {
		t1 = Game::cellMoveOffsets[col];
		t1[row] = (int8_t)(t1[row] + 1);
	}
	Game::cellUpdateTimers[col][row] = 24;
}

void Game::killEnemyAt(int32_t col, int32_t row) {
	Game::cellObjects[col][row] = Game::cellObjects[col][row] & 268435455 | 268435456;
	this->progressGateObjective();
}

void Game::updateSideRoller() {
	int32_t col = 0, row = 0, state = 0, waitTimer = 0, dir = 0, moveOffset = 0, newCol = 0, newRow = 0, s1 = 0, s2 = 0;
	Ref<Object> s0_o;
	col = this->updateCellCol;
	row = this->updateCellRow;
	state = Game::cellStates[col][row];
	waitTimer = (state & 65280) >> 8;
	dir = (state & 8) == 0 ? 2 : 4;
	if (waitTimer < 20) {
		{
			if (waitTimer > 0) {
				Game::cellStates[col][row] = state & -65281 | waitTimer - 1 << 8;
				s0_o = Game::cellUpdateTimers[col];
				s1 = row;
				s2 = 24;
				cast<Array<int8_t>>(s0_o)[s1] = s2;
				goto B2_end;
			}
			moveOffset = Game::cellMoveOffsets[col][row];
			if (moveOffset > 0) {
				s0_o = Game::cellMoveOffsets[col];
				s1 = row;
				s2 = (int8_t)(moveOffset - 6);
				cast<Array<int8_t>>(s0_o)[s1] = s2;
			} else {
				newCol = col;
				newRow = row;
				if (!Game::isCellFreeForEnemy(col, row + 1)) {
					if (dir != 4) {
						if (!Game::isCellFreeForEnemy(col + 1, row)) {
							dir = 0;
							if (Game::cellTypes[col + 1][row] != 16 && Game::cellTypes[col + 1][row] != 19 && Game::cellTypes[col + 1][row] != 43) {
								state = state & -65281 | 5120;
							}
						} else {
							newCol = col + 1;
						}
					} else {
						if (!Game::isCellFreeForEnemy(col - 1, row)) {
							dir = 0;
							if (Game::cellTypes[col - 1][row] != 16 && Game::cellTypes[col - 1][row] != 19 && Game::cellTypes[col - 1][row] != 43) {
								state = state & -65281 | 5120;
							}
						} else {
							newCol = col - 1;
						}
					}
				} else {
					newRow = row + 1;
					dir = 3;
				}
				if (newCol != col || newRow != row) {
					Game::cellTypes[newCol][newRow] = 14;
					Game::wakeCellsAround(newCol, newRow);
					Game::cellTypes[col][row] = -1;
					Game::cellMoveOffsets[newCol][newRow] = 18;
				}
				Game::cellStates[newCol][newRow] = state & -8 | dir;
			}
		}
		B2_end:;
	} else {
		if (Game::isCellFreeForEnemy(col, row + 1) || dir == 4 && (Game::cellTypes[col - 1][row] < 0 || Game::cellTypes[col - 1][row] == 16 || Game::cellTypes[col - 1][row] == 19 || Game::cellTypes[col - 1][row] == 43) || dir == 2 && (Game::cellTypes[col + 1][row] < 0 || Game::cellTypes[col + 1][row] == 16 || Game::cellTypes[col + 1][row] == 19 || Game::cellTypes[col + 1][row] == 43)) {
			Game::cellStates[col][row] = state & -65281 | 4864;
		}
	}
	if (this->isPlayerAt(col, row)) {
		this->damageExplorer(1, 48, dir);
	}
}

void Game::updateTallStrikerEnemy() {
	int32_t col = 0, row = 0, lowerHalfDy = 0, upperHalfDy = 0, attackTimer = 0, state = 0, facingDir = 0, explorerInFront = 0, s0 = 0;
	col = this->updateCellCol;
	row = this->updateCellRow;
	if (Game::cellTypes[col][row + 1] == 16) {
		lowerHalfDy = 1;
		s0 = 0;
	} else {
		lowerHalfDy = 0;
		s0 = -1;
	}
	upperHalfDy = s0;
	attackTimer = Game::cellMoveOffsets[col][row + lowerHalfDy];
	state = Game::cellStates[col][row + lowerHalfDy];
	s0 = (state & 7) != 4 ? 2 : 4;
	facingDir = s0;
	s0 = this->isPlayerAt(col - Game::dirDeltas[facingDir], row + lowerHalfDy) || this->isPlayerAt(col - Game::dirDeltas[facingDir], row + upperHalfDy) ? 1 : 0;
	explorerInFront = s0;
	if (attackTimer > 0 || explorerInFront == 0 || this->playerStep > 12) {
		if (attackTimer > 0) {
			if (lowerHalfDy == 0) {
				attackTimer = (int8_t)(attackTimer - 1);
			}
			if ((attackTimer == 11 || lowerHalfDy == 0 && attackTimer < 11) && explorerInFront != 0) {
				this->damageExplorer(1, 48, state & 7);
			}
			Game::cellUpdateTimers[col][row] = 24;
		}
	} else {
		attackTimer = 36;
	}
	if (!this->isCellCrushed(col, row)) {
		Game::cellStates[col][row + upperHalfDy] = state;
		Game::cellStates[col][row + lowerHalfDy] = state;
		if (lowerHalfDy == 0) {
			Game::cellMoveOffsets[col][row + upperHalfDy] = attackTimer;
			Game::cellMoveOffsets[col][row + lowerHalfDy] = attackTimer;
		}
		return;
	}
	this->playSound(14);
	Game::cellTypes[col][row + upperHalfDy] = -1;
	this->killEnemyAt(col, row + upperHalfDy);
	Game::cellTypes[col][row + lowerHalfDy] = -1;
	this->killEnemyAt(col, row + lowerHalfDy);
}

void Game::updateExtendingTrap() {
	int32_t state = 0, dirSign = 0, segments = 0, tipRow = 0;
	state = Game::cellStates[this->updateCellCol][this->updateCellRow];
	dirSign = (state & 7) != 3 ? -1 : 1;
	segments = (state & 8) != 0 ? this->pistonFastSegments : this->pistonSlowSegments;
	tipRow = this->updateCellRow + (segments - 1) * dirSign;
	if (this->isPlayerAt(this->updateCellCol, tipRow)) {
		this->damageExplorer(2, 48, Game::oppositeDir[this->explorerStateFlags & 7]);
	}
	switch (Game::cellTypes[this->updateCellCol][tipRow]) {
		default:
			this->killEnemyAt(this->updateCellCol, tipRow);
			Game::cellTypes[this->updateCellCol][tipRow] = -1;
			Game::wakeCellsAround(this->updateCellCol, tipRow);
			this->eraseCellInBuffer(this->updateCellCol, tipRow);
			break;
		case -1:
		case 28:
		case 32:
			break;
	}
	Game::cellUpdateTimers[this->updateCellCol][this->updateCellRow] = 24;
}

void Game::tryStartDoorUnlock() {
	int32_t col = 0, row = 0, param = 0, lockType = 0, explorerAnim = 0, s1 = 0;
	col = this->updateCellCol;
	row = this->updateCellRow;
	param = Game::cellObjects[col][row] >> 8;
	lockType = Game::cellObjects[col][row] & 255;
	if ((param & 256) == 0 && (lockType == 9 && this->goldKeys > 0 || lockType == 8 && this->silverKeys > 0) && this->playerRow == row && (this->playerCol == col - 1 || this->playerCol == col + 1)) {
		explorerAnim = Game::actors[0]->animIndex;
		if (explorerAnim != 18 && explorerAnim != 17 && this->playerStep <= 6) {
			this->requestedMoveDir = 0;
			this->currentMoveDir = 0;
			if (this->playerCol != col - 1) {
				this->explorerStateFlags = this->explorerStateFlags & -8 | 4;
				s1 = 17;
			} else {
				this->explorerStateFlags = this->explorerStateFlags & -8 | 2;
				s1 = 18;
			}
			cast<Game>(this)->setExplorerAnim(s1);
			if (lockType != 9) {
				s1 = 25;
			} else {
				s1 = 24;
			}
			cast<Game>(this)->heldItemImageSet = s1;
			this->heldItemFrame = 0;
		}
	}
}

void Game::updateDoorOpening() {
	int32_t col = 0, row = 0, param = 0, openStep = 0, aboveObject = 0, aboveParam = 0;
	col = this->updateCellCol;
	row = this->updateCellRow;
	param = Game::cellObjects[col][row] >> 8;
	openStep = (param & 240) >> 4;
	if (openStep != 0) {
		if (Game::frameCount % 3 == 0 && openStep < 3) {
			param = param & -241 | openStep + 1 << 4;
			if (openStep == 2) {
				aboveObject = Game::cellObjects[col][row - 1] & 255;
				if (aboveObject == 9 || aboveObject == 8) {
					aboveParam = Game::cellObjects[col][row - 1] >> 8;
					aboveParam = aboveParam & -513;
					Game::cellObjects[col][row - 1] = aboveParam << 8 | aboveObject;
				}
				this->propagateLockFlag(col, row - 1, 1, 0, 0);
				this->propagateLockFlag(col, row - 1, -1, 0, 0);
			}
			Game::cellUpdateTimers[col][row] = 24;
		}
		Game::cellObjects[col][row] = param << 8 | 7;
	}
}

void Game::updateProximityAnimTile() {
	int32_t col = 0, row = 0, animStep = 0;
	col = this->updateCellCol;
	row = this->updateCellRow;
	animStep = Game::cellObjects[col][row] >> 8;
	if (animStep >= 6) {
		Game::cellUpdateTimers[col][row] = 0;
		return;
	}
	switch (animStep) {
		default:
			if ((Game::frameCount & 1) == 0) {
				animStep++;
			}
			break;
		case 2:
			switch (this->currentMoveDir) {
				case 4:
					if (this->isPlayerAt(col - 1, row)) {
						animStep = 3;
					}
					break;
				case 3:
					{
						if (this->isPlayerAt(col, row + 1)) {
							animStep = 3;
							goto B6_end;
						}
					}
					B6_end:;
					break;
				case 2:
					{
						if (this->isPlayerAt(col + 1, row)) {
							animStep = 3;
							goto B7_end;
						}
					}
					B7_end:;
					break;
				case 1:
					{
						if (this->isPlayerAt(col, row - 1)) {
							animStep = 3;
							goto B8_end;
						}
					}
					B8_end:;
					break;
				default:
					break;
			}
			break;
		case 0:
		case 1:
			break;
		case -1:
			if (JMath::abs(this->playerCol - col) < 4 && JMath::abs(this->playerRow - row) < 4) {
				animStep = 3;
			}
			break;
	}
	Game::cellUpdateTimers[col][row] = 24;
	Game::cellObjects[col][row] = animStep << 8 | 3;
}

void Game::updateChest(int32_t chestType) {
	int32_t col = 0, row = 0, lidFrame = 0, s1 = 0;
	col = this->updateCellCol;
	row = this->updateCellRow;
	lidFrame = Game::cellObjects[col][row] >> 8;
	Game::cellObjects[col][row] = lidFrame << 8 | chestType;
	if (Game::cellMoveOffsets[col][row] <= 0) {
		if (lidFrame != 0) {
			if ((Game::frameCount >> 1 & 1) == 0 && Game::spritePacks[chestType != 14 ? 22 : 8] != nullptr && lidFrame < Game::spritePacks[chestType != 14 ? 22 : 8]->getAnimFrameCount(0) - 1) {
				Game::cellObjects[col][row] = lidFrame + 1 << 8 | chestType;
				Game::cellUpdateTimers[col][row] = 24;
			}
		} else {
			if (this->isPlayerAt(col, row) && this->playerStep <= 0) {
				this->explorerStateFlags = this->explorerStateFlags & -2049;
				Game::cellObjects[col][row] = 256 | chestType;
				if (JMath::abs(this->lastLeverAnimTime - JSystem::currentTimeMillis()) < 5000LL) {
					s1 = 48;
				} else {
					s1 = 40;
				}
				cast<Game>(this)->setExplorerAnim(s1);
				this->playSound(3);
				return;
			}
		}
	}
}

bool Game::isCellCrushed(int32_t col, int32_t row) {
	int32_t aboveRow = 0, leftCol = 0, rightCol = 0;
	aboveRow = row - 1;
	leftCol = col - 1;
	rightCol = col + 1;
	if ((Game::cellMoveOffsets[col][aboveRow] > 6 || (!Game::isHeavyObject(col, aboveRow) || (Game::cellStates[col][aboveRow] & 7) != 3 && (Game::cellTypes[col][row] == 16 || Game::cellTypes[col][aboveRow] == 1)) && Game::cellTypes[col][aboveRow] != 46 && Game::cellTypes[col][aboveRow] != 14 && Game::cellTypes[col][aboveRow] != 48) && (Game::cellMoveOffsets[rightCol][row] > 0 || Game::cellTypes[rightCol][row] != 14 || (Game::cellStates[rightCol][row] & 8) == 0 || (Game::cellStates[rightCol][row] & 7) == 3) && (Game::cellMoveOffsets[leftCol][row] > 0 || Game::cellTypes[leftCol][row] != 14 || (Game::cellStates[leftCol][row] & 8) != 0 || (Game::cellStates[leftCol][row] & 7) == 3)) {
		return 0;
	}
	return 1;
}

bool Game::isHeavyObject(int32_t col, int32_t row) {
	if (Game::cellTypes[col][row] >= 0) {
		switch (Game::cellTypes[col][row]) {
			case 0:
			case 1:
			case 8:
			case 9:
				return 1;
			default:
				return 0;
		}
	}
	return 0;
}

void Game::wakeCellsAround(int32_t col, int32_t row) {
	int32_t leftCol = 0, rightCol = 0, topRow = 0, bottomRow = 0;
	leftCol = col - 1;
	rightCol = col + 1;
	topRow = row - 1;
	bottomRow = row + 1;
	Game::cellUpdateTimers[leftCol][topRow] = 48;
	Game::cellUpdateTimers[col][topRow] = 48;
	Game::cellUpdateTimers[rightCol][topRow] = 48;
	Game::cellUpdateTimers[leftCol][row] = 48;
	Game::cellUpdateTimers[col][row] = 48;
	Game::cellUpdateTimers[rightCol][row] = 48;
	Game::cellUpdateTimers[leftCol][bottomRow] = 48;
	Game::cellUpdateTimers[col][bottomRow] = 48;
	Game::cellUpdateTimers[rightCol][bottomRow] = 48;
}

void Game::saveCheckpoint() {
	int32_t col = 0;
	this->checkpointSwimFlag = Game::saveData[10];
	this->checkpointLeverDir = this->leverMoveDir;
	this->checkpointLeverPos = this->switchWallsPhase;
	this->checkpointDiamondsToOpenExit = this->diamondsToOpenExit;
	this->checkpointNextIndex = this->nextCheckpointIndex;
	this->checkpointDiamonds = this->diamondCount;
	this->checkpointRedDiamonds = this->redDiamondCount;
	this->checkpointCol = this->playerCol;
	this->checkpointRow = this->playerRow;
	this->checkpointGoldKeys = this->goldKeys;
	this->checkpointSilverKeys = this->silverKeys;
	this->checkpointEntryWalk = this->entryWalkRemaining;
	this->checkpointRedDiamondPickCount = this->redDiamondPickCount;
	this->checkpointRisingHazardPhase = this->floodTriggerStage;
	this->checkpointRisingHazardHeight = this->floodHeight;
	Game::checkpointGateId = Game::activeGateId;
	if (Game::gateRemainingCounts != nullptr) {
		JSystem::arraycopy(Game::gateRemainingCounts, 0, Game::checkpointGateCounts, 0, Game::gateRemainingCounts->length);
	}
	for (col = 0; col < this->levelW; col++) {
		JSystem::arraycopy(Game::cellStates[col], 0, Game::checkpointCellStates[col], 0, this->levelH);
		JSystem::arraycopy(Game::cellMoveOffsets[col], 0, Game::checkpointCellMoveOffsets[col], 0, this->levelH);
		JSystem::arraycopy(Game::cellTypes[col], 0, Game::checkpointCellTypes[col], 0, this->levelH);
		JSystem::arraycopy(Game::cellObjects[col], 0, Game::checkpointCellObjects[col], 0, this->levelH);
	}
	this->saveLiquidCheckpoint();
}

void Game::restoreCheckpoint() {
	int32_t index = 0, row = 0, innerCol = 0, col = 0, cellType = 0, cellObject = 0, s1 = 0;
	Ref<Object> s0;
	Game::bufLeftX = -1;
	this->heldItemAmount = -1;
	this->heldItemFrame = -1;
	this->heldItemImageSet = -1;
	this->slidingObjCol = 0;
	this->slidingObjRow = 0;
	this->respawnPanActive = 1;
	this->camPanTargetX = this->checkpointCol * 24 - 120;
	this->camPanTargetY = this->checkpointRow * 24 - 160 + 40;
	this->deathLetterboxHeight = 0;
	if (!this->introTrigger13Reached) {
		if (this->introTrigger16Reached) {
			this->pendingCutsceneId = 17;
			this->introTrigger16Reached = 0;
			Game::checkpointCellObjects[46][7] = -1;
			s0 = Game::checkpointCellObjects[50];
			s1 = 7;
			cast<Array<int32_t>>(s0)[s1] = -1;
		}
	} else {
		this->pendingCutsceneId = 15;
		this->introTrigger13Reached = 0;
		Game::checkpointCellObjects[37][7] = -1;
		s0 = Game::checkpointCellObjects[39];
		s1 = 5;
		cast<Array<int32_t>>(s0)[s1] = -1;
	}
	this->introHintIconVisible = 0;
	this->playerIdleCountdown = 70;
	Game::saveData[10] = this->checkpointSwimFlag;
	this->diamondsToOpenExit = this->checkpointDiamondsToOpenExit;
	this->leverMoveDir = this->checkpointLeverDir;
	this->switchWallsPhase = this->checkpointLeverPos;
	this->nextCheckpointIndex = this->checkpointNextIndex;
	this->redDiamondCount = this->checkpointRedDiamonds;
	this->diamondCount = this->checkpointDiamonds;
	Game::actors[0]->setAnimation(2);
	this->explorerStateFlags = 2;
	this->shakeTime = 0;
	this->playerCol = this->checkpointCol;
	this->playerRow = this->checkpointRow;
	this->goldKeys = this->checkpointGoldKeys;
	this->silverKeys = this->checkpointSilverKeys;
	this->redDiamondPickCount = this->checkpointRedDiamondPickCount;
	switch (this->specialStageType) {
		case 5:
			this->initKnightBossStage();
			break;
		case 4:
			this->bossState = 0;
			this->anacondaHoleIndex = 0;
			this->bossHealth = 3;
			this->anacondaSlamVisible = 0;
			break;
		case 3:
			this->bossHealth = 5;
			break;
		case 1:
			this->floodHeight = this->checkpointRisingHazardHeight;
			this->floodTriggerStage = this->checkpointRisingHazardPhase;
			break;
		default:
			break;
	}
	Game::activeGateId = Game::checkpointGateId;
	if (Game::gateRemainingCounts != nullptr) {
		JSystem::arraycopy(Game::checkpointGateCounts, 0, Game::gateRemainingCounts, 0, Game::gateRemainingCounts->length);
	}
	for (index = 0; index < this->levelW; index++) {
		JSystem::arraycopy(Game::checkpointCellStates[index], 0, Game::cellStates[index], 0, this->levelH);
		JSystem::arraycopy(Game::checkpointCellMoveOffsets[index], 0, Game::cellMoveOffsets[index], 0, this->levelH);
		JSystem::arraycopy(Game::checkpointCellTypes[index], 0, Game::cellTypes[index], 0, this->levelH);
		JSystem::arraycopy(Game::checkpointCellObjects[index], 0, Game::cellObjects[index], 0, this->levelH);
	}
	index = this->levelH - 1;
	for (row = 1; row < index; row++) {
		innerCol = this->levelW - 1;
		for (col = 1; col < innerCol; col++) {
			cellType = Game::cellTypes[col][row];
			cellObject = Game::cellObjects[col][row] & 255;
			if (cellType > -1 && cellType < 80 || cellObject > -1 && cellObject < 80) {
				Game::wakeCellsAround(col, row);
			}
		}
	}
	if (Game::actors[2] != nullptr) {
		Game::actors[2]->setAnimation(0);
		Game::cellTypes[18][63] = -1;
	}
	this->entryWalkRemaining = this->checkpointEntryWalk;
	this->requestHudRedraw();
	if (this->hasWaterLayer) {
		this->restoreLiquidCheckpoint();
	}
	if (Game::freezeRays != nullptr) {
		for (row = 0; row < this->levelH; row++) {
			for (innerCol = 0; innerCol < this->levelW; innerCol++) {
				if (Game::cellTypes[innerCol][row] == 48) {
					this->updateCellCol = innerCol;
					this->updateCellRow = row;
					if ((Game::cellStates[innerCol][row] & 8) != 0) {
						this->updateFreezeRay();
					} else {
						this->updateTallObjectFall(48);
					}
				}
			}
		}
	}
}

void Game::setCellTypeAndState(int16_t col, int16_t row, int8_t cellType, int32_t state) {
	Game::cellTypes[col][row] = cellType;
	Game::cellStates[col][row] = state;
}

bool Game::isWithinCellOverlap(int32_t ax, int32_t ay, int32_t bx, int32_t by) {
	if (JMath::abs(ax - bx) >= 24 || JMath::abs(ay - by) >= 24) {
		return 0;
	}
	return 1;
}

bool Game::doMovingCellsTouch(int32_t colA, int32_t rowA, int32_t dirA, int32_t offsetA, int32_t colB, int32_t rowB, int32_t dirB, int32_t offsetB) {
	Game::hitTestAY = 0;
	Game::hitTestAX = 0;
	Game::hitTestBY = 100;
	Game::hitTestBX = 100;
	if (JMath::abs(colA - colB) > 1 || JMath::abs(rowA - rowB) > 1) {
		return 0;
	}
	Game::hitTestAX = colA * 24 + Game::dirDeltas[dirA] * offsetA;
	Game::hitTestAY = rowA * 24 + Game::dirDeltas[8 + dirA] * offsetA;
	Game::hitTestBX = colB * 24 + Game::dirDeltas[dirB] * offsetB;
	Game::hitTestBY = rowB * 24 + Game::dirDeltas[8 + dirB] * offsetB;
	return Game::isWithinCellOverlap(Game::hitTestAX, Game::hitTestAY, Game::hitTestBX, Game::hitTestBY);
}

void Game::updateFallingObject() {
	int32_t col = 0, inLiquid = 0, dir = 0, explorerMoveDir = 0, touchesExplorer = 0, isInBubble = 0, belowType = 0, sideDx = 0, sideDy = 0, liquidFlag = 0, restKind = 0, row = 0, squashFrame = 0, offset = 0, state = 0, cellType = 0, vertDir = 0, fallDir = 0, nextRow = 0, s0 = 0, s1 = 0, t7 = 0;
	col = this->updateCellCol;
	row = this->updateCellRow;
	offset = Game::cellMoveOffsets[col][row];
	state = Game::cellStates[col][row];
	cellType = Game::cellTypes[col][row];
	s0 = Game::liquidCells == nullptr || Game::liquidCells[col][row] == 0 ? 0 : 1;
	inLiquid = s0;
	dir = state & 7;
	if (inLiquid == 0 || Game::liquidCells[col][row] == 3) {
		vertDir = 1;
		fallDir = 3;
		s0 = row + 1;
	} else {
		vertDir = -1;
		fallDir = 1;
		s0 = row - 1;
	}
	nextRow = s0;
	s0 = (this->explorerStateFlags & 4096) != 0 ? 0 : (this->currentMoveDir);
	explorerMoveDir = s0;
	touchesExplorer = Game::doMovingCellsTouch(col, row, dir, offset, this->playerCol, this->playerRow, explorerMoveDir, this->playerStep);
	if (cellType != 1 || touchesExplorer == 0) {
		s0 = (Game::cellObjects[col][row] & 255) != 35 ? 0 : 1;
		isInBubble = s0;
		belowType = Game::cellTypes[col][nextRow];
		if (belowType == 9 && offset <= 0) {
			sideDx = (int8_t)(Game::cellObjects[col][nextRow] & 255);
			sideDy = (Game::cellStates[col][nextRow] & 264241152) >> 22;
			if (sideDy != 34) {
				if (sideDy != 33) {
					if (Game::cellTypes[col][nextRow] == 19 || Game::cellTypes[col][nextRow] == 43 || Game::cellTypes[col][nextRow] == 45 || Game::cellTypes[col][nextRow] == 46 || Game::cellTypes[col][nextRow] == 49 || Game::cellTypes[col][nextRow] == 11) {
						Game::cellTypes[col][nextRow] = -1;
						this->killEnemyAt(col, nextRow);
					}
				} else {
					if (sideDx == -1) {
						Game::cellObjects[col][nextRow] = 32;
					}
					this->playerCol = col;
					this->playerRow = nextRow;
					Game::cellTypes[col][nextRow] = -1;
					this->playerStep = 0;
					this->encasedStruggleCount = 0;
					this->damageExplorer(2, 48, 0);
				}
			}
		}
		if (offset > 0 || isInBubble != 0) {
			if (isInBubble == 0) {
				if ((state & 512) != 0) {
					sideDx = 0;
					sideDy = 0;
					if (dir != 4) {
						if (dir == 2) {
							s0 = 1;
							sideDx = s0;
						}
					} else {
						s0 = -1;
						sideDx = s0;
					}
					if (!Game::isCellFreeForObject(col, nextRow) || this->isPlayerAt(col, nextRow)) {
						if (!Game::isCellFreeForObject(col + sideDx, row) || this->isPlayerAt(col + sideDx, row) || !Game::isCellFreeForObject(col + sideDx, nextRow) || this->isPlayerAt(col + sideDx, nextRow) || (Game::cellStates[col][nextRow] & 512) != 0) {
							offset = (int8_t)(offset - 6);
							if (offset <= 0) {
								offset = 0;
								state = state & -513;
								state = state & -8 | 0;
							}
							Game::cellMoveOffsets[col][row] = offset;
							Game::cellStates[col][row] = state;
							Game::cellUpdateTimers[col][row] = 24;
							this->redrawCellInBuffer(col, row);
						} else {
							if (offset >= 6 || (Game::frameCount & 3) == 0) {
								offset = (int8_t)(offset + 1);
							}
							if (offset < 12) {
								Game::cellMoveOffsets[col][row] = offset;
								Game::cellStates[col][row] = state;
								Game::cellUpdateTimers[col][row] = 24;
							} else {
								state = state & -513;
								if (sideDx == 0) {
									state = state & -8 | 0;
									offset = 0;
								} else {
									offset = 6;
									Game::cellTypes[col][row] = -1;
									if (Game::isCellFreeForObject(col + sideDx, nextRow)) {
										offset = 12;
										state = state & -8 | fallDir;
										sideDy = vertDir;
									}
								}
								Game::cellStates[col + sideDx][row + sideDy] = state | INT32_MIN;
								Game::cellMoveOffsets[col + sideDx][row + sideDy] = offset;
								Game::cellTypes[col + sideDx][row + sideDy] = cellType;
								Game::wakeCellsAround(col, row);
								Game::cellUpdateTimers[col][row + 2 * vertDir] = 24;
							}
						}
					} else {
						offset = (int8_t)(offset - 6);
						if (offset <= 0) {
							offset = 0;
							state = state & -513;
							state = state & -8 | 0;
						}
						Game::cellMoveOffsets[col][row] = offset;
						Game::cellStates[col][row] = state;
						Game::cellUpdateTimers[col][row] = 24;
					}
				} else {
					if (dir != 3 || (Game::cellObjects[col][row] & 255) != 6 || offset > 12) {
						offset = (int8_t)(offset - 6);
					} else {
						offset = (int8_t)(offset - (Game::frameCount & 1));
						Game::cellUpdateTimers[col][row] = 24;
					}
					if (offset == 0 || offset == 12) {
						switch (state & 3072) {
							case 2048:
								s0 = state & -57;
								s1 = state - 8;
								state = s0 | s1 & 56;
								break;
							case 1024:
								s0 = state & -57;
								s1 = state + 8;
								state = s0 | s1 & 56;
								break;
							default:
								break;
						}
						if (offset == 0) {
							if ((Game::cellObjects[col][row] & 255) == 6) {
								state = state & -449;
							}
							if (dir == fallDir) {
								if ((cellType == 0 || cellType == 9) && vertDir > 0 && !Game::isCellFreeForObject(col, row + 1)) {
									Game::vibrateDevice(200);
									this->playSound(14);
									this->shakeTime = 10;
									if (cellType == 9 && this->encasedStruggleCount > 0 && this->isPlayerAt(col, row)) {
										this->damageExplorer(1, 0, 0);
										this->requestHudRedraw();
									}
									sideDx = Game::isHeavyObject(col, row + 1);
									if (!sideDx) {
										state = state & -449 | 64;
									}
								}
								Game::cellUpdateTimers[col][row] = 30;
								if (!this->isPlayerAt(col, nextRow)) {
									state = state & -8 | 0;
								}
							}
						}
					}
					Game::cellMoveOffsets[col][row] = offset;
					Game::cellStates[col][row] = state;
				}
			}
		} else {
			if (dir != fallDir || !this->isPlayerAt(col, nextRow) || !Game::isCellFreeForObject(col, nextRow)) {
				if ((Game::isCellFreeForObject(col, nextRow) || Game::cellTypes[col][nextRow] == 21) && (!this->isPlayerAt(col, row) || this->encasedStruggleCount > 0) && (!this->isPlayerAt(col, nextRow) && !Game::isWithinCellOverlap(Game::hitTestAX, Game::hitTestAY, Game::hitTestBX, Game::hitTestBY - 1) || this->encasedStruggleCount > 0 || this->deathTimer != 0 || cellType != 0 && dir == fallDir)) {
					if (vertDir > 0 || Game::liquidCells != nullptr && Game::liquidCells[col][nextRow] != 0) {
						state = state + 131072;
						state = state & -8 | fallDir;
						Game::cellStates[col][nextRow] = state | INT32_MIN;
						Game::cellMoveOffsets[col][nextRow] = 18;
						Game::cellTypes[col][nextRow] = cellType;
						Game::cellTypes[col][row] = -1;
						Game::wakeCellsAround(col, row);
						Game::cellUpdateTimers[col][row + 2 * vertDir] = 24;
						this->eraseCellInBuffer(col, row);
					} else {
						state = state & -4063240 | 0;
						Game::cellStates[col][row] = state;
						Game::cellMoveOffsets[col][nextRow] = 0;
					}
				} else {
					if (!Game::isHeavyObject(col, nextRow)) {
						if (cellType != 8) {
							state = state & -3073 | 0;
							state = state & -4063233;
							state = state & -8;
							Game::cellStates[col][row] = state;
						} else {
							sideDx = (state & 4063232) >> 17;
							if (sideDx < 2) {
								state = state & -4063233;
							} else {
								Game::cellTypes[col][row] = 54;
								Game::cellStates[col][row] = 0;
								Game::wakeCellsAround(col, row);
								return;
							}
						}
					} else {
						if (vertDir >= 0 || Game::liquidCells != nullptr && Game::liquidCells[col][nextRow] != 0 || Game::cellTypes[col][row + 1] >= 0) {
							if (Game::cellMoveOffsets[col][nextRow] <= 0) {
								sideDx = (state & 4063232) >> 17;
								if (sideDx >= 2) {
									if (cellType == 8) {
										Game::cellTypes[col][row] = 54;
										Game::cellStates[col][row] = 0;
										Game::wakeCellsAround(col, row);
										return;
									}
									if (Game::cellTypes[col][nextRow] == 8) {
										Game::cellTypes[col][nextRow] = 54;
										Game::cellStates[col][nextRow] = 0;
										Game::wakeCellsAround(col, nextRow);
										return;
									}
								}
								state = state & -4063233;
								if (!Game::isCellFreeForObject(col - 1, row) || !Game::isCellFreeForObject(col - 1, nextRow) || this->isPlayerAt(col - 1, row)) {
									if (Game::isCellFreeForObject(col + 1, row) && Game::isCellFreeForObject(col + 1, nextRow) && !this->isPlayerAt(col + 1, row)) {
										Game::cellMoveOffsets[col][row] = (int8_t)(((state & 28672) >> 12) + 1);
										Game::cellUpdateTimers[col][row] = 24;
										state = state & -8 | 2;
										s0 = state & -3073;
										s1 = 1024;
										t7 = s0 | s1;
										state = t7;
										state = state | 512;
									}
								} else {
									Game::cellMoveOffsets[col][row] = (int8_t)(((state & 28672) >> 12) + 1);
									Game::cellUpdateTimers[col][row] = 24;
									state = state & -8 | 4;
									s0 = state & -3073;
									s1 = 2048;
									t7 = s0 | s1;
									state = t7;
									state = state | 512;
								}
								Game::cellStates[col][row] = state;
							}
						} else {
							Game::cellStates[col][row + 1] = state & -8 | 3;
							Game::cellStates[col][row + 1] = Game::cellStates[col][row + 1] | INT32_MIN;
							Game::cellTypes[col][row + 1] = cellType;
							Game::cellMoveOffsets[col][row + 1] = 18;
							Game::cellTypes[col][row] = -1;
						}
					}
				}
			} else {
				if ((cellType == 0 || cellType == 9) && vertDir > 0) {
					this->damageExplorer(2, 48, 0);
				} else {
					if (cellType != 1) {
						if (cellType == 8) {
							state = state & -4063233;
						}
					} else {
						Game::cellStates[col][nextRow] = state & -8 | 3;
						Game::cellMoveOffsets[col][nextRow] = 18;
						Game::cellTypes[col][nextRow] = 1;
						Game::cellTypes[col][row] = -1;
						this->eraseCellInBuffer(col, row);
					}
				}
				Game::cellStates[col][row] = state & -8 | 0;
			}
		}
		sideDx = state & 536870912;
		sideDy = Game::cellMoveOffsets[col][row];
		liquidFlag = state & 1073741824;
		restKind = 0;
		if (sideDx == 0 && sideDy != 0 || liquidFlag == 0 && inLiquid != 0) {
			this->eraseCellInBuffer(col, row);
		}
		if (sideDx != 0 && sideDy == 0 || liquidFlag != 0 && inLiquid == 0) {
			this->redrawCellInBuffer(col, row);
		}
		if ((state & 512) == 0) {
			if (sideDy != 0 || sideDx != 0) {
				s0 = 2;
			} else {
				if (inLiquid == 0) {
					if (Game::cellObjects[col][row] <= -1 || Game::cellObjects[col][row] >= 38) {
						s0 = (Game::isCellFreeForObject(col - 1, row) || Game::isCellFreeForObject(col + 1, row)) && Game::isHeavyObject(col, row + 1) && (Game::cellStates[col][row + 1] & 7) == 0 && col != this->slidingObjCol && row != this->slidingObjRow ? 6 : 0;
					} else {
						s0 = 4;
					}
				} else {
					s0 = 3;
				}
			}
		} else {
			s0 = 1;
		}
		restKind = s0;
		state = state & -536870913 | (sideDy == 0 ? 0 : 536870912);
		state = state & -1073741825 | (inLiquid == 0 ? 0 : 1073741824);
		s0 = state & 2147483647;
		s1 = restKind == 0 ? 0 : INT32_MIN;
		state = s0 | s1;
		Game::cellStates[col][row] = state;
		squashFrame = ((Game::cellStates[col][row] & 448) >> 6) - 1;
		if (squashFrame >= 0 && squashFrame < 5) {
			Game::cellStates[col][row] = Game::cellStates[col][row] & -449 | Game::cellStates[col][row] + 64 & 448;
		}
		return;
	}
	this->collectDiamondAt(col, row);
}

void Game::collectDiamondAt(int32_t col, int32_t row) {
	this->spawnCellEffect(col, row, 3);
	this->diamondCount = this->diamondCount + 1;
	Game::cellTypes[col][row] = -1;
	this->diamondsToOpenExit = this->diamondsToOpenExit - 1;
	this->slideCellsLeft = 0;
	if (this->diamondsToOpenExit == 0) {
		Game::cellTypes[this->exitDoorCol][this->exitDoorRow] = -1;
	}
	if (Game::cellTypes[col][row - 1] == -1) {
		this->eraseCellInBuffer(col, row - 1);
	}
	this->eraseCellInBuffer(col, row);
	this->requestHudRedraw();
}

Ref<SpritePack> Game::loadSpritePackPalettes(Ref<String> path, int32_t index, int32_t firstPalette, int32_t lastPalette) {
	Ref<SpritePack> pack;
	Arr<int8_t> data;
	int32_t palette = 0;
	Ref<Object> s0;
	pack = nullptr;
	try {
		pack = jnew<SpritePack>()->init();
		data = Game::readResource(path, index);
		pack->loadFromBytes(data, 0);
		for (palette = firstPalette; palette <= lastPalette; palette++) {
			pack->buildModuleImages(palette, 0, -1, -1);
		}
		pack->paletteIndex = firstPalette;
		pack->moduleData = nullptr;
		JSystem::gc();
	} catch (JavaException& ex) {
		if (ex.isa(u"java/lang/Exception")) {
			s0 = ex.ex;
			return pack;
		}
		else throw;
	}
	return pack;
}

Ref<SpritePack> Game::loadSpritePack(Ref<String> path, int32_t index) {
	return Game::loadSpritePackPalette(path, index, 0);
}

Ref<SpritePack> Game::loadSpritePackPalette(Ref<String> path, int32_t index, int32_t palette) {
	return Game::loadSpritePackPalettes(path, index, palette, palette);
}

Arr<Ref<Image>> Game::loadSpriteImages(Ref<String> path, int32_t index) {
	return Game::loadSpriteImagesPalette(path, index, 0);
}

Arr<Ref<Image>> Game::loadSpriteImagesPalette(Ref<String> path, int32_t index, int32_t palette) {
	Ref<SpritePack> pack;
	Arr<int8_t> data;
	Ref<Object> s0;
	pack = nullptr;
	try {
		pack = jnew<SpritePack>()->init();
		data = Game::readResource(path, index);
		pack->loadFromBytes(data, 0);
		pack->buildModuleImages(palette, 0, -1, -1);
		Game::freeSpritePack(pack, 0);
		JSystem::gc();
	} catch (JavaException& ex) {
		if (ex.isa(u"java/lang/Exception")) {
			s0 = ex.ex;
			return pack->moduleImages[palette];
		}
		else throw;
	}
	return pack->moduleImages[palette];
}

Ref<Image> Game::loadPng(Ref<String> path, int32_t index) {
	Ref<Image> image;
	Arr<int8_t> data;
	Ref<Object> s0;
	image = nullptr;
	try {
		data = Game::readResource(path, index);
		image = Image::createImage(data, 0, data->length);
		JSystem::gc();
	} catch (JavaException& ex) {
		if (ex.isa(u"java/lang/Exception")) {
			s0 = ex.ex;
			return image;
		}
		else throw;
	}
	return image;
}

Arr<int8_t> Game::readResource(Ref<String> path, int32_t index) {
	Arr<int8_t> data;
	Ref<InputStream> stream;
	int32_t headerSize = 0, offset = 0, size = 0;
	Ref<Object> s0;
	data = nullptr;
	stream = path->getClass()->getResourceAsStream(path);
	try {
		headerSize = stream->read() << 3;
		data = newArray<int8_t>(headerSize);
		stream->read(data);
		offset = Game::readS32LE(data, index << 3);
		size = Game::readS32LE(data, (index << 3) + 4);
		stream->skip((int64_t)offset);
		data = newArray<int8_t>(size);
		stream->read(data);
		stream->close();
	} catch (JavaException& ex) {
		if (ex.isa(u"java/lang/Exception")) {
			s0 = ex.ex;
			return data;
		}
		else throw;
	}
	return data;
}

void Game::loadCharMap() {
	Ref<InputStream> stream;
	Ref<Object> s0;
	if (SpritePack::charMap != nullptr) {
		return;
	}
	stream = this->getClass()->getResourceAsStream(u"/mc"_j);
	SpritePack::charMap = newArray<int8_t>(256);
	try {
		stream->read(SpritePack::charMap);
		stream->close();
	} catch (JavaException& ex) {
		if (ex.isa(u"java/lang/Exception")) {
			s0 = ex.ex;
			return;
		}
		else throw;
	}
}

int32_t Game::measureFirstLineWidth(Ref<SpritePack> font, Ref<String> text, int32_t lineMode) {
	int32_t cutIndex = 0;
	if (lineMode != -1) {
		cutIndex = text->indexOf(10);
		if (cutIndex != -1) {
			text = text->substring(0, cutIndex);
		}
	}
	cutIndex = text->indexOf(125);
	if (cutIndex != -1) {
		text = text->substring(0, cutIndex);
	}
	font->measureString(text);
	return SpritePack::textWidth;
}

int32_t Game::getFontLineHeight(Ref<SpritePack> font) {
	return font->lineSpacing + (font->moduleSizes[1] & 255);
}

void Game::setMoreGamesState(int32_t state) {
	MoreGames::state = state;
}

bool Game::updateMoreGamesScreen(Ref<Graphics> g) {
	MoreGames::frameCounter = MoreGames::frameCounter + 1;
	switch (MoreGames::state) {
		case 4:
			Game::setMoreGamesState(0);
			this->moreGamesScreen = nullptr;
			JSystem::gc();
			return 0;
		case 3:
			this->moreGamesScreen->updateAndDraw(g);
			return 1;
		case 2:
			MoreGames::unload();
			this->cleanup();
			Game::screen = 9;
			this->loadingStepCount = 8;
			this->loadingStep = 0;
			return 1;
		case 1:
			MoreGames::loadResources();
			Game::menuRepaintPlayfield = 0;
			return 1;
		case 0:
			this->cleanup();
			this->moreGamesScreen = jnew<MoreGames>()->init();
			this->markMoreGamesSeen();
			this->sound->stop();
			Game::setMoreGamesState(1);
			this->showMoreGamesBadge = 0;
			return 1;
		default:
			return 1;
	}
}

void Game::markMoreGamesSeen() {
	Arr<int8_t> t1;
	if ((Game::prefsData[0] & 1) == 0) {
		this->showMoreGamesBadge = 1;
		t1 = Game::prefsData;
		t1[0] = (int8_t)(t1[0] | 1);
		this->savePreferences();
	}
}

int32_t Game::readUShortLE(Ref<InputStream> stream) {
	return stream->read() & 255 | (stream->read() & 255) << 8;
}

int32_t Game::keyMask(int32_t keyCode) {
	if (keyCode < 0) {
		keyCode = JMath::abs(keyCode);
	}
	switch (keyCode) {
		default:
			return 0;
		case 57:
			return 524288;
		case 56:
			return 262144;
		case 55:
			return 131072;
		case 54:
			return 65536;
		case 53:
			return 32768;
		case 52:
			return 16384;
		case 51:
			return 8192;
		case 50:
			return 4096;
		case 49:
			return 2048;
		case 48:
			return 1024;
		case 42:
			return 256;
		case 35:
			return 512;
		case 23:
			return 128;
		case 7:
			return 64;
		case 6:
			return 32;
		case 5:
			return 16;
		case 4:
			return 8;
		case 3:
			return 4;
		case 2:
			return 2;
		case 1:
			return 1;
	}
}

void Game::saveLiquidCheckpoint() {
	int32_t col = 0;
	if (this->hasWaterLayer) {
		if (Game::savedLiquidCells == nullptr) {
			Game::savedLiquidCells = multiArray<int32_t, 2>(this->levelW, this->levelH);
		}
		for (col = 0; col < this->levelW; col++) {
			JSystem::arraycopy(Game::liquidCells[col], 0, Game::savedLiquidCells[col], 0, this->levelH);
		}
		if (Game::savedLiquidFlows == nullptr) {
			Game::savedLiquidFlows = newArray<int64_t>(15);
		}
		JSystem::arraycopy(Game::liquidFlows, 0, Game::savedLiquidFlows, 0, Game::liquidFlows->length);
		if (Game::savedLiquidEmitters == nullptr) {
			Game::savedLiquidEmitters = newArray<int64_t>(15);
		}
		JSystem::arraycopy(Game::liquidEmitters, 0, Game::savedLiquidEmitters, 0, Game::liquidEmitters->length);
		this->savedLiquidState = this->liquidState;
		this->savedLiquidDrainTick = this->liquidDrainTick;
		this->savedLiquidPoolRiseCount = this->liquidPoolRiseCount;
		this->savedLiquidSpareCounter = this->liquidSpareCounter;
		this->savedLiquidFillTargetSlot = this->liquidFillTargetSlot;
		this->savedLiquidBreachCol = this->liquidBreachCol;
		this->savedLiquidBreachRow = this->liquidBreachRow;
		this->savedLiquidBreachDir = this->liquidBreachDir;
		this->savedLiquidDrainFlow = this->liquidDrainFlow;
		this->savedLiquidDrainStopRow = this->liquidDrainStopRow;
		this->savedLiquidFlowTick = this->liquidFlowTick;
		Game::savedLiquidStartNextEmitter = this->liquidStartNextEmitter;
		this->savedLiquidNextEmitter = this->liquidNextEmitter;
		this->savedLiquidEmitterCount = this->liquidEmitterCount;
		return;
	}
}

void Game::restoreLiquidCheckpoint() {
	int32_t col = 0;
	this->liquidStartNextEmitter = Game::savedLiquidStartNextEmitter;
	this->liquidNextEmitter = this->savedLiquidNextEmitter;
	this->liquidEmitterCount = this->savedLiquidEmitterCount;
	for (col = 0; col < this->levelW; col++) {
		JSystem::arraycopy(Game::savedLiquidCells[col], 0, Game::liquidCells[col], 0, this->levelH);
	}
	JSystem::arraycopy(Game::savedLiquidFlows, 0, Game::liquidFlows, 0, Game::liquidFlows->length);
	JSystem::arraycopy(Game::savedLiquidEmitters, 0, Game::liquidEmitters, 0, Game::liquidEmitters->length);
	this->liquidState = this->savedLiquidState;
	this->liquidDrainTick = this->savedLiquidDrainTick;
	this->liquidPoolRiseCount = this->savedLiquidPoolRiseCount;
	this->liquidSpareCounter = this->savedLiquidSpareCounter;
	this->liquidFillTargetSlot = this->savedLiquidFillTargetSlot;
	this->liquidBreachCol = this->savedLiquidBreachCol;
	this->liquidBreachRow = this->savedLiquidBreachRow;
	this->liquidBreachDir = this->savedLiquidBreachDir;
	this->liquidDrainFlow = this->savedLiquidDrainFlow;
	this->liquidDrainStopRow = this->savedLiquidDrainStopRow;
	this->liquidFlowTick = this->savedLiquidFlowTick;
}

void Game::createLiquidLayer() {
	if (this->hasWaterLayer) {
		this->resetLiquidSimulation();
		Game::liquidCells = multiArray<int32_t, 2>(this->levelW, this->levelH);
		this->registerLiquidEmitters();
	}
}

void Game::resetLiquidSimulation() {
	if (this->hasWaterLayer) {
		Game::liquidFlows = newArray<int64_t>(15);
		Game::savedLiquidFlows = newArray<int64_t>(15);
		Game::liquidEmitters = newArray<int64_t>(15);
		Game::savedLiquidEmitters = newArray<int64_t>(15);
		this->liquidState = 3;
		this->liquidStartNextEmitter = 1;
		this->liquidDrainTick = -1;
		this->liquidPoolRiseCount = 0;
		this->liquidSpareCounter = 0;
		this->liquidFillTargetSlot = 0;
		this->liquidBreachCol = 0;
		this->liquidBreachRow = 0;
		this->liquidBreachDir = 0;
		this->liquidDrainFlow = 0;
		this->liquidDrainStopRow = 0;
		this->liquidFlowTick = -1;
		this->liquidNextEmitter = 0;
		this->liquidEmitterCount = 0;
	}
}

int8_t Game::addLiquidEmitter(int8_t amount, int8_t col, int8_t row, int8_t dir) {
	int32_t slot = 0, s0 = 0;
	s0 = 0;
	while (true) {
		slot = s0;
		if (slot >= 15) {
			break;
		}
		if (Game::getEmitterBits(slot, 0, 4) != 0) {
			s0 = (int8_t)(slot + 1);
			continue;
		}
		break;
	}
	if (slot >= 15) {
		return -1;
	}
	this->setEmitterBits(slot, 1, 0, 4);
	this->setEmitterBits(slot, dir, 4, 2);
	this->setEmitterBits(slot, amount, 6, 7);
	this->setEmitterBits(slot, amount, 27, 7);
	this->setEmitterBits(slot, col, 13, 7);
	this->setEmitterBits(slot, row, 20, 7);
	return slot;
}

int32_t Game::getLiquidBits(int32_t packed, int8_t subSlot, int8_t bitOffset, int8_t bitCount) {
	packed = ushr(packed, subSlot * 9 + bitOffset);
	packed = packed & (shl(-1, bitCount) ^ -1);
	return packed;
}

void Game::setLiquidBits(int32_t col, int32_t row, int8_t subSlot, int8_t value, int8_t bitOffset, int8_t bitCount) {
	int32_t newBits = 0, packed = 0, oldBits = 0, shift = 0;
	packed = Game::liquidCells[col][row];
	oldBits = Game::getLiquidBits(packed, subSlot, bitOffset, bitCount);
	shift = (int8_t)(subSlot * 9 + bitOffset);
	oldBits = shl(oldBits, shift);
	packed = packed ^ oldBits;
	newBits = value;
	newBits = shl(newBits, shift);
	packed = packed | newBits;
	Game::liquidCells[col][row] = packed;
	Game::cellUpdateTimers[col][row] = 24;
	Game::cellUpdateTimers[col][row + 1] = 24;
}

int32_t Game::getFlowBits(int32_t flowNumber, int8_t shift, int8_t bitCount) {
	return (int32_t)(lushr(Game::liquidFlows[flowNumber - 1], shift) & (lshl((-1LL), bitCount) ^ (-1LL)));
}

void Game::setFlowBits(int32_t flowNumber, int8_t value, int8_t shift, int8_t bitCount) {
	int64_t oldBits = 0, packed = 0, newBits = 0;
	oldBits = (int64_t)Game::getFlowBits(flowNumber, shift, bitCount);
	flowNumber--;
	packed = Game::liquidFlows[flowNumber];
	oldBits = lshl(oldBits, shift);
	packed = packed ^ oldBits;
	newBits = (int64_t)value;
	newBits = lshl(newBits, shift);
	packed = packed | newBits;
	Game::liquidFlows[flowNumber] = packed;
}

int32_t Game::getEmitterBits(int8_t emitter, int8_t shift, int8_t bitCount) {
	int64_t packed = 0;
	packed = Game::liquidEmitters[emitter];
	packed = lushr(packed, shift);
	packed = packed & (lshl((-1LL), bitCount) ^ (-1LL));
	return (int32_t)packed;
}

void Game::setEmitterBits(int8_t emitter, int8_t value, int8_t shift, int8_t bitCount) {
	int64_t oldBits = 0, packed = 0;
	int32_t newBits = 0;
	oldBits = (int64_t)Game::getEmitterBits(emitter, shift, bitCount);
	packed = Game::liquidEmitters[emitter];
	oldBits = lshl(oldBits, shift);
	packed = packed ^ oldBits;
	newBits = value;
	newBits = shl(newBits, shift);
	packed = packed | (int64_t)newBits;
	Game::liquidEmitters[emitter] = packed;
}

int8_t Game::findEmitterAt(int32_t col, int32_t row) {
	int32_t slot = 0, s0 = 0;
	s0 = 0;
	while (true) {
		slot = s0;
		if (slot >= 15) {
			return -1;
		}
		if (col != Game::getEmitterBits(slot, 13, 7) || row != Game::getEmitterBits(slot, 20, 7)) {
			s0 = (int8_t)(slot + 1);
			continue;
		}
		break;
	}
	return slot;
}

int8_t Game::setEmitterStateAt(int32_t col, int32_t row, int8_t state) {
	int32_t result = 0, s0 = 0;
	result = this->findEmitterAt(col, row);
	if (result < 0) {
		return -1;
	}
	this->setEmitterBits(result, state, 0, 4);
	switch (state) {
		case 3:
			s0 = 39;
			result = s0;
			break;
		case 2:
			s0 = 39;
			result = s0;
			break;
		case 1:
			s0 = 38;
			result = s0;
			break;
		default:
			break;
	}
	return result;
}

void Game::updateLiquidSimulation() {
	int32_t flowNumber = 0, s0 = 0;
	if (!this->hasWaterLayer) {
		return;
	}
	if (this->liquidDrainTick >= 0 && this->liquidFlowTick >= 0) {
		this->liquidDrainTick = this->liquidDrainTick + 1;
		this->updatePoolDrain();
	}
	switch (this->liquidState) {
		case 5:
			this->startLiquidBreachDrain(this->liquidBreachCol, this->liquidBreachRow);
			return;
		case 4:
			this->spawnErasingStreamsFromEmptySources();
			this->liquidState = 2;
			return;
		case 2:
			s0 = 1;
			while (true) {
				flowNumber = s0;
				if (flowNumber > 15) {
					break;
				}
				switch (Game::getFlowBits(flowNumber, 28, 3)) {
					case 3:
						Game::clearLiquidFlow(flowNumber);
						break;
					case 2:
						if (this->liquidFlowTick >= 0) {
							this->liquidFlowTick = this->liquidFlowTick + 1;
							this->updatePoolFill(flowNumber);
						}
						break;
					case 1:
					case 6:
					case 7:
						this->updateStreamHead(flowNumber);
						break;
					default:
						break;
				}
				s0 = (int8_t)(flowNumber + 1);
			}
			return;
		default:
			return;
		case 1:
			this->liquidState = 2;
			return;
	}
}

void Game::clearLiquidFlow(int8_t flowIndex) {
	Game::liquidFlows[flowIndex - 1] = 0LL;
}

void Game::spawnErasingStreamsFromEmptySources() {
	int32_t emitterIndex = 0, col = 0, row = 0, emitterDir = 0, streamDir = 0, startSlot = 0, s0 = 0;
	s0 = 0;
	while (true) {
		emitterIndex = s0;
		if (emitterIndex >= 15) {
			break;
		}
		if (Game::getEmitterBits(emitterIndex, 0, 4) == 3) {
			col = Game::getEmitterBits(emitterIndex, 13, 7);
			row = Game::getEmitterBits(emitterIndex, 20, 7);
			emitterDir = Game::getEmitterBits(emitterIndex, 4, 2);
			Game::liquidEmitters[emitterIndex] = 0LL;
			streamDir = 0;
			startSlot = 0;
			switch (emitterDir) {
				case 2:
					col--;
					s0 = -1;
					streamDir = s0;
					s0 = 2;
					startSlot = s0;
					break;
				case 1:
					col++;
					s0 = 1;
					streamDir = s0;
					s0 = 2;
					startSlot = s0;
					break;
				case 0:
					row++;
					streamDir = 0;
					s0 = 0;
					startSlot = s0;
					break;
				default:
					break;
			}
			this->spawnLiquidFlow(col, row, 7, streamDir, startSlot, this->findEmitterAt(col, row));
		}
		s0 = (int8_t)(emitterIndex + 1);
	}
}

void Game::updatePoolDrain() {
	int32_t col = 0, row = 0, phase = 0, width = 0, slot = 0, step = 0, nextSlotOrWidth = 0, nextRow = 0, slotGraphic = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, t4 = 0, t5 = 0;
	Ref<Object> s0_o;
	col = Game::getFlowBits(this->liquidDrainFlow, 14, 6);
	row = Game::getFlowBits(this->liquidDrainFlow, 20, 6);
	phase = Game::getFlowBits(this->liquidDrainFlow, 47, 2);
	switch (phase) {
		case 1:
			if (row == this->liquidDrainStopRow) {
				this->liquidDrainTick = -1;
				this->liquidFlowTick = -1;
				Game::clearLiquidFlow(this->liquidDrainFlow);
				this->liquidState = 4;
				return;
			}
			width = (int8_t)Game::getFlowBits(this->liquidDrainFlow, 49, 5);
			if (this->liquidDrainTick != 0 && irem(this->liquidDrainTick, width) == 0) {
				this->liquidDrainTick = 0;
				slot = (int8_t)Game::getFlowBits(this->liquidDrainFlow, 26, 2);
				if (slot >= 0) {
					s0 = 0;
					while (true) {
						step = s0;
						if (step >= width) {
							break;
						}
						Game::clearLiquidSlot(col - step, row, slot);
						nextSlotOrWidth = slot;
						nextRow = row;
						nextSlotOrWidth = (int8_t)(nextSlotOrWidth + 1);
						if (nextSlotOrWidth > 2) {
							nextSlotOrWidth = 0;
							nextRow++;
						}
						slotGraphic = Game::getLiquidBits(Game::liquidCells[col - step][nextRow], nextSlotOrWidth, 3, 4);
						if (nextRow != this->liquidDrainStopRow || slot != 2) {
							if (slotGraphic != 12 && slotGraphic != 9) {
								this->setLiquidBits(col - step, nextRow, nextSlotOrWidth, 7, 3, 4);
							}
						} else {
							if (slotGraphic != 0 && slotGraphic != 3) {
								this->setLiquidBits(col - step, nextRow, nextSlotOrWidth, 7, 3, 4);
							}
						}
						s0 = (int8_t)(step + 1);
					}
					if (slot != 2) {
						t4 = (int8_t)(slot + 1);
						t5 = this->liquidDrainFlow;
						slot = t4;
						s0_o = this;
						s1 = t5;
						s2 = slot;
						s3 = 26;
						s4 = 2;
					} else {
						this->setFlowBits(this->liquidDrainFlow, 0, 47, 2);
						this->setFlowBits(this->liquidDrainFlow, 0, 26, 2);
						row++;
						s0_o = this;
						s1 = this->liquidDrainFlow;
						s2 = (int8_t)row;
						s3 = 20;
						s4 = 6;
					}
					cast<Game>(s0_o)->setFlowBits(s1, s2, s3, s4);
				}
			}
			break;
		case 0:
			this->setFlowBits(this->liquidDrainFlow, 1, 47, 2);
			width = (int8_t)Game::getFlowBits(this->liquidDrainFlow, 49, 5);
			slot = (int8_t)Game::getFlowBits(this->liquidDrainFlow, 45, 2);
			step = 0;
			if (slot == 0) {
				if ((int8_t)(Game::cellTypes[col + 1][row] - 80) >= 0 || Game::cellTypes[col + 1][row] == 10 || Game::cellTypes[col + 1][row] == 37 || Game::cellTypes[col + 1][row] == 34 || Game::cellTypes[col + 1][row] == 35) {
					while (step < width) {
						step++;
						if ((int8_t)(Game::cellTypes[col][row] - 80) >= 0 || Game::cellTypes[col][row] == 10 || Game::cellTypes[col][row] == 37 || Game::cellTypes[col][row] == 34 || Game::cellTypes[col][row] == 35) {
							col--;
						} else {
							step = width;
						}
					}
				} else {
					while ((int8_t)(Game::cellTypes[col + 1][row] - 80) < 0 && Game::cellTypes[col + 1][row] != 10 && Game::cellTypes[col + 1][row] != 37 && Game::cellTypes[col + 1][row] != 34 && Game::cellTypes[col + 1][row] != 35) {
						col++;
					}
				}
			} else {
				if (slot != 2) {
					while (col <= this->liquidBreachCol && (int8_t)(Game::cellTypes[col + 1][row] - 80) < 0 && Game::cellTypes[col + 1][row] != 10 && Game::cellTypes[col + 1][row] != 37 && Game::cellTypes[col + 1][row] != 34 && Game::cellTypes[col + 1][row] != 35) {
						col++;
					}
				} else {
					while (col >= this->liquidBreachCol && (int8_t)(Game::cellTypes[col + 1][row] - 80) < 0 && Game::cellTypes[col + 1][row] != 10 && Game::cellTypes[col + 1][row] != 37 && Game::cellTypes[col + 1][row] != 34 && Game::cellTypes[col + 1][row] != 35) {
						col++;
					}
				}
			}
			if (this->liquidBreachDir != 2 && col <= this->liquidBreachCol) {
				while ((int8_t)(Game::cellTypes[col + 1][row] - 80) < 0 && Game::cellTypes[col + 1][row] != 10 && Game::cellTypes[col + 1][row] != 37 && Game::cellTypes[col + 1][row] != 34 && Game::cellTypes[col + 1][row] != 35) {
					col++;
				}
			}
			this->setFlowBits(this->liquidDrainFlow, (int8_t)col, 14, 6);
			s0 = 1;
			while (true) {
				nextSlotOrWidth = s0;
				if ((int8_t)(Game::cellTypes[col - nextSlotOrWidth][row] - 80) >= 0 || Game::cellTypes[col - nextSlotOrWidth][row] == 10 || Game::cellTypes[col - nextSlotOrWidth][row] == 37 || Game::cellTypes[col - nextSlotOrWidth][row] == 34 || Game::cellTypes[col - nextSlotOrWidth][row] == 35) {
					break;
				}
				s0 = (int8_t)(nextSlotOrWidth + 1);
			}
			s0_o = this;
			s1 = this->liquidDrainFlow;
			s2 = nextSlotOrWidth;
			s3 = 49;
			s4 = 5;
			cast<Game>(s0_o)->setFlowBits(s1, s2, s3, s4);
			break;
		default:
			break;
	}
}

void Game::updatePoolFill(int8_t flowIndex) {
	int32_t fillSlot = 0, overflowOrWidth = 0, stepOrExcess = 0, nextRowOrSlots = 0, stepOrRoundUp = 0, partialSlots = 0, col = 0, row = 0, capacity = 0, filledAmount = 0, phase = 0, emitterIndex = 0, sourceAmountLeft = 0, width = 0, s0 = 0;
	col = Game::getFlowBits(flowIndex, 14, 6);
	row = Game::getFlowBits(flowIndex, 20, 6);
	capacity = Game::getFlowBits(flowIndex, 0, 7);
	filledAmount = Game::getFlowBits(flowIndex, 7, 7);
	phase = Game::getFlowBits(flowIndex, 47, 2);
	emitterIndex = (int8_t)Game::getFlowBits(flowIndex, 54, 3);
	sourceAmountLeft = (int8_t)Game::getEmitterBits(emitterIndex, 6, 7);
	switch (phase) {
		case 1:
			width = (int8_t)Game::getFlowBits(flowIndex, 49, 5);
			if (this->liquidFlowTick != 0 && irem(this->liquidFlowTick, width) == 0) {
				this->liquidFlowTick = 0;
				fillSlot = (int8_t)Game::getFlowBits(flowIndex, 26, 2);
				overflowOrWidth = (int8_t)Game::getFlowBits(flowIndex, 57, 1);
				if (fillSlot >= 0) {
					if (overflowOrWidth != 1) {
						s0 = 0;
						while (true) {
							stepOrExcess = s0;
							if (stepOrExcess >= width) {
								break;
							}
							this->setLiquidBits(col - stepOrExcess, row, fillSlot, 7, 3, 4);
							this->setFlowBits(flowIndex, fillSlot, 43, 2);
							this->setLiquidBits(col - stepOrExcess, row, fillSlot, flowIndex, 0, 3);
							s0 = (int8_t)(stepOrExcess + 1);
						}
						if (this->liquidPoolRiseCount > 0) {
							stepOrExcess = fillSlot;
							nextRowOrSlots = row;
							stepOrExcess = (int8_t)(stepOrExcess + 1);
							if (stepOrExcess > 2) {
								stepOrExcess = 0;
								nextRowOrSlots++;
							}
							s0 = 0;
							while (true) {
								stepOrRoundUp = s0;
								if (stepOrRoundUp >= width) {
									break;
								}
								if ((int8_t)(Game::cellTypes[col - stepOrRoundUp][nextRowOrSlots] - 80) < 0 && Game::cellTypes[col - stepOrRoundUp][nextRowOrSlots] != 10 && Game::cellTypes[col - stepOrRoundUp][nextRowOrSlots] != 37 && Game::cellTypes[col - stepOrRoundUp][nextRowOrSlots] != 34 && Game::cellTypes[col - stepOrRoundUp][nextRowOrSlots] != 35) {
									this->setLiquidBits(col - stepOrRoundUp, nextRowOrSlots, stepOrExcess, 8, 3, 4);
								}
								s0 = (int8_t)(stepOrRoundUp + 1);
							}
						}
						this->liquidPoolRiseCount = this->liquidPoolRiseCount + 1;
					}
					if (overflowOrWidth == 1 || (filledAmount >= capacity || sourceAmountLeft == 0) && fillSlot == this->liquidFillTargetSlot) {
						if (overflowOrWidth == 1) {
							this->setFlowBits(flowIndex, 0, 57, 1);
						}
						this->setFlowBits(flowIndex, 3, 28, 3);
						if (sourceAmountLeft == 0) {
							this->setEmitterBits(emitterIndex, 3, 0, 4);
							this->setFlowBits(flowIndex, 5, 28, 3);
							if (this->liquidDrainTick == -1) {
								this->liquidFlowTick = -1;
								this->liquidState = 4;
							}
							return;
						}
					}
					if (fillSlot != 0) {
						fillSlot = (int8_t)(fillSlot - 1);
						this->setFlowBits(flowIndex, fillSlot, 26, 2);
						return;
					}
					this->setFlowBits(flowIndex, 0, 47, 2);
					this->setFlowBits(flowIndex, 2, 26, 2);
					return;
				}
			}
			break;
		case 0:
			this->setFlowBits(flowIndex, 1, 47, 2);
			row--;
			this->setFlowBits(flowIndex, (int8_t)row, 20, 6);
			fillSlot = 0;
			if ((int8_t)(Game::cellTypes[col][row] - 80) >= 0 || Game::cellTypes[col][row] == 10 || Game::cellTypes[col][row] == 37 || Game::cellTypes[col][row] == 34 || Game::cellTypes[col][row] == 35) {
				while ((int8_t)(Game::cellTypes[col][row] - 80) >= 0 || Game::cellTypes[col][row] == 10 || Game::cellTypes[col][row] == 37 || Game::cellTypes[col][row] == 34 || Game::cellTypes[col][row] == 35) {
					col = col - 1;
				}
			} else {
				while ((int8_t)(Game::cellTypes[col + 1][row] - 80) < 0 && Game::cellTypes[col + 1][row] != 10 && Game::cellTypes[col + 1][row] != 37 && Game::cellTypes[col + 1][row] != 34 && Game::cellTypes[col + 1][row] != 35) {
					col++;
				}
			}
			this->setFlowBits(flowIndex, (int8_t)col, 14, 6);
			s0 = 1;
			while (true) {
				overflowOrWidth = s0;
				if ((int8_t)(Game::cellTypes[col - overflowOrWidth][row] - 80) >= 0 || Game::cellTypes[col - overflowOrWidth][row] == 10 || Game::cellTypes[col - overflowOrWidth][row] == 37 || Game::cellTypes[col - overflowOrWidth][row] == 34 || Game::cellTypes[col - overflowOrWidth][row] == 35) {
					break;
				}
				s0 = (int8_t)(overflowOrWidth + 1);
			}
			this->setFlowBits(flowIndex, overflowOrWidth, 49, 5);
			sourceAmountLeft = (int8_t)(sourceAmountLeft - overflowOrWidth);
			stepOrExcess = 0;
			this->liquidFillTargetSlot = 0;
			if (sourceAmountLeft < 0) {
				nextRowOrSlots = -sourceAmountLeft;
				nextRowOrSlots = nextRowOrSlots * 3;
				stepOrRoundUp = 0;
				partialSlots = overflowOrWidth + sourceAmountLeft;
				if (partialSlots * 3 - overflowOrWidth != 0) {
					partialSlots = partialSlots * 3;
					if (partialSlots <= overflowOrWidth * 3 / 2) {
						stepOrRoundUp = 1;
					}
				}
				nextRowOrSlots = idiv(nextRowOrSlots, overflowOrWidth);
				this->liquidFillTargetSlot = (int8_t)nextRowOrSlots;
				this->liquidFillTargetSlot = (int8_t)(this->liquidFillTargetSlot + stepOrRoundUp);
				if (this->liquidFillTargetSlot > 2) {
					this->setFlowBits(flowIndex, 1, 57, 1);
				}
				stepOrExcess = (int8_t)JMath::abs(sourceAmountLeft);
				sourceAmountLeft = 0;
			}
			filledAmount = filledAmount + (overflowOrWidth - stepOrExcess);
			if (filledAmount > capacity) {
				nextRowOrSlots = capacity - filledAmount;
				filledAmount = filledAmount + nextRowOrSlots;
				sourceAmountLeft = (int8_t)(sourceAmountLeft - nextRowOrSlots);
			}
			this->setFlowBits(flowIndex, (int8_t)filledAmount, 7, 7);
			this->setEmitterBits(emitterIndex, sourceAmountLeft, 6, 7);
			break;
		default:
			break;
	}
}

int8_t Game::moveStreamSideways(int8_t flowIndex, int32_t col, int32_t row, int8_t curDir, int8_t slot, int8_t dx, bool isErasing) {
	int32_t sideGraphic = 0, flowState = 0, result = 0, cornerGraphic = 0, s0_n = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0;
	result = 0;
	if ((int8_t)(Game::cellTypes[col + dx][row] - 80) >= 0 || Game::cellTypes[col + dx][row] == 10 || Game::cellTypes[col + dx][row] == 37 || Game::cellTypes[col + dx][row] == 34 || Game::cellTypes[col + dx][row] == 35) {
		result = -2;
	} else {
		result = dx;
		if (curDir != dx) {
			this->setFlowBits(flowIndex, dx >= 0 ? dx : 2, 45, 2);
		}
		col = col + dx;
		this->setFlowBits(flowIndex, (int8_t)col, 31, 6);
		this->setLiquidBits(col, row, slot, flowIndex, 0, 3);
		if (isErasing == 0) {
			cornerGraphic = 0;
			sideGraphic = 0;
			flowState = Game::getFlowBits(flowIndex, 28, 3);
			if (dx <= 0) {
				cornerGraphic = flowState != 6 || this->liquidBreachCol != col || this->liquidBreachRow != row ? 5 : 14;
				s0_n = 12;
			} else {
				cornerGraphic = flowState != 6 || this->liquidBreachCol != col || this->liquidBreachRow != row ? 4 : 11;
				s0_n = 9;
			}
			sideGraphic = s0_n;
			if ((int8_t)(Game::cellTypes[col][row + 1] - 80) >= 0 || Game::cellTypes[col + dx][row] == 10 || Game::cellTypes[col + dx][row] == 37 || Game::cellTypes[col + dx][row] == 34 || Game::cellTypes[col + dx][row] == 35) {
				s1 = col;
				s2 = row;
				s3 = slot;
				s4 = cornerGraphic;
			} else {
				s1 = col;
				s2 = row;
				s3 = slot;
				s4 = sideGraphic;
			}
			cast<Game>(this)->setLiquidBits(s1, s2, s3, s4, 3, 4);
		} else {
			Game::clearLiquidSlot(col, row, slot);
		}
	}
	return result;
}

bool Game::isLiquidBasinState(int32_t cellState) {
	if (cellState == -1 || Game::extractIntBits(cellState, 6, 1) != 1) {
		return 0;
	}
	return 1;
}

int8_t Game::extractIntBits(int32_t value, int8_t shift, int8_t bitCount) {
	return (int8_t)(ushr(value, shift) & (shl(16777215, bitCount) ^ -1));
}

bool Game::isFloorSealedBackToWall(int32_t col, int32_t row, int32_t dir) {
	int32_t result = 0, floorSolid = 0, s0 = 0;
	result = 1;
	s0 = 1;
	while (true) {
		floorSolid = s0;
		while (true) {
			if (floorSolid == 0) {
				return result;
			}
			floorSolid = 1;
			col = col - dir;
			if (dir != 0) {
				if ((int8_t)(Game::cellTypes[col][row + 1] - 80) < 0 && Game::cellTypes[col][row + 1] != 10 && Game::cellTypes[col][row + 1] != 37 && Game::cellTypes[col][row + 1] != 34 && Game::cellTypes[col][row + 1] != 35) {
					floorSolid = 0;
				}
				if ((int8_t)(Game::cellTypes[col][row] - 80) >= 0 || Game::cellTypes[col][row] == 10 || Game::cellTypes[col][row] == 37 || Game::cellTypes[col][row] == 34 || Game::cellTypes[col][row] == 35) {
					result = floorSolid;
					s0 = 0;
					goto L1_next;
				}
				if (floorSolid != 0) {
					continue;
				}
				goto L1_end;
			}
			if ((int8_t)(Game::cellTypes[col - 1][row] - 80) >= 0 || Game::cellTypes[col - 1][row] == 10 || Game::cellTypes[col - 1][row] == 37 || Game::cellTypes[col - 1][row] == 34 || Game::cellTypes[col - 1][row] == 35 && (int8_t)(Game::cellTypes[col + 1][row] - 80) >= 0 || Game::cellTypes[col + 1][row] == 10 || Game::cellTypes[col + 1][row] == 37 || Game::cellTypes[col + 1][row] == 34 || Game::cellTypes[col + 1][row] == 35) {
				break;
			}
		}
		result = 1;
		s0 = 0;
		L1_next:;
	}
	L1_end:;
	return floorSolid;
}

void Game::updateStreamHead(int8_t flowIndex) {
	int32_t nextSlotOrBelowState = 0, nextRow = 0, prevSlot = 0, poolFlowIndex = 0, emitterIndex = 0, col = 0, row = 0, slot = 0, animPhase = 0, dir = 0, flowState = 0, isErasing = 0, sideResult = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0;
	Ref<Object> s0_o;
	col = Game::getFlowBits(flowIndex, 31, 6);
	row = Game::getFlowBits(flowIndex, 37, 6);
	slot = (int8_t)Game::getFlowBits(flowIndex, 43, 2);
	animPhase = (int8_t)Game::getLiquidBits(Game::liquidCells[col][row], slot, 7, 2);
	dir = (int8_t)Game::getFlowBits(flowIndex, 45, 2);
	flowState = (int8_t)Game::getFlowBits(flowIndex, 28, 3);
	isErasing = flowState == 7 ? 1 : 0;
	sideResult = 0;
	if (dir > 1) {
		dir = -1;
	}
	if (animPhase == 0) {
		nextSlotOrBelowState = (int8_t)(slot + 1);
		nextRow = row;
		if (slot == 2) {
			nextSlotOrBelowState = 0;
			nextRow = row + 1;
		}
		if (Game::getLiquidBits(Game::liquidCells[col][nextRow], nextSlotOrBelowState, 3, 4) == 7) {
			this->liquidPoolRiseCount = 1;
			if (isErasing == 0) {
				prevSlot = nextSlotOrBelowState - 1;
				if (prevSlot < 0) {
					prevSlot = 2;
				}
				this->liquidFlowTick = 0;
				poolFlowIndex = (int8_t)Game::getLiquidBits(Game::liquidCells[col][nextRow], nextSlotOrBelowState, 0, 3);
				emitterIndex = (int8_t)Game::getFlowBits(flowIndex, 54, 3);
				this->setFlowBits(poolFlowIndex, emitterIndex, 54, 3);
				this->setFlowBits(poolFlowIndex, 2, 28, 3);
				this->setFlowBits(poolFlowIndex, 0, 47, 2);
				this->setFlowBits(poolFlowIndex, (int8_t)prevSlot, 26, 2);
				this->setFlowBits(poolFlowIndex, (int8_t)col, 14, 6);
				this->setFlowBits(poolFlowIndex, (int8_t)nextRow, 20, 6);
				this->setFlowBits(poolFlowIndex, 0, 57, 1);
				Game::clearLiquidFlow(flowIndex);
				return;
			}
			Game::clearLiquidFlow(flowIndex);
			this->liquidState = 3;
			this->liquidStartNextEmitter = 1;
			return;
		}
	}
	if (slot == 2 && animPhase == 0) {
		if ((int8_t)(Game::cellTypes[col][row + 1] - 80) >= 0 || Game::cellTypes[col][row + 1] == 10 || Game::cellTypes[col][row + 1] == 37 || Game::cellTypes[col][row + 1] == 34 || Game::cellTypes[col][row + 1] == 35) {
			if (dir != 0) {
				s0_o = this;
				s1 = flowIndex;
				s2 = col;
				s3 = row;
				s4 = dir;
				s5 = slot;
				s6 = dir;
				sideResult = cast<Game>(s0_o)->moveStreamSideways(s1, s2, s3, s4, s5, s6, isErasing);
			} else {
				if (isErasing == 0) {
					this->setLiquidBits(col, row, slot, 15, 3, 4);
				} else {
					Game::clearLiquidSlot(col, row, slot);
				}
				sideResult = this->moveStreamSideways(flowIndex, col, row, dir, slot, 1, isErasing);
				if (sideResult >= 0) {
					if ((int8_t)(Game::cellTypes[col - 1][row] - 80) < 0 && Game::cellTypes[col - 1][row] != 10 && Game::cellTypes[col - 1][row] != 37 && Game::cellTypes[col - 1][row] != 34 && Game::cellTypes[col - 1][row] != 35) {
						this->spawnLiquidFlow(col - 1, row, isErasing == 0 ? 5 : 7, -1, 2, (int8_t)Game::getFlowBits(flowIndex, 54, 3));
					}
				} else {
					s0_o = this;
					s1 = flowIndex;
					s2 = col;
					s3 = row;
					s4 = dir;
					s5 = slot;
					s6 = -1;
					sideResult = cast<Game>(s0_o)->moveStreamSideways(s1, s2, s3, s4, s5, s6, isErasing);
				}
			}
			if (sideResult != -2) {
				dir = sideResult;
				col = col + dir;
			} else {
				nextSlotOrBelowState = Game::cellStates[col][row + 1];
				if (!this->isLiquidBasinState(nextSlotOrBelowState) || !Game::isFloorSealedBackToWall(col, row, dir)) {
					s0_o = this;
					s1 = flowIndex;
					s2 = 3;
					s3 = 28;
					s4 = 3;
				} else {
					this->liquidPoolRiseCount = 0;
					this->liquidFlowTick = 0;
					this->setFlowBits(flowIndex, 2, 28, 3);
					this->setFlowBits(flowIndex, Game::extractIntBits(nextSlotOrBelowState, 0, 6), 0, 7);
					this->setFlowBits(flowIndex, 2, 26, 2);
					this->setFlowBits(flowIndex, (int8_t)col, 14, 6);
					s0_o = this;
					s1 = flowIndex;
					s2 = (int8_t)(row + 1);
					s3 = 20;
					s4 = 6;
				}
				cast<Game>(s0_o)->setFlowBits(s1, s2, s3, s4);
				col = col + dir;
			}
		} else {
			if (dir != 0) {
				dir = 0;
				this->setFlowBits(flowIndex, 0, 45, 2);
			}
		}
	}
	{
		if (sideResult != -2) {
			switch (dir) {
				case 0:
					this->moveStreamDown(flowIndex, col, row, slot, isErasing);
					return;
				case -1:
				case 1:
					this->advanceLiquidAnimPhase(col, row, slot, animPhase);
					goto B16_end;
				default:
					return;
			}
		}
	}
	B16_end:;
}

void Game::advanceLiquidAnimPhase(int32_t col, int32_t row, int8_t slot, int8_t animPhase) {
	animPhase = (int8_t)(animPhase + 1);
	if (animPhase > 2) {
		animPhase = 0;
	}
	this->setLiquidBits(col, row, slot, animPhase, 7, 2);
}

void Game::moveStreamDown(int8_t flowIndex, int32_t col, int32_t row, int8_t slot, bool isErasing) {
	int32_t s1 = 0, s2 = 0, s3 = 0, s4 = 0;
	if (isErasing == 0 && Game::getLiquidBits(Game::liquidCells[col][row], slot, 3, 4) == 0) {
		this->setLiquidBits(col, row, slot, 3, 3, 4);
	}
	slot = (int8_t)(slot + 1);
	if (slot > 2) {
		slot = 0;
		row++;
		this->setFlowBits(flowIndex, (int8_t)row, 37, 6);
	}
	this->setFlowBits(flowIndex, slot, 43, 2);
	if (isErasing == 0) {
		this->setLiquidBits(col, row, slot, flowIndex, 0, 3);
		s1 = col;
		s2 = row;
		s3 = slot;
		s4 = 0;
	} else {
		s1 = col;
		s2 = row;
		s3 = slot;
		s4 = 6;
	}
	cast<Game>(this)->setLiquidBits(s1, s2, s3, s4, 3, 4);
}

void Game::spawnSourceStream(int32_t col, int32_t row) {
	this->liquidState = 1;
	this->spawnLiquidFlow(col, row + 1, 0, 0, 0, this->findEmitterAt(col, row));
}

void Game::clearLiquidSlot(int32_t col, int32_t row, int8_t slot) {
	int32_t cellValue = 0, shift = 0, slotBits = 0;
	cellValue = Game::liquidCells[col][row];
	shift = (int8_t)(slot * 9);
	slotBits = ushr(cellValue, shift);
	slotBits = slotBits & 511;
	slotBits = shl(slotBits, shift);
	cellValue = cellValue ^ slotBits;
	Game::liquidCells[col][row] = cellValue;
	Game::cellUpdateTimers[col][row] = 24;
}

int8_t Game::spawnLiquidFlow(int32_t col, int32_t row, int8_t graphic, int8_t dir, int8_t slot, int8_t emitterIndex) {
	int32_t flowIndex = 0, s0 = 0;
	s0 = 1;
	while (true) {
		flowIndex = s0;
		if (flowIndex > 15) {
			break;
		}
		if (Game::getFlowBits(flowIndex, 28, 3) != 0) {
			s0 = (int8_t)(flowIndex + 1);
			continue;
		}
		break;
	}
	Game::liquidFlows[flowIndex - 1] = 0LL;
	if (graphic != 7) {
		this->setFlowBits(flowIndex, 1, 28, 3);
		this->setFlowBits(flowIndex, emitterIndex, 54, 3);
		this->setLiquidBits(col, row, slot, flowIndex, 0, 3);
		this->setLiquidBits(col, row, slot, graphic, 3, 4);
	} else {
		Game::clearLiquidSlot(col, row, slot);
		this->setFlowBits(flowIndex, 7, 28, 3);
	}
	this->setFlowBits(flowIndex, (int8_t)col, 31, 6);
	this->setFlowBits(flowIndex, (int8_t)row, 37, 6);
	this->setFlowBits(flowIndex, slot, 43, 2);
	if (dir < 0) {
		dir = 2;
	}
	this->setFlowBits(flowIndex, dir, 45, 2);
	return flowIndex;
}

int32_t Game::getLiquidSlotGraphic(int32_t col, int32_t row, int32_t cellValue, int8_t slot) {
	int32_t flowIndex = 0, headCol = 0, headRow = 0, headSlot = 0, graphic = 0, s0 = 0;
	flowIndex = (int8_t)Game::getLiquidBits(cellValue, slot, 0, 3);
	headCol = Game::getFlowBits(flowIndex, 31, 6);
	headRow = Game::getFlowBits(flowIndex, 37, 6);
	headSlot = Game::getFlowBits(flowIndex, 43, 2);
	graphic = Game::getLiquidBits(cellValue, slot, 3, 4);
	if (headCol != col || headRow != row || headSlot != slot) {
		switch (graphic) {
			case 6:
				Game::clearLiquidSlot(col, row, slot);
				break;
			default:
				break;
		}
		return graphic << 1;
	}
	switch (graphic) {
		case 5:
			s0 = 2;
			graphic = s0;
			break;
		case 4:
			s0 = 1;
			graphic = s0;
			break;
		default:
			break;
	}
	return graphic << 1;
}

void Game::checkLiquidBreachAt(int32_t col, int32_t row) {
	int32_t s1 = 0;
	if (this->hasWaterLayer) {
		if (Game::liquidCells[col - 1][row] == 0) {
			s1 = Game::liquidCells[col + 1][row] == 0 ? 0 : 1;
		} else {
			s1 = -1;
		}
		this->liquidBreachDir = s1;
		if (this->liquidBreachDir == 0) {
			this->liquidBreachDir = Game::liquidCells[col][row - 1] == 0 ? 0 : 2;
		}
		if (this->liquidBreachDir != 0) {
			this->liquidState = 5;
			this->playSound(13);
			this->liquidBreachCol = col;
			this->liquidBreachRow = row;
		}
	}
}

int32_t Game::spreadLiquidThroughBreach(int32_t col, int32_t row) {
	int32_t flowIndex = 0, needFlow = 0, offset = 0, dir = 0, total = 0, searchSteps = 0, s0 = 0;
	flowIndex = 0;
	needFlow = 1;
	offset = 0;
	dir = this->liquidBreachDir;
	total = 0;
	while (true) {
		searchSteps = 0;
		while (Game::liquidCells[col + dir][row - 1] != 0 && (int8_t)(Game::cellTypes[col][row] - 80) >= 0 || Game::cellTypes[col][row] == 10 || Game::cellTypes[col][row] == 37 || Game::cellTypes[col][row] == 34 || Game::cellTypes[col][row] == 35) {
			col = col + dir;
		}
		s0 = 0;
		while (true) {
			offset = s0;
			if ((int8_t)(Game::cellTypes[col + offset][row] - 80) >= 0 || Game::cellTypes[col + offset][row] == 10 || Game::cellTypes[col + offset][row] == 37 || Game::cellTypes[col + offset][row] == 34 || Game::cellTypes[col + offset][row] == 35) {
				break;
			}
			if (needFlow != 0) {
				needFlow = 0;
				flowIndex = this->spawnLiquidFlow(col, row, 8, -2, 2, 0);
				this->setFlowBits(flowIndex, 5, 28, 3);
				this->setFlowBits(flowIndex, (int8_t)col, 14, 6);
				this->setFlowBits(flowIndex, (int8_t)row, 20, 6);
			}
			this->setLiquidBits(col + offset, row, 2, flowIndex, 0, 3);
			s0 = offset + dir;
		}
		offset = JMath::abs(offset);
		total = total + offset;
		row++;
		while (Game::liquidCells[col][row] == 0) {
			col = col + dir;
			if (searchSteps >= offset || col < 0 || col == this->levelW) {
				goto L1_end;
			}
			searchSteps++;
		}
	}
	L1_end:;
	if (total > 0) {
		this->setFlowBits(flowIndex, (int8_t)total, 7, 7);
	}
	return total;
}

void Game::startLiquidBreachDrain(int32_t col, int32_t row) {
	int32_t emitterOrFlowIndex = 0, cellValue = 0, poolAmount = 0, streamDir = 0, emitterCol = 0, stopRow = 0, remainingAmount = 0, emitterRow = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0;
	Ref<Object> s0;
	Ref<Game> t1;
	this->liquidDrainTick = 0;
	cellValue = 0;
	if (this->liquidBreachDir <= 1) {
		s0 = Game::liquidCells[col + this->liquidBreachDir];
		s1 = row;
	} else {
		s0 = Game::liquidCells[col];
		s1 = row - 1;
	}
	cellValue = cast<Array<int32_t>>(s0)[s1];
	this->liquidDrainFlow = (int8_t)Game::getLiquidBits(cellValue, 2, 0, 3);
	this->setFlowBits(this->liquidDrainFlow, 0, 47, 2);
	poolAmount = Game::getFlowBits(this->liquidDrainFlow, 7, 7);
	streamDir = 0;
	emitterCol = 0;
	stopRow = 0;
	remainingAmount = 0;
	emitterRow = 0;
	switch (this->liquidBreachDir) {
		default:
			streamDir = this->liquidBreachDir;
			emitterCol = col + streamDir;
			streamDir = streamDir >= 0 ? 2 : 1;
			stopRow = row + 1;
			remainingAmount = poolAmount - this->spreadLiquidThroughBreach(emitterCol, stopRow);
			emitterRow = row;
			this->liquidBreachCol = col;
			this->liquidBreachRow = row;
			break;
		case 2:
			streamDir = 0;
			emitterCol = col;
			stopRow = row;
			remainingAmount = poolAmount;
			emitterRow = row - 1;
			this->liquidBreachRow = -1;
			this->liquidBreachCol = -1;
			break;
	}
	this->setFlowBits(this->liquidDrainFlow, (int8_t)streamDir, 45, 2);
	this->liquidDrainStopRow = stopRow;
	this->addLiquidEmitter((int8_t)remainingAmount, (int8_t)emitterCol, (int8_t)emitterRow, (int8_t)streamDir);
	emitterOrFlowIndex = this->findEmitterAt(emitterCol, emitterRow);
	this->setEmitterBits(emitterOrFlowIndex, 2, 0, 4);
	this->liquidState = 1;
	switch (this->liquidBreachDir) {
		case 2:
			s0 = this;
			s1 = emitterCol;
			s2 = row;
			s3 = 3;
			s4 = 0;
			s5 = 0;
			emitterOrFlowIndex = cast<Game>(s0)->spawnLiquidFlow(s1, s2, s3, s4, s5, emitterOrFlowIndex);
			break;
		case 1:
			s0 = this;
			s1 = emitterCol - 1;
			s2 = row;
			s3 = 14;
			s4 = -1;
			t1 = cast<Game>(s0);
			s0 = t1;
			s5 = 2;
			emitterOrFlowIndex = cast<Game>(s0)->spawnLiquidFlow(s1, s2, s3, s4, s5, emitterOrFlowIndex);
			break;
		case -1:
			s0 = this;
			s1 = emitterCol + 1;
			s2 = row;
			s3 = 11;
			s4 = 1;
			t1 = cast<Game>(s0);
			s0 = t1;
			s5 = 2;
			emitterOrFlowIndex = cast<Game>(s0)->spawnLiquidFlow(s1, s2, s3, s4, s5, emitterOrFlowIndex);
			break;
		default:
			break;
	}
	this->setFlowBits(emitterOrFlowIndex, 6, 28, 3);
	this->liquidBreachDir = 0;
}

void Game::openLiquidEmitter(int32_t col, int32_t row) {
	int32_t result = 0;
	result = this->setEmitterStateAt(col, row, 2);
	if (result > 0) {
		Game::cellTypes[col][row] = -1;
		this->spawnSourceStream(col, row);
	}
}

int32_t Game::getFrameHeight(Ref<SpritePack> pack, int32_t frame) {
	int32_t boundsIndex = 0;
	boundsIndex = (frame << 2) + 3;
	return pack->frameBounds[boundsIndex] & 255;
}

int32_t Game::getFrameWidth(Ref<SpritePack> pack, int32_t frame) {
	int32_t boundsIndex = 0;
	boundsIndex = (frame << 2) + 2;
	return pack->frameBounds[boundsIndex] & 255;
}

void Game::loadTipPage(int32_t tipIndex) {
	Ref<ByteArrayInputStream> input;
	int32_t pageCount = 0, pageStart = 0, pageEnd = 0;
	Arr<int8_t> offsetTable;
	Ref<Object> s0;
	try {
		Game::tipSprites = tipIndex > 5 ? nullptr : Game::loadSpritePack(u"/tips.f"_j, tipIndex);
		input = jnew<ByteArrayInputStream>(Game::readResource(u"/tipst.f"_j, 0));
		pageCount = input->read();
		tipIndex = irem(tipIndex, pageCount);
		offsetTable = newArray<int8_t>((pageCount + 1) * 2);
		input->read(offsetTable);
		pageStart = Game::readU16LE(offsetTable, tipIndex << 1);
		pageEnd = Game::readU16LE(offsetTable, tipIndex + 1 << 1);
		input->skip((int64_t)pageStart);
		Game::tipPageData = newArray<int8_t>(pageEnd - pageStart);
		input->read(Game::tipPageData);
		input->close();
	} catch (JavaException& ex) {
		if (ex.isa(u"java/lang/Exception")) {
			s0 = ex.ex;
			return;
		}
		else throw;
	}
}

void Game::drawTipPage() {
	int32_t pos = 0, frameOrTextLength = 0, textStart = 0, iconCount = 0, iconDataStart = 0, itemCount = 0, y = 0, measuring = 0, itemIndex = 0, itemType = 0, s0 = 0, s1_n = 0;
	Ref<Graphics> g;
	Arr<int8_t> t1;
	Game::spritePacks[41]->lineSpacing = 5;
	pos = 0;
	t1 = Game::tipPageData;
	pos++;
	itemCount = t1[0];
	this->loadingFullRedraw = 0;
	g = this->screenGraphics;
	g->setColor(798521);
	g->fillRoundRect(20, 60, 200, 200, 8, 8);
	g->setColor(13540096);
	g->drawRoundRect(20, 60, 200, 200, 8, 8);
	y = 0;
	measuring = 1;
	itemIndex = 0;
	while (true) {
		if (itemIndex > itemCount) {
			return;
		}
		if (itemIndex != itemCount) {
			itemType = Game::tipPageData[pos++];
			if (itemType != 0) {
				pos += 2;
				pos += 2;
				frameOrTextLength = Game::tipPageData[pos++] & 255;
				if (Game::tipSprites != nullptr) {
					if (measuring == 0) {
						Game::tipSprites->drawFrame(g, frameOrTextLength, (240 - Game::tipSprites->frameBounds[(frameOrTextLength << 2) + 2] & 255) >> 1, y, 0, 0, 0);
					}
					s0 = y;
					s1_n = Game::tipSprites->frameBounds[(frameOrTextLength << 2) + 3] & 255;
					y = s0 + s1_n;
				}
			} else {
				pos += 2;
				pos += 2;
				frameOrTextLength = Game::readU16LE(Game::tipPageData, pos);
				pos += 2;
				textStart = pos;
				pos = pos + frameOrTextLength;
				iconCount = Game::tipPageData[pos++];
				iconDataStart = pos;
				pos = pos + iconCount;
				y -= 3;
				s0 = y;
				s1_n = this->drawWrappedRichText(g, Game::tipPageData, Game::spritePacks[41], textStart, frameOrTextLength, measuring == 0 ? y : -1, Game::tipSprites, iconDataStart, 192);
				y = s0 + s1_n;
			}
			y += 4;
		} else {
			if (measuring == 0) {
				break;
			}
			measuring = 0;
			itemIndex = -1;
			pos = 1;
			y -= 4;
			y = 60 + (200 - y >> 1);
		}
		itemIndex++;
	}
}

void Game::drawTextInBox(Ref<Graphics> g, Ref<SpritePack> font, Ref<String> text, int32_t x, int32_t y, int32_t anchor, int32_t lineSpacing, bool multiline) {
	int32_t boxX = 0, boxY = 0, textWidth = 0, textHeight = 0, s0_n = 0, s1_n = 0;
	font->lineSpacing = lineSpacing;
	if (text->endsWith(u"\n"_j)) {
		text = text->substring(0, text->length() - 1);
	}
	text = Game::wrapText(text, 230);
	textWidth = Game::measureFirstLineWidth(font, text, multiline == 0 ? 0 : -1);
	textHeight = font->measureTextHeight(text);
	boxX = x;
	boxY = y;
	if ((anchor & 32) == 0) {
		if ((anchor & 2) != 0) {
			s0_n = boxY;
			s1_n = textHeight >> 1;
			boxY = s0_n - s1_n;
		}
	} else {
		s0_n = boxY;
		s1_n = textHeight;
		boxY = s0_n - s1_n;
	}
	if ((anchor & 8) == 0) {
		if ((anchor & 1) != 0) {
			s0_n = boxX;
			s1_n = textWidth >> 1;
			boxX = s0_n - s1_n;
		}
	} else {
		s0_n = boxX;
		s1_n = textWidth;
		boxX = s0_n - s1_n;
	}
	g->setColor(798521);
	g->fillRoundRect(boxX - 5, boxY - 5, textWidth + 10, textHeight + 10, 10, 10);
	g->setColor(13540096);
	g->drawRoundRect(boxX - 5, boxY - 5, textWidth + 10, textHeight + 10, 10, 10);
	font->drawMultilineString(g, text, x, y, anchor);
}

int32_t Game::drawWrappedRichText(Ref<Graphics> g, Arr<int8_t> text, Ref<SpritePack> font, int32_t start, int32_t length, int32_t y, Ref<SpritePack> iconPack, int32_t iconDataStart, int32_t maxWidth) {
	int32_t iconIndex = 0, lineHeight = 0, x = 0, lineY = 0, doDraw = 0, savedPalette = 0, lineStart = 0, measuring = 0, lastSpacePos = 0, xAtLastSpace = 0, pos = 0, ch = 0, glyph = 0, s0 = 0, s1 = 0, s2 = 0, t2 = 0, t3 = 0;
	Ref<Object> s0_o;
	iconIndex = 0;
	y = y - font->frameModules[2];
	lineHeight = font->lineSpacing + (font->moduleSizes[1] & 255);
	x = 0;
	lineY = y;
	doDraw = y != -1 ? 1 : 0;
	savedPalette = font->paletteIndex;
	lineStart = start;
	measuring = 1;
	lastSpacePos = start;
	xAtLastSpace = 0;
	for (pos = start; pos <= start + length; pos++) {
		ch = 10;
		if (pos < start + length) {
			ch = text[pos] & 255;
		}
		if (measuring == 0 || x <= maxWidth) {
			if (ch != 10) {
				if (ch <= 32) {
					if (ch != 32) {
						if (ch != 1) {
							if (ch == 2) {
								pos++;
								s0_o = text;
								s1 = pos;
								t2 = cast<Array<int8_t>>(s0_o)[s1] & 255;
								ch = t2;
								if (ch < font->getFrameModuleCount(0)) {
									glyph = (font->frameModules[ch << 2] & 255) << 1;
									if (measuring == 0 && doDraw != 0) {
										font->drawFramePart(g, 0, ch, x, lineY, 0);
									}
									s0 = x;
									s1 = font->moduleSizes[glyph] & 255;
									s2 = font->frameModules[(ch << 2) + 1];
								} else {
									glyph = ch - font->getFrameModuleCount(0);
									if (measuring == 0 && doDraw != 0) {
										font->drawFrame(g, glyph, x, lineY, 0, 0, 0);
									}
									s0 = x;
									s1 = font->frameBounds[(glyph << 2) + 2] & 255;
									s2 = font->frameBounds[glyph << 2] & 255;
								}
								t3 = s1 - s2;
								s1 = t3;
								x = s0 + (s1 + font->frameModules[1]);
							}
						} else {
							pos++;
							font->paletteIndex = text[pos];
						}
					} else {
						lastSpacePos = pos;
						xAtLastSpace = x;
						s0 = x;
						s1 = font->moduleSizes[0] & 255;
						x = s0 + (s1 + font->frameModules[1]);
					}
				} else {
					if (ch != 64 || iconPack == nullptr) {
						s0_o = SpritePack::charMap;
						s1 = ch;
						t2 = cast<Array<int8_t>>(s0_o)[s1] & 255;
						ch = t2;
						if (ch < font->getFrameModuleCount(0)) {
							glyph = (font->frameModules[ch << 2] & 255) << 1;
							if (measuring == 0 && doDraw != 0) {
								font->drawFramePart(g, 0, ch, x, lineY, 0);
							}
							s0 = x;
							s1 = font->moduleSizes[glyph] & 255;
							s2 = font->frameModules[(ch << 2) + 1];
						} else {
							glyph = ch - font->getFrameModuleCount(0);
							if (measuring == 0 && doDraw != 0) {
								font->drawFrame(g, glyph, x, lineY, 0, 0, 0);
							}
							s0 = x;
							s1 = font->frameBounds[(glyph << 2) + 2] & 255;
							s2 = font->frameBounds[glyph << 2] & 255;
						}
						t3 = s1 - s2;
						s1 = t3;
						x = s0 + (s1 + font->frameModules[1]);
					} else {
						if (measuring == 0 && doDraw != 0) {
							iconPack->drawFrame(g, text[iconIndex + iconDataStart], x, lineY, 0, 0, 0);
						}
						x = x + Game::getFrameWidth(iconPack, text[iconIndex + iconDataStart]);
						glyph = Game::getFrameHeight(iconPack, text[iconIndex + iconDataStart]);
						if (glyph > lineHeight) {
							lineHeight = glyph;
						}
						iconIndex++;
					}
				}
			} else {
				if (measuring == 0 || doDraw == 0) {
					x = 0;
					lineStart = pos + 1;
					lineY = lineY + lineHeight;
					lineHeight = font->lineSpacing + (font->moduleSizes[1] & 255);
				} else {
					x = 120 - (x >> 1);
					pos = lineStart - 1;
					iconIndex = 0;
				}
				if (doDraw != 0) {
					measuring = measuring == 0 ? 1 : 0;
				}
			}
		} else {
			x = xAtLastSpace;
			text[lastSpacePos] = 10;
			pos = lastSpacePos - 1;
		}
	}
	font->paletteIndex = savedPalette;
	return lineY - y;
}

void Game::freeStageMapResources() {
	this->needFreeMapRes = 0;
	Game::freeSpritePack(Game::spritePacks[23], 1);
	Game::spritePacks[23] = nullptr;
	Game::freeSpritePack(Game::spritePacks[24], 1);
	Game::spritePacks[24] = nullptr;
	Game::freeSpritePack(Game::spritePacks[25], 1);
	Game::spritePacks[25] = nullptr;
	Game::freeSpritePack(Game::spritePacks[26], 1);
	Game::spritePacks[26] = nullptr;
	Game::freeSpritePack(Game::spritePacks[17], 1);
	Game::spritePacks[17] = nullptr;
	this->unlockPathPoints = nullptr;
	Game::stageMapImage = nullptr;
	Game::stageMapGraphics = nullptr;
	JSystem::gc();
}

void Game::openStageMap() {
	this->resetCounters();
	this->stageMapImageNeeded = 1;
	this->needsFullRedraw = 1;
	this->markerWalkRestart = 1;
	Game::screen = 21;
	this->loadingStep = 0;
	this->loadingStepCount = 14;
	this->firstSecretStage = 100;
	if (this->stage > this->getSavedLatestStage(this->world)) {
		this->stage = this->getSavedLatestStage(this->world);
	}
	this->allocStageMapNodes();
}

void Game::allocStageMapNodes() {
	Game::stageMapNodes = multiArray<int64_t, 2>(12, 12);
	this->unlockPathPoints = newArray<int32_t>(20);
}

int32_t Game::extractLongBits(int64_t value, int8_t shift, int8_t bitCount) {
	value = lushr(value, shift);
	value = value & (lshl((-1LL), bitCount) ^ (-1LL));
	return (int32_t)value;
}

void Game::setStageMapNodeBits(int32_t col, int32_t row, int32_t value, int8_t shift, int8_t bitCount) {
	int64_t newBits = 0, node = 0, oldBits = 0;
	node = Game::stageMapNodes[col][row];
	oldBits = (int64_t)Game::extractLongBits(node, shift, bitCount);
	oldBits = lshl(oldBits, shift);
	node = node ^ oldBits;
	newBits = (int64_t)value;
	newBits = lshl(newBits, shift);
	node = node | newBits;
	Game::stageMapNodes[col][row] = node;
}

void Game::drawStageMapScreen() {
	if (this->stageMapImageNeeded) {
		Game::stageMapImage = Image::createImage(186, 226);
	}
	if (this->needsFullRedraw) {
		this->needsFullRedraw = 0;
		this->stageMapAnimating = 1;
		this->drawStageMapBackground();
		this->drawStageMapNodes();
	}
	if (this->stageMapAnimating) {
		this->screenGraphics->drawImage(Game::stageMapImage, 27, 56, 0);
		this->drawStageMapTopBar();
		this->updateMapMarker();
		this->drawStageMapStageLabel();
		this->drawStageDiamondTooltip();
	}
	if (this->stageMapAnimating && this->mapMarkerCol == this->mapTargetCol && this->mapMarkerRow == this->mapTargetRow) {
		this->stageMapAnimating = 0;
	}
}

void Game::drawStageMapStageLabel() {
	int64_t node = 0;
	int32_t stageIndex = 0, s3 = 0;
	Ref<Object> s0, s1, s2;
	node = Game::stageMapNodes[this->mapMarkerCol][this->mapMarkerRow];
	stageIndex = Game::extractLongBits(node, 6, 5);
	if (stageIndex >= this->firstSecretStage) {
		s0 = Game::spritePacks[41];
		s1 = this->screenGraphics;
		s2 = jnew<StringBuffer>()->append(Game::secretStageLabelPrefix->toString());
		s3 = stageIndex - this->firstSecretStage;
	} else {
		s0 = Game::spritePacks[41];
		s1 = this->screenGraphics;
		s2 = jnew<StringBuffer>()->append(Game::stageLabelPrefix->toString());
		s3 = stageIndex;
	}
	cast<SpritePack>(s0)->drawString(cast<Graphics>(s1), cast<StringBuffer>(s2)->append(s3 + 1)->toString(), 8, 45, 6);
}

void Game::drawStageDiamondTooltip() {
	int64_t node = 0;
	int32_t markerY = 0, boxX = 0, boxY = 0, stageIndex = 0, collected = 0, total = 0, boxW = 0, markerX = 0;
	if (this->mapMarkerCol != this->mapTargetCol || this->mapMarkerRow != this->mapTargetRow) {
		return;
	}
	node = Game::stageMapNodes[this->mapMarkerCol][this->mapMarkerRow];
	stageIndex = Game::extractLongBits(node, 6, 5);
	collected = 0;
	collected = this->getStageBankedRedDiamonds(this->world, stageIndex);
	total = this->getStageRedDiamondTotal(this->world, stageIndex);
	if (collected > total) {
		collected = total;
	}
	Game::scratchText->deleteChars(0, Game::scratchText->length());
	Game::scratchText->append(collected);
	Game::scratchText->appendChar(47);
	Game::scratchText->append(total);
	Game::spritePacks[41]->measureString(Game::scratchText->toString());
	boxW = SpritePack::textWidth + 6 + 14;
	markerX = 37 + this->mapMarkerCol * 13 + 6;
	markerY = 73 + this->mapMarkerRow * 13 + 6;
	boxX = markerX - (boxW >> 1) + 0;
	boxY = markerY - 17 - 31;
	if (boxY <= 63) {
		boxY = 63;
		boxX = markerX + 20;
		if (boxX + boxW >= 200) {
			boxX = markerX - boxW - 20;
		}
	}
	if (boxX <= 35) {
		boxX = 35;
	}
	if (boxX + boxW >= 200) {
		boxX = 150;
	}
	Game::drawFramedBox(this->screenGraphics, boxX, boxY, boxW, 17, 37042, 0);
	Game::spritePacks[41]->drawString(this->screenGraphics, Game::scratchText->toString(), boxX + 2, boxY + 2 - 1, 20);
	if (Game::spritePacks[17] != nullptr) {
		Game::spritePacks[17]->drawFrame(this->screenGraphics, 10, boxX + boxW - 2 - 14, boxY + 2 - 1, 0, 0, 0);
	}
}

void Game::resetUnlockPathAnimation() {
	this->unlockFlashFrame = 0;
	this->unlockPathCoordCount = 0;
	this->unlockPathDotsShown = 0;
	this->unlockRevealDone = 0;
	this->recordUnlockPath = 1;
	this->unlockPathShown = 0;
	this->unlockPathDotDelay = 2;
	this->unlockNodeBlinkTimer = 2;
	this->unlockPathReversed = 0;
}

bool Game::animateUnlockPath() {
	int32_t done = 0, pathType = 0, dotsDrawn = 0, dotIndex = 0, dotStep = 0, nodeFrame = 0, nodeOffset = 0, nodeX = 0, nodeY = 0, explorerFrame = 0, showTargetIcon = 0, dotCount = 0, markerType = 0, targetType = 0, dotFrame = 0, s0_n = 0, s1 = 0;
	int64_t markerNode = 0, targetNode = 0;
	done = 0;
	dotCount = this->unlockPathCoordCount >> 1;
	if (this->unlockPathDotDelay >= 0) {
		s1 = this->unlockPathDotDelay - 1;
	} else {
		s1 = 2;
	}
	cast<Game>(this)->unlockPathDotDelay = s1;
	if (this->mapTargetCol == 0 && this->mapTargetRow == 0) {
		this->mapTargetCol = this->mapMarkerCol;
		this->mapTargetRow = this->mapMarkerRow;
	}
	if (this->unlockPathDotDelay == 0) {
		if (this->unlockPathDotsShown != dotCount) {
			this->unlockPathDotsShown = this->unlockPathDotsShown + 1;
			s0_n = 0;
		} else {
			s0_n = 1;
		}
		done = s0_n;
	}
	markerNode = Game::stageMapNodes[this->mapMarkerCol][this->mapMarkerRow];
	markerType = Game::extractLongBits(markerNode, 3, 3);
	targetNode = Game::stageMapNodes[this->mapTargetCol][this->mapTargetRow];
	targetType = Game::extractLongBits(targetNode, 3, 3);
	dotFrame = 0;
	pathType = 0;
	pathType = markerType == 1 || targetType == 1 ? 1 : markerType;
	switch (pathType) {
		case 1:
			s0_n = 8;
			dotFrame = s0_n;
			break;
		case 0:
			s0_n = 2;
			dotFrame = s0_n;
			break;
		default:
			break;
	}
	dotsDrawn = 0;
	dotIndex = !this->unlockPathReversed ? 0 : dotCount - 1;
	dotStep = !this->unlockPathReversed ? 1 : -1;
	while (dotsDrawn < this->unlockPathDotsShown) {
		nodeFrame = dotIndex * 2;
		Game::spritePacks[17]->drawFrame(this->screenGraphics, dotFrame, this->unlockPathPoints[nodeFrame], this->unlockPathPoints[nodeFrame + 1], 0, 0, 0);
		dotsDrawn++;
		dotIndex = dotIndex + dotStep;
	}
	nodeFrame = 0;
	nodeOffset = 0;
	switch (markerType) {
		case 1:
			nodeOffset = 2;
			s0_n = 9;
			nodeFrame = s0_n;
			break;
		case 0:
			nodeOffset = 0;
			s0_n = 0;
			nodeFrame = s0_n;
			break;
		default:
			break;
	}
	nodeX = this->mapMarkerCol * 13 + nodeOffset + 37;
	nodeY = this->mapMarkerRow * 13 + nodeOffset + 73;
	Game::spritePacks[17]->drawFrame(this->screenGraphics, nodeFrame, nodeX, nodeY, 0, 0, 0);
	explorerFrame = !this->markerFacingLeft ? 6 : 7;
	Game::spritePacks[17]->drawFrame(this->screenGraphics, explorerFrame, nodeX + 6, nodeY + 6, 0, 0, 0);
	showTargetIcon = 1;
	if (dotsDrawn == dotCount) {
		if (this->unlockNodeBlinkTimer >= 0) {
			s1 = this->unlockNodeBlinkTimer - 1;
		} else {
			s1 = 2;
		}
		cast<Game>(this)->unlockNodeBlinkTimer = s1;
		if (this->unlockNodeBlinkTimer == 0) {
			this->unlockNodeBlinkTimer = 1;
			showTargetIcon = 0;
		}
	}
	if (showTargetIcon != 0) {
		switch (targetType) {
			case 1:
				nodeOffset = 2;
				s0_n = 5;
				nodeFrame = s0_n;
				break;
			case 0:
				nodeOffset = 0;
				s0_n = 1;
				nodeFrame = s0_n;
				break;
			default:
				break;
		}
	} else {
		switch (targetType) {
			case 1:
				nodeOffset = 2;
				s0_n = 9;
				nodeFrame = s0_n;
				break;
			case 0:
				nodeOffset = 0;
				s0_n = 0;
				nodeFrame = s0_n;
				break;
			default:
				break;
		}
	}
	nodeX = this->mapTargetCol * 13 + nodeOffset + 37;
	nodeY = this->mapTargetRow * 13 + nodeOffset + 73;
	Game::spritePacks[17]->drawFrame(this->screenGraphics, nodeFrame, nodeX, nodeY, 0, 0, 0);
	if (showTargetIcon == 0) {
		if (this->unlockFlashFrame != Game::spritePacks[9]->getAnimFrameCount(0)) {
			s0_n = 0;
		} else {
			this->unlockFlashFrame = this->unlockFlashFrame - 1;
			this->unlockRevealDone = 1;
			s0_n = 1;
		}
		done = s0_n;
		if (!this->stageWasCompleted) {
			Game::spritePacks[9]->drawFrame(this->screenGraphics, this->unlockFlashFrame, nodeX, nodeY, 0, 0, 0);
		}
		this->unlockFlashFrame = this->unlockFlashFrame + 1;
	}
	return done;
}

void Game::updateMapMarker() {
	int32_t markerX = 0, markerY = 0, targetXOrFrame = 0, targetY = 0, arrived = 0;
	markerX = 37 + this->mapMarkerCol * 13 + 6;
	markerY = 73 + this->mapMarkerRow * 13 + 6;
	if (this->mapMarkerCol != this->mapTargetCol || this->mapMarkerRow != this->mapTargetRow) {
		targetXOrFrame = 37 + this->mapTargetCol * 13 + 6;
		targetY = 73 + this->mapTargetRow * 13 + 6;
		if ((this->getStageFlags(this->world, this->stage + 1) & 2) != 0 && this->stage + 1 == Game::latestUnlockedStage || this->stage == Game::latestUnlockedStage) {
			this->unlockPathShown = 1;
		}
		if (this->unlockPathShown) {
			arrived = this->stepMarkerWalk(markerX, markerY, targetXOrFrame, targetY);
			if (arrived) {
				this->mapMarkerCol = this->mapTargetCol;
				this->mapMarkerRow = this->mapTargetRow;
				return;
			}
		} else {
			this->unlockPathShown = this->animateUnlockPath();
			if (this->unlockPathShown) {
				this->needsFullRedraw = 1;
				return;
			}
		}
	} else {
		if (this->stageMapAnimating) {
			targetXOrFrame = !this->markerFacingLeft ? 6 : 7;
			Game::spritePacks[17]->drawFrame(this->screenGraphics, targetXOrFrame, markerX, markerY, 0, 0, 0);
		}
	}
}

bool Game::stepMarkerWalk(int32_t fromX, int32_t fromY, int32_t toX, int32_t toY) {
	int32_t frame = 0;
	if (this->markerWalkRestart) {
		this->markerWalkRestart = 0;
		this->markerWalkX = fromX;
		this->markerWalkY = fromY;
		this->markerWalkError = 0;
		this->markerWalkDx = toX - fromX;
		this->markerWalkDy = toY - fromY;
		this->markerWalkMajor2 = 0;
		this->markerWalkMinor2 = 0;
		this->markerWalkStepX = 10;
		this->markerWalkStepY = 10;
	}
	if (this->markerWalkDx < 0) {
		this->markerWalkStepX = -10;
		this->markerWalkDx = -this->markerWalkDx;
	}
	if (this->markerWalkDy < 0) {
		this->markerWalkStepY = -10;
		this->markerWalkDy = -this->markerWalkDy;
	}
	this->markerFacingLeft = this->markerWalkStepX <= 0 ? 1 : 0;
	frame = !this->markerFacingLeft ? 6 : 7;
	{
		if (this->markerWalkDy > this->markerWalkDx) {
			this->markerWalkMajor2 = 2 * this->markerWalkDy;
			this->markerWalkMinor2 = 2 * this->markerWalkDx;
			if ((this->markerWalkStepY >= 0 || this->markerWalkY > toY) && (this->markerWalkStepY <= 0 || this->markerWalkY < toY)) {
				Game::spritePacks[17]->drawFrame(this->screenGraphics, frame, this->markerWalkX, this->markerWalkY, 0, 0, 0);
				this->markerWalkY = this->markerWalkY + this->markerWalkStepY;
				this->markerWalkError = this->markerWalkError + this->markerWalkMinor2;
				if (this->markerWalkError > this->markerWalkDy) {
					this->markerWalkX = this->markerWalkX + this->markerWalkStepX;
					goto B4_end;
				}
				return 0;
			}
			toX = 37 + this->mapTargetCol * 13 + 6;
			toY = 73 + this->mapTargetRow * 13 + 6;
			Game::spritePacks[17]->drawFrame(this->screenGraphics, frame, toX, toY, 0, 0, 0);
			this->markerWalkRestart = 1;
			return 1;
		}
		this->markerWalkMajor2 = 2 * this->markerWalkDx;
		this->markerWalkMinor2 = 2 * this->markerWalkDy;
		if ((this->markerWalkStepX >= 0 || this->markerWalkX > toX) && (this->markerWalkStepX <= 0 || this->markerWalkX < toX)) {
			Game::spritePacks[17]->drawFrame(this->screenGraphics, frame, this->markerWalkX, this->markerWalkY, 0, 0, 0);
			this->markerWalkX = this->markerWalkX + this->markerWalkStepX;
			this->markerWalkError = this->markerWalkError + this->markerWalkMinor2;
			if (this->markerWalkError > this->markerWalkDx) {
				this->markerWalkY = this->markerWalkY + this->markerWalkStepY;
				goto B4_end;
			}
			return 0;
		}
		toX = 37 + this->mapTargetCol * 13 + 6;
		toY = 73 + this->mapTargetRow * 13 + 6;
		Game::spritePacks[17]->drawFrame(this->screenGraphics, frame, toX, toY, 0, 0, 0);
		this->markerWalkRestart = 1;
		return 1;
	}
	B4_end:;
	this->markerWalkError = this->markerWalkError - this->markerWalkMajor2;
	return 0;
}

void Game::drawStageMapLinksFromNode(int32_t col, int32_t row, int64_t node, int32_t nodeType, int32_t isLocked) {
	int32_t linkIndex = 0, startX = 0, startY = 0, linkCol = 0, linkRow = 0, endX = 0, endY = 0, linkStage = 0, drawnBit = 0, stepX = 0, stepY = 0, dotFrame = 0, linkLocked = 0, linkType = 0, stageIndex = 0, linkCount = 0, bitOffset = 0, s0 = 0;
	int64_t linkNode = 0;
	stageIndex = Game::extractLongBits(node, 6, 5);
	this->mapPathsDrawnMask = this->mapPathsDrawnMask | shl(1, stageIndex);
	linkCount = Game::extractLongBits(node, 11, 3);
	bitOffset = 14;
	linkIndex = 0;
	while (linkIndex < linkCount) {
		startX = 37 + col * 13;
		startY = 73 + row * 13;
		linkCol = Game::extractLongBits(node, (int8_t)bitOffset, 4);
		bitOffset += 4;
		linkRow = Game::extractLongBits(node, (int8_t)bitOffset, 4);
		endX = linkCol;
		endY = linkRow;
		linkNode = Game::stageMapNodes[endX][endY];
		linkStage = Game::extractLongBits(linkNode, 6, 5);
		drawnBit = this->mapPathsDrawnMask;
		drawnBit = drawnBit & shl(1, linkStage);
		if (drawnBit <= 0) {
			endX = 37 + endX * 13;
			endY = 73 + endY * 13;
			startX += 6;
			startY += 6;
			endX += 6;
			endY += 6;
			this->pathDotX = startX;
			this->pathDotY = startY;
			this->pathDotError = 0;
			this->pathDotDx = endX - startX;
			this->pathDotDy = endY - startY;
			this->pathDotMajor2 = 0;
			this->pathDotMinor2 = 0;
			this->pathDotStep = 1;
			stepX = 1;
			stepY = 1;
			if (this->pathDotDx < 0) {
				stepX = -1;
				this->pathDotDx = -this->pathDotDx;
			}
			if (this->pathDotDy < 0) {
				stepY = -1;
				this->pathDotDy = -this->pathDotDy;
			}
			dotFrame = 0;
			linkLocked = Game::extractLongBits(linkNode, 0, 3);
			linkType = Game::extractLongBits(linkNode, 3, 3);
			if (nodeType == 1) {
				linkType = nodeType;
			}
			if (isLocked != 1) {
				if (!this->unlockRevealDone && linkStage == Game::latestUnlockedStage) {
					linkLocked = 1;
				}
				if (linkLocked != 0) {
					switch (linkType) {
						case 1:
							s0 = 4;
							dotFrame = s0;
							break;
						case 0:
							s0 = 3;
							dotFrame = s0;
							break;
						default:
							break;
					}
				} else {
					switch (linkType) {
						case 1:
							s0 = 8;
							dotFrame = s0;
							break;
						case 0:
							s0 = 2;
							dotFrame = s0;
							break;
						default:
							break;
					}
				}
				if (this->pathDotDy > this->pathDotDx) {
					this->pathDotMajor2 = 2 * this->pathDotDy;
					this->pathDotMinor2 = 2 * this->pathDotDx;
					while (true) {
						if (this->pathDotStep % 8 == 0) {
							Game::spritePacks[17]->drawFrame(Game::stageMapGraphics, dotFrame, this->pathDotX - 27, this->pathDotY - 56, 0, 0, 0);
							if (this->recordUnlockPath) {
								this->recordUnlockPathDot(stageIndex, linkStage);
							}
						}
						if (this->pathDotY != endY) {
							this->pathDotY = this->pathDotY + stepY;
							this->pathDotError = this->pathDotError + this->pathDotMinor2;
							if (this->pathDotError > this->pathDotDy) {
								this->pathDotX = this->pathDotX + stepX;
								this->pathDotError = this->pathDotError - this->pathDotMajor2;
							}
							this->pathDotStep = this->pathDotStep + 1;
							continue;
						}
						break;
					}
				} else {
					this->pathDotMajor2 = this->pathDotDx << 1;
					this->pathDotMinor2 = this->pathDotDy << 1;
					while (true) {
						if (this->pathDotStep % 8 == 0) {
							Game::spritePacks[17]->drawFrame(Game::stageMapGraphics, dotFrame, this->pathDotX - 27, this->pathDotY - 56, 0, 0, 0);
							if (this->recordUnlockPath) {
								this->recordUnlockPathDot(stageIndex, linkStage);
							}
						}
						if (this->pathDotX != endX) {
							this->pathDotX = this->pathDotX + stepX;
							this->pathDotError = this->pathDotError + this->pathDotMinor2;
							if (this->pathDotError > this->pathDotDx) {
								this->pathDotY = this->pathDotY + stepY;
								this->pathDotError = this->pathDotError - this->pathDotMajor2;
							}
							this->pathDotStep = this->pathDotStep + 1;
							continue;
						}
						break;
					}
				}
			} else {
				if (linkType != 1) {
					linkLocked = isLocked;
					if (!this->unlockRevealDone && linkStage == Game::latestUnlockedStage) {
						linkLocked = 1;
					}
					if (linkLocked != 0) {
						switch (linkType) {
							case 1:
								s0 = 4;
								dotFrame = s0;
								break;
							case 0:
								s0 = 3;
								dotFrame = s0;
								break;
							default:
								break;
						}
					} else {
						switch (linkType) {
							case 1:
								s0 = 8;
								dotFrame = s0;
								break;
							case 0:
								s0 = 2;
								dotFrame = s0;
								break;
							default:
								break;
						}
					}
					if (this->pathDotDy > this->pathDotDx) {
						this->pathDotMajor2 = 2 * this->pathDotDy;
						this->pathDotMinor2 = 2 * this->pathDotDx;
						while (true) {
							if (this->pathDotStep % 8 == 0) {
								Game::spritePacks[17]->drawFrame(Game::stageMapGraphics, dotFrame, this->pathDotX - 27, this->pathDotY - 56, 0, 0, 0);
								if (this->recordUnlockPath) {
									this->recordUnlockPathDot(stageIndex, linkStage);
								}
							}
							if (this->pathDotY != endY) {
								this->pathDotY = this->pathDotY + stepY;
								this->pathDotError = this->pathDotError + this->pathDotMinor2;
								if (this->pathDotError > this->pathDotDy) {
									this->pathDotX = this->pathDotX + stepX;
									this->pathDotError = this->pathDotError - this->pathDotMajor2;
								}
								this->pathDotStep = this->pathDotStep + 1;
								continue;
							}
							break;
						}
					} else {
						this->pathDotMajor2 = this->pathDotDx << 1;
						this->pathDotMinor2 = this->pathDotDy << 1;
						while (true) {
							if (this->pathDotStep % 8 == 0) {
								Game::spritePacks[17]->drawFrame(Game::stageMapGraphics, dotFrame, this->pathDotX - 27, this->pathDotY - 56, 0, 0, 0);
								if (this->recordUnlockPath) {
									this->recordUnlockPathDot(stageIndex, linkStage);
								}
							}
							if (this->pathDotX != endX) {
								this->pathDotX = this->pathDotX + stepX;
								this->pathDotError = this->pathDotError + this->pathDotMinor2;
								if (this->pathDotError > this->pathDotDx) {
									this->pathDotY = this->pathDotY + stepY;
									this->pathDotError = this->pathDotError - this->pathDotMajor2;
								}
								this->pathDotStep = this->pathDotStep + 1;
								continue;
							}
							break;
						}
					}
				}
			}
		}
		linkIndex++;
		bitOffset += 4;
	}
}

void Game::recordUnlockPathDot(int32_t fromStage, int32_t toStage) {
	int64_t fromNode = 0;
	int32_t fromNodeStage = 0, t3 = 0, t5 = 0;
	Arr<int32_t> t2, t4;
	if (this->usedMainExit) {
		if (toStage == Game::latestUnlockedStage && fromStage == Game::latestUnlockedStage - 1 || fromStage == Game::latestUnlockedStage && toStage == Game::latestUnlockedStage - 1) {
			if (fromStage == Game::latestUnlockedStage && toStage == Game::latestUnlockedStage - 1) {
				this->unlockPathReversed = 1;
			}
			t2 = cast<Game>(this)->unlockPathPoints;
			t3 = this->unlockPathCoordCount;
			this->unlockPathCoordCount = t3 + 1;
			t2[t3] = this->pathDotX;
			t4 = this->unlockPathPoints;
			t5 = this->unlockPathCoordCount;
			this->unlockPathCoordCount = t5 + 1;
			t4[t5] = this->pathDotY;
		}
	} else {
		fromNode = Game::stageMapNodes[this->unlockFromNodeX][this->unlockFromNodeY];
		fromNodeStage = Game::extractLongBits(fromNode, 6, 5);
		{
			if (toStage == Game::latestUnlockedStage && fromStage == fromNodeStage || fromStage == Game::latestUnlockedStage && toStage == fromNodeStage) {
				if (fromStage == Game::latestUnlockedStage && toStage == fromNodeStage) {
					this->unlockPathReversed = 1;
				}
				t2 = cast<Game>(this)->unlockPathPoints;
				t3 = this->unlockPathCoordCount;
				this->unlockPathCoordCount = t3 + 1;
				t2[t3] = this->pathDotX;
				t4 = this->unlockPathPoints;
				t5 = this->unlockPathCoordCount;
				this->unlockPathCoordCount = t5 + 1;
				t4[t5] = this->pathDotY;
				goto B4_end;
			}
		}
		B4_end:;
	}
}

void Game::drawStageMapNodes() {
	int32_t col = 0, completeFrame = 0, nodeOffset = 0, linkCountOrPack = 0, row = 0, allDiamonds = 0, nodeType = 0, stageIndex = 0, isLocked = 0, nodeFrame = 0, s0 = 0;
	int64_t node = 0;
	this->mapPathsDrawnMask = 0;
	if ((this->getStageFlags(this->world, this->stage + 1) & 2) != 0 && this->stage + 1 == Game::latestUnlockedStage || this->stage == Game::latestUnlockedStage) {
		this->recordUnlockPath = 0;
		this->unlockRevealDone = 1;
	}
	for (col = 0; col < 12; col++) {
		for (row = 0; row < 12; row++) {
			node = Game::stageMapNodes[col][row];
			allDiamonds = 0;
			if (node != 0LL) {
				nodeType = Game::extractLongBits(node, 3, 3);
				stageIndex = Game::extractLongBits(node, 6, 5);
				isLocked = this->unlockRevealDone || stageIndex != Game::latestUnlockedStage || stageIndex == 0 ? Game::extractLongBits(node, 0, 3) : 1;
				nodeFrame = -1;
				completeFrame = -1;
				nodeOffset = -1;
				if (isLocked != 0) {
					switch (nodeType) {
						case 0:
							nodeOffset = 0;
							nodeFrame = 1;
							break;
						default:
							break;
					}
				} else {
					allDiamonds = this->getStageBankedRedDiamonds(this->world, stageIndex) == this->getStageRedDiamondTotal(this->world, stageIndex) ? 1 : 0;
					switch (nodeType) {
						case 1:
							completeFrame = 18;
							nodeOffset = 2;
							s0 = 9;
							nodeFrame = s0;
							break;
						case 0:
							completeFrame = 17;
							nodeOffset = 0;
							linkCountOrPack = Game::extractLongBits(node, 11, 3);
							s0 = linkCountOrPack <= 2 ? 0 : 13;
							nodeFrame = s0;
							break;
						default:
							break;
					}
				}
				this->drawStageMapLinksFromNode(col, row, node, nodeType, isLocked);
				if (nodeOffset != -1 && nodeFrame != -1) {
					if (allDiamonds != 0 && completeFrame != -1) {
						Game::spritePacks[17]->drawFrame(Game::stageMapGraphics, completeFrame, col * 13 + nodeOffset + 37 - 27, row * 13 + nodeOffset + 73 - 56, 0, 0, 0);
					}
					Game::spritePacks[17]->drawFrame(Game::stageMapGraphics, nodeFrame, col * 13 + nodeOffset + 37 - 27, row * 13 + nodeOffset + 73 - 56, 0, 0, 0);
					linkCountOrPack = -1;
					switch (this->world) {
						case 2:
							if (stageIndex == 10) {
								s0 = 54;
								linkCountOrPack = s0;
							}
							break;
						case 1:
							if (stageIndex == 9) {
								s0 = 53;
								linkCountOrPack = s0;
							}
							break;
						case 0:
							if (stageIndex == 8) {
								s0 = 52;
								linkCountOrPack = s0;
							}
							break;
						default:
							break;
					}
					if (linkCountOrPack != -1) {
						Game::spritePacks[linkCountOrPack]->drawFrame(Game::stageMapGraphics, 0, col * 13 - 8 + 37 - 27, row * 13 - 8 + 73 - 56, 0, 0, 0);
					}
				}
			}
		}
	}
	this->recordUnlockPath = 0;
}

void Game::drawStageMapBackground() {
	int32_t bgColor = 0, barFillColor = 0, barBorderColor = 0, titleStringId = 0, bgPackIndex = 0, progressCount = 0, progressTotal = 0, s0 = 0;
	this->screenGraphics->setClip(0, 0, 240, 320);
	bgColor = 0;
	barFillColor = 0;
	barBorderColor = 0;
	titleStringId = -1;
	bgPackIndex = 0;
	switch (this->world) {
		case 2:
			bgColor = 5210510;
			barFillColor = 3711421;
			barBorderColor = 7469567;
			bgPackIndex = 26;
			s0 = 30;
			titleStringId = s0;
			break;
		case 1:
			bgColor = 869201;
			barFillColor = 4022666;
			barBorderColor = 5873874;
			bgPackIndex = 25;
			s0 = 29;
			titleStringId = s0;
			break;
		case 0:
			bgColor = 939282;
			barFillColor = 3111750;
			barBorderColor = 8635434;
			bgPackIndex = 24;
			s0 = 28;
			titleStringId = s0;
			break;
		default:
			break;
	}
	this->screenGraphics->setColor(bgColor);
	this->screenGraphics->fillRect(0, 0, 240, 320);
	Game::spritePacks[bgPackIndex]->drawFrame(this->screenGraphics, 0, 120, 0, 0, 0, 0);
	Game::spritePacks[41]->drawString(this->screenGraphics, Game::langStrings[titleStringId], 8, 6, 20);
	Game::stageMapGraphics = Game::stageMapImage->getGraphics();
	Game::stageMapGraphics->setColor(bgColor);
	Game::stageMapGraphics->fillRect(0, 0, 186, 226);
	Game::spritePacks[23]->drawFrame(Game::stageMapGraphics, 0, 93, 113, 0, 0, 0);
	this->screenGraphics->setColor(barFillColor);
	this->screenGraphics->fillRoundRect(2, 282, 236, 22, 8, 8);
	this->screenGraphics->setColor(barBorderColor);
	this->screenGraphics->drawRoundRect(2, 282, 236, 22, 8, 8);
	this->drawBackSoftkeyIcon();
	this->drawSelectSoftkeyIcon();
	Game::spritePacks[41]->drawString(this->screenGraphics, Game::langStrings[96], 222, 311, 10);
	if (Game::spritePacks[17] != nullptr) {
		Game::spritePacks[17]->drawFrame(this->screenGraphics, 12, 11, 284, 0, 0, 0);
		Game::spritePacks[17]->drawFrame(this->screenGraphics, 10, 155, 285, 0, 0, 0);
		Game::spritePacks[17]->drawFrame(this->screenGraphics, 11, 80, 285, 0, 0, 0);
	}
	Game::scratchText->deleteChars(0, Game::scratchText->length());
	Game::scratchText->append(this->lives);
	Game::spritePacks[41]->drawString(this->screenGraphics, Game::scratchText->toString(), 39, 285, 20);
	Game::scratchText->deleteChars(0, Game::scratchText->length());
	Game::scratchText->append(Game::readU16LE(Game::saveData, 4));
	Game::spritePacks[41]->drawString(this->screenGraphics, Game::scratchText->toString(), 100, 285, 20);
	Game::scratchText->deleteChars(0, Game::scratchText->length());
	progressCount = Game::readU16LE(Game::saveData, 6);
	progressTotal = Game::saveData[0];
	if (progressCount < progressTotal) {
		Game::scratchText->append(progressCount)->append(u"/"_j)->append(progressTotal);
	} else {
		Game::scratchText->append(progressCount)->append(u"/"_j)->append(progressCount);
	}
	Game::spritePacks[41]->drawString(this->screenGraphics, Game::scratchText->toString(), 175, 285, 20);
	this->stageMapImageNeeded = 0;
}

void Game::drawStageMapTopBar() {
	int32_t fillColor = 0, borderColor = 0, s0 = 0;
	fillColor = 0;
	borderColor = 0;
	switch (this->world) {
		case 2:
			fillColor = 3711421;
			s0 = 7469567;
			borderColor = s0;
			break;
		case 1:
			fillColor = 4022666;
			s0 = 5873874;
			borderColor = s0;
			break;
		case 0:
			fillColor = 3111750;
			s0 = 8635434;
			borderColor = s0;
			break;
		default:
			break;
	}
	this->screenGraphics->setColor(fillColor);
	this->screenGraphics->fillRoundRect(2, 34, 236, 22, 8, 8);
	this->screenGraphics->setColor(borderColor);
	this->screenGraphics->drawRoundRect(2, 34, 236, 22, 8, 8);
}

void Game::handleStageMapInput() {
	int32_t dir = 0, linkIndex = 0, linkCol = 0, linkRow = 0, linkNodeOrCol2 = 0, linkRow2 = 0, linkLocked = 0, markerColOrNode = 0, markerRow = 0, nodeOrStage = 0, linkCount = 0, bitOffset = 0, firstCandidate = 0, secondCandidate = 0, s0 = 0;
	int64_t linkNodeOrCol2_l = 0, markerColOrNode_l = 0, nodeOrStage_l = 0;
	if (this->mapMarkerCol == this->mapTargetCol && this->mapMarkerRow == this->mapTargetRow) {
		dir = -1;
		if (!Game::isKeyDown(4097)) {
			if (!Game::isKeyDown(262146)) {
				if (!Game::isKeyDown(16388)) {
					if (!Game::isKeyDown(65544)) {
						if (!Game::isKeyDown(32944)) {
							if (Game::isKeyDown(64)) {
								this->needLevelCleanup = 1;
								this->needFreeMapRes = 1;
								this->needGarbageCollect = 1;
								this->loadingStep = 0;
								Game::screen = 28;
								Game::keys = 0;
								return;
							}
						} else {
							if (JSystem::currentTimeMillis() - this->stageSelectLockTime >= 2000LL) {
								markerColOrNode_l = Game::stageMapNodes[this->mapMarkerCol][this->mapMarkerRow];
								nodeOrStage = Game::extractLongBits(markerColOrNode_l, 6, 5);
								this->cleanup();
								this->freeStageMapResources();
								JSystem::gc();
								this->stage = nodeOrStage;
								this->startLevelLoading();
								Game::keys = 0;
								return;
							}
							return;
						}
					} else {
						dir = 1;
					}
				} else {
					dir = 4;
				}
			} else {
				dir = 3;
			}
		} else {
			dir = 2;
		}
		Game::keys = 0;
		if (dir != -1) {
			markerColOrNode = this->mapMarkerCol;
			markerRow = this->mapMarkerRow;
			nodeOrStage_l = Game::stageMapNodes[markerColOrNode][markerRow];
			linkCount = Game::extractLongBits(nodeOrStage_l, 11, 3);
			bitOffset = 14;
			firstCandidate = -1;
			secondCandidate = -1;
			linkIndex = 0;
			while (linkIndex < linkCount) {
				linkCol = Game::extractLongBits(nodeOrStage_l, (int8_t)bitOffset, 4);
				bitOffset += 4;
				linkRow = Game::extractLongBits(nodeOrStage_l, (int8_t)bitOffset, 4);
				linkNodeOrCol2_l = Game::stageMapNodes[linkCol][linkRow];
				linkLocked = Game::extractLongBits(linkNodeOrCol2_l, 0, 3);
				if (linkLocked != 1) {
					switch (dir) {
						case 4:
							if (linkCol < markerColOrNode) {
								if (firstCandidate < 0) {
									s0 = linkIndex;
									firstCandidate = s0;
								} else {
									secondCandidate = linkIndex;
								}
							}
							break;
						case 3:
							if (linkRow > markerRow) {
								if (firstCandidate < 0) {
									s0 = linkIndex;
									firstCandidate = s0;
								} else {
									secondCandidate = linkIndex;
								}
							}
							break;
						case 2:
							if (linkRow < markerRow) {
								if (firstCandidate < 0) {
									s0 = linkIndex;
									firstCandidate = s0;
								} else {
									secondCandidate = linkIndex;
								}
							}
							break;
						case 1:
							if (linkCol > markerColOrNode) {
								if (firstCandidate < 0) {
									s0 = linkIndex;
									firstCandidate = s0;
								} else {
									secondCandidate = linkIndex;
								}
							}
							break;
						default:
							break;
					}
				}
				linkIndex++;
				bitOffset += 4;
			}
			if (firstCandidate != -1) {
				linkIndex = -1;
				if (secondCandidate == -1) {
					linkIndex = firstCandidate;
				} else {
					bitOffset = 14 + firstCandidate * 2 * 4;
					linkCol = Game::extractLongBits(nodeOrStage_l, (int8_t)bitOffset, 4);
					bitOffset += 4;
					linkRow = Game::extractLongBits(nodeOrStage_l, (int8_t)bitOffset, 4);
					bitOffset = 14 + secondCandidate * 2 * 4;
					linkNodeOrCol2 = Game::extractLongBits(nodeOrStage_l, (int8_t)bitOffset, 4);
					bitOffset += 4;
					linkRow2 = Game::extractLongBits(nodeOrStage_l, (int8_t)bitOffset, 4);
					switch (dir) {
						case 2:
						case 3:
							if (markerColOrNode != linkCol) {
								if (markerColOrNode != linkNodeOrCol2) {
									s0 = linkCol <= linkNodeOrCol2 ? secondCandidate : firstCandidate;
								} else {
									s0 = secondCandidate;
								}
							} else {
								s0 = firstCandidate;
							}
							linkIndex = s0;
							break;
						case 1:
						case 4:
							if (markerRow != linkRow) {
								if (markerRow != linkRow2) {
									s0 = JMath::abs(markerColOrNode - linkCol) <= JMath::abs(markerColOrNode - linkNodeOrCol2) ? secondCandidate : firstCandidate;
								} else {
									s0 = secondCandidate;
								}
							} else {
								s0 = firstCandidate;
							}
							linkIndex = s0;
							break;
						default:
							break;
					}
				}
				if (linkIndex != -1) {
					bitOffset = 14 + linkIndex * 2 * 4;
					linkCol = Game::extractLongBits(nodeOrStage_l, (int8_t)bitOffset, 4);
					bitOffset += 4;
					linkRow = Game::extractLongBits(nodeOrStage_l, (int8_t)bitOffset, 4);
					linkNodeOrCol2_l = Game::stageMapNodes[linkCol][linkRow];
					linkLocked = Game::extractLongBits(linkNodeOrCol2_l, 0, 3);
					if (linkLocked == 0) {
						this->mapTargetCol = linkCol;
						this->mapTargetRow = linkRow;
						this->stageMapAnimating = 1;
					}
				}
			}
		}
	}
}

void Game::loadStageMapStep(int32_t step) {
	Ref<Object> s0, s2;
	int32_t s1 = 0, s3 = 0;
	{
		try {
			switch (step) {
				case 14:
					if (this->fromStageClear) {
						this->fromStageClear = 0;
					}
					this->setupStageMapMarkers();
					Game::screen = 15;
					return;
				case 10:
					if (!this->newStageUnlocked) {
						return;
					}
					this->resetUnlockPathAnimation();
					goto T1_end;
				case 9:
					if (Game::spritePacks[52] != nullptr) {
						return;
					}
					Game::spritePacks[52] = Game::loadSpritePack(u"/mmv.f"_j, 3);
					goto T1_end;
				case 8:
					if (Game::spritePacks[53] != nullptr) {
						return;
					}
					Game::spritePacks[53] = Game::loadSpritePack(u"/mmv.f"_j, 2);
					goto T1_end;
				case 7:
					{
						if (Game::spritePacks[54] != nullptr) {
							this->gemHalfWidth = Game::getFrameWidth(Game::spritePacks[54], 0) >> 1;
							this->gemHalfHeight = Game::getFrameHeight(Game::spritePacks[54], 0) >> 1;
						} else {
							Game::spritePacks[54] = Game::loadSpritePack(u"/mmv.f"_j, 1);
							this->gemHalfWidth = Game::getFrameWidth(Game::spritePacks[54], 0) >> 1;
							this->gemHalfHeight = Game::getFrameHeight(Game::spritePacks[54], 0) >> 1;
							goto B7_end;
						}
					}
					B7_end:;
					return;
				case 6:
					switch (this->world) {
						case 2:
							s0 = Game::spritePacks;
							s1 = 26;
							s2 = u"/ms.f"_j;
							s3 = 4;
							cast<Array<Ref<SpritePack>>>(s0)[s1] = Game::loadSpritePack(cast<String>(s2), s3);
							break;
						case 1:
							s0 = Game::spritePacks;
							s1 = 25;
							s2 = u"/ms.f"_j;
							s3 = 3;
							cast<Array<Ref<SpritePack>>>(s0)[s1] = Game::loadSpritePack(cast<String>(s2), s3);
							break;
						case 0:
							s0 = Game::spritePacks;
							s1 = 24;
							s2 = u"/ms.f"_j;
							s3 = 2;
							cast<Array<Ref<SpritePack>>>(s0)[s1] = Game::loadSpritePack(cast<String>(s2), s3);
							break;
						default:
							break;
					}
					goto T1_end;
				case 5:
					Game::spritePacks[17] = Game::loadSpritePack(u"/ms.f"_j, 0);
					Game::spritePacks[23] = Game::loadSpritePack(u"/ms.f"_j, 1);
					goto T1_end;
				case 4:
					Game::spritePacks[41]->paletteIndex = 0;
					Game::scratchText->deleteChars(0, Game::scratchText->length());
					switch (this->world) {
						case 2:
							Game::scratchText->append(u"/map_tibet.out"_j);
							Game::stageMapNodes = multiArray<int64_t, 2>(12, 12);
							this->unlockPathPoints = newArray<int32_t>(20);
							this->loadStageMapFile(Game::scratchText->toString());
							break;
						case 1:
							Game::scratchText->append(u"/map_scotland.out"_j);
							Game::stageMapNodes = multiArray<int64_t, 2>(12, 12);
							this->unlockPathPoints = newArray<int32_t>(20);
							this->loadStageMapFile(Game::scratchText->toString());
							break;
						case 0:
							Game::scratchText->append(u"/map_angkor.out"_j);
							Game::stageMapNodes = multiArray<int64_t, 2>(12, 12);
							this->unlockPathPoints = newArray<int32_t>(20);
							this->loadStageMapFile(Game::scratchText->toString());
							break;
						default:
							Game::stageMapNodes = multiArray<int64_t, 2>(12, 12);
							this->unlockPathPoints = newArray<int32_t>(20);
							this->loadStageMapFile(Game::scratchText->toString());
							break;
					}
					goto T1_end;
				case 3:
					if (!this->needFreeMapRes) {
						return;
					}
					this->freeStageMapResources();
					goto T1_end;
				case 2:
					if (!this->needFreeMenuRes) {
						return;
					}
					this->freeWorldMapResources();
					goto T1_end;
				case 1:
					if (!this->needLevelCleanup) {
						return;
					}
					this->cleanup();
					goto T1_end;
				case 0:
					if (!this->needSaveStageResult) {
						return;
					}
					this->saveStageResult();
					goto T1_end;
				default:
					return;
			}
		} catch (JavaException& ex) {
			if (ex.isa(u"java/lang/Exception")) {
				s0 = ex.ex;
			}
			else throw;
		}
	}
	T1_end:;
}

void Game::loadStageMapFile(Ref<String> path) {
	int32_t stageIndex = 0, linkCount = 0, bitOffset = 0, linkIndex = 0, linkCol = 0, linkRow = 0, dataSize = 0, nodeCount = 0, pos = 0, nodeIndex = 0, col = 0, row = 0, nodeType = 0;
	Ref<InputStream> input;
	input = this->getClass()->getResourceAsStream(path);
	dataSize = input->read();
	dataSize = ((int8_t)dataSize & 255) + ((int8_t)input->read() & 255) * 256;
	nodeCount = input->read();
	Game::tipPageData = newArray<int8_t>(dataSize);
	input->read(Game::tipPageData);
	input->close();
	pos = 0;
	for (nodeIndex = 0; nodeIndex < nodeCount; nodeIndex++) {
		col = Game::tipPageData[pos++];
		row = Game::tipPageData[pos++];
		nodeType = Game::tipPageData[pos++];
		stageIndex = Game::tipPageData[pos++];
		if (nodeType == 1 && stageIndex < this->firstSecretStage) {
			this->firstSecretStage = stageIndex;
		}
		linkCount = Game::tipPageData[pos++];
		this->setStageMapNodeBits(col, row, 1, 0, 3);
		this->setStageMapNodeBits(col, row, nodeType, 3, 3);
		this->setStageMapNodeBits(col, row, stageIndex, 6, 5);
		this->setStageMapNodeBits(col, row, linkCount, 11, 3);
		bitOffset = 14;
		for (linkIndex = 0; linkIndex < linkCount; linkIndex++) {
			linkCol = Game::tipPageData[pos++];
			this->setStageMapNodeBits(col, row, linkCol, bitOffset, 4);
			bitOffset = (int8_t)(bitOffset + 4);
			linkRow = Game::tipPageData[pos++];
			this->setStageMapNodeBits(col, row, linkRow, bitOffset, 4);
			bitOffset = (int8_t)(bitOffset + 4);
		}
	}
	Game::tipPageData = nullptr;
	JSystem::gc();
}

void Game::setupStageMapMarkers() {
	int32_t col = 0, row = 0, stageIndex = 0, isUnlocked = 0, s1 = 0, s2 = 0, s3 = 0;
	int64_t node = 0;
	Ref<Object> s0_o;
	this->mapMarkerCol = -1;
	if (!this->newStageUnlocked) {
		this->stage = Game::latestUnlockedStage;
	}
	this->newStageUnlocked = 0;
	for (col = 0; col < 12; col++) {
		for (row = 0; row < 12; row++) {
			node = Game::stageMapNodes[col][row];
			if (node != 0LL) {
				stageIndex = Game::extractLongBits(node, 6, 5);
				isUnlocked = (this->getStageFlags(this->world, stageIndex) & 64) == 0 ? 0 : 1;
				if (isUnlocked != 0 || stageIndex == 0) {
					s0_o = this;
					s1 = col;
					s2 = row;
					s3 = 0;
				} else {
					s0_o = this;
					s1 = col;
					s2 = row;
					s3 = 1;
				}
				cast<Game>(s0_o)->setStageMapNodeBits(s1, s2, s3, 0, 3);
				if (stageIndex == this->stage) {
					this->mapMarkerCol = col;
					this->mapMarkerRow = row;
				}
				if (stageIndex == Game::latestUnlockedStage) {
					this->mapTargetCol = col;
					this->mapTargetRow = row;
				}
				this->markerFacingLeft = 0;
			}
		}
	}
}

void Game::loadShopSpritesAndHandleInput() {
	Game::spritePacks[17] = Game::loadSpritePack(u"/ms.f"_j, 0);
	this->handleShopInput();
}

void Game::drawFramedBox(Ref<Graphics> g, int32_t x, int32_t y, int32_t w, int32_t h, int32_t color, int32_t frameStyle) {
	int32_t clipH = 0, pos = 0, clipX = 0, clipY = 0, clipW = 0;
	clipX = g->getClipX();
	clipY = g->getClipY();
	clipW = g->getClipWidth();
	clipH = g->getClipHeight();
	g->setClip(x, y, w, h);
	g->setColor(color);
	g->fillRect(x, y, w, h);
	g->setClip(x - 3, y, w + 6, h);
	for (pos = y; pos <= y + h; pos += 8) {
		g->drawImage(Game::uiFrameImages[frameStyle][7], x, pos, 24);
		g->drawImage(Game::uiFrameImages[frameStyle][5], x + w, pos, 20);
	}
	g->setClip(x, y - 3, w, h + 6);
	for (pos = x; pos <= x + w; pos += 8) {
		g->drawImage(Game::uiFrameImages[frameStyle][4], pos, y, 36);
		g->drawImage(Game::uiFrameImages[frameStyle][6], pos, y + h, 20);
	}
	g->setClip(x - 3, y - 3, w + 6, h + 6);
	g->drawImage(Game::uiFrameImages[frameStyle][0], x, y, 40);
	g->drawImage(Game::uiFrameImages[frameStyle][1], x + w, y, 36);
	g->drawImage(Game::uiFrameImages[frameStyle][2], x, y + h, 24);
	g->drawImage(Game::uiFrameImages[frameStyle][3], x + w, y + h, 20);
	g->setClip(clipX, clipY, clipW, clipH);
}

void Game::drawFramedBoxWithTab(Ref<Graphics> g, int32_t x, int32_t y, int32_t w, int32_t h, int32_t color, int32_t frameStyle, int32_t tabW, int32_t tabH) {
	int32_t clipY = 0, clipW = 0, clipH = 0, clipX = 0;
	clipX = g->getClipX();
	clipY = g->getClipY();
	clipW = g->getClipWidth();
	clipH = g->getClipHeight();
	Game::drawFramedBox(g, x, y, w, h, color, frameStyle);
	Game::drawFramedBox(g, x + 10, y - 3 - tabH, tabW, tabH, color, frameStyle);
	g->setClip(x + 10 - 3, y - 3, tabW + 6, 3);
	g->setColor(color);
	g->fillRect(x + 10 - 3, y - 3, tabW + 6, 3);
	g->drawImage(Game::uiFrameImages[frameStyle][3], x + 10, y - 3, 24);
	g->drawImage(Game::uiFrameImages[frameStyle][2], x + 10 + tabW, y - 3, 20);
	g->setClip(clipX, clipY, clipW, clipH);
}

void Game::drawShopScreen() {
	Ref<String> lineYOrText;
	int32_t lineYOrText_n = 0, rowOrImages_n = 0, barX = 0, segmentW = 0, segment = 0, segImageOrBarEnd = 0, filledSegment = 0, s3 = 0, s4 = 0;
	Arr<Ref<Image>> rowOrImages;
	Ref<Object> s0, s1_o, s2_o;
	if (this->shopCursor != this->shopLastDrawnCursor || this->needsFullRedraw) {
		if (this->shopCursor != this->shopLastDrawnCursor) {
			this->needsFullRedraw = 1;
		}
		this->screenGraphics->setClip(0, 0, 240, 320);
		if (this->needsFullRedraw) {
			this->drawWorldMapBackground(this->screenGraphics, 1);
			this->screenGraphics->setColor(0);
			this->screenGraphics->fillRect(0, 0, 240, 15);
			this->screenGraphics->setColor(16777215);
			this->screenGraphics->drawLine(0, 15, 240, 15);
			Game::spritePacks[41]->drawString(this->screenGraphics, Game::langStrings[72], 120, 0, 17);
			Game::drawFramedBox(this->screenGraphics, 10, 35, 220, 90, 4273165, 0);
			if (this->shopItemCost != -1) {
				Game::spritePacks[41]->drawMultilineString(this->screenGraphics, Game::wrapText(this->shopMessage, 200), 120, 280, 17);
			}
			if (this->shopPurchaseMsgPending) {
				this->shopPurchaseMsgPending = 0;
				Game::spritePacks[41]->drawString(this->screenGraphics, this->shopMessage, 120, 191, 1);
			}
			Game::spritePacks[41]->drawMultilineString(this->screenGraphics, this->shopDiamondsText, 120, 260, 17);
			this->drawBackSoftkeyIcon();
			this->drawSelectSoftkeyIcon();
			this->needsFullRedraw = 0;
		}
		if (this->shopCursor != this->shopLastDrawnCursor) {
			this->screenGraphics->setColor(4273165);
			this->screenGraphics->fillRect(20, 43 + (this->shopLastDrawnCursor < 0 ? this->shopCursor : this->shopLastDrawnCursor) * 20 + 2, 7, 9);
		}
		Game::spritePacks[17]->drawFrame(this->screenGraphics, 14, 20, 43 + this->shopCursor * 20 + 2, 0, 0, 0);
		Game::drawFramedBox(this->screenGraphics, 10, 155, 220, 70, 4273165, 0);
		if (this->shopItemCost == -1) {
			s0 = Game::spritePacks[41];
			s1_o = this->screenGraphics;
			s2_o = this->shopMessage;
			s3 = 120;
			s4 = 191;
		} else {
			lineYOrText = jnew<StringBuffer>()->append(Game::langStrings[74])->append(u" "_j)->append(this->shopPriceText->toString())->append(u"\n"_j)->append(Game::langStrings[42])->toString();
			Game::spritePacks[41]->lineSpacing = 0;
			s0 = Game::spritePacks[41];
			s1_o = this->screenGraphics;
			s2_o = lineYOrText;
			s3 = 120;
			s4 = 185;
		}
		cast<SpritePack>(s0)->drawMultilineString(cast<Graphics>(s1_o), cast<String>(s2_o), s3, s4, 1);
		lineYOrText_n = 0;
		for (rowOrImages_n = 0; rowOrImages_n < 4; rowOrImages_n++) {
			lineYOrText_n = 43 + 20 * rowOrImages_n;
			Game::spritePacks[46]->drawFrame(this->screenGraphics, 0 + rowOrImages_n, 27, lineYOrText_n, 0, 0, 0);
			Game::spritePacks[41]->drawString(this->screenGraphics, Game::langStrings[85 + rowOrImages_n], 53, lineYOrText_n, 0);
		}
		rowOrImages = Game::spritePacks[0]->moduleImages[0];
		barX = rowOrImages[11]->getWidth();
		segmentW = rowOrImages[15]->getWidth();
		this->screenGraphics->drawImage(rowOrImages[11], 100, 160, 0);
		for (segment = 0; segment < 8; segment++) {
			segImageOrBarEnd = segment < 4 ? 15 : 13;
			this->screenGraphics->drawImage(rowOrImages[segImageOrBarEnd], 100 + barX, 160, 0);
			barX = barX + segmentW;
		}
		segment = this->shopCursor;
		segImageOrBarEnd = barX;
		barX = barX - segmentW * 4;
		for (filledSegment = 0; filledSegment <= segment; filledSegment++) {
			this->screenGraphics->drawImage(rowOrImages[15], 100 + barX, 160, 0);
			barX = barX + segmentW;
		}
		this->screenGraphics->drawImage(rowOrImages[17], 100 + segImageOrBarEnd, 160, 0);
		if (this->shopCursor != this->shopLastDrawnCursor) {
			this->shopLastDrawnCursor = this->shopCursor;
		}
		return;
	}
}

void Game::setMenuItemValue(int32_t menuIndex, int32_t itemId, int16_t value) {
	int32_t pos = 0;
	pos = 0;
	while (true) {
		if (pos >= Game::menuDefs[menuIndex]->length) {
			return;
		}
		if (itemId != Game::menuDefs[menuIndex][pos]) {
			pos += 2;
			continue;
		}
		break;
	}
	Game::menuDefs[menuIndex][pos + 1] = value;
}

void Game::playSound(int32_t soundId) {
	this->sound->play(soundId);
}

void Game::updateCredits() {
	int32_t pos = 0, y = 0, s1 = 0, s2 = 0, t2 = 0;
	Ref<Object> s0;
	Ref<Game> t1;
	switch (this->screenSubState) {
		case 3:
			Game::creditsText = nullptr;
			JSystem::gc();
			Game::screen = 4;
			this->screenSubState = 2;
			this->openMenu(0);
			this->sound->play(19);
			return;
		case 2:
			if (!Game::isKeyDown(4097)) {
				if (!Game::isKeyDown(262146)) {
					if (!Game::isKeyDown(64)) {
						s0 = this;
						s1 = this->creditsScrollY;
						s2 = 1;
						t1 = cast<Game>(s0);
						t2 = s1 + s2;
						s0 = t1;
						s1 = t2;
						cast<Game>(s0)->creditsScrollY = s1;
					} else {
						if (!this->creditsAfterEnding) {
							this->screenSubState = 3;
						} else {
							this->loadingStep = 0;
							this->loadingStepCount = 8;
							Game::screen = 9;
							this->creditsAfterEnding = 0;
						}
					}
				} else {
					s0 = this;
					s1 = this->creditsScrollY;
					s2 = 3;
					t1 = cast<Game>(s0);
					t2 = s1 + s2;
					s0 = t1;
					s1 = t2;
					cast<Game>(s0)->creditsScrollY = s1;
				}
			} else {
				y = 0;
				if (this->creditsScrollY >= 240) {
					this->creditsScrollY = this->creditsScrollY - 3;
					if (this->creditsScrollY < 240) {
						s0 = this;
						s1 = 240;
						cast<Game>(s0)->creditsScrollY = s1;
					}
				} else {
					s0 = this;
					s1 = this->creditsScrollY;
					s2 = 1;
					t1 = cast<Game>(s0);
					t2 = s1 + s2;
					s0 = t1;
					s1 = t2;
					cast<Game>(s0)->creditsScrollY = s1;
				}
			}
			y = -this->creditsScrollY;
			for (pos = 0; pos < Game::creditsText->length && y <= -340; pos++) {
				if (Game::creditsText[pos] == 10) {
					y += 17;
				}
			}
			this->creditsFirstLine = pos;
			if (this->creditsFirstLine < Game::creditsText->length) {
				return;
			}
			this->creditsFirstLine = 0;
			this->creditsScrollY = 0;
			return;
		default:
			return;
		case 1:
			Game::creditsText = Game::readResource(u"/cr.f"_j, 0);
			pos = 0;
			while (pos < Game::creditsText->length) {
				if (Game::creditsText[pos] != 92 || Game::creditsText[pos + 1] != 110) {
					pos++;
				} else {
					Game::creditsText[pos++] = 10;
					Game::creditsText[pos++] = 32;
				}
			}
			for (pos = 0; Game::creditsText[pos] != 36; pos++) {
			}
			y = 0;
			while (y < Midlet::version->length) {
				Game::creditsText[pos] = Midlet::version[y];
				y++;
				pos++;
			}
			this->screenSubState = 2;
			return;
		case 0:
			this->creditsScrollY = 0;
			this->creditsFirstLine = 0;
			this->screenSubState = 1;
			return;
	}
}

void Game::drawCredits() {
	Ref<Graphics> g;
	int32_t fadeY = 0, lineY = 0, pos = 0, lineStart = 0, scrollOffset = 0, fadeStep = 0;
	if (this->screenSubState == 2) {
		g = this->screenGraphics;
		g->setColor(0, 0, 0);
		g->fillRect(0, 0, 240, 320);
		fadeY = 0;
		lineY = -17;
		pos = this->creditsFirstLine;
		lineStart = this->creditsFirstLine;
		scrollOffset = 0;
		scrollOffset = this->creditsScrollY < 340 ? 340 - this->creditsScrollY - 17 : -(this->creditsScrollY % 17);
		while (pos < Game::creditsText->length && lineY < 340) {
			if (Game::creditsText[pos] == 10) {
				Game::spritePacks[41]->paletteIndex = 0;
				this->drawWrappedRichText(g, Game::creditsText, Game::spritePacks[41], lineStart, pos - lineStart, lineY + scrollOffset, nullptr, 0, 234);
				lineY += 17;
				lineStart = pos + 1;
			}
			pos++;
		}
		fadeY = 0;
		for (fadeStep = 6; fadeStep > 0; fadeStep--) {
			g->setColor(0);
			g->fillRect(0, fadeY, 240, fadeStep);
			g->fillRect(0, 320 - fadeY - fadeStep, 240, fadeStep);
			fadeY = fadeY + (fadeStep + 1);
		}
		this->drawBackSoftkeyIcon();
		return;
	}
}

void Game::updatePopupTimer() {
	if (Game::popupTimeLeft > 0) {
		Game::popupTimeLeft = (int32_t)((int64_t)Game::popupTimeLeft - (JSystem::currentTimeMillis() - this->popupLastTick));
		this->popupLastTick = JSystem::currentTimeMillis();
		if (Game::popupTimeLeft <= 0) {
			this->hidePopup(1);
		}
	}
}

void Game::showPopup(Ref<String> text, int32_t x, int32_t y, int32_t durationMs, int32_t bgColor, int32_t frameStyle) {
	this->popupLastTick = JSystem::currentTimeMillis();
	Game::popupTimeLeft = durationMs;
	this->popupX = x;
	this->popupY = y;
	this->popupText = Game::wrapText(text, 220);
	this->popupBgColor = bgColor;
	this->popupFrameStyle = frameStyle;
}

void Game::hidePopup(bool redraw) {
	Game::popupTimeLeft = 0;
	if (redraw != 0) {
		this->needsFullRedraw = 1;
	}
}

bool Game::isPopupVisible() {
	if (Game::popupTimeLeft <= 0) {
		return 0;
	}
	return 1;
}

void Game::drawPopup() {
	Ref<SpritePack> font;
	int32_t savedLineSpacing = 0, textHeight = 0, textWidth = 0;
	font = Game::spritePacks[41];
	if (Game::popupTimeLeft > 0) {
		savedLineSpacing = font->lineSpacing;
		font->lineSpacing = 3;
		font->measureString(this->popupText);
		textHeight = SpritePack::textHeight;
		textWidth = SpritePack::textWidth;
		if (this->popupX == -1) {
			this->popupX = 240 - textWidth >> 1;
		}
		if (this->popupY == -1) {
			this->popupY = 320 - textHeight >> 1;
		}
		this->screenGraphics->setClip(this->popupX - 6, this->popupY - 3, textWidth + 12, textHeight + 6);
		Game::drawFramedBox(this->screenGraphics, this->popupX - 6, this->popupY - 3, textWidth + 12, textHeight + 6, this->popupBgColor, this->popupFrameStyle);
		font->drawMultilineString(this->screenGraphics, this->popupText, this->popupX, this->popupY, 0);
		font->lineSpacing = savedLineSpacing;
		return;
	}
}

Ref<String> Game::wrapText(Ref<String> text, int32_t maxWidth) {
	int32_t pos = 0, ch = 0, glyph = 0, lineWidth = 0, lastSpacePos = 0, widthAtLastSpace = 0, lastBreakPos = 0, s0 = 0, s1 = 0, s2 = 0, t2 = 0;
	Ref<SpritePack> font;
	Ref<StringBuffer> buffer;
	font = Game::spritePacks[41];
	lineWidth = 0;
	lastSpacePos = 0;
	widthAtLastSpace = 0;
	lastBreakPos = 0;
	buffer = jnew<StringBuffer>(text);
	for (pos = 0; pos <= buffer->length(); pos++) {
		ch = 10;
		if (pos < buffer->length()) {
			ch = buffer->charAt(pos) & 255;
		}
		if (lineWidth <= maxWidth || lastSpacePos == lastBreakPos) {
			if (ch != 10) {
				if (ch <= 32) {
					if (ch == 32) {
						lastSpacePos = pos;
						widthAtLastSpace = lineWidth;
						s0 = lineWidth;
						s1 = font->moduleSizes[0] & 255;
						t2 = s0 + (s1 + font->frameModules[1]);
						s0 = t2;
						lineWidth = s0;
					}
				} else {
					if (ch != 64) {
						ch = SpritePack::charMap[ch] & 255;
						if (ch < font->getFrameModuleCount(0)) {
							glyph = (font->frameModules[ch << 2] & 255) << 1;
							s0 = lineWidth;
							s1 = font->moduleSizes[glyph] & 255;
							s2 = font->frameModules[(ch << 2) + 1];
						} else {
							glyph = ch - font->getFrameModuleCount(0);
							s0 = lineWidth;
							s1 = font->frameBounds[(glyph << 2) + 2] & 255;
							s2 = font->frameBounds[glyph << 2] & 255;
						}
						s1 = s1 - s2;
						t2 = s0 + (s1 + font->frameModules[1]);
						s0 = t2;
						lineWidth = s0;
					} else {
						lineWidth += 14;
					}
				}
			} else {
				s0 = 0;
				lineWidth = s0;
			}
		} else {
			lineWidth = widthAtLastSpace;
			buffer->setCharAt(lastSpacePos, 10);
			pos = lastSpacePos - 1;
			lastBreakPos = lastSpacePos;
		}
	}
	return buffer->toString();
}

void Game::loadUiFont() {
	Arr<int8_t> data;
	if (Game::spritePacks[41] != nullptr) {
		Game::spritePacks[41] = nullptr;
		JSystem::gc();
	}
	Game::spritePacks[41] = jnew<SpritePack>()->init();
	data = Game::readResource(u"/ui.f"_j, 1);
	Game::spritePacks[41]->loadFromBytes(data, 0);
	Game::spritePacks[41]->buildModuleImages(0, 0, -1, -1);
	Game::spritePacks[41]->buildModuleImages(1, 0, -1, -1);
	Game::spritePacks[41]->buildModuleImages(2, 0, -1, -1);
	Game::spritePacks[41]->moduleData = nullptr;
}

void Game::clinit() {
	Arr<bool> t1, t2;
	Arr<int8_t> t3, t4;
	Arr<int32_t> t5, t15, t17, t18, t19;
	Arr<Arr<int16_t>> t6;
	Arr<int16_t> t7, t8, t9, t10, t11, t12, t13, t14;
	Arr<Arr<int32_t>> t16;
	Arr<Ref<String>> t20;
	t1 = newArray<bool>(3);
	t1[0] = 1;
	t1[1] = 0;
	t1[2] = 0;
	Game::worldUnlockedOnMap = t1;
	t2 = newArray<bool>(3);
	t2[0] = 0;
	t2[1] = 0;
	t2[2] = 0;
	Game::elementalDiamondPlaced = t2;
	Game::effectCells = newArray<int8_t>(16);
	Game::effectFrames = newArray<int8_t>(8);
	Game::effectAnims = newArray<int8_t>(8);
	Game::screen = 0;
	Game::returnScreen = Game::screen;
	t3 = newArray<int8_t>(16);
	t3[0] = 0;
	t3[1] = 0;
	t3[2] = -1;
	t3[3] = 0;
	t3[4] = 1;
	t3[5] = 0;
	t3[6] = 0;
	t3[7] = 0;
	t3[8] = 0;
	t3[9] = 1;
	t3[10] = 0;
	t3[11] = -1;
	t3[12] = 0;
	t3[13] = 0;
	t3[14] = 0;
	t3[15] = 0;
	Game::dirDeltas = t3;
	t4 = newArray<int8_t>(7);
	t4[0] = 0;
	t4[1] = 3;
	t4[2] = 4;
	t4[3] = 1;
	t4[4] = 2;
	t4[5] = 5;
	t4[6] = 6;
	Game::oppositeDir = t4;
	Game::saveData = nullptr;
	Game::prefsData = nullptr;
	Game::levelCutscenes = nullptr;
	Game::cutsceneTriggerIds = nullptr;
	Game::itemRaiseFreeze = 0;
	Game::levelBufferImage = nullptr;
	Game::levelBufferGraphics = nullptr;
	Game::bufW = 0;
	Game::bufH = 0;
	Game::bufLeftX = -1;
	Game::bufRightX = -1;
	Game::bufTopY = -1;
	Game::bufBottomY = -1;
	Game::playfieldOverlayImage = nullptr;
	Game::overlayImageX = 0;
	Game::overlayImageY = 0;
	Game::overlayImageAnchor = 0;
	Game::moreGamesBadgeBg = nullptr;
	Game::menuFullRedraw = 0;
	Game::menuRepaintPlayfield = 1;
	Game::cheatCodeProgress = 0;
	t5 = newArray<int32_t>(5);
	t5[0] = 512;
	t5[1] = 16384;
	t5[2] = 131072;
	t5[3] = 131072;
	t5[4] = 4096;
	Game::cheatCodeKeys = t5;
	Game::bankedDiamonds = 0;
	Game::bankedRedDiamonds = 0;
	Game::progressFlagsCopy = 0;
	Game::doorCols = newArray<int8_t>(16);
	Game::doorRows = newArray<int8_t>(16);
	Game::cameraHoldAfterPan = 0;
	Game::liquidFlows = newArray<int64_t>(15);
	Game::liquidEmitters = newArray<int64_t>(15);
	t6 = newArray<Arr<int16_t>>(8);
	t7 = newArray<int16_t>(14);
	t7[0] = 0;
	t7[1] = 0;
	t7[2] = 1;
	t7[3] = 1;
	t7[4] = 6;
	t7[5] = 3;
	t7[6] = 2;
	t7[7] = 2;
	t7[8] = 3;
	t7[9] = 4;
	t7[10] = 4;
	t7[11] = 5;
	t7[12] = 5;
	t7[13] = 6;
	t6[0] = t7;
	t8 = newArray<int16_t>(14);
	t8[0] = 0;
	t8[1] = 25;
	t8[2] = 1;
	t8[3] = 26;
	t8[4] = 2;
	t8[5] = 2;
	t8[6] = 6;
	t8[7] = 4;
	t8[8] = 3;
	t8[9] = 49;
	t8[10] = 4;
	t8[11] = 27;
	t8[12] = 5;
	t8[13] = 6;
	t6[1] = t8;
	t9 = newArray<int16_t>(8);
	t9[0] = 0;
	t9[1] = 28;
	t9[2] = 1;
	t9[3] = 29;
	t9[4] = 2;
	t9[5] = 30;
	t9[6] = 3;
	t9[7] = 31;
	t6[2] = t9;
	t10 = newArray<int16_t>(4);
	t10[0] = 0;
	t10[1] = 32;
	t10[2] = 1;
	t10[3] = 33;
	t6[3] = t10;
	t11 = newArray<int16_t>(4);
	t11[0] = 0;
	t11[1] = 45;
	t11[2] = 1;
	t11[3] = 46;
	t6[4] = t11;
	t12 = newArray<int16_t>(4);
	t12[0] = 0;
	t12[1] = 33;
	t12[2] = 1;
	t12[3] = 50;
	t6[5] = t12;
	t13 = newArray<int16_t>(4);
	t13[0] = 0;
	t13[1] = 25;
	t13[2] = 4;
	t13[3] = 27;
	t6[6] = t13;
	t14 = newArray<int16_t>(4);
	t14[0] = 0;
	t14[1] = 101;
	t14[2] = 1;
	t14[3] = 100;
	t6[7] = t14;
	Game::menuDefs = t6;
	t15 = newArray<int32_t>(3);
	t15[0] = 28;
	t15[1] = 29;
	t15[2] = 30;
	Game::worldNameIds = t15;
	t16 = newArray<Arr<int32_t>>(3);
	t17 = newArray<int32_t>(13);
	t17[0] = 8;
	t17[1] = 9;
	t17[2] = 10;
	t17[3] = 11;
	t17[4] = 12;
	t17[5] = 14;
	t17[6] = 15;
	t17[7] = 16;
	t17[8] = 17;
	t17[9] = 20;
	t17[10] = 21;
	t17[11] = 22;
	t17[12] = 23;
	t16[0] = t17;
	t18 = newArray<int32_t>(13);
	t18[0] = 8;
	t18[1] = 9;
	t18[2] = 10;
	t18[3] = 11;
	t18[4] = 12;
	t18[5] = 14;
	t18[6] = 15;
	t18[7] = 16;
	t18[8] = 17;
	t18[9] = 18;
	t18[10] = 20;
	t18[11] = 21;
	t18[12] = 22;
	t16[1] = t18;
	t19 = newArray<int32_t>(15);
	t19[0] = 8;
	t19[1] = 9;
	t19[2] = 10;
	t19[3] = 11;
	t19[4] = 12;
	t19[5] = 14;
	t19[6] = 15;
	t19[7] = 16;
	t19[8] = 17;
	t19[9] = 18;
	t19[10] = 19;
	t19[11] = 20;
	t19[12] = 21;
	t19[13] = 22;
	t19[14] = 47;
	t16[2] = t19;
	Game::stageNameIds = t16;
	Game::creditsText = nullptr;
	t20 = newArray<Ref<String>>(3);
	t20[0] = u"/w0.bin"_j;
	t20[1] = u"/w1.bin"_j;
	t20[2] = u"/w2.bin"_j;
	Game::worldDataFiles = t20;
	Game::popupTimeLeft = 0;
}

