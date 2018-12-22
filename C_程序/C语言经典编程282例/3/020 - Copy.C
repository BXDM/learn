#include <stdio.h>

void shsort(int s[], int n)									/*自定义函数shsort*/
{
    int i, j, d;
    d = n / 2;											/*确定固定增量值*/
    while (d >= 1)
    {
        for (i = d + 1; i <= n; i++)								/*数组下标从d+1开始进行直接插入排序*/
        {
            s[0] = s[i];									/*设置监视哨*/
            j = i - d;										/*确定要进行比较的元素的最右边位置*/
            while ((j > 0) && (s[0] < s[j]))
            {
                s[j + d] = s[j];								/*数据右移*/
                j = j - d;									/*向左移d个位置*/
            }
            s[j + d] = s[0];									/*在确定的位置插入s[i]*/
        }
        d = d / 2;										/*增量变为原来的一半*/
    }
}

void main()
{
    int a[11], i;											/*定义数组及变量为基本整型*/
    printf("请输入10个数据:\n");
    for (i = 1; i <= 10; i++)
        scanf("%d", &a[i]);									/*从键盘中输入10个数据*/
    shsort(a, 10);										/*调用shsort()函数*/
    printf("排序后的顺序是:\n");
    for (i = 1; i <= 10; i++)
        printf("%5d", a[i]);									/*将排好序的数组输出*/
		printf("\n");
}
