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
#include "ServiceManager.hh"
#include "AudioService.hh"
#include "GraphicsService.hh"
#include "InputService.hh"
#include "PhysicsService.hh"

using framework::ServiceManager;


framework::AudioService&
ServiceManager::getAudioService()
{
	static AudioService INSTANCE;
	return INSTANCE;
}


framework::GraphicsService&
ServiceManager::getGraphicsService()
{
	static GraphicsService INSTANCE;
	return INSTANCE;
}


framework::InputService&
ServiceManager::getInputService()
{
	static InputService INSTANCE;
	return INSTANCE;
}


framework::PhysicsService&
ServiceManager::getPhysicsService()
{
	static PhysicsService INSTANCE;
	return INSTANCE;
}


void
ServiceManager::updateServices() {
	getInputService().pollKeypad();
}
