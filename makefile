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

include makefile.settings

## ---------------------------------------------------------------------
## Setup project details.
## ---------------------------------------------------------------------

TARGET   := $(shell basename ${CURDIR})
BUILD    := 
SOURCES  := obj
DATA     := data
INCLUDES := inc

LIBS     := 
LIBDIRS  := 
## LIBDIRS  := ${LIBGBA}

OBJS     := ${TARGET}.o

OBJS     += ${SOURCES}/colctl.o
OBJS     += ${SOURCES}/flash.o
OBJS     += ${SOURCES}/oamctl.o
OBJS     += ${SOURCES}/palctl.o
OBJS     += ${SOURCES}/tilectl.o
OBJS     += ${SOURCES}/timerctl.o

OBJS     += ${SOURCES}/data/palette.o
OBJS     += ${SOURCES}/data/sprite.o

OBJS     += ${DATA}/gfx/font_8x8.o
OBJS     += ${DATA}/gfx/smallfnt_4x4.o
OBJS     += ${DATA}/gfx/smallfnt_8x4.o

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

LDFLAGS  := ${CFLAGS} ${SPECS}

CXXFLAGS := ${CFLAGS} -fno-rtti -fno-exceptions

ASFLAGS  := ${ARCH}

ROMTITLE ?= 'ASDj v0.0'
GAMECODE ?= 'CASE'
MAKECODE ?= 'DJ'
REVCODE  ?= 00

## ---------------------------------------------------------------------
## Compilation rules.
## ---------------------------------------------------------------------

.INTERMEDIATE: ${TARGET}.elf
.DELETE_ON_ERROR: ${OBJS} ${TARGET}.elf

## Fix GBA header.
build: ${TARGET}.gba
	-@echo 'Fixing GBA ROM header in "$<"...'
	gbafix $< -t${ROMTITLE} -c${GAMECODE} -m${MAKECODE} -r${REVCODE}

## Strip intermediary binary, and convert to GBA ROM format.
${TARGET}.gba: ${TARGET}.elf
	-@echo -e 'Stripping symbols from "$<"... ("$<"->"$@")'
	${OBJCOPY} -v -O binary $< $@

## Link objects into intermediary binary.
${TARGET}.elf: ${TARGET}.o ${OBJS}
	-@echo -e 'Linking objects... ("$^"->"$@")'
	${LD} $^ $(LDFLAGS) -o $@

## Compile objects.
${OBJS}: %.o : %.c
	-@echo -e 'Compiling object "$@"... ("$<"->"$@")'
	${CC} ${CFLAGS} -c $< -o $@

## Remove unnecessary binary files.
.IGNORE: clean
clean:
	-@echo 'Cleaning up intermediary files...'
	@rm -vf ${SOURCES}/*.o ${DATA}/gfx/*.o *.o *.elf

## EOF
