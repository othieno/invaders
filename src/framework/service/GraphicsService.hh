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
#ifndef GRAPHICS_SERVICE_HH
#define GRAPHICS_SERVICE_HH

#include "Service.hh"


namespace framework {
/**
 *
 */
class Scene;
/**
 *
 */
class GraphicsService : public Service {
	friend class ServiceManager;
public:
	GraphicsService(const GraphicsService&) = delete;
	GraphicsService(const GraphicsService&&) = delete;

	GraphicsService& operator=(const GraphicsService&) = delete;
	GraphicsService& operator=(const GraphicsService&&) = delete;

	Error initialize() override;
	/**
	 * Returns the clear color.
	 */
	std::uint16_t getClearColor() const;
	/**
	 * Sets the color used when clearing the display.
	 * @param color a 16-bit BGR color.
	 */
	void setClearColor(const std::uint16_t color);
	/**
	 * Clears the display.
	 */
	void clear();
	/**
	 * Renders the specified scene.
	 * @param scene a scene to render.
	 */
	void render(const Scene& scene);
	/**
	 * Prints the specified string.
	 * @param s the string to print.
	 */
	//void print(const std::string& s);
	/**
	 *
	 */
	void vsyncWait();


void enableHardwareRenderedSprites();
void enableLinearSpriteMapping();


private:
	/**
	 *
	 */
	GraphicsService();
	/**
	 *
	 */
	virtual ~GraphicsService();
	/**
	 * The color used when clearing the display.
	 */
	std::uint16_t clearColor_;
};

} // namespace framework

#endif // GRAPHICS_SERVICE_HH
