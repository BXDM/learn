  //文件名 NNEWTON.C
  //拟牛顿法求解非线性方程组
  #include  <stdio.h>
  #include  <stdlib.h>
  #include  <math.h>
  void n_newton(n, eps, x, f)//拟牛顿法
  int  n;
  double  eps, x[];
  void  (*f)(double [],double []);
  { 
	  int i,j,k=0;
      double am, z, beta, d;
	  double  t=0.1, h=0.1;
	  double  *a, *b, *y;
	  int gauss(int,double [],double []);
	  a = (double *)malloc(n*n*sizeof(double));
	  b = (double *)malloc(n*sizeof(double));
	  y = (double *)malloc(n*sizeof(double));	  
	  am=1.0+eps;
      while (am>=eps)
      { 
          (*f)(x,y);
          am=0.0;
          for (i=0; i<=n-1; i++)
          {
			  b[i] = y[i];
			  z=fabs(y[i]);
              if (z>am) am=z;
          }
          if (am>=eps)
          { 
			  k = k + 1;
              if (k > 500)
              {
				  printf("迭代超过500次,可能不收敛!\n");
                  free(a); free(b); free(y); return;
              }
              for (j=0; j<=n-1; j++)
              { 
				  z=x[j]; x[j]=x[j]+h;
                  (*f)(x,y);
                  for (i=0; i<=n-1; i++) a[i*n+j] = y[i];
                  x[j]=z;
              }
              if (gauss(n,a,b) == 0)
			  {
				  printf("系数矩阵奇异,Gauss消去法失败!\n");
                  free(a); free(b); free(y); return;
              }
              beta=1.0;
              for (i=0; i<=n-1; i++) beta=beta-b[i];
              if (fabs(beta)+1.0==1.0)
              {
				  printf("Beta=0. 程序工作失败！\n");
                  free(a); free(b); free(y); return;
              }
              d=h/beta;
              for (i=0; i<=n-1; i++) x[i]=x[i]-d*b[i];
              h=t*h;
          }
      }
      printf("实际迭代次数为: %d\n",k);
	  free(a); free(b); free(y);
	  return;
  }

  int gauss(int n, double a[], double b[])//全选主元Gauss消去法
  { 
	  int *js, k, i, j, is;
      double d, t;
      js = (int *)malloc(n*sizeof(int));
      for (k=0; k<=n-2; k++)
      { 
		  d=0.0;
          for (i=k;i<=n-1;i++)
          for (j=k;j<=n-1;j++)
          { 
			  t=fabs(a[i*n+j]);
              if (t>d) { d=t; js[k]=j; is=i;}
          }
          if (d+1.0==1.0) { free(js); return(0); }
          if (js[k]!=k)
              for (i=0;i<=n-1;i++)
              { 
                  t=a[i*n+k]; 
				  a[i*n+k]=a[i*n+js[k]]; 
				  a[i*n+js[k]]=t;
              }
              if (is!=k)
              { 
				  for (j=k;j<=n-1;j++)
                  { 
                      t=a[k*n+j]; 
					  a[k*n+j]=a[is*n+j]; 
					  a[is*n+j]=t;
                  }
                  t=b[k]; b[k]=b[is]; b[is]=t;
              }
          d=a[k*n+k];
          for (j=k+1;j<=n-1;j++)  a[k*n+j]=a[k*n+j]/d;
          b[k]=b[k]/d;
          for (i=k+1;i<=n-1;i++)
          { 
			  for (j=k+1;j<=n-1;j++) a[i*n+j]=a[i*n+j]-a[i*n+k]*a[k*n+j];
              b[i]=b[i]-a[i*n+k]*b[k];
          }
      }
      d=a[n*n-1];
      if (fabs(d)+1.0==1.0)  { free(js); return(0); }
      b[n-1]=b[n-1]/d;
      for (i=n-2;i>=0;i--)
      { 
		  t=0.0;
          for (j=i+1;j<=n-1;j++)  t=t+a[i*n+j]*b[j];
          b[i]=b[i]-t;
      }
      js[n-1]=n-1;
      for (k=n-1;k>=0;k--)
        if (js[k]!=k)
        { 	t=b[k]; b[k]=b[js[k]]; b[js[k]]=t;	}
      free(js);  return(1);
  }

  //包含在文件NNEWTON.C中
  main ()
  {
	  int k;
	  double x[3] = {1.0, 1.0, 1.0};
	  void f(double [],double []);
	  n_newton(3, 0.0000001, x, f);
      for (k=0; k<=2; k++)  printf("x(%d)=%f\n",k,x[k]);
	  return;
  }

  void f(double x[], double y[])   //计算方程组各左端函数值
  {
	  y[0] = x[0]*x[0] + x[1]*x[1] + x[2]*x[2] - 1.0;
	  y[1] = 2*x[0]*x[0] + x[1]*x[1] - 4*x[2];
	  y[2] = 3*x[0]*x[0] - 4*x[1] + x[2]*x[2];
  }

