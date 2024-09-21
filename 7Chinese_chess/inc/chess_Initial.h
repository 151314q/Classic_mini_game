#ifndef __CHESS_INITIAL_H__
#define __CHESS_INITIAL_H__
#include "lcd.h"
#include "Touch.h"
#include "bmp.h"

/*画象棋棋盘*/
void lcd_chinachessBoard();

/*初始化游戏悔棋、求和按键*/
void lcd_repret_peace();

//放置棋子初始位置
void lcd_chess_pieces(void);

/*
    在显示屏上显示棋子
*/
void display_china_chess();

typedef struct WeekPlayer{
    int i0;
    int j0;
    int data0;
    int i1;
    int j1;
    int data1;
    struct WeekPlayer *next;
}Weekplayer;    //留给弱者的，用于悔棋的结点类型

typedef struct HeadWeek{
    Weekplayer* first;
    Weekplayer* last;
    int num;
}Headweek;      //头结点

/*创建一个头结点*/
Headweek* creat_head();

/*元素入栈,使用头插
    参数：head为要入栈的栈的头结点
        ：i0、j0为移动前下标位置。
        ：i1、j1为移动后下标位置*/
void push_week(Headweek* head, int i0,int j0,int data0,int i1,int j1,int data1);

/*出栈，返回值为一个结点类型*/
Weekplayer* pop_week(Headweek* head);

#endif //  __CHESS_INITIAL_H__#define __CHESS_INITIAL_H__
