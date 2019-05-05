  //文件名SPIR.C
  //多项式拟合
  #include  <math.h>
  #include  <stdio.h>
  double spir(n, m, x, y, a, dt)
  int n, m;
  double  x[], y[], a[], dt[];
  { 
	  int i,j,k;
      double z,alpha,p,q,g,w,beta,d1,d2,s[20],t[20],b[20];
      z=0.0;
	  for (i=0; i<=n-1; i++)  z=z+x[i]/n;
      for (i=0; i<=m-1; i++) a[i]=0.0;
      if (m>n) m=n;
      if (m>20) m=20;
      b[0]=1.0; d1=n; alpha=0.0; q=0.0;
      for (i=0; i<=n-1; i++) { alpha=alpha+x[i]-z;  q=q+y[i];}
      q=q/d1; 
	  alpha=alpha/d1;
      a[0]=q*b[0];
      if (m>1)
      { 
		  t[1]=1.0; t[0]=-alpha;
          d2=0.0; q=0.0; g=0.0;
          for (i=0; i<=n-1; i++)
          { 
			  w=x[i]-z-alpha; d2=d2+w*w;
              q=q+y[i]*w;
              g=g+(x[i]-z)*w*w;
          }
          q=q/d2; 
		  alpha=g/d2; 
		  beta=d2/d1;
          d1=d2;
          a[1]=q*t[1]; a[0]=q*t[0]+a[0];
      }
      for (j=2; j<=m-1; j++)
      { 
		  s[j]=t[j-1];
          s[j-1]=-alpha*t[j-1]+t[j-2];
          if (j>=3)
          for (k=j-2; k>=1; k--) s[k]=-alpha*t[k]+t[k-1]-beta*b[k];
          s[0]=-alpha*t[0]-beta*b[0];
          d2=0.0; q=0.0; g=0.0;
          for (i=0; i<=n-1; i++)
          { 
			  w=s[j];
              for (k=j-1; k>=0; k--) w=w*(x[i]-z)+s[k];
              d2=d2+w*w; q=q+y[i]*w;
              g=g+(x[i]-z)*w*w;
          }
          q=q/d2; 
		  alpha=g/d2; 
		  beta=d2/d1;
          d1=d2;
          a[j]=q*s[j]; t[j]=s[j];
          for (k=j-1; k>=0; k--)
          { a[k]=q*s[k]+a[k]; b[k]=t[k]; t[k]=s[k]; }
      }
      dt[0]=0.0; dt[1]=0.0; dt[2]=0.0;
      for (i=0; i<=n-1; i++)
      { 
		  w=a[m-1];
          for (k=m-2; k>=0; k--) w=a[k]+w*(x[i]-z);
          p=w-y[i];
          if (fabs(p)>dt[2]) dt[2]=fabs(p);
          dt[0]=dt[0]+p*p;
          dt[1]=dt[1]+fabs(p);
      }
      return(z);
  }

  //包含在文件SPIR.C中
  main()
  { 
	  int i;
      double z, a[3],dt[3];
      double x[6]={4.0,10.6,17.0,33.1,52.2,70.8};
	  double y[6]={1.5,2.0,2.3,2.8,3.2,3.5};
      z=spir(6,3,x,y,a,dt);
	  printf("z=%f\n",z);
      for (i=0; i<=2; i++) printf("a(%2d)=%f\n",i,a[i]);
      for (i=0; i<=2; i++) printf("dt(%2d)=%f  ",i,dt[i]);
      printf("\n");
  }


