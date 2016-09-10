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
#include "GraphicsService.hh"
#include "device/display.hh"

using framework::GraphicsService;
using framework::Scene;


GraphicsService::GraphicsService() :
Service(Service::Identifier::Graphics),
clearColor_(0x0000) {}


GraphicsService::~GraphicsService() {}


framework::Error
GraphicsService::initialize() {
	return Error::None;
}


std::uint16_t
GraphicsService::getClearColor() const {
	return clearColor_;
}


void
GraphicsService::setClearColor(const std::uint16_t color) {
	clearColor_ = color;
}


void
GraphicsService::clear() {
	device::clearPixelBuffer(clearColor_);
}


void
GraphicsService::render(const Scene& scene) {
}


/*
void
GraphicsService::print() {}
*/

void
GraphicsService::vsyncWait() {
	//system::display::vsyncWait(); // Breaks interrupts for some reason...
}








#ifdef TO_IMPLEMENT

int
GraphicsSubsystem::initialize()
{
	platform::SpriteObjectManager::initialize();
	return 0;
}


void
GraphicsSubsystem::setVideoMode(const VideoMode& mode)
{
	REG_DISPCNT = (REG_DISPCNT & 0xfff8) | static_cast<u16>(mode);
}


void
GraphicsSubsystem::setBackgroundMode(const BackgroundMode& mode)
{
	//FIXME
	bool isValidBackgroundMode = false;
/*
	const auto& videoMode = videoMode();
	bool isValidBackgroundMode =
	(videoMode == VideoMode::B && mode != BackgroundMode::D) ||
	(videoMode == VideoMode::C && mode != BackgroundMode::A && mode != BackgroundMode::B);

	if (isValidBackgroundMode)
	{

	}
*/

	if (isValidBackgroundMode)
		REG_DISPCNT = (REG_DISPCNT & 0xf0ff) | static_cast<u16>(mode);
}


void
GraphicsSubsystem::enableHardwareRenderedSprites(const bool enable)
{
	REG_DISPCNT = (REG_DISPCNT & 0xefff) | (enable ? 0x1000 : 0);
}


void
GraphicsSubsystem::enableLinearSpriteMapping(const bool enable)
{
	REG_DISPCNT = (REG_DISPCNT & 0xffbf) | (enable ? 0x0040 : 0);
}


void
GraphicsSubsystem::clear(const u16 color)
{
	// Clearing the screen is different depending on the selected video modes.
	// Remember modes 0, 1 and 2 are tile modes while 3, 4 and 5 are bitmap modes.
	// Modes 3, 4 and 5 are bitmap modes, and clearing VRAM is
	const auto& isBitmapMode = false;//FIXME static_cast<u16>(videoMode()) > 2;
	if (isBitmapMode)
	{
		if (color == 0 || color == 0xffff)
			memset(_vram.buffer, color, _vram.size * sizeof(u16));
		else
		{
			for (auto* p = _vram.buffer; p < _vram.buffer + _vram.size; ++p)
				*p = color;
		}
	}
}



void
GraphicsSubsystem::swapBuffers()
{
	vsyncWait();
	platform::SpriteObjectManager::uploadLocalOamBuffer();
}
#endif // TO_IMPLEMENT
