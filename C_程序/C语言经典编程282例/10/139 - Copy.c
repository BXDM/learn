#include <stdio.h>
#include <dos.h>
#include <dir.h>
main()
{
	char cdir[MAXDIR];
	strcpy(cdir, "c:\\");
	cdir[0] = 'A' + getdisk();								/*调用函数返回当前驱动器*/
	if (getcurdir(0, cdir + 3))								/*调用函数将当前目录拷贝到cdir+3开始的数组中*/
	{
		printf("error");
		exit(1);
	}
	printf("the current directory is:%s\n", cdir);
	getch();
}
