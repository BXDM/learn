#include <stdio.h>
#include "Area.H"

void main()
{
    float r;										/*定义浮点型变量，存储圆的半径*/
    printf("请输入半径:\n");						/*提示用户输入圆的半径*/
    scanf("%f",&r);									/*接收用户的输入*/
    printf("面积 =%.2f\n",Area(r));					/*输出圆的面积*/
}

