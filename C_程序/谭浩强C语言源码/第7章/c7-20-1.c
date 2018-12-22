//file1.c
#include <stdio.h>
int main()
{ extern void enter_string(char str[]);
  extern void delete_string(char str[],char ch);
  extern void print_string(char str[]);
    // 以上3行声明在本函数中将要调用的已在其他文件中定义的3个函数
  char c,str[80];
  enter_string(str);                 // 调用在其他文件中定义的enter_string函数
  scanf("%c",&c);
  delete_string(str,c);               // 调用在其他文件中定义的delete_string函数 
  print_string(str);                  // 调用在其他文件中定义的print_string函数     
  return 0;     
}
