//
// inc/gba/regs/timer.h
//
// GBA Timer Register Definitions
//

#ifndef GBA_HEAD_REGS_TIMER
#define GBA_HEAD_REGS_TIMER

#include "../types.h"

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

#endif /* GBA_HEAD_REGS_TIMER */

// EOF
