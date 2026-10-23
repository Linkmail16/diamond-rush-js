#include "game.h"

Ref<SpritePack> SpritePack::init() {
	this->lineSpacing = 0;
	return this;
}

void SpritePack::loadFromBytes(Arr<int8_t> data, int32_t offset) {
	int32_t paletteFormat = 0, colorsPerPalette = 0, pal = 0, colorIndex = 0, color = 0, alpha = 0, error_n = 0, moduleCount = 0, frameModuleCount = 0, frameCount = 0, animFrameCount = 0, animCount = 0;
	Ref<Throwable> error;
	Ref<Object> s0;
	try {
		JSystem::gc();
		offset++;
		offset++;
		error_n = 0;
		offset++;
		offset++;
		offset++;
		offset++;
		moduleCount = (int16_t)((data[offset++] & 255) + ((data[offset++] & 255) << 8));
		if (moduleCount > 0) {
			this->moduleSizes = newArray<int8_t>(moduleCount << 1);
			JSystem::arraycopy(data, offset, this->moduleSizes, 0, this->moduleSizes->length);
			offset = offset + this->moduleSizes->length;
		}
		frameModuleCount = (int16_t)((data[offset++] & 255) + ((data[offset++] & 255) << 8));
		if (frameModuleCount > 0) {
			this->frameModules = newArray<int8_t>(frameModuleCount << 2);
			JSystem::arraycopy(data, offset, this->frameModules, 0, this->frameModules->length);
			offset = offset + this->frameModules->length;
		}
		frameCount = (int16_t)((data[offset++] & 255) + ((data[offset++] & 255) << 8));
		if (frameCount > 0) {
			this->frameModuleCounts = newArray<int8_t>(frameCount);
			this->frameFirstModule = newArray<int16_t>(frameCount);
			for (animFrameCount = 0; animFrameCount < frameCount; animFrameCount++) {
				this->frameModuleCounts[animFrameCount] = data[offset++];
				offset++;
				this->frameFirstModule[animFrameCount] = (int16_t)((data[offset++] & 255) + ((data[offset++] & 255) << 8));
			}
			animFrameCount = frameCount << 2;
			this->frameBounds = newArray<int8_t>(animFrameCount);
			for (animCount = 0; animCount < animFrameCount; animCount++) {
				this->frameBounds[animCount] = data[offset++];
			}
		}
		animFrameCount = (int16_t)((data[offset++] & 255) + ((data[offset++] & 255) << 8));
		if (animFrameCount > 0) {
			this->animFrames = newArray<int8_t>(animFrameCount * 5);
			JSystem::arraycopy(data, offset, this->animFrames, 0, this->animFrames->length);
			offset = offset + this->animFrames->length;
		}
		animCount = (int16_t)((data[offset++] & 255) + ((data[offset++] & 255) << 8));
		if (animCount > 0) {
			this->animFrameCounts = newArray<int8_t>(animCount);
			this->animFirstFrame = newArray<int16_t>(animCount);
			for (paletteFormat = 0; paletteFormat < animCount; paletteFormat++) {
				this->animFrameCounts[paletteFormat] = data[offset++];
				offset++;
				this->animFirstFrame[paletteFormat] = (int16_t)((data[offset++] & 255) + ((data[offset++] & 255) << 8));
			}
		}
		if (moduleCount <= 0) {
			JSystem::gc();
			return;
		}
	} catch (JavaException& ex) {
		if (ex.isa(u"java/lang/Exception")) {
			s0 = ex.ex;
			error = cast<Throwable>(s0);
			error->printStackTrace();
			return;
		}
		else throw;
	}
	try {
		paletteFormat = (int16_t)((data[offset++] & 255) + ((data[offset++] & 255) << 8));
		this->paletteCount = data[offset++] & 255;
		colorsPerPalette = data[offset++] & 255;
		this->palettes = newArray<Arr<int32_t>>(16);
		for (pal = 0; pal < this->paletteCount; pal++) {
			this->palettes[pal] = newArray<int32_t>(colorsPerPalette);
			switch (paletteFormat) {
				case 25861:
					for (colorIndex = 0; colorIndex < colorsPerPalette; colorIndex++) {
						color = data[offset++] & 255;
						color = color + ((data[offset++] & 255) << 8);
						alpha = -16777216;
						if (color == 63519) {
							alpha = 0;
							this->hasTransparency = 1;
						}
						this->palettes[pal][colorIndex] = alpha | (color & 63488) << 8 | (color & 2016) << 5 | (color & 31) << 3;
					}
					break;
				case 21781:
					for (colorIndex = 0; colorIndex < colorsPerPalette; colorIndex++) {
						color = data[offset++] & 255;
						color = color + ((data[offset++] & 255) << 8);
						alpha = -16777216;
						if ((color & 32768) != 32768) {
							alpha = 0;
							this->hasTransparency = 1;
						}
						this->palettes[pal][colorIndex] = alpha | (color & 31744) << 9 | (color & 992) << 6 | (color & 31) << 3;
					}
					break;
				case 17476:
					for (colorIndex = 0; colorIndex < colorsPerPalette; colorIndex++) {
						color = data[offset++] & 255;
						color = color + ((data[offset++] & 255) << 8);
						if ((color & 61440) != 61440) {
							this->hasTransparency = 1;
						}
						this->palettes[pal][colorIndex] = (color & 61440) << 16 | (color & 61440) << 12 | (color & 3840) << 12 | (color & 3840) << 8 | (color & 240) << 8 | (color & 240) << 4 | (color & 15) << 4 | color & 15;
					}
					break;
				case -30584:
					for (colorIndex = 0; colorIndex < colorsPerPalette; colorIndex++) {
						color = data[offset++] & 255;
						color = color + ((data[offset++] & 255) << 8);
						color = color + ((data[offset++] & 255) << 16);
						color = color + ((data[offset++] & 255) << 24);
						if ((color & -16777216) != -16777216) {
							this->hasTransparency = 1;
						}
						this->palettes[pal][colorIndex] = color;
					}
					break;
				default:
					break;
			}
		}
		this->pixelEncoding = (int16_t)((data[offset++] & 255) + ((data[offset++] & 255) << 8));
		if (moduleCount > 0) {
			this->moduleDataOffsets = newArray<int16_t>(moduleCount);
			pal = 0;
			colorIndex = offset;
			for (color = 0; color < moduleCount; color++) {
				alpha = (int16_t)((data[colorIndex++] & 255) + ((data[colorIndex++] & 255) << 8));
				this->moduleDataOffsets[color] = (int16_t)pal;
				colorIndex = colorIndex + alpha;
				pal = pal + alpha;
			}
			this->moduleData = newArray<int8_t>(pal);
			for (color = 0; color < moduleCount; color++) {
				alpha = (int16_t)((data[offset++] & 255) + ((data[offset++] & 255) << 8));
				JSystem::arraycopy(data, offset, this->moduleData, this->moduleDataOffsets[color] & 65535, alpha);
				offset = offset + alpha;
			}
		}
		JSystem::gc();
	} catch (JavaException& ex) {
		if (ex.isa(u"java/lang/Exception")) {
			s0 = ex.ex;
			error = cast<Throwable>(s0);
			error->printStackTrace();
			return;
		}
		else throw;
	}
}

void SpritePack::buildModuleImages(int32_t palette, int32_t firstModule, int32_t lastModule, int32_t sourcePalette) {
	Arr<int32_t> pixels;
	int32_t hasAlpha = 0, pixelCount = 0, pixelIndex = 0, savedPalette = 0, module = 0, sizeIndex = 0, width = 0, height = 0;
	if (this->moduleSizes != nullptr) {
		if (lastModule == -1) {
			lastModule = (this->moduleSizes->length >> 1) - 1;
		}
		if (this->moduleImages == nullptr) {
			this->moduleImages = newArray<Arr<Ref<Image>>>(this->paletteCount);
		}
		if (this->moduleImages[palette] == nullptr) {
			this->moduleImages[palette] = newArray<Ref<Image>>(this->moduleSizes->length >> 1);
		}
		if (sourcePalette < 0) {
			savedPalette = this->paletteIndex;
			this->paletteIndex = palette;
			JSystem::gc();
			module = firstModule;
			while (module <= lastModule) {
				sizeIndex = module << 1;
				width = this->moduleSizes[sizeIndex] & 255;
				height = this->moduleSizes[sizeIndex + 1] & 255;
				if (width > 0) {
					if (height > 0) {
						pixels = this->decodeModulePixels(module);
						if (pixels != nullptr) {
							hasAlpha = 0;
							pixelCount = width * height;
							pixelIndex = 0;
							while (pixelIndex < pixelCount) {
								if ((pixels[pixelIndex] & -16777216) == -16777216) {
									pixelIndex++;
									continue;
								}
								hasAlpha = 1;
								break;
							}
							this->moduleImages[palette][module] = Image::createRGBImage(pixels, width, height, hasAlpha);
						}
					}
				}
				module++;
			}
			JSystem::gc();
			this->paletteIndex = savedPalette;
		} else {
			for (savedPalette = firstModule; savedPalette <= lastModule; savedPalette++) {
				this->moduleImages[palette][savedPalette] = this->moduleImages[sourcePalette][savedPalette];
			}
		}
		JSystem::gc();
		return;
	}
}

void SpritePack::freeModuleImages(int32_t palette) {
	int32_t module = 0;
	if (this->moduleSizes != nullptr) {
		if (this->moduleImages != nullptr) {
			if (this->moduleImages[palette] != nullptr) {
				for (module = 0; module < this->moduleImages[palette]->length; module++) {
					this->moduleImages[palette][module] = nullptr;
				}
				this->moduleImages[palette] = nullptr;
				this->paletteCount = this->paletteCount - 1;
				return;
			}
			return;
		}
		return;
	}
}

Ref<String> SpritePack::toString() {
	Ref<String> result;
	int32_t fullSize = 0, module = 0;
	u""_j;
	result = nullptr;
	fullSize = 0;
	for (module = 0; module < this->moduleSizes->length / 2; module++) {
		fullSize = fullSize + 2 * (this->moduleSizes[2 * module] & 255) * (this->moduleSizes[2 * module + 1] & 255);
	}
	result = jnew<StringBuffer>()->append(u"raw/full: "_j)->append(this->moduleData->length)->append(u"/"_j)->append(fullSize)->toString();
	return result;
}

int32_t SpritePack::getFrameDuration(int32_t anim, int32_t frame) {
	return this->animFrames[(this->animFirstFrame[anim] + frame) * 5 + 1] & 255;
}

int32_t SpritePack::getAnimFrameCount(int32_t anim) {
	return this->animFrameCounts[anim] & 255;
}

int32_t SpritePack::getFrameModuleCount(int32_t frame) {
	return this->frameModuleCounts[frame] & 255;
}

int32_t SpritePack::measureTextHeight(Ref<String> text) {
	int32_t lineCount = 0, length = 0, newlinePos = 0;
	lineCount = 1;
	length = text->length();
	newlinePos = text->indexOf(10);
	while (newlinePos != -1) {
		lineCount++;
		newlinePos = newlinePos >= length - 1 ? -1 : text->indexOf(10, newlinePos + 1);
	}
	return this->lineSpacing * (lineCount - 1) + this->moduleSizes[1] * lineCount;
}

void SpritePack::drawAnimFrame(Ref<Graphics> g, int32_t anim, int32_t frame, int32_t x, int32_t y, int32_t flags, int32_t offsetX, int32_t offsetY) {
	int32_t frameId = 0, entryOffset = 0;
	entryOffset = (this->animFirstFrame[anim] + frame) * 5;
	frameId = this->animFrames[entryOffset] & 255;
	if ((flags & 32) != 0) {
		offsetX = (flags & 1) == 0 ? offsetX - this->animFrames[entryOffset + 2] : offsetX + this->animFrames[entryOffset + 2];
		offsetY = (flags & 2) == 0 ? offsetY - this->animFrames[entryOffset + 3] : offsetY + this->animFrames[entryOffset + 3];
	}
	this->drawFrame(g, frameId, x - offsetX, y - offsetY, flags ^ this->animFrames[entryOffset + 4] & 15, offsetX, offsetY);
}

void SpritePack::drawFrame(Ref<Graphics> g, int32_t frame, int32_t x, int32_t y, int32_t flags, int32_t offsetX, int32_t offsetY) {
	int32_t moduleCount = 0, part = 0;
	moduleCount = this->frameModuleCounts[frame] & 255;
	for (part = 0; part < moduleCount; part++) {
		this->drawFramePart(g, frame, part, x, y, flags);
	}
}

void SpritePack::drawFramePart(Ref<Graphics> g, int32_t frame, int32_t part, int32_t x, int32_t y, int32_t flags) {
	int32_t entryOffset = 0, partFlags = 0, module = 0;
	entryOffset = this->frameFirstModule[frame] + part << 2;
	partFlags = this->frameModules[entryOffset + 3] & 255;
	module = this->frameModules[entryOffset] & 255;
	x = (flags & 1) == 0 ? x + this->frameModules[entryOffset + 1] : x - this->frameModules[entryOffset + 1];
	y = (flags & 2) == 0 ? y + this->frameModules[entryOffset + 2] : y - this->frameModules[entryOffset + 2];
	if ((flags & 1) != 0) {
		x = x - (this->moduleSizes[module << 1] & 255);
	}
	if ((flags & 2) != 0) {
		y = y - (this->moduleSizes[(module << 1) + 1] & 255);
	}
	this->drawModule(g, module, x, y, flags ^ partFlags & 15);
}

void SpritePack::drawModule(Ref<Graphics> g, int32_t module, int32_t x, int32_t y, int32_t flags) {
	Arr<int32_t> pixels;
	int32_t sizeIndex = 0, width = 0, height = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0;
	Ref<Image> image;
	Ref<Object> s0, s1;
	sizeIndex = module << 1;
	width = this->moduleSizes[sizeIndex] & 255;
	height = this->moduleSizes[sizeIndex + 1] & 255;
	if (width <= 0 || height <= 0) {
		return;
	}
	image = nullptr;
	if (this->moduleImages != nullptr && this->moduleImages[this->paletteIndex] != nullptr) {
		image = this->moduleImages[this->paletteIndex][module];
	}
	if (image == nullptr) {
		pixels = this->decodeModulePixels(module);
		if (pixels != nullptr) {
			image = Image::createRGBImage(pixels, width, height, this->hasTransparency);
		} else {
			return;
		}
	}
	width = image->getWidth();
	height = image->getHeight();
	if ((flags & 1) == 0) {
		if ((flags & 2) == 0) {
			s0 = g;
			s1 = image;
			s2 = 0;
			s3 = 0;
			s4 = width;
			s5 = height;
			s6 = 0;
		} else {
			s0 = g;
			s1 = image;
			s2 = 0;
			s3 = 0;
			s4 = width;
			s5 = height;
			s6 = 1;
		}
	} else {
		if ((flags & 2) == 0) {
			s0 = g;
			s1 = image;
			s2 = 0;
			s3 = 0;
			s4 = width;
			s5 = height;
			s6 = 2;
		} else {
			s0 = g;
			s1 = image;
			s2 = 0;
			s3 = 0;
			s4 = width;
			s5 = height;
			s6 = 3;
		}
	}
	cast<Graphics>(s0)->drawRegion(cast<Image>(s1), s2, s3, s4, s5, s6, x, y, 0);
}

Arr<int32_t> SpritePack::decodeModulePixels(int32_t module) {
	int32_t pixelCount = 0, runLength = 0, color = 0, runColor = 0, sizeIndex = 0, width = 0, height = 0, readPos = 0, writePos = 0, t3 = 0, t5 = 0, t6 = 0;
	Arr<int32_t> out, palette;
	Arr<int8_t> data;
	if (this->moduleData == nullptr || this->moduleDataOffsets == nullptr) {
		return nullptr;
	}
	sizeIndex = module << 1;
	width = this->moduleSizes[sizeIndex] & 255;
	height = this->moduleSizes[sizeIndex + 1] & 255;
	out = SpritePack::pixelBuffer;
	palette = this->palettes[this->paletteIndex];
	if (palette != nullptr) {
		data = this->moduleData;
		readPos = this->moduleDataOffsets[module] & 65535;
		writePos = 0;
		pixelCount = width * height;
		if (this->pixelEncoding != 10225) {
			if (this->pixelEncoding != 5632) {
				if (this->pixelEncoding != 1024) {
					if (this->pixelEncoding != 512) {
						if (this->pixelEncoding != 22018) {
							if (this->pixelEncoding == 22258) {
								while (writePos < pixelCount) {
									runLength = data[readPos++] & 255;
									if (runLength <= 127) {
										color = palette[data[readPos++] & 255];
										while (true) {
											t6 = runLength;
											runLength = runLength - 1;
											if (t6 <= 0) {
												break;
											}
											out[writePos++] = color;
										}
									} else {
										runLength -= 128;
										while (true) {
											t5 = runLength;
											runLength = runLength - 1;
											if (t5 <= 0) {
												break;
											}
											out[writePos++] = palette[data[readPos++] & 255];
										}
									}
								}
							}
						} else {
							while (writePos < pixelCount) {
								out[writePos++] = palette[data[readPos++] & 255];
							}
						}
					} else {
						while (writePos < pixelCount) {
							out[writePos++] = palette[data[readPos] >> 7 & 1];
							out[writePos++] = palette[data[readPos] >> 6 & 1];
							out[writePos++] = palette[data[readPos] >> 5 & 1];
							out[writePos++] = palette[data[readPos] >> 4 & 1];
							out[writePos++] = palette[data[readPos] >> 3 & 1];
							out[writePos++] = palette[data[readPos] >> 2 & 1];
							out[writePos++] = palette[data[readPos] >> 1 & 1];
							out[writePos++] = palette[data[readPos] & 1];
							readPos++;
						}
					}
				} else {
					while (writePos < pixelCount) {
						out[writePos++] = palette[data[readPos] >> 6 & 3];
						out[writePos++] = palette[data[readPos] >> 4 & 3];
						out[writePos++] = palette[data[readPos] >> 2 & 3];
						out[writePos++] = palette[data[readPos] & 3];
						readPos++;
					}
				}
			} else {
				while (writePos < pixelCount) {
					out[writePos++] = palette[data[readPos] >> 4 & 15];
					out[writePos++] = palette[data[readPos] & 15];
					readPos++;
				}
			}
		} else {
			while (writePos < pixelCount) {
				runLength = data[readPos++] & 255;
				if (runLength <= 127) {
					out[writePos++] = palette[runLength];
				} else {
					color = data[readPos++] & 255;
					runColor = palette[color];
					runLength -= 128;
					while (true) {
						t3 = runLength;
						runLength = runLength - 1;
						if (t3 <= 0) {
							break;
						}
						out[writePos++] = runColor;
					}
				}
			}
		}
		return out;
	}
	return nullptr;
}

void SpritePack::measureString(Ref<String> text) {
	int32_t lineWidth = 0, start = 0, end = 0, charIndex = 0, ch = 0, glyphIndex = 0, s0 = 0, s1 = 0, s2 = 0, t2 = 0;
	SpritePack::textWidth = 0;
	SpritePack::textHeight = this->moduleSizes[1] & 255;
	lineWidth = 0;
	start = SpritePack::textStart < 0 ? 0 : SpritePack::textStart;
	end = SpritePack::textEnd < 0 ? text->length() : SpritePack::textEnd;
	for (charIndex = start; charIndex < end; charIndex++) {
		ch = text->charAt(charIndex);
		if (ch <= 32) {
			if (ch != 32) {
				if (ch != 10) {
					if (ch != 1) {
						if (ch == 2) {
							charIndex++;
							s0 = text->charAt(charIndex);
							ch = s0;
							if (ch < this->getFrameModuleCount(0)) {
								glyphIndex = (this->frameModules[ch << 2] & 255) << 1;
								s0 = lineWidth;
								s1 = this->moduleSizes[glyphIndex] & 255;
								s2 = this->frameModules[(ch << 2) + 1];
							} else {
								glyphIndex = ch - this->getFrameModuleCount(0);
								s0 = lineWidth;
								s1 = this->frameBounds[(glyphIndex << 2) + 2] & 255;
								s2 = this->frameBounds[glyphIndex << 2] & 255;
							}
							t2 = s1 - s2;
							s1 = t2;
							lineWidth = s0 + (s1 + this->frameModules[1]);
						}
					} else {
						charIndex++;
					}
				} else {
					if (lineWidth > SpritePack::textWidth) {
						SpritePack::textWidth = lineWidth;
					}
					lineWidth = 0;
					SpritePack::textHeight = SpritePack::textHeight + (this->lineSpacing + (this->moduleSizes[1] & 255));
				}
			} else {
				s0 = lineWidth;
				s1 = this->moduleSizes[0] & 255;
				lineWidth = s0 + (s1 + this->frameModules[1]);
			}
		} else {
			s0 = SpritePack::charMap[ch] & 255;
			ch = s0;
			if (ch < this->getFrameModuleCount(0)) {
				glyphIndex = (this->frameModules[ch << 2] & 255) << 1;
				s0 = lineWidth;
				s1 = this->moduleSizes[glyphIndex] & 255;
				s2 = this->frameModules[(ch << 2) + 1];
			} else {
				glyphIndex = ch - this->getFrameModuleCount(0);
				s0 = lineWidth;
				s1 = this->frameBounds[(glyphIndex << 2) + 2] & 255;
				s2 = this->frameBounds[glyphIndex << 2] & 255;
			}
			t2 = s1 - s2;
			s1 = t2;
			lineWidth = s0 + (s1 + this->frameModules[1]);
		}
	}
	if (lineWidth > SpritePack::textWidth) {
		SpritePack::textWidth = lineWidth;
	}
	if (SpritePack::textWidth > 0) {
		SpritePack::textWidth = SpritePack::textWidth - this->frameModules[1];
	}
}

void SpritePack::drawString(Ref<Graphics> g, Ref<String> text, int32_t x, int32_t y, int32_t anchor) {
	int32_t end = 0, charIndex = 0, ch = 0, glyphIndex = 0, penX = 0, penY = 0, savedPalette = 0, start = 0, s0 = 0, s1 = 0, s2 = 0, t2 = 0;
	y = y - this->frameModules[2];
	if ((anchor & 43) != 0) {
		this->measureString(text);
		if ((anchor & 8) == 0) {
			if ((anchor & 1) != 0) {
				s0 = x;
				s1 = SpritePack::textWidth >> 1;
				x = s0 - s1;
			}
		} else {
			s0 = x;
			s1 = SpritePack::textWidth;
			x = s0 - s1;
		}
		if ((anchor & 32) == 0) {
			if ((anchor & 2) != 0) {
				s0 = y;
				s1 = SpritePack::textHeight >> 1;
				y = s0 - s1;
			}
		} else {
			s0 = y;
			s1 = SpritePack::textHeight;
			y = s0 - s1;
		}
	}
	penX = x;
	penY = y;
	savedPalette = this->paletteIndex;
	start = SpritePack::textStart < 0 ? 0 : SpritePack::textStart;
	end = SpritePack::textEnd < 0 ? text->length() : SpritePack::textEnd;
	for (charIndex = start; charIndex < end; charIndex++) {
		ch = text->charAt(charIndex);
		if (ch <= 32) {
			if (ch != 32) {
				if (ch != 10) {
					if (ch != 1) {
						if (ch == 2) {
							charIndex++;
							s0 = text->charAt(charIndex);
							ch = s0;
							if (ch < this->getFrameModuleCount(0)) {
								glyphIndex = (this->frameModules[ch << 2] & 255) << 1;
								this->drawFramePart(g, 0, ch, penX, penY, 0);
								s0 = penX;
								s1 = this->moduleSizes[glyphIndex] & 255;
								s2 = this->frameModules[(ch << 2) + 1];
							} else {
								glyphIndex = ch - this->getFrameModuleCount(0);
								this->drawFrame(g, glyphIndex, penX, penY, 0, 0, 0);
								s0 = penX;
								s1 = this->frameBounds[(glyphIndex << 2) + 2] & 255;
								s2 = this->frameBounds[glyphIndex << 2] & 255;
							}
							t2 = s1 - s2;
							s1 = t2;
							penX = s0 + (s1 + this->frameModules[1]);
						}
					} else {
						charIndex++;
						this->paletteIndex = text->charAt(charIndex);
					}
				} else {
					penX = x;
					penY = penY + (this->lineSpacing + (this->moduleSizes[1] & 255));
				}
			} else {
				s0 = penX;
				s1 = this->moduleSizes[0] & 255;
				penX = s0 + (s1 + this->frameModules[1]);
			}
		} else {
			s0 = SpritePack::charMap[ch] & 255;
			ch = s0;
			if (ch < this->getFrameModuleCount(0)) {
				glyphIndex = (this->frameModules[ch << 2] & 255) << 1;
				this->drawFramePart(g, 0, ch, penX, penY, 0);
				s0 = penX;
				s1 = this->moduleSizes[glyphIndex] & 255;
				s2 = this->frameModules[(ch << 2) + 1];
			} else {
				glyphIndex = ch - this->getFrameModuleCount(0);
				this->drawFrame(g, glyphIndex, penX, penY, 0, 0, 0);
				s0 = penX;
				s1 = this->frameBounds[(glyphIndex << 2) + 2] & 255;
				s2 = this->frameBounds[glyphIndex << 2] & 255;
			}
			t2 = s1 - s2;
			s1 = t2;
			penX = s0 + (s1 + this->frameModules[1]);
		}
	}
	this->paletteIndex = savedPalette;
}

void SpritePack::drawMultilineString(Ref<Graphics> g, Ref<String> text, int32_t x, int32_t y, int32_t anchor) {
	int32_t line = 0, lineCount = 0, length = 0, lineHeight = 0, s0 = 0, s1 = 0;
	Arr<int32_t> lineEnds;
	lineCount = 0;
	length = text->length();
	lineEnds = newArray<int32_t>(100);
	for (lineHeight = 0; lineHeight < length; lineHeight++) {
		if (text->charAt(lineHeight) == 10) {
			lineEnds[lineCount++] = lineHeight;
		}
	}
	lineEnds[lineCount++] = length;
	lineHeight = this->lineSpacing + (this->moduleSizes[1] & 255);
	if ((anchor & 32) == 0) {
		if ((anchor & 2) != 0) {
			s0 = y;
			s1 = lineHeight * (lineCount - 1) >> 1;
			y = s0 - s1;
		}
	} else {
		s0 = y;
		s1 = lineHeight * (lineCount - 1);
		y = s0 - s1;
	}
	for (line = 0; line < lineCount; line++) {
		SpritePack::textStart = line <= 0 ? 0 : lineEnds[line - 1] + 1;
		SpritePack::textEnd = lineEnds[line];
		this->drawString(g, text, x, y + line * lineHeight, anchor);
	}
	SpritePack::textStart = -1;
	SpritePack::textEnd = -1;
}

void SpritePack::unload(bool freeImages) {
	int32_t i = 0, j = 0;
	this->moduleSizes = nullptr;
	this->frameModuleCounts = nullptr;
	this->frameFirstModule = nullptr;
	this->frameBounds = nullptr;
	this->frameModules = nullptr;
	this->animFrameCounts = nullptr;
	this->animFirstFrame = nullptr;
	this->animFrames = nullptr;
	if (this->cachedPixels != nullptr) {
		for (i = 0; i < this->cachedPixels->length; i++) {
			this->cachedPixels[i] = nullptr;
		}
		this->cachedPixels = nullptr;
	}
	if (this->palettes != nullptr) {
		for (i = 0; i < this->palettes->length; i++) {
			this->palettes[i] = nullptr;
		}
		this->palettes = nullptr;
	}
	this->moduleData = nullptr;
	this->moduleDataOffsets = nullptr;
	if (freeImages != 0 && this->moduleImages != nullptr) {
		for (i = 0; i < this->moduleImages->length; i++) {
			if (this->moduleImages[i] != nullptr) {
				for (j = 0; j < this->moduleImages[i]->length; j++) {
					this->moduleImages[i][j] = nullptr;
				}
			}
		}
		this->moduleImages = nullptr;
	}
}

void SpritePack::clinit() {
	SpritePack::pixelBuffer = newArray<int32_t>(4096);
	SpritePack::textStart = -1;
	SpritePack::textEnd = -1;
}

