#include <dos.h>
#include <stdio.h>
main()
{
	struct date setd,now; 										/*定义setd为date结构体变量*/
	struct date origind; 										/*定义origind为date结构体变量*/
	getdate(&origind); 											/*获取系统当前日期*/
	printf("original data is:%d--%d--%d\n", origind.da_year, origind.da_mon,origind.da_day);	/*输出系统当前日期*/
	setd.da_year = 2008; 										/*设置系统日期中年份为2008*/
	setd.da_mon = 10;											/*设置系统日期中月份为10*/
	setd.da_day = 23;											/*设置系统日期中日为23*/
	setdate(&setd); 								/*使用setdate()按照上面指定的数据对系统时间进行设置*/
	getdate(&now);											/*获取系统重新设置后的当前日期*/
	printf("date after setting is:%d--%d--%d", now.da_year, now.da_mon,now.da_day);	/*输出设置后的系统时间*/
	getch();
}
