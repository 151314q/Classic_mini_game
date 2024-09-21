#ifndef __GOBANG_BEGINOVER_H__
#define __GOBANG_BEGINOVER_H__

#include"gobang_process.h"

typedef struct Node{
    int x;  //一维数组首地址下标
    int y; 
    struct Node* next;
}Node;      //棋子存放

typedef struct List{
    Node* first;
    Node* last;
}List;


/*画棋盘*/
void lcd_chessboard();

/*点击函数，获取坐标确定落子位置*/
void get_chess_position(int *x,int *y);

/*人机对战获取坐标位置*/
void get_chess_position_machine(int *x,int *y);

/*画圆代表棋子，在坐标上画圆*/
void draw_chess_circle(int x,int y);

/*生成结点*/
Node* new_node(int x,int y);

/*头节点初始化*/
List* create_list();

/*
    作用：将棋子信息入栈
    参数：listgobang, x, y
*/
void push_listgobang(List *listgobang,int x,int y);

/*
    出栈
    参数：listgobang
    返回值：Node
*/
Node* pop_listgobang(List* listgobang);

/*悔棋具体操作，悔棋过后跟新棋盘*/
int regret_gobang(Node *time1);

/*第一个人下棋的情况*/
int one_people();

/*第二个人下棋的情况*/
int two_people();

/*判断游戏结束情况*/
int judge_gobang(int x);

/*双人对战*/
void double_against();

/***************************人机对战****************************/
void Man_machine_versus();

/*人机程序*/
int man_machine(int x0,int y0);

/*人机寻找对手的最高优先级和相应的需要落子的位置*/
void find_maybe(int *x,int *y,int *zi);

/*人机寻找自己的最高优先级和相应的需要落子的位置*/
void find_maybe_machine(int *x,int *y,int *z0);



#endif
