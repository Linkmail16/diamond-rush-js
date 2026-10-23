'use strict';

class MoreGames {
	static adImages = null;
	static arrowSprites = null;
	static font = null;
	static adUrls = null;
	static texts = null;
	static pageIndex = 0;
	static frameCounter = 0;
	static state = 0;
	isArrowReturning = 0;
	arrowOffset = 0;

	init() {
		MoreGames.adImages = J.newArray(5);
		MoreGames.adUrls = J.newArray(5);
		return this;
	}

	static openUrl(url) {
		let s0;
		if (url !== null) {
			try {
				Game.midlet.platformRequest(url);
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

	static loadResources() {
		let textIndex = 0, urlIndex = 0, s0;
		MoreGames.font = Game.spritePacks[41];
		MoreGames.font.lineSpacing = 1;
		MoreGames.arrowSprites = Game.loadSpritePack("/tips.f", 0);
		if (MoreGames.texts === null) {
			textIndex = 0;
			MoreGames.texts = Game.loadStringTable("/lang_IGA.f", 15);
			MoreGames.texts[7] = Game.wrapText(MoreGames.texts[7], 170);
			MoreGames.texts[8] = Game.wrapText(MoreGames.texts[8], 170);
			MoreGames.texts[9] = Game.wrapText(MoreGames.texts[9], 170);
		}
		textIndex = 10;
		urlIndex = 0;
		while (textIndex <= 14) {
			MoreGames.adUrls[urlIndex] = Game.midlet.getAppProperty(MoreGames.texts[textIndex]);
			if (MoreGames.adUrls[urlIndex] !== null && (J.compareTo(MoreGames.adUrls[urlIndex], "no") === 0 || J.compareTo(MoreGames.adUrls[urlIndex], "") === 0)) {
				MoreGames.adUrls[urlIndex] = null;
			}
			textIndex++;
			urlIndex++;
		}
		MoreGames.texts[3] = new StringBuffer(MoreGames.texts[3]).append("\n\u0001\u0001").append(MoreGames.texts[4]).append("\n\u0001��").append(MoreGames.texts[5]).toString();
		MoreGames.texts[7] = new StringBuffer().append("\u0001��").append(MoreGames.texts[7]).toString();
		try {
			for (textIndex = 0; textIndex < 4; textIndex++) {
				MoreGames.adImages[textIndex] = Image.createImage(new StringBuffer().append("/ad").append(textIndex + 1 | 0).toString());
			}
			Game.actors[0] = new Actor().init_1(Game.loadSpritePack("/ui.f", 0), 0, 0, null);
		} catch (ex) {
			ex = J.exc(ex);
			if (J.isa(ex, "java/lang/Exception")) {
				s0 = ex;
				MoreGames.pageIndex = 0;
				Game.setMoreGamesState(3);
				return;
			}
			else throw ex;
		}
		MoreGames.pageIndex = 0;
		Game.setMoreGamesState(3);
	}

	static changePage(delta) {
		let s0;
		MoreGames.pageIndex = MoreGames.pageIndex + delta | 0;
		if (MoreGames.pageIndex === 3 && MoreGames.adUrls[MoreGames.pageIndex] === null) {
			MoreGames.pageIndex = MoreGames.pageIndex + delta | 0;
		}
		B2: {
			if (MoreGames.pageIndex < 0) {
				s0 = 4;
				MoreGames.pageIndex = s0;
				break B2;
			}
			if (MoreGames.pageIndex === 5) {
				s0 = 0;
				MoreGames.pageIndex = s0;
			}
		}
	}

	static drawBlinkingPrompt(g, contentBottom) {
		let text = null, textHeight = 0, promptY = 0, boxWidth = 0, s0, s1;
		if (MoreGames.adUrls[MoreGames.pageIndex] !== null) {
			if (MoreGames.frameCounter % 30 >= 15) {
				if (MoreGames.pageIndex < 3) {
					s0 = MoreGames.texts;
					s1 = 9;
				} else {
					s0 = MoreGames.texts;
					s1 = 8;
				}
				text = s0[s1];
				MoreGames.font.measureString(text);
				boxWidth = SpritePack.textWidth + 2 | 0;
				textHeight = MoreGames.font.measureTextHeight(text);
				if (contentBottom === 0) {
					s0 = 160;
					s1 = textHeight >> 1;
				} else {
					s0 = 320 + contentBottom >> 1;
					s1 = (textHeight >> 1) + 4 | 0;
				}
				promptY = s0 - s1 | 0;
				g.setClip(0, 0, 240, 320);
				g.setColor(16711680);
				g.fillRect(120 - (boxWidth >> 1) - 4 | 0, promptY - 4 | 0, boxWidth + 8 | 0, textHeight + 8 | 0);
				MoreGames.font.drawMultilineString(g, text, 120, promptY, 1);
				return;
			}
			return;
		}
	}

	static drawBackground(g) {
		let red = 0, blue = 0, band = 0;
		red = 99;
		blue = 189;
		g.setClip(0, 0, 240, 320);
		for (band = 0; band < 16; band++) {
			g.setColor(red << 16 | 0 | blue);
			g.fillRect(0, 160 + ((160 * band | 0) / 16 | 0) | 0, 240, 21);
			g.fillRect(0, 160 - ((160 * (band + 1 | 0) | 0) / 16 | 0) | 0, 240, 21);
			red = red - 4 | 0;
			blue = blue - 8 | 0;
		}
	}

	updateAndDraw(g) {
		let contentBottom = 0, uiActor = null, s0, s1, s2;
		MoreGames.drawBackground(g);
		contentBottom = 0;
		if (MoreGames.pageIndex !== 3) {
			uiActor = Game.actors[0];
			uiActor.sprite.drawFrame(g, 11, 120, 15, 0, 0, 0);
		}
		switch (MoreGames.pageIndex) {
			default:
				g.drawImage(MoreGames.adImages[MoreGames.pageIndex], 120, 240, 33);
				MoreGames.font.drawMultilineString(g, MoreGames.texts[MoreGames.pageIndex], 120, 242, 17);
				s0 = 0;
				break;
			case 4:
				MoreGames.font.drawMultilineString(g, new StringBuffer().append("\n\u0001\u0002").append(MoreGames.texts[6]).toString(), 120, 35, 17);
				MoreGames.font.drawMultilineString(g, MoreGames.texts[7], 120, 160, 3);
				MoreGames.font.measureString(MoreGames.texts[7]);
				s0 = 160 + (SpritePack.textHeight >> 1) + 4 | 0;
				break;
			case 3:
				g.drawImage(MoreGames.adImages[MoreGames.pageIndex], 120, 15, 17);
				MoreGames.font.drawMultilineString(g, MoreGames.texts[3], 120, 160, 3);
				MoreGames.font.measureString(MoreGames.texts[3]);
				s0 = 160 + (SpritePack.textHeight >> 1) + 4 | 0;
				break;
		}
		contentBottom = s0;
		Game.instance.drawBackSoftkeyIcon();
		if (MoreGames.adUrls[MoreGames.pageIndex] !== null) {
			Game.instance.drawSelectSoftkeyIcon();
		}
		MoreGames.drawBlinkingPrompt(g, contentBottom);
		if (!Game.isKeyDown(16388)) {
			if (!Game.isKeyDown(65544)) {
				if (!Game.isKeyDown(32944)) {
					if (Game.isKeyDown(64)) {
						Game.instance.openMenu(0);
						MoreGames.state = 2;
						Game.keys = 0;
					}
				} else {
					MoreGames.openUrl(MoreGames.adUrls[MoreGames.pageIndex]);
				}
			} else {
				MoreGames.changePage(1);
			}
		} else {
			MoreGames.changePage(-1);
		}
		MoreGames.arrowSprites.drawAnimFrame(g, !Game.isKeyDown(16388) ? 0 : 2, J.irem(MoreGames.frameCounter, MoreGames.arrowSprites.getAnimFrameCount(0)), 20 + this.arrowOffset | 0, 160, 0, 0, 0);
		MoreGames.arrowSprites.drawAnimFrame(g, !Game.isKeyDown(65544) ? 1 : 3, J.irem(MoreGames.frameCounter, MoreGames.arrowSprites.getAnimFrameCount(1)), 220 - this.arrowOffset | 0, 160, 0, 0, 0);
		s0 = this;
		s1 = this.arrowOffset;
		s2 = !this.isArrowReturning ? 1 : -1;
		s0.arrowOffset = s1 + s2 | 0;
		if (this.arrowOffset > 3 || this.arrowOffset < 1) {
			this.isArrowReturning = !this.isArrowReturning ? 1 : 0;
		}
		Game.keys = 0;
	}

	static unload() {
		let index = 0, length = 0;
		index = 0;
		length = MoreGames.adImages.length;
		for (index = 0; index < length; index++) {
			MoreGames.adImages[index] = null;
		}
		MoreGames.adImages = null;
		length = MoreGames.adUrls.length;
		for (index = 0; index < length; index++) {
			MoreGames.adUrls[index] = null;
		}
		MoreGames.adUrls = null;
		length = MoreGames.texts.length;
		for (index = 0; index < length; index++) {
			MoreGames.texts[index] = null;
		}
		MoreGames.texts = null;
		MoreGames.font = null;
		MoreGames.arrowSprites = null;
		MoreGames.state = 0;
		JSystem.gc();
	}

}
