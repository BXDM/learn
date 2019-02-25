## Latex学习笔记

[TOC]

#### 一、基本类型

```
文档类

article    排版科技期刊、短报告、程序文档、邀请函等。
report    排版多章节的长报告、短篇的书籍、博士论文等。
book      排版书籍。
slides    排版幻灯片。其中使用了较大的 sans serif 字体。也可以考虑使用 FoilTEX 来得到相同的效果。

 文档类的选项

纸张大小（a4paper，a5paper，b4paper，letterpaper，legalpaper，executivepaper）：
默认的letterpaper 纸张常见于美国，和国内常用的A4 纸张的大小稍有差别，建议自己指定。

字体大小（10pt，11pt，12pt）：默认为10pt。

纸张方向（portrait，landscape）：默认为portrait（纵向），在屏幕阅读也许landscape（横向）更方便。

草稿定稿（draft，final）：默认为final（定稿）；如果是draft（草稿），页面内容有溢出时会显示粗黑条。

单面双面（oneside，twoside）：对于article 和report 文档类，默认设置为单面，页码总是在右边；对于book 文档类，默认设置为双面，奇数页页码在右边，偶数页页码在左边，这样双面打印时页码总在外侧。

新章开始（openright，openany）：仅对book 文档类有效，默认值为openright，即每章都从奇数页开始；如果设置为openany，则每章仅从新的一页开始，不管奇偶页。
```

#### 二、基本操作

Ctrl + =  		显示行号

加注释：[ctrl]+[alt]+[shift]+[→]

取消注释：[ctrl]+[alt]+[shift]+[←]

#### 基本文档格式

\quad		空格

\qquad		大空格

#### 中文支持

```	   \documentclass[UTF8]{ctexart}```

#### Package

- qrcode：生成对应的二维码

  ```\documentclass{article} 
  \usepackage{qrcode} 
  \begin{document} 
  This is a qrcode for Google HK. 
  \qrcode{[https://www.google.com.hk/}](https://www.google.com.hk/%7D) 
  \end{document}```
  ```

#### 三、段落格式

#### 1、标题、作者和注释

**\maketitle** :生成文章题目和作者，没有此项则不会显示题目

```
\documentclass{article}
\author{My Name}
\title{The Title}
\begin{document}
\maketitle
hello, world % This is comment
\end{document}
```
#### 2、段落和章节

```
\documentclass{article}
\title{Hello World}
\begin{document}
\maketitle
\section{Hello China} China is in East Asia.
\subsection{Hello Beijing} Beijing is the capital of China.
\subsubsection{Hello Dongcheng District}
\paragraph{Tian'anmen Square}is in the center of Beijing
\subparagraph{Chairman Mao} is in the center of Tian'anmen Square
\subsection{Hello Guangzhou}
\paragraph{Sun Yat-sen University} is the best university in Guangzhou.
\end{document}
```
#### 3、目录
```
\documentclass{article}
\begin{document}
\tableofcontents
\section{Hello China} China is in East Asia.
\subsection{Hello Beijing} Beijing is the capital of China.
\subsubsection{Hello Dongcheng District}
\paragraph{Hello Tian'anmen Square}is in the center of Beijing
\subparagraph{Hello Chairman Mao} is in the center of Tian'anmen Square
\end{document}
```
#### 4、换行
```
\documentclass{article}
\begin{document}
Beijing is
the capital
of China.

New York is

the capital

of America.

Amsterdam is \\ the capital \\
of Netherlands.
\end{document}
```

#### 5、数学公式

偏微分∂：  ```f(x) = \frac{\partial    y   }{\partial    t}```

$$f(x) = \frac{\partial    y   }{\partial    t}$$

求和：```sum_{ i = 0 }^{n}f(x)```

$$ \sum _{ i = 0 }^{n}f(x )$$

```\documentclass{article}
\usepackage{amsmath}
\usepackage{amssymb}
\begin{document}
The Newton's second law is F=ma.

The Newton's second law is $F=ma$.

The Newton's second law is
$$F=ma$$

The Newton's second law is
\[F=ma\]

Greek Letters $\eta$ and $\mu$

Fraction $\frac{a}{b}$

Power $a^b$

Subscript $a_b$

Derivate $\frac{\partial y}{\partial t} $

Vector $\vec{n}$

Bold $\mathbf{n}$

To time differential $\dot{F}$

Matrix (lcr here means left, center or right for each column)
\[
\left[
\begin{array}{lcr}
a1 & b22 & c333 \\
d444 & e555555 & f6
\end{array}
\right]
\]

Equations(here \& is the symbol for aligning different rows)
\begin{align}
a+b&=c\\
d&=e+f+g
\end{align}

\[
\left\{
\begin{aligned}
&a+b=c\\
&d=e+f+g
\end{aligned}
\right.
\]

\end{document}
```
多行公式环境

```latex
\begin{align*}
	公式 1  \\
	公式 2  \\
\end{align*}
```


#### 6、图片

```
\documentclass{article}
\usepackage{graphicx}
\begin{document}
\includegraphics[width=4.00in,height=3.00in]{figure1.eps}
\end{document}
```
#### 7、表格
```\documentclass{article}
\begin{document}
\begin{tabular}{|c|c|}
a & b \\
c & d\\
\end{tabular}

\begin{tabular}{|c|c|}
\hline
a & b \\
\hline
c & d\\
\hline
\end{tabular}

\begin{center}
\begin{tabular}{|c|c|}
\hline
a & b \\ \hline
c & d\\
\hline
\end{tabular}
\end{center}
\end{document}
```

#### 8、问题解决

latex的bib文件中添加中文文献报错？

问题来源：所使用的bib文件编辑工具

解决方法：将bib文件的编码格式设为UTF8



#### 四、PowerPoint安装IguanaTex方法

​	 *前提：电脑已经配置好latex环境*

1.下载**IguanaTex_v1_56**插件

​	官网：<http://www.jonathanleroux.org/software/iguanatex/download.html>

​	下载的文件格式为：[IguanaTex v1.56 (.ppam)](http://www.jonathanleroux.org/software/iguanatex/IguanaTex_v1_56.ppam)  **.ppam**

2.将**IguanaTex v1.56 .ppam**移动到**C:\Users\ `你的用户名`\AppData\Roaming\Microsoft\AddIns**目录下。

​	在C盘创建一个空白文件夹，并复制该文件夹路径。

3.打开PowerPoint > 文件 > 选项 > 加载项 > 管理 > 下拉 > 选择PowerPoint加载项，选择**IguanaTex v1.56 .ppam**

4.在PowerPoint面板点击**IguanaTex**，点击**main settings**,在路径处粘贴之前创建的文件夹路径。

[参考文献](http://www.jonathanleroux.org/software/iguanatex/download.html)

>Installation:
>	1.Load the add-in: 
>in "File" > "Options" > "Add-Ins" > "Manage:", choose "PowerPoint Add-Ins" then "Go...", then click "Add New", select the .ppam file in the default Add-In folder or in the folder where you downloaded it, then "Close"
>	2.Create and set a temporary file folder:
>IguanaTex needs access to a folder with read/write permissions to store temporary files.
>	The default is "C:\Temp\". If you have write permissions under "C:\", create the folder "C:\Temp\". You're all set.
>	If you cannot create this folder, choose/create a folder with write permission at any other location. In the IguanaTex tab, choose "Main Settings" and put the path to the folder of your choice. You can also use a relative path under the presentation's folder (e.g., ".\" for the presentation folder itself).
>	3.(Optional, for pdflatex/xelatex/lualatex support) Install and set path to GhostScript and ImageMagick:
>To use the PDF to PNG conversion (i.e., with pdflatex, xelatex and lualatex) instead of the default DVI to PNG one, you need to install GhostScript and ImageMagick and set the appropriate full paths to gswin32c.exe/gswin64c.exe (note the "c"!) and convert.exe in the "Main Settings" window. When installing ImageMagick, make sure to check the box to "Install development headers and libraries for C and C++" and (in recent versions) to "Install legacy utilities (e.g. convert)". Download links are provided in the Main Settings window.
>	4.(Optional, for vector graphics support) Install and set path to TeX2img:
>To use vector graphics output, you need to install TeX2img (here is the direct download link for recommended version 2.1.0). After unpacking TeX2img somewhere on your machine, please run TeX2img.exe once to set the various paths to latex/ghostscript, then set the full path to TeX2imgc.exe (note the "c"!) in the "Main Settings" window.

