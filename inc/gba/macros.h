//
// inc/gba/macros.h
//
// Preprocessor Macros
//

#ifndef GBA_HEAD_MACRO
#define GBA_HEAD_MACRO

#include "regs.h"
#include "video.h"

#define waitForVSync() while(REG_VCOUNT != SCREEN_HEIGHT);
#define setVideoMode(mode) REG_DISPCNT = (mode)
#define keyDown(key) (~REG_KEYS & key)
#define RGB(r, g, b) (unsigned short)(r | (g << 5) | (b << 10))

#endif

// EOF
