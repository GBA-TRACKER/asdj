/*
 * obj/oamctl.c
 * 
 * Advanced Sound Dj - OAM/Sprite Control Module.
 * 
 * Copyright 2020-2021 ASDj Dev Team
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

// Include module header:
#include "../inc/obj/oamctl.h"

// Include used C headers:
#include <string.h>

const u16 g_cSprites = 128;
const u16 g_cObjTiles = 1024;

// Move a sprite relative to its current position.
// Returns the new position.
UPoint2D8 moveSprite (POAM_ENTRY pSprite, const s8 x, const s8 y) {
	
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
void setSpritePos (POAM_ENTRY pSprite, const u8 x, const u8 y) {
	
	// Nullify current position.
	pSprite->uAttr1 &= ATR1_MASK;
	pSprite->uAttr0 &= ATR0_MASK;
	
	// Move sprite X position; protecting attribute 1 flags.
	pSprite->uAttr1 = pSprite->uAttr1 | (~ATR1_MASK & x);
	
	// Move sprite Y position; protecting attribute 0 flags.
	pSprite->uAttr0 = pSprite->uAttr0 | (~ATR0_MASK & y);
	
}

// Get a sprite's position.
UPoint2D8 getSpritePos (const POAM_ENTRY pSprite) {
	
	// Mask off the X & Y position bits from attributes 0 & 1.
	UPoint2D8 uxyPos = {
		pSprite->uAttr1 & ~ATR1_MASK,
		pSprite->uAttr0 & ~ATR0_MASK
	};
	return uxyPos;
	
}

// Copy attributes to a specific entry in OAM.
void copyAttrToOAM (const POAM_ENTRY pSprite, const u8 iIndex) {
	
	if (iIndex >= g_cSprites) return;
	
	if (pSprite == NULL) {
		memset(&OAM_Memory[iIndex * 4], 0, sizeof(OAM_ENTRY));
	} else {
		memcpy(&OAM_Memory[iIndex * 4], pSprite, sizeof(OAM_ENTRY));
	}
	
}

// Copy all sprites from pSprite to OAM.
void copySpritesToOAM (const POAM_ENTRY pSprite) {
	
	// Clear OAM if sprite pointer is null.
	if (pSprite == NULL) {
		memset(OAM_Memory, 0, (g_cSprites * sizeof(OAM_ENTRY)));
	} else {
		u8 iSprite;
		for (iSprite = 0; iSprite < g_cSprites; iSprite++)
			copyAttrToOAM(&pSprite[iSprite], iSprite);
	}
	
}

// Copy object tile data to a given tile index.
void copySpriteData (const pu8 pData, const u8 iIndex) {
	
	if (iIndex >= g_cObjTiles) return;
	
	if (pData == NULL) {
		memset(&OAM_Data[iIndex * 32], 0, 32);
	} else {
		memcpy(&OAM_Data[iIndex * 32], pData, 32);
	}
	
}

// EOF
