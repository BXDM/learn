#include<stdio.h>
main()
{
	int a[10], b[10], i;									/*定义数组及变量为基本整型*/
	printf("please input array a:\n");
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);								/*输入10个元素到数组a中*/
	for (i = 1; i < 10; i++)
		b[i] = a[i] + a[i - 1];								/*将数组a中相邻两个元素求和放到数组b中*/
	for (i = 1; i < 10; i++)
	{
		printf("%5d", b[i]); 							/*将数组b中元素输出*/
		if (i % 3 == 0)
			printf("\n");								/*每输出3个元素进行换行*/
	}
	return 0;
}
