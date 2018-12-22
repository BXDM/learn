#include<stdio.h>
main()
{
    FILE *fp;											/*定义一个指向FILE类型结构体的指针变量*/
    char filename1[20], filename2[20];							/*定义数组为字符型*/
    printf("please input the file name which do you want to change:\n");
    scanf("%s", filename1);									/*输入要重命名的文件所在的路径及名称*/
    if ((fp = fopen(filename1, "r")) != NULL)						/*以只读方式打开指定文件*/
    {
        printf("%s open successfully", filename1);
        printf("\nplease input new name!");
            scanf("%s", filename2);	/*输入新的文件路径及名称*/
        rename(filename1, filename2);								/*调用rename函数进行重命名*/
        fclose(fp);											/*关闭文件*/
    }
    else
    {
        printf("cannot find!!");
        exit(0);
    }
}
