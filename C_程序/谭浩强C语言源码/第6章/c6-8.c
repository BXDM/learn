#include <stdio.h>
int main()
 {
  char string[81];
  int i,num=0,word=0;
  char c;
  gets(string);                           // 输入一个字符串给字符数组string
  for (i=0;(c=string[i])!='\0';i++)       // 只要字符不是'\0'就继续执行循环
    if(c==' ') word=0;                    // 如果是空格字符，使word置0
    else if(word==0)                      // 如果不是空格字符且word原值为0
		{word=1;                          // 使word置1
	     num++;                           // num累加1，表示增加一个单词
		}
  printf("There are %d words in this line.\n",num);  //输出结果
  return 0;
}