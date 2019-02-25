//结构体变量的初始化和定义
#include<stdio.h>
int main()
{
	struct student		//声明结构体类型
	{					
		long int num;	//结构体的成员
		char name[20];
		char sex;
		char addr[20];
	}a = {10101,"Lilin",'M',"123 Beijin road"};	//定义结构体变量 a 并初始化
	printf("NO.:%ld\nname:%s\nsex:%c\naddress:%s\n",a.num,a.name,a.sex,a.addr);
	return 0;
}
