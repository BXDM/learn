#include <graphics.h>
main()
{
    int gdriver, gmode;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");							/*图形方式初始化*/
    setbkcolor(WHITE);									/*设置背景色为红色*/
    setcolor(RED);										/*设置绘图色为黄色*/
    circle(getmaxx() / 2, getmaxy() / 2, 100);						/*画圆*/
    getch();
    closegraph();										/*退出图形状态*/
}
