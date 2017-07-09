//===========================================================================
// als_prototype.h
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

#ifndef	_ALS_PROTOTYPE_H_
#define	_ALS_PROTOTYPE_H_

//main.c
PUBLIC	s32 main(s32 argc,s8 *argv[]);

//db_main.c
PUBLIC	s32 db_main();

//db.c
PUBLIC	MYSQL * db_conn(MYSQL *conn, s8 *server, s8 *user, s8 *pass, s8 *db);
PUBLIC	void db_close(MYSQL *conn);
PUBLIC	MYSQL_RES * db_exe(MYSQL *conn, s8 *sql);
PUBLIC	void db_disp(MYSQL_RES *tab);

//file_parse_main.c
PUBLIC	s32 file_parse_main(s8* filename);

//file_parse.c
PUBLIC	s32 file_parse(s8 file_num, s8 format);

//apache2_access_file_parse.c
PUBLIC	s32 apache2_access_do(s8 format);

//apache2_error_file_parse.c
PUBLIC	s32 apache2_error_do(s8 format);

//xferlog_file_parse.c
PUBLIC	s32 xferlog_do(s8 format);

//squid3_access_file_parse.c
PUBLIC	s32 squid3_access_do(s8 format);

//squid3_cache_file_parse.c
PUBLIC	s32 squid3_cache_do(s8 format);

//dns_file_parse.c
PUBLIC	s32 dns_do(s8 format);

//sendmail_file_parse.c
PUBLIC	s32 sendmail_do(s8 format);

//strings.c
PUBLIC 	void strcpy_1(s8 *dest, s8 *src, s32 len);
PUBLIC 	void strcpy_2(s8 *dest, s8 *src);
PUBLIC 	void 	strcpy_3(s8 *dest, s8 *src);
PUBLIC 	s8 strcmp_1(char *dest, char *src);
PUBLIC 	void itoa(s32 value,s8 *str,s32 radix);

//lib.c
PUBLIC 	void todatetime_1(s8 *dest, s32 dest_len, s8 *src);
PUBLIC 	void todatetime_2(s8 *dest, s32 dest_len, s8 *src);
PUBLIC 	void todatetime_3(s8 *dest, s32 dest_len, s8 *src);
PUBLIC 	void mon2num_1(s8 *dest);

//tmp2db_main.c
PUBLIC	s32 tmp2db_main(s8* filename);

#endif
