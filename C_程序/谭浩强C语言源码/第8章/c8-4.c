#include <stdio.h>
int main()
 {void swap(int *p1,int *p2);
  int a,b;
  int*pointer_1,*pointer_2;
  printf("please enter two integer numbers:");
  scanf("%d,%d",&a,&b);
  pointer_1=&a;
  pointer_2=&b;
  if(a<b) swap(pointer_1,pointer_2);
  printf("max=%d,min=%d\n",a,b);
  return 0;
 }    

void swap(int *p1,int *p2)
 {int *p;
  p=p1;
  p1=p2;
  p2=p;
 }
