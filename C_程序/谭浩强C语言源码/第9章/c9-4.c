#include <stdio.h>
struct student                                       // 声明结构体类型struct student  
   {int num;
    char name[20];
    float score;
   };   
int main()
  {struct student stu[5]={{10101,"Zhang",78},{10103,"Wang",98.5},{10106,"Li",86},
          {10108,"Ling",73.5},{10110,"Fun",100}};    // 定义结倒构体数组并初始化 
   struct student temp;                              //定义结构体变量temp，用作交换时的临时变量  
   const int n=5;
   int i,j,k;
   printf("The order is:\n");
   for(i=0;i<n-1;i++)
      {k=i;
       for(j=i+1;j<n;j++)
         if(stu[j].score>stu[k].score)                // 进行成绩的比较   
     		k=j;
      temp=stu[k];stu[k]=stu[i];stu[i]=temp;           // stu[k]和stu[i]元素互换  
	  }
   for(i=0;i<n;i++)
     printf("%6d %8s %6.2f\n",stu[i].num,stu[i].name,stu[i].score);
   printf("\n");
   return 0;
}
