#include <stdio.h>
main()
{
    FILE *fp; /*定义一个指向FILE类型结构体的指针变量*/
    char str[100], s[100], filename[50]; /*定义数组为字符型*/
    printf("please input string!\n");
    gets(str); /*获得字符串*/
    printf("please input filename:\n");
    scanf("%s", filename); /*输入文件所在路径及名称*/
    if ((fp = fopen(filename, "wb")) != NULL)
     /*以只写方式打开指定文件*/
    {
        fputs(str, fp); /*把字符数组str中的字符串输出到fp指向的文件*/
        fclose(fp);
    }
    else
    {
        printf("cannot open!");
        exit(0);
    }
    if ((fp = fopen(filename, "rb")) != NULL)
    {
        while (fgets(s, sizeof(s), fp))
         /*从fp所指的文件中读入字符串存入s中*/
            printf("%s", s);
         /*将字符串输出*/

        fclose(fp); /*关闭文件*/
    }
}
