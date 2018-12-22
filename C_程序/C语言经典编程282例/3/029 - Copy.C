#include<stdio.h>

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
    int i, j, k, flag1, flag2, n = 0;
    for (i = 6; i < 100; i += 2)
    for (k = 2; k <= i / 2; k++)
    {
        j = i - k;
        flag1 = ss(k);										/*判断拆分出的数是否是素数*/
        if (flag1)
        {
            flag2 = ss(j);
            if (flag2)									/*如果拆分出的两个数均是素数则输出*/
            {
                printf("%3d=%3d+%3d,", i, k, j);
                n++;
                if (n % 5 == 0)
                    printf("\n");
            }
		
        }
    }
	printf("\n");
}
