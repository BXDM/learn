  //文件名NSQT.C
  //多变量线性拟合
  #include  <math.h>
  #include  <stdlib.h>
  #include  <stdio.h>
  void nsqt(m, n, x, y, a, dt, v)
  int  m, n;
  double  x[], y[], a[], dt[], v[];
  { 
	  int i,j,k,mm;
      double q,e,u,p,yy,s,r,pp,*b;
	  void cholesky(int, double []);
	  void chol_equ(int, double [], double []);
      b=(double *)malloc((m+1)*(m+1)*sizeof(double));
      mm=m+1;
      b[mm*mm-1]=n;
      for (j=0; j<=m-1; j++)
      { 
		  p=0.0;
          for (i=0; i<=n-1; i++) p=p+x[j*n+i];
          b[m*mm+j]=p;
          b[j*mm+m]=p;
      }
      for (i=0; i<=m-1; i++)
      for (j=i; j<=m-1; j++)
      {
		  p=0.0;
          for (k=0; k<=n-1; k++) p=p+x[i*n+k]*x[j*n+k];
          b[j*mm+i]=p;
          b[i*mm+j]=p;
      }
      a[m]=0.0;
      for (i=0; i<=n-1; i++) a[m]=a[m]+y[i];
      for (i=0; i<=m-1; i++)
      { 
		  a[i]=0.0;
          for (j=0; j<=n-1; j++) a[i]=a[i]+x[i*n+j]*y[j];
      }
      cholesky(mm, b);  //Cholesky分解
      chol_equ(mm, b, a); //利用Cholesky分解结果求解方程组
      yy=0.0;
      for (i=0; i<=n-1; i++) yy=yy+y[i]/n;
      q=0.0; e=0.0; u=0.0;
      for (i=0; i<=n-1; i++)
      { 
		  p=a[m];
          for (j=0; j<=m-1; j++) p=p+a[j]*x[j*n+i];
          q=q+(y[i]-p)*(y[i]-p);
          e=e+(y[i]-yy)*(y[i]-yy);
      }
      s=sqrt(q/n);
      r=sqrt(1.0-q/e);
      for (j=0; j<=m-1; j++)
      { 
		  p=0.0;
          for (i=0; i<=n-1; i++)
          { 
			  pp=a[m];
              for (k=0; k<=m-1; k++)
                  if (k!=j) pp=pp+a[k]*x[k*n+i];
              p=p+(y[i]-pp)*(y[i]-pp);
          }
          v[j]=sqrt(1.0-q/p);
      }
      dt[0]=q; dt[1]=s; dt[2]=r;
      free(b); return;
  }

	void cholesky(int n, double a[])  //Cholesky分解
	{
		int i, j, k, u, v;
		double  sum;
		for (i=0; i<n; i++)
		for (j=0; j<n; j++)
		{
			sum = a[i*n+j];
			for (k=0; k<=(i-1); k++)
			{ 
				u = i*n + k;  v = j*n + k;
			    sum = sum - a[u]*a[v]; 
			}
			if (i == j)	a[i*n+i] = sqrt(sum);
			else	{ a[j*n+i] = sum/a[i*n+i]; }
		}
		return;
	}
	
    void chol_equ(int n, double a[], double b[]) //利用Cholesky分解结果求解方程组
	{
		int i, k;
		double  sum;
		for (i=0; i<n; i++)            //逐步递推
		{
			sum = b[i];
			for (k=0; k<=(i-1); k++)
			{ sum = sum - a[i*n+k]*b[k]; }
			b[i] = sum/a[i*n+i];
		}
		for (i=(n-1); i>=0; i--)       //逐步回代
		{
			sum = b[i];
			for (k=(i+1); k<n; k++)
			{ sum = sum - a[k*n+i]*b[k]; }
			b[i] = sum/a[i*n+i];
		}
		return;
	}

  //包含在文件NSQT.C中
  main()
  { 
	  int i;
      double a[4],v[3],dt[3];
      double x[3][5]={ {1.1,1.0,1.2,1.1,0.9},
         {2.0,2.0,1.8,1.9,2.1},{3.2,3.2,3.0,2.9,2.9}};
      double y[5]={10.1,10.2,10.0,10.1,10.0};	  
	  nsqt(3,5,&x[0][0],y,a,dt,v);
	  printf("alpha=%f\n",a[3]);
      for (i=0; i<=2; i++)
          printf("a(%2d)=%f\n",i,a[i]);
      printf("q=%f  s=%f  r=%f\n",dt[0],dt[1],dt[2]);
      for (i=0; i<=2; i++)
          printf("v(%2d)=%f\n",i,v[i]);
  }

