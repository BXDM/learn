#include <stdio.h>
int main()
 {float score[ ][4]={{60,70,80,90},{56,89,67,88},{34,78,90,66}};   //定义数组，存放成绩
  float  *search(float (*pointer)[4]);                      // 函数声明
  float  *p;
  int i,j;
  for(i=0;i<3;i++)
     {p=search(score+i);                                    //调用search函数,如有不及格返回score[i][0]的地址，否则返回NULL，
      if(p==*(score+i))                                     //如果返回的是score[i][0]的地址
        {printf("No.%d score:",i);
		 for(j=0;j<4;j++)
            printf("%5.2f  ",*(p+j));                       // 输出score[i][0]到score[i][3]的值
         printf("\n");
        } 
     }
  return 0;
}

float *search(float (*pointer)[4])                            // 定义函数，形参pointer是指向一维数组的指针变量
  {int i=0;
   float *pt;
   pt=NULL;                                                   // 先使pt的值为NULL
   for(;i<4;i++)
     if(*(*pointer+i)<60) pt=*pointer;                        // 如果有不及格课程，使pt指向score[i][0] 
   return(pt);
}
