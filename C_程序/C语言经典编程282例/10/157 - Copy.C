#include <graphics.h> 
#include <stdio.h> 

char *dvrname[] = {
"requests detection", 
"a CGA", 
"an MCGA", 
"an EGA", 
"a 64K EGA", 
"a monochrome EGA", 
"an IBM 8514", 
"a Hercules monochrome", 
"an AT&T 6300 PC", 
"a VGA", 
"an IBM 3270 PC" 
}; 

int main(void) 
{ 

int gdriver, gmode, errorcode; 

 
detectgraph(&gdriver, &gmode); 


errorcode = graphresult(); 
if (errorcode != 0)
	{

	printf("Graphics error: %s\n", grapherrormsg(errorcode));
	printf("Press any key to exit"); 
	getch(); 
	exit(1); 
	} 

clrscr(); 
printf("You have %s video display card.\n", dvrname[gdriver]);
printf("Press any key to exit:"); 
getch(); 
return 0; 
} 

