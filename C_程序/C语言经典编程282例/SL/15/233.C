#include <stdio.h>
#define PWD 1

void main()
{
    char *s="mrsoft";						/*定义字符变量，将其设置为密码*/
#if PWD										/*如果是密码*/
    printf("******\n");						/*输出星号的形式*/
#else										/*否则*/
    printf("%s\n",s);						/*输出字符串*/
#endif
}
