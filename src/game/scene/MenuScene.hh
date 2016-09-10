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
#ifndef MENU_SCENE_HH
#define MENU_SCENE_HH

#include "GameScene.hh"


/**
 *
 */
class MenuScene final : public GameScene {
public:
	/**
	 * Instantiates a MenuScene object, bound to a specified context.
	 * @param the current game's context.
	 */
	explicit MenuScene(GameContext& gameContext);
	/**
	 * @see framework::Scene::build.
	 */
	framework::Error build(framework::ServiceManager&) override;
	/**
	 * @see framework::Scene::destroy.
	 */
	void destroy(framework::ServiceManager&) override;
	/**
	 * @see framework::Scene::onInput.
	 */
	void onInput(framework::InputService&) override;
	/**
	 * @see framework::Scene::onRender.
	 */
	void onRender(framework::GraphicsService&) override;
};

#endif // MENU_SCENE_HH
