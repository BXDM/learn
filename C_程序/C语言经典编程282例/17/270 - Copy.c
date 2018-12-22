#include <graphics.h>
main()
{
    int gdriver, gmode;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, ""); /*图形方式初始化*/
    pieslice(260, 200, 0, 120, 100); /*画扇区*/
    getch();
    closegraph(); /*退出图形状态*/
}
