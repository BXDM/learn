#include<stdio.h>
main()
{
	int len;										/*定义len为基本整型变量*/
	char *str[100];									/*定义字符型指针数组str*/
	printf("please input a string:\n");
	gets(str);										/*gets函数将输入的字符串放入数组str中*/
	len=length(str);								/*调用length函数*/
	printf("the string has %d characters.",len);		/*将结果输出*/
}
int length(char *p)									/*自定义函数length*/
{
	int n=0;										/*定义变量n为基本整型*/
	while(*p!='\0')									/*当指针未指到字符串结束标志时执行循环体语句*/
	{
		n++;										/*长度加1*/
		p++;										/*指针向后移*/
	}
	return n;										/*返回最终长度*/
}
