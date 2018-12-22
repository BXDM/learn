#include <stdio.h>
int main()
{ int age(int n);
  printf("NO.5,age:%d\n",age(5));  //输出第5人的年龄
  return 0;
} 

int age(int n)                     //定义递归函数    
 {int c;                
  if(n==1)                         // 如果n等于1
    c=10;                          // 年龄为10
  else                             // 如果n不等于1     
    c=age(n-1)+2;                  // 年龄是前一人的年龄加2(如第4人年龄是第3人年龄加2)
  return(c);                       // 返回年龄
}

