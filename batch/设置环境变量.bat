::将当前路径设置为环境变量
@echo off
set mypath=%~dp0
set path %path%;%%mypath%%

