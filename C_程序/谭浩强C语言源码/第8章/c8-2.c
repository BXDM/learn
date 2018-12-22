#include <stdio.h>
int main()
 { int *p1,*p2,*p,a,b;
   printf("please enter two integer numbers:");
   scanf("%d,%d",&a,&b);                   // 输入两个整数
   p1=&a;                                  // 使p1指向变量a
   p2=&b;                                  // 使p2指向变量b 
   if(a<b)                                 // 如果a<b
     {p=p1;p1=p2;p2=p;}                    // 使p1与p2的值互换
   printf("a=%d,b=%d\n",a,b);              // 输出a,b
   printf("max=%d,min=%d\n",*p1,*p2);      // 输出p1和p2所指向的变量的值
   return 0;
}
