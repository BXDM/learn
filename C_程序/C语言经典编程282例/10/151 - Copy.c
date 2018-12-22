#include <stdio.h> 
#include <bios.h>
main() 
{ 
	int memsize;											/*声明整型变量*/
	memsize=biosmemory();								/*获取BIOS常规内存容量*/
	printf("\nBIOS regular memory size is %dKb",memsize);		/*输出BIOS常规内存容量值*/
	getch();
}
