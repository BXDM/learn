  //文件名 HHBG.C
  //初等相似变换将一般实矩阵约化为上H矩阵
  #include  <math.h>
  #include  <stdio.h>
  void hhbg(n, a) 
  int  n;
  double  a[];
  { 
	  int i,j,k,u,v;
      double d,t;
      for (k=1; k<=n-2; k++)
      { 
		  d=0.0;
          for (j=k; j<=n-1; j++)
          { 
			  t=a[j*n+k-1];
              if (fabs(t)>fabs(d))
              { d=t; i=j; }
          }
        if (fabs(d)+1.0 != 1.0)
          { 
			  if (i != k)
              { 
				  for (j=k-1; j<=n-1; j++)
                  { 
					  u=i*n+j; v=k*n+j;
                      t=a[u]; a[u]=a[v]; a[v]=t;
                  }
                for (j=0; j<=n-1; j++)
                  { 
					  u=j*n+i; v=j*n+k;
                      t=a[u]; a[u]=a[v]; a[v]=t;
                  }
              }
              for (i=k+1; i<=n-1; i++)
              { 
				  u=i*n+k-1; t=a[u]/d; a[u]=0.0;
                  for (j=k; j<=n-1; j++)
                  { 
					  v=i*n+j;
                      a[v]=a[v]-t*a[k*n+j];
                  }
                  for (j=0; j<=n-1; j++)
                  { 
					  v=j*n+k;
                      a[v]=a[v]+t*a[j*n+i];
                  }
              }
          }
      }
      return;
  }

  //包含在文件HHBG.C中
  //双重步QR方法求一般实矩阵全部特征值
  int hhqr(n, a, u, v, eps)
  int  n;
  double  eps, a[], u[], v[];
  { 
	  int m,it,i,j,k,t;
      double b,c,d,g,xy,p,q,r,x,s,e,f,z,y;
      it=0; m=n;
      while (m!=0)
      { 
		  t=m-1;
          while ((t>0)&&(fabs(a[t*n+t-1])>eps*
	      (fabs(a[(t-1)*n+t-1])+fabs(a[t*n+t])))) t=t-1;
          if (t==m-1)            //一阶块处理
          { 
			  u[m-1]=a[(m-1)*n+m-1]; v[m-1]=0.0;
              m=m-1; it=0;
          }
          else if (t==m-2)       //二阶块处理
          {			  
			  b=-(a[(m-1)*n+m-1]+a[(m-2)*n+m-2]);
              c=a[(m-1)*n+m-1]*a[(m-2)*n+m-2]-a[(m-1)*n+m-2]*a[(m-2)*n+m-1];
              d=b*b-4.0*c;
              y=sqrt(fabs(d));
              if (d>0.0)         //两个单实特征值
              { 
				  xy=1.0;
                  if (b<0.0) xy=-1.0;
                  u[m-1]=(-b-xy*y)/2.0;  v[m-1]=0.0; 
                  u[m-2]=c/u[m-1];  v[m-2]=0.0;
              }
              else               //两个复特征值
              { 
				  u[m-1]=-b/2.0; u[m-2]=u[m-1];
                  v[m-1]=y/2.0; v[m-2]=-v[m-1];
              }
              m=m-2; it=0;
          }
          else           //进行新的一次QR迭代
          { 
			  if (it>100)            //迭代超过100次
              { printf("fail\n"); return(0); }
              it=it+1;
              for (j=t+2; j<=m-1; j++)  a[j*n+j-2]=0.0;
              for (j=t+3; j<=m-1; j++)  a[j*n+j-3]=0.0;
              for (k=t; k<=m-2; k++)
              { 
				  if (k!=t)           //计算pi,qi,ri
                  { 
					  p=a[k*n+k-1]; q=a[(k+1)*n+k-1];  r=0.0;
                      if (k!=m-2)  r=a[(k+2)*n+k-1];
                  }
                  else               //计算p0,q0,r0
                  {
					  b = a[(m-1)*n+m-1];  c = a[(m-2)*n+m-2];
					  x = b + c;
                      y=c*b - a[(m-2)*n+m-1]*a[(m-1)*n+m-2];
                      p=a[t*n+t]*(a[t*n+t]-x)+a[t*n+t+1]*a[(t+1)*n+t]+y;
                      q=a[(t+1)*n+t]*(a[t*n+t]+a[(t+1)*n+t+1]-x);
                      r=a[(t+1)*n+t]*a[(t+2)*n+t+1];
                  }
                  if ((fabs(p)+fabs(q)+fabs(r))!=0.0)
                  { 
					  xy=1.0;
                      if (p<0.0) xy=-1.0;
                      s=xy*sqrt(p*p+q*q+r*r);     //计算Q中的各元素
                      if (k!=t) a[k*n+k-1]=-s;
                      e=-q/s; f=-r/s; x=-p/s;
                      y=-x-f*r/(p+s);
                      g=e*r/(p+s);
                      z=-x-e*q/(p+s);
                      for (j=k; j<=m-1; j++)     //计算QA
                      { 
                          b = a[k*n+j];  c = a[(k+1)*n+j];
                          p = x*b + e*c;  q = e*b + y*c;  r = f*b + g*c;
                          if (k!=m-2)
                          { 
                              b = a[(k+2)*n+j];
                              p = p + f*b;  q = q + g*b;  r = r + z*b; 
							  a[(k+2)*n+j]=r;
                          }
                          a[(k+1)*n+j]=q; a[k*n+j]=p;
                      }
                      j=k+3;
                      if (j>=m-1) j=m-1;
                      for (i=t; i<=j; i++)       //计算[QA]Q
                      { 	
                          b = a[i*n+k];  c = a[i*n+k+1];
                          p = x*b + e*c; q = e*b + y*c;  r = f*b + g*c;
                          if (k!=m-2)
                          { 
                              b = a[i*n+k+2];
                              p = p + f*b; q = q + g*b;  r = r + z*b; 
							  a[i*n+k+2]=r;
                          }
                          a[i*n+k+1]=q; a[i*n+k]=p;
                      }
                  }
              }
          }
      }
      return(1);
  }

  //包含在文件HHBG.C中
  main()
  { 
	  int i,j;
      double u[5],v[5];
      double a[5][5]={ {1.0,6.0,-3.0,-1.0,7.0},
	  {8.0,-15.0,18.0,5.0,4.0},{-2.0,11.0,9.0,15.0,20.0},
	  {-13.0,2.0,21.0,30.0,-6.0},{17.0,22.0,-5.0,3.0,6.0}};
      hhbg(5,&a[0][0]);         //初等相似变换
      printf("上H矩阵:\n");
      for (i=0; i<=4; i++)
      { 
		  for (j=0; j<=4; j++)  printf("%f  ",a[i][j]);
          printf("\n");
      }
      i=hhqr(5, &a[0][0] ,u, v, 0.000001);     //QR方法
	  printf("特征值:\n");
      if (i>0)
         for (i=0; i<=4; i++) printf("%f +J %f\n",u[i],v[i]);
  }
