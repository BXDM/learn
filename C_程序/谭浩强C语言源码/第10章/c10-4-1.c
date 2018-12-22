#include <stdio.h>
#define SIZE 10
struct student_type
 {char name[10];
  int num;
  int age;
  char addr[15];
 }stud[SIZE];                // 定义全局结构体数组stud，包含10个学生数据  

void save( )                 // 定义函数save，向文件输出SIZE个学生的数据  
  {FILE *fp;
   int i;
   if((fp=fopen ("stu.dat","wb"))==NULL)    // 打开输出文件atu_list  
      {printf("cannot open file\n");
       return;
      }
   for(i=0;i<SIZE;i++)
      if(fwrite (&stud[i],sizeof (struct student_type),1,fp)!=1)
         printf ("file write error\n");
   fclose(fp);
  }

int main()
  {int i;
   printf("Please enter data of students:\n");
   for(i=0;i<SIZE;i++)           // 输入SIZE个学生的数据，存放在数组stud中  
     scanf("%s%d%d%s",stud[i].name,&stud[i].num,&stud[i].age,stud[i].addr);
   save( );
   return 0;
  }

