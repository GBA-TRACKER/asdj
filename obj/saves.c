//
// obj/saves.c
//
//
//

// Include module header:
#include "../inc/obj/saves.h"

// Include used C headers:
//#include <stdlib.h>
#include <malloc.h>

const char SAVE_ID_STR[8] = "ASDjSav\0";

u16 loadSongHeader (PSONG_HDR pSong) {
	
	if !pSong return ERR_NULLPTR;
	
	// TODO: Load ID string from save RAM.
	
	// Load song metadata.
	
	
	return ERR_SUCCESS;
	
}

u16 loadSaveHeader (PSAVE_HDR pSave) {
	
	if !pSave return ERR_NULLPTR;
	
	// TODO: Load ID string from save RAM.
	
	// Check ID string.
	if (pSave->szId != SAVE_ID_STR) return ERR_BADSAVE;
	
	// TODO: Load song count from save RAM.
	
	// Verify song count.
	if !pSave->cSongs return ERR_NODATA;
	if (pSave->cSongs > C_MAX_SONG) return ERR_BADSAVE;
	
	// Allocate space for songs.
	pSave->pSong = calloc(pSave->cSongs, sizeof(SONG_HDR));
	if !pSave->pSong return ERR_OUTOFMEMORY;
	
	// TODO: Load song headers.
	u8 iSong;
	for (iSong = 0; iSong < pSave-cSongs; iSong++) {
		// TODO: Load each song header.
		loadSongHeader(pSave->pSong);
	}
	
	return ERR_SUCCESS;
	
}

// EOF
