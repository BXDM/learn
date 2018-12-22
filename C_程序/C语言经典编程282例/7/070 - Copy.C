#include<stdio.h>

int main()
{
		char c;									/*定义变量*/
		printf("请输入一个字符:\n");					/*显示提示信息*/
		scanf("%c",&c);								/*要求输入一个字符*/
		if(c>=65&&c<=90)							/*表达式1的取值范围*/
		{
			printf("输入的字符是大写字母\n");
		}
		else if(c>=97&&c<=122)						/*表达式2的取值范围*/
		{
			printf("输入的字符是小写字母\n");
		}
		else if(c>=48&&c<=57)						/*表达式3的取值范围*/
		{
			printf("输入的是数字\n");
		}
		else										/*输入其他范围*/
		{
			printf("输入的是特殊符号\n");
		}
		return 0;
} 