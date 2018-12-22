#include<graphics.h>
main()
{int gdriver,gmode,i,j;
/*cleardevice();							*/
gdriver=DETECT;
initgraph(&gdriver,&gmode,"");					/*初始化图形界面*/
for(i=120;i<=400;i=i+40)					/*设置起始点120，终止点400，表格宽度40*/
for(j=120;j<=400;j++)
{
putpixel(i,j,YELLOW);						/*画点*/
putpixel(j,i,YELLOW);
}
getch();
closegraph();							/*退出图形界面*/
}