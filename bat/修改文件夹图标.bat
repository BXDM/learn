@echo off
@echo off
setlocal enabledelayedexpansion
g:
for /d %%i in (*) do (
for /f %%j in ('dir/b "%%i\*.ico" 2^>nul^|find /i ".ico"') do (set ico=%%j)
attrib -s -h %%i
Echo %%j
if defined ico (echo [.ShellClassInfo]>"%%i\desktop.ini" && echo IconFile=!ico!>>"%%i\desktop.ini" && echo IconIndex=0 >>"%%i\desktop.ini" && attrib +s +h "%%i" && attrib +s +h "%%i\desktop.ini")
)
pause