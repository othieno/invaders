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
#ifndef BATTLEFIELD_SCENE_HH
#define BATTLEFIELD_SCENE_HH

#include "GameScene.hh"


/**
 *
 */
class BattlefieldScene final : public GameScene {
public:
	/**
	 * Instantiates a BattlefieldScene object, bound to a specified context.
	 * @param the current game's context.
	 */
	explicit BattlefieldScene(GameContext& gameContext);
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
private:
	/**
	 *
	 */
	void onSuspend();
	/**
	 *
	 */
	void onResume();
};

#endif // BATTLEFIELD_SCENE_HH










#ifdef PROTOTYPE
#ifdef __VERY_DEPRECATED

namespace invaders {
namespace logic {

#ifdef COMMENT

extern const s8 rawAudioLaser[];
extern const s8 rawAudioExplosion[];

/**
 * The space invaders game class.
 */
class SpaceInvaders
{
public:
	 /**
		* The laser sound.
		*/
	 static const Audio _audioLaser;
	 /**
		* The explosion sound.
		*/
	 static const Audio _audioExplosion;
};
}



#define MAX_INVADERS							55		/* Make 56 when adding bonus. */
#define MAX_LEVELS							5
#define DIMENSION								16
#define GAP										2
#define MAX_ROWS								5
#define MAX_COLUMNS							11
#define FLEET_WIDTH							196	/* 16*11+(2*10) */
#define FLEET_HEIGHT							60		/* 8*5+(4*5) */
#define SPRITE_WIDTH_PLAYER				16
#define SPRITE_WIDTH_INVADER				16
#define SPRITE_HEIGHT						8
#define SPACING								(DIMENSION + GAP)
#define INITIAL_X								22
#define INITIAL_Y								38
#define MIN_TIMER_INIT_VALUE				47152
#define MAX_TIMER_INIT_VALUE				62535	/* Because anything after may be inhumane for some... */
#define TIMER_INCREMENT_VALUE				((MAX_TIMER_INIT_VALUE - MIN_TIMER_INIT_VALUE) / (MAX_LEVELS * 3))


/*
	 The object (sprite) type is used to handle sprite manipulation with relative ease.
*/
typedef struct Object
{
	 int x, y, shape, size, frame[3], isExploding;
	 bool isVisible;
} obj_t;

typedef struct InvaderFleet {
	 int x, y, nInvaders, offLeft, offRight, offBottom;
	 obj_t invaders[MAX_ROWS][MAX_COLUMNS];
} fleet_t;

/*
	 Global variables.
*/
extern signed char sound_buffer[];
#endif
#endif // __VERY_DEPRECATED


#endif
