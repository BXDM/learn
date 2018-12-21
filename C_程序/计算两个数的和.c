//计算两个数的和 

#include<stdio.h> 
int main ()
{
	int a,b;
	int sum;
	
	printf("请输入两个数字：\n");
	scanf("%d %d",&a,&b);   //%d和%d之间不能用“，”分隔，可以用空格或者不用，后面不能加"|n" 
 
	sum=a+b;
	printf("%d+%d=%d",a,b,sum);
	
	return 0;
}
