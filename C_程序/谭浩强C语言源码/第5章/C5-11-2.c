#include <stdio.h>
int main()
 {char c;
  while((c=getchar())!='\n')          // 输入一个字符给字符变量c并检查它c的值是否换行符  
    {if((c>='A' && c<='Z') || (c>='a' && c<='z'))     // c如果是字母
       { c=c+4;                       // 只要是字母，都先加4
	     if(c>='Z' && c<='Z'+4 || c>'z')   // 如果是26个字母中最后4个字母之一
		    c=c-26;                   // c的值改变为26个字母中最前面的4个字母中对应的字母        
	   }
     printf("%c",c);                  // 输出己改变的字符
    }
  printf("\n");
  return 0;
}
