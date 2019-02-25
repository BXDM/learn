//使用数组逆序排列
#include <stdio.h>
int main()
{
	int a[10];
	int i;
	for(i = 0;i<10;i++)		//利用循环输出数组
	{
		a[i] = i;
	}
	for(i = 9;i>0;i--)		//如果里面的条件改为i<10呢？
		printf(" %d",a[i]);
	printf("\n");
	

	return 0;
}