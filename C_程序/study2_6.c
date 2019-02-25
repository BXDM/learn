//编写一个函数，形参用指针 
#include<stdio.h>
void main()
{
	void swap(int *,int *);
	int a,b;
	printf("please input two numbers:\n");
	scanf("a b",&a,&b);	
	int *p1 = &a,*p2 = &b;
	swap(p1,p2);
	printf("%d,%d\n",a,b);
		
}

void swap(int *p1,int *p2) 
{
	int *t;
	t = p1;p1 = p2;p2 = t;
}
