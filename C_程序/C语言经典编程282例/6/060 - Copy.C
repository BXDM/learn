#include <stdio.h>

void main()
{
    char c1,c2,c3;										/*定义字符变量*/
    printf("输入一个字符，使用getche函数接收\n");			/*提示用户输入一个字符*/
    c1=getche();										/*使用getche()函数接收*/
    printf("\n");										/*输出一行空行*/
    
    printf("输入一个字符，使用getch函数接收\n");			/*提示用户输入一个字符*/
    c2=getch();											/*使用getch()函数接收*/
    printf("\n");										/*输出一行空行*/
    
    printf("输入一个字符，使用getchar函数接收\n");			/*提示用户输入一个字符*/
    c3=getchar();										/*使用getchar()函数接收*/
    printf("\n输入的这三个字符是：\n");						/*输出一行空行*/
    /*将这些字符输出*/
    putchar(c1);
    putchar(c2);
    putchar(c3);
    printf("\n");
}
