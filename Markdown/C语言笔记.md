#### 一、C程序的基本结构

2018-11-9.12

##### （一）基本程序结构

```#include<stdio.h>```:调用系统库函数（如printf函数）
*stdio.h*一个文件（标准输入输出文件，头文件，必须放在第一行）
int ：整型的数值
```int main（）```：返回函数的数值，小括号里存放函数的**列表**
printf函数的作用：在屏幕上输出括号里的内容，**\n**:转义字符
```return 0 ```：函数执行完后，返回值为0
函数体用{}包含起来

```c
#include<stdio.h>  
int main()
{
	printf("this is the fist c program!\n");

	return 0;
}
```

##### （二）简单程序设计

**1.标识符**	p[42]

[1]、只能由`字母`、`数字`、`下划线`组成

[2]、第一个字符必须为`字母`或`下划线`

##### （三）数据类型

double		双精度小数型

int 			基本整数型

##### （四）函数



#### 二、基本输入输出

**printf**的用法

printf提供如下数字格式符：

**d格式符**。用来输出一个有符号的`十进制整数`

s格式符。用来输出一个字符串。

**f格式符**。用来输出`单精度浮点数`

e格式符。指定以指数形式输出实数。

o格式符。以八进制整数形式输出。

x格式符。以十六进制数形式输出。s

**scanf**函数的用法：

```scanf("%a,%b,%c",&a,&b,&c)```

其中`&`为取址符不能省略

#### 三、关于循环

`i = 1;i <=  9;i++`	从 1 到 10 ；

`i = 1;i <  9;i++`	从 1 到 9

#### 四、 数值计算

##### （一）、基本表达式

`pow`函数		计算乘方

```c
#include <stdio.h>
#include <math.h>
double main()
{
    double p;
    p = pow(2.0,3.0);
    printf("x^y = %f\n",p);
    return 0;
}
```



#### 五、算法

###### 1.比较两个数的大小

直接替换

```c
int a,b,t;
    scanf("%d %d",&a,&b);
    if(a<b)
    {t = a;a = b;b = t;}
    printf("max is %d,min is %d\n",a,b );
```

使用条件判断

```c
int max,min,a,b;
	scanf("%d %d",&a,&b);
	max = (a>b)?a:b;
	min = (a>b)?b:a;
	printf("max is %d,min = %d",max,min);
```

使用指针

