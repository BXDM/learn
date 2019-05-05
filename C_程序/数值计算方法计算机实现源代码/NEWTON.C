  //文件名 NEWTON.C
  //Newton迭代法求方程一个实根
  #include  <stdio.h>
  #include  <math.h>
  double newton(x, eps, f, df)
  double  x, eps, (*f)(double), (*df)(double);
  { 
	  int k=0;
      double y,dy,d,p,x1;
      y = (*f)(x);  dy = (*df)(x);
      d=eps+1.0;
      while ((d >= eps)&&(k <= 100))
      { 
		  if (fabs(dy)+1.0 == 1.0)
          { printf("f(x)的导数为0! err\n"); return(0);}
          x1 = x-y/dy;
          y = (*f)(x1);  dy = (*df)(x1);
          d=fabs(x1-x); p=fabs(y);
          if (p>d) d=p;
          x = x1; k = k + 1;
      }
    if (k > 100) printf("迭代超过100次,可能不收敛!\n");
    return(x);
  }

  //包含在文件NEWTON.C中
  main()
  { 
      double x;
      double f(double), df(double);
      x = newton(1.5, 0.000001, f, df);
      printf("x=%f\n", x);
  }

  double f(double x)
  { return(x*x*(x-1.0)-1.0); }

  double df(double x)
  { return(3.0*x*x-2.0*x); }
