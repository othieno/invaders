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
#include "GameApplication.hh"
#include "scene/MenuScene.hh"
#include "scene/BattlefieldScene.hh"
#include "framework/service/ServiceManager.hh"
#include "framework/service/AudioService.hh"
#include "framework/service/GraphicsService.hh"
#include "framework/service/InputService.hh"
#include "framework/service/PhysicsService.hh"

using framework::Error;
using framework::ServiceManager;


GameApplication::GameApplication(ServiceManager& serviceManager) :
Application("Space Invaders", serviceManager) {}


GameApplication::~GameApplication() {}


Error
GameApplication::initialize() {
	reset();
	return setScene(context_.scene);
}


void
GameApplication::beforeExit() {
	reset();
}


void
GameApplication::reset() {
	context_.scene = GameSceneIdentifier::Menu;
	context_.topScore = std::max(context_.topScore, context_.score);
	context_.score = 0;
	context_.level = 0;
	context_.livesRemaining = 0;
}


void
GameApplication::update(float dt) {
	static auto& audio = serviceManager_.getAudioService();
	static auto& graphics = serviceManager_.getGraphicsService();
	static auto& input = serviceManager_.getInputService();
	static auto& physics = serviceManager_.getPhysicsService();

	auto* scene = Application::getScene();
	if (scene != nullptr) {
		// Was the scene changed in the game context? If so, update the scene instance.
		auto& gameScene = static_cast<GameScene&>(*scene);
		if (gameScene.getIdentifier() != context_.scene) {
			scene = setScene(context_.scene) == Error::None ? Application::getScene() : nullptr;
			if (scene == nullptr) {
				return;
			}
		}
		scene->onInput(input);
		scene->onUpdatePhysics(physics, dt);
		scene->onUpdateAudio(audio, dt);
		scene->onRender(graphics);
	}
}


GameScene*
GameApplication::createScene(const GameSceneIdentifier identifier) {
	GameScene* scene = nullptr;

	if (identifier != GameSceneIdentifier::None) {
		using Key = std::underlying_type<GameSceneIdentifier>::type;
		using Value = std::unique_ptr<GameScene>;

		const Key key = static_cast<Key>(identifier);
		Value& value = scenes_[key]; // Note: This will create a new Value object in the map if one can't be found.

		scene = value.get();
		if (scene == nullptr) {
			switch (identifier) {
				case GameSceneIdentifier::Menu:
					scene = new MenuScene(context_);
					break;
				case GameSceneIdentifier::Battlefield:
					scene = new BattlefieldScene(context_);
					break;
				case GameSceneIdentifier::GameOver:
					//scene = new GameOverScene(context_);
					break;
				default:
					break;
			}
			value.reset(scene);
		}
	}
	return scene;
}


Error
GameApplication::setScene(const GameSceneIdentifier identifier) {
	auto error = Error::None;
	auto* const scene = createScene(identifier);
	if (scene != nullptr) {
		Application::setScene(*scene);
	} else {
		Application::setScene(nullptr);
	}
	return error;
}
