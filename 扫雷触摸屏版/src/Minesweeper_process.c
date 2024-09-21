#include "Minesweeper_process.h"
extern int N1;
extern char data5[N][N];
extern char data[N][N];
extern int n;
/*
    点击操作函数
    参数：二维数组的下标
    返回值：0（点雷）、1（不是雷）
*/
int click_e(int x,int y)
{
    if(data5[x][y]=='!')
    {
        return 1;   //此处已经插旗
    }
    else if(data[x][y]=='x') 
    {
        data5[x][y]='x';
        lcd_draw_bmp(y*25+25,x*25+25,"lei.bmp");
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(data[i][j]=='x')
                {
                    if(data5[i][j]!='!')
                    {
                        data5[i][j]='x';    //踩到雷，将未排掉的雷全部显示出来
                        lcd_draw_bmp(j*25+25,i*25+25,"lei.bmp");
                    }
                }
            }
        }
        return 0;
    }                  //踩雷，游戏结束
    else if(data[x][y]==' ')     //难点，点开空格之后要将附近连在一起的空格和包围空格的数字点开
    {
        while(1)
        {
            di_gui(x,y);
            break;
        }
        return 1;     //不是雷，继续游戏
    }
    else
    {
        data5[x][y]=data[x][y];
        return 1;      //不是雷，继续游戏
    }
}




/*标记雷，z为int quxiao()函数的返回值*/
int bomb_w(int x,int y,int z)
{
    if(data5[x][y]=='-')
    {
        data5[x][y]='!';
        n=n-1;                  //少一个雷
        if(z!=0)    n=n+z;          //z为当前已经取消的雷的个数；
        return n;
    }
    else    printf("点击错误\n");
    return n+z;
}

/*
    取消标记函数
    取消标记过的雷
*/
int quxiao_(int x,int y,int z)
{
    if(data5[x][y]=='!')
    {
        lcd_draw_bmp(y*25+25,x*25+25,"0.bmp");
        return z+1;             //返回+1；
    }
    else
        return z;              //没有'!',不能取消,返回z值
}

/*将所有连在一起的空白区域递归出来*/
void di_gui(int x, int y)
{

    data5[x][y] = ' ';
    int x1 = x + 1, x2 = x - 1;
    int y1 = y + 1, y2 = y - 1;
    //'x'的问题出现在边界，当边界溢出时，递归可能会把棋盘四周的雷给显现出来，故加一条判断防止误判
    if (data[x1][y] != ' ' && data[x1][y]!='0' && data[x1][y]!='x' && x1<N) 
    {
        data5[x1][y] = data[x1][y];
        xianshi_bmp(x1,y);
    }
    //else if(data[x1][y]!='0' && data[x1][y]!='x' && x1<N)
    else if(data[x1][y] == ' ' && x1<N)
    {
        data5[x1][y] = data[x1][y];     //这里显示的是将空格围起来的数字
        xianshi_bmp(x1,y);
        data[x1][y]='0';        //在往下递归之前先将自己改为0，不让递归再递归回来
        di_gui(x + 1, y);
    }

    if (data[x2][y] != ' ' && data[x2][y]!='0' && data[x2][y]!='x' && x2>=0)
    {
        data5[x2][y] = data[x2][y];
        xianshi_bmp(x2,y);
    }
    //else if(data[x2][y]!='0' && data[x2][y]!='x' && x2>=0)
    else if(data[x2][y]==' ' && x2>=0)
    {
        data5[x2][y] = data[x2][y];
        xianshi_bmp(x2,y);
        data[x2][y]='0';
        di_gui(x - 1, y);       //往上递归
    }

    if (data[x][y1] != ' ' && data[x][y1]!='0' && data[x][y1]!='x' && y1<N)
    {
        data5[x][y1] = data[x][y1];
        xianshi_bmp(x,y1);
    }
    // else if(data[x][y1]!='0' && data[x][y1]!='x' && y1<N)
    else if(data[x][y1] == ' ' && y1<N)
    {
        data5[x][y1] = data[x][y1];
        xianshi_bmp(x,y1);
        data[x][y1]='0';
        di_gui(x, y + 1);       //往右递归
    }

    if (data[x][y2] != ' ' && data[x][y2]!='0' && data[x][y2]!='x' && y2>=0)
    {
        data5[x][y2] = data[x][y2];
        xianshi_bmp(x,y2);
    }
    //else if(data[x][y2]!='0' && data[x][y2]!='x' && y2>=0)
    else if(data[x][y2]==' ' && y2>=0)
    {
        data5[x][y2] = data[x][y2];
        xianshi_bmp(x,y2);
        data[x][y2]='0';
        di_gui(x, y - 1);       //往左递归
    }
}
