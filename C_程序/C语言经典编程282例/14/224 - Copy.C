#include <stdio.h>
#include <malloc.h>

void main()
{
    int n,*p,*q;									/*定义整型变量*/
    printf("输入数据的个数:");						/*输出提示信息，提示用户输入数据的个数*/
    scanf("%d",&n);									/*接收数据*/
    p=(int *)calloc(n,2);							/*分配内存空间*/
    printf("为%d个数据分配内存空间 ",n);			/*提示用户已经分配了内存空间*/
    for(q=p;q<p+n;q++)								/*循环*/
    {
        scanf("%d",q);								/*接收数据，并赋值*/
        printf("%4d",*q);							/*输出数据*/
    }
    printf("\n");									/*输出回行*/
}
