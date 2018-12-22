#include <stdio.h>
int main()
{void inv(int *x,int n);
 int i,a[10]={3,7,9,11,0,6,7,5,4,2};
 printf("The original array:\n");
 for(i=0;i<10;i++)
   printf("%d ",a[i]);
 printf("\n");
 inv(a,10);
 printf("The array has been inverted:\n");
 for(i=0;i<10;i++)
   printf("%d ",a[i]);
 printf("\n");
 return 0;
}

void inv(int *x,int n)                   //形参x是指针变量       
 {int temp,*i,*j;
  i=x;j=x+n-1;
  for(;i<=j;i++,j--)
  {temp=*i;*i=*j;*j=temp;}               //*i与*j交换
  return;
 }


