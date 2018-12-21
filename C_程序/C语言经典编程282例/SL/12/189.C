#include<stdio.h>
#define N 5
struct order/*定义结构体用来存储数据及它的排序*/
{
	int num;
	int con;
}a[20];/*定义结构体数组a*/
void main()
{
	int i,j;
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i].num);/*输入要进行排序的5个数字*/
		a[i].con=0;
	}
	for(i=N-1;i>=1;i--)
		for(j=i-1;j>=0;j--)
			if(a[i].num<a[j].num)/*对数组中的每个元素和其他元素比较*/
				a[j].con++;/*记录排序号*/
			else
				a[i].con++;
			printf("各数的顺序是:\n");
				for(i=0;i<N;i++)
					printf("%3d%3d\n",a[i].num,a[i].con);/*将数据及其排序输出*/
}