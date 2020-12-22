//
// obj/oamctl.c
//
// OAM/Sprite Control Object.
//

#include "../inc/oamctl.h"

// Move a sprite relative to its current position.
// Returns the new position.
UPoint2D8 moveSprite (pOAMEntry pSprite, int x, int y) {
	
	UPoint2D8 upnt = getSpritePos(pSprite);
	
	upnt.x += x;
	upnt.y += y;
	
	setSpritePos(pSprite, upnt.x, upnt.y);
	
	return upnt;
	
}

// Set a sprite's position absolutely.
void setSpritePos (pOAMEntry pSprite, int x, int y) {
	
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
	
	UPoint2D8 upnt;
	upnt.x = pSprite->uAttr1 & (!ATR1_MASK);
	upnt.y = pSprite->uAttr0 & (!ATR0_MASK);
	return upnt;
	
}

// Move all sprites offscreen.
void hideAllSprites (pOAMEntry pSprite) {
	
	unsigned short iSprite;
	
	for (iSprite = 0; iSprite < C_SPRITES; iSprite++) {
		setSpritePos(&pSprite[iSprite], SCREEN_WIDTH, SCREEN_HEIGHT);
	}
	
}

// Copy all sprites from pSprite to OAM.
void copySpritesToOAM (pOAMEntry pSprite) {
	
	unsigned short iSprite;
	
	// Clear OAM if sprite pointer is null.
	if (!(pSprite)) {
		memset(OAM_Memory, 0, C_SPRITES*8);
	} else {
		
		// Create temporary pointer to sprite data.
		unsigned short* pSpriteTemp;
		pSpriteTemp = (unsigned short*)pSprite;
		
		// Copy sprite data to OAM.
		for (iSprite = 0; iSprite < C_SPRITES*4; iSprite++) {
			OAM_Memory[iSprite] = pSpriteTemp[iSprite];
		}
	}
	
}

// EOF
