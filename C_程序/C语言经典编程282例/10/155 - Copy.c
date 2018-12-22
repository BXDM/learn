
#include <conio.h> 
#include <stdlib.h>
#include <dos.h>
#include <stdio.h>
int main()
{
	union REGS regs;
	int mousedr; 
	clrscr();
	printf("Initializing Mouse...\n\n");
	regs.x.ax=0;
	int86(0x33,&regs,&regs);
	mousedr=regs.x.ax; 
	if(mousedr==0)
	{ 
	printf("initialize mouse error!"); 
	exit(1); 
	} 
	
	printf("Finished initializing!\n\n");

	printf("Showing Mouse...\n");
	regs.x.ax=1;
	int86(0x33,&regs,&regs);
	printf("you can use the mouse.....\n\n");
	printf("Press any key to hide the mouse.\n");
	getch();
	regs.x.ax=2;
	int86(0x33,&regs,&regs);
	printf("\nthe mouse is hided\n");
	getch();
	return 1;
}