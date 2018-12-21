#define N 20										/*定义常量*/
#include <stdio.h>									/*引用头文件*/
void main()
{
	int i;												/*定义整型变量，循环计数*/
	int score,count=0;									/*定义整型变量，存储分数和最大值*/
	printf(" enter score of course number:\n");			/*提示用户输入分数*/
	for (i=1;i<=N;i++)									/*循环*/
	{
		scanf("%d",&score);							/*接收用户的其他输入*/
		if(score<60)									/*如果分数小于60*/
		{
			count++;
		}
	}
	printf("the count of fail is %d\n ",count);				/*输出不及格的人数*/
	return 0;
}
