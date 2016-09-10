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
#ifndef GAME_CONTEXT_HH
#define GAME_CONTEXT_HH

#include "scene/GameSceneIdentifier.hh"
#include <cstdint>


/**
 * The game's context, shared between all its scenes.
 */
struct GameContext {
	/**
	 * Instantiates a GameContext object.
	 */
	GameContext();
	/**
	 * The game's current scene.
	 */
	GameSceneIdentifier scene;
	/**
	 * The current score.
	 */
	std::uint32_t score;
	/**
	 * The best score in the current session.
	 */
	std::uint32_t topScore;
	/**
	 * The highest possible score.
	 */
	static constexpr std::uint32_t MAX_SCORE = 999999;
	/**
	 * The player's current level.
	 */
	std::uint32_t level;
	/**
	 * The number of lives remaining.
	 */
	std::uint32_t livesRemaining;
	/**
	 * The maximum number of lives remaining.
	 */
	static constexpr std::uint32_t MAX_LIVES_REMAINING = 99;
};

#endif // GAME_CONTEXT_HH
