  //文件名BOUND.C
  //差分法求解二阶微分方程边值问题
  #include  <stdlib.h>
  #include  <stdio.h>
  void bound(int n,double t0,double tn,double y[],
	                  void (*f)(double,double *,double *,double *))
  { 
	  int k;
	  double x, h, p, q, r, *a, *b, *c;
	  void trid(int,double [],double [],double [],double []);
      a = (double *)malloc((n+1)*sizeof(double));
      b = (double *)malloc((n+1)*sizeof(double));
      c = (double *)malloc((n+1)*sizeof(double));
	  h = (tn -t0)/n;
	  a[0] = 0; b[0] = 1; c[0] = 0; 
      for (k=1; k<=n-1; k++)     //构造三对角方程组
	  {
		  x = t0 + k*h;
		  (*f)(x,&p, &q, &r);
		  c[k] = h*p/2;
		  a[k] = 1 - c[k];
		  c[k] = 1 + c[k];
		  b[k] = -2 +h*h*q;
		  y[k] = h*h*r;
	  }
      a[n] = 0; b[n] = 1; c[n] = 0;
      trid(n+1, a, b, c, y);   //求解三对角方程组
      free(a); free(b); free(c);
      return;
  }

  //“追赶”法求解三对角方程组
  void trid(int n,double a[],double b[],double c[],double d[])
  { 
	  int k;
      for (k=0;k<=n-2;k++)
      { 
		  c[k] = c[k]/b[k];
		  d[k] = d[k]/b[k];
		  b[k+1] = b[k+1] - a[k+1]*c[k];
		  d[k+1] = d[k+1] - a[k+1]*d[k];
      }
      d[n-1]=d[n-1]/b[n-1];
      for (k=n-2;k>=0;k--) d[k]=d[k]-c[k]*d[k+1];
      return;
  }

  //包含在文件BOUND.C中
  main()
  { 
	  int k;
	  double y[11];
	  void f(double, double *, double *,double *);
	  y[0] = 1.0; y[10] = 2.0;
	  bound(10, 0.0, 1.0, y, f);
	  for (k=0; k<11; k++)
		  printf("x = %f     y = %f\n", k*0.1, y[k]);
  }

  void f(double t, double *p, double *q, double *r)
  {
	  *p = -t/(1+t*t);
	  *q = -3/(1+t*t);
	  *r = (6*t-3)/(1+t*t);
	  return;
  }

