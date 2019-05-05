#include<stdio.h>
#include<math.h>
int main()
{
	double x[] = {1.0,1.1,1.2,1.3,1.4};
	int i;double yy,y[10];
	for(i = 1;i<= 4;i++)
	{
		y[i] = 1/pow((1+x[i]*x[i]),2);
		printf("y[i] = %d\n",y[i]);
	}
	return 0;

}
