#===========================================================================
# daily.sh
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
# 获取日志文件
#-----------------------------------------------------------------
source script/getlogfiles_daily.sh &> getlogfile_daily.log

#-----------------------------------------------------------------
# 将日志文件写入数据库（建立tmp table）
#-----------------------------------------------------------------
dst/als 2 &> als_2.log

#-----------------------------------------------------------------
# 将tmp table写入真正的数据表
#-----------------------------------------------------------------
dst/als 3 &> als_3.log

#-----------------------------------------------------------------
# 将web目录下的文件复制到 /var/www/log_check
#-----------------------------------------------------------------
cp src/web/*.* /var/www/log_check

chmod 777 /var/www/log_check/*
