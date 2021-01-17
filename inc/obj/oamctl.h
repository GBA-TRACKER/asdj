/*
 * inc/obj/oamctl.h
 * 
 * Advanced Sound Dj - OAM/Sprite Control Module Header.
 * 
 * Copyright 2020-2021 ASDJ Dev Team
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#ifndef _OAMCTL_H_
#define _OAMCTL_H_

// Include GBA headers:
#include "../gba/gba.h"

// 
#include "../point2d.h"

// Declare external constants:
extern const u16 g_cSprites;
extern const u16 g_cObjTiles;

// Declare functions defined in module:
UPoint2D8 moveSprite (POAM_ENTRY pSprite, const s8 x, const s8 y);
void setSpritePos (POAM_ENTRY pSprite, const u8 x, const u8 y);
UPoint2D8 getSpritePos (const POAM_ENTRY pSprite);

void copyAttrToOAM (const POAM_ENTRY pSprite, const u8 iIndex);
void copySpritesToOAM (const POAM_ENTRY pSprite);

void copySpriteData (const pu8 pData, const u8 iIndex);

#endif /* _OAMCTL_H_ */

// EOF
