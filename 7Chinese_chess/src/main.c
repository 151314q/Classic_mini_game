#include "chess_Initial.h"
#include "Touch.h"
#include "chess_rules.h"
extern int data_chess[400/40][360/40];

//游戏胜利。返回值：0未结束、1玩家1胜利、2玩家2胜利
int game_over();

/*悔棋操作*/
void regret_handle(Headweek* head);

/*请求和棋操作
  参数：player---1为玩家1提出、2为玩家2提出,其他数据会直接返回求和失败
  返回值：1允许，0不允许*/
int peace_handle(int player);

int main()
{
    
    int fd = open("/dev/fb0", O_RDWR);
    if (fd == -1)
    {
        perror("open error");
    }
    Lcd_init(fd);
    Clean_lcd(); // 先清屏
    Headweek* head=creat_head();    //创建用于保存的头结点

    lcd_chinachessBoard();  //初始化棋盘
    lcd_chess_pieces();     //初始化数组上的棋子初值
    display_china_chess();  //显示棋子
    
    int x,y;    //记录坐标
    int x1,y1;  //记录要去的坐标
    char buf[20];
    while (1)
    {
/////////////////////////玩家1：执红旗先行/////////////////////////////////
    re_read:
        useing_word_player(1);    //显示红方玩家
        get_xy(&x,&y);      //获取坐标1:起始坐标
        exchang_data(&x,&y);
        if(x<20||y<40||y>440)
            goto re_read;
        else if(x>400 && x<500 && y>390)  //玩家1请求和棋
        {
            if(peace_handle(1))    //请求成功
            {
                printf("和棋\n");
                break;
            }
            else    goto re_read;   //请求失败，需选择棋子移动,游戏结束
        }
        else if(x>500 && x<600 && y>390)  //玩家1请求悔棋
        {
            if(head->num >= 2)  //栈中需至少有两个结点才可以成功悔棋
            {
                regret_handle(head);    //悔棋处理
            }
            //每次悔棋将释放两个结点，因此无论悔棋是否成功，都应由当前玩家再次移动
            goto re_read;
        }
        else if(x<20||x>380||y<40||y>440)   //棋子范围
            goto re_read;

        int i=(y-40)/40;
        int j=(x-20)/40;
        //必须选择棋子，否则重选，也不可选择黑棋
        if(data_chess[i][j]==0 || data_chess[i][j]<10)
            goto re_read;
        //选择正确的棋子，给予高亮提示
        sprintf(buf,"./%dset.bmp",data_chess[i][j]);
        lcd_draw_bmp(20+j*40,40+i*40,buf);

    re_read1:
        get_xy(&x1,&y1);      //获取坐标2：目标坐标
        exchang_data(&x1,&y1);
        if(x1<20||x1>380||y1<40||y1>440)
            goto re_read1;
        int i1=(y1-40)/40;   //将坐标换成数组下标
        int j1=(x1-20)/40;
        if(i1==i && j1==j)
            goto re_read;   //如果读取两个坐标为同一个表示取消当前棋子，需要选择其他棋子
        
        if(Selection_rule(i, j, i1, j1))     //成功移动
        {
            //将该步入栈保留
            push_week(head,i,j,data_chess[i][j],i1,j1,data_chess[i1][j1]);

            data_chess[i1][j1]=data_chess[i][j];    //改变数组成员的值
            data_chess[i][j]=0;
            lcd_chinachessBoard();  //绘制棋盘
            display_china_chess();  //显示棋子
            int temp=game_over();   //判断游戏是否结束
            if(temp)
            {
                useing_word(0xffff0000);   //玩家1胜利
                break;  //退出循环
            }
        }
        else    
        {
            //将高亮提示关闭
            sprintf(buf,"./%d.bmp",data_chess[i][j]);
            lcd_draw_bmp(20+j*40,40+i*40,buf);
            goto re_read;      //移动失败重新读取初始和目标坐标
        }
//////////////////////////玩家2：执黑棋///////////////////////////////////////
    re_read2:
        useing_word_player(2);    //显示黑方玩家
        get_xy(&x,&y);      //获取坐标1:起始坐标
        exchang_data(&x,&y);
        if(x<20||y<40||y>440)
            goto re_read2;
        else if(x>400 && x<500 && y<90)  //玩家2请求和棋
        {
            if(peace_handle(2))    //请求成功
            {
                printf("和棋\n");
                break;
            }
            else    goto re_read2;   //请求失败，需选择棋子移动
        }
        else if(x>500 && x<600 && y<90)  //玩家2请求悔棋
        {
            if(head->num >= 2)  //栈中需至少有两个结点才可以成功悔棋
            {
                regret_handle(head);    //悔棋处理
            }
            //每次悔棋将释放两个结点，因此无论悔棋是否成功，都应由当前玩家再次移动
            goto re_read2;
        }
        else if(x<20||x>380||y<40||y>440)   //棋子范围
            goto re_read;

        i=(y-40)/40;
        j=(x-20)/40;
        //必须选择棋子，否则重选，也不可选择红棋
        if(data_chess[i][j]==0 || data_chess[i][j]>10) 
            goto re_read2;
        //选择正确的棋子，给予高亮提示
        sprintf(buf,"./%dset.bmp",data_chess[i][j]);
        lcd_draw_bmp(20+j*40,40+i*40,buf);

    re_read3:
        get_xy(&x1,&y1);      //获取坐标2：目标坐标
        exchang_data(&x1,&y1);
        if(x1<20||x1>380||y1<40||y1>440)
            goto re_read3;
        i1=(y1-40)/40;   //将坐标换成数组下标
        j1=(x1-20)/40;
        if(i1==i && j1==j)
            goto re_read2;   //如果读取两个坐标为同一个表示取消当前棋子，需要选择其他棋子
        
        if(Selection_rule(i, j, i1, j1))     //成功移动
        {
            //将该步入栈保留
            push_week(head,i,j,data_chess[i][j],i1,j1,data_chess[i1][j1]);

            data_chess[i1][j1]=data_chess[i][j];    //改变数组成员的值
            data_chess[i][j]=0;
            lcd_chinachessBoard();  //绘制棋盘
            display_china_chess();  //显示棋子
            int temp=game_over();   //判断游戏是否结束
            if(temp)
            {
                useing_word(0xff000000);      //游戏结束，黑方胜利
                break;  //退出循环
            }
        }
        else
        {
            //将高亮提示关闭
            sprintf(buf,"./%d.bmp",data_chess[i][j]);
            lcd_draw_bmp(20+j*40,40+i*40,buf);
            goto re_read2;      //移动失败重新读取初始和目标坐标
        }
    }



    Lcd_uninit(); // 关闭映射
    close(fd);

    return 0;
}

/*请求和棋操作
  参数：player---1为玩家1提出、2为玩家2提出,其他数据会直接返回求和失败
  返回值：1允许，0不允许*/
int peace_handle(int player)
{
    if(player==1)   //玩家1提出，需要玩家2同意
    {
        lcd_draw_bmp(400,340,"./asking1.bmp");
        lcd_draw_bmp(400,140,"./yes2.bmp");     //140-190
        lcd_draw_bmp(500,140,"./no2.bmp");      //显示按键
        int x,y;
        while(1)
        {
            get_xy(&x,&y);
            exchang_data(&x,&y);
            if(x>400&&x<600&&y>140&&y<190)  //识别到正确的点击才退出循环
                break;
        }
        if(x>400&&x<500)    //同意
        {
            Clean_lcd_part(400,340,200,50,0xffffffff);  //清除按键
            Clean_lcd_part(400,140,200,50,0xffffffff);
            useing_word_player(3);
            return 1;
        }
        else                //不同意
        {
            Clean_lcd_part(400,340,200,50,0xffffffff);  //清除按键
            //printf("正常1\n");
            Clean_lcd_part(400,140,200,50,0xffffffff);
            //printf("正常2\n");
            return 0;      
        }
    }
    else if(player==2)  //玩家2提出，需要玩家1同意
    {
        lcd_draw_bmp(400,90,"./asking2.bmp");
        lcd_draw_bmp(400,290,"./yes1.bmp");     //290-340
        lcd_draw_bmp(500,290,"./no1.bmp");      //显示按键
        int x,y;
        while(1)
        {
            get_xy(&x,&y);
            exchang_data(&x,&y);
            if(x>400&&x<600&&y>290&&y<340)  //识别到正确的点击才退出循环
                break;
        }
        if(x>400&&x<500)    //同意
        {
            Clean_lcd_part(400,290,200,50,0xffffffff);  //清除按键
            Clean_lcd_part(400,91,200,50,0xffffffff);
            useing_word_player(3);    
            return 1;
        }
        else                //不同意
        {
            Clean_lcd_part(400,290,200,50,0xffffffff);  //清除按键
            Clean_lcd_part(400,91,200,50,0xffffffff);
            return 0;      
        }
    }
    else    return 0;   //求和失败
}

/*悔棋操作*/
void regret_handle(Headweek* head)
{
    Weekplayer* node=pop_week(head);
    data_chess[node->i1][node->j1]=node->data1;
    data_chess[node->i0][node->j0]=node->data0;
    free(node);     //出栈一次
    node=pop_week(head);
    data_chess[node->i1][node->j1]=node->data1;
    data_chess[node->i0][node->j0]=node->data0;
    free(node);     //出栈两次
    lcd_chinachessBoard();  //绘制棋盘
    display_china_chess();  //显示棋子
}

//游戏胜利。返回值：0未结束、1玩家1胜利、2玩家2胜利
int game_over()
{
    int flag=0; //标志位
    for(int i=0;i<=2;i++)   //寻找黑棋将
    {
        for(int j=3;j<=5;j++)
        {
            if(data_chess[i][j]==5)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==0)     //黑棋将已死
        return 1;   //玩家1胜利
    flag=0;
    for(int i=7;i<=9;i++)   //寻找红棋帅
    {
        for(int j=3;j<=5;j++)
        {
            if(data_chess[i][j]==15)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==0)     //红棋帅已死
        return 2;   //玩家2胜利
    
    return 0;   //游戏继续
}