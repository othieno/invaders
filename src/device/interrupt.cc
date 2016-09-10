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
#include "device/interrupt.hh"
#include <gba_interrupt.h>


std::underlying_type<device::Interrupt>::type
device::getInterruptCode(const device::Interrupt interrupt) {
	return static_cast<std::underlying_type<device::Interrupt>::type>(interrupt);
}


void
device::initializeHardwareInterrupts() {
	irqInit();
}


void
device::enableInterrupt(const Interrupt interrupt, void (*handler)()) {
	const auto interruptCode = static_cast<irqMASK>(interrupt);
	irqEnable(interruptCode);
	if (handler != nullptr) {
		irqSet(interruptCode, handler);
	}
}


void
device::setInterruptHandler(const Interrupt interrupt, void (*handler)()) {
	if (handler != nullptr) {
		irqSet(static_cast<irqMASK>(interrupt), handler);
	}
}
