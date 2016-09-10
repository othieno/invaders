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
#ifndef DEVICE_TIMER_HH
#define DEVICE_TIMER_HH


namespace device {


#define TIMERFREQ_SYS						0x0000
#define TIMERFREQ_64							0x0001
#define TIMERFREQ_256						0x0002
#define TIMERFREQ_1024						0x0003
#define TIMER_CASCADE						0x0004
#define TIMER_IRQ								0x0040
#define ENABLE_TIMER							0x0080








#ifdef COMMENT
   // Store the address of the interrupt handler.
   //REG_INTERRUPT = (unsigned int) interruptHandler;

   // Initialize TIMER0. Steps to take to calculate the number of ticks:
   // 1. How many microseconds or nanoseconds make one second?
   // 2. Substract this value from 2^16 and voila, your initial value.
   // Suppose we are using a 256 frequency (each clock cycle takes 15.256 microseconds), then this
   // would give (10^6/61.05 = 16380.xyz). Our initial value would then be:
   //REG_TM0D		= 65536 - 16380;
   //REG_TM0CNT	= ENABLE_TIMER | ENABLE_TIMER_IRQ | FREQ_1024;

   // Activate TIMER0 interrupt in REG_IE.
   //REG_IE |= IRQ_TIMER0;
#endif

} // namespace device

#endif // DEVICE_TIMER_HH




