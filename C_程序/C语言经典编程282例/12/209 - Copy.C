#include <stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

#define STACK_SIZE 100 /*假定预分配的栈空间最多为100个元素*/  
char PASSWORD[10]= "13579";	
typedef char DataType;/*假定栈元素的数据类型为字符*/  	
typedef struct{
	DataType *base;
	DataType *top;
	int stacksize;
	int length;
}SeqStack;   
/* 置栈空*/

void Initial(SeqStack *s)
{
	s->base=(DataType *)malloc(STACK_SIZE * sizeof(DataType));
	if(!s->base) exit (-1);
	s->top=s->base;
	s->stacksize=STACK_SIZE;
	s->length=0;
} 
/*判栈空*/
int IsEmpty(SeqStack *S)
{
	return S->top==S->base;
}
/*判栈满*/
int IsFull(SeqStack *S)
{
	return S->top-S->base==STACK_SIZE-1;
}
/*进栈*/
void Push(SeqStack *S,DataType x)
{
	if (IsFull(S))
	{
		printf("栈上溢"); /*上溢,退出运行*/
		exit(1);
	}
	*(S->top++) =x;/*栈顶指针加1后将x入栈*/
	++S->length;
	/* printf("%c",*S->top);*/
}
/*出栈*/
DataType Pop(SeqStack *S)
{
	if(IsEmpty(S))
	{
		printf("栈为空"); /*下溢,退出运行*/
		exit(1);
	}
	--(S->length);	
	
	return *--S->top;/*栈顶元素返回后将栈顶指针减1*/
}
/* 取栈顶元素*/
DataType GetTop(SeqStack *S,DataType *e)
{
	if(IsEmpty(S))
	{
		printf("栈为空"); /*下溢,退出运行*/
		exit(1);
	}
	*e= *(S->top-1);
	S->top--;
}
void change(SeqStack *s,char *a)
{
	int n=s->length-1;
	while(!IsEmpty(s))
	{
		GetTop(s,&a[n--]);}
}
void clearstack(SeqStack *s)
{
	s->top=s->base;
	s->length=0;
}

void PwdSet(SeqStack *s)
{
	int i=0,k,j=0;
	DataType ch,*a;
	k=strlen(PASSWORD);
	printf("input password ");
	for(;;)
	{
		if(i>=3)
		{
			i++;
			break;
		}
		else if(i>0 && i<3)
		{
			
			for(j=1;j<=s->length;j++)printf(" ");
			clearstack(s);	
		}
		for(;;)
		{
			ch=getch();
			if(ch!=13)
			{
				if(ch==8){
					Pop(s);
					gotoxy(4+j,2);
					printf(" ");
					gotoxy(4+j,2);
				}
				else{printf("*");Push(s,ch);}
				j=s->length;
				
			}
			else 
			{printf("\n");
			break;}
		}
		i++;
		if(k!=j)continue;
		else
		{
			a=(DataType *)malloc(s->length * sizeof(DataType));
			change(s,a);
			
			for(j=1;j<=s->length;)
			{
				
				if(*(a+j-1)==PASSWORD[j-1]) j++;	
				else
				{
					
					j=s->length+2;
					printf("\n passwrod wrong!\n");
					break;
				}	
			}
			if(j==s->length+2)continue;
			else break;
		}
	}
	if(i==4)printf("\n Have no chance,It will quit!");
	else printf("\n password right!\n");
	free(a);
}

void main()
{
	SeqStack *s;
	clrscr();
	Initial(s);
	PwdSet(s);
	
	getch();
	
}
