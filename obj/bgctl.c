//
// obj/bgctl.c
//
// Background Control Module.
//

// Include module header:
#include "../inc/obj/bgctl.h"

// Include used C headers:
#include <string.h>

void copyBgPalette (const pu16 pbgPalette) {
	
	/*u16 iPalette;
	for (iPalette = 0; iPalette < 256; iPalette++) {
		BG_PalMem[iPalette] = pbgPalette[iPalette];
	}*/
	if (pbgPalette == NULL) {
		memset(BG_PalMem, 0, 512);
	} else {
		memcpy(BG_PalMem, pbgPalette, 512);
	}
	
}

void copyBackground (const pu16 pbgData) {
	
	/*u16 uLoop;
	for (uLoop = 0; uLoop < (120 * SCREEN_HEIGHT); uLoop++) {
		FrontBuff[uLoop] = pbgData[uLoop];
	}*/
	if (pbgData == NULL) {
		memset(VRAM, 0, (120 * SCREEN_HEIGHT) * 2);
	} else {
		memcpy(VRAM, pbgData, (120 * SCREEN_HEIGHT) * 2);
	}
	
}

// EOF
