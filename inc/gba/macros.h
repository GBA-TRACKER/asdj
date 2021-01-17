//
// inc/gba/macros.h
//
// GBA Preprocessor Macros.
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
//#define RGB(r, g, b) (u16)(((b << 10) | (g << 5) | r) & 0x7FFF)
#define RGB(r, g, b) (u16)(((b & 0x1F) << 10) | ((g & 0x1F) << 5) | (r & 0x1F))

#endif /* GBA_HEAD_MACRO */

// EOF
