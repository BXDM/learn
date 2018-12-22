#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#define Maxsize 30
#define TRUE 1
#define FALSE 0
char queue[Maxsize];
int front, rear;

void init()											 /*队首队尾指针初始化*/
{
	front = rear =  - 1;
}

int enqueue(char x) 									/*元素入队列*/
{
	if (front ==  - 1 && (rear + 1) == Maxsize)
		/*只有元素入队没有元素出队判断是否满足队满条件*/
	{
		printf("overflow!\n");
		return 0;
	}
	else if ((rear + 1) % Maxsize == front)					/*判断是否队满*/
	{
		printf("overflow!\n");
		return 0;
	}
	else
	{
		rear = (rear + 1) % Maxsize;						 /*rear指向下一位置*/
		queue[rear] = x;								 /*元素入队*/
		return 1;
	}
}

void dequeue() 										/*元素出队列*/
{
	if (front == rear)
		/*判断队列是否为空*/
		printf("NULL\n");
	else
		front = (front + 1) % Maxsize;
	/*队首指针指向下一个位置*/
}

char gethead() 										/*取队首元素*/
{
	if (front == rear)
		/*判断队列是否为空*/
		printf("NULL\n");
	else
		return (queue[(front + 1) % Maxsize]);
	/*取出队首元素*/
}

void main()
{
	char ch1, ch2;
	init(); 											/*队列初始化*/
	for (;;)
	{
		for (;;)
		{
			printf("A");
			if (kbhit())
			{
				ch1 = bdos(7, 0, 0);							 /*通过dos命令读入一个字符*/
				if (!enqueue(ch1))
				{
					printf("IS FULL\n");
					break;
				}
			}
			if (ch1 == ';' || ch1 == ',')
				/*判断输入字符是否是分号或逗号*/
				break;
		}
		while (front != rear)
			/*判断队列是否为空*/
		{
			ch2 = gethead(); /*取队首元素*/
			dequeue(); /*元素出队列*/
			putchar(ch2); /*输出该元素*/
		}
		if (ch1 == ';')
			/*判断输入的是否是分号*/
			break;
		/*跳出循环*/
		else
			ch1 = '';
	}
}

