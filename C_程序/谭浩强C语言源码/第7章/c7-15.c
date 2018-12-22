#include <stdio.h>
int a=3,b=5;                     // a,b是全局变量
int main()
{
  int max(int a,int b);           // 函数声明。a,b是形参
  int a=8;                        // a是局局部变量  
  printf("max=%d\n",max(a,b));    // 变量a是函数中定义的局部变量a
  return 0;
} 

int max(int a,int b)               // a,b是函数形参        
{
  int c;
  c=a>b?a:b;                       // 把a和b中的大者存放在c中 
  return(c);
}
