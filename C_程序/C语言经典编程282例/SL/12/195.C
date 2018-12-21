#include<stdio.h>

struct 
{
	int num;
	char name[10];
	char tp;
	union									/*共用体类型*/
	{
		int inclass;
		char position[10];
	}job;										/*共用体变量*/
}person[2];									/*结构体变量*/

void main()
{	
	int i;
	printf("请输入个人信息：\n");
	for(i=0;i<2;i++)
	{
		
		printf("第%d个人\n",i+1);
		
		scanf("%d %s %c",&person[i].num,person[i].name,&person[i].tp);		/*输入信息*/
		if(person[i].tp=='s')										/*根据类型值判断是老师还是学生*/
			scanf("%d",&person[i].job.inclass);					/*输入工作类型*/
		else if(person[i].tp=='t')
			scanf("%s",person[i].job.position);
		else
			printf("输入有误");
	}
	printf("\n编号    姓名    类型    班级/职位\n");
	for(i=0;i<2;i++)
	{
		if(person[i].tp=='s')										/*根据工作类型输出结果*/
			printf("%d\t%s\t%c\t%d",person[i].num,person[i].name,person[i].tp,person[i].job.inclass);
		else if(person[i].tp=='t')
			printf("%d\t%s\t%c\t%s",person[i].num,person[i].name,person[i].tp,person[i].job.position);
		printf("\n");			
	}
}
