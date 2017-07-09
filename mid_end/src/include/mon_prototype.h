//===========================================================================
// mon_prototype.h
//
//   Copyright (C) 2016 Free Software Foundation, Inc.
//   Originally by ZhaoFeng Liang <zhf.liang@hotmail.com>
//
//This file is part of DTHAS_ALS.
//
//DTHAS_ALS is free software; you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation; either version 2 of the License, or 
//(at your option) any later version.
//
//DTHAS_ALS is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with DTHAS_ALS; If not, see <http://www.gnu.org/licenses/>.  
//===========================================================================

#ifndef	_MON_PROTOTYPE_H_
#define	_MON_PROTOTYPE_H_

//main.c
PUBLIC	s32 main(s32 argc,s8 *argv[]);


//strings.c
PUBLIC 	void strcpy_1(s8 *dest, s8 *src, s32 len);
PUBLIC 	void strcpy_2(s8 *dest, s8 *src);
PUBLIC 	void 	strcpy_3(s8 *dest, s8 *src);
PUBLIC 	s8 strcmp_1(char *dest, char *src);
PUBLIC 	void itoa(s32 value,s8 *str,s32 radix);

//lib.c


#endif
