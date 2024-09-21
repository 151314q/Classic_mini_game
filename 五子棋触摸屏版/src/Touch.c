#include "Touch.h"

#define BIN_TOUCH 0x14a  //触摸屏按键

/*
    功能：
        获取手指离开触摸屏时的触摸点的坐标
    参数:
        (x, y)用来保存触摸点的坐标
*/
void get_xy(int* x, int* y)
{
    //打开触摸屏
    int fd_ev = open("/dev/input/event0", O_RDONLY);
    if(fd_ev == -1)
    {
        perror("open event0 error");
        exit(1);
    }
    //定义一个触摸事件结构体
    struct input_event ev;

    while(1)
    {
        //获取触摸事件的信息
        int ret = read(fd_ev, &ev, sizeof(ev));
        if(ret == -1)
        {
            perror("read ev error");
            exit(1);
        }   

        //触摸屏事件，键值为获取触摸点的横坐标
        if(ev.type == EV_ABS && ev.code == ABS_X) 
        {
            *x = ev.value;
        }

        //触摸屏事件，键值为获取触摸点的纵坐标
        if(ev.type == EV_ABS && ev.code == ABS_Y) 
        {
            *y = ev.value;
        }

        //当手指抬起的时候
        if(ev.type == EV_KEY && ev.code == BIN_TOUCH && ev.value == 0)
        {
            break;
        }
    }

    ev.value=0;
    //关闭触摸屏
    close(fd_ev);
}

/*
    屏幕滑动函数
    返回值: 1->左滑
            2->右滑
            3->上滑
            4->下滑
*/
int get_slipp()
{
    int fd_ev = open("/dev/input/event0",O_RDONLY);
    if(fd_ev == -1)
    {
        perror("open event0 error");
        exit(1);
    }

    //定义一个触摸事件结构体
    struct input_event ev;
    int x1=-1,y1=-1,x2=-1,y2=-1;
    while(1)
    {
        //获取触摸事件的信息
        int ret = read(fd_ev,&ev,sizeof(ev));
        if(ret==-1)
        {
            perror("read ev error");
            exit(1);
        }

        //触摸屏事件
        if(ev.type == EV_ABS && ev.code == ABS_X)
        {
            if(x1==-1)      //记录刚开始滑动时的第一个坐标
                x1=ev.value;
            else            //这里会不断更新最后一个坐标的值，直到我松手
                x2=ev.value;
        }
        if(ev.type == EV_ABS && ev.code == ABS_Y)
        {
            if(y1==-1)
                y1=ev.value;
            else
                y2=ev.value;
        }

        //手指抬起的时候获取数据结束
        if(ev.type == EV_KEY && ev.code == BIN_TOUCH && ev.value == 0)
        {
            if(x2 != -1 && y2 != -1) break;
        }
        if(ev.code == ABS_PRESSURE && ev.value == 0) //判断松手的方法
		{
			if(x2 != -1 && y2 != -1) break;
		}
    }
    //printf("x1=%d,y1=%d,x2=%d,y2=%d\n",x1,y1,x2,y2);
    close(fd_ev);
    int abs_x=x2-x1;
    int abs_y=y2-y1;
    if(abs(abs_x) > abs(abs_y))
    {
        if(abs(abs_x)>50)
        {
            if(abs_x>0)
                return 2;   //右滑
            else
                return 1;   //左滑
        }
        else
            return 0;   //滑动无效
    }
    else
    {
        if(abs(abs_y)>50)
        {
            if(abs_y>0)
                return 4;   //下滑
            else
                return 3;   //上滑
        }
        else
            return 0;   //滑动无效
    }
}

/*
    换算1024*600的触摸屏为800*480的显示屏.
    主要服务于点击触摸事件，---get_xy---便于精准定位，
*/
void exchang_data(int *x,int *y)
{
    *x=1.0*(*x)/1.28;   //数值转换
    *y=1.0*(*y)/1.25;
}