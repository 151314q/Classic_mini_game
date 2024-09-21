//#include "Photoalbum.h"
#include "process2048.h"
#include "Touch.h"

extern int data[4][4];  //2048游戏的数组
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
/*
    while (1)
    {
        offer_file_photo();
        int x = -1, y = -1;
        get_xy(&x, &y);
        exchang_data(&x,&y);
        printf("x=%d,y=%d\n",x,y);
        if (x > 700 && y > 420)
        {
            printf("关闭相册\n");
            lcd_draw_plane(0xff00ffff);
            break; // 退出循环，关闭程序
        }

        list_photo *listphoto = create_listhead();

        if (y > 0 && y < 60)
        {
            if (x > 0 && x < 100)
                get_photo_file("album1", listphoto);
            else if (x>=100 && x < 200)
                get_photo_file("album2", listphoto);
            else if (x>=200 && x < 300)
                get_photo_file("album3", listphoto);
            else if (x>=300 && x < 400)
                get_photo_file("album4", listphoto);
        }   //如果要加入新文件夹可在这里添加，也需在--offer_file_photo()--函数当中添加一张代表文件夹的图片
        else
            goto fan;

        //printf("------%d------\n",__LINE__);
        photonode *temp = listphoto->first; // temp为链表首元素
        if(temp==NULL)  //解决没有照片的情况
        {
            printf("这里没有照片\n");
            goto fan;
        }
        while (1)
        {
            Clean_lcd();
            judge_bmp_or_jpg(temp);
            int sign = get_slipp();
            switch (sign)
            {
            case 1:
                temp = temp->pre;
                printf("左滑成功\n");
                break;
            case 2:
                temp = temp->next;
                printf("右滑成功\n");
                break;
            case 3:
                printf("上滑成功\n");
                goto fan;
                break;
            case 4:
                printf("下滑成功\n");
                goto fan;
                break;
            default:
                printf("滑动不成功\n");
                break;
            }
        }
    fan:
        Clean_lcd();
    }

*/

    produce_data_0(data);
    produce_data(data);
    int sign;
    while(1)
    {
        sign=get_slipp();
        int juice=juice_();
        if(juice==0)
        {
            printf("游戏结束,你失败了\n");
            lcd_draw_bmp(0,0,"gameover.bmp");
            Lcd_uninit();
            close(fd);
            return 0;
        }
        else if(juice==1)
        {
            printf("游戏成功，你赢了\n");
            lcd_draw_bmp(0,0,"gameover.bmp");
            break;
        }                                 //循环结束条件
        process_(sign);
        
    }
    int sum=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            sum=sum+data[i][j];
    printf("你的得分是%d\n",sum);
    
    Lcd_uninit();
    close(fd);

    return 0;
}