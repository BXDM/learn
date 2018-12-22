#include<stdio.h>
#include<string.h>
#define MAX 101

struct aa/*定义结构体aa存储姓名和电话号码*/
{
	char name[15];
	char tel[15];
};

int readin(struct aa *a)/*自定义函数readin，用来存储姓名及电话号码*/
{
	int i=0,n=0;
	while(1)
	{
		scanf("%s",a[i].name);/*输入姓名*/
		if(!strcmp(a[i].name,"#"))
			break;
		scanf("%s",a[i].tel);/*输入电话号码*/
		i++;
		n++;/*记录的条数*/
	}
	return n;/*返回条数*/
}

void search(struct aa *b,char *x,int n)/*自定义函数search，查找姓名所对应的电话号码*/
{
	int i;
	i=0;
	while(1)
	{
		if(!strcmp(b[i].name,x))/*查找与输入姓名相匹配的记录*/
		{
			printf("姓名:%s  电话:%s\n",b[i].name,b[i].tel);/*输出查找到的姓名所对应的电话号码*/
			break;
		}
		else
			i++;
		n--;
		if(n==0)
		{
			printf("没有找到!");/*若没查找到记录输出提示信息*/
			break;
		}
	}
}

void main()
{
	struct aa s[MAX];/*定义结构体数组s*/
	int num;
	char name[15];
	num=readin(s);/*调用函数readin*/
	printf("输入姓名:");
	scanf("%s",name);/*输入要查找的姓名*/
	search(s,name,num);/*调用函数search*/
}