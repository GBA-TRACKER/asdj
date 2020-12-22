## ---------------------------------------------------------------------
## ASDj makefile
## Usage:
## make [build] - Build ASDj
## make clean   - Remove extra files.
## ---------------------------------------------------------------------

## ---------------------------------------------------------------------
## Set phony & default targets, and override the default suffix rules.
## ---------------------------------------------------------------------
.PHONY: build clean
.SUFFIXES:

.DEFAULT_GOAL := build

## ---------------------------------------------------------------------
## Make sure DEVKITARM is set, and load the rules for GBA & set the
## path.
## ---------------------------------------------------------------------
ifeq ($(strip ${DEVKITARM}),)
	$(error "DEVKITARM not set. Please set it in your environment.")
endif

include ${DEVKITARM}/gba_rules

PATH := ${DEVKITARM}/bin:${PATH}

## ---------------------------------------------------------------------
## Setup project details.
## ---------------------------------------------------------------------
TARGET   := $(shell basename ${CURDIR})
BUILD    := 
SOURCES  := obj
DATA     := 
INCLUDES := inc
INCLUDES += inc/gba

LIBS     := 
LIBDIRS  := ${LIBGBA}

OBJS     := ${TARGET}.o
OBJS     += ${SOURCES}/oamctl.o

## ---------------------------------------------------------------------
## Set flags for code generation.
## ---------------------------------------------------------------------

PREFIX   =  arm-none-eabi-
CC       := ${PREFIX}gcc
LD       := ${PREFIX}gcc
OBJCOPY  := ${PREFIX}objcopy

ARCH     =  -mthumb -mthumb-interwork
SPECS    =  -specs=gba.specs

CFLAGS   =  -g -Wall -O3\
	-fomit-frame-pointer -ffast-math -fno-strict-aliasing\
	-mcpu=arm7tdmi -mtune=arm7tdmi \
	${ARCH}

ifdef INCLUDE
	CFLAGS += ${INCLUDE}
endif

##LDFLAGS  := -g ${ARCH} -Wl,-Map,$(notdir $@).map
LDFLAGS  := ${CFLAGS} ${SPECS}

CXXFLAGS := ${CFLAGS} -fno-rtti -fno-exceptions

ASFLAGS  := ${ARCH}

## ---------------------------------------------------------------------
## Compilation rules.
## ---------------------------------------------------------------------

#.INTERMEDIATE: ${OBJS} ${TARGET}.elf
.DELETE_ON_ERROR: ${OBJS} ${TARGET}.elf

build: ${TARGET}.gba

## Strip binaries.
${TARGET}.gba: ${TARGET}.elf
	-@echo 'Stripping symbols.'
	${OBJCOPY} -v -O binary $< $@

## Link objects.
${TARGET}.elf: ${TARGET}.o ${OBJS}
	-@echo 'Linking objects.'
	${LD} $^ $(LDFLAGS) -o $@

## Compile objects.
${OBJS}: %.o : %.c
	-@echo 'Compiling objects: ${OBJS}'
	${CC} ${CFLAGS} -c $< -o $@

.IGNORE: clean
clean:
	rm -vf ${OBJS}
	rm -vf *.elf

## EOF
