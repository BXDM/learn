#include<stdio.h>
float *search(float(*p)[4])
{
	int i;											/*声明变量*/
	float *pt;											/*声明指针变量*/
	pt = *(p + 1);										/*获取下一行的首地址*/
	for(i=0;i<4;i++)
	{
		if(*(*p+i)<60)									/*判断分数是否小于60*/
		{
			pt=*p;									/*指向本行首地址*/
		}
	}
	return (pt);										/*返回首地址*/
}
void main()
{
	float score[][4]={{60,75,82,91},{75,81,91,90},{51,65,78,84},{65,72,78,72}};		/*声明数组*/
	float *p;												/*声明指针变量*/
	int i, j;												/*声明计数变量*/
	for(i=0;i<4;i++)
	{
		p=search(score+i);									/*查找有不及格的行*/
		if (p==*(score+i))
		{
			printf("The student NO.%d list:",i+1);
			for (j=0;j<4;j++,p++)							/*输出成绩*/
			{
				printf("%5.1f",*p);
			}
		}
	}
	getch();
}
