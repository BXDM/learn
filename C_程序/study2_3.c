//函数的使用
//例7.1，p171
#include<stdio.h>
int main()
{
	void print_star();	//函数声明
	void print_message();
	print_star();	//函数调用
	print_message();
	print_star();
	return 0;
}

void print_star()
{
	printf("**************\n");
}

void print_message()
{
	printf("hello,world!\n");
}