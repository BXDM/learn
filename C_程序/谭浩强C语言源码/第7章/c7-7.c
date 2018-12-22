#include <stdio.h>
int  main()
{ int fac(int n);   
  int n;
  int y;
  printf("input an integer number:");
  scanf("%d",&n);
  y=fac(n);
  printf("%lld!=%d\n",n,y);
  return 0;
}

 int fac(int n)
 {
  int f;
  if(n<0)
	 printf("n<0,data error!");
  else if(n==0||n==1) 
	 f=1;
  else  f=fac(n-1)*n;
  return(f);
 }

