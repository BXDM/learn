#include <stdio.h>
#define swap(a,b) {int c;c=a;a=b;b=c;}							/*定义一个带参的宏swap*/

void main()
{
    int i, j, a[10], b[10];									/*定义数组及变量为基本整型*/
    printf("请输入一个数组a:\n");
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);								/*输入一组数据存到数组a中*/
    printf("请输入一个数组b:\n");
    for (j = 0; j < 10; j++)
        scanf("%d", &b[j]);								/*输入一组数据存到数组b中*/
    printf("数组a是:\n");
    for (i = 0; i < 10; i++)
        printf("%d,", a[i]);								/*输出数组a中的内容*/
	printf("\n数组b是:\n");
    for (j = 0; j < 10; j++)
        printf("%d,", b[j]);								/*输出数组b中的内容*/
    for (i = 0; i < 10; i++)
        swap(a[i], b[i]);									/*实现数组a与数组b对应值互换*/
    printf("\n现在数组a是:\n");
    for (i = 0; i < 10; i++)
        printf("%d,", a[i]);								/*输出互换后数组a中的内容*/
    printf("\n现在数组b是:\n");
    for (j = 0; j < 10; j++)
        printf("%d,", b[j]);								/*输出互换后数组b中的内容*/ 
	printf("\n");
}
