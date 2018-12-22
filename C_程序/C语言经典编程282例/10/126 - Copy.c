#include <stdio.h>
int fac(int num)
{
	static int result=1;								/*定义局部静态变量*/
	result=result*num;								/*进行计算*/
	return(result);									/*返回结果*/
}
main()
{ 
	int i, n;										/*声明变量*/
	for(i=1;i<=5;i++)								/*循环得到1到5的阶乘值*/
	{
		n=fac(i);									/*调用自定义函数求阶乘*/
		printf("%d!=%d\n",i,n);						/*输出结果*/
	}
	return 0;
}
