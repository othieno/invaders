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
#ifndef DEVICE_KEYPAD_HH
#define DEVICE_KEYPAD_HH

#include <cstdint>
#include <type_traits>


namespace device {
/**
 * The device's available keys, each assigned to their respective keycode.
 */
enum class Key : std::uint16_t {
	A = 0x0001,
	B = 0x0002,
	SELECT = 0x0004,
	START = 0x0008,
	RIGHT = 0x0010,
	LEFT = 0x0020,
	UP = 0x0040,
	DOWN = 0x0080,
	R = 0x0100,
	L = 0x0200
};
/**
 * Returns the specified key's integer representation.
 * @param key the key to query.
 */
std::underlying_type<Key>::type getKeyCode(const Key key);
/**
 * Returns the state of all keys on the keypad.
 */
std::uint16_t getKeypadState();



/**
 * Returns true if the specified key is being pressed, false otherwise.
 * @param key the key to query.
 */
//TODO Use bitmask operator.
//@see http://blog.bitwigglers.org/using-enum-classes-as-type-safe-bitmasks/
bool isKeyPressed(const Key key);
} // namespace device

#endif // DEVICE_KEYPAD_HH
