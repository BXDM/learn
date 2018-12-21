#include<stdio.h>
#include<stdlib.h>

int main()
{
    int* p;
    int i;
    p=(int*)malloc(sizeof(int[3]));						/*分配内存空间*/
    for(i=0;i<3;i++)
    {
        *(p+i)=10*(1+i);								/*给数组赋值*/
        printf("%d\n",*(p+i));							/*输出数组的值*/
    }
    return 0;
}
