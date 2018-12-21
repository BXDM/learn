#include <stdio.h>
#include <dos.h>

int main(void)
{
   char *path, *ptr;
   int i = 0;
   
   puts(" This program is to get the information of environ.");
   /* 获得当前环境变量中的path信息 */

   while (environ[i]) /*循环输出所有的环境变量*/
       printf(" >> %s\n",environ[i++]);
   printf(" Press any key to quit...");
   getch();
   return 0;
}