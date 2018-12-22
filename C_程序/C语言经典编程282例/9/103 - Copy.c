#include <stdio.h>
main()
{
	int a[20], max, min, i, j, k, n; 						/*定义数组及变量数据类型为基本整型*/
	j=0; k=0;
	printf("please input the nunber of elements:\n");
	scanf("%d", &n); 									/*输入要输入的元素个数*/
	printf("please input the element:\n");
	for (i = 0; i < n; i++)								/*输入数据*/
		scanf("%d", &a[i]);
	min = a[0];
	for (i = 1; i < n; i++)								/*找出数组中最小的数*/
		if (a[i] < min)
		{
			min = a[i];
			j = i; 									/*将最小数所存储的位置赋给j*/
		}
	max = a[0];
	for (i = 1; i < n; i++)								/*找出这组数据中的最大数*/
		if (a[i] > max)
		{
			max = a[i];
			k = i; 									/*将最大数说存储的位置赋给k*/
		}
	printf("\nthe position of min is:%3d\n", j);			/*输出原数组中最小数所在的位置*/
	printf("the min number is:%3d\n", min);
	printf("the position of max is:%3d\n", k);				/*输出原数组中最大数所在的位置*/
	printf("the max number is:%3d\n", max);
	return 0;
}
