#include <stdio.h>
#define Listsize 100

struct sqlist
{
    int data[Listsize];
    int length;
};

void InsertList(struct sqlist *l, int t, int i)
{
    int j;
    if (i < 0 || i > l->length)
    {
        printf("位置错误");
        exit(1);
    } 
    if (l->length >= Listsize)					/*如果超出顺序表范围，则溢出*/
    {
        printf("溢出");
        exit(1);
    }
    for (j = l->length - 1; j >= i; j--)				/*插入元素*/
        l->data[j + 1] = l->data[j];
    l->data[i] = t;
    l->length++;
}

void main()
{
    struct sqlist *sq;
    int i, n, t;
    sq = (struct sqlist*)malloc(sizeof(struct sqlist));				/*分配空间*/
    sq->length = 0;
    printf("请输入链表大小:");
    scanf("%d", &n);
    printf("请输入链表的元素:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &t);
        InsertList(sq, t, i);								/*插入元素*/
    } printf("这个链表现在是:\n");
    for (i = 0; i < sq->length; i++)
    {
        printf("%d ", sq->data[i]);
    }
    getch();
}
