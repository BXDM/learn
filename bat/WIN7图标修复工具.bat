@echo off
title Win7图标损坏修复程序 V1.0 by 东坡下载 QQ：www.uzzf.com
color 70
echo ================================================================================
echo 使用说明：欢迎使用Win7图标损坏修复程序 V1.0。本程序用于修复Win7图标出现黑块儿、白片儿等乱七八糟的神经质表现。如运行本程序后仍无效果请重启计算机后再运行一次。本程序为开源软件，任何其他个人或组织未经本人许可不得对此程序进行删除、添加等修改动作。

Pause
taskkill /f /im Explorer.exe
CD /d %userprofile%\AppData\Local
DEL IconCache.db /a
start Explorer.exe