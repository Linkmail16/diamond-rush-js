'use strict';

class Actor {
	x = 0;
	y = 0;
	frameDx = 0;
	frameDy = 0;
	flipFlags = 0;
	sprite = null;
	animIndex = 0;
	frameIndex = 0;
	frameTimer = 0;
	parent = null;

	init_0() {
		return this;
	}

	init_1(spritePack, posX, posY, parentActor) {
		this.x = posX << 0;
		this.y = posY << 0;
		this.sprite = spritePack;
		this.parent = parentActor;
		return this;
	}

	setAnimation(anim) {
		if (anim !== this.animIndex) {
			this.animIndex = anim;
			this.frameIndex = 0;
			this.frameTimer = 0;
			this.frameDx = 0;
			this.frameDy = 0;
		}
	}

	applyFrameOffset() {
		let entryOffset = 0;
		entryOffset = (this.sprite.animFirstFrame[this.animIndex] + this.frameIndex | 0) * 5 | 0;
		this.frameDx = ((this.sprite.animFrames[entryOffset + 2] << 0) * 1 | 0) / 1 | 0;
		if ((this.flipFlags & 1) !== 0) {
			this.frameDx = -this.frameDx | 0;
		}
		this.frameDy = ((this.sprite.animFrames[entryOffset + 3] << 0) * 1 | 0) / 1 | 0;
		if ((this.flipFlags & 2) !== 0) {
			this.frameDy = -this.frameDy | 0;
		}
		this.x = this.x + this.frameDx | 0;
		this.y = this.y + this.frameDy | 0;
	}

	isAnimFinished() {
		let duration = 0;
		if (this.frameIndex === (this.sprite.getAnimFrameCount(this.animIndex) - 1 | 0)) {
			duration = this.sprite.getFrameDuration(this.animIndex, this.frameIndex);
			if (duration === 0 || this.frameTimer === (duration - 1 | 0)) {
				return 1;
			}
			return 0;
		}
		return 0;
	}

	draw(g) {
		let drawX = 0, drawY = 0, ancestor = null, s0;
		if (this.sprite !== null) {
			drawX = this.x;
			drawY = this.y;
			s0 = this;
			while (true) {
				ancestor = s0.parent;
				if (ancestor === null) {
					break;
				}
				drawX = drawX + ancestor.x | 0;
				drawY = drawY + ancestor.y | 0;
				s0 = ancestor;
			}
			drawX = Actor.toScreenX(drawX) + 0 | 0;
			drawY = Actor.toScreenY(drawY) + 0 | 0;
			if (this.frameTimer < 0) {
				if (this.animIndex < 0) {
					if (this.frameIndex >= 0) {
						this.sprite.drawFrame(g, this.frameIndex, drawX, drawY, this.flipFlags, 0, 0);
					}
					return;
				}
				this.sprite.drawModule(g, this.animIndex, drawX, drawY, this.flipFlags);
				return;
			}
			this.sprite.drawAnimFrame(g, this.animIndex, this.frameIndex, drawX, drawY, this.flipFlags, 0, 0);
			return;
		}
	}

	advanceFrame() {
		let duration = 0;
		if (this.sprite !== null) {
			if (this.frameTimer >= 0) {
				duration = this.sprite.getFrameDuration(this.animIndex, this.frameIndex);
				if (duration !== 0) {
					this.frameTimer = this.frameTimer + 1 | 0;
					if (duration <= this.frameTimer) {
						this.frameTimer = 0;
						this.frameIndex = this.frameIndex + 1 | 0;
						if (this.frameIndex >= this.sprite.getAnimFrameCount(this.animIndex)) {
							this.frameIndex = 0;
							this.frameDx = 0;
							this.frameDy = 0;
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

	static toScreenX(value) {
		return ((value >> 0) * 1 | 0) / 1 | 0;
	}

	static toScreenY(value) {
		return ((value >> 0) * 1 | 0) / 1 | 0;
	}

}
