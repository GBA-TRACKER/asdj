//
// inc/oamctl.h
//
// OAM/Sprite Control Functions.
//

#ifndef _OAMCTL_H_
#define _OAMCTL_H_

#include "gba/gba.h"
#include "point2d.h"
#include <string.h>

pUPoint2D8 moveSprite (pOAMEntry pSprite, s8 x, s8 y);
void setSpritePos (pOAMEntry pSprite, u8 x, u8 y);
pUPoint2D8 getSpritePos (pOAMEntry pSprite);
void hideAllSprites (pOAMEntry pSprite);
void copySpritesToOAM (pOAMEntry pSprite);

#endif

// EOF
