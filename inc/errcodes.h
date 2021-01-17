/*
 * inc/errcodes.h
 * 
 * Advanced Sound Dj - ASDj Error Codes Header.
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

#ifndef _ASDJ_ERRCODES_H_
#define _ASDJ_ERRCODES_H_

typedef unsigned short int ERRORID;

enum ASDJ_ERROR {
	ERR_SUCCESS,
	ERR_OUTOFMEMORY,
	ERR_NULLPTR,
	ERR_BADINDEX,
	ERR_BADSAVE,
	ERR_NODATA
};

#endif /* _ASDJ_ERRCODES_H_ */

// EOF
