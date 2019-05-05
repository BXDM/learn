@echo off
title 新建文件
echo 请输入文件名称：
echo.
set/p name=
echo %name%
cd.>  F:\文本文件\代码文件\%name%
start explorer F:\文本文件\代码文件\

