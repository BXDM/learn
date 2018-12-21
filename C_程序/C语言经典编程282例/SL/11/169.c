#include<stdio.h>
void max_min(int a[], int n, int *max, int *min)
{
	int *p;
	*max =  *min =  *a;									/*初始化最大值最小值指针变量*/
	for (p = a + 1; p < a + n; p++)
	if (*p >  *max)
		*max =  *p;										/*最大值*/
	else if (*p <  *min)
		*min =  *p;										/*最小值*/
	return 0;
}

main()
{
	int i, a[10];
	int max, min;
	printf("Input 10 integer numbers you want to operate:\n ");
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);										/*输入数组元素*/
	max_min(a, 10, &max, &min);								/*返回最大值和最小值*/
	printf("\nThe maximum number is: %d\n", max);				/*输出最大值*/
	printf("The minimum number is: %d\n", min);					/*输出最小值*/
	getch();
}
