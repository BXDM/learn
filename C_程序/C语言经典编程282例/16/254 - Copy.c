#include <stdio.h>											/*标准输入输出头文件*/
#include <stdlib.h>
#include <string.h>
void encrypt(char *soucefile, char *pwd, char *codefile);				/*对文件进行加密的具体函数*/
void encrypt(char *s_file, char *pwd, char *c_file) 					/*自定义函数encrypt用于加密*/
{
    int i = 0;
    FILE *fp1,  *fp2; 									/*定义fp1和fp2是指向结构体变量的指针*/
    register char ch;
    fp1 = fopen(s_file, "rb");
    if (fp1 == NULL)
    {
        printf("cannot open s_file.\n");
        exit(1); 										/*如果不能打开要加密的文件,便退出程序*/
    }
    fp2 = fopen(c_file, "wb");
    if (fp2 == NULL)
    {
        printf("cannot open or create c_file.\n");
        exit(1); 										/*如果不能建立加密后的文件,便退出*/
    }
    ch = fgetc(fp1);
    while (!feof(fp1))										/*测试文件是否结束*/
    {
        ch = ch ^ *(pwd + i);								/*采用异或方法进行加密*/
        i++;
        fputc(ch, fp2);									/*异或后写入fp2文件*/
        ch = fgetc(fp1);
        if (i > 9)
            i = 0;
    }
    fclose(fp1); 											/*关闭源文件*/
    fclose(fp2); 											/*关闭目标文件*/
}
main(int argc, char *argv[]) 										/*定义main()函数的命令行参数*/
{
    char sourcefile[50]; 										/*用户输入的要加密的文件名*/
    char codefile[50];
    char pwd[10]; 											/*用来保存密码*/
    if (argc != 4)												/*容错处理*/
    {
        printf("please input encode file name:\n");
        gets(sourcefile); 										/*得到要加密的文件名*/
        printf("please input Password:\n");
        gets(pwd); 											/*得到密码*/
        printf("please input saved file name:\n");
        gets(codefile); 										/*得到加密后你要的文件名*/
        encrypt(sourcefile, pwd, codefile);
    }
    else
    {
        strcpy(sourcefile, argv[1]);
        strcpy(pwd, argv[2]);
        strcpy(codefile, argv[3]);
        encrypt(sourcefile, pwd, codefile);
    }
}

