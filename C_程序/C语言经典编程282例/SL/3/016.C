#include <stdio.h>

void main()
{
    int cock, hen, chick;										/*定义变量为基本整型*/
    for (cock = 0; cock <= 20; cock++)								/*公鸡范围在0到20之间*/
        for (hen = 0; hen <= 33; hen++)							/*母鸡范围在0到33之间*/
            for (chick = 3; chick <= 99; chick++)						/*小鸡范围在3到99之间*/
                if (5 *cock + 3 * hen + chick / 3 == 100) 				/*判断钱数是否等于100*/
                    if (cock + hen + chick == 100) 				/*判断购买的鸡数是否等于100*/
                        if (chick % 3 == 0) 						/*判断小鸡数是否能被3整除*/
                            printf("公鸡:%d 母鸡:%d 小鸡:%d\n", cock, hen,chick);
}
