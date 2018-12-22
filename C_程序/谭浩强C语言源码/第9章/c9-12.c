#include <stdio.h>
int main()
{enum Color {red,yellow,blue,white,black};         //声明枚举类型enum Color
 enum Color i,j,k,pri;                             //定义枚举变量i,j,k,pri
 int n,loop;
 n=0;
 for (i=red;i<=black;i++)                          //外循环使i的值从red变到black
   for (j=red;j<=black;j++)                        //中循环使j的值从red变到black
     if (i!=j)                                     //如果二球不同色
       { for (k=red;k<=black;k++)                  //內循环使k的值从red变到black
         if ((k!=i) && (k!=j))                      //如果3球不同色
           {n=n+1;                                 //符合条件的次数加1
		    printf("%-4d",n);                      //输出当前是第几个符合条件的组合
            for (loop=1;loop<=3;loop++)            //先后对三个球分别处理
              {switch (loop)                       //loop的值从1变到3
			     {case 1: pri=i;break;             //loop的值为1时，把第1球的颜色赋给pri      
                  case 2: pri=j;break;             //loop的值为2时，把第2球的颜色赋给pri     
                  case 3: pri=k;break;             //loop的值为3时，把第3球的颜色赋给pri    
                  default:break;
				 }
               switch (pri)                        //根据球的颜色输出相应的文字
				 {case red:printf("%-10s","red"); break;            //pri的值等于枚举常量red时输出“red”
                  case yellow: printf("%-10s","yellow"); break;     //pri的值等于枚举常量yellowd时输出“yellow”
                  case blue: printf("%-10s","blue"); break;         //pri的值等于枚举常量blue时输出“blue” 
                  case white: printf("%-10s","white"); break;       //pri的值等于枚举常量white时输出“white”
                  case black: printf("%-10s","black"); break;       //pri的值等于枚举常量black时输出“black”
                  default :break;
                 }
			  }
            printf("\n");
		   }
        }
 printf("\ntotal:%5d\n",n);
 return 0;
}