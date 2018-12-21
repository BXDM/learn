#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<dos.h>
void guess(int n)
{
   int acount,bcount,i,j,k=0,flag,a[10],b[10];
   do
   {
       flag=0;
       srand((unsigned)time(NULL));/*利用系统时钟设定种子*/
       for(i=0;i<n;i++)
           a[i]=rand()%10;/*每次产生0—9范围内任意的一个随机数并存到数组a中*/
       for(i=0;i<n-1;i++)
       {
           for(j=i+1;j<n;j++)
               if(a[i]==a[j])/*判断数组a中是否有相同数字*/
               {
                   flag=1;/*若有上述情况则标志位置1*/
                   break;
               }
       }
   }while(flag==1);/*若标志位为1则重新分配数据*/
   do
   {
       k++;/*记录猜数字的次数*/
       acount=0;/*每次猜的过程中位置与数字均正确的个数*/
       bcount=0;/*每次猜的过程中位置不正确但数字正确的个数*/
       printf("guess:");
       for(i=0;i<n;i++)
           scanf("%d",&b[i]);/*输入猜测的数据到数组b中*/
       for(i=0;i<n;i++)
           for(j=0;j<n;j++)
           {
               if(a[i]==b[i])/*检测输入的数据与计算机分配的数据相同且位置相同的个数*/
               {
                   acount++;
                   break;
               }
               if(a[i]==b[j]&&i!=j)/*检测输入的数据与计算机分配的数据相同但位置不同的个数*/
               {
                   bcount++;
                   break;
               }
           }
       printf("clue on:%d A %d B\n\n",acount,bcount);
       if(acount==n)/*判断acount是否与数字的个数相同*/
       {
           if(k==1)
               printf(" you are the topmost rung of Fortune's ladder!! \n\n");
           else if(k<=5)
               printf("you are genius!!\n\n");
           else if(k<=10)
               printf("you are cleaver!!\n\n");
           else
               printf("you need try hard!!\n\n");
           break;
       }
   }while(1);
}

main()
{int i,n;
while(1)
{       clrscr();
	gotoxy(15,6);/*将光标定位*/
	printf("1.start game?(y/n)");
		gotoxy(15,8);
		printf("2.Rule");
	gotoxy(15,10);
	printf("3.exit\n");
	gotoxy(25,15);
printf("please choose:");
scanf("%d",&i);
switch(i)
{
case 1:                 clrscr();
	printf("please input n:\n");
	scanf("%d",&n);
guess(n);/*调用guess函数*/
sleep(5);/*程序停止5秒钟*/
break;
case 2:/*输出游戏规则*/
clrscr();
printf("\t\tThe Rules Of The Game\n");
printf(" step1: input the number of digits\n");
printf(" step2: input the number,separated by a space between two numbers\n");
printf(" step3: A represent location and data are correct\n");
printf("\tB represent location is correct but data is wrong!\n");
sleep(10);
break;
case 3:/*退出游戏*/
exit(0);
default:break;
}
}
}