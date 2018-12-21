#include <stdio.h>
#include <dir.h>
main()
{
	char *filename="mingriXXXXXX",*p;					/*为filename赋值*/
	p=mktemp(filename);								/*调用函数产生唯一文件名，返回值赋给p*/
	printf("%s\n",p);
	getch();
}
