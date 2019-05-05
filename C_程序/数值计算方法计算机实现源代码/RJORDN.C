
  //文件名 RJORDN.C
  //Gauss-Jordan法求解多组常向量的实系数线性方程组
  #include <stdlib.h>
  #include <math.h>
  #include <stdio.h>
  int rjordn(n,a,m,b)
  int n,m;
  double a[],b[];
  { int *js,l,k,i,j,is,p,q;
    double d,t;
    js=malloc(n*sizeof(int));
    l=1;
    for (k=0;k<=n-1;k++)
      { d=0.0;
        for (i=k;i<=n-1;i++)
          for (j=k;j<=n-1;j++)
            { t=fabs(a[i*n+j]);
              if (t>d) { d=t; js[k]=j; is=i;}
            }
        if (d+1.0==1.0) l=0;
        else
          { if (js[k]!=k)
              for (i=0;i<=n-1;i++)
                { p=i*n+k; q=i*n+js[k];
                  t=a[p]; a[p]=a[q]; a[q]=t;
                }
            if (is!=k)
              { for (j=k;j<=n-1;j++)
                  { p=k*n+j; q=is*n+j;
                    t=a[p]; a[p]=a[q]; a[q]=t;
                  }
                for (j=0;j<=m-1;j++)
                  { p=k*m+j; q=is*m+j;
                    t=b[p]; b[p]=b[q]; b[q]=t;
                  }
              }
          }
        if (l==0)
          { free(js); printf("fail\n");
            return(0);
          }
        d=a[k*n+k];
        for (j=k+1;j<=n-1;j++)
          { p=k*n+j; a[p]=a[p]/d;}
        for (j=0;j<=m-1;j++)
          { p=k*m+j; b[p]=b[p]/d;}
        for (j=k+1;j<=n-1;j++)
          for (i=0;i<=n-1;i++)
            { p=i*n+j;
              if (i!=k)
                a[p]=a[p]-a[i*n+k]*a[k*n+j];
            }
        for (j=0;j<=m-1;j++)
        for (i=0;i<=n-1;i++)
          { p=i*m+j;
            if (i!=k)
              b[p]=b[p]-a[i*n+k]*b[k*m+j];
          }
      }
    for (k=n-1;k>=0;k--)
      if (js[k]!=k)
        for (j=0;j<=m-1;j++)
          { p=k*m+j; q=js[k]*m+j;
            t=b[p]; b[p]=b[q]; b[q]=t;
          }
    free(js);
    return(1);
  }

  //包含在文件RJORDN.C中
  #include <stdio.h>
  main()
  { int i;
    double a[4][4]={ {1.0,3.0,2.0,13.0},
                            {7.0,2.0,1.0,-2.0},
                            {9.0,15.0,3.0,-2.0},
                            {-2.0,-2.0,11.0,5.0}};
    double b[4][2]={ {9.0,0.0},{6.0,4.0},
                            {11.0,7.0},{-2.0,-1.0}};
    if (rjordn(4,&a[0][0],2,&b[0][0])!=0)
      for (i=0;i<=3;i++)
        printf("x(%d)=%13.7f,  %13.7f\n",i,b[i][0],b[i][1]);
  }

