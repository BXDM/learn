#include <stdio.h>
main()
{
    FILE *in,*out;									/*定义两个指向FILE类型结构体的指针变量*/
    char ch, infile[50], outfile[50];							/*定义数组及变量为基本整型*/
    printf("Enter the infile name:\n");
    scanf("%s", infile);								/*输入将要被复制的文件所在路径及名称*/
    printf("Enter the outfile name:\n");
    scanf("%s", outfile);								/*输入新建的将用于复制的文件所在路径及名称*/
    if ((in = fopen(infile, "r")) == NULL)					/*以只写方式打开指定文件*/
    {
        printf("cannot open infile\n");
        exit(0);
    }
    if ((out = fopen(outfile, "w")) == NULL)
    {
        printf("cannot open outfile\n");
        exit(0);
    }
    ch = fgetc(in);
    while (ch != EOF)
    {
        fputc(ch, out);								/*将in指向的文件的内容复制到out所指向的文件中*/
        ch = fgetc(in);
    }
    fclose(in);
    fclose(out);
}
