
  //文件名 GAUSDL.C
  //Gauss-Seidel迭代法求解线性方程组
  #include <math.h>
  #include <stdio.h>
  int gausdl(n,a,b,x,eps)
  int n;
  double a[],b[],x[],eps;
  { int i,j,u,v;
    double p,t,s,q;
    for (i=0; i<=n-1; i++)
      { u=i*n+i; p=0.0; x[i]=0.0;
        for (j=0; j<=n-1; j++)
          if (i!=j)
            { v=i*n+j; p=p+fabs(a[v]);}
        if (p>=fabs(a[u]))
          { printf("fail\n"); return(-1);}
      }
    p=eps+1.0;
    while (p>=eps)
      { p=0.0;
        for (i=0; i<=n-1; i++)
          { t=x[i]; s=0.0;
            for (j=0; j<=n-1; j++)
              if (j!=i) s=s+a[i*n+j]*x[j];
            x[i]=(b[i]-s)/a[i*n+i];
            q=fabs(x[i]-t)/(1.0+fabs(x[i]));
            if (q>p) p=q;
          }
      }
    return(1);
  }

  //包含在文件GAUSDL.C中
  #include <stdio.h>
  main()
  { int i;
    double eps;
    double a[4][4]={ {7.0,2.0,1.0,-2.0},{9.0,15.0,3.0,-2.0},
                          {-2.0,-2.0,11.0,5.0},{1.0,3.0,2.0,13.0}};
    double x[5],b[4]={4.0,7.0,-1.0,0.0};
    eps=0.000001;
    if (gausdl(4,&a[0][0],b,x,eps)>0)
      for (i=0;i<=3; i++)
        printf("x(%d)=%13.7f\n",i,x[i]);
  }

