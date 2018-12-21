#include <stdio.h>
#define STACK_SIZE 100 /*假定预分配的栈空间最多为100个元素*/  	
typedef char DataType;/*假定栈元素的数据类型为字符*/  

typedef struct{
	DataType *base;
	DataType *top;
	int stacksize;
}SeqStack; 

/* 置栈空*/
void Initial(SeqStack *s)
{/*构造一个空栈*/
	s->base=(DataType *)malloc(STACK_SIZE * sizeof(DataType));
	if(!s->base) exit (-1);
	s->top=s->base;
	s->stacksize=STACK_SIZE;
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
	*S->top++ =x;/*栈顶指针加1后将x入栈*/
}
/*出栈*/
DataType Pop(SeqStack *S)
{
	if(IsEmpty(S))
	{
		printf("栈为空"); /*下溢,退出运行*/
		exit(1);
	}
	return *--S->top;/*栈顶元素返回后将栈顶指针减1*/
}
/* 取栈顶元素*/			
DataType Top(SeqStack *S)
{														
	if(IsEmpty(S))
	{
		printf("栈为空"); /*下溢,退出运行*/
		exit(1);
	}
	return *(S->top-1);
}

void conversion (int N,int B)
{/*假设N是非负的十进制整数，输出等值的B进制数*/
	int i;
	SeqStack *S;
	
	Initial(S);
	while(N){  /*从右向左产生B进制的各位数字，并将其进栈*/
		Push(S,N%B); /*将bi进栈0<=i<=j*/
		N=N/B;
	}
	
	while(!IsEmpty(S)){  /*栈非空时退栈输出*/
		i=Pop(S);
		printf("%d",i);
	}
}

void main()
{
	int n,d;
	printf("Input the integer you want to transform:");
	scanf("%d",&n);
	printf("Input the integer of the system: ");
	scanf("%d",&d);
	printf("result:");
	conversion(n,d);
	getch();
}
