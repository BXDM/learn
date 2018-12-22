#include <stdio.h>
int main()
 {int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};
  int (*p)[4],i,j;                           // 指针变量p指向包含4个整型元素的一维数组
  p=a;                                       // p指向二维数组的0行
  printf("please enter row and colum:");
  scanf("%d,%d",&i,&j);                      // 指定元素的行列
  printf("a[%d,%d]=%d\n",i,j,*(*(p+i)+j));   // 输出a[i][j]的值
  return 0;
 }
