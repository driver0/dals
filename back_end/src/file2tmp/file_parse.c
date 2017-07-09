//===========================================================================
// file_parse.c
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
#include 	"als_logfile.h"
#include 	"als_global.h"



//===========================================================================
// file_parse
//===========================================================================
PUBLIC	s32 file_parse(s8 file_num, s8 format)
{
	switch(file_num)
	{
		case APACHE2_ACCESS_LOG:
			apache2_access_do(format);
			break;
		case APACHE2_ERROR_LOG:
			apache2_error_do(format);
			break;
		case XFERLOG_LOG:
			xferlog_do(format);
			break;
		case VSFTPD_LOG:
			vsftpd_do(format);
			break;
		case SQUID3_ACCESS_LOG:
			squid3_access_do(format);
			break;
		case SQUID3_CACHE_LOG:
			squid3_cache_do(format);
			break;
		case DNS_LOG:
			dns_do(format);
			break;
		case SENDMAIL_LOG:
			sendmail_do(format);
			break;
		case IPTABLES_LOG:
			iptables_do(format);
			break;
		case SSHD_LOG:
			sshd_do(format);
			break;
		case APACHE2_TLS_ACCESS_LOG:
			apache2_tls_access_do(format);
			break;
		case APACHE2_TLS_ERROR_LOG:
			apache2_tls_error_do(format);
			break;
		default:
			printf("error::file_num = %d\n", file_num);
			break;
	}
}


