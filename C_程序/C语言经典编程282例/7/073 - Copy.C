#include <stdio.h>

void main()
{
    float salary=500;										/*员工的基本工资*/
    int k;												/*定义变量，存储销售额系数*/
    int profit ;											/*定义整型变量，存储销售额*/
    printf("输入员工这个月的销售额：");					/*输出提示信息*/
    scanf("%d",&profit);									/*将输入的销售额存储到变量中*/
    if (profit%1000==0)									/*如果是1000的整数倍*/
        k=profit/1000;									/*获得销售系数*/
    else												/*否则*/
        k=profit/1000+1;									/*将销售系数加一*/
    switch (k)
    {
    case 0:											/*销售系数是0-2之间的没有提成*/
    case 1:         
    case 2: break;
    case 3: 											/*销售系数是3-5的提成为8%*/
    case 4:
    case 5:
        salary+=profit*0.08;								/*计算工资*/
        break;
    case 6:											/*销售系数为6-10的提成为10%*/
    case 7:
    case 8:
    case 9:
    case 10:
        salary+=profit*0.1;								/*计算工资*/
        break;
    default:											/*其他情况，销售系数超过10的提成为12%*/
        salary+=profit*0.12;								/*计算工资*/
        break;
    }
    printf("员工这个月的工资为：%5.2f\n",salary); 			/*输出员工这个月的工资*/
}
