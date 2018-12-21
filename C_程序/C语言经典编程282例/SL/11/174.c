
#include "stdio.h"
void main()
{
    /*void inverte(int *x,int n);*/
    int i, a[10] = 
    {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 0
    };
    printf("The elements of original array:\n");
    for (i = 0; i < 10; i++)
        printf("%d,", a[i]);
    printf("\n");
    inverte(a, 10);
    printf("The elements has been inverted:\n");
    for (i = 0; i < 10; i++)
        printf("%d,", a[i]);
    printf("\n");
    getch();
}

inverte(int *x, int n)
{
    int *p, temp,  *i,  *j, m = (n - 1) / 2;
    i = x;
    j = x + n - 1;
    p = x + m;
    for (; i <= p; i++, j--)
    {
        temp =  *i;
         *i =  *j;
         *j = temp;
    }
    return 0;
}
