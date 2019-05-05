
  //文件名 GRAD.C
  //共轭剃度法
  #include <math.h>
  #include <stdlib.h>
  #include <stdio.h>
  void grad(n,a,b,eps,x)
  int n;
  double a[],b[],x[],eps;
  { int i,j,k;
    double *p,*r,*s,*q,alpha,beta,d,e;
    p=malloc(n*sizeof(double));
    r=malloc(n*sizeof(double));
    s=malloc(n*sizeof(double));
    q=malloc(n*sizeof(double));
    for (i=0; i<=n-1; i++)
      { x[i]=0.0; p[i]=b[i]; r[i]=b[i]; }
    i=0;
    while (i<=n-1)
      { for (k=0; k<=n-1; k++)
          { s[k]=0.0;
            for (j=0; j<=n-1; j++)
              s[k]=s[k]+a[k*n+j]*p[j];
          }
        d=0.0; e=0.0;
        for (k=0; k<=n-1; k++)
           { d=d+p[k]*b[k]; e=e+p[k]*s[k]; }
        alpha=d/e;
        for (k=0; k<=n-1; k++)
           x[k]=x[k]+alpha*p[k];
        for (k=0; k<=n-1; k++)
          { q[k]=0.0;
            for (j=0; j<=n-1; j++)
              q[k]=q[k]+a[k*n+j]*x[j];
          }
        d=0.0;
        for (k=0; k<=n-1; k++)
          { r[k]=b[k]-q[k]; d=d+r[k]*s[k]; }
        beta=d/e; d=0.0;
        for (k=0; k<=n-1; k++) d=d+r[k]*r[k];
        d=sqrt(d);
        if (d<eps) 
          { free(p); free(r); free(s); free(q);return;}
        for (k=0; k<=n-1; k++)
           p[k]=r[k]-beta*p[k];
        i=i+1;
      }
    free(p); free(r); free(s); free(q);
    return;
  }

  //包含在文件GRAD.C中
  #include <stdio.h>
  main()
  { int i;
    double eps,x[4];
    double a[4][4]={{5.0,7.0,6.0,5.0},
                           {7.0,10.0,8.0,7.0},
                           {6.0,8.0,10.0,9.0},
                           {5.0,7.0,9.0,10.0}};
    double b[4]={23.0,32.0,33.0,31.0};
    eps=0.000001;
    grad(4,&a[0][0],b,eps,x);
    printf("\n");
    for (i=0; i<=3; i++)
       printf("x[%d]=%f\n",i,x[i]);
    printf("\n");
  }

