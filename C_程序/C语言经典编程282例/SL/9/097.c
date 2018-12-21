#include<stdio.h>
int main()
{
	char cString[100];									/*定义保存字符串的数组*/
	int iIndex, iWord=1;								/*iWord表示单词的个数*/
	char cBlank;										/*表示空格*/
	gets(cString);										/*输入字符串*/
	if(cString[0]=='\0')									/*判断如果字符串为空的情况*/
	{
		printf("There is no char!\n");
	}
	else if(cString[0]==' ')								/*判断第一个字符为空格的情况*/
	{
		printf("First char just is a blank!\n");
	}
	else
	{
		for(iIndex=0;cString[iIndex]!='\0';iIndex++)		/*循环判断每一个字符*/
		{
			cBlank=cString[iIndex];						/*得到数组中的字符元素*/
			if(cBlank==' ')								/*判断是不是空格*/
			{
				iWord++;								/*如果是则加1*/
			}
		}
		printf("%d\n",iWord);
	}
}
