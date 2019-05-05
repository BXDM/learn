  //文件名LEGEND_G.C
  //Legendre-Gauss求积法
  #include  <math.h>
  #include  <stdio.h>
  double legendre(a, b, eps, f)
  double  a, b, eps, (*f)(double);
  { 
	  int m,i,j;
      double s,p,ep,h,aa,bb,w,x,g;
      double t[5]={-0.9061798459,-0.5384693101,0.0,
                         0.5384693101,0.9061798459};
      double c[5]={0.2369268851,0.4786286705,0.5688888889,
                        0.4786286705,0.2369268851};
      m=1;
      h=b-a; s=fabs(0.001*h);
      p=1.0e+35; ep=eps+1.0;
      while ((ep>=eps)&&(fabs(h)>s))
      { 
		  g=0.0;
          for (i=1;i<=m;i++)
          { 
			  aa=a+(i-1.0)*h; bb=a+i*h;
              w=0.0;
              for (j=0;j<=4;j++)
              { 
				  x=((bb-aa)*t[j]+(bb+aa))/2.0;
                  w=w+(*f)(x)*c[j];
              }
              g=g+w;
          }
          g=g*h/2.0;
          ep=fabs(g-p)/(1.0+fabs(g));
          p=g; m=m+1; h=(b-a)/m;
      }
      return(g);
  }

  //文件名LEGEND_G.C
  main()
  { 
	  double a,b,eps,g,f(double);
      a=0; b=1; eps=0.0000001;
      g=legendre(a,b,eps,f);
      printf("g=%f\n",g);
  }

  double f(double x)
  {  return(sin(x)/x); }

