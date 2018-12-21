/* ========================================================================== */
/*                                                                            */
/*   average.c                                                               */
/*   (c) 2012 Author                                                          */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */


#include <stdio.h>
int main()
{
   int count=0 ;
   int number=0 ;
   int sum=0;
   
   while (number!=-1){
   scanf("%d",&number);
   sum=sum+number;
   count++  ;
   scanf("%d",&number);
   }
   double dsum=sum;
   printf("the average is %f\n",-1*dsum/count) ;
   
      return 0;
   
   }
