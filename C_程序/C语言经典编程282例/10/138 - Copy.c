#include <string.h>
#include <stdio.h>
main()
{
	char str1[30], str2[30], str3[30], str4[30],  *p;
	int pos;
	printf("please input string1:");
	gets(str1); 											/*从键盘中输入字符串1*/
	printf("please input string2:");
	gets(str2); 											/*从键盘中输入字符串2*/
	pos = strspn(str1, str2); 									/*调用函数strspn找出不同的位置*/
	printf("the position you want to find is:%d\n", pos);
	printf("please input string3:");
	gets(str3); 											/*从键盘中输入字符串3*/
	printf("please input string4:");
	gets(str4); 											/*从键盘中输入字符串4*/
	p = strstr(str3, str4); 									/*调用函数strstr查看str3中是否包含str4*/
	if (p)
	{
		printf("str3 include str4\n");
	}
	else
	{
		printf("can not find str4 in str3!");
	}
	printf("\n");
	return 0;
}
