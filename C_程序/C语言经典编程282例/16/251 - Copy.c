#include <stdio.h>
main()
{
    FILE *fp;									/*定义一个指向FILE类型结构体的指针变量*/
    char ch, filename[50];							/*定义变量及数组为字符型*/
    printf("please input filename:\n");
    scanf("%s", filename);							/*输入文件所在路径及名称*/
    if ((fp = fopen(filename, "w")) == NULL)				/*以只写方式打开指定文件*/
    {
        printf("cannot open file\n");
        exit(0);
    }
    ch = getchar();								/*fgetc函数带回一个字符赋给ch*/
    while (ch != '#')								/*当输入"#"时结束循环*/
    {
        fputc(ch, fp);								/*将读入的字符写到磁盘文件上去*/
        ch = getchar();							/*fgetc函数继续带回一个字符赋给ch*/
    }
    fclose(fp);									/*关闭文件*/
}
