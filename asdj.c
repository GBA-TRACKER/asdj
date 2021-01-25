/*
 * asdj.c
 * 
 * Advanced Sound Dj - Main Module
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

#include "asdj.h"

// Include C headers:
#include <stdlib.h>
#include <string.h>

// Main routine:
int main () {
	
	// Initialize:
	doInit();
	
	RGB_COLOR rgbTemp = {
		0, 0, 0
	};
	
	// Main loop code:
	while(1) {
		
		// Wait for a frame to be drawn.
		waitForVSync();
		
		// Process user input.
		doKeyInput();
		
		rgbTemp.uRed += 1;
		rgbTemp.uGreen += 1;
		rgbTemp.uBlue += 1;
		MEM_PAL_BG[0] = makeColSpec(&rgbTemp);
		
	}
	
	return EXIT_SUCCESS;
	
}

ERRORID doInit () {
	
	// Initialize OAM.
	u8 iObject;
	for (iObject = 0; iObject < g_cSprites; iObject++)
		setSpritePos((volatile POAM_ENTRY) &MEM_OAM[iObject * (sizeof(OAM_ENTRY) / 2)], SCREEN_WIDTH, SCREEN_HEIGHT);
	
	// Set video mode.
	REG_DISPCNT = (u16)(MODE_0 | BG0_ENABLE | OBJ_ENABLE | OBJ_MAP_1D);
	
	// Set background 0 mode.
	REG_BG0CNT = (u16)(BG_PRIORITY(3) | BG_CHARBASE(0) | BG_SCREENBASE(8) | BG_SCREENSIZE(0));
	
	// Setup palettes:
	// Copy object palettes.
	copyObjPalette16((const pu16)PALETTE_DEFAULT, 0);
	copyObjPalette16((const pu16)PALETTE_DEFAULT2, 1);
	copyObjPalette16((const pu16)PALETTE_GREYSCALE, 2);
	copyObjPalette16((const pu16)PALETTE_MONO, 3);
	copyObjPalette16((const pu16)PALETTE_TEXT, 4);
	
	// Copy background palettes.
	copyBgPalette16((const pu16)PALETTE_DEFAULT, 0);
	copyBgPalette16((const pu16)PALETTE_DEFAULT2, 1);
	copyBgPalette16((const pu16)PALETTE_GREYSCALE, 2);
	copyBgPalette16((const pu16)PALETTE_MONO, 3);
	copyBgPalette16((const pu16)PALETTE_TEXT, 4);
	
	// Copy tile data:
	// Copy object tile data.
	copyObjTile((const pu8)SPRITE_CURSOR, 0);
	
	// Copy background tile data.
	u16 uOffset = 16;
	memcpy(MEM_VRAM + uOffset, SMALLFONT_4X4Tiles, SMALLFONT_4X4TilesLen);
	uOffset += (SMALLFONT_4X4TilesLen / 2);
	
	memcpy(MEM_VRAM + uOffset, SMALLFONT_8X4Tiles, SMALLFONT_8X4TilesLen);
	uOffset += (SMALLFONT_8X4TilesLen / 2);
	
	memcpy(MEM_VRAM + uOffset, FONT_8X8Tiles, FONT_8X8TilesLen);
	uOffset = (FONT_8X8TilesLen / 2);
	
	return ERR_SUCCESS;
	
}

// Read and process user's key input.
static inline void doKeyInput () {
	
	static u16 uKeyState;
	static Point2D8 xyDelta;
	
	// Read key register
	if ((uKeyState = (~REG_KEYINPUT & KEY_MASK))) {
		
		// Clear the cursor position's delta.
		memset(&xyDelta, 0, sizeof(Point2D8));
		
		// Disallow opposing inputs.
		if (uKeyState & (KEY_RIGHT | KEY_LEFT)) return;
		if (uKeyState & (KEY_UP | KEY_DOWN)) return;
		
		// Move the cursor based on the dpad's state.
		if (uKeyState & KEY_RIGHT) xyDelta.x = 1;
		if (uKeyState & KEY_LEFT) xyDelta.x = -1;
		if (uKeyState & KEY_UP) xyDelta.y = 1;
		if (uKeyState & KEY_DOWN) xyDelta.y = -1;
		
		moveSprite((volatile POAM_ENTRY)&MEM_OAM[0], xyDelta.x, xyDelta.y);
	}
	
}

// Waits for VSync.
static inline void waitForVSync () {
	
	//while(!(REG_DISPSTAT & VBLANK));
	//while(REG_VCOUNT >= SCREEN_HEIGHT); // Skip the rest of current vblank.
	//while(REG_VCOUNT < SCREEN_HEIGHT); // Wait until next vblank.
	
}

// EOF
