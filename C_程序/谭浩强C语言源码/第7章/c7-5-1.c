#include <stdio.h>
int main()
{ int max4(int a,int b,int c,int d);             // 对max4的函数声明
  int a,b,c,d,max;
  printf("Please enter 4 interger numbers:");    // 提示输入4个数
  scanf("%d %d %d %d",&a,&b,&c,&d);              // 输入4个数
  max=max4(a,b,c,d);                             // 调用max4函数，得到4个数中的最大者
  printf("max=%d \n",max);                       // 输出4个数中的最大者  
  return 0;
} 

int max4(int a,int b,int c,int d)   // 定义max4函数 
{int max2(int a,int b);             // 对max2的函数声明
 int m; 
 m=max2(a,b);                       // 调用max2函数，得到a和b两个数中的大者，放在m中
 m=max2(m,c);                       // 调用max2函数，得到a,b,c三个数中的大者，放在m中                         
 m=max2(m,d);                       // 调用max2函数，得到a,b,c,d四个数中的大者，放在m中           
 return(m);                         // 把m作为函数值带回main函数
}

int max2(int a,int b)               // 定义max2函数 
{if(a>=b)
   return a;                        // 若a>=b，将a为函数返回值 
 else 
   return b;                        // 若a<b，将b为函数返回值
}