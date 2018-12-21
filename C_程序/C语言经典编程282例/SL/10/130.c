#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>
main()
{
	time_t Time; 									/*定义Time为time_t类型*/
	struct tm *t,  *gt; 								/*定义指针t和gt为tm结构类型*/
	Time = time(NULL); 							/*将time函数返回值存到Time中*/
	t = localtime(&Time); 							/*调用localtime函数*/
	printf("Local time is:%s", asctime(t));				/*调用asctime函数，以固定格式输出当前时间*/
	gt = gmtime(&Time); 							/*调用gmtime函数，将当前时间转换为格林威治时间*/
	printf("Greenwich Time is:%s", asctime(gt));		/*调用asctime函数，以固定格式输出格林威治时间*/
	getch();
	return 0;
}
