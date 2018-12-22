#include <stdio.h>
int main ( )
 {
  float f,c;                      // 定义f和c为单精度浮点型变量 
  f=64.;                          // 指定f的值 
  c=(5.0/9)*(f-32);               // 利用公式计算c的值  
  printf("f=%f\nc=%f\n",f,c);     // 输出c的值 
  return 0;
 }
