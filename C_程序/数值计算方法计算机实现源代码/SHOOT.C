    //SHOOT.C
    //试射法求解二阶微分方程边值问题
    #include  <stdio.h>
    #include  <math.h>
    double  shoot(n, a, b, eps, y, f)
    int  n;
	double  a, b, eps, y[], (*f)(double,double,double);
	{
		int k;
		double h, x, yy, zz, z, zz1, zz2, y0, yn, p;
		void rkt(double,double,double,double *,double *,
			         double (*f)(double,double,double));
		h = (b-a)/n; y0 = y[0]; yn = y[n];		
		z = 0.0;  yy = y[0]; zz = z;
        for (k=0; k<n; k++)
		{
			x = a + k*h;
			rkt(x,h,eps,&yy,&zz,f);
            y[k+1] = yy; 
		}
		if (y[n]-yn > 0)    //搜索
		{
			zz2 = z;
			do
			{
				zz = zz2 - 0.1;			
                yy = y[0];
                for (k=0; k<n; k++)
				{
					x = a + k*h;
			        rkt(x,h,eps,&yy,&zz,f);
                    y[k+1] = yy; 
				}
				if (y[n]-yn > 0) zz2 = zz2 - 0.1;
			}while (y[n]-yn > 0);
			zz1 = zz2 - 0.1;
		}
		else
		{
			zz1 = z;
			do
			{
				zz = zz1 + 0.1;			
                yy = y[0];
                for (k=0; k<n; k++)
				{
					x = a + k*h;
			        rkt(x,h,eps,&yy,&zz,f);
                    y[k+1] = yy; 
				}
				if (y[n]-yn < 0) zz1 = zz1 + 0.1;
			}while (y[n]-yn < 0);
			zz2 = zz1 + 0.1;
		}
		do     //对分搜索
		{
			zz = (zz1 + zz2)/2; z = zz; 			
            yy = y[0];
            for (k=0; k<n; k++)
			{
				x = a + k*h;
			    rkt(x,h,eps,&yy,&zz,f);
                y[k+1] = yy; 
			}
			p = fabs(zz1-zz2);
			if (y[n]-yn > 0)  zz2 = z;
			else  zz1 = z;
		}while (p > 0.0000001);
		return(z);		
	}

    //变步长Runge-Kutta方法积分一步二阶微分方程初值问题
    void rkt(double t,double h,double eps,double *y,double *z,
		                      double (*f)(double,double,double))
	{
		int j,m;
		double k1,k2,k3,k4;
		double y0,z0,yy,zz,hh,p,q,x;
		k1 = (*f)(t, *y, *z);           //跨一步计算
		k2 = (*f)((t+h/2), (*y+h*(*z)/2), (*z+h*k1/2));
		k3 = (*f)((t+h/2), (*y+h*(*z)/2+h*h*k1/4), (*z+h*k2/2));
		k4 = (*f)((t+h), (*y+h*(*z)+h*h*k2/2), (*z+h*k3));
		zz = *z + h*(k1 + 2*k2 + 2*k3 + k4)/6;
		yy = *y + h*(*z) +h*h*(k1 + k2 + k3)/6;
		m = 1;  hh = h;
		p = 1 + eps;
		while (p >= eps)    //不满足精度要求
		{
			m = m + m;  hh = hh/2;   //步长减半
			y0 = *y; z0 = *z;
			for (j=0; j<m; j++)
			{
				x = t + j*hh;
			    k1 = (*f)(x, y0, z0);
			    k2 = (*f)((x+hh/2), (y0+hh*z0/2), (z0+hh*k1/2));
			    k3 = (*f)((x+hh/2), (y0+hh*z0/2+hh*hh*k1/4), (z0+hh*k2/2));
			    k4 = (*f)((x+hh), (y0+hh*z0+hh*hh*k2/2), (z0+hh*k3));
			    y0 = y0 + hh*z0 + hh*hh*(k1 + k2 + k3)/6;
				z0 = z0 + hh*(k1 + 2*k2 + 2*k3 + k4)/6;
			}
			q = fabs(y0 - yy);
			p = fabs(z0 - zz);
			if (q > p)  p = q;
			yy = y0; zz = z0;
		}
		*y = y0;  *z = z0;
		return;		
	}

	//包含在文件SHOOT.C中
	main()
	{
		int k;
		double dy0, y[11], f(double,double,double);
		y[0] = 0.0;  y[10] = 1.0;
		dy0 = shoot(10, 0.0, 1.0, 0.0000001, y, f);
		printf("初始斜率 = %f\n", dy0);
		for (k=0; k<11; k++)
			printf("x = %f     y = %f\n", k*0.1, y[k]);
	}

    double  f(double t, double y, double z)
	{
		double d;
		d = t + y;
		return(d);
	}
