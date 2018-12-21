#include <conio.h>
main()
{
	clrscr();
	highvideo(); 										/*调用函数，字符以高亮度显示*/
	gotoxy(10, 1);
	cprintf("This is high intensity text");
	lowvideo(); 										/*调用函数，字符以低亮度显示*/
	gotoxy(10, 10);
	cprintf("This is low intensity text");
	normvideo(); 										/*调用函数，字符以正常亮度显示*/
	gotoxy(10, 20);
	cprintf("This is normal intensity text");
	getch();
}
