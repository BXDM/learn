#include <stdio.h>
int main()
{
  int i,j,n=0;
  for (i=1;i<=4;i++)                      
    for (j=1;j<=5;j++,n++)
	{ if(n%5==0)printf("\n");         //控制在输出5个数据后换行
	  if (i==3 && j==1) continue;    //遇到第3行第1列，提前结束执行本次内循环体
	  printf("%d\t",i*j);
	}  
  printf("\n");	
  return 0;
}
