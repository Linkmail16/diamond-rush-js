#include "game.h"

Ref<Actor> Actor::init_0() {
	return this;
}

Ref<Actor> Actor::init_1(Ref<SpritePack> spritePack, int32_t posX, int32_t posY, Ref<Actor> parentActor) {
	this->x = posX << 0;
	this->y = posY << 0;
	this->sprite = spritePack;
	this->parent = parentActor;
	return this;
}

void Actor::setAnimation(int32_t anim) {
	if (anim != this->animIndex) {
		this->animIndex = anim;
		this->frameIndex = 0;
		this->frameTimer = 0;
		this->frameDx = 0;
		this->frameDy = 0;
	}
}

void Actor::applyFrameOffset() {
	int32_t entryOffset = 0;
	entryOffset = (this->sprite->animFirstFrame[this->animIndex] + this->frameIndex) * 5;
	this->frameDx = (this->sprite->animFrames[entryOffset + 2] << 0) * 1 / 1;
	if ((this->flipFlags & 1) != 0) {
		this->frameDx = -this->frameDx;
	}
	this->frameDy = (this->sprite->animFrames[entryOffset + 3] << 0) * 1 / 1;
	if ((this->flipFlags & 2) != 0) {
		this->frameDy = -this->frameDy;
	}
	this->x = this->x + this->frameDx;
	this->y = this->y + this->frameDy;
}

bool Actor::isAnimFinished() {
	int32_t duration = 0;
	if (this->frameIndex == this->sprite->getAnimFrameCount(this->animIndex) - 1) {
		duration = this->sprite->getFrameDuration(this->animIndex, this->frameIndex);
		if (duration == 0 || this->frameTimer == duration - 1) {
			return 1;
		}
		return 0;
	}
	return 0;
}

void Actor::draw(Ref<Graphics> g) {
	int32_t drawX = 0, drawY = 0;
	Ref<Actor> ancestor;
	Ref<Object> s0;
	if (this->sprite != nullptr) {
		drawX = this->x;
		drawY = this->y;
		s0 = this;
		while (true) {
			ancestor = cast<Actor>(s0)->parent;
			if (ancestor == nullptr) {
				break;
			}
			drawX = drawX + ancestor->x;
			drawY = drawY + ancestor->y;
			s0 = ancestor;
		}
		drawX = Actor::toScreenX(drawX) + 0;
		drawY = Actor::toScreenY(drawY) + 0;
		if (this->frameTimer < 0) {
			if (this->animIndex < 0) {
				if (this->frameIndex >= 0) {
					this->sprite->drawFrame(g, this->frameIndex, drawX, drawY, this->flipFlags, 0, 0);
				}
				return;
			}
			this->sprite->drawModule(g, this->animIndex, drawX, drawY, this->flipFlags);
			return;
		}
		this->sprite->drawAnimFrame(g, this->animIndex, this->frameIndex, drawX, drawY, this->flipFlags, 0, 0);
		return;
	}
}

void Actor::advanceFrame() {
	int32_t duration = 0;
	if (this->sprite != nullptr) {
		if (this->frameTimer >= 0) {
			duration = this->sprite->getFrameDuration(this->animIndex, this->frameIndex);
			if (duration != 0) {
				this->frameTimer = this->frameTimer + 1;
				if (duration <= this->frameTimer) {
					this->frameTimer = 0;
					this->frameIndex = this->frameIndex + 1;
					if (this->frameIndex >= this->sprite->getAnimFrameCount(this->animIndex)) {
						this->frameIndex = 0;
						this->frameDx = 0;
						this->frameDy = 0;
					}
					return;
				}
				return;
			}
			return;
		}
		return;
	}
}

int32_t Actor::toScreenX(int32_t value) {
	return (value >> 0) * 1 / 1;
}

int32_t Actor::toScreenY(int32_t value) {
	return (value >> 0) * 1 / 1;
}

