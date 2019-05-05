::在"网址收藏.txt"文件中加入新的条目

@echo off
color f0
echo ============================================
echo.>>网址收藏.txt
set /p name=名称：
set /p address=网址：
echo 名称：%name%>>网址收藏.txt
echo 网址：%address%
echo 网址：%address%>>网址收藏.txt
