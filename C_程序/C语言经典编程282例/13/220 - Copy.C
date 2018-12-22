#include<stdio.h>

void main()
{
    unsigned short  a,z;  
	printf("请输入一个八进制数:\n");
    scanf("%o", &a);								/*输入一个八进制数*/
	z=a & 0100000;									/*0100000的二进制形式为最高位为1，其余为0*/
	if(z==0100000)									/*如果a小于0*/
		z=~a+1;										/*取反加1*/
	else
		z=a;	
    printf("结果是: %o\n", z);						/*将结果输出*/
}
