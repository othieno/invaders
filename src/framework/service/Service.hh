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
#ifndef SERVICE_HH
#define SERVICE_HH

#include <cstdint>
#include "Error.hh"


namespace framework {
/**
 * @see service/AudioService.
 */
class AudioService;
/**
 * @see service/GraphicsService.
 */
class GraphicsService;
/**
 * @see service/InputService.
 */
class InputService;
/**
 * @see service/PhysicsService.
 */
class PhysicsService;
/**
 *
 */
class Service
{
public:
	Service(const Service&) = delete;
	Service(const Service&&) = delete;

	Service& operator=(const Service&) = delete;
	Service& operator=(const Service&&) = delete;

	/**
	 * An enumeration of available services.
	 */
	enum class Identifier {
		Audio,
		Graphics,
		Input,
		Physics,
	};
	/**
	 * Returns the service's unique identifier.
	 */
	Identifier getServiceIdentifier() const;
	/**
	 * Initializes the service.
	 */
	virtual Error initialize() = 0;
protected:
	/**
	 *
	 */
	explicit Service(const Identifier);
	/**
	 *
	 */
	virtual ~Service();
private:
	/**
	 * The service's unique identifier.
	 */
	const Identifier identifier_;
};

} // namespace framework

#endif // SERVICE_HH
