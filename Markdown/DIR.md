#### DIR

##### 一、查看文件信息

​	1、查看类型

```
dir /ad		只查看文件夹
dir /a-d	只查看文件
dir /ah		查看隐藏文件	
```

​	2、查看方式

```
dir /w		按款列表查看
tree		以树状显示文件列表
dir /b		无摘要显示
dir /on		按名称查看
dir /os 	按大小查看
dir /od 	按时间查看
dir /oe	    按后缀查看
```



##### 二、打印文件信息

​	打印文件夹中的所有文件列表（不含子文件夹内的文件）

```
dir /b/a-d>list.txt
```

​	打印文件夹中所有文件列表

```
for /d /r  %%i in (*) do dir /b %%i>>list.txt
```

