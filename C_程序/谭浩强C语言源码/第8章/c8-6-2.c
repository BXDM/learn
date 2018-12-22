#include <stdio.h>
int main()
 {int a[10];
  int i;
  printf("please enter 10 integer numbers:");
  for(i=0;i<10;i++)
    scanf("%d",&a[i]);
  for(i=0;i<10;i++)
    printf("%d ",*(a+i));       //通过故数组名和元素序号计算元素地址，再找到该元素
  printf("\n");
  return 0;
 }
