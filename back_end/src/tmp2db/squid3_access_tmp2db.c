//===========================================================================
// squid3_access_tmp2db.c
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

PRIVATE s8 sql_exe[1024];

//===========================================================================
// squid3_access_exec
//===========================================================================
PUBLIC	s32 squid3_access_exec()
{
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

	strcpy_2(sql_exe, "create table if not exists squid3_access_log(time DATETIME, secs int, ip char(32), hit_state_id int, trans_bytes int, req_method char, url char(128), ident char, code_remoteip char(32), http_header char(32))");

	res = db_exe(conn, sql_exe);
	printf("\ncreate table finish!\n");

	//-----------------------------------------------------------------
	//查询表记录
	//-----------------------------------------------------------------
	memset(sql_exe, NULL, 1024);

	strcpy_2(sql_exe, "select * from squid3_access_log");
	res = db_exe(conn, sql_exe);

	s32 num_cnt = mysql_fetch_row(res);

	//-----------------------------------------------------------------
	// 将tmp_squid3_access_log 里的数据放入 squid3_access_log
	//-----------------------------------------------------------------
	memset(sql_exe, NULL, 1024);

	if(num_cnt == 0)
	{
		strcpy_2(sql_exe, "insert into squid3_access_log select * from tmp_squid3_access_log");
	}
	else
	{
		memset(sql_exe, NULL, 1024);

		strcpy_2(sql_exe, "select max(time) from squid3_access_log");
		res = db_exe(conn, sql_exe);

		MYSQL_ROW sqlrow = mysql_fetch_row(res);

		strcpy_2(sql_exe, "insert into squid3_access_log select * from tmp_squid3_access_log where time > '");
		strcat(sql_exe, sqlrow[0]);
		strcat(sql_exe, "'");

		printf("squid3_access_log::sql_exe=%s\n",sql_exe);
	}

	res = db_exe(conn, sql_exe);
	printf("\ncreate table finish!\n");	

	//-----------------------------------------------------------------
	// 删除tmp table
	//-----------------------------------------------------------------
	memset(sql_exe, NULL, 1024);

	strcpy_2(sql_exe, "drop table tmp_squid3_access_log");

	res = db_exe(conn, sql_exe);
	printf("\ndrop table finish!\n");		

	//关闭数据库连接
	db_close(conn);
}


