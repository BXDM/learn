#include <stdio.h>
int main()
 {int a[10];
  int *p;
  printf("please enter 10 integer numbers:");
  for(p=a;p<(a+10);p++)
    scanf("%d",p);
  for(p=a;p<(a+10);p++)
    printf("%d ",*p);                             // 用指针指向当前的数组元素
  printf("\n");
  return 0;
}
