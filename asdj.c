//
// asdj.c
//

#include "inc/gba/gba.h"
#include "inc/point2d.h"
#include <string.h>

void copyBgPalette (unsigned short* pbgPalette);
void copyBackground (unsigned short* pbgData);

void moveSprite (pOAMEntry pSprite, int x, int y);
void hideAllSprites (pOAMEntry pSprite);
void copySpritesToOAM (pOAMEntry pSprite);

OAMEntry g_pSprite[C_SPRITES];

int main() {
	
	// Init. code:
	hideAllSprites(g_pSprite);
	setVideoMode(MODE_4 | BG2_ENABLE | OBJ_ENABLE | OBJ_MAP_1D);
	
	// Main loop code:
	while(1) {
		waitForVSync();
		copySpritesToOAM(g_pSprite);
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

void moveSprite (pOAMEntry pSprite, int x, int y) {
	
	// Nullify current position.
	pSprite->uAttr1 = pSprite->uAttr1 & ATR1_MASK;
	pSprite->uAttr0 = pSprite->uAttr0 & ATR0_MASK;
	
	// Move sprite X position; protecting attribute 1 flags.
	pSprite->uAttr1 = pSprite->uAttr1 | ((!ATR1_MASK) & x);
	
	// Move sprite Y position; protecting attribute 0 flags.
	pSprite->uAttr0 = pSprite->uAttr0 | ((!ATR0_MASK) & y);
	
}

UPoint2D8 getSpritePos (pOAMEntry pSprite) {
	
	UPoint2D8 upnt;
	upnt.x = pSprite->uAttr1 & (!ATR1_MASK);
	upnt.y = pSprite->uAttr0 & (!ATR0_MASK);
	return upnt;
	
}

void hideAllSprites (pOAMEntry pSprite) {
	
	unsigned short iSprite;
	
	for (iSprite = 0; iSprite < C_SPRITES; iSprite++) {
		moveSprite(&pSprite[iSprite], SCREEN_WIDTH, SCREEN_HEIGHT);
	}
	
}

void copySpritesToOAM (pOAMEntry pSprite) {
	
	unsigned short iSprite;
	
	// Clear OAM if sprite pointer is null.
	if (!(pSprite)) {
		/*for (iSprite = 0; iSprite < C_SPRITES*4; iSprite++) {
			OAM_Memory[iSprite] = 0;
		}*/
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

