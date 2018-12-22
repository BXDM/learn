#include <stdio.h>
float Max=0,Min=0;                                       // 定义全局变量Max,Min
int main()
{ float average(float array[ ],int n);
  float ave,score[10];
  int i;
  printf("Please enter 10 scores:");
  for(i=0;i<10;i++)
    scanf("%f",&score[i]);
  ave=average(score,10);
  printf("max=%6.2f\nmin=%6.2f\naverage=%6.2f\n",Max,Min,ave);
  return 0;
 }

float average(float array[ ],int n)                       // 定义函数，有一形参是数组
{ int i;
  float aver,sum=array[0];
  Max=Min=array[0];
  for(i=1;i<n;i++)
    {if(array[i]>Max)Max=array[i];
     else if(array[i]<Min)Min=array[i];
     sum=sum+array[i]; 
    }
  aver=sum/n;
  return(aver);
}
