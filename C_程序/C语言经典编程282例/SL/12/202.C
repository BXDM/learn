#include <stdio.h>
#define N 10

typedef struct node
{
    char name[20];
    struct node *prior,  *next;
} stud; /*双链表的结构定义*/

stud *creat(int n)
{
    stud *p,  *h,  *s;			/*声明双链表结构类型的指针*/
    int i;
    h = (stud*)malloc(sizeof(stud)); 	/*创建头结点*/
    /*初始化头结点*/
    h->name[0] = '\0';
    h->prior = NULL;
    h->next = NULL;
    p = h;						/*p指向头结点*/

    for (i = 0; i < n; i++)
    {
        s = (stud*)malloc(sizeof(stud));		/*申请结点空间*/
        p->next = s;
        printf("Input the %d records:",i);
        scanf("%s", s->name);			/*输入数据*/
        s->prior = p;					/*指定前驱结点*/
        s->next = NULL;				/*指定后继结点*/
        p = s;
    }
    p->next = NULL;
    return (h);						/*返回头结点*/
}

stud *gettp(stud *head)
{
    stud *p,  *r;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;					/*返回尾节点指针*/
}

void main()
{
    int n, i;
    int x;
    stud *q;
    printf("Input the count of the nodes you want to creat:");
    scanf("%d", &n);						/*输入要创建链表的结点数*/
    q = creat(n);							/*创建双链表*/
    q = gettp(q);							/*找到双链表的尾结点*/
    printf("The result: ");
    while (q)
    {
        printf("  %s", &*(q->name));			/*逆序输出*/
        q = q->prior;						/*从尾结点开始向前遍历链表结点*/
    }
    getch();
}

