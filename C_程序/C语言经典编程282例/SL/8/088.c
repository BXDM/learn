#include<stdio.h>
main()
{
	int n = 1, m, sum, i; 								/*定义变量为基本整形*/
	while (1)
	{
		m = n; 										/*m存储一楼灯的数量*/
		sum = 0;
		for (i = 1; i < 8; i++)
		{
			m = m * 2;								/*每层楼灯的数量是上一层的2倍*/
			sum += m; 								/*计算出除一楼外灯的总数*/
		}
		sum += n; 									/*加上一楼灯的数量*/
		if (sum == 765)								/*判断灯的总数量是否达到765*/
		{
			printf("the first floor has %d\n", n); 			/*输出一楼灯的数量*/
			printf("the eight floor has %d\n", m); 			/*输出八楼灯的数量*/
			break; 									/*跳出循环*/
		}
		n++; 										/*灯的数量加1，继续下次循环*/
	}
	return 0;
}
