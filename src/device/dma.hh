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
#ifndef DEVICE_DMA_HH
#define DEVICE_DMA_HH


namespace device {


/**
 * DMA.
 */
//#define DMA_ENABLE				0x80000000
#define DMA_ENABLE				(1 << 2)
#define DMA_WORD					0x04000000
#define DMA_HALFWORD				0x00000000
#define START_ON_FIFO_EMPTY	0x30000000
#define DMA_REPEAT				0x02000000
#define DEST_REG_SAME			0x00400000
#define DMA_CHANNEL_0			0x0
#define DMA_CHANNEL_1			0x1
#define DMA_CHANNEL_2			0x2
#define DMA_CHANNEL_3			0x3
#define DMA_CHANNEL_DEFAULT	0x3

} // namespace device

#endif // DEVICE_DMA_HH
