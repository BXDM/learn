#include<stdio.h>

void main()
{
   	unsigned a,rs;								/*声明无符号变量*/
    printf("请输入一个八进制数:");
    scanf("%o",&a);    							/*输入一个8进制数*/
    rs=~(~0<<4);								/*构造一个后4位为1的数*/
    printf("\n结果是=0%o\n", a&rs);					/*进行与运算，得到后4位的数据*/
}
