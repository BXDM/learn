#include "stdio.h"
*FindMax(int *p, int n)
{
    int i,  *max;
    max = p;
    for (i = 0; i < n; i++)
        if (*(p + i) >  *max)
            max = p + i;
    return max;
}

void main()
{
    int a[10],  *max, i;
    printf("Please input ten integer:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    max = FindMax(a, 10);
    printf("The max number is: %d\n",  *max);
    getch();
}
