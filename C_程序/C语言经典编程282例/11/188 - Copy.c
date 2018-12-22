#include "stdio.h"
#include <string.h>
#include "conio.h"
int match(char *B, char *A)
{
    int i, j, start = 0;
    int lastB = strlen(B) - 1;
    int lastA = strlen(A) - 1;
    int endmatch = lastA;
    for (j = 0; endmatch <= lastB; endmatch++, start++)
    {
        if (B[endmatch] == A[lastA])
            for (j = 0, i = start; j < lastA && B[i] == A[j];)
                i++, j++;
        if (j == lastA)
        {
            return (start + 1); /*³É¹¦  */
        }

    }
    if (endmatch > lastB)
    {
        printf("The string is not matchable!");
        return  - 1;
    }
}

void main()
{
    char s[] = "One world,one dream";
    char t[] = "world";
    int p = match(s, t);
    if (p !=  - 1)
    {
        printf("Matchable!\n");
        printf("The start position is %d", p);
    }
    printf("\n");
    getch();
}
