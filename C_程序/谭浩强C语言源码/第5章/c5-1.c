#include <stdio.h>
int main()
{
  int i=1,sum=0;                      // 定义变量i的初值为1,sum的初值为0  
  while (i<=100)                      // 当i>100，条件表达式i<=100的值为假，不执行循环体
  {                                   // 循环体开始
   sum=sum+i;                         // 第一次累加后，sum的值为1
   i++;                               // 加完后，i的值加1，为下次累加作准备
  }                                   // 循环体结束
  printf("sum=%d\n",sum);             // 输出1+2+3…+100的累加和
  return 0;
}



