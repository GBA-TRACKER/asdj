/*
 * obj/tilectl.c
 * 
 * Advanced Sound Dj - Tile Control Module
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
#include "../inc/obj/tilectl.h"

// Include used C headers:
#include <string.h>

const u8 g_cbTile = 32;
const u16 g_cObjTiles = 1024;

void copyBgTile (const pu8 pTile, const u16 iOffset) {
	
	if (pTile == NULL) {
		memset(&VRAM[iOffset * g_cbTile], 0, g_cbTile);
	} else {
		memcpy(&VRAM[iOffset * g_cbTile], pTile, g_cbTile);
	}
	
}

// Copy object tile data to a given tile index.
void copyObjTile (const pu8 pTile, const u16 iIndex) {
	
	if (iIndex >= g_cObjTiles) return;
	
	if (pTile == NULL) {
		memset(&OBJ_Data[iIndex * g_cbTile], 0, g_cbTile);
	} else {
		memcpy(&OBJ_Data[iIndex * g_cbTile], pTile, g_cbTile);
	}
	
}

// Copy a background to VRAM.
/* void copyBackground (const pu16 pbgData) {
	
	if (pbgData == NULL) {
		memset(VRAM, 0, (120 * SCREEN_HEIGHT) * 2);
	} else {
		memcpy(VRAM, pbgData, (120 * SCREEN_HEIGHT) * 2);
	}
	
} */

// EOF
