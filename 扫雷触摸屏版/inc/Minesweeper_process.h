#ifndef __MINESWEEPER_PROCESS_H__
#define __MINESWEEPER_PROCESS_H__

#include "Minesweeper_bagin.h"

/*标记雷，z为int quxiao()函数的返回值*/
int bomb_w(int x,int y,int z);

/*
    取消标记函数
    取消标记过的雷
*/
int quxiao_(int x,int y,int z);

/*
    点击操作函数
    参数：二维数组的下标
    返回值：0（点雷）、1（不是雷）
*/
int click_e(int x,int y);

/*将所有连在一起的空白区域递归出来，配合click_e函数使用*/
void di_gui(int x, int y);

#endif