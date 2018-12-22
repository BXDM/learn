#include <dos.h>
#include <stdio.h>


void DetectHDD()
{
	struct dfree diskfree;
	struct fatinfo fatinfo;
	puts("The information of the current disk is :\n");
	getdfree(0,&diskfree);
	getfat(0,&fatinfo);
	puts("----------------- hard disk space ------------------");
	printf(">>The num of avaible clusters is : %d\n",diskfree.df_avail);
	printf(">>The num of all clusters is : %d\n",diskfree.df_total);
	printf(">>The num of bytes of every sector is : %d\n",diskfree.df_bsec);
	printf(">>The num of sectors of every cluster is : %d\n",diskfree.df_sclus);
	puts("----------- file allocation table -------------");
	printf(">>The num of sectors of every cluster is : %d\n",fatinfo.fi_sclus);
	printf(">>The num of bytes of file allocation table is : %d\n",fatinfo.fi_fatid);
	printf(">>The num of clusters is : %d\n",fatinfo.fi_nclus);
	printf(">>The num of ytes of every sector is : %d\n",fatinfo.fi_bysec);
}
void main()
{                    
	DetectHDD();
	getch();
} 