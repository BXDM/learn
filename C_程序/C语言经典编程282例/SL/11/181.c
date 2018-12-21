#include<stdio.h>
#define N 10
void insert(int *a, int n, int x)								/*插入元素的自定义过程*/
{
	int*p, *q;											/*声明指针变量*/
	for(p=a;p<a+n; p++)								/*遍历数组元素*/
	{
		if(*p>x)										/*找到要插入的位置*/
		{
			q=p;										/*记录要插入的位置*/
			break;									/*跳出循环*/
		}
	}
	for(p=a+n;p>=q;p--)								/*将插入位置之后的数据下移*/
		*p=*(p-1);	
	*q=x;											/*插入*/
}
main()
{
	int i, a[N+1],an;									/*声明变量和数组*/
	int *p;											/*声明指针变量*/
	printf("Input 10 seriate integer :\n ");
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);								/*输入数组元素*/
	printf("input inserting data: ");
	scanf("%d", &an);									/*输入要插入的数*/
	insert(a,N,an);										/*进行插入操作*/
	for(p=a;p<a+N+1;p++)
	{
		printf("%3d",*p);								/*输出插入元素后的数组*/
	}
}
