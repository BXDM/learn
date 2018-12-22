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

void ClearStack(SeqStack *S)							/*清空栈*/
{
	S->top = S->base;
}

void LineEdit(SeqStack *S)								/*自定义行编辑程序*/
{
	int i = 0, a[100], n;									/*定义变量数据类型为基本整型*/
	char ch;										/*定义ch为字符型*/
	ch = getchar();									/*将输入字符赋给ch*/
	while (ch != '\n')									/*当未输入回车时执行循环体语句*/
	{
		i++;										/*记录进栈元素个数*/
		switch (ch)									/*判断输入字符*/
		{
		case '#':									/*当输入字符为#*/
			Pop(S);								/*出栈*/
			i -= 2;								/*元素个数减2*/
			break;
		case '@':									/*当输入字符为@*/
			ClearStack(S);							/*清空栈*/
			i = 0;								/*进栈元素个数清零*/
			break;
		default:
			Push(S, ch);							/*当不是#和@，其余元素进行进栈操作*/
		}
		ch = getchar();								/*接收输入字符赋给ch*/
	}
	for (n = 1; n <= i; n++)								/*将栈中元素存入数组中*/
	{
		a[n] = Top(S);
		Pop(S);
	}
	for (n = i; n >= 1; n--)								/*将数组中的元素输出*/
		printf("%c", a[n]);
}

void main() /*主函数*/
{
	SeqStack *ST;
	printf("please input\n");
	Initial(ST);
	LineEdit(ST);									/*调用行编辑函数*/
}
