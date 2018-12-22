#include <stdio.h>
void main()
{ int max4(int a,int b,int c,int d); 
  int a,b,c,d,max;
  printf("Please enter 4 interger numbers:");
  scanf("%d %d %d %d",&a,&b,&c,&d);
  max=max4(a,b,c,d);
  printf("max=%d \n",max);
} 

int max4(int a,int b,int c,int d) 
{int max2(int a,int b);
 return max2(max2(max2(a,b),c),d);         /* ×ÐÏ¸·ÖÎö´ËÐÐ */
  
}

int max2(int a,int b)
{
 return(a>b?a:b);                         
}
