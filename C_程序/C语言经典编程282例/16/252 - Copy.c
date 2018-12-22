#include <stdio.h>
#include <dir.h>
#include <dos.h>
main()
{
    char str1[50], str2[50], filename[50]; 				/*定义数组为字符型*/
    int i, j = 0, k; 								/*定义变量为基本整型*/
    FILE *fp; 									/*定义一个指向FILE类型结构体的指针变量*/
    struct ffblk fileinf;
    printf("please input filename which do you want to save:");
    gets(filename); 							
											/*输入磁盘文件路径及名称，该文件用来保存统计出的结果*/
    fp = fopen(filename, "w+");
    printf("Please input directory:\n");					/*提示输入目录*/
    gets(str1);									/*输入要进行统计的文件所在目录*/
    k = chdir(str1); 								/*切换当前工作目录,正确返回0*/
    if (k != 0)									/*如果不等于0,提示信息后退出*/
    {
        printf("Change Path failure!\n");
        getch();
        exit( - 1);
    }

    printf("\nPlease input File type:\n");
    gets(str2); 											/*输入要进行统计的文件的类型，如：*.doc*/
    i = findfirst(str2, &fileinf, FA_ARCH); 						/*查找匹配条件的第一个文件,正确返回0*/
    if (i != 0)											/*如果返回值不为0,提示信息后退出*/
    {
        printf("File Not Find!\n");
        getch();
        exit( - 1);
    }
    else
    {
        printf("\n");
        printf("%s\n", fileinf.ff_name); 						/*在屏幕上打印*/
        fputs(fileinf.ff_name, fp); 							/*输出到文件*/
        fputs("\n", fp); 									/*输出换行符到文件*/
        while (j == 0)										/*循环查找,直到findnext不等于0*/
        {
            j = findnext(&fileinf);							/*查找与findfirst相匹配的文件*/
            if (j == 0)
             /*如果找到*/
            {
                printf("%s\n", fileinf.ff_name);					/*在屏幕上打印*/
                fputs(fileinf.ff_name, fp);						/*输出到文件*/
                fputs("\n", fp);								/*输出换行符到文件*/
            } 
        }
    }
    fclose(fp); 											/*关闭文件*/
}
