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
#ifndef DEVICE_INTERRUPT_HH
#define DEVICE_INTERRUPT_HH

#include <cstdint>
#include <type_traits>


namespace device {
/**
 * The device's interrupts.
 */
enum class Interrupt : std::uint16_t {
	VBLANK = 0x0001,
	HBLANK = (1 << 1),
	VCOUNT = (1 << 2),
	TIMER0 = (1 << 3),
	TIMER1 = (1 << 4),
	TIMER2 = (1 << 5),
	TIMER3 = (1 << 6),
	SERIAL_COMM = (1 << 7),
	DMA0 = (1 << 8),
	DMA1 = (1 << 9),
	DMA2 = (1 << 10),
	DMA3 = (1 << 11),
	KEYPAD = (1 << 12),
	CARTRIDGE = (1 << 13),
};
/**
 * Returns the specified interrupt's integer representation.
 * @param interrupt the interrupt to query.
 */
std::underlying_type<Interrupt>::type getInterruptCode(const Interrupt interrupt);
/**
 * Initializes hardware interrupts.
 */
void initializeHardwareInterrupts();


//void setInterruptHandlerX(const Interrupt interrupt, std::function<void(void)> handler);















/**
 * Enables the specified interrupt.
 * @param interrupt the interrupt to enable.
 * @param handler a function that is called each time the interrupt is raised.
 */
void enableInterrupt(const Interrupt interrupt, void (*handler)() = nullptr);
/**
 * Sets the interrupt handler for a given interrupt.
 */
void setInterruptHandler(const Interrupt interrupt, void (*handler)());
} // namespace device

#endif // DEVICE_INTERRUPT_HH
