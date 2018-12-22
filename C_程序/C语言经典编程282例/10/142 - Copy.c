#include <ctype.h>
#include <stdio.h>
main()
{
	char ch, ch1;
	while (1)
	{
		printf("input the character('q' to quit):");
		ch = getchar(); 									/*从键盘中获得一个字符*/
		ch1 = getchar(); 									/*ch1接收从键盘中输入的回车*/
		if (ch == 'q' || ch == 'Q')								/*判断输入的字符是不是q或Q*/
			break;										/*如果是q或Q跳出循环*/
		if (isalpha(ch))										/*检测输入的是否是字母*/
			printf("\n%c is a letter.\n\n", ch);
		else
			printf("\n%c is not a letter.\n\n", ch);
	}
}
