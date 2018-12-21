#include<stdio.h>
main()
{
	long a[10], n, i; 											/*定义数组及变量为基本整型*/
	p: printf("please input a number:\n");
	scanf("%ld", &n); 										/*从键盘中输入一个数n*/
	if (n == 0)												/*如果输入的数为0则重新输入*/
		goto p;
	while (n != 1 && n != 145)
	{
		printf("n=%ld->", n);
		i = 1;
		while (n > 0)
		{
			a[i++] = n % 10; 									/*将n的各位数字存放到数组a中*/
			n /= 10;
		}
		n = 0;
		i--;
		while (i >= 1)											/*使用while语句将运算过程输出*/
		{
			printf("%ld*%ld", a[i], a[i]);
			if (i > 1)
				printf("+");
			n += a[i] *a[i];
			i--;
		}
		printf("=%ld\n", n); 									/*将最终求得的平方和n输出*/
	}
	getch();
}
