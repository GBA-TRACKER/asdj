//
// inc/gba/regs/dma.h
//
// GBA DMA Register Definitions.
//

#ifndef GBA_HEAD_REGS_DMA
#define GBA_HEAD_REGS_DMA

#include "../types.h"

// DMA 0 (write only):
#define REG_DMA0SAD *(pu32) 0x040000B0 // DMA 0 source address.
#define REG_DMA0DAD *(pu32) 0x040000B4 // DMA 0 destination address.
#define REG_DMA0CNT_L *(pu16) 0x040000B8 // DMA 0 word count.
#define REG_DMA0CNT_H *(pu16) 0x040000BA // DMA 0 control (read/write).

// DMA 1 (write only):
#define REG_DMA1SAD *(pu32) 0x040000BC // DMA 1 source address.
#define REG_DMA1DAD *(pu32) 0x040000C0 // DMA 1 destination address.
#define REG_DMA1CNT_L *(pu16) 0x040000C4 // DMA 1 word count.
#define REG_DMA1CNT_H *(pu16) 0x040000C6 // DMA 1 control (read/write).

// DMA 2 (write only):
#define REG_DMA2SAD *(pu32) 0x040000C8 // DMA 2 source address.
#define REG_DMA2DAD *(pu32) 0x040000CC // DMA 2 destination address.
#define REG_DMA2CNT_L *(pu16) 0x040000D0 // DMA 2 word count.
#define REG_DMA2CNT_H *(pu16) 0x040000D2 // DMA 2 control (read/write).

// DMA 3 (write only):
#define REG_DMA3SAD *(pu32) 0x040000D4 // DMA 3 source address.
#define REG_DMA3DAD *(pu32) 0x040000D8 // DMA 3 destination address.
#define REG_DMA3CNT_L *(pu16) 0x040000DC // DMA 3 word count.
#define REG_DMA3CNT_H *(pu16) 0x040000DE // DMA 3 control (read/write).

#endif /* GBA_HEAD_REGS_DMA */

// EOF
