//
// obj/oamctl.c
//
// OAM/Sprite Control Module.
//

// Include module header:
#include "../inc/obj/oamctl.h"

// Include used C headers:
#include <string.h>

// Move a sprite relative to its current position.
// Returns the new position.
UPoint2D8 moveSprite (POAM_ENTRY pSprite, s8 x, s8 y) {
	
	// Get current sprite position.
	UPoint2D8 uxyPos = getSpritePos(pSprite);
	
	// Offset by new values.
	uxyPos.x += x;
	uxyPos.y += y;
	
	// Set new position.
	setSpritePos(pSprite, uxyPos.x, uxyPos.y);
	
	// Return the updated position.
	return uxyPos;
	
}

// Set a sprite's position absolutely.
void setSpritePos (POAM_ENTRY pSprite, u8 x, u8 y) {
	
	// Nullify current position.
	pSprite->uAttr1 = pSprite->uAttr1 & ATR1_MASK;
	pSprite->uAttr0 = pSprite->uAttr0 & ATR0_MASK;
	
	// Move sprite X position; protecting attribute 1 flags.
	pSprite->uAttr1 = pSprite->uAttr1 | ((!ATR1_MASK) & x);
	
	// Move sprite Y position; protecting attribute 0 flags.
	pSprite->uAttr0 = pSprite->uAttr0 | ((!ATR0_MASK) & y);
	
}

// Get a sprite's position.
UPoint2D8 getSpritePos (const POAM_ENTRY pSprite) {
	
	UPoint2D8 uxyPos = {
		pSprite->uAttr1 & (!ATR1_MASK),
		pSprite->uAttr0 & (!ATR0_MASK)
	};
	// uxyPos.x = pSprite->uAttr1 & (!ATR1_MASK);
	// uxyPos.y = pSprite->uAttr0 & (!ATR0_MASK);
	return uxyPos;
	
}

// Move all sprites offscreen.
void hideAllSprites (POAM_ENTRY pSprite) {
	
	u16 iSprite;
	
	for (iSprite = 0; iSprite < C_SPRITES; iSprite++) {
		setSpritePos(&pSprite[iSprite], SCREEN_WIDTH, SCREEN_HEIGHT);
	}
	
}

// Copy all sprites from pSprite to OAM.
void copySpritesToOAM (const POAM_ENTRY pSprite) {
	
	// Clear OAM if sprite pointer is null.
	if (pSprite == NULL) {
		memset(OAM_Memory, 0, CB_OAM);
	} else {
		
		// Create temporary pointer to sprite data.
		pu16 pSpriteTemp = (pu16)pSprite;
		
		u16 iSprite;
		
		// Copy sprite data to OAM.
		for (iSprite = 0; iSprite < C_SPRITES*4; iSprite++) {
			OAM_Memory[iSprite] = pSpriteTemp[iSprite];
		}
	}
	
}

// Copies a sixteen color sprite palette to a given subpalette index.
void copyObjPalette (const pu16 pPalette, const u8 iIndex) {
	
	
	if (pPalette == NULL) {
		memset(&OBJ_PalMem[iIndex * CB_OBJPAL], 0, CB_OBJPAL);
	} else {
		
		/* u16 iEntry;
		for (iEntry = 0; iEntry < 16; iEntry++) {
			OBJ_PalMem[iIndex + iEntry] = pPalette[iEntry];
		} */
		memcpy(&OBJ_PalMem[iIndex * CB_OBJPAL], pPalette, CB_OBJPAL);
	
	}
	
}

// EOF
