/*
 * obj/palctl.c
 * 
 * Advanced Sound Dj - Palette Control Module Header
 * 
 * Copyright 2020-2021 ASDJ Dev Team
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

#ifndef _PALCTL_H_
#define _PALCTL_H_

// Include GBA headers:
#include "../gba/gba.h"

// Declare external constants:
extern const u16 g_cPalEntries;
extern const u16 g_cbPalette;
extern const u8 g_cSubPal;
extern const u8 g_cbSubPal;

// Declare functions defined in module:
void copyObjPalette256 (const pu16 pPalette);
void copyBgPalette256 (const pu16 pPalette);
void copyObjPalette16 (const pu16 pPalette, const u8 iIndex);
void copyBgPalette16 (const pu16 pPalette, const u8 iIndex);

#endif /* _PALCTL_H_ */

// EOF
