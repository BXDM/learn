#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<bios.h>
#define  R 4
#define Key_Up  0x4800
#define Key_Enter 0x1c0d
#define Key_Down  0x5000 
struct wall/*墙*/
{ int x;
  int y;
  int color;
}a[20][20];
int Keystate;
int MouseX;
int MouseY=400;
int dx=1,dy=1;	    /*计算球的反弹*/
int sizex=20,sizey=10;      /*墙的宽度和长度*/
int Ide,Key;
void draw(int x,int y)     /*画组成墙的砖*/
{
 int sizx=sizex-1;
 int sizy=sizey-1;
 setcolor(15);
 line(x,y,x+sizx,y);
 line(x,y+1,x+sizx,y+1);
 line(x,y,x,y+sizy);
 line(x+1,y,x+1,y+sizy);
 setcolor(4);
 line(x+1,y+sizy,x+sizx,y+sizy);
 line(x+2,y+sizy-1,x+sizx,y+sizy-1);
 line(x+sizx-1,y+1,x+sizx-1,y+sizy);
 line(x+sizx,y+2,x+sizx,y+sizy);
 setfillstyle(1,12);
 bar(x+2,y+2,x+sizx-2,y+sizy-2);
}

void picture(int r,int l)   /*画墙*/
{ int i,j;
  setcolor(15);
  rectangle(100,50,482,461);
  for(i=0;i<r;i++)
      for(j=0;j<l;j++)
	 { a[i][j].color=0;
	   a[i][j].x=106+j*25;
	   a[i][j].y=56+i*15;
	   draw(106+j*25,56+i*15);
         }
	     sizex=50,sizey=5;
}

void MouseOn(int x,int y)/*鼠标光标显示*/
{
  draw(x,y);
}

void MouseSetX(int lx,int rx)/*设置鼠标左右边界*/
  {
   _CX=lx;
   _DX=rx;
   _AX=0x07;
   geninterrupt(0x33);
  }

void MouseSetY(int uy,int dy)/*设置鼠标上下边界*/
  {
   _CX=uy;
   _DX=dy;
   _AX=0x08;
   geninterrupt(0x33);
  }

void MouseSetXY(int x,int y)/*设置鼠标当前位置*/
  {
   _CX=x;
   _DX=y;
   _AX=0x04;
   geninterrupt(0x33);
  }



void MouseSpeed(int vx,int vy)/*设置鼠标速度*/
  {
   _CX=vx;
   _DX=vy;
   _AX=0x0f;
   geninterrupt(0x33);
  }

void MouseGetXY()/*获取鼠标当前位置*/
  {
   _AX=0x03;
   geninterrupt(0x33);
   MouseX=_CX;
   MouseY=_DX;
  }
void MouseStatus()/*鼠标按键情况*/
{
 int x;
 int status;
 status=0;
 x=MouseX;
 if(x==MouseX&&status==0) /*判断鼠标是否移动*/
 {
  MouseGetXY();
  if(MouseX!=x)
     if(MouseX+50<482)
        status=1;
 }
 if(status)/*如果鼠标移动则重新显示鼠标*/
 {
   setfillstyle(1,0);
   bar(x,MouseY,x+sizex,MouseY+sizey);
   MouseOn(MouseX,MouseY);
 }
}


void Play(int r,int l)
{int ballX;
 int ballY=MouseY-R;
 int i,j,t=0;
 srand((unsigned long)time(0));
do
{
	ballX=rand()%477;
}while(ballX<=107||ballX>=476);/*随机产生小球的位置*/
 while(kbhit)
{
 MouseStatus();
 if(ballY<=(59-R))   /*碰上反弹*/
    dy*=(-1);
 if(ballX>=(482-R)||ballX<=(110-R)) /*碰左右反弹*/
    dx*=(-1);
 setcolor(YELLOW);
 circle(ballX+=dx,ballY-=dy,R-1);
 delay(2500);
 setcolor(0);/*将球移动后留下的印记用背景色覆盖*/
 circle(ballX,ballY,R-1);
 for(i=0;i<r;i++)
     for(j=0;j<l;j++)       /*判断是否撞到墙*/
	 if(t<l*r&&a[i][j].color==0 && ballX>=a[i][j].x && ballX<=a[i][j].x+20
              && ballY>=a[i][j].y && ballY<=a[i][j].y+10)
              {t++;
               dy*=(-1);
	       a[i][j].color=1;
	       setfillstyle(1,0);
	       bar(a[i][j].x,a[i][j].y,a[i][j].x+20,a[i][j].y+10);
              }
 if(ballX==MouseX||ballX==MouseX-1||ballX==MouseX-2&&ballX==(MouseX+50+2)||ballX==(MouseX+50+1)||ballX==(MouseX+50)) /*判断球落在板的边缘*/
    if(ballY>=(MouseY-R))
      { dx*=(-1);
        dy*=(-1);         /*原路返回*/
      }
 if(ballX>MouseX && ballX<(MouseX+50)) /*碰板反弹*/
    if(ballY>=(MouseY-R))
       dy*=(-1);
 if(t==l*r)/*判断是否将墙壁完全清除*/
   { sleep(1);
     cleardevice();
     setcolor(RED);
     settextstyle(0,0,4);
     outtextxy(100,200,"Win");
     sleep(1);
     break;
   }
 if(ballY>MouseY)
   { sleep(1);
     cleardevice();
     setcolor(RED);
     settextstyle(0,0,4);
     outtextxy(130,200,"Game Over");
     sleep(1);
     break;
   }
 }
 dx=1,dy=1;	    /*dx、dy重新置1*/
 sizex=20,sizey=10;
}
void Rule()/*游戏规则*/
{
int n;
char *s[5]={"move the mouse right or left to let the ball rebound","when the ball bounce the wall","the wall will disappear","when all the wall disappear","you will win!"};
settextstyle(0,0,1);
setcolor(GREEN);
for(n=0;n<5;n++)
outtextxy(150,170+n*20,s[n]);
}

void DrawMenu(int j)/*菜单中的选项*/
{
int n;
char *s[4]={"1.Mession One","2.Mession two","3.rule","4.Exit Game"};
settextstyle(0,0,1);
setcolor(GREEN);
for(n=0;n<4;n++)
outtextxy(250,170+n*20,s[n]);
setcolor(RED);/*选中那个菜单，那个菜单变为红色*/
outtextxy(250,170+j*20,s[j]);
}
void MainMenu()/*主菜单*/
{
void JudgeIde();
setbkcolor(BLACK);
cleardevice();
Ide=0,Key=0;
DrawMenu(Ide);
do
  {
  if(bioskey(1))   /*有键按下则处理按键*/
       {
       Key=bioskey(0);
       switch(Key)
     {
     case Key_Down:
	     {
		     Ide++;Ide=Ide%4;
		     DrawMenu(Ide);
		     break;
	     }
     case Key_Up:
	     {
		     Ide--;
		     Ide=(Ide+4)%4;
		     DrawMenu(Ide);
		     break;
	     }
     }
       }
  }while(Key!=Key_Enter);
JudgeIde();         /*调用judgeIde*/
}
void JudgeIde()
{
switch(Ide)
   {
   case 0:
	   cleardevice();
 picture(6,15);
 MouseSetX(101,431);           /*设置鼠标移动的范围*/
 MouseSetY(MouseY,MouseY);     /*鼠标只能左右移动*/
 MouseSetXY(150,MouseY);       /*鼠标的初始位置*/
 Play(6,15);
 MainMenu();
 break;
   case 1:{
	   cleardevice();
     picture(9,15);
     MouseSetX(101,431);
 MouseSetY(MouseY,MouseY);
 MouseSetXY(150,MouseY);
     Play(9,15);
     MainMenu();
     break;}
   case 2:{
	   cleardevice();
Rule();
sleep(8);
   MainMenu();
   break;}
   case 3:cleardevice();
	     settextstyle(0,0,4);
	     outtextxy(150,200,"goodbye!");
	     sleep(1);
	   exit(0);
   }
}
void main()
{int gdriver=DETECT,gmode;
 initgraph(&gdriver,&gmode,"");
 MainMenu();
 closegraph();
}
