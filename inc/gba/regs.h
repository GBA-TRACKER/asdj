/*
 * inc/gba/regs.h
 * 
 * GBA Hardware Definition Headers - Register Definitions Header
 * 
 * Copyright 2020-2021 ASDj Dev Team
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

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
