#include<stdio.h>
int main()
{
	int max,min,a,b;
	scanf("%d %d",&a,&b);
	max = (a>b)?a:b;
	min = (a>b)?b:a;
	printf("max is %d,min = %d",max,min);
}
