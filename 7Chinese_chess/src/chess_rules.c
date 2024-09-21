#include "chess_Initial.h"

extern int data_chess[400/40][360/40];

//判断落点位置是否有效
int judge_Drop_position(int i0,int j0,int i1, int j1)
{
    //判断落点情况：1、无棋；2、己方棋子；3、敌方棋子
    if(data_chess[i1][j1]==0)
        return 1;   //无棋子
    else if(data_chess[i0][j0] < 10)    //初始化黑棋为1~7，该棋为黑棋；
    {
        if(data_chess[i1][j1] < 10)
            return 0;       //己方棋子，不可吃
        else
            return 1;
    }
    else if(data_chess[i0][j0] > 10)    //初始化为红棋
    {
        if(data_chess[i1][j1] > 10)
            return 0;       //己方棋子，不可吃
        else
            return 1;
    }
}

/*判断“车”移动是否有效
    输入：i0、j0为移动前位置；i1、j1为移动后位置
    返回值：1有效 0无效
*/
int rules_ju(int i0, int j0, int i1, int j1)
{
    //如果出现车在一条直线上移动
    if(i0==i1 || j0==j1)
    {
        if(i0==i1)
        {
            if(j0 < j1)      //往右走
            {
                for(int j=j0+1; j<j1; j++)       //两次位置中间不能有棋子，否则不符合规则
                    if(data_chess[i0][j]!=0)
                        return 0;
            }
            else            //往左走
            {
                for(int j=j0-1; j>j1; j--)
                    if(data_chess[i0][j] != 0)
                        return 0;
            }
        }
        else if(j0==j1)
        {
            if(i0 < i1) //往下走
            {
                for(int i=i0+1; i<i1; i++)
                    if(data_chess[i][j0] != 0)
                        return 0;
            }
            else    //往上走
            {
                for(int i=i0-1; i>i1; i--)
                    if(data_chess[i][j0] != 0)
                        return 0;
            }
        }

        //判断落点情况：1、无棋；2、己方棋子；3、敌方棋子
        if(data_chess[i1][j1]==0)
            return 1;   //无棋子
        else if(data_chess[i0][j0] < 10)    //初始化黑棋为1~7，该棋为黑棋；
        {
            if(data_chess[i1][j1] < 10)
                return 0;       //己方棋子，不可吃
            else
                return 1;
        }
        else if(data_chess[i0][j0] > 10)    //初始化为红棋
        {
            if(data_chess[i1][j1] > 10)
                return 0;       //己方棋子，不可吃
            else
                return 1;
        }
    }
    else    return 0;  //否则移动失败
}

/*判断 “马” 移动是否有效
    输入：i0、j0为移动前位置；i1、j1为移动后位置
    返回值：1有效 0无效
*/
int rules_ma(int i0, int j0, int i1, int j1)
{
    //首先判断马的走向
    int temp=abs(i0-i1) > abs(j0-j1)? 0:1;  //0为竖向走，1为横向走
    if( (i1==i0+1 && (j1==j0+2 || j1==j0-2)) ||
        (i1==i0-1 && (j1==j0+2 || j1==j0-2)) ||
        (j1==j0+1 && (i1==i0+2 || i1==i0-2)) ||
        (j1==j0-1 && (i1==i0+2 || i1==i0-2)) )      //马移动可能性
    {
        //判断落点是否符合规则
        if(i0-1>=0 && data_chess[i0-1][j0] != 0)    //棋子上方有棋子
        {
            if(j1==j0-1 && i1==i0-2)    return 0;   //该位置无法移动
            if(j1==j0+1 && i1==i0-2)    return 0;   //该位置无法移动
        }
        if(i0+1<10 && data_chess[i0+1][j0] != 0)       //棋子下方有棋子
        {
            if(j1==j0-1 && i1==i0+2)    return 0;   //该位置无法移动
            if(j1==j0+1 && i1==i0+2)    return 0;   //该位置无法移动
        }
        if(j0-1>=0 && data_chess[i0][j0-1] != 0)       //棋子左方有棋子
        {
            if(i1==i0-1 && j1==j0-2)    return 0;   //该位置无法移动
            if(i1==i0+1 && j1==j0-2)    return 0;   //该位置无法移动
        }
        if(j0+1<9 && data_chess[i0][j0+1] != 0)       //棋子左方有棋子
        {
            if(i1==i0-1 && j1==j0+2)    return 0;   //该位置无法移动
            if(i1==i0+1 && j1==j0+2)    return 0;   //该位置无法移动
        }
        //判断落点是否有棋子，落点位置是否有效
        //判断落点情况：1、无棋；2、己方棋子；3、敌方棋子
        if(data_chess[i1][j1]==0)
            return 1;   //无棋子
        else if(data_chess[i0][j0] < 10)    //初始化黑棋为1~7，该棋为黑棋；
        {
            if(data_chess[i1][j1] < 10)
                return 0;       //己方棋子，不可吃
            else
                return 1;
        }
        else if(data_chess[i0][j0] > 10)    //初始化为红棋
        {
            if(data_chess[i1][j1] > 10)
                return 0;       //己方棋子，不可吃
            else
                return 1;
        }
    }
    else    return 0;   //除上之外移动错误。
}

/*判断 “相--象” 移动是否有效
    输入：i0、j0为移动前位置；i1、j1为移动后位置
    返回值：1有效 0无效
*/
int rules_xiang(int i0, int j0, int i1, int j1)
{
    //黑方象，不可过界
    if( (data_chess[i0][j0]<10 && i1>4) ||
        (data_chess[i0][j0]>10 && i1<5) )   //红方相，不可过界
    {
        return 0;   //因此，过界移动失效
    }
    
    if( i1==i0+2 &&(j1==j0+2 || j1==j0-2) ||
        i1==i0-2 &&(j1==j0+2 || j1==j0-2) )
    {
        if(i0+1<10 && j0+1<9 && data_chess[i0+1][j0+1]!=0)  //象的中间有棋子，不可移动
            if(i1==i0+2 && j1==j0+2)    return 0;
        if(i0+1<10 && j0-1>=0 && data_chess[i0+1][j0-1]!=0)  //象的中间有棋子，不可移动
            if(i1==i0+2 && j1==j0-2)    return 0;
        if(i0-1>=0 && j0+1<9 && data_chess[i0-1][j0+1]!=0)  //象的中间有棋子，不可移动
            if(i1==i0-2 && j1==j0+2)    return 0;
        if(i0-1>=0 && j0-1>=0 && data_chess[i0-1][j0-1]!=0)  //象的中间有棋子，不可移动
            if(i1==i0-2 && j1==j0-2)    return 0;

        //判断落点位置是否有效
        if(judge_Drop_position(i0,j0,i1,j1))
            return 1;
        else    return 0;
    }
    else    return 0;   //除上之外,移动错误。
}

/*判断 “士--仕” 移动是否有效
    输入：i0、j0为移动前位置；i1、j1为移动后位置
    返回值：1有效 0无效
*/
int rules_shi(int i0, int j0, int i1, int j1)
{
    if(j1>5 || j1<3)    //士不可出左右界
        return 0;
    if(data_chess[i0][j0]<10)   //黑士不可出下界
        if(i1>2)
            return 0;
    if(data_chess[i0][j0]>10)   //红士不可出上界
        if(i1<7)
            return 0;
    if( i1==i0+1&&(j1==j0+1 || j1==j0-1) ||
        i1==i0-1&&(j1==j0+1 || j1==j0-1) )
    {
        //判断落点是否有棋子
        //判断落点情况：1、无棋；2、己方棋子；3、敌方棋子
        if(judge_Drop_position(i0,j0,i1,j1))
            return 1;
        else    return 0;
    }
    else    return 0;   //除上之外,移动错误。
}

/*判断 “炮” 移动是否有效
    输入：i0、j0为移动前位置；i1、j1为移动后位置
    返回值：1有效 0无效
*/
int rules_pao(int i0, int j0, int i1, int j1)
{
    //炮棋需要先判断落点情况：1、无棋；2、己方棋子；3、敌方棋子
    if(data_chess[i1][j1]==0)   //1、无棋子，表示炮直线移动
    {
        if(i0==i1 || j0==j1)
        {
            if(i0==i1)
            {
                if(j0 < j1)      //往右走
                {
                    for(int j=j0+1; j<j1; j++)       //两次位置中间不能有棋子，否则不符合规则
                        if(data_chess[i0][j]!=0)
                            return 0;
                    return 1;
                }
                else            //往左走
                {
                    for(int j=j0-1; j>j1; j--)
                        if(data_chess[i0][j] != 0)
                            return 0;
                    return 1;
                }
            }
            else if(j0==j1)
            {
                if(i0 < i1) //往下走
                {
                    for(int i=i0+1; i<i1; i++)
                        if(data_chess[i][j0] != 0)
                            return 0;
                    return 1;
                }
                else    //往上走
                {
                    for(int i=i0-1; i>i1; i--)
                        if(data_chess[i][j0] != 0)
                            return 0;
                    return 1;
                }
            }
        }
        else    return 0;
    }
    else if(data_chess[i0][j0]<10 && data_chess[i1][j1]<10 || 
            data_chess[i0][j0]>10 && data_chess[i1][j1]>10)     //2、己方棋子，不可吃
        return 0;
    else    //3、敌方棋子
    {
        if(i0==i1 || j0==j1)
        {
            if(i0==i1)
            {
                int temp=0;
                if(j0 < j1)      //往右走
                {
                    for(int j=j0+1; j<j1; j++)       //两个位置中间有且只能有一个棋子，否则不符合规则
                    {   
                        if(data_chess[i0][j]!=0)
                            temp++;
                    }
                    if(temp==1) return 1;
                    else    return 0;
                }
                else            //往左走
                {
                    for(int j=j0-1; j>j1; j--)
                        if(data_chess[i0][j] != 0)
                            temp++;
                    if(temp==1) return 1;
                    else    return 0;
                }
            }
            else if(j0==j1)
            {
                int temp=0;
                if(i0 < i1) //往下走
                {
                    for(int i=i0+1; i<i1; i++)
                        if(data_chess[i][j0] != 0)
                            temp++;
                    if(temp==1) return 1;
                    else    return 0;
                }
                else    //往上走
                {
                    for(int i=i0-1; i>i1; i--)
                        if(data_chess[i][j0] != 0)
                            temp++;
                    if(temp==1) return 1;
                    else    return 0;
                }
            }
        }
        else    return 0;
    }
}

/*判断 “将--帅” 移动是否有效
    输入：i0、j0为移动前位置；i1、j1为移动后位置
    返回值：1有效 0无效
*/
int rules_jiang(int i0, int j0, int i1, int j1)
{
    if(data_chess[i0][j0]==5)   //黑棋将，不可越界
    {
        if(data_chess[i1][j1]==15)  //可以越界吃帅
        {
            if(j0==j1)
            {
                for(int i=i0+1; i<i1; i++)
                    if(data_chess[i][j0]!=0)
                        return 0;
                return 1;
            }
            else    return 0;
        }
        if(j1>5||j1<3||i1>2)    //越界
            return 0;   //移动失败
    }
    else if(data_chess[i0][j0]==15)   //红旗帅，不可越界
    {
        if(data_chess[i1][j1]==5)  //可以越界吃将
        {
            //printf("---%d---\n",__LINE__);
            if(j0==j1)
            {
                for(int i=i0-1; i>i1; i--)
                    if(data_chess[i][j0]!=0)
                        return 0;
                return 1;
            }
            else    return 0;
        }
        if(j1>5||j1<3||i1<7)    //越界
        {
            //printf("---%d---\n",__LINE__);
            return 0;   //移动失败
        }
    }

    //printf("---%d---\n",__LINE__);
    //将--帅每次只能移动一步
    if( i1==i0 &&(j1==j0-1 || j1==j0+1) ||
        j1==j0 &&(i1==i0-1 || i1==i0+1) )
    {
        //判断落点是否有棋子
        //判断落点情况：1、无棋；2、己方棋子；3、敌方棋子
        //printf("---%d---\n",__LINE__);
        if(judge_Drop_position(i0,j0,i1,j1))
            return 1;
        else    return 0;
    }
    else    return 0;
}

/*判断 “兵--卒” 移动是否有效
    输入：i0、j0为移动前位置；i1、j1为移动后位置
    返回值：1有效 0无效
*/
int rules_bing(int i0, int j0, int i1, int j1)
{
    if(data_chess[i0][j0]==7)   //黑棋卒
    {
        if(i0<=4)    //过界之前只能往下移动
        {
            if(j1!=j0)
                return 0;   //移动失败
        }
        if( i1==i0 && (j1==j0+1 || j1==j0-1) ||
            i1==i0+1 && j1==j0)     //小兵永不后退
        {
            //判断落点位置是否有效
            if(judge_Drop_position(i0,j0,i1,j1))
                return 1;
            else    return 0;
        }
        else    return 0;
    }
    else if(data_chess[i0][j0]==17) //红旗兵
    {
        if(i0>=5)    //过界之前只能往上移动
        {
            if(j1!=j0)
                return 0;   //移动失败
        }
        if( i1==i0 && (j1==j0+1 || j1==j0-1) ||
            i1==i0-1 && j1==j0)     //小兵永不后退
        {
            //判断落点位置是否有效
            if(judge_Drop_position(i0,j0,i1,j1))
                return 1;
            else    return 0;
        }
        else    return 0;
    }
    return 0;
}

/*
    通过读取数组元素值来选择对应棋子的移动规则
    输入：i0、j0初始下标  i1、j1目标下标
    返回值：1成功，0失败
*/
int Selection_rule(int i0, int j0, int i1, int j1)
{
    switch (data_chess[i0][j0]%10)
    {
    case 1: return rules_ju(i0,j0,i1,j1);
        break;
    case 2: return rules_ma(i0,j0,i1,j1);
        break;
    case 3: return rules_xiang(i0,j0,i1,j1);
        break;
    case 4: return rules_shi(i0,j0,i1,j1);
        break;
    case 5: return rules_jiang(i0,j0,i1,j1);
        break;
    case 6: return rules_pao(i0,j0,i1,j1);
        break;
    case 7: return rules_bing(i0,j0,i1,j1);
        break;
    default:return 0;
        break;
    }    
}