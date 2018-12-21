#include <stdio.h>
#include <graphics.h>
#include <time.h>
int main()
{
    int i, gdriver, gmode;
    time_t curtime;
    char s[30];
    gdriver = DETECT;
    time(&curtime);
    initgraph(&gdriver, &gmode, "");						/*图形方式初始化*/
    setbkcolor(BLUE);								/*设置屏幕背景颜色为蓝色*/
    cleardevice();									/*清屏*/
    setviewport(100, 100, 580, 380, 1);						/*设定图形窗口*/
    setfillstyle(1, 2);									/*设置填充类型及颜色*/
    setcolor(15);										/*设置绘图颜色为白色*/
    rectangle(0, 0, 480, 280);							/*画矩形框*/
    floodfill(50, 50, 15);								/*对指定区域进行填充*/
    setcolor(12);										/*设置绘图颜色为淡红色*/
    settextstyle(1, 0, 7);								/*设置输出字符字形、方向及大小*/
    outtextxy(20, 20, "Hello China");						/*在规定位置输出字符串*/
    setcolor(15);										/*设置绘图颜色为白色*/
    settextstyle(3, 0, 6);								/*设置输出字符字形、方向及大小*/
    outtextxy(120, 85, "Hello China");						/*在规定位置输出字符串*/
    setcolor(14);										/*设置绘图颜色为黄色*/
    settextstyle(2, 0, 8);
    sprintf(s, "Now is %s", ctime(&curtime));					/*使用格式化输出函数*/
    outtextxy(20, 150, s);								/*在指定位置将s所对应的函数输出*/
    setcolor(1);										/*设置颜色为蓝色*/
    settextstyle(4, 0, 3);								/*设置输出字符字形、方向及大小*/
    outtextxy(50, 220, s);								/*在规定位置输出字符串*/
    getch();
    exit(0);
}
