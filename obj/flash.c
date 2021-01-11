//
// obj/flash.c
//
// Flash Memory I/O Control Module
//

// Include module header:
#include "../inc/obj/flash.h"

// Include used C headers:
#include <string.h>

FLASH_INFO g_fiFlashInfo;

void flashSendCmd (const u8 uCmd) {
	
	flashAddr(0x5555) = 0xAA;
	flashAddr(0x2AAA) = 0x55;
	flashAddr(0x5555) = uCmd;
	
}

PFLASH_INFO flashGetType () {
	
	// Set 8 clk waitstate.
	REG_WAITCNT |= 0x3;
	
	// Enter ID mode.
	flashSendCmd(FLCMD_IDMODE);
	
	// Get device and manufacturer ID.
	g_fiFlashInfo.uDevId = flashAddr(0x0001);
	g_fiFlashInfo.uManId = flashAddr(0x0000);
	
	// Exit ID mode.
	flashSendCmd(FLCMD_IDEXIT);
	
	// Fill out the rest of the chip information.
	u16 uChipId = (u16)(g_fiFlashInfo.uDevId << 8) | g_fiFlashInfo.uManId;
	if (uChipId > 0) {
		switch (uChipId) {
			case FLTYP_64K_SST:
				g_fiFlashInfo.uSize = FLSIZE_64K;
				g_fiFlashInfo.uWaitWrite = 3;
				g_fiFlashInfo.uWaitRead = 2;
				g_fiFlashInfo.uTimeWrite = 10;
				g_fiFlashInfo.uTimeEraseSect = 40;
				g_fiFlashInfo.uTimeEraseChip = 200;
				break;
			case FLTYP_64K_MACRONIX:
				g_fiFlashInfo.uSize = FLSIZE_64K;
				g_fiFlashInfo.uWaitWrite = 8;
				g_fiFlashInfo.uWaitRead = 3;
				g_fiFlashInfo.uTimeWrite = 10;
				g_fiFlashInfo.uTimeEraseSect = 2000;
				g_fiFlashInfo.uTimeEraseChip = 2000;
				break;
			case FLTYP_64K_PANASONIC:
				g_fiFlashInfo.uSize = FLSIZE_64K;
				g_fiFlashInfo.uWaitWrite = 4;
				g_fiFlashInfo.uWaitRead = 2;
				g_fiFlashInfo.uTimeWrite = 10;
				g_fiFlashInfo.uTimeEraseSect = 500;
				g_fiFlashInfo.uTimeEraseChip = 500;
				break;
			case FLTYP_64K_ATMEL:
				g_fiFlashInfo.uSize = FLSIZE_64K;
				g_fiFlashInfo.uWaitWrite = 8;
				g_fiFlashInfo.uWaitRead = 8;
				g_fiFlashInfo.uTimeWrite = 40;
				g_fiFlashInfo.uTimeEraseSect = 40;
				g_fiFlashInfo.uTimeEraseChip = 40;
				break;
			case FLTYP_128K_SANYO:
				g_fiFlashInfo.uSize = FLSIZE_128K;
				/* g_fiFlashInfo.uWaitWrite = 0;
				g_fiFlashInfo.uWaitRead = 0;
				g_fiFlashInfo.uTimeWrite = 0;
				g_fiFlashInfo.uTimeEraseSect = 0;
				g_fiFlashInfo.uTimeEraseChip = 0; */
				memset(&g_fiFlashInfo.uWaitWrite, 0, ((2 * sizeof(u8)) + (3 * sizeof(u16))));
				break;
			case FLTYP_128K_MACRONIX:
				g_fiFlashInfo.uSize = FLSIZE_128K;
				/* g_fiFlashInfo.uWaitWrite = 0;
				g_fiFlashInfo.uWaitRead = 0;
				g_fiFlashInfo.uTimeWrite = 0;
				g_fiFlashInfo.uTimeEraseSect = 0;
				g_fiFlashInfo.uTimeEraseChip = 0; */
				memset(&g_fiFlashInfo.uWaitWrite, 0, ((2 * sizeof(u8)) + (3 * sizeof(u16))));
				break;
			default:
				
				// Clear the flash info table if chip type is unrecognized.
				memset(&g_fiFlashInfo, 0xFF, sizeof(FLASH_INFO));
				break;
		}
	} else {
		
		// Clear the flash info table if no chip is found.
		memset(&g_fiFlashInfo, 0, sizeof(FLASH_INFO));
	}
	
	// Return a pointer to the flash info table.
	return &g_fiFlashInfo;
	
}

void flashEraseChip () {
	
	// Issue erase command, and then "entire chip" command.
	flashSendCmd(FLCMD_ERASE);
	flashSendCmd(0x10);
	
	// Wait for chip to be erased.
	while(flashAddr(0x0000) != 0xFF);
	
}

void flashErase4KSector (const u16 uSect) {
	
	// Atmel chips don't use 4KB sectors, so return immediately if the
	// chip is one.
	if (g_fiFlashInfo.uManId == FLMAN_ATMEL) return;
	
	// Mask off the upper 4 bits, as only these are valid sector offsets.
	u16 uTempSect = uSect & 0xF000;
	
	// Send erase command to desired sector.
	flashSendCmd(FLCMD_ERASE);
	flashAddr(0x5555) = 0xAA;
	flashAddr(0x2AAA) = 0x55;
	flashAddr(uTempSect) = 0x30;
	
	// Wait for erase to finish.
	while (flashAddr(uTempSect) != 0xFF);
	
}

void flashWriteByte (const u16 uAddr, const u8 uByte) {
	
	if (g_fiFlashInfo.uManId == FLMAN_ATMEL) return;
	
	// Perform write.
	flashSendCmd(FLCMD_WRITEBYTE);
	flashAddr(uAddr) = uByte;
	
	// Wait for write to finish.
	while (flashAddr(uAddr) != uByte);
	
}

void flashSwitchBank (const u8 uBank) {
	
	// 64K chips don't support bank switching, so return immediately if
	// this is a 64K chip.
	if (g_fiFlashInfo.uSize == FLSIZE_64K) return;
	
	// Send bank switch command.
	flashSendCmd(FLCMD_SWITCHBANK);
	flashAddr(0x0000) = (uBank & 0x01);
	
}

// EOF
