'use strict';

class Game extends GameCanvas {
	static instance = null;
	boulderHoldTimer = 0;
	keyHoldTimer = 0;
	isHoldingBoulder = 0;
	isKeyReleased = 0;
	shopCursor = 0;
	shopItemCost = 0;
	shopMessage = null;
	isExplorerVisible = 0;
	worldMapNode = 0;
	worldMapCursorX = 0;
	worldMapCursorY = 0;
	worldMapCursorPrevX = 0;
	worldMapCursorPrevY = 0;
	worldMapHintText = null;
	worldMapNodeName = null;
	worldMapCommand = 0;
	isWorldMapCursorMoving = 0;
	worldMapInfoDirty = 0;
	worldMapCursorStep = 0;
	worldMapCursorTargetX = 0;
	worldMapCursorTargetY = 0;
	worldMapCursorFrameCount = 0;
	worldMapCursorFrame = 0;
	medallionX = 0;
	medallionY = 0;
	worldUnlockAnimIndex = 0;
	static worldUnlockedOnMap = null;
	worldUnlockBlinkCount = 0;
	static elementalDiamondPlaced = null;
	gotElementalDiamond = 0;
	placingElementalIndex = 0;
	flyingGemX = 0;
	flyingGemY = 0;
	gemHalfWidth = 0;
	gemHalfHeight = 0;
	gemFlashCounter = 0;
	sparkleFrameCount = 0;
	sparkleFrame = 0;
	creditsAfterEnding = 0;
	anacondaAttackTimer = 0;
	anacondaBlockCol = 0;
	anacondaBlockRow = 0;
	bossRockSpawnRow = 0;
	bossRockCol1 = 0;
	bossRockCol2 = 0;
	bossRockCheckRow = 0;
	anacondaStateWhenHit = 0;
	anacondaHitPlayer = 0;
	anacondaSlamVisible = 0;
	anacondaRiseOffset = 0;
	worldUnlockToAnnounce = 0;
	armorUnlockToAnnounce = 0;
	endingPhase = 0;
	endingFlashColor = 0;
	medallionShakeX = 0;
	medallionShakeY = 0;
	medallionShakeDirY = 0;
	medallionShakeDirX = 0;
	medallionShakeRangeY = 0;
	medallionShakeRangeX = 0;
	medallionShakeSpeedY = 0;
	medallionShakeSpeedX = 0;
	hasWaterLayer = 0;
	diamondsToOpenExit = 0;
	exitDoorCol = 0;
	exitDoorRow = 0;
	static effectCells = null;
	static effectFrames = null;
	static effectAnims = null;
	effectQueueHead = 0;
	effectQueueTail = 0;
	checkpointSwimFlag = 0;
	static vibrationEnabled = 0;
	checkpointDiamondsToOpenExit = 0;
	loadingTipIndex = 0;
	static keys = 0;
	isExplorerOnGround = 0;
	hudNeedsRedraw = 0;
	redDiamondPickCount = 0;
	checkpointRedDiamondPickCount = 0;
	static redDiamondPickCells = null;
	specialStageType = 0;
	checkpointTextEndFrame = 0;
	floodHeight = 0;
	floodTriggerStage = 0;
	compassDirection = 0;
	hasCompass = 0;
	bossState = 0;
	bossTimer = 0;
	bossHealth = 0;
	anacondaHoleIndex = 0;
	yetiX = 0;
	knightX = 0;
	introTrigger13Reached = 0;
	introTrigger16Reached = 0;
	introHintSpotReached = 0;
	introHintIconVisible = 0;
	frozenShakeX = 0;
	frozenShakeY = 0;
	static freezeRays = null;
	freezeRayCount = 0;
	playerIdleCountdown = 0;
	entryWalkRemaining = 0;
	requestedMoveDir = 0;
	currentMoveDir = 0;
	lives = 0;
	world = 0;
	stage = 0;
	camX = 0;
	camY = 0;
	camTargetX = 0;
	camTargetY = 0;
	levelW = 0;
	levelH = 0;
	nextCheckpointIndex = 0;
	hintBubbleImageSet = 0;
	hintBubbleFrame = 0;
	heldItemImageSet = 0;
	heldItemFrame = 0;
	heldItemAmount = 0;
	pickedItemType = 0;
	objectSpriteSet = 0;
	objectSpriteFrame = 0;
	terrainSpriteSet = 0;
	terrainSpriteFrame = 0;
	pistonSlowExtent = 0;
	pistonSlowSegments = 0;
	pistonFastExtent = 0;
	pistonFastSegments = 0;
	static screen = 0;
	screenSubState = 0;
	static returnScreen = 0;
	resultsSkipPressed = 0;
	static frameCount = 0;
	static drawCount = 0;
	startTime = 0n;
	frameSkipped = 0;
	playerCol = 0;
	playerRow = 0;
	playerStep = 0;
	explorerStateFlags = 0;
	encasedStruggleCount = 0;
	checkpointSavePending = 0;
	goldKeys = 0;
	silverKeys = 0;
	isExitingLevel = 0;
	explorerEnergy = 0;
	deathTimer = 0;
	invulnTimer = 0n;
	pushDelay = 0;
	diamondsInStage = 0;
	diamondCount = 0;
	redDiamondsInStage = 0;
	redDiamondCount = 0;
	hitsTaken = 0;
	livesLostInStage = 0;
	slidingObjParams = 0;
	slidingObjSavedParams = 0;
	slidingObjSubStep = 0;
	slidingObjCol = 0;
	slidingObjRow = 0;
	slideCellsLeft = 0;
	shakeTime = 0;
	shake = 0;
	deathLetterboxHeight = 0;
	pendingCutsceneId = 0;
	stuckWarned = 0;
	stageIntroEndFrame = 0;
	diamondsNeededText = null;
	menuItemChosen = 0;
	menuId = 0;
	prevMenuId = 0;
	menuCursor = 0;
	loadingStepCount = 0;
	loadingStep = 0;
	nextGenPackIndex = 0;
	enemyPackFlags = 0;
	explorerScreenX = 0;
	explorerScreenY = 0;
	cellDrawX = 0;
	cellDrawY = 0;
	landingDustOffX = 0;
	landingDustOffY = 0;
	landingDustCol = 0;
	landingDustRow = 0;
	hasLandingDust = 0;
	landingDustFrame = 0;
	updateCellCol = 0;
	updateCellRow = 0;
	paintCellCol = 0;
	paintCellRow = 0;
	paintCellTerrain = 0;
	paintCellObject = 0;
	cellAnimIndex = 0;
	cellAnimFrame = 0;
	cellDrawFlip = 0;
	cellDrawOffsetX = 0;
	cellDrawOffsetY = 0;
	cellDrawAnchor = 0;
	explorerDrawMoveDir = 0;
	sparklePhase = 0;
	checkpointCol = 0;
	checkpointRow = 0;
	checkpointGoldKeys = 0;
	checkpointSilverKeys = 0;
	checkpointEntryWalk = 0;
	checkpointDiamonds = 0;
	checkpointRedDiamonds = 0;
	checkpointNextIndex = 0;
	checkpointRisingHazardPhase = 0;
	checkpointRisingHazardHeight = 0;
	quit = 0;
	packEntryCount = 0;
	packSkipBytes = 0;
	resourceStream = null;
	exitWalkDir = 0;
	altExitWalkDir = 0;
	fromStageClear = 0;
	switchWallsPhase = 0;
	leverMoveDir = 0;
	checkpointLeverPos = 0;
	checkpointLeverDir = 0;
	screenGraphics = null;
	static titleLogoImage = null;
	static titleBackgroundImage = null;
	static titleBottomImage = null;
	static objectFrameImages = null;
	static uiFrameImages = null;
	static spritePacks = null;
	static tipSprites = null;
	static tipPageData = null;
	static actors = null;
	static curObjectSprites = null;
	static dirDeltas = null;
	static oppositeDir = null;
	levelResourceMask = 0n;
	levelExtraResourceMask = 0n;
	isNewGame = 0;
	static saveData = null;
	static prefsData = null;
	static cellObjects = null;
	static cellStates = null;
	static cellTypes = null;
	static cellMoveOffsets = null;
	static cellUpdateTimers = null;
	static compassTargets = null;
	respawnPanActive = 0;
	camPanTargetX = 0;
	camPanTargetY = 0;
	camPanSpeed = 0;
	gateRevealState = 0;
	static gateObjectiveMsgs = null;
	static gateRemainingCounts = null;
	static activeGateId = 0;
	static checkpointGateId = 0;
	static genFileTable = null;
	static checkpointCellStates = null;
	static checkpointCellObjects = null;
	static checkpointCellMoveOffsets = null;
	static checkpointCellTypes = null;
	static checkpointGateCounts = null;
	sound = null;
	activeCutscene = null;
	static levelCutscenes = null;
	static cutsceneTriggerIds = null;
	gameThread = null;
	static midlet = null;
	killerCol = 0;
	killerRow = 0;
	killerDrawY = 0;
	killerDrawX = 0;
	killerFrame = 0;
	static killerSprites = null;
	killerAnim = 0;
	checkpointMsgCount = 0;
	static itemRaiseFreeze = 0;
	frameStart = 0n;
	frameUpdated = 0n;
	frameTime = 0n;
	titleShown = 0;
	needFreeMenuRes = 0;
	needFreeMapRes = 0;
	needSaveStageResult = 0;
	needLevelCleanup = 0;
	needFreeCutscenes = 0;
	needGarbageCollect = 0;
	needReadSaveStats = 0;
	needWriteSave = 0;
	playerPaletteIndex = 0;
	prefsDataSize = 0;
	saveDataSize = 0;
	noSavedProgress = 0;
	stageWasCompleted = 0;
	unlockFromNodeX = 0;
	unlockFromNodeY = 0;
	newGamePromptDirty = 0;
	loadingFullRedraw = 0;
	cheatMaxEnergy = 0;
	cheatWeaponFlags = 0;
	cheatUnlockAllStages = 0;
	cheatUnlockSecretStages = 0;
	blockStripAnimFrame = 0;
	static levelBufferImage = null;
	static levelBufferGraphics = null;
	static bufW = 0;
	static bufH = 0;
	static bufLeftX = 0;
	static bufRightX = 0;
	static bufTopY = 0;
	static bufBottomY = 0;
	camCellX = 0;
	camCellY = 0;
	camOffX = 0;
	camOffY = 0;
	static playfieldOverlayImage = null;
	static overlayImageX = 0;
	static overlayImageY = 0;
	static overlayImageAnchor = 0;
	hudShownEnergy = 0;
	hudShownDiamonds = 0;
	hudShownRedDiamonds = 0;
	hudShownLives = 0;
	hudShownDiamondsLeft = 0;
	hudShownKeysA = 0;
	hudShownKeysB = 0;
	hudFrame19Visible = 0;
	exitOpenMsgTime = 0n;
	menuTick = 0;
	menuItemCount = 0;
	menuMaxItemWidth = 0;
	menuTextScrollStep = 0;
	menuTextScrollX = 0;
	menuItemsRevealed = 0;
	menuRevealDelay = 0;
	menuConfirmStep = 0;
	menuConfirmStepTime = 0n;
	menuLastDrawnItem = 0;
	static moreGamesBadgeBg = null;
	static menuFullRedraw = 0;
	static menuRepaintPlayfield = 0;
	menuMoveLockTime = 0n;
	hasSavedGame = 0;
	menuSaveRecheck = 0;
	bossStepDoneThisFrame = 0;
	shopPurchaseMsgPending = 0;
	cheatPassLevels = 0;
	debugTextPage = 0;
	debugTextIndices = null;
	static cheatCodeProgress = 0;
	static cheatCodeKeys = null;
	static bankedDiamonds = 0;
	static bankedRedDiamonds = 0;
	static progressFlagsCopy = 0;
	stageMedalsBefore = 0;
	stageMedalsNew = 0;
	newStageUnlocked = 0;
	static doorCols = null;
	static doorRows = null;
	lastLeverAnimTime = 0n;
	bossAttackPending = 0;
	bossAttackOffset = 0;
	bossWokenUp = 0;
	bossQuakeFrame = 0n;
	ceilingCollapseFrame = 0n;
	paused = 0;
	resumeMenuMusic = 0;
	pausedElapsedTime = 0n;
	levelHasLockType9 = 0;
	levelHasLockType8 = 0;
	levelHasBlock35 = 0;
	bossTreasureTaken = 0;
	hintText = null;
	hintTimer = 0;
	panDoorCol = 0;
	panDoorRow = 0;
	doorPanTimer = 0;
	static cameraHoldAfterPan = 0;
	static hitTestAX = 0;
	static hitTestAY = 0;
	static hitTestBX = 0;
	static hitTestBY = 0;
	moreGamesScreen = null;
	showMoreGamesBadge = 0;
	liquidStartNextEmitter = 0;
	liquidDrainTick = 0;
	liquidPoolRiseCount = 0;
	liquidSpareCounter = 0;
	liquidFillTargetSlot = 0;
	liquidNextEmitter = 0;
	liquidEmitterCount = 0;
	liquidBreachCol = 0;
	liquidBreachRow = 0;
	liquidBreachDir = 0;
	liquidDrainFlow = 0;
	liquidDrainStopRow = 0;
	liquidFlowTick = 0;
	liquidState = 0;
	savedLiquidState = 0;
	savedLiquidDrainTick = 0;
	savedLiquidPoolRiseCount = 0;
	savedLiquidSpareCounter = 0;
	savedLiquidFillTargetSlot = 0;
	savedLiquidBreachCol = 0;
	savedLiquidBreachRow = 0;
	savedLiquidBreachDir = 0;
	savedLiquidDrainFlow = 0;
	savedLiquidDrainStopRow = 0;
	savedLiquidFlowTick = 0;
	static liquidSprites = null;
	static liquidCells = null;
	static liquidFlows = null;
	static liquidEmitters = null;
	static savedLiquidCells = null;
	static savedLiquidFlows = null;
	static savedLiquidEmitters = null;
	static savedLiquidStartNextEmitter = 0;
	savedLiquidNextEmitter = 0;
	savedLiquidEmitterCount = 0;
	static stageMapNodes = null;
	static stageLabelPrefix = null;
	static secretStageLabelPrefix = null;
	static scratchText = null;
	static stageMapImage = null;
	static stageMapGraphics = null;
	firstSecretStage = 0;
	mapPathsDrawnMask = 0;
	markerWalkX = 0;
	markerWalkY = 0;
	markerWalkError = 0;
	markerWalkDx = 0;
	markerWalkDy = 0;
	markerWalkMajor2 = 0;
	markerWalkMinor2 = 0;
	markerWalkStepX = 0;
	markerWalkStepY = 0;
	markerWalkRestart = 0;
	markerFacingLeft = 0;
	mapMarkerCol = 0;
	mapMarkerRow = 0;
	mapTargetCol = 0;
	mapTargetRow = 0;
	static latestUnlockedStage = 0;
	pathDotX = 0;
	pathDotY = 0;
	pathDotError = 0;
	pathDotDx = 0;
	pathDotDy = 0;
	pathDotMajor2 = 0;
	pathDotMinor2 = 0;
	pathDotStep = 0;
	unlockPathShown = 0;
	recordUnlockPath = 0;
	unlockRevealDone = 0;
	unlockPathPoints = null;
	unlockPathCoordCount = 0;
	unlockPathDotsShown = 0;
	unlockPathDotDelay = 0;
	unlockFlashFrame = 0;
	unlockNodeBlinkTimer = 0;
	unlockPathReversed = 0;
	usedMainExit = 0;
	stageMapImageNeeded = 0;
	stageSelectLockTime = 0n;
	shopLastDrawnCursor = 0;
	shopDiamondsText = null;
	shopPriceText = null;
	needsFullRedraw = 0;
	stageMapAnimating = 0;
	creditsScrollY = 0;
	creditsFirstLine = 0;
	static menuDefs = null;
	static worldNameIds = null;
	static stageNameIds = null;
	static langStrings = null;
	static creditsText = null;
	static worldDataFiles = null;
	static popupTimeLeft = 0;
	popupLastTick = 0n;
	popupText = null;
	popupX = 0;
	popupY = 0;
	popupBgColor = 0;
	popupFrameStyle = 0;

	init(midletRef) {
		let t1;
		super.init(0);
		this.boulderHoldTimer = 40;
		this.isHoldingBoulder = 0;
		this.shopCursor = 0;
		this.shopItemCost = Tables.upgradeCosts[this.shopCursor];
		this.shopMessage = "";
		this.isExplorerVisible = 1;
		this.worldMapNode = 0;
		this.worldMapCursorX = 0;
		this.worldMapCursorY = 0;
		this.worldMapCursorPrevX = this.worldMapCursorX;
		this.worldMapCursorPrevY = this.worldMapCursorY;
		this.worldMapHintText = "";
		this.worldMapNodeName = "";
		this.worldMapCommand = -1;
		this.isWorldMapCursorMoving = 0;
		this.worldMapInfoDirty = 1;
		this.worldMapCursorStep = 0;
		this.worldMapCursorTargetX = 0;
		this.worldMapCursorTargetY = 0;
		this.worldMapCursorFrameCount = 0;
		this.worldMapCursorFrame = 0;
		this.medallionX = 0;
		this.medallionY = 0;
		this.worldUnlockAnimIndex = 0;
		this.worldUnlockBlinkCount = 0;
		this.gotElementalDiamond = 0;
		this.placingElementalIndex = -1;
		this.flyingGemX = 10;
		this.flyingGemY = 10;
		this.gemHalfWidth = 0;
		this.gemHalfHeight = 0;
		this.gemFlashCounter = 0;
		this.sparkleFrameCount = 0;
		this.sparkleFrame = 0;
		this.creditsAfterEnding = 0;
		this.anacondaAttackTimer = 0;
		this.anacondaBlockCol = -1;
		this.anacondaBlockRow = -1;
		this.bossRockSpawnRow = 0;
		this.bossRockCol1 = 0;
		this.bossRockCol2 = 0;
		this.bossRockCheckRow = 0;
		this.anacondaStateWhenHit = 0;
		this.anacondaHitPlayer = 0;
		this.anacondaSlamVisible = 0;
		this.anacondaRiseOffset = 0;
		this.worldUnlockToAnnounce = 0;
		this.armorUnlockToAnnounce = 0;
		this.endingPhase = 0;
		this.endingFlashColor = 0;
		this.medallionShakeX = 0;
		this.medallionShakeY = 0;
		this.medallionShakeDirY = 1;
		this.medallionShakeDirX = 1;
		this.medallionShakeRangeY = 3;
		this.medallionShakeRangeX = 3;
		this.medallionShakeSpeedY = 2;
		this.medallionShakeSpeedX = 0;
		this.hasWaterLayer = 0;
		this.loadingTipIndex = 0;
		this.isExplorerOnGround = 1;
		this.specialStageType = 0;
		this.checkpointTextEndFrame = 0;
		this.introTrigger13Reached = 0;
		this.introTrigger16Reached = 0;
		this.introHintSpotReached = 0;
		this.introHintIconVisible = 0;
		this.requestedMoveDir = 0;
		this.currentMoveDir = 0;
		this.resultsSkipPressed = 0;
		this.diamondsInStage = 0;
		this.redDiamondsInStage = 0;
		this.pendingCutsceneId = -1;
		this.landingDustFrame = 0;
		this.checkpointEntryWalk = 0;
		this.checkpointDiamonds = 0;
		this.checkpointRedDiamonds = 0;
		this.checkpointNextIndex = 0;
		this.checkpointRisingHazardPhase = 0;
		this.checkpointRisingHazardHeight = 0;
		this.fromStageClear = 0;
		this.isNewGame = 0;
		this.activeCutscene = null;
		this.killerCol = -1;
		this.killerRow = -1;
		this.checkpointMsgCount = 0;
		this.titleShown = 0;
		this.needFreeMenuRes = 0;
		this.needFreeMapRes = 0;
		this.needSaveStageResult = 0;
		this.needLevelCleanup = 0;
		this.needFreeCutscenes = 0;
		this.needGarbageCollect = 0;
		this.needReadSaveStats = 0;
		this.needWriteSave = 0;
		this.playerPaletteIndex = -1;
		this.stageWasCompleted = 0;
		this.newGamePromptDirty = 0;
		this.loadingFullRedraw = 0;
		this.hudShownEnergy = -1;
		this.hudShownDiamonds = -1;
		this.hudShownRedDiamonds = -1;
		this.hudShownLives = -1;
		this.hudShownDiamondsLeft = -1;
		this.hudShownKeysA = -1;
		this.hudShownKeysB = -1;
		this.hudFrame19Visible = 1;
		this.menuTextScrollStep = 2;
		this.menuTextScrollX = 0;
		this.menuRevealDelay = 3;
		this.menuConfirmStep = -1;
		this.menuConfirmStepTime = 0n;
		this.menuLastDrawnItem = -1;
		this.menuMoveLockTime = 0n;
		this.cheatPassLevels = 0;
		this.debugTextPage = 0;
		t1 = new Int32Array(5);
		t1[0] = 0;
		t1[1] = 0;
		t1[2] = 0;
		t1[3] = 0;
		t1[4] = 0;
		this.debugTextIndices = t1;
		this.newStageUnlocked = 0;
		this.lastLeverAnimTime = 0n;
		this.bossAttackOffset = 0;
		this.bossQuakeFrame = 0n;
		this.ceilingCollapseFrame = 0n;
		this.paused = 0;
		this.resumeMenuMusic = 0;
		this.bossTreasureTaken = 0;
		this.hintTimer = 0;
		this.showMoreGamesBadge = 0;
		this.liquidStartNextEmitter = 1;
		this.liquidDrainTick = -1;
		this.liquidFlowTick = -1;
		this.liquidState = 3;
		this.firstSecretStage = 100;
		this.markerWalkRestart = 1;
		this.unlockPathShown = 1;
		this.recordUnlockPath = 1;
		this.unlockRevealDone = 1;
		this.unlockPathDotDelay = 2;
		this.unlockNodeBlinkTimer = 2;
		this.usedMainExit = 1;
		this.stageMapImageNeeded = 1;
		this.stageSelectLockTime = 0n;
		this.shopLastDrawnCursor = -1;
		this.shopPriceText = new StringBuffer();
		this.needsFullRedraw = 1;
		this.stageMapAnimating = 1;
		this.popupLastTick = JSystem.currentTimeMillis();
		Game.instance = this;
		this.hintBubbleImageSet = -1;
		this.heldItemImageSet = -1;
		this.heldItemAmount = -1;
		Game.actors = J.newArray(6);
		Game.spritePacks = J.newArray(61);
		this.loadCharMap();
		Game.objectFrameImages = J.newArray(33);
		Game.uiFrameImages = J.newArray(2);
		Game.midlet = midletRef;
		this.sound = new Sound();
		Game.vibrationEnabled = 1;
		this.setFullScreenMode(1);
		this.requestHudRedraw();
		this.gameThread = new Thread(this);
		this.gameThread.start();
		return this;
	}

	damageExplorer(damage, hitKind, knockbackDir) {
		let explorerActor = null, row = 0, col = 0, animIndex = 0, dir = 0;
		this.heldItemImageSet = -1;
		this.pickedItemType = -1;
		this.heldItemAmount = -1;
		explorerActor = Game.actors[(this.explorerStateFlags & 16384) !== 0 ? 3 : 0];
		animIndex = explorerActor.animIndex;
		if (animIndex !== 40) {
			if (animIndex !== 48) {
				if (animIndex !== 47) {
					if (this.invulnTimer <= 0n && this.deathTimer === 0 && this.slideCellsLeft === 0 && this.currentMoveDir !== 6 && (this.explorerStateFlags & 112) === 0 || this.encasedStruggleCount > 0) {
						this.hitsTaken = this.hitsTaken + 1 | 0;
						this.setExplorerEnergy(this.explorerEnergy - damage << 24 >> 24);
						if (this.deathLetterboxHeight === 0 && this.explorerEnergy === 0) {
							this.bossQuakeFrame = 0n;
							this.killerCol = this.updateCellCol;
							this.killerRow = this.updateCellRow;
							Game.killerSprites = null;
						}
						this.explorerStateFlags = this.explorerStateFlags & -113 | hitKind;
						this.playSound(5);
						switch (hitKind) {
							default:
								this.setExplorerAnim(10);
								B7: {
									if (knockbackDir !== 0) {
										dir = knockbackDir << 24 >> 24;
										while (true) {
											col = this.playerCol - Game.dirDeltas[dir] | 0;
											row = this.playerRow - Game.dirDeltas[dir + 8] | 0;
											if (Game.cellTypes[col][row] >= 0 || (Game.cellObjects[col][row] & 255) << 24 >> 24 >= 0) {
												dir = dir < 4 ? dir + 1 << 24 >> 24 : 1;
												if (dir !== knockbackDir) {
													continue;
												}
												break B7;
											}
											break;
										}
										this.playerCol = col;
										this.playerRow = row;
										this.playerStep = 18;
										this.requestedMoveDir = 0;
										this.explorerStateFlags = this.explorerStateFlags & -8 | dir | 2048;
										return;
									}
								}
								return;
							case 64:
								this.setExplorerAnim(1000);
								return;
							case 16:
								this.frozenShakeY = 0;
								this.frozenShakeX = 0;
								this.encasedStruggleCount = 5;
								Game.cellTypes[this.playerCol][this.playerRow] = 9;
								this.explorerStateFlags = this.explorerStateFlags & -113 | 0;
								Game.cellStates[this.playerCol][this.playerRow] = 138412032;
								Game.cellUpdateTimers[this.playerCol][this.playerRow] = 24;
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

	setExplorerEnergy(energy) {
		let s1;
		this.explorerEnergy = energy;
		B1: {
			if (this.explorerEnergy <= 0) {
				s1 = 0;
				this.explorerEnergy = s1;
				break B1;
			}
			if (this.explorerEnergy > Game.saveData[8]) {
				s1 = Game.saveData[8];
				this.explorerEnergy = s1;
			}
		}
		this.requestHudRedraw();
	}

	openMenu(menuIdToOpen) {
		this.prevMenuId = this.menuId;
		this.menuItemChosen = 0;
		this.menuCursor = 0;
		this.menuId = menuIdToOpen;
		this.menuTick = 0;
		if (menuIdToOpen >= 0) {
			this.layoutMenuItems();
		}
	}

	static isKeyDown(mask) {
		if ((Game.keys & mask) === 0) {
			return 0;
		}
		return 1;
	}

	keyPressed(keyCode) {
		let mask = 0;
		mask = Game.keyMask(keyCode);
		Game.keys = Game.keys | mask;
		this.isKeyReleased = 0;
	}

	keyReleased(keyCode) {
		Game.keys = Game.keys & (Game.keyMask(keyCode) ^ -1);
		this.isKeyReleased = 1;
	}

	resetCounters() {
		this.startTime = JSystem.currentTimeMillis();
		Game.frameCount = 0;
		Game.drawCount = 0;
		this.checkpointTextEndFrame = 0;
	}

	static sleep(millis) {
		let s0;
		if (millis > 0n) {
			JSystem.currentTimeMillis();
			try {
				Thread.sleep(millis);
			} catch (ex) {
				ex = J.exc(ex);
				if (J.isa(ex, "java/lang/Exception")) {
					s0 = ex;
					return;
				}
				else throw ex;
			}
			return;
		}
	}

	run() {
		let error = null;
		this.startTime = JSystem.currentTimeMillis();
		this.resetCounters();
		this.loadPreferences();
		while (true) {
			if (this.quit) {
				this.cleanup();
				this.sound.release();
				Game.midlet.exitGame();
				return;
			}
			Thread.yield();
			if (!this.paused) {
				this.frameStart = JSystem.currentTimeMillis();
				try {
					this.update();
				} catch (ex) {
					ex = J.exc(ex);
					if (J.isa(ex, "java/lang/Exception")) {
						error = ex;
						error.printStackTrace();
						Game.sleep(5000n);
					}
					else throw ex;
				}
				if (!this.quit) {
					if (Game.screen !== 2) {
						Game.frameCount = Game.frameCount + 1 | 0;
					}
					this.frameUpdated = JSystem.currentTimeMillis();
					if (this.frameTime <= 65n) {
						this.paint(this.getGraphics());
						this.flushGraphics();
						this.frameSkipped = 0;
						if (Game.screen !== 2) {
							Game.drawCount = Game.drawCount + 1 | 0;
						}
						this.frameTime = J.labs(BigInt.asIntN(64, JSystem.currentTimeMillis() - this.frameStart));
						Game.sleep(BigInt.asIntN(64, 50n - BigInt.asIntN(64, JSystem.currentTimeMillis() - this.frameStart)));
					} else {
						Game.sleep(BigInt.asIntN(64, BigInt.asIntN(64, 100n - this.frameTime) - this.frameUpdated));
						this.frameSkipped = 1;
						this.frameTime = 0n;
					}
					continue;
				}
				break;
			}
		}
		this.cleanup();
		this.sound.release();
		Game.midlet.exitGame();
	}

	update() {
		let step = 0, s0, t1, t2, t3, t4;
		this.updatePopupTimer();
		this.dispatchKeyInput();
		switch (Game.screen) {
			case 35:
				t2 = this.loadingStep;
				this.loadingStep = t2 + 1 | 0;
				this.runStageCompleteStep(t2);
				this.resetCounters();
				if (this.loadingStep !== 12) {
					return;
				}
				Game.screen = 17;
				this.screenSubState = 0;
				this.playSound(15);
				return;
			case 31:
				return;
			case 29:
				this.updateEndingSequence();
				return;
			case 28:
				T3: {
					try {
						this.loadWorldMapStep(this.loadingStep);
						this.loadingStep = this.loadingStep + 1 | 0;
						if (this.loadingStep !== 11) {
							break T3;
						}
						Game.screen = 27;
						break T3;
						this.resetCounters();
						return;
					} catch (ex) {
						ex = J.exc(ex);
						if (J.isa(ex, "java/lang/Exception")) {
							s0 = ex;
							this.resetCounters();
							return;
						}
						else throw ex;
					}
				}
				this.resetCounters();
				return;
			case 27:
				this.updateWorldMap();
				return;
			case 22:
				this.updateCredits();
				return;
			case 21:
				t1 = this.loadingStep;
				this.loadingStep = t1 + 1 | 0;
				this.loadStageMapStep(t1);
				this.resetCounters();
				return;
			case 20:
				if (Game.frameCount <= 30) {
					return;
				}
				this.fromStageClear = 1;
				this.needLevelCleanup = 1;
				this.needFreeMapRes = 1;
				this.openStageMap();
				return;
			case 17:
				this.advanceStageResults();
				return;
			case 16:
				this.isNewGame = 1;
				this.startLevelLoading();
				Game.keys = 0;
				return;
			case 15:
				this.showPendingUnlockPopup();
				return;
			case 11:
				this.needLevelCleanup = 1;
				this.needFreeMapRes = 1;
				Game.screen = 5;
				this.loadingFullRedraw = 1;
				this.resetCounters();
				return;
			case 9:
				T6: {
					try {
						if ((Game.prefsData[0] & 1) !== 0) {
							this.readSaveRecord();
							step = this.loadingStepCount !== 8 ? this.loadingStep - 24 | 0 : this.loadingStep;
							this.loadMenuResourcesStep(step);
							step++;
							this.loadingStep = this.loadingStep + 1 | 0;
							this.menuSaveRecheck = 1;
							if (step !== 8) {
								break T6;
							}
							if (!this.titleShown) {
								Game.screen = 30;
								this.titleShown = 1;
								this.sound.play(19);
								break T6;
							}
							Game.screen = 4;
							if (this.menuId !== -1) {
								this.screenSubState = 2;
								this.sound.play(19);
								break T6;
							}
							this.screenSubState = 0;
							this.openMenu(0);
							this.sound.play(19);
							break T6;
						}
						this.showMoreGamesBadge = 1;
						this.readSaveRecord();
						step = this.loadingStepCount !== 8 ? this.loadingStep - 24 | 0 : this.loadingStep;
						this.loadMenuResourcesStep(step);
						step++;
						this.loadingStep = this.loadingStep + 1 | 0;
						this.menuSaveRecheck = 1;
						if (step !== 8) {
							break T6;
						}
						if (!this.titleShown) {
							Game.screen = 30;
							this.titleShown = 1;
							this.sound.play(19);
							break T6;
						}
						Game.screen = 4;
						if (this.menuId !== -1) {
							this.screenSubState = 2;
							this.sound.play(19);
							break T6;
						}
						this.screenSubState = 0;
						this.openMenu(0);
						this.sound.play(19);
						break T6;
						this.resetCounters();
						return;
						this.resetCounters();
						return;
						this.resetCounters();
						return;
						this.resetCounters();
						return;
					} catch (ex) {
						ex = J.exc(ex);
						if (J.isa(ex, "java/lang/Exception")) {
							s0 = ex;
							this.resetCounters();
							return;
						}
						else throw ex;
					}
				}
				this.resetCounters();
				return;
			case 8:
				t4 = this.loadingStep;
				this.loadingStep = t4 + 1 | 0;
				this.loadStartupStep(t4);
				this.resetCounters();
				return;
			case 7:
				if (!this.menuItemChosen) {
					return;
				}
				Game.screen = 8;
				this.loadingStep = 0;
				this.loadingStepCount = 32;
				return;
			default:
				return;
			case 6:
				if (Game.frameCount >= 60) {
					Game.langStrings = Game.loadStringTable("/lang.f", 115);
					Game.loadUiFont();
					Game.spritePacks[18] = Game.loadSpritePack("/ui.f", 3);
					this.cleanup();
					this.openMenu(3);
					Game.screen = 7;
					return;
				}
				Game.actors[0].advanceFrame();
				return;
			case 5:
				if (!this.isNewGame || this.loadingStep > 5) {
					this.loadLevelStep();
				} else {
					t3 = this.loadingStep;
					this.loadingStep = t3 + 1 | 0;
					this.buildNewSaveStep(t3);
					for (step = 0; step < 3; step++) {
						Game.elementalDiamondPlaced[step] = 0;
					}
					for (step = 1; step < 3; step++) {
						Game.worldUnlockedOnMap[step] = 0;
					}
					this.resetCounters();
					if (this.loadingStep === 5) {
						this.needWriteSave = 1;
						this.needReadSaveStats = 1;
						this.needGarbageCollect = 1;
						this.world = 0;
						this.stage = 13;
						Game.keys = 0;
					}
				}
				this.resetCounters();
				return;
			case 3:
				this.quit = 1;
				return;
			case 2:
			case 12:
				return;
			case 1:
				this.updatePlaying();
				return;
			case 0:
				Game.actors[0] = new Actor().init_1(Game.loadSpritePack("/ui.f", 0), 0, 0, null);
				Game.actors[0].setAnimation(0);
				Game.screen = 6;
				this.resetCounters();
				return;
		}
	}

	updateMedallionShake() {
		let s1;
		B1: {
			if (this.medallionShakeY >= this.medallionShakeRangeY) {
				s1 = -1;
				this.medallionShakeDirY = s1;
				break B1;
			}
			if (this.medallionShakeY <= (-this.medallionShakeRangeY | 0)) {
				s1 = 1;
				this.medallionShakeDirY = s1;
			}
		}
		this.medallionShakeY = this.medallionShakeY + Math.imul(this.medallionShakeDirY, this.medallionShakeSpeedY) | 0;
		B3: {
			if (this.medallionShakeX >= this.medallionShakeRangeX) {
				s1 = -1;
				this.medallionShakeDirX = s1;
				break B3;
			}
			if (this.medallionShakeY <= (-this.medallionShakeRangeX | 0)) {
				s1 = 1;
				this.medallionShakeDirX = s1;
			}
		}
		this.medallionShakeX = this.medallionShakeX + Math.imul(this.medallionShakeDirX, this.medallionShakeSpeedX) | 0;
	}

	updateEndingSequence() {
		let s1;
		switch (this.endingPhase) {
			case 10:
				this.cleanup();
				this.openMenu(0);
				Game.screen = 22;
				this.screenSubState = 0;
				this.sound.stop();
				break;
			case 9:
				this.needsFullRedraw = 1;
				FallingRocks.scroll(3);
				if (BigInt.asIntN(64, JSystem.currentTimeMillis() - this.startTime) >= 12000n) {
					this.endingPhase = this.endingPhase + 1 | 0;
					this.resetCounters();
					return;
				}
				break;
			case 8:
				FallingRocks.scroll(3);
				this.needsFullRedraw = 1;
				if (BigInt.asIntN(64, JSystem.currentTimeMillis() - this.startTime) >= 15000n) {
					this.endingPhase = this.endingPhase + 1 | 0;
					this.resetCounters();
					return;
				}
				break;
			case 7:
				if (BigInt.asIntN(64, JSystem.currentTimeMillis() - this.startTime) >= 1000n) {
					FallingRocks.rockGrid = J.multiArray(Int8Array, 2, [12, 13]);
					this.endingPhase = this.endingPhase + 1 | 0;
					FallingRocks.spawnTopRow(3);
					this.sound.play(19);
					this.resetCounters();
					return;
				}
				break;
			case 6:
				if (BigInt.asIntN(64, JSystem.currentTimeMillis() - this.startTime) >= 1000n) {
					this.endingPhase = this.endingPhase + 1 | 0;
					this.resetCounters();
					return;
				}
				break;
			case 5:
				if (BigInt.asIntN(64, JSystem.currentTimeMillis() - this.startTime) >= 1000n) {
					this.endingPhase = this.endingPhase + 1 | 0;
					return;
				}
				break;
			case 4:
				if (BigInt.asIntN(64, JSystem.currentTimeMillis() - this.startTime) >= 1000n) {
					this.endingPhase = this.endingPhase + 1 | 0;
					return;
				}
				break;
			case 3:
				if (BigInt.asIntN(64, JSystem.currentTimeMillis() - this.startTime) >= 1000n) {
					this.endingPhase = this.endingPhase + 1 | 0;
					return;
				}
				break;
			case 2:
				this.updateMedallionShake();
				if (BigInt.asIntN(64, JSystem.currentTimeMillis() - this.startTime) >= 10000n) {
					this.medallionShakeX = 0;
					this.medallionShakeY = 0;
					this.resetCounters();
					this.endingPhase = this.endingPhase + 1 | 0;
					return;
				}
				break;
			case 1:
				if (Game.frameCount % 6 < 3) {
					s1 = 1;
				} else {
					this.endingFlashColor = this.endingFlashColor + 1677721 | 0;
					s1 = 0;
				}
				this.needsFullRedraw = s1;
				if (BigInt.asIntN(64, JSystem.currentTimeMillis() - this.startTime) >= 5000n) {
					this.endingPhase = this.endingPhase + 1 | 0;
					this.needsFullRedraw = 1;
					this.resetCounters();
					return;
				}
				break;
			case 0:
				if (BigInt.asIntN(64, JSystem.currentTimeMillis() - this.startTime) >= 3000n) {
					this.endingPhase = this.endingPhase + 1 | 0;
					this.resetCounters();
					return;
				}
				break;
			default:
				break;
		}
	}

	freeWorldMapResources() {
		let index = 0, count = 0;
		this.needFreeMenuRes = 0;
		Game.freeSpritePack(Game.spritePacks[17], 1);
		Game.spritePacks[17] = null;
		count = MoreGames.adImages.length;
		for (index = 0; index < count; index++) {
			MoreGames.adImages[index] = null;
		}
		MoreGames.adImages = null;
		Game.freeSpritePack(Game.spritePacks[10], 1);
		Game.spritePacks[10] = null;
		Game.freeSpritePack(Game.spritePacks[46], 1);
		Game.spritePacks[46] = null;
		Game.freeSpritePack(Game.spritePacks[55], 1);
		Game.spritePacks[55] = null;
		Game.objectFrameImages[8] = null;
		Game.freeSpritePack(Game.spritePacks[59], 1);
		Game.objectFrameImages[3] = null;
		Game.freeSpritePack(Game.spritePacks[17], 1);
		Game.spritePacks[17] = null;
		JSystem.gc();
	}

	loadWorldMapStep(step) {
		let index = 0, value = 0, s0, s1, s2, t4, t6;
		switch (step) {
			case 10:
				if (Game.spritePacks[9] === null) {
					Game.spritePacks[9] = Game.loadSpritePack("/cm.f", 7);
				}
				this.sparkleFrameCount = Game.getAnimDuration(Game.spritePacks[9], 5);
				value = Game.saveData[2];
				for (index = 0; index < 3; index++) {
					if ((value & 1 << index) !== 0) {
						Game.elementalDiamondPlaced[index] = 1;
					}
				}
				this.flyingGemX = 10;
				this.flyingGemY = 10;
				value = Game.saveData[1];
				if ((value & 1) === 0) {
					index = Game.readU16LE(Game.saveData, 6);
					if (index < Tables.worldUnlockRequirements[1]) {
						s0 = Game.worldUnlockedOnMap;
						s1 = 1;
						s2 = 0;
						s0[s1] = s2;
					} else {
						t4 = Game.saveData;
						t4[1] = (t4[1] | 1) << 24 >> 24;
						this.writeSaveRecord();
						this.worldUnlockAnimIndex = 1;
						this.worldMapNode = 1;
					}
				} else {
					s0 = Game.worldUnlockedOnMap;
					s1 = 1;
					s2 = 1;
					s0[s1] = s2;
				}
				B7: {
					if ((value & 2) !== 0) {
						s0 = Game.worldUnlockedOnMap;
						s1 = 2;
						s2 = 1;
						s0[s1] = s2;
						break B7;
					}
					index = Game.readU16LE(Game.saveData, 6);
					if (index < Tables.worldUnlockRequirements[2]) {
						s0 = Game.worldUnlockedOnMap;
						s1 = 2;
						s2 = 0;
						s0[s1] = s2;
					} else {
						t6 = Game.saveData;
						t6[1] = (t6[1] | 2) << 24 >> 24;
						this.writeSaveRecord();
						this.worldUnlockAnimIndex = 2;
						this.worldMapNode = 2;
					}
				}
				this.worldMapCursorX = Tables.worldMapCursorPositions[this.worldMapNode << 1];
				this.worldMapCursorY = Tables.worldMapCursorPositions[(this.worldMapNode << 1) + 1];
				this.worldMapCursorPrevX = this.worldMapCursorX;
				this.worldMapCursorPrevY = this.worldMapCursorY;
				this.updateWorldMapNodeTexts();
				this.worldMapInfoDirty = 1;
				this.needsFullRedraw = 1;
				return;
			case 9:
				try {
					value = Game.loadSpritePackPalette(new StringBuffer("/").append(0).append(".f").toString(), 3, 0);
					Game.objectFrameImages[8] = value.moduleImages[0];
					value = Game.loadSpritePackPalette("/cm.f", 2, 0);
					value.buildModuleImages(0, 0, -1, -1);
					value.buildModuleImages(1, 0, 0, -1);
					Game.spritePacks[59] = value;
					FallingRocks.rockAnimFrameCount = value.moduleImages[0].length;
					value.moduleData = null;
					if (Game.spritePacks[17] === null) {
						Game.spritePacks[17] = Game.loadSpritePack("/ms.f", 0);
					}
				} catch (ex) {
					ex = J.exc(ex);
					if (J.isa(ex, "java/lang/Exception")) {
						s0 = ex;
						return;
					}
					else throw ex;
				}
				return;
			case 8:
				if (Game.spritePacks[52] !== null) {
					return;
				}
				Game.spritePacks[52] = Game.loadSpritePack("/mmv.f", 3);
				return;
			case 7:
				if (Game.spritePacks[53] !== null) {
					return;
				}
				Game.spritePacks[53] = Game.loadSpritePack("/mmv.f", 2);
				return;
			case 6:
				if (Game.spritePacks[54] === null) {
					Game.spritePacks[54] = Game.loadSpritePack("/mmv.f", 1);
				}
				this.gemHalfWidth = Game.getFrameWidth(Game.spritePacks[54], 0) >> 1;
				this.gemHalfHeight = Game.getFrameHeight(Game.spritePacks[54], 0) >> 1;
				return;
			case 5:
				if (Game.spritePacks[55] === null) {
					Game.spritePacks[55] = Game.loadSpritePack("/mmv.f", 4);
					this.worldMapCursorFrameCount = Game.getAnimDuration(Game.spritePacks[55], 0);
					Game.curObjectSprites = Game.spritePacks[55];
				}
				if (Game.spritePacks[18] !== null) {
					return;
				}
				Game.spritePacks[18] = Game.loadSpritePack("/ui.f", 3);
				return;
			case 4:
				this.cleanup();
				MoreGames.adImages = Game.loadSpriteImages("/demoui.f", 0);
				if (Game.spritePacks[10] === null) {
					Game.spritePacks[10] = Game.loadSpritePack("/mmv.f", 0);
				}
				if (Game.spritePacks[46] === null) {
					Game.spritePacks[46] = Game.loadSpritePack("/mmv.f", 5);
				}
				this.medallionX = 240 - Game.getFrameWidth(Game.spritePacks[10], 0) >> 1;
				this.medallionY = 320 - Game.getFrameHeight(Game.spritePacks[10], 0) - 48 >> 1;
				return;
			case 3:
				if (!this.needGarbageCollect) {
					return;
				}
				JSystem.gc();
				this.needGarbageCollect = 0;
				return;
			case 2:
				if (!this.needReadSaveStats) {
					return;
				}
				this.readSaveStats();
				return;
			case 1:
				if (!this.needFreeMapRes) {
					return;
				}
				this.freeStageMapResources();
				return;
			case 0:
				if (!this.needFreeCutscenes) {
					return;
				}
				this.freeLevelCutscenes();
				return;
			default:
				return;
		}
	}

	updateWorldMapNodeTexts() {
		let isUnlocked = 0, s1, s2;
		if (this.worldMapNode !== 3) {
			isUnlocked = Game.isWorldUnlocked(this.worldMapNode);
			if (!isUnlocked) {
				s1 = new StringBuffer().append(Tables.worldUnlockRequirements[this.worldMapNode]).append(" ");
				s2 = Game.langStrings[114].toLowerCase();
			} else {
				s1 = new StringBuffer();
				s2 = Game.langStrings[82];
			}
		} else {
			s1 = new StringBuffer();
			s2 = Game.langStrings[82];
		}
		this.worldMapHintText = s1.append(s2).append(" ").append(Game.langStrings[79]).toString();
		switch (this.worldMapNode) {
			case 3:
				s1 = Game.langStrings;
				s2 = 31;
				this.worldMapNodeName = s1[s2];
				break;
			case 2:
				s1 = Game.langStrings;
				s2 = 30;
				this.worldMapNodeName = s1[s2];
				break;
			case 1:
				s1 = Game.langStrings;
				s2 = 29;
				this.worldMapNodeName = s1[s2];
				break;
			case 0:
				s1 = Game.langStrings;
				s2 = 28;
				this.worldMapNodeName = s1[s2];
				break;
			default:
				break;
		}
	}

	static isWorldUnlocked(worldIndex) {
		let totalDiamonds = 0;
		if (worldIndex === 0 || worldIndex === 3) {
			return 1;
		}
		totalDiamonds = Game.readU16LE(Game.saveData, 6);
		if (totalDiamonds < Tables.worldUnlockRequirements[worldIndex]) {
			return 0;
		}
		return 1;
	}

	showPendingUnlockPopup() {
		let message = null, s0, s1, s2, s3, t1, t2, t3;
		if (this.worldUnlockToAnnounce > 0 || this.armorUnlockToAnnounce > 0) {
			message = new StringBuffer();
			if (this.worldUnlockToAnnounce > 0) {
				message.append(Game.langStrings[92]).append("\n");
				switch (this.worldUnlockToAnnounce) {
					case 2:
						message.append(Game.langStrings[30]);
						t2 = Game.saveData;
						t2[2] = (t2[2] | 8) << 24 >> 24;
						t3 = Game.saveData;
						s0 = t3;
						s1 = 2;
						s2 = t3[2];
						s3 = 16;
						s0[s1] = (s2 | s3) << 24 >> 24;
						break;
					case 1:
						message.append(Game.langStrings[29]);
						t1 = Game.saveData;
						s0 = t1;
						s1 = 2;
						s2 = t1[2];
						s3 = 8;
						s0[s1] = (s2 | s3) << 24 >> 24;
						break;
					default:
						break;
				}
				this.writeSaveRecord();
				this.worldUnlockToAnnounce = 0;
			}
			if (this.armorUnlockToAnnounce > 0) {
				if (message.length() > 0) {
					message.append("\n\n");
				}
				message.append(Game.langStrings[99]).append("\n").append(Game.langStrings[85 + this.armorUnlockToAnnounce - 1]);
				this.armorUnlockToAnnounce = 0;
			}
			if (message.length() > 0) {
				this.showPopup(message.toString(), -1, -1, 5000, 4273165, 0);
			}
		}
	}

	updateWorldMap() {
		let deltaX = 0, deltaY = 0;
		if (!this.frameSkipped) {
			this.worldMapCursorPrevX = this.worldMapCursorX;
			this.worldMapCursorPrevY = this.worldMapCursorY;
		}
		if (!this.isWorldMapCursorMoving) {
			switch (this.worldMapCommand) {
				default:
					deltaX = Tables.worldMapNeighbors[this.worldMapCommand][this.worldMapNode];
					if (deltaX !== -1) {
						this.worldMapNode = deltaX;
						this.isWorldMapCursorMoving = 1;
						this.worldMapCursorTargetX = Tables.worldMapCursorPositions[this.worldMapNode * 2];
						this.worldMapCursorTargetY = Tables.worldMapCursorPositions[this.worldMapNode * 2 + 1];
					}
					break;
				case 4:
					switch (this.worldMapNode) {
						case 3:
							Game.screen = 18;
							break;
						case 2:
							B6: {
								if (!Game.isWorldUnlocked(this.worldMapNode)) {
									break B6;
								}
								this.needFreeMenuRes = 1;
								this.needFreeMapRes = 1;
								this.sound.stop();
								this.world = 2;
								this.stage = 0;
								this.hasWaterLayer = 0;
								Game.screen = 15;
								Game.latestUnlockedStage = this.getSavedLatestStage(this.world);
								this.openStageMap();
								this.hasCompass = 1;
								B7: {
									if (Game.saveData[9] >= 2) {
										break B7;
									}
									Game.saveData[9] = 2;
								}
							}
							break;
						case 1:
							B8: {
								if (!Game.isWorldUnlocked(this.worldMapNode)) {
									break B8;
								}
								this.needFreeMenuRes = 1;
								this.needFreeMapRes = 1;
								this.sound.stop();
								this.world = 1;
								this.stage = 0;
								Game.screen = 15;
								Game.latestUnlockedStage = this.getSavedLatestStage(this.world);
								this.openStageMap();
								this.hasCompass = 1;
								this.hasWaterLayer = 0;
								B9: {
									if (Game.saveData[9] >= 1) {
										break B9;
									}
									Game.saveData[9] = 1;
								}
							}
							break;
						default:
							break;
						case 0:
							this.needFreeMenuRes = 1;
							this.needFreeMapRes = 1;
							this.sound.stop();
							this.world = 0;
							this.hasWaterLayer = 0;
							Game.screen = 15;
							Game.latestUnlockedStage = this.getSavedLatestStage(this.world);
							this.openStageMap();
							break;
					}
					break;
				case -1:
					break;
			}
			this.worldMapCommand = -1;
		} else {
			Game.keys = 0;
			deltaX = this.worldMapCursorTargetX - this.worldMapCursorX | 0;
			deltaY = this.worldMapCursorTargetY - this.worldMapCursorY | 0;
			this.worldMapCursorX = this.worldMapCursorX + J.idiv(deltaX, 8 - this.worldMapCursorStep | 0) | 0;
			this.worldMapCursorY = this.worldMapCursorY + J.idiv(deltaY, 8 - this.worldMapCursorStep | 0) | 0;
			this.worldMapCursorStep = this.worldMapCursorStep + 1 << 24 >> 24;
			if (this.worldMapCursorStep === 8) {
				this.worldMapCursorX = this.worldMapCursorTargetX;
				this.worldMapCursorY = this.worldMapCursorTargetY;
				this.isWorldMapCursorMoving = 0;
				this.worldMapCursorStep = 0;
				this.worldMapInfoDirty = 1;
				this.updateWorldMapNodeTexts();
				return;
			}
		}
	}

	loadStartupStep(step) {
		if (step < 21) {
			if (step === 0) {
				this.sound.open();
			}
			this.sound.load(step);
			if (step === 20) {
				this.sound.close();
			}
			JSystem.gc();
			return;
		}
		switch (step) {
			case 24:
				this.sound.start();
				Game.screen = 9;
				this.openMenu(-1);
				Game.stageLabelPrefix = new StringBuffer(Game.langStrings[8]);
				Game.stageLabelPrefix.delete(Game.stageLabelPrefix.length() - 1 | 0, Game.stageLabelPrefix.length());
				Game.secretStageLabelPrefix = new StringBuffer(Game.langStrings[20]);
				Game.secretStageLabelPrefix.delete(Game.secretStageLabelPrefix.length() - 1 | 0, Game.secretStageLabelPrefix.length());
				Game.scratchText = new StringBuffer("1");
				return;
			default:
				return;
			case 23:
				Game.uiFrameImages[0] = Game.loadSpriteImagesPalette("/demoui.f", 0, 0);
				Game.uiFrameImages[1] = Game.loadSpriteImagesPalette("/demoui.f", 0, 1);
				return;
			case 22:
				Game.spritePacks[0] = Game.loadSpritePack("/ui.f", 2);
				return;
			case 21:
				Game.spritePacks[9] = Game.loadSpritePack("/cm.f", 7);
				return;
		}
	}

	static loadStringTable(path, count) {
		let strings = null, bytes = null, index = 0, error = null, start = 0, length = 0;
		bytes = Game.readResource(path, 0);
		start = 0;
		length = 0;
		index = 0;
		strings = J.newArray(count);
		while (index < count) {
			if (bytes[start + length] !== 0) {
				length++;
			} else {
				try {
					strings[index] = J.newString(bytes, start, length, "ISO-8859-1");
				} catch (ex) {
					ex = J.exc(ex);
					if (J.isa(ex, "java/lang/Exception")) {
						error = ex;
						error.printStackTrace();
					}
					else throw ex;
				}
				start = start + (length + 1) | 0;
				length = 0;
				index++;
			}
		}
		return strings;
	}

	loadLevelStep() {
		let item = 0, step = 0, subStep = 0, s0, s1, B, t1, t2;
		let pc = 0;
		for (;;) { try {
			switch (pc) {
			case 0:
				B = 0;
				step = this.loadingStep;
				if (!this.isNewGame) { pc = 15; continue; }
				pc = 12; continue;
			case 12:
				B = 12;
				step -= 5;
				pc = 15; continue;
			case 15:
				B = 15;
				this.loadingStep = this.loadingStep + 1 | 0;
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
				if (!this.needWriteSave) { pc = 95; continue; }
				pc = 91; continue;
			case 91:
				B = 91;
				this.writeSaveRecord();
				pc = 95; continue;
			case 95:
				B = 95;
				return;
			case 96:
				B = 96;
				if (!this.needReadSaveStats) { pc = 107; continue; }
				pc = 103; continue;
			case 103:
				B = 103;
				this.readSaveStats();
				pc = 107; continue;
			case 107:
				B = 107;
				return;
			case 108:
				B = 108;
				if (!this.needGarbageCollect) { pc = 123; continue; }
				pc = 115; continue;
			case 115:
				B = 115;
				JSystem.gc();
				this.needGarbageCollect = 0;
				pc = 123; continue;
			case 123:
				B = 123;
				return;
			case 124:
				B = 124;
				Game.spritePacks[41].freeModuleImages(1);
				Game.spritePacks[41].freeModuleImages(2);
				pc = 144; continue;
			case 144:
				B = 144;
				return;
			case 145:
				B = 145;
				if (!this.needLevelCleanup) { pc = 156; continue; }
				pc = 152; continue;
			case 152:
				B = 152;
				this.cleanup();
				pc = 156; continue;
			case 156:
				B = 156;
				return;
			case 157:
				B = 157;
				if (!this.needFreeMapRes) { pc = 168; continue; }
				pc = 164; continue;
			case 164:
				B = 164;
				this.freeStageMapResources();
				pc = 168; continue;
			case 168:
				B = 168;
				return;
			case 169:
				B = 169;
				t1 = Game.getSavedTipIndex();
				subStep = t1;
				if (subStep >= 1) { pc = 183; continue; }
				pc = 178; continue;
			case 178:
				B = 178;
				s0 = this;
				s1 = subStep;
				pc = 199; continue;
			case 183:
				B = 183;
				if ((this.loadingTipIndex + 9 | 0) % 9 >= 1) { pc = 202; continue; }
				pc = 197; continue;
			case 197:
				B = 197;
				s0 = this;
				s1 = 1;
				pc = 199; continue;
			case 199:
				B = 199;
				s0.loadingTipIndex = s1;
				pc = 202; continue;
			case 202:
				B = 202;
				Game.loadTipPage(this.loadingTipIndex % 9);
				pc = 212; continue;
			case 212:
				B = 212;
				return;
			case 213:
				B = 213;
				this.loadRedDiamondsInStage();
				pc = 217; continue;
			case 217:
				B = 217;
				return;
			case 218:
				B = 218;
				Game.createLevelBuffer();
				this.loadLevelData();
				pc = 225; continue;
			case 225:
				B = 225;
				return;
			case 226:
				B = 226;
				this.setupLevelCells();
				pc = 230; continue;
			case 230:
				B = 230;
				return;
			case 231:
				B = 231;
				subStep = new StringBuffer("/").append(this.world).append(".f").toString();
				this.resourceStream = J.getClass(this).getResourceAsStream(subStep);
				this.packEntryCount = this.resourceStream.read();
				Game.genFileTable = new Int8Array(this.packEntryCount << 3);
				this.resourceStream.read(Game.genFileTable);
				pc = 303; continue;
			case 303:
				B = 303;
				return;
			case 304:
				B = 304;
				t2 = step - 10 - 1 | 0;
				subStep = t2;
				if (subStep >= 4) { pc = 327; continue; }
				pc = 316; continue;
			case 316:
				B = 316;
				this.loadWorldPackEntry(subStep);
				this.nextGenPackIndex = 0;
				pc = 326; continue;
			case 326:
				B = 326;
				return;
			case 327:
				B = 327;
				subStep -= 4;
				if (subStep < 0) { pc = 346; continue; }
				pc = 334; continue;
			case 334:
				B = 334;
				if (subStep >= 43) { pc = 346; continue; }
				pc = 340; continue;
			case 340:
				B = 340;
				this.loadGenPackEntry(subStep);
				pc = 345; continue;
			case 345:
				B = 345;
				return;
			case 346:
				B = 346;
				subStep -= 43;
				if (subStep < 0) { pc = 386; continue; }
				pc = 353; continue;
			case 353:
				B = 353;
				if (subStep >= 8) { pc = 386; continue; }
				pc = 359; continue;
			case 359:
				B = 359;
				this.loadCommonPackEntry(subStep);
				if (subStep !== 7) { pc = 385; continue; }
				pc = 370; continue;
			case 370:
				B = 370;
				this.resourceStream.close();
				this.resourceStream = null;
				JSystem.gc();
				pc = 385; continue;
			case 385:
				B = 385;
				return;
			case 386:
				B = 386;
				subStep -= 8;
				if (subStep < 0) { pc = 492; continue; }
				pc = 393; continue;
			case 393:
				B = 393;
				if (subStep >= 16) { pc = 492; continue; }
				pc = 399; continue;
			case 399:
				B = 399;
				if (subStep >= Game.levelCutscenes.length) { pc = 433; continue; }
				pc = 407; continue;
			case 407:
				B = 407;
				Game.levelCutscenes[subStep] = new Cutscene().init(this);
				Game.levelCutscenes[subStep].loadScript(Game.cutsceneTriggerIds[subStep]);
				pc = 433; continue;
			case 433:
				B = 433;
				if (subStep !== 15) { pc = 491; continue; }
				pc = 439; continue;
			case 439:
				B = 439;
				if (Game.levelCutscenes.length < 16) { pc = 491; continue; }
				pc = 448; continue;
			case 448:
				B = 448;
				item = 16;
				pc = 451; continue;
			case 451:
				B = 451;
				if (item >= Game.levelCutscenes.length) { pc = 491; continue; }
				pc = 459; continue;
			case 459:
				B = 459;
				Game.levelCutscenes[item] = new Cutscene().init(this);
				Game.levelCutscenes[item].loadScript(Game.cutsceneTriggerIds[item]);
				item++;
				pc = 451; continue;
			case 491:
				B = 491;
				return;
			case 492:
				B = 492;
				subStep -= 16;
				if (subStep < 0) { pc = 760; continue; }
				pc = 499; continue;
			case 499:
				B = 499;
				if (subStep >= 3) { pc = 760; continue; }
				pc = 504; continue;
			case 504:
				B = 504;
				switch (this.specialStageType) {
					case 1: pc = 544; continue;
					case 3: pc = 567; continue;
					case 4: pc = 625; continue;
					case 5: pc = 690; continue;
					default: pc = 759; continue;
				}
			case 544:
				B = 544;
				this.loadFloodStagePackEntry(subStep);
				if (subStep !== 2) { pc = 566; continue; }
				pc = 554; continue;
			case 554:
				B = 554;
				this.resourceStream.close();
				this.resourceStream = null;
				pc = 566; continue;
			case 566:
				B = 566;
				return;
			case 567:
				B = 567;
				if (subStep <= 0) { pc = 572; continue; }
				pc = 571; continue;
			case 571:
				B = 571;
				return;
			case 572:
				B = 572;
				item = Game.loadSpritePackPalette("/mmv.f", 1, 0);
				Game.objectFrameImages[31] = item.moduleImages[0];
				Game.actors[5] = new Actor().init_1(Game.loadSpritePack("/mm1.f", 0), 0, 0, null);
				Game.actors[5].setAnimation(0);
				pc = 624; continue;
			case 624:
				B = 624;
				return;
			case 625:
				B = 625;
				if (subStep < 2) { pc = 631; continue; }
				pc = 630; continue;
			case 630:
				B = 630;
				return;
			case 631:
				B = 631;
				this.loadAnacondaPackEntry(subStep);
				item = Game.loadSpritePackPalette("/mmv.f", 3, 0);
				Game.objectFrameImages[32] = item.moduleImages[0];
				Game.spritePacks[20] = Game.loadSpritePackPalette("/gen0.f", 7, 0);
				if (subStep !== 1) { pc = 689; continue; }
				pc = 677; continue;
			case 677:
				B = 677;
				this.resourceStream.close();
				this.resourceStream = null;
				pc = 689; continue;
			case 689:
				B = 689;
				return;
			case 690:
				B = 690;
				item = Game.loadSpritePackPalette("/mmv.f", 2, 0);
				Game.objectFrameImages[30] = item.moduleImages[0];
				Game.spritePacks[20] = Game.loadSpritePackPalette("/gen0.f", 7, 0);
				Game.actors[5] = new Actor().init_1(Game.loadSpritePack("/b1.f", 0), 0, 0, null);
				Game.actors[5].setAnimation(10);
				pc = 758; continue;
			case 758:
				B = 758;
				return;
			case 759:
				B = 759;
				return;
			case 760:
				B = 760;
				subStep -= 3;
				switch (subStep) {
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
				Game.genFileTable = null;
				s0 = this;
				if (Game.spritePacks[12] !== null) { pc = 868; continue; }
				pc = 826; continue;
			case 826:
				B = 826;
				if (Game.objectFrameImages[6] !== null) { pc = 868; continue; }
				pc = 835; continue;
			case 835:
				B = 835;
				if (Game.spritePacks[58] !== null) { pc = 868; continue; }
				pc = 844; continue;
			case 844:
				B = 844;
				if (this.specialStageType === 1) { pc = 868; continue; }
				pc = 852; continue;
			case 852:
				B = 852;
				if (this.specialStageType === 4) { pc = 868; continue; }
				pc = 860; continue;
			case 860:
				B = 860;
				if (this.specialStageType !== 5) { pc = 872; continue; }
				pc = 868; continue;
			case 868:
				B = 868;
				s1 = 1;
				pc = 873; continue;
			case 872:
				B = 872;
				s1 = 0;
				pc = 873; continue;
			case 873:
				B = 873;
				s0.loadExplorerSprites(s1);
				pc = 1151; continue;
			case 879:
				B = 879;
				this.levelResourceMask = 0n;
				this.levelExtraResourceMask = 0n;
				this.enemyPackFlags = 0;
				this.loadingTipIndex = this.loadingTipIndex + 1 | 0;
				if (this.loadingTipIndex >= 3) { pc = 919; continue; }
				pc = 912; continue;
			case 912:
				B = 912;
				s0 = this.loadingTipIndex;
				pc = 920; continue;
			case 919:
				B = 919;
				s0 = 3;
				pc = 920; continue;
			case 920:
				B = 920;
				Game.setSavedTipIndex(s0);
				this.writeSaveRecord();
				pc = 1151; continue;
			case 930:
				B = 930;
				Game.checkpointCellStates = J.multiArray(Int32Array, 2, [this.levelW, this.levelH]);
				Game.checkpointCellMoveOffsets = J.multiArray(Int8Array, 2, [this.levelW, this.levelH]);
				Game.checkpointCellTypes = J.multiArray(Int8Array, 2, [this.levelW, this.levelH]);
				Game.checkpointCellObjects = J.multiArray(Int32Array, 2, [this.levelW, this.levelH]);
				if (Game.gateRemainingCounts === null) { pc = 1149; continue; }
				pc = 996; continue;
			case 996:
				B = 996;
				Game.checkpointGateCounts = new Int8Array(Game.gateRemainingCounts.length);
				pc = 1151; continue;
			case 1008:
				B = 1008;
				this.createLiquidLayer();
				pc = 1151; continue;
			case 1015:
				B = 1015;
				this.deathLetterboxHeight = 0;
				this.effectQueueTail = 0;
				this.effectQueueHead = 0;
				this.saveCheckpoint();
				pc = 1151; continue;
			case 1037:
				B = 1037;
				this.stageIntroEndFrame = Game.frameCount + 60 | 0;
				this.diamondsNeededText = new StringBuffer(Game.langStrings[38]).append("\n").append(this.diamondsToOpenExit).append(" ").append(Game.langStrings[39]).toString();
				this.requestHudRedraw();
				pc = 1151; continue;
			case 1102:
				B = 1102;
				Game.freeSpritePack(Game.tipSprites, 1);
				Game.tipSprites = null;
				JSystem.gc();
				pc = 1151; continue;
			case 1119:
				B = 1119;
				this.isNewGame = 0;
				Game.tipPageData = null;
				JSystem.gc();
				this.sound.play(16 + this.world | 0);
				Game.screen = 1;
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
		} catch (ex) {
			ex = J.exc(ex);
			if (B >= 0 && B < 95 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 96 && B < 107 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 108 && B < 123 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 124 && B < 144 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 145 && B < 156 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 157 && B < 168 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 169 && B < 212 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 213 && B < 217 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 218 && B < 225 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 226 && B < 230 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 231 && B < 303 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 304 && B < 326 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 327 && B < 345 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 346 && B < 385 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 386 && B < 491 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 492 && B < 566 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 567 && B < 571 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 572 && B < 624 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 625 && B < 630 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 631 && B < 689 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 690 && B < 758 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			if (B >= 760 && B < 1149 && J.isa(ex, "java/lang/Exception")) { s0 = ex; pc = 1150; continue; }
			throw ex;
		} }
	}

	static getArmorPaletteIndex() {
		return Game.saveData[8] - 4 | 0;
	}

	loadExplorerSprites(withAltSprite) {
		let fileTable = null, entrySize = 0, entryCount = 0, data = null, pack = null, stream = null, s0;
		try {
			stream = J.getClass(this).getResourceAsStream("/o.f");
			entryCount = stream.read();
			fileTable = new Int8Array(entryCount << 3);
			stream.read(fileTable);
			entrySize = Game.readS32LE(fileTable, 4);
			data = new Int8Array(entrySize);
			stream.read(data);
			if (withAltSprite === 0) {
				stream.close();
				stream = null;
				JSystem.gc();
			}
			pack = new SpritePack().init();
			pack.loadFromBytes(data, 0);
			this.playerPaletteIndex = Game.getArmorPaletteIndex();
			pack.buildModuleImages(this.playerPaletteIndex, 0, -1, -1);
			pack.paletteIndex = this.playerPaletteIndex;
			pack.moduleData = null;
			Game.actors[0] = new Actor().init_1(pack, 0, 0, null);
			JSystem.gc();
			if (withAltSprite !== 0) {
				entrySize = Game.readS32LE(fileTable, 12);
				data = new Int8Array(entrySize);
				stream.read(data);
				stream.close();
				JSystem.gc();
				pack = new SpritePack().init();
				pack.loadFromBytes(data, 0);
				pack.buildModuleImages(0, 0, -1, -1);
				pack.moduleData = null;
				Game.actors[3] = new Actor().init_1(pack, 0, 0, null);
				JSystem.gc();
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

	getSelectedMenuAction() {
		return Game.menuDefs[this.menuId][this.menuCursor << 1];
	}

	selectMenuItem() {
		Game.spritePacks[41].paletteIndex = 0;
		this.menuItemChosen = 1;
		switch (this.menuId) {
			case 7:
				this.handleConfirmMenuItem();
				return;
			case 5:
				this.handleOptionsMenuItem();
				return;
			default:
				return;
			case 3:
				this.handleSoundPromptMenuItem();
				return;
			case 2:
				this.handleWorldSelectMenuItem();
				return;
			case 1:
				this.handlePauseMenuItem();
				return;
			case 0:
				this.handleMainMenuItem();
				return;
		}
	}

	handleConfirmMenuItem() {
		switch (this.getSelectedMenuAction()) {
			case 1:
				switch (this.screenSubState) {
					case 5:
						Game.screen = 3;
						this.sound.release();
						Game.midlet.notifyDestroyed();
						break;
					case 4:
						this.cleanup();
						Game.screen = 9;
						this.loadingStepCount = 8;
						this.openMenu(-1);
						this.loadingStep = 0;
						break;
					case 3:
						Game.screen = 15;
						this.needLevelCleanup = 1;
						this.needFreeMapRes = 1;
						this.openStageMap();
						break;
					case 1:
						this.startLevelLoading();
						break;
					default:
						break;
				}
				break;
			case 0:
				if (this.prevMenuId === 0) {
					Game.screen = 4;
				}
				this.openMenu(this.prevMenuId);
				break;
			default:
				break;
		}
		this.screenSubState = -1;
	}

	handleOptionsMenuItem() {
		let soundLabelId = 0, vibrationLabelId = 0, s0, s1, s2;
		switch (this.getSelectedMenuAction()) {
			case 1:
				Game.vibrationEnabled = !Game.vibrationEnabled ? 1 : 0;
				vibrationLabelId = 51;
				if (Game.vibrationEnabled) {
					vibrationLabelId = 50;
					Game.vibrateDevice(200);
				}
				s0 = 5;
				s1 = 1;
				s2 = vibrationLabelId;
				Game.setMenuItemValue(s0, s1, s2);
				break;
			case 0:
				Sound.enabled = !Sound.enabled ? 1 : 0;
				if (!Sound.enabled) {
					this.sound.stop();
					this.sound.stop();
					soundLabelId = 33;
				} else {
					soundLabelId = 32;
					this.playSound(0);
				}
				s0 = 5;
				s1 = 0;
				s2 = soundLabelId;
				Game.setMenuItemValue(s0, s1, s2);
				break;
			default:
				break;
		}
	}

	handlePauseMenuItem() {
		switch (this.getSelectedMenuAction()) {
			default:
				this.menuItemChosen = 0;
				return;
			case 6:
				Game.screen = 33;
				this.needsFullRedraw = 1;
				return;
			case 5:
				this.openMenu(7);
				this.screenSubState = 5;
				return;
			case 4:
				this.openMenu(7);
				this.screenSubState = 4;
				return;
			case 3:
				if (this.stage !== 13 || this.world !== 0) {
					this.openMenu(7);
					this.screenSubState = 3;
					return;
				}
				return;
			case 2:
				this.openMenu(5);
				return;
			case 1:
				this.openMenu(7);
				this.screenSubState = 1;
				return;
			case 0:
				Game.screen = 1;
				Game.stageMapImage = null;
				Game.moreGamesBadgeBg = null;
				return;
		}
	}

	startLevelLoading() {
		let s1;
		if (!this.isNewGame) {
			s1 = 92;
		} else {
			s1 = 97;
		}
		this.loadingStepCount = s1;
		this.loadingStep = 0;
		this.needLevelCleanup = 1;
		this.isExitingLevel = 0;
		Game.screen = 11;
		this.requestedMoveDir = 0;
		this.currentMoveDir = 0;
		this.explorerStateFlags = 0;
		this.heldItemFrame = -1;
		this.heldItemImageSet = -1;
		this.invulnTimer = 0n;
	}

	handleWorldSelectMenuItem() {
		switch (this.getSelectedMenuAction()) {
			default:
				Game.screen = 3;
				this.sound.release();
				Game.midlet.exitGame();
				return;
			case 3:
				this.openMenu(4);
				return;
			case 2:
				this.sound.stop();
				this.world = 2;
				this.stage = 0;
				this.hasWaterLayer = 0;
				Game.screen = 15;
				Game.latestUnlockedStage = this.getSavedLatestStage(this.world);
				this.needFreeMapRes = 1;
				this.openStageMap();
				this.hasCompass = 1;
				if (Game.saveData[9] < 2) {
					Game.saveData[9] = 2;
				}
				if (Game.saveData[8] >= 8) {
					return;
				}
				Game.saveData[8] = 8;
				return;
			case 1:
				this.sound.stop();
				this.world = 1;
				this.stage = 0;
				Game.screen = 15;
				Game.latestUnlockedStage = this.getSavedLatestStage(this.world);
				this.needFreeMapRes = 1;
				this.openStageMap();
				this.hasCompass = 1;
				this.hasWaterLayer = 0;
				if (Game.saveData[9] >= 1) {
					return;
				}
				Game.saveData[9] = 1;
				return;
			case 0:
				this.sound.stop();
				this.world = 0;
				this.hasWaterLayer = 0;
				Game.screen = 15;
				Game.latestUnlockedStage = this.getSavedLatestStage(this.world);
				this.needFreeMapRes = 1;
				this.openStageMap();
				return;
		}
	}

	handleSoundPromptMenuItem() {
		let soundLabelId = 0, s0;
		soundLabelId = 0;
		switch (this.getSelectedMenuAction()) {
			case 1:
				Sound.enabled = 0;
				s0 = 33;
				soundLabelId = s0;
				break;
			case 0:
				Sound.enabled = 1;
				s0 = 32;
				soundLabelId = s0;
				break;
			default:
				break;
		}
		this.screenSubState = 0;
		Game.setMenuItemValue(5, 0, soundLabelId);
	}

	handleMainMenuItem() {
		switch (this.getSelectedMenuAction()) {
			default:
				this.menuItemChosen = 0;
				return;
			case 6:
				this.menuItemChosen = 0;
				return;
			case 5:
				this.openMenu(7);
				this.screenSubState = 5;
				return;
			case 4:
				Game.screen = 22;
				this.screenSubState = 0;
				this.sound.stop();
				return;
			case 3:
				Game.screen = 33;
				this.sound.stop();
				this.needsFullRedraw = 1;
				return;
			case 2:
				this.openMenu(5);
				this.sound.stop();
				return;
			case 1:
				this.sound.stop();
				this.readSaveRecord();
				if (Game.saveData === null || !Game.readHasSavedGame()) {
					this.sound.stop();
					if (Game.readHasSavedGame()) {
						this.newGamePromptDirty = 1;
						this.isNewGame = 0;
						Game.screen = 31;
						return;
					}
					this.startNewGame();
					return;
				}
				this.loadingTipIndex = 0;
				this.needReadSaveStats = 1;
				this.hasCompass = 1;
				this.loadingStep = 0;
				Game.screen = 28;
				return;
			case 0:
				this.sound.stop();
				if (Game.readHasSavedGame()) {
					this.newGamePromptDirty = 1;
					this.isNewGame = 0;
					Game.screen = 31;
					return;
				}
				this.startNewGame();
				return;
		}
	}

	moveMenuCursorUp() {
		this.menuCursor = this.menuCursor - 1 | 0;
		if (this.menuCursor < 0) {
			this.menuCursor = (Game.menuDefs[this.menuId].length >> 1) - 1 | 0;
		}
	}

	moveMenuCursorDown() {
		this.menuCursor = J.irem(this.menuCursor + 1 | 0, Game.menuDefs[this.menuId].length >> 1);
	}

	freeLevelCutscenes() {
		let index = 0, count = 0;
		this.needFreeCutscenes = 0;
		if (Game.levelCutscenes !== null) {
			count = Game.levelCutscenes.length;
			for (index = 0; index < count; index++) {
				Game.freeCutscene(Game.levelCutscenes[index]);
				Game.levelCutscenes[index] = null;
			}
		}
		Game.levelCutscenes = null;
		Game.freeSpritePack(Game.spritePacks[42], 1);
		Game.freeSpritePack(Game.spritePacks[43], 1);
		JSystem.gc();
	}

	static freeCutscene(cutscene) {
		let index = 0;
		if (cutscene !== null) {
			if (Cutscene.sprites !== null) {
				for (index = 0; index < Cutscene.sprites.length; index++) {
					Game.freeSpritePack(Cutscene.sprites[index], 1);
					Cutscene.sprites[index] = null;
				}
			}
			if (cutscene.steps !== null) {
				for (index = 0; index < cutscene.steps.length; index++) {
					cutscene.steps[index] = null;
				}
				cutscene.steps = null;
			}
			cutscene.currentStep = null;
			return;
		}
	}

	static freeSpritePack(pack, freeImages) {
		if (pack !== null) {
			pack.unload(freeImages);
			return;
		}
	}

	cleanup() {
		let index = 0, frame = 0, count = 0;
		this.needLevelCleanup = 0;
		this.hudNeedsRedraw = 1;
		this.respawnPanActive = 0;
		this.hintTimer = 0;
		this.hintText = null;
		Game.gateRemainingCounts = null;
		Game.gateObjectiveMsgs = null;
		this.redDiamondPickCount = 0;
		this.checkpointRedDiamondPickCount = 0;
		Game.redDiamondPickCells = null;
		Game.freezeRays = null;
		this.resourceStream = null;
		Game.genFileTable = null;
		Game.stageMapImage = null;
		Game.stageMapGraphics = null;
		Game.levelBufferGraphics = null;
		Game.levelBufferImage = null;
		Game.cutsceneTriggerIds = null;
		Game.compassTargets = null;
		if (Game.levelCutscenes !== null) {
			index = Game.levelCutscenes.length;
			for (count = 0; count < index; count++) {
				Game.freeCutscene(Game.levelCutscenes[count]);
				Game.levelCutscenes[count] = null;
			}
		}
		Game.levelCutscenes = null;
		if (this.activeCutscene !== null) {
			Game.freeCutscene(this.activeCutscene);
			this.activeCutscene = null;
		}
		if (Game.objectFrameImages !== null) {
			for (index = 0; index < 33; index++) {
				if (Game.objectFrameImages[index] !== null) {
					count = Game.objectFrameImages[index].length;
					for (frame = 0; frame < count; frame++) {
						Game.objectFrameImages[index][frame] = null;
					}
					Game.objectFrameImages[index] = null;
				}
			}
		}
		Game.freeSpritePack(Game.liquidSprites, 1);
		JSystem.gc();
		if (Game.spritePacks !== null) {
			for (index = 0; index < 61; index++) {
				if (index !== 41 && index !== 0 && index !== 9 && index !== 18) {
					Game.freeSpritePack(Game.spritePacks[index], 1);
					Game.spritePacks[index] = null;
				}
			}
		}
		if (Game.actors !== null) {
			for (index = 0; index < 6; index++) {
				if (Game.actors[index] !== null) {
					Game.freeSpritePack(Game.actors[index].sprite, 1);
					Game.actors[index].sprite = null;
					Game.actors[index] = null;
				}
			}
		}
		Game.cellStates = null;
		Game.cellObjects = null;
		Game.cellMoveOffsets = null;
		Game.cellTypes = null;
		Game.cellUpdateTimers = null;
		Game.checkpointCellStates = null;
		Game.checkpointCellObjects = null;
		Game.checkpointCellMoveOffsets = null;
		Game.checkpointCellTypes = null;
		Game.checkpointGateCounts = null;
		this.levelResourceMask = 0n;
		this.enemyPackFlags = 0;
		this.hintBubbleImageSet = -1;
		this.heldItemImageSet = -1;
		this.heldItemAmount = -1;
		this.pickedItemType = -1;
		Game.curObjectSprites = null;
		this.cellAnimIndex = -1;
		this.diamondsNeededText = null;
		this.liquidState = 3;
		Game.liquidCells = null;
		Game.savedLiquidCells = null;
		Game.liquidFlows = null;
		Game.savedLiquidFlows = null;
		Game.liquidEmitters = null;
		Game.savedLiquidEmitters = null;
		this.liquidStartNextEmitter = 0;
		this.liquidDrainTick = -1;
		this.liquidPoolRiseCount = 0;
		this.liquidSpareCounter = 0;
		this.liquidFillTargetSlot = 0;
		this.liquidBreachCol = 0;
		this.liquidBreachRow = 0;
		this.liquidBreachDir = 0;
		this.liquidDrainFlow = 0;
		this.liquidDrainStopRow = 0;
		this.liquidFlowTick = -1;
		this.hasWaterLayer = 0;
		Game.freezeRays = null;
		Game.freeTitleImages();
		JSystem.gc();
	}

	requestHudRedraw() {
		this.hudNeedsRedraw = 1;
	}

	loadWorldPackEntry(entryIndex) {
		let entrySize = 0, pack = null, data = null, s0, s1, s2;
		entrySize = Game.readS32LE(Game.genFileTable, entryIndex * 8 + 4 | 0);
		data = new Int8Array(entrySize);
		this.resourceStream.read(data);
		pack = new SpritePack().init();
		pack.loadFromBytes(data, 0);
		pack.buildModuleImages(0, 0, -1, -1);
		switch (entryIndex) {
			case 3:
				s0 = Game.objectFrameImages;
				s1 = 8;
				s2 = pack.moduleImages[0];
				s0[s1] = s2;
				break;
			case 2:
				Game.objectFrameImages[0] = null;
				s0 = Game.spritePacks;
				s1 = 42;
				s2 = pack;
				s0[s1] = s2;
				break;
			case 1:
				B2: {
					if ((this.levelExtraResourceMask & 2n) !== 0n) {
						s0 = Game.spritePacks;
						s1 = 16;
						s2 = pack;
						s0[s1] = s2;
						break B2;
					}
				}
				break;
			case 0:
				B3: {
					if ((this.levelExtraResourceMask & 1n) !== 0n) {
						s0 = Game.spritePacks;
						s1 = 60;
						s2 = pack;
						s0[s1] = s2;
						break B3;
					}
				}
				break;
			default:
				break;
		}
		pack.moduleData = null;
	}

	loadCommonPackEntry(entryIndex) {
		let entrySize = 0, pack = null, data = null, s0, s1, s2;
		try {
			if (entryIndex === 0) {
				this.resourceStream.close();
				this.resourceStream = null;
				JSystem.gc();
				this.resourceStream = J.getClass(this).getResourceAsStream("/cm.f");
				this.packEntryCount = this.resourceStream.read();
				Game.genFileTable = new Int8Array(this.packEntryCount << 3);
				this.resourceStream.read(Game.genFileTable);
			}
			entrySize = Game.readS32LE(Game.genFileTable, entryIndex * 8 + 4 | 0);
			data = new Int8Array(entrySize);
			this.resourceStream.read(data);
			pack = new SpritePack().init();
			pack.loadFromBytes(data, 0);
			pack.buildModuleImages(0, 0, -1, -1);
			switch (entryIndex) {
				case 6:
					Game.spritePacks[43] = pack;
					s0 = Game.objectFrameImages;
					s1 = 20;
					s2 = null;
					s0[s1] = s2;
					break;
				case 5:
					s0 = Game.objectFrameImages;
					s1 = 18;
					s2 = pack.moduleImages[0];
					s0[s1] = s2;
					break;
				case 4:
					s0 = Game.objectFrameImages;
					s1 = 5;
					s2 = pack.moduleImages[0];
					s0[s1] = s2;
					break;
				case 3:
					Game.spritePacks[13] = pack;
					this.freeUnusedCommonPack13Frames();
					break;
				case 2:
					pack.buildModuleImages(1, 0, 0, -1);
					s0 = Game.spritePacks;
					s1 = 59;
					s2 = pack;
					s0[s1] = s2;
					break;
				case 1:
					switch (this.world) {
						case 1:
						case 2:
							if (this.world !== 0) {
								pack.buildModuleImages(this.world, 0, -1, -1);
								pack.freeModuleImages(0);
								pack.paletteIndex = this.world;
							}
							break;
						default:
							break;
					}
					s0 = Game.spritePacks;
					s1 = 56;
					s2 = pack;
					s0[s1] = s2;
					break;
				case 0:
					s0 = Game.objectFrameImages;
					s1 = 11;
					s2 = pack.moduleImages[0];
					s0[s1] = s2;
					break;
				default:
					break;
			}
			pack.moduleData = null;
		} catch (ex) {
			ex = J.exc(ex);
			if (J.isa(ex, "java/lang/Exception")) {
				s0 = ex;
				return;
			}
			else throw ex;
		}
	}

	freeUnusedCommonPack13Frames() {
		let frame = 0;
		if ((this.levelExtraResourceMask & 1n) === 0n) {
			for (frame = 0; frame < 5; frame++) {
				Game.spritePacks[13].moduleImages[0][frame] = null;
			}
		}
	}

	loadGenPackEntry(entryIndex) {
		let localIndex = 0, entrySize = 0, spritePackSlot = 0, frameImageSlot = 0, data = null, pack = null, s0, B, t1;
		let pc = 0;
		for (;;) { try {
			switch (pc) {
			case 0:
				B = 0;
				if (entryIndex % 10 !== 0) { pc = 106; continue; }
				pc = 7; continue;
			case 7:
				B = 7;
				this.resourceStream.close();
				this.resourceStream = null;
				localIndex = new StringBuffer("/gen").append(this.nextGenPackIndex).append(".f");
				this.resourceStream = J.getClass(this).getResourceAsStream(localIndex.toString());
				this.packEntryCount = this.resourceStream.read();
				Game.genFileTable = new Int8Array(this.packEntryCount << 3);
				this.resourceStream.read(Game.genFileTable);
				this.packSkipBytes = 0;
				this.nextGenPackIndex = this.nextGenPackIndex + 1 | 0;
				pc = 106; continue;
			case 106:
				B = 106;
				localIndex = entryIndex - (this.nextGenPackIndex - 1 | 0) * 10 | 0;
				entrySize = Game.readS32LE(Game.genFileTable, localIndex * 8 + 4 | 0);
				if ((this.levelResourceMask & BigInt.asIntN(64, 1n << BigInt(entryIndex & 63))) === 0n) { pc = 984; continue; }
				pc = 144; continue;
			case 144:
				B = 144;
				if (this.packSkipBytes === 0) { pc = 169; continue; }
				pc = 151; continue;
			case 151:
				B = 151;
				this.resourceStream.skip(BigInt(this.packSkipBytes));
				this.packSkipBytes = 0;
				pc = 169; continue;
			case 169:
				B = 169;
				data = new Int8Array(entrySize);
				this.resourceStream.read(data);
				t1 = new SpritePack().init();
				pack = t1;
				pack.loadFromBytes(data, 0);
				if (entryIndex !== 28) { pc = 213; continue; }
				pc = 206; continue;
			case 206:
				B = 206;
				if (!this.levelHasLockType9) { pc = 235; continue; }
				pc = 213; continue;
			case 213:
				B = 213;
				if (entryIndex !== 24) { pc = 226; continue; }
				pc = 219; continue;
			case 219:
				B = 219;
				if (!this.levelHasBlock35) { pc = 235; continue; }
				pc = 226; continue;
			case 226:
				B = 226;
				pack.buildModuleImages(0, 0, -1, -1);
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
				if (!this.levelHasLockType8) { pc = 553; continue; }
				pc = 544; continue;
			case 544:
				B = 544;
				pack.buildModuleImages(1, 0, -1, -1);
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
				if (!this.levelHasLockType9) { pc = 585; continue; }
				pc = 572; continue;
			case 572:
				B = 572;
				Game.objectFrameImages[24] = pack.moduleImages[0];
				pc = 585; continue;
			case 585:
				B = 585;
				if (!this.levelHasLockType8) { pc = 942; continue; }
				pc = 592; continue;
			case 592:
				B = 592;
				pack.buildModuleImages(1, 0, -1, -1);
				Game.objectFrameImages[25] = pack.moduleImages[1];
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
				Game.liquidSprites = pack;
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
				Game.objectFrameImages[15] = null;
				pack.buildModuleImages(1, 0, -1, -1);
				spritePackSlot = 57;
				Game.objectFrameImages[14] = null;
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
				if (this.world !== 2) { pc = 720; continue; }
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
				if (this.world !== 2) { pc = 758; continue; }
				pc = 734; continue;
			case 734:
				B = 734;
				pack.moduleImages = null;
				pack.buildModuleImages(1, 0, -1, -1);
				pack.paletteIndex = 1;
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
				Game.actors[4] = new Actor().init_1(pack, 0, 0, null);
				Game.actors[4].setAnimation(0);
				pc = 942; continue;
			case 799:
				B = 799;
				spritePackSlot = 12;
				pc = 942; continue;
			case 806:
				B = 806;
				if ((this.enemyPackFlags & 2) === 0) { pc = 850; continue; }
				pc = 815; continue;
			case 815:
				B = 815;
				if (this.world !== 2) { pc = 847; continue; }
				pc = 823; continue;
			case 823:
				B = 823;
				pack.moduleImages = null;
				pack.buildModuleImages(2, 0, -1, -1);
				pack.paletteIndex = 2;
				pc = 847; continue;
			case 847:
				B = 847;
				spritePackSlot = 4;
				pc = 850; continue;
			case 850:
				B = 850;
				if ((this.enemyPackFlags & 1) === 0) { pc = 942; continue; }
				pc = 859; continue;
			case 859:
				B = 859;
				Game.spritePacks[21] = new SpritePack().init();
				Game.spritePacks[21].loadFromBytes(data, 0);
				Game.spritePacks[21].buildModuleImages(1, 0, -1, -1);
				Game.spritePacks[21].paletteIndex = 1;
				Game.spritePacks[21].moduleData = null;
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
				if (spritePackSlot === -1) { pc = 956; continue; }
				pc = 948; continue;
			case 948:
				B = 948;
				Game.spritePacks[spritePackSlot] = pack;
				pc = 956; continue;
			case 956:
				B = 956;
				if (frameImageSlot === -1) { pc = 975; continue; }
				pc = 962; continue;
			case 962:
				B = 962;
				Game.objectFrameImages[frameImageSlot] = pack.moduleImages[0];
				pc = 975; continue;
			case 975:
				B = 975;
				pack.moduleData = null;
				pc = 996; continue;
			case 984:
				B = 984;
				this.packSkipBytes = this.packSkipBytes + entrySize | 0;
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
		} catch (ex) {
			ex = J.exc(ex);
			if (B >= 0 && B < 994 && J.isa(ex, "java/io/IOException")) { s0 = ex; pc = 995; continue; }
			throw ex;
		} }
	}

	loadAnacondaPackEntry(entryIndex) {
		let entrySize = 0, pack = null, entryBytes = null, s0;
		T1: {
			try {
				if (entryIndex === 0) {
					this.resourceStream = J.getClass(this).getResourceAsStream("/b0.f");
					this.packEntryCount = this.resourceStream.read();
					Game.genFileTable = new Int8Array(this.packEntryCount * 8 | 0);
					this.resourceStream.read(Game.genFileTable);
				}
				entrySize = Game.readS32LE(Game.genFileTable, entryIndex * 8 + 4 | 0);
				entryBytes = new Int8Array(entrySize);
				this.resourceStream.read(entryBytes);
				pack = new SpritePack().init();
				pack.loadFromBytes(entryBytes, 0);
				pack.buildModuleImages(0, 0, -1, -1);
				pack.moduleData = null;
				switch (entryIndex) {
					case 1:
						Game.spritePacks[40] = pack;
						break T1;
					default:
						return;
					case 0:
						Game.actors[5] = new Actor().init_1(pack, 0, 0, null);
						return;
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
	}

	loadFloodStagePackEntry(entryIndex) {
		let entrySize = 0, pack = null, entryBytes = null, s0;
		T1: {
			try {
				if (entryIndex === 0) {
					this.resourceStream = J.getClass(this).getResourceAsStream("/mm0.f");
					this.packEntryCount = this.resourceStream.read();
					Game.genFileTable = new Int8Array(this.packEntryCount * 8 | 0);
					this.resourceStream.read(Game.genFileTable);
				}
				entrySize = Game.readS32LE(Game.genFileTable, entryIndex * 8 + 4 | 0);
				entryBytes = new Int8Array(entrySize);
				this.resourceStream.read(entryBytes);
				pack = new SpritePack().init();
				pack.loadFromBytes(entryBytes, 0);
				pack.buildModuleImages(0, 0, -1, -1);
				pack.moduleData = null;
				switch (entryIndex) {
					case 2:
						Game.objectFrameImages[27] = pack.moduleImages[0];
						break T1;
					case 1:
						Game.actors[2] = new Actor().init_1(pack, 0, 0, null);
						Game.actors[2].setAnimation(0);
						break T1;
					case 0:
						Game.actors[1] = new Actor().init_1(pack, 0, 0, null);
						Game.actors[1].setAnimation(2);
						return;
					default:
						return;
				}
			} catch (ex) {
				ex = J.exc(ex);
				if (J.isa(ex, "java/lang/Exception")) {
					s0 = ex;
				}
				else throw ex;
			}
		}
	}

	static getSavedTipIndex() {
		let tipIndex = 0;
		tipIndex = Game.saveData[12];
		return tipIndex;
	}

	static setSavedTipIndex(tipIndex) {
		Game.saveData[12] = tipIndex << 24 >> 24;
	}

	static readHasSavedGame() {
		if (Game.saveData !== null) {
			if (Game.saveData[13] !== 0) {
				return 1;
			}
			return 0;
		}
		return 0;
	}

	setHasSavedGameAndSave(hasSave) {
		Game.saveData[13] = hasSave !== 0 ? 1 : 0;
		this.writeSaveRecord();
	}

	loadRedDiamondsInStage() {
		this.redDiamondsInStage = this.getStageRedDiamondTotal(this.world, this.stage);
	}

	saveStageResult() {
		this.needSaveStageResult = 0;
		this.writeLivesToSave();
		this.raiseSavedLatestStage(this.world, Game.latestUnlockedStage);
		this.setStageBankedRedDiamonds(this.world, this.stage, this.redDiamondCount + this.getStageBankedRedDiamonds(this.world, this.stage) | 0);
		this.writeSaveRecord();
	}

	readSaveRecord() {
		let store = null, s0;
		try {
			store = RecordStore.openRecordStore("DiamondRush", 1);
			Game.saveData = store.getRecord(1);
			this.saveDataSize = Game.saveData.length;
			store.closeRecordStore();
		} catch (ex) {
			ex = J.exc(ex);
			if (J.isa(ex, "java/lang/Exception")) {
				s0 = ex;
				return;
			}
			else throw ex;
		}
	}

	writeSaveRecord() {
		let store = null, s0;
		this.needWriteSave = 0;
		try {
			store = RecordStore.openRecordStore("DiamondRush", 1);
			if (store.getNumRecords() !== 0) {
				store.setRecord(1, Game.saveData, 0, this.saveDataSize);
			} else {
				store.addRecord(Game.saveData, 0, this.saveDataSize);
			}
			store.closeRecordStore();
		} catch (ex) {
			ex = J.exc(ex);
			if (J.isa(ex, "java/lang/Exception")) {
				s0 = ex;
				return;
			}
			else throw ex;
		}
	}

	loadPreferences() {
		let store = null, s0;
		store = null;
		try {
			store = RecordStore.openRecordStore("Preferences", 0);
		} catch (ex) {
			ex = J.exc(ex);
			if (J.isa(ex, "java/lang/Exception")) {
				s0 = ex;
				Game.prefsData = new Int8Array(1);
				if (store !== null) {
					try {
						Game.prefsData = store.getRecord(1);
						this.prefsDataSize = Game.prefsData.length;
						store.closeRecordStore();
					} catch (ex) {
						ex = J.exc(ex);
						if (J.isa(ex, "java/lang/Exception")) {
							s0 = ex;
							return;
						}
						else throw ex;
					}
					return;
				}
				try {
					store = RecordStore.openRecordStore("Preferences", 1);
					Game.prefsData[0] = 0;
					this.prefsDataSize = Game.prefsData.length;
					store.closeRecordStore();
					this.savePreferences();
				} catch (ex) {
					ex = J.exc(ex);
					if (J.isa(ex, "java/lang/Exception")) {
						s0 = ex;
						return;
					}
					else throw ex;
				}
				return;
			}
			else throw ex;
		}
		Game.prefsData = new Int8Array(1);
		if (store !== null) {
			Game.prefsData = store.getRecord(1);
			this.prefsDataSize = Game.prefsData.length;
			store.closeRecordStore();
			return;
		}
		store = RecordStore.openRecordStore("Preferences", 1);
		Game.prefsData[0] = 0;
		this.prefsDataSize = Game.prefsData.length;
		store.closeRecordStore();
		this.savePreferences();
	}

	savePreferences() {
		let store = null, s0;
		try {
			store = RecordStore.openRecordStore("Preferences", 1);
			if (store.getNumRecords() !== 0) {
				store.setRecord(1, Game.prefsData, 0, this.prefsDataSize);
			} else {
				store.addRecord(Game.prefsData, 0, this.prefsDataSize);
			}
			store.closeRecordStore();
		} catch (ex) {
			ex = J.exc(ex);
			if (J.isa(ex, "java/lang/Exception")) {
				s0 = ex;
				return;
			}
			else throw ex;
		}
	}

	buildNewSaveStep(step) {
		let colOrRow = 0, width = 0, worldBlockPos = 0, layerBytes = null, stageIndex = 0, store = null, collectibleCount = 0, redDiamondTotal = 0, worldIndex = 0, col = 0, rowOrListHeaderPos = 0, stageCount = 0, stageRecordPos = 0, height = 0, stageMapFile = null, s0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17;
		T1: {
			try {
				stageMapFile = null;
				switch (step) {
					case 2:
						stageMapFile = "/map_angkor.out";
						if (stageMapFile === null) {
							stageMapFile = "/map_scotland.out";
						}
						if (stageMapFile === null) {
							stageMapFile = "/map_tibet.out";
						}
						this.resourceStream = J.getClass(this).getResourceAsStream(Game.worldDataFiles[step - 2]);
						this.resourceStream.read();
						worldIndex = step - 2 | 0;
						worldBlockPos = this.saveDataSize;
						Game.saveData[14 + worldIndex * 2] = (this.saveDataSize & 255) << 24 >> 24;
						Game.saveData[14 + worldIndex * 2 + 1] = (this.saveDataSize >> 8) << 24 >> 24;
						stageCount = this.resourceStream.read();
						t1 = Game.saveData;
						t2 = this.saveDataSize;
						this.saveDataSize = t2 + 1 | 0;
						t1[t2] = stageCount << 24 >> 24;
						t3 = Game.saveData;
						t4 = this.saveDataSize;
						this.saveDataSize = t4 + 1 | 0;
						t3[t4] = 0;
						this.allocStageMapNodes();
						this.loadStageMapFile(stageMapFile);
						t5 = Game.saveData;
						t6 = this.saveDataSize;
						this.saveDataSize = t6 + 1 | 0;
						t5[t6] = this.firstSecretStage << 24 >> 24;
						this.freeStageMapResources();
						this.saveDataSize = this.saveDataSize + (stageCount << 1) | 0;
						for (stageIndex = 0; stageIndex < stageCount; stageIndex++) {
							stageRecordPos = this.saveDataSize;
							Game.saveData[worldBlockPos + 3 + stageIndex * 2] = (stageRecordPos & 255) << 24 >> 24;
							Game.saveData[worldBlockPos + 3 + stageIndex * 2 + 1] = (stageRecordPos >> 8) << 24 >> 24;
							collectibleCount = 0;
							redDiamondTotal = 0;
							width = Game.readUShortLE(this.resourceStream);
							height = Game.readUShortLE(this.resourceStream);
							layerBytes = new Int8Array(Math.imul(width, height));
							this.resourceStream.read(layerBytes);
							for (rowOrListHeaderPos = 0; rowOrListHeaderPos < height; rowOrListHeaderPos++) {
								for (colOrRow = 0; colOrRow < width; colOrRow++) {
									if (layerBytes[colOrRow + Math.imul(rowOrListHeaderPos, width)] === 2) {
										redDiamondTotal = redDiamondTotal + 1 << 24 >> 24;
									}
								}
							}
							t7 = Game.saveData;
							t7[0] = t7[0] + redDiamondTotal << 24 >> 24;
							t8 = Game.saveData;
							t9 = this.saveDataSize;
							this.saveDataSize = t9 + 1 | 0;
							t8[t9] = 0;
							t10 = Game.saveData;
							t11 = this.saveDataSize;
							this.saveDataSize = t11 + 1 | 0;
							t10[t11] = redDiamondTotal;
							t12 = Game.saveData;
							t13 = this.saveDataSize;
							this.saveDataSize = t13 + 1 | 0;
							t12[t13] = 0;
							this.resourceStream.skip(BigInt(Math.imul(width, height)));
							rowOrListHeaderPos = this.saveDataSize;
							this.saveDataSize = this.saveDataSize + 2 | 0;
							this.resourceStream.read(layerBytes);
							for (colOrRow = 0; colOrRow < height; colOrRow++) {
								for (col = 0; col < width; col++) {
									if (layerBytes[col + Math.imul(colOrRow, width)] === 14 || layerBytes[col + Math.imul(colOrRow, width)] === 33) {
										t14 = Game.saveData;
										t15 = this.saveDataSize;
										this.saveDataSize = t15 + 1 | 0;
										t14[t15] = col << 24 >> 24;
										t16 = Game.saveData;
										t17 = this.saveDataSize;
										this.saveDataSize = t17 + 1 | 0;
										t16[t17] = colOrRow << 24 >> 24;
										collectibleCount = collectibleCount + 1 << 24 >> 24;
									}
								}
							}
							Game.saveData[rowOrListHeaderPos] = 0;
							Game.saveData[rowOrListHeaderPos + 1] = collectibleCount;
						}
						this.resourceStream.close();
						this.resourceStream = null;
						JSystem.gc();
						break T1;
					case 3:
						if (stageMapFile === null) {
							stageMapFile = "/map_scotland.out";
						}
						if (stageMapFile === null) {
							stageMapFile = "/map_tibet.out";
						}
						this.resourceStream = J.getClass(this).getResourceAsStream(Game.worldDataFiles[step - 2]);
						this.resourceStream.read();
						worldIndex = step - 2 | 0;
						worldBlockPos = this.saveDataSize;
						Game.saveData[14 + worldIndex * 2] = (this.saveDataSize & 255) << 24 >> 24;
						Game.saveData[14 + worldIndex * 2 + 1] = (this.saveDataSize >> 8) << 24 >> 24;
						stageCount = this.resourceStream.read();
						t1 = Game.saveData;
						t2 = this.saveDataSize;
						this.saveDataSize = t2 + 1 | 0;
						t1[t2] = stageCount << 24 >> 24;
						t3 = Game.saveData;
						t4 = this.saveDataSize;
						this.saveDataSize = t4 + 1 | 0;
						t3[t4] = 0;
						this.allocStageMapNodes();
						this.loadStageMapFile(stageMapFile);
						t5 = Game.saveData;
						t6 = this.saveDataSize;
						this.saveDataSize = t6 + 1 | 0;
						t5[t6] = this.firstSecretStage << 24 >> 24;
						this.freeStageMapResources();
						this.saveDataSize = this.saveDataSize + (stageCount << 1) | 0;
						stageIndex = 0;
						while (true) {
							if (stageIndex >= stageCount) {
								break;
							}
							stageRecordPos = this.saveDataSize;
							Game.saveData[worldBlockPos + 3 + stageIndex * 2] = (stageRecordPos & 255) << 24 >> 24;
							Game.saveData[worldBlockPos + 3 + stageIndex * 2 + 1] = (stageRecordPos >> 8) << 24 >> 24;
							collectibleCount = 0;
							redDiamondTotal = 0;
							width = Game.readUShortLE(this.resourceStream);
							height = Game.readUShortLE(this.resourceStream);
							layerBytes = new Int8Array(Math.imul(width, height));
							this.resourceStream.read(layerBytes);
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
									if (layerBytes[colOrRow + Math.imul(rowOrListHeaderPos, width)] === 2) {
										redDiamondTotal = redDiamondTotal + 1 << 24 >> 24;
									}
									colOrRow++;
								}
								rowOrListHeaderPos++;
							}
							t7 = Game.saveData;
							t7[0] = t7[0] + redDiamondTotal << 24 >> 24;
							t8 = Game.saveData;
							t9 = this.saveDataSize;
							this.saveDataSize = t9 + 1 | 0;
							t8[t9] = 0;
							t10 = Game.saveData;
							t11 = this.saveDataSize;
							this.saveDataSize = t11 + 1 | 0;
							t10[t11] = redDiamondTotal;
							t12 = Game.saveData;
							t13 = this.saveDataSize;
							this.saveDataSize = t13 + 1 | 0;
							t12[t13] = 0;
							this.resourceStream.skip(BigInt(Math.imul(width, height)));
							rowOrListHeaderPos = this.saveDataSize;
							this.saveDataSize = this.saveDataSize + 2 | 0;
							this.resourceStream.read(layerBytes);
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
									if (layerBytes[col + Math.imul(colOrRow, width)] === 14 || layerBytes[col + Math.imul(colOrRow, width)] === 33) {
										t14 = Game.saveData;
										t15 = this.saveDataSize;
										this.saveDataSize = t15 + 1 | 0;
										t14[t15] = col << 24 >> 24;
										t16 = Game.saveData;
										t17 = this.saveDataSize;
										this.saveDataSize = t17 + 1 | 0;
										t16[t17] = colOrRow << 24 >> 24;
										collectibleCount = collectibleCount + 1 << 24 >> 24;
									}
									col++;
								}
								colOrRow++;
							}
							Game.saveData[rowOrListHeaderPos] = 0;
							Game.saveData[rowOrListHeaderPos + 1] = collectibleCount;
							stageIndex++;
						}
						this.resourceStream.close();
						this.resourceStream = null;
						JSystem.gc();
						break T1;
					case 4:
						if (stageMapFile === null) {
							stageMapFile = "/map_tibet.out";
						}
						this.resourceStream = J.getClass(this).getResourceAsStream(Game.worldDataFiles[step - 2]);
						this.resourceStream.read();
						worldIndex = step - 2 | 0;
						worldBlockPos = this.saveDataSize;
						Game.saveData[14 + worldIndex * 2] = (this.saveDataSize & 255) << 24 >> 24;
						Game.saveData[14 + worldIndex * 2 + 1] = (this.saveDataSize >> 8) << 24 >> 24;
						stageCount = this.resourceStream.read();
						t1 = Game.saveData;
						t2 = this.saveDataSize;
						this.saveDataSize = t2 + 1 | 0;
						t1[t2] = stageCount << 24 >> 24;
						t3 = Game.saveData;
						t4 = this.saveDataSize;
						this.saveDataSize = t4 + 1 | 0;
						t3[t4] = 0;
						this.allocStageMapNodes();
						this.loadStageMapFile(stageMapFile);
						t5 = Game.saveData;
						t6 = this.saveDataSize;
						this.saveDataSize = t6 + 1 | 0;
						t5[t6] = this.firstSecretStage << 24 >> 24;
						this.freeStageMapResources();
						this.saveDataSize = this.saveDataSize + (stageCount << 1) | 0;
						stageIndex = 0;
						while (true) {
							if (stageIndex >= stageCount) {
								break;
							}
							stageRecordPos = this.saveDataSize;
							Game.saveData[worldBlockPos + 3 + stageIndex * 2] = (stageRecordPos & 255) << 24 >> 24;
							Game.saveData[worldBlockPos + 3 + stageIndex * 2 + 1] = (stageRecordPos >> 8) << 24 >> 24;
							collectibleCount = 0;
							redDiamondTotal = 0;
							width = Game.readUShortLE(this.resourceStream);
							height = Game.readUShortLE(this.resourceStream);
							layerBytes = new Int8Array(Math.imul(width, height));
							this.resourceStream.read(layerBytes);
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
									if (layerBytes[colOrRow + Math.imul(rowOrListHeaderPos, width)] === 2) {
										redDiamondTotal = redDiamondTotal + 1 << 24 >> 24;
									}
									colOrRow++;
								}
								rowOrListHeaderPos++;
							}
							t7 = Game.saveData;
							t7[0] = t7[0] + redDiamondTotal << 24 >> 24;
							t8 = Game.saveData;
							t9 = this.saveDataSize;
							this.saveDataSize = t9 + 1 | 0;
							t8[t9] = 0;
							t10 = Game.saveData;
							t11 = this.saveDataSize;
							this.saveDataSize = t11 + 1 | 0;
							t10[t11] = redDiamondTotal;
							t12 = Game.saveData;
							t13 = this.saveDataSize;
							this.saveDataSize = t13 + 1 | 0;
							t12[t13] = 0;
							this.resourceStream.skip(BigInt(Math.imul(width, height)));
							rowOrListHeaderPos = this.saveDataSize;
							this.saveDataSize = this.saveDataSize + 2 | 0;
							this.resourceStream.read(layerBytes);
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
									if (layerBytes[col + Math.imul(colOrRow, width)] === 14 || layerBytes[col + Math.imul(colOrRow, width)] === 33) {
										t14 = Game.saveData;
										t15 = this.saveDataSize;
										this.saveDataSize = t15 + 1 | 0;
										t14[t15] = col << 24 >> 24;
										t16 = Game.saveData;
										t17 = this.saveDataSize;
										this.saveDataSize = t17 + 1 | 0;
										t16[t17] = colOrRow << 24 >> 24;
										collectibleCount = collectibleCount + 1 << 24 >> 24;
									}
									col++;
								}
								colOrRow++;
							}
							Game.saveData[rowOrListHeaderPos] = 0;
							Game.saveData[rowOrListHeaderPos + 1] = collectibleCount;
							stageIndex++;
						}
						this.resourceStream.close();
						this.resourceStream = null;
						JSystem.gc();
						break T1;
					default:
						return;
					case 0:
					case 1:
						store = null;
						try {
							store = RecordStore.openRecordStore("DiamondRush", 0);
						} catch (ex) {
							ex = J.exc(ex);
							if (J.isa(ex, "java/lang/Exception")) {
								s0 = ex;
							}
							else throw ex;
						}
						if (store !== null) {
							this.noSavedProgress = 0;
							store.closeRecordStore();
							if (step !== 0) {
								Game.saveData = new Int8Array(1000);
								Game.saveData[3] = 5;
								Game.saveData[8] = 4;
								Game.saveData[9] = 0;
								Game.saveData[10] = 0;
								this.saveDataSize = 14;
								this.saveDataSize = this.saveDataSize + 6 | 0;
							}
						} else {
							this.noSavedProgress = 1;
							B42: {
								if (step !== 0) {
									Game.saveData = new Int8Array(1000);
									Game.saveData[3] = 5;
									Game.saveData[8] = 4;
									Game.saveData[9] = 0;
									Game.saveData[10] = 0;
									this.saveDataSize = 14;
									this.saveDataSize = this.saveDataSize + 6 | 0;
									break B42;
								}
								break B42;
							}
							return;
						}
						return;
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
	}

	writeLivesToSave() {
		Game.saveData[3] = this.lives << 24 >> 24;
		Game.saveData[11] = this.checkpointMsgCount;
	}

	readSaveStats() {
		this.needReadSaveStats = 0;
		this.lives = Game.saveData[3];
		this.checkpointMsgCount = Game.saveData[11];
		this.diamondCount = Game.readU16LE(Game.saveData, 4);
	}

	getStageFlags(world, stage) {
		let recordPos = 0;
		recordPos = this.getStageSaveOffset(world, stage);
		return Game.saveData[recordPos + 2];
	}

	addStageFlags(world, stage, flags) {
		let recordPos = 0, t1, t2;
		recordPos = this.getStageSaveOffset(world, stage);
		t1 = Game.saveData;
		t2 = recordPos + 2 | 0;
		t1[t2] = (t1[t2] | flags) << 24 >> 24;
	}

	raiseSavedLatestStage(world, stage) {
		let latestStagePos = 0;
		latestStagePos = Game.getWorldSaveOffset(world) + 1 | 0;
		if (Game.saveData[latestStagePos] < stage) {
			Game.saveData[latestStagePos] = stage << 24 >> 24;
		}
	}

	getSavedLatestStage(world) {
		let latestStagePos = 0;
		latestStagePos = Game.getWorldSaveOffset(world) + 1 | 0;
		if (latestStagePos < 0 || latestStagePos > Game.saveData.length) {
			return 0;
		}
		return Game.saveData[Game.getWorldSaveOffset(world) + 1];
	}

	static getWorldSaveOffset(world) {
		let s0;
		B1: {
			if (world < 0) {
				s0 = 0;
				world = s0;
				break B1;
			}
			if (world >= 3) {
				s0 = 2;
				world = s0;
			}
		}
		return Game.readU16LE(Game.saveData, 14 + world * 2 | 0);
	}

	getWorldStageCount(world) {
		let s0;
		try {
			s0 = Game.saveData[Game.getWorldSaveOffset(world) + 0];
		} catch (ex) {
			ex = J.exc(ex);
			if (J.isa(ex, "java/lang/Exception")) {
				s0 = ex;
				return 0;
			}
			else throw ex;
		}
		return s0;
	}

	getWorldFirstSecretStage(world) {
		return Game.saveData[Game.getWorldSaveOffset(world) + 2];
	}

	getStageSaveOffset(world, stage) {
		return Game.readU16LE(Game.saveData, Game.getWorldSaveOffset(world) + 3 + stage * 2 | 0);
	}

	getStageBankedRedDiamonds(world, stage) {
		return Game.saveData[this.getStageSaveOffset(world, stage) + 0];
	}

	setStageBankedRedDiamonds(world, stage, count) {
		Game.saveData[this.getStageSaveOffset(world, stage) + 0] = count << 24 >> 24;
	}

	getStageRedDiamondTotal(world, stage) {
		return Game.saveData[this.getStageSaveOffset(world, stage) + 1];
	}

	markCollectibleTaken(world, stage, col, row) {
		let index = 0, collectibleCount = 0, recordPos = 0, t1, t2;
		recordPos = this.getStageSaveOffset(world, stage);
		collectibleCount = Game.saveData[recordPos + 4];
		index = 0;
		while (true) {
			if (index >= collectibleCount) {
				return;
			}
			if (Game.saveData[recordPos + 5 + 2 * index + 0] !== col || Game.saveData[recordPos + 5 + 2 * index + 1] !== row) {
				index++;
				continue;
			}
			break;
		}
		Game.saveData[recordPos + 5 + 2 * index + 0] = 0;
		Game.saveData[recordPos + 5 + 2 * index + 1] = 0;
		t1 = Game.saveData;
		t2 = recordPos + 3 | 0;
		t1[t2] = t1[t2] + 1 << 24 >> 24;
	}

	isCollectibleTaken(world, stage, col, row) {
		let index = 0, collectibleCount = 0, recordPos = 0;
		recordPos = this.getStageSaveOffset(world, stage);
		collectibleCount = Game.saveData[recordPos + 4];
		index = 0;
		while (true) {
			if (index >= collectibleCount) {
				return 1;
			}
			if (Game.saveData[recordPos + 5 + 2 * index + 0] !== col || Game.saveData[recordPos + 5 + 2 * index + 1] !== row) {
				index++;
				continue;
			}
			break;
		}
		return 0;
	}

	initKnightBossStage() {
		this.bossState = 13;
		this.bossHealth = 4;
		this.knightX = 408;
		this.specialStageType = 5;
		this.levelResourceMask = this.levelResourceMask | 128n;
		this.levelResourceMask = this.levelResourceMask | 8n;
		this.bossWokenUp = 0;
		this.bossRockSpawnRow = 16;
		this.bossRockCol1 = 16;
		this.bossRockCol2 = 19;
		this.bossRockCheckRow = 18;
	}

	loadLevelData() {
		let row = 0, found = 0, width = 0, stageIndex = 0, col = 0, buffer = null, stageCount = 0, height = 0;
		Game.bufLeftX = -1;
		Game.itemRaiseFreeze = 0;
		this.isExplorerVisible = 1;
		this.nextCheckpointIndex = 0;
		this.shakeTime = 0;
		this.levelResourceMask = 0n;
		this.levelExtraResourceMask = 0n;
		this.exitDoorCol = 0;
		this.exitDoorRow = 0;
		this.specialStageType = 0;
		this.stageWasCompleted = (this.getStageFlags(this.world, this.stage) & 2) !== 0 ? 1 : 0;
		this.gateRevealState = 0;
		switch (this.world) {
			case 2:
				if (this.stage === 10) {
					this.resetBoss();
					this.yetiX = 360;
					this.specialStageType = 3;
					this.levelResourceMask = this.levelResourceMask | 128n;
					this.levelResourceMask = this.levelResourceMask | 8n;
				}
				break;
			case 1:
				if (this.stage === 9) {
					this.initKnightBossStage();
				}
				break;
			case 0:
				if (this.stage !== 5) {
					if (this.stage !== 13) {
						if (this.stage === 8) {
							this.specialStageType = 4;
							this.bossState = 0;
							this.bossHealth = 3;
							this.anacondaHoleIndex = 0;
							this.bossTimer = 0;
							this.anacondaSlamVisible = 0;
							this.levelResourceMask = this.levelResourceMask | 8n;
							this.levelResourceMask = this.levelResourceMask | 1024n;
							this.bossRockSpawnRow = 2;
							this.bossRockCol1 = 12;
							this.bossRockCol2 = 15;
							this.bossRockCheckRow = 5;
						}
					} else {
						this.specialStageType = 2;
						this.introHintIconVisible = 0;
					}
				} else {
					this.specialStageType = 1;
					this.floodHeight = 816;
					this.floodTriggerStage = 0;
				}
				break;
			default:
				break;
		}
		this.introTrigger13Reached = 0;
		this.introTrigger16Reached = 0;
		this.introHintSpotReached = 0;
		this.diamondsToOpenExit = 0;
		this.slidingObjParams = -1;
		this.slidingObjSavedParams = -1;
		this.slidingObjSubStep = 0;
		this.slidingObjCol = 0;
		this.slidingObjRow = 0;
		this.slideCellsLeft = 0;
		this.playerIdleCountdown = 70;
		this.explorerEnergy = Game.saveData[8];
		this.currentMoveDir = 0;
		this.diamondCount = 0;
		this.hitsTaken = 0;
		this.livesLostInStage = 0;
		this.redDiamondCount = 0;
		this.deathTimer = 0;
		this.explorerStateFlags = 0;
		this.encasedStruggleCount = 0;
		this.goldKeys = 0;
		this.silverKeys = 0;
		Game.activeGateId = -1;
		Game.gateRemainingCounts = null;
		Game.gateObjectiveMsgs = null;
		this.resourceStream = J.getClass(this).getResourceAsStream(Game.worldDataFiles[this.world]);
		this.resourceStream.read();
		found = 0;
		while (found === 0) {
			stageCount = this.resourceStream.read();
			stageIndex = 0;
			buffer = new Int8Array(4);
			while (stageIndex < stageCount && found === 0) {
				this.resourceStream.read(buffer);
				width = Game.readU16LE(buffer, 0);
				height = Game.readU16LE(buffer, 2);
				if (stageIndex !== this.stage) {
					this.resourceStream.skip(BigInt(Math.imul(width, height) * 3 | 0));
				} else {
					this.levelW = width;
					this.levelH = height;
					Game.cellTypes = null;
					Game.cellUpdateTimers = null;
					Game.cellObjects = null;
					JSystem.gc();
					Game.cellTypes = J.multiArray(Int8Array, 2, [this.levelW, this.levelH]);
					Game.cellUpdateTimers = J.multiArray(Int8Array, 2, [this.levelW, this.levelH]);
					Game.cellObjects = J.multiArray(Int32Array, 2, [this.levelW, this.levelH]);
					buffer = new Int8Array(Math.imul(this.levelW, this.levelH));
					this.resourceStream.read(buffer);
					for (col = 0; col < this.levelW; col++) {
						for (row = 0; row < this.levelH; row++) {
							Game.cellTypes[col][row] = buffer[col + Math.imul(row, this.levelW)];
						}
					}
					Game.cellMoveOffsets = J.multiArray(Int8Array, 2, [this.levelW, this.levelH]);
					Game.cellStates = J.multiArray(Int32Array, 2, [this.levelW, this.levelH]);
					this.resourceStream.read(buffer);
					for (col = 0; col < this.levelW; col++) {
						for (row = 0; row < this.levelH; row++) {
							Game.cellStates[col][row] = buffer[col + Math.imul(row, this.levelW)];
						}
					}
					this.resourceStream.read(buffer);
					for (col = 0; col < this.levelW; col++) {
						for (row = 0; row < this.levelH; row++) {
							Game.cellObjects[col][row] = buffer[col + Math.imul(row, this.levelW)];
						}
					}
					buffer = null;
					found = 1;
				}
				stageIndex++;
			}
		}
		this.resourceStream.close();
		this.resourceStream = null;
		this.camTargetX = 0;
		this.camX = 0;
		this.camTargetY = 0;
		this.camY = 0;
		this.updateCameraFollow();
		JSystem.gc();
	}

	unlockStagesAfterClear() {
		let linkRow = 0, linkIndex = 0, linkCol = 0, linkStage = 0, nodeCol = 0, node = 0n, linkNode = 0n, nodeStage = 0, bitPos = 0, nodeRow = 0, linkKind = 0, linkCount = 0;
		nodeCol = this.mapMarkerCol;
		nodeRow = this.mapMarkerRow;
		node = Game.stageMapNodes[nodeCol][nodeRow];
		nodeStage = Game.extractLongBits(node, 6, 5);
		linkCount = Game.extractLongBits(node, 11, 3);
		bitPos = 14;
		if (this.stage >= this.firstSecretStage) {
			this.addStageFlags(this.world, this.stage, 2);
		}
		if (linkCount <= 1) {
			Game.latestUnlockedStage = this.stage;
		} else {
			linkIndex = 0;
			while (linkIndex < linkCount) {
				linkCol = Game.extractLongBits(node, bitPos << 24 >> 24, 4);
				bitPos += 4;
				linkRow = Game.extractLongBits(node, bitPos << 24 >> 24, 4);
				linkNode = Game.stageMapNodes[linkCol][linkRow];
				linkKind = Game.extractLongBits(linkNode, 3, 3);
				if (linkKind === 1) {
					linkStage = Game.extractLongBits(linkNode, 6, 5);
					if (linkStage > nodeStage) {
						Game.latestUnlockedStage = linkStage;
						this.unlockFromNodeX = nodeCol;
						this.unlockFromNodeY = nodeRow;
						this.addStageFlags(this.world, Game.latestUnlockedStage, 64);
						this.newStageUnlocked = 1;
					}
				}
				linkIndex++;
				bitPos += 4;
			}
		}
	}

	paint(g) {
		let s0;
		try {
			this.screenGraphics = g;
			this.screenGraphics.setClip(0, 0, 240, 320);
			switch (Game.screen) {
				case 34:
					this.drawTextViewerScreen();
					break;
				case 33:
					this.drawHelpScreen();
					break;
				case 31:
					if (this.newGamePromptDirty) {
						this.newGamePromptDirty = 0;
						this.screenGraphics.setColor(0);
						this.screenGraphics.fillRect(0, 0, 240, 320);
						Game.spritePacks[41].lineSpacing = 5;
						Game.spritePacks[41].drawMultilineString(this.screenGraphics, Game.wrapText(Game.langStrings[!this.noSavedProgress ? 68 : 69], 220), 120, 160, 3);
						this.drawSelectSoftkeyIcon();
						this.drawBackSoftkeyIcon();
					}
					break;
				case 30:
					this.drawTitleBackground(this.screenGraphics, 1);
					if (Game.frameCount % 20 >= 10) {
						Game.spritePacks[41].drawString(this.screenGraphics, Game.langStrings[82], 120, 250, 17);
					}
					break;
				case 29:
					this.drawEndingScreen();
					break;
				case 28:
					this.loadingStepCount = 11;
					this.drawLoadingScreen();
					break;
				case 27:
					this.drawWorldMapScreen();
					break;
				case 26:
					break;
				case 24:
					this.drawCheatScreen();
					break;
				case 22:
					this.drawCredits();
					break;
				case 20:
					Game.drawTextInBox(this.screenGraphics, Game.spritePacks[41], Game.langStrings[48], 120, 180, 3, 20, 1);
					break;
				case 18:
					this.loadShopSpritesAndHandleInput();
					this.needsFullRedraw = 1;
					Game.screen = 25;
					this.shopLastDrawnCursor = this.shopCursor;
					this.shopDiamondsText = new StringBuffer(Game.langStrings[110]).append(" ").append(Game.readU16LE(Game.saveData, 4)).append(" ").append(Game.langStrings[109]).toString();
					this.drawShopScreen();
					break;
				case 25:
					this.drawShopScreen();
					break;
				case 17:
					this.drawStageResults();
					break;
				case 16:
					this.drawLoadingScreen();
					break;
				case 15:
					this.drawStageMapScreen();
					break;
				case 12:
					this.drawGameOverScreen();
					break;
				case 10:
					this.updateMoreGamesScreen(this.screenGraphics);
					break;
				case 8:
				case 9:
				case 21:
				case 35:
					this.drawLoadingScreen();
					break;
				case 7:
					this.drawMenu();
					break;
				case 6:
					this.paintGameloftLogo();
					break;
				case 5:
					if (this.loadingFullRedraw) {
						this.drawLoadingScreen();
					} else {
						this.screenGraphics.setClip(0, 293, 240, 27);
						this.drawLoadingScreen();
						this.screenGraphics.setClip(0, 0, 240, 320);
					}
					if (Game.tipPageData !== null && this.loadingFullRedraw) {
						this.drawTipPage();
					}
					break;
				case 4:
					this.drawMainMenuScreen();
					break;
				case 2:
					this.drawMenu();
					break;
				case 1:
					this.paintPlayfield();
					break;
				case 0:
				case 3:
					break;
				default:
					break;
			}
			this.drawPopup();
		} catch (ex) {
			ex = J.exc(ex);
			{
				s0 = ex;
				return;
			}
		}
	}

	drawHelpScreen() {
		let text = null;
		if (this.needsFullRedraw) {
			this.screenGraphics.setColor(0);
			this.screenGraphics.setClip(0, 0, 240, 320);
			this.screenGraphics.fillRect(0, 0, 240, 320);
			Game.spritePacks[41].lineSpacing = 3;
			text = new StringBuffer(Game.langStrings[4]).append("\n\n").append(Game.langStrings[103]).append("\n").append(Game.langStrings[104]).append("\n").append(Game.langStrings[105]).append("\n\n").append(Game.langStrings[106]).append("\n\n").append(Game.langStrings[107]).append("\n\n").append(Game.langStrings[108]).toString();
			text = Game.wrapText(text, 235);
			Game.spritePacks[41].drawMultilineString(this.screenGraphics, text, 120, 10, 17);
			this.drawBackSoftkeyIcon();
			this.needsFullRedraw = 0;
		}
	}

	drawWorldMapBackgroundAt(g, dimmed, offsetX, offsetY) {
		let startY = 0, x = 0, overlayX = 0, y = 0, startX = 0;
		g.setClip(0, 0, 240, 320);
		startX = 0;
		startY = 0;
		if (offsetX !== 0 || offsetY !== 0) {
			startX -= 24;
			startY -= 24;
		}
		y = startY;
		overlayX = 0;
		while (y < 320) {
			for (x = startX; x < 240; x += 24) {
				g.drawImage(Game.objectFrameImages[8][0], x + offsetX | 0, y + offsetY | 0, 0);
			}
			y += 24;
		}
		Game.spritePacks[10].drawFrame(g, 0, this.medallionX + offsetX | 0, this.medallionY + offsetY | 0, 0, 0, 0);
		if (dimmed !== 0) {
			for (y = 0; y < 320; y += 24) {
				for (overlayX = 0; overlayX < 240; overlayX += 24) {
					Game.spritePacks[17].drawFrame(g, 16, overlayX, y, 0, 0, 0);
				}
			}
		}
	}

	drawWorldMapBackground(g, dimmed) {
		this.drawWorldMapBackgroundAt(g, dimmed, 0, 0);
	}

	drawEndingScreen() {
		let packOrSpacing = 0, gemOrText = 0;
		if (this.needsFullRedraw) {
			this.drawWorldMapBackgroundAt(this.screenGraphics, 0, this.medallionShakeX, this.medallionShakeY);
			Game.spritePacks[17].drawFrame(this.screenGraphics, 11, 120 + Tables.medallionPieceOffsets[6] + this.medallionShakeX | 0, 136 + Tables.medallionPieceOffsets[7] + this.medallionShakeY | 0, 0, 0, 0);
			packOrSpacing = 0;
			for (gemOrText = 0; gemOrText < 3; gemOrText++) {
				packOrSpacing = 52 + gemOrText | 0;
				Game.spritePacks[packOrSpacing].drawFrame(this.screenGraphics, 0, Tables.medallionPieceOffsets[gemOrText << 1] + 120 - this.gemHalfWidth + this.medallionShakeX | 0, Tables.medallionPieceOffsets[(gemOrText << 1) + 1] + 136 - this.gemHalfHeight + this.medallionShakeY | 0, 0, 0, 0);
			}
		}
		switch (this.endingPhase) {
			case 9:
			case 10:
				FallingRocks.draw(this.screenGraphics);
				packOrSpacing = Game.spritePacks[41].lineSpacing;
				Game.spritePacks[41].lineSpacing = 3;
				gemOrText = new StringBuffer().append(Game.langStrings[40]).append("\n").append(Game.langStrings[97]).toString();
				gemOrText = Game.wrapText(gemOrText, 220);
				Game.spritePacks[41].measureString(gemOrText);
				Game.drawFramedBox(this.screenGraphics, (240 - SpritePack.textWidth >> 1) - 3 | 0, (320 - SpritePack.textHeight >> 1) - 3 | 0, SpritePack.textWidth + 6 | 0, SpritePack.textHeight + 6 | 0, 7096587, 0);
				Game.spritePacks[41].drawMultilineString(this.screenGraphics, gemOrText, 120, 160, 3);
				Game.spritePacks[41].lineSpacing = packOrSpacing;
				return;
			case 8:
				FallingRocks.draw(this.screenGraphics);
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
				if (!this.needsFullRedraw) {
					this.screenGraphics.setColor(this.endingFlashColor);
					this.screenGraphics.fillRect(0, 0, 240, 320);
					for (gemOrText = 0; gemOrText < 3; gemOrText++) {
						packOrSpacing = 52 + gemOrText | 0;
						Game.spritePacks[packOrSpacing].drawFrame(this.screenGraphics, 0, Tables.medallionPieceOffsets[gemOrText << 1] + 120 - this.gemHalfWidth | 0, Tables.medallionPieceOffsets[(gemOrText << 1) + 1] + 136 - this.gemHalfHeight | 0, 0, 0, 0);
					}
				}
				return;
			default:
				return;
		}
	}

	drawWorldMapScreen() {
		let infoText = null, boxY = 0, boxW = 0, gemIndexOrSpacing = 0, index = 0, boxH = 0, boxX = 0;
		if (this.needsFullRedraw || this.worldMapInfoDirty) {
			this.screenGraphics.setClip(0, 0, 240, 320);
			this.drawWorldMapBackground(this.screenGraphics, 0);
			Game.spritePacks[17].drawFrame(this.screenGraphics, 11, 120 + Tables.medallionPieceOffsets[6] | 0, 136 + Tables.medallionPieceOffsets[7] | 0, 0, 0, 0);
			this.drawBackSoftkeyIcon();
			this.drawSelectSoftkeyIcon();
			Game.spritePacks[41].drawString(this.screenGraphics, Game.langStrings[27].toLowerCase(), 222, 311, 10);
			this.needsFullRedraw = 0;
		} else {
			this.screenGraphics.setClip(this.worldMapCursorPrevX + 120 | 0, this.worldMapCursorPrevY + 136 | 0, 14, 22);
			Game.spritePacks[10].drawFrame(this.screenGraphics, 0, this.medallionX, this.medallionY, 0, 0, 0);
		}
		if (this.worldUnlockAnimIndex === 0) {
			for (index = 0; index < 3; index++) {
				if (Game.worldUnlockedOnMap[index] !== 0) {
					Game.spritePacks[10].drawFrame(this.screenGraphics, index + 1 | 0, this.medallionX, this.medallionY, 0, 0, 0);
				}
			}
		} else {
			this.worldMapInfoDirty = 0;
			this.needsFullRedraw = 1;
			for (index = 0; index < this.worldUnlockAnimIndex; index++) {
				if (Game.isWorldUnlocked(index)) {
					Game.spritePacks[10].drawFrame(this.screenGraphics, index + 1 | 0, this.medallionX, this.medallionY, 0, 0, 0);
				}
			}
			this.screenGraphics.setClip(0, 0, 240, 320);
			if (this.sparkleFrame >= this.sparkleFrameCount) {
				if (J.irem(this.worldMapCursorFrame, this.worldMapCursorFrameCount) >= this.worldMapCursorFrameCount >> 1) {
					Game.spritePacks[10].drawFrame(this.screenGraphics, this.worldUnlockAnimIndex + 1 | 0, this.medallionX, this.medallionY, 0, 0, 0);
					this.worldUnlockBlinkCount = this.worldUnlockBlinkCount + 1 | 0;
				}
				if (this.worldUnlockBlinkCount >= 15) {
					Game.worldUnlockedOnMap[this.worldUnlockAnimIndex] = 1;
					this.worldUnlockBlinkCount = 0;
					this.worldUnlockAnimIndex = 0;
					this.sparkleFrame = 0;
					this.updateWorldMapNodeTexts();
					this.worldMapInfoDirty = 1;
					this.needsFullRedraw = 0;
				}
			} else {
				Game.spritePacks[9].drawAnimFrame(this.screenGraphics, 5, this.sparkleFrame, Tables.medallionPieceOffsets[this.worldUnlockAnimIndex << 1] + 120 - 12 | 0, Tables.medallionPieceOffsets[(this.worldUnlockAnimIndex << 1) + 1] + 124 | 0, 0, 0, 0);
				this.sparkleFrame = this.sparkleFrame + 1 | 0;
			}
		}
		for (gemIndexOrSpacing = 0; gemIndexOrSpacing < 3; gemIndexOrSpacing++) {
			if (Game.elementalDiamondPlaced[gemIndexOrSpacing] !== 0) {
				index = 52 + gemIndexOrSpacing | 0;
				if (this.placingElementalIndex !== gemIndexOrSpacing) {
					Game.spritePacks[index].drawFrame(this.screenGraphics, 0, Tables.medallionPieceOffsets[gemIndexOrSpacing << 1] + 120 - this.gemHalfWidth | 0, Tables.medallionPieceOffsets[(gemIndexOrSpacing << 1) + 1] + 136 - this.gemHalfHeight | 0, 0, 0, 0);
				}
			}
		}
		if (this.placingElementalIndex === -1) {
			this.worldMapCursorFrame = J.irem(this.worldMapCursorFrame, this.worldMapCursorFrameCount);
			this.screenGraphics.setClip(this.worldMapCursorX + 120 | 0, 136 + this.worldMapCursorY | 0, 14, 22);
			Game.spritePacks[55].drawAnimFrame(this.screenGraphics, 0, this.worldMapCursorFrame, 120 + this.worldMapCursorX | 0, 136 + this.worldMapCursorY | 0, 0, 0, 0);
			this.worldMapCursorFrame = this.worldMapCursorFrame + 1 | 0;
			if (this.worldMapInfoDirty) {
				gemIndexOrSpacing = Game.spritePacks[41].lineSpacing;
				Game.spritePacks[41].lineSpacing = 1;
				infoText = new StringBuffer().append(this.worldMapHintText).append("\n").append(this.worldMapNodeName).toString();
				infoText = Game.wrapText(infoText, 220);
				Game.spritePacks[41].measureString(infoText);
				boxX = (240 - SpritePack.textWidth >> 1) - 3 | 0;
				boxY = 250 - (SpritePack.textHeight >> 1) - 3 | 0;
				boxW = SpritePack.textWidth + 6 | 0;
				boxH = SpritePack.textHeight + 6 | 0;
				this.screenGraphics.setClip(boxX, boxY, boxW, boxH);
				Game.drawFramedBox(this.screenGraphics, boxX, boxY, boxW, boxH, 7096587, 0);
				Game.spritePacks[41].drawMultilineString(this.screenGraphics, infoText, 120, 250, 3);
				Game.spritePacks[41].lineSpacing = gemIndexOrSpacing;
				this.worldMapInfoDirty = 0;
			}
			return;
		}
		this.needsFullRedraw = 1;
		if (this.animateGemToMedallion(this.placingElementalIndex)) {
			this.placingElementalIndex = -1;
			if (Game.elementalDiamondPlaced[0] !== 0 && Game.elementalDiamondPlaced[1] !== 0 && Game.elementalDiamondPlaced[2] !== 0) {
				this.resetCounters();
				this.needsFullRedraw = 1;
				this.creditsAfterEnding = 1;
				Game.screen = 29;
			}
		}
	}

	animateGemToMedallion(world) {
		let packIndex = 0, targetX = 0, deltaY = 0, flashColorStep = 0, deltaX = 0, targetY = 0;
		packIndex = 52 + world | 0;
		targetX = Tables.medallionPieceOffsets[world << 1] + 120 | 0;
		targetY = Tables.medallionPieceOffsets[(world << 1) + 1] + 136 | 0;
		deltaY = targetY - this.flyingGemY | 0;
		deltaX = targetX - this.flyingGemX | 0;
		if (deltaY >= 0) {
			if (deltaY > 0) {
				this.flyingGemY = this.flyingGemY + 2 | 0;
				if (this.flyingGemY >= targetY) {
					this.flyingGemY = targetY;
				}
			}
		} else {
			this.flyingGemY = this.flyingGemY - 2 | 0;
			if (this.flyingGemY <= targetY) {
				this.flyingGemY = targetY;
			}
		}
		if (deltaX >= 0) {
			if (deltaX > 0) {
				this.flyingGemX = this.flyingGemX + 3 | 0;
				if (this.flyingGemX >= targetX) {
					this.flyingGemX = targetX;
				}
			}
		} else {
			this.flyingGemX = this.flyingGemX - 3 | 0;
			if (this.flyingGemX <= targetX) {
				this.flyingGemX = targetX;
			}
		}
		Game.spritePacks[packIndex].drawFrame(this.screenGraphics, 0, this.flyingGemX - this.gemHalfWidth | 0, this.flyingGemY - this.gemHalfHeight | 0, 0, 0, 0);
		if (this.flyingGemX !== targetX || this.flyingGemY !== targetY) {
			return 0;
		}
		this.flyingGemX = targetX;
		this.flyingGemY = targetY;
		if (this.gemFlashCounter >= 20) {
			if (this.sparkleFrame >= this.sparkleFrameCount) {
				this.sparkleFrame = 0;
				this.gemFlashCounter = 0;
				return 1;
			}
			Game.spritePacks[9].drawAnimFrame(this.screenGraphics, 5, this.sparkleFrame, Tables.medallionPieceOffsets[world << 1] + 120 - 12 | 0, Tables.medallionPieceOffsets[(world << 1) + 1] + 124 | 0, 0, 0, 0);
			this.sparkleFrame = this.sparkleFrame + 1 | 0;
			return 0;
		}
		if (this.gemFlashCounter % 2 === 1) {
			flashColorStep = 838860;
			this.screenGraphics.setColor(0 + Math.imul(flashColorStep, this.gemFlashCounter) | 0);
			this.screenGraphics.fillRect(0, 0, 240, 320);
		}
		this.gemFlashCounter = this.gemFlashCounter + 1 | 0;
		return 0;
	}

	drawCheatScreen() {
		let row = 0, font = null, valueText = null, labelStringId = 0, y = 0, s0, s1;
		valueText = null;
		font = Game.spritePacks[41];
		font.lineSpacing = 15;
		this.screenGraphics.setColor(0);
		this.screenGraphics.fillRect(0, 0, 240, 320);
		for (row = 0; row < 6; row++) {
			labelStringId = -1;
			switch (row) {
				case 5:
					labelStringId = -1;
					s0 = "5 to activate lang cheat";
					valueText = s0;
					break;
				case 4:
					labelStringId = 64;
					s0 = new StringBuffer().append(" 0 - ").append(Game.langStrings[!this.cheatUnlockSecretStages ? 67 : 66]).toString();
					valueText = s0;
					break;
				case 3:
					labelStringId = 63;
					s0 = new StringBuffer().append(" 9 - ").append(Game.langStrings[!this.cheatUnlockAllStages ? 67 : 66]).toString();
					valueText = s0;
					break;
				case 2:
					labelStringId = 62;
					s0 = new StringBuffer().append(" 8 - x ").append(String(this.cheatWeaponFlags)).append(this.cheatWeaponFlags < 4 ? "" : " blue potion").toString();
					valueText = s0;
					break;
				case 1:
					labelStringId = 61;
					s0 = new StringBuffer().append(" 7 - Add ").append(String(this.redDiamondCount)).toString();
					valueText = s0;
					break;
				case 0:
					labelStringId = 60;
					s0 = new StringBuffer().append(" 6 - Add ").append(String(this.diamondCount)).toString();
					valueText = s0;
					break;
				default:
					break;
			}
			y = row * 35 | 0;
			if (labelStringId >= 0) {
				font.drawString(this.screenGraphics, Game.langStrings[labelStringId], 110, y, 17);
			}
			y = y + font.lineSpacing | 0;
			font.drawString(this.screenGraphics, Game.langStrings[65], 110, y, 24);
			font.drawString(this.screenGraphics, valueText, 110, y, 20);
		}
		valueText = "Pound - Pass levels ";
		if (!this.cheatPassLevels) {
			s0 = new StringBuffer().append(valueText);
			s1 = "off";
		} else {
			s0 = new StringBuffer().append(valueText);
			s1 = "on";
		}
		valueText = s0.append(s1).toString();
		font.drawString(this.screenGraphics, valueText, 110, 290, 17);
		this.drawBackSoftkeyIcon();
		this.drawSelectSoftkeyIcon();
	}

	drawTextViewerScreen() {
		let font = null, pageTitle = null;
		font = Game.spritePacks[41];
		font.lineSpacing = 2;
		this.screenGraphics.setColor(0);
		this.screenGraphics.fillRect(0, 0, 240, 320);
		switch (this.debugTextPage) {
			default:
				pageTitle = "";
				break;
			case 1:
				pageTitle = "Tips";
				Game.loadTipPage(this.debugTextIndices[1]);
				this.drawTipPage();
				break;
			case 0:
				pageTitle = "Mix";
				font.drawMultilineString(this.screenGraphics, Game.langStrings[this.debugTextIndices[0]], 10, 5, 20);
				break;
		}
		font.lineSpacing = 2;
		font.drawString(this.screenGraphics, pageTitle, 40, 308, 20);
		font.drawString(this.screenGraphics, new StringBuffer().append("").append(this.debugTextIndices[this.debugTextPage]).toString(), 120, 308, 20);
		font.drawMultilineString(this.screenGraphics, "Use up, down, left and right to navigate", 10, 280, 20);
		this.drawBackSoftkeyIcon();
		this.drawSelectSoftkeyIcon();
	}

	drawMainMenuScreen() {
		this.drawMenu();
	}

	drawTitleBackground(g, showBottomImage) {
		g.drawImage(Game.titleBackgroundImage, 0, 0, 20);
		g.drawImage(Game.titleLogoImage, 0, 0, 20);
		if (showBottomImage !== 0) {
			g.drawImage(Game.titleBottomImage, 120, 319, 33);
		}
	}

	drawGameOverScreen() {
		let font = null, lostText = null, s0, s1, s2, s3, s4, s5;
		this.screenGraphics.setColor(0);
		this.screenGraphics.fillRect(0, 0, 240, 320);
		font = Game.spritePacks[41];
		font.drawString(this.screenGraphics, Game.langStrings[35], 120, 50, 17);
		if (this.specialStageType !== 2) {
			font.drawString(this.screenGraphics, Game.langStrings[1], 0, 320, 36);
			lostText = new StringBuffer(Game.langStrings[111]).append(" ").append(Game.readU16LE(Game.saveData, 4) >= 500 ? 500 : Game.readU16LE(Game.saveData, 4)).append(" ").append(Game.langStrings[109]).toString();
			s0 = font;
			s1 = this.screenGraphics;
			s2 = lostText;
			s3 = 120;
			s4 = 160;
			s5 = 17;
		} else {
			s0 = font;
			s1 = this.screenGraphics;
			s2 = Game.langStrings[26];
			s3 = 0;
			s4 = 320;
			s5 = 36;
		}
		s0.drawString(s1, s2, s3, s4, s5);
		this.paintExplorer();
	}

	paintLevelBuffer(g) {
		let srcTop = 0, srcBottom = 0, srcLeft = 0, srcRight = 0, s0, s1, s2, s3, s4;
		srcLeft = J.irem(this.camX, Game.bufW);
		srcTop = J.irem(this.camY, Game.bufH);
		srcRight = J.irem(this.camX + 240 | 0, Game.bufW);
		srcBottom = J.irem(this.camY + 240 | 0, Game.bufH);
		if (srcRight <= srcLeft) {
			if (srcBottom <= srcTop) {
				Game.blitLevelBuffer(g, srcLeft, srcTop, 0, 0);
				Game.blitLevelBuffer(g, srcLeft, 0, 0, 240 - srcBottom | 0);
				Game.blitLevelBuffer(g, 0, srcTop, 240 - srcRight | 0, 0);
				s0 = g;
				s1 = 0;
				s2 = 0;
				s3 = 240 - srcRight | 0;
				s4 = 240 - srcBottom | 0;
			} else {
				Game.blitLevelBuffer(g, srcLeft, srcTop, 0, 0);
				s0 = g;
				s1 = 0;
				s2 = srcTop;
				s3 = 240 - srcRight | 0;
				s4 = 0;
			}
		} else {
			B3: {
				if (srcBottom <= srcTop) {
					Game.blitLevelBuffer(g, srcLeft, srcTop, 0, 0);
					s0 = g;
					s1 = srcLeft;
					s2 = 0;
					s3 = 0;
					s4 = 240 - srcBottom | 0;
					break B3;
				}
				s0 = g;
				s1 = srcLeft;
				s2 = srcTop;
				s3 = 0;
				s4 = 0;
			}
		}
		Game.blitLevelBuffer(s0, s1, s2, s3, s4);
	}

	static blitLevelBuffer(g, srcX, srcY, destX, destY) {
		g.drawImage(Game.levelBufferImage, destX - srcX | 0, destY - srcY | 0, 0);
	}

	static createLevelBuffer() {
		Game.bufW = 264;
		Game.bufH = 264;
		Game.levelBufferImage = Image.createImage(Game.bufW, Game.bufH);
		Game.levelBufferGraphics = Game.levelBufferImage.getGraphics();
	}

	eraseCellInBuffer(col, row) {
		let bufTop = 0, terrain = 0, cellX = 0, objectType = 0, bufBottom = 0, cellY = 0, bufLeft = 0, bufRight = 0;
		bufLeft = this.camX - this.camX % 24 | 0;
		bufTop = this.camY - this.camY % 24 | 0;
		bufRight = this.camX + Game.bufW - 24 - (this.camX + Game.bufW - 24 | 0) % 24 | 0;
		bufBottom = this.camY + Game.bufH - 24 - (this.camY + Game.bufH - 24 | 0) % 24 | 0;
		cellX = col * 24 | 0;
		cellY = row * 24 | 0;
		if (cellX >= bufLeft && cellX <= bufRight && cellY >= bufTop && cellY <= bufBottom) {
			objectType = Game.cellObjects[col][row] & 255;
			terrain = Game.cellTypes[col][row];
			if (terrain < 80) {
				if (objectType === 4 || objectType === 16 || objectType === 15) {
					this.redrawCellInBuffer(col, row);
					return;
				}
				Game.levelBufferGraphics.drawImage(Game.objectFrameImages[8][0], J.irem(cellX, Game.bufW), J.irem(cellY, Game.bufH), 0);
			}
		}
	}

	redrawCellInBuffer(col, row) {
		let bufTop = 0, cellX = 0, bufBottom = 0, cellY = 0, bufLeft = 0, bufRight = 0;
		bufLeft = this.camX - this.camX % 24 | 0;
		bufTop = this.camY - this.camY % 24 | 0;
		bufRight = this.camX + Game.bufW - 24 - (this.camX + Game.bufW - 24 | 0) % 24 | 0;
		bufBottom = this.camY + Game.bufH - 24 - (this.camY + Game.bufH - 24 | 0) % 24 | 0;
		cellX = col * 24 | 0;
		cellY = row * 24 | 0;
		if (cellX >= bufLeft && cellX <= bufRight && cellY >= bufTop && cellY <= bufBottom) {
			this.renderCellsToBuffer(cellX, cellY, cellX, cellY, 0);
		}
	}

	static getSpritePackForImageSet(imageSet) {
		switch (imageSet) {
			default:
				return -1;
			case 23:
				Game.spritePacks[45].paletteIndex = 1;
				return 45;
			case 22:
				Game.spritePacks[45].paletteIndex = 0;
				return 45;
			case 20:
				return 43;
			case 16:
				return 58;
			case 15:
				Game.spritePacks[57].paletteIndex = 0;
				return 57;
			case 14:
				Game.spritePacks[57].paletteIndex = 1;
				return 57;
			case 4:
				return 56;
			case 3:
				Game.spritePacks[59].paletteIndex = 1;
				return 59;
			case 2:
				Game.spritePacks[59].paletteIndex = 0;
				return 59;
			case 1:
				return 60;
			case 0:
				return 42;
		}
	}

	renderCellsToBuffer(left, top, right, bottom, objectsOnly) {
		let bufWidth = 0, bufStartX = 0, g = null, bufHeight = 0, x = 0, wallFrame = 0, bufStartY = 0, y = 0, s1;
		g = null;
		bufStartX = 0;
		bufStartY = 0;
		g = Game.levelBufferGraphics;
		bufWidth = Game.bufW;
		bufHeight = Game.bufH;
		bufStartX = J.irem(left, bufWidth);
		bufStartY = J.irem(top, bufHeight);
		this.cellDrawY = bufStartY - 24 | 0;
		this.paintCellRow = (top / 24 | 0) - 1 | 0;
		for (y = top; y <= bottom; y += 24) {
			this.cellDrawX = bufStartX - 24 | 0;
			this.paintCellCol = (left / 24 | 0) - 1 | 0;
			this.cellDrawY = this.cellDrawY + 24 | 0;
			this.paintCellRow = this.paintCellRow + 1 | 0;
			if (this.cellDrawY >= bufHeight) {
				this.cellDrawY = 0;
			}
			for (x = left; x <= right; x += 24) {
				this.cellDrawX = this.cellDrawX + 24 | 0;
				this.paintCellCol = this.paintCellCol + 1 | 0;
				if (this.cellDrawX >= bufWidth) {
					this.cellDrawX = 0;
				}
				if (this.paintCellCol >= 0 && this.paintCellCol < this.levelW && this.paintCellRow >= 0) {
					if (this.paintCellRow < this.levelH) {
						this.paintCellTerrain = Game.cellTypes[this.paintCellCol][this.paintCellRow];
						this.paintCellObject = Game.cellObjects[this.paintCellCol][this.paintCellRow] & 255;
						if (this.paintCellTerrain < 80 && objectsOnly === 0) {
							g.drawImage(Game.objectFrameImages[8][0], this.cellDrawX, this.cellDrawY, 0);
						}
						if (this.paintCellObject > -1 && this.paintCellObject < 38) {
							switch (this.paintCellObject) {
								case 27:
									this.objectSpriteSet = 21;
									this.objectSpriteFrame = 0;
									this.cellDrawOffsetY = 0;
									this.cellDrawOffsetX = 0;
									break;
								case 16:
									if (this.switchWallsPhase === 9) {
										this.objectSpriteSet = 15;
										this.objectSpriteFrame = 4 - ((this.switchWallsPhase * 5 | 0) / 10 | 0) | 0;
										if (this.objectSpriteFrame < 0) {
											s1 = 0;
											this.objectSpriteFrame = s1;
										}
									}
									break;
								case 15:
									if (this.switchWallsPhase === 0) {
										this.objectSpriteSet = 14;
										s1 = 0 + ((this.switchWallsPhase * 5 | 0) / 10 | 0) | 0;
										this.objectSpriteFrame = s1;
									}
									break;
								case 4:
									this.objectSpriteSet = 20;
									this.objectSpriteFrame = 7;
									this.cellDrawOffsetY = 0;
									this.cellDrawOffsetX = 0;
									break;
								default:
									break;
							}
						}
						if (this.objectSpriteSet !== -1) {
							if (Game.objectFrameImages[this.objectSpriteSet] !== null) {
								g.drawImage(Game.objectFrameImages[this.objectSpriteSet][this.objectSpriteFrame], this.cellDrawX + this.cellDrawOffsetX | 0, this.cellDrawY + this.cellDrawOffsetY | 0, this.cellDrawAnchor);
							} else {
								Game.spritePacks[Game.getSpritePackForImageSet(this.objectSpriteSet)].drawFrame(g, this.objectSpriteFrame, this.cellDrawX + this.cellDrawOffsetX | 0, this.cellDrawY + this.cellDrawOffsetY | 0, this.cellDrawAnchor, 0, 0);
							}
							this.cellDrawAnchor = 0;
							this.objectSpriteSet = -1;
							this.cellDrawOffsetY = 0;
							this.cellDrawOffsetX = 0;
						}
						if (this.paintCellTerrain !== -1 && objectsOnly === 0) {
							wallFrame = this.paintCellTerrain - 80 << 24 >> 24;
							if (wallFrame < 0) {
								switch (this.paintCellTerrain) {
									case 35:
										if (this.switchWallsPhase === 0) {
											this.terrainSpriteSet = 15;
											this.terrainSpriteFrame = 4 - ((this.switchWallsPhase * 5 | 0) / 10 | 0) | 0;
											if (this.terrainSpriteFrame < 0) {
												s1 = 0;
												this.terrainSpriteFrame = s1;
											}
										}
										break;
									case 34:
										if (this.switchWallsPhase === 9) {
											this.terrainSpriteSet = 14;
											s1 = 0 + ((this.switchWallsPhase * 5 | 0) / 10 | 0) | 0;
											this.terrainSpriteFrame = s1;
										}
										break;
									case 10:
										Game.spritePacks[16].drawFrame(g, 0, this.cellDrawX, this.cellDrawY, 0, 0, 0);
										break;
									case 1:
										if (Game.cellMoveOffsets[this.paintCellCol][this.paintCellRow] === 0 && (Game.liquidCells === null || Game.liquidCells[this.paintCellCol][this.paintCellRow] === 0)) {
											this.prepareLooseObjectSprite();
											this.terrainSpriteFrame = this.terrainSpriteFrame - this.sparklePhase | 0;
											this.cellDrawOffsetY = 0;
										}
										break;
									case 0:
										if (Game.cellMoveOffsets[this.paintCellCol][this.paintCellRow] === 0 && (Game.liquidCells === null || Game.liquidCells[this.paintCellCol][this.paintCellRow] === 0)) {
											this.prepareLooseObjectSprite();
										}
										break;
									default:
										break;
								}
							} else {
								this.terrainSpriteSet = 0;
								s1 = wallFrame;
								this.terrainSpriteFrame = s1;
							}
							if (this.terrainSpriteSet !== -1) {
								if (Game.objectFrameImages[this.terrainSpriteSet] !== null) {
									g.drawImage(Game.objectFrameImages[this.terrainSpriteSet][this.terrainSpriteFrame], this.cellDrawX + this.cellDrawOffsetX | 0, this.cellDrawY + this.cellDrawOffsetY | 0, this.cellDrawAnchor);
								} else {
									Game.spritePacks[Game.getSpritePackForImageSet(this.terrainSpriteSet)].drawFrame(g, this.terrainSpriteFrame, this.cellDrawX + this.cellDrawOffsetX | 0, this.cellDrawY + this.cellDrawOffsetY | 0, this.cellDrawAnchor, 0, 0);
								}
								this.terrainSpriteSet = -1;
								this.cellDrawAnchor = 0;
								this.cellDrawOffsetY = 0;
								this.cellDrawOffsetX = 0;
							}
						}
						if (this.specialStageType === 2) {
							this.paintIntroStageCellOverlay(g);
						}
					}
				}
			}
		}
	}

	paintObjects(g) {
		let cellState = 0, colOffset = 0, frame = 0, rowOffset = 0;
		for (rowOffset = -1; rowOffset < 12; rowOffset++) {
			for (colOffset = -1; colOffset < 12; colOffset++) {
				this.paintCellCol = colOffset + this.camCellX | 0;
				this.paintCellRow = rowOffset + this.camCellY | 0;
				if (this.paintCellCol >= 0 && this.paintCellCol < this.levelW && this.paintCellRow >= 0) {
					if (this.paintCellRow < this.levelH) {
						this.paintCellTerrain = Game.cellTypes[this.paintCellCol][this.paintCellRow];
						this.paintCellObject = Game.cellObjects[this.paintCellCol][this.paintCellRow] & 255;
						this.cellDrawX = colOffset * 24 - this.camOffX | 0;
						this.cellDrawY = rowOffset * 24 - this.camOffY | 0;
						this.clipToPlayfield();
						if (this.paintCellObject > -1 && this.paintCellObject < 38) {
							switch (this.paintCellObject) {
								case 37:
									Game.spritePacks[27].drawAnimFrame(g, 2, 0, this.cellDrawX, this.cellDrawY, 0, 0, 0);
									this.prepareWindSprite();
									break;
								case 35:
									this.prepareWindSprite();
									break;
								case 34:
									Game.spritePacks[27].drawAnimFrame(g, 2, 0, this.cellDrawX, this.cellDrawY, 0, 0, 0);
									break;
								case 16:
									if (this.switchWallsPhase !== 9 && this.switchWallsPhase >= 5) {
										this.objectSpriteSet = 15;
										this.objectSpriteFrame = 4 - ((this.switchWallsPhase * 5 | 0) / 10 | 0) | 0;
										if (this.objectSpriteFrame < 0) {
											this.objectSpriteFrame = 0;
										}
									}
									break;
								case 15:
									if (this.switchWallsPhase !== 0 && this.switchWallsPhase <= 5) {
										this.objectSpriteSet = 14;
										this.objectSpriteFrame = 0 + ((this.switchWallsPhase * 5 | 0) / 10 | 0) | 0;
									}
									break;
								case 14:
								case 33:
									this.drawChest(this.paintCellObject);
									break;
								case 8:
								case 9:
									this.prepareKeyDoorSprite();
									break;
								case 7:
									this.prepareDoorBaseSprite();
									break;
								case 6:
									this.preparePressurePlateSprite();
									if ((this.cellDrawY + 24 | 0) < 240) {
										g.clipRect(this.cellDrawX, this.cellDrawY, 24, 24);
									}
									break;
								case 5:
								case 28:
									this.objectSpriteSet = 11;
									this.objectSpriteFrame = 0;
									break;
								case 4:
									if (Game.cellObjects[this.paintCellCol][this.paintCellRow] >> 8 >= this.nextCheckpointIndex) {
										this.prepareCheckpointStarSprite();
									}
									break;
								case 3:
									frame = (Game.cellObjects[this.paintCellCol][this.paintCellRow] >> 8) - 1 | 0;
									if (frame >= 0) {
										this.objectSpriteSet = 12;
										this.objectSpriteFrame = frame << 24 >> 24;
									}
									break;
								default:
									break;
							}
							if (this.objectSpriteSet === -1) {
								if (Game.curObjectSprites !== null) {
									if (this.cellAnimIndex !== -1) {
										Game.curObjectSprites.drawAnimFrame(g, this.cellAnimIndex, this.cellAnimFrame, this.cellDrawX + this.cellDrawOffsetX | 0, this.cellDrawY + this.cellDrawOffsetY | 0, 0, 0, 0);
										this.cellAnimIndex = -1;
									}
									Game.curObjectSprites = null;
									this.cellDrawOffsetY = 0;
									this.cellDrawOffsetX = 0;
								}
							} else {
								if (Game.objectFrameImages[this.objectSpriteSet] !== null) {
									g.drawImage(Game.objectFrameImages[this.objectSpriteSet][this.objectSpriteFrame], this.cellDrawX + this.cellDrawOffsetX | 0, this.cellDrawY + this.cellDrawOffsetY | 0, this.cellDrawAnchor);
								} else {
									Game.spritePacks[Game.getSpritePackForImageSet(this.objectSpriteSet)].drawFrame(g, this.objectSpriteFrame, this.cellDrawX + this.cellDrawOffsetX | 0, this.cellDrawY + this.cellDrawOffsetY | 0, this.cellDrawAnchor, 0, 0);
								}
								this.cellDrawAnchor = 0;
								this.objectSpriteSet = -1;
								g.setClip(0, -this.shake | 0, 240, 240);
								this.cellDrawOffsetY = 0;
								this.cellDrawOffsetX = 0;
							}
						}
						if (this.paintCellTerrain !== -1) {
							frame = this.paintCellTerrain - 80 << 24 >> 24;
							if (frame < 0) {
								cellState = Game.cellStates[this.paintCellCol][this.paintCellRow];
								switch (this.paintCellTerrain) {
									case 49:
										this.prepareEnemy49Sprite();
										break;
									case 48:
										this.prepareFreezeEmitterSprite();
										break;
									case 47:
										this.prepareLooseObjectSprite();
										break;
									case 46:
										this.prepareStaffMonkeySprite();
										break;
									case 45:
										this.prepareHopperSprite();
										break;
									case 44:
										this.prepareIcicleSprite();
										this.cellAnimFrame = 0;
										break;
									case 43:
										this.prepareSnakeSprite(this.paintCellTerrain << 24 >> 24);
										break;
									case 37:
										this.terrainSpriteSet = 17;
										this.terrainSpriteFrame = 0 + (((cellState - 1 | 0) * 3 | 0) / 8 | 0) | 0;
										break;
									case 36:
										this.prepareFloorTrapSprite();
										break;
									case 35:
										if (this.switchWallsPhase !== 0 && this.switchWallsPhase <= 5) {
											this.terrainSpriteSet = 15;
											this.terrainSpriteFrame = 4 - ((this.switchWallsPhase * 5 | 0) / 10 | 0) | 0;
											if (this.terrainSpriteFrame < 0) {
												this.terrainSpriteFrame = 0;
											}
										}
										break;
									case 34:
										if (this.switchWallsPhase !== 9 && this.switchWallsPhase >= 5) {
											this.terrainSpriteSet = 14;
											this.terrainSpriteFrame = 0 + ((this.switchWallsPhase * 5 | 0) / 10 | 0) | 0;
										}
										break;
									case 32:
										this.drawExtendingRod();
										break;
									case 30:
										Game.curObjectSprites = Game.spritePacks[20];
										this.cellAnimIndex = 0;
										this.cellAnimFrame = 0 + (((cellState - 1 | 0) * 7 | 0) / 16 | 0) | 0;
										break;
									case 28:
										this.drawPistonTrap();
										break;
									case 23:
										Game.curObjectSprites = Game.spritePacks[12];
										this.cellAnimFrame = 0;
										this.drawStatueFlame(23);
										break;
									case 22:
										Game.curObjectSprites = Game.spritePacks[12];
										this.cellAnimFrame = 1;
										this.drawStatueFlame(22);
										break;
									case 21:
										this.prepareProjectileSprite();
										break;
									case 19:
										this.prepareSnakeSprite(this.paintCellTerrain << 24 >> 24);
										break;
									case 18:
										this.prepareLeverSprite();
										break;
									case 16:
										this.prepareTallTrapSprite();
										break;
									case 14:
										this.prepareRollerSprite();
										break;
									case 12:
										this.drawExitPadlockAtCell();
										break;
									case 11:
										this.prepareWallCrawlerSprite();
										break;
									case 10:
										break;
									case 9:
										this.prepareLooseObjectSprite();
										if ((Game.cellStates[this.paintCellCol][this.paintCellRow] & 264241152) === 138412032) {
											this.cellDrawOffsetX = this.cellDrawOffsetX + this.frozenShakeX | 0;
											this.cellDrawOffsetY = this.cellDrawOffsetY + this.frozenShakeY | 0;
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
										if ((Game.cellStates[this.paintCellCol][this.paintCellRow] & -2147483648) !== 0 || this.sparklePhase !== 0) {
											this.prepareLooseObjectSprite();
										}
										break;
									case 0:
										if ((Game.cellStates[this.paintCellCol][this.paintCellRow] & -2147483648) !== 0) {
											this.prepareLooseObjectSprite();
										}
										break;
									case 8:
										this.prepareLooseObjectSprite();
										break;
									default:
										break;
								}
							}
							if (this.terrainSpriteSet === -1) {
								if (Game.curObjectSprites !== null) {
									if (this.paintCellCol === this.killerCol && this.paintCellRow === this.killerRow) {
										Game.killerSprites = Game.curObjectSprites;
										this.killerAnim = this.cellAnimIndex;
										this.killerFrame = this.cellAnimFrame;
										this.killerDrawX = this.cellDrawX + this.cellDrawOffsetX | 0;
										this.killerDrawY = this.cellDrawY + this.cellDrawOffsetY | 0;
									}
									if (this.cellAnimIndex === -1) {
										Game.curObjectSprites.drawFrame(g, this.cellAnimFrame, this.cellDrawX + this.cellDrawOffsetX | 0, this.cellDrawY + this.cellDrawOffsetY | 0, this.cellDrawFlip, 0, 0);
									} else {
										Game.curObjectSprites.drawAnimFrame(g, this.cellAnimIndex, this.cellAnimFrame, this.cellDrawX + this.cellDrawOffsetX | 0, this.cellDrawY + this.cellDrawOffsetY | 0, this.cellDrawFlip, 0, 0);
										this.cellAnimIndex = -1;
									}
									Game.curObjectSprites = null;
									this.cellDrawFlip = 0;
									this.cellDrawOffsetY = 0;
									this.cellDrawOffsetX = 0;
								}
							} else {
								if (Game.objectFrameImages[this.terrainSpriteSet] !== null) {
									g.drawImage(Game.objectFrameImages[this.terrainSpriteSet][this.terrainSpriteFrame], this.cellDrawX + this.cellDrawOffsetX | 0, this.cellDrawY + this.cellDrawOffsetY | 0, this.cellDrawAnchor);
								} else {
									Game.spritePacks[Game.getSpritePackForImageSet(this.terrainSpriteSet)].drawFrame(g, this.terrainSpriteFrame, this.cellDrawX + this.cellDrawOffsetX | 0, this.cellDrawY + this.cellDrawOffsetY | 0, this.cellDrawAnchor, 0, 0);
								}
								this.terrainSpriteSet = -1;
								this.cellDrawAnchor = 0;
								this.cellDrawOffsetY = 0;
								this.cellDrawOffsetX = 0;
							}
						}
					}
				}
			}
		}
	}

	clipToPlayfield() {
		this.screenGraphics.setClip(0, 0, 240, 240);
	}

	paintPlayfield() {
		let animIndex = 0, rightOrObject = 0, leftOrRow = 0, screenX = 0, g = null, screenY = 0, wallFrame = 0, fromOrCol = 0, animFrame = 0, pack = null, topOrCol = 0, bottomOrTerrain = 0, frame = 0, frameIndex = 0, toOrRow = 0, s0, s1, s2, s3;
		g = this.screenGraphics;
		frame = Game.frameCount;
		this.explorerDrawMoveDir = (this.explorerStateFlags & 4096) !== 0 ? 0 : this.currentMoveDir;
		g.translate(0, 40);
		this.shake = 0;
		this.clipToPlayfield();
		if (this.shakeTime > 0) {
			this.shake = J.irem(Math.imul(this.shakeTime, frame), (this.shakeTime >> 1) + 1 | 0) % 12;
		}
		if (this.shake > this.camY) {
			this.shake = this.camY;
		}
		this.camY = this.camY - this.shake | 0;
		this.camCellX = this.camX / 24 | 0;
		this.camCellY = this.camY / 24 | 0;
		this.camOffX = this.camX % 24;
		this.camOffY = this.camY % 24;
		this.sparklePhase = (frame & 63) >> 1;
		if (this.sparklePhase >= 4) {
			this.sparklePhase = 0;
		}
		leftOrRow = this.camX - this.camOffX | 0;
		topOrCol = this.camY - this.camOffY | 0;
		rightOrObject = this.camX + Game.bufW - 24 - (this.camX + Game.bufW - 24 | 0) % 24 | 0;
		bottomOrTerrain = this.camY + Game.bufH - 24 - (this.camY + Game.bufH - 24 | 0) % 24 | 0;
		if (Game.bufLeftX === -1) {
			this.renderCellsToBuffer(leftOrRow, topOrCol, rightOrObject, bottomOrTerrain, 0);
			Game.bufLeftX = leftOrRow;
			Game.bufRightX = rightOrObject;
			Game.bufTopY = topOrCol;
			Game.bufBottomY = bottomOrTerrain;
		}
		if (Game.bufLeftX !== leftOrRow) {
			if (Game.bufLeftX >= leftOrRow) {
				fromOrCol = leftOrRow;
				s0 = Game.bufLeftX - 24 | 0;
			} else {
				fromOrCol = Game.bufRightX + 24 | 0;
				s0 = rightOrObject;
			}
			toOrRow = s0;
			this.renderCellsToBuffer(fromOrCol, topOrCol, toOrRow, bottomOrTerrain, 0);
			Game.bufLeftX = leftOrRow;
			Game.bufRightX = rightOrObject;
		}
		if (Game.bufTopY !== topOrCol) {
			if (Game.bufTopY >= topOrCol) {
				fromOrCol = topOrCol;
				s0 = Game.bufTopY - 24 | 0;
			} else {
				fromOrCol = Game.bufBottomY + 24 | 0;
				s0 = bottomOrTerrain;
			}
			toOrRow = s0;
			this.renderCellsToBuffer(leftOrRow, fromOrCol, rightOrObject, toOrRow, 0);
			Game.bufTopY = topOrCol;
			Game.bufBottomY = bottomOrTerrain;
		}
		this.paintLevelBuffer(g);
		this.clipToPlayfield();
		this.paintObjects(g);
		if (!Game.itemRaiseFreeze) {
			this.paintExplorer();
			if (this.hasWaterLayer) {
				this.drawLiquidLayer(this.camOffX, this.camOffY);
			}
			if (Game.playfieldOverlayImage !== null) {
				g.drawImage(Game.playfieldOverlayImage, Game.overlayImageX, Game.overlayImageY, Game.overlayImageAnchor);
			}
			if (this.freezeRayCount > 0) {
				this.drawFreezeRays();
			}
			if (this.specialStageType !== 0) {
				this.paintSpecialStageExtras();
			}
			for (leftOrRow = -1; leftOrRow < 12; leftOrRow++) {
				for (topOrCol = -1; topOrCol < 12; topOrCol++) {
					fromOrCol = topOrCol + this.camCellX | 0;
					toOrRow = leftOrRow + this.camCellY | 0;
					if (fromOrCol >= 0 && fromOrCol < this.levelW && toOrRow >= 0) {
						if (toOrRow < this.levelH) {
							rightOrObject = Game.cellObjects[fromOrCol][toOrRow] & 255;
							bottomOrTerrain = Game.cellTypes[fromOrCol][toOrRow];
							if (rightOrObject < 38 || rightOrObject >= 80) {
								screenX = topOrCol * 24 - this.camOffX | 0;
								screenY = leftOrRow * 24 - this.camOffY | 0;
								if (rightOrObject < 20 || rightOrObject >= 26) {
									switch (rightOrObject) {
										default:
											wallFrame = rightOrObject - 80 << 24 >> 24;
											if (wallFrame >= 0) {
												Game.spritePacks[42].drawFrame(g, wallFrame, screenX, screenY, 0, 0, 0);
											}
											break;
										case 36:
											frameIndex = (Game.cellObjects[fromOrCol][toOrRow] >> 8) - 1 | 0;
											frameIndex = (0 + frameIndex * 7 | 0) / 16 | 0;
											Game.spritePacks[20].drawAnimFrame(g, 0, frameIndex, screenX, screenY, 0, 0, 0);
											break;
										case 32:
											Game.spritePacks[16].drawAnimFrame(this.screenGraphics, 0, Game.cellObjects[fromOrCol][toOrRow] >> 8 & 255, screenX, screenY, 0, 0, 0);
											break;
										case 31:
											animIndex = Game.cellObjects[fromOrCol][toOrRow] >> 8;
											pack = Game.spritePacks[15];
											animFrame = J.irem(Game.frameCount >> 1, pack.animFrameCounts[animIndex] & 255);
											pack.drawAnimFrame(this.screenGraphics, animIndex, animFrame, screenX, screenY, 0, 0, 0);
											break;
									}
									frameIndex = (Game.cellObjects[fromOrCol][toOrRow] & -268435456) >> 28;
									if (frameIndex > 0) {
										s0 = Game.spritePacks[13];
										s1 = g;
										s2 = 0;
										s3 = frameIndex;
										s0.drawAnimFrame(s1, s2, s3, screenX, screenY, 0, 0, 0);
									}
								} else {
									frameIndex = rightOrObject - 20 | 0;
									s0 = Game.spritePacks[3];
									s1 = g;
									s2 = frameIndex;
									s3 = J.irem(frame >> 2, Game.spritePacks[3].animFrameCounts[frameIndex] & 255);
									s0.drawAnimFrame(s1, s2, s3, screenX, screenY, 0, 0, 0);
								}
								if (bottomOrTerrain === 54) {
									Game.spritePacks[7].drawAnimFrame(g, 0, Game.frameAtTime(Game.spritePacks[7], 0, Game.cellStates[fromOrCol][toOrRow]), screenX, screenY, 0, 0, 0);
								}
							}
						}
					}
				}
			}
			if (this.hasLandingDust) {
				leftOrRow = (this.landingDustCol - this.camCellX | 0) * 24 - this.camOffX + this.landingDustOffX | 0;
				topOrCol = (this.landingDustRow - this.camCellY + 1 | 0) * 24 - this.camOffY + this.landingDustOffY | 0;
				g.drawImage(Game.spritePacks[13].moduleImages[0][0 + this.landingDustFrame], leftOrRow, topOrCol, 0);
				this.hasLandingDust = 0;
			}
			if (this.hintBubbleImageSet !== -1) {
				g.drawImage(Game.objectFrameImages[13][0], this.explorerScreenX - 12 | 0, this.explorerScreenY - 24 + 2 | 0, 3);
				g.drawImage(Game.objectFrameImages[this.hintBubbleImageSet][this.hintBubbleFrame], this.explorerScreenX - 12 | 0, this.explorerScreenY - 24 | 0, 3);
			}
			if (this.effectQueueHead !== this.effectQueueTail) {
				s0 = this.effectQueueHead;
				while (true) {
					leftOrRow = s0;
					if (leftOrRow === this.effectQueueTail) {
						break;
					}
					topOrCol = Game.effectCells[leftOrRow << 1] * 24 - this.camX | 0;
					rightOrObject = Game.effectCells[(leftOrRow << 1) + 1] * 24 - this.camY | 0;
					if (Game.effectAnims[leftOrRow] >= 0) {
						s0 = Game.spritePacks[9];
						s1 = g;
						s2 = Game.effectAnims[leftOrRow];
						s3 = Game.effectFrames[leftOrRow];
					} else {
						bottomOrTerrain = Game.spritePacks[2];
						s0 = bottomOrTerrain;
						s1 = g;
						s2 = 0;
						s3 = Game.frameAtTime(bottomOrTerrain, 0, Game.effectFrames[leftOrRow]);
					}
					s0.drawAnimFrame(s1, s2, s3, topOrCol, rightOrObject, 0, 0, 0);
					leftOrRow++;
					s0 = leftOrRow & 7;
				}
			}
			this.camY = this.camY + this.shake | 0;
			if (this.isExitingLevel) {
				Game.drawTextInBox(g, Game.spritePacks[41], Game.langStrings[40], 120, 160, 17, 19, 0);
			}
			if (this.stageIntroEndFrame <= Game.frameCount || this.specialStageType === 2) {
				if (this.checkpointTextEndFrame <= Game.frameCount) {
					if (this.checkpointTextEndFrame === Game.frameCount) {
						if (this.checkpointMsgCount <= 2) {
							this.checkpointMsgCount = this.checkpointMsgCount + 1 << 24 >> 24;
							this.writeLivesToSave();
						}
					}
				} else {
					if (this.checkpointMsgCount <= 2) {
						Game.drawTextInBox(g, Game.spritePacks[41], Game.langStrings[36], 120, 230, 33, 20, 0);
					} else {
						if (this.checkpointTextEndFrame === Game.frameCount) {
							if (this.checkpointMsgCount <= 2) {
								this.checkpointMsgCount = this.checkpointMsgCount + 1 << 24 >> 24;
								this.writeLivesToSave();
							}
						}
					}
				}
			} else {
				if (!this.bossTreasureTaken && !this.gotElementalDiamond) {
					leftOrRow = this.stageIntroEndFrame - Game.frameCount | 0;
					if (leftOrRow >= 20) {
						s0 = leftOrRow < 50 ? 120 : (((60 - leftOrRow | 0) * 240 | 0) / 15 | 0);
					} else {
						s0 = ((leftOrRow - 10 | 0) * 240 | 0) / 20 | 0;
					}
					topOrCol = s0;
					rightOrObject = 240 - topOrCol | 0;
					Game.drawTextInBox(g, Game.spritePacks[41], Game.langStrings[Game.worldNameIds[this.world]], topOrCol, 15, 17, 20, 0);
					Game.drawTextInBox(g, Game.spritePacks[41], Game.langStrings[Game.stageNameIds[this.world][this.stage]], rightOrObject, 50, 17, 20, 0);
					if (this.diamondsToOpenExit > 0) {
						Game.drawTextInBox(g, Game.spritePacks[41], this.diamondsNeededText, 120, 190, 17, 5, 1);
					}
				}
			}
			switch (this.specialStageType) {
				case 5:
					if (this.bossState !== -1 && this.bossState !== 15 && this.bossState !== 13 && this.bossState !== 12) {
						s0 = this;
						s1 = g;
						s2 = 4;
						s0.drawBossHealthBar(s1, s2);
					}
					break;
				case 4:
					this.paintAnacondaHealthOrExplosion();
					break;
				case 3:
					if (this.bossState !== -1 && this.bossState !== 15) {
						s0 = this;
						s1 = g;
						s2 = 5;
						s0.drawBossHealthBar(s1, s2);
					}
					break;
				default:
					break;
			}
			g.translate(0, -40);
			g.setClip(0, 0, 240, 320);
			if (this.activeCutscene === null) {
				this.drawHud();
			}
			if (this.hintText !== null) {
				this.hudNeedsRedraw = 1;
				Game.drawTextInBox(g, Game.spritePacks[41], this.hintText, 120, 263, 33, 4, 1);
			}
			if (this.activeCutscene !== null && !Game.itemRaiseFreeze) {
				this.hudNeedsRedraw = 1;
				this.activeCutscene.draw(g);
			}
			if (this.deathLetterboxHeight > 0) {
				this.hudNeedsRedraw = 1;
				g.setColor(0);
				g.fillRect(0, 0, 240, this.deathLetterboxHeight);
				g.fillRect(0, 320 - this.deathLetterboxHeight | 0, 240, this.deathLetterboxHeight);
				g.translate(0, 40);
				this.paintExplorer();
				if (Game.playfieldOverlayImage !== null) {
					g.drawImage(Game.playfieldOverlayImage, Game.overlayImageX, Game.overlayImageY, Game.overlayImageAnchor);
				}
				if (Game.killerSprites !== null) {
					if (this.killerAnim === -1) {
						Game.killerSprites.drawFrame(g, this.killerFrame, this.killerDrawX, this.killerDrawY, this.cellDrawFlip, 0, 0);
					} else {
						Game.killerSprites.drawAnimFrame(g, this.killerAnim, this.killerFrame, (this.killerCol - this.camCellX | 0) * 24 - this.camOffX | 0, (this.killerRow - this.camCellY | 0) * 24 - this.camOffY | 0, this.cellDrawFlip, 0, 0);
					}
				}
				g.translate(0, -40);
			}
			return;
		}
		g.setColor(0);
		g.fillRect(0, 0, 240, 320);
		this.paintExplorer();
		if (Game.playfieldOverlayImage !== null) {
			g.drawImage(Game.playfieldOverlayImage, Game.overlayImageX, Game.overlayImageY, Game.overlayImageAnchor);
		}
		if (this.effectQueueHead !== this.effectQueueTail) {
			s0 = this.effectQueueHead;
			while (true) {
				leftOrRow = s0;
				if (leftOrRow === this.effectQueueTail) {
					break;
				}
				topOrCol = Game.effectCells[leftOrRow << 1] * 24 - this.camX | 0;
				rightOrObject = Game.effectCells[(leftOrRow << 1) + 1] * 24 - this.camY | 0;
				if (Game.effectAnims[leftOrRow] >= 0) {
					s0 = Game.spritePacks[9];
					s1 = g;
					s2 = Game.effectAnims[leftOrRow];
					s3 = Game.effectFrames[leftOrRow];
				} else {
					bottomOrTerrain = Game.spritePacks[2];
					s0 = bottomOrTerrain;
					s1 = g;
					s2 = 0;
					s3 = Game.frameAtTime(bottomOrTerrain, 0, Game.effectFrames[leftOrRow]);
				}
				s0.drawAnimFrame(s1, s2, s3, topOrCol, rightOrObject, 0, 0, 0);
				leftOrRow++;
				s0 = leftOrRow & 7;
			}
		}
		this.screenGraphics.setClip(0, 0, 240, 320);
		g.translate(0, -40);
		this.drawHud();
	}

	drawFreezeRays() {
		let viewTop = 0, viewBottom = 0, lineY = 0, viewLeft = 0, rayYOffset = 0, rightCol = 0, rightEndFree = 0, endX = 0, sparkFrame = 0, leftX = 0, neighbourCol = 0, rightX = 0, leftEndFree = 0, viewRight = 0, leftCol = 0, startX = 0, rayRow = 0, rayY = 0, rayIndex = 0, s0, s1, s2, s3, s4, s5, s6;
		viewTop = this.camY - 24 | 0;
		viewBottom = this.camY + 320 | 0;
		viewLeft = this.camX;
		viewRight = this.camX + 240 | 0;
		sparkFrame = J.irem(Game.frameCount >> 1, Game.spritePacks[2].getAnimFrameCount(1));
		for (rayIndex = 0; rayIndex < Game.freezeRays.length; rayIndex += 3) {
			rayYOffset = 0;
			rayRow = Game.freezeRays[rayIndex + 2];
			rayY = rayRow * 24 | 0;
			if (rayY > viewTop && rayY < viewBottom) {
				leftCol = Game.freezeRays[rayIndex + 0];
				rightCol = Game.freezeRays[rayIndex + 1];
				leftX = leftCol * 24 | 0;
				rightX = rightCol * 24 + 24 | 0;
				if (leftX >= viewLeft && leftX <= viewRight || rightX >= viewLeft && rightX <= viewRight || leftX <= viewLeft && rightX >= viewRight) {
					startX = leftX - viewLeft | 0;
					s0 = leftCol;
					s1 = leftCol === 0 ? 0 : -1;
					neighbourCol = s0 + s1 | 0;
					leftEndFree = 1;
					if (Game.cellTypes[neighbourCol][rayRow] === 48 && (Game.cellStates[neighbourCol][rayRow] & 8) !== 0) {
						startX -= 12;
						leftEndFree = 0;
						if ((Game.cellStates[neighbourCol][rayRow + 1] & 7) !== 3) {
							startX = startX - -Game.cellMoveOffsets[neighbourCol][rayRow + 1] | 0;
						} else {
							rayYOffset = -Game.cellMoveOffsets[neighbourCol][rayRow + 1] | 0;
						}
					}
					endX = rightX - viewLeft | 0;
					s0 = rightCol;
					s1 = rightCol >= (this.levelW - 1 | 0) ? 0 : 1;
					neighbourCol = s0 + s1 | 0;
					rightEndFree = 1;
					if (Game.cellTypes[neighbourCol][rayRow] === 48 && (Game.cellStates[neighbourCol][rayRow] & 8) !== 0) {
						endX += 12;
						rightEndFree = 0;
						if ((Game.cellStates[neighbourCol][rayRow + 1] & 7) !== 3) {
							endX = endX + -Game.cellMoveOffsets[neighbourCol][rayRow + 1] | 0;
						} else {
							rayYOffset = -Game.cellMoveOffsets[neighbourCol][rayRow + 1] | 0;
						}
					}
					lineY = rayY - this.camY + 10 + rayYOffset | 0;
					this.screenGraphics.setColor(1820159);
					this.screenGraphics.drawLine(startX, lineY, endX, lineY);
					lineY += 2;
					this.screenGraphics.drawLine(startX, lineY, endX, lineY);
					lineY--;
					this.screenGraphics.setColor(14153215);
					this.screenGraphics.drawLine(startX, lineY, endX, lineY);
					if (leftEndFree === 0) {
						if (rightEndFree !== 0) {
							s0 = Game.spritePacks[2];
							s1 = this.screenGraphics;
							s2 = 1;
							s3 = sparkFrame;
							s4 = endX;
							s5 = lineY;
							s6 = 0;
							s0.drawAnimFrame(s1, s2, s3, s4, s5, s6, 0, 0);
						}
					} else {
						s0 = Game.spritePacks[2];
						s1 = this.screenGraphics;
						s2 = 1;
						s3 = sparkFrame;
						s4 = startX;
						s5 = lineY;
						s6 = 1;
						s0.drawAnimFrame(s1, s2, s3, s4, s5, s6, 0, 0);
					}
				}
			}
		}
	}

	prepareFreezeEmitterSprite() {
		let state = 0, dir = 0, moveOffset = 0, facingRight = 0, s0, s1;
		state = Game.cellStates[this.paintCellCol][this.paintCellRow];
		if ((state & 8) === 0) {
			Game.curObjectSprites = Game.spritePacks[32];
			dir = state & 7;
			s0 = (state & 16) !== 0 ? 0 : 1;
			facingRight = s0;
			if ((facingRight === 0 || dir !== 2) && (facingRight !== 0 || dir !== 4)) {
				s0 = this;
				s1 = facingRight === 0 ? 0 : 1;
			} else {
				s0 = this;
				s1 = 2;
			}
			s0.cellAnimFrame = s1;
			moveOffset = Game.cellMoveOffsets[this.paintCellCol][this.paintCellRow];
			this.cellDrawOffsetX = Math.imul(moveOffset, Game.dirDeltas[dir]);
			this.cellDrawOffsetY = Math.imul(moveOffset, Game.dirDeltas[dir + 8]);
		}
	}

	applyWindLiftOffset() {
		if ((Game.cellStates[this.paintCellCol][this.paintCellRow] & 7) === 1 && (Game.cellObjects[this.paintCellCol][this.paintCellRow] & 255) === 35) {
			this.cellDrawOffsetX = 0;
			this.cellDrawOffsetY = Game.cellMoveOffsets[this.paintCellCol][this.paintCellRow];
		}
	}

	prepareWindSprite() {
		Game.curObjectSprites = Game.spritePacks[30];
		this.cellAnimIndex = 1;
		this.cellAnimFrame = Game.frameAtTime(Game.curObjectSprites, 1, J.irem(Game.frameCount, Game.getAnimDuration(Game.curObjectSprites, 1)));
	}

	prepareProjectileSprite() {
		let dir = 0, frameRecord = 0, s1;
		dir = Game.cellStates[this.paintCellCol][this.paintCellRow] & 7;
		Game.curObjectSprites = Game.spritePacks[29];
		if ((Game.cellStates[this.paintCellCol][this.paintCellRow] & 8) !== 0) {
			switch (dir) {
				case 4:
					s1 = 12;
					this.cellAnimIndex = s1;
					break;
				case 2:
					s1 = 13;
					this.cellAnimIndex = s1;
					break;
				case 1:
					s1 = 14;
					this.cellAnimIndex = s1;
					break;
				default:
					break;
			}
			this.cellAnimFrame = Game.frameAtTime(Game.curObjectSprites, this.cellAnimIndex, Game.cellMoveOffsets[this.paintCellCol][this.paintCellRow]);
			frameRecord = (Game.curObjectSprites.animFirstFrame[this.cellAnimIndex] + this.cellAnimFrame | 0) * 5 | 0;
			this.cellDrawOffsetX = Game.curObjectSprites.animFrames[frameRecord + 2];
			s1 = Game.curObjectSprites.animFrames[frameRecord + 3];
		} else {
			switch (dir) {
				case 4:
					s1 = 0;
					this.cellAnimFrame = s1;
					break;
				case 2:
					s1 = 1;
					this.cellAnimFrame = s1;
					break;
				case 1:
					s1 = 2;
					this.cellAnimFrame = s1;
					break;
				default:
					break;
			}
			this.cellDrawOffsetX = Math.imul(Game.cellMoveOffsets[this.paintCellCol][this.paintCellRow], Game.dirDeltas[dir]);
			s1 = Math.imul(Game.cellMoveOffsets[this.paintCellCol][this.paintCellRow], Game.dirDeltas[8 + dir]);
		}
		this.cellDrawOffsetY = s1;
	}

	prepareStaffMonkeySprite() {
		let frame = 0, frameRecord = 0, frameRecOrTime = 0, s1;
		Game.curObjectSprites = Game.spritePacks[29];
		this.cellAnimIndex = Game.cellStates[this.paintCellCol][this.paintCellRow] & 31;
		if (this.cellAnimIndex === 8 || this.cellAnimIndex === 9) {
			this.cellAnimFrame = 0;
			frameRecOrTime = (Game.curObjectSprites.animFirstFrame[this.cellAnimIndex] + 0 | 0) * 5 | 0;
			this.cellDrawOffsetX = Game.curObjectSprites.animFrames[frameRecOrTime + 2];
			s1 = -Game.cellMoveOffsets[this.paintCellCol][this.paintCellRow] | 0;
		} else {
			frameRecOrTime = (Game.cellStates[this.paintCellCol][this.paintCellRow] & 8160) >> 5;
			frame = Game.frameAtTime(Game.curObjectSprites, this.cellAnimIndex, frameRecOrTime);
			this.cellAnimFrame = frame;
			frameRecord = (Game.curObjectSprites.animFirstFrame[this.cellAnimIndex] + frame | 0) * 5 | 0;
			this.cellDrawOffsetX = Game.curObjectSprites.animFrames[frameRecord + 2];
			s1 = Game.curObjectSprites.animFrames[frameRecord + 3];
		}
		this.cellDrawOffsetY = s1;
	}

	prepareIcicleSprite() {
		let s1;
		this.cellAnimIndex = (Game.cellStates[this.paintCellCol][this.paintCellRow] & 56) >> 3;
		Game.curObjectSprites = Game.spritePacks[27];
		switch (this.cellAnimIndex) {
			default:
				s1 = Game.cellMoveOffsets[this.paintCellCol][this.paintCellRow];
				this.cellAnimFrame = s1;
				return;
			case 3:
				this.cellAnimFrame = 0;
				this.cellDrawOffsetY = -Game.cellMoveOffsets[this.paintCellCol][this.paintCellRow] | 0;
				return;
			case 1:
				s1 = J.irem(Game.cellMoveOffsets[this.paintCellCol][this.paintCellRow] >> 1, Game.spritePacks[27].getAnimFrameCount(1));
				this.cellAnimFrame = s1;
				return;
		}
	}

	drawExitPadlockAtCell() {
		this.drawExitPadlock(this.cellDrawX, this.cellDrawY, 0);
	}

	drawExitPadlock(x, y, opened) {
		let shackleOffsetY = 0, digitShift = 0, images = null;
		images = Game.objectFrameImages[18];
		shackleOffsetY = 0;
		if (opened !== 0) {
			shackleOffsetY = -5;
		}
		this.screenGraphics.drawImage(images[1], x + 6 | 0, y + shackleOffsetY | 0, 0);
		this.screenGraphics.drawImage(images[0], x + 3 | 0, y + 7 | 0, 0);
		if (opened === 0) {
			digitShift = 0;
			if (this.diamondsToOpenExit < 10) {
				digitShift = Game.spritePacks[0].moduleImages[0][0].getWidth() >> 1;
				digitShift++;
			}
			Game.drawNumberRightAligned(this.screenGraphics, x + 19 - digitShift | 0, y + 13 | 0, this.diamondsToOpenExit, Game.spritePacks[0].moduleImages[0], 0);
		}
	}

	drawLiquidLayer(offsetX, offsetY) {
		let slot = 0, slideX = 0, cellRow = 0, row = 0, animPhase = 0, tileKind = 0, screenX = 0, g = null, col = 0, screenY = 0, cellCol = 0, liquid = 0, frame = 0, s0, s1, s2, s3, s4;
		g = this.screenGraphics;
		for (row = 0; row < 12; row++) {
			for (col = 0; col < 12; col++) {
				cellCol = col + (this.camX / 24 | 0) | 0;
				cellRow = row + (this.camY / 24 | 0) | 0;
				if (cellCol >= 0 && cellCol < this.levelW && cellRow >= 0) {
					if (cellRow < this.levelH) {
						liquid = Game.liquidCells[cellCol][cellRow];
						screenX = col * 24 - offsetX | 0;
						screenY = row * 24 - offsetY | 0;
						slideX = 0;
						if (liquid > 0) {
							s0 = 0;
							while (true) {
								slot = s0;
								if (slot > 2) {
									break;
								}
								if (Game.getLiquidBits(liquid, slot, 0, 3) !== 0) {
									slideX = (Game.getLiquidBits(liquid, slot, 7, 2) << 3) << 24 >> 24;
									if (slideX > 0) {
										frame = Game.getLiquidBits(liquid, slot, 0, 3);
										tileKind = Game.getFlowBits(frame, 45, 2);
										if (tileKind > 1) {
											s0 = 24 - slideX << 24 >> 24;
										} else {
											slideX = slideX - 24 << 24 >> 24;
											s0 = slideX;
										}
										slideX = s0;
										this.clipToPlayfield();
										g.clipRect(screenX, screenY + (slot << 3) | 0, 24, 8);
									}
									frame = this.getLiquidSlotGraphic(cellCol, cellRow, liquid, slot);
									tileKind = frame >> 1;
									animPhase = (tileKind !== 7 ? Game.frameCount : Game.frameCount >> 3) & 1;
									if (tileKind !== 15) {
										if (tileKind === 14 || tileKind === 11) {
											s0 = Game.liquidSprites;
											s1 = g;
											s2 = frame + animPhase | 0;
											s3 = screenX + slideX | 0;
											s4 = screenY;
											s0.drawFrame(s1, s2, s3, s4, 20, 0, 0);
											this.clipToPlayfield();
										} else {
											if (tileKind !== 8 || slot !== 0 || Game.liquidCells[cellCol][cellRow - 1] <= 0) {
												s0 = Game.liquidSprites;
												s1 = g;
												s2 = frame + animPhase | 0;
												s3 = screenX + slideX | 0;
												s4 = screenY + (slot << 3) | 0;
												s0.drawFrame(s1, s2, s3, s4, 20, 0, 0);
												this.clipToPlayfield();
											} else {
												Game.liquidSprites.drawFrame(g, 33, screenX + slideX | 0, screenY, 20, 0, 0);
												slot = 3;
											}
										}
									} else {
										Game.liquidSprites.drawFrame(g, frame + this.blockStripAnimFrame | 0, screenX + slideX - 8 | 0, screenY + (slot << 3) + 8 | 0, 36, 0, 0);
										this.blockStripAnimFrame = this.blockStripAnimFrame + 1 | 0;
										if (this.blockStripAnimFrame > 2) {
											this.blockStripAnimFrame = 0;
										}
									}
								}
								s0 = slot + 1 << 24 >> 24;
							}
						}
					}
				}
			}
		}
	}

	prepareCheckpointStarSprite() {
		let s1;
		this.objectSpriteSet = 20;
		if (Game.cellObjects[this.paintCellCol][this.paintCellRow] >> 8 < this.nextCheckpointIndex) {
			s1 = 7;
		} else {
			s1 = 0 + (Game.frameCount >> 1) % 7 | 0;
		}
		this.objectSpriteFrame = s1;
	}

	drawChest(objectType) {
		let openFrame = 0, packIndex = 0;
		openFrame = Game.cellObjects[this.paintCellCol][this.paintCellRow] >> 8;
		if (openFrame === 255) {
			openFrame = 0;
		}
		packIndex = 14 !== objectType ? 22 : 8;
		if (Game.spritePacks[packIndex] !== null) {
			Game.spritePacks[packIndex].drawAnimFrame(this.screenGraphics, 0, openFrame, this.cellDrawX, this.cellDrawY, 0, 0, 0);
		}
	}

	drawHud() {
		let partialRedraw = 0, barX = 0, g = null, barOffsetX = 0, hudImages = null, segmentWidth = 0, segmentIndex = 0, isLowEnergy = 0, hudPack = null, s0, s1, s2;
		partialRedraw = 0;
		g = this.screenGraphics;
		hudPack = Game.spritePacks[0];
		if (hudPack !== null) {
			g.translate(120, 320);
			if (this.hudNeedsRedraw || Game.screen === 2) {
				hudPack.drawFrame(g, 0, 0, 0, 0, 0, 0);
				if (this.hudFrame19Visible) {
					hudPack.drawFrame(g, 19, 0, 0, 0, 0, 0);
				}
				s0 = hudPack;
			} else {
				partialRedraw = 1;
				g.setClip(-120, -320, 240, 320);
				s0 = hudPack;
			}
			s0.drawFrame(g, 1, 0, 0, 0, 0, 0);
			if (this.hasCompass) {
				hudPack.drawFrame(g, 2, 0, 0, 0, 0, 0);
				hudPack.drawFrame(g, 3 + this.compassDirection | 0, 0, 0, 0, 0, 0);
			}
			if (partialRedraw !== 0) {
				g.setClip(-120, -320, 240, 320);
			}
			if (this.diamondsToOpenExit <= 0) {
				if (BigInt.asIntN(64, JSystem.currentTimeMillis() - this.exitOpenMsgTime) < 1500n) {
					Game.drawTextInBox(g, Game.spritePacks[41], Game.langStrings[34], 0, -55, 33, 5, 1);
				}
			} else {
				this.exitOpenMsgTime = JSystem.currentTimeMillis();
			}
			if (this.explorerEnergy !== this.hudShownEnergy || this.hudNeedsRedraw || this.explorerEnergy <= 1) {
				hudImages = Game.spritePacks[0].moduleImages[0];
				barOffsetX = 0;
				isLowEnergy = this.explorerEnergy <= 1 ? 1 : 0;
				barX = -11 - (Math.imul(Game.saveData[8] - 4 | 0, hudImages[11 + isLowEnergy].getWidth()) / 2 | 0) | 0;
				g.drawImage(hudImages[11 + isLowEnergy], barX, -29, 0);
				barOffsetX = 0 + hudImages[11 + isLowEnergy].getWidth() | 0;
				segmentWidth = hudImages[15].getWidth();
				for (segmentIndex = 0; segmentIndex < Game.saveData[8]; segmentIndex++) {
					if ((this.explorerEnergy > 1 || segmentIndex !== 0 || (Game.frameCount >> 2 & 1) !== 0) && (segmentIndex >= this.explorerEnergy || this.explorerEnergy <= 1)) {
						s0 = g;
						s1 = hudImages;
						s2 = 13;
					} else {
						s0 = g;
						s1 = hudImages;
						s2 = 15;
					}
					s0.drawImage(s1[s2 + isLowEnergy], barX + barOffsetX | 0, -29, 0);
					barOffsetX = barOffsetX + segmentWidth | 0;
				}
				g.drawImage(hudImages[17 + isLowEnergy], barX + barOffsetX | 0, -29, 0);
				this.hudShownEnergy = this.explorerEnergy;
			}
			if (this.hudShownDiamonds !== this.diamondCount || this.hudShownDiamondsLeft !== this.diamondsToOpenExit || this.hudNeedsRedraw) {
				if (this.diamondsToOpenExit <= 0) {
					Game.drawNumberRightAligned(g, 70, -12, this.diamondCount, Game.spritePacks[0].moduleImages[0], 0);
				} else {
					Game.drawDigitStringRightAligned(g, 70, -12, new StringBuffer().append("").append(this.diamondCount).append("/").append(this.diamondsToOpenExit + this.diamondCount | 0).toString(), Game.spritePacks[0].moduleImages[0], 0);
				}
			}
			if (this.hudShownRedDiamonds !== this.redDiamondCount || this.hudNeedsRedraw) {
				this.hudShownRedDiamonds = this.redDiamondCount;
				Game.drawNumberRightAligned(g, 107, -12, this.redDiamondCount, Game.spritePacks[0].moduleImages[0], 0);
			}
			if (this.hudShownLives !== this.lives || this.hudNeedsRedraw) {
				this.hudShownLives = this.lives;
				Game.drawNumberRightAligned(g, -25, -12, this.lives, Game.spritePacks[0].moduleImages[0], 0);
			}
			g.translate(-120, -320);
			g.translate(120, 0);
			if (this.hudNeedsRedraw || Game.screen === 2) {
				hudPack.drawFrame(g, 20, 0, 0, 0, 0, 0);
			}
			if (this.hudShownDiamonds !== this.diamondCount || this.hudShownDiamondsLeft !== this.diamondsToOpenExit || this.hudNeedsRedraw) {
				this.drawExitPadlock(-53, 8, this.diamondsToOpenExit <= 0 ? 1 : 0);
			}
			if (this.hudShownKeysA !== this.goldKeys || this.hudShownKeysB !== this.silverKeys || this.hudNeedsRedraw || Game.screen === 2) {
				hudPack.drawFrame(g, 21, 0, 0, 0, 0, 0);
				Game.drawNumberRightAligned(g, 55, 15, this.goldKeys, Game.spritePacks[0].moduleImages[0], 0);
				Game.drawNumberRightAligned(g, 87, 15, this.silverKeys, Game.spritePacks[0].moduleImages[0], 0);
				this.hudShownKeysA = this.goldKeys;
				this.hudShownKeysB = this.silverKeys;
			}
			g.translate(-120, 0);
			this.hudShownDiamonds = this.diamondCount;
			this.hudShownDiamondsLeft = this.diamondsToOpenExit;
			this.hudNeedsRedraw = 0;
			return;
		}
	}

	prepareLeverSprite() {
		let s1;
		Game.curObjectSprites = Game.spritePacks[6];
		this.cellAnimIndex = 0;
		if (this.switchWallsPhase !== 0) {
			if (this.switchWallsPhase !== 9) {
				s1 = this.leverMoveDir >= 0 ? 3 : 1;
			} else {
				s1 = 2;
			}
		} else {
			s1 = 0;
		}
		this.cellAnimFrame = s1;
	}

	prepareFloorTrapSprite() {
		let pack = null, isActive = 0;
		isActive = Game.cellStates[this.paintCellCol][this.paintCellRow] === 1 ? 1 : 0;
		pack = Game.spritePacks[5];
		pack.drawAnimFrame(this.screenGraphics, isActive, J.irem(Game.frameCount >> 1, pack.getAnimFrameCount(isActive)), this.cellDrawX, this.cellDrawY, 0, 0, 0);
	}

	drawStatueFlame(statueType) {
		let flameActor = null;
		flameActor = Game.actors[4];
		if (statueType !== 23) {
			flameActor.flipFlags = flameActor.flipFlags & -2;
			flameActor.x = this.cellDrawX + 24 | 0;
		} else {
			flameActor.x = this.cellDrawX;
			flameActor.flipFlags = flameActor.flipFlags | 1;
		}
		flameActor.y = this.cellDrawY;
		flameActor.applyFrameOffset();
		flameActor.draw(this.screenGraphics);
	}

	loadMenuResourcesStep(step) {
		switch (step) {
			case 7:
				if (Game.spritePacks[18] === null) {
					Game.spritePacks[18] = Game.loadSpritePack("/ui.f", 3);
				}
				return;
			case 6:
				if (Game.titleLogoImage === null) {
					Game.titleLogoImage = Game.loadPng("/spl.f", 0);
				}
				if (Game.titleBackgroundImage === null) {
					Game.titleBackgroundImage = Game.loadPng("/spl.f", 1);
				}
				if (Game.titleBottomImage !== null) {
					return;
				}
				Game.titleBottomImage = Game.loadPng("/spl.f", 2);
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
				Game.spritePacks[41].lineSpacing = 15;
				return;
			case 1:
				return;
			case 0:
				Game.loadUiFont();
				JSystem.gc();
				return;
		}
	}

	static freeTitleImages() {
		Game.titleLogoImage = null;
		Game.titleBackgroundImage = null;
		Game.titleBottomImage = null;
		Game.stageMapImage = null;
		Game.moreGamesBadgeBg = null;
		Game.stageMapGraphics = null;
		JSystem.gc();
	}

	layoutMenuItems() {
		let itemIndex = 0, textWidth = 0;
		this.menuItemCount = Game.menuDefs[this.menuId].length >> 1;
		this.menuMaxItemWidth = 0;
		for (itemIndex = 0; itemIndex < this.menuItemCount; itemIndex++) {
			textWidth = Game.measureFirstLineWidth(Game.spritePacks[41], Game.langStrings[Game.menuDefs[this.menuId][itemIndex * 2 + 1]], 0);
			if (this.menuId !== 0 || itemIndex !== 3) {
				if (textWidth > this.menuMaxItemWidth) {
					this.menuMaxItemWidth = textWidth;
				}
			}
		}
		this.menuItemsRevealed = 0;
		this.menuTick = 0;
	}

	drawMenuBackground(topY, bottomY) {
		let row = 0;
		if (Game.screen === 4) {
			this.drawTitleBackground(this.screenGraphics, 0);
			for (row = topY - 1 | 0; row < (bottomY - 2 | 0); row++) {
				Game.spritePacks[18].drawFrame(this.screenGraphics, 4, row % 2, row, 0, 0, 0);
			}
		}
		if (Game.screen === 2) {
			this.screenGraphics.setColor(0);
			this.screenGraphics.fillRect(0, topY - 1 | 0, 240, bottomY - 2 - (topY - 1) | 0);
		}
		this.screenGraphics.setColor(16777215);
		this.screenGraphics.drawLine(0, topY - 1 - 1 | 0, 240, topY - 1 - 1 | 0);
		this.screenGraphics.drawLine(0, bottomY - 1 | 0, 240, bottomY - 1 | 0);
		this.screenGraphics.setColor(0);
		this.screenGraphics.drawLine(0, topY - 1 - 2 | 0, 240, topY - 1 - 2 | 0);
		this.screenGraphics.drawLine(0, bottomY - 2 | 0, 240, bottomY - 2 | 0);
	}

	refreshHasSavedGame() {
		this.menuSaveRecheck = 0;
		this.hasSavedGame = Game.readHasSavedGame();
	}

	drawMenu() {
		let offsetOrTime = 0, textLeftX = 0, itemTopY = 0, itemMidY = 0, fullTextWidth = 0, scrollX = 0, itemIndex = 0, menuBottomY = 0, menuTopY = 0, paletteIndex = 0, maxTextWidth = 0, textWidth = 0, needsScroll = 0, s0, s1, s2, s3, s4;
		if (this.menuSaveRecheck) {
			this.refreshHasSavedGame();
		}
		menuTopY = 320 - (this.menuItemCount * 15 + 1 + 2) | 0;
		s0 = menuTopY;
		s1 = this.hasSavedGame || this.menuId !== 0 ? 0 : 15;
		menuTopY = s0 + s1 | 0;
		menuBottomY = 320;
		this.screenGraphics.setClip(0, 0, 240, 320);
		if (Game.screen === 2 && Game.menuFullRedraw && Game.menuRepaintPlayfield) {
			this.hudFrame19Visible = 0;
			this.paintPlayfield();
			this.hudFrame19Visible = 1;
			Game.menuRepaintPlayfield = 0;
		}
		if (Game.screen === 7 || Game.screen === 2) {
			offsetOrTime = menuTopY - (160 - ((320 - menuTopY | 0) / 2 | 0)) | 0;
			menuTopY = menuTopY - offsetOrTime | 0;
			menuBottomY = 320 - offsetOrTime | 0;
		}
		if (this.menuId === 7) {
			Game.spritePacks[41].drawString(this.screenGraphics, Game.langStrings[this.screenSubState !== 5 ? 113 : 102], 120, menuTopY - 20 | 0, 17);
		}
		if (Game.screen === 7) {
			if (this.menuLastDrawnItem === -1 || Game.menuFullRedraw) {
				this.screenGraphics.setColor(0);
				s0 = this.screenGraphics;
				s1 = 0;
				s2 = 0;
				s3 = 240;
				s4 = 320;
			} else {
				offsetOrTime = menuTopY + this.menuLastDrawnItem * 15 | 0;
				this.screenGraphics.setColor(0);
				s0 = this.screenGraphics;
				s1 = 0;
				s2 = offsetOrTime;
				s3 = 240;
				s4 = 16;
			}
			s0.fillRect(s1, s2, s3, s4);
		}
		offsetOrTime = JSystem.currentTimeMillis();
		if (this.menuConfirmStep >= 0 && BigInt.asIntN(64, offsetOrTime - this.menuConfirmStepTime) > 100n) {
			this.menuConfirmStep = this.menuConfirmStep + 1 | 0;
			this.menuConfirmStepTime = offsetOrTime;
		}
		if (this.menuLastDrawnItem !== -1 && !Game.menuFullRedraw) {
			itemIndex = this.menuId !== 0 || this.menuLastDrawnItem <= 1 || this.hasSavedGame ? 0 : 15;
			itemTopY = menuTopY + this.menuLastDrawnItem * 15 - itemIndex | 0;
			this.screenGraphics.setClip(0, itemTopY, 240, 16);
		}
		if (this.menuLastDrawnItem !== this.menuCursor || Game.menuFullRedraw) {
			this.drawMenuBackground(menuTopY, menuBottomY);
		}
		for (itemIndex = 0; itemIndex < this.menuItemCount; itemIndex++) {
			if (this.menuLastDrawnItem === -1 || itemIndex === this.menuLastDrawnItem || itemIndex === this.menuCursor || Game.menuFullRedraw) {
				if (this.menuId !== 0 || itemIndex !== 1 || this.hasSavedGame) {
					itemTopY = menuTopY + itemIndex * 15 | 0;
					itemMidY = itemTopY + 7 | 0;
					if (this.menuId === 0 && itemIndex > 1 && !this.hasSavedGame) {
						itemTopY -= 15;
						itemMidY -= 15;
					}
					paletteIndex = 0;
					if (itemIndex === 2 && this.menuId === 0) {
						paletteIndex = 1;
					}
					if (this.specialStageType !== 2 || itemIndex !== 4 || this.menuId !== 1) {
						if (itemIndex === this.menuCursor) {
							s0 = this.screenGraphics;
							s1 = 13540096;
							s0.setColor(s1);
							s0 = this.screenGraphics;
							s1 = 0;
							s2 = itemMidY - 7 | 0;
							s3 = 240;
							s4 = 16;
							s0.fillRect(s1, s2, s3, s4);
						}
					} else {
						paletteIndex = 0;
						if (itemIndex !== this.menuCursor) {
							this.screenGraphics.setColor(13421772);
							s0 = this.screenGraphics;
							s1 = 0;
							s2 = itemMidY - 7 + 1 | 0;
							s3 = 240;
							s4 = 14;
						} else {
							s0 = this.screenGraphics;
							s1 = 6710886;
							s0.setColor(s1);
							s0 = this.screenGraphics;
							s1 = 0;
							s2 = itemMidY - 7 | 0;
							s3 = 240;
							s4 = 16;
						}
						s0.fillRect(s1, s2, s3, s4);
					}
					scrollX = 0;
					needsScroll = 0;
					Game.spritePacks[41].measureString(Game.langStrings[Game.menuDefs[this.menuId][itemIndex * 2 + 1]]);
					textWidth = SpritePack.textWidth;
					fullTextWidth = textWidth;
					maxTextWidth = itemIndex !== 2 || this.menuId !== 0 ? 210 : 152;
					if (textWidth > maxTextWidth) {
						needsScroll = 1;
						textWidth = maxTextWidth;
					}
					textLeftX = 120 - (textWidth / 2 | 0) | 0;
					if (needsScroll !== 0) {
						scrollX = itemIndex !== this.menuCursor ? 0 : this.menuTextScrollX;
						this.screenGraphics.setClip(textLeftX, itemTopY, textWidth, 15);
					}
					Game.spritePacks[41].paletteIndex = paletteIndex;
					Game.spritePacks[41].drawString(this.screenGraphics, Game.langStrings[Game.menuDefs[this.menuId][itemIndex * 2 + 1]], 120 - (textWidth / 2 | 0) - scrollX | 0, itemMidY + 1 | 0, 6);
					if (needsScroll !== 0) {
						this.screenGraphics.setClip(0, 0, 240, 320);
					}
					if (itemIndex === this.menuCursor) {
						this.screenGraphics.setColor(16777215);
						Game.spritePacks[18].drawFrame(this.screenGraphics, 2, 120 - (textWidth / 2 | 0) - 8 | 0, itemMidY, 0, 0, 10);
						Game.spritePacks[18].drawFrame(this.screenGraphics, 2, 120 + (textWidth / 2 | 0) + 8 | 0, itemMidY, 0, 0, 6);
					}
					if (itemIndex === this.menuCursor && needsScroll !== 0 && this.menuTick % 2 === 0) {
						this.menuTextScrollX = this.menuTextScrollX + this.menuTextScrollStep | 0;
						if (this.menuTextScrollX < -5 || (this.menuTextScrollX + maxTextWidth - 5 | 0) > fullTextWidth) {
							this.menuTextScrollStep = -this.menuTextScrollStep | 0;
							this.menuTextScrollX = this.menuTextScrollX + this.menuTextScrollStep | 0;
						}
					}
				}
			}
		}
		this.menuLastDrawnItem = this.menuCursor;
		this.menuTick = this.menuTick + 1 | 0;
		if (this.menuRevealDelay >= 0) {
			s0 = this;
			s1 = this.menuRevealDelay - 1 | 0;
		} else {
			s0 = this;
			s1 = 3;
		}
		s0.menuRevealDelay = s1;
		if (this.menuRevealDelay === 0 && (this.menuItemsRevealed + 1 | 0) < this.menuItemCount) {
			this.menuItemsRevealed = this.menuItemsRevealed + 1 | 0;
		}
		this.screenGraphics.setClip(0, 0, 240, 320);
		if (this.menuId === 0 && this.showMoreGamesBadge) {
			itemIndex = this.menuTick % 20;
			if (itemIndex < 10) {
				if (this.menuCursor !== 2) {
					if (Game.moreGamesBadgeBg === null) {
						itemTopY = menuTopY + 30 + 1 - (!this.hasSavedGame ? 15 : 0) | 0;
						Game.moreGamesBadgeBg = Image.createImage(28, 14);
						itemMidY = Game.moreGamesBadgeBg.getGraphics();
						itemMidY.translate(-1, -itemTopY | 0);
						this.drawTitleBackground(itemMidY, 0);
						itemMidY.translate(1, itemTopY);
						for (paletteIndex = 0; paletteIndex < 14; paletteIndex++) {
							Game.spritePacks[18].drawFrame(itemMidY, 4, (itemTopY + paletteIndex + 1 | 0) % 2, paletteIndex, 0, 0, 0);
						}
					}
					this.screenGraphics.drawImage(Game.moreGamesBadgeBg, 1, menuTopY + 30 + 1 - (!this.hasSavedGame ? 15 : 0) | 0, 0);
				}
			} else {
				Game.spritePacks[18].drawFrame(this.screenGraphics, 1, 1, menuTopY + 30 + 7 - (!this.hasSavedGame ? 15 : 0) | 0, 0, 0, 6);
			}
		}
		if (this.menuId !== 0 && this.menuId !== 3 && this.menuId !== 1 && this.menuId !== 7) {
			this.drawBackSoftkeyIcon();
		}
		this.drawSelectSoftkeyIcon();
		Game.menuFullRedraw = 0;
		if (this.menuConfirmStep === 2) {
			if (Game.screen === 2) {
				Game.menuFullRedraw = 1;
				Game.menuRepaintPlayfield = 1;
			}
			this.menuConfirmStep = -1;
			this.hudNeedsRedraw = 1;
			this.menuLastDrawnItem = -1;
			this.selectMenuItem();
		}
	}

	drawBackSoftkeyIcon() {
		Game.spritePacks[18].drawFrame(this.screenGraphics, 0, 223, 308, 0, 0, 0);
	}

	drawSelectSoftkeyIcon() {
		Game.spritePacks[18].drawFrame(this.screenGraphics, 3, 2, 308, 0, 0, 0);
	}

	drawLoadingScreen() {
		let barWidth = 0, g = null;
		g = this.screenGraphics;
		g.setColor(0);
		g.fillRect(0, 0, 240, 320);
		barWidth = J.idiv((this.loadingStep + 1 | 0) * 230 | 0, this.loadingStepCount);
		if (barWidth > 230) {
			barWidth = 230;
		}
		g.setColor(13540096);
		this.screenGraphics.fillRect(5, 310, barWidth, 6);
		g.setColor(16554500);
		this.screenGraphics.drawRoundRect(4, 309, 231, 6, 2, 2);
		Game.spritePacks[41].paletteIndex = 0;
		Game.spritePacks[41].drawString(this.screenGraphics, Game.langStrings[37], 120, 293, 1);
	}

	paintSpecialStageExtras() {
		switch (this.specialStageType) {
			case 5:
				this.paintKnightBoss();
				return;
			default:
				return;
			case 4:
				this.paintAnacondaBoss();
				return;
			case 3:
				this.paintYetiBoss();
				return;
			case 2:
				this.paintIntroHintIcon();
				this.paintIntroStageForeground();
				return;
			case 1:
				this.paintFloodStage();
				return;
		}
	}

	paintIntroStageForeground() {
		let pack = null;
		if ((this.camX + 240 | 0) > 1440 && (this.camY + 320 | 0) > 48) {
			if (Game.spritePacks[10] === null) {
				Game.spritePacks[10] = Game.loadSpritePack("/mmv.f", 0);
			}
			pack = Game.spritePacks[10];
			if (this.isPlayerAt(60, 3) || this.isPlayerAt(61, 3)) {
				pack.drawFrame(this.screenGraphics, 1, 1440 - this.camX | 0, 48 - this.camY | 0, 0, 0, 0);
			}
		}
		if (this.playerCol > 55 && this.isExplorerVisible) {
			Game.actors[0].draw(this.screenGraphics);
		}
	}

	paintIntroStageCellOverlay(g) {
		if (Game.spritePacks[10] === null) {
			Game.spritePacks[10] = Game.loadSpritePack("/mmv.f", 0);
		}
		if (this.paintCellCol >= 60 && this.paintCellCol < 65 && this.paintCellRow >= 2 && this.paintCellRow < 7) {
			Game.spritePacks[10].drawFrame(g, 4 + (this.paintCellRow - 2 | 0) * 5 + this.paintCellCol - 60 | 0, this.cellDrawX, this.cellDrawY, 0, 0, 0);
		}
	}

	paintKnightBoss() {
		let knight = null, explosionX = 0, explosionY = 0;
		if (this.bossState !== -1) {
			knight = Game.actors[5];
			knight.x = this.knightX - this.camX | 0;
			knight.y = 504 - this.camY | 0;
			knight.applyFrameOffset();
			knight.draw(this.screenGraphics);
			if (this.bossState === 12) {
				explosionX = this.knightX - this.camX + Math.imul(Game.frameCount, this.bossTimer) % 48 | 0;
				explosionY = Game.actors[5].y + 24 | 0;
				Game.spritePacks[7].drawAnimFrame(this.screenGraphics, 0, J.irem(Game.frameCount, Game.spritePacks[7].getAnimFrameCount(1)), explosionX, explosionY, 0, 0, 0);
				this.hurtPlayerNearExplosion(explosionX, explosionY);
			}
		}
	}

	paintYetiBoss() {
		let colOrActorOrX = 0, explosionY = 0;
		if (this.specialStageType === 3 && BigInt(Game.frameCount) >= BigInt.asIntN(64, this.ceilingCollapseFrame + 80n)) {
			for (colOrActorOrX = 14; colOrActorOrX <= 21; colOrActorOrX++) {
				Game.cellStates[colOrActorOrX][15] = 0;
				Game.cellObjects[colOrActorOrX][15] = -1;
				Game.cellTypes[colOrActorOrX][15] = 44;
				Game.cellMoveOffsets[colOrActorOrX][15] = 0;
				Game.cellUpdateTimers[colOrActorOrX][15] = 24;
			}
			this.ceilingCollapseFrame = 0n;
		}
		if (this.bossState !== 15) {
			if ((this.camX + 240 + 48 | 0) >= this.yetiX && (this.camY + 320 + 48 | 0) >= 504) {
				colOrActorOrX = Game.actors[5];
				colOrActorOrX.x = this.yetiX - this.camX | 0;
				colOrActorOrX.y = 504 - this.camY | 0;
				colOrActorOrX.applyFrameOffset();
				colOrActorOrX.draw(this.screenGraphics);
			}
			if (this.bossState === 12) {
				colOrActorOrX = this.yetiX - this.camX + Math.imul(Game.frameCount, this.bossTimer) % 48 | 0;
				explosionY = Game.actors[5].y + 24 | 0;
				Game.spritePacks[7].drawAnimFrame(this.screenGraphics, 0, J.irem(Game.frameCount, Game.spritePacks[7].getAnimFrameCount(0)), colOrActorOrX, explosionY, 0, 0, 0);
				this.hurtPlayerNearExplosion(colOrActorOrX, explosionY);
			}
		}
	}

	paintAnacondaHealthOrExplosion() {
		let explosionY = 0, explosionX = 0, g = null, anaconda = null;
		g = this.screenGraphics;
		anaconda = Game.actors[5];
		if (this.bossState !== 7) {
			if (this.bossState !== 8 && this.bossState !== 0) {
				this.drawBossHealthBar(g, 3);
			}
			return;
		}
		explosionX = anaconda.x + Math.imul(Game.frameCount, this.bossTimer) % 48 | 0;
		explosionY = anaconda.y;
		if (this.anacondaStateWhenHit === 10) {
			explosionY = explosionY - 144 | 0;
		}
		Game.spritePacks[7].drawAnimFrame(g, 1, J.irem(Game.frameCount, Game.spritePacks[7].getAnimFrameCount(1)), explosionX, explosionY, 0, 0, 0);
		this.hurtPlayerNearExplosion(explosionX, explosionY);
	}

	drawBossHealthBar(g, maxSegments) {
		let barWidth = 0, segment = 0, barX = 0;
		barWidth = maxSegments * 14 + 2 | 0;
		barX = 240 - barWidth >> 1;
		if (this.bossHealth > 0) {
			g.setColor(0);
			g.fillRect(barX, 5, barWidth, 12);
			g.setColor(3913615);
			for (segment = 0; segment < this.bossHealth; segment++) {
				g.fillRect(barX + 2 + segment * 14 | 0, 7, 12, 8);
			}
		}
	}

	paintAnacondaBoss() {
		let riseHeight = 0, g = null, holeOrSavedY = 0, anaconda = null, holeX = 0, slamActor = null, s0, s1, s2;
		g = this.screenGraphics;
		anaconda = Game.actors[5];
		slamActor = Game.actors[4];
		switch (this.bossState) {
			default:
				s0 = -1000;
				riseHeight = s0;
				break;
			case 11:
				s0 = 15 + this.bossTimer * 18 | 0;
				riseHeight = s0;
				break;
			case 10:
				s0 = 15 + this.bossTimer * 18 | 0;
				riseHeight = s0;
				break;
			case 9:
				s0 = 15 + this.bossTimer * 18 | 0;
				riseHeight = s0;
				break;
			case 5:
				riseHeight = 15 + this.bossTimer * 18 | 0;
				this.bossStepDoneThisFrame = 0;
				break;
			case 4:
				s0 = 40 - (this.bossTimer * 2 << 1) | 0;
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
				s0 = this.bossTimer * 1 | 0;
				riseHeight = s0;
				break;
		}
		anaconda.x = (10 + Math.imul(this.anacondaHoleIndex, 2 + (this.anacondaHoleIndex > 0 ? 1 : 0) | 0) | 0) * 24 - this.camX | 0;
		if (this.bossState !== 5) {
			s0 = anaconda;
			s1 = 256 - riseHeight - this.camY | 0;
			s0.y = s1;
		} else {
			holeOrSavedY = anaconda.y;
			anaconda.y = 256 - this.camY - this.anacondaRiseOffset - 15 | 0;
			if (this.getAnacondaHeadRow() === 3) {
				s0 = anaconda;
				s1 = holeOrSavedY;
				s0.y = s1;
			}
		}
		anaconda.draw(g);
		if (this.anacondaSlamVisible) {
			slamActor.y = 96 - this.camY | 0;
			slamActor.x = (this.getAnacondaHoleCol() + 1 | 0) * 24 - this.camX | 0;
			slamActor.draw(g);
		}
		for (holeOrSavedY = 0; holeOrSavedY < 3; holeOrSavedY++) {
			s0 = holeOrSavedY;
			s1 = 2;
			s2 = holeOrSavedY <= 0 ? 0 : 1;
			holeX = (Math.imul(s0, s1 + s2 | 0) + 10 | 0) * 24 - this.camX | 0;
			if (holeX < 240 && holeX > -48 && this.camY > -80) {
				Game.spritePacks[40].drawFrame(g, 1, holeX, 216 - this.camY | 0, 0, 0, 0);
			}
		}
	}

	paintFloodStage() {
		let floodActor = null, tileY = 0, firstTileX = 0, floodTopY = 0, floodLeftX = 0, gateActor = null, floodRightX = 0, tileX = 0, frame = 0;
		frame = Game.frameCount;
		gateActor = Game.actors[2];
		if ((this.camY + this.shake | 0) < 1008 && (this.camY + this.shake | 0) > 592) {
			gateActor.x = 240 - this.camX | 0;
			gateActor.y = 1008 - this.camY | 0;
			gateActor.applyFrameOffset();
			gateActor.draw(this.screenGraphics);
			gateActor.x = 336 - this.camX | 0;
			gateActor.y = 1008 - this.camY | 0;
			gateActor.applyFrameOffset();
			gateActor.flipFlags = 1;
			gateActor.draw(this.screenGraphics);
		}
		if (this.shakeTime > 10) {
			this.paintFallingDebris();
		}
		floodTopY = this.levelH * 24 - this.floodHeight - this.camY | 0;
		firstTileX = 168 - this.camX | 0;
		floodLeftX = firstTileX;
		floodRightX = firstTileX + 240 | 0;
		while (firstTileX <= -24) {
			firstTileX += 24;
		}
		floodActor = Game.actors[1];
		if ((this.floodHeight >= 816 || floodActor.animIndex === 2) && this.floodHeight > 816) {
			for (tileY = floodTopY + 20 | 0; tileY < 320; tileY += 24) {
				for (tileX = firstTileX; tileX < floodRightX; tileX += 24) {
					floodActor.sprite.drawAnimFrame(this.screenGraphics, 1, ((frame >> 1) + tileX + tileY | 0) % 2, tileX, tileY, 0, 0, 0);
				}
			}
		}
		if (gateActor.animIndex === 2) {
			floodActor.flipFlags = 0;
			floodActor.x = floodLeftX + 120 | 0;
			floodActor.y = floodTopY;
			floodActor.applyFrameOffset();
			floodActor.draw(this.screenGraphics);
			floodActor.flipFlags = 1;
			floodActor.draw(this.screenGraphics);
			this.paintAlarmBorder();
		}
	}

	paintFallingDebris() {
		let index = 0, speed = 0, y = 0, x = 0;
		for (index = 3; index < 13; index += 2) {
			speed = 10 * (((2 * index | 0) / 5 | 0) + 1 | 0) | 0;
			x = Math.imul(speed + J.idiv(Game.frameCount, speed) | 0, index) % 240;
			y = Math.imul(J.idiv(320, speed), Game.frameCount) % 320;
			this.screenGraphics.drawImage(Game.objectFrameImages[27][index & 1], x, y, 0);
		}
	}

	paintIntroHintIcon() {
		if (this.introHintIconVisible && this.activeCutscene === null && this.pendingCutsceneId === -1) {
			Game.spritePacks[15].drawAnimFrame(this.screenGraphics, 0, Game.frameCount >> 1 & 3, this.explorerScreenX, this.explorerScreenY - 24 | 0, 0, 0, 0);
		}
	}

	paintAlarmBorder() {
		let green = 0, phase = 0, g = null;
		g = this.screenGraphics;
		phase = (Game.frameCount << 3) % 160;
		green = ((Game.frameCount / 160 | 0) & 1) !== 0 ? 0 + phase | 0 : 160 - phase | 0;
		g.setColor(255, green, 0);
		g.drawRect(0, 0, 239, 319);
	}

	paintExplorer() {
		let insideBorder = 0, row = 0, drawDir = 0, col = 0, actorIndex = 0, actor = null, bobPhaseOrAnim = 0, facing = 0, frame = 0, bobOrOffset = 0, s0, s1;
		if (!this.respawnPanActive) {
			col = this.playerCol;
			row = this.playerRow;
			frame = Game.frameCount;
			facing = this.explorerStateFlags & 7;
			actorIndex = (this.explorerStateFlags & 16384) !== 0 ? 3 : 0;
			actor = Game.actors[actorIndex];
			insideBorder = this.isPlayerInsideBorder();
			drawDir = (this.explorerStateFlags & 2048) !== 0 ? this.explorerStateFlags & 7 : this.explorerDrawMoveDir;
			if (this.isExplorerVisible) {
				this.explorerScreenX = col * 24 + Math.imul(Game.dirDeltas[drawDir], this.playerStep) - this.camX | 0;
				this.explorerScreenY = row * 24 + Math.imul(Game.dirDeltas[drawDir + 8], this.playerStep) - this.camY | 0;
				if ((this.invulnTimer <= 0n || (frame >> 1 & 1) === 0) && this.encasedStruggleCount <= 0) {
					actor.x = this.explorerScreenX;
					actor.y = this.explorerScreenY;
					if (Game.liquidCells !== null && insideBorder !== 0 && facing !== 1 && facing !== 3 && Game.liquidCells[col][row + 1] !== 0 && Game.isHeavyObject(col, row + 1 | 0)) {
						bobPhaseOrAnim = (frame >> 1) + col | 0;
						bobOrOffset = bobPhaseOrAnim % 4;
						if (((bobPhaseOrAnim / 4 | 0) & 1) === 1) {
							bobOrOffset = 4 - bobOrOffset | 0;
						}
						actor.y = actor.y + bobOrOffset | 0;
					}
					actor.applyFrameOffset();
					actor.draw(this.screenGraphics);
					bobPhaseOrAnim = actor.animIndex;
					Game.itemRaiseFreeze = bobPhaseOrAnim === 47 && actor.frameIndex === 0 ? 1 : 0;
					switch (bobPhaseOrAnim) {
						case 40:
						case 47:
						case 48:
							s0 = actor.frameIndex;
							s1 = bobPhaseOrAnim !== 40 ? 6 : 13;
							if (s0 > s1 || bobPhaseOrAnim === 47) {
								try {
									bobOrOffset = 0;
									if (this.heldItemImageSet === 30 || this.heldItemImageSet === 31 || this.heldItemImageSet === 32) {
										bobOrOffset = -2;
										if (Game.objectFrameImages[this.heldItemImageSet] !== null) {
											this.screenGraphics.drawImage(Game.objectFrameImages[this.heldItemImageSet][this.heldItemFrame], actor.x + bobOrOffset | 0, actor.y - 24 | 0, 0);
										} else {
											Game.spritePacks[Game.getSpritePackForImageSet(this.heldItemImageSet)].drawFrame(this.screenGraphics, this.heldItemFrame, actor.x + bobOrOffset | 0, actor.y - 24 | 0, 0, 0, 0);
										}
									} else {
										if (Game.objectFrameImages[this.heldItemImageSet] !== null) {
											this.screenGraphics.drawImage(Game.objectFrameImages[this.heldItemImageSet][this.heldItemFrame], actor.x + bobOrOffset | 0, actor.y - 24 | 0, 0);
										} else {
											Game.spritePacks[Game.getSpritePackForImageSet(this.heldItemImageSet)].drawFrame(this.screenGraphics, this.heldItemFrame, actor.x + bobOrOffset | 0, actor.y - 24 | 0, 0, 0, 0);
										}
									}
								} catch (ex) {
									ex = J.exc(ex);
									if (J.isa(ex, "java/lang/Exception")) {
										s0 = ex;
									}
									else throw ex;
								}
								if (this.heldItemAmount > 0) {
									Game.drawNumberRightAligned(this.screenGraphics, actor.x + 24 | 0, actor.y - 10 | 0, this.heldItemAmount, Game.spritePacks[0].moduleImages[0], 0);
								}
							}
							break;
						case 17:
						case 18:
							if (actor.frameIndex === 0) {
								this.screenGraphics.drawImage(Game.objectFrameImages[this.heldItemImageSet][this.heldItemFrame], actor.x, actor.y - 12 | 0, 0);
							}
							break;
						default:
							break;
					}
				}
				if (insideBorder === 0 || Game.cellTypes[col][row] !== 0) {
					return;
				}
				bobPhaseOrAnim = Game.cellStates[col][row] & 7;
				bobOrOffset = Game.cellMoveOffsets[col][row];
				try {
					Game.spritePacks[Game.getSpritePackForImageSet(1)].drawFrame(this.screenGraphics, 0 + (Game.cellStates[col][row] & 56) | 0, col * 24 - this.camX + Math.imul(Game.dirDeltas[bobPhaseOrAnim], bobOrOffset) | 0, row * 24 - this.camY + Math.imul(Game.dirDeltas[bobPhaseOrAnim + 8], bobOrOffset) | 0, 0, 0, 0);
				} catch (ex) {
					ex = J.exc(ex);
					if (J.isa(ex, "java/lang/Exception")) {
						s0 = ex;
						return;
					}
					else throw ex;
				}
				return;
			}
			return;
		}
	}

	prepareLooseObjectSprite() {
		let row = 0, moveOffset = 0, inLiquid = 0, rollRight = 0, col = 0, moveDir = 0, rollFrameOrPhase = 0, rollStepOrBob = 0, state = 0, rowBelow = 0, s0, s1;
		col = this.paintCellCol;
		row = this.paintCellRow;
		rowBelow = row + 1 | 0;
		this.landingDustOffX = 0;
		this.landingDustOffY = 0;
		this.hasLandingDust = 0;
		state = Game.cellStates[col][row];
		moveDir = state & 7;
		moveOffset = Game.cellMoveOffsets[col][row];
		if (state === -1) {
			state = -1;
		}
		this.cellDrawOffsetX = this.cellDrawOffsetX + Math.imul(moveOffset, Game.dirDeltas[moveDir]) | 0;
		this.cellDrawOffsetY = this.cellDrawOffsetY + Math.imul(moveOffset, Game.dirDeltas[moveDir + 8]) | 0;
		inLiquid = Game.liquidCells !== null && Game.liquidCells[col][row] !== 0 ? 1 : 0;
		switch (this.paintCellTerrain) {
			case 47:
				Game.curObjectSprites = Game.spritePacks[30];
				this.cellAnimIndex = 0;
				this.cellAnimFrame = Game.frameAtTime(Game.curObjectSprites, 0, J.irem(Game.frameCount, Game.getAnimDuration(Game.curObjectSprites, 0)));
				break;
			case 9:
				Game.curObjectSprites = Game.spritePacks[(state & 264241152) >> 22];
				this.cellAnimFrame = 0;
				break;
			case 8:
				this.terrainSpriteSet = 16;
				this.terrainSpriteFrame = 0 + (Game.frameCount >> 1 & 1) | 0;
				break;
			case 7:
				this.terrainSpriteSet = 5;
				this.terrainSpriteFrame = 1;
				break;
			case 6:
				this.terrainSpriteSet = 5;
				this.terrainSpriteFrame = 0;
				break;
			case 5:
				this.terrainSpriteSet = 25;
				this.terrainSpriteFrame = 0 + this.sparklePhase | 0;
				break;
			case 4:
				this.terrainSpriteSet = 24;
				this.terrainSpriteFrame = 0 + this.sparklePhase | 0;
				break;
			case 2:
				this.prepareRedDiamondSprite();
				break;
			case 1:
				this.terrainSpriteSet = 2;
				this.terrainSpriteFrame = 0 + this.sparklePhase | 0;
				break;
			case 0:
				rollFrameOrPhase = (state & 56) >> 3;
				rollStepOrBob = (state & 28672) >> 12;
				s0 = (state & 65536) !== 0 ? 0 : 1;
				rollRight = s0;
				if (inLiquid !== 0 || moveDir !== 0 || !Game.isHeavyObject(col, rowBelow)) {
					state = state & -28673;
				} else {
					state = state & -28673 | rollStepOrBob << 12;
					if (rollRight === 0) {
						state = state | 65536;
						rollStepOrBob = -rollStepOrBob | 0;
					} else {
						state = state & -65537;
					}
					this.cellDrawOffsetX = rollStepOrBob;
				}
				Game.cellStates[col][row] = state;
				this.terrainSpriteSet = 1;
				this.terrainSpriteFrame = 0 + rollFrameOrPhase | 0;
				break;
			default:
				break;
		}
		if (inLiquid !== 0 || Game.liquidCells !== null && Game.liquidCells[col][rowBelow] !== 0 && Game.isHeavyObject(col, rowBelow)) {
			rollFrameOrPhase = (Game.frameCount >> 1) + col | 0;
			rollStepOrBob = rollFrameOrPhase % 4;
			if (((rollFrameOrPhase / 4 | 0) & 1) === 1) {
				rollStepOrBob = 4 - rollStepOrBob | 0;
			}
			this.cellDrawOffsetY = this.cellDrawOffsetY + rollStepOrBob | 0;
		}
		if (((state & 512) !== 0 || Game.cellTypes[col - Game.dirDeltas[moveDir]][rowBelow] < 0 && Game.isHeavyObject(col, rowBelow) && (Game.cellStates[col][rowBelow] & 7) === 0 && col !== this.slidingObjCol && row !== this.slidingObjRow) && (this.explorerStateFlags & 8) === 0) {
			this.cellDrawOffsetY = this.cellDrawOffsetY + (Math.imul(moveOffset, moveOffset) / 24 | 0) | 0;
			if (this.paintCellTerrain !== 9) {
				this.cellDrawOffsetX = this.cellDrawOffsetX + (-1 + Game.frameCount % 3) | 0;
			}
		}
		if ((state & 512) !== 0) {
			this.cellDrawOffsetX = -this.cellDrawOffsetX | 0;
		}
		if (this.paintCellTerrain === 0) {
			this.landingDustFrame = ((state & 448) >> 6) - 1 | 0;
			if (this.landingDustFrame >= 0 && this.landingDustFrame < 5) {
				this.hasLandingDust = 1;
				switch (state & 7) {
					default:
						s0 = this;
						s1 = 0;
						break;
					case 4:
						s0 = this;
						s1 = 24;
						break;
					case 2:
						s0 = this;
						s1 = -24;
						break;
				}
				s0.landingDustOffX = s1;
				this.landingDustOffY = 13;
				this.landingDustCol = this.paintCellCol;
				this.landingDustRow = this.paintCellRow - 1 | 0;
			}
		}
		this.applyWindLiftOffset();
	}

	prepareEnemy49Sprite() {
		let row = 0, moveOffset = 0, col = 0, moveDir = 0, facing = 0, state = 0, s1;
		col = this.paintCellCol;
		row = this.paintCellRow;
		state = Game.cellStates[col][row];
		moveOffset = Game.cellMoveOffsets[col][row];
		moveDir = state & 7;
		this.cellDrawOffsetX = Math.imul(moveOffset, Game.dirDeltas[moveDir]);
		this.cellDrawOffsetY = Math.imul(moveOffset, Game.dirDeltas[moveDir + 8]);
		Game.curObjectSprites = Game.spritePacks[38];
		facing = (state & 28672) >> 12;
		if ((facing === 2 || facing === 4 || moveDir === 2 || moveDir === 4) && Game.cellTypes[col - 1][row] >= 0 && Game.cellTypes[col + 1][row] >= 0 || (facing === 1 || facing === 3 || moveDir === 1 || moveDir === 3) && Game.cellTypes[col][row - 1] >= 0 && Game.cellTypes[col][row + 1] >= 0) {
			this.cellAnimIndex = 1;
			s1 = 0;
		} else {
			if (moveDir === 1 || moveDir === 3) {
				s1 = moveDir - 1 | 0;
			} else {
				s1 = 0;
			}
			this.cellAnimIndex = s1;
			s1 = J.irem(Game.frameCount >> 1, Game.curObjectSprites.getAnimFrameCount(this.cellAnimIndex));
		}
		this.cellAnimFrame = s1;
		this.applyWindLiftOffset();
	}

	prepareSnakeSprite(snakeType) {
		let moveOffset = 0, hitCounter = 0, packIndex = 0, moveDir = 0, state = 0, s1, s2, s3;
		state = Game.cellStates[this.paintCellCol][this.paintCellRow];
		moveOffset = Game.cellMoveOffsets[this.paintCellCol][this.paintCellRow];
		moveDir = state & 7;
		this.cellDrawOffsetX = Math.imul(moveOffset, Game.dirDeltas[moveDir]);
		this.cellDrawOffsetY = Math.imul(moveOffset, Game.dirDeltas[moveDir + 8]);
		packIndex = snakeType !== 19 ? 21 : 4;
		Game.curObjectSprites = Game.spritePacks[packIndex];
		B1: {
			if (this.world === 1) {
				hitCounter = (state & 248) >> 3;
				if (hitCounter <= 0) {
					s1 = 0;
				} else {
					s1 = 2;
				}
				this.cellAnimIndex = s1;
				s1 = Game.frameCount;
				s2 = Game.curObjectSprites;
				s3 = this.cellAnimIndex;
				break B1;
			}
			hitCounter = (state & 248) >> 3;
			B2: {
				if (hitCounter > 0) {
					s1 = 4;
					this.cellAnimIndex = s1;
					break B2;
				}
				this.cellAnimIndex = moveDir - 1 | 0;
				if (this.cellAnimIndex < 0) {
					s1 = ((state & 28672) >> 12) - 1 | 0;
					this.cellAnimIndex = s1;
				}
			}
			s1 = Game.frameCount >> 1;
			s2 = Game.curObjectSprites;
			s3 = this.cellAnimIndex >= 0 ? this.cellAnimIndex : 0;
		}
		this.cellAnimFrame = J.irem(s1, s2.getAnimFrameCount(s3));
		this.applyWindLiftOffset();
	}

	preparePressurePlateSprite() {
		let row = 0, col = 0, s1;
		col = this.paintCellCol;
		row = this.paintCellRow;
		this.objectSpriteSet = 26;
		this.objectSpriteFrame = 0;
		B1: {
			if (Game.isHeavyObject(col, row) && Game.cellMoveOffsets[col][row] <= 12) {
				s1 = -(Game.cellMoveOffsets[col][row] - 12) | 0;
				this.cellDrawOffsetY = s1;
				break B1;
			}
			if (!this.isPlayerAt(col, row)) {
				if (!this.isPlayerAt(col - 1 | 0, row)) {
					if (this.isPlayerAt(col + 1 | 0, row) && this.explorerDrawMoveDir === 2 && this.playerStep > 12) {
						s1 = this.playerStep - 12 | 0;
						this.cellDrawOffsetY = s1;
					}
				} else {
					B5: {
						if (this.explorerDrawMoveDir === 4 && this.playerStep > 12) {
							s1 = this.playerStep - 12 | 0;
							this.cellDrawOffsetY = s1;
							break B5;
						}
					}
				}
			} else {
				B6: {
					if ((this.explorerStateFlags & 4096) !== 0) {
						s1 = 12;
						this.cellDrawOffsetY = s1;
						break B6;
					}
					B7: {
						if (this.playerStep <= 12) {
							s1 = -(this.playerStep - 12) | 0;
							this.cellDrawOffsetY = s1;
							break B7;
						}
					}
				}
			}
		}
		this.cellDrawOffsetY = this.cellDrawOffsetY + 24 | 0;
		this.cellDrawAnchor = 36;
	}

	prepareRedDiamondSprite() {
		let chestType = 0, chestFrame = 0, s1, s2;
		chestType = Game.cellObjects[this.paintCellCol][this.paintCellRow] & 255;
		chestFrame = Game.cellObjects[this.paintCellCol][this.paintCellRow] >> 8;
		if (chestType !== 14 && chestType !== 33 || chestFrame > 11) {
			this.terrainSpriteSet = 3;
			this.terrainSpriteFrame = 0 + this.sparklePhase | 0;
			B2: {
				if (chestType === 14) {
					s1 = Game.spritePacks;
					s2 = 8;
					this.cellDrawOffsetY = -(s1[s2].getAnimFrameCount(0) - chestFrame) | 0;
					break B2;
				}
				if (chestType === 33) {
					s1 = Game.spritePacks;
					s2 = 22;
					this.cellDrawOffsetY = -(s1[s2].getAnimFrameCount(0) - chestFrame) | 0;
				}
			}
		}
	}

	prepareWallCrawlerSprite() {
		let deathStage = 0, row = 0, col = 0, moveDir = 0, s1;
		col = this.paintCellCol;
		row = this.paintCellRow;
		this.terrainSpriteSet = 6;
		deathStage = (Game.cellStates[col][row] & 3840) >> 8;
		if (deathStage < 4) {
			if (deathStage !== 0) {
				s1 = 3 + deathStage - 1 | 0;
			} else {
				s1 = 0 + (Game.frameCount >> 1) % 3 | 0;
			}
			this.terrainSpriteFrame = s1;
			moveDir = Game.cellStates[col][row] & 7;
			this.cellDrawOffsetX = Math.imul(Game.cellMoveOffsets[col][row], Game.dirDeltas[moveDir]) + 2 | 0;
			this.cellDrawOffsetY = Math.imul(Game.cellMoveOffsets[col][row], Game.dirDeltas[moveDir + 8]) + 2 | 0;
			B3: {
				if ((Game.cellStates[col][row] & 16) !== 0) {
					switch (moveDir) {
						case 4:
							s1 = this.cellDrawOffsetY + 4 | 0;
							this.cellDrawOffsetY = s1;
							break B3;
						case 3:
							this.cellDrawOffsetX = this.cellDrawOffsetX + 4 | 0;
							return;
						case 2:
							s1 = this.cellDrawOffsetY - 4 | 0;
							this.cellDrawOffsetY = s1;
							break B3;
						default:
							return;
						case 1:
							this.cellDrawOffsetX = this.cellDrawOffsetX - 4 | 0;
							return;
					}
				} else {
					switch (moveDir) {
						case 4:
							s1 = this.cellDrawOffsetY - 4 | 0;
							this.cellDrawOffsetY = s1;
							return;
						case 3:
							this.cellDrawOffsetX = this.cellDrawOffsetX - 4 | 0;
							break B3;
						case 2:
							s1 = this.cellDrawOffsetY + 4 | 0;
							this.cellDrawOffsetY = s1;
							return;
						default:
							return;
						case 1:
							this.cellDrawOffsetX = this.cellDrawOffsetX + 4 | 0;
							break B3;
					}
				}
			}
			return;
		}
		this.terrainSpriteSet = -1;
	}

	drawExtendingRod() {
		let extension = 0, baseX = 0, tipX = 0, s1;
		this.screenGraphics.setColor(13883367);
		extension = Game.cellMoveOffsets[this.paintCellCol][this.paintCellRow];
		if ((Game.cellStates[this.paintCellCol][this.paintCellRow] & 1) === 0) {
			baseX = this.cellDrawX + 24 | 0;
			tipX = this.cellDrawX + extension | 0;
			s1 = 1;
		} else {
			baseX = this.cellDrawX;
			tipX = this.cellDrawX + 24 - extension | 0;
			s1 = 0;
		}
		this.cellAnimFrame = s1;
		this.screenGraphics.drawLine(baseX, this.cellDrawY + 12 | 0, tipX, this.cellDrawY + 12 | 0);
		if (extension > 0) {
			Game.actors[0].sprite.drawModule(this.screenGraphics, this.cellAnimFrame, tipX, this.cellDrawY + 12 - 2 | 0, 0);
		}
	}

	prepareKeyDoorSprite() {
		let doorParam = 0, s1;
		doorParam = Game.cellObjects[this.paintCellCol][this.paintCellRow] >> 8;
		this.objectSpriteSet = this.paintCellObject !== 9 ? 23 : 22;
		if ((doorParam & 512) === 0) {
			if ((doorParam & 256) === 0) {
				s1 = 0;
			} else {
				s1 = 1;
			}
		} else {
			s1 = 1 + (Game.frameCount >> 2) % 6 << 24 >> 24;
		}
		this.objectSpriteFrame = s1;
	}

	prepareDoorBaseSprite() {
		let openStage = 0, row = 0, col = 0, param = 0;
		col = this.paintCellCol;
		row = this.paintCellRow;
		param = Game.cellObjects[col][row] >> 8;
		openStage = ((param & 240) >> 4) - 1 | 0;
		if (openStage < 0) {
			openStage = 0;
		}
		if ((Game.cellObjects[col][row - 1] & 255) !== 9 && (Game.cellObjects[col][row - 1] & 255) !== 8) {
			Game.spritePacks[56].drawFrame(this.screenGraphics, openStage, this.cellDrawX, this.cellDrawY, 0, 0, 0);
		}
		this.objectSpriteSet = 4;
		this.objectSpriteFrame = openStage + 3 << 24 >> 24;
	}

	prepareRollerSprite() {
		let moveOffset = 0, moveDir = 0, trailFrame = 0, state = 0, frame = 0;
		frame = Game.frameCount;
		state = Game.cellStates[this.paintCellCol][this.paintCellRow];
		moveOffset = Game.cellMoveOffsets[this.paintCellCol][this.paintCellRow];
		if (moveOffset > 24) {
			moveOffset = 24;
		}
		moveDir = state & 7;
		this.cellDrawOffsetX = Math.imul(moveOffset, Game.dirDeltas[moveDir]);
		this.cellDrawOffsetY = Math.imul(moveOffset, Game.dirDeltas[moveDir + 8]);
		if ((state & 8) !== 0) {
			this.terrainSpriteSet = 10;
			this.terrainSpriteFrame = 2 - (frame >> 1) % 3 | 0;
			if (moveDir !== 3) {
				trailFrame = (frame >> 1) % 5;
				this.screenGraphics.drawImage(Game.objectFrameImages[10][8 + trailFrame], this.cellDrawX + 24 - 12 + this.cellDrawOffsetX + trailFrame * 3 | 0, this.cellDrawY + (this.cellDrawOffsetY + 24) | 0, 36);
				if ((frame >> 1 & 1) === 0 && Game.cellTypes[this.paintCellCol - 1][this.paintCellRow] >= 0) {
					this.cellDrawOffsetX = this.cellDrawOffsetX - 1 | 0;
					this.cellDrawOffsetY = this.cellDrawOffsetY + 1 | 0;
				}
			}
		} else {
			this.terrainSpriteSet = 10;
			this.terrainSpriteFrame = (frame >> 1) % 3;
			if (moveDir !== 3) {
				trailFrame = (frame >> 1) % 5;
				this.screenGraphics.drawImage(Game.objectFrameImages[10][3 + trailFrame], this.cellDrawX + this.cellDrawOffsetX - trailFrame * 4 | 0, this.cellDrawY + (this.cellDrawOffsetY + 24) | 0, 36);
				return;
			}
		}
	}

	prepareTallTrapSprite() {
		let timeLeft = 0, moveOffset = 0, frameDataIndex = 0, pack = null, state = 0, frameIdx = 0;
		if (Game.cellTypes[this.paintCellCol][this.paintCellRow + 1] !== 16) {
			state = Game.cellStates[this.paintCellCol][this.paintCellRow];
			pack = Game.spritePacks[1];
			Game.curObjectSprites = pack;
			moveOffset = Game.cellMoveOffsets[this.paintCellCol][this.paintCellRow];
			timeLeft = 36 - moveOffset | 0;
			frameIdx = 0;
			this.cellAnimIndex = (state & 7) === 4 ? 1 : 0;
			if (moveOffset !== 0) {
				frameDataIndex = 0;
				while (timeLeft > 0) {
					timeLeft = timeLeft - pack.getFrameDuration(this.cellAnimIndex, frameDataIndex) | 0;
					frameIdx = frameDataIndex;
					frameDataIndex++;
				}
			}
			this.cellAnimFrame = frameIdx;
			frameDataIndex = (pack.animFirstFrame[this.cellAnimIndex] + frameIdx | 0) * 5 | 0;
			this.cellDrawOffsetX = pack.animFrames[frameDataIndex + 2];
			return;
		}
	}

	prepareHopperSprite() {
		let frameOrTime = 0, animFrameCount = 0, animTime = 0, frameCursor = 0, state = 0, frameDataOrLast = 0, s0;
		state = Game.cellStates[this.paintCellCol][this.paintCellRow];
		Game.curObjectSprites = Game.spritePacks[28];
		this.cellAnimIndex = state & 15;
		animTime = (Game.cellStates[this.paintCellCol][this.paintCellRow] & 2088960) >> 13;
		if (this.cellAnimIndex !== 10) {
			frameOrTime = Game.frameAtTime(Game.curObjectSprites, this.cellAnimIndex, animTime);
			this.cellAnimFrame = frameOrTime;
			frameDataOrLast = (Game.curObjectSprites.animFirstFrame[this.cellAnimIndex] + frameOrTime | 0) * 5 | 0;
			this.cellDrawOffsetX = Game.curObjectSprites.animFrames[frameDataOrLast + 2];
			this.cellDrawOffsetY = Game.curObjectSprites.animFrames[frameDataOrLast + 3];
		} else {
			frameOrTime = animTime;
			frameDataOrLast = 0;
			animFrameCount = Game.curObjectSprites.getAnimFrameCount(this.cellAnimIndex);
			s0 = 0;
			while (true) {
				frameCursor = s0;
				if (frameOrTime <= 0) {
					break;
				}
				frameOrTime = frameOrTime - Game.curObjectSprites.getFrameDuration(this.cellAnimIndex, frameCursor) | 0;
				frameDataOrLast = frameCursor;
				s0 = J.irem(frameCursor + 1 | 0, animFrameCount);
			}
			this.cellAnimFrame = frameDataOrLast;
		}
		this.applyWindLiftOffset();
	}

	static frameAtTime(pack, animIndex, time) {
		let frameCursor = 0, frame = 0;
		frame = 0;
		frameCursor = 0;
		while (time > 0) {
			time = time - pack.getFrameDuration(animIndex, frameCursor) | 0;
			frame = frameCursor;
			frameCursor++;
		}
		return frame;
	}

	static animTimeBeforeFrame(pack, animIndex, frameCount) {
		let total = 0, frame = 0;
		total = 0;
		for (frame = 0; frame < frameCount; frame++) {
			total = total + pack.getFrameDuration(animIndex, frame) | 0;
		}
		return total;
	}

	updateHopperEnemy() {
		let row = 0, playerIsLeft = 0, frameOrHitDir = 0, onSteam = 0, dirToPlayerOrRow = 0, col = 0, animDuration = 0, variantBits = 0, destRow = 0, destFree = 0, animIsVertical = 0, animTime = 0, animIndex = 0, destCol = 0, nextAnimOrCol = 0, s0, s1, s2;
		col = this.updateCellCol;
		row = this.updateCellRow;
		Game.cellUpdateTimers[col][row] = 24;
		variantBits = (Game.cellStates[col][row] & 7168) >> 10;
		animIndex = Game.cellStates[col][row] & 15;
		animDuration = 0;
		onSteam = (Game.cellObjects[col][row] & 255) === 35 ? 1 : 0;
		if (animIndex !== 10) {
			animTime = Game.spritePacks[28].getAnimFrameCount(animIndex);
			for (frameOrHitDir = 0; frameOrHitDir < animTime; frameOrHitDir++) {
				animDuration = animDuration + Game.spritePacks[28].getFrameDuration(animIndex, frameOrHitDir) | 0;
			}
		} else {
			animDuration = 100;
		}
		animTime = (Game.cellStates[col][row] & 2088960) >> 13;
		animTime++;
		Game.cellStates[col][row] = Game.cellStates[col][row] & -2088961 | animTime << 13;
		if (animIndex < 4 || animIndex > 9) {
			s0 = Game.cellMoveOffsets[col];
			s1 = row;
			s2 = 0;
		} else {
			s0 = Game.cellMoveOffsets[col];
			s1 = row;
			s2 = 12;
		}
		s0[s1] = s2;
		if (animTime > animDuration >> 1) {
			if (onSteam === 0) {
				if (this.isPlayerAt(col, row) && animIndex !== 10) {
					switch (animIndex) {
						default:
							s0 = Game.oppositeDir[this.explorerStateFlags & 7];
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
					this.damageExplorer(1, 48, frameOrHitDir);
				}
				if (this.isCellCrushed(col, row)) {
					Game.cellTypes[col][row] = -1;
					this.killEnemyAt(col, row);
					return;
				}
			}
			if (animTime >= animDuration) {
				Game.wakeCellsAround(col, row);
				dirToPlayerOrRow = this.chooseDirectionToward(col, row, this.playerCol, this.playerRow, 1);
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
				playerIsLeft = dirToPlayerOrRow === 4 ? 1 : 0;
				if (animIsVertical === playerIsLeft) {
					destCol = col - Game.dirDeltas[dirToPlayerOrRow] | 0;
					destRow = row - Game.dirDeltas[8 + dirToPlayerOrRow] | 0;
					if (playerIsLeft === 0) {
						if (!this.isPlayerAt(destCol, destRow) || animIndex === 1) {
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
						if (!this.isPlayerAt(destCol, destRow) || animIndex === 0) {
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
					nextAnimOrCol = playerIsLeft === 0 ? 2 : 3;
					destCol = col;
					destRow = row;
				}
				s0 = Game.cellTypes[destCol][destRow] >= 0 ? 0 : 1;
				destFree = s0;
				if (destFree === 0 || onSteam !== 0) {
					if (destCol !== col || destRow !== row) {
						nextAnimOrCol = 0;
					}
					destCol = col;
					destRow = row;
				}
				Game.cellTypes[col][row] = -1;
				Game.cellMoveOffsets[destCol][destRow] = 0;
				Game.cellStates[destCol][destRow] = variantBits << 10 | nextAnimOrCol;
				Game.cellStates[destCol][destRow] = Game.cellStates[destCol][destRow] & -2088961;
				Game.cellTypes[destCol][destRow] = 45;
			}
		}
		if (onSteam === 0) {
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
			if (this.isPlayerAt(nextAnimOrCol, dirToPlayerOrRow)) {
				this.damageExplorer(1, 48, Game.oppositeDir[this.explorerStateFlags & 7]);
			}
		} else {
			B23: {
				if (this.isPlayerAt(col, row) && animIndex !== 10) {
					this.damageExplorer(1, 48, Game.oppositeDir[this.explorerStateFlags & 7]);
					break B23;
				}
			}
		}
	}

	drawPistonTrap() {
		let firstFrame = 0, segmentCount = 0, segment = 0, extent = 0, state = 0, dirSign = 0, s0, s1, s2, s3, s4;
		dirSign = -1;
		firstFrame = 3;
		state = Game.cellStates[this.paintCellCol][this.paintCellRow];
		if ((state & 7) === 3) {
			dirSign = 1;
			firstFrame = 0;
		}
		if ((state & 8) !== 0) {
			segmentCount = this.pistonFastSegments;
			s0 = this.pistonFastExtent;
		} else {
			segmentCount = this.pistonSlowSegments;
			s0 = this.pistonSlowExtent;
		}
		extent = s0;
		for (segment = 0; segment < segmentCount; segment++) {
			Game.spritePacks[11].drawFrame(this.screenGraphics, firstFrame + Math.imul(segment, dirSign) | 0, this.cellDrawX + 3 | 0, this.cellDrawY + Math.imul(dirSign, extent - segment * 24 | 0) | 0, 0, 0, 0);
		}
		if (dirSign !== 1) {
			s0 = Game.spritePacks[42];
			s1 = this.screenGraphics;
			s2 = Game.cellTypes[this.paintCellCol][this.paintCellRow + 1] - 80 | 0;
			s3 = this.cellDrawX;
			s4 = this.cellDrawY + 24 | 0;
		} else {
			s0 = Game.spritePacks[42];
			s1 = this.screenGraphics;
			s2 = Game.cellTypes[this.paintCellCol][this.paintCellRow - 1] - 80 | 0;
			s3 = this.cellDrawX;
			s4 = this.cellDrawY - 24 | 0;
		}
		s0.drawFrame(s1, s2, s3, s4, 0, 0, 0);
	}

	paintGameloftLogo() {
		let framesLeft = 0, dropY = 0, actor = null, bounceY = 0, s0, s1, s2, s3, s4;
		actor = Game.actors[0];
		this.screenGraphics.setColor(0);
		this.screenGraphics.fillRect(0, 0, 240, 320);
		actor.y = 136;
		bounceY = 0;
		if (Game.frameCount <= 30) {
			actor.x = Game.frameCount * 4 - 1 + 18 | 0;
		} else {
			actor.x = 139;
			actor.setAnimation(1);
			dropY = (Game.frameCount - 30 | 0) * 4 | 0;
			if (dropY <= 29) {
				actor.sprite.drawFrame(this.screenGraphics, 10, 138, 136, 0, 0, 0);
			} else {
				dropY = 29;
				if (Game.frameCount >= 42) {
					s0 = actor.sprite;
					s1 = this.screenGraphics;
					s2 = 4;
					s3 = 138;
					s4 = 136;
				} else {
					framesLeft = 42 - Game.frameCount | 0;
					bounceY = 0 + J.irem(Math.imul(framesLeft, framesLeft), (framesLeft >> 1) + 1 | 0) | 0;
					s0 = actor.sprite;
					s1 = this.screenGraphics;
					s2 = 10;
					s3 = 138;
					s4 = 136 + bounceY | 0;
				}
				s0.drawFrame(s1, s2, s3, s4, 0, 0, 0);
				actor.frameIndex = 0;
			}
			actor.y = 136 + dropY | 0;
		}
		actor.y = actor.y + bounceY | 0;
		actor.draw(this.screenGraphics);
		actor.sprite.drawFrame(this.screenGraphics, 5, 138, 160 + bounceY | 0, 0, 0, 0);
	}

	static drawNumberRightAligned(g, rightX, y, value, digitImages, imageBase) {
		let digit = 0, digitImage = null;
		if (value !== 0) {
			while (value > 0) {
				digit = value % 10;
				value = value / 10 | 0;
				digitImage = digitImages[digit + imageBase];
				rightX = rightX - digitImage.getWidth() | 0;
				g.drawImage(digitImage, rightX, y, 0);
			}
			return;
		}
		digitImage = Game.spritePacks[0].moduleImages[0][0];
		g.drawImage(digitImage, rightX, y, 24);
	}

	static drawDigitStringRightAligned(g, rightX, y, text, digitImages, imageBase) {
		let charIndex = 0, digitImage = null, charCode = 0;
		for (charIndex = text.length - 1 | 0; charIndex >= 0; charIndex--) {
			charCode = text.charCodeAt(charIndex);
			if (charCode === 47) {
				charCode = 58;
			}
			charCode = charCode - 48 & 0xFFFF;
			digitImage = digitImages[charCode + imageBase];
			g.drawImage(digitImage, rightX, y, 24);
			rightX = rightX - digitImage.getWidth() | 0;
		}
	}

	isPlayerInsideBorder() {
		if (this.playerCol <= 0 || this.playerCol >= (this.levelW - 1 | 0) || this.playerRow <= 0 || this.playerRow >= (this.levelH - 1 | 0)) {
			return 0;
		}
		return 1;
	}

	setExplorerAnim(anim) {
		let liquidLevel = 0, prevAnim = 0, s0;
		prevAnim = Game.actors[0].animIndex;
		if (prevAnim !== 19 && (this.explorerStateFlags & 16384) === 0 && (this.explorerStateFlags & 2048) === 0) {
			if (this.isPlayerInsideBorder()) {
				s0 = Game.liquidCells !== null ? (Game.getLiquidBits(Game.liquidCells[this.playerCol][this.playerRow], 0, 3, 4)) : 0;
				liquidLevel = s0;
				if (liquidLevel === 8 || liquidLevel === 7) {
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
							anim = 36 + (this.explorerStateFlags & 7) - 1 | 0;
							break;
						default:
							break;
					}
				} else {
					if (Game.cellTypes[this.playerCol][this.playerRow + 1] < 0 || Game.cellTypes[this.playerCol][this.playerRow + 1] === 14) {
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
			if (anim !== 1000) {
				Game.actors[0].setAnimation(anim);
			} else {
				Game.actors[3].setAnimation(0);
				this.explorerStateFlags = this.explorerStateFlags | 16384;
			}
			if (prevAnim !== anim) {
				this.playerIdleCountdown = 70;
			}
		}
	}

	handleShopInput() {
		let itemStatus = 0, s1, s2;
		if (!Game.isKeyDown(32944)) {
			if (!Game.isKeyDown(64)) {
				if (!Game.isKeyDown(4097)) {
					if (Game.isKeyDown(262146)) {
						s1 = 1;
						this.moveShopCursor(s1);
					}
				} else {
					s1 = -1;
					this.moveShopCursor(s1);
				}
				Game.keys = 0;
				itemStatus = Game.getShopItemStatus(this.shopCursor);
				if (itemStatus !== 0) {
					this.shopItemCost = Tables.upgradeCosts[this.shopCursor];
					this.shopPriceText.delete(0, this.shopPriceText.length());
					this.shopPriceText.append(this.shopItemCost);
					s1 = Game.langStrings;
					s2 = 90;
				} else {
					this.shopItemCost = -1;
					s1 = Game.langStrings;
					s2 = 81;
				}
				this.shopMessage = s1[s2];
				this.needsFullRedraw = 1;
				return;
			}
			Game.keys = 0;
			Game.screen = 27;
			this.needsFullRedraw = 1;
			this.worldMapInfoDirty = 1;
			Game.keys = 0;
			return;
		}
		Game.keys = 0;
		this.needsFullRedraw = 1;
		this.buyShopItem(this.shopCursor);
	}

	static getShopItemStatus(itemIndex) {
		let savedDiamonds = 0, maxEnergy = 0;
		maxEnergy = Game.saveData[8];
		if (maxEnergy < (4 + itemIndex + 1 | 0)) {
			savedDiamonds = Game.readU16LE(Game.saveData, 4);
			if (savedDiamonds >= Tables.upgradeCosts[itemIndex]) {
				return 1;
			}
			return -1;
		}
		return 0;
	}

	buyShopItem(itemIndex) {
		this.shopLastDrawnCursor = -1;
		switch (Game.getShopItemStatus(itemIndex)) {
			case 1:
				this.diamondCount = Game.readU16LE(Game.saveData, 4) - Tables.upgradeCosts[this.shopCursor] | 0;
				this.shopDiamondsText = null;
				JSystem.gc();
				this.shopDiamondsText = new StringBuffer(Game.langStrings[110]).append(" ").append(this.diamondCount).append(" ").append(Game.langStrings[109]).toString();
				Game.saveData[4] = (this.diamondCount & 255) << 24 >> 24;
				Game.saveData[5] = (this.diamondCount >> 8 & 255) << 24 >> 24;
				Game.saveData[8] = 4 + itemIndex + 1 << 24 >> 24;
				this.writeSaveRecord();
				this.shopItemCost = -1;
				this.shopMessage = Game.langStrings[81];
				this.shopPurchaseMsgPending = 1;
				this.showPopup(Game.langStrings[91], -1, -1, 5000, 4273165, 0);
				return;
			default:
				return;
			case 0:
				this.shopMessage = Game.langStrings[81];
				return;
			case -1:
				this.shopMessage = Game.langStrings[89];
				return;
		}
	}

	moveShopCursor(delta) {
		this.shopCursor = this.shopCursor + delta | 0;
		if (this.shopCursor < 0) {
			this.shopCursor = 3;
		}
		if (this.shopCursor === 4) {
			this.shopCursor = 0;
		}
	}

	handleReturnToMenuInput() {
		if (Game.isKeyDown(64)) {
			Game.screen = 4;
			this.openMenu(4);
		}
		Game.keys = 0;
	}

	dispatchKeyInput() {
		let s0;
		if (Game.keys !== 0) {
			if (!Game.isPopupVisible()) {
				switch (Game.screen) {
					case 34:
						this.handleDebugTextInput();
						break;
					case 33:
						this.handleHelpScreenInput();
						break;
					case 31:
						if (!Game.isKeyDown(64)) {
							if (Game.isKeyDown(32944)) {
								this.startNewGame();
							}
						} else {
							this.loadingStep = 0;
							this.loadingStepCount = 8;
							Game.screen = 9;
							this.openMenu(-1);
						}
						s0 = 0;
						Game.keys = s0;
						break;
					case 30:
						B6: {
							if (Game.isKeyDown(32784)) {
								Game.screen = 4;
								if (this.menuId !== -1) {
									this.screenSubState = 2;
								} else {
									this.screenSubState = 0;
									this.openMenu(0);
								}
								s0 = 0;
								Game.keys = s0;
								break B6;
							}
						}
						break;
					case 27:
						Game.returnScreen = Game.screen;
						this.checkCheatCode();
						this.handleWorldMapInput();
						break;
					case 26:
						this.handleReturnToMenuInput();
						break;
					case 25:
						this.handleShopInput();
						break;
					case 24:
						this.handleCheatMenuInput();
						break;
					case 18:
						break;
					case 17:
					case 20:
						B8: {
							if (Game.isKeyDown(32944)) {
								if (this.screenSubState === 5) {
									this.returnToStageMap();
									this.cleanup();
								}
								this.resultsSkipPressed = 1;
								s0 = 0;
								Game.keys = s0;
								break B8;
							}
						}
						break;
					case 15:
						this.handleStageMapInput();
						break;
					case 12:
						this.handleGameOverInput();
						break;
					case 10:
						break;
					case 4:
						this.handleMenuInput();
						break;
					case 2:
					case 7:
					case 32:
						this.handleMenuInput();
						break;
					case 1:
						if (this.gotElementalDiamond || this.bossTreasureTaken) {
							Game.keys = 0;
						}
						Game.returnScreen = Game.screen;
						this.checkCheatCode();
						this.handlePlayInput();
						break;
					default:
						break;
				}
				if (!this.isKeyReleased) {
					if ((this.explorerStateFlags & 7) !== 0) {
						this.keyHoldTimer = 10;
					}
					return;
				}
				return;
			}
			this.hidePopup(1);
			Game.keys = 0;
			return;
		}
		this.requestedMoveDir = 0;
	}

	startNewGame() {
		this.isNewGame = 1;
		Game.screen = 16;
		this.loadingStep = 0;
		this.loadingStepCount = 6;
		this.lives = 0;
		this.redDiamondCount = 0;
		this.diamondCount = 0;
		this.hasCompass = 0;
		this.loadingTipIndex = 0;
		Game.latestUnlockedStage = 0;
	}

	handleHelpScreenInput() {
		if (Game.isKeyDown(64)) {
			if (this.menuId === 0) {
				Game.screen = 4;
				this.openMenu(0);
				this.sound.play(19);
			}
			if (this.menuId === 1) {
				Game.screen = 2;
				Game.menuFullRedraw = 1;
				this.hudNeedsRedraw = 1;
				this.openMenu(1);
			}
		}
	}

	checkCheatCode() {
		let s0;
		if (Game.cheatCodeProgress >= Game.cheatCodeKeys.length || !Game.isKeyDown(Game.cheatCodeKeys[Game.cheatCodeProgress])) {
			if (!Game.isKeyDown(Game.cheatCodeKeys[0])) {
				s0 = 0;
			} else {
				Game.keys = 0;
				s0 = 1;
			}
			Game.cheatCodeProgress = s0;
		} else {
			Game.keys = 0;
			Game.cheatCodeProgress = Game.cheatCodeProgress + 1 << 24 >> 24;
			if (Game.cheatCodeProgress === Game.cheatCodeKeys.length) {
				Game.keys = 0;
				Game.screen = 24;
				this.cheatMaxEnergy = Game.saveData[8];
				this.cheatWeaponFlags = Game.saveData[9];
				this.cheatUnlockAllStages = 0;
				this.cheatUnlockSecretStages = 0;
				return;
			}
		}
	}

	handleWorldMapInput() {
		let s1;
		if (this.placingElementalIndex !== -1 || this.worldUnlockAnimIndex !== 0) {
			Game.keys = 0;
			return;
		}
		B2: {
			if (Game.isKeyDown(32944)) {
				s1 = 4;
				this.worldMapCommand = s1;
				break B2;
			}
			if (!Game.isKeyDown(64)) {
				B4: {
					if (Game.isKeyDown(4097)) {
						s1 = 0;
						this.worldMapCommand = s1;
						break B4;
					}
					B5: {
						if (Game.isKeyDown(262146)) {
							s1 = 2;
							this.worldMapCommand = s1;
							break B5;
						}
						B6: {
							if (Game.isKeyDown(16388)) {
								s1 = 3;
								this.worldMapCommand = s1;
								break B6;
							}
							if (Game.isKeyDown(65544)) {
								s1 = 1;
								this.worldMapCommand = s1;
							}
						}
					}
				}
			} else {
				this.cleanup();
				Game.screen = 9;
				this.loadingStepCount = 8;
				this.openMenu(-1);
				this.loadingStep = 0;
			}
		}
		Game.keys = 0;
	}

	cheatSkipStage() {
		if (this.world !== 0 || this.stage !== 13) {
			this.usedMainExit = Game.isKeyDown(524288);
			this.fromStageClear = !this.usedMainExit ? 1 : 0;
			this.livesLostInStage = 0;
			this.hitsTaken = 0;
			this.isExitingLevel = 1;
			this.playerCol = this.levelW + 5 + 1 | 0;
			return;
		}
		this.activeCutscene = null;
		this.playerCol = 60;
		this.playerRow = 3;
	}

	handleCheatMenuInput() {
		let worldIndex = 0, stageIndex = 0, closeMenu = 0, lastStage = 0, s1;
		closeMenu = 0;
		if (!Game.isKeyDown(512)) {
			if (!Game.isKeyDown(65536)) {
				if (!Game.isKeyDown(131072)) {
					if (!Game.isKeyDown(262144)) {
						if (!Game.isKeyDown(524288)) {
							if (!Game.isKeyDown(32768)) {
								if (!Game.isKeyDown(1024)) {
									B8: {
										if (Game.isKeyDown(64)) {
											closeMenu = 1;
											break B8;
										}
										if (Game.isKeyDown(32944)) {
											Game.saveData[8] = this.cheatMaxEnergy << 24 >> 24;
											Game.saveData[9] = this.cheatWeaponFlags << 24 >> 24;
											if (this.cheatUnlockAllStages || this.cheatUnlockSecretStages) {
												for (worldIndex = 0; worldIndex <= 2; worldIndex++) {
													lastStage = this.getWorldFirstSecretStage(worldIndex);
													if (worldIndex === 2) {
														lastStage++;
													}
													for (stageIndex = 0; stageIndex <= lastStage; stageIndex++) {
														this.addStageFlags(worldIndex, stageIndex, 2);
														this.addStageFlags(worldIndex, stageIndex, 64);
													}
													this.raiseSavedLatestStage(worldIndex, lastStage);
												}
												if (this.cheatUnlockSecretStages) {
													for (worldIndex = 0; worldIndex <= 2; worldIndex++) {
														lastStage = this.getWorldStageCount(worldIndex);
														if (worldIndex === 0) {
															lastStage--;
														}
														for (stageIndex = this.getWorldFirstSecretStage(worldIndex); stageIndex < lastStage; stageIndex++) {
															this.addStageFlags(worldIndex, stageIndex, 2);
															this.addStageFlags(worldIndex, stageIndex, 64);
														}
														this.raiseSavedLatestStage(worldIndex, lastStage - 1 | 0);
													}
												}
											}
											this.bankStageDiamonds();
											this.bankStageRedDiamonds();
											this.writeSaveRecord();
											closeMenu = 1;
										}
									}
								} else {
									this.cheatUnlockSecretStages = !this.cheatUnlockSecretStages ? 1 : 0;
								}
							} else {
								Game.screen = 34;
							}
						} else {
							this.cheatUnlockAllStages = !this.cheatUnlockAllStages ? 1 : 0;
						}
					} else {
						if (Game.returnScreen !== 1) {
							this.cheatWeaponFlags = this.cheatWeaponFlags << 1;
							B19: {
								if (this.cheatWeaponFlags === 0) {
									s1 = 1;
									this.cheatWeaponFlags = s1;
									break B19;
								}
								if (this.cheatWeaponFlags > 8) {
									s1 = 0;
									this.cheatWeaponFlags = s1;
								}
							}
							if (this.cheatWeaponFlags <= 2) {
								Game.saveData[10] = 0;
							} else {
								Game.saveData[10] = 1;
							}
						}
					}
				} else {
					this.redDiamondCount = this.redDiamondCount + 5 | 0;
				}
			} else {
				this.diamondCount = this.diamondCount + 50 | 0;
			}
		} else {
			this.cheatPassLevels = !this.cheatPassLevels ? 1 : 0;
		}
		if (closeMenu !== 0) {
			this.closeCheatMenu();
		}
		Game.keys = 0;
	}

	closeCheatMenu() {
		Game.screen = Game.returnScreen;
		if (Game.returnScreen !== 27) {
			if (Game.returnScreen === 1) {
				this.requestHudRedraw();
			}
		} else {
			this.needsFullRedraw = 1;
			this.worldMapInfoDirty = 1;
		}
		Game.keys = 0;
	}

	handleDebugTextInput() {
		let maxIndex = 0, textIndex = 0, s0;
		maxIndex = 0;
		textIndex = 0;
		if (Game.isKeyDown(33008)) {
			this.closeCheatMenu();
			Game.freeSpritePack(Game.tipSprites, 1);
			Game.tipSprites = null;
		}
		if (Game.isKeyDown(4097)) {
			this.debugTextPage = this.debugTextPage - 1 | 0;
			if (this.debugTextPage < 0) {
				this.debugTextPage = 0;
			}
		}
		if (Game.isKeyDown(262146)) {
			this.debugTextPage = this.debugTextPage + 1 | 0;
			if (this.debugTextPage >= 2) {
				this.debugTextPage = 1;
			}
		}
		textIndex = this.debugTextIndices[this.debugTextPage];
		if (Game.isKeyDown(16388)) {
			textIndex--;
		}
		if (Game.isKeyDown(65544)) {
			textIndex++;
		}
		if (textIndex < 0) {
			textIndex = 0;
		}
		switch (this.debugTextPage) {
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
			textIndex = maxIndex - 1 | 0;
		}
		this.debugTextIndices[this.debugTextPage] = textIndex;
		Game.keys = 0;
	}

	handleGameOverInput() {
		if (Game.isKeyDown(32944)) {
			this.lives = 5;
			Game.saveData[3] = this.lives << 24 >> 24;
			if (this.specialStageType !== 2) {
				Game.addToSaveCounter(4, -500);
				Game.screen = 15;
				this.needLevelCleanup = 1;
				this.needFreeMapRes = 1;
				this.openStageMap();
				return;
			}
			this.startLevelLoading();
			return;
		}
	}

	handlePlayInput() {
		let isTarget = 0, checkObject = 0, neighborDir = 0, neighborIndex = 0, targetMask = 0, hitDir = 0, isEnemy = 0, targetsBothSides = 0, neighborRow = 0, scratch = 0, aimMasks = null, checkType = 0, signOrDyTable = 0, checkCol = 0, facing = 0, aimDir = 0, sideOrDxTable = 0, rangedDir = 0, distance = 0, neighborCol = 0, s0, s1, s2, t2, t3, t4;
		if (this.cheatPassLevels && (Game.isKeyDown(524288) || Game.isKeyDown(131072))) {
			this.cheatSkipStage();
		}
		if ((this.gateRevealState === 0 || Game.isKeyDown(32944)) && this.entryWalkRemaining === 0 && !this.isExitingLevel && this.explorerEnergy > 0 && Game.actors[0].animIndex !== 19 && !this.respawnPanActive) {
			if (this.activeCutscene === null) {
				if (this.encasedStruggleCount <= 0) {
					if (!Game.isKeyDown(4097)) {
						if (!Game.isKeyDown(262146)) {
							if (!Game.isKeyDown(16388)) {
								if (!Game.isKeyDown(65544)) {
									if (!Game.isKeyDown(32784)) {
										if (!Game.isKeyDown(256)) {
											if (Game.isKeyDown(32944)) {
												this.openPauseMenu();
												Game.keys = 0;
											}
										} else {
											this.hintBubbleImageSet = -1;
											scratch = Game.actors[0].animIndex;
											if (scratch === (36 + (this.explorerStateFlags & 7) - 1 | 0)) {
												if ((Game.cellObjects[this.playerCol][this.playerRow] & 255) !== 4) {
													this.playSound(2);
													this.setExplorerAnim(19);
												} else {
													this.restoreCheckpoint();
												}
											}
											switch (scratch) {
												case 0:
												case 1:
												case 2:
												case 3:
												case 34:
												case 35:
													if ((Game.cellObjects[this.playerCol][this.playerRow] & 255) !== 4) {
														this.playSound(2);
														this.setExplorerAnim(19);
													} else {
														this.restoreCheckpoint();
													}
													break;
												default:
													break;
											}
										}
									} else {
										Game.keys = 0;
										if (this.checkpointCol !== this.playerCol || this.checkpointRow !== this.playerRow || (Game.cellObjects[this.playerCol][this.playerRow] & 255) !== 4) {
											s0 = Game.liquidCells !== null ? (Game.getLiquidBits(Game.liquidCells[this.playerCol][this.playerRow], 0, 3, 4)) : 0;
											scratch = s0;
											if (scratch !== 8 && scratch !== 7) {
												facing = this.explorerStateFlags & 7;
												aimDir = -1;
												rangedDir = -1;
												targetsBothSides = 0;
												if (Game.saveData[9] >= 2) {
													targetMask = 0;
													for (sideOrDxTable = 0; sideOrDxTable < 2; sideOrDxTable++) {
														s0 = sideOrDxTable !== 0 ? -1 : 1;
														signOrDyTable = s0;
														if (signOrDyTable > 0 && this.playerCol < (this.levelW - 3 | 0) || signOrDyTable < 0 && this.playerCol > 3) {
															for (distance = 1; distance <= 3; distance++) {
																checkCol = this.playerCol + Math.imul(signOrDyTable, distance) | 0;
																checkType = Game.cellTypes[checkCol][this.playerRow];
																checkObject = Game.cellObjects[checkCol][this.playerRow] & 255;
																if (checkObject !== 7 || (Game.cellObjects[checkCol][this.playerRow] >> 8 & 240) !== 0) {
																	if (checkType !== 48 || (Game.cellStates[checkCol][this.playerRow] & 8) === 0) {
																		switch (checkType) {
																			case 11:
																			case 19:
																			case 43:
																				if (signOrDyTable <= 0) {
																					if (signOrDyTable < 0) {
																						s0 = targetMask;
																						s1 = 4;
																						targetMask = s0 | s1;
																					}
																				} else {
																					s0 = targetMask;
																					s1 = 2;
																					targetMask = s0 | s1;
																				}
																				if (distance === 1) {
																					s0 = 4;
																				} else {
																					if (rangedDir >= 0) {
																						targetsBothSides = 1;
																						if (targetMask !== 2) {
																							s0 = targetMask !== 4 ? -1 : 4;
																						} else {
																							s0 = 2;
																						}
																						rangedDir = s0;
																						s0 = 4;
																					} else {
																						rangedDir = signOrDyTable <= 0 ? 4 : 2;
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
																				if (distance === 1) {
																					s0 = 4;
																				} else {
																					if (rangedDir >= 0) {
																						targetsBothSides = 1;
																						if (targetMask !== 2) {
																							s0 = targetMask !== 4 ? -1 : 4;
																						} else {
																							s0 = 2;
																						}
																						rangedDir = s0;
																						s0 = 4;
																					} else {
																						rangedDir = signOrDyTable <= 0 ? 4 : 2;
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
												if (Game.saveData[9] >= 1) {
													this.requestedMoveDir = 5;
													targetMask = 0;
													t2 = new Int32Array(12);
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
													t3 = new Int32Array(12);
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
													t4 = new Int32Array(12);
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
													for (neighborIndex = 0; neighborIndex < sideOrDxTable.length; neighborIndex++) {
														neighborCol = this.playerCol + sideOrDxTable[neighborIndex] | 0;
														neighborRow = this.playerRow + signOrDyTable[neighborIndex] | 0;
														if (neighborCol >= 0 && neighborCol < this.levelW && neighborRow >= 0) {
															if (neighborRow < this.levelH) {
																neighborDir = Game.cellStates[neighborCol][neighborRow] & 7;
																isEnemy = 0;
																hitDir = -1;
																isTarget = 0;
																switch (Game.cellTypes[neighborCol][neighborRow]) {
																	case 46:
																	case 49:
																	case 50:
																		if (aimMasks[neighborIndex] === 0) {
																			targetMask++;
																			isTarget = 1;
																		}
																		break;
																	case 45:
																		if ((Game.cellStates[neighborCol][neighborRow] & 15) !== 10) {
																			isEnemy = 1;
																		}
																		break;
																	case 19:
																	case 43:
																		if ((Game.cellStates[neighborCol][neighborRow] & 248) === 0) {
																			isEnemy = 1;
																		}
																		break;
																	case 9:
																	case 18:
																	case 30:
																		if (aimMasks[neighborIndex] === 0) {
																			isTarget = 1;
																		}
																		break;
																	default:
																		break;
																}
																if (isEnemy !== 0) {
																	if (aimMasks[neighborIndex] !== 0) {
																		if (Game.cellMoveOffsets[neighborCol][neighborRow] >= 12) {
																			if ((aimMasks[neighborIndex] & 1) === 0 || neighborDir !== 3) {
																				if ((aimMasks[neighborIndex] & 8) !== 0 && neighborDir === 2) {
																					if (signOrDyTable[neighborIndex] !== 0) {
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
																				if (sideOrDxTable[neighborIndex] !== 0) {
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
																		s0 = neighborIndex + 1 | 0;
																		hitDir = s0;
																	}
																	if (hitDir !== -1) {
																		isTarget = 1;
																		targetMask++;
																	}
																}
																if (isTarget !== 0) {
																	if (targetMask !== 0) {
																		if (targetMask !== 1) {
																			aimDir = facing;
																			break;
																		}
																		aimDir = hitDir;
																	} else {
																		if (facing !== (neighborIndex + 1 | 0)) {
																			if (aimDir < 0) {
																				aimDir = neighborIndex + 1 | 0;
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
												B63: {
													if (aimDir > 0 && rangedDir === facing) {
														this.requestedMoveDir = 6;
														s0 = this;
														s1 = this.explorerStateFlags & -8;
														s2 = facing;
														s0.explorerStateFlags = s1 | s2;
														break B63;
													}
													B64: {
														if (aimDir > 0 && rangedDir < 0 && targetsBothSides === 0) {
															s0 = this;
															s1 = this.explorerStateFlags & -8;
															s2 = aimDir;
															s0.explorerStateFlags = s1 | s2;
															break B64;
														}
														B65: {
															if (aimDir < 0 && rangedDir > 0 && targetsBothSides === 0) {
																this.requestedMoveDir = 6;
																s0 = this;
																s1 = this.explorerStateFlags & -8;
																s2 = rangedDir;
																s0.explorerStateFlags = s1 | s2;
																break B65;
															}
															B66: {
																if (targetsBothSides !== 0 && (facing === 2 || facing === 4)) {
																	this.requestedMoveDir = 6;
																	s0 = this;
																	s1 = this.explorerStateFlags & -8;
																	s2 = facing;
																	s0.explorerStateFlags = s1 | s2;
																	break B66;
																}
																if (targetsBothSides !== 0 && rangedDir > 0) {
																	this.requestedMoveDir = 6;
																	s0 = this;
																	s1 = this.explorerStateFlags & -8;
																	s2 = rangedDir;
																	s0.explorerStateFlags = s1 | s2;
																}
															}
														}
													}
												}
												if (this.requestedMoveDir === 6 && (Game.cellObjects[this.playerCol][this.playerRow] & 255) === 2 && Game.cellObjects[this.playerCol][this.playerRow] >> 8 === 1) {
													this.hintBubbleImageSet = -1;
													this.clearConnectedObjects(this.playerCol, this.playerRow, 2);
												}
											}
										} else {
											this.playSound(9);
											this.restoreCheckpoint();
										}
									}
								} else {
									this.requestedMoveDir = 2;
								}
							} else {
								this.requestedMoveDir = 4;
							}
						} else {
							this.requestedMoveDir = 3;
						}
					} else {
						this.requestedMoveDir = 1;
					}
					if (this.requestedMoveDir !== 5 && this.currentMoveDir === 0 && this.keyHoldTimer === 0 && this.requestedMoveDir !== (this.explorerStateFlags & 7)) {
						this.explorerStateFlags = this.explorerStateFlags | 4096;
					}
				} else {
					scratch = 1;
					if (!Game.isKeyDown(4097)) {
						if (!Game.isKeyDown(262146)) {
							if (!Game.isKeyDown(16388)) {
								if (!Game.isKeyDown(65544)) {
									if (!Game.isKeyDown(32784)) {
										if (!Game.isKeyDown(32944)) {
											scratch = 0;
										} else {
											this.openPauseMenu();
											Game.keys = 0;
										}
									}
								} else {
									this.frozenShakeX = 5;
								}
							} else {
								this.frozenShakeX = -5;
							}
						} else {
							this.frozenShakeY = 5;
						}
					} else {
						this.frozenShakeY = -5;
					}
					if (scratch !== 0) {
						this.encasedStruggleCount = this.encasedStruggleCount - 1 | 0;
						if (this.encasedStruggleCount === 0) {
							if ((Game.cellObjects[this.playerCol][this.playerRow] & 255) << 24 >> 24 < 0) {
								Game.cellObjects[this.playerCol][this.playerRow] = 32;
							}
							if (Game.cellTypes[this.playerCol][this.playerRow] === 9) {
								Game.cellTypes[this.playerCol][this.playerRow] = -1;
							}
							this.invulnTimer = 40n;
							this.playerStep = 0;
							this.explorerStateFlags = this.explorerStateFlags & -113 | 0;
							this.setExplorerAnim(this.endHurtState());
						}
						Game.keys = 0;
						return;
					}
				}
				return;
			}
			if (!Game.isKeyDown(32784)) {
				if (Game.isKeyDown(32944)) {
					this.activeCutscene.isSkipped = 1;
				}
			} else {
				this.activeCutscene.onConfirmPressed();
			}
			Game.keys = 0;
			return;
		}
		Game.keys = 0;
	}

	handleMenuInput() {
		if (this.menuConfirmStep < 0 || this.menuConfirmStep > 2) {
			if (!Game.isKeyDown(4097)) {
				if (!Game.isKeyDown(262146)) {
					if (!Game.isKeyDown(32944)) {
						if (Game.isKeyDown(64)) {
							this.handleMenuBack();
						}
					} else {
						if (this.menuConfirmStep < 0 || this.menuConfirmStep > 2) {
							this.menuConfirmStep = 0;
							this.menuConfirmStepTime = JSystem.currentTimeMillis();
						}
					}
				} else {
					if (BigInt.asIntN(64, JSystem.currentTimeMillis() - this.menuMoveLockTime) < 300n) {
						return;
					}
					this.moveMenuCursorDown();
					if (this.menuId === 0 && this.menuCursor === 1 && !this.hasSavedGame) {
						this.moveMenuCursorDown();
					}
				}
			} else {
				if (BigInt.asIntN(64, JSystem.currentTimeMillis() - this.menuMoveLockTime) < 300n) {
					return;
				}
				this.moveMenuCursorUp();
				if (this.menuId === 0 && this.menuCursor === 1 && !this.hasSavedGame) {
					this.moveMenuCursorUp();
				}
			}
			Game.keys = 0;
			return;
		}
		Game.keys = 0;
	}

	handleMenuBack() {
		switch (this.menuId) {
			case 5:
				Game.menuFullRedraw = 1;
				Game.menuRepaintPlayfield = 0;
				if (Game.screen === 2) {
					this.openMenu(1);
					this.requestHudRedraw();
					Game.menuRepaintPlayfield = 1;
				}
				if (Game.screen !== 4) {
					return;
				}
				this.openMenu(0);
				this.playSound(19);
				return;
			case 4:
				this.openMenu(2);
				return;
			default:
				return;
			case 2:
				Game.screen = 9;
				this.openMenu(0);
				this.loadingStepCount = 8;
				this.loadingStep = 0;
				return;
			case -1:
				return;
		}
	}

	strikeCell(col, row) {
		let dRows = null, moveOffset = 0, i = 0, handled = 0, hasFreezePower = 0, targetRow = 0, canDamage = 0, targetType = 0, value = 0, hitSolid = 0, isHit = 0, dCols = null, isDamageable = 0, targetCol = 0, s0, t1, t2;
		t1 = new Int32Array(5);
		t1[0] = 0;
		t1[1] = 1;
		t1[2] = -1;
		t1[3] = 0;
		t1[4] = 0;
		dCols = t1;
		t2 = new Int32Array(5);
		t2[0] = 0;
		t2[1] = 0;
		t2[2] = 0;
		t2[3] = 1;
		t2[4] = -1;
		dRows = t2;
		handled = 0;
		hasFreezePower = Game.saveData[9] >= 8 ? 1 : 0;
		hitSolid = 0;
		switch (Game.cellTypes[col][row]) {
			default:
				if ((Game.cellTypes[col][row] - 80 | 0) >= 0 || (Game.cellObjects[col][row] & 255) === 7 && (Game.cellObjects[col][row] >> 8 & 240) === 0) {
					hitSolid = 1;
					s0 = 1;
					handled = s0;
				}
				break;
			case 30:
				handled = 1;
				if (Game.cellStates[col][row] === 0) {
					this.playSound(11);
					Game.cellStates[col][row] = 1;
				}
				break;
			case 18:
				s0 = this.tryPullLever();
				handled = s0;
				break;
			case 16:
				handled = 1;
				hitSolid = 1;
				break;
			case 10:
				if (this.liquidState === 3 && Game.cellStates[col][row] <= 0) {
					handled = 1;
					Game.cellStates[col][row] = 1;
					this.eraseCellInBuffer(col, row);
				}
				break;
			case 9:
				if ((this.explorerStateFlags & 8192) === 0) {
					this.explorerStateFlags = this.explorerStateFlags | 8192;
					handled = 1;
					this.thawFrozenCell(col, row);
				}
				break;
			case 0:
				hitSolid = 1;
				break;
		}
		if (hitSolid !== 0) {
			Game.vibrateDevice(200);
			this.playSound(6);
			this.setExplorerAnim(41 + (this.explorerStateFlags & 7) - 1 | 0);
		}
		if (handled === 0) {
			for (i = 0; i < 5; i++) {
				targetCol = col + dCols[i] | 0;
				targetRow = row + dRows[i] | 0;
				if (targetCol >= 0 && targetCol < this.levelW && targetRow >= 0) {
					if (targetRow < this.levelH) {
						targetType = Game.cellTypes[targetCol][targetRow];
						canDamage = 0;
						isHit = 0;
						switch (targetType) {
							case 19:
							case 43:
							case 45:
							case 46:
							case 49:
								value = Game.cellStates[targetCol][targetRow] & 7;
								s0 = value !== 0 ? Game.cellMoveOffsets[targetCol][targetRow] : 0;
								moveOffset = s0;
								isDamageable = targetType !== 49 && targetType !== 46 ? 1 : 0;
								if (Game.doMovingCellsTouch(col, row, 0, 0, targetCol, targetRow, value, moveOffset)) {
									isHit = 1;
									canDamage = isDamageable;
								}
								if (isHit !== 0) {
									this.playSound(10);
								}
								break;
							case 1:
								if (targetCol === (this.playerCol - Game.dirDeltas[this.explorerStateFlags & 7] | 0) && targetRow === (this.playerRow - Game.dirDeltas[(this.explorerStateFlags & 7) + 8] | 0)) {
									isHit = 1;
								}
								break;
							default:
								break;
						}
						if (hasFreezePower === 0 || isHit === 0 || targetCol === this.playerCol && targetRow === this.playerRow) {
							if (canDamage !== 0) {
								this.explorerStateFlags = this.explorerStateFlags | 8192;
								if (targetType !== 45) {
									this.hitCreature(targetType, targetCol, targetRow);
								} else {
									value = (Game.cellStates[targetCol][targetRow] & 7168) >> 10;
									if (value !== 3) {
										value++;
										Game.cellStates[targetCol][targetRow] = 10 | value << 10;
										Game.cellStates[targetCol][targetRow] = Game.cellStates[targetCol][targetRow] & -249 | 120;
										Game.cellMoveOffsets[targetCol][targetRow] = 0;
									} else {
										Game.cellTypes[targetCol][targetRow] = -1;
										this.killEnemyAt(targetCol, targetRow);
									}
								}
							}
						} else {
							value = this.freezeCell(targetCol, targetRow);
							if (value) {
								this.explorerStateFlags = this.explorerStateFlags | 8192;
							}
						}
					}
				}
			}
		}
	}

	thawFrozenCell(col, row) {
		let facing = 0, s0, s1, s2;
		if (Game.isFreezeRayBlocker(col, row)) {
			return;
		}
		Game.wakeCellsAround(col, row);
		facing = !this.isPlayerAt(col, row - 1 | 0) ? 1 : 2;
		switch ((Game.cellStates[col][row] & 264241152) >> 22) {
			case 39:
				Game.cellTypes[col][row] = 49;
				Game.cellStates[col][row] = facing;
				return;
			case 37:
				if ((Game.cellStates[col][row] & 268435456) === 0) {
					s0 = Game.cellTypes[col];
					s1 = row;
					s2 = 19;
				} else {
					s0 = Game.cellTypes[col];
					s1 = row;
					s2 = 43;
				}
				s0[s1] = s2;
				Game.cellStates[col][row] = facing;
				this.hitCreature(19, col, row);
				return;
			case 36:
				Game.cellTypes[col][row] = 46;
				Game.cellStates[col][row] = 0;
				Game.cellMoveOffsets[col][row] = 0;
				return;
			default:
				return;
			case 35:
				Game.cellTypes[col][row] = 45;
				Game.cellStates[col][row] = Game.cellStates[col][row] & -16 | 10;
				return;
			case 34:
				Game.cellTypes[col][row] = 1;
				this.redrawCellInBuffer(col, row);
				return;
		}
	}

	tryPullLever() {
		let layerObj = 0, s1;
		if (this.liquidState !== 3) {
			return 0;
		}
		layerObj = Game.cellObjects[this.playerCol][this.playerRow] & 255;
		if (this.leverMoveDir === 0 && layerObj !== 15 && layerObj !== 16) {
			this.playSound(0);
			if (this.switchWallsPhase > 0) {
				s1 = -1;
			} else {
				s1 = 1;
			}
			this.leverMoveDir = s1;
		}
		return 1;
	}

	hitCreature(type, col, row) {
		let state = 0;
		state = Game.cellStates[col][row];
		if (type === 43 && (state & 248) === 0) {
			if ((state & 98304) === 0) {
				Game.cellTypes[col][row] = -1;
				this.killEnemyAt(col, row);
				return;
			}
			state = state - 32768 | 0;
			state = state & -16646145 | col << 17;
			state = state & -2130706433 | row << 24;
			state = (state & 7) === 1 || (state & 7) === 3 ? state | -2147483648 : state & 2147483647;
		}
		state = state & -249 | 120;
		Game.cellStates[col][row] = state;
	}

	tickExpiringLayerObject() {
		let age = 0, s0, s1, s2;
		age = Game.cellObjects[this.updateCellCol][this.updateCellRow] >> 8;
		age++;
		if (age < 16) {
			Game.cellUpdateTimers[this.updateCellCol][this.updateCellRow] = 24;
			s0 = Game.cellObjects[this.updateCellCol];
			s1 = this.updateCellRow;
			s2 = age << 8 | 36;
		} else {
			s0 = Game.cellObjects[this.updateCellCol];
			s1 = this.updateCellRow;
			s2 = -1;
		}
		s0[s1] = s2;
	}

	crushCellContents(col, row) {
		let rayIndex = 0, otherRow = 0;
		switch (Game.cellTypes[col][row]) {
			default:
				Game.cellObjects[col][row] = -1;
				return;
			case 48:
				Game.cellObjects[col][row] = -1;
				this.killEnemyAt(col, row);
				otherRow = row + 1 | 0;
				if (Game.cellTypes[col][otherRow] !== 48) {
					otherRow = -1;
				}
				Game.cellTypes[col][otherRow] = -1;
				this.killEnemyAt(col, otherRow);
				rayIndex = (Game.cellStates[col][row] >> 24) * 3 | 0;
				Game.freezeRays[rayIndex + 2] = -1;
				return;
			case 0:
				this.playSound(11);
				Game.cellObjects[col][row] = -1;
				this.killEnemyAt(col, row);
				return;
			case 19:
			case 43:
			case 45:
			case 46:
				Game.cellObjects[col][row] = -1;
				this.killEnemyAt(col, row);
				return;
		}
	}

	updatePlaying() {
		let layerObj = 0, row = 0, switched = 0, col = 0, cellType = 0, value = 0, moved = 0, inBounds = 0, s0, s1, s2, t1, t2, t3, t4;
		if (this.isHoldingBoulder) {
			this.boulderHoldTimer = this.boulderHoldTimer - 1 | 0;
		}
		if ((this.gotElementalDiamond || this.bossTreasureTaken) && Game.frameCount > 140) {
			if (this.bossTreasureTaken) {
				this.bankStageDiamonds();
			}
			this.gotElementalDiamond = 0;
			this.bossTreasureTaken = 0;
			this.needFreeCutscenes = 1;
			this.loadingStep = 0;
			this.resetCounters();
			this.needSaveStageResult = 1;
			Game.screen = 28;
		}
		inBounds = this.isPlayerInsideBorder();
		if (this.liquidStartNextEmitter) {
			this.liquidStartNextEmitter = 0;
			if (this.liquidNextEmitter >= this.liquidEmitterCount) {
				this.liquidNextEmitter = 0;
				this.liquidEmitterCount = 0;
			} else {
				moved = Game.getEmitterBits(this.liquidNextEmitter << 24 >> 24, 13, 7);
				value = Game.getEmitterBits(this.liquidNextEmitter << 24 >> 24, 20, 7);
				this.openLiquidEmitter(moved, value);
				this.liquidNextEmitter = this.liquidNextEmitter + 1 | 0;
			}
		}
		if (Game.actors[4] !== null) {
			Game.actors[4].advanceFrame();
		}
		if (this.shakeTime > 0) {
			this.shakeTime = this.shakeTime - 1 | 0;
		}
		if (this.hintTimer > 0) {
			this.hintTimer = this.hintTimer - 1 | 0;
			if (this.hintTimer === 0) {
				this.hintText = null;
			}
		}
		if (this.effectQueueHead !== this.effectQueueTail) {
			s0 = this.effectQueueHead;
			while (true) {
				moved = s0;
				if (moved === this.effectQueueTail) {
					break;
				}
				t1 = Game.effectFrames;
				t1[moved] = t1[moved] + 1 << 24 >> 24;
				value = Game.effectAnims[moved] >= 0 ? Game.spritePacks[9].getAnimFrameCount(Game.effectAnims[moved]) : Game.getAnimDuration(Game.spritePacks[2], 0);
				if (Game.effectFrames[moved] >= value) {
					this.effectQueueHead = this.effectQueueHead + 1 | 0;
					this.effectQueueHead = this.effectQueueHead & 7;
				}
				s0 = moved + 1 & 7;
			}
		}
		if (this.specialStageType !== 0) {
			this.updateSpecialStage();
			if (Game.screen !== 1) {
				return;
			}
		}
		if ((Game.frameCount & 15) === 0) {
			this.updateCompassDirection();
		}
		if (this.leverMoveDir !== 0 && (Game.frameCount >> 1 & 1) === 0) {
			this.switchWallsPhase = this.switchWallsPhase + this.leverMoveDir | 0;
			if (this.switchWallsPhase === 0 || this.switchWallsPhase === 9) {
				this.leverMoveDir = 0;
				for (moved = 1; moved < (this.levelH - 1 | 0); moved++) {
					for (value = 1; value < (this.levelW - 1 | 0); value++) {
						row = Game.cellObjects[value][moved] & 255;
						col = Game.cellTypes[value][moved];
						if (row === 15 || row === 16 || col === 34 || col === 35) {
							this.redrawCellInBuffer(value, moved);
						}
					}
				}
			} else {
				if (this.switchWallsPhase === 5) {
					moved = this.levelH - 1 | 0;
					value = this.levelW - 1 | 0;
					for (row = 1; row < moved; row++) {
						for (col = 1; col < value; col++) {
							layerObj = Game.cellObjects[col][row] & 255;
							cellType = Game.cellTypes[col][row];
							switched = 0;
							if (layerObj !== 15) {
								if (layerObj !== 16) {
									if (cellType !== 34) {
										if (cellType === 35) {
											s0 = Game.cellObjects[col];
											s1 = row;
											s2 = 16;
											s0[s1] = s2;
											Game.cellTypes[col][row] = -1;
											this.checkLiquidBreachAt(col, row);
											switched = 1;
										}
									} else {
										s0 = Game.cellObjects[col];
										s1 = row;
										s2 = 15;
										s0[s1] = s2;
										Game.cellTypes[col][row] = -1;
										this.checkLiquidBreachAt(col, row);
										switched = 1;
									}
								} else {
									this.crushCellContents(col, row);
									Game.cellTypes[col][row] = 35;
									switched = 1;
								}
							} else {
								this.crushCellContents(col, row);
								Game.cellTypes[col][row] = 34;
								switched = 1;
							}
							if (switched !== 0) {
								Game.wakeCellsAround(col, row);
							}
						}
					}
				}
			}
		}
		this.invulnTimer = BigInt.asIntN(64, this.invulnTimer - 1n);
		if (this.deathTimer > 0) {
			t2 = this.deathTimer - 1 | 0;
			this.deathTimer = t2;
			if (t2 === 0) {
				this.loseLife();
			}
		}
		if (this.playerStep <= 0 && this.checkpointSavePending) {
			this.checkpointSavePending = 0;
			this.playSound(9);
			try {
				Thread.sleep(100n);
			} catch (ex) {
				ex = J.exc(ex);
				if (J.isa(ex, "java/lang/InterruptedException")) {
					s0 = ex;
				}
				else throw ex;
			}
			this.saveCheckpoint();
		}
		if (Game.spritePacks[11] !== null) {
			this.updatePistonTraps();
		}
		if (this.slideCellsLeft !== 0 && this.slidingObjCol !== 0) {
			this.updateSlidingObject();
		}
		this.updateCellsNearPlayer();
		if (this.freezeRayCount > 0) {
			this.updateFreezeRays();
		}
		this.updateLiquidSimulation();
		if (this.gateRevealState !== 0) {
			this.updateGateRevealPan();
		}
		if (this.activeCutscene === null) {
			if (this.pendingCutsceneId !== -1) {
				this.startCutscene(this.pendingCutsceneId);
				this.pendingCutsceneId = -1;
				this.requestedMoveDir = 0;
			}
		} else {
			this.playerIdleCountdown = 70;
			if (this.activeCutscene.isStepFinished() && this.activeCutscene.nextStep() === null) {
				this.activeCutscene = null;
			}
			if (this.activeCutscene !== null) {
				this.activeCutscene.updateStep();
			}
		}
		B42: {
			if (this.encasedStruggleCount <= 0) {
				if ((this.currentMoveDir === 0 || this.playerStep <= 0 && this.currentMoveDir !== 5) && !this.isExitingLevel && (this.explorerStateFlags & 112) === 0 && this.heldItemImageSet === -1) {
					this.currentMoveDir = this.requestedMoveDir;
					moved = 0;
					if (this.entryWalkRemaining <= 0) {
						if (inBounds !== 0) {
							Game.wakeCellsAround(this.playerCol, this.playerRow);
						}
					} else {
						this.currentMoveDir = 2;
						this.entryWalkRemaining = this.entryWalkRemaining - 1 | 0;
						if (this.entryWalkRemaining === 0) {
							this.closeDoorAt(this.playerCol - 1 | 0, this.playerRow);
							this.requestedMoveDir = 0;
							Game.keys = 0;
						}
					}
					switch (this.currentMoveDir) {
						case 6:
							s0 = (this.explorerStateFlags & 7) !== 2 ? -1 : 1;
							value = s0;
							if (inBounds !== 0 && Game.cellTypes[this.playerCol + value][this.playerRow] < 0) {
								this.setExplorerAnim(value !== -1 ? 20 : 22);
								Game.cellTypes[this.playerCol + value][this.playerRow] = 32;
								Game.cellMoveOffsets[this.playerCol + value][this.playerRow] = 18;
								Game.cellStates[this.playerCol + value][this.playerRow] = 4 | (value > 0 ? 1 : 0);
								Game.cellUpdateTimers[this.playerCol + value][this.playerRow] = 30;
								this.playerStep = 72;
								this.requestedMoveDir = 0;
							}
							break;
						case 5:
							this.playerStep = 0;
							row = this.explorerStateFlags & 7;
							if (this.isPlayerInsideBorder()) {
								this.setExplorerAnim(13 + row - 1 | 0);
							}
							break;
						case 3:
							this.explorerStateFlags = this.explorerStateFlags & -9;
							if (Game.actors[0].animIndex !== 40 && Game.actors[0].animIndex !== 48) {
								if ((this.explorerStateFlags & 4096) !== 0) {
									this.explorerStateFlags = this.explorerStateFlags & -8 | this.currentMoveDir;
									this.playerStep = 18;
									t4 = this.currentMoveDir - 1 | 0;
									value = t4;
									if (value < 0) {
										value = 0;
									}
									this.setExplorerAnim(0 + value | 0);
								} else {
									moved = this.tryMoveExplorer(-Game.dirDeltas[this.currentMoveDir] | 0, -Game.dirDeltas[this.currentMoveDir + 8] | 0, 0);
									inBounds = this.isPlayerInsideBorder();
									if (moved !== 0) {
										this.boulderHoldTimer = 40;
										this.isHoldingBoulder = 0;
										t3 = this.currentMoveDir - 1 | 0;
										value = t3;
										if (value < 0) {
											value = 0;
										}
										if ((this.explorerStateFlags & 8) === 0) {
											this.setExplorerAnim(4 + value | 0);
										} else {
											if (this.currentMoveDir !== 2) {
												this.setExplorerAnim(9);
											} else {
												this.setExplorerAnim(8);
											}
										}
									}
								}
							}
							break;
						case 1:
						case 2:
						case 4:
							if (Game.actors[0].animIndex !== 40 && Game.actors[0].animIndex !== 48) {
								if ((this.explorerStateFlags & 4096) !== 0) {
									this.explorerStateFlags = this.explorerStateFlags & -8 | this.currentMoveDir;
									this.playerStep = 18;
									t4 = this.currentMoveDir - 1 | 0;
									value = t4;
									if (value < 0) {
										value = 0;
									}
									this.setExplorerAnim(0 + value | 0);
								} else {
									moved = this.tryMoveExplorer(-Game.dirDeltas[this.currentMoveDir] | 0, -Game.dirDeltas[this.currentMoveDir + 8] | 0, 0);
									inBounds = this.isPlayerInsideBorder();
									if (moved !== 0) {
										this.boulderHoldTimer = 40;
										this.isHoldingBoulder = 0;
										t3 = this.currentMoveDir - 1 | 0;
										value = t3;
										if (value < 0) {
											value = 0;
										}
										if ((this.explorerStateFlags & 8) === 0) {
											this.setExplorerAnim(4 + value | 0);
										} else {
											if (this.currentMoveDir !== 2) {
												this.setExplorerAnim(9);
											} else {
												this.setExplorerAnim(8);
											}
										}
									}
								}
							}
							break;
						case 0:
							this.explorerStateFlags = this.explorerStateFlags & -9;
							col = 0;
							switch (Game.actors[0].animIndex) {
								default:
									if ((this.explorerStateFlags & 16384) === 0) {
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
							if (col !== 0) {
								layerObj = 0 + (this.explorerStateFlags & 7) - 1 | 0;
								if (layerObj < 0) {
									layerObj = 0;
								}
								this.setExplorerAnim(layerObj);
							}
							if (this.activeCutscene !== null) {
								s0 = this;
								s1 = 0;
							} else {
								s0 = this;
								s1 = 6;
							}
							s0.pushDelay = s1;
							if (this.playerStep > 0) {
								this.playerStep = this.playerStep - 6 | 0;
							}
							break;
						default:
							break;
					}
					if (inBounds !== 0) {
						value = Game.cellTypes[this.playerCol][this.playerRow - 1];
						if (moved === 0 && this.currentMoveDir !== 5 && this.playerStep <= 0 && (value === 0 || value === 9 || value === 8 || value === 48) && (Game.cellObjects[this.playerCol][this.playerRow] & 255) !== 35) {
							row = 0;
							if (Game.liquidCells !== null) {
								row = Game.getLiquidBits(Game.liquidCells[this.playerCol][this.playerRow], 0, 3, 4);
							}
							if (!this.hasWaterLayer || row === 0 && row !== 3) {
								if ((this.explorerStateFlags & 8) === 0 && Game.actors[0].animIndex !== 11 && Game.actors[0].animIndex !== 10 && Game.actors[0].animIndex !== 12) {
									this.setExplorerAnim(11);
								}
								this.isHoldingBoulder = 1;
								if (this.boulderHoldTimer <= 0) {
									this.boulderHoldTimer = 40;
									this.invulnTimer = 0n;
									this.damageExplorer(Game.saveData[8], 32, 0);
									return;
								}
							}
						}
					}
					if (moved === 0) {
						if (inBounds !== 0 && (Game.frameCount & 31) === 0) {
							value = Game.cellTypes[this.playerCol][this.playerRow - 1] === 0 ? 1 : 0;
							for (row = 1; value === 0 && row <= 4; row++) {
								value = value | this.tryMoveExplorer(Game.dirDeltas[row], Game.dirDeltas[row + 8], 1);
							}
							if (value === 0) {
								if (!this.stuckWarned) {
									this.stuckWarned = 1;
								} else {
									this.setExplorerAnim(19);
								}
							}
						}
					} else {
						this.stuckWarned = 0;
					}
				} else {
					if (this.isExitingLevel && this.playerStep <= 0) {
						if (!this.usedMainExit) {
							s0 = this;
							s1 = this.altExitWalkDir;
						} else {
							s0 = this;
							s1 = this.exitWalkDir;
						}
						s0.currentMoveDir = s1;
						this.explorerStateFlags = this.explorerStateFlags & -8 | this.currentMoveDir;
						this.playerCol = this.playerCol + -Game.dirDeltas[this.currentMoveDir] | 0;
						this.playerRow = this.playerRow + -Game.dirDeltas[this.currentMoveDir + 8] | 0;
						inBounds = this.isPlayerInsideBorder();
						this.playerStep = 18;
						if (Game.actors[0].animIndex !== 4) {
							this.setExplorerAnim(4 + this.currentMoveDir - 1 | 0);
						}
					}
					if ((this.explorerStateFlags & 112) <= 32 || (this.explorerStateFlags & 2048) !== 0) {
						this.playerStep = this.playerStep - 6 | 0;
						if (this.playerStep <= 0) {
							this.explorerStateFlags = this.explorerStateFlags & -4209;
							s0 = this;
							s1 = 0;
							break B42;
						}
					}
				}
				if (this.gateRevealState === 0) {
					if (!this.respawnPanActive) {
						if (this.activeCutscene !== null) {
							this.camX = this.camTargetX;
							this.camY = this.camTargetY;
						} else {
							if (Game.cameraHoldAfterPan && this.currentMoveDir !== 0) {
								Game.cameraHoldAfterPan = 0;
								this.playerIdleCountdown = 0;
							}
							if (!Game.cameraHoldAfterPan) {
								this.updateCameraFollow();
							}
						}
					} else {
						this.camPanSpeed = 8;
						if (this.stepCameraPan()) {
							this.spawnCellEffect(this.checkpointCol, this.checkpointRow, 5);
							this.respawnPanActive = 0;
						}
					}
				}
				if (this.currentMoveDir !== 0 && inBounds !== 0) {
					this.isExplorerOnGround = Game.cellTypes[this.playerCol][this.playerRow + 1] >= 0 ? 1 : 0;
				}
				this.updateExplorerAnim();
				if (this.isExitingLevel && (this.playerCol < -5 || this.playerCol > (this.levelW + 5 | 0) || this.playerRow < -5 || this.playerRow > (this.levelH + 5 | 0))) {
					this.freeLevelCutscenes();
					if (this.usedMainExit || this.stage >= this.firstSecretStage) {
						this.loadingStep = 0;
						this.loadingStepCount = 12;
						Game.screen = 35;
					} else {
						Game.screen = 20;
						this.loadingStep = 0;
						this.saveRedDiamondPicks();
						this.unlockStagesAfterClear();
						Game.addToSaveCounter(6, this.redDiamondCount);
						this.saveStageResult();
					}
					this.resetCounters();
					this.screenSubState = -1;
				}
				return;
			}
			if (Game.cellTypes[this.playerCol][this.playerRow] < 0) {
				if (Game.cellTypes[this.playerCol][this.playerRow + 1] !== 9 || (Game.cellStates[this.playerCol][this.playerRow + 1] & 7) !== 3) {
					if (Game.cellTypes[this.playerCol - 1][this.playerRow + 1] !== 9 || (Game.cellStates[this.playerCol - 1][this.playerRow + 1] & 7) !== 3) {
						if (Game.cellTypes[this.playerCol + 1][this.playerRow + 1] !== 9 || (Game.cellStates[this.playerCol + 1][this.playerRow + 1] & 7) !== 3) {
							s0 = this;
							s1 = this.explorerStateFlags & -8;
							s2 = 0;
						} else {
							this.playerRow = this.playerRow + 1 | 0;
							this.playerCol = this.playerCol + 1 | 0;
							s0 = this;
							s1 = this.explorerStateFlags & -8;
							s2 = 3;
						}
					} else {
						this.playerRow = this.playerRow + 1 | 0;
						this.playerCol = this.playerCol - 1 | 0;
						s0 = this;
						s1 = this.explorerStateFlags & -8;
						s2 = 3;
					}
				} else {
					this.playerRow = this.playerRow + 1 | 0;
					s0 = this;
					s1 = this.explorerStateFlags & -8;
					s2 = 3;
				}
				s0.explorerStateFlags = s1 | s2;
			}
			s0 = this;
			s1 = Game.cellMoveOffsets[this.playerCol][this.playerRow];
		}
		s0.playerStep = s1;
		if (this.gateRevealState === 0) {
			if (!this.respawnPanActive) {
				if (this.activeCutscene !== null) {
					this.camX = this.camTargetX;
					this.camY = this.camTargetY;
				} else {
					if (Game.cameraHoldAfterPan && this.currentMoveDir !== 0) {
						Game.cameraHoldAfterPan = 0;
						this.playerIdleCountdown = 0;
					}
					if (!Game.cameraHoldAfterPan) {
						this.updateCameraFollow();
					}
				}
			} else {
				this.camPanSpeed = 8;
				if (this.stepCameraPan()) {
					this.spawnCellEffect(this.checkpointCol, this.checkpointRow, 5);
					this.respawnPanActive = 0;
				}
			}
		}
		if (this.currentMoveDir !== 0 && inBounds !== 0) {
			this.isExplorerOnGround = Game.cellTypes[this.playerCol][this.playerRow + 1] >= 0 ? 1 : 0;
		}
		this.updateExplorerAnim();
		B107: {
			if (this.isExitingLevel && (this.playerCol < -5 || this.playerCol > (this.levelW + 5 | 0) || this.playerRow < -5 || this.playerRow > (this.levelH + 5 | 0))) {
				this.freeLevelCutscenes();
				B108: {
					if (this.usedMainExit || this.stage >= this.firstSecretStage) {
						this.loadingStep = 0;
						this.loadingStepCount = 12;
						Game.screen = 35;
						break B108;
					}
					Game.screen = 20;
					this.loadingStep = 0;
					this.saveRedDiamondPicks();
					this.unlockStagesAfterClear();
					Game.addToSaveCounter(6, this.redDiamondCount);
					this.saveStageResult();
					break B108;
				}
				this.resetCounters();
				this.screenSubState = -1;
				break B107;
			}
		}
	}

	extendFreezeRayEnd(col, step, limitCol, row) {
		let nextCol = 0;
		nextCol = col + step | 0;
		if ((col > 0 && limitCol === 0 || col < limitCol && limitCol > 0) && (Game.cellTypes[nextCol][row] < 0 || Game.cellTypes[nextCol][row] === 31 || Game.getFrozenKind(nextCol, row) >= 0)) {
			do {
				col = nextCol;
				nextCol = nextCol + step | 0;
			} while (!((col <= 0 || limitCol !== 0) && (col >= limitCol || limitCol <= 0) || Game.cellTypes[nextCol][row] >= 0 && Game.getFrozenKind(nextCol, row) < 0 && Game.cellTypes[nextCol][row] !== 31));
		}
		return col << 24 >> 24;
	}

	static isFreezeRayBlocker(col, row) {
		let i = 0;
		if (Game.freezeRays !== null) {
			i = 0;
			while (true) {
				if (i >= Game.freezeRays.length) {
					return 0;
				}
				if (Game.freezeRays[i + 2] === row) {
					if ((Game.freezeRays[i + 0] - 1 | 0) === col || (Game.freezeRays[i + 1] + 1 | 0) === col) {
						break;
					}
				}
				i += 3;
			}
			return 1;
		}
		return 0;
	}

	updateFreezeRays() {
		let row = 0, i = 0, maxCol = 0, col = 0, leftCol = 0, rightCol = 0, t2, t3, t4, t5, t6, t7;
		maxCol = this.levelW - 1 | 0;
		for (i = 0; i < Game.freezeRays.length; i += 3) {
			row = Game.freezeRays[i + 2];
			if (row > 0) {
				rightCol = Game.freezeRays[i + 1];
				leftCol = Game.freezeRays[i + 0];
				t2 = Game.freezeRays;
				t3 = i + 0 | 0;
				t4 = this.extendFreezeRayEnd(leftCol, -1, 0, row);
				t2[t3] = t4;
				leftCol = t4;
				t5 = Game.freezeRays;
				t6 = i + 1 | 0;
				t7 = this.extendFreezeRayEnd(rightCol, 1, maxCol, row);
				t5[t6] = t7;
				rightCol = t7;
				for (col = leftCol; col <= rightCol; col++) {
					this.freezeCell(col, row);
				}
			}
		}
	}

	freezeCell(col, row) {
		let actor = null, variantFlag = 0, frozenKind = 0, actorIndex = 0;
		frozenKind = Game.getFrozenKind(col, row);
		variantFlag = 0;
		if (frozenKind >= 0) {
			if (frozenKind === 37 && Game.cellTypes[col][row] === 43) {
				variantFlag = 268435456;
			}
			Game.wakeCellsAround(col, row);
			Game.cellTypes[col][row] = 9;
			Game.cellStates[col][row] = Game.cellStates[col][row] & -264241153 | frozenKind << 22 | variantFlag;
			this.spawnCellEffect(col, row, 1);
		}
		actorIndex = (this.explorerStateFlags & 16384) !== 0 ? 3 : 0;
		actor = Game.actors[actorIndex];
		if (this.isPlayerAt(col, row) && this.encasedStruggleCount <= 0 && actor.animIndex !== 40 && actor.animIndex !== 48) {
			if (actor.animIndex !== 47) {
				this.damageExplorer(0, 16, 0);
			}
		}
		if (frozenKind < 0) {
			return 0;
		}
		return 1;
	}

	static getFrozenKind(col, row) {
		if (Game.cellTypes[col][row] < 0) {
			return -1;
		}
		switch (Game.cellTypes[col][row]) {
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

	drawStageResults() {
		let text = null, slideX = 0, step = 0, animLength = 0, g = null, font = null, value = 0, slideX2 = 0, s0, s1, s2, s3, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;
		let pc = 0;
		for (;;) {
			switch (pc) {
			case 0:
				step = this.screenSubState;
				font = Game.spritePacks[41];
				t1 = this.screenGraphics;
				g = t1;
				g.setColor(2496263);
				g.fillRect(0, 0, 240, 320);
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
				if (this.livesLostInStage !== 0) { pc = 181; continue; }
				pc = 83; continue;
			case 83:
				if ((this.stageMedalsNew & 32) === 0) { pc = 162; continue; }
				pc = 93; continue;
			case 93:
				g.drawImage(Game.objectFrameImages[5][0], 200, 237, 0);
				if (step !== 5) { pc = 162; continue; }
				pc = 116; continue;
			case 116:
				t2 = Game.spritePacks[9];
				text = t2;
				value = text.getAnimFrameCount(0);
				if (Game.frameCount >= (value * 2 | 0)) { pc = 162; continue; }
				pc = 141; continue;
			case 141:
				text.drawAnimFrame(g, 0, Game.frameCount * 2 | 0, 200, 237, 0, 0, 0);
				pc = 162; continue;
			case 162:
				g.drawImage(Game.objectFrameImages[28][0], 180, 254, 0);
				pc = 181; continue;
			case 181:
				if (step !== 4) { pc = 201; continue; }
				pc = 186; continue;
			case 186:
				t3 = -100 + Game.frameCount * 10 | 0;
				slideX = t3;
				if (slideX <= 0) { pc = 204; continue; }
				pc = 201; continue;
			case 201:
				slideX = 0;
				pc = 204; continue;
			case 204:
				Game.actors[0].sprite.drawAnimFrame(g, 12, 0, 7 + slideX | 0, 243, 0, 0, 0);
				font.drawMultilineString(g, Game.langStrings[44], 120, 243, 17);
				text = String(this.livesLostInStage);
				font.drawMultilineString(g, text, 120, 255, 17);
				if (this.hitsTaken !== 0) { pc = 376; continue; }
				pc = 278; continue;
			case 278:
				if ((this.stageMedalsNew & 16) === 0) { pc = 357; continue; }
				pc = 288; continue;
			case 288:
				g.drawImage(Game.objectFrameImages[5][0], 200, 179, 0);
				if (step !== 4) { pc = 357; continue; }
				pc = 311; continue;
			case 311:
				t4 = Game.spritePacks[9];
				value = t4;
				animLength = value.getAnimFrameCount(0);
				if (Game.frameCount >= (animLength * 2 | 0)) { pc = 357; continue; }
				pc = 336; continue;
			case 336:
				value.drawAnimFrame(g, 0, Game.frameCount >> 1, 200, 179, 0, 0, 0);
				pc = 357; continue;
			case 357:
				g.drawImage(Game.objectFrameImages[28][0], 180, 196, 0);
				pc = 376; continue;
			case 376:
				if (step !== 3) { pc = 396; continue; }
				pc = 381; continue;
			case 381:
				t5 = -100 + Game.frameCount * 10 | 0;
				slideX = t5;
				if (slideX <= 0) { pc = 399; continue; }
				pc = 396; continue;
			case 396:
				slideX = 0;
				pc = 399; continue;
			case 399:
				Game.actors[0].sprite.drawAnimFrame(g, 10, 0, 7 + slideX | 0, 189, 0, 0, 0);
				font.drawMultilineString(g, Game.langStrings[43], 120, 185, 17);
				text = String(this.hitsTaken);
				font.drawMultilineString(g, text, 120, 197, 17);
				if (this.redDiamondCount !== this.redDiamondsInStage) { pc = 573; continue; }
				pc = 477; continue;
			case 477:
				if ((this.stageMedalsNew & 8) === 0) { pc = 554; continue; }
				pc = 487; continue;
			case 487:
				g.drawImage(Game.objectFrameImages[5][0], 200, 121, 0);
				if (step !== 3) { pc = 554; continue; }
				pc = 509; continue;
			case 509:
				t6 = Game.spritePacks[9];
				value = t6;
				animLength = value.getAnimFrameCount(0);
				if (Game.frameCount >= (animLength * 2 | 0)) { pc = 554; continue; }
				pc = 534; continue;
			case 534:
				value.drawAnimFrame(g, 0, Game.frameCount >> 1, 200, 121, 0, 0, 0);
				pc = 554; continue;
			case 554:
				g.drawImage(Game.objectFrameImages[28][0], 180, 138, 0);
				pc = 573; continue;
			case 573:
				if (step !== 2) { pc = 593; continue; }
				pc = 578; continue;
			case 578:
				t7 = -100 + Game.frameCount * 10 | 0;
				slideX = t7;
				if (slideX <= 0) { pc = 596; continue; }
				pc = 593; continue;
			case 593:
				slideX = 0;
				pc = 596; continue;
			case 596:
				Game.spritePacks[Game.getSpritePackForImageSet(3)].drawFrame(g, 0, 7 + slideX | 0, 127, 0, 0, 0);
				font.drawMultilineString(g, Game.langStrings[114], 120, 127, 17);
				text = new StringBuffer().append(this.redDiamondCount).append("/").append(this.redDiamondsInStage).toString();
				font.drawMultilineString(g, text, 120, 139, 17);
				if (this.diamondCount !== this.diamondsInStage) { pc = 787; continue; }
				pc = 693; continue;
			case 693:
				if ((this.stageMedalsNew & 4) === 0) { pc = 769; continue; }
				pc = 702; continue;
			case 702:
				g.drawImage(Game.objectFrameImages[5][0], 200, 63, 0);
				if (step !== 2) { pc = 769; continue; }
				pc = 724; continue;
			case 724:
				t8 = Game.spritePacks[9];
				value = t8;
				animLength = value.getAnimFrameCount(0);
				if (Game.frameCount >= animLength >> 1) { pc = 769; continue; }
				pc = 749; continue;
			case 749:
				value.drawAnimFrame(g, 0, Game.frameCount * 2 | 0, 200, 63, 0, 0, 0);
				pc = 769; continue;
			case 769:
				g.drawImage(Game.objectFrameImages[28][0], 180, 80, 0);
				pc = 787; continue;
			case 787:
				if (step !== 1) { pc = 807; continue; }
				pc = 792; continue;
			case 792:
				t9 = -100 + Game.frameCount * 10 | 0;
				slideX = t9;
				if (slideX <= 0) { pc = 810; continue; }
				pc = 807; continue;
			case 807:
				slideX = 0;
				pc = 810; continue;
			case 810:
				Game.spritePacks[Game.getSpritePackForImageSet(2)].drawFrame(g, 0, 7 + slideX | 0, 69, 0, 0, 0);
				font.drawMultilineString(g, Game.langStrings[109], 120, 69, 17);
				if (step !== 1) { pc = 870; continue; }
				pc = 855; continue;
			case 855:
				t10 = Game.frameCount >> 1;
				value = t10;
				if (value <= this.diamondCount) { pc = 876; continue; }
				pc = 870; continue;
			case 870:
				value = this.diamondCount;
				pc = 876; continue;
			case 876:
				text = new StringBuffer().append(value).append("/").append(this.diamondsInStage).toString();
				font.drawMultilineString(g, text, 120, 81, 17);
				pc = 919; continue;
			case 919:
				if (step !== 0) { pc = 957; continue; }
				pc = 923; continue;
			case 923:
				t11 = -100 + Game.frameCount * 10 | 0;
				slideX = t11;
				slideX2 = slideX - 240 | 0;
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
				font.drawString(g, Game.langStrings[Game.stageNameIds[this.world][this.stage]], 120 + slideX | 0, 10, 17);
				font.drawString(g, Game.langStrings[41], 120 + slideX2 | 0, 25, 17);
				pc = 1014; continue;
			case 1014:
				s0 = Game.spritePacks[41];
				s1 = this.screenGraphics;
				s2 = Game.langStrings;
				if (this.screenSubState !== 5) { pc = 1040; continue; }
				pc = 1035; continue;
			case 1035:
				s3 = 98;
				pc = 1042; continue;
			case 1040:
				s3 = 53;
				pc = 1042; continue;
			case 1042:
				s0.drawString(s1, s2[s3], 5, 318, 36);
				return;
			}
		}
	}

	static readU16LE(data, offset) {
		return data[offset] & 255 | (data[offset + 1] & 255) << 8;
	}

	static readS32LE(data, offset) {
		return data[offset] & 255 | (data[offset + 1] & 255) << 8 | (data[offset + 2] & 255) << 16 | (data[offset + 3] & 255) << 24;
	}

	static addToSaveCounter(offset, delta) {
		let value = 0;
		value = Game.readU16LE(Game.saveData, offset);
		value = value + delta | 0;
		if (value < 0) {
			value = 0;
		}
		Game.saveData[offset] = (value & 255) << 24 >> 24;
		Game.saveData[offset + 1] = (value >> 8 & 255) << 24 >> 24;
		return value;
	}

	saveRedDiamondPicks() {
		let i = 0;
		for (i = 0; i < this.redDiamondPickCount; i++) {
			this.markCollectibleTaken(this.world, this.stage, Game.redDiamondPickCells[i << 1] & 255, Game.redDiamondPickCells[(i << 1) + 1] & 255);
		}
	}

	bankStageDiamonds() {
		return Game.addToSaveCounter(4, this.diamondCount);
	}

	bankStageRedDiamonds() {
		return Game.addToSaveCounter(6, this.redDiamondCount);
	}

	runStageCompleteStep(step) {
		let newLevel = 0, oldLevel = 0, s0, t2, t3;
		switch (step) {
			case 11:
				if (this.lives < 99 && this.diamondCount === this.diamondsInStage && (this.stageMedalsBefore & 4) === 0) {
					this.addStageFlags(this.world, this.stage, 4);
					this.stageMedalsNew = (this.stageMedalsNew | 4) << 24 >> 24;
					this.lives = this.lives + 1 | 0;
				}
				if (this.lives < 99 && this.redDiamondCount === this.redDiamondsInStage && (this.stageMedalsBefore & 8) === 0) {
					this.addStageFlags(this.world, this.stage, 8);
					this.stageMedalsNew = (this.stageMedalsNew | 8) << 24 >> 24;
					this.lives = this.lives + 1 | 0;
				}
				if (this.lives < 99 && this.hitsTaken === 0 && (this.stageMedalsBefore & 16) === 0) {
					this.addStageFlags(this.world, this.stage, 16);
					this.stageMedalsNew = (this.stageMedalsNew | 16) << 24 >> 24;
					this.lives = this.lives + 1 | 0;
				}
				if (this.lives < 99 && this.livesLostInStage === 0 && (this.stageMedalsBefore & 32) === 0) {
					this.addStageFlags(this.world, this.stage, 32);
					this.stageMedalsNew = (this.stageMedalsNew | 32) << 24 >> 24;
					this.lives = this.lives + 1 | 0;
				}
				this.unlockNextStage();
				this.saveStageResult();
				this.needSaveStageResult = 0;
				this.needFreeMapRes = 1;
				return;
			case 10:
				this.resetCounters();
				JSystem.gc();
				return;
			case 8:
				oldLevel = (Game.progressFlagsCopy & 224) >> 5;
				for (newLevel = oldLevel; newLevel < 4 && Game.bankedDiamonds >= Tables.upgradeCosts[newLevel]; newLevel++) {
				}
				if (oldLevel < newLevel) {
					t2 = Game.saveData;
					t2[2] = (t2[2] & -225) << 24 >> 24;
					t3 = Game.saveData;
					t3[2] = (t3[2] | newLevel << 5 & 224) << 24 >> 24;
					this.writeSaveRecord();
					this.armorUnlockToAnnounce = newLevel;
				}
				this.saveRedDiamondPicks();
				return;
			case 9:
				this.saveRedDiamondPicks();
				return;
			case 7:
				this.addStageFlags(this.world, this.stage, 2);
				this.armorUnlockToAnnounce = 0;
				return;
			case 6:
				try {
					Game.objectFrameImages[28] = Game.loadSpriteImages("/ui.f", 4);
				} catch (ex) {
					ex = J.exc(ex);
					if (J.isa(ex, "java/lang/Exception")) {
						s0 = ex;
						return;
					}
					else throw ex;
				}
				return;
			case 5:
				Game.progressFlagsCopy = Game.saveData[2];
				this.worldUnlockToAnnounce = 0;
				if ((Game.progressFlagsCopy & 8) !== 0 || Game.bankedRedDiamonds < Tables.worldUnlockRequirements[1]) {
					if ((Game.progressFlagsCopy & 16) !== 0 || Game.bankedRedDiamonds < Tables.worldUnlockRequirements[2]) {
						return;
					}
					this.worldUnlockToAnnounce = 2;
					return;
				}
				this.worldUnlockToAnnounce = 1;
				return;
			default:
				return;
			case 4:
				Game.saveData[6] = (Game.bankedRedDiamonds & 255) << 24 >> 24;
				Game.saveData[7] = (Game.bankedRedDiamonds >> 8 & 255) << 24 >> 24;
				return;
			case 3:
				Game.bankedRedDiamonds = Game.readU16LE(Game.saveData, 6);
				Game.bankedRedDiamonds = Game.bankedRedDiamonds + this.redDiamondCount | 0;
				return;
			case 2:
				Game.saveData[4] = (Game.bankedDiamonds & 255) << 24 >> 24;
				Game.saveData[5] = (Game.bankedDiamonds >> 8 & 255) << 24 >> 24;
				return;
			case 1:
				Game.bankedDiamonds = Game.readU16LE(Game.saveData, 4);
				Game.bankedDiamonds = Game.bankedDiamonds + this.diamondCount | 0;
				this.resultsSkipPressed = 0;
				return;
			case 0:
				Game.bankedDiamonds = 0;
				Game.bankedRedDiamonds = 0;
				Game.progressFlagsCopy = 0;
				this.stageMedalsBefore = this.getStageFlags(this.world, this.stage);
				this.stageMedalsNew = 0;
				return;
		}
	}

	advanceStageResults() {
		switch (this.screenSubState) {
			case 4:
				if (Game.frameCount > 10 || this.resultsSkipPressed) {
					this.screenSubState = this.screenSubState + 1 | 0;
					this.resetCounters();
					this.resultsSkipPressed = 0;
				}
				break;
			case 3:
				if (Game.frameCount > 10 || this.resultsSkipPressed) {
					this.screenSubState = this.screenSubState + 1 | 0;
					this.resetCounters();
					return;
				}
				break;
			case 2:
				if (Game.frameCount > 40 || this.resultsSkipPressed) {
					this.screenSubState = this.screenSubState + 1 | 0;
					this.resetCounters();
					return;
				}
				break;
			case 1:
				if (Game.frameCount > this.diamondCount << 1 && Game.frameCount > 40 || this.resultsSkipPressed) {
					this.screenSubState = this.screenSubState + 1 | 0;
					this.resetCounters();
					return;
				}
				break;
			case 0:
				if (Game.frameCount > 40 || this.resultsSkipPressed) {
					this.screenSubState = this.screenSubState + 1 | 0;
					this.resetCounters();
					return;
				}
				break;
			default:
				break;
		}
	}

	findStageMapNode(stageIndex) {
		let node = 0n, row = 0, col = 0;
		col = 0;
		L1: while (true) {
			if (col >= 12) {
				return (-1n);
			}
			row = 0;
			while (row < 12) {
				node = Game.stageMapNodes[col][row];
				if (node === 0n || Game.extractLongBits(node, 6, 5) !== stageIndex) {
					row++;
					continue;
				}
				break L1;
			}
			col++;
		}
		return node;
	}

	unlockNextStage() {
		let node = 0n;
		node = this.findStageMapNode(this.stage);
		if ((this.stage === 0 || Game.extractLongBits(node, 11, 3) > 1) && node >= 0n && (this.getStageFlags(this.world, this.stage + 1 | 0) & 64) === 0) {
			Game.latestUnlockedStage = this.stage + 1 | 0;
			this.addStageFlags(this.world, Game.latestUnlockedStage, 64);
			this.newStageUnlocked = 1;
			return;
		}
		Game.latestUnlockedStage = this.stage;
	}

	returnToStageMap() {
		this.openStageMap();
	}

	spawnCellEffect(col, row, anim) {
		let cellIndex = 0;
		cellIndex = this.effectQueueTail << 1;
		Game.effectCells[cellIndex] = col << 24 >> 24;
		Game.effectCells[cellIndex + 1] = row << 24 >> 24;
		Game.effectAnims[this.effectQueueTail] = anim << 24 >> 24;
		Game.effectFrames[this.effectQueueTail] = 0;
		this.effectQueueTail = this.effectQueueTail + 1 & 7;
	}

	loseLife() {
		this.lives = this.lives - 1 | 0;
		this.livesLostInStage = this.livesLostInStage + 1 | 0;
		if (this.lives < 0) {
			Game.screen = 12;
			return;
		}
		this.restoreCheckpoint();
		this.explorerEnergy = Game.saveData[8];
		this.requestHudRedraw();
		this.explorerStateFlags = 0;
		this.encasedStruggleCount = 0;
		this.currentMoveDir = 0;
		this.requestedMoveDir = 0;
	}

	unlockDoorLock(doorId) {
		let row = 0, locksLeft = 0, col = 0, param = 0, objType = 0, aboveParam = 0;
		if (doorId >= 0) {
			col = Game.doorCols[doorId];
			row = Game.doorRows[doorId];
			objType = Game.cellObjects[col][row] & 255;
			param = Game.cellObjects[col][row] >> 8;
			if ((param & 240) === 0) {
				if (objType !== 7 || (param & 65280) >> 8 !== doorId) {
					JSystem.out.println("!!!!!!!!!!!!!! door missing");
				}
				locksLeft = param & 15;
				locksLeft--;
				if (locksLeft !== 0) {
					param = param & -16 | locksLeft;
				} else {
					param = param & -241 | 16;
					this.propagateLockFlag(col, row - 1 | 0, 1, 0, 1);
					this.propagateLockFlag(col, row - 1 | 0, -1, 0, 1);
					aboveParam = Game.cellObjects[col][row - 1] >> 8;
					aboveParam = aboveParam | 512;
					Game.cellObjects[col][row - 1] = aboveParam << 8 | Game.cellObjects[col][row - 1] & 255;
					Game.cellUpdateTimers[col][row] = 24;
				}
				Game.cellObjects[col][row] = param << 8 | objType;
				this.playSound(8);
				return;
			}
			return;
		}
	}

	static openDoorAt(col, row) {
		let param = 0;
		param = Game.cellObjects[col][row] >> 8;
		if ((param & 240) === 0) {
			param = param | 16;
			Game.cellObjects[col][row] = param << 8 | 7;
			Game.cellUpdateTimers[col][row] = 24;
		}
	}

	closeDoorAt(col, row) {
		let param = 0;
		param = Game.cellObjects[col][row] >> 8;
		if ((Game.cellObjects[col][row] & 255) === 7) {
			if ((param & 240) !== 0) {
				if (Game.cellTypes[col][row] !== 32) {
					this.playSound(14);
					param = param & -241;
					Game.cellObjects[col][row] = param << 8 | 7;
					this.propagateLockFlag(col, row - 1 | 0, 1, 0, 0);
					this.propagateLockFlag(col, row - 1 | 0, -1, 0, 0);
					if (!this.isPlayerAt(col, row)) {
						switch (Game.cellTypes[col][row]) {
							case 0:
							case 1:
							case 19:
							case 43:
							case 45:
								Game.cellTypes[col][row] = -1;
								this.eraseCellInBuffer(col, row);
								this.killEnemyAt(col, row);
								break;
							default:
								break;
						}
					} else {
						this.invulnTimer = 0n;
						this.slideCellsLeft = 0;
						this.damageExplorer(Game.saveData[8], 48, 0);
						this.playSound(2);
					}
					Game.cellUpdateTimers[col][row] = 24;
					return;
				}
				return;
			}
			return;
		}
	}

	closeDoorById(doorId) {
		if (doorId >= 0) {
			this.closeDoorAt(Game.doorCols[doorId], Game.doorRows[doorId]);
			return;
		}
	}

	updateExplorerAnim() {
		let row = 0, advanceAnim = 0, col = 0, objType = 0, actorIndex = 0, isIdle = 0, actor = null, nextAnim = 0, animEnded = 0, s0, s1, t2, t3;
		actorIndex = (this.explorerStateFlags & 16384) !== 0 ? 3 : 0;
		actor = Game.actors[actorIndex];
		nextAnim = -1;
		advanceAnim = 1;
		isIdle = 0;
		animEnded = actor.isAnimFinished();
		if (animEnded) {
			this.explorerStateFlags = this.explorerStateFlags & -8193;
		}
		if (actorIndex !== 3) {
			switch (actor.animIndex) {
				default:
					s0 = 36;
					t2 = s0 + (this.explorerStateFlags & 7) - 1 | 0;
					s0 = t2;
					nextAnim = s0;
					break;
				case 47:
					this.playerStep = 0;
					this.currentMoveDir = 0;
					this.requestedMoveDir = 0;
					if ((Game.frameCount & 1) === 0) {
						col = this.playerCol - 2 + Game.frameCount % 5 | 0;
						row = this.playerRow - 2 + Game.frameCount % 3 | 0;
						if (col === this.playerCol && (row === this.playerRow || row === (this.playerRow - 1 | 0))) {
							col = col + ((Game.frameCount >> 1 & 1) !== 0 ? -1 : 1) | 0;
						}
						this.spawnCellEffect(col, row, (Game.frameCount * 3 | 0) % 5);
					}
					if (animEnded !== 0) {
						nextAnim = 0 + (this.explorerStateFlags & 7) - 1 | 0;
						this.heldItemAmount = -1;
						this.heldItemFrame = -1;
						this.heldItemImageSet = -1;
					}
					break;
				case 41:
				case 42:
				case 43:
				case 44:
				case 45:
				case 46:
					if (animEnded !== 0) {
						nextAnim = 0 + (this.explorerStateFlags & 7) - 1 | 0;
						this.requestedMoveDir = 0;
						this.currentMoveDir = 0;
						this.playerStep = 0;
						Game.keys = 0;
					}
					break;
				case 40:
				case 48:
					this.playerStep = 0;
					this.currentMoveDir = 0;
					this.requestedMoveDir = 0;
					if (actor.frameTimer === 0) {
						if (actor.frameIndex === (actor.animIndex !== 40 ? 6 : 12)) {
							this.playSound(4);
						}
						if (actor.frameIndex === (actor.animIndex !== 40 ? 6 : 13)) {
							this.finishItemPickup();
						}
					}
					if (actor.isAnimFinished()) {
						this.lastLeverAnimTime = JSystem.currentTimeMillis();
						nextAnim = 0 + (this.explorerStateFlags & 7) - 1 | 0;
						this.heldItemAmount = -1;
						this.heldItemFrame = -1;
						this.heldItemImageSet = -1;
					}
					break;
				case 36:
				case 37:
				case 38:
				case 39:
					B12: {
						if (animEnded !== 0) {
							s0 = 4;
							t2 = s0 + (this.explorerStateFlags & 7) - 1 | 0;
							s0 = t2;
							nextAnim = s0;
							break B12;
						}
					}
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
					B13: {
						if (!this.isExplorerOnGround) {
							s0 = 9;
							nextAnim = s0;
							break B13;
						}
					}
					break;
				case 26:
					B14: {
						if (!this.isExplorerOnGround) {
							s0 = 8;
							nextAnim = s0;
							break B14;
						}
					}
					break;
				case 25:
					B15: {
						if (this.isExplorerOnGround) {
							s0 = 7;
							nextAnim = s0;
							break B15;
						}
					}
					break;
				case 24:
					B16: {
						if (this.isExplorerOnGround) {
							s0 = 5;
							nextAnim = s0;
							break B16;
						}
					}
					break;
				case 20:
				case 21:
				case 22:
				case 23:
				case 30:
				case 31:
				case 32:
				case 33:
					if (animEnded !== 0) {
						advanceAnim = 0;
						Game.keys = 0;
					}
					break;
				case 19:
					if (animEnded !== 0) {
						advanceAnim = 0;
						this.loseLife();
					}
					break;
				case 17:
				case 18:
					if (animEnded === 0) {
						if (actor.frameIndex > 0 && this.heldItemImageSet !== -1) {
							col = (this.explorerStateFlags & 7) !== 2 ? this.playerCol - 1 | 0 : this.playerCol + 1 | 0;
							row = Game.cellObjects[col][this.playerRow] >> 8;
							objType = Game.cellObjects[col][this.playerRow] & 255;
							row = row | 256;
							if (objType !== 9) {
								this.silverKeys = this.silverKeys - 1 | 0;
							} else {
								this.goldKeys = this.goldKeys - 1 | 0;
							}
							Game.cellObjects[col][this.playerRow] = row << 8 | objType;
							this.unlockDoorLock(row & 255);
							this.heldItemAmount = -1;
							this.heldItemImageSet = -1;
						}
					} else {
						nextAnim = 0 + (this.explorerStateFlags & 7) - 1 | 0;
						this.playerStep = 0;
					}
					break;
				case 13:
				case 14:
				case 15:
				case 16:
				case 28:
				case 29:
					B22: {
						if (animEnded !== 0) {
							Game.keys = 0;
							this.currentMoveDir = 0;
							this.playerStep = 0;
							s0 = 0;
							t2 = s0 + (this.explorerStateFlags & 7) - 1 | 0;
							s0 = t2;
							nextAnim = s0;
							break B22;
						}
						if ((this.explorerStateFlags & 8192) === 0 && actor.frameIndex === 2 && actor.frameTimer === 0) {
							col = this.playerCol - Game.dirDeltas[this.explorerStateFlags & 7] | 0;
							row = this.playerRow - Game.dirDeltas[(this.explorerStateFlags & 7) + 8] | 0;
							if (Game.saveData[9] >= 8 && actor.frameIndex === 2 && actor.frameTimer === 0) {
								this.spawnCellEffect(col, row, -1);
							}
							this.strikeCell(col, row);
							this.requestedMoveDir = 0;
							Game.keys = 0;
						}
					}
					break;
				case 12:
					if (this.deathLetterboxHeight < 160) {
						this.deathLetterboxHeight = this.deathLetterboxHeight + 12 | 0;
					}
					break;
				case 11:
					B26: {
						if (Game.cellTypes[this.playerCol][this.playerRow - 1] !== -1) {
							if (animEnded !== 0 && Game.cellTypes[this.playerCol][this.playerRow - 1] !== -1) {
								this.invulnTimer = 0n;
								this.damageExplorer(Game.saveData[8], 32, 0);
							}
						} else {
							s0 = 0;
							t2 = s0 + (this.explorerStateFlags & 7) - 1 | 0;
							s0 = t2;
							nextAnim = s0;
							break B26;
						}
					}
					break;
				case 10:
					B28: {
						if (animEnded === 0) {
							this.invulnTimer = 40n;
						} else {
							this.explorerStateFlags = this.explorerStateFlags & -2049;
							s0 = this.endHurtState();
							nextAnim = s0;
							break B28;
						}
					}
					break;
				case 9:
					B29: {
						if (!this.isExplorerOnGround) {
							s0 = 27;
							nextAnim = s0;
							break B29;
						}
					}
					break;
				case 8:
					B30: {
						if (!this.isExplorerOnGround) {
							s0 = 26;
							nextAnim = s0;
							break B30;
						}
					}
					break;
				case 7:
					B31: {
						if (!this.isExplorerOnGround) {
							s0 = 25;
							nextAnim = s0;
							break B31;
						}
					}
					break;
				case 5:
					B32: {
						if (!this.isExplorerOnGround) {
							s0 = 24;
							nextAnim = s0;
							break B32;
						}
					}
					break;
				case 4:
				case 6:
					B33: {
						if (this.isExplorerOnGround) {
							s0 = actor.animIndex;
							nextAnim = s0;
							break B33;
						}
					}
					break;
				case 2:
					isIdle = 1;
					s0 = 2;
					nextAnim = s0;
					break;
				case 1:
				case 3:
					if (animEnded !== 0) {
						nextAnim = 0 + (this.explorerStateFlags & 7) - 1 | 0;
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
			B35: {
				if (animEnded !== 0) {
					this.explorerStateFlags = this.explorerStateFlags & -18433;
					s0 = this.endHurtState();
					nextAnim = s0;
					break B35;
				}
			}
		}
		if (isIdle === 0) {
			s0 = this;
			s1 = 70;
		} else {
			s0 = this;
			s1 = this.playerIdleCountdown - 1 | 0;
		}
		s0.playerIdleCountdown = s1;
		if (nextAnim !== -1) {
			this.setExplorerAnim(nextAnim);
		}
		if (advanceAnim !== 0) {
			actor.advanceFrame();
		}
		s0 = this;
		if (this.keyHoldTimer <= 0) {
			s1 = 0;
		} else {
			t3 = this.keyHoldTimer - 1 | 0;
			this.keyHoldTimer = t3;
			s1 = t3;
		}
		s0.keyHoldTimer = s1;
	}

	endHurtState() {
		let anim = 0;
		anim = 0;
		if (this.explorerEnergy > 0) {
			anim = 0 + (this.explorerStateFlags & 7) - 1 | 0;
			this.explorerStateFlags = this.explorerStateFlags & -113 | 0;
			this.invulnTimer = 40n;
		} else {
			this.playSound(2);
			anim = 12;
			this.deathTimer = 80;
		}
		this.currentMoveDir = 0;
		return anim;
	}

	static vibrateDevice(durationMs) {
		if (Game.vibrationEnabled) {
			Game.midlet.display.vibrate(durationMs);
		}
	}

	updateSlidingObject() {
		let col = 0, state = 0, dir = 0, otherRow = 0, s0;
		if (this.slidingObjSubStep > 0) {
			this.slidingObjSubStep = this.slidingObjSubStep - 6 << 24 >> 24;
			Game.cellMoveOffsets[this.slidingObjCol][this.slidingObjRow] = this.slidingObjSubStep;
			if ((this.slideCellsLeft === 1 || this.slideCellsLeft === -1) && this.slidingObjSubStep <= 6 && (this.explorerStateFlags & 112) === 0) {
				this.setExplorerAnim((this.explorerStateFlags & 7) !== 4 ? 21 : 23);
			}
			return;
		}
		dir = this.slideCellsLeft <= 0 ? -1 : 1;
		this.slideCellsLeft = this.slideCellsLeft - dir | 0;
		if (this.slideCellsLeft === 0) {
			if (Game.cellTypes[this.slidingObjCol][this.slidingObjRow] !== 48) {
				Game.cellStates[this.slidingObjCol][this.slidingObjRow] = this.slidingObjSavedParams;
			} else {
				state = Game.cellStates[this.slidingObjCol][this.slidingObjRow];
				otherRow = this.slidingObjRow + ((state & 8) !== 0 ? 1 : -1) | 0;
				Game.cellMoveOffsets[this.slidingObjCol][otherRow] = 0;
			}
			Game.cellMoveOffsets[this.slidingObjCol][this.slidingObjRow] = 0;
			this.slidingObjSavedParams = -1;
			this.redrawCellInBuffer(this.slidingObjCol, this.slidingObjRow);
		} else {
			if (Game.cellTypes[this.slidingObjCol][this.slidingObjRow] === 48) {
				state = Game.cellStates[this.slidingObjCol][this.slidingObjRow];
				otherRow = this.slidingObjRow + ((state & 8) !== 0 ? 1 : -1) | 0;
				if (Game.cellTypes[this.slidingObjCol + dir][otherRow] >= 0) {
					s0 = this.playerCol;
					while (true) {
						col = s0 - dir | 0;
						if (Game.cellTypes[col][this.playerRow] !== 32) {
							break;
						}
						Game.cellTypes[col][this.playerRow] = -1;
						s0 = col;
					}
					this.slideCellsLeft = 0;
					return;
				}
				Game.cellTypes[this.slidingObjCol + dir][otherRow] = Game.cellTypes[this.slidingObjCol][otherRow];
				Game.cellTypes[this.slidingObjCol][otherRow] = -1;
				Game.cellStates[this.slidingObjCol + dir][otherRow] = Game.cellStates[this.slidingObjCol][otherRow];
				Game.cellMoveOffsets[this.slidingObjCol][otherRow] = this.slidingObjSubStep;
			}
			Game.cellTypes[this.slidingObjCol + dir][this.slidingObjRow] = Game.cellTypes[this.slidingObjCol][this.slidingObjRow];
			Game.cellTypes[this.slidingObjCol][this.slidingObjRow] = -1;
			this.eraseCellInBuffer(this.slidingObjCol, this.slidingObjRow);
			this.slidingObjCol = this.slidingObjCol + dir | 0;
			Game.cellStates[this.slidingObjCol][this.slidingObjRow] = this.slidingObjParams | -2147483648;
			this.slidingObjSubStep = 18;
			Game.cellMoveOffsets[this.slidingObjCol][this.slidingObjRow] = this.slidingObjSubStep;
		}
		Game.wakeCellsAround(this.slidingObjCol - dir | 0, this.slidingObjRow);
	}

	updatePistonTraps() {
		let phase = 0, s1;
		phase = Game.frameCount % 89;
		if (phase >= 15) {
			if (phase >= 45) {
				if (phase >= 60) {
					s1 = 48 - ((48 * (phase - 60 | 0) | 0) / 30 | 0) | 0;
				} else {
					s1 = 48;
				}
			} else {
				s1 = (48 * (phase - 15 | 0) | 0) / 30 | 0;
			}
		} else {
			s1 = 0;
		}
		this.pistonSlowExtent = s1;
		this.pistonSlowSegments = this.pistonSlowExtent <= 0 ? 1 : ((this.pistonSlowExtent - 1 | 0) / 24 | 0) + 2 | 0;
		phase = Game.frameCount % 44;
		if (phase >= 7) {
			if (phase >= 22) {
				if (phase >= 30) {
					s1 = 48 - ((48 * (phase - 30 | 0) | 0) / 15 | 0) | 0;
				} else {
					s1 = 48;
				}
			} else {
				s1 = (48 * (phase - 7 | 0) | 0) / 15 | 0;
			}
		} else {
			s1 = 0;
		}
		this.pistonFastExtent = s1;
		this.pistonFastSegments = this.pistonFastExtent <= 0 ? 1 : ((this.pistonFastExtent - 1 | 0) / 24 | 0) + 2 | 0;
	}

	updateCompassDirection() {
		let dy = 0, dx = 0, slope = 0, s1;
		dx = Game.compassTargets[this.nextCheckpointIndex << 1] - this.playerCol | 0;
		dy = Game.compassTargets[(this.nextCheckpointIndex << 1) + 1] - this.playerRow | 0;
		if (this.specialStageType === 2 && this.nextCheckpointIndex === 2) {
			dx = 10;
			dy = -8;
		}
		if (dy !== 0) {
			if (dx !== 0) {
				slope = J.idiv(dx * 128 | 0, dy);
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
		this.compassDirection = s1;
	}

	updateSpecialStage() {
		switch (this.specialStageType) {
			case 5:
				this.updateKnightBoss();
				return;
			default:
				return;
			case 4:
				this.updateAnacondaBoss();
				return;
			case 3:
				this.updateYetiBoss();
				return;
			case 2:
				this.updateIntroStageTriggers();
				this.updateIntroStage();
				return;
			case 1:
				this.updateFloodStage();
				return;
		}
	}

	updateIntroStage() {
		if (this.isPlayerAt(61, 3) && this.playerStep === 6) {
			this.spawnCellEffect(this.playerCol, this.playerRow, 5);
			this.isExplorerVisible = 0;
		}
		if (this.activeCutscene === null && (this.isPlayerAt(60, 3) || this.isPlayerAt(61, 3))) {
			this.setHasSavedGameAndSave(1);
			this.needWriteSave = 1;
			this.freeStageMapResources();
			this.cleanup();
			this.world = 0;
			this.stage = 0;
			this.startLevelLoading();
		}
		if (this.pickedItemType === 2) {
			Game.cellObjects[11][50] = -1;
		}
	}

	hurtPlayerNearExplosion(screenX, screenY) {
		let dy = 0, row = 0, col = 0, dx = 0;
		for (dy = -1; dy < 2; dy++) {
			for (dx = -1; dx < 2; dx++) {
				col = ((this.camX + screenX | 0) / 24 | 0) + dx | 0;
				row = ((this.camY + screenY | 0) / 24 | 0) + dy | 0;
				if (this.isPlayerAt(col, row)) {
					this.damageExplorer(1, 48, 0);
				}
			}
		}
	}

	updateKnightBoss() {
		let knightPosX = 0, row = 0, playerX = 0, stepsLeft = 0, knight = null, nextAnim = 0, col = 0, playerY = 0, s0, s1, t1, t2;
		knight = Game.actors[5];
		B1: {
			if (this.bossState !== 12) {
				if (this.bossState !== -1) {
					if (this.bossState !== 15 && this.bossState !== -1) {
						nextAnim = -1;
						playerX = this.playerCol * 24 + 12 | 0;
						playerY = this.playerRow * 24 | 0;
						knightPosX = this.knightX + 24 | 0;
						if (this.bossState === 13) {
							nextAnim = 13;
							if (playerX > knightPosX) {
								this.bossWokenUp = 1;
							}
						}
						if (this.bossHealth > 0) {
							s0 = J.irem(Game.frameCount, this.bossHealth) !== 0 ? 1 : 2;
						} else {
							s0 = 1;
						}
						stepsLeft = s0;
						if (this.bossState === 6 || this.bossState === 7) {
							stepsLeft = (Game.frameCount & 11) !== 0 ? stepsLeft : 2;
						}
						if (!this.bossAttackPending && (this.bossState === 0 || this.bossState === 1)) {
							if (this.bossState !== 0) {
								s0 = this;
								s1 = 36;
							} else {
								this.bossAttackOffset = 36;
								this.bossAttackOffset = this.bossAttackOffset ^ -1;
								s0 = this;
								s1 = this.bossAttackOffset + 1 | 0;
							}
							s0.bossAttackOffset = s1;
							if (playerY < 504 && (playerX === (knightPosX + this.bossAttackOffset | 0) || Game.frameCount % 76 === 0)) {
								this.bossAttackPending = 1;
							}
						}
						while (true) {
							t2 = stepsLeft;
							stepsLeft = stepsLeft - 1 | 0;
							if (t2 <= 0) {
								break;
							}
							switch (this.bossState) {
								case 13:
									if (!knight.isAnimFinished()) {
										if (this.bossWokenUp) {
											knight.advanceFrame();
										}
									} else {
										nextAnim = 0;
										this.bossState = nextAnim;
										this.bossWokenUp = 0;
									}
									break;
								case 10:
								case 11:
									if (playerX <= knightPosX || knightPosX >= 504) {
										if (playerX < knightPosX && knightPosX > 360) {
											s0 = this;
											s1 = 0;
											nextAnim = s1;
											s0.bossState = nextAnim;
										}
									} else {
										s0 = this;
										s1 = 1;
										nextAnim = s1;
										s0.bossState = nextAnim;
									}
									this.bossAttackPending = 0;
									this.bossAttackOffset = 0;
									break;
								case 9:
									if (knight.isAnimFinished()) {
										nextAnim = 11;
										this.bossState = nextAnim;
									}
									if (knight.frameIndex >= 4 && playerY >= 504 && playerX >= knightPosX && playerX <= (knightPosX + 48 | 0)) {
										this.damageExplorer(1, 48, 0);
									}
									break;
								case 8:
									if (knight.isAnimFinished()) {
										nextAnim = 10;
										this.bossState = nextAnim;
									}
									if (knight.frameIndex >= 4 && playerY >= 504 && playerX >= (knightPosX - 48 | 0) && playerX <= knightPosX) {
										this.damageExplorer(1, 48, 0);
									}
									break;
								case 7:
									if (playerY < 504) {
										if (knightPosX <= 504) {
											nextAnim = 1;
											this.bossState = nextAnim;
										}
									} else {
										if (playerX > (knightPosX + 48 | 0)) {
											this.knightX = this.knightX + 2 | 0;
										} else {
											nextAnim = 9;
											this.bossState = nextAnim;
										}
									}
									break;
								case 6:
									if (playerY < 504) {
										if (knightPosX >= 360) {
											nextAnim = 0;
											this.bossState = nextAnim;
										}
									} else {
										if (playerX < (knightPosX - 48 | 0)) {
											this.knightX = this.knightX - 2 | 0;
										} else {
											nextAnim = 8;
											this.bossState = nextAnim;
										}
									}
									break;
								case 4:
								case 5:
									if (knight.isAnimFinished()) {
										nextAnim = this.bossState !== 4 ? 1 : 0;
										this.bossState = nextAnim;
									}
									this.bossAttackPending = 0;
									this.bossAttackOffset = 0;
									break;
								case 3:
									if (knight.frameIndex === 5 && knight.frameTimer === 0) {
										this.shakeTime = 30;
									}
									if (knight.isAnimFinished()) {
										nextAnim = 11;
										this.bossState = nextAnim;
										this.bossAttackPending = 0;
										this.bossAttackOffset = 0;
									}
									if (knight.frameIndex >= 7 && playerY < 504 && playerX === (knightPosX + this.bossAttackOffset | 0)) {
										this.damageExplorer(1, 48, 0);
									}
									break;
								case 2:
									if (knight.frameIndex === 5 && knight.frameTimer === 0) {
										this.shakeTime = 30;
									}
									if (knight.isAnimFinished()) {
										nextAnim = 10;
										this.bossState = nextAnim;
										this.bossAttackPending = 0;
										this.bossAttackOffset = 0;
									}
									if (knight.frameIndex >= 7 && playerY < 504 && playerX === (knightPosX + this.bossAttackOffset | 0)) {
										this.damageExplorer(1, 48, 0);
									}
									break;
								case 1:
									if (playerY < 504 || knightPosX >= 504) {
										if (!this.bossAttackPending) {
											if (knightPosX < 504) {
												this.knightX = this.knightX + 1 | 0;
											} else {
												nextAnim = 0;
												this.bossState = nextAnim;
											}
										} else {
											nextAnim = 3;
											this.bossState = nextAnim;
										}
									} else {
										if (playerX >= knightPosX) {
											nextAnim = 7;
											this.bossState = nextAnim;
										} else {
											this.knightX = this.knightX + 1 | 0;
										}
									}
									break;
								case 0:
									if (playerY < 504 || knightPosX <= 360) {
										if (!this.bossAttackPending) {
											if (knightPosX > 360) {
												this.knightX = this.knightX - 1 | 0;
											} else {
												nextAnim = 1;
												this.bossState = nextAnim;
											}
										} else {
											nextAnim = 2;
											this.bossState = nextAnim;
										}
									} else {
										if (playerX >= knightPosX) {
											this.knightX = this.knightX - 1 | 0;
										} else {
											nextAnim = 6;
											this.bossState = nextAnim;
										}
									}
									break;
								default:
									break;
							}
							if (playerY >= 504 && playerX >= (knightPosX - 24 | 0) && playerX <= (knightPosX - 24 | 0)) {
								this.damageExplorer(1, 48, Game.oppositeDir[this.explorerStateFlags & 7]);
							}
						}
						if ((this.bossState === 8 || this.bossState === 9) && knight.frameIndex === 5) {
							this.dropBossShakeRocks();
						}
						if (this.bossState !== 6 && this.bossState !== 7) {
							for (row = 21; row < 23; row++) {
								for (col = (knightPosX / 24 | 0) - 1 | 0; col < ((knightPosX / 24 | 0) - 2 + 4 | 0); col++) {
									if (Game.cellTypes[col][row] === 0) {
										if ((Game.cellStates[col][row] & 7) === 3 && this.bossState !== 13) {
											this.bossHealth = this.bossHealth - 1 | 0;
											switch (this.bossState) {
												case 1:
												case 3:
												case 5:
												case 9:
												case 11:
													s0 = this;
													s1 = 5;
													nextAnim = s1;
													s0.bossState = nextAnim;
													break;
												case 0:
												case 2:
												case 4:
												case 8:
												case 10:
													s0 = this;
													s1 = 4;
													nextAnim = s1;
													s0.bossState = nextAnim;
													break;
												default:
													break;
											}
										}
										Game.cellTypes[col][row] = -1;
										this.eraseCellInBuffer(col, row);
										Game.cellTypes[col][row] = 30;
										Game.cellUpdateTimers[col][row] = 24;
										Game.cellStates[col][row] = 4;
										this.playSound(14);
									}
								}
							}
						}
						if (this.bossHealth <= 0) {
							this.bossState = 12;
							this.bossTimer = 0;
							nextAnim = 12;
						}
						if (nextAnim === -1) {
							s0 = knight;
							break B1;
						}
						knight.setAnimation(nextAnim);
						return;
					}
				} else {
					if ((this.playerCol * 24 | 0) >= 360) {
						this.bossState = 10;
						knight.setAnimation(10);
						return;
					}
				}
				return;
			}
			t1 = this.bossTimer;
			this.bossTimer = t1 + 1 | 0;
			if (t1 <= 100) {
				this.sound.play(7);
			} else {
				this.bossState = 15;
				this.killEnemyAt(11, 11);
			}
			s0 = knight;
		}
		s0.advanceFrame();
	}

	checkAnacondaBodyHit() {
		let frameDy = 0, holeCol = 0, topY = 0, bottomY = 0, anaconda = null, playerY = 0;
		holeCol = this.getAnacondaHoleCol();
		if (this.playerCol === holeCol || this.playerCol === (holeCol + 1 | 0)) {
			anaconda = Game.actors[5];
			topY = anaconda.y - 40 | 0;
			bottomY = anaconda.y + 256 | 0;
			frameDy = (anaconda.sprite.animFirstFrame[anaconda.animIndex] + anaconda.frameIndex | 0) * 5 | 0;
			frameDy = ((anaconda.sprite.animFrames[frameDy + 3] << 0) * 1 | 0) / 1 | 0;
			topY = topY - frameDy | 0;
			bottomY = bottomY - frameDy | 0;
			playerY = Game.actors[0].y;
			if (playerY > topY && playerY < bottomY && !this.anacondaHitPlayer) {
				this.damageExplorer(1, 48, this.playerCol !== holeCol ? 2 : 4);
			}
		}
	}

	static clearAnacondaBlock(col, row) {
		if (col < 0 || row < 0) {
			return;
		}
		Game.cellTypes[col][row] = -1;
		Game.cellTypes[col + 1][row] = -1;
	}

	static placeAnacondaBlock(col, row) {
		if (col < 0 || row < 0) {
			return;
		}
		Game.cellTypes[col][row] = 50;
		Game.cellTypes[col + 1][row] = 50;
	}

	smashBouldersAt(col, row) {
		let y = 0, smashed = 0, x = 0;
		smashed = 0;
		for (x = col; x <= (col + 1 | 0); x++) {
			for (y = row; y >= (row - 1 | 0); y--) {
				if (Game.cellTypes[x][y] === 0) {
					this.crushCellContents(x, y);
					Game.wakeCellsAround(x, y);
					Game.cellTypes[x][y] = -1;
					this.eraseCellInBuffer(x, y);
					smashed = 1;
				}
			}
		}
		return smashed;
	}

	getAnacondaHoleCol() {
		let notFirstHole = 0;
		notFirstHole = this.anacondaHoleIndex > 0 ? 1 : 0;
		return 10 + Math.imul(this.anacondaHoleIndex, 2 + notFirstHole | 0) | 0;
	}

	getAnacondaHeadRow() {
		let headY = 0, frameDy = 0, anaconda = null;
		anaconda = Game.actors[5];
		headY = anaconda.y - 40 | 0;
		frameDy = (anaconda.sprite.animFirstFrame[anaconda.animIndex] + anaconda.frameIndex | 0) * 5 | 0;
		frameDy = ((anaconda.sprite.animFrames[frameDy + 3] << 0) * 1 | 0) / 1 | 0;
		headY = headY - frameDy | 0;
		headY = headY + this.camY | 0;
		return J.idiv(Math.imul(this.levelH, headY), this.levelH * 24 | 0);
	}

	smashBouldersUnderAnaconda() {
		let row = 0, holeCol = 0, col = 0, smashed = 0, headRow = 0;
		holeCol = this.getAnacondaHoleCol();
		headRow = this.getAnacondaHeadRow();
		smashed = 0;
		for (col = holeCol; col <= (holeCol + 1 | 0); col++) {
			for (row = headRow; row <= 10; row++) {
				if (Game.cellTypes[col][row] === 0) {
					this.crushCellContents(col, row);
					Game.wakeCellsAround(col, row);
					Game.cellTypes[col][row] = -1;
					this.eraseCellInBuffer(col, row);
					smashed = 1;
				}
			}
		}
		return smashed;
	}

	pickAnacondaHoleNearPlayer() {
		let relCol = 0, hole = 0;
		relCol = this.playerCol - 10 | 0;
		hole = relCol / 3 | 0;
		if (relCol === (hole * 3 + 2 | 0)) {
			hole = hole + (Game.frameCount % 50 / 25 | 0) | 0;
		}
		return hole;
	}

	updateAnacondaBoss() {
		let frameDy = 0, slamAnim = 0, holeCol = 0, headY = 0, waitFrames = 0, anaconda = null, nextAnim = 0, slamActor = null, headY2 = 0, frameDy2 = 0, s0;
		if (this.bossState === 5) {
			if (!this.bossStepDoneThisFrame) {
				this.bossStepDoneThisFrame = 1;
			} else {
				return;
			}
		}
		anaconda = Game.actors[5];
		this.bossTimer = this.bossTimer + 1 | 0;
		nextAnim = -1;
		slamActor = Game.actors[4];
		slamAnim = -1;
		holeCol = this.getAnacondaHoleCol();
		if (Game.cellTypes[this.bossRockCol1][2] === -1) {
			Game.cellTypes[this.bossRockCol1][2] = 31;
		}
		if (Game.cellTypes[this.bossRockCol2][2] === -1) {
			Game.cellTypes[this.bossRockCol2][2] = 31;
		}
		switch (this.bossState) {
			case 11:
				this.bossTimer = this.bossTimer - 1 | 0;
				this.anacondaAttackTimer = this.anacondaAttackTimer + 1 | 0;
				if (this.anacondaAttackTimer < 12) {
					if (!this.anacondaHitPlayer) {
						this.checkAnacondaSlamHit();
					}
				} else {
					this.anacondaAttackTimer = 0;
					this.bossState = 9;
					nextAnim = 4;
					this.anacondaHitPlayer = 0;
					this.anacondaSlamVisible = 0;
				}
				break;
			case 10:
				this.bossTimer = this.bossTimer - 1 | 0;
				this.checkAnacondaBodyHit();
				this.anacondaAttackTimer = this.anacondaAttackTimer + 1 | 0;
				if (this.anacondaAttackTimer === 28) {
					nextAnim = 7;
				}
				if (this.anacondaAttackTimer >= 50) {
					this.anacondaAttackTimer = 0;
					this.bossState = 11;
					Game.clearAnacondaBlock(this.anacondaBlockCol, this.anacondaBlockRow);
					this.anacondaBlockCol = -1;
					this.anacondaBlockRow = -1;
					nextAnim = 8;
					slamAnim = 2;
					this.anacondaSlamVisible = 1;
				}
				break;
			case 9:
				this.bossTimer = this.bossTimer - 2 | 0;
				this.checkAnacondaBodyHit();
				headY2 = anaconda.y - 40 | 0;
				frameDy2 = (anaconda.sprite.animFirstFrame[anaconda.animIndex] + anaconda.frameIndex | 0) * 5 | 0;
				frameDy2 = ((anaconda.sprite.animFrames[frameDy2 + 3] << 0) * 1 | 0) / 1 | 0;
				headY2 = headY2 - frameDy2 | 0;
				if (headY2 >= (240 - this.camY + 40 | 0)) {
					this.bossState = 6;
					this.bossTimer = 0;
					this.anacondaHoleIndex = this.pickAnacondaHoleNearPlayer();
				}
				break;
			case 7:
				Game.clearAnacondaBlock(this.anacondaBlockCol, this.anacondaBlockRow);
				this.anacondaBlockCol = -1;
				this.anacondaBlockRow = -1;
				if (this.bossTimer > 80) {
					this.bossState = 8;
					this.progressGateObjective();
				}
				if ((this.bossTimer & 111) === 1) {
					this.playSound(7);
				}
				break;
			case 6:
				if (this.bossTimer > 10) {
					this.bossState = 1;
					nextAnim = 2;
					this.bossTimer = 0;
				}
				break;
			case 5:
				headY = anaconda.y - 40 | 0;
				frameDy = (anaconda.sprite.animFirstFrame[anaconda.animIndex] + anaconda.frameIndex | 0) * 5 | 0;
				frameDy = ((anaconda.sprite.animFrames[frameDy + 3] << 0) * 1 | 0) / 1 | 0;
				headY = headY - frameDy | 0;
				if (headY <= (72 - this.camY + 40 | 0)) {
					this.anacondaRiseOffset = 0;
					this.dropBossShakeRocks();
					this.bossState = 10;
					this.anacondaBlockCol = holeCol;
					this.anacondaBlockRow = 4;
					Game.placeAnacondaBlock(this.anacondaBlockCol, this.anacondaBlockRow);
				}
				this.smashBouldersUnderAnaconda();
				this.checkAnacondaBodyHit();
				break;
			case 4:
				waitFrames = this.bossHealth > 1 ? 10 : 5;
				B15: {
					if (this.bossTimer < waitFrames) {
						if (this.bossTimer > waitFrames >> 1 && anaconda.animIndex !== 1) {
							s0 = 1;
							nextAnim = s0;
						}
					} else {
						this.bossState = 5;
						this.bossTimer = 0;
						s0 = 4;
						nextAnim = s0;
						break B15;
					}
				}
				this.smashBouldersUnderAnaconda();
				this.checkAnacondaBodyHit();
				break;
			case 3:
				waitFrames = 0;
				if (this.bossTimer > 40) {
					if (this.bossHealth <= 0) {
						this.bossState = 7;
						this.bossTimer = 0;
					} else {
						if (this.anacondaStateWhenHit !== 10) {
							if (this.anacondaStateWhenHit === 2 || this.anacondaStateWhenHit === 1) {
								this.bossState = 4;
								this.bossTimer = 0;
								nextAnim = 2;
							}
						} else {
							this.bossState = 9;
							this.bossTimer = 0;
						}
					}
				}
				break;
			case 2:
				waitFrames = 0;
				if (this.smashBouldersAt(holeCol, 8)) {
					this.bossHealth = this.bossHealth - 1 | 0;
					this.anacondaStateWhenHit = this.bossState;
					Game.clearAnacondaBlock(this.anacondaBlockCol, this.anacondaBlockRow);
					this.anacondaBlockCol = -1;
					this.anacondaBlockRow = -1;
					this.anacondaStateWhenHit = this.bossState;
					this.bossState = 3;
					nextAnim = 3;
					this.playSound(10);
				}
				if (this.bossTimer > 15 && anaconda.animIndex !== 6) {
					nextAnim = 6;
				}
				if (this.bossTimer > 30) {
					this.bossState = 4;
					this.bossTimer = 0;
					nextAnim = 0;
					Game.clearAnacondaBlock(this.anacondaBlockCol, this.anacondaBlockRow);
					this.anacondaBlockCol = -1;
					this.anacondaBlockRow = -1;
				}
				break;
			case 1:
				waitFrames = 0;
				if (this.bossTimer <= 40) {
					if (this.bossTimer > 20) {
						this.smashBouldersAt(holeCol, 8);
						Game.placeAnacondaBlock(holeCol, 8);
						this.anacondaBlockCol = holeCol;
						this.anacondaBlockRow = 8;
					}
				} else {
					this.bossState = 2;
					this.bossTimer = 0;
				}
				break;
			case 0:
				if (this.playerCol >= 10) {
					this.bossState = 6;
					this.bossTimer = 0;
				}
				break;
			default:
				break;
		}
		if (nextAnim !== -1) {
			anaconda.setAnimation(nextAnim);
		} else {
			anaconda.advanceFrame();
		}
		if (this.anacondaSlamVisible) {
			if (slamAnim !== -1) {
				slamActor.setAnimation(slamAnim);
			} else {
				slamActor.advanceFrame();
				return;
			}
		}
	}

	checkAnacondaSlamHit() {
		let holeCol = 0;
		holeCol = this.getAnacondaHoleCol();
		if (this.playerRow === 4 && this.playerCol >= (holeCol - 3 | 0) && this.playerCol <= (holeCol + 4 | 0)) {
			this.damageExplorer(1, 64, this.playerCol !== holeCol ? 2 : 4);
			this.anacondaHitPlayer = 1;
		}
	}

	dropBossShakeRocks() {
		this.shakeTime = 30;
		if (Game.cellTypes[this.bossRockCol1][this.bossRockCheckRow] === -1) {
			Game.cellTypes[this.bossRockCol1][this.bossRockSpawnRow] = 0;
			Game.wakeCellsAround(this.bossRockCol1, this.bossRockSpawnRow);
		}
		if (Game.cellTypes[this.bossRockCol2][this.bossRockCheckRow] === -1) {
			Game.cellTypes[this.bossRockCol2][this.bossRockSpawnRow] = 0;
			Game.wakeCellsAround(this.bossRockCol2, this.bossRockSpawnRow);
		}
	}

	resetBoss() {
		this.bossState = -1;
		this.bossHealth = 5;
	}

	updateYetiBoss() {
		let playerY = 0, viewMaxRow = 0, row = 0, viewMinRow = 0, playerCenterX = 0, savedUpdateRow = 0, yetiActor = null, col = 0, yetiCenterX = 0, nextState = 0, stepsThisFrame = 0, viewMaxCol = 0, savedUpdateCol = 0, stompReachRight = 0, stompReachLeft = 0, viewMinCol = 0, s0, s1, t1, t2;
		yetiActor = Game.actors[5];
		savedUpdateCol = this.updateCellCol;
		savedUpdateRow = this.updateCellRow;
		viewMinCol = this.playerCol - 8 | 0;
		viewMaxCol = this.playerCol + 8 | 0;
		viewMaxRow = this.playerRow + 8 | 0;
		viewMinRow = this.playerRow - 8 | 0;
		for (nextState = 15; nextState <= 22; nextState++) {
			for (playerCenterX = 14; playerCenterX <= 21; playerCenterX++) {
				if (playerCenterX <= viewMinCol || playerCenterX >= viewMaxCol || nextState <= viewMaxRow || nextState >= viewMinRow) {
					if (Game.cellTypes[playerCenterX][nextState] === 44) {
						this.updateCellCol = playerCenterX;
						this.updateCellRow = nextState;
						this.updateStalactite();
					}
				}
			}
		}
		this.updateCellCol = savedUpdateCol;
		this.updateCellRow = savedUpdateRow;
		if (this.explorerEnergy === 0) {
			this.resetBoss();
		}
		B6: {
			if (this.bossState !== 12) {
				if (this.bossState !== -1) {
					if (this.bossState !== 15 && this.bossState !== -1) {
						nextState = -1;
						playerCenterX = this.playerCol * 24 + 12 | 0;
						playerY = this.playerRow * 24 | 0;
						yetiCenterX = this.yetiX + 24 | 0;
						if (this.bossQuakeFrame === 0n && this.explorerEnergy !== 0) {
							this.bossQuakeFrame = BigInt(Game.frameCount + Rnd.nextInRange(340, 441) | 0);
						}
						if (this.bossHealth > 0) {
							s0 = J.irem(Game.frameCount, this.bossHealth) !== 0 ? 1 : 2;
						} else {
							s0 = 1;
						}
						stepsThisFrame = s0;
						if (this.bossState === 10 || this.bossState === 11) {
							stepsThisFrame = (Game.frameCount & 11) !== 0 ? stepsThisFrame : 2;
						}
						while (true) {
							t2 = stepsThisFrame;
							stepsThisFrame = stepsThisFrame - 1 | 0;
							if (t2 <= 0) {
								break;
							}
							switch (this.bossState) {
								case 11:
									if (!yetiActor.isAnimFinished()) {
										this.yetiX = this.yetiX + 2 | 0;
									} else {
										this.shakeTime = 10;
										yetiCenterX = this.yetiX + 24 | 0;
										if (BigInt(Game.frameCount) <= this.bossQuakeFrame) {
											if (playerY < 504) {
												nextState = 5;
												this.bossState = nextState;
											} else {
												if (playerCenterX <= (yetiCenterX + 48 | 0)) {
													nextState = 7;
													this.bossState = nextState;
												}
											}
										} else {
											nextState = 14;
											this.bossState = nextState;
										}
									}
									break;
								case 10:
									if (!yetiActor.isAnimFinished()) {
										this.yetiX = this.yetiX - 2 | 0;
									} else {
										this.shakeTime = 10;
										yetiCenterX = this.yetiX + 24 | 0;
										if (BigInt(Game.frameCount) <= this.bossQuakeFrame) {
											if (playerY < 504) {
												nextState = 4;
												this.bossState = nextState;
											} else {
												if (playerCenterX >= (yetiCenterX - 48 | 0)) {
													nextState = 6;
													this.bossState = nextState;
												}
											}
										} else {
											nextState = 13;
											this.bossState = nextState;
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
									switch (this.bossState) {
										case 7:
										case 14:
											col = 5;
											stompReachLeft = 1;
											s0 = 2;
											stompReachRight = s0;
											break;
										case 6:
										case 13:
											col = 4;
											stompReachLeft = 2;
											s0 = 1;
											stompReachRight = s0;
											break;
										default:
											break;
									}
									if (yetiActor.frameIndex === 5 && yetiActor.frameTimer === 0) {
										if (this.bossState === 13 || this.bossState === 14) {
											s0 = this;
											s1 = 80;
										} else {
											s0 = this;
											s1 = 10;
										}
										s0.shakeTime = s1;
									}
									if (yetiActor.isAnimFinished()) {
										if (this.bossState === 13 || this.bossState === 14) {
											this.ceilingCollapseFrame = BigInt(Game.frameCount + 40 | 0);
											this.bossQuakeFrame = BigInt(Game.frameCount + Rnd.nextInRange(340, 441) | 0);
										}
										nextState = col;
										this.bossState = nextState;
									}
									if (yetiActor.frameIndex >= 5 && playerY >= 504 && playerCenterX >= (yetiCenterX - stompReachLeft * 24 | 0) && playerCenterX <= (yetiCenterX + stompReachRight * 24 | 0)) {
										this.damageExplorer(1, 48, 4);
									}
									break;
								case 5:
									if (BigInt(Game.frameCount) <= this.bossQuakeFrame) {
										if (playerY >= 504 && playerCenterX > yetiCenterX && (this.yetiX + 48 | 0) <= 504) {
											nextState = 11;
											this.bossState = nextState;
										}
										if (yetiCenterX >= 504) {
											nextState = 4;
											this.bossState = nextState;
										}
										if (this.bossState === 5) {
											this.yetiX = this.yetiX + 1 | 0;
										}
									} else {
										nextState = 14;
										this.bossState = nextState;
									}
									break;
								case 4:
									if (BigInt(Game.frameCount) <= this.bossQuakeFrame) {
										if (playerY >= 504 && playerCenterX < yetiCenterX && (this.yetiX - 48 | 0) >= 360) {
											nextState = 10;
											this.bossState = nextState;
										}
										if (yetiCenterX <= 360) {
											nextState = 5;
											this.bossState = nextState;
										}
										if (this.bossState === 4) {
											this.yetiX = this.yetiX - 1 | 0;
										}
									} else {
										nextState = 13;
										this.bossState = nextState;
									}
									break;
								case 3:
									if (yetiActor.isAnimFinished()) {
										if (BigInt(Game.frameCount) <= this.bossQuakeFrame) {
											nextState = 5;
											this.bossState = nextState;
										} else {
											nextState = 14;
											this.bossState = nextState;
										}
									}
									break;
								case 2:
									if (yetiActor.isAnimFinished()) {
										if (BigInt(Game.frameCount) <= this.bossQuakeFrame) {
											nextState = 4;
											this.bossState = nextState;
										} else {
											nextState = 13;
											this.bossState = nextState;
										}
									}
									break;
								case 1:
									if (yetiCenterX >= 504) {
										nextState = 4;
										this.bossState = nextState;
									} else {
										nextState = 5;
										this.bossState = nextState;
									}
									break;
								case 0:
									if (yetiCenterX <= 360) {
										nextState = 5;
										this.bossState = nextState;
									} else {
										nextState = 4;
										this.bossState = nextState;
									}
									break;
								default:
									break;
							}
							if (playerY >= 504 && playerCenterX >= (yetiCenterX - 24 | 0) && playerCenterX <= (yetiCenterX + 24 | 0)) {
								this.damageExplorer(1, 48, Game.oppositeDir[this.explorerStateFlags & 7]);
							}
							if (this.bossHealth > 0) {
								continue;
							}
							this.bossState = 12;
							this.bossTimer = 0;
							return;
						}
						if (this.switchWallsPhase === 5) {
							if (this.leverMoveDir > 0) {
								Game.cellTypes[10][19] = 45;
								Game.cellUpdateTimers[10][19] = 24;
								Game.cellMoveOffsets[10][19] = 0;
								Game.cellStates[10][19] = 0;
								if (this.bossHealth <= 2) {
									Game.cellTypes[26][16] = 45;
									Game.cellUpdateTimers[26][16] = 24;
									Game.cellMoveOffsets[26][16] = 0;
									s0 = Game.cellStates[26];
									s1 = 16;
									s0[s1] = 0;
								}
							} else {
								if (this.bossHealth <= 2) {
									Game.cellTypes[10][16] = 45;
									Game.cellUpdateTimers[10][16] = 24;
									Game.cellMoveOffsets[10][16] = 0;
									Game.cellStates[10][16] = 0;
								}
								Game.cellTypes[26][19] = 45;
								Game.cellUpdateTimers[26][19] = 24;
								Game.cellMoveOffsets[26][19] = 0;
								s0 = Game.cellStates[26];
								s1 = 19;
								s0[s1] = 0;
							}
						}
						if (this.bossState !== 10 && this.bossState !== 11) {
							for (row = 21; row < 23; row++) {
								for (col = (yetiCenterX / 24 | 0) - 1 | 0; col < ((yetiCenterX / 24 | 0) - 2 + 4 | 0); col++) {
									if (Game.cellTypes[col][row] === 9) {
										if ((Game.cellStates[col][row] & 7) === 3) {
											this.bossHealth = this.bossHealth - 1 | 0;
											switch (this.bossState) {
												case 1:
												case 3:
												case 5:
												case 7:
													s0 = this;
													s1 = 3;
													nextState = s1;
													s0.bossState = nextState;
													break;
												case 0:
												case 2:
												case 4:
												case 6:
													s0 = this;
													s1 = 2;
													nextState = s1;
													s0.bossState = nextState;
													break;
												default:
													break;
											}
										}
										Game.cellTypes[col][row] = -1;
										this.eraseCellInBuffer(col, row);
										Game.cellTypes[col][row] = 30;
										Game.cellUpdateTimers[col][row] = 24;
										Game.cellStates[col][row] = 4;
										this.playSound(14);
									}
								}
							}
						}
						if (nextState === -1) {
							s0 = yetiActor;
							break B6;
						}
						yetiActor.setAnimation(nextState);
						return;
					}
				} else {
					if ((this.playerCol * 24 | 0) >= 336) {
						this.bossState = 0;
						yetiActor.setAnimation(0);
						return;
					}
				}
				return;
			}
			t1 = this.bossTimer;
			this.bossTimer = t1 + 1 | 0;
			if (t1 <= 100) {
				this.sound.play(7);
			} else {
				this.bossState = 15;
				this.killEnemyAt(11, 11);
			}
			s0 = yetiActor;
		}
		s0.advanceFrame();
	}

	updateFloodStage() {
		let minFloodHeight = 0, s0, s1;
		if (Game.cellTypes[18][63] === 0 && Game.cellMoveOffsets[18][63] <= 0 && this.floodTriggerStage === 0) {
			this.shakeTime = 120;
			this.floodTriggerStage = this.floodTriggerStage + 1 | 0;
		}
		if (this.floodTriggerStage !== 3) {
			if (Game.actors[2].animIndex !== 0) {
				s0 = Game.actors[2];
				s1 = 0;
				s0.setAnimation(s1);
			}
		} else {
			if (Game.actors[2].animIndex !== 0) {
				if (Game.actors[2].animIndex === 1 && Game.actors[2].isAnimFinished()) {
					Game.actors[2].setAnimation(2);
					if (this.playerRow === (this.levelH - 4 | 0)) {
						this.floodHeight = 817;
					}
				}
			} else {
				s0 = Game.actors[2];
				s1 = 1;
				s0.setAnimation(s1);
			}
		}
		Game.actors[2].advanceFrame();
		if (Game.actors[2].animIndex === 2) {
			Game.actors[1].advanceFrame();
			if (this.shakeTime === 10) {
				this.shakeTime = 60;
			}
			if (Game.actors[1].animIndex !== 0) {
				if (Game.actors[1].isAnimFinished()) {
					Game.actors[1].setAnimation(0);
				}
			} else {
				if ((this.activeCutscene === null || this.floodHeight < 46) && this.floodHeight < 1704) {
					this.floodHeight = this.floodHeight + 1 | 0;
					minFloodHeight = this.levelH * 24 - (this.camY + 320 - 80) | 0;
					if (this.floodHeight < minFloodHeight) {
						this.floodHeight = minFloodHeight;
					}
				}
				if ((this.levelH * 24 - this.floodHeight | 0) <= (this.playerRow * 24 + 18 | 0) && this.playerCol < 17) {
					this.damageExplorer(Game.saveData[8], 64, 1);
					return;
				}
			}
		}
	}

	updateIntroStageTriggers() {
		let triggerId = 0;
		if (Game.cellObjects !== null && this.isPlayerInsideBorder() && (Game.cellObjects[this.playerCol][this.playerRow] & 255) === 0) {
			triggerId = Game.cellObjects[this.playerCol][this.playerRow] >> 8;
			if (triggerId !== 13) {
				if (triggerId === 16) {
					this.introTrigger16Reached = 1;
				}
			} else {
				this.introTrigger13Reached = 1;
			}
		}
		if (!this.introHintSpotReached && this.playerStep <= 0 && this.isPlayerAt(46, 7)) {
			this.introHintIconVisible = 1;
			this.introHintSpotReached = 1;
		}
	}

	updateCameraFollow() {
		let playerPos = 0, maxCamY = 0, maxCamX = 0, moveDir = 0, s1, s2;
		moveDir = (this.explorerStateFlags & 4096) !== 0 ? 0 : this.currentMoveDir;
		playerPos = this.playerCol * 24 + Math.imul(this.playerStep, Game.dirDeltas[moveDir]) | 0;
		maxCamX = 24 * this.levelW - 240 | 0;
		maxCamY = 24 * this.levelH - 240 | 0;
		if (playerPos >= (this.camTargetX + 96 | 0)) {
			if (playerPos > (this.camTargetX + 120 | 0)) {
				this.camTargetX = this.camTargetX - 120 + playerPos >> 1;
				if (this.camTargetX > maxCamX) {
					s1 = maxCamX;
					this.camTargetX = s1;
				}
			}
		} else {
			this.camTargetX = this.camTargetX - 96 + playerPos >> 1;
			if (this.camTargetX < 0) {
				s1 = 0;
				this.camTargetX = s1;
			}
		}
		playerPos = this.playerRow * 24 + Math.imul(this.playerStep, Game.dirDeltas[moveDir + 8]) + 40 | 0;
		if (playerPos < (this.camTargetY + 96 | 0)) {
			this.camTargetY = this.camTargetY - 96 + playerPos >> 1;
			if (this.camTargetY < 0) {
				this.camTargetY = 0;
			}
		}
		if (playerPos > (this.camTargetY + 160 | 0)) {
			this.camTargetY = this.camTargetY - 160 + playerPos >> 1;
			if (this.camTargetY > maxCamY) {
				this.camTargetY = maxCamY;
			}
		}
		this.camX = this.camTargetX;
		this.camY = this.camTargetY;
		B9: {
			if (this.camX < 0) {
				s1 = 0;
				this.camX = s1;
				break B9;
			}
			if (this.camX > maxCamX) {
				s1 = maxCamX;
				this.camX = s1;
			}
		}
		B11: {
			if (this.camY < 0) {
				s1 = this;
				s2 = 0;
				s1.camTargetY = s2;
				this.camY = s2;
				break B11;
			}
			if (this.camY > maxCamY) {
				s1 = this;
				s2 = maxCamY;
				s1.camTargetY = s2;
				this.camY = s2;
			}
		}
	}

	pushObjectSideways(col, row, toRight, cellType) {
		let state = 0, destCol = 0, s0, s1;
		destCol = toRight === 0 ? col - 1 | 0 : col + 1 | 0;
		state = Game.cellStates[col][row];
		Game.cellTypes[destCol][row] = cellType;
		Game.cellTypes[col][row] = -1;
		Game.cellMoveOffsets[destCol][row] = 18;
		if (toRight === 0) {
			state = state & -8 | 4;
			s0 = state & -3073;
			s1 = 2048;
		} else {
			state = state & -8 | 2;
			s0 = state & -3073;
			s1 = 1024;
		}
		state = s0 | s1;
		Game.cellStates[destCol][row] = state & -513 | -2147483648;
		Game.wakeCellsAround(destCol, row);
		this.eraseCellInBuffer(col, row);
	}

	clearConnectedObjects(col, row, objType) {
		if ((Game.cellObjects[col][row] & 255) === objType) {
			Game.cellObjects[col][row] = -1;
			this.clearConnectedObjects(col - 1 | 0, row, objType);
			this.clearConnectedObjects(col + 1 | 0, row, objType);
			this.clearConnectedObjects(col, row - 1 | 0, objType);
			this.clearConnectedObjects(col, row + 1 | 0, objType);
		}
	}

	tryMoveExplorer(dx, dy, testOnly) {
		let newMoveDir = 0, curDeathTimer = 0, objParam = 0, targetCellType = 0, destObjParam = 0, objType = 0, newExiting = 0, destObjType = 0, newCol = 0, pushDestCol = 0, canMove = 0, targetRow = 0, newStep = 0, newPushDelay = 0, blockedByObject = 0, cellBelowTarget = 0, onHintTile = 0, topCellOffset = 0, newRow = 0, bottomCellOffset = 0, newStateFlags = 0, targetCol = 0, pushDestRow = 0, s0, s1;
		blockedByObject = 0;
		newStateFlags = this.explorerStateFlags;
		newCol = this.playerCol;
		newRow = this.playerRow;
		newMoveDir = this.currentMoveDir;
		newExiting = this.isExitingLevel;
		newPushDelay = this.pushDelay;
		newStep = this.playerStep;
		curDeathTimer = this.deathTimer;
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
		targetCol = newCol + dx | 0;
		targetRow = newRow + dy | 0;
		canMove = 0;
		onHintTile = 0;
		if (targetCol < 0 || targetCol >= this.levelW || targetRow < 0 || targetRow >= this.levelH) {
			canMove = 1;
		} else {
			if (Game.liquidCells !== null && Game.liquidCells[targetCol][targetRow] !== 0 && Game.saveData[10] === 0) {
				canMove = 0;
				blockedByObject = 1;
			}
			objType = (Game.cellObjects[targetCol][targetRow] & 255) << 24 >> 24;
			switch (objType) {
				case 28:
					if (testOnly === 0) {
						newExiting = 1;
						this.usedMainExit = 0;
					}
					break;
				case 19:
					if (testOnly === 0) {
						targetCellType = targetCol + 3 | 0;
						for (pushDestCol = targetRow; Game.cellTypes[targetCellType][pushDestCol] !== 39; pushDestCol--) {
						}
						if (!this.hasWaterLayer) {
							this.resetLiquidSimulation();
						}
						this.hasWaterLayer = 1;
						this.liquidStartNextEmitter = 0;
						if (Game.liquidCells === null) {
							Game.liquidCells = J.multiArray(Int32Array, 2, [this.levelW, this.levelH]);
						}
						this.addLiquidEmitter(Game.cellStates[targetCellType][pushDestCol] << 24 >> 24, targetCellType << 24 >> 24, pushDestCol << 24 >> 24, 0);
						this.openLiquidEmitter(targetCellType, pushDestCol);
						targetCellType = targetCol;
						while (true) {
							pushDestCol++;
							if ((Game.cellObjects[targetCellType][pushDestCol] & 255) !== 19) {
								break;
							}
							Game.cellObjects[targetCellType][pushDestCol] = -1;
						}
					}
					break;
				case 7:
					objParam = Game.cellObjects[targetCol][targetRow] >> 8;
					if ((objParam & 240) >> 4 < 2) {
						s0 = 1;
						blockedByObject = s0;
					}
					break;
				case 6:
					break;
				case 5:
					canMove = 1;
					if (testOnly === 0) {
						newExiting = 1;
						this.usedMainExit = 1;
					}
					break;
				case 4:
					if (testOnly === 0) {
						objParam = (Game.cellObjects[targetCol][targetRow] & -256) >> 8;
						if (objParam >= this.nextCheckpointIndex) {
							this.checkpointSavePending = 1;
							this.nextCheckpointIndex = objParam + 1 | 0;
							this.checkpointTextEndFrame = Game.frameCount + 13 | 0;
						}
					}
					break;
				case 3:
					if (Game.cellObjects[targetCol][targetRow] >> 8 >= 3) {
						canMove = 0;
						s0 = 1;
						blockedByObject = s0;
					} else {
						canMove = 1;
					}
					break;
				case 2:
					if (testOnly === 0) {
						onHintTile = 1;
						objParam = Game.cellObjects[targetCol][targetRow] >> 8;
						switch (objParam) {
							case 1:
								if (Game.saveData[9] < 2) {
									s0 = this;
									s1 = 13;
								} else {
									s0 = this;
									s1 = 7;
								}
								s0.hintBubbleImageSet = s1;
								s0 = this;
								s1 = 1;
								s0.hintBubbleFrame = s1;
								break;
							case 0:
								if (Game.saveData[9] < 1) {
									s0 = this;
									s1 = 13;
									s0.hintBubbleImageSet = s1;
									s0 = this;
									s1 = 1;
								} else {
									this.hintBubbleImageSet = 7;
									s0 = this;
									s1 = 0;
								}
								s0.hintBubbleFrame = s1;
								break;
							default:
								break;
						}
					}
					break;
				case 1:
					if (testOnly === 0) {
						this.shakeTime = 120;
						this.floodTriggerStage = this.floodTriggerStage + 1 | 0;
						this.clearConnectedObjects(targetCol, targetRow, 1);
					}
					break;
				default:
					break;
			}
			if (blockedByObject === 0) {
				targetCellType = Game.cellTypes[targetCol][targetRow];
				switch (targetCellType) {
					default:
						dx = 0;
						canMove = 0;
						if (this.currentMoveDir === 4 || this.currentMoveDir === 2) {
							this.setExplorerAnim(0 + this.currentMoveDir - 1 | 0);
						}
						break;
					case 48:
						pushDestCol = newCol + (dx << 1) | 0;
						pushDestRow = newRow + (dy << 1) | 0;
						newPushDelay--;
						if ((Game.cellStates[targetCol][targetRow] & 8) === 0) {
							topCellOffset = -1;
							s0 = 0;
						} else {
							topCellOffset = 0;
							s0 = 1;
						}
						bottomCellOffset = s0;
						if ((newPushDelay < 0 || testOnly !== 0) && dx !== 0 && Game.cellTypes[pushDestCol][pushDestRow + topCellOffset] < 0 && Game.cellTypes[pushDestCol][pushDestRow + bottomCellOffset] < 0 && Game.cellTypes[targetCol][targetRow + bottomCellOffset + 1] >= 0) {
							if (testOnly === 0) {
								Game.cellTypes[pushDestCol][pushDestRow + topCellOffset] = targetCellType;
								Game.cellTypes[pushDestCol][pushDestRow + bottomCellOffset] = targetCellType;
								Game.cellTypes[targetCol][targetRow + topCellOffset] = -1;
								Game.cellTypes[targetCol][targetRow + bottomCellOffset] = -1;
								Game.cellStates[pushDestCol][pushDestRow + topCellOffset] = Game.cellStates[targetCol][targetRow + topCellOffset];
								Game.cellStates[pushDestCol][pushDestRow + bottomCellOffset] = Game.cellStates[targetCol][targetRow + bottomCellOffset] & -16 | (dx <= 0 ? 4 : 2);
								Game.cellMoveOffsets[pushDestCol][pushDestRow + bottomCellOffset] = 18;
								Game.cellUpdateTimers[pushDestCol][pushDestRow + topCellOffset - 1] = 48;
								Game.cellUpdateTimers[pushDestCol][pushDestRow + topCellOffset - 1] = 48;
								Game.cellUpdateTimers[pushDestCol][pushDestRow + topCellOffset - 1] = 48;
								Game.wakeCellsAround(pushDestCol, pushDestRow + bottomCellOffset | 0);
							}
							canMove = 1;
							newStateFlags = newStateFlags | 8;
						} else {
							if (dx !== 0) {
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
						if (this.liquidState === 3) {
							if (testOnly === 0 && Game.cellStates[targetCol][targetRow] <= 0) {
								Game.cellStates[targetCol][targetRow] = 1;
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
						pushDestCol = newCol + (dx << 1) | 0;
						pushDestRow = newRow + (dy << 1) | 0;
						if (this.specialStageType === 4) {
							destObjType = this.getAnacondaHoleCol();
							if (pushDestCol === destObjType || pushDestCol === (destObjType + 1 | 0)) {
								destObjParam = this.getAnacondaHeadRow();
								if (pushDestRow >= destObjParam) {
									newStateFlags = newStateFlags | 8;
									this.setExplorerAnim((newStateFlags & 7) !== 2 ? 9 : 8);
									return 0;
								}
							}
						}
						newPushDelay--;
						destObjType = Game.cellObjects[pushDestCol][pushDestRow] & 255;
						destObjParam = Game.cellObjects[pushDestCol][pushDestRow] >> 8;
						cellBelowTarget = Game.cellTypes[targetCol][newRow + 1];
						if ((newPushDelay < 0 || testOnly !== 0) && dx !== 0 && Game.isCellFreeForObject(pushDestCol, pushDestRow) && (destObjType !== 7 || (destObjParam & 240) !== 0) && (cellBelowTarget !== 19 && cellBelowTarget !== 45 && cellBelowTarget !== 49 && cellBelowTarget !== 43 || (Game.cellObjects[targetCol][newRow + 1] & 255) === 35)) {
							if (testOnly === 0) {
								this.pushObjectSideways(targetCol, targetRow, dx > 0 ? 1 : 0, targetCellType);
							}
							canMove = 1;
							newStateFlags = newStateFlags | 8;
						} else {
							if (dx !== 0) {
								newStateFlags = newStateFlags | 8;
							}
							newMoveDir = 0;
							Game.cellStates[targetCol][targetRow] = Game.cellStates[targetCol][targetRow] & -8 | 0;
						}
						break;
					case -1:
						if (targetCol === 0 || targetRow === 0 || targetCol === (this.levelW - 1 | 0) || targetRow === (this.levelH - 1 | 0)) {
							s0 = 1;
							canMove = s0;
						} else {
							if ((dx === 0 || Game.cellTypes[targetCol][newRow + 1] !== 0 || (Game.cellStates[targetCol][newRow + 1] & 7) !== 3) && (this.pistonSlowExtent < 24 || (Game.cellTypes[targetCol][targetRow - 1] !== 28 || (Game.cellStates[targetCol][targetRow - 1] & 8) !== 0) && (Game.cellTypes[targetCol][targetRow + 1] !== 28 || (Game.cellStates[targetCol][targetRow + 1] & 8) !== 0)) && (this.pistonFastExtent < 24 || Game.cellTypes[targetCol][targetRow - 1] !== 28 && Game.cellTypes[targetCol][targetRow + 1] !== 28)) {
								s0 = 1;
								canMove = s0;
							} else {
								if (testOnly === 0) {
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
		if (testOnly === 0 && canMove !== 0 && onHintTile === 0) {
			this.hintBubbleImageSet = -1;
		}
		if (canMove === 0 || curDeathTimer !== 0) {
			if (dx !== 0 && testOnly === 0) {
				newStateFlags = newStateFlags | 8;
			}
		} else {
			newStep = 18;
			newCol = newCol + dx | 0;
			newRow = newRow + dy | 0;
			if ((newStateFlags & 8) === 0 && testOnly === 0) {
				this.setExplorerAnim(4 + newMoveDir - 1 | 0);
			}
		}
		if ((newStateFlags & 8) !== 0 && testOnly === 0) {
			this.setExplorerAnim((newStateFlags & 7) !== 2 ? 9 : 8);
		}
		if (testOnly === 0) {
			this.explorerStateFlags = newStateFlags;
			this.playerCol = newCol;
			this.playerRow = newRow;
			this.currentMoveDir = newMoveDir;
			this.isExitingLevel = newExiting;
			this.pushDelay = newPushDelay;
			this.playerStep = newStep;
			this.deathTimer = curDeathTimer;
		}
		return canMove;
	}

	static requestQuit() {
		Game.screen = 3;
	}

	openPauseMenu() {
		Game.screen = 2;
		Game.menuFullRedraw = 1;
		this.openMenu(1);
		this.requestHudRedraw();
		if (Game.spritePacks[18] === null) {
			Game.spritePacks[18] = Game.loadSpritePack("/ui.f", 3);
		}
	}

	pauseGame() {
		this.pausedElapsedTime = BigInt.asIntN(64, JSystem.currentTimeMillis() - this.startTime);
		this.paused = 1;
		JSystem.out.println(Sound.isPlaying());
		if ((Game.screen === 30 || Game.screen === 4) && Sound.isPlaying()) {
			this.resumeMenuMusic = 1;
		}
		this.sound.stop();
	}

	showNotify() {
		if (this.paused) {
			this.resumeGame();
		}
	}

	hideNotify() {
		if (!this.paused) {
			this.pauseGame();
		}
	}

	resumeGame() {
		this.paused = 0;
		Game.menuFullRedraw = 1;
		Game.menuRepaintPlayfield = 1;
		this.isKeyReleased = 1;
		Game.keys = 0;
		this.menuConfirmStep = -1;
		if (this.menuId === 7) {
			this.menuCursor = 0;
		}
		this.startTime = BigInt.asIntN(64, JSystem.currentTimeMillis() - this.pausedElapsedTime);
		switch (Game.screen) {
			case 33:
				this.needsFullRedraw = 1;
				return;
			case 31:
				this.newGamePromptDirty = 1;
				return;
			case 27:
				this.needsFullRedraw = 1;
				this.worldMapInfoDirty = 1;
				return;
			case 23:
				return;
			case 21:
				this.openStageMap();
				return;
			case 20:
				return;
			case 19:
				return;
			case 18:
			case 25:
			case 26:
				this.needsFullRedraw = 1;
				return;
			case 17:
				return;
			case 16:
				this.lives = 0;
				this.redDiamondCount = 0;
				this.hasCompass = 0;
				this.loadingTipIndex = 0;
				this.isNewGame = 1;
				return;
			case 15:
				this.needsFullRedraw = 1;
				return;
			case 11:
				this.loadingStep = 6;
				return;
			case 10:
				Game.menuRepaintPlayfield = 0;
				return;
			case 9:
			case 28:
				return;
			case 8:
				return;
			case 7:
				this.menuCursor = 1;
				return;
			case 5:
				this.loadingFullRedraw = 1;
				return;
			case 4:
			case 30:
				if (!this.resumeMenuMusic) {
					return;
				}
				this.sound.play(19);
				return;
			case 2:
				Game.stageMapImage = null;
				this.hudNeedsRedraw = 1;
				if (this.menuId !== 1) {
					return;
				}
				this.menuCursor = 0;
				return;
			default:
				return;
			case 1:
				this.requestHudRedraw();
				if (!Game.itemRaiseFreeze) {
					if (this.activeCutscene === null) {
						if (this.entryWalkRemaining === 0) {
							if (!this.isExitingLevel) {
								if (this.explorerEnergy > 0) {
									if (Game.actors[0].animIndex !== 19) {
										if (!this.respawnPanActive) {
											this.openPauseMenu();
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

	registerLiquidEmitters() {
		let row = 0, col = 0;
		if (this.hasWaterLayer) {
			for (col = 0; col < this.levelW; col++) {
				for (row = 0; row < this.levelH; row++) {
					if (Game.cellTypes[col][row] === 38) {
						this.addLiquidEmitter(Game.cellStates[col][row] << 24 >> 24, col << 24 >> 24, row << 24 >> 24, 0);
						this.liquidEmitterCount = this.liquidEmitterCount + 1 | 0;
					}
				}
			}
			return;
		}
	}

	placeChestOnCell(col, row) {
		let t1, t2;
		this.levelResourceMask = this.levelResourceMask | 4194304n;
		t1 = Game.cellObjects[col];
		t1[row] = t1[row] & -256;
		t2 = Game.cellObjects[col];
		t2[row] = t2[row] | 14;
	}

	isBossStage() {
		if (this.specialStageType === 4 || this.specialStageType === 5 || this.specialStageType === 3) {
			return 1;
		}
		return 0;
	}

	setupLevelCells() {
		let gateTaskCounts = null, gateIdMask = 0, typeOrParam = 0, prevMsgId = 0, gateKey = null, pickupSlotCount = 0, gateObjectiveMsgIds = null, cellParam = 0, count = 0, row = 0, objValue = 0, col = 0, objType = 0, key = 0, taskCount = null, msgId = null, cellType = 0, cutsceneCount = 0, locksPerDoor = null, goalTargetCount = 0, goalIndex = 0, s0, s1, s2, t4, t5, t7, t8, t9;
		locksPerDoor = new Hashtable();
		gateTaskCounts = new Hashtable();
		gateObjectiveMsgIds = new Hashtable();
		this.redDiamondPickCount = 0;
		this.checkpointRedDiamondPickCount = 0;
		pickupSlotCount = 0;
		this.diamondsInStage = 0;
		this.enemyPackFlags = 0;
		goalTargetCount = 0;
		gateIdMask = 0;
		this.levelHasLockType9 = 0;
		this.levelHasLockType8 = 0;
		this.levelHasBlock35 = 0;
		this.freezeRayCount = 0;
		cutsceneCount = 0;
		for (col = 0; col < this.levelW; col++) {
			for (row = 0; row < this.levelH; row++) {
				Game.cellMoveOffsets[col][row] = 0;
				Game.cellUpdateTimers[col][row] = 0;
				objValue = Game.cellObjects[col][row];
				cellParam = Game.cellStates[col][row];
				cellType = Game.cellTypes[col][row];
				if (objValue !== -1) {
					switch (objValue & 255) {
						default:
							if (objValue < 20 || objValue >= 26) {
								if (objValue < 80 && objValue > -1) {
									Game.cellObjects[col][row] = -1;
								}
							} else {
								Game.cellObjects[col][row] = objValue;
								switch (this.world) {
									case 1:
										s0 = this;
										s1 = this.levelResourceMask;
										s2 = 2097152n;
										s0.levelResourceMask = s1 | s2;
										break;
									case 0:
										s0 = this;
										s1 = this.levelResourceMask;
										s2 = 16n;
										s0.levelResourceMask = s1 | s2;
										break;
									default:
										break;
								}
							}
							break;
						case 34:
							this.levelResourceMask = this.levelResourceMask | 17179869184n;
							break;
						case 31:
							this.levelResourceMask = this.levelResourceMask | 1073741824n;
							Game.cellObjects[col][row] = cellParam << 8 | 31;
							Game.cellObjects[col][row] = cellParam << 8 | 19;
							break;
						case 30:
							this.levelResourceMask = this.levelResourceMask | 1073741824n;
							cutsceneCount++;
							Game.cellObjects[col][row] = cellParam << 8 | objValue & 255;
							break;
						case 28:
							this.altExitWalkDir = cellParam << 24 >> 24;
							break;
						case 19:
							Game.cellObjects[col][row] = cellParam << 8 | 19;
							break;
						case 17:
							objType = Game.cellObjects[col][row - 1] & 255;
							if (objType === 14 || objType === 33) {
								Game.cellObjects[col][row - 1] = 65280 | objType;
							}
							typeOrParam = Game.cellTypes[col][row - 1];
							switch (typeOrParam) {
								default:
									Game.cellObjects[col][row] = cellParam << 8 | 17;
									break;
								case 19:
								case 36:
								case 43:
								case 45:
								case 46:
								case 49:
									key = new Integer(cellParam);
									count = gateTaskCounts.get(key);
									count = count !== null ? new Integer(count.intValue() + 1 | 0) : new Integer(1);
									gateTaskCounts.put(key, count);
									Game.cellObjects[col][row] = -1;
									prevMsgId = gateObjectiveMsgIds.get(key);
									if (typeOrParam !== 36) {
										gateObjectiveMsgIds.put(key, new Integer(57));
										if (this.specialStageType !== 4) {
											if (this.specialStageType !== 5) {
												if (this.specialStageType === 3) {
													gateObjectiveMsgIds.put(key, new Integer(95));
												}
											} else {
												gateObjectiveMsgIds.put(key, new Integer(94));
											}
										} else {
											gateObjectiveMsgIds.put(key, new Integer(93));
										}
									} else {
										if (prevMsgId === null) {
											gateObjectiveMsgIds.put(key, new Integer(58));
										}
									}
									break;
							}
							if (cellParam >= 0) {
								gateIdMask = gateIdMask | 1 << cellParam;
							}
							break;
						case 14:
						case 33:
							if (!this.isBossStage()) {
								Game.cellObjects[col][row] = 33;
							}
							this.levelResourceMask = this.levelResourceMask | BigInt.asIntN(64, 1n << BigInt(((Game.cellObjects[col][row] & 255) !== 14 ? 33 : 22) & 63));
							if (this.isCollectibleTaken(this.world, this.stage, col, row)) {
								if (!this.isBossStage()) {
									Game.cellTypes[col][row] = -1;
									t4 = Game.cellObjects[col];
									t4[row] = t4[row] | 256;
								} else {
									Game.cellTypes[col][row] = 41;
									Game.cellStates[col][row] = 10;
									this.diamondsInStage = this.diamondsInStage + 10 | 0;
								}
							}
							break;
						case 8:
							this.levelHasLockType8 = 1;
							if ((objValue & 255) !== 8) {
								this.levelHasLockType9 = 1;
							}
							this.levelResourceMask = this.levelResourceMask | 268435456n;
							key = new Integer(cellParam);
							t5 = locksPerDoor.get(key);
							count = t5;
							count = count !== null ? new Integer(count.intValue() + 1 | 0) : new Integer(1);
							locksPerDoor.put(key, count);
							Game.cellObjects[col][row] = cellParam << 8 | objValue;
							break;
						case 9:
							if ((objValue & 255) !== 8) {
								this.levelHasLockType9 = 1;
							}
							this.levelResourceMask = this.levelResourceMask | 268435456n;
							key = new Integer(cellParam);
							t5 = locksPerDoor.get(key);
							count = t5;
							count = count !== null ? new Integer(count.intValue() + 1 | 0) : new Integer(1);
							locksPerDoor.put(key, count);
							Game.cellObjects[col][row] = cellParam << 8 | objValue;
							break;
						case 7:
							if (cellParam !== -1) {
								Game.doorCols[cellParam] = col << 24 >> 24;
								Game.doorRows[cellParam] = row << 24 >> 24;
							}
							Game.cellObjects[col][row] = cellParam << 8 | objValue;
							break;
						case 6:
							key = new Integer(cellParam);
							count = locksPerDoor.get(key);
							count = count !== null ? new Integer(count.intValue() + 1 | 0) : new Integer(1);
							locksPerDoor.put(key, count);
							this.levelResourceMask = this.levelResourceMask | 536870912n;
							Game.cellObjects[col][row] = cellParam << 8 | 6;
							break;
						case 5:
							this.exitWalkDir = cellParam << 24 >> 24;
							break;
						case 4:
							goalTargetCount++;
							this.levelResourceMask = this.levelResourceMask | 16n;
							Game.cellObjects[col][row] = cellParam << 8 | objValue & 255;
							break;
						case 3:
							Game.cellUpdateTimers[col][row] = 127;
							if (cellParam > 0) {
								Game.cellObjects[col][row] = cellParam + 1 << 8 | 3;
							}
							break;
						case 2:
							this.levelResourceMask = this.levelResourceMask | 1048576n;
							switch (cellParam) {
								case 0:
								case 1:
									this.levelResourceMask = this.levelResourceMask | 524288n;
									break;
								default:
									break;
							}
							Game.cellObjects[col][row] = cellParam << 8 | 2;
							break;
						case 1:
						case 26:
							Game.cellObjects[col][row] = cellParam << 8 | objValue & 255;
							break;
						case 0:
							cutsceneCount++;
							Game.cellObjects[col][row] = cellParam << 8 | objValue & 255;
							break;
					}
				}
				switch (cellType) {
					default:
						if (cellType < 80 && cellType > -1) {
							s0 = Game.cellTypes[col];
							s1 = row;
							s2 = -1;
							s0[s1] = s2;
						}
						break;
					case 79:
						this.playerCol = 0;
						this.playerRow = row;
						this.entryWalkRemaining = col;
						Game.cellTypes[col][row] = -1;
						this.camTargetX = 0;
						this.camX = 0;
						t9 = this.playerRow * 24 - 160 | 0;
						this.camTargetY = t9;
						this.camY = t9;
						break;
					case 53:
						break;
					case 52:
						break;
					case 51:
						break;
					case 49:
						this.levelResourceMask = this.levelResourceMask | 2199023255552n;
						s0 = Game.cellUpdateTimers[col];
						s1 = row;
						s2 = 48;
						s0[s1] = s2;
						break;
					case 48:
						if ((cellParam & 7) !== 4) {
							s0 = Game.cellStates[col];
							s1 = row;
							s2 = 0;
						} else {
							s0 = Game.cellStates[col];
							s1 = row;
							s2 = 16;
						}
						s0[s1] = s2;
						this.freezeRayCount = this.freezeRayCount + 1 | 0;
						this.levelResourceMask = this.levelResourceMask | 1099511627776n;
						this.levelResourceMask = this.levelResourceMask | 4294967296n;
						objType = row - 1 | 0;
						Game.cellTypes[col][objType] = 48;
						Game.cellStates[col][objType] = 8;
						Game.wakeCellsAround(col, objType);
						break;
					case 47:
						Game.cellUpdateTimers[col][row] = 48;
						Game.cellStates[col][row] = 0;
						this.levelResourceMask = this.levelResourceMask | 8388608n;
						break;
					case 46:
						Game.cellStates[col][row] = 0;
						Game.cellUpdateTimers[col][row] = 24;
						Game.cellMoveOffsets[col][row] = 0;
						this.levelResourceMask = this.levelResourceMask | 137438953472n;
						break;
					case 45:
						Game.cellStates[col][row] = 0;
						Game.cellUpdateTimers[col][row] = 24;
						this.levelResourceMask = this.levelResourceMask | 34359738368n;
						break;
					case 44:
						Game.cellUpdateTimers[col][row] = 24;
						Game.cellStates[col][row] = 0;
						this.levelResourceMask = this.levelResourceMask | 17179869184n;
						break;
					case 43:
						this.levelResourceMask = this.levelResourceMask | BigInt.asIntN(64, 1n << BigInt((this.world !== 1 ? 15 : 17) & 63));
						this.enemyPackFlags = this.enemyPackFlags | 1;
						Game.cellStates[col][row] = cellParam & -98305 | 65536;
						s0 = Game.cellUpdateTimers[col];
						s1 = row;
						s2 = 48;
						s0[s1] = s2;
						break;
					case 42:
						cutsceneCount++;
						pickupSlotCount++;
						this.levelResourceMask = this.levelResourceMask | 2147483648n;
						this.levelResourceMask = this.levelResourceMask | 1073741824n;
						this.placeChestOnCell(col, row);
						break;
					case 41:
						if (Game.cellStates[col][row] <= 0) {
							Game.cellStates[col][row] = 1;
						}
						this.diamondsInStage = this.diamondsInStage + Game.cellStates[col][row] | 0;
						break;
					case 40:
						this.levelResourceMask = this.levelResourceMask | 1073741824n;
						cutsceneCount++;
						this.hasWaterLayer = 1;
						this.levelResourceMask = this.levelResourceMask | 134217728n;
						this.placeChestOnCell(col, row);
						pickupSlotCount++;
						break;
					case 39:
						this.hasWaterLayer = 1;
						this.levelResourceMask = this.levelResourceMask | 67108864n;
						break;
					case 38:
						this.hasWaterLayer = 1;
						this.levelResourceMask = this.levelResourceMask | 67108864n;
						Game.cellObjects[col][row] = 27;
						this.levelResourceMask = this.levelResourceMask | 64n;
						break;
					case 37:
						this.levelResourceMask = this.levelResourceMask | 33554432n;
						Game.cellStates[col][row] = 0;
						break;
					case 36:
						if (Game.cellStates[col][row] !== 1) {
							Game.cellStates[col][row] = 0;
						}
						this.levelResourceMask = this.levelResourceMask | 256n;
						break;
					case 35:
						Game.cellTypes[col][row] = 35;
						Game.cellObjects[col][row] = -1;
						this.levelResourceMask = this.levelResourceMask | 16777216n;
						this.levelHasBlock35 = 1;
						break;
					case 34:
						Game.cellTypes[col][row] = -1;
						Game.cellObjects[col][row] = 15;
						this.levelResourceMask = this.levelResourceMask | 16777216n;
						break;
					case 31:
					case 33:
						break;
					case 30:
						this.levelResourceMask = this.levelResourceMask | 128n;
						Game.cellStates[col][row] = 0;
						break;
					case 28:
						this.levelResourceMask = this.levelResourceMask | 2048n;
						if (cellParam > 10) {
							t7 = Game.cellStates[col];
							t7[row] = t7[row] / 11 | 0;
							t8 = Game.cellStates[col];
							t8[row] = t8[row] | 8;
						}
						s0 = Game.cellUpdateTimers[col];
						s1 = row;
						s2 = 24;
						s0[s1] = s2;
						break;
					case 26:
						this.levelResourceMask = this.levelResourceMask | 1099511627776n;
						cutsceneCount++;
						pickupSlotCount++;
						this.levelResourceMask = this.levelResourceMask | 1073741824n;
						this.levelResourceMask = this.levelResourceMask | 524288n;
						this.placeChestOnCell(col, row);
						break;
					case 24:
					case 27:
						cutsceneCount++;
						pickupSlotCount++;
						this.levelResourceMask = this.levelResourceMask | 1073741824n;
						this.levelResourceMask = this.levelResourceMask | 524288n;
						this.placeChestOnCell(col, row);
						break;
					case 22:
					case 23:
						this.levelResourceMask = this.levelResourceMask | 512n;
						this.levelResourceMask = this.levelResourceMask | 1024n;
						s0 = Game.cellUpdateTimers[col];
						s1 = row;
						s2 = 48;
						s0[s1] = s2;
						break;
					case 19:
						this.levelResourceMask = this.levelResourceMask | BigInt.asIntN(64, 1n << BigInt((this.world !== 1 ? 15 : 17) & 63));
						this.enemyPackFlags = this.enemyPackFlags | 2;
						s0 = Game.cellUpdateTimers[col];
						s1 = row;
						s2 = 48;
						s0[s1] = s2;
						break;
					case 18:
						this.switchWallsPhase = 0;
						this.leverMoveDir = 0;
						this.levelResourceMask = this.levelResourceMask | 549755813888n;
						this.levelResourceMask = this.levelResourceMask | 128n;
						break;
					case 16:
						if (Game.cellTypes[col][row + 1] !== 16) {
							Game.cellTypes[col][row - 1] = 16;
							Game.cellStates[col][row - 1] = cellParam;
						}
						this.levelResourceMask = this.levelResourceMask | 8192n;
						break;
					case 14:
						this.levelResourceMask = this.levelResourceMask | 4096n;
						Game.cellStates[col][row] = Game.cellStates[col][row] !== 4 ? 0 : 8;
						s0 = Game.cellUpdateTimers[col];
						s1 = row;
						s2 = 24;
						s0[s1] = s2;
						break;
					case 12:
						this.exitDoorCol = col;
						this.exitDoorRow = row;
						this.diamondsToOpenExit = cellParam;
						break;
					case 11:
						Game.cellStates[col][row] = cellParam !== 1 ? 0 : 16;
						Game.cellUpdateTimers[col][row] = 48;
						this.levelResourceMask = this.levelResourceMask | 16384n;
						break;
					case 10:
						Game.cellStates[col][row] = 0;
						this.levelExtraResourceMask = this.levelExtraResourceMask | 2n;
						break;
					case 8:
						this.levelResourceMask = this.levelResourceMask | 32n;
						this.levelResourceMask = this.levelResourceMask | 8n;
						if (cellType !== 8) {
							this.placeChestOnCell(col, row);
						}
						this.levelResourceMask = this.levelResourceMask | 4n;
						pickupSlotCount++;
						Game.cellUpdateTimers[col][row] = 48;
						Game.cellStates[col][row] = 0;
						this.levelExtraResourceMask = this.levelExtraResourceMask | 1n;
						break;
					case 6:
						pickupSlotCount++;
						this.placeChestOnCell(col, row);
						this.levelResourceMask = this.levelResourceMask | 16n;
						Game.cellStates[col][row] = 0;
						break;
					case 7:
						this.levelResourceMask = this.levelResourceMask | 16n;
						Game.cellStates[col][row] = 0;
						break;
					case 4:
						if (cellType !== 8) {
							this.placeChestOnCell(col, row);
						}
						this.levelResourceMask = this.levelResourceMask | 4n;
						pickupSlotCount++;
						Game.cellUpdateTimers[col][row] = 48;
						Game.cellStates[col][row] = 0;
						this.levelExtraResourceMask = this.levelExtraResourceMask | 1n;
						break;
					case 5:
						this.levelResourceMask = this.levelResourceMask | 4n;
						pickupSlotCount++;
						Game.cellUpdateTimers[col][row] = 48;
						Game.cellStates[col][row] = 0;
						this.levelExtraResourceMask = this.levelExtraResourceMask | 1n;
						break;
					case 2:
						pickupSlotCount++;
						Game.cellUpdateTimers[col][row] = 48;
						Game.cellStates[col][row] = 0;
						this.levelExtraResourceMask = this.levelExtraResourceMask | 1n;
						break;
					case 1:
						this.diamondsInStage = this.diamondsInStage + 1 | 0;
						Game.cellUpdateTimers[col][row] = 48;
						Game.cellStates[col][row] = 0;
						break;
					case 0:
						Game.cellUpdateTimers[col][row] = 48;
						Game.cellStates[col][row] = 0;
						this.levelExtraResourceMask = this.levelExtraResourceMask | 1n;
						break;
				}
			}
		}
		Game.redDiamondPickCells = new Int8Array(pickupSlotCount << 1);
		for (col = 0; col < Game.redDiamondPickCells.length; col++) {
			Game.redDiamondPickCells[col] = 0;
		}
		Game.levelCutscenes = J.newArray(cutsceneCount);
		Game.cutsceneTriggerIds = new Int8Array(cutsceneCount);
		col = 0;
		Game.compassTargets = new Int8Array((goalTargetCount + 1 | 0) * 2 | 0);
		for (row = 31; row >= 0 && (gateIdMask & 1 << row) === 0; row--) {
		}
		row++;
		if (row > 0) {
			Game.gateRemainingCounts = new Int8Array(row);
			Game.gateObjectiveMsgs = new Int8Array(row);
		}
		if (this.freezeRayCount > 0) {
			Game.freezeRays = new Int8Array(this.freezeRayCount * 3 | 0);
		}
		objValue = 0;
		for (cellParam = 0; cellParam < this.levelH; cellParam++) {
			for (cellType = 0; cellType < this.levelW; cellType++) {
				objType = Game.cellObjects[cellType][cellParam] & 255;
				typeOrParam = Game.cellObjects[cellType][cellParam] >> 8;
				switch (objType) {
					case 17:
						if (typeOrParam !== -1) {
							gateKey = new Integer(typeOrParam);
							taskCount = gateTaskCounts.get(gateKey);
							if (taskCount === null) {
								taskCount = new Integer(0);
							}
							Game.gateRemainingCounts[typeOrParam] = taskCount.byteValue();
							msgId = gateObjectiveMsgIds.get(gateKey);
							if (msgId === null) {
								msgId = new Integer(59);
							}
							s0 = Game.gateObjectiveMsgs;
							s1 = typeOrParam;
							s2 = msgId.byteValue();
							s0[s1] = s2;
						}
						break;
					case 7:
						key = locksPerDoor.get(new Integer(typeOrParam));
						typeOrParam = typeOrParam << 8;
						if (key !== null) {
							typeOrParam = typeOrParam & -16 | key.intValue();
						}
						s0 = (Game.cellObjects[cellType][cellParam - 1] & 255) !== 17 ? 0 : 1;
						count = s0;
						s0 = (Game.cellObjects[cellType][cellParam + 1] & 255) !== 17 || (Game.cellObjects[cellType + 1][cellParam] & 255) === 26 || (Game.cellObjects[cellType - 1][cellParam] & 255) === 26 ? 0 : 1;
						prevMsgId = s0;
						if (count !== 0 || prevMsgId !== 0) {
							typeOrParam = typeOrParam & -241 | 48;
							Game.cellUpdateTimers[cellType][cellParam] = 24;
							if (count !== 0) {
								Game.cellObjects[cellType][cellParam - 1] = -1;
							}
						}
						Game.cellObjects[cellType][cellParam] = typeOrParam << 8 | objType;
						break;
					case 5:
						Game.compassTargets[goalTargetCount * 2] = cellType << 24 >> 24;
						s0 = Game.compassTargets;
						s1 = goalTargetCount * 2 + 1 | 0;
						s2 = cellParam << 24 >> 24;
						s0[s1] = s2;
						break;
					case 4:
						goalIndex = typeOrParam;
						Game.compassTargets[goalIndex * 2] = cellType << 24 >> 24;
						s0 = Game.compassTargets;
						s1 = goalIndex * 2 + 1 | 0;
						s2 = cellParam << 24 >> 24;
						s0[s1] = s2;
						break;
					case 0:
					case 30:
						s0 = Game.cutsceneTriggerIds;
						s1 = col++;
						s2 = typeOrParam << 24 >> 24;
						s0[s1] = s2;
						break;
					default:
						break;
				}
				switch (Game.cellTypes[cellType][cellParam]) {
					case 48:
						if ((Game.cellStates[cellType][cellParam] & 8) !== 0) {
							key = cellType + ((Game.cellStates[cellType][cellParam + 1] & 16) !== 0 ? -1 : 1) | 0;
							count = objValue * 3 | 0;
							if (Game.getFrozenKind(key, cellParam) < 0) {
								s0 = Game.freezeRays;
								s1 = count + 2 | 0;
								s2 = -1;
							} else {
								Game.freezeRays[count + 0] = key << 24 >> 24;
								Game.freezeRays[count + 1] = key << 24 >> 24;
								s0 = Game.freezeRays;
								s1 = count + 2 | 0;
								s2 = cellParam << 24 >> 24;
							}
							s0[s1] = s2;
							Game.cellStates[cellType][cellParam] = Game.cellStates[cellType][cellParam] & 16777215 | objValue << 24;
							objValue++;
						}
						break;
					case 42:
						s0 = Game.cutsceneTriggerIds;
						s1 = col++;
						s2 = 11;
						s0[s1] = s2;
						break;
					case 40:
						s0 = Game.cutsceneTriggerIds;
						s1 = col++;
						s2 = 24;
						s0[s1] = s2;
						break;
					case 27:
						s0 = Game.cutsceneTriggerIds;
						s1 = col++;
						s2 = 23;
						s0[s1] = s2;
						break;
					case 26:
						s0 = Game.cutsceneTriggerIds;
						s1 = col++;
						s2 = 25;
						s0[s1] = s2;
						break;
					case 24:
						s0 = Game.cutsceneTriggerIds;
						s1 = col++;
						s2 = 22;
						s0[s1] = s2;
						break;
					default:
						break;
				}
			}
		}
		Game.cellObjects[this.entryWalkRemaining - 2][this.playerRow] = -193 << 8 | 7;
		if ((this.levelResourceMask & 4294967296n) !== 0n || Game.saveData[9] >= 8) {
			this.levelResourceMask = this.levelResourceMask | 1099511627776n;
			this.levelResourceMask = this.levelResourceMask | 2n;
			this.levelResourceMask = this.levelResourceMask | 1n;
			if ((this.levelResourceMask & 131072n) !== 0n) {
				this.levelResourceMask = this.levelResourceMask | 262144n;
			}
			if ((this.levelResourceMask & 32768n) !== 0n) {
				this.levelResourceMask = this.levelResourceMask | 65536n;
			}
			if ((this.levelResourceMask & 34359738368n) !== 0n) {
				this.levelResourceMask = this.levelResourceMask | 68719476736n;
			}
			if ((this.levelResourceMask & 137438953472n) !== 0n) {
				this.levelResourceMask = this.levelResourceMask | 274877906944n;
			}
			if ((this.levelResourceMask & 2199023255552n) !== 0n) {
				this.levelResourceMask = this.levelResourceMask | 4398046511104n;
			}
		}
	}

	propagateLockFlag(col, row, dx, dy, setFlag) {
		let objParam = 0, stepDx = 0, stepDy = 0, objType = 0;
		if ((col + dx | 0) <= 0 || (col + dx | 0) >= this.levelW || (row + dy | 0) <= 0 || (row + dy | 0) >= this.levelH) {
			return;
		}
		stepDx = dx;
		stepDy = dy;
		objType = Game.cellObjects[col + dx][row + dy] & 255;
		switch (objType) {
			case 8:
			case 9:
				objParam = Game.cellObjects[col + dx][row + dy] >> 8;
				objParam = setFlag !== 1 ? objParam & -513 : objParam | 512;
				Game.cellObjects[col + dx][row + dy] = objParam << 8 | objType;
				this.propagateLockFlag(col + dx | 0, row + dy | 0, stepDx, stepDy, setFlag);
				this.propagateLockFlag(col + dx | 0, row + dy | 0, 0, 1, setFlag);
				break;
			default:
				break;
		}
	}

	isPlayerAt(col, row) {
		if (col !== this.playerCol || row !== this.playerRow) {
			return 0;
		}
		return 1;
	}

	startCutscene(triggerId) {
		let index = 0;
		this.currentMoveDir = 0;
		this.requestedMoveDir = 0;
		for (index = 0; index < Game.cutsceneTriggerIds.length; index++) {
			if (Game.cutsceneTriggerIds[index] === triggerId) {
				this.activeCutscene = Game.levelCutscenes[index];
			}
		}
		this.activeCutscene.start();
	}

	stepCameraPan() {
		let xReached = 0, yReached = 0;
		if (this.camX >= this.camPanTargetX) {
			if (this.camX > this.camPanTargetX) {
				this.camX = this.camX - this.camPanSpeed | 0;
				if (this.camX < this.camPanTargetX) {
					this.camX = this.camPanTargetX;
				}
			}
		} else {
			this.camX = this.camX + this.camPanSpeed | 0;
			if (this.camX > this.camPanTargetX) {
				this.camX = this.camPanTargetX;
			}
		}
		if (this.camY >= this.camPanTargetY) {
			if (this.camY > this.camPanTargetY) {
				this.camY = this.camY - this.camPanSpeed | 0;
				if (this.camY < this.camPanTargetY) {
					this.camY = this.camPanTargetY;
				}
			}
		} else {
			this.camY = this.camY + this.camPanSpeed | 0;
			if (this.camY > this.camPanTargetY) {
				this.camY = this.camPanTargetY;
			}
		}
		xReached = 0;
		yReached = 0;
		if (this.camX >= 0) {
			if (this.camX <= (this.levelW * 24 - 240 | 0)) {
				if (this.camX === this.camPanTargetX) {
					xReached = 1;
				}
			} else {
				this.camX = this.levelW * 24 - 240 | 0;
				xReached = 1;
			}
		} else {
			this.camX = 0;
			xReached = 1;
		}
		B12: {
			if (this.camY < 0) {
				this.camY = 0;
				yReached = 1;
				break B12;
			}
			B13: {
				if (this.camY <= (this.levelH * 24 - 320 + 80 | 0)) {
					if (this.camY === this.camPanTargetY) {
						yReached = 1;
					}
				} else {
					this.camY = this.levelH * 24 - 320 + 80 | 0;
					yReached = 1;
					break B13;
				}
			}
		}
		if (xReached === 0 || yReached === 0) {
			return 0;
		}
		this.camTargetX = this.camX;
		this.camTargetY = this.camY;
		this.playerIdleCountdown = 70;
		return 1;
	}

	updateGateRevealPan() {
		let doorParam = 0;
		switch (this.gateRevealState) {
			case 4:
				this.doorPanTimer = this.doorPanTimer - 1 | 0;
				if (this.doorPanTimer === 0) {
					this.playerIdleCountdown = 0;
					this.gateRevealState = 0;
					Game.cameraHoldAfterPan = 1;
				}
				break;
			case 3:
				if (this.stepCameraPan()) {
					this.doorPanTimer = 20;
					this.gateRevealState = 4;
					this.playerIdleCountdown = 0;
					return;
				}
				break;
			case 2:
				this.doorPanTimer = this.doorPanTimer - 1 | 0;
				if (this.doorPanTimer !== 30) {
					if (this.doorPanTimer === 0) {
						this.gateRevealState = 3;
						this.camPanTargetX = this.playerCol * 24 - 108 | 0;
						this.camPanTargetY = this.playerRow * 24 - 108 | 0;
						this.camPanSpeed = 5;
						this.hintText = Game.langStrings[Game.gateObjectiveMsgs[Game.activeGateId]];
						Game.spritePacks[41].measureTextHeight(this.hintText);
						this.hintTimer = 80;
						return;
					}
				} else {
					doorParam = Game.cellObjects[this.panDoorCol][this.panDoorRow] >> 8;
					if ((doorParam & 240) !== 0) {
						this.closeDoorAt(this.panDoorCol, this.panDoorRow);
						return;
					}
				}
				break;
			case 1:
				this.camPanSpeed = 8;
				if (this.stepCameraPan()) {
					this.gateRevealState = 2;
					this.doorPanTimer = 40;
					return;
				}
				break;
			default:
				break;
		}
	}

	setGatePanTarget(gateId) {
		let doorParam = 0, row = 0, targetRow = 0, maxCol = 0, col = 0, maxRow = 0, objAbove = 0, targetCol = 0, s0;
		this.playSound(1);
		maxCol = this.levelW - 1 | 0;
		maxRow = this.levelH - 1 | 0;
		for (row = 1; row < maxRow; row++) {
			for (col = 1; col < maxCol; col++) {
				if ((Game.cellObjects[col][row] & 255) === 17 && Game.cellObjects[col][row] >> 8 === gateId) {
					targetCol = -1;
					targetRow = -1;
					if (Game.cellTypes[col][row] !== 18) {
						objAbove = Game.cellObjects[col][row - 1] & 255;
						switch (objAbove) {
							case 7:
								doorParam = Game.cellObjects[col][row - 1] >> 8;
								if ((doorParam & 240) !== 0) {
									targetCol = col;
									s0 = row - 1 | 0;
									targetRow = s0;
								}
								break;
							case 14:
							case 33:
								targetCol = col;
								s0 = row - 1 | 0;
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
					if (targetCol !== -1) {
						this.panDoorCol = targetCol;
						this.panDoorRow = targetRow;
						this.camPanTargetX = 24 * targetCol - 108 | 0;
						this.camPanTargetY = 24 * targetRow - 108 | 0;
					}
				}
			}
		}
	}

	openGateById(gateId) {
		let row = 0, maxCol = 0, col = 0, maxRow = 0, objAbove = 0;
		this.playSound(8);
		maxCol = this.levelW - 1 | 0;
		maxRow = this.levelH - 1 | 0;
		for (row = 1; row < maxRow; row++) {
			for (col = 1; col < maxCol; col++) {
				if ((Game.cellObjects[col][row] & 255) === 17 && Game.cellObjects[col][row] >> 8 === gateId) {
					objAbove = Game.cellObjects[col][row - 1] & 255;
					switch (objAbove) {
						case 14:
						case 33:
							Game.cellObjects[col][row - 1] = 0 | objAbove;
							break;
						case 7:
							Game.openDoorAt(col, row - 1 | 0);
							break;
						default:
							break;
					}
				}
			}
		}
	}

	updateCellsNearPlayer() {
		let effectFrame = 0, maxCol = 0, isSlidingObj = 0, cellType = 0, maxRow = 0, trapLength = 0, minRow = 0, minCol = 0, s0, s1, t2, t3;
		minCol = this.playerCol - 8 | 0;
		maxCol = this.playerCol + 8 | 0;
		maxRow = this.playerRow + 8 | 0;
		minRow = this.playerRow - 8 | 0;
		trapLength = 0;
		if (Game.actors[4] !== null) {
			isSlidingObj = Game.actors[4].frameIndex;
			if (isSlidingObj !== 0) {
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
		if (maxCol > (this.levelW - 2 | 0)) {
			maxCol = this.levelW - 2 | 0;
		}
		if (minRow < 1) {
			minRow = 1;
		}
		if (maxRow > (this.levelH - 2 | 0)) {
			maxRow = this.levelH - 2 | 0;
		}
		s0 = this;
		s1 = maxRow;
		while (true) {
			s0.updateCellRow = s1;
			if (this.updateCellRow < minRow) {
				break;
			}
			s0 = this;
			s1 = minCol;
			while (true) {
				s0.updateCellCol = s1;
				if (this.updateCellCol > maxCol) {
					break;
				}
				s0 = this.slideCellsLeft === 0 || this.updateCellCol !== this.slidingObjCol || this.updateCellRow !== this.slidingObjRow ? 0 : 1;
				isSlidingObj = s0;
				if (Game.cellUpdateTimers[this.updateCellCol][this.updateCellRow] > 0 && isSlidingObj === 0) {
					t2 = Game.cellUpdateTimers[this.updateCellCol];
					t3 = this.updateCellRow;
					t2[t3] = t2[t3] - 6 << 24 >> 24;
					cellType = (Game.cellObjects[this.updateCellCol][this.updateCellRow] & 255) << 24 >> 24;
					switch (cellType) {
						case 36:
							this.tickExpiringLayerObject();
							break;
						case 35:
						case 37:
							if (this.updateCellCol !== this.slidingObjCol || this.updateCellRow !== this.slidingObjRow || this.slideCellsLeft === 0) {
								this.updateLiftColumnCell();
							}
							break;
						case 33:
							this.updateChest(33);
							break;
						case 32:
							this.animateWallDebris();
							break;
						case 30:
							if (this.activeCutscene === null && this.pendingCutsceneId === -1 && this.isPlayerAt(this.updateCellCol, this.updateCellRow) && this.playerStep <= 0) {
								this.pendingCutsceneId = Game.cellObjects[this.updateCellCol][this.updateCellRow] >> 8;
								Game.cellObjects[this.updateCellCol][this.updateCellRow] = -1;
							}
							break;
						case 26:
							this.triggerGateChallenge();
							break;
						case 14:
							this.updateChest(14);
							break;
						case 9:
							s0 = this;
							s0.tryStartDoorUnlock();
							break;
						case 8:
							s0 = this;
							s0.tryStartDoorUnlock();
							break;
						case 7:
							this.updateDoorOpening();
							break;
						case 6:
							this.updatePressurePlate();
							break;
						case 3:
							this.updateProximityAnimTile();
							break;
						case 2:
							switch (Game.cellObjects[this.updateCellCol][this.updateCellRow] >> 8) {
								case 0:
									if (Game.cellTypes[this.updateCellCol - 1][this.updateCellRow] !== 30 && Game.cellTypes[this.updateCellCol + 1][this.updateCellRow] !== 30 && Game.cellTypes[this.updateCellCol][this.updateCellRow - 1] !== 30 && Game.cellTypes[this.updateCellCol][this.updateCellRow + 1] !== 30) {
										this.hintBubbleImageSet = -1;
										this.clearConnectedObjects(this.updateCellCol, this.updateCellRow, 2);
									}
									break;
								default:
									break;
							}
							break;
						case 0:
							if (this.activeCutscene === null && this.pendingCutsceneId === -1 && this.isPlayerAt(this.updateCellCol, this.updateCellRow) && this.playerStep <= 6) {
								this.pendingCutsceneId = Game.cellObjects[this.updateCellCol][this.updateCellRow] >> 8;
								Game.cellObjects[this.updateCellCol][this.updateCellRow] = -1;
							}
							break;
						default:
							break;
					}
					effectFrame = (Game.cellObjects[this.updateCellCol][this.updateCellRow] & -268435456) >> 28;
					if (effectFrame > 0) {
						this.animateEnemyDeathPuff();
					}
					cellType = Game.cellTypes[this.updateCellCol][this.updateCellRow];
					switch (cellType) {
						case 54:
							this.updateExplosion();
							break;
						case 53:
							this.startItemPickup(53);
							break;
						case 52:
							this.startItemPickup(52);
							break;
						case 51:
							this.startItemPickup(51);
							break;
						case 50:
							if (this.playerStep < 12 && this.isPlayerAt(this.updateCellCol, this.updateCellRow) && !this.anacondaHitPlayer) {
								this.damageExplorer(1, 48, Game.oppositeDir[this.explorerStateFlags & 7]);
							}
							break;
						case 49:
							this.updateWalkingEnemy(49);
							break;
						case 48:
							if ((Game.cellStates[this.updateCellCol][this.updateCellRow] & 8) !== 0) {
								this.updateFreezeRay();
							} else {
								this.updateTallObjectFall(48);
							}
							break;
						case 47:
							this.updateFallingObject();
							this.emitLiftColumn();
							break;
						case 46:
							this.updateShooterEnemy();
							break;
						case 45:
							this.updateHopperEnemy();
							break;
						case 44:
							this.updateStalactite();
							break;
						case 43:
							this.updateWalkingEnemy(43);
							break;
						case 42:
							this.startItemPickup(42);
							break;
						case 41:
							this.startItemPickup(41);
							break;
						case 40:
							this.startItemPickup(40);
							break;
						case 37:
							this.updateCrackingWall();
							break;
						case 36:
							this.updateTorch();
							break;
						case 32:
							this.updateExtendingRod();
							break;
						case 30:
							this.updateCrumblingWall();
							break;
						case 28:
							this.updateExtendingTrap();
							break;
						case 27:
							this.takeRelicFromChest(27);
							break;
						case 26:
							this.takeRelicFromChest(26);
							break;
						case 24:
							this.takeRelicFromChest(24);
							break;
						case 23:
							s0 = this;
							s1 = 23;
							s0.updateFlameJetTrap(s1, trapLength);
							break;
						case 22:
							s0 = this;
							s1 = 22;
							s0.updateFlameJetTrap(s1, trapLength);
							break;
						case 21:
							this.updateProjectile();
							break;
						case 19:
							this.updateWalkingEnemy(19);
							break;
						case 16:
							this.updateTallStrikerEnemy();
							break;
						case 14:
							this.updateSideRoller();
							break;
						case 11:
							this.updateCrawlingFlame();
							break;
						case 10:
							this.updateFragileWall();
							break;
						case 9:
							if ((Game.cellStates[this.updateCellCol][this.updateCellRow] & 264241152) === 138412032) {
								Game.cellUpdateTimers[this.updateCellCol][this.updateCellRow] = 24;
								if (this.frozenShakeX <= 0) {
									if (this.frozenShakeX < 0) {
										s0 = this;
										s1 = this.frozenShakeX + 1 | 0;
										s0.frozenShakeX = s1;
									}
								} else {
									s0 = this;
									s1 = this.frozenShakeX - 1 | 0;
									s0.frozenShakeX = s1;
								}
								if (this.frozenShakeY <= 0) {
									if (this.frozenShakeY < 0) {
										s0 = this;
										s1 = this.frozenShakeY + 1 | 0;
										s0.frozenShakeY = s1;
									}
								} else {
									s0 = this;
									s1 = this.frozenShakeY - 1 | 0;
									s0.frozenShakeY = s1;
								}
							}
							this.updateFallingObject();
							break;
						case 8:
							this.updateFallingObject();
							break;
						case 7:
							this.startItemPickup(7);
							break;
						case 6:
							this.startItemPickup(6);
							break;
						case 5:
							this.startItemPickup(5);
							break;
						case 4:
							this.startItemPickup(4);
							break;
						case 2:
							this.startItemPickup(2);
							break;
						case 1:
							this.updateFallingObject();
							break;
						case 0:
							this.updateFallingObject();
							break;
						default:
							break;
					}
				}
				s0 = this;
				s1 = this.updateCellCol + 1 | 0;
			}
			s0 = this;
			s1 = this.updateCellRow - 1 | 0;
		}
	}

	updateFreezeRay() {
		let row = 0, baseState = 0, baseRow = 0, col = 0, rayIndex = 0, rayCol = 0, s0, s1, s2, t3;
		col = this.updateCellCol;
		row = this.updateCellRow;
		baseRow = row + 1 | 0;
		baseState = Game.cellStates[col][baseRow];
		switch (baseState & 7) {
			default:
				if ((baseState & 16) !== 0) {
					s0 = col;
					t3 = s0 - 1 | 0;
					s0 = t3;
				} else {
					s0 = col + 1 | 0;
				}
				break;
			case 4:
				s0 = col + 1 | 0;
				break;
			case 2:
				s0 = col;
				t3 = s0 - 1 | 0;
				s0 = t3;
				break;
		}
		rayCol = s0;
		rayIndex = (Game.cellStates[col][row] >> 24) * 3 | 0;
		if (Game.cellTypes[rayCol][row] >= 0) {
			s0 = Game.freezeRays;
			s1 = rayIndex + 2 | 0;
			s2 = -1;
		} else {
			Game.freezeRays[rayIndex + 2] = row << 24 >> 24;
			Game.freezeRays[rayIndex + 1] = rayCol << 24 >> 24;
			s0 = Game.freezeRays;
			s1 = rayIndex + 0 | 0;
			s2 = rayCol << 24 >> 24;
		}
		s0[s1] = s2;
	}

	updateTallObjectFall(cellType) {
		let row = 0, wakeRow = 0, col = 0, state = 0, dir = 0, belowRow = 0, s0, t3;
		col = this.updateCellCol;
		row = this.updateCellRow;
		if (Game.cellMoveOffsets[col][row] === 6 && (Game.cellObjects[col][row] & 255) === 6) {
			this.unlockDoorLock(Game.cellObjects[col][row] >> 8);
		}
		if (Game.cellMoveOffsets[col][row] > 0) {
			t3 = Game.cellMoveOffsets[col];
			t3[row] = t3[row] - 6 << 24 >> 24;
		} else {
			state = Game.cellStates[col][row];
			dir = state & 7;
			if (dir !== 2) {
				if (dir === 4) {
					s0 = state & -17;
					state = s0;
				}
			} else {
				s0 = state | 16;
				state = s0;
			}
			belowRow = row + 1 | 0;
			if (Game.cellTypes[col][belowRow] >= 0 || this.isPlayerAt(col, belowRow) && this.deathTimer === 0) {
				if ((state & 7) === 3 && this.isPlayerAt(col, row + 1 | 0)) {
					this.damageExplorer(2, 48, 0);
				}
				Game.cellStates[col][row] = state & -8 | 0;
			} else {
				Game.cellTypes[col][row - 1] = -1;
				Game.cellTypes[col][belowRow] = cellType;
				Game.cellStates[col][belowRow] = state & -8 | 3;
				Game.cellStates[col][row] = Game.cellStates[col][row - 1] | 8;
				Game.cellMoveOffsets[col][belowRow] = 18;
				wakeRow = row - 2 | 0;
				Game.cellUpdateTimers[col - 1][wakeRow] = 48;
				Game.cellUpdateTimers[col][wakeRow] = 48;
				Game.cellUpdateTimers[col + 1][wakeRow] = 48;
				Game.wakeCellsAround(col, row);
				if (cellType === 48) {
					this.updateFreezeRay();
				}
			}
		}
		Game.cellUpdateTimers[col][row] = 24;
		Game.cellUpdateTimers[col][row - 1] = 24;
	}

	updateLiftColumnCell() {
		let aboveRow = 0, row = 0, col = 0, cellType = 0, aboveObj = 0, belowRow = 0, s0, s1, s2, t2;
		col = this.updateCellCol;
		row = this.updateCellRow;
		Game.cellUpdateTimers[col][row] = 24;
		if (Game.cellMoveOffsets[col][row] > 0) {
			t2 = Game.cellMoveOffsets[col];
			s0 = t2;
			s1 = row;
			s2 = t2[row] - 6 << 24 >> 24;
			s0[s1] = s2;
		} else {
			aboveRow = row - 1 | 0;
			belowRow = row + 1 | 0;
			aboveObj = (Game.cellObjects[col][aboveRow] & 255) << 24 >> 24;
			if (aboveObj === 34 || aboveObj === 37) {
				s0 = Game.cellObjects[col];
				s1 = aboveRow;
				s2 = 37;
				s0[s1] = s2;
			} else {
				if (aboveObj !== 35 && Game.canLiftColumnEnter(col, aboveRow)) {
					Game.cellMoveOffsets[col][aboveRow] = 18;
					s0 = Game.cellObjects[col];
					s1 = aboveRow;
					s2 = 35;
					s0[s1] = s2;
				}
			}
			cellType = Game.cellTypes[col][row];
			if (Game.cellTypes[col][aboveRow] >= 0 || this.isPlayerAt(col, aboveRow) || aboveObj !== 35 || cellType === 32 || cellType === 21 || Game.cellTypes[col][row] === -1) {
				this.redrawCellInBuffer(col, row);
			} else {
				Game.cellMoveOffsets[col][aboveRow] = 18;
				Game.cellTypes[col][aboveRow] = Game.cellTypes[col][row];
				Game.cellStates[col][aboveRow] = Game.cellStates[col][row] & -8 | 1;
				Game.cellTypes[col][row] = -1;
				this.eraseCellInBuffer(col, row);
			}
			if ((Game.cellObjects[col][belowRow] & 255) !== 35 && Game.cellTypes[col][belowRow] !== 47) {
				if (Game.cellObjects[col][row] !== 37) {
					s0 = Game.cellObjects[col];
					s1 = row;
					s2 = -1;
				} else {
					s0 = Game.cellObjects[col];
					s1 = row;
					s2 = 34;
				}
				s0[s1] = s2;
			}
			Game.cellUpdateTimers[col][aboveRow] = 24;
			B7: {
				if (Game.cellTypes[col][row] < 0) {
					s0 = Game.cellMoveOffsets[col];
					s1 = row;
					s2 = 18;
					s0[s1] = s2;
					break B7;
				}
			}
		}
	}

	static canLiftColumnEnter(col, row) {
		let cellType = 0, objType = 0;
		cellType = Game.cellTypes[col][row];
		objType = Game.cellObjects[col][row] & 255;
		if (cellType >= 80 || cellType === 30 || cellType === 10 || cellType === 37 || cellType === 34 || cellType === 35 || objType === 14 || objType === 33 || objType === 15 || objType === 4 || objType === 16) {
			return 0;
		}
		return 1;
	}

	static isCellFreeForObject(col, row) {
		let cellType = 0, objType = 0;
		cellType = Game.cellTypes[col][row];
		objType = Game.cellObjects[col][row] & 255;
		if (cellType !== -1 || objType === 14 || objType === 33 || objType === 5 || objType === 28) {
			return 0;
		}
		return 1;
	}

	static isCellFreeForEnemy(col, row) {
		let cellType = 0, objType = 0;
		cellType = Game.cellTypes[col][row];
		objType = Game.cellObjects[col][row] & 255;
		if (cellType !== -1 || objType === 14 || objType === 33 || objType === 4 || objType === 32 || objType === 7 && (Game.cellObjects[col][row] >> 8 & 240) === 0) {
			return 0;
		}
		return 1;
	}

	emitLiftColumn() {
		let aboveRow = 0, atLiquidSurface = 0;
		aboveRow = this.updateCellRow - 1 | 0;
		atLiquidSurface = Game.liquidCells === null || Game.liquidCells[this.updateCellCol][this.updateCellRow] === 0 || Game.liquidCells[this.updateCellCol][this.updateCellRow - 1] !== 0 ? 0 : 1;
		if ((Game.cellStates[this.updateCellCol][this.updateCellRow] & 7) === 0 && (Game.cellObjects[this.updateCellCol][aboveRow] & 255) !== 35 && Game.canLiftColumnEnter(this.updateCellCol, aboveRow) && (!this.isPlayerAt(this.updateCellCol - 1 | 0, this.updateCellRow) && !this.isPlayerAt(this.updateCellCol + 1 | 0, this.updateCellRow) || (this.explorerStateFlags & 8) === 0) && (Game.cellTypes[this.updateCellCol][this.updateCellRow + 1] >= 0 || atLiquidSurface !== 0)) {
			Game.cellObjects[this.updateCellCol][aboveRow] = 35;
			Game.cellMoveOffsets[this.updateCellCol][aboveRow] = 18;
			Game.cellUpdateTimers[this.updateCellCol][aboveRow] = 24;
		}
	}

	updateShooterEnemy() {
		let aboveRow = 0, playerFacing = 0, animTick = 0, row = 0, isOnLiftColumn = 0, animLength = 0, dirToPlayer = 0, col = 0, rightCol = 0, animState = 0, s0, s1, t1;
		col = this.updateCellCol;
		row = this.updateCellRow;
		animState = Game.cellStates[col][row] & 31;
		animTick = (Game.cellStates[col][row] & 8160) >> 5;
		animLength = Game.getAnimDuration(Game.spritePacks[29], animState);
		isOnLiftColumn = (Game.cellObjects[col][row] & 255) === 35 ? 1 : 0;
		if (!isOnLiftColumn) {
			if (Game.cellTypes[col][row + 1] >= 0 || animState === 8 || animState === 9) {
				if (animState === 8 || animState === 9) {
					t1 = Game.cellMoveOffsets[col];
					t1[row] = t1[row] - 6 << 24 >> 24;
					if (Game.cellMoveOffsets[col][row] >= 0) {
						if (Game.doMovingCellsTouch(col, row, 3, Game.cellMoveOffsets[col][row], this.playerCol, this.playerRow, this.explorerStateFlags & 7, this.playerStep)) {
							this.damageExplorer(1, 48, Game.cellStates[col][row] & 7);
							return;
						}
					} else {
						if (Game.cellTypes[col][row + 1] >= 0) {
							animState = animState !== 8 ? 11 : 10;
							Game.cellStates[col][row] = animState;
							Game.cellMoveOffsets[col][row] = 0;
							return;
						}
						Game.cellMoveOffsets[col][row + 1] = 18;
						Game.cellTypes[col][row + 1] = 46;
						Game.cellTypes[col][row] = -1;
						Game.cellStates[col][row + 1] = animState;
						Game.wakeCellsAround(col, row);
						return;
					}
				} else {
					if (this.isCellCrushed(col, row)) {
						Game.cellTypes[col][row] = -1;
						this.killEnemyAt(col, row);
						Game.wakeCellsAround(col, row);
						return;
					}
					if (this.isPlayerAt(col - 1 | 0, row) || this.isPlayerAt(col + 1 | 0, row) || this.isPlayerAt(col, row - 1 | 0)) {
						B9: {
							if (this.playerRow === (row - 1 | 0)) {
								s0 = 17;
								animState = s0;
								break B9;
							}
							B10: {
								if (this.playerCol === (col - 1 | 0)) {
									s0 = 16;
									animState = s0;
									break B10;
								}
								if (this.playerCol === (col + 1 | 0)) {
									s0 = 15;
									animState = s0;
								}
							}
						}
						animTick = 0;
					} else {
						playerFacing = this.explorerStateFlags & 7;
						if (this.playerCol !== col || this.playerStep !== 6 || playerFacing !== 4 && playerFacing !== 2 || this.playerRow >= row || Game.cellTypes[col][row - 1] >= 0 || (row * 24 | 0) > (this.camY + 320 - 80 | 0)) {
							if (this.playerRow !== row || this.playerStep !== 6 || playerFacing !== 1 && playerFacing !== 3 || animState < 0 || animState > 3 || (this.playerCol >= col || Game.cellTypes[col - 1][row] >= 0 || (col * 24 | 0) >= (this.camX + 240 | 0)) && (this.playerCol <= col || Game.cellTypes[col + 1][row] >= 0 || ((col + 1 | 0) * 24 | 0) <= this.camX)) {
								animTick++;
								switch (animState) {
									case 6:
									case 7:
										aboveRow = row - 1 | 0;
										if (Game.cellTypes[col][aboveRow] < 0 && animTick === Game.animTimeBeforeFrame(Game.spritePacks[29], animState, 1)) {
											Game.cellTypes[col][aboveRow] = 21;
											Game.cellStates[col][aboveRow] = 1;
											Game.cellMoveOffsets[col][aboveRow] = 18;
											s0 = Game.cellUpdateTimers[col];
											s1 = aboveRow;
											s0[s1] = 24;
										}
										break;
									case 5:
										rightCol = col + 1 | 0;
										if (Game.cellTypes[rightCol][row] < 0 && animTick === Game.animTimeBeforeFrame(Game.spritePacks[29], 5, 1)) {
											Game.cellTypes[rightCol][row] = 21;
											Game.cellStates[rightCol][row] = 2;
											Game.cellMoveOffsets[rightCol][row] = 18;
											s0 = Game.cellUpdateTimers[rightCol];
											s1 = row;
											s0[s1] = 24;
										}
										break;
									case 4:
										dirToPlayer = col - 1 | 0;
										if (Game.cellTypes[dirToPlayer][row] < 0 && animTick === Game.animTimeBeforeFrame(Game.spritePacks[29], 4, 1)) {
											Game.cellTypes[dirToPlayer][row] = 21;
											Game.cellStates[dirToPlayer][row] = 4;
											Game.cellMoveOffsets[dirToPlayer][row] = 18;
											s0 = Game.cellUpdateTimers[dirToPlayer];
											s1 = row;
											s0[s1] = 24;
										}
										break;
									default:
										break;
								}
								if (animTick > animLength) {
									animTick = 0;
									dirToPlayer = this.chooseDirectionToward(col, row, this.playerCol, this.playerRow, 0);
									switch (dirToPlayer) {
										default:
											s0 = this.playerCol >= col ? 1 : 0;
											animState = s0;
											break;
										case 4:
											s0 = this.playerRow !== row || animState === 4 || (col * 24 | 0) >= (this.camX + 240 | 0) ? 0 : 4;
											animState = s0;
											break;
										case 2:
											s0 = this.playerRow !== row || animState === 5 || ((col + 1 | 0) * 24 | 0) <= this.camX ? 1 : 5;
											animState = s0;
											break;
										case 1:
											if (this.playerCol !== col || animState === 6 || animState === 7 || (row * 24 | 0) > (this.camY + 320 - 80 | 0)) {
												animState = this.playerCol >= col ? 3 : 2;
											} else {
												animState = animState !== 2 ? 7 : 6;
											}
											break;
									}
								}
							} else {
								animState = this.playerCol >= col ? 5 : 4;
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
					Game.cellUpdateTimers[col][row] = 24;
					Game.cellStates[col][row] = animState & 31 | animTick << 5;
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
			Game.cellMoveOffsets[col][row + 1] = 18;
			Game.cellTypes[col][row + 1] = 46;
			Game.cellTypes[col][row] = -1;
			Game.cellStates[col][row + 1] = animState;
			Game.wakeCellsAround(col, row);
			return;
		}
		animTick++;
		if (animTick > animLength) {
			animTick = 0;
		}
		Game.cellStates[col][row] = 0 | animTick << 5;
	}

	static getAnimDuration(pack, animIndex) {
		let totalTicks = 0, i = 0, frameCount = 0;
		totalTicks = 0;
		frameCount = pack.animFrameCounts[animIndex] & 255;
		for (i = 0; i < frameCount; i++) {
			totalTicks = totalTicks + (pack.animFrames[(pack.animFirstFrame[animIndex] + i | 0) * 5 + 1] & 255) | 0;
		}
		return totalTicks;
	}

	updateStalactite() {
		let row = 0, blocked = 0, phase = 0, col = 0, scanRow = 0, s0, s1, s2, t2, t3, t4;
		col = this.updateCellCol;
		row = this.updateCellRow;
		Game.cellUpdateTimers[col][row] = 24;
		phase = (Game.cellStates[col][row] & 56) >> 3;
		switch (phase) {
			case 4:
				if ((Game.frameCount & 1) === 0) {
					t4 = Game.cellMoveOffsets[col];
					t4[row] = t4[row] + 1 << 24 >> 24;
					if (Game.cellMoveOffsets[col][row] === Game.spritePacks[27].getAnimFrameCount(4)) {
						s0 = Game.cellTypes[col];
						s1 = row;
						s2 = -1;
						s0[s1] = s2;
						Game.wakeCellsAround(col, row);
					}
				}
				break;
			case 3:
				if (Game.cellMoveOffsets[col][row] > 0) {
					t3 = Game.cellMoveOffsets[col];
					t3[row] = t3[row] - 5 << 24 >> 24;
					return;
				}
				scanRow = this.isPlayerAt(col, row + 1 | 0);
				blocked = 0;
				if (scanRow !== 0 || Game.cellTypes[col][row + 1] >= 0 || this.hasWaterLayer && Game.liquidCells[col][row + 1] !== 0) {
					if (scanRow === 0) {
						blocked = 1;
						switch (Game.cellTypes[col][row + 1]) {
							default:
								this.playSound(14);
								break;
							case 30:
								this.playSound(11);
								Game.cellStates[col][row + 1] = 1;
								break;
							case 21:
								blocked = 0;
								break;
							case 19:
							case 43:
							case 45:
							case 46:
							case 49:
								this.killEnemyAt(col, row + 1 | 0);
								Game.cellTypes[col][row + 1] = -1;
								break;
							case 18:
								this.tryPullLever();
								break;
							case 10:
								Game.cellObjects[col][row + 1] = 32;
								this.eraseCellInBuffer(col, row + 1 | 0);
								blocked = 0;
								break;
						}
					} else {
						this.damageExplorer(1, 48, 0);
						blocked = 1;
					}
				}
				if (blocked === 0) {
					Game.cellTypes[col][row] = -1;
					Game.cellTypes[col][row + 1] = 44;
					Game.cellStates[col][row + 1] = Game.cellStates[col][row];
					s0 = Game.cellMoveOffsets[col];
					s1 = row + 1 | 0;
					s2 = 19;
					s0[s1] = s2;
					Game.wakeCellsAround(col, row);
					break;
				}
				Game.cellStates[col][row] = Game.cellStates[col][row] & -64 | 32;
				Game.cellMoveOffsets[col][row] = 0;
				return;
			case 1:
				t2 = Game.cellMoveOffsets[col];
				t2[row] = t2[row] - 1 << 24 >> 24;
				if (Game.cellMoveOffsets[col][row] <= 0) {
					Game.cellObjects[col][row] = 34;
					Game.cellStates[col][row] = Game.cellStates[col][row] & -64 | 24 | 3;
					Game.cellMoveOffsets[col][row] = 0;
					return;
				}
				break;
			case 0:
				if (this.playerCol === col && ((row + 1 | 0) * 24 | 0) > this.camY && this.specialStageType !== 3 || this.specialStageType === 3 && this.ceilingCollapseFrame !== 0n && BigInt(Game.frameCount) >= BigInt.asIntN(64, this.ceilingCollapseFrame + BigInt(21 - col | 0))) {
					scanRow = row + 1 | 0;
					while (true) {
						blocked = Game.cellTypes[col][scanRow];
						if (this.playerRow === scanRow || blocked >= 80 || blocked === 30 || blocked === 34 || blocked === 35 || blocked === 0) {
							break;
						}
						scanRow++;
					}
					if (this.playerRow === scanRow || this.specialStageType === 3) {
						Game.cellStates[col][row] = Game.cellStates[col][row] & -57 | 8;
						Game.cellMoveOffsets[col][row] = 10;
						return;
					}
				}
				break;
			default:
				break;
		}
	}

	animateWallDebris() {
		let frame = 0, s0, s1, s2;
		frame = Game.cellObjects[this.updateCellCol][this.updateCellRow] >> 8 & 255;
		if ((Game.frameCount & 1) !== 0) {
			if (frame === 1) {
				this.eraseCellInBuffer(this.updateCellCol, this.updateCellRow);
			}
		} else {
			frame++;
		}
		if (frame !== Game.spritePacks[16].getAnimFrameCount(0)) {
			s0 = Game.cellObjects[this.updateCellCol];
			s1 = this.updateCellRow;
			s2 = frame << 8 | 32;
		} else {
			s0 = Game.cellObjects[this.updateCellCol];
			s1 = this.updateCellRow;
			s2 = -1;
		}
		s0[s1] = s2;
		Game.cellUpdateTimers[this.updateCellCol][this.updateCellRow] = 24;
	}

	updatePressurePlate() {
		let row = 0, doorId = 0, pressDepth = 0, col = 0, isPressed = 0;
		col = this.updateCellCol;
		row = this.updateCellRow;
		doorId = Game.cellObjects[col][row] >> 8;
		isPressed = Game.isHeavyObject(col, row) || Game.cellTypes[col][row] === 47 || Game.cellTypes[col][row] === 48 ? 1 : 0;
		pressDepth = Game.cellMoveOffsets[col][row];
		if (isPressed === 0 && this.isPlayerAt(col, row)) {
			isPressed = 1;
			pressDepth = (this.explorerStateFlags & 4096) === 0 ? this.playerStep : 0;
		}
		if (isPressed === 0 || pressDepth >= 12) {
			this.closeDoorById(doorId);
			return;
		}
		this.unlockDoorLock(doorId);
	}

	updateExplosion() {
		let explosionSprites = null, row = 0, animLength = 0, col = 0, x = 0, dy = 0, frame = 0, y = 0, dx = 0, s0, s1, s2;
		col = this.updateCellCol;
		row = this.updateCellRow;
		frame = Game.cellStates[col][row];
		explosionSprites = Game.spritePacks[7];
		frame++;
		animLength = Game.getAnimDuration(explosionSprites, 0);
		if (frame < animLength) {
			if (frame !== 1) {
				if (frame === animLength >> 1) {
					for (dy = -1; dy < 2; dy++) {
						for (dx = -1; dx < 2; dx++) {
							x = col + dx | 0;
							y = row + dy | 0;
							switch (Game.cellTypes[x][y]) {
								case 16:
								case 19:
								case 43:
								case 49:
									Game.cellTypes[x][y] = -1;
									this.killEnemyAt(x, y);
									Game.cellUpdateTimers[x][y] = 24;
									break;
								case 10:
									if (this.liquidState === 3) {
										s0 = Game.cellStates[x];
										s1 = y;
										s2 = 1;
										s0[s1] = s2;
										Game.wakeCellsAround(x, y);
									}
									break;
								case 30:
								case 37:
									s0 = Game.cellStates[x];
									s1 = y;
									s2 = 1;
									s0[s1] = s2;
									Game.wakeCellsAround(x, y);
									break;
								case 8:
									Game.cellTypes[x][y] = 54;
									s0 = Game.cellStates[x];
									s1 = y;
									s2 = 0;
									s0[s1] = s2;
									Game.wakeCellsAround(x, y);
									break;
								default:
									break;
							}
							if (this.isPlayerAt(x, y)) {
								this.damageExplorer(1, 64, 0);
							}
						}
					}
				}
			} else {
				this.playSound(7);
				Game.wakeCellsAround(col, row);
			}
			Game.cellStates[col][row] = frame;
			Game.cellUpdateTimers[col][row] = 24;
			return;
		}
		Game.cellTypes[col][row] = -1;
		Game.wakeCellsAround(col, row);
	}

	updateTorch() {
		let row = 0, col = 0;
		col = this.updateCellCol;
		row = this.updateCellRow;
		if (Game.cellStates[col][row] !== 0) {
			if (this.isPlayerAt(col, row - 1 | 0)) {
				this.damageExplorer(1, 64, 0);
			}
		} else {
			if (Game.cellTypes[col][row - 1] === 11) {
				Game.cellStates[col][row] = 1;
				this.progressGateObjective();
				return;
			}
		}
	}

	triggerGateChallenge() {
		if (this.playerStep <= 6 && this.isPlayerAt(this.updateCellCol, this.updateCellRow)) {
			Game.keys = 0;
			this.requestedMoveDir = 0;
			Game.activeGateId = Game.cellObjects[this.updateCellCol][this.updateCellRow] >> 8;
			this.closeDoorAt(this.playerCol + Game.dirDeltas[this.explorerStateFlags & 7] | 0, this.playerRow);
			if (Game.activeGateId < 0 || Game.activeGateId >= Game.gateRemainingCounts.length) {
				Game.activeGateId = -1;
			} else {
				this.playSound(1);
				this.gateRevealState = 1;
				this.setGatePanTarget(Game.activeGateId);
			}
			Game.cellObjects[this.updateCellCol][this.updateCellRow] = -1;
		}
	}

	updateFlameJetTrap(trapType, flameLength) {
		let row = 0, i = 0, flameCol = 0, col = 0, dirSign = 0;
		col = this.updateCellCol;
		row = this.updateCellRow;
		dirSign = trapType !== 23 ? 1 : -1;
		Game.cellUpdateTimers[col][row] = 24;
		if (this.playerRow === row) {
			for (i = 0; i <= flameLength; i++) {
				flameCol = col + Math.imul(i, dirSign) | 0;
				if (this.playerCol === flameCol) {
					this.damageExplorer(1, 64, 0);
				}
			}
		}
	}

	finishItemPickup() {
		let rememberPickupCell = 0, playRaiseAnim = 0, effectType = 0, s1, t1, t2, t3;
		playRaiseAnim = 0;
		effectType = -1;
		rememberPickupCell = 0;
		switch (this.pickedItemType) {
			case 51:
			case 52:
			case 53:
				this.markCollectibleTaken(this.world, this.stage, this.playerCol, this.playerRow);
				effectType = 0;
				playRaiseAnim = 1;
				this.resetCounters();
				this.gotElementalDiamond = 1;
				if (this.pickedItemType !== 53) {
					if (this.pickedItemType !== 51) {
						s1 = 2;
					} else {
						s1 = 1;
					}
				} else {
					s1 = 0;
				}
				this.placingElementalIndex = s1;
				t3 = Game.saveData;
				t3[2] = (t3[2] | 1 << this.placingElementalIndex) << 24 >> 24;
				this.writeSaveRecord();
				break;
			case 42:
				rememberPickupCell = 1;
				playRaiseAnim = 1;
				this.hasCompass = 1;
				this.pendingCutsceneId = 11;
				break;
			case 41:
				if (this.isBossStage()) {
					this.bossTreasureTaken = 1;
					this.resetCounters();
				}
				this.diamondCount = this.diamondCount + this.heldItemAmount | 0;
				this.diamondsToOpenExit = this.diamondsToOpenExit - this.heldItemAmount | 0;
				if (this.diamondsToOpenExit <= 0 && !this.isBossStage()) {
					Game.cellTypes[this.exitDoorCol][this.exitDoorRow] = -1;
					this.diamondsToOpenExit = 0;
				}
				effectType = 3;
				break;
			case 40:
				rememberPickupCell = 1;
				playRaiseAnim = 1;
				this.pendingCutsceneId = 24;
				break;
			case 27:
				rememberPickupCell = 1;
				playRaiseAnim = 1;
				this.pendingCutsceneId = 23;
				break;
			case 26:
				playRaiseAnim = 1;
				this.pendingCutsceneId = 25;
				rememberPickupCell = 1;
				break;
			case 24:
				rememberPickupCell = 1;
				playRaiseAnim = 1;
				this.pendingCutsceneId = 22;
				break;
			case 7:
				this.setExplorerEnergy(127);
				effectType = 4;
				break;
			case 6:
				this.lives = this.lives + 1 | 0;
				Game.checkpointCellTypes[this.playerCol][this.playerRow] = -1;
				t1 = Game.checkpointCellObjects[this.playerCol];
				t2 = this.playerRow;
				t1[t2] = t1[t2] | 256;
				effectType = 0;
				this.markCollectibleTaken(this.world, this.stage, this.playerCol, this.playerRow);
				break;
			case 5:
				this.silverKeys = this.silverKeys + 1 | 0;
				effectType = 1;
				break;
			case 4:
				effectType = 2;
				this.goldKeys = this.goldKeys + 1 | 0;
				break;
			case 2:
				this.redDiamondCount = this.redDiamondCount + 1 | 0;
				rememberPickupCell = 1;
				effectType = 0;
				break;
			default:
				break;
		}
		if (playRaiseAnim !== 0) {
			this.setExplorerAnim(47);
		}
		if (effectType !== -1) {
			this.spawnCellEffect(this.playerCol, this.playerRow - 1 | 0, effectType);
		}
		if (rememberPickupCell !== 0) {
			Game.redDiamondPickCells[this.redDiamondPickCount << 1] = this.playerCol << 24 >> 24;
			Game.redDiamondPickCells[(this.redDiamondPickCount << 1) + 1] = this.playerRow << 24 >> 24;
			this.redDiamondPickCount = this.redDiamondPickCount + 1 | 0;
		}
		this.requestHudRedraw();
		this.pickedItemType = -1;
	}

	startItemPickup(itemType) {
		let cellObject = 0, row = 0, col = 0, s1;
		col = this.updateCellCol;
		row = this.updateCellRow;
		if (this.playerStep > 0 || !this.isPlayerAt(col, row)) {
			return;
		}
		cellObject = Game.cellObjects[col][row] & 255;
		if ((cellObject === 14 || cellObject === 33) && Game.cellObjects[col][row] >> 8 === 255) {
			return;
		}
		this.pickedItemType = itemType;
		switch (itemType) {
			case 53:
				this.heldItemImageSet = 32;
				s1 = 0;
				this.heldItemFrame = s1;
				break;
			case 52:
				this.heldItemImageSet = 31;
				s1 = 0;
				this.heldItemFrame = s1;
				break;
			case 51:
				this.heldItemImageSet = 30;
				s1 = 0;
				this.heldItemFrame = s1;
				break;
			case 42:
				this.heldItemImageSet = 29;
				s1 = 0;
				this.heldItemFrame = s1;
				break;
			case 41:
				this.heldItemImageSet = 2;
				this.heldItemFrame = 0;
				this.heldItemAmount = Game.cellStates[this.updateCellCol][this.updateCellRow];
				break;
			case 40:
				this.heldItemImageSet = 19;
				this.heldItemFrame = 0;
				Game.cellTypes[this.updateCellCol][this.updateCellRow] = -1;
				this.pickedItemType = 40;
				Game.saveData[10] = 1;
				break;
			case 7:
				B4: {
					if (this.explorerEnergy !== Game.saveData[8]) {
						this.heldItemImageSet = 5;
						s1 = 1;
						this.heldItemFrame = s1;
						break B4;
					}
					Game.cellTypes[col][row] = 41;
					Game.cellStates[col][row] = 10;
					this.diamondsInStage = this.diamondsInStage + 10 | 0;
					this.startItemPickup(41);
				}
				break;
			case 6:
				B5: {
					if (this.lives >= 99) {
						Game.cellTypes[col][row] = 7;
						Game.cellStates[col][row] = 0;
						this.startItemPickup(7);
					} else {
						this.heldItemImageSet = 5;
						s1 = 0;
						this.heldItemFrame = s1;
						break B5;
					}
				}
				break;
			case 5:
				this.heldItemImageSet = 25;
				s1 = 0;
				this.heldItemFrame = s1;
				break;
			case 4:
				this.heldItemImageSet = 24;
				s1 = 0;
				this.heldItemFrame = s1;
				break;
			case 2:
				this.heldItemImageSet = 3;
				s1 = 0;
				this.heldItemFrame = s1;
				break;
			default:
				break;
		}
		Game.cellTypes[col][row] = -1;
		this.requestHudRedraw();
	}

	isBlockedByExtendingTrap(col, row) {
		if (Game.cellTypes[col][row] === 28 || this.pistonSlowExtent >= 24 && (Game.cellTypes[col][row - 1] === 28 && (Game.cellStates[col][row - 1] & 8) === 0 || Game.cellTypes[col][row + 1] === 28 && (Game.cellStates[col][row + 1] & 8) === 0) || this.pistonFastExtent >= 24 && (Game.cellTypes[col][row - 1] === 28 || Game.cellTypes[col][row + 1] === 28)) {
			return 1;
		}
		return 0;
	}

	chooseDirectionToward(fromCol, fromRow, toCol, toRow, avoidBlockedVertical) {
		let absDx = 0, nextRow = 0, dy = 0, absDy = 0, dir = 0, dx = 0, s0;
		dx = fromCol - toCol | 0;
		dy = fromRow - toRow | 0;
		absDx = dx <= 0 ? -dx | 0 : dx;
		absDy = dy <= 0 ? -dy | 0 : dy;
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
			if (dir !== 0 && (!Game.isCellFreeForEnemy(fromCol - Game.dirDeltas[dir] | 0, fromRow) || this.isBlockedByExtendingTrap(fromCol - Game.dirDeltas[dir] | 0, fromRow))) {
				dir = 0;
			}
		}
		if (dir === 0) {
			B6: {
				if (dy > 0) {
					s0 = 1;
					dir = s0;
					break B6;
				}
				if (dy < 0) {
					s0 = 3;
					dir = s0;
				}
			}
			nextRow = fromRow - Game.dirDeltas[8 + dir] | 0;
			if (avoidBlockedVertical !== 0 && dir !== 0 && (!Game.isCellFreeForEnemy(fromCol, nextRow) || this.hasWaterLayer && Game.liquidCells[fromCol][nextRow] !== 0 || this.isBlockedByExtendingTrap(fromCol, nextRow))) {
				dir = 0;
				B9: {
					if (dx > 0) {
						s0 = 4;
						dir = s0;
						break B9;
					}
					if (dx < 0) {
						s0 = 2;
						dir = s0;
					}
				}
				if (dir !== 0 && Game.cellTypes[fromCol - Game.dirDeltas[dir]][fromRow] >= 0) {
					dir = 0;
				}
			}
		}
		return dir;
	}

	updateWalkingEnemy(enemyType) {
		let row = 0, stepY = 0, moveOffset = 0, dirOrTargetCol = 0, targetRow = 0, col = 0, isInBubble = 0, pathDir = 0, isChasing = 0, state = 0, dir = 0, stepX = 0, s0, s1, s2;
		col = this.updateCellCol;
		row = this.updateCellRow;
		state = Game.cellStates[col][row];
		moveOffset = Game.cellMoveOffsets[col][row];
		stepX = 0;
		stepY = 0;
		s0 = (Game.cellObjects[col][row] & 255) !== 35 ? 0 : 1;
		isInBubble = s0;
		s0 = enemyType !== 43 || (state & 3840) === 0 ? 0 : 1;
		isChasing = s0;
		if (isInBubble !== 0 || !this.isCellCrushed(col, row)) {
			dir = state & 7;
			if (moveOffset > 0) {
				if (moveOffset < 0) {
					Game.cellMoveOffsets[col][row] = 0;
				}
				moveOffset = moveOffset - 3 << 24 >> 24;
				s0 = Game.cellMoveOffsets[col];
				s1 = row;
				s2 = moveOffset;
				s0[s1] = s2;
			} else {
				if (isInBubble === 0 || moveOffset > 6) {
					Game.wakeCellsAround(col, row);
					if (isChasing === 0) {
						if ((state & 16646144) === 0 || (state & 248) !== 0) {
							if (dir !== 0) {
								moveOffset = 21;
								stepX = -Game.dirDeltas[dir] | 0;
								stepY = -Game.dirDeltas[dir + 8] | 0;
								if (!Game.isCellFreeForEnemy(col + stepX | 0, row + stepY | 0)) {
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
								stepX = -Game.dirDeltas[dirOrTargetCol] | 0;
								stepY = -Game.dirDeltas[dirOrTargetCol + 8] | 0;
								if (!Game.isCellFreeForEnemy(col + stepX | 0, row + stepY | 0)) {
									stepY = 0;
									stepX = stepY;
									moveOffset = 0;
								}
							}
						} else {
							dirOrTargetCol = (state & 16646144) >> 17;
							targetRow = (state & 2130706432) >> 24;
							if (col !== dirOrTargetCol || row !== targetRow) {
								moveOffset = 21;
								pathDir = this.chooseDirectionToward(col, row, dirOrTargetCol, targetRow, 1);
								state = state & -8 | pathDir;
								stepX = -Game.dirDeltas[pathDir] | 0;
								stepY = -Game.dirDeltas[pathDir + 8] | 0;
								dir = pathDir;
								if (pathDir === 0) {
									moveOffset = 0;
									stepY = 0;
									stepX = stepY;
								}
							} else {
								state = state & -16646145;
								dir = (state & -2147483648) !== 0 ? 1 : 2;
								state = state & -8 | dir;
							}
						}
					} else {
						moveOffset = 18;
						dirOrTargetCol = this.chooseDirectionToward(col, row, this.playerCol, this.playerRow, 1);
						state = state & -8 | dirOrTargetCol;
						dir = dirOrTargetCol;
						stepX = -Game.dirDeltas[dirOrTargetCol] | 0;
						stepY = -Game.dirDeltas[dirOrTargetCol + 8] | 0;
						if (dirOrTargetCol === 0) {
							moveOffset = 0;
							stepY = 0;
							stepX = stepY;
						}
						state = state - 256 | 0;
					}
				} else {
					if (moveOffset < 0) {
						Game.cellMoveOffsets[col][row] = 0;
					}
				}
				B17: {
					if ((state & 248) !== 0) {
						if ((Game.frameCount & 3) === 0) {
							state = state & -249 | (state & 248) - 8;
							if (enemyType === 43 && (state & 248) === 0) {
								state = state & -3841 | 3072;
							}
						}
						s0 = Game.cellMoveOffsets[col];
						s1 = row;
						s2 = 0;
						s0[s1] = s2;
						break B17;
					}
					Game.cellTypes[col][row] = -1;
					Game.cellTypes[col + stepX][row + stepY] = enemyType;
					Game.cellUpdateTimers[col + stepX][row + stepY] = 48;
					Game.cellMoveOffsets[col + stepX][row + stepY] = moveOffset;
					Game.cellStates[col + stepX][row + stepY] = state;
				}
			}
			if ((state & 248) === 0 && (Game.actors[0].animIndex < 13 || Game.actors[0].animIndex > 16) && Game.doMovingCellsTouch(col, row, dir, Game.cellMoveOffsets[col][row], this.playerCol, this.playerRow, (this.explorerStateFlags & 4096) !== 0 ? 0 : this.currentMoveDir, this.playerStep)) {
				this.damageExplorer(1, 48, dir);
				if (isChasing !== 0) {
					state = state & -3841;
				}
			}
			Game.cellStates[col][row] = state;
			return;
		}
		Game.cellTypes[col][row] = -1;
		this.killEnemyAt(col, row);
	}

	animateEnemyDeathPuff() {
		let frame = 0, s0, s1, s2;
		frame = (Game.cellObjects[this.updateCellCol][this.updateCellRow] & -268435456) >> 28;
		if (frame === 0) {
			this.playSound(10);
		}
		if ((Game.frameCount & 1) === 0) {
			frame++;
		}
		if (frame < Game.spritePacks[13].getAnimFrameCount(0)) {
			s0 = Game.cellObjects[this.updateCellCol];
			s1 = this.updateCellRow;
			s2 = Game.cellObjects[this.updateCellCol][this.updateCellRow] & 268435455 | frame << 28;
		} else {
			s0 = Game.cellObjects[this.updateCellCol];
			s1 = this.updateCellRow;
			s2 = Game.cellObjects[this.updateCellCol][this.updateCellRow] & 268435455;
		}
		s0[s1] = s2;
		Game.wakeCellsAround(this.updateCellCol, this.updateCellRow);
	}

	progressGateObjective() {
		let t1, t2;
		if ((this.specialStageType === 3 || this.specialStageType === 4 || this.specialStageType === 5) && this.bossHealth > 0) {
			return;
		}
		if (Game.activeGateId >= 0) {
			t1 = Game.gateRemainingCounts;
			t2 = Game.activeGateId;
			t1[t2] = t1[t2] - 1 << 24 >> 24;
			if (Game.gateRemainingCounts[Game.activeGateId] === 0) {
				this.openGateById(Game.activeGateId);
			}
		}
	}

	takeRelicFromChest(relicType) {
		let s1;
		if ((Game.cellObjects[this.updateCellCol][this.updateCellRow] & 255) !== 14 || Game.cellObjects[this.updateCellCol][this.updateCellRow] >> 8 !== 255) {
			if (this.isPlayerAt(this.updateCellCol, this.updateCellRow) && (Game.actors[0].animIndex === 40 || Game.actors[0].animIndex === 48)) {
				Game.cellTypes[this.updateCellCol][this.updateCellRow] = -1;
				switch (relicType) {
					case 27:
						Game.saveData[9] = 2;
						this.heldItemImageSet = 7;
						this.heldItemFrame = 1;
						s1 = 27;
						this.pickedItemType = s1;
						break;
					case 26:
						Game.saveData[9] = 8;
						this.heldItemImageSet = 7;
						this.heldItemFrame = 2;
						s1 = 26;
						this.pickedItemType = s1;
						break;
					case 24:
						Game.saveData[9] = 1;
						this.heldItemImageSet = 7;
						this.heldItemFrame = 0;
						s1 = 24;
						this.pickedItemType = s1;
						break;
					default:
						break;
				}
				this.markCollectibleTaken(this.world, this.stage, this.updateCellCol, this.updateCellRow);
			}
			return;
		}
	}

	updateCrumblingWall() {
		let row = 0, crumbleStep = 0, col = 0, dy = 0, dir = 0, dx = 0, t2, t3;
		crumbleStep = Game.cellStates[this.updateCellCol][this.updateCellRow];
		if (crumbleStep > 0) {
			col = this.updateCellCol;
			row = this.updateCellRow;
			if (crumbleStep !== 4) {
				if (crumbleStep >= 16) {
					Game.cellTypes[col][row] = -1;
					Game.wakeCellsAround(col, row);
				}
			} else {
				for (dir = 1; dir < 5; dir++) {
					dx = Game.dirDeltas[dir];
					dy = Game.dirDeltas[dir + 8];
					if (Game.cellTypes[col + dx][row + dy] === 30) {
						t2 = Game.cellStates[col + dx];
						t3 = row + dy | 0;
						t2[t3] = t2[t3] + 1;
						Game.cellUpdateTimers[col + dx][row + dy] = 24;
					}
				}
			}
			Game.cellStates[col][row] = crumbleStep + 1;
			Game.cellUpdateTimers[col][row] = 24;
		}
	}

	updateCrackingWall() {
		let row = 0, col = 0, crackStep = 0;
		col = this.updateCellCol;
		row = this.updateCellRow;
		crackStep = Game.cellStates[col][row];
		if (crackStep > 0) {
			if (crackStep >= 8) {
				this.checkLiquidBreachAt(col, row);
				Game.cellTypes[col][row] = -1;
				Game.wakeCellsAround(col, row);
			}
			Game.cellStates[col][row] = crackStep + 1;
			Game.cellUpdateTimers[col][row] = 24;
		}
	}

	updateCrawlingFlame() {
		let isCounterClockwise = 0, row = 0, forwardDy = 0, dyingStep = 0, sideDy = 0, sideDx = 0, col = 0, blockedTurnDir = 0, sideTurnDir = 0, forwardDx = 0, state = 0, dir = 0, s0, s1, s2, s3, t5;
		col = this.updateCellCol;
		row = this.updateCellRow;
		dyingStep = (Game.cellStates[col][row] & 3840) >> 8;
		if (dyingStep === 0) {
			if (Game.liquidCells === null || Game.liquidCells[col][row] === 0) {
				if (Game.cellMoveOffsets[col][row] <= 4) {
					state = Game.cellStates[col][row];
					Game.cellUpdateTimers[col][row] = 24;
					isCounterClockwise = (state & 16) !== 0 ? 1 : 0;
					dir = state & 7;
					if (dir === 0) {
						if (Game.cellTypes[col - 1][row] < 0) {
							if (Game.cellTypes[col][row + 1] >= 0) {
								s0 = Game.cellStates[col];
								s1 = row;
								s2 = state & -8 | (isCounterClockwise === 0 ? 4 : 2);
								s0[s1] = s2;
							}
						} else {
							s0 = Game.cellStates[col];
							s1 = row;
							s2 = state & -8 | (isCounterClockwise === 0 ? 3 : 1);
							s0[s1] = s2;
						}
						if (Game.cellTypes[col + 1][row] >= 0) {
							Game.cellStates[col][row] = state & -8 | (isCounterClockwise === 0 ? 1 : 3);
						}
						if (Game.cellTypes[col][row + 1] >= 0) {
							s0 = Game.cellStates[col];
							s1 = row;
							s2 = state & -8;
							s3 = isCounterClockwise === 0 ? 2 : 4;
							s0[s1] = s2 | s3;
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
								sideDy = isCounterClockwise === 0 ? -1 : 1;
								sideTurnDir = isCounterClockwise === 0 ? 1 : 3;
								blockedTurnDir = isCounterClockwise === 0 ? 3 : 1;
								s0 = -1;
								forwardDx = s0;
								break;
							case 3:
								sideDx = isCounterClockwise === 0 ? -1 : 1;
								sideTurnDir = isCounterClockwise === 0 ? 4 : 2;
								blockedTurnDir = isCounterClockwise === 0 ? 2 : 4;
								forwardDy = 1;
								break;
							case 2:
								sideDy = isCounterClockwise === 0 ? 1 : -1;
								sideTurnDir = isCounterClockwise === 0 ? 3 : 1;
								blockedTurnDir = isCounterClockwise === 0 ? 1 : 3;
								s0 = 1;
								forwardDx = s0;
								break;
							case 1:
								sideDx = isCounterClockwise === 0 ? 1 : -1;
								sideTurnDir = isCounterClockwise === 0 ? 2 : 4;
								blockedTurnDir = isCounterClockwise === 0 ? 4 : 2;
								forwardDy = -1;
								break;
							default:
								break;
						}
						if (!Game.isCellFreeForEnemy(col + forwardDx | 0, row + forwardDy | 0) || !Game.isCellFreeForEnemy(col + sideDx | 0, row + sideDy | 0) || !Game.isCellFreeForEnemy(col + sideDx - forwardDx | 0, row + sideDy - forwardDy | 0)) {
							if (!Game.isCellFreeForEnemy(col + sideDx | 0, row + sideDy | 0)) {
								B13: {
									if (!Game.isCellFreeForEnemy(col + forwardDx | 0, row + forwardDy | 0)) {
										s0 = Game.cellStates[col];
										s1 = row;
										s2 = state & -8;
										s3 = blockedTurnDir;
										s0[s1] = s2 | s3;
										break B13;
									}
									if (Game.cellMoveOffsets[col][row] <= 0) {
										Game.cellStates[col + forwardDx][row + forwardDy] = state;
										Game.cellTypes[col + forwardDx][row + forwardDy] = 11;
										Game.cellTypes[col][row] = -1;
										Game.cellMoveOffsets[col + forwardDx][row + forwardDy] = 18;
									}
								}
							} else {
								Game.cellStates[col + sideDx][row + sideDy] = state & -8 | sideTurnDir;
								Game.cellTypes[col + sideDx][row + sideDy] = 11;
								Game.cellTypes[col][row] = -1;
								Game.cellMoveOffsets[col + sideDx][row + sideDy] = 18;
							}
						} else {
							if (Game.cellMoveOffsets[col][row] <= 0) {
								Game.cellStates[col + forwardDx][row + forwardDy] = state;
								Game.cellTypes[col + forwardDx][row + forwardDy] = 11;
								Game.cellTypes[col][row] = -1;
								Game.cellMoveOffsets[col + forwardDx][row + forwardDy] = 18;
							}
						}
					}
					Game.wakeCellsAround(col, row);
				}
			} else {
				Game.cellStates[col][row] = Game.cellStates[col][row] & -3841 | 256;
			}
		} else {
			if (dyingStep < 4) {
				if ((Game.frameCount >> 1 & 1) === 0) {
					Game.cellStates[col][row] = Game.cellStates[col][row] + 256;
				}
			} else {
				Game.cellTypes[col][row] = -1;
			}
		}
		if (this.isPlayerAt(col, row)) {
			this.damageExplorer(1, 64, 0);
		}
		if (Game.cellMoveOffsets[col][row] > 0) {
			t5 = Game.cellMoveOffsets[col];
			t5[row] = t5[row] - 5 << 24 >> 24;
		}
	}

	updateFragileWall() {
		let row = 0, col = 0, hitState = 0;
		col = this.updateCellCol;
		row = this.updateCellRow;
		hitState = Game.cellStates[col][row];
		if (hitState > 0) {
			Game.cellTypes[col][row] = -1;
			Game.cellObjects[col][row] = 32;
			Game.wakeCellsAround(col, row);
			this.checkLiquidBreachAt(col, row);
			Game.cellUpdateTimers[col][row] = 24;
		}
	}

	updateExtendingRod() {
		let pushBack = 0, aheadType = 0, row = 0, lengthLeft = 0, retract = 0, aheadObject = 0, col = 0, state = 0, dirX = 0, aheadState = 0, s0, s1, s2, t3, t4;
		col = this.updateCellCol;
		row = this.updateCellRow;
		Game.cellUpdateTimers[col][row] = 24;
		if (Game.cellMoveOffsets[col][row] !== 0) {
			t4 = Game.cellMoveOffsets[col];
			s0 = t4;
			s1 = row;
			s2 = t4[row] - 6 << 24 >> 24;
		} else {
			state = Game.cellStates[col][row];
			dirX = (state & 1) !== 0 ? 1 : -1;
			aheadType = Game.cellTypes[col + dirX][row];
			aheadObject = Game.cellObjects[col + dirX][row] & 255;
			retract = 0;
			lengthLeft = state >> 1;
			if (lengthLeft <= 0) {
				retract = 1;
			} else {
				if (aheadType >= 0 || aheadObject === 14 || aheadObject === 33) {
					if (aheadType !== 32) {
						aheadState = Game.cellStates[col + dirX][row];
						pushBack = 0;
						if (aheadType !== 48 || (aheadState & 8) === 0) {
							switch (aheadType) {
								default:
									if (aheadType !== -1) {
										retract = 1;
									}
									break;
								case 1:
								case 2:
								case 4:
								case 5:
								case 6:
								case 7:
									pushBack = -dirX | 0;
									this.playSound(12);
									this.slidingObjSubStep = 0;
									this.slideCellsLeft = this.playerCol - (col + dirX) + pushBack | 0;
									this.slidingObjCol = col + dirX | 0;
									this.slidingObjRow = row;
									if (this.slidingObjSavedParams === -1) {
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
										this.slidingObjSavedParams = aheadState;
									}
									if (this.slideCellsLeft >= 0) {
										this.slidingObjParams = aheadState & -8 | 2;
									} else {
										this.slidingObjParams = aheadState & -8 | 4;
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
									this.playSound(12);
									this.slidingObjSubStep = 0;
									this.slideCellsLeft = this.playerCol - (col + dirX) + pushBack | 0;
									this.slidingObjCol = col + dirX | 0;
									this.slidingObjRow = row;
									if (this.slidingObjSavedParams === -1) {
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
										this.slidingObjSavedParams = aheadState;
									}
									if (this.slideCellsLeft >= 0) {
										this.slidingObjParams = aheadState & -8 | 2;
									} else {
										this.slidingObjParams = aheadState & -8 | 4;
									}
									break;
							}
						}
					}
				} else {
					Game.cellStates[col + dirX][row] = lengthLeft - 1 << 1 | state & 1;
					Game.cellUpdateTimers[col + dirX][row] = 30;
					Game.cellMoveOffsets[col + dirX][row] = 18;
					aheadType = 32;
				}
			}
			if (retract !== 0) {
				for (aheadState = 1; aheadState <= 3; aheadState++) {
					if (Game.cellTypes[this.playerCol + Math.imul(dirX, aheadState)][this.playerRow] === 32) {
						Game.cellTypes[this.playerCol + Math.imul(dirX, aheadState)][this.playerRow] = -1;
					}
				}
			}
			s0 = Game.cellTypes[col + dirX];
			s1 = row;
			s2 = aheadType;
		}
		s0[s1] = s2;
		Game.wakeCellsAround(col, row);
	}

	updateProjectile() {
		let otherDir = 0, row = 0, pushRow = 0, pushCol = 0, nextCol = 0, ownState = 0, col = 0, nextRow = 0, startOffset = 0, dir = 0, s0, s1, s2, t1, t2, t3;
		col = this.updateCellCol;
		row = this.updateCellRow;
		dir = Game.cellStates[col][row] & 7;
		if ((Game.cellStates[col][row] & 8) === 0) {
			if (this.isPlayerAt(col, row) || this.isPlayerAt(col + Game.dirDeltas[dir] | 0, row + Game.dirDeltas[8 + dir] | 0) && Game.cellMoveOffsets[col][row] <= this.playerStep) {
				this.damageExplorer(1, 48, 0);
			}
			if (Game.cellMoveOffsets[col][row] > 0) {
				t3 = Game.cellMoveOffsets[col];
				s0 = t3;
				s1 = row;
				s2 = t3[row] - 12 << 24 >> 24;
			} else {
				nextCol = col - Game.dirDeltas[dir] | 0;
				nextRow = row - Game.dirDeltas[dir + 8] | 0;
				startOffset = 24;
				if (dir === 4) {
					startOffset = 12;
				}
				if (Game.cellTypes[nextCol][nextRow] >= 0) {
					if (Game.cellTypes[nextCol][nextRow] !== 21) {
						switch (Game.cellTypes[nextCol][nextRow]) {
							case 19:
							case 43:
							case 45:
							case 46:
								Game.cellTypes[nextCol][nextRow] = -1;
								this.killEnemyAt(nextCol, nextRow);
								break;
							case 10:
							case 30:
								if (Game.cellStates[nextCol][nextRow] < 1) {
									Game.cellStates[nextCol][nextRow] = 1;
								}
								break;
							default:
								break;
						}
						t2 = Game.cellStates[col];
						t2[row] = t2[row] | 8;
						s0 = Game.cellMoveOffsets[col];
						s1 = row;
						s2 = 0;
					} else {
						otherDir = Game.cellStates[nextCol][nextRow] & 7;
						pushCol = nextCol - Game.dirDeltas[otherDir] | 0;
						pushRow = nextRow - Game.dirDeltas[otherDir + 8] | 0;
						Game.cellTypes[col][row] = -1;
						Game.wakeCellsAround(col, row);
						ownState = Game.cellStates[col][row];
						if (Game.cellTypes[pushCol][pushRow] < 0) {
							Game.cellTypes[pushCol][pushRow] = 21;
							Game.cellStates[pushCol][pushRow] = Game.cellStates[nextCol][nextRow];
							Game.cellMoveOffsets[pushCol][pushRow] = 18;
						}
						Game.cellTypes[nextCol][nextRow] = 21;
						Game.cellStates[nextCol][nextRow] = ownState;
						s0 = Game.cellMoveOffsets[nextCol];
						s1 = nextRow;
						s2 = 18;
					}
				} else {
					Game.cellTypes[nextCol][nextRow] = 21;
					Game.cellStates[nextCol][nextRow] = Game.cellStates[col][row];
					Game.cellMoveOffsets[nextCol][nextRow] = startOffset;
					s0 = Game.cellTypes[col];
					s1 = row;
					s2 = -1;
				}
				s0[s1] = s2;
				s0 = Game.cellUpdateTimers[nextCol];
				s1 = nextRow;
				s2 = 48;
			}
			s0[s1] = s2;
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
		if (Game.cellMoveOffsets[col][row] >= Game.getAnimDuration(Game.spritePacks[29], nextCol) || (Game.cellObjects[this.updateCellCol][this.updateCellRow] & 255) === 35) {
			Game.cellTypes[col][row] = -1;
			Game.wakeCellsAround(col, row);
		} else {
			t1 = Game.cellMoveOffsets[col];
			t1[row] = t1[row] + 1 << 24 >> 24;
		}
		Game.cellUpdateTimers[col][row] = 24;
	}

	killEnemyAt(col, row) {
		Game.cellObjects[col][row] = Game.cellObjects[col][row] & 268435455 | 268435456;
		this.progressGateObjective();
	}

	updateSideRoller() {
		let row = 0, moveOffset = 0, col = 0, newRow = 0, newCol = 0, waitTimer = 0, state = 0, dir = 0, s0, s1, s2;
		col = this.updateCellCol;
		row = this.updateCellRow;
		state = Game.cellStates[col][row];
		waitTimer = (state & 65280) >> 8;
		dir = (state & 8) === 0 ? 2 : 4;
		if (waitTimer < 20) {
			B2: {
				if (waitTimer > 0) {
					Game.cellStates[col][row] = state & -65281 | waitTimer - 1 << 8;
					s0 = Game.cellUpdateTimers[col];
					s1 = row;
					s2 = 24;
					s0[s1] = s2;
					break B2;
				}
				moveOffset = Game.cellMoveOffsets[col][row];
				if (moveOffset > 0) {
					s0 = Game.cellMoveOffsets[col];
					s1 = row;
					s2 = moveOffset - 6 << 24 >> 24;
					s0[s1] = s2;
				} else {
					newCol = col;
					newRow = row;
					if (!Game.isCellFreeForEnemy(col, row + 1 | 0)) {
						if (dir !== 4) {
							if (!Game.isCellFreeForEnemy(col + 1 | 0, row)) {
								dir = 0;
								if (Game.cellTypes[col + 1][row] !== 16 && Game.cellTypes[col + 1][row] !== 19 && Game.cellTypes[col + 1][row] !== 43) {
									state = state & -65281 | 5120;
								}
							} else {
								newCol = col + 1 | 0;
							}
						} else {
							if (!Game.isCellFreeForEnemy(col - 1 | 0, row)) {
								dir = 0;
								if (Game.cellTypes[col - 1][row] !== 16 && Game.cellTypes[col - 1][row] !== 19 && Game.cellTypes[col - 1][row] !== 43) {
									state = state & -65281 | 5120;
								}
							} else {
								newCol = col - 1 | 0;
							}
						}
					} else {
						newRow = row + 1 | 0;
						dir = 3;
					}
					if (newCol !== col || newRow !== row) {
						Game.cellTypes[newCol][newRow] = 14;
						Game.wakeCellsAround(newCol, newRow);
						Game.cellTypes[col][row] = -1;
						Game.cellMoveOffsets[newCol][newRow] = 18;
					}
					Game.cellStates[newCol][newRow] = state & -8 | dir;
				}
			}
		} else {
			if (Game.isCellFreeForEnemy(col, row + 1 | 0) || dir === 4 && (Game.cellTypes[col - 1][row] < 0 || Game.cellTypes[col - 1][row] === 16 || Game.cellTypes[col - 1][row] === 19 || Game.cellTypes[col - 1][row] === 43) || dir === 2 && (Game.cellTypes[col + 1][row] < 0 || Game.cellTypes[col + 1][row] === 16 || Game.cellTypes[col + 1][row] === 19 || Game.cellTypes[col + 1][row] === 43)) {
				Game.cellStates[col][row] = state & -65281 | 4864;
			}
		}
		if (this.isPlayerAt(col, row)) {
			this.damageExplorer(1, 48, dir);
		}
	}

	updateTallStrikerEnemy() {
		let row = 0, attackTimer = 0, explorerInFront = 0, facingDir = 0, col = 0, upperHalfDy = 0, lowerHalfDy = 0, state = 0, s0;
		col = this.updateCellCol;
		row = this.updateCellRow;
		if (Game.cellTypes[col][row + 1] === 16) {
			lowerHalfDy = 1;
			s0 = 0;
		} else {
			lowerHalfDy = 0;
			s0 = -1;
		}
		upperHalfDy = s0;
		attackTimer = Game.cellMoveOffsets[col][row + lowerHalfDy];
		state = Game.cellStates[col][row + lowerHalfDy];
		s0 = (state & 7) !== 4 ? 2 : 4;
		facingDir = s0;
		s0 = this.isPlayerAt(col - Game.dirDeltas[facingDir] | 0, row + lowerHalfDy | 0) || this.isPlayerAt(col - Game.dirDeltas[facingDir] | 0, row + upperHalfDy | 0) ? 1 : 0;
		explorerInFront = s0;
		if (attackTimer > 0 || explorerInFront === 0 || this.playerStep > 12) {
			if (attackTimer > 0) {
				if (lowerHalfDy === 0) {
					attackTimer = attackTimer - 1 << 24 >> 24;
				}
				if ((attackTimer === 11 || lowerHalfDy === 0 && attackTimer < 11) && explorerInFront !== 0) {
					this.damageExplorer(1, 48, state & 7);
				}
				Game.cellUpdateTimers[col][row] = 24;
			}
		} else {
			attackTimer = 36;
		}
		if (!this.isCellCrushed(col, row)) {
			Game.cellStates[col][row + upperHalfDy] = state;
			Game.cellStates[col][row + lowerHalfDy] = state;
			if (lowerHalfDy === 0) {
				Game.cellMoveOffsets[col][row + upperHalfDy] = attackTimer;
				Game.cellMoveOffsets[col][row + lowerHalfDy] = attackTimer;
			}
			return;
		}
		this.playSound(14);
		Game.cellTypes[col][row + upperHalfDy] = -1;
		this.killEnemyAt(col, row + upperHalfDy | 0);
		Game.cellTypes[col][row + lowerHalfDy] = -1;
		this.killEnemyAt(col, row + lowerHalfDy | 0);
	}

	updateExtendingTrap() {
		let tipRow = 0, state = 0, segments = 0, dirSign = 0;
		state = Game.cellStates[this.updateCellCol][this.updateCellRow];
		dirSign = (state & 7) !== 3 ? -1 : 1;
		segments = (state & 8) !== 0 ? this.pistonFastSegments : this.pistonSlowSegments;
		tipRow = this.updateCellRow + Math.imul(segments - 1 | 0, dirSign) | 0;
		if (this.isPlayerAt(this.updateCellCol, tipRow)) {
			this.damageExplorer(2, 48, Game.oppositeDir[this.explorerStateFlags & 7]);
		}
		switch (Game.cellTypes[this.updateCellCol][tipRow]) {
			default:
				this.killEnemyAt(this.updateCellCol, tipRow);
				Game.cellTypes[this.updateCellCol][tipRow] = -1;
				Game.wakeCellsAround(this.updateCellCol, tipRow);
				this.eraseCellInBuffer(this.updateCellCol, tipRow);
				break;
			case -1:
			case 28:
			case 32:
				break;
		}
		Game.cellUpdateTimers[this.updateCellCol][this.updateCellRow] = 24;
	}

	tryStartDoorUnlock() {
		let lockType = 0, row = 0, col = 0, param = 0, explorerAnim = 0, s1;
		col = this.updateCellCol;
		row = this.updateCellRow;
		param = Game.cellObjects[col][row] >> 8;
		lockType = Game.cellObjects[col][row] & 255;
		if ((param & 256) === 0 && (lockType === 9 && this.goldKeys > 0 || lockType === 8 && this.silverKeys > 0) && this.playerRow === row && (this.playerCol === (col - 1 | 0) || this.playerCol === (col + 1 | 0))) {
			explorerAnim = Game.actors[0].animIndex;
			if (explorerAnim !== 18 && explorerAnim !== 17 && this.playerStep <= 6) {
				this.requestedMoveDir = 0;
				this.currentMoveDir = 0;
				if (this.playerCol !== (col - 1 | 0)) {
					this.explorerStateFlags = this.explorerStateFlags & -8 | 4;
					s1 = 17;
				} else {
					this.explorerStateFlags = this.explorerStateFlags & -8 | 2;
					s1 = 18;
				}
				this.setExplorerAnim(s1);
				if (lockType !== 9) {
					s1 = 25;
				} else {
					s1 = 24;
				}
				this.heldItemImageSet = s1;
				this.heldItemFrame = 0;
			}
		}
	}

	updateDoorOpening() {
		let row = 0, col = 0, param = 0, openStep = 0, aboveObject = 0, aboveParam = 0;
		col = this.updateCellCol;
		row = this.updateCellRow;
		param = Game.cellObjects[col][row] >> 8;
		openStep = (param & 240) >> 4;
		if (openStep !== 0) {
			if (Game.frameCount % 3 === 0 && openStep < 3) {
				param = param & -241 | openStep + 1 << 4;
				if (openStep === 2) {
					aboveObject = Game.cellObjects[col][row - 1] & 255;
					if (aboveObject === 9 || aboveObject === 8) {
						aboveParam = Game.cellObjects[col][row - 1] >> 8;
						aboveParam = aboveParam & -513;
						Game.cellObjects[col][row - 1] = aboveParam << 8 | aboveObject;
					}
					this.propagateLockFlag(col, row - 1 | 0, 1, 0, 0);
					this.propagateLockFlag(col, row - 1 | 0, -1, 0, 0);
				}
				Game.cellUpdateTimers[col][row] = 24;
			}
			Game.cellObjects[col][row] = param << 8 | 7;
		}
	}

	updateProximityAnimTile() {
		let animStep = 0, row = 0, col = 0;
		col = this.updateCellCol;
		row = this.updateCellRow;
		animStep = Game.cellObjects[col][row] >> 8;
		if (animStep >= 6) {
			Game.cellUpdateTimers[col][row] = 0;
			return;
		}
		switch (animStep) {
			default:
				if ((Game.frameCount & 1) === 0) {
					animStep++;
				}
				break;
			case 2:
				switch (this.currentMoveDir) {
					case 4:
						if (this.isPlayerAt(col - 1 | 0, row)) {
							animStep = 3;
						}
						break;
					case 3:
						B6: {
							if (this.isPlayerAt(col, row + 1 | 0)) {
								animStep = 3;
								break B6;
							}
						}
						break;
					case 2:
						B7: {
							if (this.isPlayerAt(col + 1 | 0, row)) {
								animStep = 3;
								break B7;
							}
						}
						break;
					case 1:
						B8: {
							if (this.isPlayerAt(col, row - 1 | 0)) {
								animStep = 3;
								break B8;
							}
						}
						break;
					default:
						break;
				}
				break;
			case 0:
			case 1:
				break;
			case -1:
				if ((Math.abs(this.playerCol - col | 0) | 0) < 4 && (Math.abs(this.playerRow - row | 0) | 0) < 4) {
					animStep = 3;
				}
				break;
		}
		Game.cellUpdateTimers[col][row] = 24;
		Game.cellObjects[col][row] = animStep << 8 | 3;
	}

	updateChest(chestType) {
		let lidFrame = 0, row = 0, col = 0, s1;
		col = this.updateCellCol;
		row = this.updateCellRow;
		lidFrame = Game.cellObjects[col][row] >> 8;
		Game.cellObjects[col][row] = lidFrame << 8 | chestType;
		if (Game.cellMoveOffsets[col][row] <= 0) {
			if (lidFrame !== 0) {
				if ((Game.frameCount >> 1 & 1) === 0 && Game.spritePacks[chestType !== 14 ? 22 : 8] !== null && lidFrame < (Game.spritePacks[chestType !== 14 ? 22 : 8].getAnimFrameCount(0) - 1 | 0)) {
					Game.cellObjects[col][row] = lidFrame + 1 << 8 | chestType;
					Game.cellUpdateTimers[col][row] = 24;
				}
			} else {
				if (this.isPlayerAt(col, row) && this.playerStep <= 0) {
					this.explorerStateFlags = this.explorerStateFlags & -2049;
					Game.cellObjects[col][row] = 256 | chestType;
					if (J.labs(BigInt.asIntN(64, this.lastLeverAnimTime - JSystem.currentTimeMillis())) < 5000n) {
						s1 = 48;
					} else {
						s1 = 40;
					}
					this.setExplorerAnim(s1);
					this.playSound(3);
					return;
				}
			}
		}
	}

	isCellCrushed(col, row) {
		let aboveRow = 0, leftCol = 0, rightCol = 0;
		aboveRow = row - 1 | 0;
		leftCol = col - 1 | 0;
		rightCol = col + 1 | 0;
		if ((Game.cellMoveOffsets[col][aboveRow] > 6 || (!Game.isHeavyObject(col, aboveRow) || (Game.cellStates[col][aboveRow] & 7) !== 3 && (Game.cellTypes[col][row] === 16 || Game.cellTypes[col][aboveRow] === 1)) && Game.cellTypes[col][aboveRow] !== 46 && Game.cellTypes[col][aboveRow] !== 14 && Game.cellTypes[col][aboveRow] !== 48) && (Game.cellMoveOffsets[rightCol][row] > 0 || Game.cellTypes[rightCol][row] !== 14 || (Game.cellStates[rightCol][row] & 8) === 0 || (Game.cellStates[rightCol][row] & 7) === 3) && (Game.cellMoveOffsets[leftCol][row] > 0 || Game.cellTypes[leftCol][row] !== 14 || (Game.cellStates[leftCol][row] & 8) !== 0 || (Game.cellStates[leftCol][row] & 7) === 3)) {
			return 0;
		}
		return 1;
	}

	static isHeavyObject(col, row) {
		if (Game.cellTypes[col][row] >= 0) {
			switch (Game.cellTypes[col][row]) {
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

	static wakeCellsAround(col, row) {
		let topRow = 0, leftCol = 0, rightCol = 0, bottomRow = 0;
		leftCol = col - 1 | 0;
		rightCol = col + 1 | 0;
		topRow = row - 1 | 0;
		bottomRow = row + 1 | 0;
		Game.cellUpdateTimers[leftCol][topRow] = 48;
		Game.cellUpdateTimers[col][topRow] = 48;
		Game.cellUpdateTimers[rightCol][topRow] = 48;
		Game.cellUpdateTimers[leftCol][row] = 48;
		Game.cellUpdateTimers[col][row] = 48;
		Game.cellUpdateTimers[rightCol][row] = 48;
		Game.cellUpdateTimers[leftCol][bottomRow] = 48;
		Game.cellUpdateTimers[col][bottomRow] = 48;
		Game.cellUpdateTimers[rightCol][bottomRow] = 48;
	}

	saveCheckpoint() {
		let col = 0;
		this.checkpointSwimFlag = Game.saveData[10];
		this.checkpointLeverDir = this.leverMoveDir;
		this.checkpointLeverPos = this.switchWallsPhase;
		this.checkpointDiamondsToOpenExit = this.diamondsToOpenExit;
		this.checkpointNextIndex = this.nextCheckpointIndex;
		this.checkpointDiamonds = this.diamondCount;
		this.checkpointRedDiamonds = this.redDiamondCount;
		this.checkpointCol = this.playerCol;
		this.checkpointRow = this.playerRow;
		this.checkpointGoldKeys = this.goldKeys;
		this.checkpointSilverKeys = this.silverKeys;
		this.checkpointEntryWalk = this.entryWalkRemaining;
		this.checkpointRedDiamondPickCount = this.redDiamondPickCount;
		this.checkpointRisingHazardPhase = this.floodTriggerStage;
		this.checkpointRisingHazardHeight = this.floodHeight;
		Game.checkpointGateId = Game.activeGateId;
		if (Game.gateRemainingCounts !== null) {
			JSystem.arraycopy(Game.gateRemainingCounts, 0, Game.checkpointGateCounts, 0, Game.gateRemainingCounts.length);
		}
		for (col = 0; col < this.levelW; col++) {
			JSystem.arraycopy(Game.cellStates[col], 0, Game.checkpointCellStates[col], 0, this.levelH);
			JSystem.arraycopy(Game.cellMoveOffsets[col], 0, Game.checkpointCellMoveOffsets[col], 0, this.levelH);
			JSystem.arraycopy(Game.cellTypes[col], 0, Game.checkpointCellTypes[col], 0, this.levelH);
			JSystem.arraycopy(Game.cellObjects[col], 0, Game.checkpointCellObjects[col], 0, this.levelH);
		}
		this.saveLiquidCheckpoint();
	}

	restoreCheckpoint() {
		let row = 0, index = 0, innerCol = 0, col = 0, cellType = 0, cellObject = 0, s0, s1;
		Game.bufLeftX = -1;
		this.heldItemAmount = -1;
		this.heldItemFrame = -1;
		this.heldItemImageSet = -1;
		this.slidingObjCol = 0;
		this.slidingObjRow = 0;
		this.respawnPanActive = 1;
		this.camPanTargetX = this.checkpointCol * 24 - 120 | 0;
		this.camPanTargetY = this.checkpointRow * 24 - 160 + 40 | 0;
		this.deathLetterboxHeight = 0;
		if (!this.introTrigger13Reached) {
			if (this.introTrigger16Reached) {
				this.pendingCutsceneId = 17;
				this.introTrigger16Reached = 0;
				Game.checkpointCellObjects[46][7] = -1;
				s0 = Game.checkpointCellObjects[50];
				s1 = 7;
				s0[s1] = -1;
			}
		} else {
			this.pendingCutsceneId = 15;
			this.introTrigger13Reached = 0;
			Game.checkpointCellObjects[37][7] = -1;
			s0 = Game.checkpointCellObjects[39];
			s1 = 5;
			s0[s1] = -1;
		}
		this.introHintIconVisible = 0;
		this.playerIdleCountdown = 70;
		Game.saveData[10] = this.checkpointSwimFlag;
		this.diamondsToOpenExit = this.checkpointDiamondsToOpenExit;
		this.leverMoveDir = this.checkpointLeverDir;
		this.switchWallsPhase = this.checkpointLeverPos;
		this.nextCheckpointIndex = this.checkpointNextIndex;
		this.redDiamondCount = this.checkpointRedDiamonds;
		this.diamondCount = this.checkpointDiamonds;
		Game.actors[0].setAnimation(2);
		this.explorerStateFlags = 2;
		this.shakeTime = 0;
		this.playerCol = this.checkpointCol;
		this.playerRow = this.checkpointRow;
		this.goldKeys = this.checkpointGoldKeys;
		this.silverKeys = this.checkpointSilverKeys;
		this.redDiamondPickCount = this.checkpointRedDiamondPickCount;
		switch (this.specialStageType) {
			case 5:
				this.initKnightBossStage();
				break;
			case 4:
				this.bossState = 0;
				this.anacondaHoleIndex = 0;
				this.bossHealth = 3;
				this.anacondaSlamVisible = 0;
				break;
			case 3:
				this.bossHealth = 5;
				break;
			case 1:
				this.floodHeight = this.checkpointRisingHazardHeight;
				this.floodTriggerStage = this.checkpointRisingHazardPhase;
				break;
			default:
				break;
		}
		Game.activeGateId = Game.checkpointGateId;
		if (Game.gateRemainingCounts !== null) {
			JSystem.arraycopy(Game.checkpointGateCounts, 0, Game.gateRemainingCounts, 0, Game.gateRemainingCounts.length);
		}
		for (index = 0; index < this.levelW; index++) {
			JSystem.arraycopy(Game.checkpointCellStates[index], 0, Game.cellStates[index], 0, this.levelH);
			JSystem.arraycopy(Game.checkpointCellMoveOffsets[index], 0, Game.cellMoveOffsets[index], 0, this.levelH);
			JSystem.arraycopy(Game.checkpointCellTypes[index], 0, Game.cellTypes[index], 0, this.levelH);
			JSystem.arraycopy(Game.checkpointCellObjects[index], 0, Game.cellObjects[index], 0, this.levelH);
		}
		index = this.levelH - 1 | 0;
		for (row = 1; row < index; row++) {
			innerCol = this.levelW - 1 | 0;
			for (col = 1; col < innerCol; col++) {
				cellType = Game.cellTypes[col][row];
				cellObject = Game.cellObjects[col][row] & 255;
				if (cellType > -1 && cellType < 80 || cellObject > -1 && cellObject < 80) {
					Game.wakeCellsAround(col, row);
				}
			}
		}
		if (Game.actors[2] !== null) {
			Game.actors[2].setAnimation(0);
			Game.cellTypes[18][63] = -1;
		}
		this.entryWalkRemaining = this.checkpointEntryWalk;
		this.requestHudRedraw();
		if (this.hasWaterLayer) {
			this.restoreLiquidCheckpoint();
		}
		if (Game.freezeRays !== null) {
			for (row = 0; row < this.levelH; row++) {
				for (innerCol = 0; innerCol < this.levelW; innerCol++) {
					if (Game.cellTypes[innerCol][row] === 48) {
						this.updateCellCol = innerCol;
						this.updateCellRow = row;
						if ((Game.cellStates[innerCol][row] & 8) !== 0) {
							this.updateFreezeRay();
						} else {
							this.updateTallObjectFall(48);
						}
					}
				}
			}
		}
	}

	static setCellTypeAndState(col, row, cellType, state) {
		Game.cellTypes[col][row] = cellType;
		Game.cellStates[col][row] = state;
	}

	static isWithinCellOverlap(ax, ay, bx, by) {
		if ((Math.abs(ax - bx | 0) | 0) >= 24 || (Math.abs(ay - by | 0) | 0) >= 24) {
			return 0;
		}
		return 1;
	}

	static doMovingCellsTouch(colA, rowA, dirA, offsetA, colB, rowB, dirB, offsetB) {
		Game.hitTestAY = 0;
		Game.hitTestAX = 0;
		Game.hitTestBY = 100;
		Game.hitTestBX = 100;
		if ((Math.abs(colA - colB | 0) | 0) > 1 || (Math.abs(rowA - rowB | 0) | 0) > 1) {
			return 0;
		}
		Game.hitTestAX = colA * 24 + Math.imul(Game.dirDeltas[dirA], offsetA) | 0;
		Game.hitTestAY = rowA * 24 + Math.imul(Game.dirDeltas[8 + dirA], offsetA) | 0;
		Game.hitTestBX = colB * 24 + Math.imul(Game.dirDeltas[dirB], offsetB) | 0;
		Game.hitTestBY = rowB * 24 + Math.imul(Game.dirDeltas[8 + dirB], offsetB) | 0;
		return Game.isWithinCellOverlap(Game.hitTestAX, Game.hitTestAY, Game.hitTestBX, Game.hitTestBY);
	}

	updateFallingObject() {
		let squashFrame = 0, sideDx = 0, touchesExplorer = 0, liquidFlag = 0, fallDir = 0, dir = 0, belowType = 0, row = 0, explorerMoveDir = 0, col = 0, isInBubble = 0, offset = 0, vertDir = 0, inLiquid = 0, sideDy = 0, cellType = 0, nextRow = 0, restKind = 0, state = 0, s0, s1, t7;
		col = this.updateCellCol;
		row = this.updateCellRow;
		offset = Game.cellMoveOffsets[col][row];
		state = Game.cellStates[col][row];
		cellType = Game.cellTypes[col][row];
		s0 = Game.liquidCells === null || Game.liquidCells[col][row] === 0 ? 0 : 1;
		inLiquid = s0;
		dir = state & 7;
		if (inLiquid === 0 || Game.liquidCells[col][row] === 3) {
			vertDir = 1;
			fallDir = 3;
			s0 = row + 1 | 0;
		} else {
			vertDir = -1;
			fallDir = 1;
			s0 = row - 1 | 0;
		}
		nextRow = s0;
		s0 = (this.explorerStateFlags & 4096) !== 0 ? 0 : this.currentMoveDir;
		explorerMoveDir = s0;
		touchesExplorer = Game.doMovingCellsTouch(col, row, dir, offset, this.playerCol, this.playerRow, explorerMoveDir, this.playerStep);
		if (cellType !== 1 || touchesExplorer === 0) {
			s0 = (Game.cellObjects[col][row] & 255) !== 35 ? 0 : 1;
			isInBubble = s0;
			belowType = Game.cellTypes[col][nextRow];
			if (belowType === 9 && offset <= 0) {
				sideDx = (Game.cellObjects[col][nextRow] & 255) << 24 >> 24;
				sideDy = (Game.cellStates[col][nextRow] & 264241152) >> 22;
				if (sideDy !== 34) {
					if (sideDy !== 33) {
						if (Game.cellTypes[col][nextRow] === 19 || Game.cellTypes[col][nextRow] === 43 || Game.cellTypes[col][nextRow] === 45 || Game.cellTypes[col][nextRow] === 46 || Game.cellTypes[col][nextRow] === 49 || Game.cellTypes[col][nextRow] === 11) {
							Game.cellTypes[col][nextRow] = -1;
							this.killEnemyAt(col, nextRow);
						}
					} else {
						if (sideDx === -1) {
							Game.cellObjects[col][nextRow] = 32;
						}
						this.playerCol = col;
						this.playerRow = nextRow;
						Game.cellTypes[col][nextRow] = -1;
						this.playerStep = 0;
						this.encasedStruggleCount = 0;
						this.damageExplorer(2, 48, 0);
					}
				}
			}
			if (offset > 0 || isInBubble !== 0) {
				if (isInBubble === 0) {
					if ((state & 512) !== 0) {
						sideDx = 0;
						sideDy = 0;
						if (dir !== 4) {
							if (dir === 2) {
								s0 = 1;
								sideDx = s0;
							}
						} else {
							s0 = -1;
							sideDx = s0;
						}
						if (!Game.isCellFreeForObject(col, nextRow) || this.isPlayerAt(col, nextRow)) {
							if (!Game.isCellFreeForObject(col + sideDx | 0, row) || this.isPlayerAt(col + sideDx | 0, row) || !Game.isCellFreeForObject(col + sideDx | 0, nextRow) || this.isPlayerAt(col + sideDx | 0, nextRow) || (Game.cellStates[col][nextRow] & 512) !== 0) {
								offset = offset - 6 << 24 >> 24;
								if (offset <= 0) {
									offset = 0;
									state = state & -513;
									state = state & -8 | 0;
								}
								Game.cellMoveOffsets[col][row] = offset;
								Game.cellStates[col][row] = state;
								Game.cellUpdateTimers[col][row] = 24;
								this.redrawCellInBuffer(col, row);
							} else {
								if (offset >= 6 || (Game.frameCount & 3) === 0) {
									offset = offset + 1 << 24 >> 24;
								}
								if (offset < 12) {
									Game.cellMoveOffsets[col][row] = offset;
									Game.cellStates[col][row] = state;
									Game.cellUpdateTimers[col][row] = 24;
								} else {
									state = state & -513;
									if (sideDx === 0) {
										state = state & -8 | 0;
										offset = 0;
									} else {
										offset = 6;
										Game.cellTypes[col][row] = -1;
										if (Game.isCellFreeForObject(col + sideDx | 0, nextRow)) {
											offset = 12;
											state = state & -8 | fallDir;
											sideDy = vertDir;
										}
									}
									Game.cellStates[col + sideDx][row + sideDy] = state | -2147483648;
									Game.cellMoveOffsets[col + sideDx][row + sideDy] = offset;
									Game.cellTypes[col + sideDx][row + sideDy] = cellType;
									Game.wakeCellsAround(col, row);
									Game.cellUpdateTimers[col][row + 2 * vertDir] = 24;
								}
							}
						} else {
							offset = offset - 6 << 24 >> 24;
							if (offset <= 0) {
								offset = 0;
								state = state & -513;
								state = state & -8 | 0;
							}
							Game.cellMoveOffsets[col][row] = offset;
							Game.cellStates[col][row] = state;
							Game.cellUpdateTimers[col][row] = 24;
						}
					} else {
						if (dir !== 3 || (Game.cellObjects[col][row] & 255) !== 6 || offset > 12) {
							offset = offset - 6 << 24 >> 24;
						} else {
							offset = offset - (Game.frameCount & 1) << 24 >> 24;
							Game.cellUpdateTimers[col][row] = 24;
						}
						if (offset === 0 || offset === 12) {
							switch (state & 3072) {
								case 2048:
									s0 = state & -57;
									s1 = state - 8 | 0;
									state = s0 | s1 & 56;
									break;
								case 1024:
									s0 = state & -57;
									s1 = state + 8 | 0;
									state = s0 | s1 & 56;
									break;
								default:
									break;
							}
							if (offset === 0) {
								if ((Game.cellObjects[col][row] & 255) === 6) {
									state = state & -449;
								}
								if (dir === fallDir) {
									if ((cellType === 0 || cellType === 9) && vertDir > 0 && !Game.isCellFreeForObject(col, row + 1 | 0)) {
										Game.vibrateDevice(200);
										this.playSound(14);
										this.shakeTime = 10;
										if (cellType === 9 && this.encasedStruggleCount > 0 && this.isPlayerAt(col, row)) {
											this.damageExplorer(1, 0, 0);
											this.requestHudRedraw();
										}
										sideDx = Game.isHeavyObject(col, row + 1 | 0);
										if (!sideDx) {
											state = state & -449 | 64;
										}
									}
									Game.cellUpdateTimers[col][row] = 30;
									if (!this.isPlayerAt(col, nextRow)) {
										state = state & -8 | 0;
									}
								}
							}
						}
						Game.cellMoveOffsets[col][row] = offset;
						Game.cellStates[col][row] = state;
					}
				}
			} else {
				if (dir !== fallDir || !this.isPlayerAt(col, nextRow) || !Game.isCellFreeForObject(col, nextRow)) {
					if ((Game.isCellFreeForObject(col, nextRow) || Game.cellTypes[col][nextRow] === 21) && (!this.isPlayerAt(col, row) || this.encasedStruggleCount > 0) && (!this.isPlayerAt(col, nextRow) && !Game.isWithinCellOverlap(Game.hitTestAX, Game.hitTestAY, Game.hitTestBX, Game.hitTestBY - 1 | 0) || this.encasedStruggleCount > 0 || this.deathTimer !== 0 || cellType !== 0 && dir === fallDir)) {
						if (vertDir > 0 || Game.liquidCells !== null && Game.liquidCells[col][nextRow] !== 0) {
							state = state + 131072 | 0;
							state = state & -8 | fallDir;
							Game.cellStates[col][nextRow] = state | -2147483648;
							Game.cellMoveOffsets[col][nextRow] = 18;
							Game.cellTypes[col][nextRow] = cellType;
							Game.cellTypes[col][row] = -1;
							Game.wakeCellsAround(col, row);
							Game.cellUpdateTimers[col][row + 2 * vertDir] = 24;
							this.eraseCellInBuffer(col, row);
						} else {
							state = state & -4063240 | 0;
							Game.cellStates[col][row] = state;
							Game.cellMoveOffsets[col][nextRow] = 0;
						}
					} else {
						if (!Game.isHeavyObject(col, nextRow)) {
							if (cellType !== 8) {
								state = state & -3073 | 0;
								state = state & -4063233;
								state = state & -8;
								Game.cellStates[col][row] = state;
							} else {
								sideDx = (state & 4063232) >> 17;
								if (sideDx < 2) {
									state = state & -4063233;
								} else {
									Game.cellTypes[col][row] = 54;
									Game.cellStates[col][row] = 0;
									Game.wakeCellsAround(col, row);
									return;
								}
							}
						} else {
							if (vertDir >= 0 || Game.liquidCells !== null && Game.liquidCells[col][nextRow] !== 0 || Game.cellTypes[col][row + 1] >= 0) {
								if (Game.cellMoveOffsets[col][nextRow] <= 0) {
									sideDx = (state & 4063232) >> 17;
									if (sideDx >= 2) {
										if (cellType === 8) {
											Game.cellTypes[col][row] = 54;
											Game.cellStates[col][row] = 0;
											Game.wakeCellsAround(col, row);
											return;
										}
										if (Game.cellTypes[col][nextRow] === 8) {
											Game.cellTypes[col][nextRow] = 54;
											Game.cellStates[col][nextRow] = 0;
											Game.wakeCellsAround(col, nextRow);
											return;
										}
									}
									state = state & -4063233;
									if (!Game.isCellFreeForObject(col - 1 | 0, row) || !Game.isCellFreeForObject(col - 1 | 0, nextRow) || this.isPlayerAt(col - 1 | 0, row)) {
										if (Game.isCellFreeForObject(col + 1 | 0, row) && Game.isCellFreeForObject(col + 1 | 0, nextRow) && !this.isPlayerAt(col + 1 | 0, row)) {
											Game.cellMoveOffsets[col][row] = ((state & 28672) >> 12) + 1 << 24 >> 24;
											Game.cellUpdateTimers[col][row] = 24;
											state = state & -8 | 2;
											s0 = state & -3073;
											s1 = 1024;
											t7 = s0 | s1;
											state = t7;
											state = state | 512;
										}
									} else {
										Game.cellMoveOffsets[col][row] = ((state & 28672) >> 12) + 1 << 24 >> 24;
										Game.cellUpdateTimers[col][row] = 24;
										state = state & -8 | 4;
										s0 = state & -3073;
										s1 = 2048;
										t7 = s0 | s1;
										state = t7;
										state = state | 512;
									}
									Game.cellStates[col][row] = state;
								}
							} else {
								Game.cellStates[col][row + 1] = state & -8 | 3;
								Game.cellStates[col][row + 1] = Game.cellStates[col][row + 1] | -2147483648;
								Game.cellTypes[col][row + 1] = cellType;
								Game.cellMoveOffsets[col][row + 1] = 18;
								Game.cellTypes[col][row] = -1;
							}
						}
					}
				} else {
					if ((cellType === 0 || cellType === 9) && vertDir > 0) {
						this.damageExplorer(2, 48, 0);
					} else {
						if (cellType !== 1) {
							if (cellType === 8) {
								state = state & -4063233;
							}
						} else {
							Game.cellStates[col][nextRow] = state & -8 | 3;
							Game.cellMoveOffsets[col][nextRow] = 18;
							Game.cellTypes[col][nextRow] = 1;
							Game.cellTypes[col][row] = -1;
							this.eraseCellInBuffer(col, row);
						}
					}
					Game.cellStates[col][row] = state & -8 | 0;
				}
			}
			sideDx = state & 536870912;
			sideDy = Game.cellMoveOffsets[col][row];
			liquidFlag = state & 1073741824;
			restKind = 0;
			if (sideDx === 0 && sideDy !== 0 || liquidFlag === 0 && inLiquid !== 0) {
				this.eraseCellInBuffer(col, row);
			}
			if (sideDx !== 0 && sideDy === 0 || liquidFlag !== 0 && inLiquid === 0) {
				this.redrawCellInBuffer(col, row);
			}
			if ((state & 512) === 0) {
				if (sideDy !== 0 || sideDx !== 0) {
					s0 = 2;
				} else {
					if (inLiquid === 0) {
						if (Game.cellObjects[col][row] <= -1 || Game.cellObjects[col][row] >= 38) {
							s0 = (Game.isCellFreeForObject(col - 1 | 0, row) || Game.isCellFreeForObject(col + 1 | 0, row)) && Game.isHeavyObject(col, row + 1 | 0) && (Game.cellStates[col][row + 1] & 7) === 0 && col !== this.slidingObjCol && row !== this.slidingObjRow ? 6 : 0;
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
			state = state & -536870913 | (sideDy === 0 ? 0 : 536870912);
			state = state & -1073741825 | (inLiquid === 0 ? 0 : 1073741824);
			s0 = state & 2147483647;
			s1 = restKind === 0 ? 0 : -2147483648;
			state = s0 | s1;
			Game.cellStates[col][row] = state;
			squashFrame = ((Game.cellStates[col][row] & 448) >> 6) - 1 | 0;
			if (squashFrame >= 0 && squashFrame < 5) {
				Game.cellStates[col][row] = Game.cellStates[col][row] & -449 | Game.cellStates[col][row] + 64 & 448;
			}
			return;
		}
		this.collectDiamondAt(col, row);
	}

	collectDiamondAt(col, row) {
		this.spawnCellEffect(col, row, 3);
		this.diamondCount = this.diamondCount + 1 | 0;
		Game.cellTypes[col][row] = -1;
		this.diamondsToOpenExit = this.diamondsToOpenExit - 1 | 0;
		this.slideCellsLeft = 0;
		if (this.diamondsToOpenExit === 0) {
			Game.cellTypes[this.exitDoorCol][this.exitDoorRow] = -1;
		}
		if (Game.cellTypes[col][row - 1] === -1) {
			this.eraseCellInBuffer(col, row - 1 | 0);
		}
		this.eraseCellInBuffer(col, row);
		this.requestHudRedraw();
	}

	static loadSpritePackPalettes(path, index, firstPalette, lastPalette) {
		let pack = null, palette = 0, data = null, s0;
		pack = null;
		try {
			pack = new SpritePack().init();
			data = Game.readResource(path, index);
			pack.loadFromBytes(data, 0);
			for (palette = firstPalette; palette <= lastPalette; palette++) {
				pack.buildModuleImages(palette, 0, -1, -1);
			}
			pack.paletteIndex = firstPalette;
			pack.moduleData = null;
			JSystem.gc();
		} catch (ex) {
			ex = J.exc(ex);
			if (J.isa(ex, "java/lang/Exception")) {
				s0 = ex;
				return pack;
			}
			else throw ex;
		}
		return pack;
	}

	static loadSpritePack(path, index) {
		return Game.loadSpritePackPalette(path, index, 0);
	}

	static loadSpritePackPalette(path, index, palette) {
		return Game.loadSpritePackPalettes(path, index, palette, palette);
	}

	static loadSpriteImages(path, index) {
		return Game.loadSpriteImagesPalette(path, index, 0);
	}

	static loadSpriteImagesPalette(path, index, palette) {
		let pack = null, data = null, s0;
		pack = null;
		try {
			pack = new SpritePack().init();
			data = Game.readResource(path, index);
			pack.loadFromBytes(data, 0);
			pack.buildModuleImages(palette, 0, -1, -1);
			Game.freeSpritePack(pack, 0);
			JSystem.gc();
		} catch (ex) {
			ex = J.exc(ex);
			if (J.isa(ex, "java/lang/Exception")) {
				s0 = ex;
				return pack.moduleImages[palette];
			}
			else throw ex;
		}
		return pack.moduleImages[palette];
	}

	static loadPng(path, index) {
		let data = null, image = null, s0;
		image = null;
		try {
			data = Game.readResource(path, index);
			image = Image.createImage(data, 0, data.length);
			JSystem.gc();
		} catch (ex) {
			ex = J.exc(ex);
			if (J.isa(ex, "java/lang/Exception")) {
				s0 = ex;
				return image;
			}
			else throw ex;
		}
		return image;
	}

	static readResource(path, index) {
		let headerSize = 0, size = 0, data = null, offset = 0, stream = null, s0;
		data = null;
		stream = J.getClass(path).getResourceAsStream(path);
		try {
			headerSize = stream.read() << 3;
			data = new Int8Array(headerSize);
			stream.read(data);
			offset = Game.readS32LE(data, index << 3);
			size = Game.readS32LE(data, (index << 3) + 4 | 0);
			stream.skip(BigInt(offset));
			data = new Int8Array(size);
			stream.read(data);
			stream.close();
		} catch (ex) {
			ex = J.exc(ex);
			if (J.isa(ex, "java/lang/Exception")) {
				s0 = ex;
				return data;
			}
			else throw ex;
		}
		return data;
	}

	loadCharMap() {
		let stream = null, s0;
		if (SpritePack.charMap !== null) {
			return;
		}
		stream = J.getClass(this).getResourceAsStream("/mc");
		SpritePack.charMap = new Int8Array(256);
		try {
			stream.read(SpritePack.charMap);
			stream.close();
		} catch (ex) {
			ex = J.exc(ex);
			if (J.isa(ex, "java/lang/Exception")) {
				s0 = ex;
				return;
			}
			else throw ex;
		}
	}

	static measureFirstLineWidth(font, text, lineMode) {
		let cutIndex = 0;
		if (lineMode !== -1) {
			cutIndex = J.indexOf(text, 10);
			if (cutIndex !== -1) {
				text = text.substring(0, cutIndex);
			}
		}
		cutIndex = J.indexOf(text, 125);
		if (cutIndex !== -1) {
			text = text.substring(0, cutIndex);
		}
		font.measureString(text);
		return SpritePack.textWidth;
	}

	static getFontLineHeight(font) {
		return font.lineSpacing + (font.moduleSizes[1] & 255) | 0;
	}

	static setMoreGamesState(state) {
		MoreGames.state = state;
	}

	updateMoreGamesScreen(g) {
		MoreGames.frameCounter = MoreGames.frameCounter + 1 | 0;
		switch (MoreGames.state) {
			case 4:
				Game.setMoreGamesState(0);
				this.moreGamesScreen = null;
				JSystem.gc();
				return 0;
			case 3:
				this.moreGamesScreen.updateAndDraw(g);
				return 1;
			case 2:
				MoreGames.unload();
				this.cleanup();
				Game.screen = 9;
				this.loadingStepCount = 8;
				this.loadingStep = 0;
				return 1;
			case 1:
				MoreGames.loadResources();
				Game.menuRepaintPlayfield = 0;
				return 1;
			case 0:
				this.cleanup();
				this.moreGamesScreen = new MoreGames().init();
				this.markMoreGamesSeen();
				this.sound.stop();
				Game.setMoreGamesState(1);
				this.showMoreGamesBadge = 0;
				return 1;
			default:
				return 1;
		}
	}

	markMoreGamesSeen() {
		let t1;
		if ((Game.prefsData[0] & 1) === 0) {
			this.showMoreGamesBadge = 1;
			t1 = Game.prefsData;
			t1[0] = (t1[0] | 1) << 24 >> 24;
			this.savePreferences();
		}
	}

	static readUShortLE(stream) {
		return stream.read() & 255 | (stream.read() & 255) << 8;
	}

	static keyMask(keyCode) {
		if (keyCode < 0) {
			keyCode = Math.abs(keyCode) | 0;
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

	saveLiquidCheckpoint() {
		let col = 0;
		if (this.hasWaterLayer) {
			if (Game.savedLiquidCells === null) {
				Game.savedLiquidCells = J.multiArray(Int32Array, 2, [this.levelW, this.levelH]);
			}
			for (col = 0; col < this.levelW; col++) {
				JSystem.arraycopy(Game.liquidCells[col], 0, Game.savedLiquidCells[col], 0, this.levelH);
			}
			if (Game.savedLiquidFlows === null) {
				Game.savedLiquidFlows = new BigInt64Array(15);
			}
			JSystem.arraycopy(Game.liquidFlows, 0, Game.savedLiquidFlows, 0, Game.liquidFlows.length);
			if (Game.savedLiquidEmitters === null) {
				Game.savedLiquidEmitters = new BigInt64Array(15);
			}
			JSystem.arraycopy(Game.liquidEmitters, 0, Game.savedLiquidEmitters, 0, Game.liquidEmitters.length);
			this.savedLiquidState = this.liquidState;
			this.savedLiquidDrainTick = this.liquidDrainTick;
			this.savedLiquidPoolRiseCount = this.liquidPoolRiseCount;
			this.savedLiquidSpareCounter = this.liquidSpareCounter;
			this.savedLiquidFillTargetSlot = this.liquidFillTargetSlot;
			this.savedLiquidBreachCol = this.liquidBreachCol;
			this.savedLiquidBreachRow = this.liquidBreachRow;
			this.savedLiquidBreachDir = this.liquidBreachDir;
			this.savedLiquidDrainFlow = this.liquidDrainFlow;
			this.savedLiquidDrainStopRow = this.liquidDrainStopRow;
			this.savedLiquidFlowTick = this.liquidFlowTick;
			Game.savedLiquidStartNextEmitter = this.liquidStartNextEmitter;
			this.savedLiquidNextEmitter = this.liquidNextEmitter;
			this.savedLiquidEmitterCount = this.liquidEmitterCount;
			return;
		}
	}

	restoreLiquidCheckpoint() {
		let col = 0;
		this.liquidStartNextEmitter = Game.savedLiquidStartNextEmitter;
		this.liquidNextEmitter = this.savedLiquidNextEmitter;
		this.liquidEmitterCount = this.savedLiquidEmitterCount;
		for (col = 0; col < this.levelW; col++) {
			JSystem.arraycopy(Game.savedLiquidCells[col], 0, Game.liquidCells[col], 0, this.levelH);
		}
		JSystem.arraycopy(Game.savedLiquidFlows, 0, Game.liquidFlows, 0, Game.liquidFlows.length);
		JSystem.arraycopy(Game.savedLiquidEmitters, 0, Game.liquidEmitters, 0, Game.liquidEmitters.length);
		this.liquidState = this.savedLiquidState;
		this.liquidDrainTick = this.savedLiquidDrainTick;
		this.liquidPoolRiseCount = this.savedLiquidPoolRiseCount;
		this.liquidSpareCounter = this.savedLiquidSpareCounter;
		this.liquidFillTargetSlot = this.savedLiquidFillTargetSlot;
		this.liquidBreachCol = this.savedLiquidBreachCol;
		this.liquidBreachRow = this.savedLiquidBreachRow;
		this.liquidBreachDir = this.savedLiquidBreachDir;
		this.liquidDrainFlow = this.savedLiquidDrainFlow;
		this.liquidDrainStopRow = this.savedLiquidDrainStopRow;
		this.liquidFlowTick = this.savedLiquidFlowTick;
	}

	createLiquidLayer() {
		if (this.hasWaterLayer) {
			this.resetLiquidSimulation();
			Game.liquidCells = J.multiArray(Int32Array, 2, [this.levelW, this.levelH]);
			this.registerLiquidEmitters();
		}
	}

	resetLiquidSimulation() {
		if (this.hasWaterLayer) {
			Game.liquidFlows = new BigInt64Array(15);
			Game.savedLiquidFlows = new BigInt64Array(15);
			Game.liquidEmitters = new BigInt64Array(15);
			Game.savedLiquidEmitters = new BigInt64Array(15);
			this.liquidState = 3;
			this.liquidStartNextEmitter = 1;
			this.liquidDrainTick = -1;
			this.liquidPoolRiseCount = 0;
			this.liquidSpareCounter = 0;
			this.liquidFillTargetSlot = 0;
			this.liquidBreachCol = 0;
			this.liquidBreachRow = 0;
			this.liquidBreachDir = 0;
			this.liquidDrainFlow = 0;
			this.liquidDrainStopRow = 0;
			this.liquidFlowTick = -1;
			this.liquidNextEmitter = 0;
			this.liquidEmitterCount = 0;
		}
	}

	addLiquidEmitter(amount, col, row, dir) {
		let slot = 0, s0;
		s0 = 0;
		while (true) {
			slot = s0;
			if (slot >= 15) {
				break;
			}
			if (Game.getEmitterBits(slot, 0, 4) !== 0) {
				s0 = slot + 1 << 24 >> 24;
				continue;
			}
			break;
		}
		if (slot >= 15) {
			return -1;
		}
		this.setEmitterBits(slot, 1, 0, 4);
		this.setEmitterBits(slot, dir, 4, 2);
		this.setEmitterBits(slot, amount, 6, 7);
		this.setEmitterBits(slot, amount, 27, 7);
		this.setEmitterBits(slot, col, 13, 7);
		this.setEmitterBits(slot, row, 20, 7);
		return slot;
	}

	static getLiquidBits(packed, subSlot, bitOffset, bitCount) {
		packed = packed >>> subSlot * 9 + bitOffset | 0;
		packed = packed & (-1 << bitCount ^ -1);
		return packed;
	}

	setLiquidBits(col, row, subSlot, value, bitOffset, bitCount) {
		let shift = 0, packed = 0, oldBits = 0, newBits = 0;
		packed = Game.liquidCells[col][row];
		oldBits = Game.getLiquidBits(packed, subSlot, bitOffset, bitCount);
		shift = subSlot * 9 + bitOffset << 24 >> 24;
		oldBits = oldBits << shift;
		packed = packed ^ oldBits;
		newBits = value;
		newBits = newBits << shift;
		packed = packed | newBits;
		Game.liquidCells[col][row] = packed;
		Game.cellUpdateTimers[col][row] = 24;
		Game.cellUpdateTimers[col][row + 1] = 24;
	}

	static getFlowBits(flowNumber, shift, bitCount) {
		return Number(BigInt.asIntN(32, BigInt.asIntN(64, BigInt.asUintN(64, Game.liquidFlows[flowNumber - 1]) >> BigInt(shift & 63)) & (BigInt.asIntN(64, (-1n) << BigInt(bitCount & 63)) ^ (-1n))));
	}

	setFlowBits(flowNumber, value, shift, bitCount) {
		let packed = 0n, oldBits = 0n, newBits = 0n;
		oldBits = BigInt(Game.getFlowBits(flowNumber, shift, bitCount));
		flowNumber--;
		packed = Game.liquidFlows[flowNumber];
		oldBits = BigInt.asIntN(64, oldBits << BigInt(shift & 63));
		packed = packed ^ oldBits;
		newBits = BigInt(value);
		newBits = BigInt.asIntN(64, newBits << BigInt(shift & 63));
		packed = packed | newBits;
		Game.liquidFlows[flowNumber] = packed;
	}

	static getEmitterBits(emitter, shift, bitCount) {
		let packed = 0n;
		packed = Game.liquidEmitters[emitter];
		packed = BigInt.asIntN(64, BigInt.asUintN(64, packed) >> BigInt(shift & 63));
		packed = packed & (BigInt.asIntN(64, (-1n) << BigInt(bitCount & 63)) ^ (-1n));
		return Number(BigInt.asIntN(32, packed));
	}

	setEmitterBits(emitter, value, shift, bitCount) {
		let packed = 0n, oldBits = 0n, newBits = 0;
		oldBits = BigInt(Game.getEmitterBits(emitter, shift, bitCount));
		packed = Game.liquidEmitters[emitter];
		oldBits = BigInt.asIntN(64, oldBits << BigInt(shift & 63));
		packed = packed ^ oldBits;
		newBits = value;
		newBits = newBits << shift;
		packed = packed | BigInt(newBits);
		Game.liquidEmitters[emitter] = packed;
	}

	findEmitterAt(col, row) {
		let slot = 0, s0;
		s0 = 0;
		while (true) {
			slot = s0;
			if (slot >= 15) {
				return -1;
			}
			if (col !== Game.getEmitterBits(slot, 13, 7) || row !== Game.getEmitterBits(slot, 20, 7)) {
				s0 = slot + 1 << 24 >> 24;
				continue;
			}
			break;
		}
		return slot;
	}

	setEmitterStateAt(col, row, state) {
		let result = 0, s0;
		result = this.findEmitterAt(col, row);
		if (result < 0) {
			return -1;
		}
		this.setEmitterBits(result, state, 0, 4);
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

	updateLiquidSimulation() {
		let flowNumber = 0, s0;
		if (!this.hasWaterLayer) {
			return;
		}
		if (this.liquidDrainTick >= 0 && this.liquidFlowTick >= 0) {
			this.liquidDrainTick = this.liquidDrainTick + 1 | 0;
			this.updatePoolDrain();
		}
		switch (this.liquidState) {
			case 5:
				this.startLiquidBreachDrain(this.liquidBreachCol, this.liquidBreachRow);
				return;
			case 4:
				this.spawnErasingStreamsFromEmptySources();
				this.liquidState = 2;
				return;
			case 2:
				s0 = 1;
				while (true) {
					flowNumber = s0;
					if (flowNumber > 15) {
						break;
					}
					switch (Game.getFlowBits(flowNumber, 28, 3)) {
						case 3:
							Game.clearLiquidFlow(flowNumber);
							break;
						case 2:
							if (this.liquidFlowTick >= 0) {
								this.liquidFlowTick = this.liquidFlowTick + 1 | 0;
								this.updatePoolFill(flowNumber);
							}
							break;
						case 1:
						case 6:
						case 7:
							this.updateStreamHead(flowNumber);
							break;
						default:
							break;
					}
					s0 = flowNumber + 1 << 24 >> 24;
				}
				return;
			default:
				return;
			case 1:
				this.liquidState = 2;
				return;
		}
	}

	static clearLiquidFlow(flowIndex) {
		Game.liquidFlows[flowIndex - 1] = 0n;
	}

	spawnErasingStreamsFromEmptySources() {
		let streamDir = 0, row = 0, col = 0, emitterDir = 0, startSlot = 0, emitterIndex = 0, s0;
		s0 = 0;
		while (true) {
			emitterIndex = s0;
			if (emitterIndex >= 15) {
				break;
			}
			if (Game.getEmitterBits(emitterIndex, 0, 4) === 3) {
				col = Game.getEmitterBits(emitterIndex, 13, 7);
				row = Game.getEmitterBits(emitterIndex, 20, 7);
				emitterDir = Game.getEmitterBits(emitterIndex, 4, 2);
				Game.liquidEmitters[emitterIndex] = 0n;
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
				this.spawnLiquidFlow(col, row, 7, streamDir, startSlot, this.findEmitterAt(col, row));
			}
			s0 = emitterIndex + 1 << 24 >> 24;
		}
	}

	updatePoolDrain() {
		let slot = 0, nextSlotOrWidth = 0, step = 0, row = 0, width = 0, phase = 0, col = 0, nextRow = 0, slotGraphic = 0, s0, s1, s2, s3, s4, t4, t5;
		col = Game.getFlowBits(this.liquidDrainFlow, 14, 6);
		row = Game.getFlowBits(this.liquidDrainFlow, 20, 6);
		phase = Game.getFlowBits(this.liquidDrainFlow, 47, 2);
		switch (phase) {
			case 1:
				if (row === this.liquidDrainStopRow) {
					this.liquidDrainTick = -1;
					this.liquidFlowTick = -1;
					Game.clearLiquidFlow(this.liquidDrainFlow);
					this.liquidState = 4;
					return;
				}
				width = Game.getFlowBits(this.liquidDrainFlow, 49, 5) << 24 >> 24;
				if (this.liquidDrainTick !== 0 && J.irem(this.liquidDrainTick, width) === 0) {
					this.liquidDrainTick = 0;
					slot = Game.getFlowBits(this.liquidDrainFlow, 26, 2) << 24 >> 24;
					if (slot >= 0) {
						s0 = 0;
						while (true) {
							step = s0;
							if (step >= width) {
								break;
							}
							Game.clearLiquidSlot(col - step | 0, row, slot);
							nextSlotOrWidth = slot;
							nextRow = row;
							nextSlotOrWidth = nextSlotOrWidth + 1 << 24 >> 24;
							if (nextSlotOrWidth > 2) {
								nextSlotOrWidth = 0;
								nextRow++;
							}
							slotGraphic = Game.getLiquidBits(Game.liquidCells[col - step][nextRow], nextSlotOrWidth, 3, 4);
							if (nextRow !== this.liquidDrainStopRow || slot !== 2) {
								if (slotGraphic !== 12 && slotGraphic !== 9) {
									this.setLiquidBits(col - step | 0, nextRow, nextSlotOrWidth, 7, 3, 4);
								}
							} else {
								if (slotGraphic !== 0 && slotGraphic !== 3) {
									this.setLiquidBits(col - step | 0, nextRow, nextSlotOrWidth, 7, 3, 4);
								}
							}
							s0 = step + 1 << 24 >> 24;
						}
						if (slot !== 2) {
							t4 = slot + 1 << 24 >> 24;
							t5 = this.liquidDrainFlow;
							slot = t4;
							s0 = this;
							s1 = t5;
							s2 = slot;
							s3 = 26;
							s4 = 2;
						} else {
							this.setFlowBits(this.liquidDrainFlow, 0, 47, 2);
							this.setFlowBits(this.liquidDrainFlow, 0, 26, 2);
							row++;
							s0 = this;
							s1 = this.liquidDrainFlow;
							s2 = row << 24 >> 24;
							s3 = 20;
							s4 = 6;
						}
						s0.setFlowBits(s1, s2, s3, s4);
					}
				}
				break;
			case 0:
				this.setFlowBits(this.liquidDrainFlow, 1, 47, 2);
				width = Game.getFlowBits(this.liquidDrainFlow, 49, 5) << 24 >> 24;
				slot = Game.getFlowBits(this.liquidDrainFlow, 45, 2) << 24 >> 24;
				step = 0;
				if (slot === 0) {
					if (Game.cellTypes[col + 1][row] - 80 << 24 >> 24 >= 0 || Game.cellTypes[col + 1][row] === 10 || Game.cellTypes[col + 1][row] === 37 || Game.cellTypes[col + 1][row] === 34 || Game.cellTypes[col + 1][row] === 35) {
						while (step < width) {
							step++;
							if (Game.cellTypes[col][row] - 80 << 24 >> 24 >= 0 || Game.cellTypes[col][row] === 10 || Game.cellTypes[col][row] === 37 || Game.cellTypes[col][row] === 34 || Game.cellTypes[col][row] === 35) {
								col--;
							} else {
								step = width;
							}
						}
					} else {
						while (Game.cellTypes[col + 1][row] - 80 << 24 >> 24 < 0 && Game.cellTypes[col + 1][row] !== 10 && Game.cellTypes[col + 1][row] !== 37 && Game.cellTypes[col + 1][row] !== 34 && Game.cellTypes[col + 1][row] !== 35) {
							col++;
						}
					}
				} else {
					if (slot !== 2) {
						while (col <= this.liquidBreachCol && Game.cellTypes[col + 1][row] - 80 << 24 >> 24 < 0 && Game.cellTypes[col + 1][row] !== 10 && Game.cellTypes[col + 1][row] !== 37 && Game.cellTypes[col + 1][row] !== 34 && Game.cellTypes[col + 1][row] !== 35) {
							col++;
						}
					} else {
						while (col >= this.liquidBreachCol && Game.cellTypes[col + 1][row] - 80 << 24 >> 24 < 0 && Game.cellTypes[col + 1][row] !== 10 && Game.cellTypes[col + 1][row] !== 37 && Game.cellTypes[col + 1][row] !== 34 && Game.cellTypes[col + 1][row] !== 35) {
							col++;
						}
					}
				}
				if (this.liquidBreachDir !== 2 && col <= this.liquidBreachCol) {
					while (Game.cellTypes[col + 1][row] - 80 << 24 >> 24 < 0 && Game.cellTypes[col + 1][row] !== 10 && Game.cellTypes[col + 1][row] !== 37 && Game.cellTypes[col + 1][row] !== 34 && Game.cellTypes[col + 1][row] !== 35) {
						col++;
					}
				}
				this.setFlowBits(this.liquidDrainFlow, col << 24 >> 24, 14, 6);
				s0 = 1;
				while (true) {
					nextSlotOrWidth = s0;
					if (Game.cellTypes[col - nextSlotOrWidth][row] - 80 << 24 >> 24 >= 0 || Game.cellTypes[col - nextSlotOrWidth][row] === 10 || Game.cellTypes[col - nextSlotOrWidth][row] === 37 || Game.cellTypes[col - nextSlotOrWidth][row] === 34 || Game.cellTypes[col - nextSlotOrWidth][row] === 35) {
						break;
					}
					s0 = nextSlotOrWidth + 1 << 24 >> 24;
				}
				s0 = this;
				s1 = this.liquidDrainFlow;
				s2 = nextSlotOrWidth;
				s3 = 49;
				s4 = 5;
				s0.setFlowBits(s1, s2, s3, s4);
				break;
			default:
				break;
		}
	}

	updatePoolFill(flowIndex) {
		let overflowOrWidth = 0, row = 0, stepOrRoundUp = 0, width = 0, stepOrExcess = 0, nextRowOrSlots = 0, partialSlots = 0, phase = 0, col = 0, capacity = 0, fillSlot = 0, emitterIndex = 0, filledAmount = 0, sourceAmountLeft = 0, s0;
		col = Game.getFlowBits(flowIndex, 14, 6);
		row = Game.getFlowBits(flowIndex, 20, 6);
		capacity = Game.getFlowBits(flowIndex, 0, 7);
		filledAmount = Game.getFlowBits(flowIndex, 7, 7);
		phase = Game.getFlowBits(flowIndex, 47, 2);
		emitterIndex = Game.getFlowBits(flowIndex, 54, 3) << 24 >> 24;
		sourceAmountLeft = Game.getEmitterBits(emitterIndex, 6, 7) << 24 >> 24;
		switch (phase) {
			case 1:
				width = Game.getFlowBits(flowIndex, 49, 5) << 24 >> 24;
				if (this.liquidFlowTick !== 0 && J.irem(this.liquidFlowTick, width) === 0) {
					this.liquidFlowTick = 0;
					fillSlot = Game.getFlowBits(flowIndex, 26, 2) << 24 >> 24;
					overflowOrWidth = Game.getFlowBits(flowIndex, 57, 1) << 24 >> 24;
					if (fillSlot >= 0) {
						if (overflowOrWidth !== 1) {
							s0 = 0;
							while (true) {
								stepOrExcess = s0;
								if (stepOrExcess >= width) {
									break;
								}
								this.setLiquidBits(col - stepOrExcess | 0, row, fillSlot, 7, 3, 4);
								this.setFlowBits(flowIndex, fillSlot, 43, 2);
								this.setLiquidBits(col - stepOrExcess | 0, row, fillSlot, flowIndex, 0, 3);
								s0 = stepOrExcess + 1 << 24 >> 24;
							}
							if (this.liquidPoolRiseCount > 0) {
								stepOrExcess = fillSlot;
								nextRowOrSlots = row;
								stepOrExcess = stepOrExcess + 1 << 24 >> 24;
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
									if (Game.cellTypes[col - stepOrRoundUp][nextRowOrSlots] - 80 << 24 >> 24 < 0 && Game.cellTypes[col - stepOrRoundUp][nextRowOrSlots] !== 10 && Game.cellTypes[col - stepOrRoundUp][nextRowOrSlots] !== 37 && Game.cellTypes[col - stepOrRoundUp][nextRowOrSlots] !== 34 && Game.cellTypes[col - stepOrRoundUp][nextRowOrSlots] !== 35) {
										this.setLiquidBits(col - stepOrRoundUp | 0, nextRowOrSlots, stepOrExcess, 8, 3, 4);
									}
									s0 = stepOrRoundUp + 1 << 24 >> 24;
								}
							}
							this.liquidPoolRiseCount = this.liquidPoolRiseCount + 1 | 0;
						}
						if (overflowOrWidth === 1 || (filledAmount >= capacity || sourceAmountLeft === 0) && fillSlot === this.liquidFillTargetSlot) {
							if (overflowOrWidth === 1) {
								this.setFlowBits(flowIndex, 0, 57, 1);
							}
							this.setFlowBits(flowIndex, 3, 28, 3);
							if (sourceAmountLeft === 0) {
								this.setEmitterBits(emitterIndex, 3, 0, 4);
								this.setFlowBits(flowIndex, 5, 28, 3);
								if (this.liquidDrainTick === -1) {
									this.liquidFlowTick = -1;
									this.liquidState = 4;
								}
								return;
							}
						}
						if (fillSlot !== 0) {
							fillSlot = fillSlot - 1 << 24 >> 24;
							this.setFlowBits(flowIndex, fillSlot, 26, 2);
							return;
						}
						this.setFlowBits(flowIndex, 0, 47, 2);
						this.setFlowBits(flowIndex, 2, 26, 2);
						return;
					}
				}
				break;
			case 0:
				this.setFlowBits(flowIndex, 1, 47, 2);
				row--;
				this.setFlowBits(flowIndex, row << 24 >> 24, 20, 6);
				fillSlot = 0;
				if (Game.cellTypes[col][row] - 80 << 24 >> 24 >= 0 || Game.cellTypes[col][row] === 10 || Game.cellTypes[col][row] === 37 || Game.cellTypes[col][row] === 34 || Game.cellTypes[col][row] === 35) {
					while (Game.cellTypes[col][row] - 80 << 24 >> 24 >= 0 || Game.cellTypes[col][row] === 10 || Game.cellTypes[col][row] === 37 || Game.cellTypes[col][row] === 34 || Game.cellTypes[col][row] === 35) {
						col = col - 1 | 0;
					}
				} else {
					while (Game.cellTypes[col + 1][row] - 80 << 24 >> 24 < 0 && Game.cellTypes[col + 1][row] !== 10 && Game.cellTypes[col + 1][row] !== 37 && Game.cellTypes[col + 1][row] !== 34 && Game.cellTypes[col + 1][row] !== 35) {
						col++;
					}
				}
				this.setFlowBits(flowIndex, col << 24 >> 24, 14, 6);
				s0 = 1;
				while (true) {
					overflowOrWidth = s0;
					if (Game.cellTypes[col - overflowOrWidth][row] - 80 << 24 >> 24 >= 0 || Game.cellTypes[col - overflowOrWidth][row] === 10 || Game.cellTypes[col - overflowOrWidth][row] === 37 || Game.cellTypes[col - overflowOrWidth][row] === 34 || Game.cellTypes[col - overflowOrWidth][row] === 35) {
						break;
					}
					s0 = overflowOrWidth + 1 << 24 >> 24;
				}
				this.setFlowBits(flowIndex, overflowOrWidth, 49, 5);
				sourceAmountLeft = sourceAmountLeft - overflowOrWidth << 24 >> 24;
				stepOrExcess = 0;
				this.liquidFillTargetSlot = 0;
				if (sourceAmountLeft < 0) {
					nextRowOrSlots = -sourceAmountLeft | 0;
					nextRowOrSlots = nextRowOrSlots * 3 | 0;
					stepOrRoundUp = 0;
					partialSlots = overflowOrWidth + sourceAmountLeft | 0;
					if ((partialSlots * 3 - overflowOrWidth | 0) !== 0) {
						partialSlots = partialSlots * 3 | 0;
						if (partialSlots <= ((overflowOrWidth * 3 | 0) / 2 | 0)) {
							stepOrRoundUp = 1;
						}
					}
					nextRowOrSlots = J.idiv(nextRowOrSlots, overflowOrWidth);
					this.liquidFillTargetSlot = nextRowOrSlots << 24 >> 24;
					this.liquidFillTargetSlot = this.liquidFillTargetSlot + stepOrRoundUp << 24 >> 24;
					if (this.liquidFillTargetSlot > 2) {
						this.setFlowBits(flowIndex, 1, 57, 1);
					}
					stepOrExcess = Math.abs(sourceAmountLeft) << 24 >> 24;
					sourceAmountLeft = 0;
				}
				filledAmount = filledAmount + (overflowOrWidth - stepOrExcess) | 0;
				if (filledAmount > capacity) {
					nextRowOrSlots = capacity - filledAmount | 0;
					filledAmount = filledAmount + nextRowOrSlots | 0;
					sourceAmountLeft = sourceAmountLeft - nextRowOrSlots << 24 >> 24;
				}
				this.setFlowBits(flowIndex, filledAmount << 24 >> 24, 7, 7);
				this.setEmitterBits(emitterIndex, sourceAmountLeft, 6, 7);
				break;
			default:
				break;
		}
	}

	moveStreamSideways(flowIndex, col, row, curDir, slot, dx, isErasing) {
		let result = 0, cornerGraphic = 0, sideGraphic = 0, flowState = 0, s0, s1, s2, s3, s4;
		result = 0;
		if (Game.cellTypes[col + dx][row] - 80 << 24 >> 24 >= 0 || Game.cellTypes[col + dx][row] === 10 || Game.cellTypes[col + dx][row] === 37 || Game.cellTypes[col + dx][row] === 34 || Game.cellTypes[col + dx][row] === 35) {
			result = -2;
		} else {
			result = dx;
			if (curDir !== dx) {
				this.setFlowBits(flowIndex, dx >= 0 ? dx : 2, 45, 2);
			}
			col = col + dx | 0;
			this.setFlowBits(flowIndex, col << 24 >> 24, 31, 6);
			this.setLiquidBits(col, row, slot, flowIndex, 0, 3);
			if (isErasing === 0) {
				cornerGraphic = 0;
				sideGraphic = 0;
				flowState = Game.getFlowBits(flowIndex, 28, 3);
				if (dx <= 0) {
					cornerGraphic = flowState !== 6 || this.liquidBreachCol !== col || this.liquidBreachRow !== row ? 5 : 14;
					s0 = 12;
				} else {
					cornerGraphic = flowState !== 6 || this.liquidBreachCol !== col || this.liquidBreachRow !== row ? 4 : 11;
					s0 = 9;
				}
				sideGraphic = s0;
				if (Game.cellTypes[col][row + 1] - 80 << 24 >> 24 >= 0 || Game.cellTypes[col + dx][row] === 10 || Game.cellTypes[col + dx][row] === 37 || Game.cellTypes[col + dx][row] === 34 || Game.cellTypes[col + dx][row] === 35) {
					s0 = this;
					s1 = col;
					s2 = row;
					s3 = slot;
					s4 = cornerGraphic;
				} else {
					s0 = this;
					s1 = col;
					s2 = row;
					s3 = slot;
					s4 = sideGraphic;
				}
				s0.setLiquidBits(s1, s2, s3, s4, 3, 4);
			} else {
				Game.clearLiquidSlot(col, row, slot);
			}
		}
		return result;
	}

	isLiquidBasinState(cellState) {
		if (cellState === -1 || Game.extractIntBits(cellState, 6, 1) !== 1) {
			return 0;
		}
		return 1;
	}

	static extractIntBits(value, shift, bitCount) {
		return (value >>> shift & (16777215 << bitCount ^ -1)) << 24 >> 24;
	}

	static isFloorSealedBackToWall(col, row, dir) {
		let floorSolid = 0, result = 0, s0;
		result = 1;
		s0 = 1;
		L1: while (true) {
			floorSolid = s0;
			while (true) {
				if (floorSolid === 0) {
					return result;
				}
				floorSolid = 1;
				col = col - dir | 0;
				if (dir !== 0) {
					if (Game.cellTypes[col][row + 1] - 80 << 24 >> 24 < 0 && Game.cellTypes[col][row + 1] !== 10 && Game.cellTypes[col][row + 1] !== 37 && Game.cellTypes[col][row + 1] !== 34 && Game.cellTypes[col][row + 1] !== 35) {
						floorSolid = 0;
					}
					if (Game.cellTypes[col][row] - 80 << 24 >> 24 >= 0 || Game.cellTypes[col][row] === 10 || Game.cellTypes[col][row] === 37 || Game.cellTypes[col][row] === 34 || Game.cellTypes[col][row] === 35) {
						result = floorSolid;
						s0 = 0;
						continue L1;
					}
					if (floorSolid !== 0) {
						continue;
					}
					break L1;
				}
				if (Game.cellTypes[col - 1][row] - 80 << 24 >> 24 >= 0 || Game.cellTypes[col - 1][row] === 10 || Game.cellTypes[col - 1][row] === 37 || Game.cellTypes[col - 1][row] === 34 || Game.cellTypes[col - 1][row] === 35 && Game.cellTypes[col + 1][row] - 80 << 24 >> 24 >= 0 || Game.cellTypes[col + 1][row] === 10 || Game.cellTypes[col + 1][row] === 37 || Game.cellTypes[col + 1][row] === 34 || Game.cellTypes[col + 1][row] === 35) {
					break;
				}
			}
			result = 1;
			s0 = 0;
		}
		return floorSolid;
	}

	updateStreamHead(flowIndex) {
		let slot = 0, row = 0, isErasing = 0, sideResult = 0, animPhase = 0, flowState = 0, col = 0, nextRow = 0, poolFlowIndex = 0, nextSlotOrBelowState = 0, emitterIndex = 0, prevSlot = 0, dir = 0, s1, s2, s3, s4, s5, s6;
		col = Game.getFlowBits(flowIndex, 31, 6);
		row = Game.getFlowBits(flowIndex, 37, 6);
		slot = Game.getFlowBits(flowIndex, 43, 2) << 24 >> 24;
		animPhase = Game.getLiquidBits(Game.liquidCells[col][row], slot, 7, 2) << 24 >> 24;
		dir = Game.getFlowBits(flowIndex, 45, 2) << 24 >> 24;
		flowState = Game.getFlowBits(flowIndex, 28, 3) << 24 >> 24;
		isErasing = flowState === 7 ? 1 : 0;
		sideResult = 0;
		if (dir > 1) {
			dir = -1;
		}
		if (animPhase === 0) {
			nextSlotOrBelowState = slot + 1 << 24 >> 24;
			nextRow = row;
			if (slot === 2) {
				nextSlotOrBelowState = 0;
				nextRow = row + 1 | 0;
			}
			if (Game.getLiquidBits(Game.liquidCells[col][nextRow], nextSlotOrBelowState, 3, 4) === 7) {
				this.liquidPoolRiseCount = 1;
				if (isErasing === 0) {
					prevSlot = nextSlotOrBelowState - 1 | 0;
					if (prevSlot < 0) {
						prevSlot = 2;
					}
					this.liquidFlowTick = 0;
					poolFlowIndex = Game.getLiquidBits(Game.liquidCells[col][nextRow], nextSlotOrBelowState, 0, 3) << 24 >> 24;
					emitterIndex = Game.getFlowBits(flowIndex, 54, 3) << 24 >> 24;
					this.setFlowBits(poolFlowIndex, emitterIndex, 54, 3);
					this.setFlowBits(poolFlowIndex, 2, 28, 3);
					this.setFlowBits(poolFlowIndex, 0, 47, 2);
					this.setFlowBits(poolFlowIndex, prevSlot << 24 >> 24, 26, 2);
					this.setFlowBits(poolFlowIndex, col << 24 >> 24, 14, 6);
					this.setFlowBits(poolFlowIndex, nextRow << 24 >> 24, 20, 6);
					this.setFlowBits(poolFlowIndex, 0, 57, 1);
					Game.clearLiquidFlow(flowIndex);
					return;
				}
				Game.clearLiquidFlow(flowIndex);
				this.liquidState = 3;
				this.liquidStartNextEmitter = 1;
				return;
			}
		}
		if (slot === 2 && animPhase === 0) {
			if (Game.cellTypes[col][row + 1] - 80 << 24 >> 24 >= 0 || Game.cellTypes[col][row + 1] === 10 || Game.cellTypes[col][row + 1] === 37 || Game.cellTypes[col][row + 1] === 34 || Game.cellTypes[col][row + 1] === 35) {
				if (dir !== 0) {
					s1 = flowIndex;
					s2 = col;
					s3 = row;
					s4 = dir;
					s5 = slot;
					s6 = dir;
					sideResult = this.moveStreamSideways(s1, s2, s3, s4, s5, s6, isErasing);
				} else {
					if (isErasing === 0) {
						this.setLiquidBits(col, row, slot, 15, 3, 4);
					} else {
						Game.clearLiquidSlot(col, row, slot);
					}
					sideResult = this.moveStreamSideways(flowIndex, col, row, dir, slot, 1, isErasing);
					if (sideResult >= 0) {
						if (Game.cellTypes[col - 1][row] - 80 << 24 >> 24 < 0 && Game.cellTypes[col - 1][row] !== 10 && Game.cellTypes[col - 1][row] !== 37 && Game.cellTypes[col - 1][row] !== 34 && Game.cellTypes[col - 1][row] !== 35) {
							this.spawnLiquidFlow(col - 1 | 0, row, isErasing === 0 ? 5 : 7, -1, 2, Game.getFlowBits(flowIndex, 54, 3) << 24 >> 24);
						}
					} else {
						s1 = flowIndex;
						s2 = col;
						s3 = row;
						s4 = dir;
						s5 = slot;
						s6 = -1;
						sideResult = this.moveStreamSideways(s1, s2, s3, s4, s5, s6, isErasing);
					}
				}
				if (sideResult !== -2) {
					dir = sideResult;
					col = col + dir | 0;
				} else {
					nextSlotOrBelowState = Game.cellStates[col][row + 1];
					if (!this.isLiquidBasinState(nextSlotOrBelowState) || !Game.isFloorSealedBackToWall(col, row, dir)) {
						s1 = flowIndex;
						s2 = 3;
						s3 = 28;
						s4 = 3;
					} else {
						this.liquidPoolRiseCount = 0;
						this.liquidFlowTick = 0;
						this.setFlowBits(flowIndex, 2, 28, 3);
						this.setFlowBits(flowIndex, Game.extractIntBits(nextSlotOrBelowState, 0, 6), 0, 7);
						this.setFlowBits(flowIndex, 2, 26, 2);
						this.setFlowBits(flowIndex, col << 24 >> 24, 14, 6);
						s1 = flowIndex;
						s2 = row + 1 << 24 >> 24;
						s3 = 20;
						s4 = 6;
					}
					this.setFlowBits(s1, s2, s3, s4);
					col = col + dir | 0;
				}
			} else {
				if (dir !== 0) {
					dir = 0;
					this.setFlowBits(flowIndex, 0, 45, 2);
				}
			}
		}
		B16: {
			if (sideResult !== -2) {
				switch (dir) {
					case 0:
						this.moveStreamDown(flowIndex, col, row, slot, isErasing);
						return;
					case -1:
					case 1:
						this.advanceLiquidAnimPhase(col, row, slot, animPhase);
						break B16;
					default:
						return;
				}
			}
		}
	}

	advanceLiquidAnimPhase(col, row, slot, animPhase) {
		animPhase = animPhase + 1 << 24 >> 24;
		if (animPhase > 2) {
			animPhase = 0;
		}
		this.setLiquidBits(col, row, slot, animPhase, 7, 2);
	}

	moveStreamDown(flowIndex, col, row, slot, isErasing) {
		let s1, s2, s3, s4;
		if (isErasing === 0 && Game.getLiquidBits(Game.liquidCells[col][row], slot, 3, 4) === 0) {
			this.setLiquidBits(col, row, slot, 3, 3, 4);
		}
		slot = slot + 1 << 24 >> 24;
		if (slot > 2) {
			slot = 0;
			row++;
			this.setFlowBits(flowIndex, row << 24 >> 24, 37, 6);
		}
		this.setFlowBits(flowIndex, slot, 43, 2);
		if (isErasing === 0) {
			this.setLiquidBits(col, row, slot, flowIndex, 0, 3);
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
		this.setLiquidBits(s1, s2, s3, s4, 3, 4);
	}

	spawnSourceStream(col, row) {
		this.liquidState = 1;
		this.spawnLiquidFlow(col, row + 1 | 0, 0, 0, 0, this.findEmitterAt(col, row));
	}

	static clearLiquidSlot(col, row, slot) {
		let cellValue = 0, shift = 0, slotBits = 0;
		cellValue = Game.liquidCells[col][row];
		shift = slot * 9 << 24 >> 24;
		slotBits = cellValue >>> shift | 0;
		slotBits = slotBits & 511;
		slotBits = slotBits << shift;
		cellValue = cellValue ^ slotBits;
		Game.liquidCells[col][row] = cellValue;
		Game.cellUpdateTimers[col][row] = 24;
	}

	spawnLiquidFlow(col, row, graphic, dir, slot, emitterIndex) {
		let flowIndex = 0, s0;
		s0 = 1;
		while (true) {
			flowIndex = s0;
			if (flowIndex > 15) {
				break;
			}
			if (Game.getFlowBits(flowIndex, 28, 3) !== 0) {
				s0 = flowIndex + 1 << 24 >> 24;
				continue;
			}
			break;
		}
		Game.liquidFlows[flowIndex - 1] = 0n;
		if (graphic !== 7) {
			this.setFlowBits(flowIndex, 1, 28, 3);
			this.setFlowBits(flowIndex, emitterIndex, 54, 3);
			this.setLiquidBits(col, row, slot, flowIndex, 0, 3);
			this.setLiquidBits(col, row, slot, graphic, 3, 4);
		} else {
			Game.clearLiquidSlot(col, row, slot);
			this.setFlowBits(flowIndex, 7, 28, 3);
		}
		this.setFlowBits(flowIndex, col << 24 >> 24, 31, 6);
		this.setFlowBits(flowIndex, row << 24 >> 24, 37, 6);
		this.setFlowBits(flowIndex, slot, 43, 2);
		if (dir < 0) {
			dir = 2;
		}
		this.setFlowBits(flowIndex, dir, 45, 2);
		return flowIndex;
	}

	getLiquidSlotGraphic(col, row, cellValue, slot) {
		let flowIndex = 0, headSlot = 0, headCol = 0, headRow = 0, graphic = 0, s0;
		flowIndex = Game.getLiquidBits(cellValue, slot, 0, 3) << 24 >> 24;
		headCol = Game.getFlowBits(flowIndex, 31, 6);
		headRow = Game.getFlowBits(flowIndex, 37, 6);
		headSlot = Game.getFlowBits(flowIndex, 43, 2);
		graphic = Game.getLiquidBits(cellValue, slot, 3, 4);
		if (headCol !== col || headRow !== row || headSlot !== slot) {
			switch (graphic) {
				case 6:
					Game.clearLiquidSlot(col, row, slot);
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

	checkLiquidBreachAt(col, row) {
		let s1;
		if (this.hasWaterLayer) {
			if (Game.liquidCells[col - 1][row] === 0) {
				s1 = Game.liquidCells[col + 1][row] === 0 ? 0 : 1;
			} else {
				s1 = -1;
			}
			this.liquidBreachDir = s1;
			if (this.liquidBreachDir === 0) {
				this.liquidBreachDir = Game.liquidCells[col][row - 1] === 0 ? 0 : 2;
			}
			if (this.liquidBreachDir !== 0) {
				this.liquidState = 5;
				this.playSound(13);
				this.liquidBreachCol = col;
				this.liquidBreachRow = row;
			}
		}
	}

	spreadLiquidThroughBreach(col, row) {
		let needFlow = 0, flowIndex = 0, searchSteps = 0, total = 0, offset = 0, dir = 0, s0;
		flowIndex = 0;
		needFlow = 1;
		offset = 0;
		dir = this.liquidBreachDir;
		total = 0;
		L1: while (true) {
			searchSteps = 0;
			while (Game.liquidCells[col + dir][row - 1] !== 0 && Game.cellTypes[col][row] - 80 << 24 >> 24 >= 0 || Game.cellTypes[col][row] === 10 || Game.cellTypes[col][row] === 37 || Game.cellTypes[col][row] === 34 || Game.cellTypes[col][row] === 35) {
				col = col + dir | 0;
			}
			s0 = 0;
			while (true) {
				offset = s0;
				if (Game.cellTypes[col + offset][row] - 80 << 24 >> 24 >= 0 || Game.cellTypes[col + offset][row] === 10 || Game.cellTypes[col + offset][row] === 37 || Game.cellTypes[col + offset][row] === 34 || Game.cellTypes[col + offset][row] === 35) {
					break;
				}
				if (needFlow !== 0) {
					needFlow = 0;
					flowIndex = this.spawnLiquidFlow(col, row, 8, -2, 2, 0);
					this.setFlowBits(flowIndex, 5, 28, 3);
					this.setFlowBits(flowIndex, col << 24 >> 24, 14, 6);
					this.setFlowBits(flowIndex, row << 24 >> 24, 20, 6);
				}
				this.setLiquidBits(col + offset | 0, row, 2, flowIndex, 0, 3);
				s0 = offset + dir | 0;
			}
			offset = Math.abs(offset) | 0;
			total = total + offset | 0;
			row++;
			while (Game.liquidCells[col][row] === 0) {
				col = col + dir | 0;
				if (searchSteps >= offset || col < 0 || col === this.levelW) {
					break L1;
				}
				searchSteps++;
			}
		}
		if (total > 0) {
			this.setFlowBits(flowIndex, total << 24 >> 24, 7, 7);
		}
		return total;
	}

	startLiquidBreachDrain(col, row) {
		let emitterCol = 0, streamDir = 0, stopRow = 0, poolAmount = 0, emitterRow = 0, emitterOrFlowIndex = 0, remainingAmount = 0, cellValue = 0, s0, s1, s2, s3, s4, s5;
		this.liquidDrainTick = 0;
		cellValue = 0;
		if (this.liquidBreachDir <= 1) {
			s0 = Game.liquidCells[col + this.liquidBreachDir];
			s1 = row;
		} else {
			s0 = Game.liquidCells[col];
			s1 = row - 1 | 0;
		}
		cellValue = s0[s1];
		this.liquidDrainFlow = Game.getLiquidBits(cellValue, 2, 0, 3) << 24 >> 24;
		this.setFlowBits(this.liquidDrainFlow, 0, 47, 2);
		poolAmount = Game.getFlowBits(this.liquidDrainFlow, 7, 7);
		streamDir = 0;
		emitterCol = 0;
		stopRow = 0;
		remainingAmount = 0;
		emitterRow = 0;
		switch (this.liquidBreachDir) {
			default:
				streamDir = this.liquidBreachDir;
				emitterCol = col + streamDir | 0;
				streamDir = streamDir >= 0 ? 2 : 1;
				stopRow = row + 1 | 0;
				remainingAmount = poolAmount - this.spreadLiquidThroughBreach(emitterCol, stopRow) | 0;
				emitterRow = row;
				this.liquidBreachCol = col;
				this.liquidBreachRow = row;
				break;
			case 2:
				streamDir = 0;
				emitterCol = col;
				stopRow = row;
				remainingAmount = poolAmount;
				emitterRow = row - 1 | 0;
				this.liquidBreachRow = -1;
				this.liquidBreachCol = -1;
				break;
		}
		this.setFlowBits(this.liquidDrainFlow, streamDir << 24 >> 24, 45, 2);
		this.liquidDrainStopRow = stopRow;
		this.addLiquidEmitter(remainingAmount << 24 >> 24, emitterCol << 24 >> 24, emitterRow << 24 >> 24, streamDir << 24 >> 24);
		emitterOrFlowIndex = this.findEmitterAt(emitterCol, emitterRow);
		this.setEmitterBits(emitterOrFlowIndex, 2, 0, 4);
		this.liquidState = 1;
		switch (this.liquidBreachDir) {
			case 2:
				s0 = this;
				s1 = emitterCol;
				s2 = row;
				s3 = 3;
				s4 = 0;
				s5 = 0;
				emitterOrFlowIndex = s0.spawnLiquidFlow(s1, s2, s3, s4, s5, emitterOrFlowIndex);
				break;
			case 1:
				s0 = this;
				s1 = emitterCol - 1 | 0;
				s2 = row;
				s3 = 14;
				s4 = -1;
				s5 = 2;
				emitterOrFlowIndex = s0.spawnLiquidFlow(s1, s2, s3, s4, s5, emitterOrFlowIndex);
				break;
			case -1:
				s0 = this;
				s1 = emitterCol + 1 | 0;
				s2 = row;
				s3 = 11;
				s4 = 1;
				s5 = 2;
				emitterOrFlowIndex = s0.spawnLiquidFlow(s1, s2, s3, s4, s5, emitterOrFlowIndex);
				break;
			default:
				break;
		}
		this.setFlowBits(emitterOrFlowIndex, 6, 28, 3);
		this.liquidBreachDir = 0;
	}

	openLiquidEmitter(col, row) {
		let result = 0;
		result = this.setEmitterStateAt(col, row, 2);
		if (result > 0) {
			Game.cellTypes[col][row] = -1;
			this.spawnSourceStream(col, row);
		}
	}

	static getFrameHeight(pack, frame) {
		let boundsIndex = 0;
		boundsIndex = (frame << 2) + 3 | 0;
		return pack.frameBounds[boundsIndex] & 255;
	}

	static getFrameWidth(pack, frame) {
		let boundsIndex = 0;
		boundsIndex = (frame << 2) + 2 | 0;
		return pack.frameBounds[boundsIndex] & 255;
	}

	static loadTipPage(tipIndex) {
		let pageStart = 0, pageEnd = 0, offsetTable = null, input = null, pageCount = 0, s0;
		try {
			Game.tipSprites = tipIndex > 5 ? null : Game.loadSpritePack("/tips.f", tipIndex);
			input = new ByteArrayInputStream(Game.readResource("/tipst.f", 0));
			pageCount = input.read();
			tipIndex = J.irem(tipIndex, pageCount);
			offsetTable = new Int8Array((pageCount + 1 | 0) * 2 | 0);
			input.read(offsetTable);
			pageStart = Game.readU16LE(offsetTable, tipIndex << 1);
			pageEnd = Game.readU16LE(offsetTable, tipIndex + 1 << 1);
			input.skip(BigInt(pageStart));
			Game.tipPageData = new Int8Array(pageEnd - pageStart | 0);
			input.read(Game.tipPageData);
			input.close();
		} catch (ex) {
			ex = J.exc(ex);
			if (J.isa(ex, "java/lang/Exception")) {
				s0 = ex;
				return;
			}
			else throw ex;
		}
	}

	drawTipPage() {
		let itemType = 0, itemCount = 0, pos = 0, textStart = 0, measuring = 0, iconCount = 0, g = null, itemIndex = 0, iconDataStart = 0, frameOrTextLength = 0, y = 0, s0, s1, t1;
		Game.spritePacks[41].lineSpacing = 5;
		pos = 0;
		t1 = Game.tipPageData;
		pos++;
		itemCount = t1[0];
		this.loadingFullRedraw = 0;
		g = this.screenGraphics;
		g.setColor(798521);
		g.fillRoundRect(20, 60, 200, 200, 8, 8);
		g.setColor(13540096);
		g.drawRoundRect(20, 60, 200, 200, 8, 8);
		y = 0;
		measuring = 1;
		itemIndex = 0;
		while (true) {
			if (itemIndex > itemCount) {
				return;
			}
			if (itemIndex !== itemCount) {
				itemType = Game.tipPageData[pos++];
				if (itemType !== 0) {
					pos += 2;
					pos += 2;
					frameOrTextLength = Game.tipPageData[pos++] & 255;
					if (Game.tipSprites !== null) {
						if (measuring === 0) {
							Game.tipSprites.drawFrame(g, frameOrTextLength, (240 - Game.tipSprites.frameBounds[(frameOrTextLength << 2) + 2] & 255) >> 1, y, 0, 0, 0);
						}
						s0 = y;
						s1 = Game.tipSprites.frameBounds[(frameOrTextLength << 2) + 3] & 255;
						y = s0 + s1 | 0;
					}
				} else {
					pos += 2;
					pos += 2;
					frameOrTextLength = Game.readU16LE(Game.tipPageData, pos);
					pos += 2;
					textStart = pos;
					pos = pos + frameOrTextLength | 0;
					iconCount = Game.tipPageData[pos++];
					iconDataStart = pos;
					pos = pos + iconCount | 0;
					y -= 3;
					s0 = y;
					s1 = this.drawWrappedRichText(g, Game.tipPageData, Game.spritePacks[41], textStart, frameOrTextLength, measuring === 0 ? y : -1, Game.tipSprites, iconDataStart, 192);
					y = s0 + s1 | 0;
				}
				y += 4;
			} else {
				if (measuring === 0) {
					break;
				}
				measuring = 0;
				itemIndex = -1;
				pos = 1;
				y -= 4;
				y = 60 + (200 - y >> 1) | 0;
			}
			itemIndex++;
		}
	}

	static drawTextInBox(g, font, text, x, y, anchor, lineSpacing, multiline) {
		let boxY = 0, textHeight = 0, textWidth = 0, boxX = 0, s0, s1;
		font.lineSpacing = lineSpacing;
		if ((text.endsWith("\n") ? 1 : 0)) {
			text = text.substring(0, text.length - 1 | 0);
		}
		text = Game.wrapText(text, 230);
		textWidth = Game.measureFirstLineWidth(font, text, multiline === 0 ? 0 : -1);
		textHeight = font.measureTextHeight(text);
		boxX = x;
		boxY = y;
		if ((anchor & 32) === 0) {
			if ((anchor & 2) !== 0) {
				s0 = boxY;
				s1 = textHeight >> 1;
				boxY = s0 - s1 | 0;
			}
		} else {
			s0 = boxY;
			s1 = textHeight;
			boxY = s0 - s1 | 0;
		}
		if ((anchor & 8) === 0) {
			if ((anchor & 1) !== 0) {
				s0 = boxX;
				s1 = textWidth >> 1;
				boxX = s0 - s1 | 0;
			}
		} else {
			s0 = boxX;
			s1 = textWidth;
			boxX = s0 - s1 | 0;
		}
		g.setColor(798521);
		g.fillRoundRect(boxX - 5 | 0, boxY - 5 | 0, textWidth + 10 | 0, textHeight + 10 | 0, 10, 10);
		g.setColor(13540096);
		g.drawRoundRect(boxX - 5 | 0, boxY - 5 | 0, textWidth + 10 | 0, textHeight + 10 | 0, 10, 10);
		font.drawMultilineString(g, text, x, y, anchor);
	}

	drawWrappedRichText(g, text, font, start, length, y, iconPack, iconDataStart, maxWidth) {
		let doDraw = 0, xAtLastSpace = 0, iconIndex = 0, savedPalette = 0, pos = 0, glyph = 0, measuring = 0, ch = 0, x = 0, lineHeight = 0, lastSpacePos = 0, lineStart = 0, lineY = 0, s0, s1, s2, t2, t3;
		iconIndex = 0;
		y = y - font.frameModules[2] | 0;
		lineHeight = font.lineSpacing + (font.moduleSizes[1] & 255) | 0;
		x = 0;
		lineY = y;
		doDraw = y !== -1 ? 1 : 0;
		savedPalette = font.paletteIndex;
		lineStart = start;
		measuring = 1;
		lastSpacePos = start;
		xAtLastSpace = 0;
		for (pos = start; pos <= (start + length | 0); pos++) {
			ch = 10;
			if (pos < (start + length | 0)) {
				ch = text[pos] & 255;
			}
			if (measuring === 0 || x <= maxWidth) {
				if (ch !== 10) {
					if (ch <= 32) {
						if (ch !== 32) {
							if (ch !== 1) {
								if (ch === 2) {
									pos++;
									s0 = text;
									s1 = pos;
									t2 = s0[s1] & 255;
									ch = t2;
									if (ch < font.getFrameModuleCount(0)) {
										glyph = (font.frameModules[ch << 2] & 255) << 1;
										if (measuring === 0 && doDraw !== 0) {
											font.drawFramePart(g, 0, ch, x, lineY, 0);
										}
										s0 = x;
										s1 = font.moduleSizes[glyph] & 255;
										s2 = font.frameModules[(ch << 2) + 1];
									} else {
										glyph = ch - font.getFrameModuleCount(0) | 0;
										if (measuring === 0 && doDraw !== 0) {
											font.drawFrame(g, glyph, x, lineY, 0, 0, 0);
										}
										s0 = x;
										s1 = font.frameBounds[(glyph << 2) + 2] & 255;
										s2 = font.frameBounds[glyph << 2] & 255;
									}
									t3 = s1 - s2 | 0;
									s1 = t3;
									x = s0 + (s1 + font.frameModules[1]) | 0;
								}
							} else {
								pos++;
								font.paletteIndex = text[pos];
							}
						} else {
							lastSpacePos = pos;
							xAtLastSpace = x;
							s0 = x;
							s1 = font.moduleSizes[0] & 255;
							x = s0 + (s1 + font.frameModules[1]) | 0;
						}
					} else {
						if (ch !== 64 || iconPack === null) {
							s0 = SpritePack.charMap;
							s1 = ch;
							t2 = s0[s1] & 255;
							ch = t2;
							if (ch < font.getFrameModuleCount(0)) {
								glyph = (font.frameModules[ch << 2] & 255) << 1;
								if (measuring === 0 && doDraw !== 0) {
									font.drawFramePart(g, 0, ch, x, lineY, 0);
								}
								s0 = x;
								s1 = font.moduleSizes[glyph] & 255;
								s2 = font.frameModules[(ch << 2) + 1];
							} else {
								glyph = ch - font.getFrameModuleCount(0) | 0;
								if (measuring === 0 && doDraw !== 0) {
									font.drawFrame(g, glyph, x, lineY, 0, 0, 0);
								}
								s0 = x;
								s1 = font.frameBounds[(glyph << 2) + 2] & 255;
								s2 = font.frameBounds[glyph << 2] & 255;
							}
							t3 = s1 - s2 | 0;
							s1 = t3;
							x = s0 + (s1 + font.frameModules[1]) | 0;
						} else {
							if (measuring === 0 && doDraw !== 0) {
								iconPack.drawFrame(g, text[iconIndex + iconDataStart], x, lineY, 0, 0, 0);
							}
							x = x + Game.getFrameWidth(iconPack, text[iconIndex + iconDataStart]) | 0;
							glyph = Game.getFrameHeight(iconPack, text[iconIndex + iconDataStart]);
							if (glyph > lineHeight) {
								lineHeight = glyph;
							}
							iconIndex++;
						}
					}
				} else {
					if (measuring === 0 || doDraw === 0) {
						x = 0;
						lineStart = pos + 1 | 0;
						lineY = lineY + lineHeight | 0;
						lineHeight = font.lineSpacing + (font.moduleSizes[1] & 255) | 0;
					} else {
						x = 120 - (x >> 1) | 0;
						pos = lineStart - 1 | 0;
						iconIndex = 0;
					}
					if (doDraw !== 0) {
						measuring = measuring === 0 ? 1 : 0;
					}
				}
			} else {
				x = xAtLastSpace;
				text[lastSpacePos] = 10;
				pos = lastSpacePos - 1 | 0;
			}
		}
		font.paletteIndex = savedPalette;
		return lineY - y | 0;
	}

	freeStageMapResources() {
		this.needFreeMapRes = 0;
		Game.freeSpritePack(Game.spritePacks[23], 1);
		Game.spritePacks[23] = null;
		Game.freeSpritePack(Game.spritePacks[24], 1);
		Game.spritePacks[24] = null;
		Game.freeSpritePack(Game.spritePacks[25], 1);
		Game.spritePacks[25] = null;
		Game.freeSpritePack(Game.spritePacks[26], 1);
		Game.spritePacks[26] = null;
		Game.freeSpritePack(Game.spritePacks[17], 1);
		Game.spritePacks[17] = null;
		this.unlockPathPoints = null;
		Game.stageMapImage = null;
		Game.stageMapGraphics = null;
		JSystem.gc();
	}

	openStageMap() {
		this.resetCounters();
		this.stageMapImageNeeded = 1;
		this.needsFullRedraw = 1;
		this.markerWalkRestart = 1;
		Game.screen = 21;
		this.loadingStep = 0;
		this.loadingStepCount = 14;
		this.firstSecretStage = 100;
		if (this.stage > this.getSavedLatestStage(this.world)) {
			this.stage = this.getSavedLatestStage(this.world);
		}
		this.allocStageMapNodes();
	}

	allocStageMapNodes() {
		Game.stageMapNodes = J.multiArray(BigInt64Array, 2, [12, 12]);
		this.unlockPathPoints = new Int32Array(20);
	}

	static extractLongBits(value, shift, bitCount) {
		value = BigInt.asIntN(64, BigInt.asUintN(64, value) >> BigInt(shift & 63));
		value = value & (BigInt.asIntN(64, (-1n) << BigInt(bitCount & 63)) ^ (-1n));
		return Number(BigInt.asIntN(32, value));
	}

	setStageMapNodeBits(col, row, value, shift, bitCount) {
		let node = 0n, oldBits = 0n, newBits = 0n;
		node = Game.stageMapNodes[col][row];
		oldBits = BigInt(Game.extractLongBits(node, shift, bitCount));
		oldBits = BigInt.asIntN(64, oldBits << BigInt(shift & 63));
		node = node ^ oldBits;
		newBits = BigInt(value);
		newBits = BigInt.asIntN(64, newBits << BigInt(shift & 63));
		node = node | newBits;
		Game.stageMapNodes[col][row] = node;
	}

	drawStageMapScreen() {
		if (this.stageMapImageNeeded) {
			Game.stageMapImage = Image.createImage(186, 226);
		}
		if (this.needsFullRedraw) {
			this.needsFullRedraw = 0;
			this.stageMapAnimating = 1;
			this.drawStageMapBackground();
			this.drawStageMapNodes();
		}
		if (this.stageMapAnimating) {
			this.screenGraphics.drawImage(Game.stageMapImage, 27, 56, 0);
			this.drawStageMapTopBar();
			this.updateMapMarker();
			this.drawStageMapStageLabel();
			this.drawStageDiamondTooltip();
		}
		if (this.stageMapAnimating && this.mapMarkerCol === this.mapTargetCol && this.mapMarkerRow === this.mapTargetRow) {
			this.stageMapAnimating = 0;
		}
	}

	drawStageMapStageLabel() {
		let stageIndex = 0, node = 0n, s0, s1, s2, s3;
		node = Game.stageMapNodes[this.mapMarkerCol][this.mapMarkerRow];
		stageIndex = Game.extractLongBits(node, 6, 5);
		if (stageIndex >= this.firstSecretStage) {
			s0 = Game.spritePacks[41];
			s1 = this.screenGraphics;
			s2 = new StringBuffer().append(Game.secretStageLabelPrefix.toString());
			s3 = stageIndex - this.firstSecretStage | 0;
		} else {
			s0 = Game.spritePacks[41];
			s1 = this.screenGraphics;
			s2 = new StringBuffer().append(Game.stageLabelPrefix.toString());
			s3 = stageIndex;
		}
		s0.drawString(s1, s2.append(s3 + 1 | 0).toString(), 8, 45, 6);
	}

	drawStageDiamondTooltip() {
		let boxY = 0, boxW = 0, markerY = 0, total = 0, stageIndex = 0, collected = 0, boxX = 0, node = 0n, markerX = 0;
		if (this.mapMarkerCol !== this.mapTargetCol || this.mapMarkerRow !== this.mapTargetRow) {
			return;
		}
		node = Game.stageMapNodes[this.mapMarkerCol][this.mapMarkerRow];
		stageIndex = Game.extractLongBits(node, 6, 5);
		collected = 0;
		collected = this.getStageBankedRedDiamonds(this.world, stageIndex);
		total = this.getStageRedDiamondTotal(this.world, stageIndex);
		if (collected > total) {
			collected = total;
		}
		Game.scratchText.delete(0, Game.scratchText.length());
		Game.scratchText.append(collected);
		Game.scratchText.append(String.fromCharCode(47));
		Game.scratchText.append(total);
		Game.spritePacks[41].measureString(Game.scratchText.toString());
		boxW = SpritePack.textWidth + 6 + 14 | 0;
		markerX = 37 + this.mapMarkerCol * 13 + 6 | 0;
		markerY = 73 + this.mapMarkerRow * 13 + 6 | 0;
		boxX = markerX - (boxW >> 1) + 0 | 0;
		boxY = markerY - 17 - 31 | 0;
		if (boxY <= 63) {
			boxY = 63;
			boxX = markerX + 20 | 0;
			if ((boxX + boxW | 0) >= 200) {
				boxX = markerX - boxW - 20 | 0;
			}
		}
		if (boxX <= 35) {
			boxX = 35;
		}
		if ((boxX + boxW | 0) >= 200) {
			boxX = 150;
		}
		Game.drawFramedBox(this.screenGraphics, boxX, boxY, boxW, 17, 37042, 0);
		Game.spritePacks[41].drawString(this.screenGraphics, Game.scratchText.toString(), boxX + 2 | 0, boxY + 2 - 1 | 0, 20);
		if (Game.spritePacks[17] !== null) {
			Game.spritePacks[17].drawFrame(this.screenGraphics, 10, boxX + boxW - 2 - 14 | 0, boxY + 2 - 1 | 0, 0, 0, 0);
		}
	}

	resetUnlockPathAnimation() {
		this.unlockFlashFrame = 0;
		this.unlockPathCoordCount = 0;
		this.unlockPathDotsShown = 0;
		this.unlockRevealDone = 0;
		this.recordUnlockPath = 1;
		this.unlockPathShown = 0;
		this.unlockPathDotDelay = 2;
		this.unlockNodeBlinkTimer = 2;
		this.unlockPathReversed = 0;
	}

	animateUnlockPath() {
		let explorerFrame = 0, nodeY = 0, nodeOffset = 0, pathType = 0, nodeX = 0, done = 0, dotFrame = 0, targetType = 0, dotsDrawn = 0, showTargetIcon = 0, targetNode = 0n, markerNode = 0n, dotCount = 0, nodeFrame = 0, dotIndex = 0, markerType = 0, dotStep = 0, s0, s1;
		done = 0;
		dotCount = this.unlockPathCoordCount >> 1;
		if (this.unlockPathDotDelay >= 0) {
			s0 = this;
			s1 = this.unlockPathDotDelay - 1 | 0;
		} else {
			s0 = this;
			s1 = 2;
		}
		s0.unlockPathDotDelay = s1;
		if (this.mapTargetCol === 0 && this.mapTargetRow === 0) {
			this.mapTargetCol = this.mapMarkerCol;
			this.mapTargetRow = this.mapMarkerRow;
		}
		if (this.unlockPathDotDelay === 0) {
			if (this.unlockPathDotsShown !== dotCount) {
				this.unlockPathDotsShown = this.unlockPathDotsShown + 1 | 0;
				s0 = 0;
			} else {
				s0 = 1;
			}
			done = s0;
		}
		markerNode = Game.stageMapNodes[this.mapMarkerCol][this.mapMarkerRow];
		markerType = Game.extractLongBits(markerNode, 3, 3);
		targetNode = Game.stageMapNodes[this.mapTargetCol][this.mapTargetRow];
		targetType = Game.extractLongBits(targetNode, 3, 3);
		dotFrame = 0;
		pathType = 0;
		pathType = markerType === 1 || targetType === 1 ? 1 : markerType;
		switch (pathType) {
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
		dotsDrawn = 0;
		dotIndex = !this.unlockPathReversed ? 0 : dotCount - 1 | 0;
		dotStep = !this.unlockPathReversed ? 1 : -1;
		while (dotsDrawn < this.unlockPathDotsShown) {
			nodeFrame = dotIndex * 2 | 0;
			Game.spritePacks[17].drawFrame(this.screenGraphics, dotFrame, this.unlockPathPoints[nodeFrame], this.unlockPathPoints[nodeFrame + 1], 0, 0, 0);
			dotsDrawn++;
			dotIndex = dotIndex + dotStep | 0;
		}
		nodeFrame = 0;
		nodeOffset = 0;
		switch (markerType) {
			case 1:
				nodeOffset = 2;
				s0 = 9;
				nodeFrame = s0;
				break;
			case 0:
				nodeOffset = 0;
				s0 = 0;
				nodeFrame = s0;
				break;
			default:
				break;
		}
		nodeX = this.mapMarkerCol * 13 + nodeOffset + 37 | 0;
		nodeY = this.mapMarkerRow * 13 + nodeOffset + 73 | 0;
		Game.spritePacks[17].drawFrame(this.screenGraphics, nodeFrame, nodeX, nodeY, 0, 0, 0);
		explorerFrame = !this.markerFacingLeft ? 6 : 7;
		Game.spritePacks[17].drawFrame(this.screenGraphics, explorerFrame, nodeX + 6 | 0, nodeY + 6 | 0, 0, 0, 0);
		showTargetIcon = 1;
		if (dotsDrawn === dotCount) {
			if (this.unlockNodeBlinkTimer >= 0) {
				s0 = this;
				s1 = this.unlockNodeBlinkTimer - 1 | 0;
			} else {
				s0 = this;
				s1 = 2;
			}
			s0.unlockNodeBlinkTimer = s1;
			if (this.unlockNodeBlinkTimer === 0) {
				this.unlockNodeBlinkTimer = 1;
				showTargetIcon = 0;
			}
		}
		if (showTargetIcon !== 0) {
			switch (targetType) {
				case 1:
					nodeOffset = 2;
					s0 = 5;
					nodeFrame = s0;
					break;
				case 0:
					nodeOffset = 0;
					s0 = 1;
					nodeFrame = s0;
					break;
				default:
					break;
			}
		} else {
			switch (targetType) {
				case 1:
					nodeOffset = 2;
					s0 = 9;
					nodeFrame = s0;
					break;
				case 0:
					nodeOffset = 0;
					s0 = 0;
					nodeFrame = s0;
					break;
				default:
					break;
			}
		}
		nodeX = this.mapTargetCol * 13 + nodeOffset + 37 | 0;
		nodeY = this.mapTargetRow * 13 + nodeOffset + 73 | 0;
		Game.spritePacks[17].drawFrame(this.screenGraphics, nodeFrame, nodeX, nodeY, 0, 0, 0);
		if (showTargetIcon === 0) {
			if (this.unlockFlashFrame !== Game.spritePacks[9].getAnimFrameCount(0)) {
				s0 = 0;
			} else {
				this.unlockFlashFrame = this.unlockFlashFrame - 1 | 0;
				this.unlockRevealDone = 1;
				s0 = 1;
			}
			done = s0;
			if (!this.stageWasCompleted) {
				Game.spritePacks[9].drawFrame(this.screenGraphics, this.unlockFlashFrame, nodeX, nodeY, 0, 0, 0);
			}
			this.unlockFlashFrame = this.unlockFlashFrame + 1 | 0;
		}
		return done;
	}

	updateMapMarker() {
		let markerY = 0, targetXOrFrame = 0, arrived = 0, markerX = 0, targetY = 0;
		markerX = 37 + this.mapMarkerCol * 13 + 6 | 0;
		markerY = 73 + this.mapMarkerRow * 13 + 6 | 0;
		if (this.mapMarkerCol !== this.mapTargetCol || this.mapMarkerRow !== this.mapTargetRow) {
			targetXOrFrame = 37 + this.mapTargetCol * 13 + 6 | 0;
			targetY = 73 + this.mapTargetRow * 13 + 6 | 0;
			if ((this.getStageFlags(this.world, this.stage + 1 | 0) & 2) !== 0 && (this.stage + 1 | 0) === Game.latestUnlockedStage || this.stage === Game.latestUnlockedStage) {
				this.unlockPathShown = 1;
			}
			if (this.unlockPathShown) {
				arrived = this.stepMarkerWalk(markerX, markerY, targetXOrFrame, targetY);
				if (arrived) {
					this.mapMarkerCol = this.mapTargetCol;
					this.mapMarkerRow = this.mapTargetRow;
					return;
				}
			} else {
				this.unlockPathShown = this.animateUnlockPath();
				if (this.unlockPathShown) {
					this.needsFullRedraw = 1;
					return;
				}
			}
		} else {
			if (this.stageMapAnimating) {
				targetXOrFrame = !this.markerFacingLeft ? 6 : 7;
				Game.spritePacks[17].drawFrame(this.screenGraphics, targetXOrFrame, markerX, markerY, 0, 0, 0);
			}
		}
	}

	stepMarkerWalk(fromX, fromY, toX, toY) {
		let frame = 0;
		if (this.markerWalkRestart) {
			this.markerWalkRestart = 0;
			this.markerWalkX = fromX;
			this.markerWalkY = fromY;
			this.markerWalkError = 0;
			this.markerWalkDx = toX - fromX | 0;
			this.markerWalkDy = toY - fromY | 0;
			this.markerWalkMajor2 = 0;
			this.markerWalkMinor2 = 0;
			this.markerWalkStepX = 10;
			this.markerWalkStepY = 10;
		}
		if (this.markerWalkDx < 0) {
			this.markerWalkStepX = -10;
			this.markerWalkDx = -this.markerWalkDx | 0;
		}
		if (this.markerWalkDy < 0) {
			this.markerWalkStepY = -10;
			this.markerWalkDy = -this.markerWalkDy | 0;
		}
		this.markerFacingLeft = this.markerWalkStepX <= 0 ? 1 : 0;
		frame = !this.markerFacingLeft ? 6 : 7;
		B4: {
			if (this.markerWalkDy > this.markerWalkDx) {
				this.markerWalkMajor2 = 2 * this.markerWalkDy | 0;
				this.markerWalkMinor2 = 2 * this.markerWalkDx | 0;
				if ((this.markerWalkStepY >= 0 || this.markerWalkY > toY) && (this.markerWalkStepY <= 0 || this.markerWalkY < toY)) {
					Game.spritePacks[17].drawFrame(this.screenGraphics, frame, this.markerWalkX, this.markerWalkY, 0, 0, 0);
					this.markerWalkY = this.markerWalkY + this.markerWalkStepY | 0;
					this.markerWalkError = this.markerWalkError + this.markerWalkMinor2 | 0;
					if (this.markerWalkError > this.markerWalkDy) {
						this.markerWalkX = this.markerWalkX + this.markerWalkStepX | 0;
						break B4;
					}
					return 0;
				}
				toX = 37 + this.mapTargetCol * 13 + 6 | 0;
				toY = 73 + this.mapTargetRow * 13 + 6 | 0;
				Game.spritePacks[17].drawFrame(this.screenGraphics, frame, toX, toY, 0, 0, 0);
				this.markerWalkRestart = 1;
				return 1;
			}
			this.markerWalkMajor2 = 2 * this.markerWalkDx | 0;
			this.markerWalkMinor2 = 2 * this.markerWalkDy | 0;
			if ((this.markerWalkStepX >= 0 || this.markerWalkX > toX) && (this.markerWalkStepX <= 0 || this.markerWalkX < toX)) {
				Game.spritePacks[17].drawFrame(this.screenGraphics, frame, this.markerWalkX, this.markerWalkY, 0, 0, 0);
				this.markerWalkX = this.markerWalkX + this.markerWalkStepX | 0;
				this.markerWalkError = this.markerWalkError + this.markerWalkMinor2 | 0;
				if (this.markerWalkError > this.markerWalkDx) {
					this.markerWalkY = this.markerWalkY + this.markerWalkStepY | 0;
					break B4;
				}
				return 0;
			}
			toX = 37 + this.mapTargetCol * 13 + 6 | 0;
			toY = 73 + this.mapTargetRow * 13 + 6 | 0;
			Game.spritePacks[17].drawFrame(this.screenGraphics, frame, toX, toY, 0, 0, 0);
			this.markerWalkRestart = 1;
			return 1;
		}
		this.markerWalkError = this.markerWalkError - this.markerWalkMajor2 | 0;
		return 0;
	}

	drawStageMapLinksFromNode(col, row, node, nodeType, isLocked) {
		let linkLocked = 0, endX = 0, stepY = 0, linkRow = 0, linkType = 0, linkIndex = 0, endY = 0, startY = 0, linkCol = 0, stageIndex = 0, linkStage = 0, drawnBit = 0, stepX = 0, dotFrame = 0, linkNode = 0n, bitOffset = 0, startX = 0, linkCount = 0, s0;
		stageIndex = Game.extractLongBits(node, 6, 5);
		this.mapPathsDrawnMask = this.mapPathsDrawnMask | 1 << stageIndex;
		linkCount = Game.extractLongBits(node, 11, 3);
		bitOffset = 14;
		linkIndex = 0;
		while (linkIndex < linkCount) {
			startX = 37 + col * 13 | 0;
			startY = 73 + row * 13 | 0;
			linkCol = Game.extractLongBits(node, bitOffset << 24 >> 24, 4);
			bitOffset += 4;
			linkRow = Game.extractLongBits(node, bitOffset << 24 >> 24, 4);
			endX = linkCol;
			endY = linkRow;
			linkNode = Game.stageMapNodes[endX][endY];
			linkStage = Game.extractLongBits(linkNode, 6, 5);
			drawnBit = this.mapPathsDrawnMask;
			drawnBit = drawnBit & 1 << linkStage;
			if (drawnBit <= 0) {
				endX = 37 + endX * 13 | 0;
				endY = 73 + endY * 13 | 0;
				startX += 6;
				startY += 6;
				endX += 6;
				endY += 6;
				this.pathDotX = startX;
				this.pathDotY = startY;
				this.pathDotError = 0;
				this.pathDotDx = endX - startX | 0;
				this.pathDotDy = endY - startY | 0;
				this.pathDotMajor2 = 0;
				this.pathDotMinor2 = 0;
				this.pathDotStep = 1;
				stepX = 1;
				stepY = 1;
				if (this.pathDotDx < 0) {
					stepX = -1;
					this.pathDotDx = -this.pathDotDx | 0;
				}
				if (this.pathDotDy < 0) {
					stepY = -1;
					this.pathDotDy = -this.pathDotDy | 0;
				}
				dotFrame = 0;
				linkLocked = Game.extractLongBits(linkNode, 0, 3);
				linkType = Game.extractLongBits(linkNode, 3, 3);
				if (nodeType === 1) {
					linkType = nodeType;
				}
				if (isLocked !== 1) {
					if (!this.unlockRevealDone && linkStage === Game.latestUnlockedStage) {
						linkLocked = 1;
					}
					if (linkLocked !== 0) {
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
					if (this.pathDotDy > this.pathDotDx) {
						this.pathDotMajor2 = 2 * this.pathDotDy | 0;
						this.pathDotMinor2 = 2 * this.pathDotDx | 0;
						while (true) {
							if (this.pathDotStep % 8 === 0) {
								Game.spritePacks[17].drawFrame(Game.stageMapGraphics, dotFrame, this.pathDotX - 27 | 0, this.pathDotY - 56 | 0, 0, 0, 0);
								if (this.recordUnlockPath) {
									this.recordUnlockPathDot(stageIndex, linkStage);
								}
							}
							if (this.pathDotY !== endY) {
								this.pathDotY = this.pathDotY + stepY | 0;
								this.pathDotError = this.pathDotError + this.pathDotMinor2 | 0;
								if (this.pathDotError > this.pathDotDy) {
									this.pathDotX = this.pathDotX + stepX | 0;
									this.pathDotError = this.pathDotError - this.pathDotMajor2 | 0;
								}
								this.pathDotStep = this.pathDotStep + 1 | 0;
								continue;
							}
							break;
						}
					} else {
						this.pathDotMajor2 = this.pathDotDx << 1;
						this.pathDotMinor2 = this.pathDotDy << 1;
						while (true) {
							if (this.pathDotStep % 8 === 0) {
								Game.spritePacks[17].drawFrame(Game.stageMapGraphics, dotFrame, this.pathDotX - 27 | 0, this.pathDotY - 56 | 0, 0, 0, 0);
								if (this.recordUnlockPath) {
									this.recordUnlockPathDot(stageIndex, linkStage);
								}
							}
							if (this.pathDotX !== endX) {
								this.pathDotX = this.pathDotX + stepX | 0;
								this.pathDotError = this.pathDotError + this.pathDotMinor2 | 0;
								if (this.pathDotError > this.pathDotDx) {
									this.pathDotY = this.pathDotY + stepY | 0;
									this.pathDotError = this.pathDotError - this.pathDotMajor2 | 0;
								}
								this.pathDotStep = this.pathDotStep + 1 | 0;
								continue;
							}
							break;
						}
					}
				} else {
					if (linkType !== 1) {
						linkLocked = isLocked;
						if (!this.unlockRevealDone && linkStage === Game.latestUnlockedStage) {
							linkLocked = 1;
						}
						if (linkLocked !== 0) {
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
						if (this.pathDotDy > this.pathDotDx) {
							this.pathDotMajor2 = 2 * this.pathDotDy | 0;
							this.pathDotMinor2 = 2 * this.pathDotDx | 0;
							while (true) {
								if (this.pathDotStep % 8 === 0) {
									Game.spritePacks[17].drawFrame(Game.stageMapGraphics, dotFrame, this.pathDotX - 27 | 0, this.pathDotY - 56 | 0, 0, 0, 0);
									if (this.recordUnlockPath) {
										this.recordUnlockPathDot(stageIndex, linkStage);
									}
								}
								if (this.pathDotY !== endY) {
									this.pathDotY = this.pathDotY + stepY | 0;
									this.pathDotError = this.pathDotError + this.pathDotMinor2 | 0;
									if (this.pathDotError > this.pathDotDy) {
										this.pathDotX = this.pathDotX + stepX | 0;
										this.pathDotError = this.pathDotError - this.pathDotMajor2 | 0;
									}
									this.pathDotStep = this.pathDotStep + 1 | 0;
									continue;
								}
								break;
							}
						} else {
							this.pathDotMajor2 = this.pathDotDx << 1;
							this.pathDotMinor2 = this.pathDotDy << 1;
							while (true) {
								if (this.pathDotStep % 8 === 0) {
									Game.spritePacks[17].drawFrame(Game.stageMapGraphics, dotFrame, this.pathDotX - 27 | 0, this.pathDotY - 56 | 0, 0, 0, 0);
									if (this.recordUnlockPath) {
										this.recordUnlockPathDot(stageIndex, linkStage);
									}
								}
								if (this.pathDotX !== endX) {
									this.pathDotX = this.pathDotX + stepX | 0;
									this.pathDotError = this.pathDotError + this.pathDotMinor2 | 0;
									if (this.pathDotError > this.pathDotDx) {
										this.pathDotY = this.pathDotY + stepY | 0;
										this.pathDotError = this.pathDotError - this.pathDotMajor2 | 0;
									}
									this.pathDotStep = this.pathDotStep + 1 | 0;
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

	recordUnlockPathDot(fromStage, toStage) {
		let fromNodeStage = 0, fromNode = 0n, t2, t3, t4, t5;
		if (this.usedMainExit) {
			if (toStage === Game.latestUnlockedStage && fromStage === (Game.latestUnlockedStage - 1 | 0) || fromStage === Game.latestUnlockedStage && toStage === (Game.latestUnlockedStage - 1 | 0)) {
				if (fromStage === Game.latestUnlockedStage && toStage === (Game.latestUnlockedStage - 1 | 0)) {
					this.unlockPathReversed = 1;
				}
				t2 = this.unlockPathPoints;
				t3 = this.unlockPathCoordCount;
				this.unlockPathCoordCount = t3 + 1 | 0;
				t2[t3] = this.pathDotX;
				t4 = this.unlockPathPoints;
				t5 = this.unlockPathCoordCount;
				this.unlockPathCoordCount = t5 + 1 | 0;
				t4[t5] = this.pathDotY;
			}
		} else {
			fromNode = Game.stageMapNodes[this.unlockFromNodeX][this.unlockFromNodeY];
			fromNodeStage = Game.extractLongBits(fromNode, 6, 5);
			B4: {
				if (toStage === Game.latestUnlockedStage && fromStage === fromNodeStage || fromStage === Game.latestUnlockedStage && toStage === fromNodeStage) {
					if (fromStage === Game.latestUnlockedStage && toStage === fromNodeStage) {
						this.unlockPathReversed = 1;
					}
					t2 = this.unlockPathPoints;
					t3 = this.unlockPathCoordCount;
					this.unlockPathCoordCount = t3 + 1 | 0;
					t2[t3] = this.pathDotX;
					t4 = this.unlockPathPoints;
					t5 = this.unlockPathCoordCount;
					this.unlockPathCoordCount = t5 + 1 | 0;
					t4[t5] = this.pathDotY;
					break B4;
				}
			}
		}
	}

	drawStageMapNodes() {
		let nodeType = 0, row = 0, nodeOffset = 0, stageIndex = 0, col = 0, linkCountOrPack = 0, allDiamonds = 0, node = 0n, completeFrame = 0, nodeFrame = 0, isLocked = 0, s0;
		this.mapPathsDrawnMask = 0;
		if ((this.getStageFlags(this.world, this.stage + 1 | 0) & 2) !== 0 && (this.stage + 1 | 0) === Game.latestUnlockedStage || this.stage === Game.latestUnlockedStage) {
			this.recordUnlockPath = 0;
			this.unlockRevealDone = 1;
		}
		for (col = 0; col < 12; col++) {
			for (row = 0; row < 12; row++) {
				node = Game.stageMapNodes[col][row];
				allDiamonds = 0;
				if (node !== 0n) {
					nodeType = Game.extractLongBits(node, 3, 3);
					stageIndex = Game.extractLongBits(node, 6, 5);
					isLocked = this.unlockRevealDone || stageIndex !== Game.latestUnlockedStage || stageIndex === 0 ? Game.extractLongBits(node, 0, 3) : 1;
					nodeFrame = -1;
					completeFrame = -1;
					nodeOffset = -1;
					if (isLocked !== 0) {
						switch (nodeType) {
							case 0:
								nodeOffset = 0;
								nodeFrame = 1;
								break;
							default:
								break;
						}
					} else {
						allDiamonds = this.getStageBankedRedDiamonds(this.world, stageIndex) === this.getStageRedDiamondTotal(this.world, stageIndex) ? 1 : 0;
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
								linkCountOrPack = Game.extractLongBits(node, 11, 3);
								s0 = linkCountOrPack <= 2 ? 0 : 13;
								nodeFrame = s0;
								break;
							default:
								break;
						}
					}
					this.drawStageMapLinksFromNode(col, row, node, nodeType, isLocked);
					if (nodeOffset !== -1 && nodeFrame !== -1) {
						if (allDiamonds !== 0 && completeFrame !== -1) {
							Game.spritePacks[17].drawFrame(Game.stageMapGraphics, completeFrame, col * 13 + nodeOffset + 37 - 27 | 0, row * 13 + nodeOffset + 73 - 56 | 0, 0, 0, 0);
						}
						Game.spritePacks[17].drawFrame(Game.stageMapGraphics, nodeFrame, col * 13 + nodeOffset + 37 - 27 | 0, row * 13 + nodeOffset + 73 - 56 | 0, 0, 0, 0);
						linkCountOrPack = -1;
						switch (this.world) {
							case 2:
								if (stageIndex === 10) {
									s0 = 54;
									linkCountOrPack = s0;
								}
								break;
							case 1:
								if (stageIndex === 9) {
									s0 = 53;
									linkCountOrPack = s0;
								}
								break;
							case 0:
								if (stageIndex === 8) {
									s0 = 52;
									linkCountOrPack = s0;
								}
								break;
							default:
								break;
						}
						if (linkCountOrPack !== -1) {
							Game.spritePacks[linkCountOrPack].drawFrame(Game.stageMapGraphics, 0, col * 13 - 8 + 37 - 27 | 0, row * 13 - 8 + 73 - 56 | 0, 0, 0, 0);
						}
					}
				}
			}
		}
		this.recordUnlockPath = 0;
	}

	drawStageMapBackground() {
		let titleStringId = 0, progressTotal = 0, bgPackIndex = 0, bgColor = 0, progressCount = 0, barFillColor = 0, barBorderColor = 0, s0;
		this.screenGraphics.setClip(0, 0, 240, 320);
		bgColor = 0;
		barFillColor = 0;
		barBorderColor = 0;
		titleStringId = -1;
		bgPackIndex = 0;
		switch (this.world) {
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
		this.screenGraphics.setColor(bgColor);
		this.screenGraphics.fillRect(0, 0, 240, 320);
		Game.spritePacks[bgPackIndex].drawFrame(this.screenGraphics, 0, 120, 0, 0, 0, 0);
		Game.spritePacks[41].drawString(this.screenGraphics, Game.langStrings[titleStringId], 8, 6, 20);
		Game.stageMapGraphics = Game.stageMapImage.getGraphics();
		Game.stageMapGraphics.setColor(bgColor);
		Game.stageMapGraphics.fillRect(0, 0, 186, 226);
		Game.spritePacks[23].drawFrame(Game.stageMapGraphics, 0, 93, 113, 0, 0, 0);
		this.screenGraphics.setColor(barFillColor);
		this.screenGraphics.fillRoundRect(2, 282, 236, 22, 8, 8);
		this.screenGraphics.setColor(barBorderColor);
		this.screenGraphics.drawRoundRect(2, 282, 236, 22, 8, 8);
		this.drawBackSoftkeyIcon();
		this.drawSelectSoftkeyIcon();
		Game.spritePacks[41].drawString(this.screenGraphics, Game.langStrings[96], 222, 311, 10);
		if (Game.spritePacks[17] !== null) {
			Game.spritePacks[17].drawFrame(this.screenGraphics, 12, 11, 284, 0, 0, 0);
			Game.spritePacks[17].drawFrame(this.screenGraphics, 10, 155, 285, 0, 0, 0);
			Game.spritePacks[17].drawFrame(this.screenGraphics, 11, 80, 285, 0, 0, 0);
		}
		Game.scratchText.delete(0, Game.scratchText.length());
		Game.scratchText.append(this.lives);
		Game.spritePacks[41].drawString(this.screenGraphics, Game.scratchText.toString(), 39, 285, 20);
		Game.scratchText.delete(0, Game.scratchText.length());
		Game.scratchText.append(Game.readU16LE(Game.saveData, 4));
		Game.spritePacks[41].drawString(this.screenGraphics, Game.scratchText.toString(), 100, 285, 20);
		Game.scratchText.delete(0, Game.scratchText.length());
		progressCount = Game.readU16LE(Game.saveData, 6);
		progressTotal = Game.saveData[0];
		if (progressCount < progressTotal) {
			Game.scratchText.append(progressCount).append("/").append(progressTotal);
		} else {
			Game.scratchText.append(progressCount).append("/").append(progressCount);
		}
		Game.spritePacks[41].drawString(this.screenGraphics, Game.scratchText.toString(), 175, 285, 20);
		this.stageMapImageNeeded = 0;
	}

	drawStageMapTopBar() {
		let borderColor = 0, fillColor = 0, s0;
		fillColor = 0;
		borderColor = 0;
		switch (this.world) {
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
		this.screenGraphics.setColor(fillColor);
		this.screenGraphics.fillRoundRect(2, 34, 236, 22, 8, 8);
		this.screenGraphics.setColor(borderColor);
		this.screenGraphics.drawRoundRect(2, 34, 236, 22, 8, 8);
	}

	handleStageMapInput() {
		let linkLocked = 0, linkRow = 0, linkIndex = 0, linkCol = 0, nodeOrStage = 0, markerRow = 0, markerColOrNode = 0, firstCandidate = 0, bitOffset = 0, dir = 0, secondCandidate = 0, linkCount = 0, linkRow2 = 0, linkNodeOrCol2 = 0, s0;
		if (this.mapMarkerCol === this.mapTargetCol && this.mapMarkerRow === this.mapTargetRow) {
			dir = -1;
			if (!Game.isKeyDown(4097)) {
				if (!Game.isKeyDown(262146)) {
					if (!Game.isKeyDown(16388)) {
						if (!Game.isKeyDown(65544)) {
							if (!Game.isKeyDown(32944)) {
								if (Game.isKeyDown(64)) {
									this.needLevelCleanup = 1;
									this.needFreeMapRes = 1;
									this.needGarbageCollect = 1;
									this.loadingStep = 0;
									Game.screen = 28;
									Game.keys = 0;
									return;
								}
							} else {
								if (BigInt.asIntN(64, JSystem.currentTimeMillis() - this.stageSelectLockTime) >= 2000n) {
									markerColOrNode = Game.stageMapNodes[this.mapMarkerCol][this.mapMarkerRow];
									nodeOrStage = Game.extractLongBits(markerColOrNode, 6, 5);
									this.cleanup();
									this.freeStageMapResources();
									JSystem.gc();
									this.stage = nodeOrStage;
									this.startLevelLoading();
									Game.keys = 0;
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
			Game.keys = 0;
			if (dir !== -1) {
				markerColOrNode = this.mapMarkerCol;
				markerRow = this.mapMarkerRow;
				nodeOrStage = Game.stageMapNodes[markerColOrNode][markerRow];
				linkCount = Game.extractLongBits(nodeOrStage, 11, 3);
				bitOffset = 14;
				firstCandidate = -1;
				secondCandidate = -1;
				linkIndex = 0;
				while (linkIndex < linkCount) {
					linkCol = Game.extractLongBits(nodeOrStage, bitOffset << 24 >> 24, 4);
					bitOffset += 4;
					linkRow = Game.extractLongBits(nodeOrStage, bitOffset << 24 >> 24, 4);
					linkNodeOrCol2 = Game.stageMapNodes[linkCol][linkRow];
					linkLocked = Game.extractLongBits(linkNodeOrCol2, 0, 3);
					if (linkLocked !== 1) {
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
				if (firstCandidate !== -1) {
					linkIndex = -1;
					if (secondCandidate === -1) {
						linkIndex = firstCandidate;
					} else {
						bitOffset = 14 + (firstCandidate * 2 | 0) * 4 | 0;
						linkCol = Game.extractLongBits(nodeOrStage, bitOffset << 24 >> 24, 4);
						bitOffset += 4;
						linkRow = Game.extractLongBits(nodeOrStage, bitOffset << 24 >> 24, 4);
						bitOffset = 14 + (secondCandidate * 2 | 0) * 4 | 0;
						linkNodeOrCol2 = Game.extractLongBits(nodeOrStage, bitOffset << 24 >> 24, 4);
						bitOffset += 4;
						linkRow2 = Game.extractLongBits(nodeOrStage, bitOffset << 24 >> 24, 4);
						switch (dir) {
							case 2:
							case 3:
								if (markerColOrNode !== linkCol) {
									if (markerColOrNode !== linkNodeOrCol2) {
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
								if (markerRow !== linkRow) {
									if (markerRow !== linkRow2) {
										s0 = (Math.abs(markerColOrNode - linkCol | 0) | 0) <= (Math.abs(markerColOrNode - linkNodeOrCol2 | 0) | 0) ? secondCandidate : firstCandidate;
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
					if (linkIndex !== -1) {
						bitOffset = 14 + (linkIndex * 2 | 0) * 4 | 0;
						linkCol = Game.extractLongBits(nodeOrStage, bitOffset << 24 >> 24, 4);
						bitOffset += 4;
						linkRow = Game.extractLongBits(nodeOrStage, bitOffset << 24 >> 24, 4);
						linkNodeOrCol2 = Game.stageMapNodes[linkCol][linkRow];
						linkLocked = Game.extractLongBits(linkNodeOrCol2, 0, 3);
						if (linkLocked === 0) {
							this.mapTargetCol = linkCol;
							this.mapTargetRow = linkRow;
							this.stageMapAnimating = 1;
						}
					}
				}
			}
		}
	}

	loadStageMapStep(step) {
		let s0, s1, s2, s3;
		T1: {
			try {
				switch (step) {
					case 14:
						if (this.fromStageClear) {
							this.fromStageClear = 0;
						}
						this.setupStageMapMarkers();
						Game.screen = 15;
						return;
					case 10:
						if (!this.newStageUnlocked) {
							return;
						}
						this.resetUnlockPathAnimation();
						break T1;
					case 9:
						if (Game.spritePacks[52] !== null) {
							return;
						}
						Game.spritePacks[52] = Game.loadSpritePack("/mmv.f", 3);
						break T1;
					case 8:
						if (Game.spritePacks[53] !== null) {
							return;
						}
						Game.spritePacks[53] = Game.loadSpritePack("/mmv.f", 2);
						break T1;
					case 7:
						B7: {
							if (Game.spritePacks[54] !== null) {
								this.gemHalfWidth = Game.getFrameWidth(Game.spritePacks[54], 0) >> 1;
								this.gemHalfHeight = Game.getFrameHeight(Game.spritePacks[54], 0) >> 1;
							} else {
								Game.spritePacks[54] = Game.loadSpritePack("/mmv.f", 1);
								this.gemHalfWidth = Game.getFrameWidth(Game.spritePacks[54], 0) >> 1;
								this.gemHalfHeight = Game.getFrameHeight(Game.spritePacks[54], 0) >> 1;
								break B7;
							}
						}
						return;
					case 6:
						switch (this.world) {
							case 2:
								s0 = Game.spritePacks;
								s1 = 26;
								s2 = "/ms.f";
								s3 = 4;
								s0[s1] = Game.loadSpritePack(s2, s3);
								break;
							case 1:
								s0 = Game.spritePacks;
								s1 = 25;
								s2 = "/ms.f";
								s3 = 3;
								s0[s1] = Game.loadSpritePack(s2, s3);
								break;
							case 0:
								s0 = Game.spritePacks;
								s1 = 24;
								s2 = "/ms.f";
								s3 = 2;
								s0[s1] = Game.loadSpritePack(s2, s3);
								break;
							default:
								break;
						}
						break T1;
					case 5:
						Game.spritePacks[17] = Game.loadSpritePack("/ms.f", 0);
						Game.spritePacks[23] = Game.loadSpritePack("/ms.f", 1);
						break T1;
					case 4:
						Game.spritePacks[41].paletteIndex = 0;
						Game.scratchText.delete(0, Game.scratchText.length());
						switch (this.world) {
							case 2:
								Game.scratchText.append("/map_tibet.out");
								Game.stageMapNodes = J.multiArray(BigInt64Array, 2, [12, 12]);
								this.unlockPathPoints = new Int32Array(20);
								this.loadStageMapFile(Game.scratchText.toString());
								break;
							case 1:
								Game.scratchText.append("/map_scotland.out");
								Game.stageMapNodes = J.multiArray(BigInt64Array, 2, [12, 12]);
								this.unlockPathPoints = new Int32Array(20);
								this.loadStageMapFile(Game.scratchText.toString());
								break;
							case 0:
								Game.scratchText.append("/map_angkor.out");
								Game.stageMapNodes = J.multiArray(BigInt64Array, 2, [12, 12]);
								this.unlockPathPoints = new Int32Array(20);
								this.loadStageMapFile(Game.scratchText.toString());
								break;
							default:
								Game.stageMapNodes = J.multiArray(BigInt64Array, 2, [12, 12]);
								this.unlockPathPoints = new Int32Array(20);
								this.loadStageMapFile(Game.scratchText.toString());
								break;
						}
						break T1;
					case 3:
						if (!this.needFreeMapRes) {
							return;
						}
						this.freeStageMapResources();
						break T1;
					case 2:
						if (!this.needFreeMenuRes) {
							return;
						}
						this.freeWorldMapResources();
						break T1;
					case 1:
						if (!this.needLevelCleanup) {
							return;
						}
						this.cleanup();
						break T1;
					case 0:
						if (!this.needSaveStageResult) {
							return;
						}
						this.saveStageResult();
						break T1;
					default:
						return;
				}
			} catch (ex) {
				ex = J.exc(ex);
				if (J.isa(ex, "java/lang/Exception")) {
					s0 = ex;
				}
				else throw ex;
			}
		}
	}

	loadStageMapFile(path) {
		let nodeType = 0, pos = 0, row = 0, linkRow = 0, linkIndex = 0, linkCol = 0, stageIndex = 0, col = 0, nodeIndex = 0, input = null, bitOffset = 0, nodeCount = 0, dataSize = 0, linkCount = 0;
		input = J.getClass(this).getResourceAsStream(path);
		dataSize = input.read();
		dataSize = (dataSize << 24 >> 24 & 255) + (input.read() << 24 >> 24 & 255) * 256 | 0;
		nodeCount = input.read();
		Game.tipPageData = new Int8Array(dataSize);
		input.read(Game.tipPageData);
		input.close();
		pos = 0;
		for (nodeIndex = 0; nodeIndex < nodeCount; nodeIndex++) {
			col = Game.tipPageData[pos++];
			row = Game.tipPageData[pos++];
			nodeType = Game.tipPageData[pos++];
			stageIndex = Game.tipPageData[pos++];
			if (nodeType === 1 && stageIndex < this.firstSecretStage) {
				this.firstSecretStage = stageIndex;
			}
			linkCount = Game.tipPageData[pos++];
			this.setStageMapNodeBits(col, row, 1, 0, 3);
			this.setStageMapNodeBits(col, row, nodeType, 3, 3);
			this.setStageMapNodeBits(col, row, stageIndex, 6, 5);
			this.setStageMapNodeBits(col, row, linkCount, 11, 3);
			bitOffset = 14;
			for (linkIndex = 0; linkIndex < linkCount; linkIndex++) {
				linkCol = Game.tipPageData[pos++];
				this.setStageMapNodeBits(col, row, linkCol, bitOffset, 4);
				bitOffset = bitOffset + 4 << 24 >> 24;
				linkRow = Game.tipPageData[pos++];
				this.setStageMapNodeBits(col, row, linkRow, bitOffset, 4);
				bitOffset = bitOffset + 4 << 24 >> 24;
			}
		}
		Game.tipPageData = null;
		JSystem.gc();
	}

	setupStageMapMarkers() {
		let row = 0, stageIndex = 0, col = 0, node = 0n, isUnlocked = 0, s0, s1, s2, s3;
		this.mapMarkerCol = -1;
		if (!this.newStageUnlocked) {
			this.stage = Game.latestUnlockedStage;
		}
		this.newStageUnlocked = 0;
		for (col = 0; col < 12; col++) {
			for (row = 0; row < 12; row++) {
				node = Game.stageMapNodes[col][row];
				if (node !== 0n) {
					stageIndex = Game.extractLongBits(node, 6, 5);
					s0 = (this.getStageFlags(this.world, stageIndex) & 64) === 0 ? 0 : 1;
					isUnlocked = s0;
					if (isUnlocked !== 0 || stageIndex === 0) {
						s0 = this;
						s1 = col;
						s2 = row;
						s3 = 0;
					} else {
						s0 = this;
						s1 = col;
						s2 = row;
						s3 = 1;
					}
					s0.setStageMapNodeBits(s1, s2, s3, 0, 3);
					if (stageIndex === this.stage) {
						this.mapMarkerCol = col;
						this.mapMarkerRow = row;
					}
					if (stageIndex === Game.latestUnlockedStage) {
						this.mapTargetCol = col;
						this.mapTargetRow = row;
					}
					this.markerFacingLeft = 0;
				}
			}
		}
	}

	loadShopSpritesAndHandleInput() {
		Game.spritePacks[17] = Game.loadSpritePack("/ms.f", 0);
		this.handleShopInput();
	}

	static drawFramedBox(g, x, y, w, h, color, frameStyle) {
		let clipH = 0, pos = 0, clipW = 0, clipX = 0, clipY = 0;
		clipX = g.getClipX();
		clipY = g.getClipY();
		clipW = g.getClipWidth();
		clipH = g.getClipHeight();
		g.setClip(x, y, w, h);
		g.setColor(color);
		g.fillRect(x, y, w, h);
		g.setClip(x - 3 | 0, y, w + 6 | 0, h);
		for (pos = y; pos <= (y + h | 0); pos += 8) {
			g.drawImage(Game.uiFrameImages[frameStyle][7], x, pos, 24);
			g.drawImage(Game.uiFrameImages[frameStyle][5], x + w | 0, pos, 20);
		}
		g.setClip(x, y - 3 | 0, w, h + 6 | 0);
		for (pos = x; pos <= (x + w | 0); pos += 8) {
			g.drawImage(Game.uiFrameImages[frameStyle][4], pos, y, 36);
			g.drawImage(Game.uiFrameImages[frameStyle][6], pos, y + h | 0, 20);
		}
		g.setClip(x - 3 | 0, y - 3 | 0, w + 6 | 0, h + 6 | 0);
		g.drawImage(Game.uiFrameImages[frameStyle][0], x, y, 40);
		g.drawImage(Game.uiFrameImages[frameStyle][1], x + w | 0, y, 36);
		g.drawImage(Game.uiFrameImages[frameStyle][2], x, y + h | 0, 24);
		g.drawImage(Game.uiFrameImages[frameStyle][3], x + w | 0, y + h | 0, 20);
		g.setClip(clipX, clipY, clipW, clipH);
	}

	static drawFramedBoxWithTab(g, x, y, w, h, color, frameStyle, tabW, tabH) {
		let clipH = 0, clipY = 0, clipW = 0, clipX = 0;
		clipX = g.getClipX();
		clipY = g.getClipY();
		clipW = g.getClipWidth();
		clipH = g.getClipHeight();
		Game.drawFramedBox(g, x, y, w, h, color, frameStyle);
		Game.drawFramedBox(g, x + 10 | 0, y - 3 - tabH | 0, tabW, tabH, color, frameStyle);
		g.setClip(x + 10 - 3 | 0, y - 3 | 0, tabW + 6 | 0, 3);
		g.setColor(color);
		g.fillRect(x + 10 - 3 | 0, y - 3 | 0, tabW + 6 | 0, 3);
		g.drawImage(Game.uiFrameImages[frameStyle][3], x + 10 | 0, y - 3 | 0, 24);
		g.drawImage(Game.uiFrameImages[frameStyle][2], x + 10 + tabW | 0, y - 3 | 0, 20);
		g.setClip(clipX, clipY, clipW, clipH);
	}

	drawShopScreen() {
		let segment = 0, lineYOrText = 0, barX = 0, filledSegment = 0, rowOrImages = 0, segImageOrBarEnd = 0, segmentW = 0, s0, s1, s2, s3, s4;
		if (this.shopCursor !== this.shopLastDrawnCursor || this.needsFullRedraw) {
			if (this.shopCursor !== this.shopLastDrawnCursor) {
				this.needsFullRedraw = 1;
			}
			this.screenGraphics.setClip(0, 0, 240, 320);
			if (this.needsFullRedraw) {
				this.drawWorldMapBackground(this.screenGraphics, 1);
				this.screenGraphics.setColor(0);
				this.screenGraphics.fillRect(0, 0, 240, 15);
				this.screenGraphics.setColor(16777215);
				this.screenGraphics.drawLine(0, 15, 240, 15);
				Game.spritePacks[41].drawString(this.screenGraphics, Game.langStrings[72], 120, 0, 17);
				Game.drawFramedBox(this.screenGraphics, 10, 35, 220, 90, 4273165, 0);
				if (this.shopItemCost !== -1) {
					Game.spritePacks[41].drawMultilineString(this.screenGraphics, Game.wrapText(this.shopMessage, 200), 120, 280, 17);
				}
				if (this.shopPurchaseMsgPending) {
					this.shopPurchaseMsgPending = 0;
					Game.spritePacks[41].drawString(this.screenGraphics, this.shopMessage, 120, 191, 1);
				}
				Game.spritePacks[41].drawMultilineString(this.screenGraphics, this.shopDiamondsText, 120, 260, 17);
				this.drawBackSoftkeyIcon();
				this.drawSelectSoftkeyIcon();
				this.needsFullRedraw = 0;
			}
			if (this.shopCursor !== this.shopLastDrawnCursor) {
				this.screenGraphics.setColor(4273165);
				this.screenGraphics.fillRect(20, 43 + (this.shopLastDrawnCursor < 0 ? this.shopCursor : this.shopLastDrawnCursor) * 20 + 2 | 0, 7, 9);
			}
			Game.spritePacks[17].drawFrame(this.screenGraphics, 14, 20, 43 + this.shopCursor * 20 + 2 | 0, 0, 0, 0);
			Game.drawFramedBox(this.screenGraphics, 10, 155, 220, 70, 4273165, 0);
			if (this.shopItemCost === -1) {
				s0 = Game.spritePacks[41];
				s1 = this.screenGraphics;
				s2 = this.shopMessage;
				s3 = 120;
				s4 = 191;
			} else {
				lineYOrText = new StringBuffer().append(Game.langStrings[74]).append(" ").append(this.shopPriceText.toString()).append("\n").append(Game.langStrings[42]).toString();
				Game.spritePacks[41].lineSpacing = 0;
				s0 = Game.spritePacks[41];
				s1 = this.screenGraphics;
				s2 = lineYOrText;
				s3 = 120;
				s4 = 185;
			}
			s0.drawMultilineString(s1, s2, s3, s4, 1);
			lineYOrText = 0;
			for (rowOrImages = 0; rowOrImages < 4; rowOrImages++) {
				lineYOrText = 43 + 20 * rowOrImages | 0;
				Game.spritePacks[46].drawFrame(this.screenGraphics, 0 + rowOrImages | 0, 27, lineYOrText, 0, 0, 0);
				Game.spritePacks[41].drawString(this.screenGraphics, Game.langStrings[85 + rowOrImages], 53, lineYOrText, 0);
			}
			rowOrImages = Game.spritePacks[0].moduleImages[0];
			barX = rowOrImages[11].getWidth();
			segmentW = rowOrImages[15].getWidth();
			this.screenGraphics.drawImage(rowOrImages[11], 100, 160, 0);
			for (segment = 0; segment < 8; segment++) {
				segImageOrBarEnd = segment < 4 ? 15 : 13;
				this.screenGraphics.drawImage(rowOrImages[segImageOrBarEnd], 100 + barX | 0, 160, 0);
				barX = barX + segmentW | 0;
			}
			segment = this.shopCursor;
			segImageOrBarEnd = barX;
			barX = barX - segmentW * 4 | 0;
			for (filledSegment = 0; filledSegment <= segment; filledSegment++) {
				this.screenGraphics.drawImage(rowOrImages[15], 100 + barX | 0, 160, 0);
				barX = barX + segmentW | 0;
			}
			this.screenGraphics.drawImage(rowOrImages[17], 100 + segImageOrBarEnd | 0, 160, 0);
			if (this.shopCursor !== this.shopLastDrawnCursor) {
				this.shopLastDrawnCursor = this.shopCursor;
			}
			return;
		}
	}

	static setMenuItemValue(menuIndex, itemId, value) {
		let pos = 0;
		pos = 0;
		while (true) {
			if (pos >= Game.menuDefs[menuIndex].length) {
				return;
			}
			if (itemId !== Game.menuDefs[menuIndex][pos]) {
				pos += 2;
				continue;
			}
			break;
		}
		Game.menuDefs[menuIndex][pos + 1] = value;
	}

	playSound(soundId) {
		this.sound.play(soundId);
	}

	updateCredits() {
		let pos = 0, y = 0, s1, s2, t1;
		switch (this.screenSubState) {
			case 3:
				Game.creditsText = null;
				JSystem.gc();
				Game.screen = 4;
				this.screenSubState = 2;
				this.openMenu(0);
				this.sound.play(19);
				return;
			case 2:
				if (!Game.isKeyDown(4097)) {
					if (!Game.isKeyDown(262146)) {
						if (!Game.isKeyDown(64)) {
							s1 = this.creditsScrollY;
							s2 = 1;
							t1 = s1 + s2 | 0;
							s1 = t1;
							this.creditsScrollY = s1;
						} else {
							if (!this.creditsAfterEnding) {
								this.screenSubState = 3;
							} else {
								this.loadingStep = 0;
								this.loadingStepCount = 8;
								Game.screen = 9;
								this.creditsAfterEnding = 0;
							}
						}
					} else {
						s1 = this.creditsScrollY;
						s2 = 3;
						t1 = s1 + s2 | 0;
						s1 = t1;
						this.creditsScrollY = s1;
					}
				} else {
					y = 0;
					if (this.creditsScrollY >= 240) {
						this.creditsScrollY = this.creditsScrollY - 3 | 0;
						if (this.creditsScrollY < 240) {
							s1 = 240;
							this.creditsScrollY = s1;
						}
					} else {
						s1 = this.creditsScrollY;
						s2 = 1;
						t1 = s1 + s2 | 0;
						s1 = t1;
						this.creditsScrollY = s1;
					}
				}
				y = -this.creditsScrollY | 0;
				for (pos = 0; pos < Game.creditsText.length && y <= -340; pos++) {
					if (Game.creditsText[pos] === 10) {
						y += 17;
					}
				}
				this.creditsFirstLine = pos;
				if (this.creditsFirstLine < Game.creditsText.length) {
					return;
				}
				this.creditsFirstLine = 0;
				this.creditsScrollY = 0;
				return;
			default:
				return;
			case 1:
				Game.creditsText = Game.readResource("/cr.f", 0);
				pos = 0;
				while (pos < Game.creditsText.length) {
					if (Game.creditsText[pos] !== 92 || Game.creditsText[pos + 1] !== 110) {
						pos++;
					} else {
						Game.creditsText[pos++] = 10;
						Game.creditsText[pos++] = 32;
					}
				}
				for (pos = 0; Game.creditsText[pos] !== 36; pos++) {
				}
				y = 0;
				while (y < Midlet.version.length) {
					Game.creditsText[pos] = Midlet.version[y];
					y++;
					pos++;
				}
				this.screenSubState = 2;
				return;
			case 0:
				this.creditsScrollY = 0;
				this.creditsFirstLine = 0;
				this.screenSubState = 1;
				return;
		}
	}

	drawCredits() {
		let pos = 0, fadeY = 0, g = null, fadeStep = 0, scrollOffset = 0, lineStart = 0, lineY = 0;
		if (this.screenSubState === 2) {
			g = this.screenGraphics;
			g.setColor(0, 0, 0);
			g.fillRect(0, 0, 240, 320);
			fadeY = 0;
			lineY = -17;
			pos = this.creditsFirstLine;
			lineStart = this.creditsFirstLine;
			scrollOffset = 0;
			scrollOffset = this.creditsScrollY < 340 ? 340 - this.creditsScrollY - 17 | 0 : -(this.creditsScrollY % 17) | 0;
			while (pos < Game.creditsText.length && lineY < 340) {
				if (Game.creditsText[pos] === 10) {
					Game.spritePacks[41].paletteIndex = 0;
					this.drawWrappedRichText(g, Game.creditsText, Game.spritePacks[41], lineStart, pos - lineStart | 0, lineY + scrollOffset | 0, null, 0, 234);
					lineY += 17;
					lineStart = pos + 1 | 0;
				}
				pos++;
			}
			fadeY = 0;
			for (fadeStep = 6; fadeStep > 0; fadeStep--) {
				g.setColor(0);
				g.fillRect(0, fadeY, 240, fadeStep);
				g.fillRect(0, 320 - fadeY - fadeStep | 0, 240, fadeStep);
				fadeY = fadeY + (fadeStep + 1) | 0;
			}
			this.drawBackSoftkeyIcon();
			return;
		}
	}

	updatePopupTimer() {
		if (Game.popupTimeLeft > 0) {
			Game.popupTimeLeft = Number(BigInt.asIntN(32, BigInt.asIntN(64, BigInt(Game.popupTimeLeft) - BigInt.asIntN(64, JSystem.currentTimeMillis() - this.popupLastTick))));
			this.popupLastTick = JSystem.currentTimeMillis();
			if (Game.popupTimeLeft <= 0) {
				this.hidePopup(1);
			}
		}
	}

	showPopup(text, x, y, durationMs, bgColor, frameStyle) {
		this.popupLastTick = JSystem.currentTimeMillis();
		Game.popupTimeLeft = durationMs;
		this.popupX = x;
		this.popupY = y;
		this.popupText = Game.wrapText(text, 220);
		this.popupBgColor = bgColor;
		this.popupFrameStyle = frameStyle;
	}

	hidePopup(redraw) {
		Game.popupTimeLeft = 0;
		if (redraw !== 0) {
			this.needsFullRedraw = 1;
		}
	}

	static isPopupVisible() {
		if (Game.popupTimeLeft <= 0) {
			return 0;
		}
		return 1;
	}

	drawPopup() {
		let textWidth = 0, savedLineSpacing = 0, textHeight = 0, font = null;
		font = Game.spritePacks[41];
		if (Game.popupTimeLeft > 0) {
			savedLineSpacing = font.lineSpacing;
			font.lineSpacing = 3;
			font.measureString(this.popupText);
			textHeight = SpritePack.textHeight;
			textWidth = SpritePack.textWidth;
			if (this.popupX === -1) {
				this.popupX = 240 - textWidth >> 1;
			}
			if (this.popupY === -1) {
				this.popupY = 320 - textHeight >> 1;
			}
			this.screenGraphics.setClip(this.popupX - 6 | 0, this.popupY - 3 | 0, textWidth + 12 | 0, textHeight + 6 | 0);
			Game.drawFramedBox(this.screenGraphics, this.popupX - 6 | 0, this.popupY - 3 | 0, textWidth + 12 | 0, textHeight + 6 | 0, this.popupBgColor, this.popupFrameStyle);
			font.drawMultilineString(this.screenGraphics, this.popupText, this.popupX, this.popupY, 0);
			font.lineSpacing = savedLineSpacing;
			return;
		}
	}

	static wrapText(text, maxWidth) {
		let pos = 0, glyph = 0, widthAtLastSpace = 0, ch = 0, font = null, buffer = null, lastSpacePos = 0, lineWidth = 0, lastBreakPos = 0, s0, s1, s2, t2;
		font = Game.spritePacks[41];
		lineWidth = 0;
		lastSpacePos = 0;
		widthAtLastSpace = 0;
		lastBreakPos = 0;
		buffer = new StringBuffer(text);
		for (pos = 0; pos <= buffer.length(); pos++) {
			ch = 10;
			if (pos < buffer.length()) {
				ch = buffer.charAt(pos) & 255;
			}
			if (lineWidth <= maxWidth || lastSpacePos === lastBreakPos) {
				if (ch !== 10) {
					if (ch <= 32) {
						if (ch === 32) {
							lastSpacePos = pos;
							widthAtLastSpace = lineWidth;
							s0 = lineWidth;
							s1 = font.moduleSizes[0] & 255;
							t2 = s0 + (s1 + font.frameModules[1]) | 0;
							s0 = t2;
							lineWidth = s0;
						}
					} else {
						if (ch !== 64) {
							ch = SpritePack.charMap[ch] & 255;
							if (ch < font.getFrameModuleCount(0)) {
								glyph = (font.frameModules[ch << 2] & 255) << 1;
								s0 = lineWidth;
								s1 = font.moduleSizes[glyph] & 255;
								s2 = font.frameModules[(ch << 2) + 1];
							} else {
								glyph = ch - font.getFrameModuleCount(0) | 0;
								s0 = lineWidth;
								s1 = font.frameBounds[(glyph << 2) + 2] & 255;
								s2 = font.frameBounds[glyph << 2] & 255;
							}
							s1 = s1 - s2 | 0;
							t2 = s0 + (s1 + font.frameModules[1]) | 0;
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
				buffer.setCharAt(lastSpacePos, 10);
				pos = lastSpacePos - 1 | 0;
				lastBreakPos = lastSpacePos;
			}
		}
		return buffer.toString();
	}

	static loadUiFont() {
		let data = null;
		if (Game.spritePacks[41] !== null) {
			Game.spritePacks[41] = null;
			JSystem.gc();
		}
		Game.spritePacks[41] = new SpritePack().init();
		data = Game.readResource("/ui.f", 1);
		Game.spritePacks[41].loadFromBytes(data, 0);
		Game.spritePacks[41].buildModuleImages(0, 0, -1, -1);
		Game.spritePacks[41].buildModuleImages(1, 0, -1, -1);
		Game.spritePacks[41].buildModuleImages(2, 0, -1, -1);
		Game.spritePacks[41].moduleData = null;
	}

	static clinit() {
		let t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20;
		t1 = new Int8Array(3);
		t1[0] = 1;
		t1[1] = 0;
		t1[2] = 0;
		Game.worldUnlockedOnMap = t1;
		t2 = new Int8Array(3);
		t2[0] = 0;
		t2[1] = 0;
		t2[2] = 0;
		Game.elementalDiamondPlaced = t2;
		Game.effectCells = new Int8Array(16);
		Game.effectFrames = new Int8Array(8);
		Game.effectAnims = new Int8Array(8);
		Game.screen = 0;
		Game.returnScreen = Game.screen;
		t3 = new Int8Array(16);
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
		Game.dirDeltas = t3;
		t4 = new Int8Array(7);
		t4[0] = 0;
		t4[1] = 3;
		t4[2] = 4;
		t4[3] = 1;
		t4[4] = 2;
		t4[5] = 5;
		t4[6] = 6;
		Game.oppositeDir = t4;
		Game.saveData = null;
		Game.prefsData = null;
		Game.levelCutscenes = null;
		Game.cutsceneTriggerIds = null;
		Game.itemRaiseFreeze = 0;
		Game.levelBufferImage = null;
		Game.levelBufferGraphics = null;
		Game.bufW = 0;
		Game.bufH = 0;
		Game.bufLeftX = -1;
		Game.bufRightX = -1;
		Game.bufTopY = -1;
		Game.bufBottomY = -1;
		Game.playfieldOverlayImage = null;
		Game.overlayImageX = 0;
		Game.overlayImageY = 0;
		Game.overlayImageAnchor = 0;
		Game.moreGamesBadgeBg = null;
		Game.menuFullRedraw = 0;
		Game.menuRepaintPlayfield = 1;
		Game.cheatCodeProgress = 0;
		t5 = new Int32Array(5);
		t5[0] = 512;
		t5[1] = 16384;
		t5[2] = 131072;
		t5[3] = 131072;
		t5[4] = 4096;
		Game.cheatCodeKeys = t5;
		Game.bankedDiamonds = 0;
		Game.bankedRedDiamonds = 0;
		Game.progressFlagsCopy = 0;
		Game.doorCols = new Int8Array(16);
		Game.doorRows = new Int8Array(16);
		Game.cameraHoldAfterPan = 0;
		Game.liquidFlows = new BigInt64Array(15);
		Game.liquidEmitters = new BigInt64Array(15);
		t6 = J.newArray(8);
		t7 = new Int16Array(14);
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
		t8 = new Int16Array(14);
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
		t9 = new Int16Array(8);
		t9[0] = 0;
		t9[1] = 28;
		t9[2] = 1;
		t9[3] = 29;
		t9[4] = 2;
		t9[5] = 30;
		t9[6] = 3;
		t9[7] = 31;
		t6[2] = t9;
		t10 = new Int16Array(4);
		t10[0] = 0;
		t10[1] = 32;
		t10[2] = 1;
		t10[3] = 33;
		t6[3] = t10;
		t11 = new Int16Array(4);
		t11[0] = 0;
		t11[1] = 45;
		t11[2] = 1;
		t11[3] = 46;
		t6[4] = t11;
		t12 = new Int16Array(4);
		t12[0] = 0;
		t12[1] = 33;
		t12[2] = 1;
		t12[3] = 50;
		t6[5] = t12;
		t13 = new Int16Array(4);
		t13[0] = 0;
		t13[1] = 25;
		t13[2] = 4;
		t13[3] = 27;
		t6[6] = t13;
		t14 = new Int16Array(4);
		t14[0] = 0;
		t14[1] = 101;
		t14[2] = 1;
		t14[3] = 100;
		t6[7] = t14;
		Game.menuDefs = t6;
		t15 = new Int32Array(3);
		t15[0] = 28;
		t15[1] = 29;
		t15[2] = 30;
		Game.worldNameIds = t15;
		t16 = J.newArray(3);
		t17 = new Int32Array(13);
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
		t18 = new Int32Array(13);
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
		t19 = new Int32Array(15);
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
		Game.stageNameIds = t16;
		Game.creditsText = null;
		t20 = J.newArray(3);
		t20[0] = "/w0.bin";
		t20[1] = "/w1.bin";
		t20[2] = "/w2.bin";
		Game.worldDataFiles = t20;
		Game.popupTimeLeft = 0;
	}

}
