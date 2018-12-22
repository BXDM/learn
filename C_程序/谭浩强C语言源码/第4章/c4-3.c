#include <stdio.h>
int main()
{
   float a,b,c,t;
   scanf("%f,%f,%f",&a,&b,&c);
   if(a>b)
   {
     t=a;
     a=b;
     b=t;
   }                            // 实现a和b的互换 
   if(a>c)
   {
     t=a;
     a=c;
     c=t;
   }                           // 实现a和c的互换 
   if(b>c)
   {
     t=b;
     b=c;
     c=t;
   }                           // 实现b和c的互换 
   printf("%5.2f,%5.2f,%5.2f\n",a,b,c);
   return 0;
}




