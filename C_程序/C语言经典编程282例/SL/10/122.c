#include <stdio.h>
#include <math.h>
main()
{
	float x, n;
	int i;
	printf("please input the base:\n");
	scanf("%f", &x); 											/*输入底数x*/
	printf("please input the power:\n");
	scanf("%f", &n); 											/*输入次幂数*/
	for (i = 1; i <= 5; i++)
	{
		printf("%.1f^%.1f is %.3f\n", x, n, pow(x, n));				/*将求出的结果输出*/
		n += 1;
	}
	getch();
}
