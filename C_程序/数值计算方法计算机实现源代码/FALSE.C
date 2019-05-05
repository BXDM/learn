  //文件名FALSE.C
  //试位法求方程实根
  #include  <math.h>
  #include  <stdio.h>
  double false_pos(a, b, eps, f)
  double  a, b, eps, (*f)(double);
  {
      int  flag = 1;
      double fa, fb, y, x;
	  fa = (*f)(a);  fb = (*f)(b);
	  if (fa*fb > 0)
	  { printf("区间内可能无根！\n");  return(0); }
	  do
	  {
		  x = (a*fb - b*fa)/(fb - fa);
		  y = (*f)(x);
		  if (fabs(y) < eps)  flag = 0;
		  if (y*fa > 0)  { a = x; fa = y; }
		  else  { b = x; fb = y; }
	  } while (flag);
      return(x);
  }

  //包含在文件FALSE.C中
  main()
  { 
	  double x;
      double f(double);
      x=false_pos(2.0, 3.0, 0.000001, f);
      printf("x=%f\n",x);
  }

  double f(double x)
  { 
	  double z;
      z=exp(x*log(x))-10;
      return(z);
  }
