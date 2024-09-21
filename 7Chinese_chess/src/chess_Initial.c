//象棋初始化文件
#include "chess_Initial.h"

int data_chess[400/40][360/40]={0};    //棋盘数组，间隔大小为40
/*  
    绘制象棋棋盘
*/
void lcd_chinachessBoard()
{
    lcd_draw_plane(0xffffffff);     //线将整个面化成棕色
    for(int x=40;x<=360;x++)
    {
        for(int y=60;y<=420;y++)
        {
            if((x%40==0&&(y>=260||y<=220)) || (y+20)%40==0)
                lcd_draw_point(x,y,0xff000000);
        }
    }
    for(int i=220;i<=260;i++)
    {
        lcd_draw_point(40,i,0xff000000);
        lcd_draw_point(360,i,0xff000000);
    }
    lcd_draw_segment(160,60,240,140);   //绘制将帅移动范围叉
    lcd_draw_segment(240,60,160,140);
    lcd_draw_segment(160,340,240,420);
    lcd_draw_segment(240,340,160,420);

    useing_word_chuhe(0xffff0000);      //显示楚河汉界
    lcd_repret_peace();     //显示游戏悔棋、求和按键
}

/*初始化游戏悔棋、求和按键*/
void lcd_repret_peace()
{
    lcd_draw_bmp(400,40,"./peace2.bmp");
    lcd_draw_bmp(500,40,"./regret2.bmp");
    lcd_draw_bmp(400,390,"./peace1.bmp");
    lcd_draw_bmp(500,390,"./regret1.bmp");
}

//放置棋子初始位置
void lcd_chess_pieces(void)
{
    //黑棋
    data_chess[0][0]=data_chess[0][8]=1;    //车
    data_chess[0][1]=data_chess[0][7]=2;    //马
    data_chess[0][2]=data_chess[0][6]=3;    //象
    data_chess[0][3]=data_chess[0][5]=4;    //士
    data_chess[0][4]=5;                     //将
    data_chess[2][1]=data_chess[2][7]=6;    //炮
    data_chess[3][0]=data_chess[3][2]=data_chess[3][4]=data_chess[3][6]=data_chess[3][8]=7;//卒
    //红棋
    data_chess[9][0]=data_chess[9][8]=11;    //车
    data_chess[9][1]=data_chess[9][7]=12;    //马
    data_chess[9][2]=data_chess[9][6]=13;    //相
    data_chess[9][3]=data_chess[9][5]=14;    //仕
    data_chess[9][4]=15;                     //帅
    data_chess[7][1]=data_chess[7][7]=16;    //炮
    data_chess[6][0]=data_chess[6][2]=data_chess[6][4]=data_chess[6][6]=data_chess[6][8]=17;//兵
}

/*
    在显示屏上显示棋子
*/
void display_china_chess()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(data_chess[i][j]!=0)
            {
                char buf[32];
                sprintf(buf,"./%d.bmp",data_chess[i][j]);       //sprintf中决定了图片路径
                lcd_draw_bmp(20+j*40, 40+40*i, buf);
            }
        }
    }
}


/*创建一个头结点*/
Headweek* creat_head()
{
    Headweek* head=(Headweek*)malloc(sizeof(Headweek));
    head->first=NULL;
    head->last=NULL;
    head->num=0;
    return head;
}

/*元素入栈,使用头插
    参数：head为要入栈的栈的头结点
        ：i0、j0为移动前下标位置。
        ：i1、j1为移动后下标位置*/
void push_week(Headweek* head, int i0,int j0,int data0,int i1,int j1,int data1)
{
    Weekplayer* new=(Weekplayer*)malloc(sizeof(Weekplayer));
    new->next=NULL;
    new->i0=i0;
    new->j0=j0;
    new->data0=data0;
    new->i1=i1;
    new->j1=j1;
    new->data1=data1;
    if(head->first==NULL)   //没有结点的情况
    {
        head->first=head->last=new;
    }
    else
    {
        new->next=head->first;
        head->first=new;
    }
    head->num++;    //结点数量加一
}

/*出栈，返回值为一个结点类型*/
Weekplayer* pop_week(Headweek* head)
{
    if(head->num==0)    //栈中没有元素，无法出栈
        return NULL;
    Weekplayer* node=head->first;
    head->first=head->first->next;
    node->next=NULL;
    head->num--;
    return node;
}
