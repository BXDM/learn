#include <stdio.h>

void main()
{
    int year;											 /*定义基本整型变量year*/
    printf("请输入年份:\n");
    scanf("%d", &year);									 /*从键盘输入表示年份的整数*/
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)		 /*判断闰年条件*/
        printf("%d 是闰年\n", year);						 /*满足条件的输出是闰年*/
    else
        printf("%d 不是闰年\n", year);						 /*否则输出不是闰年*/
}
