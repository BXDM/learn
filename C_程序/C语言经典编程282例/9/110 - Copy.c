#include<stdio.h>
#include<string.h>
void insert (char s[],  char t,  int i)					/*自定义函数insert*/
{
	char string[100];								/*定义数组string作为中间变量*/
	if (!strlen(s))
		string[0]=t;								/*若s数组长度为0，则直接将t数组内容复制到s中*/
	else										/*若长度不为空，执行以下语句*/
	{
		strncpy (string,s,i);							/*将s数组中的前i个字符复制到string中*/
		string[i]=t;
		string[i+1]='\0';
		//strcat (string,t) ;							/*将t中字符串连接到string*/
		strcat (string,(s+i));							/*将s中剩余字符串连接到string*/
		strcpy (s,string);							/*将string中字符串复制到s中*/
	}
}
main ()
{
	char str1[100],c;								/*定义str1，str2两个字符型数组*/
	int position;									/*定义变量position为基本整型*/
	printf("please input str1:\n");
	gets(str1);									/*gets函数获得一个字符串*/
	printf("please input a char:\n");
	scanf("%c",&c);								/*scanf函数获得一个字符*/
	printf("please input position:\n");
	scanf("%d",&position);							/*输入字符串插入的位置*/
	insert(str1,c,position);							/*调用insert函数*/
	puts(str1);									/*输出最终得到的字符串*/
}
