#include <stdio.h>

double f1(int n, int x)											/*自定义函数f1，递归的方法*/
{
	if (n == 0)
		return 1;											/*n为0时返回值为1*/
	else if (n == 1)
		return 2 *x;											/*n为1时返回值为2与x的乘积*/
	else
		return 2 *x * f1(n - 1, x) - 2 *(n - 1) *f1(n - 2, x);				/*当n大于2时递归求值*/
}

double f2(int n, int x)											/*自定义函数f2，栈的方法*/
{
	struct STACK
	{
		int num;											/*num用来存放n值*/
		double data;											/*data存放不同n所对应的不同结果*/
	} stack[100];
	int i, top = 0;											/*变量数据类型为基本整型*/
	double sum1 = 1, sum2;										/*多项式的结果为双精度型*/
	sum2 = 2 * x;											/*当n是1的时候结果是2*/
	for (i = n; i >= 2; i--)
	{
		top++;												/*栈顶指针上移*/
		stack[top].num = i;										/*i进栈*/
	}
	while (top > 0)
	{
		stack[top].data = 2 * x * sum2 - 2 *(stack[top].num - 1) *sum1;		/*求出栈顶元素对应的函数值*/
		sum1 = sum2;										/*sum2赋给sum1*/
		sum2 = stack[top].data;									/*刚算出的函数值赋给sum2*/
		top--;												/*栈顶指针下移*/
	}
	return sum2;												/*最终返回sum2的值*/
}

void main()
{
	int x, n;												/*定义x、n为基本整型*/
	double sum1, sum2;										/*sum1、sum2为双精度型*/
	printf("请输入n:\n");
	scanf("%d", &n); 											/*输入n值*/
	printf("请输入x:\n");
	scanf("%d", &x);											/*输入x的值*/
	sum1 = f1(n, x);											/*调用f1，算出递归求多项式的值*/
	sum2 = f2(n, x);											/*调用f2，算出栈求多项式的值*/
	printf("用递归算法得出的函数值是：%f\n", sum1);			/*将递归方法算出的函数值输出*/
	printf("用栈方法得出的函数值是：%f\n", sum2);				/*将使用栈方法算出的函数值输出*/
}
