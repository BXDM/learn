//调用函数比较两个数的大小 
//例7.2,p176
#include<stdio.h>
int main()
{
	int max(int x,int y);
	int a,b,c;
	printf("please input two numbers:\n");
	scanf("%d %d",&a,&b);
	c = max(a,b);	//实现实现函数传值 
	printf("max is %d\n",c);
	return 0;
}
int max(int x,int y)
{
	int z;
	z = x>y?x:y;
	return (z);
}
