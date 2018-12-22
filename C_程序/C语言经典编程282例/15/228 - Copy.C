#include <stdio.h>
#define A  8								/*定义宏，设置底边的长度*/
#define H  6								/*定义宏，设置高的长度*/

void main()
{
    int AREA;								/*定义整形变量，存储平行四边形面积*/
    AREA=A * H;							/*计算平行四边形面积*/
    printf("AREA = %d\n",AREA);				/*输出面积值*/
}
