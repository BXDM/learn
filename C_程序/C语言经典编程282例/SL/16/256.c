/* Note:Your choice is C IDE */
#include "stdio.h"
#include "string.h"
void main()
{
	char *ysn;
	char *sn;
	printf("\nPlease input the serial number\n");
	sn="1001-1618-2903";
	scanf("%s",ysn);
    if(!strcmp(ysn,sn))
    	printf("register succeed");
    else
    	printf("register lose");
    	exit();
}