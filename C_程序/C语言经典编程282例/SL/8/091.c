#include<stdio.h>
void main()
{
    int day, x1, x2;
    day = 0; 												/*天数*/
    x1 = 1020; 												/*瓜的总数量*/
    while (x1)
    {
        x2 = x1 / 2-2; 										/*卖出一半多两个*/
        x1 = x2;
        day++;												/*天数加1*/
    }
    printf("day=%d\n", day); 									/*将天数加1*/
}
