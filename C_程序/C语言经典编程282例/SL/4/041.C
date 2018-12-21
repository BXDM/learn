#include <stdio.h>

void main()
{
    int i, j;
    int hun, ten, data; 							/*定义变量存储分解出的百位、十位、个位*/
    printf("结果是:\n");
    for (i = 100; i <= 999; i++)
    {
        j = 10;
        while (j *j <= i)
        {
            if (i == j *j)
            {
                hun = i / 100; 						/*分解出百位上的数*/
                data = i - hun * 100;
                ten = data / 10; 					/*分解出十位上的数*/
                data = data - ten * 10; 			/*分解出个位上的数*/
                if (hun == ten || hun == data || ten == data)/*判断分解出的三个数中是否有两个数是相等的*/
                    printf("%5d", i);				/*将符合条件的数输出*/
            }
            j++;
        }
    }
	printf("\n");
}
