::调用pandoc,将tex文件转换为word文档
@echo off
echo 请输入需要转换的文件名(不带后缀）：
set /p name=名称：
echo %name%.tex
pandoc -s %name%.tex -o %name%.docx
::pandoc -s a.tex -o b.docx