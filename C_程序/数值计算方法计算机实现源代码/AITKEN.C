  //AITKEN.C
  //Aitken迭代法
  #include  <math.h>
  #include  <stdio.h>
  double aitken(x, eps, f)
  double  x, eps, (*f)(double);
  { 
	  int flag = 0, k = 0;
      double u, v;
      while ((flag == 0) && (k <= 100))
      { 
		  k = k + 1; 
          u = (*f)(x);  v = (*f)(u);
          if (fabs(u-v)<eps) { x = v;  flag = 1; }
          else x = v - (v - u)*(v - u)/(v - 2.0*u + x);
      }
	  if (k > 100) printf("迭代超过100次,可能不收敛!\n");
      return(x);
  }

  //包含在文件AITKEN.C中
  main()
  { 
      double x, f(double);
      x = aitken(0.5 ,0.0000001, f);
      printf("x=%f\n", x);
  }

  double f(double x)
  {  return(6.0-x*x); }
