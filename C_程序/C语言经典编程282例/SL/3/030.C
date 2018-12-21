#include <stdio.h>

void main()
{
    int i, j, k = 0, l, n, m, sum,flag=1;
    printf("请输入一个数:\n");
    scanf("%d", &n);									/*从键盘中任意输入一个数*/
    m = n * n * n;										/*计算出该数的立方*/
    i = m / 2;
    if (i % 2 == 0)										/*当i为偶数时i值加1*/
        i = i + 1;
    while (flag==1&&i >= 1)								/*当i大于等于1且flag=1时执行循环体语句*/
    {
        sum = 0;
        k = 0;
        while (1)
        {
            sum += (i - 2 * k);								/*奇数累加求和*/
            k++;
            if (sum == m)									/*如果sum与m相等，则输出累加过程*/
            {
                printf("%d*%d*%d=%d=", n, n, n, m);
                for (l = 0; l < k - 1; l++)
                    printf("%d+", i - l * 2);
                printf("%d\n", i - (k - 1) *2);					/*输出累加求和的最后一个数*/
                flag=0;
                break;
            }
            if (sum > m)
                break;
        }
        i -= 2;											/*i等于下一个奇数继续上面过程*/
    }
}
