#include <stdio.h>
int main ( )
{
  char c1,c2;
  c1='A';                         // 将字符'A'的ASCII代码放到c1变量中
  c2=c1+32;	                      // 得到字符'a'的ASCII代码，放在c2变量中 
  printf("%c\n",c2);              // 输出c2的值，是一个字符
  printf("%d\n",c2);              // 输出c2的值，是字符'a'的ASCII代码
  return 0;
}
