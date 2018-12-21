#include <stdio.h>
struct time/*定义结构体time，存储时间信息*/
{
	int hour;
	int minute;
	int second;
}t;
void main()
{
	FILE *fp;/*定义文件类型指针fp*/
	fp=fopen("Time","r");/*以只读方式打开文件Time*/
	fread(&t,sizeof(struct time),1,fp);/*读取文件中信息*/
	while(!kbhit())/*当无按键时执行循环体语句*/
	{
		rewind(fp);/*将文件指针设置到文件起点*/
		sleep(1);/*程序停止1秒钟*/
		fread(&t,sizeof(struct time),1,fp);/*读取文件中的内容*/
		if(t.second==59)/*如果到60秒*/
		{
			t.minute=t.minute+1;/*如果到60秒分钟数加1*/
			if(t.minute==60)/*判断是否到60分钟*/
			{
				t.hour=t.hour+1;/*到60分钟小时数加1*/
				t.minute=0;/*分数置0*/
			}
			t.second=0;/*秒数置0*/
		}
		else
			t.second=t.second+1;/*秒数加1*/
		printf("%d:%d:%d\n",t.hour,t.minute,t.second);/*输出累积开机时间*/
		fp=fopen("Time","w");/*以可写方式打开Time文件*/
		fwrite(&t,sizeof(struct time),1,fp);/*定义结构体time，存储时间信息*/
		fclose(fp);/*关闭文件指针*/
	}
}
