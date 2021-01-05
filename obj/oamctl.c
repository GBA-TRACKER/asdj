//
// obj/oamctl.c
//
// OAM/Sprite Control Module.
//

#include "../inc/obj/oamctl.h"

// Move a sprite relative to its current position.
// Returns the new position.
UPoint2D8 moveSprite (pOAMEntry pSprite, s8 x, s8 y) {
	
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
void setSpritePos (pOAMEntry pSprite, u8 x, u8 y) {
	
	// Nullify current position.
	pSprite->uAttr1 = pSprite->uAttr1 & ATR1_MASK;
	pSprite->uAttr0 = pSprite->uAttr0 & ATR0_MASK;
	
	// Move sprite X position; protecting attribute 1 flags.
	pSprite->uAttr1 = pSprite->uAttr1 | ((!ATR1_MASK) & x);
	
	// Move sprite Y position; protecting attribute 0 flags.
	pSprite->uAttr0 = pSprite->uAttr0 | ((!ATR0_MASK) & y);
	
}

// Get a sprite's position.
UPoint2D8 getSpritePos (pOAMEntry pSprite) {
	
	UPoint2D8 uxyPos = {
		pSprite->uAttr1 & (!ATR1_MASK),
		pSprite->uAttr0 & (!ATR0_MASK)
	};
	// uxyPos.x = pSprite->uAttr1 & (!ATR1_MASK);
	// uxyPos.y = pSprite->uAttr0 & (!ATR0_MASK);
	return uxyPos;
	
}

// Move all sprites offscreen.
void hideAllSprites (pOAMEntry pSprite) {
	
	u16 iSprite;
	
	for (iSprite = 0; iSprite < C_SPRITES; iSprite++) {
		setSpritePos(&pSprite[iSprite], SCREEN_WIDTH, SCREEN_HEIGHT);
	}
	
}

// Copy all sprites from pSprite to OAM.
void copySpritesToOAM (pOAMEntry pSprite) {
	
	u16 iSprite;
	
	// Clear OAM if sprite pointer is null.
	if (!(pSprite)) {
		memset(OAM_Memory, 0, CB_OAM);
	} else {
		
		// Create temporary pointer to sprite data.
		pu16 pSpriteTemp = (pu16)pSprite;
		//pSpriteTemp = (pu16)pSprite;
		
		// Copy sprite data to OAM.
		for (iSprite = 0; iSprite < C_SPRITES*4; iSprite++) {
			OAM_Memory[iSprite] = pSpriteTemp[iSprite];
		}
	}
	
}

// EOF
