#include <stdio.h>

void main()
{
    int a, b, c, d, e;
    for (a = 0; a <= 1; a++)								/*对a、b、c、d、e穷举贴黑纸和白纸的所有可能*/
        for (b = 0; b <= 1; b++)
            for (c = 0; c <= 1; c++)
                for (d = 0; d <= 1; d++)
                    for (e = 0; e <= 1; e++)
                        if ((a && b + c + d + e == 3 || !a && b + c + d + e !=
                            3) && (b && a + c + d + e == 0 || !b && a + c + d +
                            e != 0) && (c && a + b + d + e == 1 || !c && a + b
                            + d + e != 1) && (d && a + b + c + e == 4 || !d &&
                            a + b + c + e != 4))							/*根据体列出相应条件*/
						{
							printf("0-黑纸,1-白纸\n");
							printf("a is %d\nb is %d\nc is %d\nd is %d\ne is %d\n", a, b, c, d, e);			/*将最终结果输出*/
						}
}
