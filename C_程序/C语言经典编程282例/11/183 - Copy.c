#include "stdio.h"
void main()
{
    int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    printf("%d,%d\n",a,*a);
    printf("%d,%d\n",a[0],*(a+0));
    printf("%d,%d\n",&a[0],&a[0][0]);
    printf("%d,%d\n",a[1],a+1);
    printf("%d,%d\n",&a[1][0],*(a+1)+0);
    printf("%d,%d\n",a[1][1],*(*(a+1)+1));
    getch();
}
