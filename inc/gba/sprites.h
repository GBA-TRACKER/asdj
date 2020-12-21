//
// inc/gba/sprites.h
//
// GBA Sprite Flags and Structures
//

#ifndef GBA_HEAD_SPRITES
#define GBA_HEAD_SPRITES

// OAM Entry:
typedef struct tagOAMEntry
{
	unsigned short uAttr0;
	unsigned short uAttr1;
	unsigned short uAttr2;
	unsigned short uAttr3;
} OAMEntry, *pOAMEntry;


// Sprite rotation data:
typedef struct tagRotData
{
	unsigned short uFiller1[3];
	unsigned short uPa;
	unsigned short uFiller2[3];
	unsigned short uPb;
	unsigned short uFiller3[3];
	unsigned short uPc;
	unsigned short uFiller4[3];
	unsigned short uPd;
} RotData, *pRotData;

#define C_SPRITES 128

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
