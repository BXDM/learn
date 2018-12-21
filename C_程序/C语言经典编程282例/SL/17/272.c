#include <graphics.h>
int main()
{
    int gdriver, gmode, i;
    int point[16] =
    {
        200, 100, 300, 100, 300, 110, 330, 95, 300, 80, 300, 90, 200, 90, 200, 100
    };												/*将各顶点坐标存在数组point中*/
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");							/*图形方式初始化*/
    setbkcolor(BLUE);									/*设置背景颜色为蓝色*/
    cleardevice();										/*清屏*/
    setcolor(WHITE);										/*设置作图颜色*/
    drawpoly(8, point);									/*画一箭头*/
    getch();
    closegraph();
    return 0;
}
