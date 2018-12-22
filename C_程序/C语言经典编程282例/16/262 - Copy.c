#include <stdio.h>
#include <dos.h>
struct SYSTEMINFO
{
	 unsigned char current_second;      
	 unsigned char alarm_second;        
	 unsigned char current_minute;      
	 unsigned char alarm_minute;       
	 unsigned char current_hour;       
	 unsigned char alarm_hour;         
	 unsigned char current_day_of_week;
	 unsigned char current_day;        
	 unsigned char current_month;       
	 unsigned char current_year;        
	 unsigned char status_registers[4]; 
	 unsigned char diagnostic_status;   
	 unsigned char shutdown_code;		
	 unsigned char drive_types;			
	 unsigned char reserved_x;          
	 unsigned char disk_1_type;			
	 unsigned char reserved;			
	 unsigned char equipment;			
	 unsigned char lo_mem_base;			
	 unsigned char hi_mem_base;
	 unsigned char hi_exp_base;
	 unsigned char lo_exp_base;
	 unsigned char fdisk_0_type;		
	 unsigned char fdisk_1_type;		
	 unsigned char reserved_2[19];		
	 unsigned char hi_check_sum;
	 unsigned char lo_check_sum;
	 unsigned char lo_actual_exp;
	 unsigned char hi_actual_exp;
	 unsigned char century;				
	 unsigned char information;
	 unsigned char reserved3[12];		
};
int main()
{
	struct SYSTEMINFO systeminfo;		
	int i,size;							
	char *ptr_sysinfo,byte;				
	clrscr();									
	puts("********************************************");
	puts("* Get configure information of your system *");
	puts("********************************************");
	size=sizeof(systeminfo);		
	ptr_sysinfo=(char*)&systeminfo;	
	for(i=0;i<size;i++)
	{
	    outportb(0x70,(char)i);		
	    byte=inportb(0x71);			
	    *ptr_sysinfo++=byte;		
	}
	printf("--The hard disk type is: %d.\n", systeminfo.disk_1_type);
        printf("--The drive type     is: %d.\n", systeminfo.drive_types);
	printf("--The equipment_num  is: %d.\n", systeminfo.equipment);	

	printf("--The current date   is: %x/%x/0%x.\n",systeminfo.current_day,systeminfo.current_month,systeminfo.current_year);

	printf("--The current time   is: %x:%x:%x.\n", systeminfo.current_hour,systeminfo.current_minute,systeminfo.current_second);

	printf("--The alarm time     is: %x:%x:%x.\n", systeminfo.alarm_hour,systeminfo.alarm_minute,systeminfo.alarm_second);
	getch();						
	return 0;
}
