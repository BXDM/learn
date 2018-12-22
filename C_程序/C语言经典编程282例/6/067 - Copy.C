#include <stdio.h>

int ss(int i)												/*自定义函数判断是否为素数*/
{
    int j;
    if (i <= 1) 											/*小于1的数不是素数*/
        return 0;
    if (i == 2) 											/*2是素数*/
        return 1;
    for (j = 2; j < i; j++)									/*对大于2的数进行判断*/
    {
        if (i % j == 0)
            return 0;
        else if (i != j + 1)
            continue;
        else
            return 1;
    }
}

void main()
{
    int i;
    for (i = 10; i < 1000; i++)
        if (ss(i) == 1)										/*判断是否是素数*/
    if (i / 100 == 0) 										/*判断是否是两位数*/
    {
        if (i / 10 == i % 10) 								/*判断十位和各位是否相同*/
                printf("%5d", i);
	}
    else
        if (i / 100 == i % 10) 								/*判断百位和个位是否相同*/
            printf("%5d", i);
}
