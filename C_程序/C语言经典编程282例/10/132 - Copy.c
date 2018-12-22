#include <dos.h>
#include <stdio.h>
main()
{
	struct date d; 														/*定义date结构体类型变量d*/
	struct time t; 														/*定义time结构体类型变量t*/
	getdate(&d); 														/*获取系统当前日期*/
	gettime(&t); 														/*获取系统当前时间*/
	printf("the current day is:%d--%d--%d\n",d.da_year, d.da_mon, d.da_day);		/*按指定格式输出当前日期*/
	printf("the current time is:%d:%d:%d", t.ti_hour, t.ti_min, t.ti_sec);			/*按指定格式输出当前时间*/
	getch();
}
