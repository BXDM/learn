  //文件名 PART.C
  //分部积分法计算高振荡积分
  #include <math.h>
  void part(a,b,m,n,fa,fb,s)
  int m,n;
  double a,b,fa[],fb[],s[];
  { int mm,k,j;
    double sa[4],sb[4],ca[4],cb[4],sma,smb,cma,cmb;
    sma=sin(m*a); smb=sin(m*b);
    cma=cos(m*a); cmb=cos(m*b);
    sa[0]=sma; sa[1]=cma; sa[2]=-sma; sa[3]=-cma;
    sb[0]=smb; sb[1]=cmb; sb[2]=-smb; sb[3]=-cmb;
    ca[0]=cma; ca[1]=-sma; ca[2]=-cma; ca[3]=sma;
    cb[0]=cmb; cb[1]=-smb; cb[2]=-cmb; cb[3]=smb;
    s[0]=0.0; s[1]=0.0;
    mm=1;
    for (k=0;k<=n-1;k++)
      { j=k;
        while (j>=4) j=j-4;
        mm=mm*m;
        s[0]=s[0]+(fb[k]*sb[j]-fa[k]*sa[j])/(1.0*mm);
        s[1]=s[1]+(fb[k]*cb[j]-fa[k]*ca[j])/(1.0*mm);
      }
    s[1]=-s[1];
    return;
  }

  //包含在文件PART.C中
  #include <stdio.h>
  main()
  { int n,m;
    double a,b;
    double s[2],fa[4]={0.0,1.0,0.0,-3.0};
    double fb[4]={6.2831852,1.0,-6.2831852,-3.0};
    a=0.0; b=6.2831852;
    m=30; n=4;
    part(a,b,m,n,fa,fb,s);
    printf("\n");
    printf("s(0)=%e ,   s(1)=%e\n",s[0],s[1]);
    printf("\n");
  }

