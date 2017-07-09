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

ASMLIBFLAGS	= -I src/include/ -I src/lib/ -f elf

CFLAGS		= -I src/include/ -c -fno-builtin -w -fno-stack-protector
LDFLAGS		= -Map mon.map $(LOBJS_UBUNTU)
ARFLAGS		= rcs

# This Program
MONITOR		= dst/mon
LIB		= dst/mon.a

OBJS		= $(OBJS_MAIN)\
			$(OBJS_SQL) $(OBJS_FILE_PARSE)\
			$(OBJS_DB)


OBJS_MAIN	= src/main/main.o


LOBJS_UBUNTU	= /usr/lib/x86_64-linux-gnu/crt1.o\
			/usr/lib/x86_64-linux-gnu/crti.o\
			/usr/lib/gcc/x86_64-linux-gnu/4.6/crtbegin.o\
			-lc /usr/lib/gcc/x86_64-linux-gnu/4.6/crtend.o\
			/usr/lib/x86_64-linux-gnu/crtn.o\
			-dynamic-linker /lib64/ld-linux-x86-64.so.2
	
LOBJS		= src/lib/strings.o

all : realclean everything clean

realclean :
	rm -f  $(OBJS) $(LOBJS) $(LIB)

clean :
	rm -f $(OBJS) $(LOBJS)

everything : $(MONITOR) $(OBJS) $(LOBJS)


$(MONITOR) : $(OBJS) $(LIB)
	$(LD) $(LDFLAGS) -o $(MONITOR) $^

$(LIB) : $(LOBJS)
	$(AR) $(ARFLAGS) $@ $^

src/main/main.o: src/main/main.c
	$(CC) $(CFLAGS) -o $@ $<

src/lib/strings.o: src/lib/strings.c
	$(CC) $(CFLAGS) -o $@ $<
