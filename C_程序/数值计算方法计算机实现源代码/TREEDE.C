
  //文件名 TREEDE.C
  //“追赶”法求解三对角方程组
  #include <math.h>
  #include <stdio.h>
  int treede(n, a, b, c, d)
  int  n;
  double  a[], b[], c[], d[];
  {   int k;
      for (k=0;k<=n-2;k++)
      { 
          if (fabs(b[k])+1.0==1.0)
          { printf("fail\n"); return(0);}
		  c[k] = c[k]/b[k];
		  d[k] = d[k]/b[k];
		  b[k+1] = b[k+1] - a[k+1]*c[k];
		  d[k+1] = d[k+1] - a[k+1]*d[k];
      }
      if (fabs(b[n-1])+1.0==1.0)
      { printf("fail\n"); return(0);}
      d[n-1]=d[n-1]/b[n-1];
      for (k=n-2;k>=0;k--)
          d[k]=d[k]-c[k]*d[k+1];
      return(1);
  }

  //包含在文件TREEDE.C中
  main()
  {   int i;
      double a[5] = {0, 11, 8, 5, 2};
	  double b[5] = {13, 10, 7, 4, 1};
	  double c[5] = {12, 9, 6, 3, 0};
      double d[5]={3, 0, -2, 6, 8};	  
	  if (treede(5,a,b,c,d)>0)
         for (i=0;i<=4;i++)
             printf("x(%d)=%f\n",i,d[i]);
	  return;
  }
