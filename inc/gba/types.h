/*
 * inc/gba/types.h
 * 
 * GBA Hardware Definition Headers - Type Definitions Header
 * 
 * Copyright 2020-2021 ASDj Dev Team
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

// Define color specifier types:
typedef unsigned short COLORSPEC;
typedef unsigned short* PCOLORSPEC;

// Define structures:
// RGB color buffer:
typedef struct tagRGB_COLOR
{
	u8 uRed;
	u8 uGreen;
	u8 uBlue;
} RGB_COLOR, *PRGB_COLOR;

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
