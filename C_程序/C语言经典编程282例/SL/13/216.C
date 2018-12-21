#include<stdio.h>

void main()
{
    int a;
    printf("请输入a:");
    scanf("%d",&a);							/*输入一个数*/
    a=a<<2;								/*左移两位*/
    printf("\n结果是: %d\n", a);				/*得到结果*/
}
