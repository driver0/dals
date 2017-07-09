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

#CFLAGS		= -I src/include/ -c -fno-builtin -w -fno-stack-protector
CFLAGS		= -I src/include/ -I /usr/include/mysql -c -fno-builtin -w -fno-stack-protector -DBIG_JOINS=1 -fno-strict-aliasing -g
LDFLAGS		= -Map als.map $(LOBJS_UBUNTU) $(MYSQLFLAGS)
ARFLAGS		= rcs
MYSQLFLAGS	= -lmysqlclient
#MYSQLFLAGS	= `mysql_config --cflags --libs`
#MYSQLFLAGS	= -L /usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -lrt -ldl

# This Program
ALS		= dst/als
LIB		= dst/als.a

OBJS		= $(OBJS_MAIN)\
			$(OBJS_SQL) $(OBJS_FILE_PARSE)\
			$(OBJS_DB)


OBJS_MAIN	= src/main/main.o
OBJS_SQL	= src/db/db_main.o\
			src/db/db.o

OBJS_FILE_PARSE	= src/file2tmp/file_parse_main.o\
			src/file2tmp/file_parse.o\
			src/file2tmp/apache2_access_file_parse.o\
			src/file2tmp/apache2_error_file_parse.o\
			src/file2tmp/xferlog_file_parse.o\
			src/file2tmp/vsftpd_file_parse.o\
			src/file2tmp/squid3_access_file_parse.o\
			src/file2tmp/squid3_cache_file_parse.o\
			src/file2tmp/dns_file_parse.o\
			src/file2tmp/sendmail_file_parse.o\
			src/file2tmp/iptables_file_parse.o\
			src/file2tmp/sshd_file_parse.o\
			src/file2tmp/apache2_tls_access_file_parse.o\
			src/file2tmp/apache2_tls_error_file_parse.o\

OBJS_DB		= src/tmp2db/tmp2db_main.o\
			src/tmp2db/tmp2db.o\
			src/tmp2db/sendmail_tmp2db.o\
			src/tmp2db/dns_tmp2db.o\
			src/tmp2db/squid3_cache_tmp2db.o\
			src/tmp2db/squid3_access_tmp2db.o\
			src/tmp2db/vsftpd_tmp2db.o\
			src/tmp2db/xferlog_tmp2db.o\
			src/tmp2db/apache2_access_tmp2db.o\
			src/tmp2db/apache2_error_tmp2db.o\
			src/tmp2db/iptables_tmp2db.o\
			src/tmp2db/sshd_tmp2db.o\
			src/tmp2db/apache2_tls_access_tmp2db.o\
			src/tmp2db/apache2_tls_error_tmp2db.o

LOBJS_UBUNTU	= /usr/lib/x86_64-linux-gnu/crt1.o\
			/usr/lib/x86_64-linux-gnu/crti.o\
			/usr/lib/gcc/x86_64-linux-gnu/4.6/crtbegin.o\
			-lc /usr/lib/gcc/x86_64-linux-gnu/4.6/crtend.o\
			/usr/lib/x86_64-linux-gnu/crtn.o\
			-dynamic-linker /lib64/ld-linux-x86-64.so.2
	
#LOBJS		= src/lib/lib.o src/lib/liba.o
LOBJS		= src/lib/strings.o\
			src/lib/lib.o

all : realclean everything clean

realclean :
	rm -f  $(OBJS) $(LOBJS) $(LIB)

clean :
	rm -f $(OBJS) $(LOBJS)

everything : $(ALS) $(OBJS) $(LOBJS)


$(ALS) : $(OBJS) $(LIB)
	$(LD) $(LDFLAGS) -o $(ALS) $^

$(LIB) : $(LOBJS)
	$(AR) $(ARFLAGS) $@ $^

src/main/main.o: src/main/main.c
	$(CC) $(CFLAGS) -o $@ $<

src/db/db.o: src/db/db.c
	$(CC) $(CFLAGS) -o $@ $<

src/db/db_main.o: src/db/db_main.c
	$(CC) $(CFLAGS) -o $@ $<

src/file2tmp/file_parse.o: src/file2tmp/file_parse.c
	$(CC) $(CFLAGS) -o $@ $<

src/file2tmp/file_parse_main.o: src/file2tmp/file_parse_main.c
	$(CC) $(CFLAGS) -o $@ $<

src/file2tmp/apache2_access_file_parse.o: src/file2tmp/apache2_access_file_parse.c
	$(CC) $(CFLAGS) -o $@ $<

src/file2tmp/apache2_error_file_parse.o: src/file2tmp/apache2_error_file_parse.c
	$(CC) $(CFLAGS) -o $@ $<

src/file2tmp/xferlog_file_parse.o: src/file2tmp/xferlog_file_parse.c
	$(CC) $(CFLAGS) -o $@ $<

src/file2tmp/vsftpd_file_parse.o: src/file2tmp/vsftpd_file_parse.c
	$(CC) $(CFLAGS) -o $@ $<

src/file2tmp/squid3_access_file_parse.o: src/file2tmp/squid3_access_file_parse.c
	$(CC) $(CFLAGS) -o $@ $<

src/file2tmp/squid3_cache_file_parse.o: src/file2tmp/squid3_cache_file_parse.c
	$(CC) $(CFLAGS) -o $@ $<

src/file2tmp/dns_file_parse.o: src/file2tmp/dns_file_parse.c
	$(CC) $(CFLAGS) -o $@ $<

src/file2tmp/sendmail_file_parse.o: src/file2tmp/sendmail_file_parse.c
	$(CC) $(CFLAGS) -o $@ $<

src/file2tmp/iptables_file_parse.o: src/file2tmp/iptables_file_parse.c
	$(CC) $(CFLAGS) -o $@ $<

src/file2tmp/sshd_file_parse.o: src/file2tmp/sshd_file_parse.c
	$(CC) $(CFLAGS) -o $@ $<

src/file2tmp/apache2_tls_access_file_parse.o: src/file2tmp/apache2_tls_access_file_parse.c
	$(CC) $(CFLAGS) -o $@ $<

src/file2tmp/apache2_tls_error_file_parse.o: src/file2tmp/apache2_tls_error_file_parse.c
	$(CC) $(CFLAGS) -o $@ $<

src/lib/strings.o: src/lib/strings.c
	$(CC) $(CFLAGS) -o $@ $<

src/lib/lib.o: src/lib/lib.c
	$(CC) $(CFLAGS) -o $@ $<

src/tmp2db/tmp2db.o: src/tmp2db/tmp2db.c
	$(CC) $(CFLAGS) -o $@ $<

src/tmp2db/tmp2db_main.o: src/tmp2db/tmp2db_main.c
	$(CC) $(CFLAGS) -o $@ $<

src/tmp2db/sendmail_tmp2db.o: src/tmp2db/sendmail_tmp2db.c
	$(CC) $(CFLAGS) -o $@ $<

src/tmp2db/dns_tmp2db.o: src/tmp2db/dns_tmp2db.c
	$(CC) $(CFLAGS) -o $@ $<

src/tmp2db/squid3_cache_tmp2db.o: src/tmp2db/squid3_cache_tmp2db.c
	$(CC) $(CFLAGS) -o $@ $<

src/tmp2db/squid3_access_tmp2db.o: src/tmp2db/squid3_access_tmp2db.c
	$(CC) $(CFLAGS) -o $@ $<

src/tmp2db/vsftpd_tmp2db.o: src/tmp2db/vsftpd_tmp2db.c
	$(CC) $(CFLAGS) -o $@ $<

src/tmp2db/xferlog_tmp2db.o: src/tmp2db/xferlog_tmp2db.c
	$(CC) $(CFLAGS) -o $@ $<

src/tmp2db/apache2_access_tmp2db.o: src/tmp2db/apache2_access_tmp2db.c
	$(CC) $(CFLAGS) -o $@ $<

src/tmp2db/apache2_error_tmp2db.o: src/tmp2db/apache2_error_tmp2db.c
	$(CC) $(CFLAGS) -o $@ $<

src/tmp2db/iptables_tmp2db.o: src/tmp2db/iptables_tmp2db.c
	$(CC) $(CFLAGS) -o $@ $<

src/tmp2db/sshd_tmp2db.o: src/tmp2db/sshd_tmp2db.c
	$(CC) $(CFLAGS) -o $@ $<

src/tmp2db/apache2_tls_access_tmp2db.o: src/tmp2db/apache2_tls_access_tmp2db.c
	$(CC) $(CFLAGS) -o $@ $<

src/tmp2db/apache2_tls_error_tmp2db.o: src/tmp2db/apache2_tls_error_tmp2db.c
	$(CC) $(CFLAGS) -o $@ $<
