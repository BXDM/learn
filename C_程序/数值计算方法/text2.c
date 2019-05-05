#include<stdio.h>
#include<math.h>
int main()
{
	double x[] = {1.0,1.1,1.2,1.3,1.4};
	int i;double yy,y[10];
	for(i = 1;i<=5;i++)
	{
		yy = 1+x[i]*x[i];
		y[i] = yy*yy;
		printf("y[%d] = %d\n",i,y[i]);
	}
	return 0;
}
