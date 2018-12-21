#include<graphics.h>						/*头文件为graphics.h*/
main()
{int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"");					/*使用initgraph函数进行图形初始化*/
line(100,300,300,300);						/*使用line函数画横线*/
moveto(350,50);							/*移动游标到（350，50）点*/
linerel(0,300); 						/*使用linerel函数画竖线*/
lineto(200,200);						/*使用lineto函数画斜线*/
getch();
closegraph();							/*退出图形状态*/
}