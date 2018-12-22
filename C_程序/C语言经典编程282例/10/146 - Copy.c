#include <stdio.h>
#include <dos.h>
main()
{
	printf("\nThe status of Ctrl+Break %s",(getcbrk())?"On":"Off");			/*检测当前ctrl+break状态并输出*/
	printf("\npress any key to see the status of Ctrl+Break:");
	getch();
	setcbrk(1); 													/*设置ctrl+break状态为on*/
	printf("\nThe status of Ctrl+Break %s",(getcbrk())?"On":"Off");			/*检测当前ctrl+break状态并输出*/
	printf("\npress any key to see the status of Ctrl+Break:");
	getch();
	setcbrk(0);													/*设置ctrl+break状态为off*/
	printf("\nThe status of Ctrl+Break %s\n",(getcbrk())?"On":"Off");		/*检测当前ctrl+break状态并输出*/
}
