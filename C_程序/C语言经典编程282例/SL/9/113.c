#include<stdio.h>
char *replace(char *s1, char *s2, int pos) 						/*自定义替代函数*/
{
	int i, j;
	i = 0;
	for (j = pos; s1[j] != '\0'; j++)								/*从原字符串指定位置开始替代*/
	if (s2[i] != '\0')
	{
		s1[j] = s2[i]; 										/*将替代内容逐个放到原字符串中*/
		i++;
	}
	else
		break;
	return s1; 											/*将替代后的字符按串输出*/
}
main()
{
	char string1[100], string2[100]; 							/*定义两个字符串数组*/
	int position;
	printf("\nPlease input original string:");
	gets(string1); 											/*输入字符串1*/
	printf("\nPlease input substitute string:");
	gets(string2); 											/*输入字符串2*/
	printf("\nPlease input substitute position:");
	scanf("%d", &position); 								/*输入要替换的位置*/
	replace(string1, string2, position); 						/*调用替换函数*/
	printf("\nThe final string:%s\n", string1); 				/*输出最终字符串*/
	return 0;
}
