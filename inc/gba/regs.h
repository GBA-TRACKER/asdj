//
// inc/gba/regs.h
//
// GBA Registers
//

#ifndef GBA_HEAD_REGS
#define GBA_HEAD_REGS

#define OAM_Memory ((unsigned short*) 0x07000000) // Sprite co-ords, size, etc (1Kb total).
#define OAM_Data ((unsigned short*) 0x06010000) // Bitmapped sprite data.

#define FrontBuff ((unsigned short*) 0x06000000) // Display memory (screen in modes 3-5).

#define BG_PalMem ((unsigned short*) 0x05000000) // Background palette.
#define OBJ_PalMem ((unsigned short*) 0x05000200) // Sprite palette.

#define REG_DISPCNT *(unsigned short*) 0x04000000 // Display control mode.
#define REG_VCOUNT *(volatile unsigned short*) 0x04000006 // Vertical sync control.

#define REG_KEYS *(volatile unsigned short*) 0x04000130 // Key input register.

#endif

// EOF
