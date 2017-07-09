//===========================================================================
// tmp2db_main.c
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
// tmp2db_main
//===========================================================================
PUBLIC	s32 tmp2db_main(s8* filename)
{
	s32 ret;	

	if(filename == NULL)
	{
		//分析日志文件
		ret	= tmp2db(APACHE2_ACCESS_LOG, CHAR_SPACE);
		ret	= tmp2db(APACHE2_ERROR_LOG, CHAR_SPACE);
		ret	= tmp2db(XFERLOG_LOG, CHAR_SPACE);
		ret	= tmp2db(VSFTPD_LOG, CHAR_SPACE);
		ret	= tmp2db(SQUID3_ACCESS_LOG, CHAR_SPACE);
		ret	= tmp2db(SQUID3_CACHE_LOG, CHAR_SPACE);
		ret	= tmp2db(DNS_LOG, CHAR_SPACE);
		ret	= tmp2db(SENDMAIL_LOG, CHAR_SPACE);

		ret	= tmp2db(IPTABLES_LOG, CHAR_SPACE);

		ret	= tmp2db(SSHD_LOG, CHAR_SPACE);
	
		ret	= tmp2db(APACHE2_TLS_ACCESS_LOG, CHAR_SPACE);
		ret	= tmp2db(APACHE2_TLS_ERROR_LOG, CHAR_SPACE);
	}
	else
	{
		if(strcmp_1(filename, "dns.log") == TRUE)
		{
			ret	= tmp2db(DNS_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(filename, "sendmail.log") == TRUE)
		{
			ret	= tmp2db(SENDMAIL_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(filename, "squid3_access.log") == TRUE)
		{
			ret	= tmp2db(SQUID3_ACCESS_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(filename, "squid3_cache.log") == TRUE)
		{
			ret	= tmp2db(SQUID3_CACHE_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(filename, "vsftpd.log") == TRUE)
		{
			ret	= tmp2db(VSFTPD_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(filename, "xferlog.log") == TRUE)
		{
			ret	= tmp2db(XFERLOG_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(&filename[11], "apache2_access_log") == TRUE)		//2017_07_05_apache2_access_log
		{
			ret	= tmp2db(APACHE2_ACCESS_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(&filename[11], "apache2_error_log") == TRUE)		//2017_07_05_apache2_error_log
		{
			ret	= tmp2db(APACHE2_ERROR_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(&filename[11], "apache2_tls_access_log") == TRUE)	//2017_07_05_apache2_tls_access_log
		{
			ret	= tmp2db(APACHE2_TLS_ACCESS_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(&filename[11], "apache2_tls_error_log") == TRUE)	//2017_07_05_apache2_tls_error_log
		{
			ret	= tmp2db(APACHE2_TLS_ERROR_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(filename, "iptables.log") == TRUE)		
		{
			ret	= tmp2db(IPTABLES_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(filename, "sshd.log") == TRUE)		
		{
			ret	= tmp2db(SSHD_LOG, CHAR_SPACE);
		}
	}
}
