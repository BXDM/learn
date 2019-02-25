//用指针交换两个数
#include<stdio.h>
int main()
{
	int a,b;
	printf("please input two numbers:\n");
	scanf("%d %d",&a,&b);
	int *point_a,*point_b,*temp;
	point_a = &a;
	point_b = &b;
	temp = point_a;point_a = point_b;point_b = temp;
	printf("a = %d,b = %d\n",*point_a,*point_b);	//指针所指向的数据 
	return 0;
}
