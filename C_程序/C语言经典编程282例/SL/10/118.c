#include<stdio.h>
int isprime(int num)								/*自定义判断素数的函数*/
{
	int flag=1,i;									/*定义变量*/
	for(i=2;i<=num/2;i++)							/*循环*/
		if(num%i==0)								/*判断是否能整除*/
			flag=0;								/*能整除则不是素数*/
	return(flag);									/*返回判断结果*/
}
main()
{ 
	int n;											/*声明变量*/
	printf("input an integer:");							/*在屏幕上输出提示字符串*/
	scanf("%d",&n);									/*接收一个输入的数*/
	if(isprime(n))										/*调用自定义函数*/
		printf("%d is a prime",n);						/*输出结果*/
	else
		printf("%d is not a prime",n);
	printf("\n");										/*换行*/
}
