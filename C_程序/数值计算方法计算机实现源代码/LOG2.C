  //文件名LOG2.C
  //对数数据拟合
  #include  <math.h>
  #include  <stdio.h>
  void log2(n, x, y, d)
  int  n;
  double  x[], y[], d[];
  { 
	  int i;
      double xx,yy,sumx,dsumx,sumy,sumxy,s;
      sumx=0.0; sumy=0.0; sumxy=0.0; dsumx=0.0;
      for (i=0; i<=n-1; i++)
      {
		  xx = log(x[i]);
		  yy = log(y[i]);
		  sumx = sumx + xx/n;
		  sumy = sumy + yy/n;
		  sumxy = sumxy +xx*yy/n;
		  dsumx = dsumx +xx*xx/n;
      }
      d[0]=(sumxy - sumx*sumy)/(dsumx - sumx*sumx);
	  d[1]=sumy - d[0]*sumx; d[1] = exp(d[1]);
      d[2]=0.0; d[6]=0.0; d[4]=0.0; d[5]=1.0e+30;
      for (i=0; i<=n-1; i++)
      { 
		  d[3]=d[1]*exp(d[0]*log(x[i])); 
          d[2]=d[2]+(y[i]-d[3])*(y[i]-d[3]);
          s=fabs(y[i]-d[3]);
          if (s>d[4]) d[4]=s;
          if (s<d[5]) d[5]=s;
          d[6]=d[6]+s/n;
      }
    d[3]=sqrt(d[2]/n);
    return;
  }

  //包含在文件LOG2.C中
  main()
  {
      double d[7];
      double x[10]={0.1,1.0,3.0,5.0,8.0,10.0,20.0,50.0,80.0,100.0};
      double y[10]={0.1,0.9,2.5,4.0,6.3,7.8,14.8,36.0,54.0,67.0};
      log2(10,x,y,d);
      printf("a=%f ,   b=%f\n",d[0],d[1]);
      printf("q=%f ,   s=%f\n",d[2],d[3]);
      printf("umax=%f ,  umin=%f ,  u=%f\n",d[4],d[5],d[6]);
  }

