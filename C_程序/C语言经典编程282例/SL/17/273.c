#include <conio.h>
#include <math.h>
#include <graphics.h>
main()
{
    int y = 200;
    int i, h;
    float m;
    int gdriver, gmode;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");							/*图形方式初始化*/
    setviewport(50, 50, 450, 450, 1);							/*设定图形窗口*/
    setcolor(14);											/*设置绘图颜色为黄色*/
    rectangle(0, 0, 400, 400);								/*画矩形框*/
    line(200, 0, 200, 400);									/*画纵坐标轴*/
    line(0, 200, 400, 200);									/*画横坐标轴*/
    for (i = 0; i < 400; i++)
    {
        m = 100 * sin(i / 31.83);								/*求每个像素对应的sin值*/
        h = y - (int)m;									/*求出每个像素点的相对坐标轴纵坐标的位置*/
        putpixel(i, h, 15);									/*画点*/
        delay(10000);
    }
    getch();
    closegraph();										/*退出图形状态*/
} 
