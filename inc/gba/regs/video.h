//
// inc/gba/regs/video.h
//
// GBA Video Register Definitions
//

#ifndef GBA_HEAD_REGS_VIDEO
#define GBA_HEAD_REGS_VIDEO

#include "../types.h"

// General control registers:
#define REG_DISPCNT *(pu16) 0x04000000 // Display control mode.
#define REG_DISPSTAT *(pu16) 0x04000004 // General display status 
#define REG_VCOUNT *(volatile pu16) 0x04000006 // Vertical sync control.

// Background control registers:
#define REG_BG0CNT *(pu16) 0x04000008 // BG0 control.
#define REG_BG1CNT *(pu16) 0x0400000A // BG1 control.
#define REG_BG2CNT *(pu16) 0x0400000C // BG2 control.
#define REG_BG3CNT *(pu16) 0x0400000E // BG3 control.

// Background horizontal & vertical offset registers (write only):
#define REG_BG0HOFS *(pu16) 0x04000010
#define REG_BG0VOFS *(pu16) 0x04000012
#define REG_BG1HOFS *(pu16) 0x04000014
#define REG_BG1VOFS *(pu16) 0x04000016
#define REG_BG2HOFS *(pu16) 0x04000018
#define REG_BG2VOFS *(pu16) 0x0400001A
#define REG_BG3HOFS *(pu16) 0x0400001C
#define REG_BG3VOFS *(pu16) 0x0400001E

// Background 2 rotation & scaling registers (write only):
#define REG_BG2PA *(pu16) 0x04000020 // dx.
#define REG_BG2PB *(pu16) 0x04000022 // dmx.
#define REG_BG2PC *(pu16) 0x04000024 // dy.
#define REG_BG2PD *(pu16) 0x04000026 // dmy.
#define REG_BG2X *(pu32) 0x04000028 // Reference X co-ord.
#define REG_BG2Y *(pu32) 0x0400002C // Reference Y co-ord.

// Background 3 rotation & scaling registers (write only):
#define REG_BG3PA *(pu16) 0x04000030 // dx.
#define REG_BG3PB *(pu16) 0x04000032 // dmx.
#define REG_BG3PC *(pu16) 0x04000034 // dy.
#define REG_BG3PD *(pu16) 0x04000036 // dmy.
#define REG_BG3X *(pu32) 0x04000038 // Reference X co-ord.
#define REG_BG3Y *(pu32) 0x0400003C // Reference Y co-ord.

// Window registers:
#define REG_WIN0H *(pu16) 0x04000040 // Window 0 horizontal dimensions (write only).
#define REG_WIN1H *(pu16) 0x04000042 // Window 1 horizontal dimensions (write only).
#define REG_WIN0V *(pu16) 0x04000044 // Window 0 vertical dimensions (write only).
#define REG_WIN1V *(pu16) 0x04000046 // Window 1 vertical dimensions (write only).
#define REG_WININ *(pu16) 0x04000048 // Window 0 & 1 insides (read/write).
#define REG_WINOUT *(pu16) 0x0400004A // Window 0 & 1 outsides (read/write).

#define REG_MOSAIC *(pu16) 0x0400004C // Mosaic size.

// Blending control registers:
#define REG_BLDCNT *(pu16) 0x04000050 // Special color effects control.
#define REG_BLDALPHA *(pu16) 0x04000052 // Alpha blending coefficients.
#define REG_BLDY *(pu16) 0x04000054 // Fade-in/out/brightness coefficient.

#endif

// EOF
