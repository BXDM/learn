#include <stdio.h>
int main()
 {
  int i; // 
  int f[120]={1,2};
  for(i=2;i<120;i++)
    //f[i]=f[i-2]+f[i-1];
    f[i]=f[i-1]*2;
  for(i=0;i<120;i++)
    {
     if(i%5==0) printf("\n");
       printf("%12d",f[i]);
    }
  printf("\n");
  return 0;
}
