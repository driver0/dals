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
#include 	"als_db.h"
#include 	"als_prototype.h"
#include 	"als_global.h"

PRIVATE s32 db_init();

PRIVATE s8 database_server[16] 	= "101.102.103.102";  
PRIVATE s8 database_user[8] 	= "root";  
PRIVATE s8 database_pass[8] 	= "root";  
PRIVATE s8 database_name[8] 	= "abc";

//===========================================================================
// db_main:
//	主函数
//===========================================================================

PUBLIC	s32 db_main()
{
	db_init();

	//db_test();
}

PRIVATE s32 db_init()
{
	db_server		= database_server;
	db_user			= database_user;
	db_pass			= database_pass;
	db_name			= database_name;
}

PUBLIC	s32 db_test()
{
	MYSQL *conn	= NULL;
	MYSQL_RES *res	= NULL;

	s8 db_server[16] 	= "101.102.103.100";  
    	s8 user[8] 		= "root";  
    	s8 pass[8] 		= "root";  
    	s8 db_name[8] 	= "abc";
	s8 sql_query[128]	= "select * from x1";
	s8 sql_queryt[128]	= "select * from x2";
	s8 sql_insert[128]	= "insert into x1 values (null, 'test', 333)";
	s8 sql_delete[128]	= "delete from x1 where idx=3";
	s8 sql_update[128]	= "update x1 set a2='999' where idx=2";
	s8 sql_crt_table[128] = "create table x1(idx int auto_increment primary key, a1 char(64), a2 int)";
	s8 sql_del_table[128] = "drop table x1";		

	s32 ret;

	//printf("0)main::&conn=%x\n", conn);

	//-----------------------------------------------------------------
	//连接数据库
	//-----------------------------------------------------------------
	conn	= db_conn(conn, db_server, user, pass, db_name);
	if(conn == NULL)
	{
		return;
	}

	//printf("2)main::conn=%x\n", conn);

	//-----------------------------------------------------------------
	//查询表记录
	//-----------------------------------------------------------------
	res = db_exe(conn, sql_query);

	//显示查询结果
	if(res != NULL)
	{
		db_disp(res);

		mysql_free_result(res);	//完成对数据的所有操作后,调用此函数来让MySQL库清理它分配的对象 
	}

	//-----------------------------------------------------------------
	// insert
	//-----------------------------------------------------------------
	//res = db_exe(conn, sql_insert);
	//printf("\ninsert finish!\n");

	//-----------------------------------------------------------------
	// delete
	//-----------------------------------------------------------------
	//res = db_exe(conn, sql_delete);
	//printf("\ndelete finish!\n");

	//-----------------------------------------------------------------
	// update
	//-----------------------------------------------------------------
	res = db_exe(conn, sql_update);
	printf("\nupdate finish!\n");

	//-----------------------------------------------------------------
	// create table
	//-----------------------------------------------------------------
	//res = db_exe(conn, sql_crt_table);
	//printf("\ncreate table finish!\n");

	//-----------------------------------------------------------------
	// delete table
	//-----------------------------------------------------------------
	//res = db_exe(conn, sql_del_table);
	//printf("\ndelete table finish!\n");


	//-----------------------------------------------------------------
	//查询表记录
	//-----------------------------------------------------------------
	res = db_exe(conn, sql_query);

	//显示查询结果
	if(res != NULL)
	{
		db_disp(res);

		mysql_free_result(res);	//完成对数据的所有操作后,调用此函数来让MySQL库清理它分配的对象 
	}

	//关闭数据库连接
	db_close(conn);
}
