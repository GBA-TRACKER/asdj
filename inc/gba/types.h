//
// inc/gba/types.h
//
// GBA Type Definitions
//

#ifndef GBA_HEAD_TYPES
#define GBA_HEAD_TYPES

// Define unsigned integer types:
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

// Define signed integer types:
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

// Define unsigned integer pointer types:
typedef unsigned char* pu8;
typedef unsigned short* pu16;
typedef unsigned long* pu32;

// Define signed integer pointer types:
typedef signed char* ps8;
typedef signed short* ps16;
typedef signed long* ps32;

// Define structures:
// OAM Entry:
typedef struct tagOAM_ENTRY
{
	u16 uAttr0;
	u16 uAttr1;
	u16 uAttr2;
	u16 uAttr3;
} OAM_ENTRY, *POAM_ENTRY;

// Sprite rotation data:
typedef struct tagROT_DATA
{
	u16 uFiller1[3];
	u16 uPa;
	u16 uFiller2[3];
	u16 uPb;
	u16 uFiller3[3];
	u16 uPc;
	u16 uFiller4[3];
	u16 uPd;
} ROT_DATA, *PROT_DATA;

#endif /* GBA_HEAD_TYPES */

// EOF
