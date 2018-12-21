#include <stdio.h>
int min(int array[20],int n)
{
	int m,i;
	m = array[0];										/*为变量赋初值*/
	for (i = 1; i < n; i++)								/*找出数组中最小的数*/
	{
		if (array[i] < m)
		{
			m= array[i];								/*将最小数赋给变量*/
		}
	}
	return (m);									/*返回最小数*/
}
main()
{
	int a[20], m, n,i; 									/*定义数组及变量数据类型为基本整型*/
	printf("please input the counts of elements:\n");
	scanf("%d", &n); 									/*输入要输入的元素个数*/
	printf("please input the element:\n");
	for (i = 0; i < n; i++)								/*输入数据*/
	{
		scanf("%d", &a[i]);
	}
	m=min(a,n);										/*调用函数求数组中最小数*/
	printf("the min number is:%3d\n", m);
	return 0;
}
