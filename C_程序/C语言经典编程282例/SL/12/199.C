#include <stdio.h>

typedef struct node
{
    char name[20];
    struct node *prior,  *next;
} stud; 						/*双链表的结构定义*/

stud *creat(int n)
{
    stud *p,  *h,  *s;
    int i;
    h = (stud*)malloc(sizeof(stud));			/*申请结点空间*/
    h->name[0] = '\0';
    h->prior = NULL;
    h->next = NULL;
    p = h;
    for (i = 0; i < n; i++)
    {
        s = (stud*)malloc(sizeof(stud));
        p->next = s;						/*指定后继结点*/
        printf("输入第%d个学生的姓名: ", i + 1);
        scanf("%s", s->name);
        s->prior = p;						/*指定前驱结点*/
        s->next = NULL;
        p = s;
    }
    p->next = NULL;
    return (h);
}

/*查找*/
stud *search(stud *h, char *x)
{
    stud *p;				/*指向结构体类型的指针*/
    char *y;
    p = h->next;		
    while (p)
    {
        y = p->name;
        if (strcmp(y, x) == 0)		/*如果是要删除的节点，则返回地址*/
            return (p);
        else
            p = p->next;
    }
    printf("没有找到数据!\n");
}

/*删除*/
void del(stud *p)
{
    p->next->prior = p->prior;		/*p的下一个结点的前驱指针指向p的前驱结点*/
    p->prior->next = p->next;		/*p的前驱结点的后继指针指向p的后继结点*/
    free(p);
}

void main()
{
    int number;
    char sname[20];
    stud *head,  *sp;
    puts("请输入链表的大小:");
    scanf("%d", &number);					/*输入链表结点数*/
    head = creat(number);					/*创建链表*/
    sp = head->next;
    printf("\n现在这个双链表是:\n");
    while (sp) 							/*输出链表中数据*/
    {
        printf("%s ", &*(sp->name));
        sp = sp->next;
    }
    printf("\n请输入你想查找的姓名:\n");
    scanf("%s", sname);
    sp = search(head, sname);				/*查找指定结点*/
    printf("你想查找的姓名是:%s\n",  * &sp->name);
    del(sp);							/*删除结点*/
    sp = head->next;
    printf("\n现在这个双链表是:\n");
    while (sp)
    {
        printf("%s ", &*(sp->name));			/*输出当前链表中数据*/
        sp = sp->next;
    }
    printf("\n");
    puts("\n 按任意键退出...");
}

