#ifndef _LCD_H_
#define _LCD_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/mman.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*用白色作为清屏*/
void Clean_lcd();

/*
    用write函数向屏幕中写入数据
    参数：文件标识符fd、颜色数据color
*/
void Write_lcd(int fd, int color);

/*使用三种颜色刷新显示屏*/
void shuaxing_write_lcd(int fd);

/*打开映射*/
void Lcd_init(int fd);

/*解除映射*/
void Lcd_uninit();

/*画点函数*/
void lcd_draw_point(int x,int y,unsigned int color);

/*画横线函数*/
void lcd_draw_line(int y,unsigned int color);

/*画竖线函数*/
void lcd_draw_line1(int x,unsigned int color);

/*画平面函数*/
void lcd_draw_plane(unsigned int color);

/*画矩形函数*/
void draw_juxing();

/*画圆函数*/
void draw_circle(int x, int y, int r, unsigned int color);

/*画爱心：爱心函数---> (x^2 + y^2 - 1)^3 - x^2 * y^3 = 0 */
void draw_aixing();

/*画太极函数*/
void draw_taiji();

/*
    功能:
        显示一个字符
    参数：
        (x0, y0): 在第y0行的第x0个像素点开始进行字符显示
        w:字符的宽   h: 字符的高
        color: 字符的颜色
        word: 需要进行显示的字符的像素点取模数组
*/
void display_word(int x0,int y0,int w,int h,unsigned int color,char *word);

/*
    使用display_word函数的中间函数
    参数：color---字体颜色
*/
void useing_word(unsigned int color);

#endif