#include <stdio.h>
#include <math.h>
int main ( )
 {
   double a,b,c,s,area;                       // 定义各变量，均为double型 
   a=3.67;                                    // 对边长a赋值 
   b=5.43;                                    // 对边长b赋值 
   c=6.21;                                    // 对边长c赋值  
   s=(a+b+c)/2;	                              // 计算s 
   area=sqrt(s*(s-a)*(s-b)*(s-c));            // 计算area 
   printf("a=%f\tb=%f\t%f\n",a,b,c);          // 输出三边a,b,c的值 
   printf("area=%f\n",area);                  // 输出面积area的值
   return 0;
 }  

