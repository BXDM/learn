#include <stdio.h>
#include <math.h>
#include <stdlib.h>
main()
{
	int i, j, n = 0;										/*定义变量为基本整型*/
	system("cls");
	printf("10-100之间的素数:\n");
	for (i = 10; i <= 100; i++)
	{
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0) 							/*判断是否能被整除*/
				break; 								/*如果能被整除，就不需要接着判断，跳出循环*/
			else
			{
				if (j > sqrt(i) - 1) 
				{
					printf("%d,", i);
					n++;								/*记录次数*/
					if (n % 5 == 0) 					/*5个一换行*/
						printf("\n");
				}
				else
					continue;
			}
		}
	}
	printf("\n");
}
