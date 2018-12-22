#include <stdio.h>
main()
{
	long a[10]={0},s[10]={0},i,n3,n4,x=18;				/*因为有六位数出现，所以定义为长整形*/
	do
	{
		n3=x*x*x;									/*求出x的三次方*/
		for(i=3;i>=0;i--)
		{
			a[i]=n3%10;								/*取这个三位数的各位数字*/
			n3/=10;
	}
	n4=x*x*x*x;										/*求x的四次方*/
	for(i=9;i>=4;i--)
	{
		a[i]=n4%10;									/*取这个四位数的各位数字*/
		n4/=10;
	}
	for(i=0;i<=9;i++)
		s[a[i]]++;										/*统计数字出现次数*/
	for(i=0;i<=9;i++)
		if(s[i]==1)									/*判断有无重复数字*/
		{
			if(i==9)
			printf("\n the number is %ld\n",x);			/*将结果输出*/
		}
		else break;									/*跳出for循环*/
		x++;
	}
	while(x<22);										/*x的最大值取到21*/
}
