//
// inc/gba/flags/sprites.h
//
// GBA OAM/Sprite Attribute Flags
//

#ifndef GBA_HEAD_FLAGS_SPRITES
#define GBA_HEAD_FLAGS_SPRITES

// OAM Attribute 0:
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

// OAM Attribute 1:
#define ATR1_ROTDATA(n) (n << 9)
#define ATR1_HFLIP 0x1000
#define ATR1_VFLIP 0x2000
#define ATR1_SIZE8 0x0000
#define ATR1_SIZE16 0x4000
#define ATR1_SIZE32 0x8000
#define ATR1_SIZE64 0xC000 // (0x4000 | 0x8000)
#define ATR1_MASK 0xFE00

// OAM Attribute 2:
#define ATR2_PRIORITY(n) ((n) << 10)
#define ATR2_PALETTE(n) ((n) << 12)

#endif /* GBA_HEAD_FLAGS_SPRITES */

// EOF
