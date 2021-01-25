## ---------------------------------------------------------------------
## Makefile for ASDj graphics.
## ---------------------------------------------------------------------


## ---------------------------------------------------------------------
## Set phony & default targets, and override the default suffix rules.
## ---------------------------------------------------------------------

.PHONY: convert clean
.SUFFIXES:

.DEFAULT_GOAL := convert

include ../../makefile.settings

## ---------------------------------------------------------------------
## Set settings for bitmap/PNG conversion using GRIT.
## ---------------------------------------------------------------------

GFXOPTS   = -g -gu8 -gt -gB4
MAPOPTS   = -m!
PALOPTS   = -p! -pu16 -pn16
OBJOPTS   = -Mh1 -Mw1
FILEOPTS  = -ftc -fh
MISCOPTS  = -tw8 -th8 -U8 -W3 -Z!

GRITFLAGS := ${GFXOPTS} ${MAPOPTS} ${PALOPTS} ${OBJOPTS} ${FILEOPTS} ${MISCOPTS}

ifdef GRITOPTS
	GRITFLAGS += ${GRITOPTS}
endif

## ---------------------------------------------------------------------
## Compilation rules.
## ---------------------------------------------------------------------

convert: smallfnt_4x4 smallfnt_8x4 font_8x8
	-@echo 'Successfully created: $^'

smallfnt_4x4: smallfnt.png
	-@echo 'Creating $@ from $<...'
	grit $< ${GRITFLAGS} -at0 -ah8 -s SMALLFONT_4X4 -o $@.c
	test -f $@.h
	test -f $@.c

smallfnt_8x4: smallfnt.png
	-@echo 'Creating $@ from $<...'
	grit $< ${GRITFLAGS} -at16 -ah48 -s SMALLFONT_8X4 -o $@.c
	test -f $@.h
	test -f $@.c

font_8x8: numpunct.png
	-@echo 'Creating $@ from $<...'
	grit $< ${GRITFLAGS} -s FONT_8X8 -o $@.c
	test -f $@.h
	test -f $@.c

.IGNORE: clean
clean:
	-@echo 'Cleaning up built files...'
	@rm -vf *.o
	@rm -vf *.c
	@rm -vf *.h
## EOF
