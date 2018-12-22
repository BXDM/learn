#include <stdio.h>
int main()
{ int max( );     
  extern int A,B,C;                        // 把外部变量A,B,C的作用域扩展到从此处开始
  printf("Please enter three integer numbers:");
  scanf("%d %d %d",&A,&B,&C);
  printf("max is %d\n",max());
  return 0;
}

int A ,B ,C;                     // 定义外部变量A,B,C      

int max( )    
{ int m;
  m=A>B?A:B;
  if (C>m) m=C;
  return(m);
}
