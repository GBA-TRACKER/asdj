/*
 * obj/data/palette.c
 * 
 * Advanced Sound Dj - Palette Data Module
 * 
 * Copyright 2020-2021 ASDJ Dev Team
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

#include "../../inc/obj/data/palette.h"

// Default/placeholder 16-color palette.
const u16 PALETTE_DEFAULT[16] __attribute__((aligned(4))) __attribute__((visibility("hidden"))) = {
	0x0000, 0x7FFF, 0x0010, 0x0200, 0x7FFF, 0x4210, 0x001F, 0x03E0,
	0x0210, 0x4000, 0x4010, 0x4200, 0x03FF, 0x7C00, 0x7C1F, 0x7FE0
};

// Second default 16-color palette.
const u16 PALETTE_DEFAULT2[16] __attribute__((aligned(4))) __attribute__((visibility("hidden"))) = {
	0x7FFF, 0x0000, 0x7FFF, 0x0C59, 0x0E04, 0x6D08, 0x0FDF, 0x6B64,
	0x56B5, 0x318C, 0x0D11, 0x5A9F, 0x4351, 0x7E93, 0x1E7F, 0x5CD1
};

// Greyscale 16-color palette.
const u16 PALETTE_GREYSCALE[16] __attribute__((aligned(4))) __attribute__((visibility("hidden"))) = {
	0x7FFF, 0x0000, 0x0842, 0x1084, 0x18C6, 0x2108, 0x294A, 0x318C,
	0x4210, 0x4E73, 0x56B5, 0x5EF7, 0x6739, 0x6F7B, 0x77BD, 0x7FFF
};

// Monochrome (black and white) palette.
const u16 PALETTE_MONO[16] __attribute__((aligned(4))) __attribute__((visibility("hidden"))) = {
	0x7FFF, 0x0000, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
	0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF
};

const u16 PALETTE_TEXT[16] __attribute__((aligned(4))) __attribute__((visibility("hidden"))) = {
	0x0000, 0x7FFF, 0x3DEF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

// EOF
