/* Note:Your choice is C IDE */
#include "stdio.h"
#include "string.h"
#include "ctype.h"
int getsn1();
int getsn2();
int getsn3();
int getsn4();
void main()
{
	char *str;
	printf("\nplease input the serial number:\n");
    scanf("%s",str);
    if(strlen(str)==23 && str[5]=='-' && str[11]=='-' && str[17]=='-')
    {
    	if(getsn1(str)%6==1 && getsn2(str)%8==1 && getsn3(str)%9==2 && getsn4(str)%3==0)
    	{
    	printf("%s\n","register succeed");
    	}
    }
    else
    printf("%s\n","register Lose");
    exit();
}

int getsn1(char *str)
{
    int i;
    int sum;
    sum=0;
    for(i=0;i<5;i++)
    {
    	sum=sum+toascii(str[i]);
    }
    return sum;
}

int getsn2(char *str)
{
    int i;
    int sum;
    sum=0;
    for(i=6;i<11;i++)
    {
    	sum=sum+toascii(str[i]);
    }
    return sum;
}

int getsn3(char *str)
{
    int i;
    int sum;
    sum=0;
    for(i=12;i<17;i++)
    {
    	sum=sum+toascii(str[i]);
    }
    return sum;
}

int getsn4(char *str)
{
    int i;
    int sum;
    sum=0;
    for(i=18;i<23;i++)
    {
    	sum=sum+toascii(str[i]);
    }
    return sum;
}