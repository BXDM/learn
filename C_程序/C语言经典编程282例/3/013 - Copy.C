#include<stdio.h>

void main()
{
	int i, x, y, z = 1;
	printf("请输入两个数，x和y(x^y):\n");
	scanf("%d%d", &x, &y); 								/*输入底数和幂数*/
	for (i = 1; i <= y; i++)
		z = z * x % 1000;								/*计算一个数任意次方的后三位*/
	if(z>=100)
	{
		printf("%d^%d的最后三位是:%d\n", x, y, z); 			/*输出最终结果*/  
	}
	else 
	{
		printf("%d^%d的最后三位是:0%d\n", x, y, z);			/*输出最终结果*/
	}
}