#include<stdio.h>
#include<conio.h>
main()
{
    int a[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int *p, (*pt)[4], i, j;
    printf("The array is:");
    for (p = a[0]; p < a[0] + 12; p++)
    {
        if ((p - a[0]) % 4 == 0)
            printf("\n");
        printf("%4d",  *p);
    }
    printf("\n");
    printf("Plesase input the position like: i= ,j= \n ");
    pt = a;
    scanf("i=%d,j=%d", &i, &j);
    printf("a[%d,%d]=%d\n", i, j, *(*(pt + i) + j));
    getch();
}
