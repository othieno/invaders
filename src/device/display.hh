/*
 * This file is part of the Space Invaders clone project.
 * https://github.com/othieno/invaders
 *
 * Copyright (c) 2016 Jeremy Othieno.
 *
 * The MIT License (MIT)
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef DEVICE_DISPLAY_HH
#define DEVICE_DISPLAY_HH

#include <cstdint>


namespace device {
/**
 * Return the GBA display's width.
 */
constexpr std::size_t DISPLAY_WIDTH = 240;
/**
 * Returns the GBA display's height.
 */
constexpr std::size_t DISPLAY_HEIGHT = 160;
/**
 * The available video modes.
 */
enum class VideoMode : std::uint16_t {
	A = 0x0000, // Tiled video mode 0
	B = 0x0001, // Tiled video mode 1
	C = 0x0002, // Tiled video mode 2
	D = 0x0003, // Bitmap video mode 3
	E = 0x0004, // Bitmap video mode 4
	F = 0x0005  // Bitmap video mode 5
};
/**
 * The available background modes.
 */
enum class BackgroundMode : std::uint16_t {
	A = 0x0100, // Background 0
	B = 0x0200, // Background 1
	C = 0x0400, // Background 2
	D = 0x0800  // Background 3
};
/**
 * Returns a pointer to the device's VRAM.
 */
extern constexpr std::uint16_t* getPixelBuffer();
/**
 * Clears (fills) the VRAM with a specified pixel 16-bit BGR value.
 * @param value the pixel value that the buffer will be filled with.
 */
void clearPixelBuffer(std::uint16_t value = 0x0000);
/**
 * Returns the pixel value at the VRAM's specified <x, y> location.
 * @param x the VRAM element's column.
 * @param y the VRAM element's row.
 */
std::uint16_t getPixel(const std::size_t x, const std::size_t y);
/**
 * Writes a value to the VRAM at the specified <x, y> location.
 * @param x the VRAM element's column.
 * @param y the VRAM element's row.
 * @param value the value to write to the VRAM.
 */
void setPixel(const std::size_t x, const std::size_t y, const std::uint16_t value);
/**
 * Blocks until the vertical synchronisation is complete.
 */
void vsyncWait();





#ifdef TO_IMPLEMENT
/**
 * Swap front and back buffers.
 */
void swapBuffers();


VideoMode getVideoMode();
/**
 * Sets the display's video mode.
 */
void setVideoMode(const VideoMode mode);
/**
 * Sets the display's background mode.
 */
void setBackgroundMode(const BackgroundMode mode);

//VideoMode videoMode();
void setVideoMode(const VideoMode& videoMode);

//BackgroundMode backgroundMode();
void setBackgroundMode(const BackgroundMode& backgroundMode);

//bool hasHardwareRenderedSprites();
void enableHardwareRenderedSprites(const bool enable = true);

//bool isLinearSpriteMappingEnabled();
void enableLinearSpriteMapping(const bool enable = true);

void forceScreenBlank();

void printf(const u32 x, const u32 y, const char* const format, ...);

#endif

} // namespace device

#endif // DEVICE_DISPLAY_HH
