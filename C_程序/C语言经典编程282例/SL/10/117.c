#include<stdio.h>

int max(int x,int y)										/*定义一个求最大值的函数*/
{
	int z;											/*声明一个变量*/
	z=x>y?x:y;										/*求两个数中的最大值*/
	return z;											/*函数返回最大值*/
}

int main()
{
	int a, b, c;											/*定义3个变量*/
	printf("input two number:\n");						/*输出提示字符串*/
	scanf("%d%d",&a,&b);								/*接收键盘输入的两个数字*/
	c=max(a,b);										/*调用函数求最大值*/
	printf("max is %d\n",c);								/*输出最大值*/
	return 0;											/*程序结束*/
}
