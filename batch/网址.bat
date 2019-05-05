@echo off
:menu
echo ====================================================
echo 请输入要打开的网址:
echo ====================================================

echo 1、百度          10、慕课网
echo 2、bilibili
echo 3、盘多多
echo 4、教务处
echo 5、图标
echo 6、壁纸
echo 7、百度文库
echo 8、知乎
echo 9、锤子便签
echo ----------------------------------------------------
echo p、退出
echo ====================================================
set/p num=


if %num% == 1 (start chrome baidu.com
cls
goto menu
)

if %num% == 2 (start chrome bilibili.com
cls
goto menu
)

if %num% == 3 (start chrome panduoduo.com
cls
goto menu
)

if %num% == 4 (start chrome jw.glut.edu.cn
cls
goto menu
)

if %num% == 5 (start chrome iconpng.com
cls
goto menu
)

if %num% == 6 (start chrome alpha.wallhaven.cc
cls
goto menu
)

if %num% == 7 (start chrome wenku.baidu.com
cls
goto menu
)

if %num% == 8 (start chrome zhihu.com
cls
goto menu
)

if %num% == 9 (start chrome https://yun.smartisan.com/#/
cls
goto menu
)

if %num% == 10 (start chrome https://www.icourse163.org/
cls
goto menu
)
if %num% == p exit











