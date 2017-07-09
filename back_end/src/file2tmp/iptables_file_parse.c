//===========================================================================
// iptables_file_parse.c
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
PUBLIC	s32 iptables_do(s8 format)
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
	memset(sql_exe, NULL, 1024);

	strcpy_2(sql_exe, "create table if not exists tmp_iptables_log(time DATETIME, content varchar(512))");

	res = db_exe(conn, sql_exe);
	printf("\ncreate table finish!\n");			


	//-----------------------------------------------------------------
	// 分析日志文件
	//-----------------------------------------------------------------
	fp_r 	= fopen(iptables_log_path,"r");

	num	= (CHAR_IN_LINE_MAX-1);
	
	//循环读取每一行，直到文件尾 
	while(fgets(buf_line, num ,fp_r) != NULL)
	{
		printf("1) %s", buf_line);

		//0)替换 iptables_log 里面的 '
		replace_ch(buf_line, '\'', ' ');

		//1)清空sql语句
		memset(sql_exe, NULL, 1024);

		//2)将一行的内容以“format”的格式分割，分别存入line_array[i]
		// Jun 25 15:12:00 test named[5734]: starting BIND 9.8.1-P1 -u bind
		struct iptables_log_1 *dl	= buf_line;	

		//3)构建sql语句
		strcpy_2(sql_exe, "insert into tmp_iptables_log values (");

		//add datetime
		//将日志里的日期格式转换为mysql里的DATETIIME格式
		//---------------------------------------------
		// remark on 2017-07-05
		//
		// Jun 25 15:12:00	==>	2017-06-25 15:12:00
		//todatetime_5(tmp_buf, 32, &(dl->dt));
		//---------------------------------------------

		//---------------------------------------------
		// add on 2017-07-05
		//
		//2017-07-02T11:04:16.582669+08:00 test named[1479]: error (network unreachable) resolving '102.103.102.101.in-addr.arpa
		//2017-07-05T10:41:08.231250+08:00 test kernel: [ 2244.686564] IN=eth0 OUT= MAC=01:00:5e:00:00:01:c0:4a:00:49:f9:28:08:00
		memset(tmp_buf, NULL, 32);
		//strcpy_2(tmp_buf, &(dl->dt));
		//tmp_buf[10]	= ' ';		//将T变成空格：2017-07-02 11:04:16
		todatetime_6(tmp_buf, 32, &(dl->dt));
		//---------------------------------------------

		strcat(sql_exe, "'");
		strcat(sql_exe, tmp_buf);
		strcat(sql_exe, "', ");
		
		//add content
		strcat(sql_exe, "'");
		strcat(sql_exe, dl->content);
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


