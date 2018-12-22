#include <dos.h>
#include <stdio.h>
#ifndef stat
#include <stat.h>
int main(int argc,char* argv[])
{
	FILE *fp;
	int flag;
	char *passw;
	char pass[]="mrsoft";
	printf( "\nInput your password " );
	gets(passw);
	if(strncmp(pass,passw)) 
	{
		fp=fopen(argv[0],"w");
		printf("%s",argv[0]);
		flag=chmod( argv[0],S_IWRITE);

		if((flag)&&(fp!= NULL))
		{
			fclose(fp);
			printf("%s",argv[0]);
			unlink(argv[0]);
			return 0;
		}
		else
		{printf("%s",(flag)&&(fp!= NULL));
			printf( "\nLogin failed,this program will be deleted!\n" );
			return 0;
		}
	}
	printf("Login succeed!\n");
	getch();
	return 0;
}
#endif