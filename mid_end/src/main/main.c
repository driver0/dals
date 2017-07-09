//===========================================================================
// main.c
//   Copyright (C) 2017 Free Software Foundation, Inc.
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
#include 	<sys/types.h>
#include 	<sys/inotify.h>
#include 	"mon_type.h"
#include 	"mon_prototype.h"
#include 	"mon_global.h"

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )

PRIVATE	s8 dwin_cmd[256]	= "/media/sf_install_disk_als/front_end/dst/dwin ";

PRIVATE	s8 als_cmd[256]		= "/media/sf_install_disk_als/back_end/dst/als 10 ";
PRIVATE	s8 shell_cmd[256]	= "/media/sf_install_disk_als/back_end/script/getlogfiles.sh ";
#define ALS_CMD_LEN	47						//strlen(als_cmd);
#define SHELL_CMD_LEN	58						//strlen(shell_cmd);

#define DWIN_CMD_LEN	46						//strlen(shell_cmd);
//===========================================================================
// monitor_main
//===========================================================================
PUBLIC	s32 main(s32 argc,s8 *argv[])
{
	s32 fd;
  	s32 wd;
  	s8 buffer[BUF_LEN];
	
  	fd = inotify_init();

	if(fd<0)
	{
		printf("error::inotify::init!\n");
	}

	wd=inotify_add_watch(fd,"/dita/log",IN_MODIFY|IN_CREATE|IN_DELETE);

	while(1)
	{
		s32 length, i = 0;

		length=read(fd,buffer,BUF_LEN);

		if(length<0)
		{
			printf("error::inotify::read!\n");
		}

	  	while(i<length) 
		{
	    		struct inotify_event *event = (struct inotify_event *)&buffer[i];
	   
			if(event->len) 
			{
	      			if(event->mask & IN_CREATE) 
				{
					if(event->mask & IN_ISDIR) 
					{
		  				printf("The directory %s was created.\n", event->name);
						break;
					}
					else 
					{
		  				printf("The file %s was created.\n", event->name);
						break;
					}
	      			}
	      			else if(event->mask & IN_DELETE)
				{
					if(event->mask & IN_ISDIR)
					{
		  				printf("The directory %s was deleted.\n", event->name);
						break;
					}
					else 
					{
		  				printf("The file %s was deleted.\n",event->name);
						break;
					}
	      			}
	      			else if(event->mask & IN_MODIFY)
				{
					if(event->mask & IN_ISDIR)
					{
		  				printf("The directory %s was modified.\n",event->name);
						break;
					}
					else 
					{
		  				//printf("The file %s was modified.\n",event->name);

						mon_ctrl(event->name);

						break;
					}
	      			}
	    		}
	    		i += EVENT_SIZE + event->len;
	  	}
	}
	
	(void)inotify_rm_watch(fd,wd);
	(void)close(fd);

	exit(0);
}

//===========================================================================
// mon_ctrl(s8 *filename)
//===========================================================================
PUBLIC	s32 mon_ctrl(s8 *filename)
{
	if((strcmp_1(filename, "dns.log") == TRUE) ||
		(strcmp_1(filename, "sendmail.log") == TRUE) ||
		(strcmp_1(filename, "squid3_access.log") == TRUE) ||
		(strcmp_1(filename, "squid3_cache.log") == TRUE) ||
		(strcmp_1(filename, "vsftpd.log") == TRUE) ||
		(strcmp_1(filename, "xferlog.log") == TRUE) ||
		//(strcmp_1(filename, "iptables.log") == TRUE) ||
		(strcmp_1(filename, "sshd.log") == TRUE) ||
		(strcmp_1(&filename[11], "apache2_access_log") == TRUE) ||	//2017_07_05_apache2_access_log
		(strcmp_1(&filename[11], "apache2_error_log") == TRUE)	||	//2017_07_05_apache2_error_log
		(strcmp_1(&filename[11], "apache2_tls_access_log") == TRUE) ||	//2017_07_05_apache2_tls_access_log
		(strcmp_1(&filename[11], "apache2_tls_error_log") == TRUE))	//2017_07_05_apache2_tls_error_log
	{
		//--------------------------------------------------------------------------
		// 启动 getlogfiles.sh 采集单个日志文件（内容变动的那个）：：system(shell_cmd);
		//--------------------------------------------------------------------------
		memset(&shell_cmd[SHELL_CMD_LEN], NULL, (256-SHELL_CMD_LEN));
		strcat(&shell_cmd[SHELL_CMD_LEN], filename);		
		strcat(&shell_cmd[SHELL_CMD_LEN], "&");

		printf("shell_cmd::%s\n", shell_cmd);

		//--------------------------------------------------------------------------
		// 启动 als 将单个日志文件（内容变动的那个）写入数据库 ：：system(als_cmd);
		//--------------------------------------------------------------------------
		memset(&als_cmd[ALS_CMD_LEN], NULL, (256-ALS_CMD_LEN));
		strcat(&als_cmd[ALS_CMD_LEN], filename);
		strcat(&als_cmd[ALS_CMD_LEN], "&");

		printf("als_cmd::%s\n", als_cmd);

		//--------------------------------------------------------------------------
		// 启动 dwin 将弹出一个窗口提示告警：：system(dwin_cmd);
		//--------------------------------------------------------------------------
		memset(&dwin_cmd[DWIN_CMD_LEN], NULL, (256-DWIN_CMD_LEN));
		strcat(&dwin_cmd[DWIN_CMD_LEN], filename);
		strcat(&dwin_cmd[DWIN_CMD_LEN], "&");

		printf("dwin_cmd::%s\n", dwin_cmd);

		system(shell_cmd); 
		system(als_cmd);
		system(dwin_cmd);
	}
	

	//system(als_cmd);
}
