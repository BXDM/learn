#include <stdio.h>
int main()
{void copy_string(char *from, char *to);
 char *a="I am a teacher.";
 char b[]="You are a student.";
 char *p=b;                                             // 使指针变量p指向b数组首元素
 printf("string a=%s\nstring b=%s\n",a,b);              // 输出a串和b串
 printf("\ncopy string a to string b:\n");
 copy_string(a,p);                                      // 调用copy_string函数，实现复制
 printf("string a=%s\nstring b=%s\n",a,b);  
 return 0;
}

void copy_string(char *from, char *to)                  // 定义函数，形参为字符指针变量
{  for(;*from!='\0';from++,to++)
      {*to=*from;}
   *to='\0';
}        
