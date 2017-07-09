//===========================================================================
// strings.c
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

#include "mon_global.h"
#include "mon_type.h"


PUBLIC 	void strcpy_1(s8 *dest, s8 *src, s32 len)
{
	s32 i;

	for(i=0; i<len; i++)
	{
		*dest++ = *src++;
	}	
}

PUBLIC 	void 	strcpy_2(s8 *dest, s8 *src)
{
	while(*src != NULL)
	{
		*dest = *src;
		dest++;
		src++;
	}
}

PUBLIC 	void 	strcpy_3(s8 *dest, s8 *src)
{
	while(*src != NULL)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest	= NULL;
}

PUBLIC 	s8 strcmp_1(char *dest, char *src)
{
	s32	lend = strlen(dest);
	s32	lens = strlen(src);

	if(lend != lens)
	{
		return FALSE;
	}

	for(; lend > 0; lend--)
	{
		if(*dest++ != *src++)
		{
			break;
		}		
	}

	if(lend == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

PUBLIC 	void itoa(s32 value,s8 *str,s32 radix) //将整型装换成字符型
{
    	s8 temp[2]=" ";

	if (value!=0)
	{
		 itoa((value/radix) , str , radix);

		 temp[0]	= (s8)((value%radix)+'0');

		 strcat(str,temp);
	}
}

PUBLIC 	void replace_ch(s8 *dest,s8 s_ch, s8 d_ch)
{
	while(*dest != NULL)
	{
		if(*dest == s_ch)
		{
			*dest	= d_ch;
		}
		
		dest++;
	}
}
