#include <stdio.h>
main()
{
    FILE *fp1,  *fp2,  *fp3; /*定义文件类型指针fp1、fp2、fp3*/
    char file1[20], file2[20], file3[20], ch;
    int file_number; /*关闭的文件数目*/
    printf("please input file1:");
    scanf("%s", file1); /*输入文件1的路径及名称*/
    printf("file1:\n");
    if ((fp1 = fopen(file1, "rb")) != NULL)
    {
        ch = fgetc(fp1); /*读取文件1中内容*/
        while (ch != EOF)
        {
            putchar(ch);
            ch = fgetc(fp1);
        }
    }
    else
    {
        printf("can not open!"); /*若文件未打开输出提示信息*/
        exit(1);
    }
    printf("\nplease input file2:");
    scanf("%s", file2); /*输入文件2的路径及名称*/
    printf("file2:\n");
    if ((fp2 = fopen(file2, "rb")) != NULL)
    {
        ch = fgetc(fp2); /*读取文件2中内容*/
        while (ch != EOF)
        {
            putchar(ch);
            ch = fgetc(fp2);
        }
    }
    else
    {
        printf("can not open!");
        exit(1);
    }
    printf("\nplease input file3:");
    scanf("%s", file3); /*输入文件3的路径及名称*/
    printf("file3:\n");
    if ((fp3 = fopen(file3, "rb")) != NULL)
    {
        ch = fgetc(fp3); /*读取文件3中内容*/
        while (ch != EOF)
        {
            putchar(ch);
            ch = fgetc(fp3);
        }
    }
    else
    {
        printf("can not open!");
        exit(1);
    }
    file_number = fcloseall(); /*调用fcloseall()
        函数关闭打开的文件，将返回值赋给file_number*/
    printf("\n%d files colsed", file_number);
}
