
    //文件名 POWER.C
    //乘幂法计算矩阵绝对值最大的特征值
    #include  <stdio.h>
    #include  <math.h>
    #include  <stdlib.h>
	int power(n, a, eps, lambda, v)
    int n;
    double eps, a[];
    double  *lambda, v[];
	{
		int i, j, k, flag = 1, iteration;
		double  sum, *u, z;
		double  err, t, d, f;
		u = (double *)malloc(n*sizeof(double));
        iteration = 0;
		do
		{
			iteration++;
			for (i=0; i<n; i++)       //计算u=Av
			{
				sum = 0.0;
				for (j=0; j<n; j++)
				{ sum = sum + a[i*n+j]*v[j]; }
				u[i] = sum;
			}
			d = 0.0;            //计算向量的范数			
			for (k=0; k<n; k++)  d = d+u[k]*u[k];
			d = sqrt(d);
			for (i=0; i<n; i++)
			{ v[i] = u[i]/d; }
			if (iteration > 1)
			{
				err = fabs((d - t)/d);
				f = 1;
				if (v[0]*z < 0 )  f = -1;
				if (err < eps) { flag = 0; }
			}
			if (flag == 1)
			{
				t = d;  z = v[0];
			}
			if (iteration > 1000)
			{
				printf("\n1000次迭代不收敛. 失败...\n");
				free(u);
				return(iteration);
			}
		} while (flag == 1);
        *lambda = f*d;
		free(u);
		return(iteration);
	}

	//包含在文件POWER.C中
	void main()
	{
		int i;
		double a1[3][3] = {{0,1,1.5},{-5,-0.5,1},{-1,2,3.5}};
		double a2[3][3] = {{-5,1,5},{1,0,0},{0,1,0}};
		double v[3] = {0,0,1};
		double lambda=0;
		i = power(3, &a1[0][0], 0.0000001, &lambda, &v[0]);
        printf("迭代次数= %d \n", i);
		printf("绝对值最大的特征值 lambda = %f \n", lambda);
		for (i=0; i<3; i++)
			printf("v(%d)= %f \n",i, v[i]);
		printf("\n");
		i = power(3, &a2[0][0], 0.000000001, &lambda, &v[0]);
        printf("迭代次数= %d \n", i);
		printf("绝对值最大的特征值 lambda = %f \n", lambda);
		for (i=0; i<3; i++)
			printf("v(%d)= %f \n",i, v[i]);
		printf("\n");
		
		return;
	}
