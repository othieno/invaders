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
#include "Application.hh"
#include "Scene.hh"

using framework::Application;
using framework::Scene;
using framework::Error;


Application::Application(const std::string& name, ServiceManager& serviceManager) :
serviceManager_(serviceManager),
name_(name),
state_(State::New),
scene_(nullptr) {}


Application::~Application() {
	destroyScene();
}


const std::string&
Application::getName() const {
	return name_;
}


Application::State
Application::getState() const {
	return state_;
}


void
Application::setState(const Application::State state) {
	state_ = state;
}


void
Application::beforeExit() {}


Scene*
Application::getScene() {
	return scene_;
}


void
Application::setScene(Scene& newScene) {
	// If a previous scene exists, clean up its resources before initializing a new one.
	destroyScene();

	auto error = newScene.build(serviceManager_);
	if (error == Error::None) {
		scene_ = &newScene;
	} else {
		newScene.destroy(serviceManager_);
	}
}


void
Application::setScene(std::nullptr_t) {
	destroyScene();
}


void
Application::destroyScene() {
	if (scene_ != nullptr) {
		scene_->destroy(serviceManager_);
		scene_ = nullptr;
	}
}
