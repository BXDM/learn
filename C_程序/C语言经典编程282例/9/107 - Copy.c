#include<stdio.h>
main()
{
  int i,j,i1,j1,a[101][101],b[101][101];					/*定义变量的数据类型和数组类型*/
  printf("please input the number of rows(<=100)\n");		
  scanf("%d",&i1);								/*输入行数*/
  printf("please input the number of columns(<=100)\n");
  scanf("%d",&j1);								/*输入列数*/
  printf("please input the element\n");
  for(i=0;i<i1;i++)								/*控制行数*/
  for(j=0;j<j1;j++)								/*控制列数*/
  scanf("%d",&a[i][j]);								/*输入数组中的元素*/
  printf("array a:\n");								/*将输入的数据以二维数组的形式输出*/
  for(i=0;i<i1;i++)								/*控制输出的行数*/
  {
    for(j=0;j<j1;j++)								/*控制输出的列数*/
    printf("\t%d",a[i][j]);							/*输出元素*/
    printf("\n");									/*每输出一行元素进行换行*/
  }
  for(i=0;i<i1;i++)
  for(j=0;j<j1;j++)
  b[j][i]=a[i][j];									/*将a数组的i行j列元素赋给b数组的j行i列实现行列互换*/
  printf("array b:\n");								/*将互换后的b数组输出*/
  for(i=0;i<j1;i++)								/*b数组行数最大值为a数组列数*/
  {
    for(j=0;j<i1;j++)								/*b数组列数最大值为a数组行数*/
    printf("\t%d",b[i][j]);							/*输出b数组元素*/
    printf("\n");									/*每输出一行进行换行*/
  }
} 
