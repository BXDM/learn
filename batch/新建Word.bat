::新建一个Word文件

@echo off
color f0
title 新建Word文档
echo ==============================================
echo 请输入文件名称：
echo ==============================================
set/p name=
echo %name%
echo ==============================================>>%name%.docx
echo %name%>>%name%.docx
echo ==============================================>>%name%.docx
start winword %name%.docx

