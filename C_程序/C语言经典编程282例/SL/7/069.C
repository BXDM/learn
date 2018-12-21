#include <stdio.h>

void main()
{
    char c;										/*定义字符变量c*/
    printf("输入一个字母:\n");							/*输出提示信息*/
    c=getchar();									/*接收用户输入*/
    if (c>=65 && c<=90)								/*大写字母的范围*/
        printf("uppercase letter!\n");						/*该字母为大写字母*/
    else											/*否则*/
        printf("other letter!\n");							/*提示该字母属于其他字母*/
}
