#include <stdio.h>

void main()
{
    char c1,c2;										/*定义字符变量*/
    printf("输入一个小写字符\n");						/*输出提示信息，提示用户输入一个字符*/
    c1=getchar();									/*将这个字符赋给变量c1*/
    c2=c1-32;										/*将小写字符对应的ASCII值减去32得到大写字符的ASCII值*/
    printf("转换以后的字符为：%c,%d\n",c2,c2);				/*输出这个大写字符*/
}
