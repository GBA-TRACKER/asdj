//
// obj/bgctl.c
//
// Background Control Module.
//

#include "../inc/obj/bgctl.h"

void copyBgPalette (pu16 pbgPalette) {
	
	/*u16 iPalette;
	for (iPalette = 0; iPalette < 256; iPalette++) {
		BG_PalMem[iPalette] = pbgPalette[iPalette];
	}*/
	memcpy(BG_PalMem, pbgPalette, 512);
	
}

void copyBackground (pu16 pbgData) {
	
	/*u16 uLoop;
	for (uLoop = 0; uLoop < (120 * SCREEN_HEIGHT); uLoop++) {
		FrontBuff[uLoop] = pbgData[uLoop];
	}*/
	memcpy(VRAM, pbgData, (120 * SCREEN_HEIGHT) * 2);
	
}

// EOF
