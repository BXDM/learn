#include <stdio.h>
int main()
 {char a[]="I am a boy.",b[20],*p1,*p2;
  p1=a;p2=b;                                   // p1,p2分别指向a数组和b数组中的第一个元素
  for(;*p1!='\0';p1++,p2++)
     *p2=*p1;                                  // 将p1所指向的元素的值赋给p2所指向的元素
  *p2='\0';                                    // 在复制完全部有效字符后加'\0'
  printf("string a is:%s\n",a);                // 输出a数组中的字符
  printf("string b is:%s\n",b);                // 输出b数组中的字符
  return 0;
}
