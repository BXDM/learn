#include<stdio.h>
#include<io.h>
void main()
{
		int h;
		char filename[20];									/*定义字符数组存储文件名*/
		LOOP:
		printf("please input filename:\n");
		scanf("%s",&filename);								/*输入文件名及路径*/
		if(h=creat(filename,0)==-1)
		{
			printf("\n Error! Cannot vreat!\n");			/*错误提示*/
			goto LOOP;									/*跳到LOOP处*/
	}
		else
		{
			printf("\nthis file has created!\n");						/*成功提示*/
			close(h);
		}
}
