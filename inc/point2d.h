//
// inc/point2d.h
//
// 2D Point Structures
//

#ifndef POINT2D_HEAD
#define POINT2D_HEAD

#include "gba/types.h"

typedef struct tagPoint2D8
{
	s8 x;
	s8 y;
} Point2D8, *pPoint2D8;

typedef struct tagUPoint2D8
{
	u8 x;
	u8 y;
} UPoint2D8, *pUPoint2D8;

typedef struct tagPoint2D16
{
	s16 x;
	s16 y;
} Point2D16, *pPoint2D16;

typedef struct tagUPoint2D16
{
	u16 x;
	u16 y;
} UPoint2D16, *pUPoint2D16;

#endif

// EOF
