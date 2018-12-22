#include <dir.h>
#include <stdio.h>
main()
{
	if (!mkdir("temp"))									/*调用函数应temp为路径名建立一个目录*/
		printf("directory test is created\n");				/*目录建成输出提示信息*/
	else
	{
		printf("unable to create new directory\n");			/*目录未建成也同样输出提示信息*/
		exit(1);
	}
	getch();
}
