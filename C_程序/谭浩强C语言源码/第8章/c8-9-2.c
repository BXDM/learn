#include <stdio.h>
int  main()
{void inv(int *x,int n);                  // inv函数声明
 int i,*arr;                              // 指针变量arr未指向数组元素
 printf("The original array:\n");
 for(i=0;i<10;i++)
   scanf("%d",arr+i);                   
 printf("\n");
 inv(arr,10);                             // 调用inv函数，实参arr是指针变量，但无指向
 printf("The array has been inverted:\n");
 for(i=0;i<10;i++)
   printf("%d ",*(arr+i));
 printf("\n");
 return 0;
}

void inv(int *x,int n)                      // 定义inv函数，形参x是指针变量 
 {int *p,m,temp,*i,*j;
  m=(n-1)/2;
  i=x;j=x+n-1;p=x+m;
  for(;i<=p;i++,j--)
    {temp=*i;*i=*j;*j=temp;}
  return;
 }
