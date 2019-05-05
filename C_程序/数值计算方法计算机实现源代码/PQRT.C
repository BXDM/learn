  //文件名 PQRT.C
  //方程求根的连分式解法
  #include <math.h>
  double pqrt(x,eps,f)
  double x,eps,(*f)(double);
  { int i,j,m,it,k,flag=0;
    double a[10],y[10],z,h,q;
    k=10; q=1.0e+35; h=0.0;
    while ((flag==0)&&(k!=0))
      { k=k-1; j=0;
        while (j<=7)
           { if (j<=2) z=x+0.1*j;
             else z=h;
             y[j]=(*f)(z);
             h=z;
             if (j==0) a[0]=z;
             else
               { m=0; i=0;
                 while ((m==0)&&(i<=j-1))
                   { if (fabs(h-a[i])+1.0==1.0) m=1;
                     else h=(y[j]-y[i])/(h-a[i]);
                     i=i+1;
                   }
                 a[j]=h;
                 if (m!=0) a[j]=q;
                 h=0.0;
                 for (i=j-1; i>=0; i--)
                   { if (fabs(a[i+1]+h)+1.0==1.0) h=q;
                     else h=-y[i]/(a[i+1]+h);
                   }
                 h=h+a[0];
               }
             if (fabs(y[j])>=eps) j=j+1;
             else { j=10; flag=1;}
           }
         x=h;
       }
     if (k==0)  printf("迭代了10次，可能不收敛！！\n");
     return(h);
   }

  //包含在文件PQRT.C中
  #include <math.h>
  #include <stdio.h>
  main()
  { double x,eps,pqrtf(double);
    int k;
    x=1.0; eps=0.000001;
    x=pqrt(x,eps,pqrtf);
    printf("\n");
    printf("x=%13.7e\n",x);
    printf("\n");
  }

  double pqrtf(x)
  double x;
  { double y;
    y=x*(x*x-1.0)-1.0;
    return(y);
  }

