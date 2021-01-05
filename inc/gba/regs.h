//
// inc/gba/regs.h
//
// GBA Registers
//

#ifndef GBA_HEAD_REGS
#define GBA_HEAD_REGS

#include "types.h"

// Include register definition files for subsystems:
#include "regs/video.h"
#include "regs/sound.h"
#include "regs/dma.h"
#include "regs/timer.h"
#include "regs/serial.h"
#include "regs/keys.h"
#include "regs/sys.h"

// Define memory ranges:
#define BG_PalMem ((pu16) 0x05000000) // Background palette.
#define OBJ_PalMem ((pu16) 0x05000200) // Sprite palette.

#define VRAM ((pu16) 0x06000000) // Video memory, screen in modes 3-5.

#define OAM_Data ((pu16) 0x06010000) // Bitmapped sprite data.
#define OAM_Memory ((pu16) 0x07000000) // Sprite co-ords, size, etc (1Kb total).

#define SRAM ((pu8) 0x0E000000)

#endif /* GBA_HEAD_REGS */

// EOF
