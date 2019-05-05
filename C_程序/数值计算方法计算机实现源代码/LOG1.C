  //文件名LOG1.C
  //半对数数据拟合
  #include  <math.h>
  #include  <stdio.h>
  void log1(n, x, y, t, d)
  int  n;
  double  t, x[], y[], d[];
  { 
	  int i;
      double yy,sumx,dsumx,sumy,sumxy,s;
      sumx=0.0; sumy=0.0; sumxy=0.0; dsumx=0.0;
      for (i=0; i<=n-1; i++)
      {
		  yy = log(y[i])/log(t);
		  sumx = sumx + x[i]/n;
		  sumy = sumy + yy/n;
		  sumxy = sumxy +x[i]*yy/n;
		  dsumx = dsumx +x[i]*x[i]/n;
      }
      d[0]=(sumxy - sumx*sumy)/(dsumx - sumx*sumx);
	  d[1]=sumy - d[0]*sumx;
      d[2]=0.0; d[6]=0.0; d[4]=0.0; d[5]=1.0e+30;
      for (i=0; i<=n-1; i++)
      { 
		  d[3]=(d[0]*x[i]+d[1])*log(t); d[3]=exp(d[3]);
          d[2]=d[2]+(y[i]-d[3])*(y[i]-d[3]);
          s=fabs(y[i]-d[3]);
          if (s>d[4]) d[4]=s;
          if (s<d[5]) d[5]=s;
          d[6]=d[6]+s/n;
      }
    d[3]=sqrt(d[2]/n);
    return;
  }

  //包含在文件LOG1.C中
  main()
  {
      double t,d[7];
      double x[12]={0.96,0.94,0.92,0.90,0.88,
                    0.86,0.84,0.82,0.80,0.78,0.76,0.74};
      double y[12]={558.0,313.0,174.0,97.0,55.8,
                    31.3,17.4,9.70,5.58,3.13,1.74,1.00};
      t=10;
      log1(12,x,y,t,d);
      printf("a=%f ,   b=%f\n",d[0],d[1]);
      printf("q=%f ,   s=%f\n",d[2],d[3]);
      printf("umax=%f ,  umin=%f ,  u=%f\n",d[4],d[5],d[6]);
  }

