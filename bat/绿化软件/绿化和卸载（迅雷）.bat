@ECHO OFF&PUSHD %~DP0 &TITLE 绿化和选项
mode con cols=36 lines=20
color 2F
Rd "%WinDir%\system32\test_permissions" >NUL 2>NUL
Md "%WinDir%\System32\test_permissions" 2>NUL||(Echo 请使用右键管理员身份运行！&&PAUSE >NUL&&EXIT)
Rd "%WinDir%\System32\test_permissions" 2>NUL
SetLocal EnableDelayedExpansion
:Menu
Cls
@ echo.
@ echo.　　　　　 菜 单 选 项
@ echo.
@ echo.     绿化[必须] → 请输入1
@ echo.
@ echo.     设为默认下载器 → 请输入2
@ echo.
@ echo.     创建桌面图标 → 请输入3
@ echo.
@ echo.     自定义边下边播 → 请输入4
@ echo.
@ echo.     卸载 → 请输入5
@ echo.
set /p xj= 输入数字按回车：
if /i "%xj%"=="1" Goto Install
if /i "%xj%"=="2" Goto Give
if /i "%xj%"=="3" Goto Establish
if /i "%xj%"=="4" Goto custom
if /i "%xj%"=="5" Goto Uninstall
@ echo.
echo      选择无效，请重新输入
ping -n 2 127.1>nul
goto menu
:Install
@ echo.
ECHO 　　　正在安装中..请稍等..
taskkill /f /im Thunder*>nul 2>nul
Program\Thunder.exe -unassociate:td -unassociate:torrent -unassociate:downlist -unassociate:thunderskin -unassociate:thunderaddin -unassociate:all -unregprotocol:ed2k -unregprotocol:magnet -unregprotocol:thunder -unregprotocol:xlapplink
rd/s/q "%tmp%\Xunlei" >nul 2>nul
rd/s/q "%tmp%\Thunder" >nul 2>nul
rd/s/q "%tmp%\ThunderLiveUD" >nul 2>nul
rd/s/q "%tmp%\Thunder Network" >nul 2>nul
rd/s/q "%AllUsersProfile%\Application Data\Thunder Network" >nul 2>nul
rd/s/q "%AllUsersProfile%\Application Data\Xunlei" >nul 2>nul
rd/s/q "%AllUsersProfile%\Xunlei" >nul 2>nul
rd/s/q "%AllUsersProfile%\Thunder Network" >nul 2>nul
rd/s/q "%AppData%\Thunder Network" >nul 2>nul
rd/s/q "%CommonProgramFiles%\Thunder Network" >nul 2>nul
rd/s/q "%CommonProgramFiles(x86)%\Thunder Network" >nul 2>nul
rd/s/q "%UserProfile%\Local Settings\Application Data\Thunder Network" 2>nul
rd/s/q "%UserProfile%\Local Settings\Application Data\Pusher" 2>nul
rd/s/q "%UserProfile%\AppData\LocalLow\Thunder Network" >nul 2>nul
rd/s/q "%UserProfile%\AppData\LocalLow\XueLei" >nul 2>nul
rd/s/q "%UserProfile%\My Documents\Thunder"2>nul
rd/s/q "%AllUsersProfile%\Application Data\Thunder Network"2>nul
If Exist "%PUBLIC%" Rd /s/q "%PUBLIC%\Thunder Network" >nul 2>nul
If Exist "%PUBLIC%" Rd /s/q "%PUBLIC%\Documents\Thunder Network" >nul 2>nul
del/f/q "%AppData%\Microsoft\Windows\Libraries\迅雷下载.library-ms" 2>nul
Md "%AllUsersProfile%\Application Data\Thunder Network\tp_common_info.dat"
if %errorlevel%==0 Md  "%PUBLIC%\Thunder Network\tp_common_info.dat"
regsvr32 /s "Program\BHO\ThunderAgent.dll" >nul 2>nul
if exist "%WinDir%\SysWOW64" regsvr32 /s "Program\BHO\ThunderAgent64.dll" >nul 2>nul
Md "%AllUsersProfile%\Application Data\Thunder Network\cid_store.dat"
Md "%AllUsersProfile%\Application Data\Thunder Network\emule_upload_list.dat"
if %errorlevel%==0 (Md "%PUBLIC%\Thunder Network\cid_store.dat"&Md "%PUBLIC%\Thunder Network\emule_upload_list.dat")
reg add "HKLM\Software\Thunder Network\ThunderOem\thunder_backwnd" /v "dir" /d "%~dp0\" /f >nul 2>nul
reg add "HKLM\Software\Thunder Network\ThunderOem\thunder_backwnd" /v "Path" /d "%~dp0Program\Thunder.exe" /f >nul 2>nul
reg add "HKLM\Software\Thunder Network\ThunderOem\thunder_backwnd" /v "instdir" /d "%~dp0\" /f >nul 2>nul
reg add "HKLM\Software\Thunder Network\ThunderOem\thunder_backwnd" /v "Version" /d "7.9.43.5054" /f >nul 2>nul
reg add "HKCU\Software\Microsoft\Internet Explorer\MenuExt\使用迅雷下载" /ve /d "%~dp0Program\BHO\geturl.htm" /f >nul
reg add "HKCU\Software\Microsoft\Internet Explorer\MenuExt\使用迅雷下载" /v "Contexts" /t REG_DWORD /d "0x00000022" /f >nul
reg add "HKCU\Software\Microsoft\Internet Explorer\MenuExt\使用迅雷下载全部链接" /ve /d "%~dp0Program\BHO\getAllurl.htm" /f >nul
reg add "HKCU\Software\Microsoft\Internet Explorer\MenuExt\使用迅雷下载全部链接" /v "Contexts" /t REG_DWORD /d "0x000000f3" /f >nul
if exist "%WinDir%\SysWOW64" reg add "HKLM\Software\Wow6432Node\Thunder Network\ThunderOem\thunder_backwnd" /v "dir" /d "%~dp0\" /f >nul 2>nul
if exist "%WinDir%\SysWOW64" reg add "HKLM\Software\Wow6432Node\Thunder Network\ThunderOem\thunder_backwnd" /v "Path" /d "%~dp0Program\Thunder.exe" /f >nul 2>nul
if exist "%WinDir%\SysWOW64" reg add "HKLM\Software\Wow6432Node\Thunder Network\ThunderOem\thunder_backwnd" /v "instdir" /d "%~dp0\" /f >nul 2>nul
if exist "%WinDir%\SysWOW64" reg add "HKLM\Software\Wow6432Node\Thunder Network\ThunderOem\thunder_backwnd" /v "Version" /d "7.9.43.5054" /f >nul 2>nul
reg add "HKCR\Xunlei.Bittorrent.6\DefaultIcon" /ve /d "%~dp0Program\TorrentFile.ico" /F>nul
reg add "HKCR\Xunlei.Bittorrent.6\Shell\Open" /ve /d "使用迅雷下载该BT文件" /F>nul
reg add "HKCR\Xunlei.Bittorrent.6\Shell\Open\command" /ve /d "%~dp0Program\Thunder.exe %%1" /F>nul
reg add "HKCR\Xunlei.LSTFile.6\DefaultIcon" /ve /d "%~dp0Program\XLDownloadList.ico" /F>nul
reg add "HKCR\Xunlei.LSTFile.6\Shell\Open" /ve /d "使用迅雷下载该任务列表文件" /F>nul
reg add "HKCR\Xunlei.LSTFile.6\Shell\Open\command" /ve /d "%~dp0Program\Thunder.exe %%1" /F>nul
reg add "HKCR\Xunlei.TDFile.6\DefaultIcon" /ve /d "%~dp0Program\XLTempFile.ico" /F>nul
reg add "HKCR\Xunlei.TDFile.6\Shell\Open" /ve /d "使用迅雷下载未完成文件" /F>nul
reg add "HKCR\Xunlei.TDFile.6\Shell\Open\command" /ve /d "%~dp0Program\Thunder.exe %%1" /F>nul
goto Install2
:Establish
mshta VBScript:Execute("Set a=CreateObject(""WScript.Shell""):Set b=a.CreateShortcut(a.SpecialFolders(""Desktop"") & ""\迅雷.lnk""):b.TargetPath=""%~dp0Program\Thunder.exe"":b.WorkingDirectory=""%~dp0Program"":b.Save:close")
goto fanhui
:Give
Program\BHO\XLNonIESvr.exe -r ie -silent -setfirst
Program\BHO\XLNonIESvr.exe -r 360 -silent -setfirst
Program\BHO\XLNonIESvr.exe -r opera -silent -setfirst
Program\BHO\XLNonIESvr.exe -r maxthon -silent -setfirst
Program\BHO\XLNonIESvr.exe -r theworld -silent -setfirst
Program\BHO\XLNonIESvr.exe -r firefox -silent -setfirst
Program\BHO\XLNonIESvr.exe -r chrome -silent -setfirst
Program\BHO\XLNonIESvr.exe -r SogouExplorer -silent -setfirst
regsvr32 /s "Program\np_tdieplat.dll" >nul 2>nul
reg add "HKLM\Software\Google\Chrome\NativeMessagingHosts\com.xunlei.thunder" /f /ve /d "%~dp0Program\com.xunlei.thunder.json" >nul
if exist "%WinDir%\SysWOW64" reg add "HKLM\Software\Google\Chrome\NativeMessagingHosts\com.xunlei.thunder" /f /ve /d "%~dp0Program\com.xunlei.thunder.json" >nul
goto fanhui
:Uninstall
@ echo.
echo 　　　正在卸载中..请稍等..
taskkill /f /im Thunder*>nul 2>nul
rd/s/q "%tmp%\Xunlei" >nul 2>nul
rd/s/q "%tmp%\Thunder" >nul 2>nul
rd/s/q "%tmp%\ThunderLiveUD" >nul 2>nul
rd/s/q "%tmp%\Thunder Network" >nul 2>nul
rd/s/q "%AllUsersProfile%\Application Data\Thunder Network" >nul 2>nul
rd/s/q "%AllUsersProfile%\Application Data\Xunlei" >nul 2>nul
rd/s/q "%AllUsersProfile%\Xunlei" >nul 2>nul
rd/s/q "%AllUsersProfile%\Thunder Network" >nul 2>nul
rd/s/q "%AppData%\Thunder Network" >nul 2>nul
rd/s/q "%CommonProgramFiles%\Thunder Network" >nul 2>nul
rd/s/q "%CommonProgramFiles(x86)%\Thunder Network" >nul 2>nul
rd/s/q "%UserProfile%\Local Settings\Application Data\Thunder Network" 2>nul
rd/s/q "%UserProfile%\Local Settings\Application Data\Pusher" 2>nul
rd/s/q "%UserProfile%\AppData\LocalLow\Thunder Network" >nul 2>nul
rd/s/q "%UserProfile%\AppData\LocalLow\XueLei" >nul 2>nul
rd/s/q "%UserProfile%\My Documents\Thunder"2>nul
rd/s/q "%AllUsersProfile%\Application Data\Thunder Network"2>nul
del/f/q "Program\BHO\ThunderAgent7.9.43.5054.dll"2>nul
del/f/q "%AppData%\Microsoft\Windows\Libraries\迅雷下载.library-ms" 2>nul
If Exist "%PUBLIC%" Rd /s/q "%PUBLIC%\Thunder Network" >nul 2>nul
If Exist "%PUBLIC%" Rd /s/q "%PUBLIC%\Documents\Thunder Network" >nul 2>nul
Program\Thunder.exe -unassociate:td -unassociate:torrent -unassociate:downlist -unassociate:thunderskin -unassociate:thunderaddin -unassociate:all -unregprotocol:ed2k -unregprotocol:magnet -unregprotocol:thunder -unregprotocol:xlapplink
Program\BHO\XLNonIESvr.exe -u ie -silent 
Program\BHO\XLNonIESvr.exe -u 360 -silent
Program\BHO\XLNonIESvr.exe -u opera -silent 
Program\BHO\XLNonIESvr.exe -u chrome -silent
Program\BHO\XLNonIESvr.exe -u firefox -silent
Program\BHO\XLNonIESvr.exe -u theworld -silent
Program\BHO\XLNonIESvr.exe -u SogouExplorer -silent
regsvr32 /s /u "Program\BHO\ThunderAgent.dll" >nul 2>nul
if exist "%WinDir%\SysWOW64" regsvr32 /s /u "Program\BHO\ThunderAgent64.dll" >nul 2>nul
regsvr32 /s /u "Program\np_tdieplat.dll" >nul 2>nul
reg delete "HKLM\Software\Thunder Network" /f >nul 2>nul
reg delete "HKLM\Software\Wow6432Node\Thunder Network" /f >nul 2>nul
reg delete "HKLM\Software\Google\Chrome\NativeMessagingHosts" /f >nul 2>nul
reg delete "HKLM\Software\Wow6432Node\Google\Chrome\NativeMessagingHosts" /f >nul 2>nul
reg delete "HKCR\Xunlei.Bittorrent.6" /f >nul 2>nul
reg delete "HKCR\Xunlei.LSTFile.6" /f >nul 2>nul
reg delete "HKCR\Xunlei.TDFile.6" /f >nul 2>nul
reg delete "HKCR\Xunlei.ThunderSkin.6" /f >nul 2>nul
reg delete "HKCU\Software\Thunder Network" /f >nul 2>nul
reg delete "HKLM\Software\Google\Chrome\NativeMessagingHosts" /f >nul 2>nul
reg delete "HKCU\Software\Microsoft\Internet Explorer\MenuExt\使用迅雷下载" /f >nul 2>nul
reg delete "HKCU\Software\Microsoft\Internet Explorer\MenuExt\使用迅雷下载全部链接" /f >nul 2>nul
del /f /q "%userprofile%"\Desktop\迅雷.lnk
del /f /q "%userprofile%"\桌面\迅雷.lnk
goto Uninstall2
:custom
start Program\Xmp.ini
:fanhui
@ ECHO.
ECHO 　　　设置完成..
goto menu
:Install2
@ ECHO.
ECHO 　　　安装完成..
goto menu
:Uninstall2
@ ECHO.
ECHO 　　　卸载完成..
goto menu