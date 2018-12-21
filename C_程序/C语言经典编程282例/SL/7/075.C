#include <stdio.h>

void main()
{
    float x, m1, m2, m;
    char y, z;
    scanf("%f,%c,%c", &x, &y, &z); 					/*输入选择油的千克数、种类及服务*/
    switch (y)										/*选择汽油种类*/
    {
        case 'a':
            m1 = 3.25;
            break;
        case 'b':
            m1 = 3.00;
            break;
        case 'c':
            m1 = 2.75;
            break;
    }
    switch (z)										/*选择服务种类*/	
    {
        case 'a':									/*不需要提供服务*/
            m2 = 0;
            break;
        case 'm':
            m2 = 0.05;
            break;
        case 'e':
            m2 = 0.1;
            break;
    }
    m = x * m1 - x * m1 * m2; 						/*计算应付的钱数*/
    printf("汽油种类是:%c\n", y);
    printf("服务等级是:%c\n", z);
    printf("用户应付金额是:%.3f\n", m);
}
