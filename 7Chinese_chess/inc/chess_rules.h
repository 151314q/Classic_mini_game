#ifndef __CHESS_RULES_H__
#define __CHESS_RULES_H__

#include "chess_Initial.h"

/*判断“车”移动是否有效
    输入：i0、j0为移动前位置；i1、j1为移动后位置
    返回值：1有效 0无效
*/
int rules_ju(int i0, int j0, int i1, int j1);

/*判断 “马” 移动是否有效
    输入：i0、j0为移动前位置；i1、j1为移动后位置
    返回值：1有效 0无效
*/
int rules_ma(int i0, int j0, int i1, int j1);

/*判断 “相--象” 移动是否有效
    输入：i0、j0为移动前位置；i1、j1为移动后位置
    返回值：1有效 0无效
*/
int rules_xiang(int i0, int j0, int i1, int j1);

/*判断 “士--仕” 移动是否有效
    输入：i0、j0为移动前位置；i1、j1为移动后位置
    返回值：1有效 0无效
*/
int rules_shi(int i0, int j0, int i1, int j1);

/*判断 “炮” 移动是否有效
    输入：i0、j0为移动前位置；i1、j1为移动后位置
    返回值：1有效 0无效
*/
int rules_pao(int i0, int j0, int i1, int j1);

/*判断 “将--帅” 移动是否有效
    输入：i0、j0为移动前位置；i1、j1为移动后位置
    返回值：1有效 0无效
*/
int rules_jiang(int i0, int j0, int i1, int j1);

/*判断 “兵--卒” 移动是否有效
    输入：i0、j0为移动前位置；i1、j1为移动后位置
    返回值：1有效 0无效
*/
int rules_bing(int i0, int j0, int i1, int j1);

/*
    通过读取数组元素值来选择对应棋子的移动规则
    输入：i0、j0初始下标  i1、j1目标下标
    返回值：1成功，0失败
*/
int Selection_rule(int i0, int j0, int i1, int j1);

#endif