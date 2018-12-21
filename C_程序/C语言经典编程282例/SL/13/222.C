#include <stdio.h>

void main()
{
    unsigned result; 								/*定义无符号数*/
    int a, b;
    printf("请输入a:");
    scanf("%d",&a);
    b=0;											/*与0异或*/
    printf("a=%d,b=%d", a, b);
    result = a^b; 									/*求整数与0异或的结果*/
    printf("\na^b=%u\n", result);
}
