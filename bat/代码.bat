::新建一个带后缀的文件并在notepad++中打开
@echo off
echo ===========================
echo 请输入文件名：
set /p name=
cd.>%name%

start notepad++ %name%
