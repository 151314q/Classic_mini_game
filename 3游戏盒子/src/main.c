#include "Touch.h"
#include "bmp.h"

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int fd=open("/dev/fb0",O_RDWR);
    if(fd==-1)
    {
        perror("open fd error");
        exit(0);
    }
    Lcd_init(fd);
    int x,y;
    char *buf=malloc(sizeof(char)*100);
    while(1)
    {
        Clean_lcd();
        //显示点击区域图片
        lcd_draw_bmp(0,0,"game2048.bmp");
        lcd_draw_bmp(0,160,"gamesaolei.bmp");
        lcd_draw_bmp(0,320,"gamegobang.bmp");
        lcd_draw_bmp(350,0,"gameschinachess.bmp");
        lcd_draw_bmp(350,160,"gamesnake.bmp");
        lcd_draw_bmp(350,320,"gametetris.bmp");
        get_xy(&x,&y);
        exchang_data(&x,&y);
        if(x>700)
            break;  //退出程序
        int *wstatus=malloc(sizeof(4));
        if(x>0&&x<350&&y>0&&y<160)  //2048游戏
        {
            pid_t pid=fork();
            if(pid==0)  //子进程
            {   getcwd(buf,100);
                printf("%s\n",buf);
                chdir("../2048");   //切换到工作路径
                execl("./main","main",NULL);    //执行路径下的程序
            }
            else if(pid>0)  //父进程
            {
                waitpid(pid,wstatus,0);     //阻塞等待子进程结束
                getcwd(buf,100);        //值得注意的是，在子进程当中改变工作路径并不会影响父进程的路径
                printf("%s\n",buf);
                sleep(2);   //延时两秒
            }
        }
        else if(x>0&&x<350&&y>160&&y<320)   //扫雷游戏
        {
            pid_t pid=fork();
            if(pid==0)  //子进程
            {   getcwd(buf,100);
                printf("%s\n",buf);
                chdir("../saolei");   //切换到工作路径
                execl("./main","main",NULL);    //执行路径下的程序
            }
            else if(pid>0)  //父进程
            {
                waitpid(pid,wstatus,0);     //阻塞等待子进程结束
                sleep(2);   //延时两秒
            }
        }
        else if(x>0&&x<350&&y>320)          //五子棋游戏
        {
            pid_t pid=fork();
            if(pid==0)  
            {   getcwd(buf,100);
                printf("%s\n",buf);
                chdir("../gobang");   
                execl("./main","main",NULL);
            }
            else if(pid>0)
            {
                waitpid(pid,wstatus,0);
                sleep(2);   
            }
        }
        else if(x>350&&x<700&&y>0&&y<160)   //中国象棋
        {
            pid_t pid=fork();
            if(pid==0)  
            {   getcwd(buf,100);
                printf("%s\n",buf);
                chdir("../china_chess");   
                execl("./main","main",NULL);
            }
            else if(pid>0)
            {
                waitpid(pid,wstatus,0);
                sleep(2);   
            }
        }
        else if(x>350&&x<750&&y>160&&y<320) //贪吃蛇
        {
            pid_t pid=fork();
            if(pid==0)  
            {   getcwd(buf,100);
                printf("%s\n",buf);
                chdir("../gluttonous_snake");   
                execl("./main","main",NULL);
            }
            else if(pid>0)
            {
                waitpid(pid,wstatus,0);
                sleep(2);   
            }
        }
        else if(x>350&&x<750&&y>320&&y<480) //俄罗斯方块
        {
            pid_t pid=fork();
            if(pid==0)  
            {   getcwd(buf,100);
                printf("%s\n",buf);
                chdir("../tetris");   
                execl("./main","main",NULL);
            }
            else if(pid>0)
            {
                waitpid(pid,wstatus,0);
                sleep(2);   
            }
        }
        else if(x>700)
            break;  //离开游戏盒子
    }

    //关闭
    Lcd_uninit();
    close(fd);
}