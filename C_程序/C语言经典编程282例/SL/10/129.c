#include <stdio.h>
#include <math.h>
main()
{
	float i, k; 										/*定义变量i，k为单精度型*/
	printf("please input a number:\n");
	scanf("%f", &i); 									/*输入一个数赋给变量i*/
	printf("the result is:\n");
	printf("%f", ceil(i)); 								/*调用ceil函数，求出不小于i的最小整数*/
	printf("\n");
	return 0;
}
