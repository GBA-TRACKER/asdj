//
// obj/bgctl.c
//
// Background Control Module.
//

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
