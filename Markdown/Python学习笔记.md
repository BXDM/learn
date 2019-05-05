## Python学习笔记

#### 基本操作

在cmd命令行里进入和退出Python程序
**进入**：直接输入python即可
**退出**：
```
1：输入exit()，回车
2：输入quit()，回车
3：输入ctrl+z，回车
```

安装离线库

<https://www.lfd.uci.edu/~gohlke/pythonlibs/#numpy>

#### Jupyter Notebook的使用

打开

命令行输入	 `Jupyter Notebook`

浏览器输入	 `http://localhost:8890/tree`

主题设置		<https://github.com/dunovank/jupyter-themes> 





#### 基本函数

**import**
`import moudle`
导入模块，将整个模块赋值给一个变量名。
加载多个模块：
`ipmport os,sys,types`
导入模块的部分：
`frome ... ipmort...`

**def**		定义函数
`def function_name(parameters):
	expressions`




#### 模块、类
###### （一）模块

1.什么是模块(moudle)？
模块是由一组类、函数与变量所组成，这些类都存储在文本文件中。

2.一些模块
**request**		访问web网络
**re**			字符串处理，匹配等
**os**			用于处理大量文件和路径的问题

###### （二）类

1.什么是类（class）？
类是封装的数据以及操作这些这些数据的接口函数所组成的一群对象的集合。**类是一个抽象的概念**，要用类来解决问题，必须创建一个实例化的对象。
`class(object)`