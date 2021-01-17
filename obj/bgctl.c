/*
 * obj/bgctl.c
 * 
 * Advanced Sound Dj - Background Control Module
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
#include "../inc/obj/bgctl.h"

// Include used C headers:
#include <string.h>

// Copy a background palette to BG palette memory.
/* void copyBgPalette (const pu16 pbgPalette) {
	
	if (pbgPalette == NULL) {
		memset(BG_PalMem, 0, 512);
	} else {
		memcpy(BG_PalMem, pbgPalette, 512);
	}
	
} */

// Copy a background to VRAM.
void copyBackground (const pu16 pbgData) {
	
	if (pbgData == NULL) {
		memset(VRAM, 0, (120 * SCREEN_HEIGHT) * 2);
	} else {
		memcpy(VRAM, pbgData, (120 * SCREEN_HEIGHT) * 2);
	}
	
}

// EOF
