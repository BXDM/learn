#include <graphics.h>
void main()
{
    int gdriver, gmode;
    int i, start, end;										/*设置变量为基本整型*/
    gdriver = DETECT;
    initgraph(&gdriver, gmode, "");							/*图形方式初始化*/
    start = 0;											/*start赋初值为0°*/
    end = 45;											/*end赋初值为45°*/
    for (i = 0; i < 8; i++)
    {
        setfillstyle(SOLID_FILL, i);							/*设置填充方式*/
        pieslice(getmaxx() / 2, getmaxy() / 2, start, end, 200);		/*画扇形*/
        start += 45;										/*起始角度数每次增加45°*/
        end += 45;										/*终止角度数每次增加45°*/
    }
    getch();
    closegraph();										/*退出图形状态*/
}
