//
// inc/obj/bgctl.h
//
// Background Control Module Header.
//

#ifndef _BGCTL_H_
#define _BGCTL_H_

// Include GBA headers:
#include "../gba/gba.h"

// Declare functions used in module:
void copyBgPalette (const pu16 pbgPalette);
void copyBackground (const pu16 pbgData);

#endif /* _BGCTL_H_ */

// EOF
