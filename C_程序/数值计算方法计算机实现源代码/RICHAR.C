    //RICHAR.C
    //数值微分
    #include  <stdio.h>
    #include  <math.h>
    //计算给定点处的一阶导数
	double richardson1(x, h, f)
    double x, h, (*f)(double);
	{
		int  k;
		double fxh, fx2h, fx_h, fx_2h, d[2];
        for (k=0; k<=1; k++)
		{
		    fxh = (*f)(x + h);
		    fx2h = (*f)(x + 2*h);
		    fx_h = (*f)(x - h);
		    fx_2h = (*f)(x - 2*h);
		    d[k] = (-fx2h + 8*fxh - 8*fx_h + fx_2h)/(12*h);
			h = 0.5*h;
		}
		return((16*d[1] - d[0])/15);
	}

    //计算给定点处的二阶导数
	double richardson2(x, h, f)
    double  x, h, (*f)(double);
	{
		int  k;
		double fx, fxh, fx2h, fx_h, fx_2h, d[2];
        for (k=0; k<=1; k++)
		{
			fx = (*f)(x);
		    fxh = (*f)(x + h);
		    fx2h = (*f)(x + 2*h);
		    fx_h = (*f)(x - h);
		    fx_2h = (*f)(x - 2*h);
		    d[k] = (-fx2h + 16*fxh - 30*fx + 16*fx_h - fx_2h)/(12*h*h);
			h = 0.5*h;
		}
		return((16*d[1] - d[0])/15);
	}

	//包含在文件RICHAR.C中
	main()
	{
		double x, h, dy, ddy, f(double);
		x = 0.5;  h = 0.1;
		dy = richardson1(x, h, f);
        printf("dy=%f\n", dy);
		ddy = richardson2(x, h, f);
        printf("ddy=%f\n", ddy);		
	}

	double  f(double x)    //要求导的函数
	{
		double  y;
		y = exp(x);
		return(y);
	}
