/*
 * inc/gba/flags.h
 * 
 * GBA Hardware Definition Headers - Flags Definitions Header
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

#ifndef GBA_HEAD_FLAGS
#define GBA_HEAD_FLAGS

#include "types.h"

// TODO: Write dma.h, & serial.h.
// Include flag definition files for subsystems:
#include "flags/video.h"
#include "flags/sprites.h"
#include "flags/sound.h"
//#include "flags/dma.h"
#include "flags/timer.h"
//#include "flags/serial.h"
#include "flags/keys.h"
#include "flags/sys.h"

#endif /* GBA_HEAD_FLAGS */

// EOF
