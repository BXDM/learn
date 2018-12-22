#include<stdio.h>
int main()
  {FILE *fp1,*fp2;
   fp1=fopen("file1.dat","r");              // 打开输入文件  
   fp2=fopen("file2.dat","w");              // 打开输出文件  
   while(!feof(fp1)) putchar(getc(fp1));    // 逐个读入字符并输出到屏幕  
   putchar(10);                             // 输出一个换行 
   rewind(fp1);                             // 使文件位置指示器返回文件头  
   while(!feof(fp1)) putc(getc(fp1),fp2);   // 从文件头重新逐个读字符，输出到file2文件  
   fclose(fp1);fclose(fp2);
   return 0;
  }

