  //文件名HERMIT_G.C
  //Hermite-Gauss求积法
  #include  <math.h>
  #include  <stdio.h>
  double hermite(f)
  double (*f)(double);
  { 
	  int i;
      double x,g;
      double t[5]={-2.02018200,-0.95857190,
		           0.0,0.95857190,2.02018200};
      double c[5]={1.181469599,0.9865791417,
           0.9453089237,0.9865791417,1.181469599};	  	  
	  g=0.0;
      for (i=0; i<=4; i++)
      { x=t[i]; g=g+c[i]*(*f)(x); }
      return(g);
  }

  //包含在文件HERMIT_G.C中
  main()
  { 
	  double  f(double);
      printf("g=%f\n",hermite(f));
  }

  double f(double x)
  {  return(x*x*exp(-x*x)); }

