#include<stdlib.h>
#include<stdio.h>
int num[]={125,-26,53,12,-6,95,46,85,-45,785};/*定义全局数组*/
main()
{
int i,comp1(),comp2();
clrscr();/*清屏*/
printf("the original array is:\n");
for(i=0;i<10;i++)/*将数组按原序输出*/
printf("%10d",num[i]);
qsort(num,10,sizeof(int),comp1);
printf("\n The accending sorted array is:\n");
for(i=0;i<10;i++)/*将数组按升序输出*/
printf("%10d",num[i]);
qsort(num,10,sizeof(int),comp2);
printf("\n The decending sorted array is:\n");
for(i=0;i<10;i++)/*将数组按降序输出*/
printf("%10d",num[i]);
getch();
}
comp1(int *i,int *j)
{
return *i-*j;
}
comp2(int *i,int *j)
{
return *j-*i;
}