#include <stdio.h>
int search(int *pt, int n, int key)
{
    int *p;
    for (p = pt; p < pt + n; p++)
        if (*p == key)
            return p - pt;
    return 0;
}

int *find(int *pt, int n, int key)
{
    int *p;
    for (p = pt; p < pt + n; p++)
        if (*p == key)
            return p;
    return 0;
}

int a[] = 
{
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60
};
main()
{
    int i, key;
    int *j;
    printf("The elements of array a:\n");
    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
    printf("\nThe address of a[0] is :%d\n", &a[0]);
    printf("\nPlease input the key number you want to search:");
    scanf("%d", &key);
    i = search(a, sizeof(a) / sizeof(a[0]), key);
    printf("\nThe label number of the key number %d in the array is: %d", key,
        i);
    j = find(a, sizeof(a) / sizeof(a[0]), key);
    printf("\nThe point value of the key number %d in the array is: %d", key, j)
        ;
    getch();

}
