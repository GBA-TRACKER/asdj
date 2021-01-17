//
// inc/obj/saves.h
//
//
//

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

u16 loadSongHeader (PSONG_HDR pSong);
u16 loadSaveHeader (PSAVE_HDR pSave);

#endif /* _SAVES_H_ */

// EOF
