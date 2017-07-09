#===========================================================================
# Makefile
#   Copyright (C) 2017 Free Software Foundation, Inc.
#   Originally by ZhaoFeng Liang <zhf.liang@outlook.com>
#
#This file is part of DTHAS_ALS.
#
#DTAHS is free software; you can redistribute it and/or modify
#it under the terms of the GNU General Public License as published by
#the Free Software Foundation; either version 2 of the License, or 
#(at your option) any later version.
#
#DTAHS is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.
#
#You should have received a copy of the GNU General Public License
#along with DTHAS_ALS; If not, see <http://www.gnu.org/licenses/>.  
#===========================================================================

# Programs, flags, etc.
ASM		= nasm
CC		= gcc
LD		= ld

CFLAGS		= -I src/include/
CFLAGS_GTK	= `pkg-config --cflags --libs gtk+-2.0`


# This Program
DWIN		= dst/dwin

OBJS		= src/main/main.o


all : realclean everything clean

realclean :
	rm -f  $(OBJS) $(LOBJS) $(LIB)

clean :
	rm -f $(OBJS) $(LOBJS)

everything : $(DWIN)


$(DWIN) : src/main/main.c
	$(CC)  $(CFLAGS) $(CFLAGS_GTK) src/main/main.c -o $@ $(CFLAGS_GTK)
