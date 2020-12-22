
.PHONY: clean
.IGNORE: clean
.SUFFIXES:
.INTERMEDIATE: %.o %.elf
.DELETE_ON_ERROR:

.DEFAULT_GOAL := asdj.gba

ifeq ($(strip ${DEVKITARM}),)
	$(error "DEVKITARM not set. Please set it in your environment.")
endif

include ${DEVKITARM}/gba_rules
PATH := ${DEVKITARM}/bin:${PATH}

## export PATH := ${DEVKITARM}/bin:${PATH}

## Set Flags:
ARCH = -mthumb -mthumb-interwork

CC = arm-none-eabi-gcc
CFLAGS = -g -Wall -O3\
	-mcpu=arm7tdmi -mtune=arm7tdmi\
	-fomit-frame-pointer -ffast-math \
	${ARCH}

ifdef INCLUDE
	CFLAGS += ${INCLUDE}
endif

CXXFLAGS := ${CFLAGS} -fno-rtti -fno-exceptions

ASFLAGS := ${ARCH}
LDFLAGS := -g ${ARCH} -Wl,-Map,$(notdir $@).map

asdj.gba: asdj.elf
	arm-none-eabi-objcopy -v -O binary $< $@

asdj.elf: asdj.o
	${CC} -specs=gba.specs ${CFLAGS} $< -o $@

asdj.o: asdj.c
	${CC} ${CFLAGS} -c $<

clean:
	rm -vf *.o *.elf

## EOF
