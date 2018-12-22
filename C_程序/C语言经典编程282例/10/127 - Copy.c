#include <stdio.h>
int hf(int u,int v)
{
	int t,r;										/*声明两个变量*/
	if(v>u)										/*判断两个数大小*/
	{t=u;u=v;v=t;}								/*使u大于v*/
	while((r=u%v)!=0)								/*求最大公约数*/
	{
		u=v;
		v=r;
	}
	return(v);										/*返回最大公约数*/
}
int ld(int u,int v, int h)
{
	return(u*v/h);									/*求最小公倍数*/
}
main()
{
	int u, v, h, l;									/*声明变量*/
	printf("input two integer number:\n");				/*输出字符串*/
	scanf("%d%d",&u,&v);							/*输入两个整数*/
	h=hf(u,v);									/*调用求最大公约数的自定义函数*/
	l=ld(u,v,h);									/*调用求最小公倍数的自定义函数*/
	printf("最大公约数为： %d\n",h);				/*输出最大公约数*/
	printf("最小公倍数为： %d\n",l);				/*输出最小公倍数*/
}
