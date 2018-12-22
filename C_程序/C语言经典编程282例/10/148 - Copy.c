#include<stdio.h>
#include<time.h>
main() 
{ 
	struct tm * tmpointer;											// tm结构指针
	time_t secs;													//声明time_t类型变量
	time(&secs);													//获取系统日期与时间
	tmpointer=localtime(&secs);										//获取当地日期时间
	//输出本地时间
	printf("\nNow: %d-%d-%d %d:%d:%d\n ",tmpointer->tm_mon,tmpointer->
	tm_mday,tmpointer->tm_year+1900,tmpointer->tm_hour,tmpointer->tm_min,tmpointer->tm_sec);
}
