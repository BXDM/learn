#include<stdio.h>

void main()
{
    int i, s, k, count =  - 1;
    for (i = 100; i <= 1000; i++)									/*对100~1000之内的数进行穷举*/
    {
        s = 0; 												/*s用来存储各位之和*/
        k = i;
        while (k)
        {
            s = s + k % 10; 									/*求各位之和*/
            k = k / 10; 										/*分离出各位*/
        }
        if (s != 5)											/*判断和是否等于5*/
            continue;										/*结束本次循环继续下次循环*/
        else
        {
            count++; 										/*计数器*/
            if (count % 5 == 0)									/*输出5个数据进行换行*/
                printf("\n");
            printf("%5d", i);
        }
    }
    printf("\n这样的数一共有%d个\n", count + 1); 								/*输出满足条件的数据个数*/
}
