//
// inc/gba/flags/video.h
//
// GBA Video Flags
//

#ifndef GBA_HEAD_FLAGS_VIDEO
#define GBA_HEAD_FLAGS_VIDEO

// ---------------------------------------------------------------------
// Flags for REG_DISPCNT.
// ---------------------------------------------------------------------

// Screen modes:
#define MODE_0 0x0000 // Screen mode 0.
#define MODE_1 0x0001 // Screen mode 1.
#define MODE_2 0x0002 // Screen mode 2.
#define MODE_3 0x0003 // Screen mode 3.
#define MODE_4 0x0004 // Screen mode 4.
#define MODE_5 0x0005 // Screen mode 5.

#define CGB_MODE 0x0008 // Reserved for CGB mode; can only be used by BIOS.

//#define backbuffer 0x0010
#define FRAMESEL_FRONT 0x0000
#define FRAMESEL_BACK 0x0010

#define H_BLANK_OAM 0x0020 // Flag allowing OAM to be updated during H-blank.

#define OBJ_MAP_2D 0x0000 // Sprite data is 2 dimensional.
#define OBJ_MAP_1D 0x0040 // Sprite data is 1 dimensional.

#define FORCE_BLANK 0x0080 // Forced blanking, allows fast access to video memory.

// Layer enable flags:
#define BG0_ENABLE 0x0100 // Background 0.
#define BG1_ENABLE 0x0200 // Background 1.
#define BG2_ENABLE 0x0400 // Background 2.
#define BG3_ENABLE 0x0800 // Background 3.
#define OBJ_ENABLE 0x1000 // Sprite layer.

#define WIN0_ENABLE 0x2000 // Display window 0.
#define WIN1_ENABLE 0x4000 // Display window 1.
#define OBJWIN_ENABLE 0x8000 // Display object window.

// Flag masks:
#define VIDF_MODE_MASK 0x0007
#define VIDF_LAYER_MASK 0xFF00
#define VIDF_DISPCNT_MASK 0xFFF7

// ---------------------------------------------------------------------
// Flags for REG_DISPSTAT.
// ---------------------------------------------------------------------

// V-/H-Blank flags (read only):
#define VBLANK 0x00001 // Set in lines 160-226, but not 227.
#define HBLANK 0x00002 // Toggled in all lines, even in V-Blank.
#define VCOUNTER 0x0004 // Set only in selected line.

// IRQ enable flags:
#define VBLNKIRQ 0x0008 // V-Blank IRQ enable.
#define HBLNKIRQ 0x0010 // H-Blank IRQ enable.
#define VCOUNTIRQ 0x0020 // V-Counter IRQ enable.

#define LYC(setting) ((setting & 0xFF) << 8)

// ---------------------------------------------------------------------
// Flags for REG_VCOUNT.
// ---------------------------------------------------------------------

#define LY_MASK 0x00FF

// ---------------------------------------------------------------------
// Flags for REG_BGxCNT.
// ---------------------------------------------------------------------

#define BG_PRIORITY(pri) (u16)(pri & 0x0003)
#define BG_CHARBASE(base) (u16)((base & 0x0003) << 2)
#define BG_MOSAIC 0x0040
#define BG_256COL 0x0080
#define BG_SCREENBASE(base) (u16)((base & 0x001F) << 8)
#define BG_DISPAREAWRAP 0x2000
#define BG_SCREENSIZE(size) (u16)((size & 0x0003) << 14)
#define BG_MASK 0xFFCF

// ---------------------------------------------------------------------
// Flags for REG_BGxHOFS and REG_BGxVOFS.
// ---------------------------------------------------------------------

#define BG_OFFSET(ofs) (u16)(ofs & 0x01FF)

#endif /* GBA_HEAD_FLAGS_VIDEO */

// EOF

