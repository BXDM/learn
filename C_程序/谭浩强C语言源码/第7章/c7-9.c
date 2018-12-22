#include <stdio.h>
int main()
  {int max(int x,int y);            
   int a[10],m,n,i;
   printf("enter 10 integer numbers:");
   for(i=0;i<10;i++)
     scanf("%d",&a[i]);
   printf("\n");
   for(i=1,m=a[0],n=0;i<10;i++)
   {                       
	  if (max(m,a[i])>m)                 // 若max函数返回的值大于m                  
	  {m=max(m,a[i]);                    // max函数返回的值取代m原值
	   n=i;                              // 把此数组元素的序号记下来，放在n中
	  }
   }
    printf("The largest number is %d\nit is the %dth number.\n",m,n+1);
	return 0;
   }

 int max(int x,int y)
  {
	 return(x>y?x:y);
 }
