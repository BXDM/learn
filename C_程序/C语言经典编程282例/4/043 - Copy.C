#include <stdio.h>

	void main()
	{
		int j, number, n;
		for (number = 1; number < 6; number++)					/*对1到5之间的数进行穷举*/
			for (n = 1; n < 4; n++)								/*对1到3之间的数进行穷举*/
		if ((4 *number + 6 * n == 26) && (number *(number + n)*(number + 2 * n)*
			(number + 3 * n)) == 880)							/*判断是否满足题中条件*/
		{
			printf("结果是:\n");
			for (j = 1; j <= 20; j++)
			{
				printf("%3d", number);
				number += n;
				if (j % 5 == 0)									/*每输出5个进行换行*/
						printf("\n");
			}
		}
	}
