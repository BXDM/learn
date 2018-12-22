/* Note:Your choice is C IDE */
#include "stdio.h"
#include<conio.h>
void window_3d( int, int, int, int, int, int );
int main(void)
{
	directvideo = 0;
	textmode(3);				
	textbackground( WHITE );		
	textcolor( BLACK );		
	clrscr();				
	window_3d( 10,4,50,12, BLUE, WHITE );	
	gotoxy( 17,6);					
	cputs("The first window");			
	window_3d(20,10,60,18,RED, WHITE );		
	gotoxy(17,6);					
	cputs("The second window");		
	getch();
	return 0;
}
void window_3d( int x1, int y1, int x2, int y2, int bk_color, int fo_color)

{
	textbackground(BLACK);			
	window(x1, y1,x2, y2); 			
	clrscr();							
	textbackground(bk_color); 			
	textcolor(fo_color);				
	window(x1-2, y1-1, x2-2, y2-1); 	
	clrscr();							
}
