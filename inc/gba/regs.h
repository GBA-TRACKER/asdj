//
// inc/gba/regs.h
//
// GBA Registers
//

#ifndef GBA_HEAD_REGS
#define GBA_HEAD_REGS

#include "types.h"

#define REG_DISPCNT *(pu16) 0x04000000 // Display control mode.
#define REG_VCOUNT *(volatile pu16) 0x04000006 // Vertical sync control.

// Sound Hardware Registers:
#define REG_SNDCNT_L *(pu16) 0x04000080 // Sound control L (Legacy).
#define REG_SNDCNT_H *(pu16) 0x04000082 // Sound control H (GBA).
#define REG_SNDCNT_X *(pu32) 0x04000084 // Sound control X.

// Timer Control Registers:
#define REG_TM0CNT *(volatile pu16) 0x04000102
#define REG_TM1CNT *(volatile pu16) 0x04000106
#define REG_TM2CNT *(volatile pu16) 0x0400010A
#define REG_TM3CNT *(volatile pu16) 0x0400010E

// Timer Counter Registers:
#define REG_TM0D *(volatile pu16) 0x04000100
#define REG_TM1D *(volatile pu16) 0x04000104
#define REG_TM2D *(volatile pu16) 0x04000108
#define REG_TM3D *(volatile pu16) 0x0400010C

#define REG_KEYS *(volatile pu16) 0x04000130 // Key input register.

#define BG_PalMem ((pu16) 0x05000000) // Background palette.
#define OBJ_PalMem ((pu16) 0x05000200) // Sprite palette.

#define VRAM ((pu16) 0x06000000) // Video memory, screen in modes 3-5.

#define OAM_Data ((pu16) 0x06010000) // Bitmapped sprite data.
#define OAM_Memory ((pu16) 0x07000000) // Sprite co-ords, size, etc (1Kb total).

#endif

// EOF
