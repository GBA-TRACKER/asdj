//
// inc/obj/flash.h
//
// Flash Memory I/O Control Module Header
//

#ifndef _FLASH_H_
#define _FLASH_H_

#include "../gba/gba.h"

// Define flash command IDs:
#define FLCMD_IDMODE 0x90
#define FLCMD_IDEXIT 0xF0
#define FLCMD_WRITEBYTE 0xA0
#define FLCMD_ERASE 0x80
#define FLCMD_SWITCHBANK 0xB0

// Define flash type IDs:
#define FLTYP_64K_SST 0xD4BF
#define FLTYP_64K_MACRONIX 0x1CC2
#define FLTYP_64K_PANASONIC 0x1B32
#define FLTYP_64K_ATMEL 0x3D1F
#define FLTYP_128K_SANYO 0x1362
#define FLTYP_128K_MACRONIX 0x09C2

#define FLMAN_SST 0xBF
#define FLMAN_MACRONIX 0xC2
#define FLMAN_PANASONIC 0x32
#define FLMAN_ATMEL 0x1F
#define FLMAN_SANYO 0x62

#define FLSIZE_64K 0x00
#define FLSIZE_128K 0x01

#define flashAddr(uAddr) *(pu8)(0x0E000000 | uAddr)

// Flash chip information.
// If device and manufacturer ID are 0, no chip was found.
// If wait counts are 0, assume 8.
// If timeouts are 0, assume they're unknown, and use manual checking.
typedef struct tagFLASH_INFO
{
	u8 uDevId; // Device ID.
	u8 uManId; // Manufacturer ID.
	u8 uSize; // Flash size (0=64K, >0=128K).
	u8 uWaitWrite; // Minimum write wait count in clock cycles.
	u8 uWaitRead; // Minimum read wait count in clock cycles.
	u16 uTimeWrite; // Timeout for write in ms.
	u16 uTimeEraseSect; // Timeout for erase sector in ms.
	u16 uTimeEraseChip; // Timeout for erase chip in ms.
} FLASH_INFO, *PFLASH_INFO;

void flashSendCmd (const u8 uCmd);

PFLASH_INFO flashGetType ();

void flashEraseChip ();
void flashWriteByte (const u16 uAddr, const u8 uByte);
void flashSwitchBank (const u8 uBank);

#endif /* _FLASH_H_ */

// EOF
