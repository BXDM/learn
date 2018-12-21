#include<stdio.h>
void main()
{ 
    char a;									/*定义字符变量*/
    a='#';										/*给变量赋值*/
    printf("\40\40%c\n",a);						/*输出变量和转义字符*/
    printf("\40%c\40%c\n",a,a);						/*输出变量和转义字符*/
    printf("%c\40%c\40%c\n",a,a,a);					/*输出变量和转义字符*/
}
