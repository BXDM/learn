#include <stdio.h>
#include <dos.h>
struct SYSTEMINFO
{
	 unsigned char current_second;      /*当前系统时间（秒）*/
	 unsigned char alarm_second;        /*闹钟时间（秒）*/
	 unsigned char current_minute;      /*当前系统时间（分）*/
	 unsigned char alarm_minute;        /*闹钟时间（分）*/
	 unsigned char current_hour;        /*前系统时间（小时）*/
	 unsigned char alarm_hour;          /*闹钟时间（小时）*/
	 unsigned char current_day_of_week; /*当前系统时间（星期几）*/
	 unsigned char current_day;         /*当前系统时间（日）*/
	 unsigned char current_month;       /*当前系统时间（月）*/
	 unsigned char current_year;        /*当前系统时间（年）*/
	 unsigned char status_registers[4]; /*寄存器状态*/
	 unsigned char diagnostic_status;   /*诊断位*/
	 unsigned char shutdown_code;		/*关机代码*/
	 unsigned char drive_types;			/*驱动类型*/
	 unsigned char reserved_x;          /*保留位*/
	 unsigned char disk_1_type;			/*硬盘类型*/
	 unsigned char reserved;			/*保留位*/
	 unsigned char equipment;			/*设备号*/
	 unsigned char lo_mem_base;					
	 unsigned char hi_mem_base;
	 unsigned char hi_exp_base;
	 unsigned char lo_exp_base;
	 unsigned char fdisk_0_type;		/*软盘驱动器0类型*/
	 unsigned char fdisk_1_type;		/*软盘驱动器1类型*/
	 unsigned char reserved_2[19];		/*保留位*/
	 unsigned char hi_check_sum;
	 unsigned char lo_check_sum;
	 unsigned char lo_actual_exp;
	 unsigned char hi_actual_exp;
	 unsigned char century;				/*世纪信息*/
	 unsigned char information;
	 unsigned char reserved3[12];		/*保留位*/
};
int main()
{
	struct SYSTEMINFO systeminfo;		/*声明SYSTEMINFO结构变量*/
	int i,size;							/*声明整型变量*/
	char *ptr_sysinfo,byte;				/*声明字符指针变量与字符变量*/
	clrscr();							/*清屏*/								
	puts("********************************************");
	puts("* Get configure information of your system *");
	puts("********************************************");
	size=sizeof(systeminfo);			/*结构占用字节数*/
	ptr_sysinfo=(char*)&systeminfo;		/*将结构地址转换为字符指针*/
	for(i=0;i<size;i++)
	{
	    outportb(0x70,(char)i);				/*输出整数到硬件端口中*/
	    byte=inportb(0x71);				/*从硬件端口中输入*/
	    *ptr_sysinfo++=byte;			/*以字节为单位依次为变量SYSTEMINFO赋值*/
	}
	printf("--The hard disk type is: %d.\n", systeminfo.disk_1_type);/*硬盘类型*/
	printf("--The drive type     is: %d.\n", systeminfo.drive_types);/*驱动类型*/
	printf("--The equipment_num  is: %d.\n", systeminfo.equipment);	/*设备号*/
	/*当前日期*/
	printf("--The current date   is: %x/%x/0%x.\n",systeminfo.current_day,systeminfo.current_month,systeminfo.current_year);
	/*当前时间*/
	printf("--The current time   is: %x:%x:%x.\n", systeminfo.current_hour,systeminfo.current_minute,systeminfo.current_second);
	/*警报时间*/
	printf("--The alarm time     is: %x:%x:%x.\n", systeminfo.alarm_hour,systeminfo.alarm_minute,systeminfo.alarm_second);
	getch();							/*获取字符，用户在WIN2000以上操作系统防止程序自动关闭*/
	return 0;
}
