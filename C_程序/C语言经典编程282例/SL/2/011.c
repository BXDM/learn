#include <stdio.h>
main()
{
	int day,x1,x2;								/*定义day，x1，x2三个变量为基本整型*/
	day=9;
	x2=1;
	while(day>0)
	{
		x1=(x2+1)*2;							/*第一天的桃子数是第二天桃子数加1后的2倍*/
		x2=x1;
		day--;								/*因为从后向前推天数递减*/
	}
	printf("the total is %d\n",x1);					/*输出桃子的总数*/
}
