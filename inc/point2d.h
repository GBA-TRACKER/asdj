/*
 * point2d.h
 * 
 * Advanced Sound Dj - 2D Point Structures
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
 * 
 */

#ifndef _POINT2D_H_
#define _POINT2D_H_

#include "gba/types.h"

// 8-bit signed point.
typedef struct tagPoint2D8
{
	s8 x;
	s8 y;
} Point2D8, *pPoint2D8;

// 8-bit unsigned point.
typedef struct tagUPoint2D8
{
	u8 x;
	u8 y;
} UPoint2D8, *pUPoint2D8;

// 16-bit signed point.
typedef struct tagPoint2D16
{
	s16 x;
	s16 y;
} Point2D16, *pPoint2D16;

// 16-bit unsigned point.
typedef struct tagUPoint2D16
{
	u16 x;
	u16 y;
} UPoint2D16, *pUPoint2D16;

// 32-bit signed point.
typedef struct tagPoint2D32
{
	s32 x;
	s32 y;
} Point2D32, *pPoint2D32;

// 32-bit unsigned point.
typedef struct tagUPoint2D32
{
	u32 x;
	u32 y;
} UPoint2D32, *pUPoint2D32;

#endif /* _POINT2D_H_ */

// EOF
