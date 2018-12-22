#include<stdio.h>
main()
{
	char c; 										/*定义c为字符型*/
	int letters = 0, space = 0, digit = 0, others = 0;		/*定义letters、space、digit、others、四个变量为基本整型*/
	printf("please input some characters\n");
	while ((c = getchar()) != '\n')						/*当输入的不是回车时执行while循环体部分*/
	{
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
			letters++;								/*当输入的是英文字母时变量letters加1*/
		else if (c == ' ')
			space++;								/*当输入的是空格时变量space加1*/
		else if (c >= '0' && c <= '9')
			digit++;								/*当输入的是数字时变量digit加1*/
		else
			others++;							/*当输入的即不是英文字母又不是空格或数字是变量others加1*/
	}
	printf("char=%d space=%d digit=%d others=%d\n",letters,space,digit,others);		/*将最终统计结果输出*/
}

