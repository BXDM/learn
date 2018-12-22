#include <stdio.h>
main()
{
    int i, flag = 1;								/*定义变量为基本整型*/
    char str[80], filename[50];						/*定义数组为字符型*/
    FILE *fp; 									/*定义一个指向FILE类型结构体的指针变量*/
    printf("please input filename:\n");
    scanf("%s", filename);							/*输入文件所在路径及名称*/
    if ((fp = fopen(filename, "w")) == NULL)				/*以只写方式打开指定文件*/
    {
        printf("cannot open!");
        exit(0);
    }
    while (flag == 1)
    {
        printf("\nInput string:\n");
        scanf("%s", str);								/*输入字符串*/
        fprintf(fp, "%s", str);							/*将str字符串内容以%s形式写到fp所指文件上*/
        printf("\nContinue:?");
        if ((getchar() == 'N') || (getchar() == 'n'))				/*输入n结束输入*/
            flag = 0;									/*标志位置0*/
    }
    fclose(fp);										/*关闭文件*/
    fp = fopen(filename, "r");							/*以只写读方式打开指定文件*/
    while (fscanf(fp, "%s", str) != EOF)						/*从fp所指的文件中以%s形式读入字符串*/
    {
        for (i = 0; str[i] != '\0'; i++)
            if ((str[i] >= 'a') && (str[i] <= 'z'))
                str[i] -= 32;							/*将小写字母转换为小写字母*/
        printf("\n%s\n", str);							/*输出转换后的字符串*/
    }
    fclose(fp);										/*关闭文件*/
}
