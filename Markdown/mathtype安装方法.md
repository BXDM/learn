## Mathtype安装方法

[参考文献](https://jingyan.baidu.com/article/a17d5285d9b9348099c8f263.html)

*特别说明：具体路径需根据自己的安装目录*

1.首先要找出office及mathtype的安装路径

比如office安装路径为`C:\Program Files\Microsoft Office`，

mathtype安装路径为`D:\Program Files (x86)\MathType`。



2.确保路径被office信任。

依次打开word->文件->选项->信任中心->信任中心设置->受信任的位置->添加新位置

添加`C:\Program Files\Microsoft Office\root\Office16\STARTUP\`



3.在MathType安装目录下找到以下文件(以64为系统为例)：

（1） D:\Program Files (x86)\MathType\ `MathPage\64\MathPage.wll`

将**MathPage.wll**拷贝到`C:\Program Files\Microsoft Office\root\Office16`之下，**而不是**都拷贝到**STARTUP**文件夹中。

（2） D:\Program Files (x86)\MathType\ `Office Support`\64\MathType Commands 6 For Word 2016.dotm

将**MathType Commands 6 For Word 2016.dotm**拷贝到`C:\Program Files\Microsoft Office\root\Office16\STARTUP`,



5.关闭word重启。

> 特别注意：复制 mathpage.wll 时需严格对应自己的office 版本，严格区分32位还是64位，要对应。
>
> 若为 office 2010版本，需要将 mathpage.wll 复制到 C:\Program Files (x86)\Microsoft Office\Office14 目录（没有root目录）