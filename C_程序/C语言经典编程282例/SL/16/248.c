#include <stdio.h>
main()
{
    char ch, filename1[50], filename2[50];						/*数组和变量的数据类型为字符型*/
    FILE *fp1,  *fp2;										/*定义两个指向FILE类型结构体的指针变量*/
    printf("please input filename1:\n");
    scanf("%s", filename1);									/*输入文件所在路径及名称*/
    if ((fp1 = fopen(filename1, "a+")) == NULL)					/*以读写方式打开指定文件*/
    {
        printf(" cannot open\n");
        exit(0);
    }
    printf("file1:\n");
    ch = fgetc(fp1);
    while (ch != EOF)
    {
        putchar(ch);										/*将文件1中的内容输出*/
        ch = fgetc(fp1);
    }
    printf("\nplease input filename2:\n");
    scanf("%s", filename2);									/*输入文件所在路径及名称*/
    if ((fp2 = fopen(filename2, "r")) == NULL)					/*以只读方式打开指定文件*/
    {
        printf("cannot open\n");
        exit(0);
    }
    printf("file2:\n");
    ch = fgetc(fp2);
    while (ch != EOF)
    {
        putchar(ch);										/*将文件2中的内容输出*/
        ch = fgetc(fp2);
    }
    fseek(fp2, 0L, 0);										/*将文件2中的位置指针移到文件开始处*/
    ch = fgetc(fp2);
    while (!feof(fp2))
    {
        fputc(ch, fp1);									/*将文件2中的内容输出到文件1中*/
        ch = fgetc(fp2);									/*继续读取文件2中的内容*/
    }
    fclose(fp1);											/*关闭文件1*/
    fclose(fp2);											/*关闭文件2*/
}
