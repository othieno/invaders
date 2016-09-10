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
#include "BattlefieldScene.hh"
#include "GameContext.hh"
#include "framework/service/ServiceManager.hh"
#include "framework/service/GraphicsService.hh"
#include "framework/service/InputService.hh"

using framework::Error;
using framework::ServiceManager;
using framework::InputService;
using framework::GraphicsService;
using framework::Key;

BattlefieldScene::BattlefieldScene(GameContext& gameContext) :
GameScene(GameSceneIdentifier::Battlefield, gameContext) {}


#include "device/register.hh" //TODO Remove this when REG_DISPCNT is no longer directly accessed.
Error
BattlefieldScene::build(ServiceManager& serviceManager) {
	auto& graphics = serviceManager.getGraphicsService();
	graphics.setClearColor(0x001f);


	device::REG_DISPCNT = 0x0403;
/*
	((unsigned short*)0x06000000)[120+80*240] = 0x001F;
	((unsigned short*)0x06000000)[136+80*240] = 0x03E0;
	((unsigned short*)0x06000000)[120+96*240] = 0x7C00;
*/

	return Error::None;
}


void
BattlefieldScene::destroy(ServiceManager& serviceManager) {
	auto& graphics = serviceManager.getGraphicsService();
	graphics.setClearColor(0x0000);
}


void
BattlefieldScene::onInput(InputService& input)
{
	// Go back to the main menu, for now.
	if (input.isKeyPressed(Key::START)) {
		gameContext_.scene = GameSceneIdentifier::Menu;
	}
}


void
BattlefieldScene::onRender(GraphicsService& graphics) {
	graphics.clear();
	graphics.render(*this);
}
