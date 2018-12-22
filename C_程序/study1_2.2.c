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
	while(n > 0){
		fac = fac*n;
		n--;
	}
	printf("factorial is %.2f\n",fac);	//	.2f 表示输出的位数为2为，其中的 . 不能省略
}

/*更改方案：用 n 参加计算，每次是的 n 的值减小 1*/