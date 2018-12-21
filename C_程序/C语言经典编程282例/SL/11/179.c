#include <stdio.h>
void order(int *p,int n)
{
	int i,t,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(*(p+j)>*(p+j+1)) 							/*判断相邻两个元素的大小*/
			{
				t=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=t; 								/*借助中间变量t进行值互换*/
			}
	printf("排序后的数组:");
	for(i=0;i<n;i++)
	{
		if(i%5==0) 										/*以每行5个元素的形式输出*/
			printf("\n");
		printf("%5d",*(p+i)); 								/*输出数组中排序后的元素*/
	}
	printf("\n");
}
main()
{
	int a[20],i,n;
	printf("请输入数组元素的个数:\n");
	scanf("%d",&n); 										/*输入数组元素的个数*/
	printf("请输入各个元素:\n");
	for(i=0;i<n;i++)
		scanf("%d",a+i); 									/*给数组元素赋初值*/
	order(a,n); 											/*调用order函数*/
}
