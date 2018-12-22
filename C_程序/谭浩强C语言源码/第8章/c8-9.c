#include <stdio.h>
int  main()
{void inv(int *x,int n);                  // inv函数声明
 int i,arr[10],*p=arr;                    // 指针变量p指向arr[0]
 printf("The original array:\n");
 for(i=0;i<10;i++,p++)
   scanf("%d",p);                         // 输入arr数组的元素
 printf("\n");
 p=arr;                                    // 指针变量p重新指向arr[0]
 inv(p,10);                                // 调用inv函数，实参p是指针变量
 printf("The array has been inverted:\n");
 for(p=arr;p<arr+10;p++)
   printf("%d ",*p);
 printf("\n");
 return 0;
}

void inv(int *x,int n)                      // 定义inv函数，形参x是指针变量 
 {int temp,*i,*j;
  i=x;j=x+n-1;
  for(;i<=j;i++,j--)
    {temp=*i;*i=*j;*j=temp;}
  return;
 }
