#include <stdio.h>
#include <dos.h>
main()
{
	int value=0;
	printf("\n\The current status of  the Caps Lock key is:");
	value=peekb(0x0040,0x0017);
	if (value & 64)
	printf("\n\nThe Caps Lock key is: on");
	else
	printf("\n\nThe Caps Lock key is: off");
}