#include "stdio.h"
#define N 9
#define OVERFLOW 0
#define OK 1
int KeyW[N]={4,7,5,9,3,2,6,1,8};

typedef struct LNode{
	int keyword;
	struct LNode *next;
}LNode,*LinkList;

void Joseph(LinkList p,int m,int x){
	LinkList q;						/*声明变量*/
	int i;
	if(x==0)return;
	q=p;
	m%=x;
	if(m==0)m=x;
	for(i=1;i<=m;i++){				/*找到下一个结点*/
		p=q;
		q=p->next;
	}
	p->next=q->next;
	i=q->keyword;
	printf("%d ",q->keyword);
	free(q);
	Joseph(p,i,x-1);					/*递归调用*/
}

int main()
{
	int i,m;
	LinkList Lhead,p,q;
	Lhead=(LinkList)malloc(sizeof(LNode));					/*申请结点空间*/
	if(!Lhead) return OVERFLOW;
	Lhead->keyword=KeyW[0];							/*数据域赋值*/
	Lhead->next=NULL;
	p=Lhead;
	for(i=1;i<9;i++){									/*创建循环链表*/
		if(!(q=(LinkList)malloc(sizeof(LNode))))return OVERFLOW;
		q->keyword=KeyW[i];
		p->next=q;
		p=q;
	}
	p->next=Lhead;
	printf("请输入第一次计数值m: \n");
	scanf("%d",&m);
	printf("输出的队列是:\n");
	Joseph(p,m,N);
	getch();
	return OK;
    
}
