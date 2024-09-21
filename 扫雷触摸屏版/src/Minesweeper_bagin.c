#include "Minesweeper_bagin.h"
char data[N][N]={0};    //data为实际数组
char data5[N][N]={0};   //data5为显示数组
extern int N1;      //雷的数量在main函数中确定

/*
    扫雷初始化：扫雷棋盘的雷位置的随机抽取，及雷身边的数字信息
*/
void chu_shi_hua()
{
    int n=0,x=0,y=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            data5[i][j]=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            data5[i][j]='-';    //将data5数组赋值为'-'

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            data[i][j]=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            data[i][j]=32;      //data初始化为空格' '
    srand((unsigned)time(NULL));    //获取随机数组下标
fan:    
    x=rand()%N;
    y=rand()%N;
    if(data[x][y]==' ')        //' '表示空白区域
    {
        data[x][y]='x';        //赋‘x’表示雷
        n++;
    }
    else goto fan;
    if(n!=N1) goto fan;      //使棋盘中随机存有N1个雷

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int i1=i+1,i2=i-1,j1=j+1,j2=j-1;
            int n=48;       //0的ASCLL码
            if(data[i][j]==' ')
            {
                if(i1<N)
                {
                    if(data[i1][j]=='x')    n++;
                    if(j1<N)
                        if(data[i1][j1]=='x')   n++;
                    if(j2>=0)
                        if(data[i1][j2]=='x')   n++;
                }
                if(i2>=0)
                {
                    if(data[i2][j]=='x')    n++;
                    if(j1<N)
                        if(data[i2][j1]=='x') n++;
                    if(j2>=0)
                        if(data[i2][j2]=='x')   n++;
                }
                if(j1<N)
                    if(data[i][j1]=='x')    n++;
                if(j2>=0)
                    if(data[i][j2]=='x')    n++;
                //判断该点周围有几个雷
                if(n>48)
                    data[i][j]=n;
            }
        }
    }
}

/*扫雷字符版打印*/
void da_ying()
{
    for(int i=0;i<N;i++)
        printf(" %d",i);
    printf("\n");
    for(int i=0;i<N;i++)
        printf("——");
    printf("——\n");
    for(int i=0;i<N;i++)
    {
        printf("|");
        for(int j=0;j<N;j++)
        {
            printf("%c ",data5[i][j]);
        }
        printf("|");
        printf("%d\n",i);
    }
    for(int i=0;i<N;i++)
        printf("——");
    printf("——\n");    
}

/*******************************触摸屏版相关函数*********************************/

/*显示扫雷游戏界面*/
void saolei_jiemian()
{
    lcd_draw_plane(0xffffffff);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            lcd_draw_bmp(25*i,25*j,"0.bmp");
        }
    }
    for(int i=25;i<400;i++)
    {
        for(int j=25;j<400;j++)
        {
            if(i%25==0||j%25==0)
                lcd_draw_point(i,j,0xffffffff);
        }
    }
}

/*获取触摸地区对应的数组下标*/
void get_saolei_poition(int *x,int *y)
{
fan:
    get_xy(x,y);
    exchang_data(x,y);
    if(*x>=25 && *x<400 && *y>=25 && *y<400)
    {
        *x=*x/25-1;
        *y=*y/25-1;     //此时获取的数组下标为
        //交换一下*x，*y
        int temp;
        temp=*x;
        *x=*y;
        *y=temp;
    }
    else goto fan;
}

/*扫雷难度选择*/
int get_game_difficulty()
{
    lcd_draw_plane(0xffffffff);
    lcd_draw_bmp(0,190,"jiandan.bmp");      //简单
    lcd_draw_bmp(200,190,"putong.bmp");     //普通
    lcd_draw_bmp(400,190,"kunnan.bmp");     //困难
    lcd_draw_bmp(600,190,"gaonandu.bmp");   //高难度
    int x,y;
    while(1)
    {
        get_xy(&x,&y);
        exchang_data(&x,&y);
        if(x<150&&x>0 && y<290&&y>190)
        {
            printf("简单模式\n");
            return 1;
        }
        if(x>200&&x<350 && y<290&&y>190)
        {
            printf("普通模式\n");
            return 2;
        }
        if(x>400&&x<550 && y<290&&y>190)
        {
            printf("困难模式\n");
            return 3;
        }
        if(x>600&&x<750 && y<290&&y>190)
        {
            printf("高难度模式\n");
            return 4;
        }
    }
}

/*扫雷功能键获取，每次点击之前先判断是经行什么操作*/
int get_function_poition()
{
    lcd_draw_bmp(450,50,"dianji.bmp");
    lcd_draw_bmp(600,50,"quxiao.bmp");
    lcd_draw_bmp(450,150,"walei.bmp");
    lcd_draw_bmp(600,150,"chongkai.bmp");   //打印所设按键图片
    lcd_draw_bmp(600,250,"tuichu.bmp");
    int x,y;
fan:    
    get_xy(&x,&y);
    exchang_data(&x,&y);
    if(x>450&&x<550 && y>50&&y<100)
    {
        printf("点击\n");
        return 1;   //点击键
    }
    else if(x>600&&x<700 && y>50&&y<100)
    {
        printf("取消\n");
        return 2;   //取消键
    }
    else if(x>450&&x<550 && y>150&&y<200)
    {
        printf("插旗\n");
        return 3;   //挖雷键（插旗）
    }
    else if(x>600&&x<700 && y>150&&y<200)
    {
        printf("重开\n");
        return 4;
    }
    else if(x>600&&x<700 && y>250&&y<300)
    {
        printf("退出游戏\n");
        return 5;
    }
    else
    {
        printf("点击无效,请点击功能键\n");
        goto fan;
    }
}

/*显示点击元素对应数组对应的图片*/
void xianshi_bmp(int x,int y)
{
    char *str[]={"0.bmp","1.bmp","2.bmp","3.bmp","4.bmp","5.bmp","6.bmp","7.bmp","8.bmp","chaqi.bmp","9.bmp"};
    if(data5[x][y]=='!')
    {
        lcd_draw_bmp(y*25+25,x*25+25,str[9]);
    }
    else if(data5[x][y]=='1')
        lcd_draw_bmp(y*25+25,x*25+25,str[1]);
    else if(data5[x][y]=='2')
        lcd_draw_bmp(y*25+25,x*25+25,str[2]);
    else if(data5[x][y]=='3')
        lcd_draw_bmp(y*25+25,x*25+25,str[3]);
    else if(data5[x][y]=='4')
        lcd_draw_bmp(y*25+25,x*25+25,str[4]);
    else if(data5[x][y]=='5')
        lcd_draw_bmp(y*25+25,x*25+25,str[5]);
    else if(data5[x][y]=='6')
        lcd_draw_bmp(y*25+25,x*25+25,str[6]);
    else if(data5[x][y]=='7')
        lcd_draw_bmp(y*25+25,x*25+25,str[7]);
    else if(data5[x][y]=='8')
        lcd_draw_bmp(y*25+25,x*25+25,str[8]);
    else if(data5[x][y]=='0'||data5[x][y]==' ')
        lcd_draw_bmp(y*25+25,x*25+25,str[10]);
}