#include <stdio.h>
#include <math.h>
int main()
 {int n,i,k;
  printf("please enter a integer number:n=?");
  scanf("%d",&n);
  k=sqrt(n);
  for (i=2;i<=k;i++)
    if(n%i==0) break;
  if(i<=k) 
	printf("%d is not a prime number.\n",n);
  else printf("%d is a prime number.\n",n);
  return 0;
} 
