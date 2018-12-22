#include <graphics.h>
#include <math.h>
#define PI 3.1415926
void main()
{
    double a;
    int x1, x2, j = 1, color = 1;
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");
    cleardevice();
    for (a = 1; a <= 600; a +=1)
    {
        setcolor(color);
        x1 = 220+100 * cos(a / 47.75);
        x2 = 280+100 * sin(a / 47.75 - PI / 2);
        line(a, x1, a + 80, x1);
        line(a, x2, a + 80, x2);
        delay(10000);
        color++;
        if (color > 15)
            color = 1;
    }
    getch();
    closegraph();
} 
