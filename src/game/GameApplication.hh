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
#ifndef GAME_APPLICATION_HH
#define GAME_APPLICATION_HH

#include "framework/Application.hh"
#include "GameContext.hh"
#include "GameScene.hh"
#include <unordered_map>
#include <memory>


/**
 * MARS ATTACKS, OR IS IT JUPITER?!
 */
class GameApplication final : public framework::Application {
public:
	GameApplication(const GameApplication&) = delete;
	GameApplication(const GameApplication&&) = delete;

	GameApplication& operator=(const GameApplication&) = delete;
	GameApplication& operator=(const GameApplication&&) = delete;

	/**
	 * Instantiates a GameApplication object.
	 */
	explicit GameApplication(framework::ServiceManager&);
	/**
	 * Disposes of the application's resources.
	 */
	~GameApplication();
	/**
	 * @see framework::Application::initialize.
	 */
	framework::Error initialize() override;
	/**
	 * @see framework::Application::beforeExit.
	 */
	void beforeExit() override;
	/**
	 * @see framework::Application::reset.
	 */
	void reset() override;
	/**
	 * @see framework::Application::update.
	 */
	void update(const float) override;
private:
	/**
	 * Creates an instance of the scene with the specified identifier.
	 * @param identifier the scene's unique identifier.
	 */
	GameScene* createScene(const GameSceneIdentifier identifier);
	/**
	 * Sets the client's scene.
	 * @param identifier the new scene's unique identifier.
	 */
	framework::Error setScene(const GameSceneIdentifier identifier);
	/**
	 * The game's current context.
	 */
	GameContext context_;
	/**
	 * The client's available scenes.
	 */
	//TODO Use a space-efficient data structure to store the scenes.
	std::unordered_map<std::underlying_type<GameSceneIdentifier>::type, std::unique_ptr<GameScene>> scenes_;
};

#endif // GAME_APPLICATION_HH
