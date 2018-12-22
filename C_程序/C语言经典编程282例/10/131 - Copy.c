#include <time.h>
#include <stdio.h>
#include <dos.h>
main()
{
	time_t start, end; 									/*定义time_t类型变量start，end*/
	start = time(NULL); 								/*将当前时间赋给start*/
	sleep(10); 										/*程序中断10秒钟*/
	end = time(NULL); 								/*将中断后的当前时间赋给end*/
	printf("runtime is:%f(s)\n", difftime(end, start));		/*调用difftime函数，从start到end说经过的时间*/
	getch();
	return 0;
}
