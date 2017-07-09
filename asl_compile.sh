#===========================================================================
# als.sh
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

#-------------------------------------------------------------------------
# (1) 编译日志文件入数据库的程序
#-------------------------------------------------------------------------
cd back_end
make all

#-------------------------------------------------------------------------
# (2) 编译日志变动监控程序
#-------------------------------------------------------------------------
cd ../mid_end
make all

#-------------------------------------------------------------------------
# (3) 编译告警窗口
#-------------------------------------------------------------------------
cd ../front_end
make all



