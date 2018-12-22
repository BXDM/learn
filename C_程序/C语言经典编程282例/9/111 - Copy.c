#include<stdio.h>
char del(char s[],int pos,int len)					/*自定义删除函数*/
{
	int i;
	for(i=pos+len-1;s[i]!='\0';i++,pos++)				/*i初值为指定删除部分后的第一个字符*/
		s[pos-1]=s[i];								/*用删除部分后的字符依次从删除部分开始覆盖*/
	s[pos-1]='\0';									/*在重新得到的字符后加上字符串结束标志*/
	return s;										/*返回新得到的字符串*/
}
main()
{
	char str[50];									/*定义字符型数组*/
	int position;
	int length;
	printf("\nPlease input string:");
	gets(str);										/*使用gets函数获得字符串*/
	printf("\nPlease input delete position:");
	scanf("%d",&position);							/*输入要删除的位置*/
	printf("\nPlease input delete length:");
	scanf("%d",&length);							/*输入要删除的长度*/
	del(str,position,length);							/*调用删除函数*/
	printf("\nThe final string:%s\n",str);				/*将新得到的字符串输出*/
}
