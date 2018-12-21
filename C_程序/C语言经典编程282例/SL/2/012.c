#include <stdio.h>
main()
{
	int n=2,day=0;								/*定义n，day为基本整型*/
	float money=0,ave;							/*定义money，ave为单精度型*/
	while(n<100)								/*苹果个数不超过100，故while中表达式n小于100*/
	{
		money+=0.8*n;						/*将每天花的钱数累加求和*/
		day++;								/*天数自加*/
		n*=2;								/*每天买前一天个数的2倍*/
	}
	ave=money/day;							/*求出平均每天花的钱数*/
	printf("The result is %.6f\n",ave);				/*将求出的ave输出*/
}
