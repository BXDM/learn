#include <graphics.h>
#include <math.h>
main()
{
    int i, j = 0, gdriver, gmode, points[20];
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");								/*图形方式初始化*/
    setcolor(YELLOW);										/*设置绘图颜色*/
    setlinestyle(0, 0, 1);										/*设置线形*/
    for (i = 0; i < 5; i++)
    {
        points[j++] = (int)(320+150 * cos(0.4 *3.1415926 * i));			/*五角星外圈点的横坐标存入数组中*/
        points[j++] = (int)(240-150 * sin(0.4 *3.1415926 * i));			/*五角星外圈点的纵坐标存入数组中*/
        points[j++] = (int)(320+50 * cos(0.4 *3.1415926 * i + 0.6283));		/*五角星内圈点的横坐标存入数组中*/
        points[j++] = (int)(240-50 * sin(0.4 *3.1415926 * i + 0.6283));		/*五角星内圈点的纵坐标存入数组中*/
    }
    setfillstyle(1, RED);										/*设置填充方式*/
    fillpoly(10, points);										/*对五角星进行填充*/
    getch();
    closegraph();											/*退出图形状态*/
}
