#include <stdio.h>
#define N 3                                     // 学生数为3  
struct student                                  // 建立结构体类型struct student  
 {int num;                                      // 学号  
  char name[20];                                // 姓名   
  float score[3];                               // 3门课成绩  
  float aver;                                   // 平均成绩  
 };

int main()
 {void input(struct student stu[]);             // 函数声明  
  struct student max(struct student stu[]);     // 函数声明    
  void print(struct student stu);               // 函数声明  
  struct student stu[N],*p=stu;                 // 定义结构体数组和指针  
  input(p);                                     // 调用input函数  
  print(max(p));                                // 调用print函数,以max函数的返回值作为实参  
  return 0;
 }

void input(struct student stu[])   // 定义input 函数  
  {int i;
   printf("请输入各学生的信息：学号、姓名、三门课成绩:\n");
   for(i=0;i<N;i++)
   {scanf("%d %s %f %f %f",&stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);   // 输入数据  
    stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;                                    // 求各人平均成绩  
   }
  }

struct student max(struct student stu[])          // 定义max 函数  
{int i,m=0;                                       // 用m存放成绩最高的学生在数组中的序号  
  for(i=0;i<N;i++)
     if (stu[i].aver>stu[m].aver) m=i;            // 找出平均成绩最高的学生在数组中的序号    
  return stu[m];                                  // 返回包含该生信息的结构体元素  
}

void print(struct student stud)                   // 定义print函数  
  { printf("\n成绩最高的学生是:\n");
	printf("学号:%d\n姓名:%s\n三门课成绩:%5.1f,%5.1f,%5.1f\n平均成绩:%6.2f\n",stud.num,stud.name,stud.score[0],stud.score[1],stud.score[2],stud.aver);
 }
