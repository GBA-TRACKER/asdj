//
// inc/gba/flags/sys.h
//
// GBA Interrupt and System Flags.
//

#ifndef GBA_HEAD_FLAGS_SYS
#define GBA_HEAD_FLAGS_SYS

// Interrupt master enable flags:
#define IME_ENABLE 0x00000001

// Interrupt enable and interrupt request/acknowledge flags:
#define INT_VBLANK 0x0001 // LCD vertical blank int.
#define INT_HBLANK 0x0002 // LCD horizontal blank int.
#define INT_VCOUNT 0x0004 // LCD vertical count interrupt.
#define INT_TM0OF 0x0008 // Timer 0 overflow.
#define INT_TM1OF 0x0010 // Timer 1 overflow.
#define INT_TM2OF 0x0020 // Timer 2 overflow.
#define INT_TM3OF 0x0040 // Timer 3 overflow.
#define INT_SERIAL 0x0080 // Serial comm.
#define INT_DMA0 0x0100 // DMA 0.
#define INT_DMA1 0x0200 // DMA 1.
#define INT_DMA2 0x0400 // DMA 2.
#define INT_DMA3 0x0800 // DMA 3.
#define INT_KEYPAD 0x1000 // Keypad.
#define INT_GAMEPAK 0x2000 // Game pak/external INTQ.

#define INT_MASK 0x3FFF



#endif /* GBA_HEAD_FLAGS_SYS */

// EOF
