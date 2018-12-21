#include<conio.h>
main()
{
    void *buf;
    clrscr();											/*清除字符屏幕*/
    gotoxy(35,15);										/*光标定位到（35，15）*/
    textcolor(YELLOW);									/*设置文本颜色为黄色*/
    textbackground(BLUE);									/*设置背景颜色为蓝色*/
    cprintf("hello world\n");									/*输出字符串hello world*/
    cprintf("hello computer\n");								/*输出字符串hello computer*/
    buf=(char *)malloc(2*11*2);								/*buf指向分配的内存空间*/
    gettext(35,15,60,16,buf);								/*保存指定范围内的文本到内存中*/
    puttext(20,5,45,6,buf);									/*将在内存中保存的文本输出*到指定位置*/
    gotoxy(30,10);										/*光标定位到（30，10）*/
    textattr(RED|128|GREEN*16);							/*用textattr设置文本属性*/
    cprintf("Moring");										/*输出字符串Morning*/
  }
