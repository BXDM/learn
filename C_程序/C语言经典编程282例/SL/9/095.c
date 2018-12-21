#include<stdio.h>
int main()
{
	int a[3][3];								/*定义一个3行3列的数组*/
	int i,j,sum=0;								/*定义循环控制变量和保存数据变量sum*/
	printf("please input:\n");
	for(i=0;i<3;i++)							/*利用循环进行对数组元素进行赋值*/
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<3;i++)							/*使用循环进行计算对角线的总和*/
	{
		for(j=0;j<3;j++)
		{
			printf("%5d",a[i][j]);
			sum=sum+a[i][j];					/*进行数据的累加计算*/
		}
		printf("\n");
	}
	printf("the result is :%d\n",sum);				/*输出最后的结果*/
	return 0;
}
