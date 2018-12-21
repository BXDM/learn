#include<stdio.h>
#include<dos.h> 
int ctrbrkpr()
{
	printf("\nCtrl+Break pressed.This program will be quit");
	return(0);
}
main() 
{ 
if(getcbrk()==0)
	{
		setcbrk(1);
	}
	ctrlbrk(ctrbrkpr);
	for(;;)
	{
		printf("\nPlease press Ctrl+Break to quit");
	}
	
} 
