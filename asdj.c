//
// asdj.c
//
// Advanced Sound Dj - Main Module
//

#include "asdj.h"

// Default 16-color sprite palette.
const u16 SPRITE_PALETTE[16] = {
	0x7FFF, 0x0000, 0x0010, 0x0200, 0x7FFF, 0x4210, 0x001F, 0x03E0,
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

// Shared module level variables:
OAM_ENTRY s_pSprite[C_SPRITES]; // Temporary buffer for all sprites.

// Main routine:
int main () {
	
	// Initialization code:
	// Clear sprites in memory.
	memset(s_pSprite, 0, (C_SPRITES * sizeof(OAM_ENTRY)));
	
	// Set video mode.
	setVideoMode(MODE_0 | OBJ_ENABLE | OBJ_MAP_1D);
	
	// Hide all sprites from view.
	hideAllSprites(s_pSprite);
	
	// Initialize sprite palette.
	copyObjPalette((const pu16)SPRITE_PALETTE, 0);
	
	u8 iSprData;
	for (iSprData = 0; iSprData < 32; iSprData++) {
		OAM_Data[iSprData] = SPRITE_CURSOR[iSprData];
	}
	
	// Main loop code:
	while(1) {
		
		// Wait for a frame to be drawn.
		waitForVSync();
		
		// Copy the temporary sprite buffer to OAM.
		copySpritesToOAM(s_pSprite);
	}
	
	return EXIT_SUCCESS;
	
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
