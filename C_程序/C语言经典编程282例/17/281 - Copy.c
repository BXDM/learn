#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
void main()
{
    int gdriver, gmode;
    unsigned size;
    void *buf;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");								/*图形界面初始化*/
    setcolor(15);												/*设置绘图颜色为白色*/
    rectangle(20, 20, 200, 200);									/*画正方形*/
    setcolor(RED);											/*设置绘图颜色为红色*/
    line(20, 20, 200, 200);										/*画对角线*/
    setcolor(GREEN);											/*设置绘图颜色为绿色*/
    line(20, 200, 200, 20);
    outtext("press any key,you can see the same image!!");
    getch();
    size = imagesize(20, 20, 200, 200);								/*返回这个图像存储所需字节数*/
    if (size !=  - 1)
    {
        buf = malloc(size);										/*buf指向在内存中分配的空间*/
        if (buf)
        {
            getimage(20, 20, 200, 200, buf);							/*保存图像到buf指向的内存空间*/
            putimage(100, 100, buf, COPY_PUT);						/*将保存的图像输出到指定位置*/
            putimage(300, 50, buf, COPY_PUT);
            putimage(400, 150, buf, COPY_PUT);
        }
    }
    getch();
    closegraph();											/*退出图形状态*/
}
