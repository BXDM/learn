#include <stdio.h>
main()
{
	int i, num, k;												/*声明变量*/
	int a[10]={10,11,27,25,34,56,18,37,45,16};					/*初始化一个数组*/
	k=11;													/*为变量赋值*/
	printf("Please input the member which you want to find:\n");
	scanf("%d",&num);										/*输入一个数*/
	for (i=0; i<10; i++)											/*执行循环*/
	{
		if(num==a[i])											/*判断是否和数组元素值相等*/
			k=i;												/*记录下标位置*/
	}
	if(k!=11)													/*根据结果输出*/
		printf("The member you find is in the array \n");
	else
		printf("Have not found the number\n");
}
