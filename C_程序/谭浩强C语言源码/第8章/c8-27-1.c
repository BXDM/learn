#include <stdio.h>
#include <string.h>
int main()
 {void sort(char *name[ ],int n);
  void print(char *name[ ],int n);
  char *name[ ]={"Follow me","BASIC","Great Wall","FORTRAN","Computer design"};
  int n=5;
  sort(name,n);
  print(name,n);
  return 0;
}

void sort(char *name[ ],int n)
 {char *temp;
  int i,j,k;
  for(i=0;i<n-1;i++)
	 {k=i;
      for(j=i+1;j<n;j++)
	      if(strcmp(name[k],name[j])>0) k=j;
	  if(k!=i)
	    {temp=name[i]; name[i]=name[k]; name[k]=temp;}
	 }
}

void print(char *name[ ],int n)
 {int i;
  for(i=0;i<n;i++)
    printf("%s\n",name[i]);
}
