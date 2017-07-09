//===========================================================================
// main.c
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
#include	<gtk/gtk.h> 
#include 	"dwin_type.h"
#include 	"dwin_prototype.h"
#include 	"dwin_global.h"

//安装：sudo apt-get install libgtk2.0-dev
//
//编译：gcc `pkg-config --cflags --libs gtk+-2.0` test_1.c -o test_1 `pkg-config --cflags --libs gtk+-2.0`


 
//===========================================================================
// “按下”按钮事件：
//	按钮后会输出 "exit"
//===========================================================================
PUBLIC	void btn_alarm(GtkWidget *widget,gpointer data)  
{  
        g_print("exit!\n");  
}  

//===========================================================================
// “删除”按钮事件：
//===========================================================================
PUBLIC	gint delete_event(GtkWidget *widget,GdkEvent *event,gpointer data)  
{  
        g_print ("delete event occurred\n");  
        return(TRUE);  
}  

//===========================================================================
// “析构”按钮事件：
//===========================================================================
PUBLIC	void destroy(GtkWidget *widget,gpointer data)  
{  
        gtk_main_quit();  
}

//===========================================================================
// 主程序入口：
//===========================================================================
PUBLIC	s32 main(s32 argc, s8 *argv[])  
{  
	s8 head_title[8]="Alarm";

        GtkWidget *window;  
        GtkWidget *button;  
        gtk_init(&argc, &argv);  

	//---------------------------------------------------------------
	// 窗口设置（外观）
	//---------------------------------------------------------------
        window=gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW (window),head_title);
	//gtk_widget_set_usize(window, 400, 200);	//长：400,宽：200
	gtk_window_set_default_size(GTK_WINDOW(window),400,200);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window), 8); 	//边框
	gtk_window_set_keep_above(GTK_WINDOW(window), TRUE);		//窗口始终在最前面

	//---------------------------------------------------------------
	// 窗口设置（事件响应）
	//---------------------------------------------------------------
        gtk_signal_connect (GTK_OBJECT(window),"delete_event",GTK_SIGNAL_FUNC(delete_event),NULL);  
        gtk_signal_connect (GTK_OBJECT (window), "destroy",GTK_SIGNAL_FUNC(destroy), NULL);  
        

	//---------------------------------------------------------------
	// 按键设置（外观）
	//---------------------------------------------------------------
	button = gtk_button_new_with_label(argv[1]);		//按键的显示内容为“输入参数1” 
  
	//---------------------------------------------------------------
	// 按键设置（事件）
	//---------------------------------------------------------------
        gtk_signal_connect(GTK_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(btn_alarm), NULL);  
        gtk_signal_connect_object(GTK_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(gtk_widget_destroy),GTK_OBJECT(window));  

	//---------------------------------------------------------------
	// 将“按键”加入到“窗口”
	//---------------------------------------------------------------
        gtk_container_add (GTK_CONTAINER(window), button); 

	//---------------------------------------------------------------
	// “画” 按键 和 窗口
	//--------------------------------------------------------------- 
        gtk_widget_show(button);  
        gtk_widget_show(window);  

	//---------------------------------------------------------------
	// 死循环
	//--------------------------------------------------------------- 
        gtk_main(); 
  
        return(0);  
}  
