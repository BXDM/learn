  //文件名 SNSE.C
  //梯度法求解非线性方程组
  #include  <stdlib.h>
  #include  <math.h>
  #include  <stdio.h>
  int snse(n, x, eps, f)
  int  n;
  double  x[], eps, (*f)(double [],double []);
  { 
	  int k=1000,j;
      double z,d,s,*y;
      y=(double *)malloc(n*sizeof(double));
      z=(*f)(x,y);
      while (z >= eps)
      {
		  k = k - 1;
          if (k == 0) { free(y); return(k);}
          d=0.0;
          for (j=0; j<=n-1; j++) d=d+y[j]*y[j];
          if (d+1.0==1.0) { free(y); return(-1);}
          s=z/d;
          for (j=0; j<=n-1; j++) x[j]=x[j]-s*y[j];
          z=(*f)(x,y);
      }
      free(y); return(k);
  }

  //包含在文件SNSE.C中
  main()
  { 
	  int i;
	  double f(double [], double []);
      double x[3]={1.5,6.5,-5.0};
      i=snse(3,x,0.000001,f);
      if (i>0)
      { 
		  for (i=0; i<=2; i++)  printf("x(%d)=%f\n",i,x[i]);
      }
  }

  double f(double x[], double y[])
  { 
	  double z,f1,f2,f3,df1,df2,df3;
      f1=x[0]-5.0*x[1]*x[1]+7.0*x[2]*x[2]+12.0;
      f2=3.0*x[0]*x[1]+x[0]*x[2]-11.0*x[0];
      f3=2.0*x[1]*x[2]+40.0*x[0];
      z=f1*f1+f2*f2+f3*f3;
      df1=1.0; df2=3.0*x[1]+x[2]-11.0; df3=40.0;
      y[0]=2.0*(f1*df1+f2*df2+f3*df3);
      df1=10.0*x[1]; df2=3.0*x[0]; df3=2.0*x[2];
      y[1]=2.0*(f1*df1+f2*df2+f3*df3);
      df1=14.0*x[2]; df2=x[0]; df3=2.0*x[1];
      y[2]=2.0*(f1*df1+f2*df2+f3*df3);
      return(z);
  }
