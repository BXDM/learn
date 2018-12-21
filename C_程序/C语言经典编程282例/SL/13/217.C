#include<stdio.h>

move(unsigned value, int n)									/*自定义移位函数*/
{
    unsigned z;
	if(n>0)
	{
		z = (value >> (32-n)) | (value << n);						/*循环左移的实现过程*/
	}
	else
	{
		n=-n;
		z = (value << (32-n)) | (value >> n);						/*循环右移的实现过程*/
	}
	return z;
}

void main()
{
    unsigned a;
    int n;
    printf("请输入一个八进制数:\n");
    scanf("%o", &a);										/*输入一个八进制数*/
    printf("请输入要移位的位数:\n");
    scanf("%d", &n);									/*输入要移位的位数*/
    printf("移位后的结果是:%o\n", move(a, n));					/*将移位后的结果输出*/
}
