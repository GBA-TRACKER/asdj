//
// inc/obj/oamctl.h
//
// OAM/Sprite Control Module Header.
//

#ifndef _OAMCTL_H_
#define _OAMCTL_H_

// Include GBA headers:
#include "../gba/gba.h"

// 
#include "../point2d.h"

// Declare external constants:
extern const u16 cSprites;

// Declare functions defined in module:
UPoint2D8 moveSprite (POAM_ENTRY pSprite, const s8 x, const s8 y);
void setSpritePos (POAM_ENTRY pSprite, const u8 x, const u8 y);
UPoint2D8 getSpritePos (const POAM_ENTRY pSprite);
void hideAllSprites (POAM_ENTRY pSprite);

void copyAttrToOAM (const POAM_ENTRY pSprite, const u8 iIndex);
void copySpritesToOAM (const POAM_ENTRY pSprite);

// void copyObjPalette (const pu16 pPalette, const u8 iIndex);

#endif /* _OAMCTL_H_ */

// EOF
