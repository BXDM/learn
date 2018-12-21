#include<stdio.h>

void main()
{
    long i, j, k1, k2, k3, a[10] =
    {
        0
    }
    , num, m, n, sum;										/*定义变量及数组为长整形*/
    printf("请输入一个数表示范围:\n");
    scanf("%ld", &num);									/*从键盘中输入要求的范围*/
    printf("结果是:");
    for (j = 0; j < num; j++)									/*对该范围内的数逐个试探*/
    {
        m = j;
        n = 1;
        sum = 0;
        k1 = 10;
        k2 = 1;
        while (m != 0)									/*判断该数的位数*/
        {
            a[n] = j % k1;									/*分离出的数存入数组中*/
            n++;										/*记录位数，实际位数为n-1*/
            k1 *= 10;									/*最小n位数*/
            m = m / 10;
        }
        k1 = k1 / 10;
        k3 = k1;
        for (i = 1; i <= n - 1; i++)
        {
            sum += (a[i] / k2 * a[n - i]) % k1 * k2;					/*求每一部分积之和*/
            k2 *= 10;
            k1 /= 10;
        }
        sum = sum % k3;									/*求和的后n-1位*/
        if (sum == j)
            printf("%5ld", sum);								/*输出找到的自守数*/
    }
	printf("\n");
}
