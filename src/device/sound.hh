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
#ifndef DEVICE_SOUND_HH
#define DEVICE_SOUND_HH


namespace device {

/**
 * Sound.
 */
#define SND_ENABLED				0x00000080
#define SND_OUTPUT_RATIO_25	0x0000
#define SND_OUTPUT_RATIO_50	0x0001
#define SND_OUTPUT_RATIO_100	0x0002
#define DSA_OUTPUT_RATIO_50	0x0000
#define DSA_OUTPUT_RATIO_100	0x0004
#define DSA_OUTPUT_TO_RIGHT	0x0100
#define DSA_OUTPUT_TO_LEFT		0x0200
#define DSA_OUTPUT_TO_BOTH		0x0300
#define DSA_TIMER0				0x0000
#define DSA_TIMER1				0x0400
#define DSA_FIFO_RESET			0x0800
#define DSB_OUTPUT_RATIO_50	0x0000
#define DSB_OUTPUT_RATIO_100	0x0008
#define DSB_OUTPUT_TO_RIGHT	0x1000
#define DSB_OUTPUT_TO_LEFT		0x2000
#define DSB_OUTPUT_TO_BOTH		0x3000
#define DSB_TIMER0				0x0000
#define DSB_TIMER1				0x4000
#define DSB_FIFO_RESET			0x8000
#define FREQUENCY					22050
#define TIMER_INTERVAL			0xfd07    // (65536-(round((2^24)/FREQUENCY)))
#define SAMPLES_PER_VBLANK		0x0170    // (FREQUENCY/60)


} // namespace device

#endif // DEVICE_SOUND_HH
