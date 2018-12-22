#include <stdio.h>
int main()
 {char c;
  c=getchar();                             // 输入一个字符给字符变量c
  while(c!='\n')                           // 检查c的值是否换行符'\n'  
    {if((c>='a' && c<='z') || (c>='A' && c<='Z'))     // c如果是字母
       { if(c>='W' && c<='Z' || c>='w' && c<='z') c=c-22;   // 如果是26个字母中最后4个字母之一
         else c=c+4;                      // 如果是前面22个字母之一，就使c加4，即变成其后第4个字母
	   }
     printf("%c",c);                      // 输出己改变的字符
     c=getchar();                         // 再输入下一个字符给字符变量c
    }
  printf("\n");
  return 0;
}
