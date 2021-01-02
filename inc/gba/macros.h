//
// inc/gba/macros.h
//
// Preprocessor Macros.
//

#ifndef GBA_HEAD_MACRO
#define GBA_HEAD_MACRO

#include "types.h"
#include "regs/video.h"
#include "regs/keys.h"
#include "flags/video.h"

#define waitForVSync() while(REG_VCOUNT != SCREEN_HEIGHT)
#define setVideoMode(mode) REG_DISPCNT = (mode)
#define keyDown(key) (~REG_KEYINPUT & key)
#define RGB(r, g, b) (u16)(r | (g << 5) | (b << 10))

#endif

// EOF
