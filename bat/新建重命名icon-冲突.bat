::可以生成一个以网址为名称的txt文件

@echo off
set /p name=名称：
set /p address=网址：

echo 名称：%name%
echo 名称：%name%>>%name%.txt
echo 网址：%address%
echo 网址：%address%>>%name%.txt
pause
start %name%.txt
