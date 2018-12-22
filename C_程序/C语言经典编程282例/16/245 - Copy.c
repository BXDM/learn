#include <stdio.h>
#include <string.h>
struct emploee											/*定义结构体，存放员工工资信息*/
{
    char name[10];
    int salary;
} emp[20];
main()
{
    FILE *fp1,  *fp2;
    int i, j, n, flag, salary;
    char name[10], filename[50];								/*定义数组为字符类型*/
    printf("please input filename:\n");
    scanf("%s", filename);									/*输入文件所在路径及名称*/
    printf("please input the number of emploees:\n");
    scanf("%d", &n);										/*输入要录入的人数*/
    printf("input name and salary:\n");
    for (i = 0; i < n; i++)
    {
        printf("NO%d:\n", i + 1);
        scanf("%s%d", emp[i].name, &emp[i].salary);			/*输入员工姓名及工资*/
    }
    if ((fp1 = fopen(filename, "ab")) == NULL)					/*以追加的方式打开指定的二进制文件*/
    {
        printf("Can not open the file.");
        exit(0);
    }
    for (i = 0; i < n; i++)
        if (fwrite(&emp[i], sizeof(struct emploee), 1, fp1) != 1)		/*将输入的员工信息输出到磁盘文件上*/
            printf("error\n");
    fclose(fp1);
    if ((fp2 = fopen(filename, "rb")) == NULL)
    {
        printf("Can not open file.");
        exit(0);
    } printf("\n original data:");
    for (i = 0; fread(&emp[i], sizeof(struct emploee), 1, fp2) != 0; i++)	/*读取磁盘文件上的信息到emp数组中*/
        printf("\n %8s%7d", emp[i].name, emp[i].salary);
    n = i;
    fclose(fp2);
    printf("\n Input name which do you want to delete:");
    scanf("%s", name);									/*输入要删除的员工姓名*/
    for (flag = 1, i = 0; flag && i < n; i++)
    {
        if (strcmp(name, emp[i].name) == 0)						/*查找与输入姓名相匹配的位置*/
        {
            for (j = i; j < n - 1; j++)
            {
                strcpy(emp[j].name, emp[j + 1].name);			/*查找到要删除信息的位置后将后面信息前移*/
                emp[j].salary = emp[j + 1].salary;
            } flag = 0;									/*标志位置0*/
        }
    }
    if (!flag)
        n = n - 1;										/*记录个数减1*/
    else
        printf("\nNot found");
    printf("\nNow,the content of file:\n");
    fp2 = fopen(filename, "wb");								/*以只写方式打开指定文件*/
    for (i = 0; i < n; i++)
        fwrite(&emp[i], sizeof(struct emploee), 1, fp2);			/*将数组中的员工工资信息输出到磁盘文件上*/
    fclose(fp2);
    fp2 = fopen(filename, "rb");								/*以只读方式打开指定二进制文件*/
    for (i = 0; fread(&emp[i], sizeof(struct emploee), 1, fp2) != 0; i++)	/*以只读方式打开指定二进制文件*/
        printf("\n%8s%7d", emp[i].name, emp[i].salary);			/*输出员工工资信息*/
    fclose(fp2);
}
