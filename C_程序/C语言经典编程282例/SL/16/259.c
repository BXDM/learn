#include <stdio.h>
int candp(int a,int b,int c)
{ int r=1;
b=b+1;
while(b!=1)
{
    r=r*a;
    r=r%c;
    b--;
}
printf("%d\n",r);
return r;
}
void main()
{
int p,q,e,d,m,n,t,c,r;
char s;
printf("please input the p,q: ");
scanf("%d%d",&p,&q);
n=p*q;
printf("the n is %3d\n",n);
t=(p-1)*(q-1);
printf("the t is %3d\n",t);
printf("please input the e: ");
scanf("%d",&e);
if(e<1||e>t)
{
     printf("e is error,please input again: ");
     scanf("%d",&e);
}
d=1;
while(((e*d)%t)!=1)   d++;
printf("then caculate out that the d is %d\n",d);
printf("the cipher please input 1\n");
printf("the plain please input 2\n");
scanf("%d",&r);
switch(r)
{
    case 1: printf("input the m: "); /*输入要加密的明文数字*/
            scanf("%d",&m);
            c=candp(m,e,n);
            printf("the cipher is %d\n",c);break;
    case 2: printf("input the c: "); /*输入要解密的密文数字*/
            scanf("%d",&c);
            m=candp(c,d,n);
            printf("the cipher is %d\n",m);break;
}
getch();
}
