rem 步长创建文件

@echo off 
md text
rem cd text
for /l %%i in (1,2,20) do cd.> text\%%i.txt