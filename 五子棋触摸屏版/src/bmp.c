#include "bmp.h"
#include "Touch.h"
/*
    获取BMP图片的信息
    参数：BMP图片的路径
*/
BMP get_bmp_info(char *bmpname)
{
    int fd_bmp = open(bmpname, O_RDONLY);
    if (fd_bmp == -1)
    {
        perror("open bmp error");
        exit(1);
    }

    // 判断该文件是否为bmp文件
    char bm[2] = {0};
    read(fd_bmp, bm, 2);
    if (!(bm[0] == 'B' && bm[1] == 'M'))
    {
        printf("%s is not BMP file\n", bmpname);
        exit(1);
    }

    // 获取bmp图片的数据
    BMP bmpinfo;

    // 文件大小
    lseek(fd_bmp, 0x02, SEEK_SET);
    read(fd_bmp, &bmpinfo.size, 4);

    // 宽度和高度
    lseek(fd_bmp, 0x12, SEEK_SET);
    read(fd_bmp, &bmpinfo.width, 4);
    read(fd_bmp, &bmpinfo.height, 4);

    //色深
    lseek(fd_bmp, 0x1c, SEEK_SET);
    read(fd_bmp, &bmpinfo.depth, 2);

    //像素数组
    char* p=malloc(bmpinfo.size - 54);  //图片总大小 - 文件头大小
    lseek(fd_bmp ,0x36, SEEK_SET);
    read(fd_bmp, p,bmpinfo.size-54);
    bmpinfo.data = p;

    close(fd_bmp);
    return bmpinfo;
}

/*
    功能：
        显示一张BMP图片
    参数：
        (x, y) 图片从那个位置开始进行显示 x.y为图片的最左上角的坐标
        bmpname: 需要进行显示的图片的路径
*/
void lcd_draw_bmp(int x,int y,char *bmpname)
{
    BMP bmp=get_bmp_info(bmpname);

    //printf("bmpname=%s, size=%d, height = %d, depth = %d\n",bmpname, bmp.size, bmp.width, bmp.height, bmp.depth);
    
    //一行的有效字节数
    int line_types = bmp.width*bmp.depth / 8;

    //一行需要填充字节数
    int pad_types=(line_types % 4 == 0)? 0 : (4 - line_types % 4);

    //解析像素数组中的数据
    unsigned int color;
    unsigned char a,r,g,b;  //颜色分量

    char* p=bmp.data;
    for(int h=0; h < abs(bmp.height); h++)
    {
        for(int w=0; w < abs(bmp.width); w++)
        {
            //获取颜色分量,小端模式存储
            b=*(p++);
            g=*(p++);
            r=*(p++);
            a=(bmp.depth == 24)? 0:*(p++);
            //合成像素点
            color=a<<24 | r<<16 | g<<8 | b;

            //描点
            // width > 0 : 每一行的像素点从左往右存放
            // width < 0 : 每一行的像素点从右往左存放
            // height > 0: 每一列的像素点从下往上存放
            // height < 0: 每一列的像素点从上往下存放
            int m = x+w;      //横坐标  一行中的第几个像素点
            int n = y+bmp.height-1-h;        //纵坐标  第几行
            lcd_draw_point(m, n, color);
        }
        
        p+=pad_types;
    }
}

/*自动播放电子相册*/
void atuo_photo()
{
    char *str[]={"1.bmp","2.bmp","3.bmp","4.bmp","5.jpg"};
    int n=10;
    while(n--)
    {
        for(int i=0;i<5;i++)
        {
            char temp[20]={0};
            strncat(temp,str[i],strlen(str[i])-4);
            strcat(temp,".bmp");
            if(strcmp(temp,str[i]) == 0)
            {
                lcd_draw_bmp(0,0,str[i]);   //打印bmp文件
            }
            else
            {
                lcd_draw_jpeg(0,0,str[i]);    //打印jpg文件
            }
            sleep(3);
            Clean_lcd();
        }
    }
}


