//
// inc/gba/regs/sound.h
//
// GBA Sound Register Definitions.
//

#ifndef GBA_HEAD_REGS_SOUND
#define GBA_HEAD_REGS_SOUND

#include "../types.h"

// APU channel 1 registers:
#define REG_SOUND1CNT_L *(pu16) 0x04000060 // Sweep.
#define REG_SOUND1CNT_H *(pu16) 0x04000062 // Duty cycle, length, envelope.
#define REG_SOUND1CNT_X *(pu16) 0x04000064 // Frequency & control.

// APU channel 2 registers:
#define REG_SOUND2CNT_L *(pu16) 0x04000086 // Duty cycle, length, envelope.
#define REG_SOUND2CNT_H *(pu16) 0x0400008C // Frequency & control.

// APU channel 3 registers:
#define REG_SOUND3CNT_L *(pu16) 0x04000070 // Wave select & stop.
#define REG_SOUND3CNT_H *(pu16) 0x04000072 // Volume & length.
#define REG_SOUND3CNT_X *(pu16) 0x04000074 // Frequency & control.

// APU channel 4 registers:
#define REG_SOUND4CNT_L *(pu16) 0x04000078 // Length & envelope.
#define REG_SOUND4CNT_H *(pu16) 0x0400007C // Frequency & control.

#define REG_SOUNDCNT_L *(pu16) 0x04000080 // Sound control L (Legacy).
#define REG_SOUNDCNT_H *(pu16) 0x04000082 // Sound control H (GBA).
#define REG_SOUNDCNT_X *(pu16) 0x04000084 // Sound control X.

#define REG_SOUNDBIAS *(volatile pu16) 0x04000088 // PWM control.

#define WAVE_RAM ((pu8) 0x04000090) // Channel 3 wave RAM (2*10h).

#define REG_FIFO_A *(pu32) 0x040000A0 // FIFO A.
#define REG_FIFO_B *(pu32) 0x040000A4 // FIFO B.

#endif

// EOF
