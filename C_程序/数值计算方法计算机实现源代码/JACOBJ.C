  //文件名JACOBJ.C
  //雅可比过关法求实对称矩阵的全部特征值与特征向量
  #include  <math.h>
  #include  <stdio.h>
  void jacobj(n, a, u, eps)
  int  n;
  double  eps, a[], u[];
  { 
	  int i,j,p,q,v,w,t,s,flag;
      double ff,fm,cn,sn,omega,x,y,d;
      for (i=0; i<=n-1; i++)         //U = I
      { 
		  u[i*n+i]=1.0;
          for (j=0; j<=n-1; j++)
             if (i!=j) u[i*n+j]=0.0;
      }
      ff=0.0;
      for (i=1; i<=n-1; i++)
      for (j=0; j<=i-1; j++)
      { d=a[i*n+j];  ff=ff+d*d; }
      ff=sqrt(2.0*ff);
      ff=ff/(1.0*n);
	  while (1 == 1)
	  {
		  flag = 0;
		  while (flag == 0)
		  {
			  for (i=1; i<=n-1; i++)
              for (j=0; j<=i-1; j++)
			  { 
				  d=fabs(a[i*n+j]);
                  if (d>ff)
				  { p=i; q=j; flag =1; break;}
			  }
              if (flag ==0)
              {
				  if (ff<eps) return;
                  ff=ff/(1.0*n);
			  }
		  }	  
	      v=p*n+q; w=p*n+p; t=q*n+p; s=q*n+q;
          x=-a[v]; y=(a[s]-a[w])/2.0;
          omega=x/sqrt(x*x+y*y);
          if (y<0.0) omega=-omega;
          sn=1.0+sqrt(1.0-omega*omega);
          sn=omega/sqrt(2.0*sn);
          cn=sqrt(1.0-sn*sn);
          fm=a[w];
          a[w]=fm*cn*cn+a[s]*sn*sn+a[v]*omega;
          a[s]=fm*sn*sn+a[s]*cn*cn-a[v]*omega;
          a[v]=0.0; a[t]=0.0;
          for (j=0; j<=n-1; j++)
             if ((j!=p)&&(j!=q))
			 { 
				 v=p*n+j; w=q*n+j;
                 fm=a[v];
                 a[v]=fm*cn+a[w]*sn;
                 a[w]=-fm*sn+a[w]*cn;
			 }
          for (i=0; i<=n-1; i++)
             if ((i!=p)&&(i!=q))
			 { 
			     v=i*n+p; w=i*n+q;
                 fm=a[v];
                 a[v]=fm*cn+a[w]*sn;
                  a[w]=-fm*sn+a[w]*cn;
			 }
          for (i=0; i<=n-1; i++)
		  { 
		      v=i*n+p; w=i*n+q;
              fm=u[v];
              u[v]=fm*cn+u[w]*sn;
              u[w]=-fm*sn+u[w]*cn;
		  }
	  }
	  return;
  }

  //包含在文件JACOBJ.C中
  main()
  { 
	  int i,j;
      double eps;
      double u[5][5];
      double a[5][5]={ {10.0,1.0,2.0,3.0,4.0},
                       {1.0,9.0,-1.0,2.0,-3.0},
                       {2.0,-1.0,7.0,3.0,-5.0},
                       {3.0,2.0,3.0,12.0,-1.0},
                       {4.0,-3.0,-5.0,-1.0,15.0}};
    eps=0.000001;
    jacobj(5,&a[0][0],&u[0][0],eps);
	printf("特征值：\n");
    for (i=0; i<=4; i++)
       printf("%f\n",a[i][i]);
    printf("特征向量：\n");
    for (i=0; i<=4; i++)
      { 
		for (j=0; j<=4; j++)
            printf("%f  ",u[i][j]);
        printf("\n");
      }
  }

