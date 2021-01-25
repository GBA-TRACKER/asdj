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

// Define constants:
const u16 g_cPalEntries = 256;
const u16 g_cbPalette = (g_cPalEntries * sizeof(u16));

const u8 g_cSubPal = 16;
const u8 g_cbSubPal = (g_cSubPal * sizeof(u16));

// Copies a 256-color object palette.
void copyObjPalette256 (const pu16 pPalette) {
	
	if (pPalette == NULL) {
		memset(MEM_PAL_OBJ, 0, g_cbPalette);
	} else {
		memcpy(MEM_PAL_OBJ, pPalette, g_cbPalette);
	}
	
}

// Copies a 256-color background palette.
void copyBgPalette256 (const pu16 pPalette) {
	
	if (pPalette == NULL) {
		memset(MEM_PAL_BG, 0, g_cbPalette);
	} else {
		memcpy(MEM_PAL_BG, pPalette, g_cbPalette);
	}
	
}

// Copies a sixteen color sprite palette to a given subpalette index.
void copyObjPalette16 (const pu16 pPalette, const u8 iIndex) {
	
	// Return immediately if index is invalid.
	if (iIndex >= g_cSubPal) return;
	
	if (pPalette == NULL) {
		memset(&MEM_PAL_OBJ[iIndex * g_cSubPal], 0, g_cbSubPal);
	} else {
		memcpy(&MEM_PAL_OBJ[iIndex * g_cSubPal], pPalette, g_cbSubPal);
	}
	
}

// Copies a sixteen color background palette to a given subpalette index.
void copyBgPalette16 (const pu16 pPalette, const u8 iIndex) {
	
	// Return immediately if index is invalid.
	if (iIndex >= g_cSubPal) return;
	
	if (pPalette == NULL) {
		memset(&MEM_PAL_BG[iIndex * g_cSubPal], 0, g_cbSubPal);
	} else {
		memcpy(&MEM_PAL_BG[iIndex * g_cSubPal], pPalette, g_cbSubPal);
	}
	
}

// EOF
