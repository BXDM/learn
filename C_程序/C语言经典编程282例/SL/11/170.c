main()
{
	char *strings[]={"赵XX",
				"钱XX",
				"孙XX",
				"李XX",
				"周XX"};			/*使用指针数组创建字符串数组*/
	char **p,i;							/*声明变量*/
	p=strings;							/*指针指向字符串数组首地址*/
	for(i=0;i<5;i++)						/*循环输出字符串*/
	{
		printf("%s\n",*(p+i));
	}
}
