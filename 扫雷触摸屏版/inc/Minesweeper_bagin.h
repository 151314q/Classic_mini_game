#ifndef __MINESWEEPER_BAGIN_H__
#define __MINESWEEPER_BAGIN_H__

#define N 15    //15为正方形扫雷棋盘的边
//#define N1 30   //雷的数量，此处采用宏定义

#include<time.h>
#include"lcd.h"
#include "bmp.h"
#include "Touch.h"

/*
    扫雷初始化：扫雷棋盘的雷位置的随机抽取，及雷身边的数字信息
*/
void chu_shi_hua();

/*扫雷字符版打印*/
void da_ying();

/*显示扫雷游戏界面*/
void saolei_jiemian();

/*显示点击元素对应数组对应的图片*/
void xianshi_bmp(int x,int y);

/*获取触摸地区对应的数组下标*/
void get_saolei_poition(int *x,int *y);

/*扫雷难度选择*/
int get_game_difficulty();

/*扫雷功能键获取，每次点击之前先判断是经行什么操作*/
int get_function_poition();

#endif