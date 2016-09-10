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
#ifndef INPUT_SERVICE_HH
#define INPUT_SERVICE_HH

#include "Service.hh"
#include "device/keypad.hh"
#include <initializer_list>


namespace framework {
/**
 * @see device/keypad.hh.
 */
using device::Key;
/**
 *
 */
class InputService : public Service {
	friend class ServiceManager;
public:
	InputService(const InputService&) = delete;
	InputService(const InputService&&) = delete;

	InputService& operator=(const InputService&) = delete;
	InputService& operator=(const InputService&&) = delete;

	/**
	 * @see Service::initialize.
	 */
	Error initialize() override;
	/**
	 * Returns true if the specified key is being pressed in the given keypad state, false otherwise.
	 * @param key the key to query.
	 */
	bool isKeyPressed(const Key key) const;
private:
	/**
	 *
	 */
	InputService();
	/**
	 *
	 */
	virtual ~InputService();
	/**
	 * Acquires the keypad's current state.
	 */
	void pollKeypad();
};
} // namespace framework

#endif // INPUT_SERVICE_HH
