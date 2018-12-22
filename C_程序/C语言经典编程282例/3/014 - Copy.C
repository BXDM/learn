#include<stdio.h>

int leap(int a)										/*自定义函数leap用来指定年份是否为闰年*/
{
    if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)				/*闰年判定条件*/
        return 1;									/*是闰年返回1*/
    else
        return 0;									/*不是闰年返回0*/
}

int number(int year, int m, int d) /*自定义函数number计算输入日期为该年第几天*/
{
    int sum = 0, i, a[12] =
    {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };											/*数组a存放平年每月的天数*/
    int b[12] =
    {
        31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };											/*数组b存放闰年每月的天数*/
    if (leap(year) == 1)								/*判断是否为闰年*/
        for (i = 0; i < m - 1; i++)
            sum += b[i];								/*是闰年，累加数组b前m-1个月份天数*/
    else
        for (i = 0; i < m - 1; i++)
            sum += a[i];								/*不是闰年，累加数组a钱m-1个月份天数*/
    sum += d;										/*将前面累加的结果加上日期，求出总天数*/
    return sum;										/*将计算的天数返回*/
}

void main()
{
    int year, month, day, n;								/*定义变量为基本整型*/
    printf("请输入年月日\n");
    scanf("%d%d%d", &year, &month, &day);				/*输入年月日*/
    n = number(year, month, day);							/*调用函数number*/
    printf("第%d天\n", n);
}

