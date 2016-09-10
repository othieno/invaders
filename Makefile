# This file is part of the Space Invaders clone project.
# https://github.com/othieno/invaders
#
# Copyright (c) 2016 Jeremy Othieno.
#
# The MIT License (MIT)
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
TARGET				= invaders
SRC_DIR				= \
					src \
					src/device \
					src/framework \
					src/framework/scene \
					src/framework/service \
					src/game \
					src/game/scene \
					src/type
INCLUDE_DIR			= $(SRC_DIR)
LIB_DIR				= lib/libgba
LIB					= -lgba
GBA_EMULATOR		= mednafen

# ---------------------------------------------------------------------------------------
# Beware, here be dragons!
GBASDK_DIR			= sdk
export PATH			:= $(GBASDK_DIR)/bin:$(PATH)

BIN_DIR				= bin
ELF					= $(BIN_DIR)/$(TARGET).elf
ELF_MAP				= $(BIN_DIR)/$(TARGET).elf.map
BIN					= $(BIN_DIR)/$(TARGET).gba

VPATH				= $(SRC_DIR)
SRC					= $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.cc))

OBJ_DIR				= build
OBJ					= $(foreach file, $(SRC), $(OBJ_DIR)/$(notdir $(file:%.cc=%.o)))
DEP					= $(OBJ:%.o=%.d)

LIB_PATH			= $(foreach dir, $(LIB_DIR), -L$(dir)/lib)

INCLUDE_PATH		= $(INCLUDE_DIR:%=-I%) $(foreach path, $(LIB_DIR), -I$(path)/include)
INCLUDE				= $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.hh))

PREFIX				= arm-none-eabi-
CXX					= $(PREFIX)g++
LD					= $(CXX)
OBJCOPY				= $(PREFIX)objcopy
GBAFIX 				= gbafix
ARCH				= -mthumb -mthumb-interwork
CXXFLAGS			= \
					-std=c++11 -Wall -O3 \
					-mcpu=arm7tdmi -mtune=arm7tdmi \
					-fomit-frame-pointer -ffast-math \
					-fno-strict-aliasing -fno-rtti -fno-exceptions \
					$(ARCH) $(LIB) $(INCLUDE_PATH)
LDFLAGS				= $(ARCH) -Wl,-Map,$(ELF_MAP)

all: $(BIN)

$(BIN): $(ELF)
	@$(OBJCOPY) -O binary $< $@
	@$(GBAFIX) $@ > /dev/null

$(ELF): $(OBJ) | $(BIN_DIR)
	@echo LD $@
	@$(LD) $(LDFLAGS) -specs=gba.specs $(OBJ) $(LIB_PATH) $(LIB) -o $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR) $(BIN_DIR):;	@mkdir -p $@

$(OBJ_DIR)/%.o: %.cc Makefile
$(OBJ_DIR)/%.o: %.cc Makefile $(OBJ_DIR)/%.d
	@echo CC $(filter %.cc, $^)
	@$(CXX) $(CXXFLAGS) -MT $@ -MMD -MP -MF $(filter %.d, $^) -c $(filter %.cc, $^) -o $@

$(DEP):;
.PRECIOUS: $(DEP)
-include $(DEP)

run: $(BIN)
	@$(GBA_EMULATOR) $<

clean:
	@rm -df $(BIN) $(DEP) $(ELF) $(ELF_MAP) $(OBJ) $(BIN_DIR) $(OBJ_DIR)
