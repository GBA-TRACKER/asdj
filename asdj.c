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

/*
// Default 16-color palette.
const u16 DEFAULT_PALETTE[16] = {
	0x0000, 0x7FFF, 0x0010, 0x0200, 0x7FFF, 0x4210, 0x001F, 0x03E0,
	0x0210, 0x4000, 0x4010, 0x4200, 0x03FF, 0x7C00, 0x7C1F, 0x7FE0
};

// Placeholder cursor graphic.
const u8 SPRITE_CURSOR[32] = {
	0x00, 0x10, 0x01, 0x00,
	0x00, 0x00, 0x11, 0x00,
	0x00, 0x00, 0x10, 0x01,
	0x11, 0x11, 0x11, 0x11,
	0x11, 0x11, 0x11, 0x11,
	0x00, 0x00, 0x10, 0x01,
	0x00, 0x00, 0x11, 0x00,
	0x00, 0x10, 0x01, 0x00
};
*/

// Shared module level variables:
OAM_ENTRY s_pSprite[128]; // Temporary buffer for all sprites.

// Main routine:
int main () {
	
	// Initialization code:
	// Clear sprites in memory.
	memset(s_pSprite, 0, (cSprites * sizeof(OAM_ENTRY)));
	
	// Set video mode.
	setVideoMode(MODE_0 | BG0_ENABLE | OBJ_ENABLE | OBJ_MAP_1D);
	REG_BG0CNT = (BG_PRIORITY(3) | BG_CHARBASE(0) | BG_SCREENBASE(0) | BG_SCREENSIZE(0));
	
	// Hide all sprites from view.
	hideAllSprites(s_pSprite);
	
	// Initialize palettes.
	copyObjPalette16((const pu16)DEFAULT_PALETTE, 0);
	copyBgPalette16((const pu16)DEFAULT_PALETTE, 0);
	
	// Copy sprite data.
	//memcpy(OAM_Data, SPRITE_CURSOR, sizeof(SPRITE_CURSOR));
	copySpriteData((const pu8)SPRITE_CURSOR, 0);
	
	s_pSprite[0].uAttr0 = (ATR0_COLOR16 | ATR0_SQUARE);
	s_pSprite[0].uAttr1 = (ATR1_SIZE8);
	s_pSprite[0].uAttr2 = (ATR2_PRIORITY(0) | ATR2_PALETTE(0));
	
	// Main loop code:
	while(1) {
		
		// Wait for a frame to be drawn.
		waitForVSync();
		
		doKeyInput();
		
		// Copy the temporary sprite buffer to OAM.
		//copySpritesToOAM(s_pSprite);
		copyAttrToOAM(&s_pSprite[0], 0);
	}
	
	return EXIT_SUCCESS;
	
}

void doKeyInput () {
	
	static UPoint2D8 uxyCurPos;
	
	if keyDown(KEY_RIGHT) uxyCurPos.x += 1;
	if keyDown(KEY_LEFT) uxyCurPos.x -= 1;
	if keyDown(KEY_UP) uxyCurPos.y += 1;
	if keyDown(KEY_DOWN) uxyCurPos.y -= 1;
	
	if keyDown(KEY_A) {
		if (s_pSprite[0].uAttr1 & ATR1_HFLIP) {
			s_pSprite[0].uAttr1 &= ~ATR1_HFLIP;
		} else {
			s_pSprite[0].uAttr1 |= ATR1_HFLIP;
		}
	}
	
	//moveSprite(&s_pSprite[0], dX, dY);
	setSpritePos(&s_pSprite[0], uxyCurPos.x, uxyCurPos.y);
	
}

// Waits a specified length of time in milliseconds.
void waitTime (u32 length) {
	
	// Divide length into milliseconds and seconds.
	u32 nMs = length % 1000;
	u32 nSec = (length - nMs) / 1000;
	
	// Enable timers.
	// Timer 2 on every 256th cycle, and timer 3 when timer 2 overflows.
	REG_TM2CNT = (TIMF_ENABLE | TIMF_PRESCALE_256);
	REG_TM3CNT = (TIMF_ENABLE | TIMF_OVERFLOW);
	
	// Reset timer counts.
	REG_TM2D = REG_TM3D = 0;
	
	// Wait for nSec seconds.
	while(REG_TM3D < nSec);
	
	// Wait the remaining milliseconds.
	while(REG_TM2D < (65535 / 1000) * nMs);
	
	// Disable the timers.
	REG_TM2CNT = REG_TM3CNT = 0;
	
}

// EOF
