#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 100
void Init();
void input();
void Delline();
void List();
int Menu();

typedef struct node/*定义存放字符串的结点*/
{
	char data[50];
	struct node *next;
}strnode;

typedef struct head/*定义每行的头结点*/
{
	int number;			/*行号*/
	int length;			/*字符串的长度*/
	strnode *next;
}headnode;

headnode Head[MAX];/*定义有100行*/

void main()
{
	int sel;
	Init();/*初始化*/
	while(1)
	{
		sel= Menu();
		switch (sel)/*输入对应数字进行选择*/
		{
			case 1:input();
				break;
			case 2:Delline();
				break;
			case 3:List();
				break;
			case 4:exit(0);
		}
	}
}

void Init()/*定义初始化函数*/
{
	int i;
	for(i=0;i<MAX;i++)
	{
		Head[i].length=0;
	}
}

int Menu()/*定义菜单*/
{
	int i;
	i=0;
	printf(" 1. Input\n");
	printf(" 2. Delete\n");
	printf(" 3. List\n");
	printf(" 4. Exit\n");
	while(i<=0||i>4)
	{
		printf("please choose\n");
		scanf("%d",&i);
	}
	return i;
}

void input()/*自定义输入字符串函数*/
{
	strnode *p,*find();
	int i,j,LineNum;
	char ch;
	while(1)
	{j=-1;
		printf("input the number of line(0~100),101-exit:\n");
			scanf("%d",&LineNum);/*输入要输入的字符串所在的行号*/
		if(LineNum<0||LineNum>=MAX)
			return;
		printf("please input,#-end\n");
		i=LineNum;
		Head[i].number=LineNum;
		Head[i].next=(strnode *)malloc(sizeof(strnode));/*分配内存空间*/
		p=Head[i].next;
		ch=getchar();
		while(ch!='#')
		{j++;/*计数*/
		if(j>=50)/*如果字符串长度超过50需要再分配一个结点空间*/
		{
			p->next=(strnode *)malloc(sizeof(strnode));
				p=p->next;/*p指向新分配的结点*/
		}
		p->data[j%50]=ch;/*将输入的字符串放入data中*/
		ch=getchar();
		}
		Head[i].length =j+1;/*长度*/
	}
	}


void Delline()/*自定义删除行函数*/
{
	strnode *p,*q;
	int i,LineNum;
	while(1)
	{
	
		printf("input the number of line which do you want to delete(0~100),101-exit:\n");
		scanf("%d",&LineNum);/*输入要删除的行号*/
		if(LineNum<0||LineNum>=MAX)/*如果超出行的范围则返回菜单界面*/
			return;
		i = LineNum;
		p=Head[i].next;
		if(Head[i].length>0)
                	while(p!=NULL)
		{
			q=p->next;
			free(p);/*将p的空间释放*/
			p=q;
		}
		Head[i].length=0;
		Head[i].number=0;
	}
}

void List()
{
	strnode *p;
	int i,j,m,n;
	for(i=0;i<MAX;i++)
	{
		if(Head[i].length>0)
		{
			printf("line %d",Head[i].number);
			n=Head[i].length;
			m=1;
			p=Head[i].next;
			for(j=0;j<n;j++)
				if(j>=50*m)/*以50为准，超过一个则指向下一个结点*/
				{
					p=p->next;
					m++;/*结点个数*/
				}
				else
				printf("%c",p->data[j%50]);/*将结点中内容输出*/
				printf("\n");
		}
	}
	printf("\n");
}
	