//===========================================================================
// xferlog_file_parse.c
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
PRIVATE s8 sql_exe[1024];

//===========================================================================
// apache2_access_do
//===========================================================================
PUBLIC	s32 xferlog_do(s8 format)
{
	FILE *fp_r;
	s32 num;
	s32 len;
	s8 buf_line[CHAR_IN_LINE_MAX];
	s8 tmp_buf[32];
	struct datetime_2 dt2;
	struct datetime_2 *dt2_p;

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
	memset(sql_exe, NULL, 1024);

	strcpy_2(sql_exe, "create table if not exists tmp_xferlog_log(time DATETIME, trans_secs int, remote_ip char(32), file_size int, file_path char(128), trans_type char, flag char, trans_direction char, access_mode char, user_name char(20), server_name char(20), auth_method char, auth_id char(20), trans_state char)");

	res = db_exe(conn, sql_exe);
	printf("\ncreate table finish!\n");			


	//-----------------------------------------------------------------
	// 分析日志文件
	//-----------------------------------------------------------------
	fp_r 	= fopen(xferlog_log_path,"r");

	num	= (CHAR_IN_LINE_MAX-1);

	//循环读取每一行，直到文件尾  
	while(fgets(buf_line, num ,fp_r) != NULL)
	{
		printf("1) %s", buf_line);   

		//0)清空sql语句
		memset(sql_exe, NULL, 1024);		                   

		//2)将一行的内容以“format”的格式分割，分别存入line_array[i]
		sscanf(buf_line, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", 
			line_array[0],line_array[1],line_array[2],line_array[3],line_array[4],
			line_array[5],line_array[6],line_array[7],line_array[8], line_array[9],
			line_array[10],line_array[11],line_array[12],line_array[13], line_array[14],
			line_array[15],line_array[16],line_array[17]);	

		//printf("2) %s:%s:%s:%s:%s:%s:%s:%s:%s:%s:%s:%s:%s:%s:%s:%s:%s:%s\n", 
		//	line_array[0],line_array[1],line_array[2],line_array[3],line_array[4],
		//	line_array[5],line_array[6],line_array[7],line_array[8], line_array[9],
		//	line_array[10],line_array[11],line_array[12],line_array[13], line_array[14],
		//	line_array[15],line_array[16],line_array[17]);	

		//3)构建sql语句
		strcpy_2(sql_exe, "insert into tmp_xferlog_log values (");

		//add datetime
		//将日志里的日期格式转换为mysql里的DATETIIME格式
		// 27/Jun/2017:12:07:42	==>	2017-06-27 12:07:42
		dt2_p	= (struct datetime_2 *)buf_line;
		strcpy_1(&dt2, dt2_p,LEN_DATETIME_2);

		todatetime_2(tmp_buf, 32, &dt2);		

		strcat(sql_exe, "'");
		strcat(sql_exe, tmp_buf);
		strcat(sql_exe, "', ");		
		
		//add trans_secs
		strcat(sql_exe, "'");
		strcat(sql_exe, line_array[5]);
		strcat(sql_exe, "', ");

		//remote ip
		strcat(sql_exe, "'");
		strcat(sql_exe, line_array[6]);
		strcat(sql_exe, "', ");

		//add file_size
		strcat(sql_exe, "'");
		strcat(sql_exe, line_array[7]);
		strcat(sql_exe, "', ");

		//add file_path
		strcat(sql_exe, "'");
		strcat(sql_exe, line_array[8]);
		strcat(sql_exe, "', ");

		//add trans_type
		strcat(sql_exe, "'");
		strcat(sql_exe, line_array[9]);
		strcat(sql_exe, "', ");

		//add flag
		strcat(sql_exe, "'");
		strcat(sql_exe, line_array[10]);
		strcat(sql_exe, "', ");

		//add trans_direction
		strcat(sql_exe, "'");
		strcat(sql_exe, line_array[11]);
		strcat(sql_exe, "', ");

		//add access_mode
		strcat(sql_exe, "'");
		strcat(sql_exe, line_array[12]);
		strcat(sql_exe, "', ");

		//add user_name
		strcat(sql_exe, "'");
		strcat(sql_exe, line_array[13]);
		strcat(sql_exe, "', ");

		//add server_name
		strcat(sql_exe, "'");
		strcat(sql_exe, line_array[14]);
		strcat(sql_exe, "', ");

		//add auth_method
		strcat(sql_exe, "'");
		strcat(sql_exe, line_array[15]);
		strcat(sql_exe, "', ");

		//add auth_id
		strcat(sql_exe, "'");
		strcat(sql_exe, line_array[16]);
		strcat(sql_exe, "', ");

		//add trans_state
		strcat(sql_exe, "'");
		strcat(sql_exe, line_array[17]);
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


