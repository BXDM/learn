#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<bios.h>
#include<conio.h>

#define LEFT 0x4b00
#define RIGHT 0x4d00
#define DOWN 0x5000
#define UP 0x4800
#define ESC 0x011b
#define SPACE 0x3920
int chessx,chessy ;
int key ;
int chess[20][20];
int flag=1 ;
void chessboard();
void draw_cicle(int x,int y,int color);
void play();
int result(int x,int y);
void start();
void start()/*是否开始游戏*/
{
settextstyle(4,0,5);
outtextxy(80,240,"GAME START!");
settextstyle(3,0,3);
outtextxy(120,340,"ESC-exit/press any key to continue");
}
void chessboard()/*画棋盘*/
{
    int i,j ;
    setbkcolor(WHITE);
   cleardevice();										/*清屏*/
    for (i = 40; i <= 440; i = i + 20)							/*设置起始点120，终止点400，表格宽度40*/
    for (j = 40; j <= 440; j++)
    {
	putpixel(i,j,8);								/*画点*/
	putpixel(j,i,8);
    }
    setcolor(8);
 setlinestyle(1,0,1);
rectangle(32,32,448,448);
}
void draw_circle(int x,int y,int color)/*画棋子*/
{
    setcolor(color);
    setlinestyle(SOLID_LINE,0,1);
    x=(x+2)*20 ;
    y=(y+2)*20 ;
    circle(x,y,8);
}
void draw_pixel(int x,int y,int color)/*画点，棋走过所留下的点*/
{
    x=(x+2)*20;
    y=(y+2)*20;

		    {putpixel(x+8,y,color);
    putpixel(x,y-8,color);
    putpixel(x,y+8,color);
    putpixel(x-8,y,color);
}
}

void play()/*五子棋游戏过程*/
{
    int i ;
    int j ;
    switch(key)
    {
        case LEFT :

	if(chessx-1<0)/*判断向左走是否出了棋盘*/
	break;
        else
        {
	    for(i=chessx-1,j=chessy;i>=1;i--)
	    if(chess[i][j]==0)
            {
		draw_circle(chessx,chessy,WHITE);/*去除棋子走过留下的痕迹*/
		draw_pixel(chessx,chessy,8);
                break ;
            }
	    if(i<1)break ;
            chessx=i ;
             if(flag==1)/*判断flag值来确定要画的棋子的颜色*/
		  draw_circle(chessx,chessy,BLUE);
	  else
		  draw_circle(chessx,chessy,RED);
        }
	 break;
        case RIGHT :

	if(chessx+1>19)/*判断向右走是否出了棋盘*/
        break ;
        else
        {
	    for(i=chessx+1,j=chessy;i<=19;i++)
            if(chess[i][j]==0)
            {
	draw_circle(chessx,chessy,WHITE);/*去除棋子走过留下的痕迹*/
		draw_pixel(chessx,chessy,8);
                break ;
            }
	    if(i>19)break ;
            chessx=i ;
          if(flag==1)/*判断flag值来确定要画的棋子的颜色*/
		  draw_circle(chessx,chessy,BLUE);
	  else
		  draw_circle(chessx,chessy,RED);
        }
	break;
        case DOWN :

	if((chessy+1)>19)/*判断向下走是否出了棋盘*/
        break ;
        else
        {
	    for(i=chessx,j=chessy+1;j<=19;j++)
            if(chess[i][j]==0)
            {
		draw_circle(chessx,chessy,WHITE);/*去除棋子走过留下的痕迹*/
		draw_pixel(chessx,chessy,8);
                break ;
            }
	    if(j>19)break ;
            chessy=j ;
             if(flag==1)/*判断flag值来确定要画的棋子的颜色*/
		  draw_circle(chessx,chessy,BLUE);
	  else
		  draw_circle(chessx,chessy,RED);
        }
	break;
        case UP :

	if(chessy-1<0)/*判断向上走是否出了棋盘*/
        break;
        else
        {
	    for(i=chessx,j=chessy-1;j>=1;j--)
            if(chess[i][j]==0)
            {
		draw_circle(chessx,chessy,WHITE);/*去除棋子走过留下的痕迹*/
			draw_pixel(chessx,chessy,8);
                break ;
            }
	    if(j<1)break ;
            chessy=j ;
             if(flag==1)/*判断flag值来确定要画的棋子的颜色*/
		  draw_circle(chessx,chessy,BLUE);
	  else
		  draw_circle(chessx,chessy,RED);
        }
	break;
        case ESC :/*按ESC退出游戏*/
        break ;

        case SPACE :
	if(chessx>=1&&chessx<=19&&chessy>=1&&chessy<=19)/*判断棋子是否在棋盘范围内*/
        {
            if(chess[chessx][chessy]==0)/*判断该位置上是否有棋*/
            {
                chess[chessx][chessy]=flag ;/*若无棋则在该位置存入指定的棋子的flag值*/
                if(result(chessx,chessy)==1)/*判断下完该棋子游戏是否结束*/
                {
                    if(flag==1)/*如果flag是1则蓝棋赢*/
                    {
                        cleardevice();
			settextstyle(4,0,9);
			outtextxy(80,200,"BLUE Win!");
                        getch();
                        closegraph();
                        exit(0);
                    }
                    if(flag==2)/*如果flag是2则红棋赢*/
                    {
                        cleardevice();
			settextstyle(4,0,9);
			outtextxy(80,200,"Red Win!");
                        getch();
                        closegraph();
                        exit(0);
                    }
                }
               if(flag==1)/*若按下空格后游戏未结束则将棋的颜色改变*/
    flag=2 ;
    else
    flag=1 ;
                break ;
            }
        }
        else
        break ;
    }
}

int result(int x,int y)/*判断两种颜色的棋在不同方向的个数是否到达5个*/
{
    int j,k,n1,n2 ;
    while(1)
    {
          /*左上方*/
        n1=0 ;
        n2=0 ;
        for(j=x,k=y;j>=1&&k>=1;j--,k--)
        {
	    if(chess[j][k]==flag)
            n1++;
            else
            break ;
        }
        /*右下方*/
        for(j=x,k=y;j<=19&&k<=19;j++,k++)
        {
            if(chess[j][k]==flag)
            n2++;
            else
            break ;
        }
        if(n1+n2-1>=5)
            return(1);

        /*右上方*/
        n1=0 ;
        n2=0 ;
        for(j=x,k=y;j<=19&&k>=1;j++,k--)
        {
            if(chess[j][k]==flag)
            n1++;
            else
            break ;
        }
        /*左下方*/
        for(j=x,k=y;j>=1&&k<=19;j--,k++)
        {
            if(chess[j][k]==flag)
            n2++;
            else
            break ;
        }
        if(n1+n2-1>=5)
		return(1);
	n1=0 ;
        n2=0 ;
        /*水平向左*/
        for(j=x,k=y;j>=1;j--)
        {
            if(chess[j][k]==flag)
            n1++;
            else
            break ;
        }
        /*水平向右*/
        for(j=x,k=y;j<=19;j++)
        {
            if(chess[j][k]==flag)
            n2++;
            else
            break ;
        }
        if(n1+n2-1>=5)
	    return(1);

        /*垂直向上*/
        n1=0 ;
        n2=0 ;
        for(j=x,k=y;k>=1;k--)
        {
            if(chess[j][k]==flag)
            n1++;
            else
            break ;
        }
        /*垂直向下*/
        for(j=x,k=y;k<=19;k++)
        {
            if(chess[j][k]==flag)
            n2++;
            else
            break ;
        }
        if(n1+n2-1>=5)
            return(1);
        return(0);
    }
}

void main()
{
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"");/*图形界面初始化*/
start();/*调用start()*/
key=bioskey(0);/*接收键盘按键*/
if(key==ESC)/*按ESC退出游戏*/
exit(0);
else
{cleardevice();
	flag=1 ;/*设置flag初始值*/
    chessboard();/*画棋盘*/
    do
    {
	chessx=0 ;
	chessy=0 ;
	  if(flag==1)/*判断flag值来确定要画的棋子的颜色*/
		  draw_circle(chessx,chessy,BLUE);
	  else
		  draw_circle(chessx,chessy,RED);
        do
	{
            while(bioskey(1)==0);
            key=bioskey(0);/*接收键盘按键*/
	    play();/*调用play函数，进行五子棋游戏*/
        }
        while(key!=SPACE&&key!=ESC);/*当为ESC或空格时退出循环*/
    }
    while(key!=ESC);
    closegraph();/*退出图形界面*/
}
}
