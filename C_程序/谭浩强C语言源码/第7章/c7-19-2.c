//file2.c
extern  A;
int power(int n)
 {int i,y=1;
  for(i=1;i<=n;i++)
    y*=A;
  return(y);
}
