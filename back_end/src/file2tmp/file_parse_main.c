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

PRIVATE s8 logfiles[NUM_LOG][128];

PRIVATE s8 file_log_init();

//===========================================================================
// file_parse_main
//===========================================================================
PUBLIC	s32 file_parse_main(s8* filename)
{
	s32 ret;

	ret	= file_log_init();

	if(filename == NULL)
	{
		//分析日志文件
		ret	= file_parse(APACHE2_ACCESS_LOG, CHAR_SPACE);
		ret	= file_parse(APACHE2_ERROR_LOG, CHAR_SPACE);
		ret	= file_parse(XFERLOG_LOG, CHAR_SPACE);
		ret	= file_parse(VSFTPD_LOG, CHAR_SPACE);
		ret	= file_parse(SQUID3_ACCESS_LOG, CHAR_SPACE);
		ret	= file_parse(SQUID3_CACHE_LOG, CHAR_SPACE);
		ret	= file_parse(SENDMAIL_LOG, CHAR_SPACE);

		ret	= file_parse(DNS_LOG, CHAR_SPACE);

		ret	= file_parse(IPTABLES_LOG, CHAR_SPACE);

		ret	= file_parse(SSHD_LOG, CHAR_SPACE);

		ret	= file_parse(APACHE2_TLS_ACCESS_LOG, CHAR_SPACE);
		ret	= file_parse(APACHE2_TLS_ERROR_LOG, CHAR_SPACE);
	}
	else
	{
		if(strcmp_1(filename, "dns.log") == TRUE)
		{
			ret	= file_parse(DNS_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(filename, "sendmail.log") == TRUE)
		{
			ret	= file_parse(SENDMAIL_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(filename, "squid3_access.log") == TRUE)
		{
			ret	= file_parse(SQUID3_ACCESS_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(filename, "squid3_cache.log") == TRUE)
		{
			ret	= file_parse(SQUID3_CACHE_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(filename, "vsftpd.log") == TRUE)
		{
			ret	= file_parse(VSFTPD_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(filename, "xferlog.log") == TRUE)
		{
			ret	= file_parse(XFERLOG_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(&filename[11], "apache2_access_log") == TRUE)		//2017_07_05_apache2_access_log
		{
			ret	= file_parse(APACHE2_ACCESS_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(&filename[11], "apache2_error_log") == TRUE)		//2017_07_05_apache2_error_log
		{
			ret	= file_parse(APACHE2_ERROR_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(&filename[11], "apache2_tls_access_log") == TRUE)		//2017_07_05_apache2_tls_access_log
		{
			ret	= file_parse(APACHE2_TLS_ACCESS_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(&filename[11], "apache2_tls_error_log") == TRUE)		//2017_07_05_apache2_tls_error_log
		{
			ret	= file_parse(APACHE2_TLS_ERROR_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(filename, "iptables.log") == TRUE)
		{
			ret	= file_parse(IPTABLES_LOG, CHAR_SPACE);
		}
		else if(strcmp_1(filename, "sshd.log") == TRUE)
		{
			ret	= file_parse(SSHD_LOG, CHAR_SPACE);
		}
	}	
}

//===========================================================================
// file_log_init
//===========================================================================
PRIVATE s8 file_log_init()
{
	//-------------------------------------------------------------------------------
	// init logfiles[][]
	//-------------------------------------------------------------------------------
	strcpy_2(logfiles[APACHE2_ACCESS_LOG], 	"/media/sf_install_disk_als/back_end/logfile/apache2_access.log");
	strcpy_2(logfiles[APACHE2_ERROR_LOG], 	"/media/sf_install_disk_als/back_end/logfile/apache2_error.log");	
	strcpy_2(logfiles[DNS_LOG], 		"/media/sf_install_disk_als/back_end/logfile/dns.log");
	strcpy_2(logfiles[DHCP_LOG], 		"/media/sf_install_disk_als/back_end/logfile/dhcp.log");
	strcpy_2(logfiles[IPTABLES_LOG], 	"/media/sf_install_disk_als/back_end/logfile/iptables.log");
	strcpy_2(logfiles[NFS_LOG]	, 	"/media/sf_install_disk_als/back_end/logfile/nfs.log");
	strcpy_2(logfiles[POSTFIX_LOG], 	"/media/sf_install_disk_als/back_end/logfile/postfix.log");
	strcpy_2(logfiles[SENDMAIL_LOG], 	"/media/sf_install_disk_als/back_end/logfile/sendmail.log");
	strcpy_2(logfiles[SAMBA_LOG], 		"/media/sf_install_disk_als/back_end/logfile/samba_log.smbd");
	strcpy_2(logfiles[SQUID3_ACCESS_LOG], 	"/media/sf_install_disk_als/back_end/logfile/squid3_access.log");
	strcpy_2(logfiles[SQUID3_CACHE_LOG], 	"/media/sf_install_disk_als/back_end/logfile/squid3_cache.log");
	strcpy_2(logfiles[VSFTPD_LOG], 		"/media/sf_install_disk_als/back_end/logfile/vsftpd.log");
	strcpy_2(logfiles[XFERLOG_LOG], 	"/media/sf_install_disk_als/back_end/logfile/xferlog");
		
	strcpy_2(logfiles[IPTABLES_LOG], 	"/media/sf_install_disk_als/back_end/logfile/iptables.log");

	strcpy_2(logfiles[SSHD_LOG],	 	"/media/sf_install_disk_als/back_end/logfile/sshd.log");

	strcpy_2(logfiles[APACHE2_TLS_ACCESS_LOG], 	"/media/sf_install_disk_als/back_end/logfile/apache2_tls_access.log");
	strcpy_2(logfiles[APACHE2_TLS_ERROR_LOG], 	"/media/sf_install_disk_als/back_end/logfile/apache2_tls_error.log");
	
	//-------------------------------------------------------------------------------
	// init global pointer
	//-------------------------------------------------------------------------------
	apa_access_log_path	= logfiles[APACHE2_ACCESS_LOG];
	apa_error_log_path	= logfiles[APACHE2_ERROR_LOG];
	dns_log_path		= logfiles[DNS_LOG];
	dhcp_log_path		= logfiles[DHCP_LOG];
	iptables_log_path	= logfiles[IPTABLES_LOG];
	nfs_log_path		= logfiles[NFS_LOG];
	postfix_log_path	= logfiles[POSTFIX_LOG];
	sendmail_log_path	= logfiles[SENDMAIL_LOG];
	samba_log_path		= logfiles[SAMBA_LOG];
	squid3_access_log_path	= logfiles[SQUID3_ACCESS_LOG];
	squid3_cache_log_path	= logfiles[SQUID3_CACHE_LOG];
	vsftpd_log_path		= logfiles[VSFTPD_LOG];
	xferlog_log_path	= logfiles[XFERLOG_LOG];

	iptables_log_path	= logfiles[IPTABLES_LOG];

	sshd_log_path		= logfiles[SSHD_LOG];

	apa_tls_access_log_path	= logfiles[APACHE2_TLS_ACCESS_LOG];
	apa_tls_error_log_path	= logfiles[APACHE2_TLS_ERROR_LOG];
}
