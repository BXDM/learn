#include<stdio.h>

void main()
{
    int i, j, t, a[11];					/*定义变量及数组为基本整型*/
    printf("请输入10个数:\n");
    for (i = 1; i < 11; i++)
        scanf("%d", &a[i]);				/*从键盘中输入要排序的10个数字*/
    for (i = 1; i <= 9; i++)
        for (j = i + 1; j <= 10; j++)
            if (a[i] > a[j])				/*如果后一个数比前一个数大则利用中间变量t实现俩值互换*/
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    printf("排序后的顺序是:\n");
    for (i = 1; i <= 10; i++)
        printf("%5d", a[i]);				/*将排好序的数组输出*/
	    printf("\n");
}
