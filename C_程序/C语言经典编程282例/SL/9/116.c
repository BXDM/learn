#include <stdio.h>
main()
{
	int a[20], max, min, i, j, k, n; 							/*定义数组及变量数据类型为基本整型*/
	printf("please input the nunber of elements:\n");
	scanf("%d", &n); 										/*输入要输入的元素个数*/
	printf("please input the element:\n");
	for (i = 0; i < n; i++)									/*输入数据*/
		scanf("%d", &a[i]);
	min = a[0];
	for (i = 1; i < n; i++)									/*找出数组中最小的数*/
	if (a[i] < min)
	{
		min = a[i];
		j = i; 											/*将最小数所存储的位置赋给j*/
	}
	max = a[0];
	for (i = 1; i < n; i++)									/*找出这组数据中的最大数*/
	if (a[i] > max)
	{
		max = a[i];
		k = i; 											/*将最大数说存储的位置赋给k*/
	}
	a[k] = min; 											/*在最大数位置存放最小数*/
	a[j] = max; 											/*在最小数位置存放最大数*/
	printf("\nthe position of min is:%3d\n", j);				/*输出原数组中最小数所在的位置*/
	printf("the position of max is:%3d\n", k);					/*输出原数组中最大数所在的位置*/
	printf("Now the array is:\n");
	for (i = 0; i < n; i++)
		printf("%5d", a[i]);									/*将还完位置的数组再次输出*/
    printf("\n");
}
