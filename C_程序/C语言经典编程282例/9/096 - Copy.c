#include<stdio.h>
int main()
{
	int a[2][3];									/*定义数组*/
	int i,j;										/*用于控制循环*/
	for(i=0;i<2;i++)								/*从键盘为数组元素赋值*/
	{
		for(j=0;j<3;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);					/*输出数组元素*/
		}
	}
	printf("输出二维数组\n");						/*信息提示*/
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",a[i][j]);					/*输出结果*/
		}
		printf("\n");								/*使元素分行显示*/
	}
	return 0;
}
