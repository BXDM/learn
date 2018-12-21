#include <stdio.h>
enum week{Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday} ; /*定义枚举结构*/

void main()
{	
	int day;											/*定义整型变量*/
	printf("输入星期数(0-6):");
	scanf("%d",&day);									/*输入0-6的值*/
	switch(day)										/*根据数值进行判断*/
	{
	case Sunday: printf("今天是星期天"); break;			/*根据枚举类型进行判断*/
	case Monday: printf("今天是星期一"); break; 
	case Tuesday: printf("今天是星期二"); break;
	case Wednesday: printf("今天是星期三"); break;
	case Thursday: printf("今天是星期天四"); break;
	case Friday: printf("今天是星期五"); break;
	case Saturday: printf("今天是星期六"); break;	
	}
	printf("\n");
}
