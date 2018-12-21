#include<stdio.h>
main()
{
	int i,sum=0;								/*定义整型变量，并给sum赋值*/
	for(i=1;i<=10;i++)							/*循环10次*/
		sum+=i*i;							/*累加平方和*/
	printf("sum = %d\n",sum);					/*输出累加和*/
}
