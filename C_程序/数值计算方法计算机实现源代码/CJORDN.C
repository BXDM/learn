
  //文件名 CJORDN.C
  //Gauss-Jordan法求解多组常向量的复系数线性方程组
  #include <stdlib.h>
  #include <stdio.h>
  int cjordn(n,ar,ai,m,br,bi)
  int n,m;
  double ar[],ai[],br[],bi[];
  { int *js,l,k,i,j,is,u,v;
    double p,q,s,d;
    js=malloc(n*sizeof(int));
    for (k=0;k<=n-1;k++)
      { d=0.0;
        for (i=k;i<=n-1;i++)
        for (j=k;j<=n-1;j++)
          { u=i*n+j;
            p=ar[u]*ar[u]+ai[u]*ai[u];
            if (p>d) {d=p;js[k]=j;is=i;}
          }
        if (d+1.0==1.0)
          { free(js); printf("err**fail\n");
            return(0);
          }
        if (is!=k)
          { for (j=k;j<=n-1;j++)
              { u=k*n+j; v=is*n+j;
                p=ar[u]; ar[u]=ar[v]; ar[v]=p;
                p=ai[u]; ai[u]=ai[v]; ai[v]=p;
              }
            for (j=0;j<=m-1;j++)
              { u=k*m+j; v=is*m+j;
                p=br[u]; br[u]=br[v]; br[v]=p;
                p=bi[u]; bi[u]=bi[v]; bi[v]=p;
              }
          }
        if (js[k]!=k)
          for (i=0;i<=n-1;i++)
            { u=i*n+k; v=i*n+js[k];
              p=ar[u]; ar[u]=ar[v]; ar[v]=p;
              p=ai[u]; ai[u]=ai[v]; ai[v]=p;
            }
        v=k*n+k;
        for (j=k+1;j<=n-1;j++)
          { u=k*n+j;
            p=ar[u]*ar[v]; q=-ai[u]*ai[v];
            s=(ar[v]-ai[v])*(ar[u]+ai[u]);
            ar[u]=(p-q)/d; ai[u]=(s-p-q)/d;
          }
        for (j=0;j<=m-1;j++)
          { u=k*m+j;
            p=br[u]*ar[v]; q=-bi[u]*ai[v];
            s=(ar[v]-ai[v])*(br[u]+bi[u]);
            br[u]=(p-q)/d; bi[u]=(s-p-q)/d;
          }
        for (i=0;i<=n-1;i++)
          if (i!=k)
            { u=i*n+k;
              for (j=k+1;j<=n-1;j++)
                { v=k*n+j; l=i*n+j;
                  p=ar[u]*ar[v]; q=ai[u]*ai[v];
                  s=(ar[u]+ai[u])*(ar[v]+ai[v]);
                  ar[l]=ar[l]-p+q;
                  ai[l]=ai[l]-s+p+q;
                }
              for (j=0;j<=m-1;j++)
                { l=i*m+j; v=k*m+j;
                  p=ar[u]*br[v]; q=ai[u]*bi[v];
                  s=(ar[u]+ai[u])*(br[v]+bi[v]);
                  br[l]=br[l]-p+q; bi[l]=bi[l]-s+p+q;
                }
            }
      }
    for (k=n-1;k>=0;k--)
      if (js[k]!=k)
        for (j=0;j<=m-1;j++)
          { u=k*m+j;v=js[k]*m+j;
            p=br[u]; br[u]=br[v]; br[v]=p;
            p=bi[u]; bi[u]=bi[v]; bi[v]=p;
          }
    free(js);
    return(1);
  }

  //包含在文件CJORDN.C中
  #include <stdio.h>
  main()
  { int i;
    double ar[4][4]={ {1.0,3.0,2.0,13.0},
                             {7.0,2.0,1.0,-2.0},
                             {9.0,15.0,3.0,-2.0},
                             {-2.0,-2.0,11.0,5.0}};
    double ai[4][4]={ {3.0,-2.0,1.0,6.0},
                             {-2.0,7.0,5.0,8.0},
                             {9.0,-3.0,15.0,1.0},
                             {-2.0,-2.0,7.0,6.0}};
    double br[4][2]={ {2.0,-2.0},{7.0,3.0},
                             {3.0,2.0},{9.0,1.0}};
    double bi[4][2]={ {1.0,3.0},{2.0,7.0},
                             {-2.0,9.0},{3.0,2.0}};
    if (cjordn(4,&ar[0][0],&ai[0][0],2,&br[0][0],&bi[0][0])!=0)
      for (i=0;i<=3;i++)
        printf("x(%d)=%13.7f +j %13.7f,   %13.7f +j %13.7f\n",
               i,br[i][0],bi[i][0],br[i][1],bi[i][1]);
  }

