#include <graphics.h>
main()
{
    int gdriver, gmode;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");						/*图形方式初始化*/
    setbkcolor(GREEN);								/*设置背景颜色为绿色*/
    setcolor(RED);									/*设置绘图颜色为红色*/
    arc(getmaxx() / 2, getmaxy() / 2, 0, 120, 100);				/*画圆弧*/
    getch();
    closegraph();									/*退出图形状态*/
}
