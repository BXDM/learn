#include "stdio.h"
int *find(int *pa, int *pb, int an, int bn)
{
    int *pta,  *ptb;
    pta = pa;
    ptb = pb;
    while (pta < pa + an && ptb < pb + bn)
    {
        if (*pta <  *ptb)
            pta++;
        else if (*pta >  *ptb)
            ptb++;
        else
            return pta;
    }
    return 0;
}

void main()
{
    int *p, i;
    int a[] = 
    {
        1, 3, 5, 7, 9, 11, 13, 15
    };
    int b[] = 
    {
        2, 4, 6, 8, 11, 15, 17
    };
    printf("The elements of array a:\n");
    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\nThe elements of array b:\n");
    for (i = 0; i < sizeof(b) / sizeof(b[0]); i++)
        printf("%d ", b[i]);
    p = find(a, b, sizeof(a) / sizeof(a[0]), sizeof(b) / sizeof(b[0]));
    if (p)
        printf("\nThe first element in both arrays is %d\n ",  *p);
    else
        printf("Doesn't found the same element!\n");
    getch();
}
