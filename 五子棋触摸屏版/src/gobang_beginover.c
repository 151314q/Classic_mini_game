#include "gobang_beginover.h"
extern char data_gobang[400/25][600/25];

/*画棋盘*/
void lcd_chessboard()
{
    lcd_draw_plane(0xffcd8162);   //先将整个面化成棕色
    //每阁25个像素点画线，横竖方向一样
    for(int i=25;i<=600;i++)
    {
        for(int j=25;j<=400;j++)
        {
            if(i%25==0 || j%25==0)
                lcd_draw_point(i,j,0xffff0000);
        }
    }
}

/*第一个人下棋的情况，用‘x’代表其棋子*/
int one_people(int *p,int *q)
{
    int x=*p,y=*q;

    data_gobang[x][y]='x';
    draw_chess_circle(x,y);
    int z=request_(x,y);
    return z;
}

/*第二个人下棋的情况,用‘o’代表其棋子*/
int two_people(int *p,int *q)
{
    int x=*p,y=*q;

    data_gobang[x][y]='o';
    draw_chess_circle(x,y);
    int z=request_(x,y);
    return z;
}

/*点击函数，获取坐标确定落子位置*/
void get_chess_position(int *x,int *y)
{
fan:
    get_xy(x,y);
    exchang_data(x,y);
    if((*x>625) || *y>425)    //超过625、425范围视为点击无效
    {
        if(*x>650 && *x<750 && *y>50 && *y<100)
        {
            printf("悔棋成功\n");
        }
        else if(*x>650 && *x<750 && *y>150 && *y<200)
        {
            printf("认输了\n");
        }
        else if(*x>650 && *x<750 && *y>250 && *y<300)
        {
            printf("退出人机对战/双人对战\n");
        }
        else                  //点击不成功，重新获取
            goto fan;
    }

    if(*x%25 < 12 || *x<25)  //确定x坐标对应数组的位置
    {
        *x=(*x/25==0)? 0 : *x/25-1;   //当x<25时，视为下标为0的元素
    }
    else
        *x=*x/25+1-1;            //减一的目的是为了对应数组下标

    if(*y%25 < 12 || *y<25)  //确定y坐标对应数组的位置
    {
        *y=(*y/25==0)? 0 : *y/25-1;
    }
    else
        *y=*y/25+1-1;

    int temp;
    temp = *x;
    *x = *y;
    *y = temp;   // 这里将x、y的下标交换一下
}

/*人机对战获取坐标位置*/
void get_chess_position_machine(int *x,int *y)
{
fan:
    get_xy(x,y);
    exchang_data(x,y);
    if((*x>625) || *y>425)    //超过625、425范围视为点击无效
    {
        if(*x>650 && *x<750 && *y>50 && *y<100)
        {
            printf("退出人机对战\n");
        }
        else                  //点击不成功，重新获取
            goto fan;
    }

    if(*x%25 < 12 || *x<25)  //确定x坐标对应数组的位置
    {
        *x=(*x/25==0)? 0 : *x/25-1;   //当x<25时，视为下标为0的元素
    }
    else
        *x=*x/25+1-1;            //减一的目的是为了对应数组下标

    if(*y%25 < 12 || *y<25)  //确定y坐标对应数组的位置
    {
        *y=(*y/25==0)? 0 : *y/25-1;
    }
    else
        *y=*y/25+1-1;

    int temp;
    temp = *x;
    *x = *y;
    *y = temp;   // 这里将x、y的下标交换一下
}

/*画圆代表棋子，在坐标上画圆*/
void draw_chess_circle(int x,int y)
{
    if(data_gobang[x][y] == 'x')    //在屏幕上进行画圆，黑棋代表第一个人
        draw_circle( (y+1) * 25, (x+1) * 25, 25/2, 0xff000000);
    else if(data_gobang[x][y] == 'o')   //白棋代表第二个人
        draw_circle( (y+1) * 25, (x+1) * 25, 25/2, 0xffffffff);        
}

/********************************悔棋功能********************************/
/*生成结点*/
Node* new_node(int x,int y)
{
    Node *new=malloc(sizeof(Node));
    new->x=x;
    new->y=y;
    new->next=NULL;
    return new;
}

/*头节点初始化*/
List* create_list()
{
    List *listgobang=malloc(sizeof(List));
    listgobang->first=NULL;
    listgobang->last=NULL;
    return listgobang;
}

/*
    作用：将棋子信息入栈
    参数：listgobang, x, y
*/
void push_listgobang(List *listgobang,int x,int y)
{
    Node *new=new_node(x,y);

    if(listgobang->first==NULL)
    {
        listgobang->first=new;
        listgobang->last=new;
    }
    else
    {
        //头插
        new->next=listgobang->first;
        listgobang->first=new;
    }
}

/*
    出栈
    参数：listgobang
    返回值：Node
*/
Node* pop_listgobang(List* listgobang)
{
    Node* p=NULL;
    Node* q=listgobang->first;
    if(listgobang->first==NULL)
    {
        printf("栈为空，不可再悔棋\n");
        return NULL;
    }
    p=q;
    q=q->next;
    p->next=NULL;
    listgobang->first=q;

    return p;
}

/*悔棋具体操作，悔棋过后跟新棋盘*/
int regret_gobang(Node *time1)
{
    char sign=data_gobang[time1->x][time1->y];
    data_gobang[time1->x][time1->y]=0;

    //重新画棋盘，并将已记录的棋子也打印出来
    lcd_chessboard();
    lcd_draw_bmp(650,50,"regret.bmp");
    lcd_draw_bmp(650,150,"rshu.bmp");
    lcd_draw_bmp(650,250,"tuichu.bmp");
    for(int i=0;i<400/25;i++)
    {
        for(int j=0;j<600/25;j++)
        {
            if(data_gobang[i][j]!=0)
            {
                draw_chess_circle(i,j);
            }
        }
    }

    if(sign=='x')    //代表黑棋悔棋
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

/********************************结束条件********************************/
int judge_gobang(int x)               //游戏结束条件
{

    if(x==1)    return 1;       //1赢
    else if(x==2)   return 2;  //2赢

    int count=0;
    for(int i=0;i<400/25;i++)
        for(int j=0;j<600/25;j++)
            if(data_gobang[i][j]==0)
            {
                count++;
                break;
            }
    if(count==0)
        return 0;              //棋子填满，游戏结束，和棋
    else return 3;         //继续游戏
}


/************************双人对战*****************************************/
void double_against()
{
    for(int i=0;i<16;i++)
        for(int j=0;j<24;j++)
            data_gobang[i][j]=0;

    lcd_chessboard();
    lcd_draw_bmp(650,50,"regret.bmp");
    lcd_draw_bmp(650,150,"rshu.bmp");
    lcd_draw_bmp(650,250,"tuichu.bmp");
    List* listgobang=create_list();

    int Z1, Z2; // 玩家1和玩家2的获胜标识符
    while (1)
    {
        int x, y;
    xun:
        get_chess_position(&x, &y);
        // printf("x=%d,y=%d\n",x,y);
        if(y>=24)   
        {
            if(x<=3)    //  悔棋    
            {
                Node* time1=pop_listgobang(listgobang);
                if(time1!=NULL)
                {
                    int tmpe2=regret_gobang(time1);
                    printf("tmpe2=%d\n",tmpe2);
                    if(tmpe2==1)
                        goto xun;   //第一个人悔棋
                    else
                        goto xun1;  //第二个人悔棋
                }
                else goto xun;
            }
            else if(x<=7)   //认输
            {
                printf("play2 win!\n");
                useing_word(0xffffffff);
                sleep(5);
                break;
            }
            else if(x<=11)  //退出双人对战
            {
                break;
            }
        }
        else if (data_gobang[x][y] != 0)
        {
            printf("该处已落子，请重新下子\n");
            goto xun;
        } 
        // 确定落子有效
        //此时将棋子的信息入栈
        push_listgobang(listgobang,x,y);
        Z1 = one_people(&x, &y);    //玩家1的环节
        //printf("Z1=%d\n",Z1);
        if (judge_gobang(Z1) == 1)
        {
            printf("play1 win!\n");
            useing_word(0xff000000);
            sleep(5);
            break;
        }
        else if (judge_gobang(Z1) == 0)
        {
            printf("和棋\n");
            sleep(5);
            break;
        }

    xun1:
        get_chess_position(&x, &y);
        // printf("x=%d,y=%d\n",x,y);
        if(y>=24)
        {
            if(x<=3)    //悔棋
            {
                Node* time1=pop_listgobang(listgobang);
                if(time1!=NULL)
                {
                    int tmpe2=regret_gobang(time1);
                    printf("tmpe2=%d\n",tmpe2);
                    if(tmpe2==1)
                        goto xun;   //第一个人悔棋
                    else
                        goto xun1;  //第二个人悔棋
                }
                else goto xun;
            }
            else if(x<=7)   //选手2认输
            {
                printf("play1 win!\n");
                useing_word(0xff000000);
                sleep(5);
                break;
            }
            else if(x<=11)  //退出双人对战
            {
                break;
            }
        }
        if (data_gobang[x][y] != 0)
        {
            printf("该处已落子，请重新下子\n");
            goto xun1;
        }
        // 确定落子是有效的
        //此时将棋子的信息入栈
        push_listgobang(listgobang,x,y);
        Z2 = two_people(&x, &y);    //玩家2的环节
        //printf("Z2=%d\n",Z2);
        if (judge_gobang(Z2) == 2)
        {
            printf("play2 win!\n");
            useing_word(0xffffffff);
            sleep(5);
            break;
        }
        else if (judge_gobang(Z2) == 0)
        {
            printf("和棋\n");
            sleep(5);
            break;
        }
    }
}

/***************************人机对战****************************/
void Man_machine_versus()
{
    for(int i=0;i<16;i++)
        for(int j=0;j<24;j++)
            data_gobang[i][j]=0;

    lcd_chessboard();
    lcd_draw_bmp(650,50,"tuichu.bmp");
    int x,y,Z1;
    while(1)
    {
    fan:
        get_chess_position_machine(&x,&y);
        if(y>=24)
        {
            if(x<=3)
            {
                //printf("退出人机对战\n");
                break;
            }
        }
        if(data_gobang[x][y]!=0)
        {
            printf("此处已经落子，请重新落子\n");
            goto fan;
        }

        //落子有效
        Z1=one_people(&x,&y);
        if (judge_gobang(Z1) == 1)
        {
            printf("play1 win!\n");
            useing_word(0xff000000);
            break;
        }
        else if (judge_gobang(Z1) == 0)
        {
            printf("和棋\n");
            break;
        }
        sleep(1);

        int Z2;
        Z2=man_machine(x,y);       //调用人机函数
        if (judge_gobang(Z2) == 2)
        {
            printf("play2 win!\n");
            useing_word(0xffffffff);
            break;
        }
        else if (judge_gobang(Z2) == 0)
        {
            printf("和棋\n");
            break;
        }
    }
}

/*人机程序*/
int man_machine(int x0,int y0)
{
    int zi=1;     //用于记录当前棋子优先级
    int x,y;
    int Z2;     //人机判断输赢标志位
    find_maybe(&x0,&y0,&zi);
    printf("x=%d,y=%d,zi=%d\n",x,y,zi);

    printf("----%d----\n",__LINE__);
    Z2=two_people(&x,&y);
    
    return Z2;
}

/*人机寻找对手的最高优先级和相应的需要落子的位置*/
void find_maybe(int *x,int *y,int *zi)
{
    
}

/*人机寻找自己的最高优先级和相应的需要落子的位置*/
void find_maybe_machine(int *x,int *y,int *z0)
{
    int x0=*x,y0=*y;  //存储玩家的落子信息
    int x1,y1;
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<24;j++)
        {
            if(data_gobang[i][j]=='o')
            {
                *z0=1;
                x1=i,y1=j;
                //横竖斜方向标志位
                typedef struct ZHSX{
                    int z;  //标志位
                    int b;  //判断标志位是否改变的标志位
                    int x;
                    int y;
                }ZHSX;
                ZHSX zhsx[3]={{1,1},{1,1},{1,1}};
                for(int k=0; k<5; k++)
                {
                    if(data_gobang[i+k][j]==0 && i+k+1<16 && zhsx[1].b==1)
                    {
                        zhsx[1].z++;
                        zhsx[1].x=i+k+1;
                        zhsx[1].y=j;
                    }
                    else if(data_gobang[i+k][j]=='x')
                    {
                        zhsx[1].b=0;
                    }
                    if(data_gobang[i][j+k]==0 && j+k+1<24 && zhsx[0].b==1)
                    {
                        zhsx[0].z++;
                        zhsx[0].x=i;
                        zhsx[0].y=j+k+1;
                    }
                    else if(data_gobang[i][j+k]=='x')
                    {
                        zhsx[0].b=0;
                    }
                    if(data_gobang[i+k][j+k]==0 || (i+k+1<16 && j+k+1<24) && zhsx[2].b==1)
                    {
                        zhsx[2].z++;
                        zhsx[2].x=i+k+1;
                        zhsx[2].y=j+k+1;
                    }
                    else if(data_gobang[i+k][j+k]=='x')
                    {
                        zhsx[2].b=0;
                    }
                }
                for(int k=0;k<3;k++)
                {
                    if(zhsx[k].z>*z0 && data_gobang[zhsx[k].x][zhsx[k].y]==0)
                    {
                        *z0=zhsx[k].z;
                        *x=zhsx[k].x;
                        *y=zhsx[k].y;
                    }
                }
                if(*z0==1)
                {
                    if(data_gobang[x1+1][y1]==0)
                    {
                        *x=x1+1;
                        *y=y1;
                    }
                    else if(data_gobang[x1][y1+1]==0)
                    {
                        *x=x1;
                        *y=y1+1;
                    }
                    else if(data_gobang[x1+1][y1+1]==0)
                    {
                        *x=x1+1;
                        *y=y1+1;
                    }
                }
            }
        }
    }
    if(*z0==0)  //人机从无到有
    {
        *x=x0+1;
        *y=y0+1;
    }
}