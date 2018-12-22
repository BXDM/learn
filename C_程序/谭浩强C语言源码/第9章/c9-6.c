#include <stdio.h>
struct student
  {int num;
   char name[20];
   char sex;
   int age;
  };
struct student stu[3]={{10101,"Li Lin",'M',18},{10102,"Zhang Fun",'M',19},{10104,"Wang Min",'F',20}};              // 定义结构体数组并初始化 

int main()
 {struct student *p;                                            //定义指向struct student结构体的数组 
   printf(" No.  Name                 sex age\n");
   for (p=stu;p<stu+3;p++)
     printf("%5d %-20s %2c %4d\n",p->num, p->name, p->sex, p->age);
   return 0;
}            
