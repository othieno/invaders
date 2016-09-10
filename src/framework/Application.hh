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
#ifndef APPLICATION_HH
#define APPLICATION_HH

#include "Error.hh"
#include <string>


namespace framework {
/**
 * @see scene/Scene.hh
 */
class Scene;
/**
 * @see ServiceManager.hh
 */
class ServiceManager;
/**
 *
 */
class Application {
public:
	Application(const Application&) = delete;
	Application(const Application&&) = delete;

	Application& operator=(const Application&) = delete;
	Application& operator=(const Application&&) = delete;

	/**
	 * An enumeration of possible application states.
	 */
	enum class State {
		New,
		Running,
		Exiting,
		Terminated
	};
	/**
	 * Returns the application's name.
	 */
	const std::string& getName() const;
	/**
	 * Returns the application's current state.
	 */
	State getState() const;
	/**
	 * Sets the application's state.
	 * @param state the application state to set.
	 */
	void setState(const State state);
	/**
	 * Initializes the application.
	 */
	virtual Error initialize() = 0;
	/**
	 * A handler that is called before the server exits.
	 */
	virtual void beforeExit();
	/**
	 * Resets the application.
	 */
	virtual void reset() = 0;
	/**
	 * Updates the application.
	 */
	virtual void update(const float dt) = 0;
protected:
	/**
	 * Instantiates an Application object with the specified name, that is attached
	 * to a given ApplicationController instance.
	 * @param name the application's name.
	 * @param serviceManager the framework's service manager.
	 */
	Application(const std::string& name, ServiceManager& serviceManager);
	/**
	 * Disposes of the application's resources.
	 */
	virtual ~Application();
	/**
	 * Returns the application's current scene.
	 */
	Scene* getScene();
	/**
	 * Sets the application's scene.
	 * @param scene the application's new scene.
	 */
	void setScene(Scene& scene);
	/**
	 * Sets the application's scene to null.
	 */
	void setScene(std::nullptr_t);
	/**
	 * The framework's service manager which, among other responsibilities,
	 * provides services to the application.
	 */
	ServiceManager& serviceManager_;
private:
	/**
	 * Frees up the resources used by the current scene, if one is set.
	 */
	void destroyScene();
	/**
	 * The application's name.
	 */
	const std::string name_;
	/**
	 * The application's current state.
	 */
	State state_;
	/**
	 * The application's current scene.
	 */
	Scene* scene_;
};
} // namespace framework

#endif // APPLICATION_HH
