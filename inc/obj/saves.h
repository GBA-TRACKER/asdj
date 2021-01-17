/*
 * inc/obj/saves.h
 * 
 * Advanced Sound Dj - Saves Module Header
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
 * 
 */

#ifndef _SAVES_H_
#define _SAVES_H_

#include "gba/gba.h"

#define CCH_MAX_DESC 442
#define C_MAX_SONG 32

typedef struct tagPATTERN_HDR
{
	u8 uPlaceholder; // Temporary placeholder.
} PATTERN_HDR, *PPATTERN_HDR;

typedef struct tagSONG_META
{
	char szName[32]; // 32-char buffer for song name.
	char szAuth[32]; // 32-char buffer for author name.
	u16 uYear; // 16-bit binary year.
	u16 cchDesc; // Length of pszDesc in chars.
	char* pszDesc; // Pointer to buffer for description.
} SONG_META, *PSONG_META;

typedef struct tagSONG_HDR
{
	char strId[8]; // String identifier containing "ASDjSong".
	SONG_META meta; // Pointer to metadata structure.
	u16 cPatterns; // Count of patterns in pPattern.
	PPATTERN_HDR pPattern; // Array of patterns.
} SONG_HDR, *PSONG_HDR;

typedef struct tagSAVE_HDR
{
	char strId[8]; // String identifier containing "ASDjSave".
	u8 cSongs; // Count of saved songs.
	PSONG_HDR pSong; // Pointer to song headers.
} SAVE_HDR, *PSAVE_HDR;

#endif /* _SAVES_H_ */

// EOF
