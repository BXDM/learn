#include <bios.h>
#include <stdio.h>
main()
{
	long origin, new;
	origin = biostime(0, 0); 									/*调用biostime函数读取时钟的当前值*/
	printf("\nthe current time is %ld \n", origin); 				/*将获取的当前值输出*/
	new = biostime(1, 500); 								/*设置bios的时钟*/
	printf("the new time is %ld", new); 						/*输出设置后的时间*/
}
