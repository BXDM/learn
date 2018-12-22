#include <stdio.h>
#include  <math.h>                                // 程序中要调用求平方根函数sqrt  
int main ( ) 
 {double a,b,c,disc,x1,x2,p,q;                    // disc是判别式sqrt(b*b-4ac)  
  scanf("%lf%lf%lf",&a,&b,&c);                    // 输入实型变量的值要用格式声明"%f"  
  disc=b*b-4*a*c;
  p=-b/(2.0*a);
  q=sqrt(disc)/(2.0*a);
  x1=p+q;x2=p-q;                                  // 求出方程的两个根  
  printf("x1=%7.2f\nx2=%7.2f\n",x1,x2);           // 输出方程的两个根   
  return 0;
}


