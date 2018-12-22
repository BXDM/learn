#include<stdio.h>
main()
{
    FILE *fp;											/*定义一个指向FILE类型结构体的指针变量*/
    char filename[50];										/*定义数组为字符型*/
    printf("please input the name of the file which do you want to delete:\n");
    scanf("%s", filename);									/*输入要删除的文件的路径及名称*/
    if ((fp = fopen(filename, "r")) != NULL)						/*以只读方式打开指定文件*/
    {
        printf("%s open successfully!", filename);					/*文件打开成功输出提示信息*/
        fclose(fp);										/*关闭文件*/
    }
    else
    {
        printf("%s cannot open!", filename);				/*文件打开失败输出提示信息*/
        exit(0);
    }
    remove(filename);								/*调用函数删除文件*/
    if ((fp = fopen(filename, "r")) == NULL)
        printf("\n%s has removed!", filename);			/*若要打开的文件不存在，则删除成功，输出提示信息*/
    else
        printf("error");							/*若要打开的文件存在，则删除不成功，输出提示信息*/
}
