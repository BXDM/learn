#include<stdio.h>

void main()
{
    int a, b, x, y; 								/*定义变量为基本整型*/
    printf("请输入a和b:\n");
    scanf("%d%d", &a, &b); 							/*输入变量a和b的值*/
    x = a * a + b * b; 								/*计算出平方和*/
    if (x > 100)									/*判断平方和是否大于100*/
    {
        printf("a^2+b^2=");
        printf("%d\n", x); 							/*如果平方和大于100，则输出平方和*/
    }
    else
        printf("a+b=%d\n", a + b);					/*如果平方和不大于100，则输出两数之和*/
}
