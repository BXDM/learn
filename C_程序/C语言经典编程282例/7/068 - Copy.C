#include <stdio.h>

void main()
{
    int value;
    printf("输入一个整数:\n");	/*输出提示信息*/
    scanf("%d",&value);			/*输入value*/
    if (value%2==0)				/*判断value是否能被2整除*/
    {
        printf("%d 是偶数！\n",value);/*输出value的值*/
    }
}

