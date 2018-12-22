#include<stdio.h>
main()
{
	int i=2,n=10;								/*定义变量i，n为基本整型并为i赋初值2*/
	float fac=1;								/*定义fac为单精度型并赋初值1*/
	/*使用scanf函数获取n的值*/
	if(n==0||n==1)								/*当n为0或1的时候输出阶乘为1*/
	{
		printf("factorial is 1.\n");
		return 0;
	}
	while(i<=n)								/*当满足输入的数值大于等于i时执行循环体语句*/
	{
		fac=fac*i;							/*实现求阶乘的过程*/
		i++;									/*变量i自加*/
	}
	printf("factorial of %d is:%.2f.\n",n,fac);		/*输出n和fac最终的值*/
}
