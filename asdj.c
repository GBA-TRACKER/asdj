//
// asdj.c
//
// Advanced Sound Dj - Main Module
//

#include "inc/gba/gba.h"
#include "inc/oamctl.h"

void copyBgPalette (unsigned short* pbgPalette);
void copyBackground (unsigned short* pbgData);

// Shared module level variables:
OAMEntry s_pSprite[C_SPRITES]; // Temporary buffer for all sprites.

int main() {
	
	// Init. code:
	hideAllSprites(s_pSprite);
	setVideoMode(MODE_4 | BG2_ENABLE | OBJ_ENABLE | OBJ_MAP_1D);
	
	// Main loop code:
	while(1) {
		
		// Wait for a frame to be drawn.
		waitForVSync();
		
		// Copy the temporary sprite buffer to OAM.
		copySpritesToOAM(s_pSprite);
	}
	
	return 0;
	
}

void waitTime (u32 length) {
	
	// Divide length into milliseconds and seconds.
	u32 nSec, nMs;
	nMs = length % 1000;
	nSec = (length - nMs) / 1000;
	
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

void copyBgPalette (pu16 pbgPalette) {
	
	//u16 iPalette;
	
	/*for (iPalette = 0; iPalette < 256; iPalette++) {
		BG_PalMem[iPalette] = pbgPalette[iPalette];
	}*/
	memcpy(BG_PalMem, pbgPalette, 512);
	
}

void copyBackground (pu16 pbgData) {
	
	//u16 uLoop;
	
	/*for (uLoop = 0; uLoop < (120 * SCREEN_HEIGHT); uLoop++) {
		FrontBuff[uLoop] = pbgData[uLoop];
	}*/
	memcpy(VRAM, pbgData, (120 * SCREEN_HEIGHT)*2);
	
}

// EOF
