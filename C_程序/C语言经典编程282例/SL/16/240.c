#include <stdio.h>
struct student_type											/*定义结构体存储学生信息*/
{
    char name[10];
    int num;
    int age;
}stud[10];
void save(char *name, int n)										/*自定义函数save*/
{
    FILE *fp;
    int i;
    if ((fp = fopen(name, "wb")) == NULL)							/*以只写方式打开指定文件*/
    {
        printf("cannot open file\n");
        exit(0);
    }
    for (i = 0; i < n; i++)
        if (fwrite(&stud[i], sizeof(struct student_type), 1, fp) != 1)		/*将一组数据输出到fp所指的文件中*/
            printf("file write error\n");							/*如果写入文件不成功，则输出错误*/
    fclose(fp);											/*关闭文件*/
}
main()
{
    int i, n;											/*变量类型为基本整型*/
    FILE *fp;											/*定义一个指向FILE类型结构体的指针变量*/
    char filename[50];										/*数组为字符型*/
    printf("please input filename:\n");
    scanf("%s", filename);									/*输入文件所在路径及名称*/
    printf("please input the number of students:\n");
    scanf("%d", &n);										/*输入学生数*/
    printf("please input name,number,age:\n");
    for (i = 0; i < n; i++)									/*输入学生信息*/
    {
        printf("NO%d", i + 1);
        scanf("%s%d%d", stud[i].name, &stud[i].num, &stud[i].age);
        save(filename, n);									/*调用函数save*/
    } if ((fp = fopen(filename, "rb")) == NULL)					/*以只读方式打开指定文件*/
    {
        printf("can not open file\n");
        exit(0);
    }
    for (i = 0; i < n; i += 2)
    {
        fseek(fp, i *sizeof(struct student_type), 0);					/*随着i的变化从文件开始处随机读文件*/
        fread(&stud[i], sizeof(struct student_type), 1, fp);	
        printf("%-10s%5d%5d\n", stud[i].name, stud[i].num, stud[i].age);
    }
    fclose(fp);											/*关闭文件*/
}
