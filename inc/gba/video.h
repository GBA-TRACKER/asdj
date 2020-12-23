//
// inc/gba/video.h
//
// GBA Video Flags
//

#ifndef GBA_HEAD_VIDEO
#define GBA_HEAD_VIDEO

// Screen resolution:
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160

// Screen modes:
#define MODE_0 0x0000 // Screen mode 0.
#define MODE_1 0x0001 // Screen mode 1.
#define MODE_2 0x0002 // Screen mode 2.
#define MODE_3 0x0003 // Screen mode 3.
#define MODE_4 0x0004 // Screen mode 4.
#define MODE_5 0x0005 // Screen mode 5.

#define backbuffer 0x0010

#define H_BLANK_OAM 0x0020 // Flag allowing OAM to be updated during H-blank.

#define OBJ_MAP_2D 0x0000 // Sprite data is 2 dimensional.
#define OBJ_MAP_1D 0x0040 // Sprite data is 1 dimensional.

// Layer enable flags:
#define BG0_ENABLE 0x0100 // Background 0.
#define BG1_ENABLE 0x0200 // Background 1.
#define BG2_ENABLE 0x0400 // Background 2.
#define BG3_ENABLE 0x0800 // Background 3.
#define OBJ_ENABLE 0x1000 // Sprite layer.

#define VIDF_MODE_MASK 0x0007
#define VIDF_LAYER_MASK 0x1F00
#define VIDF_MASK 0x1F77

#endif

// EOF

