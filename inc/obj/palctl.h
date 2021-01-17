//
// inc/obj/palctl.h
//
// Palette Control Module Header
//

#ifndef _PALCTL_H_
#define _PALCTL_H_

// Include GBA headers:
#include "../gba/gba.h"

// Declare external constants:
extern const u16 cPalEntries;
extern const u16 cbPalette;
extern const u16 cSubPal;
extern const u16 cbSubPal;

// Declare functions defined in module:
void copyObjPalette256 (const pu16 pPalette);
void copyBgPalette256 (const pu16 pPalette);
void copyObjPalette16 (const pu16 pPalette, const u8 iIndex);
void copyBgPalette16 (const pu16 pPalette, const u8 iIndex);

#endif /* _PALCTL_H_ */

// EOF
