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

void copyBgPalette (unsigned short* pbgPalette) {
	
	unsigned short iPalette;
	
	for (iPalette = 0; iPalette < 256; iPalette++) {
		BG_PalMem[iPalette] = pbgPalette[iPalette];
	}
	
}

void copyBackground (unsigned short* pbgData) {
	
	unsigned short uLoop;
	
	for (uLoop = 0; uLoop < (120 * SCREEN_HEIGHT); uLoop++) {
		FrontBuff[uLoop] = pbgData[uLoop];
	}
	
}

// EOF
