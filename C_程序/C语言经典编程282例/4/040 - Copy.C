#include<stdio.h>

int bin_dec(int x, int n) 									/*自定义函数将二进制数转换成十进制数*/
{
    if (n == 0)
     /*递归结束条件*/
    {
        return 1;
    }
    return x *bin_dec(x, n - 1); 								/*递归调用bin_dec()函数*/
}

void main()
{
    int i;
    int ip[4] ={0};
    char a[33]; 											/*存放输入的二进制数*/
    printf("输入二进制数:\n");
    scanf("%s", a); 										/*二进制数以字符串形式读入*/

    for (i = 0; i < 8; i++)
    {
        if (a[i] == '1')
        {
            ip[0] += bin_dec(2, 7-i); 							/*计算0-7转换的结果*/
        }
    }
    for (i = 8; i < 16; i++)
    {
        if (a[i] == '1')
        {
            ip[1] += bin_dec(2, 15-i); 						/*计算8-15转换的结果*/
        }
    }
    for (i = 16; i < 24; i++)
    {
        if (a[i] == '1')
        {
            ip[2] += bin_dec(2, 23-i); 							/*计算16-23转换的结果*/
        }
    }
    for (i = 24; i < 32; i++)
    {
        if (a[i] == '1')
        {
            ip[3] += bin_dec(2, 31-i); 							/*计算24-31转换的结果*/
        }
        if (a[i] == '\0')
        {
            break;
        }
    }
    printf("IP:\n");
    printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);				/*将最终结果以IP形式输出*/
}
