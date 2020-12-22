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

UPoint2D8 moveSprite (pOAMEntry pSprite, int x, int y);
void setSpritePos (pOAMEntry pSprite, int x, int y);
UPoint2D8 getSpritePos (pOAMEntry pSprite);
void hideAllSprites (pOAMEntry pSprite);
void copySpritesToOAM (pOAMEntry pSprite);

#endif

// EOF
