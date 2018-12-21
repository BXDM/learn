#include <stdio.h>
main()
{
	int i, j, sum;									//定义整型变量
	int a[4][4]={									//定义整型数组，并对其初始化
				{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12},
				{13,14,15,16}
			};
	sum=0;										//为整型变量赋初值
	printf("The array is:\n");							//输出提示信息
	for(i=0;i<4;i++)								//循环嵌套输出对角线之和
	{
		for(j=0;j<4;j++)
		{
			printf("%5d",a[i][j]);
			if(i==j)
				sum=sum+a[i][j];
		}
		printf("\n");
	}
	printf("The sum of the diagonal is %d\n",sum);
	return 0;
}
