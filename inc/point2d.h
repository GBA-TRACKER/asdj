//
// inc/point2d.h
//
// 2D Point Structures
//

#ifndef POINT2D_HEAD
#define POINT2D_HEAD

typedef struct tagPoint2D8
{
	char x;
	char y;
} Point2D8, *pPoint2D8;

typedef struct tagUPoint2D8
{
	unsigned char x;
	unsigned char y;
} UPoint2D8, *pUPoint2D8;

typedef struct tagPoint2D16
{
	short x;
	short y;
} Point2D16, *pPoint2D16;

typedef struct tagUPoint2D16
{
	unsigned short x;
	unsigned short y;
} UPoint2D16, *pUPoint2D16;

#endif

// EOF
