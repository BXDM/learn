#include <stdio.h>
main()
{
	int i, j, count;
	puts("the result is:\n");
	printf("time  red ball  white ball  black ball\n");
	count = 1;
	for (i = 0; i <= 3; i++)										/*红球数量范围0到3之间*/
	{
		for (j = 0; j <= 3; j++)									/*白球的数量范围0到3之间*/
		{
			if ((8-i - j) <= 6) 									/*判断要取黑色球的数量是否在6个以内*/
				printf("%3d%8d%9d%10d\n", count++, i, j, 8-i - j); 	/*输出各种颜色球的数量*/
		}
	}
	return 0;
}
