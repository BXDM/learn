
  //文件名 LLUU.C
  //LU分解
  #include <stdio.h>
  #include <math.h>
  int lluu(n,a,l,u)
  int n;
  double a[],l[],u[];
  { int i,j,k,w,v,ll;
    for (k=0; k<=n-2; k++)
      { ll=k*n+k;
	if (fabs(a[ll])+1.0==1.0)
          { printf("fail\n"); return(0);}
        for (i=k+1; i<=n-1; i++)
	  { w=i*n+k; a[w]=a[w]/a[ll];}
        for (i=k+1; i<=n-1; i++)
          { w=i*n+k;
            for (j=k+1; j<=n-1; j++)
              { v=i*n+j;
                a[v]=a[v]-a[w]*a[k*n+j];
              }
          }
      }
    for (i=0; i<=n-1; i++)
      { for (j=0; j<i; j++)
          { w=i*n+j; l[w]=a[w]; u[w]=0.0;}
        w=i*n+i;
        l[w]=1.0; u[w]=a[w];
        for (j=i+1; j<=n-1; j++)
          { w=i*n+j; l[w]=0.0; u[w]=a[w];}
      }
    return(1);
  }

  //包含在文件LLUU.C中
  #include <stdio.h>
  main()
  { int i,j;
    double l[4][4],u[4][4];
    double a[4][4]={ {2.0,4.0,4.0,2.0},
                            {3.0,3.0,12.0,6.0},
                            {2.0,4.0,-1.0,2.0},
                            {4.0,2.0,1.0,1.0}};
    i=lluu(4,&a[0][0],&l[0][0],&u[0][0]);
    if (i!=0)
      { printf("MAT L IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7f ",l[i][j]);
            printf("\n");
          }
        printf("\n");
        printf("MAT U IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7f ",u[i][j]);
            printf("\n");
          }
        printf("\n");
      }
  }

