#include <stdio.h>

void merge(int r[], int s[], int x1, int x2, int x3) /*实现一次归并排序函数*/
{
    int i, j, k;
    i = x1; 										/*第一部分的开始位置*/
    j = x2 + 1; 										/*第二部分的开始位置*/
    k = x1;
    while ((i <= x2) && (j <= x3))
     											/*当i和j都在两个要合并的部分中*/
        if (r[i] <= r[j])
     											/*筛选两部分中较小的元素放到数组s中*/
    {
        s[k] = r[i];
        i++;
        k++;
    }
    else
    {
        s[k] = r[j];
        j++;
        k++;
    }
    while (i <= x2)
    												/*将x1~x2范围内的未比较的数顺次加到数组r中*/
        s[k++] = r[i++];
    while (j <= x3)
     											/*将x2+1~x3范围内的未比较的数顺次加到数组r中*/
        s[k++] = r[j++];
}

void merge_sort(int r[], int s[], int m, int n)
{
    int p;
    int t[20];
    if (m == n)
        s[m] = r[m];
    else
    {
        p = (m + n) / 2;
        merge_sort(r, t, m, p);
            									/*递归调用merge_sort函数将r[m]~r[p]归并成有序的t[m]~t[p]*/
        merge_sort(r, t, p + 1, n);						/*递归调用merge_sort函数将r[p
            +1]~r[n]归并成有序的t[p+1]~t[n]*/
        merge(t, s, m, p, n); 						/*调用函数将前两部分归并到s[m]~s[n]*/
    }
}

void main()
{
    int a[11];
    int i;
    printf("请输入10个数:\n");
    for (i = 1; i <= 10; i++)
        scanf("%d", &a[i]);
     									/*从键盘中输入10个数*/
    merge_sort(a, a, 1, 10);					 /*调用merge_sort函数进行归并排序*/
    printf("排序后的顺序是:\n");
    for (i = 1; i <= 10; i++)
        printf("%5d", a[i]);
     									/*将排序后的结构输出*/
	    printf("\n");
}
