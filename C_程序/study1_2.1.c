//用while计算输入数字的阶乘
//北巷的猫 2018.12.22
#include<stdio.h>
void main()
{
	float fac=1;	//定义最终运算结果为浮点型
	int i = 1,n;
	printf("please inpute a nimber >=0\n");
	scanf("%d",&n);
	if(n == 0 || n == 1){
		printf("factorial is %d\n",1);
		return 0;	//函数到此结束，并返回函数值 0
	}
	while(i <= n){
		fac = fac*i;
		i++;
	}
	printf("factorial is %.2f\n",fac);	//	.2f 表示输出的位数为2为，其中的 . 不能省略
}

/*问题：
		数据类型如何如何解决？
		为了防止溢出，结果定义为浮点型
		循环条件如何给定？
  基本思路：输入的数字并不参加实际运算，仅只是作为循环变量，阶乘运算由自加来解决，从小到大开始乘*/
