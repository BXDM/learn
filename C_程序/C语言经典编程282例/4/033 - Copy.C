#include <stdio.h>
#include <math.h>

void main()
{
    int i, j, n = 0;								/*定义变量为基本整型*/
    for (i = 100; i <= 200; i++)
        for (j = 2; j <= sqrt(i); j++)
            if (i % j == 0) 						/*判断是否能被整除*/
                break; 								/*如果能被整除，就不需要接着判断，跳出循环*/
            else
    if (j > sqrt(i) - 1) 
    {
        printf("%d,", i);
        n++;										/*记录次数*/
        if (n % 5 == 0) 							/*5个一换行*/
            printf("\n");
    }
    else
        continue;
}
