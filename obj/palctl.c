//
// obj/palctl.c
//
// Palette Control Module
//

// Include module header:
#include "../inc/obj/palctl.h"

// Include used C headers:
#include <string.h>

const u16 cPalEntries = 256;
const u16 cbPalette = (cPalEntries * sizeof(u16));

const u16 cSubPal = 16;
const u16 cbSubPal = (cSubPal * sizeof(u16));

// Copies a 256-color object palette.
void copyObjPalette256 (const pu16 pPalette) {
	
	if (pPalette == NULL) {
		memset(OBJ_PalMem, 0, cbPalette);
	} else {
		memcpy(OBJ_PalMem, pPalette, cbPalette);
	}
	
}

// Copies a 256-color background palette.
void copyBgPalette256 (const pu16 pPalette) {
	
	if (pPalette == NULL) {
		memset(BG_PalMem, 0, cbPalette);
	} else {
		memcpy(BG_PalMem, pPalette, cbPalette);
	}
	
}

// Copies a sixteen color sprite palette to a given subpalette index.
void copyObjPalette16 (const pu16 pPalette, const u8 iIndex) {
	
	if (iIndex >= cSubPal) return;
	
	if (pPalette == NULL) {
		memset(&OBJ_PalMem[iIndex * cbSubPal], 0, cbSubPal);
	} else {
		memcpy(&OBJ_PalMem[iIndex * cbSubPal], pPalette, cbSubPal);
	}
	
}

// Copies a sixteen color background palette to a given subpalette index.
void copyBgPalette16 (const pu16 pPalette, const u8 iIndex) {
	
	if (iIndex >= cSubPal) return;
	
	if (pPalette == NULL) {
		memset(&BG_PalMem[iIndex * cbSubPal], 0, cbSubPal);
	} else {
		memcpy(&BG_PalMem[iIndex * cbSubPal], pPalette, cbSubPal);
	}
	
}

// EOF
