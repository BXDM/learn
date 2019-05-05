  //文件名LAGUER_G.C
  //LAguerre-Gauss求积法
  #include  <math.h>
  #include  <stdio.h>
  double laguerre(f)
  double  (*f)(double);
  { 
	  int i;
      double x,g;
      double t[5]={0.26355990,1.41340290,
            3.59642600,7.08580990,12.64080000};
      double c[5]={0.6790941054,1.638487956,
             2.769426772,4.315944000,7.104896230};
	  g=0.0;
      for (i=0; i<=4; i++)
      { x=t[i]; g=g+c[i]*(*f)(x); }
      return(g);
  }

  //包含在文件LAGUER_G.C中
  main()
  {
	  double  f(double);
      printf("g=%f\n",laguerre(f));
  }

  double f(double x)
  {  return(x*exp(-x)); }

