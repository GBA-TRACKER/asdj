//
// inc/gba/regs/keys.h
//
// GBA Keypad Register Definitions
//

#ifndef GBA_HEAD_REGS_KEYS
#define GBA_HEAD_REGS_KEYS

#include "../types.h"

#define REG_KEYINPUT *(volatile pu16) 0x04000130 // Key input register.
#define REG_KEYCNT *(volatile pu16) 0x04000132 // Key interrupt control.

#define REG_KEYS REG_KEYINPUT

#endif /* GBA_HEAD_REGS_KEYS */

// EOF
