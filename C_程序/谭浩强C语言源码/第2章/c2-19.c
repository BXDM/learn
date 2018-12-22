#include <stdio.h>
int main( )
 {
  int sign=1;
  double deno=2.0,sum=1.0,term;    // 定义deno,sum,term为双精度变量 
  while (deno<=100)
  {
   sign=-sign;
   term=sign/deno;
   sum=sum+term;
   deno=deno+1;
  }
  printf("%f\n",sum);
  return 0;
}
