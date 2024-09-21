#include "lcd.h"
#include "word.h"

int *plcd = NULL; // 映射标志位
int fd = -1;

/*****************基础close、write、lseek函数的使用*********************/
/*用白色作为清屏*/
void Clean_lcd()
{
    // lseek(fd, 0, SEEK_SET);
    unsigned int color = 0xffffffff;
    for (int i = 0; i < 800 * 480; i++)
        // write(fd, &color, 4);
        *(plcd + i) = color;
}

/*用write函数向屏幕中写入数据*/
void Write_lcd(int fd, int color)
{
    for (int i = 0; i < 800 * 480; i++)
        write(fd, &color, 4);
}

/*使用三种颜色刷新显示屏*/
void shuaxing_write_lcd(int fd)
{
    int color = 0xffff00ff;
    int color1 = 0xffff0000;
    int color2 = 0xff00ff00;
    int n = 10;
    while (n--) // 每隔3s刷屏
    {
        Write_lcd(fd, color);
        lseek(fd, 0, SEEK_SET);
        sleep(3);

        Write_lcd(fd, color1);
        lseek(fd, 0, SEEK_SET);
        sleep(3);

        Write_lcd(fd, color2);
        lseek(fd, 0, SEEK_SET);
        sleep(3);
    }
}

/********************内存映射相关函数********************/

/*打开映射*/
void Lcd_init(int fd)
{
    plcd = mmap(NULL, 800 * 480 * 4, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (plcd == MAP_FAILED)
    {
        perror("mmap error");
    }
}

/*解除映射*/
void Lcd_uninit()
{
    munmap(plcd, 800 * 480 * 4);
}

/*画点函数*/
void lcd_draw_point(int x, int y, unsigned int color)
{
    if (x >= 0 && x < 800 && y >= 0 && y < 480)
        *(plcd + y * 800 + x) = color;
}

/*画横线函数*/
void lcd_draw_line(int y, unsigned int color)
{
    for (int i = 0; i < 800; i++)
        lcd_draw_point(i, y, color);
}

/*画竖线函数*/
void lcd_draw_line1(int x,unsigned int color)
{
    for(int i=0;i<480;i++)
        lcd_draw_point(x,i,color);
}

/*画平面函数*/
void lcd_draw_plane(unsigned int color)
{
    for (int i = 0; i < 800 * 480; i++)
        *(plcd + i)=color;
}

/*画矩形函数*/
void draw_juxing()
{

    int x1, x2, y1, y2;
    unsigned int color = 0xffff0000; // 红色
    Clean_lcd();                     // 刷新屏幕

    printf("请输入要画矩形的x1:");
    scanf("%d", &x1);
    printf("请输入要画矩形的x2:");
    scanf("%d", &x2);
    printf("请输入要画矩形的y1:");
    scanf("%d", &y1);
    printf("请输入要画矩形的y2:");
    scanf("%d", &y2);

    int i0 = (x1 > x2) ? x1 : x2;
    int j0 = (y1 > y2) ? y1 : y2;
    for (int i = (x1 < x2) ? x1 : x2; i < i0; i++)
    {
        for (int j = (y1 < y2) ? y1 : y2; j < j0; j++)
        {
            lcd_draw_point(i, j, color);
        }
    }
}

/*画圆函数*/
void draw_circle(int x, int y, int r, unsigned int color)
{
    for (int i = x - r; i < x + r; i++)
    {
        for (int j = y - r; j < y + r; j++)
        {
            if (sqrt(pow(x - i, 2) + pow(y - j, 2)) < r)
                lcd_draw_point(i, j, color);
        }
    }
}

/*画爱心：爱心函数---> (x^2 + y^2 - 1)^3 - x^2 * y^3 = 0 ,该函数改变1的值进行放大，改成25，放大25倍*/
void draw_aixing()
{
    int color=0xffff0000;
    int x=100,y=50,r=50;
    for(int i=x-r;i<x+r;i++)
    {
        for(int j=y-r;j<y+r;j++)    //倒叙打印
        {
            int i0=x-i,j0=y-j;
            if(pow( (i0*i0+j0*j0-300) ,3) < i0*i0*j0*j0*j0)
            {
                lcd_draw_point(i,j,color);
                //printf("i=%d,j=%d\n",i,j);
            }
        }
    }
}

/*画太极函数*/
void draw_taiji()
{
    int x = 400, y = 240; // 确定圆心位于正中心
    unsigned int color1 = 0xff000000;
    unsigned int color2 = 0xffffffff;
    int r = 100;
    lcd_draw_plane(0xff00ffff);
    for (int i = x - r; i < x + r; i++)
    {
        for (int j = y - r; j < y + r; j++)
        {
            if (sqrt(pow(i - x, 2) + pow(j - y, 2)) < r)
            {
                if (i < 400)
                    lcd_draw_point(i, j, color1);
                else
                    lcd_draw_point(i, j, color2);
            }
        }
    } // 左黑色大圈，右红色大圈
    int r1 = 50;
    for (int i = x - r1; i < x + r1; i++)
    {
        for (int j = y - r; j < y + r; j++)
        {
            if (j < 240) // 上半区域
            {
                if (sqrt(pow(i - x, 2) + pow(j - (y - r1), 2)) < r1) // 圆心向上移动了50
                {
                    if (i < 400)
                        lcd_draw_point(i, j, color2);
                }
            }
            else
            {
                if (sqrt(pow(i - x, 2) + pow(j - (y + r1), 2)) < r1) // 圆心向上移动了50
                {
                    if (i >= 400)
                        lcd_draw_point(i, j, color1);
                }
            }
        }
    }
    int r2 = r1 / 4;    //小圆半径
    draw_circle(x, y - r1, r2, color1);
    draw_circle(x, y + r1, r2, color2);
}

/*
    功能:
        显示一个字符
    参数：
        (x0, y0): 在第y0行的第x0个像素点开始进行字符显示
        w:字符的宽   h: 字符的高
        color: 字符的颜色
        word: 需要进行显示的字符的像素点取模数组
*/
void display_word(int x0, int y0, int w, int h, unsigned int color, char *word)
{
    int x, y;                           // 表示需要显示的像素的坐标
    for (int i = 0; i < w * h / 8; i++) // 循环次数为数组里面的元素个数，遍历数组
    {
        for (int j = 0; j < 8; j++) // 进行bit遍历
        {
            if (word[i] & (1 << (7 - j))) // 从高位开始向低位遍历
            {
                y = i / (w / 8);
                x = i % (w / 8) * 8 + j;
            }
            lcd_draw_point(x0 + x, y0 + y, color);
        }
    }
}

/*
    使用display_word函数的中间函数
    参数：color---字体颜色
*/
void useing_word(unsigned int color)
{
    int x0, y0;
    /*
    printf("请输入开始打印字符的x坐标:");
    scanf("%d", &x0);
    printf("请输入开始打印字符的y坐标:");
    scanf("%d", &y0);
    */
   //数组大小48*48/8；
    x0 = 450;
    y0 = 350;
    int w = 48, h = 48;
    char *str[] = {word, word1, word2, word3}; // 用来存储字符矩阵的数组的首地址名称
    for (int i = 0; i < 4; i++)
    {
        display_word(x0 + i * 50, y0, w, h, color, str[i]);
    }
}

/*打印你输了！*/
void useing_word1(unsigned int color)
{
    int x0, y0;
    /*
    printf("请输入开始打印字符的x坐标:");
    scanf("%d", &x0);
    printf("请输入开始打印字符的y坐标:");
    scanf("%d", &y0);
    */
   //数组大小48*48/8；
    x0 = 450;
    y0 = 350;
    int w = 48, h = 48;
    char *str[] = {word, word4, word2, word3}; // 用来存储字符矩阵的数组的首地址名称
    for (int i = 0; i < 4; i++)
    {
        display_word(x0 + i * 50, y0, w, h, color, str[i]);
    }
}


