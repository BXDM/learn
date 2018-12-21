#include <stdio.h>
#include <string.h>

void main()
{
    long t1;
    int i, n, t, t3;
    char a[100];
    printf("请输入字符:\n");
    gets(a);											/*输入n进制数存到数组a中*/
    strupr(a);											/*将a中的小写字母转换成大写字母*/
    t3 = strlen(a);										/*求出数组a的长度*/
    t1 = 0;												/*为t1赋初值0*/
    printf("请输入n(2or8or16):\n");
    scanf("%d", &n);										/*输入进制数*/
    for (i = 0; i < t3; i++)
    {
        if (a[i] - '0' >= n && a[i] < 'A' || a[i] - 'A' + 10 >= n)			/*判断输入的数据和进制数是否相符*/
        {
            printf("输入有误!!");							/*输出错误*/
            exit(0);										/*退出程序*/
        }
        if (a[i] >= '0' && a[i] <= '9')							/*判断是否为数字*/
            t = a[i] - '0';									/*求出该数字赋给t*/
        else if (n >= 11 && (a[i] >= 'A' && a[i] <= 'A' + n - 10))		/*判断是否为字母*/
            t = a[i] - 'A' + 10;								/*求出字母所代表的十进制数*/
        t1 = t1 * n + t;									/*求出最终转换成的十进制数*/
    }
    printf("十进制形式是%ld\n", t1);							/*将最终结果输出*/
}
