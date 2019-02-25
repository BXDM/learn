#include<stdio.h>
int main()
{
    int i,j,k,n,x,a[100][100];
    a[0][1]=1;
    scanf("%d",&x);
    for(i=1;i<=x;i++)
    {
        for(j=1;j<=i;j++)
        {
            a[i][j]=a[i-1][j-1]+a[i-1][j];
            printf("%5d ",a[i][j]);//%5d  表示右对齐隔5个空格；
        }//同理，%-5d  表示左对齐隔5个空格
        printf("\n");
    }
    return 0;
}
/*--------------------- 
作者：beyond谚语 
来源：CSDN 
原文：https://blog.csdn.net/qq_41264055/article/details/80274297 
版权声明：本文为博主原创文章，转载请附上博文链接！*/