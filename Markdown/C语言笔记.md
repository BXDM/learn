#### Sublime的使用

配置编译环境（自带的编译器无法打开cmd控制台）

1.工具 > 编译系统 > 新建编译系统

2.输入以下内容：

```{
    "cmd": "gcc -g -Wall \"$file_name\" -o \"$file_base_name\"",
    "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
    "working_dir": "$file_path",
    "selector": "source.c",

    "variants":
    [
        {
            "name": "CMD Run",
            "shell_cmd": "gcc -g -Wall \"$file\" -o \"$file_base_name\" && start cmd /c \"\"${file_path}/${file_base_name}\" & pause\""
        },
        {
            "name": "Run in Sublime",
            "shell_cmd": "gcc -g -Wall \"$file\" -o \"$file_base_name\" && cmd /c \"${file_path}/${file_base_name}\""
        }
    ]
}
```

3.重命名，保存

sublime 多行注释：Ctrl + shift + /
sublime 单行注释：Ctrl +  /

批量修改：Alt + F3

​			反复按Ctrl + D，依次选中下一个

中文乱码问题：先按Ctrl + shift + C，再输入中文

#### 第一次课

C程序的基本结构
2018-11-12
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

程序的注释
单行注释：*//*
多行注释：*/*一整块函数*/*

**scanf**函数的用法：

```scanf("%a,%b,%c",&a,&b,&c)```