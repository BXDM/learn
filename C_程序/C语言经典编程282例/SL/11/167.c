#include "stdio.h"
struct student
{
    int num;
    char name[20];
    char sex;
    int age;
    float score;
};
void main()
{
    struct student student1 = 
    {
        1001, "ÀîXX", 'M', 25, 90.3
    };
    struct student *p;
    p = &student1;
    printf("Number:%d\n", p->num);
    printf("Name:%s\n", p->name);
    printf("Sex:%c\n", p->sex);
    printf("Age:%d\n", p->age);
    printf("Score:%5.1f\n", p->score);
    getch();
}
