#include <stdio.h>

void main()
{
    int i, j, k, sum1, sum2;										/*定义变量为基本整型*/
    for (i = 1; i <= 10000; i++)									/*对10000以内的数进行穷举*/
    {
        sum1 = 0;
        sum2 = 0;
        for (j = 1; j < i; j++)
            if (i % j == 0) 									/*判断j是否是i的因子*/
                sum1 += j; 									/*求因子的和*/
        for (k = 1; k < sum1; k++)
            if (sum1 % k == 0)									/*判断k是否是sum1的因子*/
                sum2 += k; 									/*求因子和*/
        if (sum2 == i && i != sum1 && i < sum1)
            printf("%5d=>%5d\n", i, sum1); 						/*将亲密数输出*/
    }
}
