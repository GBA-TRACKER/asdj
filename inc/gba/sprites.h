//
// inc/gba/sprites.h
//
// GBA Sprite Flags, Constants, and Structures
//

#ifndef GBA_HEAD_SPRITES
#define GBA_HEAD_SPRITES

#include "types.h"

// OAM Entry:
typedef struct tagOAMEntry
{
	u16 uAttr0;
	u16 uAttr1;
	u16 uAttr2;
	u16 uAttr3;
} OAMEntry, *pOAMEntry;


// Sprite rotation data:
typedef struct tagRotData
{
	u16 uFiller1[3];
	u16 uPa;
	u16 uFiller2[3];
	u16 uPb;
	u16 uFiller3[3];
	u16 uPc;
	u16 uFiller4[3];
	u16 uPd;
} RotData, *pRotData;

#define C_SPRITES 128 // Total count of sprites.
#define CB_OAM C_SPRITES*8 // Total size of OAM, in bytes.

// Attribute 0:
#define ATR0_ROTATION_FLAG 0x0100
#define ATR0_SIZE_DOUBLE 0x0200
#define ATR0_MODE_NORMAL 0x0000
#define ATR0_MODE_TRANSPARENT 0x0400
#define ATR0_MODE_WINDOWED 0x0800
#define ATR0_MOSAIC 0x1000
#define ATR0_COLOR16 0x0000
#define ATR0_COLOR256 0x2000
#define ATR0_SQUARE 0x0000
#define ATR0_WIDE 0x4000
#define ATR0_TALL 0x8000
#define ATR0_MASK 0xFF00

// Attribute 1:
#define ATR1_ROTDATA(n) (n << 9)
#define ATR1_HFLIP 0x1000
#define ATR1_VFLIP 0x2000
#define ATR1_SIZE8 0x0000
#define ATR1_SIZE16 0x4000
#define ATR1_SIZE32 0x8000
#define ATR1_SIZE64 0xC000 // (0x4000 | 0x8000)
#define ATR1_MASK 0xFE00

// Attribute 2:
#define ATR2_PRIORITY(n) ((n) << 10)
#define ATR2_PALETTE(n) ((n) << 12)

#endif

// EOF
