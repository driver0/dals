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
// db_conn:
//		连接数据库
//===========================================================================
PUBLIC	MYSQL * db_conn(MYSQL *conn, s8 *server, s8 *user, s8 *pass, s8 *db)
{
	MYSQL *conn_ptr;
	s32 ret;
	u32 time_out = 15;	//设置连接超时15s

	conn = mysql_init(NULL);

	if(!conn)  
	{  
		printf("mysql_init::fail!\n");  
		return NULL;  
	}

	ret = mysql_options(conn,MYSQL_OPT_CONNECT_TIMEOUT,(const s8 *)&time_out);	//设置连接超时  
	if( ret )  
	{  
		printf("Connection is timeout!\n");  
		return NULL;  
	}
		
	conn_ptr = mysql_real_connect(conn,server,user,pass,db,0,NULL,0);		//连接数据库
	
	if(!conn_ptr)  
    	{
		printf("mysql_real_connect::fail!\n");
		return NULL; 
	}
	else
	{
		printf("mysql_real_connect::success!\n");
		return conn_ptr;
	}
}

//===========================================================================
// db_close:
//		关闭数据库
//===========================================================================
PUBLIC	void db_close(MYSQL *conn)
{
	mysql_close(conn);
}

//===========================================================================
// db_query:
//		返回值：MYSQL_RES *res
// 作用：
//		在数据库中查询记录
//===========================================================================
PUBLIC	MYSQL_RES * db_exe(MYSQL *conn, s8 *sql)
{
	s32 ret;
	MYSQL_RES *res;

	//执行SQL语句
	ret = mysql_query(conn,sql);				 

	if(ret)  
        {  
            	printf("select error %d: %s !\n",mysql_errno(conn),mysql_error(conn));
            	return EXIT_FAILURE;  
        }  
		
	res 	= mysql_store_result(conn);


	return res;
}



//===========================================================================
// db_disp:
//		显示“表记录”集合的内容
//===========================================================================
PUBLIC	void db_disp(MYSQL_RES *tab)
{
	s32 row,col,i,j;
	MYSQL_ROW sqlrow;
	
	if(tab)  
        {  
            	row = mysql_num_rows(tab);			//行  
            	col = mysql_num_fields(tab);			//列  
              
            	for(i=0; i<row; i++)  
            	{  
              		sqlrow = mysql_fetch_row(tab);  
              		for(j=0; j<col; j++)  
              		{
                		printf("%-8s  ",sqlrow[j]);	//字符串向左靠，右补空格  
              		}  
             	 	printf("\n");  
                }
        }  

}
