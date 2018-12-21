#include <dir.h>
#include <stdio.h>
main()
{
	char *name[10]; 											/*定义字符型数组存储文件名*/
	printf("please input directory name:\n");
	scanf("%s", name); 										/*输入文件名*/
	printf("Press any key,and the directory will be removed\n");
	getch();
	if (!rmdir(name))											/*删除目录*/
		printf("Directory is removed.\n");							/*删除成功输出提示信息*/
	else
		printf("can not remove");								/*删除不成功输出提示信息*/
	getch();
}
