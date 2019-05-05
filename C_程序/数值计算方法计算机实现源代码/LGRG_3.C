  //文件名 LGRG_3.C
  //三点插值
  #include "math.h"
  double lagrange_3(x,y,n,t)
  int n;
  double t,x[],y[];
  { int i,j,k,m;
    double z,s;
    z=0.0;
    if (n<1) return(z);
    if (n==1) { z=y[0]; return(z);}
    if (n==2)
      { z=(y[0]*(t-x[1])-y[1]*(t-x[0]))/(x[0]-x[1]);
        return(z);
      }
    if (t<=x[1]) { k=0; m=2;}
    else if (t>=x[n-2]) { k=n-3; m=n-1;}
    else
      { k=1; m=n;
        while (m-k!=1)
          { i=(k+m)/2;
            if (t<x[i-1]) m=i;
            else k=i;
          }
        k=k-1; m=m-1;
        if (fabs(t-x[k])<fabs(t-x[m])) k=k-1;
        else m=m+1;
      }
    z=0.0;
    for (i=k;i<=m;i++)
      { s=1.0;
        for (j=k;j<=m;j++)
          if (j!=i) s=s*(t-x[j])/(x[i]-x[j]);
        z=z+s*y[i];
      }
    return(z);
  }

  //包含在文件LGRG_3.C中
  #include <stdio.h>
  main()
  { double t,z;
    double x[5]={1.615,1.634,1.702,1.828,1.921};
    double y[5]={2.41450,2.46459,2.65271,3.03035,3.34066};
    printf("\n");
    t=1.682; z=lagrange_3(x,y,5,t);
    printf("x=%6.3f,   f(x)=%f\n",t,z);
    t=1.813; z=lagrange_3(x,y,5,t);
    printf("x=%6.3f,   f(x)=%f\n",t,z);
    printf("\n");
  }

