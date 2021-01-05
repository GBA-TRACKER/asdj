//
// asdj.c
//
// Advanced Sound Dj - Main Module
//

#include "asdj.h"

// Shared module level variables:
OAMEntry s_pSprite[C_SPRITES]; // Temporary buffer for all sprites.

// Main routine:
int main () {
	
	// Initialization code:
	// Clear sprites in memory.
	memset(s_pSprite, 0, (C_SPRITES * sizeof(OAMEntry)));
	
	// Set video mode.
	setVideoMode(MODE_4 | BG2_ENABLE | OBJ_ENABLE | OBJ_MAP_1D);
	
	// Hide all sprites from view.
	hideAllSprites(s_pSprite);
	
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
