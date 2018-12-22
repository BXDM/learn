#include <string.h>
#include <stdio.h>
main()
{
	int i, j = 1, n;
	float a[100], b[100], sum = 0;
	printf("\nEnter the number of players:\n");
	scanf("%d", &n); 										/*从键盘中输入选手的人数*/
	for (i = 1; i <= n; i++)
	{
		printf("now player %d\n", i);
		printf("please input score:\n");
		for (; j < 5 *n + 1; j++)
		{
			scanf("%f", &a[j]); 							/*输入5个裁判每个裁判所给的分数*/
			sum += a[j]; 									/*求出总份数*/
			if (j % 5 == 0)									/*一位选手有5个裁判给打分*/
			{
				break;
			}
		}
		b[i] = sum; 										/*将每个选手的总分存到数组b中*/
		sum = 0; 										/*将总分重新置0*/
		j++; 											/*j自加*/
	}
	j = 1;
	printf("player     judgeA  judgeB  judgeC  judgeD  judgeE  total\n");
	for (i = 1; i <= n; i++)
	{
		printf("player %d", i); 								/*输出几号选手*/
		for (; j < 5 *n + 1; j++)
		{
			printf("%8.1f", a[j]); 							/*输出裁判给每个选手对应的分数*/
			if (j % 5 == 0)
			{
				break;
			}
		}
		printf("%8.1f\n", b[i]); 								/*输出每个选手所得的总成绩*/
		j++;
	}
	return 0;
}
