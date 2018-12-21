#include <stdio.h>
main()
{
    FILE *fp1,  *fp2;									/*定义两个指向FILE类型结构体的指针变量*/
    char filename1[50], filename2[50], ch;					/*定义数组及变量为字符型*/
    long character, space, other, digit;						/*定义变量为长整形*/
    character = space = digit = other = 0;					/*长整形变量的初值均为0*/
    printf("Enter file name \n");
    scanf("%s", filename1);								/*输入要进行统计的文件的路径及名称*/
    if ((fp1 = fopen(filename1, "r")) == NULL)
     /*以只读方式打开指定文件*/
    {
        printf("cannot open file\n");
        exit(1);
    }
    printf("Enter file name for write data:\n");
    scanf("%s", filename2);								/*输入文件名即将统计结果放到那个文件中*/
    if ((fp2 = fopen(filename2, "w")) == NULL)				/*以可写方式要存放统计结果的文件*/
    {
        printf("cannot open file\n");
        exit(1);
    }
    while ((ch = fgetc(fp1)) != EOF)						/*知道文件内容结束处停止while循环*/
        if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
            character++;								/*当遇到字母时字符个数加1*/
    else if (ch == ' ')
        space++;									/*当遇到空格时空格数加1*/
    else if (ch >= '0' && ch <= '9')
        digit++;									/*当遇到数字时数字数加1*/
    else
        other++;									/*当是其他字符时其他字符数加1*/
    close(fp1);										/*关闭fp1指向的文件*/
    fprintf(fp2, "character:%ld space:%ld digit:%ld other:%ld\n", character,
        space, digit, other);								/*将统计结果写入fp指向的磁盘文件中*/
    fclose(fp2);										/*关闭fp2指向的文件*/
}
