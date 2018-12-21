#include<stdio.h>
main()
{
	int i,j,k;													/*定义i，j，k为基本整型*/
		for(i=0;i<=10;i++)										/*i是一角钱兑换个数，所以范围从1到10*/
			for(j=0;j<=5;j++)									/*j是两角钱兑换个数，所以范围从0到5*/
				for(k=0;k<=2;k++)								/*k是五角钱兑换个数，所以范围从0到2*/
					if(i+j*2+k*5==10)							/*三种钱数相加是否等于十*/
						printf("yi jiao%d,liang jiao%d,wu jiao%d\n",i,j,k);/*将每次可兑换的方案输出*/
	return 0;
}
