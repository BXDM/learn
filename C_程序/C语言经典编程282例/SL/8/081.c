#include<stdio.h>
main()
{
	int i, j; 								/*定义i，j两个变量为基本整型*/
	for (i = 1; i <= 9; i++)					/*for循环i为乘法口诀表中的行数*/
	{
		for (j = 1; j <= i; j++)				/*乘法口诀表中的另一个因子，取值范围受一个因子i的影响*/
		printf("%d*%d=%d ", i, j, i *j);		/*输出i，j及i*j的值*/
		printf("\n"); 						/*打完每行值后换行*/
	}
}
