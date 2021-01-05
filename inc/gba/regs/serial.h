//
// inc/gba/regs/serial.h
//
// GBA Serial Register Definitions.
//

#ifndef GBA_HEAD_REGS_SERIAL
#define GBA_HEAD_REGS_SERIAL

#include "../types.h"

// Serial communications 1:
#define REG_SIODATA32 *(pu32) 0x04000120 // Serial I/O data (32-bit normal mode).
#define REG_SIOMULTI0 *(pu16) 0x04000120 // Serial I/O data (multiplayer parent).
#define REG_SIOMULTI1 *(pu16) 0x04000122 // Serial I/O data (multiplayer child 1).
#define REG_SIOMULTI2 *(pu16) 0x04000124 // Serial I/O data (multiplayer child 2).
#define REG_SIOMULTI3 *(pu16) 0x04000126 // Serial I/O data (multiplayer child 3).
#define REG_SIOCNT *(pu16) 0x04000128 // Serial I/O control.
#define REG_SIOMLT_SEND *(pu16) 0x0400012A //
#define REG_SIODATA8 *(pu16) 0x0400012A // Serial I/O data (8-bit normal mode/UART mode).

// Serial communications 2:
#define REG_RCNT *(pu16) 0x04000134 // General data & SIO control.
#define REG_JOYCNT *(pu16) 0x04000140 // SIO joy bus control.
#define REG_JOY_RECV *(pu32) 0x04000150 // SIO joy bus recieve.
#define REG_JOY_SEND *(pu32) 0x04000154 // SIO joy bus send.
#define REG_JOYSTAT *(volatile pu16) 0x04000158 // SIO joy bus status.

#endif /* GBA_HEAD_REGS_SERIAL */

// EOF
