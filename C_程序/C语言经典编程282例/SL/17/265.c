#include <graphics.h>
main()
{
    int gdriver, gmode;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");							/*图形方式初始化*/
    setcolor(RED);										/*设置作图颜色*/
    setlinestyle(DASHED_LINE, 0, 3);							/*设置线的宽度和形式*/
    rectangle(100, 100, 550, 350);								/*画矩形*/
    getch();
    closegraph();										/*退出图形状态*/
}
