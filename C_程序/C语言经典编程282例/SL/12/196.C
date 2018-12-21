#include<stdio.h>

union {										/*定义共用体*/
	int i;									/*共用体成员*/									
	char c;
	float f;
	double d;
}temp;										/*声明共用体类型的变量*/

void main()
{
	char TypeFlag;
	printf("输入成员类型:\n");
	scanf("%c",&TypeFlag);								/*输入类型符*/							
	printf("输入数字:\n");
	switch(TypeFlag)									/*多分支选择语句判断输入*/
	{
	case 'i':scanf("%d",&temp.i);break;
	case 'c':scanf("%c",&temp.c);;break;
	case 'f':scanf("%f",&temp.f);break;
	case 'd':scanf("%lf",&temp.d);
	}
	switch(TypeFlag) 									/*多分支选择语句判断输出*/
	{
	case 'i':printf("%d",temp.i);break;
	case 'c':printf("%c",temp.c);break;
	case 'f':printf("%f",temp.f);break;
	case 'd':printf("%lf",temp.d);
	}							
	printf("\n");
}
