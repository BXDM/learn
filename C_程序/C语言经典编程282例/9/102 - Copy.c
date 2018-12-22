#include<stdio.h>
#define MAX 50												/*定义MAX为常量50*/
main()
{
	int i,num;													/*定义变量i，num为基本整型*/
	int Chinese[MAX],Math[MAX],English[MAX];				/*定义数组为基本整型*/
	long StudentID[MAX];										/*定义StudentID为长整形*/
	float average[MAX];
	printf("please input the number of students");
	scanf("%d",&num);										/*输入学生数*/
	printf("Please input a StudentID and three scores:\n");
	printf("    StudentID  Chinese  Math    English\n");
	for( i=0; i<num; i++ )										/*根据输入的学生数量控制循环次数*/
	{
		printf("No.%d>",i+1);
		scanf("%ld%d%d%d",&StudentID[i],&Chinese[i],&Math[i],&English[i]);
		/*依次输入学号及语文，数学，英语成绩*/
		average[i] = (float)(Chinese[i]+Math[i]+English[i])/3;		/*计算出平均成绩*/
	}
	puts("\nStudentNum    Chinese   Math   English  Average");
	for( i=0; i<num; i++ )										/*for循环将每个学生的成绩信息输出*/
	{
		printf("%8ld %8d %8d %8d %8.2f\n",StudentID[i],Chinese[i],Math[i],English[i],average[i]);
	}
	return 0;
}
