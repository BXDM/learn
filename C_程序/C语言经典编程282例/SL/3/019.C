#include <stdio.h>

void insort(int s[], int n)							/*自定义函数isort*/
{
    int i, j;
    for (i = 2; i <= n; i++)					/*数组下标从2开始，0做监视哨，1一个数据无可比性*/
    {
        s[0] = s[i];								/*给监视哨赋值*/
        j = i - 1;								/*确定要进行比较的元素的最右边位置*/
        while (s[0] < s[j])
        {
            s[j + 1] = s[j];							/*数据右移*/
            j--;								/*移向左边一个未比较的数*/
        }
        s[j + 1] = s[0];							/*在确定的位置插入s[i]*/
    }
}

void main()
{
    int a[11], i;									/*定义数组及变量为基本整型*/
    printf("请输入10个数据:\n");
    for (i = 1; i <= 10; i++)
        scanf("%d", &a[i]);							/*接收从键盘中输入的10个数据到数组a中*/
    printf("原始顺序:\n");
    for (i = 1; i < 11; i++)
        printf("%5d", a[i]);							/*将未排序前的顺序输出*/
    insort(a, 10);									/*调用自定义函数isort()*/
    printf("\n插入数据排序后顺序:\n");
    for (i = 1; i < 11; i++)
        printf("%5d", a[i]);							/*将排序后的数组输出*/
    printf("\n");
}
