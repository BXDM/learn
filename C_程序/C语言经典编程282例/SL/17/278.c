#include <graphics.h>
void main(void)
{
    int color;											/*定义变量color为基本整型*/
    int gdriver, gmode;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");							/*图形方式初始化*/
    for (color = 0; color <= 14; color++)
    {
        setbkcolor(color);									/*设置背景颜色*/
        getch();
    }
    closegraph();
}
