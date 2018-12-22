#include <stdio.h>
int main()
 {char a[ ]="I am a student.",b[20];
  int i;
  for(i=0;*(a+i)!='\0';i++)
     *(b+i)=*(a+i);                  //将a[i]的值赋给b[i]
  *(b+i)='\0';                       //在b数组的有效字符之后加'\n'
  printf("string a is:%s\n",a);      //输出a数组中全部字符
  printf("string b is:");
  for(i=0;b[i]!='\0';i++)
    printf("%c",b[i]);               //逐个输出b数组中全部字符
  printf("\n");
  return 0;
 }
