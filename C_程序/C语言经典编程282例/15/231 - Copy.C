#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define EVEN(x) (((x)%2==0)?TRUE:FALSE)

void main()
{
    int sum,i;									/*定义整型变量，分别为存储累计和和循环计数变量*/
    sum=0;									/*给累加和初始化*/
    for(i=1;i<=100;i++)							/*1-100做循环*/
    {
        if(EVEN(i))								/*如果是偶数*/
            sum+=i;							/*累加*/
    }
    printf("SUM=%d\n",sum);						/*输出累加和*/
}
