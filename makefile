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

PATH := ${DEVKITPRO}/tools/bin:${DEVKITARM}/bin:${PATH}

## ---------------------------------------------------------------------
## Setup project details.
## ---------------------------------------------------------------------

TARGET   := $(shell basename ${CURDIR})
BUILD    := build
SOURCES  := obj
DATA     := 
INCLUDES := inc
INCLUDES += inc/gba

LIBS     := 
LIBDIRS  := ${LIBGBA}

OBJS     := ${TARGET}.o
OBJS     += ${SOURCES}/bgctl.o
OBJS     += ${SOURCES}/oamctl.o
OBJS     += ${SOURCES}/flash.o

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
	@rm -vf ${SOURCES}/*.o *.o *.elf

## EOF
