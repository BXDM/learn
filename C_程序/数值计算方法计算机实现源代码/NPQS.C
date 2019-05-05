  //文件名 NPQS.C
  //构造连分式插值函数
  #include <math.h>
  double npqs(x,y,n,t)
  int n;
  double t,x[],y[];
  { int i,j,k,m,l;
    double z,h,b[8];
    z=0.0;
    if (n<1) return(z);
    if (n==1) { z=y[0]; return(z);}
    if (n<=8) { k=0; m=n;}
    else if (t<x[4]) { k=0; m=8;}
    else if (t>x[n-5]) { k=n-8; m=8;}
    else
      { k=1; j=n;
        while (j-k!=1)
          { i=(k+j)/2;
            if (t<x[i-1]) j=i;
            else k=i;
          }
        k=k-4; m=8;
      }
    b[0]=y[k];
    for (i=2;i<=m;i++)
      { h=y[i+k-1]; l=0; j=1;
        while ((l==0)&&(j<=i-1))
            { if (fabs(h-b[j-1])+1.0==1.0) l=1;
              else h=(x[i+k-1]-x[j+k-1])/(h-b[j-1]);
              j=j+1;
            }
        b[i-1]=h;
        if (l!=0) b[i-1]=1.0e+35;
      }
    z=b[m-1];
    for (i=m-1;i>=1;i--) z=b[i-1]+(t-x[i+k-1])/z;
    return(z);
  }

  //包含在文件NPQS.C中
  #include <stdio.h>
  main()
  { double t,z;
    double x[10]={-1.0,-0.8,-0.65,-0.4,-0.3,
                         0.0,0.2,0.45,0.8,1.0};
    double y[10]={0.0384615,0.0588236,0.0864865,0.2,0.307692,
                         1.0,0.5,0.164948,0.0588236,0.0384615};
    printf("\n");
    t=-0.85; z=npqs(x,y,10,t);
    printf("t=%6.3f,   z=%e\n",t,z);
    t=0.25; z=npqs(x,y,10,t);
    printf("t=%6.3f,   z=%e\n",t,z);
    printf("\n");
  }

