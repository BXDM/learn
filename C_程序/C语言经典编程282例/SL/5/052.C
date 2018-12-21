#include <stdio.h>
#include <math.h>

void main()
{
    double a,b,c;								/*定义系数变量*/
    double x1,x2,p;								/*定义根变量和表达式的变量值*/
    printf("请输入a,b,c:");						/*提示用户输入三个系数*/
    scanf("%lf%lf%lf",&a,&b,&c);					/*接收用户输入的系数*/
    printf("\n");								/*输出回行*/
    p=b*b-4*a*c;								/*给表达式赋值*/
    x1=(-b+sqrt(p))/(2*a);							/*根1的值*/
    x2=(-b-sqrt(p))/(2*a);							/*跟2的值*/
    printf("x1=%f,x2=%f\n",x1,x2);					/*输出两个根的值*/
}
