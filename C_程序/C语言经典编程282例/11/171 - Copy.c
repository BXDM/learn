#include "stdio.h"									/*引用头文件*/
#include "string.h"
#include "conio.h"
sort(char *strings[], int n)
{
	char *temp;									/*声明字符型指针变量*/
	int i, j;										/*声明整型变量*/
	for (i = 0; i < n; i++)							/*外层循环*/
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(strings[i], strings[j]) > 0)		/*比较两个字符*/
			{
				temp = strings[i];					/*交换字符位置*/
				strings[i] = strings[j];
				strings[j] = temp;
			}
		}
	}
}
void main()
{
	int n = 5;
	int i;
	char **p;										/*指向指针的指针变量*/
	char *strings[] =
	{
		"赵XX", "钱XX", "孙XX", "李XX", "周XX"
	};											/*初始化字符串数组*/
	p = strings;									/*指针指向数组首地址*/
	printf("排序前的数组:\n");
	for(i=0;i<n;i++)
	{
		printf("%s\n",strings[i]);
	}
	sort(p, n);										/*调用排序自定义过程*/
	printf("排序后的数组:\n");
	for (i = 0; i < n; i++)							/*循环输出排序后的数组元素*/
	{
		printf("%s\n", strings[i]);
	}
	getch();
}