#include<stdio.h>
int palind(char str[],int k,  int i)							/*自定义函数检测是否为回文字符串*/
{
	if(str[k]==str[i-k]&&k==0)							/*递归结束条件*/
		return 1;
	else if(str[k]==str[i-k])								/*判断相对应的两个字符是否相等*/
		palind(str,k-1,i);   							/*递归调用*/
	else
		return 0;
}
main()
{
	int i=0,n=0;										/*i记录字符个数，n是函数返回值*/
	char ch,str[20];
	while ((ch=getchar())!='\n')
	{
		str[i]=ch;
		i++;
	}
	if(i%2==0)										/*当字符串中字符个数为偶数时*/
	{
		n=palind(str,(i/2),i-1);
	}
	else
	{
		n=palind(str,(i/2-1),i-1);							/*当字符串中字符个数为奇数时*/
	}
	if(n==0)
	{
		printf("not palindrome");						/*当n为0说明不是回文数，否则是回文数*/
	}
	else
	{
		printf("palindrome\n");
	}
	getch();
	return 0;
}
