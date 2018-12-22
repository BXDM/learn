#include <stdio.h>

void result(int a, int b, int c, int *x2, int *y2) 								/*自定义函数解*/
{
    int x[100], y[100], z[100];
    int i, j, d, t, gcd;
    x[0] = 0;
    y[0] = 1;
    for (i = 0; i < 100; i++)
    {
        z[i] = a / b; 											/*求a/b的值*/
        d = a % b; 											/*求a对b取余的值*/
        a = b;
        b = d;
        if (d == 0)
        {
            gcd = a; 										/*辗转法求最大公约数*/
            break;
        }
        if (i == 0)											/*判断a是否能被b整除*/
        {
            x[1] = 1;
            y[1] = z[0];
        }
        else
        {
            x[i + 1] = z[i] *x[i] + x[i - 1];
            y[i + 1] = z[i] *y[i] + y[i - 1];
        }
    }
    for (t =  - 1, j = 1; j < i; j++)
        t =  - t;
    *x2 =  - t * x[i];
    *y2 = t * y[i]; 											/*求出ax+by=gcd(a，b)的一组解*/
    if (c % gcd != 0)											/*如果c能否整除a和b的最大公约数*/
    {
        printf("无解!\n"); 							/*如不能整除，则输出无解的提示信息*/
        exit(0);
    }
    t = c / gcd; 												/*若能整除则将结果赋给t*/
    *x2 =  *x2 * t;
    *y2 =  *y2 * t;
}

void test(int a, int b, int c, int x, int y) 								/*自定义函数检测求出的结果*/
{
    if (a *x + b * y == c)										/*将x、y带进整式看是否等于c*/
        printf("结果正确!\n");
    else
        printf("结果错误!\n");
}

void main()
{
    int a, b, c, x2, y2;
    printf("输入a,b,c:\n"); 										/*输入a、b、c的值*/
    scanf("%d%d%d", &a, &b, &c);
    result(a, b, c, &x2, &y2); 									/*调用函数求出解*/
    test(a, b, c, x2, y2); 										/*检验结果是否正确*/
    printf("x=%d,y=%d\n", x2, y2); 								/*将x、y的值输出*/
}
