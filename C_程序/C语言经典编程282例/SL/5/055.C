#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int a, b, c, sign, max;								 /*定义基本整型变量*/
    char sign1;										 /*定义字符型变量*/
    printf("请选择运算符(1 or other,1:-,other:+):\n");
    scanf("%d", &sign);							 /*输入函数，输入数据赋给sign*/
    printf("请选择最大的数(<10000):\n");
    scanf("%d", &max);								 /*输入函数，输入数据赋给max*/
    srand((unsigned long)time(0));							 /*系统时钟设定种子*/
    a = rand() % max;									 /*产生小于max的随即数并赋给a*/
    b = rand() % max;									 /*产生小于max的随即数并赋给b*/
    while ((a < b) && (sign == 1))							 /*选择减法操作时如果a小于b则重新产生随即数*/
    {
        a = rand() % max;
        b = rand() % max;
    }
    sign1 = (sign == 1 ? '-' : '+');							 /*将选择的符号赋给sign1*/
    printf("\n%d%c%d=", a, sign1, b);
    scanf("%d", &c);									 /*输入运算结果*/
    if ((sign == 1) && (a - b == c) || (sign != 1) && (a + b == c))	 /*判断运算结果是否等于正确答案*/
        printf("计算正确!\n");								 /*等于正确答案输出ok*/
    else
        printf("计算错误!\n");					 /*不等于正确答案输出错误*/
}
