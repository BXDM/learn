#include <graphics.h>
main()
{
    int gdriver, gmode;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");					/*图形方式初始化*/
    ellipse(200, 200, 0, 360, 50, 100);					/*以（200，200）为中心的椭圆*/
    getch();
    closegraph();								/*退出图形状态*/
}
