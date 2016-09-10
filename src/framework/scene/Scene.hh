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
#ifndef SCENE_HH
#define SCENE_HH

#include "framework/Error.hh"


namespace framework {
/**
 * @see service/ServiceManager.hh
 */
class ServiceManager;
/**
 * @see input/InputEvent.hh
 */
class InputEvent;
/**
 * @see service/InputService.hh
 */
class InputService;
/**
 * @see service/PhysicsService.hh
 */
class PhysicsService;
/**
 * @see service/AudioService.hh
 */
class AudioService;
/**
 * @see service/GraphicsService.hh
 */
class GraphicsService;
/**
 * @see scene/SceneNode.hh
 */
class SceneNode;
/**
 *
 */
class Scene {
public:
	/**
	 * Initializes the scene.
	 * @param services the services provided by the server.
	 */
	virtual Error build(ServiceManager& serviceManager) = 0;
	/**
	 * Destroys the resources used by the scene.
	 * @param services the services provided by the server.
	 */
	virtual void destroy(ServiceManager& serviceManager) = 0;
	/**
	 * Handles input.
	 */
	virtual void onInput(InputService& input) = 0;
	/**
	 * Handles the specified input event.
	 */
	virtual void onInputEvent(const InputEvent& event) = 0;
	/**
	 * Updates the client's physics state.
	 */
	virtual void onUpdatePhysics(PhysicsService& physics, const float dt) = 0;
	/**
	 * Updates the client's audio state.
	 */
	virtual void onUpdateAudio(AudioService& audio, const float dt) = 0;
	/**
	 * Renders the client's scene.
	 */
	virtual void onRender(GraphicsService& graphics) = 0;
protected:
	/**
	 * The scene's root node.
	 */
	SceneNode* root_;
};

} // namespace framework

#endif // SCENE_HH
