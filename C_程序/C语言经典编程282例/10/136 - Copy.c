#include <stdio.h>
#include <string.h>
main()
{
	char str[50];
	printf("please input string:\n");
	gets(str); 										/*输入字符串*/
	strlwr(str);										/*调用strlwr函数，实现大写字母转小写字母*/
	printf(str); 										/*将转换后的结果输出*/
	printf("\n");
}
