#include <graphics.h>
void main()
{
    int gdriver, gmode, n;
    int points[] =
    {
        200, 200, 150, 250, 150, 300, 200, 350, 250, 350, 300, 300, 300, 250,
            250, 200
    };														/*定义数组存放顶点坐标*/
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");									/*图形方式初始化*/
    setfillstyle(INTERLEAVE_FILL, RED);								/*设置填充方式*/
    n = sizeof(points) / (2 *sizeof(int));									/*计算定点个数*/
    fillpoly(n, points);												/*对多边形进行填充*/
    getch();
    closegraph();												/*退出图形状态*/
}
