#include <stdio.h>
#define STACK_SIZE 100 							/*假定预分配的栈空间最多为100个元素*/
typedef char DataType;								/*设定DataType的代表的数据类型为字符型*/

typedef struct									/*定义结构体*/
{
	DataType *base;								/*定义栈底指针*/
	DataType *top;								/*定义栈顶指针*/
	int stacksize;								/*定义栈的大小*/
} SeqStack;										/*SeqStack为该结构体类型*/

void Initial(SeqStack *S) /*初始化栈*/
{
	S->base = (DataType*)malloc(STACK_SIZE *sizeof(DataType));
	if (!S->base)
		exit( - 1);
	S->top = S->base;								/*栈为空时栈顶栈底指针指向同一处*/
	S->stacksize = STACK_SIZE;
}

int IsEmpty(SeqStack *S)							/*判栈空*/
{
	return S->top == S->base;
}

int IsFull(SeqStack *S)									/*判栈满*/
{
	return S->top - S->base == STACK_SIZE - 1;
}

void Push(SeqStack *S, DataType x)						/*进栈*/
{
	if (IsFull(S))
	{
		printf("overflow");								/*上溢,退出运行*/
		exit(1);
	}
	else
		*S->top++ = x;								/*栈顶指针加1后将x入栈*/
}

void Pop(SeqStack *S)									/*出栈*/
{
	if (IsEmpty(S))
	{
		printf("NULL");								/*下溢,退出运行*/
		exit(1);
	}
	else
		--S->top;									/*栈顶元素返回后将栈顶指针减1*/
}

DataType Top(SeqStack *S)								/* 取栈顶元素*/
{
	if (IsEmpty(S))
	{
		printf("empty");								/*下溢,退出运行*/
		exit(1);
	}
	return *(S->top - 1);
}

int match(SeqStack *S, char *str)
{
	char x;
	int i, flag = 1;
	for (i = 0; str[i] != '\0'; i++)
	{
		switch (str[i])
		{
		case '(':
			Push(S, '(');
			break;
		case '[':
			Push(S, '[');
			break;
		case '{':
			Push(S, '{');
			break;
		case ')':
			x = Top(S);
			Pop(S);
			if (x != '(')
				flag = 0;
			break;
		case ']':
			x = Top(S);
			Pop(S);
			if (x != '[')
				flag = 0;
			break;
		case '}':
			x = Top(S);
			Pop(S);
			if (x != '{')
				flag = 0;
			break;
		}
		if (!flag)
			break;
	}
	if (IsEmpty(S) == 1 && flag)
		return 1;
	else
		return 0;
}

void main()
{
	SeqStack *st;
	char str[100];
	Initial(st);
	gets(str);
	if (match(st, str))
		printf("matching\n");
	else
		printf("no matching\n");
}
