#include "game.h"

Ref<MoreGames> MoreGames::init() {
	MoreGames::adImages = newArray<Ref<Image>>(5);
	MoreGames::adUrls = newArray<Ref<String>>(5);
	return this;
}

void MoreGames::openUrl(Ref<String> url) {
	Ref<Object> s0;
	if (url != nullptr) {
		try {
			Game::midlet->platformRequest(url);
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

void MoreGames::loadResources() {
	int32_t textIndex = 0, urlIndex = 0;
	Ref<Object> s0;
	MoreGames::font = Game::spritePacks[41];
	MoreGames::font->lineSpacing = 1;
	MoreGames::arrowSprites = Game::loadSpritePack(u"/tips.f"_j, 0);
	if (MoreGames::texts == nullptr) {
		textIndex = 0;
		MoreGames::texts = Game::loadStringTable(u"/lang_IGA.f"_j, 15);
		MoreGames::texts[7] = Game::wrapText(MoreGames::texts[7], 170);
		MoreGames::texts[8] = Game::wrapText(MoreGames::texts[8], 170);
		MoreGames::texts[9] = Game::wrapText(MoreGames::texts[9], 170);
	}
	textIndex = 10;
	urlIndex = 0;
	while (textIndex <= 14) {
		MoreGames::adUrls[urlIndex] = Game::midlet->getAppProperty(MoreGames::texts[textIndex]);
		if (MoreGames::adUrls[urlIndex] != nullptr && (MoreGames::adUrls[urlIndex]->compareTo(u"no"_j) == 0 || MoreGames::adUrls[urlIndex]->compareTo(u""_j) == 0)) {
			MoreGames::adUrls[urlIndex] = nullptr;
		}
		textIndex++;
		urlIndex++;
	}
	MoreGames::texts[3] = jnew<StringBuffer>(MoreGames::texts[3])->append(u"\n\u0001\u0001"_j)->append(MoreGames::texts[4])->append(u"\n\u0001\uFFFD\uFFFD"_j)->append(MoreGames::texts[5])->toString();
	MoreGames::texts[7] = jnew<StringBuffer>()->append(u"\u0001\uFFFD\uFFFD"_j)->append(MoreGames::texts[7])->toString();
	try {
		for (textIndex = 0; textIndex < 4; textIndex++) {
			MoreGames::adImages[textIndex] = Image::createImage(jnew<StringBuffer>()->append(u"/ad"_j)->append(textIndex + 1)->toString());
		}
		Game::actors[0] = jnew<Actor>()->init_1(Game::loadSpritePack(u"/ui.f"_j, 0), 0, 0, nullptr);
	} catch (JavaException& ex) {
		if (ex.isa(u"java/lang/Exception")) {
			s0 = ex.ex;
			MoreGames::pageIndex = 0;
			Game::setMoreGamesState(3);
			return;
		}
		else throw;
	}
	MoreGames::pageIndex = 0;
	Game::setMoreGamesState(3);
}

void MoreGames::changePage(int32_t delta) {
	int32_t s0 = 0;
	MoreGames::pageIndex = MoreGames::pageIndex + delta;
	if (MoreGames::pageIndex == 3 && MoreGames::adUrls[MoreGames::pageIndex] == nullptr) {
		MoreGames::pageIndex = MoreGames::pageIndex + delta;
	}
	{
		if (MoreGames::pageIndex < 0) {
			s0 = 4;
			MoreGames::pageIndex = s0;
			goto B2_end;
		}
		if (MoreGames::pageIndex == 5) {
			s0 = 0;
			MoreGames::pageIndex = s0;
		}
	}
	B2_end:;
}

void MoreGames::drawBlinkingPrompt(Ref<Graphics> g, int32_t contentBottom) {
	Ref<String> text;
	int32_t boxWidth = 0, textHeight = 0, promptY = 0, s0_n = 0, s1 = 0;
	Ref<Object> s0;
	if (MoreGames::adUrls[MoreGames::pageIndex] != nullptr) {
		if (MoreGames::frameCounter % 30 >= 15) {
			if (MoreGames::pageIndex < 3) {
				s0 = MoreGames::texts;
				s1 = 9;
			} else {
				s0 = MoreGames::texts;
				s1 = 8;
			}
			text = cast<Array<Ref<String>>>(s0)[s1];
			MoreGames::font->measureString(text);
			boxWidth = SpritePack::textWidth + 2;
			textHeight = MoreGames::font->measureTextHeight(text);
			if (contentBottom == 0) {
				s0_n = 160;
				s1 = textHeight >> 1;
			} else {
				s0_n = 320 + contentBottom >> 1;
				s1 = (textHeight >> 1) + 4;
			}
			promptY = s0_n - s1;
			g->setClip(0, 0, 240, 320);
			g->setColor(16711680);
			g->fillRect(120 - (boxWidth >> 1) - 4, promptY - 4, boxWidth + 8, textHeight + 8);
			MoreGames::font->drawMultilineString(g, text, 120, promptY, 1);
			return;
		}
		return;
	}
}

void MoreGames::drawBackground(Ref<Graphics> g) {
	int32_t red = 0, blue = 0, band = 0;
	red = 99;
	blue = 189;
	g->setClip(0, 0, 240, 320);
	for (band = 0; band < 16; band++) {
		g->setColor(red << 16 | 0 | blue);
		g->fillRect(0, 160 + 160 * band / 16, 240, 21);
		g->fillRect(0, 160 - 160 * (band + 1) / 16, 240, 21);
		red = red - 4;
		blue = blue - 8;
	}
}

void MoreGames::updateAndDraw(Ref<Graphics> g) {
	int32_t contentBottom = 0, s0 = 0, s1_n = 0, s2 = 0;
	Ref<Actor> uiActor;
	Ref<Object> s0_o;
	MoreGames::drawBackground(g);
	contentBottom = 0;
	if (MoreGames::pageIndex != 3) {
		uiActor = Game::actors[0];
		uiActor->sprite->drawFrame(g, 11, 120, 15, 0, 0, 0);
	}
	switch (MoreGames::pageIndex) {
		default:
			g->drawImage(MoreGames::adImages[MoreGames::pageIndex], 120, 240, 33);
			MoreGames::font->drawMultilineString(g, MoreGames::texts[MoreGames::pageIndex], 120, 242, 17);
			s0 = 0;
			break;
		case 4:
			MoreGames::font->drawMultilineString(g, jnew<StringBuffer>()->append(u"\n\u0001\u0002"_j)->append(MoreGames::texts[6])->toString(), 120, 35, 17);
			MoreGames::font->drawMultilineString(g, MoreGames::texts[7], 120, 160, 3);
			MoreGames::font->measureString(MoreGames::texts[7]);
			s0 = 160 + (SpritePack::textHeight >> 1) + 4;
			break;
		case 3:
			g->drawImage(MoreGames::adImages[MoreGames::pageIndex], 120, 15, 17);
			MoreGames::font->drawMultilineString(g, MoreGames::texts[3], 120, 160, 3);
			MoreGames::font->measureString(MoreGames::texts[3]);
			s0 = 160 + (SpritePack::textHeight >> 1) + 4;
			break;
	}
	contentBottom = s0;
	Game::instance->drawBackSoftkeyIcon();
	if (MoreGames::adUrls[MoreGames::pageIndex] != nullptr) {
		Game::instance->drawSelectSoftkeyIcon();
	}
	MoreGames::drawBlinkingPrompt(g, contentBottom);
	if (!Game::isKeyDown(16388)) {
		if (!Game::isKeyDown(65544)) {
			if (!Game::isKeyDown(32944)) {
				if (Game::isKeyDown(64)) {
					Game::instance->openMenu(0);
					MoreGames::state = 2;
					Game::keys = 0;
				}
			} else {
				MoreGames::openUrl(MoreGames::adUrls[MoreGames::pageIndex]);
			}
		} else {
			MoreGames::changePage(1);
		}
	} else {
		MoreGames::changePage(-1);
	}
	MoreGames::arrowSprites->drawAnimFrame(g, !Game::isKeyDown(16388) ? 0 : 2, irem(MoreGames::frameCounter, MoreGames::arrowSprites->getAnimFrameCount(0)), 20 + this->arrowOffset, 160, 0, 0, 0);
	MoreGames::arrowSprites->drawAnimFrame(g, !Game::isKeyDown(65544) ? 1 : 3, irem(MoreGames::frameCounter, MoreGames::arrowSprites->getAnimFrameCount(1)), 220 - this->arrowOffset, 160, 0, 0, 0);
	s0_o = this;
	s1_n = this->arrowOffset;
	if (!this->isArrowReturning) {
		s0_o = cast<MoreGames>(s0_o);
		s2 = 1;
	} else {
		s0_o = cast<MoreGames>(s0_o);
		s2 = -1;
	}
	cast<MoreGames>(s0_o)->arrowOffset = s1_n + s2;
	if (this->arrowOffset > 3 || this->arrowOffset < 1) {
		this->isArrowReturning = !this->isArrowReturning ? 1 : 0;
	}
	Game::keys = 0;
}

void MoreGames::unload() {
	int32_t index = 0, length = 0;
	index = 0;
	length = MoreGames::adImages->length;
	for (index = 0; index < length; index++) {
		MoreGames::adImages[index] = nullptr;
	}
	MoreGames::adImages = nullptr;
	length = MoreGames::adUrls->length;
	for (index = 0; index < length; index++) {
		MoreGames::adUrls[index] = nullptr;
	}
	MoreGames::adUrls = nullptr;
	length = MoreGames::texts->length;
	for (index = 0; index < length; index++) {
		MoreGames::texts[index] = nullptr;
	}
	MoreGames::texts = nullptr;
	MoreGames::font = nullptr;
	MoreGames::arrowSprites = nullptr;
	MoreGames::state = 0;
	JSystem::gc();
}

