#include <stdio.h>
#include<string.h>
main()
{
	char str1[30], str2[30],  *p1,  *p2;
	printf("please input string1:");
	gets(str1); 										/*从键盘中输入字符串1*/
	printf("please input string2:");
	gets(str2); 										/*从键盘中输入字符串2*/
	p1 = strdup(str1); 									/*p1指向存放字符串1的地址*/
	p2 = strdup(str2); 									/*p2指向存放字符串2的地址*/
	printf("string1:%s\nstring2:%s", p1, p2); 			/*利用指针输出字符串*/
	printf("\n");
	return 0;
}
