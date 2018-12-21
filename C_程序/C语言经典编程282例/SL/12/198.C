#include "stdio.h"
#include <malloc.h>

struct LNode
{
    int data;
    struct LNode *next;
};

struct LNode *create(int n)
{
    int i;
    struct LNode *head,  *p1,  *p2;
    int a;
    head = NULL;
    printf("输入整数:\n");
    for (i = n; i > 0; --i)
    {
        p1 = (struct LNode*)malloc(sizeof(struct LNode)); 		/*分配空间*/
        scanf("%d", &a);								/*输入数据*/
        p1->data = a;									 /*数据域赋值*/
        if (head == NULL)  							/*指定头结点*/
        {
            head = p1;
            p2 = p1;
        } 
        else
        {
            p2->next = p1; 							/*指定后继指针*/
            p2 = p1;
        }
    }
    p2->next = NULL;
    return head;
}

void main()
{
    int n;
    struct LNode *q;
    printf("输入你想创建的结点个数:");
    scanf("%d", &n);								/*输入链表结点个数*/
    q = create(n);
    printf("结果是:\n");
    while (q)
    {
        printf("%d  ", q->data);						/*输出链表*/
        q = q->next;
    };
	printf("\n");
}
