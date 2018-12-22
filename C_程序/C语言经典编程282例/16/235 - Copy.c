#include <stdio.h>
#include<conio.h>
main()
{
    FILE *fp1,  *fp2;										/*定义两个指向FILE类型结构体的指针变量*/
    char filename1[50], filename2[50], a;						/*定义数组和变量为字符型*/
    printf("please input filename1:\n");
    scanf("%s", filename1); 								/*输入第一个文件所在路径及名称*/
    printf("please input filename2\n");
    scanf("%s", filename2); 								/*输入第二个文件所在路径及名称*/
    fp1 = fopen(filename1, "r");								/*以只读方式打开输入的第一个文件*/
    fp2 = fopen(filename2, "r");								/*以只读方式打开输入的第二个文件*/
    gotoxy(3, 5); 										/*将光标定位*/
    printf("file1:\n");
    a = fgetc(fp1);
    while (!feof(fp1))
    {
        printf("%c", a);									/*输出第一个文件中的内容*/
        a = fgetc(fp1);
    }
    gotoxy(3, 13);										/*将光标定位*/
    printf("file2:\n");
    a = fgetc(fp2);
    while (!feof(fp2))
    {
        printf("%c", a);									/*输出第二个文件中的内容*/
        a = fgetc(fp2);
    }
    fclose(fp1);											/*关闭第一个文件*/
    fclose(fp2);											/*关闭第二个文件*/
}
