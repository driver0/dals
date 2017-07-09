//===========================================================================
// als_type.h
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

#ifndef	_ALS_TYPE_H_
#define	_ALS_TYPE_H_

#define	PUBLIC		
#define	PRIVATE	static

#define	NULL	'\0'

typedef	unsigned long long	u64;
typedef	unsigned int		u32;
typedef	unsigned short		u16;
typedef	unsigned char		u8;

typedef	long long		s64;
typedef	int			s32;
typedef	short			s16;
typedef	char			s8;


struct iaddr
{
	u8	addr1;
	u8	addr2;
	u8	addr3;
	u8	addr4;
};

//-------------------------------------------------------------------------
// 27/Jun/2017:12:07:42
//-------------------------------------------------------------------------
struct datetime_1
{
	s8	day[2];
	s8	ph1;
	s8	mon[3];
	s8	ph2;
	s8	year[4];
	s8	ph3;
	s8	hour[2];
	s8	ph4;
	s8	min[2];
	s8	ph5;
	s8	sec[2];
	s8	ph6;
};

//-------------------------------------------------------------------------
// [Fri Jun 30 10:55:55 2017] [notice] Apache/2.2.22 (Ubuntu) configured -- resuming normal operations
//-------------------------------------------------------------------------
#define LEN_DATETIME_2	25
struct datetime_2
{
	s8	weekday[3];
	s8	ph1;
	s8	mon[3];
	s8	ph2;
	s8	day[2];
	s8	ph3;
	s8	hour[2];
	s8	ph4;
	s8	min[2];
	s8	ph5;
	s8	sec[2];
	s8	ph6;
	s8	year[4];
	s8	ph7;	
};

//-------------------------------------------------------------------------
// 2017/06/22 10:14:23
//-------------------------------------------------------------------------
struct datetime_4
{
	s8	year[4];	
	s8	ph1;
	s8	mon[2];
	s8	ph2;
	s8	day[2];
	s8	ph3;
	s8	hour[2];
	s8	ph4;
	s8	min[2];
	s8	ph5;
	s8	sec[2];
	s8	ph6;
};

//-------------------------------------------------------------------------
// Jun 25 15:12:00
//-------------------------------------------------------------------------
struct datetime_5
{	
	s8	mon[3];
	//s8	mon[2];
	s8	ph1;
	s8	day[2];
	s8	ph2;
	s8	hour[2];
	s8	ph3;
	s8	min[2];
	s8	ph4;
	s8	sec[2];
	s8	ph5;
};

//-------------------------------------------------------------------------
// 2017-06-26T10:28:29.672151+08:00
//-------------------------------------------------------------------------
struct datetime_6
{
	s8	year[4];	
	s8	ph1;
	s8	mon[2];
	s8	ph2;
	s8	day[2];
	s8	ph3;
	s8	hour[2];
	s8	ph4;
	s8	min[2];
	s8	ph5;
	s8	sec[2];
	s8	ph6[13];
};

struct err_log_1
{
	s8	ph0;
	struct datetime_2 dt;
	s8	ph1;
	s8	content[128];
};

struct vsftpd_log
{
	struct datetime_2 dt;
	s8	ph1;
	s8	content[128];
};

struct cache_log_1
{
	struct datetime_4 dt;
	s8	ph1;
	s8	content[128];
};

struct dns_log_1
{
	struct datetime_6 dt;
	//s8	ph1;
	s8	content[512];
};

struct iptables_log_1
{
	struct datetime_6 dt;
	//s8	ph1;
	s8	content[512];
};

struct sshd_log_1
{
	struct datetime_6 dt;
	//s8	ph1;
	s8	content[512];
};

struct sendmail_log_1
{
	struct datetime_6 dt;
	s8	ph1;
	s8	content[512];
};

#endif
