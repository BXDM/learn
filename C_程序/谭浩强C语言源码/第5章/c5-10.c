# include <stdio.h>
# include <math.h>
int main()
 {int n,k,i,m=0;
  for(n=101;n<=200;n=n+2)                        // n从100变化到200，对每个n进行判定
    { k=sqrt(n);
      for (i=2;i<=k;i++)                          
        if (n%i==0) break;                      // 如果n被i整除，终止内循环，此时i<k+1
      if (i>=k+1)                               // 若j>=k+1，表示n未被整除
		{printf("%d ",n);                       // 应确定n是素数
	     m=m+1;                                 // m用来控制换行，一行内输出10个录素数
		}     
	  if(m%10==0) printf("\n");                 // m累计到10的倍数，换行
    }
  printf ("\n");
  return 0;
 }
