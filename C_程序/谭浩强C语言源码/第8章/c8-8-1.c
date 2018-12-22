#include <stdio.h>
int main()
{void inv(int x[ ],int n);
 int i,a[10]={3,7,9,11,0,6,7,5,4,2};
 printf("The original array:\n");
 for(i=0;i<10;i++)
   printf("%d ",a[i]);                   // 输出未交换时数组各元素的值
 printf("\n");
 inv(a,10);                               // 调用inv函数，进行交换
 printf("The array has been inverted:\n");
 for(i=0;i<10;i++)
   printf("%d ",a[i]);                    //  输出交换后数组各元素的值
 printf("\n");
 return 0;
}

void inv(int x[ ],int n)                  // 形参x是蚊数组名
 {int temp,i,j,m=(n-1)/2;
  for(i=0;i<=m;i++)
    {j=n-1-i;
     temp=x[i];x[i]=x[j];x[j]=temp;       // 把x[i]和x[j]交换
	}
  return;
 }
