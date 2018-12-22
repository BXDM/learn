#include<stdio.h>
#include<stdlib.h>
#define ElemType int

typedef struct node /*定义结点*/
{
	ElemType data;/*存放元素内容*/
	struct node *next;/*指向下个结点*/
}quenode;

struct quefr/*定义结点存放队首队尾指针*/
{
	quenode *front,*rear;
};


void creat(struct quefr *q)/*自定义函数初始化链队列*/
{
	quenode *h;
	h=(quenode *)malloc(sizeof(quenode));
	h->next=NULL;
	q->front=h;/*队首指针队尾指针均指向头结点*/
	q->rear=h;
}

void enqueue(struct quefr *q,int x)/*自定义函数，元素x入队*/
{
	quenode *s;
	s=(quenode *)malloc(sizeof(quenode));
	s->data=x;/*x放到结点的数据域中*/
	s->next=NULL;/*next域为空*/
	q->rear->next=s;
	q->rear=s;/*队尾指向s结点*/
}

ElemType dequeue(struct quefr *q)/*自定义函数实现元素出队*/
{
		quenode *p;
			ElemType x;
	p=(quenode *)malloc(sizeof(quenode));

	if(q->front==q->rear)
	{
		printf("queue is NULL \n");
		x=0;
	}
	else
	{
		p=q->front->next;
		q->front->next=p->next;/*指向出队元素所在结点的后一个结点*/
		if(p->next==NULL)
			q->rear=q->front;
		x=p->data;
		free(p);/*释放p结点*/
	}
	return(x);
}

void display(struct quefr dq)/*自定义函数显示队列中元素*/
{
	quenode *p;
	p=(quenode *)malloc(sizeof(quenode));
	p=dq.front->next;      /*指向第一个数据元素节点 */
	while(p!=NULL)
	{
		printf("data=%d\n",p->data);
		p=p->next;/*指向下个结点*/
	}
	printf("结束---------------\n");
}

void main()
{
	struct quefr *que;
	int n,i,x,sel;
	void display();/*显示队列中元素*/
	void creat();/*创建队列*/
	void enqueue();/*元素入队列*/
	ElemType dequeue();/*元素出队列*/
	do
	{
		printf("\n");
		
		printf("      1    创建队列   \n");
		printf("      2    向队列中插入元素  \n");
		printf("      3    从队列中删除元素  \n");
		printf("      4    显示队列中元素  \n");
		printf("      5    退出  \n");
		printf("-------------------------------\n");
		printf("请选择(1, 2, 3, 4，5) ");
		scanf("%d",&sel);/*输入相关功能所对应的标号*/
		switch(sel)
		{
		case 1:
			que=(struct quefr *)malloc(sizeof(struct quefr));/*分配内存空间*/
			creat(que);/*初始化队列*/
			printf("请选择你想创建元素的个数:");
			scanf("%d",&n);/*输入队列元素个数*/
			for(i=1;i<=n;i++)
			{
				scanf("%d",&x);/*输入元素*/
				enqueue(que,x);
			}
			break;
		case 2:
			printf("请输入你想要插入的元素:");
			scanf("%d",&x);/*输入元素*/
			enqueue(que,x);/*元素入队*/
			break;
		case 3:
			printf("x=%d\n",dequeue(que));/*元素出队*/
			break;
		case 4:
			display(*que);/*显示队列中元素*/
			break;
		case 5:
			exit(0);
		}
	}while (sel<=4);
}







