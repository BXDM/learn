#include<stdio.h>

void main()
{
    int a,b,c,sum;										/*定义变量*/
	float ave;
    printf("请输入三个学生的分数:\n");					/*输出提示信息*/
    scanf("%d%d%d",&a,&b,&c);							/*输入三个学生的成绩*/
    sum=a+b+c;											/*求总成绩*/
	ave=sum/3.0;										/*求平均成绩*/
    printf("总成绩=%4d\t, 平均成绩=%5.2f\n",sum,ave);	/*输出总成绩和平均成绩*/
}