//计算 5 的阶乘
//北巷的猫 2018.12.22
#include <stdio.h>
int main()
{
    int i=1;
    int p=1 ;
    
    while (i<=5) {
	    p=i*p;
	    i++;
	}
    printf("%d\n", p);
    
    return 0 ;
}
