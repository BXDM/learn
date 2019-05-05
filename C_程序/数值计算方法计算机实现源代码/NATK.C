  //文件名 NATK.C
  //Aitken插值
  #include <math.h>
  double natk(x,y,n,t,eps)
  int n;
  double t,eps,x[],y[];
  { int i,j,k,m,l;
    double z,xx[10],yy[10];
    z=0.0;
    if (n<1) return(z);
    if (n==1) { z=y[0]; return(z);}
    m=10;
    if (m>n) m=n;
    if (t<=x[0]) k=1;
    else if (t>=x[n-1]) k=n;
    else
      { k=1; j=n;
        while ((k-j!=1)&&(k-j!=-1))
          { l=(k+j)/2;
            if (t<x[l-1]) j=l;
            else k=l;
          }
        if (fabs(t-x[l-1])>fabs(t-x[j-1])) k=j;
      }
    j=1; l=0;
    for (i=1;i<=m;i++)
      { k=k+j*l;
        if ((k<1)||(k>n))
          { l=l+1; j=-j; k=k+j*l;}
        xx[i-1]=x[k-1]; yy[i-1]=y[k-1];
        l=l+1; j=-j;
      }
    i=0;
    do
      { i=i+1; z=yy[i];
        for (j=0;j<=i-1;j++)
          z=yy[j]+(t-xx[j])*(yy[j]-z)/(xx[j]-xx[i]);
        yy[i]=z;
      }
    while ((i!=m-1)&&(fabs(yy[i]-yy[i-1])>eps));
    return(z);
  }

  //包含在文件NATK.C中
  #include <stdio.h>
  main()
  { double t,z,eps;
    double x[11]={-1.0,-0.8,-0.65,-0.4,-0.3,
                         0.0,0.2,0.4,0.6,0.8,1.0};
    double y[11]={0.0384615,0.0588236,0.0864865,0.2,
            0.307692,1.0,0.5,0.2,0.1,0.0588236,0.0384615};
    eps=1.0e-6;
    printf("\n");
    t=-0.75; z=natk(x,y,11,t,eps);
    printf("t=%6.3f,   z=%f\n",t,z);
    t=0.05; z=natk(x,y,11,t,eps);
    printf("t=%6.3f,   z=%f\n",t,z);
    printf("\n");
  }

