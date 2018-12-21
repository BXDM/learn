#include <stdio.h>
#include <math.h>

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
    int i, n = 0, n1, n2, n3, n4;
    for (i = 1000; i < 10000; i++)
    if (ss(i) == 1)
    {
        n4 = i % 10;										/*取个位数*/
        n3 = (i % 100) / 10; 								/*取十位数*/
        n2 = (i / 100) % 10; 								/*取千位数*/
        n1 = i / 1000;										/*取万位数*/
        if (ss(1000 *n4 + 100 * n3 + 10 * n2 + n1) == 1 && 1000 *n4 + 100 * n3
            + 10 * n2 + n1 > i)								/*根据条件判断*/
        {
            printf("%d,", i);
            n++;										/*记录个数*/
            if (n % 10 == 0)								/*10个一换行*/
                printf("\n");
        }
    }
}
