#include <stdio.h>

void qusort(int s[], int start, int end)									/*自定义函数qusort()*/
{
    int i, j;													/*定义变量为基本整型*/
    i = start;												/*将每组首个元素赋给i*/
    j = end;												/*将每组末尾元素赋给j*/
    s[0] = s[start];											/*设置基准值*/
    while (i < j)
    {
        while (i < j && s[0] < s[j])
            j--;											/*位置左移*/
        if (i < j)
        {
            s[i] = s[j];										/*将s[j]放到s[i]的位置上*/
            i++;											/*位置右移*/
        }
        while (i < j && s[i] <= s[0])
            i++;											/*位置右移*/
        if (i < j)
        {
            s[j] = s[i];										/*将大于基准值的s[j]放到s[i]位置*/
            j--;											/*位置右移*/
        }
    }
    s[i] = s[0];												/*将基准值放入指定位置*/
    if (start < i)
        qusort(s, start, j - 1);									/*对分割出的部分递归调用函数qusort()*/
    if (i < end)
        qusort(s, j + 1, end);
}

void main()
{
    int a[11], i;												/*定义数组及变量为基本整型*/
    printf("请输入10个数:\n");
    for (i = 1; i <= 10; i++)
        scanf("%d", &a[i]);										/*从键盘中输入10个要进行排序的数*/
    qusort(a, 1, 10);											/*调用qusort()函数进行排序*/
    printf("排序后的顺序是:\n");
    for (i = 1; i <= 10; i++)
        printf("%5d", a[i]);										/*输出排好序的数组*/
	    printf("\n");
}
