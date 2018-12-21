#include "format.h"								/*引用自定义头文件*/
#include <stdio.h>								/*引用输入输出头文件*/

void main()
{
    int d;										/*定义整型变量*/
    printf("请输入一个整数:");					/*提示用户输入整型数字*/
    scanf("%d",&d);								/*接收用户输入*/
    INTEGER(d);								/*调用头文件输出整型数字*/
}
