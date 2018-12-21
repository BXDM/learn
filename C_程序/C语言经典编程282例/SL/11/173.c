#include <stdio.h>
connect(char *s, char *t, char *q);
int main(void)
{
    char *str,  *t,  *p;
    str = "One world";
    t = " one dream";
    printf("The first string is: %s\n", str);
    printf("The second string is: %s\n", t);
    connect(str, t, p);
    printf("The connected string is:\n");
    printf("%s", p);
    getch();
}

connect(char *s, char *t, char *q)
{
    int i = 0;
    for (;  *s != '\0';)
    {
        *q =  *s;
        s++;
        q++;
    }
    for (;  *t != '\0';)
    {
        *q =  *t;
        t++;
        q++;
    }
    *q = '\0';
}
