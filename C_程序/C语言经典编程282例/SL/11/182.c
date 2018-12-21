#include <stdio.h>
#define N 5
*max(int *a, int n)									/*自定义函数返回数组最大值地址*/
{
	int *p, *q;									/*定义指针变量*/
	q=a;											/*获取首地址*/
	for(p=a+1;p<a+n;p++)							/*判断查找最大值*/
	{
		if(*p>*q)
			q=p;									/*将最大值地址保存在q中*/
	}
	return q;										/*返回最大值地址*/
}
swap(int *pa, int *pb)								/*交换两个数值的自定义函数*/
{
	int temp;										/*定义变量*/
	temp=*pa;									/*进行交换*/
	*pa=*pb;
	*pb=temp;
}
main()
{
	int a[N], b[N];									/*定义两个数组*/
	int *pa, *pb, *p;								/*定义指针变量*/
	printf("input array a with 5 element\n");
	for(p=a;p<a+N;p++)							/*输入数组元素*/
	{
		scanf("%d",p);
	}
	printf("input array b with 5 element\n");
	for(p=b;p<b+N;p++)							/*输入数组b的元素*/
	{
		scanf("%d",p);
	}
	pa=max(a,N);									/*获取数组a中的最大值地址*/
	pb=max(b,N);									/*获取数组b中的最大值地址*/
	printf("The max numbers are %d and %d\n",*pa,*pb);
	swap(pa,pb);									/*交换两个元素值*/
	printf("now a: ");
	for(p=a;p<a+N;p++)							/*输出数组*/
	{
		printf ("%3d",*p);
	}
	printf("\nnow b: ");
	for(p=b;p<b+N;p++)							/*输出数组*/
	{
		printf ("%3d",*p);
	}
	printf("\n");
}
