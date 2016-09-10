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
#ifndef APPLICATION_CONTROLLER_HH
#define APPLICATION_CONTROLLER_HH

#include "Error.hh"
#include "ServiceManager.hh"
#include "Application.hh"
#include "device/interrupt.hh"


namespace framework {
/**
 *
 */
template<class Application>
class ApplicationController {
public:
	ApplicationController(const ApplicationController&) = delete;
	ApplicationController(const ApplicationController&&) = delete;

	ApplicationController& operator=(const ApplicationController&) = delete;
	ApplicationController& operator=(const ApplicationController&&) = delete;

	/**
	 * Instantiates an ApplicationController object.
	 */
	ApplicationController();
	/**
	 * Destroys the ApplicationController object.
	 */
	~ApplicationController();
	/**
	 * Runs the application.
	 */
	Error runApplication(int& argc, char** argv);
private:
	/**
	 * Initializes the application controller.
	 */
	Error initialize(int& argc, char** argv);
	/**
	 * The framework's services.
	 */
	ServiceManager serviceManager_;
	/**
	 * The application instance.
	 */
	Application application_;
};


template<class Application>
ApplicationController<Application>::ApplicationController() :
application_(serviceManager_) {}


template<class Application>
ApplicationController<Application>::~ApplicationController() {}


template<class Application> Error
ApplicationController<Application>::initialize(int& argc, char** argv) {




	device::initializeHardwareInterrupts();

	return Error::None;
}


template<class Application> Error
ApplicationController<Application>::runApplication(int& argc, char** argv) {
	auto error = initialize(argc, argv);
	if (error == Error::None) {
		error = application_.initialize();
		if (error == Error::None) {
			using ApplicationState = framework::Application::State;

			application_.setState(ApplicationState::Running);
			do {
				serviceManager_.updateServices();
				constexpr float dt = 0.33f; // TODO Calculate this.
				application_.update(dt);
			} while (application_.getState() == ApplicationState::Running);

			application_.setState(ApplicationState::Exiting);
			application_.beforeExit();
			application_.setState(ApplicationState::Terminated);
		}
	}
	return error;
}
} // namespace framework

#endif // APPLICATION_CONTROLLER_HH
