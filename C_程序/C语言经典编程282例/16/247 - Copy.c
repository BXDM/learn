#include <stdio.h>
#include <stdlib.h>
void error(int e)/*自定义error函数判断出错的性质*/
{
	if(e == 0)
		printf("input error\n");
	else
		printf("output error\n");
	exit(1);    /* 跳出程序 */
}
main()
{
    FILE *in,  *out; /*第一两个文件类型指针in和out*/
    int tab, i;
    char ch, filename1[30], filename2[30];
    printf("please input the filename1:");
    scanf("%s", filename1); /*输入文件路径及名称*/
    printf("please input the filename2:");
    scanf("%s", filename2); /*输入文件路径及名称*/
    if ((in = fopen(filename1, "rb")) == NULL)
    {
        printf("can not open the file %s。\n", filename1);
        exit(1);
    }
    if ((out = fopen(filename2, "wb")) == NULL)
    {
        printf("can not open the file %s。\n", filename2);
        exit(1);
    }
    tab = 0;
    ch = fgetc(in); /*从指定的文件中读取字符*/
    while (!feof(in))
     /*检测是否有读入错误*/
    {
        if (ferror(in))
            error(0);
        if (ch == '\t')
         /*如果发现制表符，则输出相同数目的空格符*/
        {
            for (i = tab; i < 8; i++)
            {
                putc(' ', out);
                if (ferror(out))
                    error(1);
            }
            tab = 0;
        }
        else
        {
            putc(ch, out);
            if (ferror(out))
             /*检查是否有输出错误*/
                error(1);
            tab++;
            if (tab == 8)
                tab = 0;
            if (ch == '\n' || ch == '\r')
                tab = 0;
        }
        ch = fgetc(in);
    }

    fclose(in);
    fclose(out);
}
