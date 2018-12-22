#include<stdio.h>
int sub(int n) 											/*定义函数递归求鱼的总数*/
{
	if (n == 1)										/*当n等于1时递归结束*/
	{
		static int i = 0;
		do
		{
			i++;
		}
		while (i % 5 != 0);
		return (i + 1);									/*5人平分后多出一条*/
	}
	else
	{
		int t;
		do
		{
			t = sub(n - 1);
		}
		while (t % 4 != 0);
		return (t / 4 * 5+1);
	}
}
main() 
{ 
	int total; 
	total=sub(5); 										/*调用递归函数*/
	printf("the total number of fish is %d\n",total); 
	return 0;
}
