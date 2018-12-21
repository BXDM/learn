#include <stdio.h>

void main()
{
    char c,c1;													/*定义字符变量*/
    printf("请输入字符:\n");								/*输出字符串，提示用户输入字符*/
    c=getchar();												/*接收用户输入的字符*/
    c1=c-1;													/*求出字符的前驱字符*/
    printf("字符=%c %d, 前驱字符=%c %d\n",c,c,c1,c1);				/*输出字符的前驱字符*/
}
