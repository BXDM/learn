#include <stdio.h>
#include <dos.h>
void main() 
{ 
int n; 
char comspass; 
char temp=0; 
int result;

printf("\nThis program only is tested at win98 and award bios!!\n"); 
printf("The password of the cmos is:"); 

outportb(0x70,0x1d); 
comspass=inportb(0x71); 
for(n=6;n>=0;n-=2) 
{ temp=comspass;
temp>>=n; 
temp=temp&0x03; 
printf("%d",temp); 
} 

outportb(0x70,0x1c); 
result=inportb(0x71); 
for(n=6;n>=0;n-=2) 
{ temp=comspass; 
temp>>=n; 
temp=temp&0x03; 
printf("%d",temp); 
} 
}