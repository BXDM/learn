#include <stdio.h>
int main()
{ float average(float array[10]);           // 函数声明
  float score[10],aver;
  int i;
  printf("input 10 scores:\n");
  for(i=0;i<10;i++)
      scanf("%f",&score[i]);
  printf("\n");
  aver=average(score);                     // 调用average函数
  printf("average score is %5.2f\n",aver);
  return 0;
} 

float average(float array[10])             // 定义average函数
  {int i;
   float aver,sum=array[0];
   for(i=1;i<10;i++)
       sum=sum+array[i];                  // 累加学生成绩
   aver=sum/10;
   return(aver);
}
