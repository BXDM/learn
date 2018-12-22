#include<stdio.h>
#include<time.h>
main() 
{
	struct tm * gmtp;												//tm结构指针
	time_t secs;													//声明time_t类型变量secs
	time(&secs);													//获取时间
	gmtp=gmtime(&secs);											//获取格林尼治平时
	printf("\nGreenwich time: %d-%d-%d %d:%d:%d\n ",gmtp->tm_mon,	//输出格林尼治平时
	gmtp->tm_mday,gmtp->tm_year+1900,gmtp->tm_hour,gmtp->tm_min,gmtp->tm_sec);
}
