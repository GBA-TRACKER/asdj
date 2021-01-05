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

// Declare functions used in module:
UPoint2D8 moveSprite (POAM_ENTRY pSprite, s8 x, s8 y);
void setSpritePos (POAM_ENTRY pSprite, u8 x, u8 y);
UPoint2D8 getSpritePos (POAM_ENTRY pSprite);
void hideAllSprites (POAM_ENTRY pSprite);
void copySpritesToOAM (POAM_ENTRY pSprite);

#endif /* _OAMCTL_H_ */

// EOF
