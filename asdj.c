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

// Shared module level variables:
OAM_ENTRY s_pSprite[128]; // Temporary buffer for all sprites attributes.

// Main routine:
int main () {
	
	// Initialize:
	doInit();
	
	// Main loop code:
	while(1) {
		
		// Wait for a frame to be drawn.
		waitForVSync();
		
		// Copy the temporary sprite buffer to OAM.
		copyAttrToOAM(&s_pSprite[0], 0);
		
		// Process user input.
		doKeyInput();
	}
	
	return EXIT_SUCCESS;
	
}

ERRORID doInit () {
	
	// Set video mode.
	// setVideoMode(MODE_0 | BG0_ENABLE | OBJ_ENABLE | OBJ_MAP_1D);
	REG_DISPCNT = (u16)(MODE_0 | BG0_ENABLE | OBJ_ENABLE | OBJ_MAP_1D);
	
	// Set background 0 mode.
	REG_BG0CNT = (u16)(BG_PRIORITY(3) | BG_CHARBASE(0) | BG_SCREENBASE(0) | BG_SCREENSIZE(0));
	
	
	// Setup temporary OAM buffer:
	// Clear temporary buffer.
	memset(s_pSprite, 0, (g_cSprites * sizeof(OAM_ENTRY)));
	
	// Fill it with default values.
	u8 iSprite;
	for (iSprite = 0; iSprite < g_cSprites; iSprite++) {
		
		// Hide all sprites offscreen.
		setSpritePos(&s_pSprite[iSprite], SCREEN_WIDTH, SCREEN_HEIGHT);
		
		// Setup some default attributes.
		s_pSprite[iSprite].uAttr0 |= (ATR0_COLOR16 | ATR0_SQUARE);
		s_pSprite[iSprite].uAttr1 |= (ATR1_SIZE8);
		s_pSprite[iSprite].uAttr2 |= (ATR2_PRIORITY(0) | ATR2_PALETTE(0));
	}
	
	// Setup palettes:
	// Copy object palettes.
	copyObjPalette16((const pu16)PALETTE_DEFAULT, 0);
	copyObjPalette16((const pu16)PALETTE_DEFAULT2, 1);
	copyObjPalette16((const pu16)PALETTE_GREYSCALE, 2);
	copyObjPalette16((const pu16)PALETTE_MONO, 3);
	
	// Copy background palettes.
	copyBgPalette16((const pu16)PALETTE_DEFAULT, 0);
	copyBgPalette16((const pu16)PALETTE_DEFAULT2, 1);
	copyBgPalette16((const pu16)PALETTE_GREYSCALE, 2);
	copyBgPalette16((const pu16)PALETTE_MONO, 3);
	
	// Copy tile data:
	// Copy object tile data.
	copySpriteData((const pu8)SPRITE_CURSOR, 0);
	
	return ERR_SUCCESS;
	
}

// Read and process user's key input.
void doKeyInput () {
	
	static u16 uKeyState;
	static Point2D8 xyDelta;
	
	// Read key register
	uKeyState = (REG_KEYINPUT & KEY_MASK);
	
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
	
	moveSprite(&s_pSprite[0], xyDelta.x, xyDelta.y);
	
}

// Waits for VSync.
void waitForVSync () {
	
	while(!(REG_DISPSTAT & VBLANK));
	while(REG_VCOUNT != SCREEN_HEIGHT);
	
}

// EOF
