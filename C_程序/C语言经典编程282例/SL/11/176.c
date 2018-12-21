#include "stdio.h"
float *search(float(*p)[4], int n)
{
    float *pt;
    pt = *(p + n);
    return (pt);

}
void main()
{
    float score[][4]={{60,75,82,91},{75,81,91,90},{51,65,78,84},{65,51,78,72}};
    float *p;
    int i, j;
    printf("enter the student's number you want to search:");
    scanf("%d", &j);
    printf("This student's scores are:\n");
    p = search(score, j);
    for (i = 0; i < 4; i++)
        printf("%5.1f\t", *(p + i));
    getch();
    printf("\n");
}
