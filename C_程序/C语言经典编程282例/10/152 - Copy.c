#include<stdio.h> 
#include<dos.h>
main() 
{ 
   long ticks;
   char *str;
   ticks =biostime(0,ticks);
   printf("\n Ticks since midnight %ld \n ", ticks);
   getch();
   printf("\n Please input the numbers of ticks \n ");
   gets(str);
   ticks =biostime(1,atol(str));
   printf("\n Ticks since midnight %ld \n", ticks);
}
