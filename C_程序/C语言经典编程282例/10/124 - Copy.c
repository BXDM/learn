#include<stdio.h>
float average(float array[],int n)							/*自定义求平均身高函数*/
{
	int i;
	float aver,sum=0;
	for(i=0;i<n;i++)
	sum+=array[i];									/*用for语句实现sum累加求和*/
	aver=sum/n;										/*总和除以人数求出平均值*/
	return(aver);										/*返回平均值*/
}
int main()
{
	float average(float array[],int n);						/*函数声明*/
	float height[100],aver;
	int i,n;
	printf("请输入学生的数量:\n");
	scanf("%d",&n);									/*输入学生数量*/
	printf("请输入学生们的身高:\n");
	for(i=0;i<n;i++)
	scanf("%f",&height[i]);								/*逐个输入学生的身高*/
	printf("\n");
	aver=average(height,n);								/*调用average函数求出平均身高*/
	printf("学生的平均身高为：%6.2f\n",aver);			/*将平均身高输出*/
	return 0;
}
