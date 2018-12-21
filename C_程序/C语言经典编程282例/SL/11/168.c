#include "stdio.h"
main()
{
    int a[10];
    int *p, i;
    puts("\nPlease input ten integer:\n");
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    printf("\n");
    for (p = &a; p < (a + 10); p++)
        printf("%d",  *p);
    puts("\n\n Press any key to quit...");
    getch();
    return 0;
}
