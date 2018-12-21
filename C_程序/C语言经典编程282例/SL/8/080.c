#include<stdio.h>
main()
{
	int x, y, z, i;
	for (x = 1; x < 10; x++)									/*对x进行穷举*/
		for (y = 1; y < 10; y++)								/*对y进行穷举*/
			for (z = 0; z < 10; z++)							/*对z进行穷举，由于是个位所以可以为0*/
			{
				i = 100 * x + 10 * y + z + 100 * y + 10 * z + z; 	/*求和*/
				if (i == 532)								/*判断和是否等于532*/
					printf("x=%d,y=%d,z=%d\n", x, y, z);		/*输入x、y、z最终的值*/
			}
	return 0;
}
