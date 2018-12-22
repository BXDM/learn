#include<stdio.h>

void main()
{
    int x;
    printf("请输入一个整数:\n");
    scanf("%d", &x); 										/*从键盘中输入一个数*/
    if (x % 5 == 0 && x % 7 == 0)							/*判断该数是否能同时被5和7整除*/
        printf("yes\n");										/*如果能，则输出yes*/
    else
        printf("no\n");										/*如果不能，则输出no*/
}
