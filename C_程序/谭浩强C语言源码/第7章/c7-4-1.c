#include <stdio.h>
int main()
{float add(float x, float y);   
 float a,b,c;
 printf("Please enter a and b:");
 scanf("%f,%f",&a,&b);
 c=add(a,b);
 printf("sum is %f\n",c);
 return 0;
}

float add(float x,float y)       
 {float z;                          
  z=x+y;
  return(z);
}