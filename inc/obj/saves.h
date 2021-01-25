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
 */

#ifndef _SAVES_H_
#define _SAVES_H_

#include "../gba/gba.h"

#define CCH_MAX_DESC 442
#define C_MAX_SONG 32

extern const u16 g_saves_cchMaxDesc;
extern const u8 g_saves_cMaxSong;

// Save system header ID.
// This mostly exists as an internal security/durability feature.
typedef struct tagSAVE_HDRID
{
	char szId[9]; // Header identifier string.
	u8 uHdrVer; // Header version code.
} SAVE_HDRID, *PSAVE_HDRID;

#define SAMPF_LOOP 0x0001
#define SAMPF_MASK 0x0001

typedef struct tagSAMPLE_HDR
{
	SAVE_HDRID hdrId; // ID string is "ASDjSamp\0". This is header v0x00.
	u16 uFlags; // Contains flags about the sample content.
	s8 sTranspose; // Transpose sample up and down.
	u32 iLoopStart; // Sample index of loop start (ignored if !(uFlags & SAMPF_LOOP)).
	u32 iLoopEnd; // Sample index of loop end (ignored if !(uFlags & SAMPF_LOOP)).
	u32 cSamples; // Contains total count of samples (aka sample length).
	pu8 pSamples; // Array of samples.
} SAMPLE_HDR, *PSAMPLE_HDR;


// Pattern header.
typedef struct tagPATTERN_HDR
{
	void* pPlaceholder; // Temporary placeholder.
} PATTERN_HDR, *PPATTERN_HDR;


// Song metadata.
typedef struct tagSONG_META
{
	SAVE_HDRID hdrId; // ID string is "SongMeta\0". This is header v0x00.
	char szName[32]; // 32-char buffer for song name.
	char szAuth[32]; // 32-char buffer for author name.
	u16 uYear; // 16-bit binary year.
	u16 cchDesc; // Length of pszDesc in chars.
	char* pszDesc; // Pointer to buffer for description.
} SONG_META, *PSONG_META;


// Song header.
typedef struct tagSONG_HDR
{
	SAVE_HDRID hdrId; // ID string is "ASDjSong\0". This is header v0x00.
	SONG_META meta; // Pointer to metadata structure.
	u16 cPatterns; // Count of patterns in pPattern.
	PPATTERN_HDR pPattern; // Array of patterns.
} SONG_HDR, *PSONG_HDR;

// Save header.
typedef struct tagSAVE_HDR
{
	SAVE_HDRID hdrId; // ID string is "ASDjSave\0". This is header v 0x00.
	u8 cSongs; // Count of saved songs.
	PSONG_HDR pSong; // Pointer to song headers.
} SAVE_HDR, *PSAVE_HDR;

#endif /* _SAVES_H_ */

// EOF
