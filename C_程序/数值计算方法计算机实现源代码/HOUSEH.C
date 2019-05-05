    //HOUSEH.C
    //用Householder变换将对称矩阵约化成三对角矩阵
    #include  <stdio.h>
    #include  <math.h>
    #include  <stdlib.h>
	void househ(n, a)
    int  n;
	double  a[];
	{
		int i, j, k, m;
		double s, d, *w, *b, *c;
		w = (double *)malloc(n*sizeof(double));
		b = (double *)malloc(n*n*sizeof(double));
		c = (double *)malloc(n*n*sizeof(double));
        for (k=0; k<(n-2); k++)
		{
			s = 0.0;
		    for (i=(k+1); i<n; i++)
			{ d = a[k*n+i];  s = s + d*d; }
		    s = sqrt(s);
			if ( s + 1.0 != 1.0 )
			{
				for (i=0; i<n; i++)  w[i] = 0.0; 
				w[k+1] = sqrt(0.5*(1+fabs(a[k*n+k+1])/s));
				for (i=(k+2); i<n; i++)
				{ 
					w[i] = (a[k*n+i]/(2*s*w[k+1])); 
					if (a[k*n+k+1] < 0)  w[i] = -w[i];
				}
				for (i=0; i<n; i++)
				for (j=0; j<n; j++)
                {
					if (i == j)  b[i*n+j] = 1.0 - 2*w[i]*w[j];
					else b[i*n+j] = -2*w[i]*w[j];
				}
				for (i=0; i<n; i++)      //AB
				for (j=0; j<n; j++)
                {
					c[i*n+j] = 0.0;
					for (m=0; m<n; m++)
					{ c[i*n+j] += a[i*n+m]*b[m*n+j]; }
				}
				for (i=0; i<n; i++)    //BAB
				for (j=0; j<n; j++)
				{
					a[i*n+j] = 0.0;
					for (m=0; m<n; m++)
					{ a[i*n+j] += b[i*n+m]*c[m*n+j]; }
				}
			}
		}
		free(w); free(b); free(c);
        return;
	}

  //包含在文件HOUSEH.C中
  //QR方法求对称三对角矩阵的特征值
  int trid_qr(n, a, eps)
  int  n;
  double  eps, a[];
  { 
	  int i,j,m,it;
      double d,f,h,g,p,r,e,s;
      d=0.0; f=0.0;
      for (j=0; j<=n-1; j++)
      { 
		  it=0;
          h=eps*(fabs(a[j*n+j])+fabs(a[j*n+j+1]));
          if (h>d) d=h;
          m=j;
          while ((m<=n-1)&&(fabs(a[m*n+m+1])>d)) m=m+1;
          if (m!=j)
          { 
			  do
              { 
				  if (it==1000)
                  {   printf("fail\n");  return(0); }
                  it=it+1;
                  g=a[j*n+j];
                  p=(a[(j+1)*n+j+1]-g)/(2.0*a[j*n+j+1]);
                  r=sqrt(p*p+1.0);
                  if (p>=0.0) a[j*n+j]=a[j*n+j+1]/(p+r);
                  else a[j*n+j]=a[j*n+j+1]/(p-r);
                  h=g-a[j*n+j];
                  for (i=j+1; i<=n-1; i++)  a[i*n+i]=a[i*n+i]-h;
                  f=f+h; p=a[m*n+m]; e=1.0; s=0.0;
                  for (i=m-1; i>=j; i--)
                  { 
					  g=e*a[i*n+i+1]; h=e*p;
                      if (fabs(p)>=fabs(a[i*n+i+1]))
                      { 
						  e=a[i*n+i+1]/p; r=sqrt(e*e+1.0);
                          a[(i+1)*n+i+2]=s*p*r; s=e/r; e=1.0/r;
                      }
                      else
					  { 
						  e=p/a[i*n+i+1]; r=sqrt(e*e+1.0);
                          a[(i+1)*n+i+2]=s*a[i*n+i+1]*r;
                          s=1.0/r; e=e/r;
                      }
                      p=e*a[i*n+i]-s*g;
                      a[(i+1)*n+i+1]=h+s*(e*g+s*a[i*n+i]);
                  }
                  a[j*n+j+1]=s*p; a[j*n+j]=e*p;
              }
              while (fabs(a[j*n+j+1])>d);
          }
          a[j*n+j]=a[j*n+j]+f;
	  }
	  for (i=1; i<n; i++)  a[i*n+i-1] = 0.0;
      return(1);
  }

    //包含在文件HOUSEH.C中
	main()
	{
	  int i,j;
      double a[5][5]={ {10,1,2,3,4},{1,9,-1,2,-3},
	  {2,-1,7,3,-5},{3,2,3,12,-1},{4,-3,-5,-1,15}};
      printf("实对称矩阵:\n");
      for (i=0; i<=4; i++)
      { 
		  for (j=0; j<=4; j++)  printf("%f  ",a[i][j]);
          printf("\n");
      }
      househ(5, &a[0][0]);
      printf("对称三对角矩阵:\n");
      for (i=0; i<=4; i++)
      { 
		  for (j=0; j<=4; j++)  printf("%f  ",a[i][j]);
          printf("\n");
      }
	  trid_qr(5,&a[0][0],0.000001);
      printf("特征值:\n");
      for (i=0; i<=4; i++)  printf("%f\n",a[i][i]);
	}


