/*
 * asdj.h
 * 
 * Advanced Sound Dj - Main Module Header
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

#ifndef _ASDJ_H_
#define _ASDJ_H_

// Include GBA headers:
#include "inc/gba/gba.h"

// Include error codes header:
#include "inc/errcodes.h"

// Include object headers:
#include "inc/obj/colctl.h"
#include "inc/obj/flash.h"
#include "inc/obj/oamctl.h"
#include "inc/obj/palctl.h"
#include "inc/obj/tilectl.h"
#include "inc/obj/saves.h"

// Include data headers:
#include "inc/obj/data/palette.h"
#include "inc/obj/data/sprite.h"
#include "data/inc/gfx.h"

// Declare functions defined in main module:
ERRORID doInit ();
void doKeyInput (POAM_ENTRY poeCursor);
static inline void waitForVSync ();

#endif /* _ASDJ_H_ */

// EOF
