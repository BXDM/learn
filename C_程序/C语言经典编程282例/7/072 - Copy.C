#include<stdio.h>
#include<stdlib.h>

void main()
{
    int button;							/*定义变量*/
    system("cls");						/*清屏*/
    printf("**********************\n");	/*输出普通字符*/
    printf("*  可选择的按键:     *\n");
    printf("*  1. 巧克力         *\n");
    printf("*  2. 蛋糕           *\n");
    printf("*  3. 可口可乐       *\n");
    printf("**********************\n");
    printf("从1~3中选择按键:\n");			/*输出提示信息*/
    scanf("%d",&button);					/*输入数据*/
    switch(button)							/*根据button决定输出结果*/
    {
    case 1: 
        printf("你选择了巧克力");
        break;
    case 2: 
        printf("你选择了蛋糕");
        break;
    case 3: 
        printf("你选择了可口可乐");
        break;
    default:
        printf("\n 输入错误 !\n");			/*其它情况*/
        break;
    }
     printf("\n");
}