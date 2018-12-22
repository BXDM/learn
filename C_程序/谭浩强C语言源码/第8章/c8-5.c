#include <stdio.h>
int main()
{ void exchange(int *q1, int *q2, int *q3);    // 函数声明  
  int a,b,c,*p1,*p2,*p3;
  printf("please enter three numbers:");
  scanf("%d,%d,%d",&a,&b,&c);
  p1=&a;p2=&b;p3=&c;
  exchange(p1,p2,p3);
  printf("The order is:%d,%d,%d\n",a,b,c);
  return 0;
}

void exchange(int *q1, int *q2, int *q3)       // 定义将3个变量的值交换的函数   
{ void swap(int *pt1, int *pt2);               // 函数声明  
  if(*q1<*q2) swap(q1,q2);                     // 如果a<b，交换a和b的值  
  if(*q1<*q3) swap(q1,q3);                     // 如果a<c，交换a和c的值  
  if(*q2<*q3) swap(q2,q3);                     // 如果b<c，交换b和c的值  
}        

void swap(int *pt1, int *pt2)                  // 定义交换2个变量的值的函数      
{ int temp;
  temp=*pt1;                                   // 换*pt1和*pt2变量的值  
  *pt1=*pt2;
  *pt2=temp;
}  
