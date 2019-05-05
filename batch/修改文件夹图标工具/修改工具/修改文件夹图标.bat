@echo off
echo 使用方法：
echo 将图标文件和图标信息.txt、修改工具总共3个文件放入要修改的文件夹中，双击修改工具。注意：有ico格式的文件夹中不可用。
pause
copy 图标信息.txt a.txt
ren *.ico icon.ico
ren a.txt desktop.ini
attrib desktop.ini +h +s +r
attrib icon.ico +h
echo 完成......
pause