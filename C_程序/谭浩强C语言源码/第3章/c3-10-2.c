#include <stdio.h>
int main ( )
{
  char c1,c2;
  c1=getchar();                                        // 从键盘读入一个大写字符，赋给字符变量c1  
  c2=c1+32;	                                           // 得到对应的小写字符的ASCII代码，放在字符变量c2中  	       
  printf("大写字母：%c\n小写字母：%c\n",c1,c2);        // 输出c1,c2的值---大小写字符  
  return 0;
 }






