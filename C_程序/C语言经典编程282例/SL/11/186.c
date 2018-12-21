#include "stdio.h"
min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

void main()
{
    int(*pmin)();
    int a, b, m;
    pmin = min;
    printf("Please input two integer numbers: \n");
    scanf("%d%d", &a, &b);
    m = (*pmin)(a, b);
    printf("min=%d", m);
    getch();
    printf("\n");
}
