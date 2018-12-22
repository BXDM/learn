#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int main()
{  FILE *fp;
   char  str[3][10],temp[10];   // str是用来存放字符串的二维数组，temp是临时数组  
   int i,j,k,n=3;
   printf("Enter strings:\n");    // 提示输入字符串 */
   for(i=0;i<n;i++)         
     gets(str[i]);              // 输入字符串
   
   for(i=0;i<n-1;i++)           // 用选择法对字符串排序  
     {k=i;
      for(j=i+1;j<n;j++)
	    if(strcmp(str[k],str[j])>0) k=j;
      if(k!=i)
        {strcpy(temp,str[i]);  
	     strcpy(str[i],str[k]);
	     strcpy(str[k],temp);
        }
	 }
   if((fp=fopen("D:\\CC\\string.dat","w"))==NULL)     // 打开磁盘文件 ,必须事先建好。 
        {
	     printf("can't open file!\n");
	     exit(0);
        }
   printf("\nThe new sequence:\n");
   for(i=0;i<n;i++)
	  {fputs(str[i],fp);fputs("\n",fp);       // 撤号 
	   printf("%s\n",str[i]);                 // 在屏幕上显示字符串  
     }
   return 0;
}
