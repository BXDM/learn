#include<stdio.h>
main()
{
	int a[5], i, temp; 									/*定义数组及变量为基本整型*/
	printf("please input array a:\n");
	for (i = 0; i < 5; i++)								/*逐个输入数组元素*/
		scanf("%d", &a[i]);
	printf("array a:\n");
	for (i = 0; i < 5; i++)								/*将数组中的元素逐个输出*/
		printf("%d ", a[i]);
	printf("\n");
	for (i = 0; i < 2; i++)								/*将数组中元素的前后位置互换*/
	{
		temp = a[i]; 									/*元素位置互换的过程借助中间变量temp*/
		a[i] = a[4-i];
		a[4-i] = temp;
	}
	printf("Now array a:\n");
	for (i = 0; i < 5; i++)								/*将转换后的数组再次输出*/
		printf("%d ", a[i]);
}
