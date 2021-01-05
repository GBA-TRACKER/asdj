//
// inc/gba/gba.h
//
// GBA Hardware Header File
//

#ifndef GBA_HEAD
#define GBA_HEAD

// Include other headers:
#include "types.h" // Typedefs.
#include "regs.h" // Registers.
#include "flags.h" // Flags.
#include "macros.h" // Macros.

// Default definitions:

// Screen resolution:
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160

#define C_SPRITES 128 // Total count of sprites.
#define CB_OAM (C_SPRITES*8) // Total size of OAM, in bytes.

#endif /* GBA_HEAD */

// EOF
