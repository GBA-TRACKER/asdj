/*
 * obj/palctl.c
 * 
 * Advanced Sound Dj - Palette Control Module
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

// Include module header:
#include "../inc/obj/palctl.h"

// Include used C headers:
#include <string.h>

const u16 cPalEntries = 256;
const u16 cbPalette = (cPalEntries * sizeof(u16));

const u16 cSubPal = 16;
const u16 cbSubPal = (cSubPal * sizeof(u16));

// Copies a 256-color object palette.
void copyObjPalette256 (const pu16 pPalette) {
	
	if (pPalette == NULL) {
		memset(OBJ_PalMem, 0, cbPalette);
	} else {
		memcpy(OBJ_PalMem, pPalette, cbPalette);
	}
	
}

// Copies a 256-color background palette.
void copyBgPalette256 (const pu16 pPalette) {
	
	if (pPalette == NULL) {
		memset(BG_PalMem, 0, cbPalette);
	} else {
		memcpy(BG_PalMem, pPalette, cbPalette);
	}
	
}

// Copies a sixteen color sprite palette to a given subpalette index.
void copyObjPalette16 (const pu16 pPalette, const u8 iIndex) {
	
	if (iIndex >= cSubPal) return;
	
	if (pPalette == NULL) {
		memset(&OBJ_PalMem[iIndex * cSubPal], 0, cbSubPal);
	} else {
		memcpy(&OBJ_PalMem[iIndex * cSubPal], pPalette, cbSubPal);
	}
	
}

// Copies a sixteen color background palette to a given subpalette index.
void copyBgPalette16 (const pu16 pPalette, const u8 iIndex) {
	
	if (iIndex >= cSubPal) return;
	
	if (pPalette == NULL) {
		memset(&BG_PalMem[iIndex * cSubPal], 0, cbSubPal);
	} else {
		memcpy(&BG_PalMem[iIndex * cSubPal], pPalette, cbSubPal);
	}
	
}

// EOF
