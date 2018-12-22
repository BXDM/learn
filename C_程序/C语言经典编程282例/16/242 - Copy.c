#include<stdio.h>
main()
{
    char *ptr, filename[50];									/*定义变量及数组为字符型*/
    printf("please input the file name you want to search:\n");
    scanf("%s", filename);									/*输入要查找的文件名*/
    if ((ptr = searchpath(filename)) != NULL)
        printf("the path is:%s\n", ptr);							/*将文件所在的路径输出*/
    else
        printf("cannot find");								/*若文件未找到，输出双引号内提示信息*/
}
