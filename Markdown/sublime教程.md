#### 一、Sublime的使用

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