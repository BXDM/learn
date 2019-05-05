  //文件名 EULER.C
  //改进欧拉公式变步长积分一步
  #include <stdlib.h>
  #include <math.h>
  void euler(t,h,y,n,eps,f)
  void  (*f)(double, double [], int, double []);
  int n;
  double t,h,eps,y[];
  { int i,j,m;
    double hh,p,x,q,*a,*b,*c,*d;
    a=malloc(n*sizeof(double));
    b=malloc(n*sizeof(double));
    c=malloc(n*sizeof(double));
    d=malloc(n*sizeof(double));
    hh=h; m=1; p=1.0+eps;
    for (i=0; i<=n-1; i++) a[i]=y[i];
    while (p>=eps)
      { for (i=0; i<=n-1; i++)
          { b[i]=y[i]; y[i]=a[i];}
        for (j=0; j<=m-1; j++)
          { for (i=0; i<=n-1; i++) c[i]=y[i];
            x=t+j*hh;
            (*f)(x,y,n,d);
            for (i=0; i<=n-1; i++)
              y[i]=c[i]+hh*d[i];
            x=t+(j+1)*hh;
            (*f)(x,y,n,d);
            for (i=0; i<=n-1; i++)
              d[i]=c[i]+hh*d[i];
            for (i=0; i<=n-1; i++)
              y[i]=(y[i]+d[i])/2.0;
          }
        p=0.0;
        for (i=0; i<=n-1; i++)
          { q=fabs(y[i]-b[i]);
            if (q>p) p=q;
          }
        hh=hh/2.0; m=m+m;
      }
    free(a); free(b); free(c); free(d);
    return;
  }

  //包含在文件ELR2.C中
  #include <stdio.h>
  main()
  { int i,j;
    double t,h,eps,y[3];
    void  euler_f(double, double [], int, double []);
    y[0]=-1.0; y[1]=0.0; y[2]=1.0;
    t=0.0; h=0.01; eps=0.00001;
    printf("\n");
    printf("t=%5.2f",t);
    for (i=0; i<=2; i++)
      printf("    y(%d)=%10.7f",i,y[i]);
    printf("\n");
    for (j=1; j<=10; j++)
      { euler(t,h,y,3,eps,euler_f);
        t=t+h;
        printf("t=%5.2f",t);
        for (i=0; i<=2; i++)
          printf("    y(%d)=%10.7f",i,y[i]);
        printf("\n");
      }
  }

  void euler_f(t,y,n,d)
  int n;
  double t,y[],d[];
  { t=t; n=n;
    d[0]=y[1]; d[1]=-y[0]; d[2]=-y[2];
    return;
  }

