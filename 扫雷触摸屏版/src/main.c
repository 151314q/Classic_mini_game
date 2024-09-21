// #include "Photoalbum.h"
//#include "gobang_process.h"
//#include "gobang_beginover.h"
//char data_gobang[400 / 25][600 / 25] = {0}; // 棋盘数组，大小由间隔25和最大范围400、600决定

#include "Minesweeper_bagin.h"
#include "Minesweeper_process.h"
extern char data[N][N];
extern char data5[N][N];

int N1;    //采用变量记录雷的个数，用于调整游戏难度
int n;      //用于记录当前雷的数量
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

    /*  电子相册
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

   int Diff;
Again:
    Diff=get_game_difficulty();     //触摸选择难度
    if(Diff==1)    N1=10;
    else if(Diff==2)    N1=25;
    else if(Diff==3)    N1=35;
    else if(Diff==4)    N1=50;

    n=N1; 
    int x, y,z=0;  //n记录雷的数量
    int sign;
    chu_shi_hua();
    saolei_jiemian();
    
    while (1)
    {
        sign=get_function_poition();
        switch (sign)
        {
        case 2:
            get_saolei_poition(&x,&y);
            printf("x=%d,y=%d\n",x,y);
            z = quxiao_(x, y,z);
            break;              //取消标记的雷
        case 3:
            get_saolei_poition(&x,&y);
            printf("x=%d,y=%d\n",x,y);
            n = bomb_w(x, y, z);
            z = 0;
            xianshi_bmp(x,y);
            break;              //挖掉雷
        case 1:
            get_saolei_poition(&x,&y);
            printf("x=%d,y=%d\n",x,y);
            if(click_e(x,y)==0)
            {
                xianshi_bmp(x,y);
                printf("你输了\n");
                useing_word1(0xffff0000);
                goto fan;
            }
            else
            {
                xianshi_bmp(x,y);
            }
            break;              //点开格子，点错就输了
        case 4:
            goto Again;
            break;
        default:
            return 0;
        } 
        printf("n==%d\n",n);
        if (n==0)
        {
            int temp=0;
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                {
                    if(data[i][j]=='x' && data5[i][j]=='!')
                        temp++;
                }
            if(temp==N1)
            {
                printf("胜利\n");
                useing_word(0xff000000);
                break;
            }
        }
    } // 结束条件拟定为两个数组中 ‘x’与‘!’是否一一对应
fan:
    while(1)
    {
        int again=get_function_poition();
        if(again==4) goto Again;    //再来一局
        else if(again == 5) break;
    }

    Lcd_uninit(); // 关闭映射
    close(fd);

    return 0;
}