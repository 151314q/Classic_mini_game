#include "gobang_process.h"
extern char data_gobang[400/25][600/25];
int request_(int x,int y)
{
    char sign;
    if(data_gobang[x][y]=='x') sign='x';
    else sign='o';
    int n=1,x1=x,y1=y;
    for(int i=1;i<5;i++)
    {
        x1=x1+1;
        if(x1<400/25 && x1>=0)
        {
            if(data_gobang[x1][y1]==sign)  n++;
            else break;
        }
        else break;
    }
    x1=x;
    if(n>=5)
    {
        if(sign=='x') return 1;     //1代表第一个人赢了
        else return 2;              //2代表第二个人赢了
    }
    else
    {   for(int i=1;i<5;i++)
        {
            x1=x1-1;
            if(x1<400/25 && x1>=0)
            {
                if(data_gobang[x1][y1]==sign) n++;
                else break;
            }
            else break;
        }
    }
    if(n>=5)
    {
        if(sign=='x') return 1;
        else return 2;
    }
    else n=1;                      //竖直方向判断结束

    x1=x;
    for(int i=1;i<5;i++)
    {
        y1=y1+1;
        if(y1<600/25 && y1>=0)
        {
            if(data_gobang[x1][y1]==sign)  n++;
            else break;
        }
        else break;
    }
    y1=y;
    if(n>=5)
    {
        if(sign=='x')   return 1;
        else return 2;
    }
    else
    {
        for(int i=1;i<5;i++)
        {
            y1=y1-1;
            if(y1<600/25 && y1>=0)
            {
                if(data_gobang[x1][y1]==sign)  n++;
                else break;
            }
            else break;
        }
    }
    if(n>=5)
    {
        if(sign=='x')   return 1;   //1代表第一个人赢了
        else return 2;              //2代表第二个人赢了
    }
    else n=1;                     //横向方向判断结束

    y1=y;
    for(int i=1;i<5;i++)
    {
        x1=x1+1;
        y1=y1+1;
        if(x1<400/25 && x1>=0 && y1<600/25 && y1>=0)
        {
            if(data_gobang[x1][y1]==sign)  n++;
            else break;
        }
        else break;
    }
    x1=x;y1=y;
    if(n>=5)
    {
        if(sign=='x')   return 1;
        else return 2;
    }
    else
    {
        for(int i=1;i<5;i++)
        {
            x1=x1-1;
            y1=y1-1;
            if(x1<400/25 && x1>=0 && y1<600/25 && y1>=0)
            {
                if(data_gobang[x1][y1]==sign)  n++;
                else break;
            }
            else break;
        }
    }
    if(n>=5)
    {
        if(sign=='x')   return 1;
        else return 2;
    }
    else n=1;                          //斜方向\这样的判断结束

    y1=y;x1=x;
    for(int i=1;i<5;i++)
    {
        x1=x1-1;
        y1=y1+1;
        if(x1<400/25 && x1>=0 && y1<600/25 && y1>=0)
        {
            if(data_gobang[x1][y1]==sign)  n++;
            else break;
        }
        else break;
    }
    x1=x;y1=y;
    if(n>=5)
    {
        if(sign=='x')   return 1;
        else return 2;
    }
    else
    {
        for(int i=1;i<5;i++)
        {
            x1=x1+1;
            y1=y1-1;
            if(x1<400/25 && x1>=0 && y1<600/25 && y1>=0)
            {
                if(data_gobang[x1][y1]==sign)  n++;
                else break;
            }
            else break;
        }
    }
    if(n>=5)
    {
        if(sign=='x')   return 1;   //1代表第一个人赢了
        else return 2;              //2代表第二个人赢了
    }
    else n=1;
    y1=y;x1=x;              //斜方向/这样的判断结束

    return 0;
}
