#include <stdio.h>

typedef struct student
{
    int num;
    struct student *next;
} LNode,  *LinkList;

LinkList create(void)
{
    LinkList head;
    LNode *p1,  *p2;
    char a;
    head = NULL;
    a = getchar();
    while (a != '\n')
    {
        p1 = (LNode*)malloc(sizeof(LNode));		 /*分配空间*/
        p1->num = a;							 /*数据域赋值*/
        if (head == NULL)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        a = getchar();
    }
    p2->next = NULL;
    return head;
}

LinkList coalition(LinkList L1, LinkList L2)
{
    LNode *temp;
    if (L1 == NULL)
        return L2;
    else
    {
        if (L2 != NULL)
        {
            for (temp = L1; temp->next != NULL; temp = temp->next);
            temp->next = L2; 							/*遍历L1中节点直到尾节点*/
        }
    }
    return L1;
}

void main()
{
    LinkList L1, L2, L3;
    printf("请输入两个链表:\n");
    printf("第一个链表是:\n");
    L1 = create();								/*创建一个链表*/
    printf("第二个链表是:\n");
    L2 = create();								/*创建第二个链表*/
    coalition(L1, L2);								/*连接两个链表*/
    printf("合并后的链表是:\n");
    while (L1)									/*输出合并后的链表*/
    {
        printf("%c", L1->num);
        L1 = L1->next;
    }
    getch();
}
