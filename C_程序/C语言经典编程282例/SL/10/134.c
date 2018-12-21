#include <dos.h>
#include <stdio.h>
main()
{
	struct time sett, now; 								/*定义sett,now为time结构体变量*/
	struct time origint; 									/*定义origint为time结构体变量*/
	gettime(&origint); 									/*获取系统当前时间*/
	printf("original time is:%d:%d:%d\n",origint.ti_hour, origint.ti_min,origint.ti_sec);/*输出系统当前时间*/
	sett.ti_hour = 10; 									/*设置系统时间中小时为10*/
	sett.ti_min = 5; 									/*设置系统时间中分为5*/
	sett.ti_sec = 12; 									/*设置系统时间中秒为12*/
	sett.ti_hund = 32;
	settime(&sett); 									/*使用settime()按照指定的数据对系统时间进行设置*/
	gettime(&now);
	printf("time after setting is:%d:%d:%d",now.ti_hour, now.ti_min,now.ti_sec); 	/*输出设置后的系统时间*/
	getch();
}
