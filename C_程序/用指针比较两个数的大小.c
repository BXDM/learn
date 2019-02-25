// 引用指针变量
//p225，例8.2
#include<stdio.h>
int main()
{
	int *p1,*p2,*p,a,b;
	printf("please input two numbers:\n");
	scanf("%d%d",&a,&b);
	p1 = &a;
	p2 = &b;
	if(a<b)
		{p = p1;p1 = p2;p2 =p;}
	printf("max = %d,min = %d\n",a,b);
	return 0;
}
