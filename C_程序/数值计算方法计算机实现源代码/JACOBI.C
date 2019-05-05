  //文件名 JACOBI.C
  //雅可比方法求实对称矩阵全部特征值与特征向量
  #include  <math.h>
  #include  <stdio.h>
  int jacobi(n, a, u, eps)
  int  n;
  double  eps, a[], u[];
  { 
	  int i,j,p,q,v,w,t,s,jt;
      double fm,cn,sn,omega,x,y,d;
      jt=1;
      for (i=0; i<=n-1; i++)        //u = I
      { 
		  u[i*n+i]=1.0;
          for (j=0; j<=n-1; j++)
          if (i!=j) u[i*n+j]=0.0;
      }
      while (1==1)
	  { 
		  fm=0.0;
          for (i=1; i<=n-1; i++)
          for (j=0; j<=i-1; j++)
          { 
			  d=fabs(a[i*n+j]);
              if ((i!=j)&&(d>fm))
              { fm=d; p=i; q=j;}
          }
          if (fm<eps)  return(jt);
          if (jt>1000)  return(jt);
          jt = jt + 1;
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
      return(jt);
  }

  //包含在文件JACOBI.C中
  main()
  { 
	  int i,j;
      double eps;
      double u[3][3];
      double a[3][3]={ {2.0,-1.0,0.0},{-1.0,2.0,-1.0},{0.0,-1.0,2.0}};
      eps=0.000001;
      i=jacobi(3,&a[0][0],&u[0][0],eps);
      if (i<1000)
      {
		  printf("迭代次数 = %d\n",i);
		  printf("特征值：\n");
		  for (i=0; i<=2; i++)
              printf("%f  ",a[i][i]);   //输出特征值
          printf("\n特征向量\n");
          for (i=0; i<=2; i++)          //输出特征向量
          { 
			  for (j=0; j<=2; j++)
                 printf("%f  ",u[i][j]);
              printf("\n");
          }
          printf("\n");
	  }
  }


