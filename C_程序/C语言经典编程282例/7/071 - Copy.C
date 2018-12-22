#include <stdio.h>

void main()
{
    float s1,s2,s3,s4,min,max;								/*定义浮点型变量*/
    printf("输入4个成绩：\n");								/*提示用户输入四个值*/
    scanf("%f%f%f%f",&s1,&s2,&s3,&s4);					/*接收用户输入的值*/
    min=max=s1;										/*将第一个数赋值给min和max变量*/
    if (s2<min)											/*查看s2是否比min变量小*/
        min=s2;										/*如果s2比min小，则替换*/
    else if(s2>max)										/*如果比最大值大*/
        max=s2;										/*将s2赋给max变量*/
    if (s3<min)											/*比较s3*/
        min=s3;
    else if(s3>max)
        max=s3;
    if (s4<min)											/*比较s4*/
        min=s4;
    else if(s4>max)
        max=s4;
    printf("min= %3.2f  max=%3.2f\n",min,max);			/*输出最大值和最小值*/
}
