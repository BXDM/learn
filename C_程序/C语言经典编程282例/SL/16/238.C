#include<stdio.h>
main()
{
    FILE *temp;											/*定义一个指向FILE类型结构体的指针变量*/
    char c;												/*定义变量c为字符型*/
    if ((temp = tmpfile()) != NULL)
        fputs("\nhello world\nhello mingri", temp);					/*向临时文件中写入要求内容*/
    rewind(temp);										/*文件指针返回文件首*/
    while ((c = fgetc(temp)) != EOF)							/*读取临时文件中内容*/
        printf("%c", c);									/*将读取的内容输出在屏幕上*/
    fclose(temp);										/*关闭临时文件*/
}
