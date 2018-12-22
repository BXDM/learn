#include <stdio.h>
void main()
{
	int i;												/*定义整型变量*/
	float total=0;										/*定义实型变量，并初始化*/
	for(i=0;i<5;i++)									/*循环*/
		total=(total+1000)/(1+0.025);						/*累计存款额*/
	printf("must save %5.2f at first. \n",total); 			/*输出存款额*/
}
