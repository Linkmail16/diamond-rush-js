'use strict';

class SpritePack {
	static pixelBuffer = null;
	moduleSizes = null;
	frameModuleCounts = null;
	frameFirstModule = null;
	frameBounds = null;
	frameModules = null;
	animFrameCounts = null;
	animFirstFrame = null;
	animFrames = null;
	cachedPixels = null;
	palettes = null;
	paletteCount = 0;
	paletteIndex = 0;
	hasTransparency = 0;
	pixelEncoding = 0;
	moduleData = null;
	moduleDataOffsets = null;
	moduleImages = null;
	static textWidth = 0;
	static textHeight = 0;
	static charMap = null;
	lineSpacing = 0;
	static textStart = 0;
	static textEnd = 0;

	init() {
		this.lineSpacing = 0;
		return this;
	}

	loadFromBytes(data, offset) {
		let colorsPerPalette = 0, moduleCount = 0, error = 0, color = 0, animFrameCount = 0, animCount = 0, frameCount = 0, paletteFormat = 0, pal = 0, colorIndex = 0, frameModuleCount = 0, alpha = 0, s0;
		try {
			JSystem.gc();
			offset++;
			offset++;
			error = 0;
			offset++;
			offset++;
			offset++;
			offset++;
			moduleCount = (data[offset++] & 255) + ((data[offset++] & 255) << 8) << 16 >> 16;
			if (moduleCount > 0) {
				this.moduleSizes = new Int8Array(moduleCount << 1);
				JSystem.arraycopy(data, offset, this.moduleSizes, 0, this.moduleSizes.length);
				offset = offset + this.moduleSizes.length | 0;
			}
			frameModuleCount = (data[offset++] & 255) + ((data[offset++] & 255) << 8) << 16 >> 16;
			if (frameModuleCount > 0) {
				this.frameModules = new Int8Array(frameModuleCount << 2);
				JSystem.arraycopy(data, offset, this.frameModules, 0, this.frameModules.length);
				offset = offset + this.frameModules.length | 0;
			}
			frameCount = (data[offset++] & 255) + ((data[offset++] & 255) << 8) << 16 >> 16;
			if (frameCount > 0) {
				this.frameModuleCounts = new Int8Array(frameCount);
				this.frameFirstModule = new Int16Array(frameCount);
				for (animFrameCount = 0; animFrameCount < frameCount; animFrameCount++) {
					this.frameModuleCounts[animFrameCount] = data[offset++];
					offset++;
					this.frameFirstModule[animFrameCount] = (data[offset++] & 255) + ((data[offset++] & 255) << 8) << 16 >> 16;
				}
				animFrameCount = frameCount << 2;
				this.frameBounds = new Int8Array(animFrameCount);
				for (animCount = 0; animCount < animFrameCount; animCount++) {
					this.frameBounds[animCount] = data[offset++];
				}
			}
			animFrameCount = (data[offset++] & 255) + ((data[offset++] & 255) << 8) << 16 >> 16;
			if (animFrameCount > 0) {
				this.animFrames = new Int8Array(animFrameCount * 5 | 0);
				JSystem.arraycopy(data, offset, this.animFrames, 0, this.animFrames.length);
				offset = offset + this.animFrames.length | 0;
			}
			animCount = (data[offset++] & 255) + ((data[offset++] & 255) << 8) << 16 >> 16;
			if (animCount > 0) {
				this.animFrameCounts = new Int8Array(animCount);
				this.animFirstFrame = new Int16Array(animCount);
				for (paletteFormat = 0; paletteFormat < animCount; paletteFormat++) {
					this.animFrameCounts[paletteFormat] = data[offset++];
					offset++;
					this.animFirstFrame[paletteFormat] = (data[offset++] & 255) + ((data[offset++] & 255) << 8) << 16 >> 16;
				}
			}
			if (moduleCount <= 0) {
				JSystem.gc();
				return;
			}
		} catch (ex) {
			ex = J.exc(ex);
			if (J.isa(ex, "java/lang/Exception")) {
				s0 = ex;
				error = s0;
				error.printStackTrace();
				return;
			}
			else throw ex;
		}
		try {
			paletteFormat = (data[offset++] & 255) + ((data[offset++] & 255) << 8) << 16 >> 16;
			this.paletteCount = data[offset++] & 255;
			colorsPerPalette = data[offset++] & 255;
			this.palettes = J.newArray(16);
			for (pal = 0; pal < this.paletteCount; pal++) {
				this.palettes[pal] = new Int32Array(colorsPerPalette);
				switch (paletteFormat) {
					case 25861:
						for (colorIndex = 0; colorIndex < colorsPerPalette; colorIndex++) {
							color = data[offset++] & 255;
							color = color + ((data[offset++] & 255) << 8) | 0;
							alpha = -16777216;
							if (color === 63519) {
								alpha = 0;
								this.hasTransparency = 1;
							}
							this.palettes[pal][colorIndex] = alpha | (color & 63488) << 8 | (color & 2016) << 5 | (color & 31) << 3;
						}
						break;
					case 21781:
						for (colorIndex = 0; colorIndex < colorsPerPalette; colorIndex++) {
							color = data[offset++] & 255;
							color = color + ((data[offset++] & 255) << 8) | 0;
							alpha = -16777216;
							if ((color & 32768) !== 32768) {
								alpha = 0;
								this.hasTransparency = 1;
							}
							this.palettes[pal][colorIndex] = alpha | (color & 31744) << 9 | (color & 992) << 6 | (color & 31) << 3;
						}
						break;
					case 17476:
						for (colorIndex = 0; colorIndex < colorsPerPalette; colorIndex++) {
							color = data[offset++] & 255;
							color = color + ((data[offset++] & 255) << 8) | 0;
							if ((color & 61440) !== 61440) {
								this.hasTransparency = 1;
							}
							this.palettes[pal][colorIndex] = (color & 61440) << 16 | (color & 61440) << 12 | (color & 3840) << 12 | (color & 3840) << 8 | (color & 240) << 8 | (color & 240) << 4 | (color & 15) << 4 | color & 15;
						}
						break;
					case -30584:
						for (colorIndex = 0; colorIndex < colorsPerPalette; colorIndex++) {
							color = data[offset++] & 255;
							color = color + ((data[offset++] & 255) << 8) | 0;
							color = color + ((data[offset++] & 255) << 16) | 0;
							color = color + ((data[offset++] & 255) << 24) | 0;
							if ((color & -16777216) !== -16777216) {
								this.hasTransparency = 1;
							}
							this.palettes[pal][colorIndex] = color;
						}
						break;
					default:
						break;
				}
			}
			this.pixelEncoding = (data[offset++] & 255) + ((data[offset++] & 255) << 8) << 16 >> 16;
			if (moduleCount > 0) {
				this.moduleDataOffsets = new Int16Array(moduleCount);
				pal = 0;
				colorIndex = offset;
				for (color = 0; color < moduleCount; color++) {
					alpha = (data[colorIndex++] & 255) + ((data[colorIndex++] & 255) << 8) << 16 >> 16;
					this.moduleDataOffsets[color] = pal << 16 >> 16;
					colorIndex = colorIndex + alpha | 0;
					pal = pal + alpha | 0;
				}
				this.moduleData = new Int8Array(pal);
				for (color = 0; color < moduleCount; color++) {
					alpha = (data[offset++] & 255) + ((data[offset++] & 255) << 8) << 16 >> 16;
					JSystem.arraycopy(data, offset, this.moduleData, this.moduleDataOffsets[color] & 65535, alpha);
					offset = offset + alpha | 0;
				}
			}
			JSystem.gc();
		} catch (ex) {
			ex = J.exc(ex);
			if (J.isa(ex, "java/lang/Exception")) {
				s0 = ex;
				error = s0;
				error.printStackTrace();
				return;
			}
			else throw ex;
		}
	}

	buildModuleImages(palette, firstModule, lastModule, sourcePalette) {
		let savedPalette = 0, width = 0, hasAlpha = 0, pixelIndex = 0, module = 0, pixelCount = 0, height = 0, pixels = null, sizeIndex = 0;
		if (this.moduleSizes !== null) {
			if (lastModule === -1) {
				lastModule = (this.moduleSizes.length >> 1) - 1 | 0;
			}
			if (this.moduleImages === null) {
				this.moduleImages = J.newArray(this.paletteCount);
			}
			if (this.moduleImages[palette] === null) {
				this.moduleImages[palette] = J.newArray(this.moduleSizes.length >> 1);
			}
			if (sourcePalette < 0) {
				savedPalette = this.paletteIndex;
				this.paletteIndex = palette;
				JSystem.gc();
				module = firstModule;
				while (module <= lastModule) {
					sizeIndex = module << 1;
					width = this.moduleSizes[sizeIndex] & 255;
					height = this.moduleSizes[sizeIndex + 1] & 255;
					if (width > 0) {
						if (height > 0) {
							pixels = this.decodeModulePixels(module);
							if (pixels !== null) {
								hasAlpha = 0;
								pixelCount = Math.imul(width, height);
								pixelIndex = 0;
								while (pixelIndex < pixelCount) {
									if ((pixels[pixelIndex] & -16777216) === -16777216) {
										pixelIndex++;
										continue;
									}
									hasAlpha = 1;
									break;
								}
								this.moduleImages[palette][module] = Image.createRGBImage(pixels, width, height, hasAlpha);
							}
						}
					}
					module++;
				}
				JSystem.gc();
				this.paletteIndex = savedPalette;
			} else {
				for (savedPalette = firstModule; savedPalette <= lastModule; savedPalette++) {
					this.moduleImages[palette][savedPalette] = this.moduleImages[sourcePalette][savedPalette];
				}
			}
			JSystem.gc();
			return;
		}
	}

	freeModuleImages(palette) {
		let module = 0;
		if (this.moduleSizes !== null) {
			if (this.moduleImages !== null) {
				if (this.moduleImages[palette] !== null) {
					for (module = 0; module < this.moduleImages[palette].length; module++) {
						this.moduleImages[palette][module] = null;
					}
					this.moduleImages[palette] = null;
					this.paletteCount = this.paletteCount - 1 | 0;
					return;
				}
				return;
			}
			return;
		}
	}

	toString() {
		let result = null, fullSize = 0, module = 0;
		"";
		result = null;
		fullSize = 0;
		for (module = 0; module < (this.moduleSizes.length / 2 | 0); module++) {
			fullSize = fullSize + Math.imul(2 * (this.moduleSizes[2 * module] & 255) | 0, this.moduleSizes[2 * module + 1] & 255) | 0;
		}
		result = new StringBuffer().append("raw/full: ").append(this.moduleData.length).append("/").append(fullSize).toString();
		return result;
	}

	getFrameDuration(anim, frame) {
		return this.animFrames[(this.animFirstFrame[anim] + frame | 0) * 5 + 1] & 255;
	}

	getAnimFrameCount(anim) {
		return this.animFrameCounts[anim] & 255;
	}

	getFrameModuleCount(frame) {
		return this.frameModuleCounts[frame] & 255;
	}

	measureTextHeight(text) {
		let lineCount = 0, newlinePos = 0, length = 0;
		lineCount = 1;
		length = text.length;
		newlinePos = J.indexOf(text, 10);
		while (newlinePos !== -1) {
			lineCount++;
			newlinePos = newlinePos >= (length - 1 | 0) ? -1 : J.indexOf(text, 10, newlinePos + 1 | 0);
		}
		return Math.imul(this.lineSpacing, lineCount - 1 | 0) + Math.imul(this.moduleSizes[1], lineCount) | 0;
	}

	drawAnimFrame(g, anim, frame, x, y, flags, offsetX, offsetY) {
		let entryOffset = 0, frameId = 0;
		entryOffset = (this.animFirstFrame[anim] + frame | 0) * 5 | 0;
		frameId = this.animFrames[entryOffset] & 255;
		if ((flags & 32) !== 0) {
			offsetX = (flags & 1) === 0 ? offsetX - this.animFrames[entryOffset + 2] | 0 : offsetX + this.animFrames[entryOffset + 2] | 0;
			offsetY = (flags & 2) === 0 ? offsetY - this.animFrames[entryOffset + 3] | 0 : offsetY + this.animFrames[entryOffset + 3] | 0;
		}
		this.drawFrame(g, frameId, x - offsetX | 0, y - offsetY | 0, flags ^ this.animFrames[entryOffset + 4] & 15, offsetX, offsetY);
	}

	drawFrame(g, frame, x, y, flags, offsetX, offsetY) {
		let part = 0, moduleCount = 0;
		moduleCount = this.frameModuleCounts[frame] & 255;
		for (part = 0; part < moduleCount; part++) {
			this.drawFramePart(g, frame, part, x, y, flags);
		}
	}

	drawFramePart(g, frame, part, x, y, flags) {
		let entryOffset = 0, partFlags = 0, module = 0;
		entryOffset = this.frameFirstModule[frame] + part << 2;
		partFlags = this.frameModules[entryOffset + 3] & 255;
		module = this.frameModules[entryOffset] & 255;
		x = (flags & 1) === 0 ? x + this.frameModules[entryOffset + 1] | 0 : x - this.frameModules[entryOffset + 1] | 0;
		y = (flags & 2) === 0 ? y + this.frameModules[entryOffset + 2] | 0 : y - this.frameModules[entryOffset + 2] | 0;
		if ((flags & 1) !== 0) {
			x = x - (this.moduleSizes[module << 1] & 255) | 0;
		}
		if ((flags & 2) !== 0) {
			y = y - (this.moduleSizes[(module << 1) + 1] & 255) | 0;
		}
		this.drawModule(g, module, x, y, flags ^ partFlags & 15);
	}

	drawModule(g, module, x, y, flags) {
		let width = 0, image = null, height = 0, pixels = null, sizeIndex = 0, s0, s1, s2, s3, s4, s5, s6;
		sizeIndex = module << 1;
		width = this.moduleSizes[sizeIndex] & 255;
		height = this.moduleSizes[sizeIndex + 1] & 255;
		if (width <= 0 || height <= 0) {
			return;
		}
		image = null;
		if (this.moduleImages !== null && this.moduleImages[this.paletteIndex] !== null) {
			image = this.moduleImages[this.paletteIndex][module];
		}
		if (image === null) {
			pixels = this.decodeModulePixels(module);
			if (pixels !== null) {
				image = Image.createRGBImage(pixels, width, height, this.hasTransparency);
			} else {
				return;
			}
		}
		width = image.getWidth();
		height = image.getHeight();
		if ((flags & 1) === 0) {
			if ((flags & 2) === 0) {
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
			if ((flags & 2) === 0) {
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
		s0.drawRegion(s1, s2, s3, s4, s5, s6, x, y, 0);
	}

	decodeModulePixels(module) {
		let readPos = 0, width = 0, writePos = 0, runColor = 0, palette = null, color = 0, runLength = 0, data = null, pixelCount = 0, height = 0, sizeIndex = 0, out = null, t3, t5, t6;
		if (this.moduleData === null || this.moduleDataOffsets === null) {
			return null;
		}
		sizeIndex = module << 1;
		width = this.moduleSizes[sizeIndex] & 255;
		height = this.moduleSizes[sizeIndex + 1] & 255;
		out = SpritePack.pixelBuffer;
		palette = this.palettes[this.paletteIndex];
		if (palette !== null) {
			data = this.moduleData;
			readPos = this.moduleDataOffsets[module] & 65535;
			writePos = 0;
			pixelCount = Math.imul(width, height);
			if (this.pixelEncoding !== 10225) {
				if (this.pixelEncoding !== 5632) {
					if (this.pixelEncoding !== 1024) {
						if (this.pixelEncoding !== 512) {
							if (this.pixelEncoding !== 22018) {
								if (this.pixelEncoding === 22258) {
									while (writePos < pixelCount) {
										runLength = data[readPos++] & 255;
										if (runLength <= 127) {
											color = palette[data[readPos++] & 255];
											while (true) {
												t6 = runLength;
												runLength = runLength - 1 | 0;
												if (t6 <= 0) {
													break;
												}
												out[writePos++] = color;
											}
										} else {
											runLength -= 128;
											while (true) {
												t5 = runLength;
												runLength = runLength - 1 | 0;
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
							runLength = runLength - 1 | 0;
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
		return null;
	}

	measureString(text) {
		let charIndex = 0, ch = 0, start = 0, glyphIndex = 0, lineWidth = 0, end = 0, s0, s1, s2, t2;
		SpritePack.textWidth = 0;
		SpritePack.textHeight = this.moduleSizes[1] & 255;
		lineWidth = 0;
		start = SpritePack.textStart < 0 ? 0 : SpritePack.textStart;
		end = SpritePack.textEnd < 0 ? text.length : SpritePack.textEnd;
		for (charIndex = start; charIndex < end; charIndex++) {
			ch = text.charCodeAt(charIndex);
			if (ch <= 32) {
				if (ch !== 32) {
					if (ch !== 10) {
						if (ch !== 1) {
							if (ch === 2) {
								charIndex++;
								s0 = text.charCodeAt(charIndex);
								ch = s0;
								if (ch < this.getFrameModuleCount(0)) {
									glyphIndex = (this.frameModules[ch << 2] & 255) << 1;
									s0 = lineWidth;
									s1 = this.moduleSizes[glyphIndex] & 255;
									s2 = this.frameModules[(ch << 2) + 1];
								} else {
									glyphIndex = ch - this.getFrameModuleCount(0) | 0;
									s0 = lineWidth;
									s1 = this.frameBounds[(glyphIndex << 2) + 2] & 255;
									s2 = this.frameBounds[glyphIndex << 2] & 255;
								}
								t2 = s1 - s2 | 0;
								s1 = t2;
								lineWidth = s0 + (s1 + this.frameModules[1]) | 0;
							}
						} else {
							charIndex++;
						}
					} else {
						if (lineWidth > SpritePack.textWidth) {
							SpritePack.textWidth = lineWidth;
						}
						lineWidth = 0;
						SpritePack.textHeight = SpritePack.textHeight + (this.lineSpacing + (this.moduleSizes[1] & 255)) | 0;
					}
				} else {
					s0 = lineWidth;
					s1 = this.moduleSizes[0] & 255;
					lineWidth = s0 + (s1 + this.frameModules[1]) | 0;
				}
			} else {
				s0 = SpritePack.charMap[ch] & 255;
				ch = s0;
				if (ch < this.getFrameModuleCount(0)) {
					glyphIndex = (this.frameModules[ch << 2] & 255) << 1;
					s0 = lineWidth;
					s1 = this.moduleSizes[glyphIndex] & 255;
					s2 = this.frameModules[(ch << 2) + 1];
				} else {
					glyphIndex = ch - this.getFrameModuleCount(0) | 0;
					s0 = lineWidth;
					s1 = this.frameBounds[(glyphIndex << 2) + 2] & 255;
					s2 = this.frameBounds[glyphIndex << 2] & 255;
				}
				t2 = s1 - s2 | 0;
				s1 = t2;
				lineWidth = s0 + (s1 + this.frameModules[1]) | 0;
			}
		}
		if (lineWidth > SpritePack.textWidth) {
			SpritePack.textWidth = lineWidth;
		}
		if (SpritePack.textWidth > 0) {
			SpritePack.textWidth = SpritePack.textWidth - this.frameModules[1] | 0;
		}
	}

	drawString(g, text, x, y, anchor) {
		let penY = 0, savedPalette = 0, charIndex = 0, ch = 0, start = 0, penX = 0, glyphIndex = 0, end = 0, s0, s1, s2, t2;
		y = y - this.frameModules[2] | 0;
		if ((anchor & 43) !== 0) {
			this.measureString(text);
			if ((anchor & 8) === 0) {
				if ((anchor & 1) !== 0) {
					s0 = x;
					s1 = SpritePack.textWidth >> 1;
					x = s0 - s1 | 0;
				}
			} else {
				s0 = x;
				s1 = SpritePack.textWidth;
				x = s0 - s1 | 0;
			}
			if ((anchor & 32) === 0) {
				if ((anchor & 2) !== 0) {
					s0 = y;
					s1 = SpritePack.textHeight >> 1;
					y = s0 - s1 | 0;
				}
			} else {
				s0 = y;
				s1 = SpritePack.textHeight;
				y = s0 - s1 | 0;
			}
		}
		penX = x;
		penY = y;
		savedPalette = this.paletteIndex;
		start = SpritePack.textStart < 0 ? 0 : SpritePack.textStart;
		end = SpritePack.textEnd < 0 ? text.length : SpritePack.textEnd;
		for (charIndex = start; charIndex < end; charIndex++) {
			ch = text.charCodeAt(charIndex);
			if (ch <= 32) {
				if (ch !== 32) {
					if (ch !== 10) {
						if (ch !== 1) {
							if (ch === 2) {
								charIndex++;
								s0 = text.charCodeAt(charIndex);
								ch = s0;
								if (ch < this.getFrameModuleCount(0)) {
									glyphIndex = (this.frameModules[ch << 2] & 255) << 1;
									this.drawFramePart(g, 0, ch, penX, penY, 0);
									s0 = penX;
									s1 = this.moduleSizes[glyphIndex] & 255;
									s2 = this.frameModules[(ch << 2) + 1];
								} else {
									glyphIndex = ch - this.getFrameModuleCount(0) | 0;
									this.drawFrame(g, glyphIndex, penX, penY, 0, 0, 0);
									s0 = penX;
									s1 = this.frameBounds[(glyphIndex << 2) + 2] & 255;
									s2 = this.frameBounds[glyphIndex << 2] & 255;
								}
								t2 = s1 - s2 | 0;
								s1 = t2;
								penX = s0 + (s1 + this.frameModules[1]) | 0;
							}
						} else {
							charIndex++;
							this.paletteIndex = text.charCodeAt(charIndex);
						}
					} else {
						penX = x;
						penY = penY + (this.lineSpacing + (this.moduleSizes[1] & 255)) | 0;
					}
				} else {
					s0 = penX;
					s1 = this.moduleSizes[0] & 255;
					penX = s0 + (s1 + this.frameModules[1]) | 0;
				}
			} else {
				s0 = SpritePack.charMap[ch] & 255;
				ch = s0;
				if (ch < this.getFrameModuleCount(0)) {
					glyphIndex = (this.frameModules[ch << 2] & 255) << 1;
					this.drawFramePart(g, 0, ch, penX, penY, 0);
					s0 = penX;
					s1 = this.moduleSizes[glyphIndex] & 255;
					s2 = this.frameModules[(ch << 2) + 1];
				} else {
					glyphIndex = ch - this.getFrameModuleCount(0) | 0;
					this.drawFrame(g, glyphIndex, penX, penY, 0, 0, 0);
					s0 = penX;
					s1 = this.frameBounds[(glyphIndex << 2) + 2] & 255;
					s2 = this.frameBounds[glyphIndex << 2] & 255;
				}
				t2 = s1 - s2 | 0;
				s1 = t2;
				penX = s0 + (s1 + this.frameModules[1]) | 0;
			}
		}
		this.paletteIndex = savedPalette;
	}

	drawMultilineString(g, text, x, y, anchor) {
		let lineCount = 0, lineEnds = null, lineHeight = 0, length = 0, line = 0, s0, s1;
		lineCount = 0;
		length = text.length;
		lineEnds = new Int32Array(100);
		for (lineHeight = 0; lineHeight < length; lineHeight++) {
			if (text.charCodeAt(lineHeight) === 10) {
				lineEnds[lineCount++] = lineHeight;
			}
		}
		lineEnds[lineCount++] = length;
		lineHeight = this.lineSpacing + (this.moduleSizes[1] & 255) | 0;
		if ((anchor & 32) === 0) {
			if ((anchor & 2) !== 0) {
				s0 = y;
				s1 = Math.imul(lineHeight, lineCount - 1 | 0) >> 1;
				y = s0 - s1 | 0;
			}
		} else {
			s0 = y;
			s1 = Math.imul(lineHeight, lineCount - 1 | 0);
			y = s0 - s1 | 0;
		}
		for (line = 0; line < lineCount; line++) {
			SpritePack.textStart = line <= 0 ? 0 : lineEnds[line - 1] + 1 | 0;
			SpritePack.textEnd = lineEnds[line];
			this.drawString(g, text, x, y + Math.imul(line, lineHeight) | 0, anchor);
		}
		SpritePack.textStart = -1;
		SpritePack.textEnd = -1;
	}

	unload(freeImages) {
		let i = 0, j = 0;
		this.moduleSizes = null;
		this.frameModuleCounts = null;
		this.frameFirstModule = null;
		this.frameBounds = null;
		this.frameModules = null;
		this.animFrameCounts = null;
		this.animFirstFrame = null;
		this.animFrames = null;
		if (this.cachedPixels !== null) {
			for (i = 0; i < this.cachedPixels.length; i++) {
				this.cachedPixels[i] = null;
			}
			this.cachedPixels = null;
		}
		if (this.palettes !== null) {
			for (i = 0; i < this.palettes.length; i++) {
				this.palettes[i] = null;
			}
			this.palettes = null;
		}
		this.moduleData = null;
		this.moduleDataOffsets = null;
		if (freeImages !== 0 && this.moduleImages !== null) {
			for (i = 0; i < this.moduleImages.length; i++) {
				if (this.moduleImages[i] !== null) {
					for (j = 0; j < this.moduleImages[i].length; j++) {
						this.moduleImages[i][j] = null;
					}
				}
			}
			this.moduleImages = null;
		}
	}

	static clinit() {
		SpritePack.pixelBuffer = new Int32Array(4096);
		SpritePack.textStart = -1;
		SpritePack.textEnd = -1;
	}

}
