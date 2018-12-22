#include <stdio.h>
int main()
 {int max(int,int);
  int a,b,c;
  printf("please enter a and b:");
  scanf("%d,%d",&a,&b);
  c=max(a,b);
  printf("a=%d\nb=%d\nmax=%d\n",a,b,c);
  return 0;
}

int max(int x,int y)
 {int z;
  if(x>y)  z=x;
  else     z=y;
  return(z);
 }
