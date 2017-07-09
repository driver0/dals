//===========================================================================
// als_logfile.h
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

#ifndef	_ALS_LOGFILE_H_
#define	_ALS_LOGFILE_H_

s8 *apa_access_log_path;
s8 *apa_error_log_path;
s8 *dns_log_path;
s8 *dhcp_log_path;
s8 *iptables_log_path;
s8 *nfs_log_path;
s8 *postfix_log_path;
s8 *sendmail_log_path;
s8 *samba_log_path;
s8 *squid3_access_log_path;
s8 *squid3_cache_log_path;
s8 *vsftpd_log_path;
s8 *xferlog_log_path;
s8 *iptables_log_path;
s8 *sshd_log_path;
s8 *apa_tls_access_log_path;
s8 *apa_tls_error_log_path;

#define	CHAR_IN_LINE_MAX	1024

#define	CHAR_SPACE	0x20

//--------------------------------------------------------------------------
// log file numbers
//--------------------------------------------------------------------------
#define	NUM_LOG			17

#define	APACHE2_ACCESS_LOG	0
#define	APACHE2_ERROR_LOG	1
#define	DNS_LOG			2
#define	DHCP_LOG		3
#define	IPTABLES_LOG		4
#define	NFS_LOG			5
#define	POSTFIX_LOG		6
#define	SENDMAIL_LOG		7
#define	SAMBA_LOG		8
#define	SQUID3_ACCESS_LOG	9
#define	SQUID3_CACHE_LOG	10
#define	VSFTPD_LOG		11
#define	XFERLOG_LOG		12

#define	IPTABLES_LOG		13
#define	SSHD_LOG		14

#define	APACHE2_TLS_ACCESS_LOG	15
#define	APACHE2_TLS_ERROR_LOG	16

#endif
