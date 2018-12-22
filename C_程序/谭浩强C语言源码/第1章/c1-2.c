#include <stdio.h>                      // 这是编译预处理命令 
int main( )                             // 定义主函数
{                                       // 函数开始 
  int a,b,sum;                          // 本行是程序的声明部分，定义a、b、sum为整型变量
  a = 123;                              // 对变量a赋值    
  b = 456;                              // 对变量b赋值 
  sum = a + b;                          // 进行a+b 的运算，并把结果存放在变量sum中
  printf("sum is %d\n",sum);            // 输出结果 
  return 0;                             // 使函数返回值为0
}                                       // 函数结束 

  

