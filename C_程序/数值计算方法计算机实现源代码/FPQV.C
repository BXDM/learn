  //文件名 FPQV.C
  //函数连分式的计算
  #include <math.h>
  double fpqv(x,b,n,t)
  int n;
  double x[],b[],t;
  { int k;
    double u;
    u=b[n-1];
    for (k=n-2; k>=0; k--)
      { if (fabs(u)+1.0==1.0)
           u=1.0e+35*(t-x[k])/fabs(t-x[k]);
        else
           u=b[k]+(t-x[k])/u;
      }
    return(u);
  }

  //包含在文件FPQV.C中
  #include <stdio.h>
  main()
  { double x[7]={1.0,2.0,3.0,4.0,5.0,6.0,0.0};
    double b[7]={1.0,3.0,-1.0,2.0,5.0,-8.0,11.0};
    double t;
    printf("\n");
    t=0.0;
    printf(" t=%3.1lf  y=%13.7e\n",t,fpqv(x,b,7,t));
    printf("\n");
    t=3.5;
    printf(" t=%3.1lf  y=%13.7e\n",t,fpqv(x,b,7,t));
    printf("\n");
  }

