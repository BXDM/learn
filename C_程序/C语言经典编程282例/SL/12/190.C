#include<stdio.h>

struct student
{
	/*结构体成员*/
    int num;
    char name[20];
    float score;
};

void main()
{
    int i, m;
    float maxscore;
    struct student stu[5] =
    {
        {101, "李明", 89} ,
        {102, "苑达", 95},
        {103, "孙佳", 89},
        {104, "王子川", 85},
        {105, "刘春月", 75}
    };										/*声明结构体类型数组*/
    m = 0;
    maxscore = stu[0].score;						/*初始化最大成绩*/
    for (i = 1; i < 5; i++)
    {
        if (stu[i].score > maxscore)
        {
            maxscore = stu[i].score;					/*记录最大成绩*/
            m = i;								/*记录最大成绩下标*/
        }
    }
    printf("最高分是:%5.1f\n", maxscore);	/*输出最大成绩*/
    printf("最高分学生的学号: %d\n", stu[m].num);	/*最大成绩的学号*/
    printf("最高分学生的姓名: %s\n", stu[m].name);	/*最大成绩的姓名*/
	
}

