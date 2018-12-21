#include<stdio.h>
int age(int n)											/*自定义函数age*/
{
	int f;
	if(n==1)
	f=10;											/*当n等于1时，f等于10*/
	else
	f=age(n-1)+2;										/*递归调用age函数*/
	return f;											/*将f值返回*/
}
main()
{
	int i,j;											/*定义变量i，j为基本整型*/
	printf("Do you want to know whose age?please input:\n");
	scanf("%d",&i);									/*输入i的值*/
	j=age(i);											/*调用函数age求年龄*/
	printf("the age is %d",j);								/*将求出的年龄输出*/
    printf("\n");
}
