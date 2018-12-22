#include <stdio.h>
int main()
 { 
  int f1=1,f2=1;
  int i;
  for(i=1; i<=20; i++)                    // 每个循环中输出2个月的数据，故循环20次即可
    {
	  printf("%12d %12d ",f1,f2);         // 输出己知的两个月的兔子数
      if(i%2==0) printf("\n");
      f1=f1+f2;                       // 计算出下一个月的兔子数，并存放在f1中
      f2=f2+f1;                       // 计算出下两个月的兔子数，并存放在f2中
    }
  return 0;
}
