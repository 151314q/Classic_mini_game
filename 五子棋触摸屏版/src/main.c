#include "gobang_process.h"
#include "gobang_beginover.h"
char data_gobang[400 / 25][600 / 25] = {0}; // 棋盘数组，大小由间隔25和最大范围400、600决定
extern int *plcd;
extern int fd;
int main()
{
    fd = open("/dev/fb0", O_RDWR);
    if (fd == -1)
    {
        perror("open error");
    }
    Lcd_init(fd);
    Clean_lcd(); // 先清屏

    while(1)
    {
        lcd_chessboard();
        lcd_draw_bmp(650,0,"renji.bmp");
        lcd_draw_bmp(650,240,"shuangren.bmp");
        int x,y;
        get_xy(&x,&y);
        exchang_data(&x,&y);
        if(x>650 && x<750&& y<200)
        {
            printf("开始人机对战\n");
            Man_machine_versus();
        }
        else if(x>650 && x<750 && y>240 && y<440)
        {
            printf("开始双人对战\n");
            double_against();
        }
        else
        {
            printf("模式选择错误\n");
        }
    }

    Lcd_uninit(); // 关闭映射
    close(fd);

    return 0;
}