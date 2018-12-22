#include<stdio.h>
#include<conio.h>
int main()
{
	char *Month[]={								/*定义字符串数组*/
			"January",
			"February",
			"March",
			"April",
			"May",
			"June",
			"Junly",
			"August",
			"September",
			"October",
			"November",
			"December"
	};
	int i;
	char **p;										/*声明指向指针的指针变量*/
	p=Month;									/*将数组首地址值赋给指针变量*/
	printf("Input a number for month\n");
	scanf("%d",&i);								/*输入要显示的月份号*/
	printf("The month is:");
	printf("%s\n",*(p+i-1));							/*使用指向指针的指针输出对应的字符串数组中字符串*/
	getch();
	return 0;
}
