//
// inc/point2d.h
//
// 2D Point Structures
//

#ifndef POINT2D_HEAD
#define POINT2D_HEAD

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

#endif

// EOF
