/*
 * obj/colctl.c
 * 
 * Advanced Sound Dj - Color Control Module
 * 
 * Copyright 2020-2021 ASDj Dev Team
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#include "../inc/obj/colctl.h"

COLORSPEC makeColSpec (const PRGB_COLOR pRgb) {
	
	if (pRgb == NULL) return 0;
	
	COLORSPEC csCol;
	
	csCol = (pRgb->uRed & 0x1F);
	csCol |= ((pRgb->uGreen & 0x1F) << 5);
	csCol |= ((pRgb->uBlue & 0x1F) << 10);
	
	return csCol;
	
}

RGB_COLOR makeRgbCol (const COLORSPEC csCol) {
	
	RGB_COLOR rgb = {
		(csCol & 0x001F),
		((csCol & 0x03E0) >> 5),
		((csCol & 0x7C00) >> 10)
	}
	
	return rgb;
	
}

// EOF
