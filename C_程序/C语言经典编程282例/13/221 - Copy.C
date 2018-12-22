#include <stdio.h>

void main()
{
    unsigned result;
    int a, b, c, d;
    a = 2;
    b = 4;
    c = 6;
    d = 8;
    printf("a=%d,b=%d,c=%d,d=%d", a, b, c, d);						/*输出变量a、b、c、d四个数的值*/
    result = a &c;											/*a与c的结果赋给result*/
    printf("\na&c=%u\n", result);									/*将结果输出*/
    result = b | d; 											/*b|d的结果赋给result*/
    printf("b|d=%u\n", result);									/*将结果输出*/
    result = a ^ d;											/*a^d的结果赋给result*/
    printf("a^d=%u\n", result);									/*将结果输出*/
    result = ~a;												/*~a的结果赋给result*/
    printf("~a=%u\n", result);									/*将结果输出*/
}
