//===========================================================================
// db.c
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

#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<mysql/mysql.h>
#include 	"als_type.h"
#include 	"als_prototype.h"
#include 	"als_global.h"

//===========================================================================
// main:
//	主函数
//===========================================================================

PUBLIC	s32 main(s32 argc,s8 *argv[])
{
	s32 ret;

	if (strcmp_1(argv[1], "0") == TRUE)
	{
		printf("==========\n");
		printf(" Options:\n");
		printf("==========\n");
		printf("	[1] Starting to collect log files!\n");
		printf("	[2] Starting to insert log files into tmp tables!\n");
		printf("	[3] Starting to insert log data into tables from tmp tables!\n");
		printf("	[10] Starting to insert a log into table from tmp tables!\n");
	}

	//---------------------------------------------------------------------------
	// daily -- 所有日志入库
	//---------------------------------------------------------------------------
	if (strcmp_1(argv[1], "1") == TRUE)
	{
		printf("\n-------------------------------------------------------\n");
		printf(" Starting to collect log files!\n");
		printf("-------------------------------------------------------\n");
	}

	if (strcmp_1(argv[1], "2") == TRUE)
	{
		printf("\n-------------------------------------------------------\n");
		printf(" Starting to insert log files into tmp tables!\n");
		printf("-------------------------------------------------------\n");

		ret	= db_main();
		ret	= file_parse_main(NULL);
	}
	
	if (strcmp_1(argv[1], "3") == TRUE)
	{
		printf("\n-------------------------------------------------------\n");
		printf(" Starting to insert log data into tables from tmp tables!\n");
		printf("-------------------------------------------------------\n");

		ret	= db_main();
		ret	= tmp2db_main(NULL);
	}

	//---------------------------------------------------------------------------
	// 实时 -- 某个日志单独入库（实时告警）
	//---------------------------------------------------------------------------
	if (strcmp_1(argv[1], "10") == TRUE)
	{
		printf("\n-------------------------------------------------------\n");
		printf(" Starting to insert a log files into table!\n");
		printf("-------------------------------------------------------\n");

		ret	= db_main();
		ret	= file_parse_main(argv[2]);

		ret	= tmp2db_main(argv[2]);
	}
	
}
