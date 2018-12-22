#include <stdio.h>
#include <string.h>
#include <stdlib.h>
FILE *in,  *out;											/*定义两个指向FILE类型结构体的指针变量*/
char filename[50], ch, cfilename[50];
void space()											/* 分隔文件函数 */
{
    char ext[6][6] =
    {
        "a.txt", "b.txt", "c.txt", "d.txt", "e.txt", "f.txt"
    };												/* 分割出来的文件扩展名 */
    unsigned long int n = 1, k, byte = 0;							/* 定义变量类型为无符号的长整形变量 */
    unsigned int j = 0, i = 0;
    printf("Please input filename:\n");
    scanf("%s", filename);									/*输入文件所在路径及名称*/
    strcpy(cfilename, filename);								/*输入文件所在路径及名称复制到cfilename中*/
    if ((in = fopen(filename, "r")) == NULL)						/* 以只读方式打开输入文件 */
    {
        printf("Cannot open file\n");
        exit(0);
    }
    printf("Please input file size after space(kb):\n");
    scanf("%d", &n);										/* 输入分割后单个文件的大小 */
    n = n * 1024;
    while (filename[j] != '.')
        j++;
    filename[j] = '\0';										/*遇'.'时,在该处加字符串结束符*/
    if ((out = fopen(strcat(filename, ext[i]), "w")) == NULL)			/*生成分割后文件所在路径及名称*/
    {
        printf("Cannot open file\n");
        exit(0);
    }
    fseek(in, 0, 2);										/*将位置指针移到文件末尾*/
    k = ftell(in);											/* k存放当前位置，也就是整个文件的大小 */
    fseek(in, 0, 0);
    while (k > 0)
    {
        ch = fgetc(in);
        fputc(ch, out);
        byte++;											/*字节数增加*/
        k--;											/*大小减1*/
        if (byte == n)										/*当为要求的大小时执行括号内语句*/
        {
            fclose(out);									/*完成一个分割出的文件*/
            byte = 0;										/*byte重新置0*/
            strcpy(filename, cfilename);						/*filename恢复初始状态*/
            while (filename[j] != '.')
                j++;	
            filename[j] = '\0';								/*遇'.'时,在该处加字符串结束符*/
            i++;
            if ((out = fopen(strcat(filename, ext[i]), "w")) == NULL)
													/*生成分割后文件所在路径及名称*/
            {
                printf("Cannot open file\n");
                exit(0);
            }
        }
    }
    fclose(in);											/* 关闭文件 */
    printf("File succeed space!\n\n\n");
}
main()												/* 程序主函数 */
{
    printf(" now file space!\n");
    space();
}
