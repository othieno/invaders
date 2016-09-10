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
#ifndef DEVICE_REGISTER_HH
#define DEVICE_REGISTER_HH

#include <cstdint>


namespace device {
static constexpr std::uint32_t&          REG_DISPCNT = *(std::uint32_t*)0x04000000;
static constexpr std::uint32_t&          REG_DISPSTAT = *(std::uint32_t*)0x04000004;
static constexpr volatile std::uint16_t& REG_KEYINPUT = *(volatile std::uint16_t*)0x04000130;
static constexpr volatile std::uint32_t& REG_VCOUNT = *(volatile std::uint32_t*)0x04000006;
} // namespace device


#define X_REG_IE                (*(std::uint16_t*)0x04000200)
#define X_REG_IF                (*(volatile std::uint16_t*)0x04000202)
#define X_REG_IME               (*(volatile std::uint16_t*)0x04000208)
#define X_REG_INTERRUPT         (*(std::uint16_t*)0x3007ffc)

#define X_REG_TM0D              (*(volatile std::uint16_t*)0x04000100)
#define X_REG_TM0CNT            (*(volatile std::uint16_t*)0x04000102)
#define X_REG_TM1D              (*(volatile std::uint16_t*)0x04000104)
#define X_REG_TM1CNT            (*(volatile std::uint16_t*)0x04000106)
#define X_REG_TM2D              (*(volatile std::uint16_t*)0x04000108)
#define X_REG_TM2CNT            (*(volatile std::uint16_t*)0x0400010a)
#define X_REG_TM3D              (*(volatile std::uint16_t*)0x0400010c)
#define X_REG_TM3CNT            (*(volatile std::uint16_t*)0x0400010e)
//#define X_REG_KEYINPUT          (*(volatile std::uint16_t*)0x04000130)
#define X_REG_KEYCNT	        (*(volatile std::uint16_t*)0x04000132)
#define X_REG_DMA0SAD           (*(std::uint32_t*)0x040000b0)
#define X_REG_DMA0DAD           (*(std::uint32_t*)0x040000b4)
#define X_REG_DMA0CNT           (*(std::uint32_t*)0x040000b8)
#define X_REG_DMA1SAD           (*(std::uint32_t*)0x040000bc)
#define X_REG_DMA1DAD           (*(std::uint32_t*)0x040000c0)
#define X_REG_DMA1CNT           (*(std::uint32_t*)0x040000c4)
#define X_REG_DMA2SAD           (*(std::uint32_t*)0x040000c8)
#define X_REG_DMA2DAD           (*(std::uint32_t*)0x040000cc)
#define X_REG_DMA2CNT           (*(std::uint32_t*)0x040000d0)
#define X_REG_DMA3SAD           (*(std::uint32_t*)0x040000d4)
#define X_REG_DMA3DAD           (*(std::uint32_t*)0x040000d8)
#define X_REG_DMA3CNT           (*(std::uint32_t*)0x040000dc)
#define X_REG_SOUNDCNT_L        (*(std::uint16_t*)0x04000080)
#define X_REG_SOUNDCNT_H        (*(std::uint16_t*)0x04000082)
#define X_REG_SOUNDCNT_X        (*(std::uint32_t*)0x04000084)
#define X_REG_FIFOA             (0x040000a0)
#define X_REG_FIFOA_L           (0x040000a0)
#define X_REG_FIFOA_H           (0x040000a2)
#define X_REG_FIFOB             (0x040000a4)
#define X_REG_FIFOB_L           (0x040000a4)
#define X_REG_FIFOB_H           (0x040000a6)
#define X_REG_DISPCNT           (*(std::uint16_t*)0x04000000)
#define X_REG_DISPSTAT			(*(std::uint32_t*)0x04000004)
#define X_REG_VCOUNT            (*(volatile std::uint16_t*)0x04000006)

#endif // DEVICE_REGISTER_HH
