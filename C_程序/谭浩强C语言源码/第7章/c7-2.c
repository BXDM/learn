#include <stdio.h>
int main()
{ int max(int x,int y);  
  int a,b,c;  
  printf("please enter two integer numbers:");
  scanf("%d,%d",&a,&b);
  c=max(a,b);
  printf("max is %d\n",c);
  return 0;
}

int max(int x,int y)               // 定义max函数
{
  int z;                           // 定义临时变量
  z=x>y?x:y;                       // 把x和y中大者赋给z
  return(z);                       // 把z作为max函数的伦值带回main函数
}
