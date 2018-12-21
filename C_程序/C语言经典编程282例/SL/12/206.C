#include <stdio.h>

struct student
{
    int num;
    struct student *next;
};

struct student *create(int n)
{
    int i;
    struct student *head,  *p1,  *p2;
    int a;
    head = NULL;
    printf("链表元素:\n");
    for (i = n; i > 0; --i)
    {
        p1 = (struct student*)malloc(sizeof(struct student)); 			/*分配空间*/

        scanf("%d", &a);
        p1->num = a;											 /*数据域赋值*/
        if (head == NULL)
        {
            head = p1;
            p2 = p1;
        } 
        else
        {
            p2->next = p1; 									/*指定后继指针*/
            p2 = p1;
        }
    }
    p2->next = NULL;
    return head;												/*返回头结点指针*/
}

struct student *reverse(struct student *head)
{
    struct student *p,  *r;
    if (head->next && head->next->next)
    {
        p = head;						/*获取头结点地址*/
        r = p->next;
        p->next = NULL;
        while (r)
        {
            p = r;
            r = r->next;
            p->next = head;
            head = p;
        } return head;
    }
    return head;								/*返回头结点*/
}

void main()
{
    int n, i;
    int x;
    struct student *q;
    printf("输入你想创建的结点个数:");
    scanf("%d", &n);
    q = create(n);						/*创建单链表*/
    q = reverse(q);						/*单链表逆置*/
    printf("逆置后的单链表是:\n");
    while (q)							/*输出逆置后的单链表*/
    {
        printf("%d ", q->num);
        q = q->next;
    } getch();
}
