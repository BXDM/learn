#include<stdio.h>
int main()
{
	int iSelect=1;											/*定义变量，表示菜单的选项*/
	while(iSelect!=0)										/*检验条件，循环显示菜单*/
	{	/*显示菜单内容*/
		printf("---------Menu---------\n");
		printf("----Sell----------1\n");
		printf("----Buy-----------2\n");
		printf("----ShowProduct---3\n");
		printf("----Out-----------0\n");
		scanf("%d",&iSelect);								/*输入菜单的选项*/
		switch(iSelect)										/*使用switch语句，检验条件进行相应的处理*/
		{
			case 1:										/*选择第一项菜单的情况*/
				printf("you are buying something into store\n");
				break;
			case 2:										/*选择第二项菜单的情况*/
				printf("you are selling to consumer\n");
				break;
			case 3:										/*选择第三项菜单的情况*/
				printf("checking the store\n");
				break;
			case 0:										/*选择退出项菜单的情况*/
				printf("the Program is out\n");
				break;
			default:										/*默认处理*/
				printf("You put a wrong selection\n");
				break;
		}
	}
	return 0;
}
