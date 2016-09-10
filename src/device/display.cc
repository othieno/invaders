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
#include "device/display.hh"
#include "device/register.hh"


void
device::vsyncWait() {
	while (REG_VCOUNT >= DISPLAY_HEIGHT); // Wait till VDraw.
	while (REG_VCOUNT  < DISPLAY_HEIGHT); // Wait till VBlank.
}


constexpr std::uint16_t*
device::getPixelBuffer() {
	return (std::uint16_t*)0x06000000;
}


void
device::clearPixelBuffer(const std::uint16_t value) {
	constexpr auto size = DISPLAY_WIDTH * DISPLAY_HEIGHT;
	auto* const buffer = getPixelBuffer();
	for (std::size_t i = 0; i < size; ++i) {
		buffer[i] = value;
	}
}


std::uint16_t
device::getPixel(const std::size_t x, const std::size_t y) {
	//return (x < _vram.width && y < _vram.height) ? *(_vram.buffer + x + (y * _vram.width)) : 0;
	return 0;
}


void
device::setPixel(const std::size_t x, const std::size_t y, const std::uint16_t value) {
/*
   if (x < _vram.width && y < _vram.height)
      *(_vram.buffer + x + (y * _vram.width)) = color;
*/
}
