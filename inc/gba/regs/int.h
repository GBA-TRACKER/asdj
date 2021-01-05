//
// inc/gba/regs/int.h
//
// GBA Interrupt Register Definitions.
//

#ifndef GBA_HEAD_REGS_INT
#define GBA_HEAD_REGS_INT

#include "../types.h"

#define REG_IE *(pu16) 0x04000200 // Interrupt enable.
#define REG_IF *(pu16) 0x04000202 // IRQ flags & acknowledge.
#define REG_WAITCNT *(pu16) 0x04000204 // Waitstate control.
#define REG_IME *(pu16) 0x04000208 // Interrupt master enable register.
#define REG_POSTFLG *(pu8) 0x04000300 // Post boot flag.
#define REG_HALTCNT *(volatile pu8) 0x04000301 // Power down control (write only).

#endif /* GBA_HEAD_REGS_INT */

// EOF
