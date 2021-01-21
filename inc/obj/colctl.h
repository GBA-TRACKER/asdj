/*
 * inc/obj/colctl.h
 * 
 * Advanced Sound Dj - Color Control Module Header
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

#ifndef _COLCTL_H_
#define _COLCTL_H_

// Include GBA headers:
#include "../gba/gba.h"

// Declare functions defined in module:
COLORSPEC makeColSpec (const PRGB_COLOR pRgb);
RGB_COLOR makeRgbCol (const COLORSPEC csCol);

#endif /* _COLCTL_H_ */

// EOF
