//===========================================================================
// lib.c
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

#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "als_global.h"
#include "als_type.h"

//-------------------------------------------------------------------------
// 27/Jun/2017:12:07:42	==>	2017-06-27 12:07:42 
//-------------------------------------------------------------------------
PUBLIC 	void todatetime_1(s8 *dest, s32 dest_len, s8 *src)
{
	s32 i;
	s8 time_array[6][8];
	struct datetime_1 *dt;

	dt	= (struct datetime_1*)src;

	dt->ph1	= NULL;
	dt->ph2	= NULL;
	dt->ph3	= NULL;
	dt->ph4	= NULL;
	dt->ph5	= NULL;
	dt->ph6	= NULL;

	mon2num_1(dt->mon);

	memset(dest, NULL, dest_len);

	strcpy_3(dest, 	dt->year);

	strcat(dest,	"-");
	strcat(dest,	dt->mon);
	strcat(dest,	"-");
	strcat(dest,	dt->day);
	strcat(dest,	" ");
	strcat(dest,	dt->hour);
	strcat(dest,	":");
	strcat(dest,	dt->min);
	strcat(dest,	":");
	strcat(dest,	dt->sec);

	printf("todatetime_1(dest)::%s\n", dest);
}

//-------------------------------------------------------------------------
// Fri Jun 30 10:55:55 2017	==>	2017-06-27 12:07:42 
//-------------------------------------------------------------------------
PUBLIC 	void todatetime_2(s8 *dest, s32 dest_len, s8 *src)
{
	s32 i;
	s8 time_array[6][8];
	struct datetime_2 *dt;

	dt	= (struct datetime_1*)src;

	dt->ph1	= NULL;
	dt->ph2	= NULL;
	dt->ph3	= NULL;
	dt->ph4	= NULL;
	dt->ph5	= NULL;
	dt->ph6	= NULL;
	dt->ph7	= NULL;

	mon2num_1(dt->mon);
	
	//add on 2017-07-05
	day2num_1(dt->day);

	memset(dest, NULL, dest_len);

	strcpy_3(dest, 	dt->year);

	strcat(dest,	"-");
	strcat(dest,	dt->mon);
	strcat(dest,	"-");
	strcat(dest,	dt->day);
	strcat(dest,	" ");
	strcat(dest,	dt->hour);
	strcat(dest,	":");
	strcat(dest,	dt->min);
	strcat(dest,	":");
	strcat(dest,	dt->sec);

	printf("todatetime_2(dest)::%s\n", dest);
}

//-------------------------------------------------------------------------
// 1498732902.562	==>	2017-6-29 18:41:42 
//-------------------------------------------------------------------------
PUBLIC 	void todatetime_3(s8 *dest, s32 dest_len, s8 *src)
{
	s32 i;
	s8 time_array[6][8];
	s8* delim 	= ".";			//分隔符字符串

	//1、将 1498732902.562 以 '.' 作为分割符分成2个字符串，且最后'.'变成 NULL，即执行完strtok()后，src="1498732902"
    	strtok(src,delim);			

	//2、将 "1498732902" 转换为整型，即 s_time = 1498732902
	time_t s_time	= atoi(src);

	//printf("1)todatetime_3::(s)=%s,(d)=%d\n", src, s_time);

	//3、使用gmtime()函数将“整数s_time” 转换类型为 struct tm
	//struct tm *p	= gmtime(&s_time);
	struct tm *p	= localtime(&s_time);

	//memset(dest, dest_len, NULL);
	memset(dest, NULL, dest_len);

	//4、最终将"1498732902" 以"2017-6-29 18:41:42"格式输出至 dest[]中
	strftime(dest, dest_len, "%Y-%m-%d %H:%M:%S", p); 

	//printf("todatetime_3(dest)::%s\n", dest);
}

//-------------------------------------------------------------------------
// 27/Jun/2017:12:07:42	==>	2017-06-27 12:07:42 
//-------------------------------------------------------------------------
PUBLIC 	void todatetime_4(s8 *dest, s32 dest_len, s8 *src)
{
	s32 i;
	s8 time_array[6][8];
	struct datetime_4 *dt;

	dt	= (struct datetime_4*)src;

	dt->ph1	= NULL;
	dt->ph2	= NULL;
	dt->ph3	= NULL;
	dt->ph4	= NULL;
	dt->ph5	= NULL;
	dt->ph6	= NULL;

	memset(dest, NULL, dest_len);

	strcpy_3(dest, 	dt->year);

	strcat(dest,	"-");
	strcat(dest,	dt->mon);
	strcat(dest,	"-");
	strcat(dest,	dt->day);
	strcat(dest,	" ");
	strcat(dest,	dt->hour);
	strcat(dest,	":");
	strcat(dest,	dt->min);
	strcat(dest,	":");
	strcat(dest,	dt->sec);

	printf("todatetime_4(dest)::%s\n", dest);
}

//-------------------------------------------------------------------------
// Jun 25 15:12:00	==>	2017-06-25 15:12:00 
//-------------------------------------------------------------------------
PUBLIC 	void todatetime_5(s8 *dest, s32 dest_len, s8 *src)
{
	s32 i;
	s8 time_year[8];
	struct datetime_5 *dt;

	s64 timep;  
    	struct tm *p;  
    	time(&timep);

	//此函数获得的tm结构体的时间，是已经进行过时区转化为本地时间 
    	p =localtime(&timep);

	//把日期和时间转换为格林威治(GMT)时间的函数   
    	//p = gmtime(&timep);

	//memset(time_year, 8, NULL);
	memset(time_year,NULL, 8);
	itoa((1900+p->tm_year), time_year, 10);
    	
	dt	= (struct datetime_5*)src;

	dt->ph1	= NULL;
	dt->ph2	= NULL;
	dt->ph3	= NULL;
	dt->ph4	= NULL;
	dt->ph5	= NULL;
	
	mon2num_1(dt->mon);

	memset(dest, NULL, dest_len);

	strcpy_3(dest, 	time_year);

	strcat(dest,	"-");
	strcat(dest,	dt->mon);
	strcat(dest,	"-");
	strcat(dest,	dt->day);
	strcat(dest,	" ");
	strcat(dest,	dt->hour);
	strcat(dest,	":");
	strcat(dest,	dt->min);
	strcat(dest,	":");
	strcat(dest,	dt->sec);

	printf("todatetime_5(dest)::%s\n", dest);
}

//-------------------------------------------------------------------------
// Jun 25 15:12:00	==>	2017-06-25 15:12:00 
//-------------------------------------------------------------------------
PUBLIC 	void todatetime_6(s8 *dest, s32 dest_len, s8 *src)
{
	s32 i;
	struct datetime_6 *dt;

	dt	= (struct datetime_6*)src;

	dt->ph1	= NULL;
	dt->ph2	= NULL;
	dt->ph3	= NULL;
	dt->ph4	= NULL;
	dt->ph5	= NULL;
	
	memset(dt->ph6, NULL, 13);

	memset(dest, NULL, dest_len);

	strcpy_3(dest, 	dt->year);

	strcat(dest,	"-");
	strcat(dest,	dt->mon);
	strcat(dest,	"-");
	strcat(dest,	dt->day);
	strcat(dest,	" ");
	strcat(dest,	dt->hour);
	strcat(dest,	":");
	strcat(dest,	dt->min);
	strcat(dest,	":");
	strcat(dest,	dt->sec);

	printf("todatetime_6(dest)::%s\n", dest);
}

//-------------------------------------------------------------------------
// Feb	==>	02
//-------------------------------------------------------------------------
PUBLIC 	void mon2num_1(s8 *dest)
{
	if (strcmp_1(dest, "Jan") == TRUE)
	{
		strcpy_3(dest, "01");
	}

	if (strcmp_1(dest, "Feb") == TRUE)
	{
		strcpy_3(dest, "02");
	}

	if (strcmp_1(dest, "Mar") == TRUE)
	{
		strcpy_3(dest, "03");
	}

	if (strcmp_1(dest, "Apr") == TRUE)
	{
		strcpy_3(dest, "04");
	}

	if (strcmp_1(dest, "May") == TRUE)
	{
		strcpy_3(dest, "05");
	}

	if (strcmp_1(dest, "Jun") == TRUE)
	{
		strcpy_3(dest, "06");
	}

	if (strcmp_1(dest, "Jul") == TRUE)
	{
		strcpy_3(dest, "07");
	}

	if (strcmp_1(dest, "Aug") == TRUE)
	{
		strcpy_3(dest, "08");
	}

	if (strcmp_1(dest, "Sep") == TRUE)
	{
		strcpy_3(dest, "09");
	}

	if (strcmp_1(dest, "Oct") == TRUE)
	{
		strcpy_3(dest, "10");
	}

	if (strcmp_1(dest, "Nov") == TRUE)
	{
		strcpy_3(dest, "11");
	}

	if (strcmp_1(dest, "Dec") == TRUE)
	{
		strcpy_3(dest, "12");
	}
}

//-------------------------------------------------------------------------
// 2	==>	02
//-------------------------------------------------------------------------
PUBLIC 	void day2num_1(s8 *dest)
{
	if (strcmp_1(dest, " 1") == TRUE)
	{
		strcpy_3(dest, "01");
	}

	if (strcmp_1(dest, " 2") == TRUE)
	{
		strcpy_3(dest, "02");
	}

	if (strcmp_1(dest, " 3") == TRUE)
	{
		strcpy_3(dest, "03");
	}

	if (strcmp_1(dest, " 4") == TRUE)
	{
		strcpy_3(dest, "04");
	}

	if (strcmp_1(dest, " 5") == TRUE)
	{
		strcpy_3(dest, "05");
	}

	if (strcmp_1(dest, " 6") == TRUE)
	{
		strcpy_3(dest, "06");
	}

	if (strcmp_1(dest, " 7") == TRUE)
	{
		strcpy_3(dest, "07");
	}

	if (strcmp_1(dest, " 8") == TRUE)
	{
		strcpy_3(dest, "08");
	}

	if (strcmp_1(dest, " 9") == TRUE)
	{
		strcpy_3(dest, "09");
	}
}
