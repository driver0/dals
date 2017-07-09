//===========================================================================
// squid3_cache_file_parse.c
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
#include 	"als_db.h"
#include 	"als_prototype.h"
#include 	"als_logfile.h"
#include 	"als_global.h"

PRIVATE	s8 line_array[32][128];
PRIVATE s8 sql_exe[256];

//===========================================================================
// squid3_cache_do
//===========================================================================
PUBLIC	s32 squid3_cache_do(s8 format)
{
	FILE *fp_r;
	s32 num;
	s32 len;
	s8 buf_line[CHAR_IN_LINE_MAX];
	s8 tmp_buf[32];

	MYSQL *conn	= NULL;
	MYSQL_RES *res	= NULL;

	//-----------------------------------------------------------------
	//连接数据库
	//-----------------------------------------------------------------
	conn	= db_conn(conn, db_server, db_user, db_pass, db_name);
	if(conn == NULL)
	{
		return;
	}

	//-----------------------------------------------------------------
	// 新建数据表
	//-----------------------------------------------------------------
	memset(sql_exe, NULL, 256);

	strcpy_2(sql_exe, "create table if not exists tmp_squid3_cache_log(time DATETIME, content char(128))");

	res = db_exe(conn, sql_exe);
	printf("\ncreate table finish!\n");			


	//-----------------------------------------------------------------
	// 分析日志文件
	//-----------------------------------------------------------------
	fp_r 	= fopen(squid3_cache_log_path,"r");

	num	= (CHAR_IN_LINE_MAX-1);
	
	//循环读取每一行，直到文件尾 
	while(fgets(buf_line, num ,fp_r) != NULL)
	{
		printf("1) %s", buf_line); 

		//1)清空sql语句
		memset(sql_exe, NULL, 256);

		//2)将一行的内容以“format”的格式分割，分别存入line_array[i]
		// 2017/06/22 10:14:23| Starting Squid Cache version 3.1.19 for x86_64-pc-linux-gnu...
		struct cache_log_1 *cl	= buf_line;	

		//3)构建sql语句
		strcpy_2(sql_exe, "insert into tmp_squid3_cache_log values (");

		//add datetime
		//将日志里的日期格式转换为mysql里的DATETIIME格式
		// 2017/06/22 10:14:23	==>	2017-06-27 12:07:42
		todatetime_4(tmp_buf, 32, &(cl->dt));		

		strcat(sql_exe, "'");
		strcat(sql_exe, tmp_buf);
		strcat(sql_exe, "', ");
		
		//add content
		strcat(sql_exe, "'");
		strcat(sql_exe, cl->content);
		strcat(sql_exe, "')");

		
		
		//4)将这一行内容插入数据库
		res = db_exe(conn, sql_exe);
		//printf("\ninsert finish!\n");	

		printf("sql_exe::%s\n", sql_exe);	

	}   

	fclose(fp_r);


	mysql_free_result(res);	//完成对数据的所有操作后,调用此函数来让MySQL库清理它分配的对象 
	//关闭数据库连接
	db_close(conn);
}


