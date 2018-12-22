::新建一个带名称的bat文件

@echo off
color f0
echo 请输入bat名称：
set/p name=
echo %name%
rem echo %name%>>%name%.bat
echo @echo off>>%name%.bat
start notepad %name%.bat