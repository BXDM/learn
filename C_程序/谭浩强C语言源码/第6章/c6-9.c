#include<stdio.h>
#include<string.h>
int main ( )
{
  char str[3][20];                 // 定义二维字符数组
  char string[20];                 // 定义一维字符数组，作为交换字符串时的临时字符数组
  int i;
  for (i=0;i<3;i++)
      gets (str[i]);                 // 读入3个字符串，分别给str[0],str[1],str[2]   
  if (strcmp(str[0],str[1])>0)     // 若str[0]大于str[1]
	  strcpy(string,str[0]);       // 把str[0]的字符串赋给字符数组string
  else                             // 若str[0]小于等于str[1]
	  strcpy(string,str[1]);       // 把str[1]的字符串赋给字符数组string 
  if (strcmp(str[2],string)>0)     // 若str[2]大于string
      strcpy(string,str[2]);       // 把str[2]的字符串赋给字符数组string     
  printf("\nthe largest string is:\n%s\n",string);  // 输出string
  return 0;
}
