#===========================================================================
# getlogfiles_daily.sh
#   Copyright (C) 2017 Free Software Foundation, Inc.
#   Originally by ZhaoFeng Liang <zhf.liang@outlook.com>
#
#This file is part of DTHAS_ALS.
#
#DTHAS_ALS is free software; you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation; either version 2 of the License, or 
#(at your option) any later version.
#
#DTHAS_ALS is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License
#along with DTHAS_ALS; If not, see <http://www.gnu.org/licenses/>.  
#===========================================================================

#!/bin/bash


#-----------------------------------------------------------------
# Apache2 -- error_log
#-----------------------------------------------------------------

file=/dita/log/`date +%Y_%m_%d_apache2_error_log`

if [ -f "$file" ]; then
  	cp $file /media/sf_install_disk_als/back_end/logfile/apache2_error.log
fi

#-----------------------------------------------------------------
# Apache2 -- access_log
#-----------------------------------------------------------------
file=/dita/log/`date +%Y_%m_%d_apache2_access_log`

if [ -f "$file" ]; then
  	cp $file /media/sf_install_disk_als/back_end/logfile/apache2_access.log
fi

#-----------------------------------------------------------------
# Apache2 -- https -- error_log
#-----------------------------------------------------------------

file=/dita/log/`date +%Y_%m_%d_apache2_tls_error_log`

if [ -f "$file" ]; then
  	cp $file /media/sf_install_disk_als/back_end/logfile/apache2_tls_error.log
fi

#-----------------------------------------------------------------
# Apache2 -- https -- access_log
#-----------------------------------------------------------------
file=/dita/log/`date +%Y_%m_%d_apache2_tls_access_log`

if [ -f "$file" ]; then
  	cp $file /media/sf_install_disk_als/back_end/logfile/apache2_tls_access.log
fi

#-----------------------------------------------------------------
# dhcp
#-----------------------------------------------------------------
file=/dita/log/dhcp.log

if [ -f "$file" ]; then
  	cp $file /media/sf_install_disk_als/back_end/logfile
fi

#-----------------------------------------------------------------
# dns
#-----------------------------------------------------------------
cat /var/log/messages | grep named > /dita/log/dns.log

file=/dita/log/dns.log

if [ -f "$file" ]; then
  	cp $file /media/sf_install_disk_als/back_end/logfile
fi

#-----------------------------------------------------------------
# nfs
#-----------------------------------------------------------------
file=/dita/log/nfs.log

if [ -f "$file" ]; then
  	cp $file /media/sf_install_disk_als/back_end/logfile
fi

#-----------------------------------------------------------------
# postfix
#-----------------------------------------------------------------
file=/dita/log/postfix.log

if [ -f "$file" ]; then
  	cp $file /media/sf_install_disk_als/back_end/logfile/postfix.log
fi

#-----------------------------------------------------------------
# sendmail
#-----------------------------------------------------------------
file=/dita/log/sendmail.log

if [ -f "$file" ]; then
  	cp $file /media/sf_install_disk_als/back_end/logfile/sendmail.log
fi

#-----------------------------------------------------------------
# log.smbd
#-----------------------------------------------------------------
file=/dita/log/samba_log.smbd

if [ -f "$file" ]; then
  	cp $file /media/sf_install_disk_als/back_end/logfile
fi

#-----------------------------------------------------------------
# squid3 -- access.log
#-----------------------------------------------------------------
file=/dita/log/squid3_access.log

if [ -f "$file" ]; then
  	cp $file /media/sf_install_disk_als/back_end/logfile/squid3_access.log
fi

#-----------------------------------------------------------------
# squid3 -- cache.log
#-----------------------------------------------------------------
file=/dita/log/squid3_cache.log

if [ -f "$file" ]; then
  	cp $file /media/sf_install_disk_als/back_end/logfile/squid3_cache.log
fi

#-----------------------------------------------------------------
# vsftp -- vsftp.log
#-----------------------------------------------------------------
file=/dita/log/vsftpd.log

if [ -f "$file" ]; then
  	cp $file /media/sf_install_disk_als/back_end/logfile
fi

#-----------------------------------------------------------------
# vsftp -- xferlog
#-----------------------------------------------------------------
file=/dita/log/xferlog

if [ -f "$file" ]; then
  	cp $file /media/sf_install_disk_als/back_end/logfile
fi

#-----------------------------------------------------------------
# sshd.log
#-----------------------------------------------------------------
file=/dita/log/sshd.log

if [ -f "$file" ]; then
  	cp $file /media/sf_install_disk_als/back_end/logfile
fi

#-----------------------------------------------------------------
# iptables.log
#-----------------------------------------------------------------
#file=/dita/log/iptables.log
#
#if [ -f "$file" ]; then
#  	cp $file /media/sf_install_disk_als/back_end/logfile
#fi

