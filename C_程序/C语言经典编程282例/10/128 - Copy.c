#include <stdio.h>
#include <math.h>
main()
{
	float a, b, c;
	printf("please input two orthogonal sides:\n");
	scanf("%f,%f", &a, &b);									/*从键盘中输入两个直角边*/
	c = hypot(a, b);										/*调用hypot函数，返回斜边值赋给c*/
	printf("hypotenuse is:%f\n", c);							/*将斜边值输出*/
	getch();
}
