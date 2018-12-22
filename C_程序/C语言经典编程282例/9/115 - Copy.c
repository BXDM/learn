#include <stdio.h>
#include<string.h>
int main()
{
	int result = 1;
	int i;
	int count = 0;
	char Text[128] = {'\0'};								/*定义一个明文字符数组*/
	char cryptograph[128] = {'\0'};						/*定义一个密文字符数组*/
	while (1)
	{
		if (result == 1)									/*如果是加密明文*/
		{
			printf("请输入要加密的明文：\n");			/*输出字符串*/
			scanf("%s", &Text);						/*获取输入的明文*/
			count = strlen(Text);
			for(i=0; i<count; i++)						/*遍历明文*/
			{
				cryptograph[i] = Text[i] + i + 5;			/*设置加密字符*/
			}
			cryptograph[i] = '\0';						/*设置字符串结束标记*/
			/*输出密文信息*/
			printf("加密后的密文是：%s\n",cryptograph);
		}
		else if(result == 2)								/*如果是解密字符串*/
		{
			count = strlen(Text);
			for(i=0; i<count; i++)						/*遍历密文字符串*/
			{
				Text[i] = cryptograph[i] - i - 5;			/*设置解密字符*/
			}
			Text[i] = '\0';								/*设置字符串结束标记*/
			/*输出明文信息*/
			printf("解密后的明文是：%s\n",Text);
		}
		else if(result == 3)								/*如果是退出系统*/
		{
			break;									/*跳出循环*/
		}
		else
		{
			printf("请输入正确命令符：\n");			/*输出字符串*/
		}
		/*输出字符串*/
		printf("输入1加密新的明文，输入2对刚加密的密文进行解密，输入3退出系统：\n");	
		printf("请输入命令符：\n");						/*输出字符串*/
		scanf("%d", &result);							/*获取输入的命令字符*/
	}
	return 0;											/*程序结束*/
}
