#include <stdio.h>
#include<time.h>
main()
{
	time_t now;												//声明time_t类型变量
	time(&now);												//获取当前系统日期与时间
	printf("\nNow is:%s",ctime(&now));							//输出当前系统日期与时间
}
