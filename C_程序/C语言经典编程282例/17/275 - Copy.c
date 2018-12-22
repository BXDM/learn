#include <graphics.h>
main()
{
    int gdriver, gmode;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");						/*图形方式初始化*/
    setcolor(RED);									/*设置绘图颜色为红色*/
    ellipse(320, 240, 0, 360, 160, 80);						/*在屏幕中心绘制一椭圆*/
    setfillstyle(7, 14);									/*设置填充类型及颜色*/
    floodfill(320, 240, RED);							/*对椭圆进行填充*/
    getch();
    closegraph();									/*退出图形状态*/
}
