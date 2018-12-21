#include <stdio.h>
main()
{
	int a, b, c, t;									/*定义四个基本整型变量a，b，c，t*/
	printf("please input a,b,c:\n");						/*双引号内普通字符原样输出并换行*/
	scanf("%d%d%d", &a, &b, &c);					/*输入任意三个数*/
	if (a > b)										/*如果a大于b，借助中间变量t实现a，b值互换*/
	{
		t = a;
		a = b;
		b = t;
	}
	if (a > c)										/*如果a大于c，借助中间变量t实现a，c值互换*/
	{
		t = a;
		a = c;
		c = t;
	}
	if (b > c)										/*如果b大于c，借助中间变量t实现b，c值互换*/
	{
		t = b;
		b = c;
		c = t;
	}
	printf("the order of the number is:\n");
	printf("%d,%d,%d", a, b, c);						/*输出函数将a,b,c的值顺序输出*/
}
