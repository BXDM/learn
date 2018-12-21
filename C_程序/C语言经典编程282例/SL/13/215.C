#include<stdio.h>

void main()
{
    unsigned result; 									/*定义无符号数*/
    int a, b;
    printf("请输入a:");
    scanf("%d",&a);									/*输入一个数*/
    b=15;											/*15的二进制形式为00001111，所以这里使用15*/
    result = a^b; 									/*求a与b异或的结果*/
    printf("\n结果是: %d\n", result);						/*输出结果*/
}
