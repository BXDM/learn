@echo off
color f0
title 新建txt
echo ==============================================
echo 请输入文件名称：
echo ==============================================
set/p name=
echo %name%
echo ==============================================>>%name%.txt
echo %name%>>%name%.txt
echo ==============================================>>%name%.txt
echo.>>%name%.txt
start notepad %name%.txt

