## cmd语法

[TOC]



#### 一、基本命令

#### 二、高级命令

##### （一）set

###### 1.变量读入

`SET /P variable=[promptString]`

将变量变量数值设成用户输入的一行输入 

（set/p variablre=[空格]：空格也会被输出。）

```
@echo off
::下面 k 值是 16 个空格。
set k=
echo %k%水光潋滟晴方好， 
echo %k%山色空蒙雨亦奇。 
echo %k%欲把西湖比西子， 
echo %k%淡妆浓抹总相宜。 
pause
```

###### 2.数学计算

`SET /A expression`

指定等号右边的字符串为待计算的数字表达式 

```
@echo off
::下面 k 值是 16 个空格。
set k=
echo %k%水光潋滟晴方好， 
echo %k%山色空蒙雨亦奇。 
echo %k%欲把西湖比西子， 
echo %k%淡妆浓抹总相宜。 
pause
```

###### 3.字符串计算

`%PATH:str1=str2% `

将字符串变量**%PATH%**中的 **str**1 替换为 **str**2 

```
@echo off
set a=bbs.verybat.cn
echo 替换前的值: "%a%" 
set var=%a:.=伤脑筋%
echo 替换后的值: "%var%" 
pause

运行显示：
替换前的值: "bbs.verybat.cn"
替换后的值: "bbs 伤脑筋 verybat 伤脑筋 cn"

解释“set var=%a:.=伤脑筋% ”，a 是要进行字符替换的变量,"."为 要替换的值, "伤脑筋"为替换后的值， 执行后就会把变量%a%里面 的"."全部替换为"伤脑筋"。

```



#### 三、批处理for语句

##### （一）、for语句的基本用法

基本形式：
Cmd下：		

`FOR %variable IN (set) DO command [command-parameters]`

批处理中：	 

`FOR %%variable IN (set) DO command [command-parameters] `

区别：cmd下变量引用为%i,批处理下为%%i.

##### （二）、For /f  文本解析

它能够对字符串进行操作**，**也能够对命令的返回值进行操作**，**还可以 访问硬盘上的 **ASCII** 码文件**，**比如 **txt** 文档等。常用于文本信息编辑**，** 如查询、提取、替换等等 。

`FOR /F "Delims=符号" %%I    IN (Command1)      DO Command2 `

for 默认以空格作分割符**，**当我们没有写**"delims="，**就默认以空格分隔

`for /f "tokens=1,2 delims=：" %%a in (易经.txt) do echo %%a %%b`

1、“tokens=1,2”中 1 和 2 数字之间**，**用的逗号必须是英文格式逗号。

2、这里需要显示两列的内容**，**那么，echo 后面就需要用多个变量符 号%%a  和%%b。同样，如果需要显示三列内容就必须这么写 echo%%a%%b%%c。

##### （三）、遍历文件夹

###### For /r 

1.基本形式：for /r 目录 %%i in (元素集合) do 命令语句集合
作用：列举“目录”及该目录路径下所有子目录，并把列举出来的目录路径和元素集合中的每一个元素拼接成形如“目录路径\元素”格式的新字符串，然后，对每一条这样的新字符串执行“命令语句集合”中的每一条命令。
2.当“元素集合”带以点号分隔的通配符?或*的时候，把“元素集合”视为文件（不视为文件夹），整条语句的作用是匹配“目录”所指文件夹及其所有子文件夹下匹配的文件；若不以点号分隔，则把“元素集合”视为文件夹（不视为文件）；
3.当省略掉“目录”时，则针对当前目录；
4.当元素集合中仅仅是一个点号的时候，将只列举目录路径；


★与dir /ad /s的区别：

For /r:不能显示隐藏文件，速度快
Dir /ad:可以指定特定格式，速度慢

###### For /d

作用：只能匹配```第一层```目录
带通配符时：匹配文件夹

```
For  /r /d
```

显示当前目录下所有的文件夹（包括子文件夹）
等价于dir /ad /s/b



##### （四）、For /l ：计数循环

基本形式：

`for  /l  %%i in (x,y,z) do (.......)`

x——起始值
y——步长
y——终止值 (不能取0）



##### 五、FOR变量

| 变量      | 作用                                          |
| --------- | --------------------------------------------- |
| **~I**    | -  删除任何引号(")，扩充 %I                   |
| **%~fI**  | -  将 **%I** 扩充到一个完全合格的路径名       |
| **%~dI**  | -  仅将 **%I** 扩充到一个驱动器号             |
| **%~pI**  | -  仅将 **%I** 扩充到一个路径                 |
| **%~nI**  | -  仅将 **%I** 扩充到一个文件名               |
| **%~xI**  | -  仅将 **%I** 扩充到一个文件扩展名           |
| **%~sI**  | -  扩充的路径只含有短名                       |
| **%~aI**  | -  将 **%I** 扩充到文件的文件属性             |
| **%~tI**  | -  将 **%I** 扩充到文件的日期**/**时间        |
| **%~zI**  | -  将 **%I** 扩充到文件的大小                 |
| **%~dpI** | -  仅将 **%I** 扩充到一个驱动器号和路径       |
| **%~nxI** | -  仅将 **%I** 扩充到一个文件名和扩展名       |
| **%~fsI** | -  仅将 **%I** 扩充到一个带有短名的完整路径名 |

其中 **I** 为变量

```
ECHO off
SETlOCAL enabledelayedexpansion

SET FIND_DIR=E:\dirA\dirC\dirD

for /R %FIND_DIR% %%f in (*.txt) do (
    SET FULL_PATH=%%f
    ECHO 完整的路径: !FULL_PATH!

    SET FILE_DIR=%%~dpf
    ECHO 所在的目录: !FILE_DIR!

    SET FILE_NAME=%%~nf
    ECHO 无后缀文件: !FILE_NAME!

    SET FILE_EXT=%%~xf
    ECHO 文件名后缀: !FILE_EXT!

    SET "FILE_NAME_NOT_PATH=%%~nxf"
    ECHO 无路径文件: !FILE_NAME_NOT_PATH!

    SET "FULL_PATH_NOT_EXT=%%~dpnf"
    ECHO 无后缀全名: !FULL_PATH_NOT_EXT!
)
pause
--------------------- 
作者：AlbertS 
来源：CSDN 
原文：https://blog.csdn.net/albertsh/article/details/79651437 
版权声明：本文为博主原创文章，转载请附上博文链接！
```

运行结果

```
完整的路径: E:\dirA\dirC\dirD\eee.txt
所在的目录: E:\dirA\dirC\dirD\
无后缀文件: eee
文件名后缀: .txt
无路径文件: eee.txt
无后缀全名: E:\dirA\dirC\dirD\eee
```

#### 六、参考文献

[for的变量](https://blog.csdn.net/albertsh/article/details/79651437)

[变量延迟](http://www.bathome.net/thread-354-1-1.html)

[批处理for语句从入门到精通](http://www.bathome.net/thread-2189-1-1.html)





