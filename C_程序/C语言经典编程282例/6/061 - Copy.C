#include <stdio.h>
#include <math.h>

void main()
{
    float i; 									/*定义变量i为单精度型*/
    printf("输入一个数:\n");					/*输出一个提示信息*/
    scanf("%f", &i); 							/*输入一个数赋给变量i*/
    printf("得到的结果为:\n");					/*输出提示信息*/
    printf("%f\n", ceil(i)); 					/*调用ceil函数，求出不小于i的最小整数*/
}
