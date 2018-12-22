#include <stdio.h>
int main( )                          // 定义主函数
{                                    // 主函数体开始
 int max(int x,int y);               // 对被调用函数max的声明 
 int a,b,c;                          // 定义变量a，b，c
 scanf("%d,%d",&a,&b);               // 输入变量a和b的值
 c = max(a,b);                       // 调用max函数，将得到的值赋给c 
 printf("max=%d\n",c);               // 输出c的值
 return 0;                           // 返回函数值为0
}

int max(int x,int y)                 //定义max函数,函数值为整型, 形式参数x和y为整型 
{
 int z;                              // max函数中的声明部分，定义本函数中用到的变量z为整型 
 if (x > y) z = x;
 else z = y;
 return(z);                          //将z的值返回，通过max带回到调用函数的位置
}
