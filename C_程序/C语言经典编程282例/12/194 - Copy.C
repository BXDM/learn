#include<stdio.h>

union {										/*定义共用体*/
	/*共用体成员*/
	char ch[2];
	int num;
}word;										/*共用体变量*/

void main()
{	
	word.num=0x1234;											/*以十六进制方式为数据成员赋值*/
	printf("十六进制数是: %x\n",word.num);							/*以十六进制输出数据*/
	printf("高字节位数据是: %x\n",word.ch[1]); 							/*以十六进制输出高字节位数据*/
	word.ch[1]='b';												/*修改高字节位数据*/
	printf("现在这个数变为: %x\n",word.num);						/*查看结果*/
}

