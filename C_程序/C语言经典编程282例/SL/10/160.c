#include <dos.h>
main(void)
{
	unsigned fre=50;								
	int times;										
	for(times=0;times<1000;times++)					
	{
		fre=(fre+times)%40000;						
		sound(fre);									
		delay(1000);								
	}
	nosound(); 										
}
