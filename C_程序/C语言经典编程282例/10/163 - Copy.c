#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include<conio.h>
#define LEFT 0x4b00
#define RIGHT 0x4d00
#define DOWN 0x5000
#define UP 0x4800
#define ESC 0x011b
#define N 100/*贪吃蛇的最大长度*/
int i,key;
int speed;/*游戏速度*/
struct FOOD
{
   int x;/*食物的横坐标*/
   int y;/*食物的纵坐标*/
   int flag;/*标志是否要出现食物*/
}food;
struct Snake
{
   int x[N];
   int y[N];
   int node;/*蛇的节数*/
   int dir;/*蛇移动方向*/
   int life;/*标志是死是活*/
}snake;
void GameOver();/*结束游戏*/
void Play();/*玩游戏过程*/
void dwall();/*画墙*/
void wall(int x,int y);/*画组成墙的砖*/
int Speed();/*选择贪吃蛇的速度*/

main()
{
  int gdriver=DETECT,gmode;
   initgraph(&gdriver,&gmode,"");
   speed=Speed();/*将函数返回值赋给speed*/
   cleardevice();/*清屏*/
   dwall();/*开始画墙*/
   Play();/*开始完游戏*/
   getch();
   closegraph();/*退出图形界面*/
}

void wall(int x,int y)
{
 int sizx=9;
 int sizy=9;
 setcolor(15);/*白色画砖的上边和左边*/
 line(x,y,x+sizx,y);
 line(x,y+1,x+sizx-1,y+1);
 line(x,y,x,y+sizy);
 line(x+1,y,x+1,y+sizy-1);
 setcolor(4);/*红色画砖的右面和下面*/
 line(x+1,y+sizy,x+sizx,y+sizy);
 line(x+2,y+sizy-1,x+sizx,y+sizy-1);
 line(x+sizx-1,y+2,x+sizx-1,y+sizy-1);
 line(x+sizx,y+1,x+sizx,y+sizy);
 setfillstyle(1,12);/*用淡红色填充砖的中间部分*/
 bar(x+2,y+2,x+sizx-2,y+sizy-2);
}
void dwall()/*用前面画好的砖来画墙*/
{int j;
for(j=50;j<=600;j+=10)
{
	wall(j,40);/*画上面墙*/
	wall(j,451);/*画下面墙*/
}
for(j=40;j<=450;j+=10)
{
wall(50,j);/*画左面墙*/
wall(601,j);/*画右面墙*/
}
}
int Speed()/*选择贪吃蛇运行的速度*/
{           int m;
gotoxy(20,10);
   printf("level1\n");
   gotoxy(20,12);
   printf("level2\n");
   gotoxy(20,14);
   printf("level3\n\t\tplease choose:");
   scanf("%d",&m);
   switch(m)
   {
   case 1:return 60000;
   case 2:return 40000;
   case 3:return 20000;
   default:
   cleardevice();
   Speed();
   }
}

void Play(void)/*游戏实现过程*/
{
   srand((unsigned long)time(0));
   food.flag=1;/*1表示需出现新食物,0表示食物已存在*/
   snake.life=0;/*标志贪吃蛇活着*/
   snake.dir=1;/*方向向右*/
   snake.x[0]=300;snake.y[0]=240;/*定位蛇头初始位置*/
   snake.x[1]=300;snake.y[1]=240;
   snake.node=2;/*贪食蛇节数*/
   do
   {
      while(!kbhit())/*在没有按键的情况下,蛇自己移动身体*/
      {
	 if(food.flag==1)/*需要出现新食物*/
	 do
	 {
	     food.x=rand()%520+60;
	     food.y=rand()%370+60;
		food.flag=0;/*标志已有食物*/
	 }while(food.x%10!=0||food.y%10!=0);
	 if(food.flag==0)/*画出食物*/
	 {
              setcolor(GREEN);
	      setlinestyle(3,0,3);
              rectangle(food.x,food.y,food.x+10,food.y+10);
	 }
         for(i=snake.node-1;i>0;i--)/*实现蛇向前移动*/
         {
            snake.x[i]=snake.x[i-1];
	    snake.y[i]=snake.y[i-1];
	 }
      
	 switch(snake.dir)
	 {
	    case 1:snake.x[0]+=10;break;/*向右移*/
	    case 2: snake.x[0]-=10;break;/*向左移*/
	    case 3: snake.y[0]-=10;break;/*向上移*/
	    case 4: snake.y[0]+=10;break;/*向下移*/
	 }
	 for(i=3;i<snake.node;i++)
	 {
	    if(snake.x[i]==snake.x[0]&&snake.y[i]==snake.y[0])/*判断蛇是否吃到自己*/
	    {
               GameOver();/*游戏结束*/
               snake.life=1;/*蛇死*/
               break;
	    }
        }
	if(snake.x[0]<60||snake.x[0]>590||snake.y[0]<50||
	   snake.y[0]>440)/*蛇是否撞到墙壁*/
	{
	    GameOver();/*游戏结束*/
	    snake.life=1; /*蛇死*/
	    break;
	}
	if(snake.x[0]==food.x&&snake.y[0]==food.y)/*判断是否吃到食物*/
	{
           setcolor(0);/*用背景色遮盖调食物*/
           rectangle(food.x,food.y,food.x+10,food.y+10);
	   snake.node++;/*蛇的身体长一节*/
	   food.flag=1;/*需要出现新的食物*/
	}
	setcolor(4);/*画蛇*/
	for(i=0;i<snake.node;i++)
	 {     setlinestyle(0,0,1);
	   rectangle(snake.x[i],snake.y[i],snake.x[i]+10,
	       snake.y[i]+10);
	       }
	delay(speed);
	setcolor(0);/*用背景色遮盖蛇的的最后一节*/
	rectangle(snake.x[snake.node-1],snake.y[snake.node-1],
	snake.x[snake.node-1]+10,snake.y[snake.node-1]+10);
     }  /*endwhile（！kbhit）*/
    if(snake.life==1)/*如果蛇死就跳出循环*/
        break;
    key=bioskey(0);/*接收按键*/
       if(key==UP&&snake.dir!=4)/*判断是否往相反的方向移动*/
	  snake.dir=3;
       else
	 if(key==DOWN&&snake.dir!=3)/*判断是否往相反的方向移动*/
		   snake.dir=4;
	  else
	      if(key==RIGHT&&snake.dir!=2)/*判断是否往相反的方向移动*/
	     snake.dir=1;
	     else
	if(key==LEFT&&snake.dir!=1)/*判断是否往相反的方向移动*/
		snake.dir=2;
   }while(key!=ESC);/*ESC键退出游戏*/
}

void GameOver(void)
{
    cleardevice();
   setcolor(RED);
   settextstyle(0,0,4);
   outtextxy(50,200,"GAME OVER,BYE BYE!");
   sleep(3);
}
