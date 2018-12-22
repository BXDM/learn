#include <stdio.h>
#include <math.h>

void main()
{
    long i, n, n1, n2, n3, n4, count = 0; 				/*定义变量为长整形*/
    printf("这样的数有:\n");
    for (i = 100000; i <= 999999; i++)					/*遍历所有的六位数*/
    {
        n = (long)sqrt(i); 								/*对i值开平方得到一个长整型数值n*/
        if (i == n *n)									/*判断n的平方是否等于i*/
        {
            n1 = i / 1000; 								/*求出高三位数*/
            n2 = i % 1000; 								/*求出低三位数*/
            n3 = (long)sqrt(n1); 						/*对n1值开平方得到一个长整型数值n3*/
            n4 = (long)sqrt(n2); 						/*对n2值开平方得到一个长整型数值n4*/
            if (n1 == n3 *n3 && n2 == n4 *n4)
			/*判断是否同时满足n1等于n3的平方，n2等于n4的平方*/
            {
                count++; 								/*count作为计数器，记录满足条件的个数*/
                printf("%ld,", i);
            } 											/*将最终满足条件的i值输出*/
        }
    }
    printf("\n满足条件的有:%d个", count); 			/*输出满足条件的个数*/
	printf("\n");
}
