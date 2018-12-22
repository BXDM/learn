#include <stdio.h>
int main()
{
  void hanoi(int n,char one,char two,char three);         // 对hanoi函数的声明 
  int m;
  printf("input the number of diskes:");
  scanf("%d",&m);
  printf("The step to move %d diskes:\n",m);
  hanoi(m,'A','B','C');
  return 0;
}

void hanoi(int n,char one,char two,char three)          // 定义hanoi函数  
    // 将n个盘从one座借助two座,移到three座 
 {
   void move(char x,char y);       // 对move函数的声明 
   if(n==1)
     move(one,three);
   else
    {
     hanoi(n-1,one,three,two);
     move(one,three);
     hanoi(n-1,two,one,three);
    }
 }

 void move(char x,char y)           //  定义move函数 
 {
    printf("%c-->%c\n",x,y);
 }

